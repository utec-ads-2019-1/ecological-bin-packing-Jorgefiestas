#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;
int  total, arr[3][3], color_index[] = {0, 2, 1};
char color_key[] = {'B','C','G'};

void get_input(string &);
string minimum_movements();

int main(){
	string line;
	while(getline(cin, line)){
		total = 0;
		if(line == "") continue;
		get_input(line);
		cout<<minimum_movements()<<endl;
	}
}

void get_input(string &line){
	stringstream ss(line);
	for(int i = 0; i<3; i++)
		for(int j = 0; j<3; j++)
			ss>>arr[i][color_index[j]], total += arr[i][color_index[j]];
}

string minimum_movements(){
	int order[] = {0, 1, 2};
	int mx = 0;
	string  ans;
	do{	
		int unmoved = arr[0][order[0]] + arr[1][order[1]] + arr[2][order[2]];
		if(unmoved > mx){
			mx = unmoved;
			ans = "";
			for(int i = 0; i<3; i++) ans += color_key[order[i]];
		}
	}while(next_permutation(order, order+3));
	ans += ' ' + to_string(total - mx);
	return ans;
}
