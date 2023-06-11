#include <bits/stdc++.h> 
using namespace std;
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr, arr + n);
    	sort(dep, dep + n);
    	int i = 1, j = 0;
    	int maxP = 1;
    	int p = 1;
    	while(i < n && j < n){
    	    if(arr[i] > dep[j]){
    	        i++;
    	        j++;
    	    }
    	    else{
    	        p++;
    	        i++;
    	        maxP = max(p, maxP);
    	    }
    	}
    	return maxP;
    }
};