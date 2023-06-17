#include <bits/stdc++.h>
using namespace std;
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	// Write your code here.
	sort (arr.begin(), arr.end());

    int max = arr[k - 1];

    int min = arr[n - k];

    vector<int> v;

    v.push_back(max);

    v.push_back(min);

    return v;
	// priority_queue<int, vector<int>, greater<int>> pq;
	// priority_queue<int> pqs;
    // for(int i = 0; i < k; i++){
    //     pq.push(arr[i]);
	// 	pqs.push(arr[i]);

    // }
    // for(int i = k; i < n; i++){
    //     if(arr[i] > pq.top()){
    //         pq.pop();
    //         pq.push(arr[i]);
    //     }
	// 	if(arr[i] < pqs.top()){
	// 		pqs.pop();
	// 		pqs.push(arr[i]);
	// 	}
    // }
	// vector<int> ans;
	// ans.push_back(pqs.top());
	// ans.push_back(pq.top());
	// return ans;

}