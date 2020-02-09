/*
程程序设计与算法（二）算法基础 / 第一周 枚举 / 熄灯问题 
https://www.icourse163.org/learn/PKU-1001894005?tid=1206483202#/learn/content?type=detail&id=1211268435

描述
有一个由按钮组成的矩阵，其中每行有6个按钮，共5行
每个按钮的位置上有一盏灯
当按下一个按钮后，该按钮以及周围位置（上边、下边、左边、右边）的灯都会改变状态 

输入
第一行是一个正整数N，表示需要解决的案例数
每个案例由5行组成，每行包括6个数字
这些数字以空格隔开，可以是0或1
0表示灯的初始状态是熄灭的
1表示灯的初始状态是点亮的 

样例输入
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

样例输出
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

题目来源
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

//位翻转 
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
		//接收初始数据 
		for(int i=0;i<5;i++){
			for(int j=0;j<6;j++){
				int s;
				scanf("%d",&s);
				SetBit(oriLights[i],j,s);
			} 
		}
		//head用来枚举第一行的开关状态
		for(int head=0;head<64;head++){
			int switchs = head; //操作记录 临时变量 
			memcpy(lights,oriLights,sizeof(oriLights));
			for(int i=0;i<5;i++){
				result[t][i]=switchs; //保存这行的操作记录 
				for(int j=0;j<6;j++){
					//点击按钮后对本行的影响 （左、中、右） 
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
				//点击按钮后对上一行的影响 （上） 
				if(i>0){
					lights[i-1] ^= switchs; 
				}
				//点击按钮后对下一行的影响 （下） 
				if(i<4){
					lights[i+1] ^= switchs;
				}
				//本行亮着的开关，下一行的对应位置需要被按下 
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
