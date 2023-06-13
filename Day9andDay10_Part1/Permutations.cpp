#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void helper(vector<int>& nums, vector<int>& output, vector<vector<int>>& ans){
        if(nums.size() == 0){
            ans.push_back(output);
            // output.clear();
            return;
        }
        int n = nums.size();
        for(int i = 0; i < n; i++){
            vector<int> rem;
            for(int j = 0; j < n; j++){
                if(j != i){
                    rem.push_back(nums[j]);
                }
            }
            vector<int> o(output);
            o.push_back(nums[i]);
            helper(rem, o, ans);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        helper(nums, output, ans);
        return ans;
    }
};