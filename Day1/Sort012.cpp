#include <bits/stdc++.h> 
using namespace std;
    void merge(int *nums, int si, int mid, int ei){
        int n = mid - si + 1;
        int m = ei - mid;
        int arr1[n], arr2[m];
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
            }
        }
        
        while(i < n){
            nums[k++] = arr1[i++];
        }
        
        
        while(j < m){
            nums[k++] = arr2[j++];
        }
        
    }

    void mergeSort(int *nums, int si, int ei){
        if(si >= ei){
            return;
        }
        int mid = (ei + si) / 2;
        mergeSort(nums, si, mid);
        mergeSort(nums, mid + 1, ei);
        merge(nums, si, mid, ei);
    }
    void sort012(int *nums, int n)
    {
    //   Write your code here
        int si = 0;
        int ei = n - 1;
        mergeSort(nums, si, ei);
    }