#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void helper(vector<int> arr, int n, vector<int> output, int m, vector<int>& ans){
        if(n == 0){
            int sum = 0;
            for(int i = 0; i < m; i++){
                sum += output[i];
            }
            ans.push_back(sum);
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

    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ans;
        vector<int> output;
        helper(arr, N, output, 0, ans);
        return ans;
    }
};