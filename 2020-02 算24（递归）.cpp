/*
����������㷨�������㷨���� / ������ �ݹ� / ��24 
https://www.icourse163.org/learn/PKU-1001894005?tid=1206483202#/learn/content?type=detail&id=1211268449

����4��С��10���������������ʹ�üӼ��˳�4�������Լ����Ű���4�������������õ�һ�����ʽ��
���ڵ��������Ƿ����һ�ַ�ʽʹ�õ��ı��ʽ�Ľ������24��
�������5��5��5��1������֪��5*(5-1/5)=24 

����
����������У�ÿ�и���һ��������ݣ�����4��С��10����������
���һ��������ݰ���4��0����ʾ����Ľ������������ݲ��ô��� 

��� 
��ÿһ��������ݣ����һ�У�������Եõ�24�������YES�������������NO���� 

��������
5 5 5 1
1 1 4 2
0 0 0 0 

�������
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

//������a�����n����������24 
bool count24(double a[],int n){
	if(n==1){
		//������������'=='�Ƚϴ�С 
		return (isZero(a[0]-24));
	}
	
	double b[5];
	int n_temp=n-1;
	for(int i=0;i<n_temp;i++){
		for(int j=i+1;j<n;j++){
			//��ʣ��m������m=n-2
			int m=0; 
			//������������b[] 
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
