/* ***********************************************
 	Author        : Napoleon
 	Mail		  : tyfdream@163.com
 	Created Time  : 2015-03-14 18:53:58
	Problem       : BC_33_B.cpp
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
LL n, p; 
LL pow_(LL a, LL b, LL p){
	LL ret = 1; 
	while(b) {
		if(b & 1) {
			ret *= a; ret %= p; 
		}
		b >>= 1; 
		a *= a; a %= p; 
	}
	return ret; 
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
	scanf("%I64d%I64d", &n, &p); 
	cout<<n<<"  "<<p<<endl; 
	cout<<pow_(2, n, p)<<endl; 
	
	return 0; 
}