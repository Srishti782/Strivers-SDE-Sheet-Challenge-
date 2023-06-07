#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    unordered_set<int> st;
    for(int i = 0; i < n; i++){
        st.insert(arr[i]);
    }
    int longest = 1, cnt = 0;
    for(auto i = st.begin(); i != st.end(); i++){
        if(st.find(*(i) - 1) == st.end()){
            cnt = 1;;
            int k = 1;
            while(st.find(*(i) + k) != st.end()){
                cnt++;
                k++;
            }
            longest = max(longest, cnt);
        }
        else{
            continue;
        }
    }
    return longest;

}