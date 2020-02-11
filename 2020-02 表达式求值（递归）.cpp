/*
����������㷨�������㷨���� / ������ �ݹ� / ���ʽ��ֵ 
https://www.icourse163.org/learn/PKU-1001894005?tid=1206483202#/learn/content?type=detail&id=1211268446

����Ϊ����������ʽ���������֡�+��-��*��/��(��)��ɣ�û�пո�Ҫ������ֵ��
����������������������"/"���Ҳ�������� 

��������
(2+3)*(5+7)+9/3 

�������
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

//��һ�����ʽ��ֵ 
int expression_value(){
	int result=term_value(); //���һ���ֵ
	while(true){
		char op=cin.peek(); //����һ���ַ�����ȡ�� 
		if(op=='+'||op=='-'){
			cin.get(); //ȡ�ߵ�һ���ַ�
			int value=term_value(); //��ڶ����ֵ
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


//��һ�����ֵ
int term_value(){
	int result=factor_value(); //���һ�����ӵ�ֵ 
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

//��һ�����ӵ�ֵ 
int factor_value(){
	int result=0;
	char c=cin.peek();
	if(c=='('){
		cin.get(); //ȡ�������� 
		result=expression_value();
		cin.get(); //ȡ�������� 
	}
	else{
		//������� 
		while(isdigit(c)){ //isdigit �ж�ĳ���ַ����Ƿ�Ϊ���� 
			result=10*result+(c-'0'); // c-'0' ���ַ�ת��Ϊ���� 
			cin.get();
			c=cin.peek();
		}
	}
	return result;
}

