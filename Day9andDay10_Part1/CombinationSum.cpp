#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void helper(vector<int>& candidates, int index, int target,vector<int>& output, vector<vector<int>>& ans){
        if(index == candidates.size()){
            if(target == 0){
                ans.push_back(output);
                return;
            }
            else{
                return;
            }
        }
        
        helper(candidates, index + 1, target, output, ans);
        if(target >= candidates[index]){
            output.push_back(candidates[index]);
            helper(candidates, index, target - candidates[index], output, ans);
            output.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> output;
        vector<vector<int>> ans;
        helper(candidates, 0, target, output, ans);
        return ans;
    }
};