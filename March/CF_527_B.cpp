/* ***********************************************
 	Author        : Napoleon
 	Mail		  : tyfdream@163.com
 	Created Time  : 2015-03-20 21:22:04
	Problem       : CF_527_B.cpp
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
int a[33][33]; 
char s1[N], s2[N]; 

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
	scanf("%d", &n); 
	scanf("%s%s", s1, s2); 	
	memset(a, -1, sizeof(a)); 
	int ans = 0; 
	for(int i = 0; s1[i]; i++) {
		int x = s1[i] - 'a'; 
		int y = s2[i] - 'a'; 
		if(x != y) ans ++; 
		a[x][y] = i; 
	}
	int ax, ay; 
	for(int i = 0; i <= 'z' - 'a'; i++) {
		for(int j = 0; j <= 'z' - 'a'; j++) {
			if(i == j) continue; 
			if(a[i][j] != -1)  a[i][30] = a[i][j]; 
		}
	}
	int sub = 0; 
	ax = ay = -1; 
	for(int i = 0; i <= 'z' - 'a'; i++) {
		for(int j = 0; j <= 'z' - 'a'; j++) {
			if(i == j || a[i][j] == -1) continue; 
			if(sub <= 0 && a[j][30] != -1) {
				sub = 1; ax = a[i][j]; ay = a[j][30]; 
			}
			if(a[j][i] != -1) {
				sub = 2; ax = a[i][j]; ay = a[j][i]; 
			}
		}
	}
	if(ax != -1) ax++; 
	if(ay != -1) ay++; 
	printf("%d\n", ans - sub); 
	printf("%d %d\n", ax, ay); 

	return 0; 
}