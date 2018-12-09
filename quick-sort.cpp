#include <iostream>
#include <vector>
#include <stdlib.h>
#define pb push_back

using namespace std;

void quickSort(int arr[], int start, int end);
int partition(int arr[], int start, int end);
void swap(int* a, int* b);
void printArr(int arr[], int n);

int main(){
	int n; cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	quickSort(arr, 0, n-1);

	printArr(arr, n);
	return 0;
}

void quickSort(int arr[], int start, int end){
	if(start<end){
		int pIndex = partition(arr, start, end);
		quickSort(arr, start, pIndex-1);
		quickSort(arr, pIndex+1, end);
	}
}

int partition(int arr[], int start, int end){
	int randomInd = start + (rand() % (end-start)); // to make it randomised
	swap(&arr[randomInd], &arr[end]);
	int pivot = arr[end];// Using Run Throw Catch
	int catcher = start; // front runner throws and back catcher moves only after catch
	for(int thrower = start; thrower<end; thrower++){
		if(arr[thrower]<pivot){	// if condition is >, sort is reversed
			swap(&arr[thrower], &arr[catcher]);
			catcher++;
		}
	}
	swap(&arr[catcher], &arr[end]);
	return catcher;
}

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void printArr(int arr[], int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}