/*
程序设计与算法（二）算法基础 / 第二周 递归 / 汉诺塔问题 
https://www.icourse163.org/learn/PKU-1001894005?tid=1206483202#/learn/content?type=detail&id=1211268441&cid=1213844077&replay=true

有A,B,C三根棍子，将A上N个从小到大叠放的盘子移动到C，移动过程可以利用B，
一次只能移动一个，移动过程中小盘子必须在大盘子上面。

输入
输入一个整数，代表盘子的数量 

输出 
移动过程 

*/

#include <cstdio>

using namespace std;

void Hanoi(int n,char src,char mid,char dest){
	if(n==1){ //如果只需移动一个盘子
		printf("\n%c->%c",src,dest); //直接将盘子从src移动到dest即可 
		return; //递归终止 
	}
	n--;
	//先将n-1个盘子从src移动到mid,移动过程可以利用dest
	Hanoi(n,src,dest,mid);
	//这样就可以将src最底部的盘子移到dest 
	printf("\n%c->%c",src,dest);
	//最后将n-1个盘子从mid移动到dest,移动过程可以利用src
	Hanoi(n,mid,src,dest);
	return; 
}

int main(){
	int n;
	scanf("%d",&n);
	Hanoi(n,'A','B','C');
	return 0; 
}
