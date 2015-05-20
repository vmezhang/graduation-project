// =====================================================================================
// 
//       Filename:  testShell.h
//
//    Description:  一些自定义的测试命令
//
//        Version:  1.0
//        Created:  2015年05月15日 13时40分23秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  ZhangRui, v.me-zr@live.cn
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================


#ifndef TESTSHELL_H
#define TESTSHELL_H

QString readShell(QString cmd);
void printp(QString pMessage);

QString readShell(QString cmd)
{
    Qstring qcmd;
    // 解析cmd
    return qcmd;
}

// 屏幕打印函数
void printp(char *pMessage)
{
    appendPlainText(pMessage);
}

#endif  // TESTSHELL_H
