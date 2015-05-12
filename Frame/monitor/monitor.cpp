// =====================================================================================
// 
//       Filename:  monitor.cpp
//
//    Description:  实现监控
//
//        Version:  1.0
//        Created:  2015年05月11日 21时00分49秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  ZhangRui, v.me-zr@live.cn
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#include "monitor.h"
#include "ui_monitor.h"
#include <QLabel>
#include <QTimer>

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "dataclass.h"

using namespace std;

CpuInfo cpu_info;
MemInfo mem_infoKB,mem_infoMB;
LoadInfo load_info;
BasicInfo basic_info;

extern void TestBasicInfo();
extern void TestCpuInfo();
extern void TestMemInfo();
extern void TestLoadInfo();

monitor::monitor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::monitor)
{
    ui->setupUi(this);

    QTimer *testtimer = new QTimer(this);

    TestBasicInfo();
    ui->ker_ver_contex->setText(basic_info.kernel_version.c_str());
    ui->hostname_contex->setText(basic_info.hostname.c_str());
    ui->process_contex->setText(basic_info.cpu_name.c_str());

    DisplayCpuInfo();

    ui->tabWidget->setTabsClosable(false);

    connect(testtimer,SIGNAL(timeout()),this,SLOT(DisplayLoadInfo()));
    connect(testtimer,SIGNAL(timeout()),this,SLOT(DisplayMemInfo()));

    connect(ui->tabWidget,SIGNAL(tabCloseRequested(int)),this,SLOT(removeSubTab(int)));

    testtimer->start(1000);     // start timer of loadinfo every 1 second
}

void monitor::DisplayCpuInfo()
{
     TestCpuInfo();
     QTableWidget *pCPUtable = new QTableWidget(cpu_info.CpuNum+1,5,0);
     ui->tabWidget->addTab(pCPUtable,"CpuInfo");

     pCPUtable->setItem(0,1,new QTableWidgetItem("Num"));
     pCPUtable->setItem(0,2,new QTableWidgetItem("VendorID"));
     pCPUtable->setItem(0,3,new QTableWidgetItem("Freq(MHz)"));
     pCPUtable->setItem(0,4,new QTableWidgetItem("Cache(KB)"));


     for(int i=0;i<cpu_info.CpuNum;i++) {
         ostringstream o_temp;
         o_temp<<i;

         pCPUtable->setItem(i+1,0,new QTableWidgetItem("Processor"));
         pCPUtable->setItem(i+1,1,new QTableWidgetItem(o_temp.str().c_str()));
         pCPUtable->setItem(i+1,2,new QTableWidgetItem(cpu_info.name.c_str()));
         pCPUtable->setItem(i+1,3,new QTableWidgetItem(cpu_info.freq.c_str()));
         pCPUtable->setItem(i+1,4,new QTableWidgetItem(cpu_info.CapOfCache.c_str()));

     }


}

void monitor::DisplayMemInfo()
{
    TestMemInfo();
    ui->tableWidget_2->setItem(0,0,new QTableWidgetItem(mem_infoKB.MemTotal.c_str()));
    ui->tableWidget_2->setItem(0,1,new QTableWidgetItem(mem_infoKB.MemFree.c_str()));
    ui->tableWidget_2->setItem(0,2,new QTableWidgetItem(mem_infoKB.Buffers.c_str()));
    ui->tableWidget_2->setItem(0,3,new QTableWidgetItem(mem_infoKB.Cached.c_str()));
    ui->tableWidget_2->setItem(0,4,new QTableWidgetItem(mem_infoKB.SwapTotal.c_str()));
    ui->tableWidget_2->setItem(0,5,new QTableWidgetItem(mem_infoKB.SwapFree.c_str()));

    ui->tableWidget_2->setItem(1,0,new QTableWidgetItem(mem_infoMB.MemTotal.c_str()));
    ui->tableWidget_2->setItem(1,1,new QTableWidgetItem(mem_infoMB.MemFree.c_str()));
    ui->tableWidget_2->setItem(1,2,new QTableWidgetItem(mem_infoMB.Buffers.c_str()));
    ui->tableWidget_2->setItem(1,3,new QTableWidgetItem(mem_infoMB.Cached.c_str()));
    ui->tableWidget_2->setItem(1,4,new QTableWidgetItem(mem_infoMB.SwapTotal.c_str()));
    ui->tableWidget_2->setItem(1,5,new QTableWidgetItem(mem_infoMB.SwapFree.c_str()));
}

void monitor::DisplayLoadInfo()
{
    TestLoadInfo();
    ui->lcdNumber_2->display(load_info.m_OneMin);
    ui->lcdNumber_3->display(load_info.m_FivMin);
    ui->lcdNumber_1->display(load_info.m_FiftMin);
}

void TestBasicInfo()
{
    ifstream infile("/proc/version");
    string word;    // Maybe string should be QString
    infile>>word;
    infile>>word;
    infile>>word;
    basic_info.kernel_version = word;

    ifstream infile2("/proc/sys/kernel/hostname");
    infile2>>word;
    basic_info.hostname = word;


    ifstream infile3("/proc/cpuinfo");

    while(infile3>>word) {
        if(word=="name") {
            infile3>>word;
            infile3>>word;
            basic_info.cpu_name = word; // intel

            while(infile3>>word&&word!="stepping") {

                    basic_info.cpu_name+=" ";
                    basic_info.cpu_name+= word; // pentium

            }
            break;
        }

    }

}

void TestCpuInfo()
{
    // getcpuinfo
    ifstream infile("/proc/cpuinfo");
    string word;
    cpu_info.CpuNum = 0;


    while(infile>>word) {
        if(word=="processor") {
            cpu_info.CpuNum++;
            continue;
        }

        if(word=="vendor_id") {
            infile>>word;
            infile>>word;
            cpu_info.name = word;
            continue;
        }
        if(word=="MHz") {
            infile>>word;
            infile>>word;
            cpu_info.freq = word;
            continue;
        }
        if(word=="cache") {
            infile>>word;
            infile>>word;
            infile>>word;
            cpu_info.CapOfCache = word+" KB";
            continue;
        }
    }
}

void TestMemInfo()
{
    ifstream infile("/proc/meminfo");
    string word;
    double db_temp=0;

    // search the function to switch between string and int

    while(infile>>word) {

        istringstream in_temp;
        ostringstream o_temp;

        if(word=="MemTotal:") {
            infile>>word;
            mem_infoKB.MemTotal = word;
            in_temp.clear();
            in_temp.str(word);
            in_temp>>db_temp;
            o_temp<<(db_temp/1024);
            mem_infoMB.MemTotal = o_temp.str();
            continue;
        }
        if(word=="MemFree:") {
            infile>>word;
            mem_infoKB.MemFree = word;
            in_temp.clear();
            in_temp.str(word);
            in_temp>>db_temp;
            o_temp<<(db_temp/1024);
            mem_infoMB.MemFree = o_temp.str();
            continue;
        }
        if(word=="Buffers:") {
            infile>>word;
            mem_infoKB.Buffers = word;
            in_temp.clear();
            in_temp.str(word);
            in_temp>>db_temp;
            o_temp<<(db_temp/1024);
            mem_infoMB.Buffers = o_temp.str();
            continue;
        }
        if(word=="Cached:") {
            infile>>word;
            mem_infoKB.Cached = word;
            in_temp.clear();
            in_temp.str(word);
            in_temp>>db_temp;
            o_temp<<(db_temp/1024);
            mem_infoMB.Cached =o_temp.str() ;
            continue;
        }
        if(word=="SwapTotal:") {
            infile>>word;
            mem_infoKB.SwapTotal = word;
            in_temp.clear();
            in_temp.str(word);
            in_temp>>db_temp;
            o_temp<<(db_temp/1024);
            mem_infoMB.SwapTotal = o_temp.str();
            continue;
        }
        if(word=="SwapFree:") {
            infile>>word;
            mem_infoKB.SwapFree = word;
            in_temp.clear();
            in_temp.str(word);
            in_temp>>db_temp;
            o_temp<<(db_temp/1024);
            mem_infoMB.SwapFree = o_temp.str();
            continue;
        }
    }
}

void TestLoadInfo()
{
    ifstream infile("/proc/loadavg");
    string word;
    double db_temp;
    istringstream in_temp;

    infile>>word;
    in_temp.clear();
    in_temp.str(word);
    in_temp>>db_temp;

    load_info.m_OneMin = db_temp ;

    infile>>word;
    in_temp.clear();
    in_temp.str(word);
    in_temp>>db_temp;

    load_info.m_FivMin = db_temp;

    infile>>word;
    in_temp.clear();
    in_temp.str(word);
    in_temp>>db_temp;

    load_info.m_FiftMin = db_temp;
}

void monitor::removeSubTab(int index)
{
    ui->tabWidget->removeTab(index);
}

monitor::~monitor()
{
    delete ui;
}



