#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    void helper(vector<int> arr, int n, vector<int> output, int m, set<vector<int>>& ans){
        if(n == 0){
            ans.insert(output);
            return;
        }
        vector<int> rem(arr);
        vector<int>::iterator it;
 
        it = rem.begin();
        rem.erase(it);
        helper(rem, n - 1, output, m, ans);
        output.push_back(arr[0]);
        helper(rem, n - 1, output, m + 1, ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> output;
        sort(nums.begin(), nums.end());
        helper(nums, nums.size(), output, 0, ans);
        vector<vector<int>> a;
        a.insert(a.begin(), ans.begin(), ans.end());
        return a;
    }
};