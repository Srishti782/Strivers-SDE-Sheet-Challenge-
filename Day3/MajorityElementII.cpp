#include <bits/stdc++.h>
using namespace std;
vector<int> majorityElementII(vector<int> &nums)
{
    // Write your code here.
    vector<int> ans;
        int element1, count1 = 0;
        int element2, count2 = 0;

        for(int i = 0; i < nums.size(); i++){
            if(count1 == 0 && nums[i] != element2){
                element1 = nums[i];
                count1 = 1;
            }
            else if(count2 == 0 && nums[i] != element1){
                element2 = nums[i];
                count2 = 1;
            }
            else if(element1 == nums[i]){
                count1++;
            }
            else if(element2 == nums[i]){
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }
        
        int element_count1 = 0;
        int element_count2 = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == element1){
                element_count1++;
            }
            if(nums[i] == element2){
                element_count2++;
            }
        }
        if(element_count1 > (nums.size() / 3)){
            ans.push_back(element1);
        }
        if(element_count2 > (nums.size() / 3)){
            ans.push_back(element2);
        }
        return ans;

}