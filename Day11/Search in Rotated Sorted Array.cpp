#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int si = 0, ei = nums.size() - 1;
        while(si <= ei){
            int mid = (si + ei) / 2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[si] <= nums[mid]){
                if(target >= nums[si] && target < nums[mid]){
                    ei = mid - 1;
                }
                else{
                    si = mid + 1;
                }
            }
            else{
                if(target > nums[mid] && target <= nums[ei]){
                    si = mid + 1;
                }
                else{ 
                    ei = mid - 1;
                }
            } 
            
        }
        return -1;
        // for(int i = 0; i < nums.size(); i++){
        //     if(nums[i] == target){
        //         return i;
        //     }
        // }
        // return -1;
    }
};