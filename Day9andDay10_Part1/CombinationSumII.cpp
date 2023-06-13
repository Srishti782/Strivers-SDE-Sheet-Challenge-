#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Brute Force
    // void helper(vector<int>& candidates, int index, int target,vector<int>& output, set<vector<int>>& ans){
    //     if(index == candidates.size()){
    //         if(target == 0){
    //             ans.insert(output);
    //             return;
    //         }
    //         else{
    //             return;
    //         }
    //     }
        
    //     helper(candidates, index + 1, target, output, ans);
    //     output.push_back(candidates[index]);
    //     helper(candidates, index + 1, target - candidates[index], output, ans);
    //     output.pop_back();
        
    // }

    void helper(vector<int>& candidates, int index, int target,vector<int>& output, vector<vector<int>>& ans){
        if(target == 0){
            ans.push_back(output);
            return;
        }
        for(int i = index; i < candidates.size(); i++){
            if(i > index && candidates[i] == candidates[i - 1]) continue;
            if(candidates[i] > target) break;
            output.push_back(candidates[i]);
            helper(candidates, i + 1, target - candidates[i], output, ans);
            output.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> output;
        helper(candidates, 0, target, output, ans);
        return ans;

        // Brute Force
        // sort(candidates.begin(), candidates.end());
        // set<vector<int>> st;
        // vector<int> output;
        // vector<vector<int>> ans;
        // helper(candidates, 0, target, output, st);
        // ans.insert(ans.begin(), st.begin(), st.end());
        // return ans;
    }
};