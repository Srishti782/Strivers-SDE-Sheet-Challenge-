#include <bits/stdc++.h> 
using namespace std;
struct Item{
    int value;
    int weight;
};
class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool cmp(pair<double, Item> a, pair<double, Item> b){
        return a.first > b.first;
    }
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<double, Item>> valperw;
        
        for(int i = 0; i < n; i++){
            pair<double, Item> p;
            p.first = (1.0 * arr[i].value) / arr[i].weight;
            p.second = arr[i];
            valperw.push_back(p);
        }
        
        sort(valperw.begin(), valperw.end(), cmp);
        
        double totalVal = 0;
        for(int i = 0; i < n; i++){
            if(valperw[i].second.weight > W){
                totalVal += (valperw[i].first * W);
                W = 0;
            }
            else{
                totalVal += valperw[i].second.value;
                W = W - valperw[i].second.weight;
            }
        }
        
        return totalVal;
    }
        
};