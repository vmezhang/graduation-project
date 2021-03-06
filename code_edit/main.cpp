// =====================================================================================
// 
//       Filename:  main.cpp
//
//    Description:  测试函数
//
//        Version:  1.0
//        Created:  2014年12月14日 10时30分02秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  ZhangRui, v.me-zr@live.cn
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#include <QtGui/QApplication>
#include "codeWindow.h"
#include <QMessageBox>
#include <QSplashScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CodeWindow w;
#if defined(Q_WS_S60) || defined(Q_WS_MAEMO_5)
    w.showMaximized();
#else
    w.show();
#endif
    return a.exec();
}


