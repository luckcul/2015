/* ***********************************************
 	Author        : Napoleon
 	Mail		  : tyfdream@163.com
 	Created Time  : 2015-03-31 22:37:51
	Problem       : catch
************************************************ */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
using namespace std; 
#define INF 1000000000
//typedef __int64 LL; 
string s; 
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); 
	freopen("gg.out", "w", stdout); 
#endif // ONLINE_JUDGE
	int flag = 0; 
	while(cin>>s) {
		if(s == "output") flag = 1; 
		else {
			if(flag == 1) {
				flag --; cout<<s<<" "; 
			}
		}
	}
	
	return 0; 
}