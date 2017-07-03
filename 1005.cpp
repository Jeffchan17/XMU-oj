#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>

using namespace std;

vector<int> seq;
vector<int>::iterator pointer;
vector<bool> vis;

void f(int x, int n){
	if(x == n + 1){
		for(pointer = seq.begin(); pointer != seq.end(); pointer++)
			printf(pointer == seq.end() - 1 ? "%d\n": "%d ", *pointer);
	}
	for(int i = 0; i < n; i++){
		if(!vis[i]){
			vis[i] = true;
			seq.push_back(i + 1);
			f(x + 1, n );
			vis[i] = false;
			seq.pop_back();
		}
	}
}

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)vis.push_back(false);
	f(1, n);
}
