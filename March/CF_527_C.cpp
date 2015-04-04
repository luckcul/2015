/* ***********************************************
 	Author        : Napoleon
 	Mail		  : tyfdream@163.com
 	Created Time  : 2015-03-21 10:40:03
	Problem       : CF_527_C.cpp
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
set<int > W, H; 
multiset<int > w, h; 
char ch[10]; 
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
	int a, b, n; 
	scanf("%d%d%d", &a, &b, &n); 
	W.insert(0); W.insert(a); 
	H.insert(0); H.insert(b); 
	w.insert(a); 
	h.insert(b); 
	int tmp; 
	set<int>::iterator it, it1, it2; 
	while(n--) {
		scanf("%s%d", ch, &tmp); 
		if(ch[0] == 'H') {
			it = (H.insert(tmp)).first; 
			it1 = it2 = it; 
			it1 --; it2 ++; 
			h.insert(*it - *it1); 
			h.insert(*it2 - *it); 
			h.erase(h.lower_bound(*it2 - *it1)); 
		}
		else {
			it = (W.insert(tmp)).first; 
			it1 = it2 = it; 
			it1 --; it2 ++; 
			w.insert(*it - *it1); 
			w.insert(*it2 - *it); 
			w.erase(w.lower_bound(*it2 - *it1)); 
		}
		printf("%I64d\n", (LL)(*(h.rbegin())) * (LL)(*(w.rbegin()))); 
	}
	
	return 0; 
}