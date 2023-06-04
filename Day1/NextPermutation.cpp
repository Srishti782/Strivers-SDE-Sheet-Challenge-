#include <bits/stdc++.h> 
using namespace std;
vector<int> nextPermutation(vector<int> &nums, int n)
{
    //  Write your code here.
    int k = -1;
        for(int i = nums.size() - 1; i > 0; i--){
            if(nums[i] > nums[i - 1]){
                k = i - 1;
                break;
            }
        }
        if(k != -1){
            for(int i = nums.size() - 1; i > k; i--){
                if(nums[i] > nums[k]){
                    int temp = nums[k];
                    nums[k] = nums[i];
                    nums[i] = temp;
                    break;
                }
            }
            sort(nums.begin() + k + 1, nums.end());
        }
        else{
            sort(nums.begin(), nums.end());
        }
        return nums;
}