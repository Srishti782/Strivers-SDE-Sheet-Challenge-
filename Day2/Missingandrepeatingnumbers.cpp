#include <bits/stdc++.h>
using namespace std;
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	long long len = n;
	long long m, r;
	long long  s1 = 0, s2 = 0;
	long long cs1 = (len * (len + 1)) / 2;
	long long cs2 = (len * (len + 1) * ((2*len) + 1)) / 6;
	for(int i = 0; i < len; i++){
		s1 += arr[i];
		s2 += (long long)(pow(arr[i], 2));
	}
    long long x = s1 - cs1;
	long long y = (s2 - cs2) / x;
	r = (x + y) / 2;
	m = r - x;
    return {(int)m, (int)r};
}
