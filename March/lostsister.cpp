/* ***********************************************
 	Author        : Napoleon
 	Mail		  : tyfdream@163.com
 	Created Time  : 2015-04-05 15:02:03
	Problem       : lostsister.cpp
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
int n, tmp; 

int main() {
	while(cin>>n ) {
		int ans = 0; 
		n = 2*n - 1; 
		while(n--) {
			cin>>tmp; ans ^= tmp; 
		}
		printf("%d\n", ans); 
	}	
	
	return 0; 
}