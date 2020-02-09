/*
�̳���������㷨�������㷨���� / ��һ�� ö�� / Ϩ������ 
https://www.icourse163.org/learn/PKU-1001894005?tid=1206483202#/learn/content?type=detail&id=1211268435

����
��һ���ɰ�ť��ɵľ�������ÿ����6����ť����5��
ÿ����ť��λ������һյ��
������һ����ť�󣬸ð�ť�Լ���Χλ�ã��ϱߡ��±ߡ���ߡ��ұߣ��ĵƶ���ı�״̬ 

����
��һ����һ��������N����ʾ��Ҫ����İ�����
ÿ��������5����ɣ�ÿ�а���6������
��Щ�����Կո������������0��1
0��ʾ�Ƶĳ�ʼ״̬��Ϩ���
1��ʾ�Ƶĳ�ʼ״̬�ǵ����� 

��������
2
0 1 1 0 1 0
1 0 0 1 1 1
0 0 1 0 0 1
1 0 0 1 0 1
0 1 1 1 0 0
0 0 1 0 1 0
1 0 1 0 1 1
0 0 1 0 1 1
1 0 1 1 0 0
0 1 0 1 0 0

�������
PUZZLE #1
1 0 1 0 0 1
1 1 0 1 0 1
0 0 1 0 1 1
1 0 0 1 0 0
0 1 0 0 0 0
PUZZLE #2
1 0 0 1 1 1
1 1 0 0 0 0
0 0 0 1 0 0
1 1 0 1 0 1
1 0 1 1 0 1

��Ŀ��Դ
POJ1222 
*/

#include <cstdio>
#include <cstring>
using namespace std;

char oriLights[5];
char lights[5];

int GetBit(char c,int i){
	return (c >> i) & 1;
} 

void SetBit(char & c,int i,int v){
	if(v){
		c |= (1 << i); 
	}
	else{
		c &= ~(1 << i);
	}
	return;
}

//λ��ת 
void FlipBit(char & c,int i){
	c ^= (1 << i);
}

void OutputResult(int t,char result[]){
	printf("PUZZLE #%d",t);
	for(int i=0;i<5;i++){
		printf("\n");
		for(int j=0;j<6;j++){
			printf("%d",GetBit(result[i],j));
			if(j<5){
				printf(" ");
			}
		}
	}
}

int main(){
	int n;
	scanf("%d",&n);
	char result[n][5];
	for(int t=0;t<n;t++){
		//���ճ�ʼ���� 
		for(int i=0;i<5;i++){
			for(int j=0;j<6;j++){
				int s;
				scanf("%d",&s);
				SetBit(oriLights[i],j,s);
			} 
		}
		//head����ö�ٵ�һ�еĿ���״̬
		for(int head=0;head<64;head++){
			int switchs = head; //������¼ ��ʱ���� 
			memcpy(lights,oriLights,sizeof(oriLights));
			for(int i=0;i<5;i++){
				result[t][i]=switchs; //�������еĲ�����¼ 
				for(int j=0;j<6;j++){
					//�����ť��Ա��е�Ӱ�� �����С��ң� 
					if(GetBit(switchs,j)){
						FlipBit(lights[i],j);
						if(j>0){
							FlipBit(lights[i],j-1);
						}
						if(j<5){
							FlipBit(lights[i],j+1);
						}
					} 
				}
				//�����ť�����һ�е�Ӱ�� ���ϣ� 
				if(i>0){
					lights[i-1] ^= switchs; 
				}
				//�����ť�����һ�е�Ӱ�� ���£� 
				if(i<4){
					lights[i+1] ^= switchs;
				}
				//�������ŵĿ��أ���һ�еĶ�Ӧλ����Ҫ������ 
				switchs=lights[i];
			}
			if(lights[4]==0){
				break;
			} 
		}
	}
	for(int t=0;t<n;t++){
		OutputResult(t+1,result[t]);
		printf("\n");
	}
	return 0;
}
