#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define N 201

using namespace std;

int f[N][N];
int a[N];

int main(){
	int n;
	cin >> n;
	for(int i = 0; i <= n; i++)cin >> a[i];
	for(int i = 1; i < n; i++)f[i][i+1] = a[i-1] * a[i] * a[i+1];
	for(int k = 2; k < n; k++){
		for(int l = 1; l + k <= n; l++){
			int r = l + k;
			for(int i = 0; l+i+1 <= r; i++){
				f[l][r] = (f[l][r] == 0 ? f[l][l+i] + f[l+i+1][r] + a[l-1] * a[l+i] * a[r] : min(f[l][l+i] + f[l+i+1][r] + a[l-1] * a[l+i] * a[r], f[l][r]));
			}
		}
	}
	cout << f[1][n] << endl;
}
