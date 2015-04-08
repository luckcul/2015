/* ***********************************************
 	Author        : Napoleon
 	Mail		  : tyfdream@163.com
 	Created Time  : 2015-04-04 18:59:37
	Problem       : BC_36_B.cpp
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
#define INF 1000000011
//typedef __int64 LL; 
#define N 1000011
int h[N], n, m, ans[N]; 
struct node {
	int q, id; 
}qq[N];
void scanf_(int &num)
{
    char in;
    while((in=getchar())>'9' || in<'0');
    num=in-'0';
    while(in=getchar(),in>='0' && in<='9')
    num*=10,num+=in-'0';
}
int cmp(node a, node b) {
	if(a.q != b.q) return a.q <b.q; 
	return a.id < b.id; 
}
int main() {
	while(scanf("%d%d", &n, &m) != EOF) { 
		for(int i = 0; i < n; i++) {
			// scanf("%d", &h[i]); 
			scanf_(h[i]); 
		}
		for(int i = 0; i < m; i++) {
			// scanf("%d", &qq[i].q); 
			scanf_(qq[i].q); 
			qq[i].id = i;
		}
		sort(h, h+n); 
		h[n] = INF; 
		sort(qq, qq+m, cmp); 
		int last = -1; 
		int ii = 0; 
		int gg; 
		for(int i = 0; i < m; i++) {gg = 0; 
			if(qq[i].q == last){
				ans[qq[i].id] = 0; 
				continue; 
			}
			last = qq[i].q; 
			while(h[ii] < qq[i].q) ii++; 
			while(h[ii] == qq[i].q) ii++, gg++; 
			ans[qq[i].id] = gg; 
		}
		for(int i = 0; i < m; i++) {
			printf("%d\n", ans[i]); 
		}
	}
	
	return 0; 
}