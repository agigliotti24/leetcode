class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prefix = nums[0];
        int max = nums[0];

        // Iterate over nums array
        for (int i = 1; i < nums.size(); ++i) {
            // Disregard any negative prefix values
            if (prefix < 0) {
                prefix = nums[i];
            } else { // Keep adding prefix while positive
                prefix += nums[i];
            }
            
            // At each step check for max prefix
            if (prefix > max)
                max = prefix;
        }

        return max;
    }
};