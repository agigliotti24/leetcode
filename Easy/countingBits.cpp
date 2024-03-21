class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for (int i = 0; i <= n; ++i) {
            int count = 0;
            uint32_t num = i;   // This is OK in this case bc input is defined as being 0 <= n <= 105

            // Find num of 1s for any specific number
            while (num != 0) {
                count += num & 1;   // & with 1 to see if right most digit is 1
                num = num >> 1;     // Shift over by 1 to essentially check ever right digit until there are no more 1s
            }
            res.push_back(count);
        }

        return res;
    }
};