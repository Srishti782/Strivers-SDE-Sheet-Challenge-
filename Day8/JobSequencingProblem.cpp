#include <bits/stdc++.h> 
using namespace std;
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool cmp(Job a, Job b){
        return a.profit > b.profit;
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr, arr + n, cmp);
        vector<int> schedule(n + 1, -1);
        int profit = 0;
        int count = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = arr[i].dead; j > 0; j--){
                if(schedule[j] == -1){
                    count++;
                    profit += arr[i].profit;
                    schedule[j] = arr[i].id;
                    break;
                }
            }
        }
        vector<int> ans;
        ans.push_back(count);
        ans.push_back(profit);
        return ans;
    } 
};