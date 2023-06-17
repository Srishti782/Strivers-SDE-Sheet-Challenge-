#include <bits/stdc++.h>
using namespace std;
bool possible(vector<int> &stalls, int k, int mid){
    int cnt = 1;
    int lastcow = stalls[0];
    for(int i = 1; i < stalls.size(); i++){
        if(stalls[i] - lastcow >= mid){
            cnt++;
            lastcow = stalls[i];
        }
        if(cnt == k) return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    if(k > stalls.size()) return 0;
    sort(stalls.begin(), stalls.end());
    int low = 1, high = stalls[stalls.size() - 1] - stalls[0];
    int res = 0;
    while(low <= high){
        int mid = (low + high) / 2;
        if(possible(stalls, k, mid)){
            res = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return res;
}