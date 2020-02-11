/*
程序设计与算法（二）算法基础 / 第三周 递归 / 表达式求值 
https://www.icourse163.org/learn/PKU-1001894005?tid=1206483202#/learn/content?type=detail&id=1211268446

输入为四则运算表达式，仅由数字、+、-、*、/、(、)组成，没有空格，要求求其值。
假设运算符结果都是整数。"/"结果也是整数。 

样例输入
(2+3)*(5+7)+9/3 

样例输出
63

*/

#include <cstdio>
#include <iostream>

using namespace std;

int factor_value();
int term_value();
int expression_value(); 

int main(){
	cout << expression_value() << endl;
	return 0;
} 

//求一个表达式的值 
int expression_value(){
	int result=term_value(); //求第一项的值
	while(true){
		char op=cin.peek(); //看第一个字符，不取走 
		if(op=='+'||op=='-'){
			cin.get(); //取走第一个字符
			int value=term_value(); //求第二项的值
			if(op=='+'){
				result+=value;
			}
			else{
				result-=value;
			}
		} 
		else{
			break;
		}
	}
	return result;
} 


//求一个项的值
int term_value(){
	int result=factor_value(); //求第一个因子的值 
	while(true){
		char op=cin.peek();
		if(op=='*'||op=='/'){
			cin.get();
			int value=factor_value();
			if(op=='*'){
				result*=value;
			}
			else{
				result/=value;
			}
		}
		else{
			break;
		}
	}
	return result;
} 

//求一个因子的值 
int factor_value(){
	int result=0;
	char c=cin.peek();
	if(c=='('){
		cin.get(); //取走左括号 
		result=expression_value();
		cin.get(); //取走右括号 
	}
	else{
		//组合数字 
		while(isdigit(c)){ //isdigit 判断某个字符型是否为数字 
			result=10*result+(c-'0'); // c-'0' 将字符转换为数字 
			cin.get();
			c=cin.peek();
		}
	}
	return result;
}

