// =====================================================================================
// 
//       Filename:  FrameWindow.h
//
//    Description:  主窗体类
//
//        Version:  1.0
//        Created:  2014年12月11日 19时33分01秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  ZhangRui, v.me-zr@live.cn
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================


#ifndef FRAMWINDOW_H
#define FRAMWINDOW_H

#include <QMainWindow>

#include "Shell/shell.h"
#include "CodeEdit/codeWindow.h"
#include "monitor/monitor.h"

#define MAX_TAB 64

class QAction;
class QLabel;
class QTabWidget;
class QWidget;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    // 新建一个终端
    void newTerminal();
    // 打开编辑器
    void newEdit();
    // 打开监控
    void newMonitor();
    // 关闭标签页
    void removeShellTab(int index);
    // 关闭所有终端
    void closeAllShell();
    // 退出程序
    void exitApp();

    // 关于我们
    void aboutUs();
    // 使用指南
    void useGuide();

private:
    // 创建动作
    void createAction();
    // 创建菜单栏
    void createMenus();
    // 创建工具栏
    void createToolBars();
    // 初始化标签页
    void initTab();
    // 创建标签页
    void createNewTab(ShellEdit *newShellEdit);

    // 菜单栏
    QMenu *newMenu;

    // 工具栏-添加内容
    QToolBar *addThing;
    // 工具栏-帮助信息
    QToolBar *Help;

    // 打开终端动作
    QAction *newTerminalAction;
    // 打开编辑器动作
    QAction *newEditAction;
    // 打开监控动作
    QAction *newMonitorAction;
    // 关闭所有终端动作
    QAction *closeAllShellAction;
    // 退出动作
    QAction *exitAction;

    // 关于本软件动作
    QAction *about;
    // 使用帮助
    QAction *useHelp;

private:
    // 标签页数
    int newTabCount;
    // 标签页
    QTabWidget *tabWidget;
    // shell部分
    ShellEdit *shellEdit;

    // codeEdit
    CodeWindow edit;
    // monitor
    monitor view;

    QMainWindow guide;
    QMainWindow aboutus;

};

#endif // FRAMWINDOW_H
