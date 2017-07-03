#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>

using namespace std;

vector<vector<int> > mat1, mat2, mat3;

int main(){
	int n1, m1, n2, m2;
	cin >> n1 >> m1;
	for(int i = 0; i < n1; i++){
		vector<int> tempv;
		for(int j = 0; j < m1; j++){
			int temp;
			cin >> temp;
			tempv.push_back(temp);
		}
		mat1.push_back(tempv);
	}
	cin >> n2 >> m2;
	for(int i = 0; i < n2; i++){
		vector<int> tempv;
		for(int j = 0; j < m2; j++){
			int temp;
			cin >> temp;
			tempv.push_back(temp);
		}
		mat2.push_back(tempv);
	}
	for(int i = 0; i < n1; i++){
		vector<int>tempv;
		for(int j = 0; j < m2; j++){
			int temp = 0;
			for(int k = 0; k < n2; k++){
				temp += mat1[i][k] * mat2[k][j];
			}
			tempv.push_back(temp);
		}
		mat3.push_back(tempv);
	}
	for(vector<vector<int> >::iterator pti = mat3.begin(); pti != mat3.end(); pti++)
		for(vector<int>::iterator ptj = (*pti).begin(); ptj != (*pti).end(); ptj++)
			printf(ptj == (*pti).end() - 1 ? "%d\n" : "%d ", *ptj);
}
	
