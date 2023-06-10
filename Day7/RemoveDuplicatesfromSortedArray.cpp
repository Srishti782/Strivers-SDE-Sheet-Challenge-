class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1){
            return n;
        }
        int j = 1, i = 0;
        while(i < n - 1){
            if(nums[i] == nums[i + 1]){
                i++;
            }
            else{
                nums[j++] = nums[i + 1];
                i++;
            }
        }
        return j;
    }
};