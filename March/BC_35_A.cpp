/* ***********************************************
 	Author        : Napoleon
 	Mail		  : tyfdream@163.com
 	Created Time  : 2015-03-28 18:59:38
	Problem       : BC_35_A.cpp
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
// using namespace std; 
#define INF 1000000000
//typedef __int64 LL; 
#define N 22
int n, m; 
int c[2*N][2*N]; 
void init() {
	memset(c, 0, sizeof(c)); 
	for(int i = 0; i < 2*N; i++) {
		for(int j = 0; j < 2*N; j++) {
			if(j == 0 || i == j) c[i][j] = 1;
			else c[i][j] = c[i-1][j] + c[i-1][j-1]; 
		}
	}
}
int gcd(int a, int b) {
	if(!b) return a; 
	return gcd(b, a%b); 
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
	init(); 
	while(scanf("%d%d", &n, &m) != EOF) {
		// cout<<n<<m<<endl; 
		int ans = 0; 
		int down = c[n+m][n]; 
		for(int i = 1; i <= std::min(n, m); i++) {
			// printf("%d %d %d, %d %d %d\n", m-1, i+1, c[m-1][i+1], m-1, i, c[m-1][i]); 
			int aa =  c[m-1][i-1]; 
			int bb =  c[m-1][i]; 
			// printf("this: %d \n", c[n][i] * (aa+bb)); 
			ans += i * c[n][i] * (aa + bb); 
		}
		int g = gcd(ans, down); 
		printf("%d/%d\n", ans/g, down/g); 
	}
	
	return 0; 
}