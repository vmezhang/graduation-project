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

#include "shell.h"
#include <QFile>

QString readShell(QString cmd);

QString readShell(QString cmd)
{
    QString outMessage;
    QString fileName;
    // 以下为测试时设置的文件名
    // 命令的返回结果可以是一个文件名,将读取文件的内容传给outMessage
    // 或者直接将运行结果返回成字符串,将字符串传给outMessage
    fileName = "cmd.txt";
    // 解析cmd
    // 如果编译程序过程中或者运行程序有输出将会返回
    // 一个保存运行结果的信息的文件路径
    // 通过读取文件中的内容获得返回结果

    QFile outputFile(fileName);
    outputFile.open(QFile::ReadWrite);
    outMessage = outputFile.readAll();
    // 运行结束后将文件内容清空
    outputFile.resize(0);

    return outMessage;
}


#endif  // TESTSHELL_H
