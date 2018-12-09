#include <iostream>
#include <vector>
#define pb push_back

using namespace std;

vector<int> bubbleSort(vector<int> vec);
void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(){
	int n;cin>>n;
	vector<int> vec;
	int temp;
	for(int i=0;i<n;i++){
		cin>>temp;
		vec.pb(temp);
	}

	vec = bubbleSort(vec);
	for(auto i : vec)
		cout<<i<<" ";
	cout<<endl;
	return 0;
}

vector<int> bubbleSort(vector<int> vec){
	int n= vec.size();
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1-i; j++){
			if(vec[j] > vec[j+1])
				swap(&vec[j], &vec[j+1]);
		}
	}
	return vec;
}

/*
10
17 5 12 35 5 12 345 13 4 37
*/