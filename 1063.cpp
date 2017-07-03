#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#define N 13

using namespace std; 

int n, a[N][N], ans, seq[N];

void f(int x, int tmp){
	if(x == n+1){
		tmp += a[seq[n]][seq[1]];
		ans = min(ans, tmp);
		//for(int i = 1; i <= n; i++)cout << seq[i] << " ";
		//cout << endl;
		return;
	}
	if(tmp >= ans)return;
	for(int i = x; i <= n; i++){
		swap(seq[i], seq[x]);
		f(x+1, tmp + a[seq[x]][seq[x-1]]);
		swap(seq[i], seq[x]);
	}
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin >> a[i][j];
	for(int i = 1; i <= n-1; i++)
		ans += a[i][i+1];
	for(int i = 1; i <= n; i++)seq[i] = i;
	ans += a[n][1];
	f(1, 0);
	cout << ans << endl;
}
