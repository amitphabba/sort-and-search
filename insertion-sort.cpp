#include <iostream>
#include <vector>
#define pb push_back

using namespace std;

vector<int> insertionSort(vector<int> vec);

int main(){
	int n; cin>>n;
	vector<int> vec;
	int temp;
	for(int i=0;i<n;i++){
		cin>>temp;
		vec.pb(temp);
	}

	vec = insertionSort(vec);

	for(auto i : vec)
		cout<<i<<" ";
	cout<<endl;
	return 0;
}

vector<int> insertionSort(vector<int> vec){
	int n = vec.size();
	for(int i=1;i<n;i++){
		int hole = i;
		int value = vec[i];
		while(hole > 0 && value<vec[hole-1]){
			vec[hole] = vec[hole-1];
			hole--;
		}
		vec[hole] = value;
	}
	return vec;
}
/*
10
17 5 12 35 5 12 345 13 4 37
*/