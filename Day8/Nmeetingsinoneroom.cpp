#include <bits/stdc++.h> 
using namespace std;
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<pair<int, int>, int>> eps;
        for(int i = 0; i < n; i++){
            eps.push_back({{end[i], i + 1}, start[i]});
        }
        sort(eps.begin(), eps.end());
        vector<int> ans;
        ans.push_back(eps[0].first.second);
        int endLimit = eps[0].first.first;
        
        
        for(int i = 1; i < n; i++){
            if(eps[i].second > endLimit){
                ans.push_back(eps[i].first.second);
                endLimit = eps[i].first.first;
            }
        }
        return ans.size();
    }
};