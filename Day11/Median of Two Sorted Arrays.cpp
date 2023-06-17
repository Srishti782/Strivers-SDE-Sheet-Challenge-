#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()){
            return findMedianSortedArrays(nums2, nums1);
        }
        int low = 0, high = nums1.size();

        while(low <= high){
            int cut1 = (low + high + 1) / 2;
            int cut2 = (nums1.size() + nums2.size() + 1) / 2 - cut1;
            int l1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
            int l2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];

            int r1 = cut1 == nums1.size() ? INT_MAX : nums1[cut1];
            int r2 = cut2 == nums2.size() ? INT_MAX : nums2[cut2];

            if(l1 <= r2 && l2 <= r1){
                if((nums1.size() + nums2.size()) % 2 == 0){
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }
                else{
                    return max(l1, l2);
                }
            }
            if(l1 > r2){
                high = cut1 - 1;
            }
            else{
                low = cut1 + 1;
            }

        }
        return 0.0;



        // vector<int> vec;
        // for(int i = 0; i < nums1.size(); i++){
        //     vec.push_back(nums1[i]);
        // }
        // for(int i = 0; i < nums2.size(); i++){
        //     vec.push_back(nums2[i]);
        // }
        // sort(vec.begin(), vec.end());
        // int mid = vec.size() / 2;
        // double ans;
        // if(vec.size() % 2 == 0){
        //     ans = vec[mid - 1] + vec[mid];
        //     ans = ans / 2.0;
        // }
        // else{
        //     ans = vec[mid];
        // }
        // return ans;
    }
};