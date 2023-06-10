class Solution {
public:
    int trap(vector<int>& height) {
        // Better Brute Approach, TC: O(3*n), SC: O(2*n)
        int n = height.size();
        if(n <= 1){
            return 0;
        }
        int preMax[n];
        int sufMax[n];

        int max = INT_MIN;
        for(int i = 0; i < n; i++){
            if(height[i] > max){
                max = height[i];
            }
            preMax[i] = max;
        }
        max = INT_MIN;
        for(int i = n - 1; i >= 0; i--){
            if(height[i] > max){
                max = height[i];
            }
            sufMax[i] = max;
        }
        int ans = 0;
        for(int i = 1; i < n - 1; i++){
            ans += min(preMax[i], sufMax[i]) - height[i];
        }
        return ans;

        // Optimised Approach, TC: O(n), SC: O(1)
        // int n = height.size();
        // if(n <= 1){
        //     return 0;
        // }
        // int ans = 0;
        // int l = 0, r = n - 1;
        // int lmax = 0, rmax = 0;
        // while(l < r){
        //     if(height[l] <= height[r]){
        //         if(height[l] > lmax){
        //             lmax = height[l];
        //         }
        //         else{
        //             ans += (lmax - height[l]);
        //         }
        //         l++;
        //     }
        //     else{
        //         if(height[r] > rmax){
        //             rmax = height[r];
        //         }
        //         else{
        //             ans += (rmax - height[r]);
        //         }
        //         r--;
        //     }
        // }
        // return ans;
    }
};