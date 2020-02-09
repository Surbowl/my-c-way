/*
程序设计实习MOOC / 程序设计与算法（一）第5周测验(2019秋季) 006:图像模糊处理
http://cxsjsxmooc.openjudge.cn/2019t1fall5/006/

总时间限制: 1000ms 内存限制: 65536kB

描述
给定n行m列的图像各像素点的灰度值，要求用如下方法对其进行模糊化处理：
1. 四周最外侧的像素点灰度值不变；
2. 中间各像素点新灰度值为该像素点及其上下左右相邻四个像素点原灰度值的平均（舍入到最接近的整数）。

输入
第一行包含两个整数n和m，表示图像包含像素点的行数和列数。1 <= n <= 100，1 <= m <= 100。
接下来n行，每行m个整数，表示图像的每个像素点灰度。相邻两个整数之间用单个空格隔开，每个元素均在0~255之间。 

输出
n行，每行m个整数，为模糊处理后的图像。相邻两个整数之间用单个空格隔开。

样例输入
4 5
100 0 100 0 50
50 100 200 0 0
50 50 100 100 200
100 100 50 50 100

样例输出
100 0 100 0 50
50 80 100 60 0
50 80 100 90 200
100 100 50 50 100
*/

#include <cstdio>
#include <cmath>

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int img[n][m];
	for(int n_i=0;n_i<n;n_i++){
		for(int m_i=0;m_i<m;m_i++){
			scanf("%d",&img[n_i][m_i]);
		}
	}
	
	int vagueImg[n][m];
	int n_p=n-1;
	int m_p=m-1;

	for(int n_i=0;n_i<n;n_i++){
		for(int m_i=0;m_i<m;m_i++){
			if(n_i==0 || n_i==n_p || m_i==0 || m_i==m_p){
				vagueImg[n_i][m_i]=img[n_i][m_i];
				continue;
			}
			int *p=&img[n_i][m_i];
			vagueImg[n_i][m_i]=round((float)(*p+*(p+1)+*(p-1)+*(p+m)+*(p-m))/5.0);
		}
	}
	
	for(int n_i=0;n_i<n;n_i++){
		for(int m_i=0;m_i<m;m_i++){
			printf("%d ",vagueImg[n_i][m_i]);
		}
		if(n_i<n_p){
			printf("\n");
		}
	}
	
	return 0;
}
