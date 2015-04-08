/* ***********************************************
 	Author        : Napoleon
 	Mail		  : tyfdream@163.com
 	Created Time  : 2015-04-04 20:14:46
	Problem       : BC_36_C.cpp
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
#define N 51111
int q[N], m, n, vis[N], ans[N]; 
struct node {
	int q, id; 
}p[N]; 
struct nod {
	int fir, sec; 
}h[N]; 
void scanf_(int &num)
{
    char in;
    while((in=getchar())>'9' || in<'0');
    num=in-'0';
    while(in=getchar(),in>='0' && in<='9')
    num*=10,num+=in-'0';
}
int cmp(node a, node b) {
	return a.q < b.q; 
}
int cmp1(nod a, nod b) {
	return a.fir < b.fir; 
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
	while(scanf("%d%d", &n, &m)!= EOF) {
		for(int i = 0; i < n; i++) {
			scanf_(h[i].fir); 
			h[i].sec = i+1; 
		}
		for(int i = 0; i < m; i++) {
			scanf_(p[i].q); p[i].id = i; 
		}
		sort(p, p+m, cmp); 
		sort(h, h+n, cmp1); 
		int now = 1; 
		memset(vis, 0, sizeof(vis)); 
		vis[0] = vis[n+1] = 1; 
		int it = 0; 
		int last = -1; 
		for(int i = 0; i < m; i++) {
			if(last == p[i].q) {
				ans[p[i].id] = ans[p[i-1].id]; 
				continue; 
			}
			while(it < n && h[it].fir <= p[i].q) {
				int dd = h[it].sec; 
				if(vis[dd-1] == 0 && vis[dd+1] == 0) {
					now ++; 
				}
				else if(vis[dd-1] == 1 && vis[dd+1] ==1) {
					now --; 
				}
				vis[dd] = 1; 
				it ++; 
			}
			// printf("now: %d \n", now); 
			ans[p[i].id] = now; 
		}
		for(int i = 0; i < m; i++) {
			printf("%d\n", ans[i]); 
		}
	}
	
	return 0; 
}