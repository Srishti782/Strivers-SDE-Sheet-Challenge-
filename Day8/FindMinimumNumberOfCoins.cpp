#include <bits/stdc++.h> 
using namespace std;
int findMinimumCoins(int amount) 
{
    // Write your code here
    int coins[9] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
	    
	int count = 0;
	int M = 9;   
	for(int i = M - 1; i >= 0; i--){
        while(amount >= coins[i]){
            count++;
            amount -= coins[i];
        }
	}
	    
	return count;
}