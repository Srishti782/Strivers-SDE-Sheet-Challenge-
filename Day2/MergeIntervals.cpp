#include <bits/stdc++.h> 
using namespace std;
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
    if(intervals.size() <= 1){
            return intervals;
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> output;
        output.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] > output[output.size() - 1][1]){
                output.push_back(intervals[i]);
            }
            else{
                output[output.size() - 1][1] = max(intervals[i][1], output[output.size() - 1][1]);
            }
        }
        return output;
}
