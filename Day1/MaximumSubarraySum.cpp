#include <bits/stdc++.h> 
using namespace std;
long long maxSubarraySum(int nums[], int n)
{
    /*
        Don't write main().
        Don't read input, it is passed as function argument.    
        No need to print anything.
        Taking input and printing output is handled automatically.
    */
        long long sum = 0, maxSum = INT_MIN;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            maxSum = max(sum, maxSum);
            if(sum < 0){
                sum = 0;
            }
        }
        if(maxSum < 0){
            return 0;
        }
        return maxSum;
}