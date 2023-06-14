#include <bits/stdc++.h> 
using namespace std;
bool isInDictionary(string &s, vector<string> &dictionary){
    for(int i = 0; i < dictionary.size(); i++){
        if(dictionary[i] == s){
            return true;
        }
    }
    return false;
    
}

void helper(string& s, int index, vector<string> &path, vector<string> &ans,
 vector<string> &dictionary){
    if(index == s.size()){
        string s;
        for(int i = 0; i < path.size() - 1; i++){
            s += path[i];
            s += " ";
        }
        s += path[path.size() - 1];
        ans.push_back(s);
        return;
    }

    for(int i = index; i < s.size(); i++){
        string a = s.substr(index, i - index + 1);
        if(isInDictionary(a, dictionary)){
            
            path.push_back(s.substr(index, i - index + 1));
            helper(s, i + 1, path, ans,dictionary);
            path.pop_back();
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here
    vector<string> ans;
    vector<string> path;
    helper(s, 0, path, ans, dictionary);
    return ans;

}