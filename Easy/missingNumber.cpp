class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // XOR nums
        int num = 0;
        for (int i = 0; i < nums.size(); ++i) {
            num = num ^ nums[i];
        }
        // XOR expected
        int expected = 0;
        for (int i = 0; i < nums.size() + 1; ++i) {
            expected = expected ^ i;
        }

        // XOR num and expected, result will be missing number
        // Using the fact that if you XOR the same number together
        // the result will be 0;
        return num ^ expected;
    }
};