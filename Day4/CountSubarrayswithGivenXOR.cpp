#include <bits/stdc++.h>
using namespace std;

int subarraysXor(vector<int> &arr, int k)
{
    //    Write your code here.
    map<int,int> frontXOR;
    frontXOR[0]++;
    int XR = 0;
    int count = 0;
    for(int i = 0; i < arr.size(); i++){
        XR = XR ^ arr[i];
        int x = XR ^ k;
        if(frontXOR.find(x) != frontXOR.end()){
            count += (frontXOR.find(x))->second;
        }
        frontXOR[XR]++;
    }
    return count;
}