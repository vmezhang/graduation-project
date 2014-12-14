// =====================================================================================
// 
//       Filename:  codeWindow.cpp
//
//    Description:  编辑器窗口实现
//
//        Version:  1.0
//        Created:  2014年12月14日 10时29分52秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  ZhangRui, v.me-zr@live.cn
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#include "codeWindow.h"
#include "ui_codeWindow.h"

#include <QMessageBox>
#include <QTextCodec>
#include <QFileDialog>
#include <QFontDialog>
#include <QSettings>

#include "codeEdit.h"

CodeWindow::CodeWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CodeWindow)
{
    ui->setupUi(this);
    // init
    newTabCount = 0;

    //![init menus]
    // Create no recent file tip
    noRecentFile = new QAction(this);
    noRecentFile->setText(tr("No Recent File"));
    noRecentFile->setEnabled(false);
    noRecentFile->setVisible(false);
    // Create recent files actions
    for (int i=0; i<MaxRecentFiles; i++) {
        recentFileActs[i] = new QAction(this);
        recentFileActs[i]->setVisible(false);
        connect(recentFileActs[i], SIGNAL(triggered()),
                this, SLOT(openRecentFile()));
    }
    // Add no recent file tip
    ui->menuRecentFiles->addAction(noRecentFile);
    // Add recent files actions
    for (int i = 0; i < MaxRecentFiles; ++i)
        ui->menuRecentFiles->addAction(recentFileActs[i]);
    // Updata recent files actions;
    updateRecentFileActions();
    // Get Codec
    findCodecs();
    for (int i=0; i<codecs.count(); i++) {
        codecsActs[i] = new QAction(this);
        codecsActs[i]->setText(codecs.at(i)->name());
        codecsActs[i]->setData(codecs.at(i)->mibEnum());
        codecsActs[i]->setVisible(true);
        connect(codecsActs[i], SIGNAL(triggered()),
                this, SLOT(setupCodec()));
        ui->menuEncoding->addAction(codecsActs[i]);
    }
    //![init menus]

    //! [status bar]
    labelLineRow.setText(tr(" Ln:0 Col:0 " ));
    labelCodec.setText(tr(" none "));

    ui->statusBar->addWidget(&labelLineRow, 0);
    ui->statusBar->addWidget(new QLabel, 1);
    ui->statusBar->addWidget(&labelCodec, 0);
    ui->statusBar->addWidget(new QLabel, 1);
    //! [status bar]

    //![default settings]
    font.setFamily("Fixedsys");
    font.setPointSize(9);
    font.setFixedPitch(true);
    wrapMode = QTextOption::NoWrap;
    codec = QTextCodec::codecForLocale()->mibEnum();
    lineNumberEnable = true;
    highlightEnable = true;
    currentLineEnable = true;
    //![default settings]

//    newFile();

    setupMenu();
    setupEditors();
}

CodeWindow::~CodeWindow()
{
    delete ui;
}

void CodeWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void CodeWindow::closeEvent(QCloseEvent *e)
{
    e->accept();
}

void CodeWindow::setupEditors()
{
    ui->actionLineNumber->setChecked(lineNumberEnable);
    ui->actionHightlight->setChecked(highlightEnable);
    ui->actionWordWrap->setChecked(wrapMode);
    ui->actionHightlightCurrentLine->setChecked(currentLineEnable);
    for (int i=0; i<ui->tabWidget->count(); i++) {
        ((CodePad *)ui->tabWidget->widget(i))->setup();
    }
}

void CodeWindow::createNewTab(CodePad *newEdit)
{
    if(ui->tabWidget->count() < MAX_TAB && newEdit) {
        int tabIndex = ui->tabWidget->addTab(newEdit, NULL);
        // Show new created tab with TextEdit
        ui->tabWidget->setCurrentIndex(tabIndex);
        // connect signal & slot
        connect(newEdit, SIGNAL(textChanged()), this, SLOT(tabTextChange()));
    }
}

void CodeWindow::newFile()
{
    // Create a new TextEdit
    CodePad *newEdit = new CodePad(this);
    newTabCount++;
    newEdit->document()->setPlainText(QString(""));
    newEdit->setTabName(QString("New %1").arg(newTabCount));
    createNewTab(newEdit);
    ui->tabWidget->setTabText(ui->tabWidget->currentIndex(), newEdit->getTabName());
}

void CodeWindow::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    openFile(fileName);
}

void CodeWindow::openFile(const QString &fileName)
{
    if (!fileName.isEmpty()) {
        CodePad *newEdit = NULL;
        for (int i=0; i<ui->tabWidget->count(); i++) {
            newEdit = (CodePad *)ui->tabWidget->widget(i);
            if (fileName.compare(newEdit->getFileName()) == 0) {
                ui->tabWidget->setCurrentIndex(i);
                setCurrentFile(fileName);
                return;
            }
        }
        newEdit = new CodePad(this);
        if (newEdit->open(fileName) == 0) {
            createNewTab(newEdit);
            ui->tabWidget->setTabText(ui->tabWidget->currentIndex(), newEdit->getTabName());
            setCurrentFile(fileName);
        } else {
            if (newEdit) {
                delete newEdit;
                newEdit = NULL;
            }
        }
    }
}

int CodeWindow::saveFile(CodePad *tmp)
{
    QString fileName = tmp->getFileName();
    if (fileName.isEmpty()) {
        return saveFileAs(tmp);
    } else {
        int rt = tmp->save();
        if (rt == 0)
            setCurrentFile(fileName);
        return rt;
    }
}

int CodeWindow::saveFileAs(CodePad *tmp)
{
    QString fileName = QFileDialog::getSaveFileName(
            this, tr("Save File"),
            tmp->getTabName());
    int rt = tmp->saveAs(fileName);
    if (rt == 0)
        setCurrentFile(fileName);
    return rt;
}

void CodeWindow::saveAll()
{
    CodePad *tmp = NULL;
    for (int i=0; i<ui->tabWidget->count(); i++) {
        ui->tabWidget->setCurrentIndex(i);
        tmp = (CodePad *)ui->tabWidget->currentWidget();
        if (saveFile(tmp) == 0) {
            ui->tabWidget->setTabText(ui->tabWidget->currentIndex(), tmp->getTabName());
        }
    }
}

int CodeWindow::closeFile(CodePad *tmp)
{
    int rt = 0;
    if (tmp) {
        if (tmp->getChanged()) {
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this, tr("CodeEdit"),
                                          tr("File changed.\nSave current file?"),
                                          QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
            if (reply == QMessageBox::Yes) {
                rt = saveFile(tmp);
            }else if (reply == QMessageBox::Cancel) {
                rt = -1;
            } else {
                rt = 0;
            }
        }
        if (rt == 0) {
            delete tmp;
            tmp = NULL;
        }
    }
    return rt;
}

int CodeWindow::closeAll()
{
    CodePad *tmp = (CodePad *)ui->tabWidget->currentWidget();
    int rt = 0;
    while (tmp) {
        rt = closeFile(tmp);
        if (rt != 0)
            break;
        else
            tmp = (CodePad *)ui->tabWidget->currentWidget();
    }
    return rt;
}

void CodeWindow::closeExit()
{
    if (closeAll() == 0)
        close();
}

void CodeWindow::tabTextChange()
{
    CodePad *tmp = (CodePad *)ui->tabWidget->currentWidget();
    tmp->setChanged(true);
    ui->tabWidget->setTabText(ui->tabWidget->currentIndex(), tmp->getTabName() + "*");
}

void CodeWindow::setupMenu()
{
    if(ui->tabWidget->count()) {
        ui->actionSave->setEnabled(true);
        ui->actionSaveAs->setEnabled(true);
        ui->actionSaveAll->setEnabled(true);
        ui->actionClose->setEnabled(true);
        ui->actionCloseAll->setEnabled(true);
        ui->actionCopy->setEnabled(true);
        ui->actionCut->setEnabled(true);
        ui->actionPaste->setEnabled(true);
        ui->actionRedo->setEnabled(true);
        ui->actionUndo->setEnabled(true);
    } else {
        ui->actionSave->setEnabled(false);
        ui->actionSaveAs->setEnabled(false);
        ui->actionSaveAll->setEnabled(false);
        ui->actionClose->setEnabled(false);
        ui->actionCloseAll->setEnabled(false);
        ui->actionCopy->setEnabled(false);
        ui->actionCut->setEnabled(false);
        ui->actionPaste->setEnabled(false);
        ui->actionRedo->setEnabled(false);
        ui->actionUndo->setEnabled(false);
    }
}

void CodeWindow::setCurrentFile(const QString &fileName)
{
    QSettings settings("./config.ini", QSettings::IniFormat);
    QStringList files = settings.value("RecentFiles/list").toStringList();
    files.removeAll(fileName);
    files.prepend(fileName);
    while (files.size() > MaxRecentFiles)
        files.removeLast();

    settings.setValue("RecentFiles/list", files);

    foreach (QWidget *widget, QApplication::topLevelWidgets())
    {
        CodeWindow *mainWin = qobject_cast<CodeWindow *>(widget);
        if (mainWin)
            mainWin->updateRecentFileActions();
    }
}

void CodeWindow::updateRecentFileActions()
{
    QSettings settings("./config.ini", QSettings::IniFormat);
    QStringList files = settings.value("RecentFiles/list").toStringList();
    QMutableStringListIterator i(files);
    // Remove files doesn't exist
    while(i.hasNext())
    {
        if(!QFile::exists(i.next()))
            i.remove();
    }
    int numRecentFiles = qMin(files.size(), (int)MaxRecentFiles);
    for (int i = 0; i < numRecentFiles; ++i)
    {
        QString text = tr("&%1: %2").arg(i + 1).arg(files[i]);
        recentFileActs[i]->setText(text);
        recentFileActs[i]->setData(files[i]);
        recentFileActs[i]->setVisible(true);
    }
    for (int j = numRecentFiles; j < MaxRecentFiles; ++j)
        recentFileActs[j]->setVisible(false);
    if (numRecentFiles == 0)
        noRecentFile->setVisible(true);
    else
        noRecentFile->setVisible(false);
}

void CodeWindow::openRecentFile()
{
    QAction *action = qobject_cast<QAction *>(sender());
    if (action) {
        openFile(action->data().toString());
    }
}

void CodeWindow::findCodecs()
{
    QMap<QString, QTextCodec *> codecMap;
    QRegExp iso8859RegExp("ISO[- ]8859-([0-9]+).*");

    foreach (int mib, QTextCodec::availableMibs()) {
        QTextCodec *codec = QTextCodec::codecForMib(mib);

        QString sortKey = codec->name().toUpper();
        int rank;

        if (sortKey.startsWith("UTF-8")) {
            rank = 1;
        } else if (sortKey.startsWith("UTF-16")) {
            rank = 2;
        } else if (iso8859RegExp.exactMatch(sortKey)) {
            if (iso8859RegExp.cap(1).size() == 1)
                rank = 3;
            else
                rank = 4;
        } else {
            rank = 5;
        }
        sortKey.prepend(QChar('0' + rank));

        codecMap.insert(sortKey, codec);
    }
    codecs = codecMap.values();
}

void CodeWindow::setupCodec() {
    QAction *action = qobject_cast<QAction *>(sender());
    if (action) {
        CodePad *tmp = (CodePad *)ui->tabWidget->currentWidget();
        if (tmp) {
            tmp->codec = action->data().toInt();
            tmp->updateTextEdit();
            labelCodec.setText(tr(" %1 ").arg(action->text()));
            ui->statusBar->update();
        }
    }
}

void CodeWindow::on_actionExit_triggered()
{
    this->closeExit();
}

void CodeWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, tr("About CodeEdit"),
                       tr( "<b>CodeEdit</b>  Version 1.0.0<br><br>" \
                           "Copyright (C) 2014 ZhangRui<br><br>"));
}

void CodeWindow::on_actionAboutQt_triggered()
{
    qApp->aboutQt();
}

void CodeWindow::on_tabWidget_tabCloseRequested(int index)
{
//    if(ui->tabWidget->count() == 1)
//        return;
    closeFile((CodePad *)ui->tabWidget->widget(index));
}

void CodeWindow::on_actionNew_triggered()
{
    newFile();
}

void CodeWindow::on_actionOpen_triggered()
{
    openFile();
}

void CodeWindow::on_actionClose_triggered()
{
    closeFile((CodePad *)ui->tabWidget->currentWidget());
}

void CodeWindow::on_actionCloseAll_triggered()
{
    closeAll();
}

void CodeWindow::on_actionSave_triggered()
{
    CodePad *tmp = (CodePad *)ui->tabWidget->currentWidget();
    if (saveFile(tmp) == 0) {
        ui->tabWidget->setTabText(ui->tabWidget->currentIndex(), tmp->getTabName());
    }
}

void CodeWindow::on_actionSaveAs_triggered()
{
    CodePad *tmp = (CodePad *)ui->tabWidget->currentWidget();
    if (saveFileAs(tmp) == 0) {
        ui->tabWidget->setTabText(ui->tabWidget->currentIndex(), tmp->getTabName());
    }
}

void CodeWindow::on_actionUndo_triggered()
{
    ((CodePad *)ui->tabWidget->currentWidget())->undo();
}

void CodeWindow::on_actionRedo_triggered()
{
    ((CodePad *)ui->tabWidget->currentWidget())->redo();
}

void CodeWindow::on_actionCut_triggered()
{
    ((CodePad *)ui->tabWidget->currentWidget())->cut();
}

void CodeWindow::on_actionCopy_triggered()
{
    ((CodePad *)ui->tabWidget->currentWidget())->copy();
}

void CodeWindow::on_actionPaste_triggered()
{
    ((CodePad *)ui->tabWidget->currentWidget())->paste();
}

void CodeWindow::on_actionSaveAll_triggered()
{
    saveAll();
}

void CodeWindow::on_tabWidget_currentChanged(int index)
{
    setupMenu();

    CodePad *tmp = (CodePad *)ui->tabWidget->widget(index);
    if (tmp) {
        labelCodec.setText(tr(" %1 ").arg(QString(QTextCodec::codecForMib(tmp->codec)->name())));
    } else {
        labelCodec.setText(tr(" none "));
    }
    ui->statusBar->update();
}

void CodeWindow::on_actionWordWrap_triggered(bool checked)
{
    if(checked)
        wrapMode = QTextOption::WrapAtWordBoundaryOrAnywhere;
    else
        wrapMode = QTextOption::NoWrap;
    setupEditors();
}

void CodeWindow::on_actionHightlight_triggered(bool checked)
{
    highlightEnable = checked;
    setupEditors();
}

void CodeWindow::on_actionLineNumber_triggered(bool checked)
{
    lineNumberEnable = checked;
    setupEditors();
}

void CodeWindow::on_actionHightlightCurrentLine_triggered(bool checked)
{
    currentLineEnable = checked;
    setupEditors();
}

void CodeWindow::on_actionFont_triggered()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, this->font, this);
    if (ok) {
        this->font = font;
        setupEditors();
    }
}

