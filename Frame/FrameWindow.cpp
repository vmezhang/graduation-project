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
    initTab();
}

void MainWindow::initTab()
{
    // 初始化标签页
    newTabCount = 0;
    tabWidget = new QTabWidget();
    setCentralWidget(tabWidget);
    tabWidget->setTabsClosable(true);
    connect(tabWidget, SIGNAL(tabCloseRequested(int)), SLOT(removeShellTab(int)));
    // 设置QTabBar样式
    QString tabBarStyle = "QTabBar::tab {min-width:100px;font:bold; \
                           background:#E0EEEE; \
                           border: 2px solid;border-top-left-radius: 10px;border-top-right-radius: 10px;padding:5px;} \
                           QTabBar::tab:!selected {margin-top: 5px;}";
    tabWidget->setStyleSheet(tabBarStyle);
}

void MainWindow::createAction()
{
    // 动作打开终端
    newTerminalAction = new QAction(tr("&终端"), this);
    newTerminalAction->setIcon(QIcon(":/res/images/1.png"));
    // 快捷键ctrl+n
    newTerminalAction->setShortcut(QKeySequence::New);
    // 提示
    newTerminalAction->setStatusTip(tr("新建一个终端"));
    connect(newTerminalAction, SIGNAL(triggered()), this, SLOT(newTerminal()));

    // 动作打开编辑器
    newEditAction = new QAction(tr("&编辑器"), this);
    newEditAction->setIcon(QIcon(":/res/images/2.png"));
    newEditAction->setShortcut(tr("Ctrl+E"));
    newEditAction->setStatusTip(tr("打开程序编辑器"));
    connect(newEditAction, SIGNAL(triggered()), this, SLOT(newEdit()));

    // 动作关闭所有终端
    closeAllShellAction = new QAction(tr("&关闭所有终端"), this);
    closeAllShellAction->setShortcut(tr("Ctrl+D"));
    connect(closeAllShellAction, SIGNAL(triggered()), this, SLOT(closeAllShell()));

    // 动作退出
    exitAction = new QAction(tr("&退出"),this);
    exitAction->setShortcut(tr("Ctrl+Q"));
    exitAction->setStatusTip(tr("关闭程序"));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));

    // 动作关于
    about = new QAction(tr("&关于我们"), this);
    connect(about, SIGNAL(triggered()), this, SLOT(aboutUs()));

    // 动作帮助
    useHelp = new QAction(tr("&使用指南"), this);
    useHelp->setIcon(QIcon(":/res/images/5.png"));
    useHelp->setShortcut(tr("Ctrl+H"));
    useHelp->setStatusTip(tr("使用指南"));
    connect(useHelp, SIGNAL(triggered()), this, SLOT(useGuide()));
}

void MainWindow::createMenus()
{
    newMenu = menuBar()->addMenu(tr("新建"));
    newMenu->setStyleSheet("QMenu{background-color:white;} \
                           QMenu::item:selected{color:#000000;background:#E0EEEE}");
    newMenu->addAction(newTerminalAction);
    newMenu->addAction(newEditAction);
    newMenu->addSeparator();
    newMenu->addAction(closeAllShellAction);
    newMenu->addAction(exitAction);

    newMenu = menuBar()->addMenu(tr("帮助"));
    newMenu->setStyleSheet("QMenu{background-color:white;} \
                           QMenu::item:selected{color:#000000;background:#E0EEEE}");
    newMenu->addAction(about);
    newMenu->addAction(useHelp);

}

void MainWindow::createToolBars()
{
    // 工具栏-添加内容
    addThing = addToolBar(tr("&add"));
    addThing->setIconSize(QSize(40, 40));
    addThing->addAction(newTerminalAction);
    addThing->addAction(newEditAction);

    // 帮助工具栏
    Help = addToolBar(tr("&help"));
    Help->setIconSize(QSize(40, 40));
    Help->addAction(useHelp);
}

void MainWindow::newTerminal()
{
    newTabCount++;
    shellEdit = new ShellEdit();
    createNewTab(shellEdit);
    // 给当前标签页命名
    tabWidget->setTabText(tabWidget->currentIndex(), "Shell " + QString::number(newTabCount, 10));
}

void MainWindow::createNewTab(ShellEdit *newShellEdit)
{
    if(tabWidget->count() < MAX_TAB && newShellEdit) {
        int tabIndex = tabWidget->addTab(newShellEdit, NULL);
        // Show new created tab with shellEdit
        tabWidget->setCurrentIndex(tabIndex);
    }
}

void MainWindow::removeShellTab(int index)
{
    // 删除当前标签页
    tabWidget->removeTab(index);
    // 如果标签页个数为0，则置count为0
    if (tabWidget->count() == 0 && newTabCount > 0) {
        newTabCount = 0;
    }
}

void MainWindow::closeAllShell()
{
    tabWidget->clear();
    // 置count为0
    newTabCount = 0;
}

void MainWindow::newEdit()
{
    QMainWindow *edit = new QMainWindow();
    edit->setWindowTitle("MyEdit");
    edit->resize(500, 350);
    edit->show();
}

void MainWindow::aboutUs()
{
    QMainWindow *aboutus = new QMainWindow();
    aboutus->setWindowTitle("关于我们");
    aboutus->resize(100, 50);
    aboutus->show();
}

void MainWindow::useGuide()
{
    QMainWindow *guide = new QMainWindow();
    guide->setWindowTitle("使用指南");
    guide->resize(100, 50);
    guide->show();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    event->accept();
}
