//
//  main.cpp
//  Fraction
//
//  Copyright © 2017年 JXH. All rights reserved.
//
#include <iostream>
#include "Fraction.h"
#include "MyComplex.h"

using namespace std;

//输入提示
int inputWindow(){
    
    cout << "请选择数据类型:1.分数 2.复数" << endl;
    int inputType = 0;
    cin >> inputType;
    
    while (inputType != 1 && inputType != 2) {
        
        cout << "输入错误,请重新输入数据类型：" << endl;
        cin >> inputType;
    }
    return inputType;
    
}
//分数输入
Fraction inputFractionMethod(){

    cout << "请输入分数的分子和分母：用空格或换行分隔" << endl;
    Fraction a;
    cin >> a;
    cout << "您输入的分数为："<< a << endl;

    return a;
    
}
//分数计算
Fraction calculateFraction(Fraction a,Fraction b,int control){

    Fraction result;
    switch (control) {
        case 1:
            result = (a+b);
            break;
        case 2:
            result = (a-b);
            break;
        case 3:
            result = (a*b);
            break;
        case 4:
            result = (a/b);
            break;
        default:
            break;
    }
    return result;
}
//复数输入
MyComplex inputComplexMethod(){
    Fraction a,b;
    cout << "请输入复数的实部(分数)和虚部（分数）：用空格或换行分隔" << endl;
    cin >> a >> b;
    
    MyComplex cc (a,b);
    cout << "您输入的复数为："<< cc.display() << endl;

    return cc;
}

//复数计算
MyComplex calculateComplex(MyComplex a,MyComplex b,int control){

    switch (control) {
        case 1:
            return (a+b);
            break;
        case 2:
            return (a-b);
            break;
        case 3:
            return (a*b);
            break;

        default:
            return (a/b);

            break;
    }
}

//符号输入
int inputControl(){

    cout << "请继续你的操作(输入‘0’重置)：+ - * /" << endl;
    char c;
    int controlType = 0;
    cin >> c;
    switch (c) {
        case '+':
            controlType = 1;
            break;
        case '-':
            controlType = 2;
            break;
        case '*':
            controlType = 3;
            break;
        case '/':
            controlType = 4;
            break;
            case '0':
            controlType = 5;
            break;
            
        default:
            controlType = 0;
            break;
    }

    while (controlType == 0) {
        
        cout << "输入错误,请重新输入你需要的操作：" << endl;
        
        cin >> c;
        switch (c) {
            case '+':
                controlType = 1;
                break;
            case '-':
                controlType = 2;
                break;
            case '*':
                controlType = 3;
                break;
            case '/':
                controlType = 4;
                break;
                
            default:
                controlType = 0;
                break;
        }

    }
    return controlType;
    
}


int main(int argc, const char * argv[]) {
    
    //变量声明
    //分数、复数
    Fraction resultFraction,tempFraction;
    MyComplex resultComplex,tempComplex;
    
    //菜单界面
    cout << "菜单" << endl;
    //标志是否已经有计算值
    bool resultFractionFlag = false;
    bool resultComplexFlag = false;
    
    //运算
    int controlType = 0;
    
    //是否输入了复数
    bool haveComplex = false;
    
    while (1) {
        
        //如果有上一次（复数或者分数）的计算结果，直接输入符号
        if (resultFractionFlag || resultComplexFlag) {
            
            //输入符号
            controlType = inputControl();
            
            //重置
            if (controlType == 5) {
                
                resultFractionFlag = false;
                resultComplexFlag = false;
                haveComplex = false;
                continue;
            }
            
            //输入数
            int inputType = inputWindow();
            
            if (inputType == 1){//分数
                
                tempFraction = inputFractionMethod();
                haveComplex = false;

            }
            else if (inputType == 2){//复数
               
                tempComplex = inputComplexMethod();
                
                haveComplex = true;

            }else{//整数
//                int a;
//                cin >> a;
//                Fraction temp(a);
//                tempFraction = temp;
            }

            //计算结果
            if (haveComplex || resultComplexFlag) {//只要有复数的计算,或者上次结果是复数
             
                //1.分数 + 复数 ： 满足了+复数或者结果是复数： 上次结果是分数，则这次输入的是复数
                if (resultFractionFlag) {//如果之前的值是一个分数，现在输入的是一个复数
                    
                    resultComplex = calculateComplex(MyComplex(resultFraction,0), tempComplex, controlType);
                    cout << endl << "运算结果为（分数 & 复数）：" << resultComplex.display() << endl << endl;
                    resultComplexFlag = true;
                    resultFractionFlag = false;
                    
                }else{
                    //2.复数 + 复数： 上次结果是复数
                    if (haveComplex) {
                        
                        resultComplex = calculateComplex(resultComplex, tempComplex, controlType);
                        cout << endl << "运算结果为（复数 & 复数）：" << resultComplex.display() << endl << endl;
                        resultComplexFlag = true;
                        resultFractionFlag = false;
                        
                    }else{ //3.复数 + 分数： 上次结果是复数
                        resultComplex = calculateComplex(resultComplex, MyComplex(tempFraction,0), controlType);
                        cout << endl << "运算结果为（复数 & 分数）：" << resultComplex.display() << endl << endl;
                        resultComplexFlag = true;
                        resultFractionFlag = false;
                    }
                }
                
            }else{//无复数
            
                resultFraction = calculateFraction(resultFraction, tempFraction, controlType);
                cout << endl << "运算结果为：" << resultFraction << endl << endl;
                cout << "是否化为小数:1.是 2.否" << endl;
                
                int transToDecimal;
                cin >>transToDecimal;
                if (transToDecimal == 1) {
                    cout << resultFraction <<" 化为小数为：" << resultFraction.convertToDecimal() << endl;
                }
                
                resultFractionFlag = true;
            }
            
        }else {
        
            //输入数
            int inputType = inputWindow();
            
            if (inputType == 1){//分数
                
                tempFraction = inputFractionMethod();
                //保存数
                resultFraction = tempFraction;
                resultFractionFlag = 1;
                haveComplex = false;
            }
            else{//复数
                
                tempComplex = inputComplexMethod();
                //保存数
                resultComplex = tempComplex;
                resultComplexFlag = 1;
                haveComplex = true;
            }
        }
        
}

//    Fraction a;
//    Fraction b(-5);
//    Fraction c(-20,4);
//    cout << "a = " << a.display() << endl;
//    cout << "b = " << b.display() << endl;
//    cout << "c = " << c.display() << endl;
//    cout << "b + c = " << (b + c).display() << endl;
//    cout << "b - c = " << (b - c).display() << endl;
//    cout << "b * c = " << (b * c).display() << endl;
//    cout << "b / c = " << (b / c).display() << endl;
//    cout << "b < c : " << (b < c) << endl;
//    cout << "b > c : " << (b > c) << endl;
//    cout << "b <= c : " << (b <= c) << endl;
//    cout << "b >= c : " << (b >= c) << endl;
//    cout << "b == c : " << (b == c) << endl;
//    cout << "b != c : " << (b != c) << endl;
//    Fraction a,b;
//    cin >> a >> b;
//    cout << "a = " << a << endl;
//    cout << "b = " << b << endl;
//    Fraction c;
//    c = a - b;
//    cout << "a - b = " << c << endl;
//    cout << c.convertToDecimal() << endl;
//    c.convertToFraction(-11.5123123);
//    cout << c << endl;
//    MyComplex d(a, b);
//    cout << d.display() << endl;
    

//
//    Fraction xx, yy(1, 1);//分数 1/1
//    MyComplex cc(xx, yy);//复数 1+i
//    MyComplex dd(0, 1);//复数
//    MyComplex ee = cc * dd;
//    cout << ee.display() << endl;
//    
//    MyComplex ii(-10, 20);
//    MyComplex jj(20, 30);
//    MyComplex kk = ii + jj;
//    cout << kk.display() << endl;
//    MyComplex mm = ii - jj;
//    cout << mm.display() << endl;
    return 0;
}
