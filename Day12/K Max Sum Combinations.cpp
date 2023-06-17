#include <bits/stdc++.h>
using namespace std; 
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	// Write your code here.
	sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
	priority_queue<int> pq;
	for(int i = 0; i < k; i++){
		for(int j = 0; j < k; j++){
			pq.push(a[i] + b[j]);
		}
	}
	vector<int> ans;
	while(k--){
		ans.push_back(pq.top());
		pq.pop();
	}
	return ans;
}