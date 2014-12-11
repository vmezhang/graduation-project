// =====================================================================================
// 
//       Filename:  FrameWindow.cpp
//
//    Description:  主窗体实现
//
//        Version:  1.0
//        Created:  2014年12月11日 19时33分08秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  ZhangRui, v.me-zr@live.cn
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#include <QtGui>

#include "FrameWindow.h"

MainWindow::MainWindow()
{
    createAction();
    createMenus();
    createToolBars();
}

void MainWindow::createAction()
{
    // 动作打开终端
    newTerminalAction = new QAction(tr("&终端"), this);
    newTerminalAction->setIcon(QIcon(":/res/images/terminal.png"));
    // 快捷键ctrl+n
    newTerminalAction->setShortcut(QKeySequence::New);
    // 提示
    newTerminalAction->setStatusTip(tr("新建一个终端"));
    connect(newTerminalAction, SIGNAL(triggered()), this, SLOT(newTerminal()));

    // 动作打开编辑器
    newEditAction = new QAction(tr("&编辑器"), this);
    newEditAction->setShortcut(tr("Ctrl+E"));
    newEditAction->setStatusTip(tr("打开程序编辑器"));
    connect(newEditAction, SIGNAL(triggered()), this, SLOT(newEdit()));

    // 动作退出
    exitAction = new QAction(tr("&退出"),this);
    exitAction->setShortcut(tr("Ctrl+Q"));
    exitAction->setStatusTip(tr("关闭程序"));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));
}

void MainWindow::createMenus()
{
    newMenu = menuBar()->addMenu(tr("新建"));
    newMenu->addAction(newTerminalAction);
    newMenu->addAction(newEditAction);
    newMenu->addSeparator();
    newMenu->addAction(exitAction);
}

void MainWindow::createToolBars()
{
    addTerminal = addToolBar(tr("&打开终端"));
    addTerminal->addAction(newTerminalAction);
}

void MainWindow::newTerminal()
{

}

void MainWindow::newEdit()
{

}

void MainWindow::closeEvent(QCloseEvent *event)
{
    event->accept();
}
