#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define N 1022

using namespace std;

int f[3][N], a[N], b[N], t1[N], t2[N];

int main(){
	int n;
	cin >> n;
	cin >> f[1][0] >> f[2][0] >> f[1][n+1] >> f[2][n+1];
	for(int i = 1; i <= n; i++)cin >> a[i];
	for(int i = 1; i <= n; i++)cin >> b[i];
	for(int i = 1; i <= n-1; i++)cin >> t1[i];
	for(int i = 1; i <= n-1; i++)cin >> t2[i];
	f[1][1] = f[1][0] + a[1];
	f[2][1] = f[2][0] + b[1];
	for(int i = 2; i <= n; i++){
		f[1][i] = f[1][i-1] + a[i];
		f[2][i] = f[2][i-1] + b[i];
		f[1][i] = min(f[1][i], f[2][i-1] + t2[i-1] + a[i]);
		f[2][i] = min(f[2][i], f[1][i-1] + t1[i-1] + b[i]);
	}
	cout << min(f[1][n]+f[1][n+1], f[2][n]+f[2][n+1]) << endl;
}
