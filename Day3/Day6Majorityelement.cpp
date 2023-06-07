#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	// Write your code here.
	int element, count = 0;
        for(int i = 0; i < n; i++){
            if(count == 0){
                element = arr[i];
                count = 1;
            }
            else{
                if(element == arr[i]){
                count++;
                }
                else{
                    count--;
                }
            }
        }
        int element_count = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] == element){
                element_count++;
            }
        }
        if(element_count > (n / 2)){
            return element;
        }
        else{
            return -1;
        }
}