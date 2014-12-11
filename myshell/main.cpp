// =====================================================================================
// 
//       Filename:  main.cpp
//
//    Description:  仿终端界面
//
//        Version:  1.0
//        Created:  2014年12月10日 09时36分18秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  ZhangRui, v.me-zr@live.cn
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#include <QtGui/QtGui>
#include "shell.h"

int main(int argc, char *argv[])
{
    // 处理中文乱码问题
    QTextCodec *codec = QTextCodec::codecForName("system");

    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);

    QApplication a(argc, argv);

    ShellEdit w;
    // 窗口图标
    w.setWindowIcon(QIcon(":/res/images/1.ico"));
    // 窗口大小
    w.resize(800, 550);
    // 窗口名称
    w.setWindowTitle("myshell");
    // 窗体在屏幕中间
    w.move((QApplication::desktop()->width() - w.width()) >> 1,
                (QApplication::desktop()->height() - w.height()) >> 1);
    w.show();

    return a.exec();
}

