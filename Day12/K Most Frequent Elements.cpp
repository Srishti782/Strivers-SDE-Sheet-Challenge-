#include <bits/stdc++.h>
using namespace std; 
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    unordered_map<int, int> mp;
    priority_queue<int> pq;
    for(int i = 0; i < arr.size(); i++){
        mp[arr[i]]++;
    }
    for(auto i = mp.begin(); i != mp.end(); i++){
        pq.push(i->second);
    }
    set<int> st;
    while(k--){
        int a = pq.top();
        pq.pop();
        for(auto i = mp.begin(); i != mp.end(); i++){
            if(a == i->second){
                st.insert(i->first);
            }
        }
    }
    vector<int> ans;
    ans.insert(ans.begin(), st.begin(), st.end());
    return ans;
}