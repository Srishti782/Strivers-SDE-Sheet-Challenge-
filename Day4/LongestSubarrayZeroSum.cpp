#include <bits/stdc++.h>
using namespace std;

int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your code here
  map<int,int> mp;
  int k = 0;
  int sum = 0;
  int len = 0;
  for(int i = 0; i < arr.size(); i++){
    sum += arr[i];
    
    if(sum == k){
      len = max((i + 1), len);
    }
    int rem = sum - k;
    if(mp.find(rem) != mp.end()){
      len = max(len, (i - mp[rem]));
    }
    if (mp.find(sum) == mp.end()) {
      mp[sum] = i;
    }
  }
  return len;
}