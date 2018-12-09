#include <iostream>
#include <vector>
#define pb push_back
using namespace std;

vector<int> selectionSort(vector<int> vec);
void swap(int *a, int *b);
int main(){
	int n;cin>>n;
	vector<int> vec;
	int temp;
	for(int i=0;i<n;i++){
		cin>>temp;
		vec.pb(temp);
	}

	vec = selectionSort(vec);
	for(auto i : vec)
		cout<<i<<" ";
	cout<<endl;
	return 0;
}

vector<int> selectionSort(vector<int> vec){
	int n= vec.size();
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(vec[j]<vec[i])
				swap(&vec[i], &vec[j]);
		}
	}
	return vec;
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

/*
5
5 4 3 2 1
*/