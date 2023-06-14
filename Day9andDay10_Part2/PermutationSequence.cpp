#include <bits/stdc++.h> 
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
    string getPermutation(int n, int k) {

        // Optimal solution
        int fact = 1;
        vector<int> arr;
        for(int i = 1; i < n; i++){
            fact *= i;
            arr.push_back(i);
        }
        arr.push_back(n);

        k = k - 1;
        string a;

        while(arr.size() > 0){
            a += (arr[k / fact] + '0');
            
            arr.erase(arr.begin() + (k / fact));
            if(arr.size() == 0){
                break;
            }
            k = k % fact;
            fact = fact / arr.size();
        }
        return a;


        // Brute Force
        // vector<int> arr;
        // for(int i = 1; i <= n; i++){
        //     arr.push_back(i);
        // }
        // vector<vector<int>> ans;
        // vector<int> output;
        // helper(arr, output, ans);
        // // sort(ans.begin(), ans.end());
        // string a;
        // for(int i = 0; i < ans[k - 1].size(); i++){
        //     a += (ans[k - 1][i] + '0');
        // }
        // return a;
        

    }
};