/*mergeSort
	1. selection, bubble, insertion o(n^2)
	2. merge o(nlogn)
	3. mainly using recursion
--------------------------
	ideas:
		divid an unsorted array into two parts
		keep doing it until there is only two element in the segment
		sort it and merge each segment
		finally get one sorted array
*/

#include <stdio.h>
#include <stdlib.h>
using namespace std;

//merge method --> merge two subarrays of arr[]
void merge(int a[], int l, int m, int r){

	int i, j ,k;
	int n1 = m-l+1;
	int n2 = r-m;

	//temp arrays
	int L[n1];
	int R[n2];

	//copy data into two temp arrays
	for(int i=0; i<n1; i++)
		L[i] = a[l+i];
	for(int j=0; j<n2; j++)
		R[j] = a[m+1+j];

	i=0; //1st array index
	j=0;//2nd array index
	k=l;//merge array index

	while(i<n1 && j<n2){
		if(L[i] <= R[j])
			a[k++] = L[i++];
		else
			a[k++] = R[j++];
	}

	//copy the remain element of L if there is any left
	while(i<n1)
		a[k++] = L[i++];

	//copy the remain element of R if there is any left
	while(i<n2)
		a[k++] = R[j++];
}

//using recursion
void mergeSort(int a[], int l, int r){
	if(l<r){
		int m = l+(r-l)/2;
		mergeSort(a, l, m);
		mergeSort(a, m+1, r);
		merge(a, l, m, r);
	}
	
}


int main(){
	int A[] = {7,8,9,5,3,4,6,2,1};

	for(int i=0; i < sizeof(A)/sizeof(A[0]); i++){
		printf("%d ", A[i]);
	}
	printf("\n");

	mergeSort(A, 0, sizeof(A)/sizeof(A[0]));
	
	for(int i=0; i < sizeof(A)/sizeof(A[0]); i++){
		printf("%d ", A[i]);
	}
	printf("\n");
}