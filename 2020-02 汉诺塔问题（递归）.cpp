/*
����������㷨�������㷨���� / �ڶ��� �ݹ� / ��ŵ������ 
https://www.icourse163.org/learn/PKU-1001894005?tid=1206483202#/learn/content?type=detail&id=1211268441&cid=1213844077&replay=true

��A,B,C�������ӣ���A��N����С������ŵ������ƶ���C���ƶ����̿�������B��
һ��ֻ���ƶ�һ�����ƶ�������С���ӱ����ڴ��������档

����
����һ���������������ӵ����� 

��� 
�ƶ����� 

*/

#include <cstdio>

using namespace std;

void Hanoi(int n,char src,char mid,char dest){
	if(n==1){ //���ֻ���ƶ�һ������
		printf("\n%c->%c",src,dest); //ֱ�ӽ����Ӵ�src�ƶ���dest���� 
		return; //�ݹ���ֹ 
	}
	n--;
	//�Ƚ�n-1�����Ӵ�src�ƶ���mid,�ƶ����̿�������dest
	Hanoi(n,src,dest,mid);
	//�����Ϳ��Խ�src��ײ��������Ƶ�dest 
	printf("\n%c->%c",src,dest);
	//���n-1�����Ӵ�mid�ƶ���dest,�ƶ����̿�������src
	Hanoi(n,mid,src,dest);
	return; 
}

int main(){
	int n;
	scanf("%d",&n);
	Hanoi(n,'A','B','C');
	return 0; 
}
