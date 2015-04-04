/* ***********************************************
 	Author        : Napoleon
 	Mail		  : tyfdream@163.com
 	Created Time  : 2015-03-11 16:04:59
	Problem       : CB_32_C.cpp
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
#define N 1100111
#define mod 1000000007
LL n, a, b, fac[N]; 
char str[N]; 
void init() {
	fac[0] = 1; 
	for(int i = 1;i <= 1000111; i++) {
		fac[i] = (fac[i-1] * i) % mod; 
	}
}
LL pow_(LL a, LL b, LL m) {
	LL ret = 1; 
	while(b) {
		if(b&1) {
			ret *= a; ret %= m;  
		}
		a *= a; a %= m; 
		b >>= 1; 
	}
	return ret; 
}
LL Inv(LL a, LL m) {
	return pow_(a, m - 2, m); 
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
	init();
	while(scanf("%I64d", &n) != EOF) {
		scanf("%s", str); 
		if(n&1) {
			puts("0"); continue; 
		}
		a = b = 0; 
		int flag = 0; 
		for(int i = 0; str[i]; i ++) {
			if(str[i] == '(') a ++; 
			else b ++; 
			if(b > a) flag = 1; 
		}
		LL m = n / 2; 
		if(flag || a > m || b > m || b > a) {
			puts("0"); continue; 
		}
		a = m - a; b = m - b; 
		swap(a, b); //a >= b
		cout<<a<<"  "<<b<<endl; 
		LL ans = (a-b+1)*fac[a+b] % mod; 
		ans = ans * Inv(a+1, mod) % mod; 
		ans = ans * Inv(fac[a], mod) % mod; 
		ans = ans * Inv(fac[b], mod) % mod; 
		cout<<ans<<endl; 
	}
	return 0; 
}