/* ***********************************************
 	Author        : Napoleon
 	Mail		  : tyfdream@163.com
 	Created Time  : 2015-03-15 16:51:08
	Problem       : kmp_example.cpp
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
#define N 11111

char s1[N], s2[N]; 
int next[N], len1, len2;  
void init(char s1[], char s2[]) {
	len1 = strlen(s1+1); 
	len2 = strlen(s2+1); 
	int j = next[1] = 0; 
	for(int i = 2; i<= len2; i++) {
		while(j > 0 && s1[j+1] != s2[i]) j = next[j]; 
		if(s1[j + 1] == s2[i]) j += 1; 
		next[i] = j;
	}
}
void kmp(char s1[], char s2[]) {
	int j = 0; 
	for(int i = 1; i<= len1; i++) {
		while(j > 0 && s2[j+1] != s1[i]) j = next[j]; 
		if(s2[j+1] == s1[i]) j += 1; 
		if(j == len2) {
			printf("Find this substring in %d \n", i - len2 + 1); 
			j = next[j]; 
		}
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
	while(scanf("%s%s" ,s1+1, s2+1) != EOF) {
		init(s1, s2); 
		for(int i = 0; i < len2; i++) {
			printf("%d ", next[i]); 
		}
		puts(""); 
		kmp(s1, s2); 
	}

	return 0; 
}