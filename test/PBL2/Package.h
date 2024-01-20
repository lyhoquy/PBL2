// 2 cau lenh dau voi cau lenh cuoi cua moi Package laf de tranh bi loi definition 

#ifndef PACKAGE_H
#define PACKAGE_H

#include <iostream>

class Package
{
public:
    virtual void ChangePrice() = 0;
    // virtual int TotalPrice() = 0;
};

#endif

