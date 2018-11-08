#include <stdio.h>
#include <stdlib.h>

void MergeSort(int A[], int p, int r);
void Merge(int A[], int p, int q, int r);


int main(){
	
	int arr[9] = {1 , 3, 8, 5, 10, 2, 20, 9 , 30};
	
	MergeSort(arr, 0, 8);
	
	int i;
	for(i = 0; i < 9; i++)
		printf("%d ", arr[i]);
	
}

void MergeSort(int A[], int p, int r){
	if(p<r){
		int mid = (p+r)/2;
		MergeSort(A, p, mid);
		MergeSort(A, mid+1, r);
		Merge(A, p, mid, r);
	}
}

void Merge(int A[], int p, int q, int r){
	int i = p;
	int j = q+1;
	int t = 0;
	int *temp;
	temp = (int*)malloc(sizeof(int)*100);
	while(i<=q && j <= r){
		if(A[i] <= A[j]) temp[t++] = A[i++];
		else temp[t++] = A[j++];
	}
	while(i<=q) temp[t++] = A[i++];
	while(j<=r) temp[t++] = A[j++];
	for(i=p, t=0; i<=r; i++)
		A[i] = temp[t++];
}
