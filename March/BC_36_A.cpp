/* ***********************************************
     Author        : Napoleon
     Mail          : tyfdream@163.com
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
#define INF 1000000000
//typedef __int64 LL; 
#define N 2111111
int  n, m, h[N]; 
map<int, int> M; 
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
    while(scanf("%d%d", &n, &m) != EOF) {
        int tmp; 
        M.clear(); 
        for(int i = 1; i <= n; i++) {
            scanf("%d", &h[i]); 
            M[h[i]]++; 
        }
        for(int i = 1; i <= m; i++) {
            scanf("%d", &tmp); 
            printf("%d\n", M[tmp]); 
            M[tmp] = 0; 
        }
    }
    
    return 0; 
}