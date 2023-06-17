#include <bits/stdc++.h>
using namespace std;
int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.  
    //Brute Force
    vector<int> arr;
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[0].size(); j++){
            arr.push_back(matrix[i][j]);
        }
    }
    sort(arr.begin(), arr.end());
    int k = arr.size() / 2;
    return arr[k];
}