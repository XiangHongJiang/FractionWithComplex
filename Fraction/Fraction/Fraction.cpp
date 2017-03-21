//
//  Fraction.cpp
//  Fraction
//
//  Copyright © 2017年 JXH. All rights reserved.
//

#include "Fraction.h"

// 最简分数：获取分子分母最大公约数，分别除以最大公约数
void Fraction::simplestFraction() {
    bool isNegative = ((top < 0 && bottom > 0) || (top > 0 && bottom < 0));
    top = fractionABS(top);
    bottom = fractionABS(bottom); // 把分子分母都变成正数，主要是保证分母是正数，方便运算
    int maxFactor = fractionGCD(top, bottom);
    top = top / maxFactor;
    bottom = bottom / maxFactor;
    if (isNegative) { // 如果是个负数就把负号挂在分子上
        top = -top;
    }
}

// 获取最大公约数
int Fraction::fractionGCD(int a, int b) {
    return b == 0 ? a : fractionGCD(b, a % b);
}

// 获取绝对值
int Fraction::fractionABS(int x) {
    return x < 0 ? -x : x;
}

// 默认构造函数: Franction a;会调用这个方法
Fraction::Fraction() {
    top = 0;
    bottom = 1;
}

// 只有分子的构造函数: Franction a(5);会调用这个方法
Fraction::Fraction(int denominator) {
    top = denominator;
    bottom = 1;
}

// 带有分子分母的构造函数: Franction a(2,3); 会调用这个方法
Fraction::Fraction(int numerator, int denominator) {
    top = numerator;
    bottom = denominator;
    simplestFraction(); // 最简分数
}

// 四则运算
// 重载加法
Fraction Fraction::operator + (const Fraction &anotherFraction) {
    int denominator = bottom * anotherFraction.bottom;
    int numerator = top * anotherFraction.bottom + bottom * anotherFraction.top;
    return Fraction(numerator, denominator);
}

// 重载减法
Fraction Fraction::operator - (const Fraction &anotherFraction) {
    int denominator = bottom * anotherFraction.bottom;
    int numerator = top * anotherFraction.bottom - bottom * anotherFraction.top;
    return Fraction(numerator, denominator);
}

// 重载乘法
Fraction Fraction::operator * (const Fraction &anotherFraction) {
    int denominator = bottom * anotherFraction.bottom;
    int numerator = top * anotherFraction.top;
    return Fraction(numerator, denominator);
}

// 重载除法
Fraction Fraction::operator / (const Fraction &anotherFraction) {
    int denominator = bottom * anotherFraction.top;
    int numerator = top * anotherFraction.bottom;
    return Fraction(numerator, denominator);
}

// 关系运算符
// 重载小于号
bool Fraction::operator < (const Fraction &anotherFraction) {
    int thisNumerator = top * anotherFraction.bottom;
    int anotherNumerator = bottom * anotherFraction.top;
    return thisNumerator < anotherNumerator;
}

bool Fraction::operator < (const int &x) {
    Fraction tmp(x * bottom, bottom);
    return *this < tmp;
}

bool Fraction::operator < (const double &x) {
    Fraction tmp;
    tmp.convertToFraction(x);
    return *this < tmp;
}

// 重载大于号
bool Fraction::operator > (const Fraction &anotherFraction) {
    int thisNumerator = top * anotherFraction.bottom;
    int anotherNumerator = bottom * anotherFraction.top;
    return thisNumerator > anotherNumerator;
}

bool Fraction::operator > (const int &x) {
    Fraction tmp(x * bottom, bottom);
    return *this > tmp;
}

bool Fraction::operator > (const double &x) {
    Fraction tmp;
    tmp.convertToFraction(x);
    return *this > tmp;
}

// 重载小于等于号
bool Fraction::operator <= (const Fraction &anotherFraction) {
    int thisNumerator = top * anotherFraction.bottom;
    int anotherNumerator = bottom * anotherFraction.top;
    return thisNumerator <= anotherNumerator;
}

bool Fraction::operator <= (const int &x) {
    Fraction tmp(x * bottom, bottom);
    return *this <= tmp;
}

bool Fraction::operator <= (const double &x) {
    Fraction tmp;
    tmp.convertToFraction(x);
    return *this <= tmp;
}

// 重载大于等于号
bool Fraction::operator >= (const Fraction &anotherFraction) {
    int thisNumerator = top * anotherFraction.bottom;
    int anotherNumerator = bottom * anotherFraction.top;
    return thisNumerator >= anotherNumerator;
}

bool Fraction::operator >= (const int &x) {
    Fraction tmp(x * bottom, bottom);
    return *this >= tmp;
}

bool Fraction::operator >= (const double &x) {
    Fraction tmp;
    tmp.convertToFraction(x);
    return *this >= tmp;
}

// 重载等于号
bool Fraction::operator == (const Fraction &anotherFraction) {
    int thisNumerator = top * anotherFraction.bottom;
    int anotherNumerator = bottom * anotherFraction.top;
    return thisNumerator == anotherNumerator;
}

bool Fraction::operator == (const int &x) {
    Fraction tmp(x * bottom, bottom);
    return *this == tmp;
}

bool Fraction::operator == (const double &x) {
    Fraction tmp;
    tmp.convertToFraction(x);
    return *this == tmp;
}

// 重载不等号
bool Fraction::operator != (const Fraction &anotherFraction) {
    int thisNumerator = top * anotherFraction.bottom;
    int anotherNumerator = bottom * anotherFraction.top;
    return thisNumerator != anotherNumerator;
}

bool Fraction::operator != (const int &x) {
    Fraction tmp(x * bottom, bottom);
    return *this != tmp;
}

bool Fraction::operator != (const double &x) {
    Fraction tmp;
    tmp.convertToFraction(x);
    return *this != tmp;
}

// 输入流输出流
// 重载输入流
istream &operator >> (istream &input, Fraction &f) {
    input >> f.top >> f.bottom;
    f.simplestFraction();
    return input;
}

// 重载输出流
ostream &operator << (ostream &output, Fraction &f) {
    output << f.display();
    return output;
}

// 转化成小数
double Fraction::convertToDecimal() {
    return top * 1.0 / bottom;
}

// 小数转化成分数，注意：不能用位数过多的小数，全长（包括整数位数）最好不要超过9位
// 假设小数部分有k位，则转化规则为 原数值 * 10^k / 10^k
Fraction Fraction::convertToFraction(double decimal) {
    string str = to_string(decimal); // 小数转化成字符串
    size_t found = str.find('.'); // 查找小数点
    if (found != string::npos) { // 找见小数点
        int length = (int)(str.length() - found) - 1; // 小数的位数 length
        bottom = 1;
        while (length) { // 求分母 10^length
            bottom *= 10;
            length--;
        }
        top = (int)(decimal * bottom); // 求分子 decimal * 10^length
    }
    else { // 没有小数点，即整数
        top = (int)decimal;
        bottom = 1;
    }
    simplestFraction();  // 化简
    return *this;
}

// 分数格式
string Fraction::display() {
    return to_string(top) + "/" + to_string(bottom);
}
