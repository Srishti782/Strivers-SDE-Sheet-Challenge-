#include <bits/stdc++.h>
using namespace std;
vector<int> ninjaAndSortedArrays(vector<int>& nums1, vector<int>& nums2,
 int m, int n) {
	// Write your code here.
	
	int i = m - 1, j = 0;
        while(i >= 0 && j < n){
            if(nums1[i] > nums2[j]){
                int temp = nums1[i];
                nums1[i] = nums2[j];
                nums2[j] = temp;
            }
            i--;
            j++;
        }
        sort(nums1.begin(), nums1.begin() + m);
        sort(nums2.begin(), nums2.end());
        for(int i = 0 ; i < n; i++){
            nums1[i + m] = nums2[i];
        }
		return nums1;
}