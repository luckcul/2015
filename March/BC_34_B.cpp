/* ***********************************************
 	Author        : Napoleon
 	Mail		  : tyfdream@163.com
 	Created Time  : 2015-03-21 18:58:29
	Problem       : BC_34_B.cpp
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
typedef __int64 LL; 
#define N 1511110
LL n, w, h; 
LL num[N], sum[N], duo[N], shao[N]; 
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
	while(scanf("%I64d%I64d%I64d", &n, &w, &h) != EOF) {
		LL total = 0; 
		for(int i = 1; i <= w; i++) num[i] = 0; 
		for(int i = w+1; i <= w + n; i++) {
			scanf("%I64d", &num[i]); 
			total += num[i]; 
		}
		for(int i = w+n+1; i <= w+n+w+10; i++) num[i] = 0; 
		if(total < w*h) {
			puts("-1"); continue; 
		}
		sum[0] = duo[0] = shao[0] = 0; 
		for(int i = 1; i <= w+w+n; i++) {
			sum[i] = sum[i-1] + num[i]; 
			duo[i] = duo[i-1]; 
			shao[i] = shao[i-1]; 
			if(num[i] > h) {
				duo[i] += num[i] - h; 
			}
			else shao[i] += h - num[i]; 
			// printf("duo: %I64d shao: %I64d \n", duo[i], shao[i]); 
		}
		LL ans = INF; 
		for(int i = 1; i <= w+n+1; i++) {
			LL Duo = duo[i+w-1] - duo[i-1]; 
			LL Shao = shao[i+w-1] - shao[i-1]; 
			LL tt = 0; 
			tt = min(Duo, Shao) + abs(Duo - Shao); 
			ans = min(ans, tt); 
		}
		printf("%I64d\n", ans); 

	}
	
	return 0; 
}