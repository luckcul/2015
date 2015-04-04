/* ***********************************************
 	Author        : Napoleon
 	Mail		  : tyfdream@163.com
 	Created Time  : 2015-03-09 21:58:15
	Problem       : BC_32_B.cpp
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
#define N 1000005

int a[N], n, k; 
LL sum[N]; 
set<LL> hs; 
inline void scanf_(int &num) {
	char in; 
	bool neg = false; 
	while(((in = getchar()) > '9' || in < '0') && in != '-') ; 
	if(in == '-') {
		neg = true; 
		while((in = getchar()) > '9' || in < '0') ; 
	}
	num = in - '0'; 
	while(in = getchar(), in >= '0' && in <= '9') 
		num *= 10, num += in - '0'; 
	if(neg) num = -num; 
}
bool sol() {
	hs.clear(); 
	for(int i = n; i >= 1; i--) {
		hs.insert(sum[i]); 
		LL want; 
		if(i & 1) want = sum[i-1] + k;
		else want = sum[i-1] - k; //printf("want: %d\n", want); 
		if(hs.count(want)) return true;//printf("%d.\n", i);  
	}
	return false; 
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
	int t, ti = 0; 
	scanf("%d", &t); 	
	while(t--) {
		scanf("%d%d", &n, &k); 
		for(int i = 1;i <= n; i++) {
			// scanf("%d", &a[i]);
			scanf_(a[i]); 
			if(i&1) sum[i] = sum[i-1] + a[i]; 
			else sum[i] = sum[i-1] - a[i]; 
		}
		bool ans = sol(); 
		printf("Case #%d: ", ++ti); 
		if(ans) puts("Yes."); 
		else puts("No."); 
	}
	
	return 0; 
}