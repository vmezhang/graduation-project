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

#include "codeWindow.h".h"
#include "ui_codeWindow.h"

#include <QMessageBox>
#include <QTextCodec>
#include <QFileDialog>
#include <QFontDialog>
#include <QSettings>

#include "codeEdit.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
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

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
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

void MainWindow::closeEvent(QCloseEvent *e)
{
    QMainWindow::closeEvent(e);
    e->ignore();
    exit();
}

void MainWindow::setupEditors()
{
    ui->actionLineNumber->setChecked(lineNumberEnable);
    ui->actionHightlight->setChecked(highlightEnable);
    ui->actionWordWrap->setChecked(wrapMode);
    ui->actionHightlightCurrentLine->setChecked(currentLineEnable);
    for (int i=0; i<ui->tabWidget->count(); i++) {
        ((CodePad *)ui->tabWidget->widget(i))->setup();
    }
}

void MainWindow::createNewTab(CodePad *newEdit)
{
    if(ui->tabWidget->count() < MAX_TAB && newEdit) {
        int tabIndex = ui->tabWidget->addTab(newEdit, NULL);
        // Show new created tab with TextEdit
        ui->tabWidget->setCurrentIndex(tabIndex);
        // connect signal & slot
        connect(newEdit, SIGNAL(textChanged()), this, SLOT(tabTextChange()));
    }
}

void MainWindow::newFile()
{
    // Create a new TextEdit
    CodePad *newEdit = new CodePad(this);
    newTabCount++;
    newEdit->document()->setPlainText(QString(""));
    newEdit->setTabName(QString("New %1").arg(newTabCount));
    createNewTab(newEdit);
    ui->tabWidget->setTabText(ui->tabWidget->currentIndex(), newEdit->getTabName());
}

void MainWindow::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    openFile(fileName);
}

void MainWindow::openFile(const QString &fileName)
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

int MainWindow::saveFile(CodePad *tmp)
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

int MainWindow::saveFileAs(CodePad *tmp)
{
    QString fileName = QFileDialog::getSaveFileName(
            this, tr("Save File"),
            tmp->getTabName());
    int rt = tmp->saveAs(fileName);
    if (rt == 0)
        setCurrentFile(fileName);
    return rt;
}

void MainWindow::saveAll()
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

int MainWindow::closeFile(CodePad *tmp)
{
    int rt = 0;
    if (tmp) {
        if (tmp->getChanged()) {
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this, tr("QtCodePad"),
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

int MainWindow::closeAll()
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

void MainWindow::exit()
{
    if (closeAll() == 0)
        qApp->exit();
}

void MainWindow::tabTextChange()
{
    CodePad *tmp = (CodePad *)ui->tabWidget->currentWidget();
    tmp->setChanged(true);
    ui->tabWidget->setTabText(ui->tabWidget->currentIndex(), tmp->getTabName() + "*");
}

void MainWindow::setupMenu()
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

void MainWindow::setCurrentFile(const QString &fileName)
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
        MainWindow *mainWin = qobject_cast<MainWindow *>(widget);
        if (mainWin)
            mainWin->updateRecentFileActions();
    }
}

void MainWindow::updateRecentFileActions()
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

void MainWindow::openRecentFile()
{
    QAction *action = qobject_cast<QAction *>(sender());
    if (action) {
        openFile(action->data().toString());
    }
}

void MainWindow::findCodecs()
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

void MainWindow::setupCodec() {
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

void MainWindow::on_actionExit_triggered()
{
    exit();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, tr("About QtCodePad"),
                       tr( "<b>QtCodePad</b>  Version 1.0.0<br><br>" \
                           "Copyright (C) 2010 Ninsun<br><br>" \
                           "This program is free software: you can redistribute it and/or modify" \
                           "it under the terms of the GNU General Public License as published by" \
                           "the Free Software Foundation, either version 3 of the License, or" \
                           "(at your option) any later version.<br><br>" \
                           "This program is distributed in the hope that it will be useful," \
                           "but WITHOUT ANY WARRANTY; without even the implied warranty of" \
                           "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the" \
                           "GNU General Public License for more details.<br><br>" \
                           "You should have received a copy of the GNU General Public License"\
                           "along with this program. " \
                           "If not, see <a href=\"http://www.gnu.org/licenses/\">http://www.gnu.org/licenses/</a>."));
}

void MainWindow::on_actionAboutQt_triggered()
{
    qApp->aboutQt();
}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
//    if(ui->tabWidget->count() == 1)
//        return;
    closeFile((CodePad *)ui->tabWidget->widget(index));
}

void MainWindow::on_actionNew_triggered()
{
    newFile();
}

void MainWindow::on_actionOpen_triggered()
{
    openFile();
}

void MainWindow::on_actionClose_triggered()
{
    closeFile((CodePad *)ui->tabWidget->currentWidget());
}

void MainWindow::on_actionCloseAll_triggered()
{
    closeAll();
}

void MainWindow::on_actionSave_triggered()
{
    CodePad *tmp = (CodePad *)ui->tabWidget->currentWidget();
    if (saveFile(tmp) == 0) {
        ui->tabWidget->setTabText(ui->tabWidget->currentIndex(), tmp->getTabName());
    }
}

void MainWindow::on_actionSaveAs_triggered()
{
    CodePad *tmp = (CodePad *)ui->tabWidget->currentWidget();
    if (saveFileAs(tmp) == 0) {
        ui->tabWidget->setTabText(ui->tabWidget->currentIndex(), tmp->getTabName());
    }
}

void MainWindow::on_actionUndo_triggered()
{
    ((CodePad *)ui->tabWidget->currentWidget())->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    ((CodePad *)ui->tabWidget->currentWidget())->redo();
}

void MainWindow::on_actionCut_triggered()
{
    ((CodePad *)ui->tabWidget->currentWidget())->cut();
}

void MainWindow::on_actionCopy_triggered()
{
    ((CodePad *)ui->tabWidget->currentWidget())->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ((CodePad *)ui->tabWidget->currentWidget())->paste();
}

void MainWindow::on_actionSaveAll_triggered()
{
    saveAll();
}

void MainWindow::on_tabWidget_currentChanged(int index)
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

void MainWindow::on_actionWordWrap_triggered(bool checked)
{
    if(checked)
        wrapMode = QTextOption::WrapAtWordBoundaryOrAnywhere;
    else
        wrapMode = QTextOption::NoWrap;
    setupEditors();
}

void MainWindow::on_actionHightlight_triggered(bool checked)
{
    highlightEnable = checked;
    setupEditors();
}

void MainWindow::on_actionLineNumber_triggered(bool checked)
{
    lineNumberEnable = checked;
    setupEditors();
}

void MainWindow::on_actionHightlightCurrentLine_triggered(bool checked)
{
    currentLineEnable = checked;
    setupEditors();
}

void MainWindow::on_actionFont_triggered()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, this->font, this);
    if (ok) {
        this->font = font;
        setupEditors();
    }
}

