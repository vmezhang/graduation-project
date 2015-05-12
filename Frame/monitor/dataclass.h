// =====================================================================================
// 
//       Filename:  dataclass.h
//
//    Description:  监控模块数据结构
//
//        Version:  1.0
//        Created:  2015年05月11日 21时00分37秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  ZhangRui, v.me-zr@live.cn
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#ifndef DATACLASS_H
#define DATACLASS_H

#include <string>

using namespace std;

class CpuInfo {

public:
    int CpuNum;
    string name;
    string CapOfCache;
    string freq;

};

class MemInfo {
public:
    string MemTotal;
    string MemFree;
    string Buffers;
    string Cached;
    string SwapTotal;
    string SwapFree;
};

class LoadInfo {
public:
    double m_OneMin;
    double m_FivMin;
    double m_FiftMin;
};

class BasicInfo {
public:
    string hostname;
    string kernel_version;
    string cpu_name;
};



#endif // DATACLASS_H
