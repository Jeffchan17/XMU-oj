#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>
#include<iostream>
#include<queue>
#define N 504

using namespace std;

vector<string>name;
vector<int>G[N];
int in[N];
queue<int>q;
vector<int>ans;

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		string temp;
		cin >> temp;
		name.push_back(temp);
	}
	for(int i = 1; i <= n; i++){
		int m;
		cin >> m;
		for(int j = 0; j < m; j++){
			int pre;
			cin >> pre;
			G[pre].push_back(i);
		}
		in[i] = m;
	}
	int flag = 0;
	for(int i = 1; i <= n; i++)if(!in[i])flag = 1;
	if(!flag){
		cout << "Impossible!\n";
		return 0;
	}
	for(int i = 1; i <= n; i++)
		if(!in[i])q.push(i);
	while(!q.empty()){
		int temp = q.front();
		for(vector<int>::iterator pt = G[temp].begin(); pt != G[temp].end(); pt++)
			if(!(--in[*pt]) && !)q.push(*pt);
		q.pop();
		ans.push_back(temp);
	}
	if(ans.size() != n){
		cout << "Impossible!\n";
		return 0;
	}
	for(vector<int>::iterator pt = ans.begin(); pt != ans.end() - 1; pt++)
		cout << name[(*pt)-1] << " ";
	cout << name[*(ans.end()-1)-1] << endl;
}
