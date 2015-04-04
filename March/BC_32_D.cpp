/* ***********************************************
 	Author        : Napoleon
 	Mail		  : tyfdream@163.com
 	Created Time  : 2015-03-14 10:55:36
	Problem       : BC_32_D.cpp
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
#define N 50005
int n, t, m, dp[360][N]; 

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
	scanf("%d", &t); 
	int ti = 0; 
	while(t--) {
		scanf("%d%d", &n, &m); 
		int M = 0; 
		while(M*(M+1) <= 2*n) M++; 
		M--; 
		dp[0][0] = 1; 
		for(int i = 1;i <= M; i++) {
			for(int j = i; j <= n; j++) {
				dp[i][j] = (dp[i][j-i] + dp[i-1][j-i]) % m; 
			}
		}
		int ans = 0; 
		for(int i = 1; i <= M; i++) {
			ans = (ans + dp[i][n]) % m; 
		}
		printf("Case #%d: %d\n", ++ti, ans); 
	}
	return 0; 
}
题意：求满足题目要求的x序列的种类数。
可以发现符合条件的序列去重后是一个0, 1, ..., k的连续序列(k满足k*(k+1)/2 <= n) ,则这个去重后的序列长度最长为sqrt(n)规模大小。
可以DP。dp[i][j]表示用到1~i的连续数字当前和为j的方法数。不用考虑长度是否满足n个，因为前面可以用0补上去。
dp[i][j] = dp[i][j-i] + dp[i-1][j-i]; 
ans = sum(dp[i][n]) for i in range(1, k)