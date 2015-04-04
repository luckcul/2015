/* ***********************************************
 	Author        : Napoleon
 	Mail		  : tyfdream@163.com
 	Created Time  : 2015-03-14 18:55:00
	Problem       : BC_33_C.cpp
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

typedef __int64 LL; 
const LL INF = 1000000000000000000LL; 
#define N 33
int n, w; 
struct node {
	int t, l , v; 
}p[N]; 
LL dp[3000005]; 

int cmp(node a, node b) {
	return a.l - a.t < b.l - b.t; 
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
	while(scanf("%d%d", &n, &w) != EOF) {
		for(int i = 0; i < n; i++) 
			scanf("%d%d%d", &p[i].t, &p[i].v, &p[i].l); 
		sort(p, p+n, cmp); 
		memset(dp, -1, sizeof(dp)); 
		dp[0] = 0; 
		int M = 0; 
		LL ans = INF; 
		for(int i = 0; i < n; i++) {
			for(int j = M; j >= 0; j -- ) {
				if(dp[j] < 0) continue; 
				if(dp[j] >= w && j < ans) ans = j;
				int next = max(j + p[i].t, p[i].l); 
				dp[next] = max(dp[next], dp[j] + p[i].v); 
				M = max(M, next); 
				if(dp[next] >= w && next < ans) ans = next; 
			}
		}
		if(ans >= INF) cout<<"zhx is naive!"<<endl; 
		else cout<<ans<<endl; 
	}	
	
	return 0; 
}