#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct girl{
	string name;
	string s, t;
};

typedef struct girl Girl;
vector<Girl>vec;
vector<string>ans;

bool cmp(const Girl & a, const Girl & b){
	return a.t == b.t ? a.s < b.s : a.t < b.t;
}

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		Girl temp;
		cin >> temp.name >> temp.s >> temp.t;
		vec.push_back(temp);
	}
	sort(vec.begin(), vec.end(), cmp);
	string tmp = "00:00";
	for(vector<Girl>::iterator pt = vec.begin(); pt != vec.end(); pt++){
		if((*pt).s >= tmp){
			ans.push_back((*pt).name);
			tmp = (*pt).t;
		}
	}
	cout << ans.size() << endl;
	for(vector<string>::iterator pt = ans.begin(); pt != ans.end()-1; pt++)
		cout << *pt << " ";
	cout << *(ans.end() - 1) << endl;
}
