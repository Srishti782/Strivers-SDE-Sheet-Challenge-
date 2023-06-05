#include <bits/stdc++.h> 
using namespace std;
long long merge(long long * nums, int si, int mid, int ei){
    long long count = 0;
    int n = mid - si + 1;
    int m = ei - mid;
    long long arr1[n], arr2[m];
    for(int i = 0; i < n; i++){
        arr1[i] = nums[i + si];
    }

    for(int i = 0; i < m; i++){
        arr2[i] = nums[i + mid + 1];
    }

    int i = 0, j = 0;
    int k = si;
    while(i < n && j < m){
        if(arr1[i] <= arr2[j]){
            nums[k++] = arr1[i++];
        }
        else{
            nums[k++] = arr2[j++];
            count += (n - i);
        }
    }
        
    while(i < n){
        nums[k++] = arr1[i++];
    }
        
        
    while(j < m){
        nums[k++] = arr2[j++];
    }
    return count;
        
    }

long long mergeSort(long long *nums, int si, int ei){
    long long count = 0;
    if(si >= ei){
        return count;
    }
    int mid = (ei + si) / 2;
    count += mergeSort(nums, si, mid);
    count += mergeSort(nums, mid + 1, ei);
    count += merge(nums, si, mid, ei);

    return count;
}
long long getInversions(long long *arr, int n){
    // Write your code here.
    int si = 0; 
    int ei = n -1;
    return mergeSort(arr, si, ei);
}