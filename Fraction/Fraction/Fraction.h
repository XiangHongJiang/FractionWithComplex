//
//  Fraction.h
//  Fraction
//
//  Copyright © 2017年 JXH. All rights reserved.
//

#ifndef Fraction_h
#define Fraction_h

#include <iostream>
using namespace std;

class Fraction {
private:
    int top;
    int bottom;
    
    // 最简分数：获取分子分母最大公约数，分别除以最大公约数
    void simplestFraction();
    
    // 获取最大公约数
    int fractionGCD(int a, int b);
    
    // 获取绝对值
    int fractionABS(int x);
    
public:
    // 默认构造函数: Franction a;会调用这个方法
    Fraction();
    
    // 只有分子的构造函数: Franction a(5);会调用这个方法
    Fraction(int denominator);
    
    // 带有分子分母的构造函数: Franction a(2,3); 会调用这个方法
    Fraction(int numerator, int denominator);
    
    // 四则运算
    // 重载加法
    Fraction operator + (const Fraction &anotherFraction);
    
    // 重载减法
    Fraction operator - (const Fraction &anotherFraction);
    
    // 重载乘法
    Fraction operator * (const Fraction &anotherFraction);
    
    // 重载除法
    Fraction operator / (const Fraction &anotherFraction);
    
    // 关系运算符
    // 重载小于号
    bool operator < (const Fraction &anotherFraction);
    bool operator < (const int &x);
    bool operator < (const double &x);
    
    // 重载大于号
    bool operator > (const Fraction &anotherFraction);
    bool operator > (const int &x);
    bool operator > (const double &x);
    
    // 重载小于等于号
    bool operator <= (const Fraction &anotherFraction);
    bool operator <= (const int &x);
    bool operator <= (const double &x);
    
    // 重载大于等于号
    bool operator >= (const Fraction &anotherFraction);
    bool operator >= (const int &x);
    bool operator >= (const double &x);
    
    // 重载等于号
    bool operator == (const Fraction &anotherFraction);
    bool operator == (const int &x);
    bool operator == (const double &x);
    
    // 重载不等号
    bool operator != (const Fraction &anotherFraction);
    bool operator != (const int &x);
    bool operator != (const double &x);
    
    // 输入流输出流
    // 重载输入流
    friend istream &operator >> (istream &input, Fraction &f);
    
    // 重载输出流
    friend ostream &operator << (ostream &output, Fraction &f);
    
    // 转化成小数
    double convertToDecimal();
    
    // 小数转化成分数，注意：不能用位数过多的小数，全长（包括整数位数）最好不要超过9位
    // 假设小数部分有k位，则转化规则为 原数值 * 10^k / 10^k
    Fraction convertToFraction(double decimal);
    
    // 分数格式
    std::string display();
};

#endif /* Fraction_h */
