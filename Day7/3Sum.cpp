class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> o1;
        vector<vector<int>> output;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(i != 0 && nums[i] == nums[i - 1]){
                continue;
            }
            int j = i + 1, k = n - 1;
            while(j < k){
                if(nums[i] + nums[j] + nums[k] < 0){
                    j++;
                }
                else if(nums[i] + nums[j] + nums[k] > 0){
                    k--;
                }
                else{
                    o1 = {nums[i], nums[j], nums[k]};
                    output.push_back(o1);
                    j++;
                    k--;
                    while(nums[j] == nums[j - 1] && j < k){
                        j++;
                    }
                    while(nums[k] == nums[k + 1] && j < k){
                        k--;
                    }
                }
            }
        }
        return output;
    }
};