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

class QAction;
class QLabel;

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

private:
    // 创建动作
    void createAction();
    // 创建菜单栏
    void createMenus();
    // 创建工具栏
    void createToolBars();

    // 菜单栏-新建
    QMenu *newMenu;
    // 工具栏-添加终端
    QToolBar *addTerminal;
    // 打开终端动作
    QAction *newTerminalAction;
    // 打开编辑器动作
    QAction *newEditAction;
    // 退出动作
    QAction *exitAction;
};

#endif // FRAMWINDOW_H
