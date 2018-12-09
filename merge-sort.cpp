#include <iostream>
#include <vector>
#define pb push_back

using namespace std;

vector<int> mergeSort(vector<int> vec);
vector<int> merge(vector<int> vecLeft, vector<int> vecRight);
void printVec(vector<int> vec);

int main(){
	int n; cin>>n;
	vector<int> vec;
	int temp;
	for(int i=0;i<n;i++){
		cin>>temp;
		vec.pb(temp);
	}

	vec = mergeSort(vec);

	printVec(vec);
	return 0;
}

vector<int> mergeSort(vector<int> vec){
	int size = vec.size();
	if(size<2)
		return vec;
	int mid = size/2;
	vector<int> vecLeft, vecRight;
	for(int i=0;i<mid;i++)
		vecLeft.pb(vec[i]);
	for(int i=mid;i<size;i++)
		vecRight.pb(vec[i]);
	vecLeft = mergeSort(vecLeft);
	vecRight = mergeSort(vecRight);
	vec = merge(vecLeft, vecRight);
	return vec;
}

vector<int> merge(vector<int> vecLeft, vector<int> vecRight){
	vector<int> vec;
	int li = 0, ri = 0;
	while(li<vecLeft.size() && ri<vecRight.size()){
		if(vecLeft[li] < vecRight[ri]){
			//cout<<"inserting "<<vecLeft[li]<<" compare "<<vecRight[ri]<<endl;
			vec.pb(vecLeft[li]);
			li++;
		}
		else{
			//cout<<"inserting "<<vecRight[ri]<<" compare "<<vecLeft[li]<<endl;
			vec.pb(vecRight[ri]);
			ri++;
		}
	}
	
	if(li==vecLeft.size()){
		li=ri;
		vecLeft = vecRight;
	}

	while(li<vecLeft.size()){
		//cout<<"LeftInsert "<<vecLeft[li]<<endl;
		vec.pb(vecLeft[li]);
		li++;
	}
	return vec;
}

void printVec(vector<int> vec){
	for(auto ele:vec)
		cout<<ele<<" ";
	cout<<endl;
}