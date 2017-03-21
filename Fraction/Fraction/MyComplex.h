//
//  MyComplex.h
//  Fraction
//
//  Copyright © 2017年 JXH. All rights reserved.
//

#ifndef MyComplex_h
#define MyComplex_h

#include <iostream>
#include "Fraction.h"

class MyComplex {
private:
    Fraction realPart;
    Fraction imaginaryPart;
    
public:
    
    // 默认构造函数: MyComplex a;会调用这个方法
    MyComplex();
    
    MyComplex(Fraction real);
    
    MyComplex(Fraction real, Fraction imaginary);
    
    MyComplex(int real, int imaginary);
    
    // 重载加法
    MyComplex operator + (const MyComplex &anotherComplex);
    
    // 重载减法
    MyComplex operator - (const MyComplex &anotherComplex);
    
    // 重载乘法
    MyComplex operator * (const MyComplex &anotherComplex);
    
    // 重载除法
    MyComplex operator / (const MyComplex &anotherComplex);
    
    // 复数格式
    string display();
};

#endif /* MyComplex_h */
