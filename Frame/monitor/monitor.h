// =====================================================================================
// 
//       Filename:  monitor.h
//
//    Description:  监控器头文件
//
//        Version:  1.0
//        Created:  2015年05月11日 21时00分56秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  ZhangRui, v.me-zr@live.cn
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#ifndef MONITOR_H
#define MONITOR_H

#include <QMainWindow>


namespace Ui {
    class monitor;
}

class monitor : public QMainWindow
{
    Q_OBJECT

public:
    explicit monitor(QWidget *parent = 0);
    ~monitor();

private:
    Ui::monitor *ui;

private slots:
    void removeSubTab(int index);
    void DisplayCpuInfo();
    void DisplayMemInfo();
    void DisplayLoadInfo();

};

#endif // MONITOR_H


