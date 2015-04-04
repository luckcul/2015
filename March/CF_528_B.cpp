/* ***********************************************
 	Author        : Napoleon
 	Mail		  : tyfdream@163.com
 	Created Time  : 2015-03-21 14:18:10
	Problem       : CF_528_B.cpp
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
#define N 211111
int n; 
int x, w, lastx, lastw, ans; 
struct node {
	int x, w; 
}p[N]; 
int cmp(node a, node b) {
	return a.x < b.x; 
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
	scanf("%d", &n); 
	for(int i = 1; i <= n; i++) {
		scanf("%d%d", &p[i].x, &p[i].w); 
	}
	sort(p+1, p+1+n, cmp); 
	ans = 1; 
	lastx = p[1].x; lastw = p[1].w; 
	for(int i = 2; i <= n; i++) {
		if(p[i].x - lastx >= lastw + p[i].w) {
			ans ++; 
			lastx = p[i].x; lastw = p[i].w; 
		}
		else if(p[i].x + p[i].w < lastx + lastw) {
			lastx = p[i].x; lastw = p[i].w; 
		}
	}
	cout<<ans<<endl; 
	return 0; 
}