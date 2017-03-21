//
//  MyComplex.cpp
//  Fraction
//
//  Copyright © 2017年 JXH. All rights reserved.
//

#include "MyComplex.h"

// 默认构造函数: MyComplex a;会调用这个方法
MyComplex::MyComplex() {
    realPart = Fraction(0);
    imaginaryPart = Fraction(0);
}

MyComplex::MyComplex(Fraction real) {
    realPart = real;
}

MyComplex::MyComplex(Fraction real, Fraction imaginary) {
    realPart = real;
    imaginaryPart = imaginary;
}

MyComplex::MyComplex(int real, int imaginary) {
    realPart = Fraction(real);
    imaginaryPart = Fraction(imaginary);
}

// 重载加法
MyComplex MyComplex::operator + (const MyComplex &anotherComplex) {
    Fraction real = realPart + anotherComplex.realPart;
    Fraction imaginary = imaginaryPart + anotherComplex.imaginaryPart;
    return MyComplex(real, imaginary);
}

// 重载减法
MyComplex MyComplex::operator - (const MyComplex &anotherComplex) {
    Fraction real = realPart - anotherComplex.realPart;
    Fraction imaginary = imaginaryPart - anotherComplex.imaginaryPart;
    return MyComplex(real, imaginary);
}

// 重载乘法
MyComplex MyComplex::operator * (const MyComplex &anotherComplex) {
    Fraction real = realPart * anotherComplex.realPart - imaginaryPart * anotherComplex.imaginaryPart;
    Fraction imaginary = imaginaryPart * anotherComplex.realPart + realPart * anotherComplex.imaginaryPart;
    return MyComplex(real, imaginary);
}

// 重载除法
MyComplex MyComplex::operator / (const MyComplex &anotherComplex) {
    
    Fraction a,b,c,d;
    a = realPart;
    b = imaginaryPart;
    c = anotherComplex.realPart;
    d = anotherComplex.imaginaryPart;
    
    Fraction real = (a*c + b*d)/(c*c + d*d);
    Fraction imaginary = (b*c - a*d)/(c*c + d*d);
   
    return MyComplex(real, imaginary);
}

// 复数格式
string MyComplex::display() {
    string rst = realPart.display();
    if (imaginaryPart >= 0) {
        rst += "+";
    }
    rst += imaginaryPart.display() + "i";
    return rst;
}
