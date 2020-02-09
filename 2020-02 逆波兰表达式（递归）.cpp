/*
程序设计与算法（二）算法基础 / 第二周 递归 / 逆波兰表达式 
https://www.icourse163.org/learn/PKU-1001894005?tid=1206483202#/learn/content?type=detail&id=1211268443&sm=1

逆波兰表达式是一种把运算符前置的算术表达式，例如普通的
表达式2 + 3的逆波兰表示法为+ 2 3。逆波兰表达式的优点是运算
符之间不必有优先级关系，也不必用括号改变运算次序，例如(2 +
3) * 4的逆波兰表示法为* + 2 3 4。本题求解逆波兰表达式的值，
其中运算符包括+ - * /四个。


输入
输入为一行，其中运算符和运算数之间都用空格分隔，运算数是浮点数。 

输出 
输出为一行，表达式的值。 

样例输入
* + 11.0 12.0 + 24.0 35.0 

样例输出
1357.000000

提示
(11.0+12.0)*(24.0+35.0) 

*/

#include <cstdio>
#include <cstdlib>

double exp(){
	char s[20];
	scanf("%s",s); //%s的默认分隔符是空格
	switch(s[0]){
		case '+': return exp()+exp();
		case '-': return exp()-exp();
		case '*': return exp()*exp();
		case '/': return exp()/exp();
		default : return atof(s); //atof函数将字串转换成浮点型数 
		break; 
	}
} 

int main(){
	printf("%lf",exp());
	return 0;
} 
