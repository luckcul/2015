/* ***********************************************
 	Author        : Napoleon
 	Mail		  : tyfdream@163.com
 	Created Time  : 2015-03-21 18:58:40
	Problem       : BC_34_C.cpp
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

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "w", stdout); 
#endif // ONLINE_JUDGE
	int n = 1000000, m = 1000000; 
	printf("%d %d\n", n, m); 
	for(int i = 1; i <= n; i++) {
		printf("%d ", (rand()<<16 | rand()) % INF); 
	}
	puts(""); 
	for(int i = 1; i <= n; i++) {
		printf("%d ", (rand()<<16 | rand()) % INF); 
	}
	
	return 0; 
}