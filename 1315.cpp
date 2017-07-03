#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#define N 200

using namespace std;

int a[N];
string str;
priority_queue<int, vector<int>, greater<int> > heap;
int ans;

int main(){
	cin >> str;
	for(int i = 0 ; i < str.length(); i++)
		a[str[i]]++;
	for(int i = 0; i < N; i++)
		if(a[i])heap.push(a[i]);
	if(heap.size() == 1){
		cout << heap.top() << endl;
		return 0;
	} 
	while(heap.size() != 1){
		int i = heap.top();
		heap.pop();
		int j = heap.top();
		heap.pop();
		ans += i + j;
		heap.push(i + j);
	}
	cout << ans << endl;
}
