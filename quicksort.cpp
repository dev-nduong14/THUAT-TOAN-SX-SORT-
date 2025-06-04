#include <stdio.h>
void hv(int *a,int *b){
	int k= *a;
	*a = *b;
	*b = k;
}
int p(int a[],int left ,int high){
	int pivot = a[high];
	int i = left-1;
	for(int j = left; j < high ;j++){
		if(a[j] < pivot){
			i++;
			hv(&a[i],&a[j]);
		}
	}
	hv(&a[i+1],&a[high]);
	return i+1;
}
void quick(int a[],int l,int r){
	if(l < r){
	
	int m = p(a,l,r);
	quick(a,l,m-1);
	quick(a,m+1,r);
}
}
int main(){
	int n;
	int a[100];
	scanf("%d",&n);
	for(int i = 0 ; i < n;i++){
		scanf("%d",&a[i]);
	}
	quick(a,0,n-1);
	for(int i = 0 ; i< n;i++){
		printf("%d ",a[i]);
	}
}
