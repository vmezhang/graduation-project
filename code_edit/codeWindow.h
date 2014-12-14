// =====================================================================================
// 
//       Filename:  codeWindow.h
//
//    Description:  编辑器主窗口类
//
//        Version:  1.0
//        Created:  2014年12月14日 10时29分46秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  ZhangRui, v.me-zr@live.cn
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#ifndef CODEWINDOW_H
#define CODEWINDOW_H

#include <QMainWindow>
#include <QTextOption>
#include <QLabel>

#define MAX_TAB 64

QT_BEGIN_NAMESPACE
class CodePad;
QT_END_NAMESPACE

namespace Ui {
    class CodeWindow;
}

class CodeWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit CodeWindow(QWidget *parent = 0);
    ~CodeWindow();

protected:
    void changeEvent(QEvent *e);
    void closeEvent(QCloseEvent *e);

private:
    Ui::CodeWindow *ui;

private slots:
    void on_actionFont_triggered();
    void on_actionHightlightCurrentLine_triggered(bool checked);
    void on_actionLineNumber_triggered(bool checked);
    void on_actionHightlight_triggered(bool checked);
    void on_actionWordWrap_triggered(bool checked);
    void on_tabWidget_currentChanged(int index);
    void on_actionSaveAll_triggered();
    void on_actionPaste_triggered();
    void on_actionCopy_triggered();
    void on_actionCut_triggered();
    void on_actionRedo_triggered();
    void on_actionUndo_triggered();
    void on_actionSaveAs_triggered();
    void on_actionSave_triggered();
    void on_actionCloseAll_triggered();
    void on_actionClose_triggered();
    void on_actionOpen_triggered();
    void on_actionNew_triggered();
    void on_tabWidget_tabCloseRequested(int index);
    void on_actionAboutQt_triggered();
    void on_actionAbout_triggered();
    void on_actionExit_triggered();

    //![custom values]
public:
    QFont font;
    QTextOption::WrapMode wrapMode;
    int codec;
    bool lineNumberEnable;
    bool highlightEnable;
    bool currentLineEnable;

    QLabel labelLineRow;
    QLabel labelCodec;
private:
    int newTabCount;
    enum { MaxRecentFiles = 9, MaxCodecCount = 100 };
    QAction* noRecentFile;
    QAction* recentFileActs[MaxRecentFiles];

    QAction* codecsActs[MaxCodecCount];
    QList<QTextCodec *> codecs;
    //![custom values]

    //![custom functions]
private:
    void setupEditors();
    void createNewTab(CodePad *newEdit);
    void newFile();
    void openFile();
    void openFile(const QString &fileName);
    int saveFile(CodePad *tmp);
    int saveFileAs(CodePad *tmp);
    void saveAll();
    int closeFile(CodePad *tmp);
    int closeAll();
    void exit();

    void setCurrentFile(const QString &fileName);
    void updateRecentFileActions();
    void findCodecs();

private slots:
    void tabTextChange();
    void setupMenu();

    void openRecentFile();
    void setupCodec();
    //![custom functions]
};

#endif // CODEWINDOW_H
