#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    int singleNonDuplicate(vector<int>& nums) {
        // Brute Force( can be done by taking XOR)
        // if(nums.size() == 1){
        //     return nums[0];
        // }
        // int ans = INT_MIN;
        // for(int i = 0; i < nums.size() - 1; i++){
        //     if(nums[i] == nums[i + 1]){
        //         i++;
        //     }
        //     else{
        //         ans = nums[i];
        //         break;
        //     }
        // }
        // if(ans == INT_MIN){
        //     return nums[nums.size() - 1];
        // }
        // return ans;

   
        if(nums.size() == 1){
            return nums[0];
        }
        int low = 0, high = nums.size() - 2;
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] == nums[mid^1]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return nums[low];
    }
};