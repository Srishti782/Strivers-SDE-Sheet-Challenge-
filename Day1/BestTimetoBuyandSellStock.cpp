
#include <bits/stdc++.h> 
using namespace std;
int maximumProfit(vector<int>& prices){
    // Write your code here.
    int maxP = INT_MIN;
        int profit, buy, sell;
        int minm = prices[0];
        for(int i = 0; i < prices.size(); i++){
            sell = prices[i];
            minm = min(minm, prices[i]);
            buy = minm;
            profit = sell - buy;
            maxP = max(maxP, profit);
        }
        return maxP;
}