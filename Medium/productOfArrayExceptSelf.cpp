class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*
         * Keep track of left product and right product arrays
         * loop over array from left to right and fill left product array
         * loop over array from right to left and fill right product array
         * Multiply left and right products together to find final product at
         * each index
         */

        int size = nums.size();
        vector<int> left_products(size);
        vector<int> right_products(size);
        vector<int> res(size);

        // Fill left_products
        left_products[0] = 1;
        for (int i = 1; i < size; ++i) {
            left_products[i] = left_products[i - 1] * nums[i - 1];
        }

        // Fill right_prodcuts
        right_products[size - 1] = 1;
        for (int i = size - 2; i >= 0; --i) {
            right_products[i] = right_products[i + 1] * nums[i + 1];
        }

        // Fill res
        for (int i = 0; i < size; ++i) {
            res[i] = left_products[i] * right_products[i];
        }

        return res;
    }
};