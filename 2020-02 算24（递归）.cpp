/*
程序设计与算法（二）算法基础 / 第三周 递归 / 算24 
https://www.icourse163.org/learn/PKU-1001894005?tid=1206483202#/learn/content?type=detail&id=1211268449

给出4个小于10的正整数，你可以使用加减乘除4种运算以及括号把这4个数连接起来得到一个表达式。
现在的问题是是否存在一种方式使得到的表达式的结果等于24。
比如对于5，5，5，1，我们知道5*(5-1/5)=24 

输入
输入包括多行，每行给出一组测试数据，包括4个小于10的正整数。
最后一组测试数据包括4个0，表示输入的结束，这种数据不用处理 

输出 
对每一组测试数据，输出一行，如果可以得到24，输出“YES”；否则输出“NO”。 

样例输入
5 5 5 1
1 1 4 2
0 0 0 0 

样例输出
YES
NO

*/

#include <cstdio>
#include <cmath>

using namespace std;

double a[5];
#define EPS 1e-6

bool isZero(double x){
	return fabs(x)<=EPS;
}

//用数组a里面的n个数，计算24 
bool count24(double a[],int n){
	if(n==1){
		//浮点数不能用'=='比较大小 
		return (isZero(a[0]-24));
	}
	
	double b[5];
	int n_temp=n-1;
	for(int i=0;i<n_temp;i++){
		for(int j=i+1;j<n;j++){
			//还剩下m个数，m=n-2
			int m=0; 
			//把其余数放入b[] 
			for(int k=0;k<n;k++){
				if(k!=i&&k!=j){
					b[m++]=a[k];
				}
			} 
			int m_temp=m+1;
			b[m]=a[i]+a[j];
			if(count24(b,m_temp)){
				return true;
			}
			b[m]=a[i]-a[j];
			if(count24(b,m_temp)){
				return true;
			}
			b[m]=a[j]+a[i];
			if(count24(b,m_temp)){
				return true;
			}
			b[m]=a[i]*a[j];
			if(count24(b,m_temp)){
				return true;
			}
			if(!isZero(a[j])){
				b[m]=a[i]/a[j];
				if(count24(b,m_temp)){
					return true;
				}
			}
			if(!isZero(a[i])){
				b[m]=a[j]/a[i];
				if(count24(b,m_temp)){
					return true;
				}
			}
		}
	}
	return false;
}

int main(){
	int a,b,c,d;
	while(true){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if((a+b+c+d)==0){
			break;
		}
		double arr[4]={a,b,c,d};
		if(count24(arr,4)){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
}
