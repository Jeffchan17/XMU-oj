#include<cstdio>
#include<cstdlib>
#include<iostream>
#define N 6

using namespace std;

int a[N], b[N] = {500, 100, 50, 10, 5, 1}, cnt;

int main(){
	int n;
	cin >> n;
	int left = 1000 - 25 * n;
	for(int i = 0; i < 6; i++)cin >> a[i];
	for(int i = 0; i < 6; i++){
		while(a[i] && left >= b[i]){
			cnt++;
			a[i]--;
			left -= b[i];
		}
	}
	if(!left)
		cout << cnt << endl;
	else
		cout << -1 << endl;
}
