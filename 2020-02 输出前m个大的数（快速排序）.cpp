//根据快速排序改 
#include <cstdio>

void Swap(int &a,int &b){
	int tmp=a;
	a=b;
	b=tmp;
	return;
}

void QuickSort(int a[],int m,int s,int e){
	if(e>s){
		int k=a[s];
		int i=s,j=e;
		while(i!=j){
			while(j>i && a[j]>=k){
				--j;
			}
			Swap(a[i],a[j]);
			while(j>i && a[i]<=k){
				++i;
			}
			Swap(a[i],a[j]);
		} //处理完后，a[i]=k 
		if(i==m){
			return;
		}
		if(i>m){
			QuickSort(a,m,s,i-1);
		}else{
			QuickSort(a,m,i+1,e);
		}
	}
	return;
}

int src[10]={9,3,1,32,12,94,23,11,4,23};
int main(){
	int m=5;
	QuickSort(src,m,0,9); 
	for(int i=0;i<10;i++){
		printf("%d ",src[i]);
	}
	return 0;
}
