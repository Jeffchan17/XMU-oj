#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iostream>
using namespace std;

vector<int>seq;
vector<int>::iterator point_seq;

int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		int temp;
		cin >> temp;
		seq.push_back(temp);
	}
	sort(seq.begin(), seq.end());
	for(point_seq = seq.begin(); point_seq != seq.end(); point_seq++){
		printf(point_seq == seq.end() - 1 ? "%d\n" : "%d ", *point_seq);
	}
}
