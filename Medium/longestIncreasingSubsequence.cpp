class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int max = 1;

        for(int i = 1; i < nums.size(); ++i){
            for(int j = 0; j < i; ++j){
                if(nums[i] > nums[j]){
                    // Only update to largest substring possible
                    if(dp[i] <= dp[j]){
                        dp[i] = dp[j] + 1;
                        if(dp[i] > max){
                            max = dp[i];
                        }
                    }
                }
            }
        }

        return max;
    }
};