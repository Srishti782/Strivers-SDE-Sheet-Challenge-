#include <bits/stdc++.h> 
using namespace std;
int merge(vector<int>& nums, int si, int mid, int ei){
    int count = 0;
    int n = mid - si + 1;
    int m = ei - mid;
    long long arr1[n], arr2[m];
    for(int i = 0; i < n; i++){
        arr1[i] = nums[i + si];
    }

    for(int i = 0; i < m; i++){
        arr2[i] = nums[i + mid + 1];
    }
    int j = 0;
    for(int i = 0; i < n; i++){
        while(j < m && (long long)arr1[i] > (long long)(2 * (long long)arr2[j])){
            j++;
        }
        count += j;
    }

    int i = 0;
    j = 0;
    int k = si;
    while(i < n && j < m){
        if(arr1[i] <= arr2[j]){
            nums[k++] = arr1[i++];
        }
        else{
            nums[k++] = arr2[j++];
           
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

int mergeSort(vector<int>& nums, int si, int ei){
    int count = 0;
    if(si >= ei){
        return count;
    }
    int mid = (ei + si) / 2;
    count += mergeSort(nums, si, mid);
    count += mergeSort(nums, mid + 1, ei);
    count += merge(nums, si, mid, ei);

    return count;
}
int reversePairs(vector<int> &arr, int n){
	// Write your code here.	
	return mergeSort(arr, 0, n -1);
}