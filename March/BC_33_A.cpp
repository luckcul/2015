/* ***********************************************
 	Author        : Napoleon
 	Mail		  : tyfdream@163.com
 	Created Time  : 2015-03-14 18:53:28
	Problem       : BC_33_A.cpp
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
#define N 222
int n, b; 
char now[N], ans[N], tmp[N]; 
void gao(char str[]) {
	for(int i = 0; i < N; i++) {
		tmp[i] = str[i]; 
	}
	int len = strlen(tmp); 
	int i, j; 
	for(i = len-1, j = 0; i >= 0; i--, j++) {
		str[j] = tmp[i]; 
	}
	str[j] = 0; 
}
int f(char ch) {
	int ret = 0; 
	if(ch >= '0' && ch <= '9') return ch - '0'; 
	return ch - 'a' + 10; 
}
char ff(int x) {
	char ret; 
	if(x >= 0 && x <= 9) return x + '0'; 
	return 'a' + x - 10; 
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
	while(scanf("%d%d", &n, &b) != EOF) {
		memset(ans, 0, sizeof(ans)); 
		memset(now, 0, sizeof(now)); 
		// printf("%d %d \n", n, b); 
		scanf("%s", ans); //puts(ans); 
		gao(ans); 
		//puts(ans); 
		for(int i = 2;i <= n; i++) {
			scanf("%s", now); 
			gao(now);// puts(now);// puts("..."); 
			int len1 = strlen(ans); 
			int len2 = strlen(now); 
			for(int j = 0; j < min(len1, len2); j++) {
				int gg = f(now[j]) + f(ans[j]); 
				ans[j] = ff(gg % b); 
			}
			char * sss; 
			if(len1 >= len2) sss = ans; 
			else sss = now; 
			int j; 
			for( j = min(len1, len2); sss[j]; j++) {
				ans[j] = sss[j]; 
			}
			ans[j] = 0; 
		}
		int lena = strlen(ans), jj; 
		for(jj = lena - 1; jj >= 0; jj --) {
			if(ans[jj] != '0') break; 
		}
		if(jj < 0) {
			puts("0"); 
		}
		else {
			for(int j = jj; j >= 0; j--) printf("%c", ans[j]); puts(""); 
		}
	//puts("____________"); 
	}
	
	return 0; 
}