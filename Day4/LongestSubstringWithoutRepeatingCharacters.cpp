#include <bits/stdc++.h> 
using namespace std;
int uniqueSubstrings(string s)
{
    //Write your code here
    map<int, int> mp;
        int n = s.length();
        int len = 0;
        int left = 0, right = 0;
        while(right < n){
            if(mp.find(s[right]) != mp.end() && mp[s[right]] >= left){
                left = mp[s[right]] + 1;
            }
            else{
                mp[s[right]] = right;
                len = max(len, right - left + 1);
                right++;
            }
        }
        return len;
}