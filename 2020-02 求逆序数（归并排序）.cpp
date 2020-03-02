//根据归并排序改 
#include <cstdio>
int g_result=0;

void Merge(int a[],int i,int m,int j,int tmp[]){
	int p0=0,p1=i,p2=m+1;
	while(p1<=m && p2<=j){
		if(a[p1]<=a[p2]){
			tmp[p0++]=a[p1++]; 
		}
		else{
			g_result+=(p2-m);
			tmp[p0++]=a[p2++];
		}
	}
	while(p1<=m){
		tmp[p0++]=a[p1++];
	}
	while(p2<=j){
		tmp[p0++]=a[p2++];
	}
	p0=0;
	while(i<=j){
		a[i++]=tmp[p0++];
	}
}

void MergeSort(int a[],int i,int j,int tmp[]){
	if(j>i){
		int m=i+(j-i)/2;
		MergeSort(a,i,m,tmp);
		MergeSort(a,m+1,j,tmp);
		Merge(a,i,m,j,tmp);
	}
	return;
}

int src[8]={6,1,2,7,3,4,8,5};
int tmp[8];
int main(){
	for(int i=0;i<8;i++){
		printf("%d ",src[i]);
	}
	MergeSort(src,0,8-1,tmp);
	printf("\n含有%d个逆序数\n排序后：",g_result);
	for(int i=0;i<8;i++){
		printf("%d ",src[i]);
	}
	return 0;
} 
