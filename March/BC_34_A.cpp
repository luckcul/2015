/* ***********************************************
 	Author        : Napoleon
 	Mail		  : tyfdream@163.com
 	Created Time  : 2015-03-21 18:58:05
	Problem       : BC_34_A.cpp
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
int n, m; 
int a, b; 
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
	while(scanf("%d%d", &n, &m) != EOF) {
		int ans = INF; 
		for(int i = 1; i <= m; i++) {
			scanf("%d%d", &a, &b); 
			int tmp = b * (n/a); 
			if(n%a) {
				tmp += b; 
			}
			ans = min(ans, tmp); 
		}
		printf("%d\n", ans); 
	}
	
	return 0; 
}