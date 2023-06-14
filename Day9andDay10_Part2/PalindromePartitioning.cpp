#include <bits/stdc++.h> 
using namespace std;
class Solution {
public:
bool isPalindrome(string &s, int start, int end){
    if(start >= end){
        return true;
    }
    if(s[start] != s[end]){
        return false;
    }
    return isPalindrome(s, start + 1, end - 1);
}

void helper(string& s, int index, vector<string> &path, vector<vector<string>> &ans){
    if(index == s.size()){
        ans.push_back(path);
        return;
    }

    for(int i = index; i < s.size(); i++){
        if(isPalindrome(s, index, i)){
            path.push_back(s.substr(index, i - index + 1));
            helper(s, i + 1, path, ans);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) 
{
    // Write your code here.
    vector<vector<string>> ans;
    vector<string> path;
    helper(s, 0, path, ans);
    return ans;
}

};