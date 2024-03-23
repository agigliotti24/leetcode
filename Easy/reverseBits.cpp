class Solution {
public:
    void printBinary(uint32_t num) {
        const int bits =
            sizeof(num) *
            8; // Total bits in an integer (assuming 8 bits per byte)

        for (int i = bits - 1; i >= 0; i--) {
            // Use bitwise AND with 1 to extract the i-th bit
            int bit = (num >> i) & 1;
            std::cout << bit;

            if (i % 4 == 0) {
                std::cout << " "; // Add a space every 4 bits for readability
            }
        }

        std::cout << std::endl;
    }

    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        uint32_t left_bit = 1 << 31;
        uint32_t right_bit = 1;
        uint32_t lsb = 0;
        uint32_t msb = 0;

        for (int i = 31, shift_offset = 0; i >= 15, i - shift_offset >= 0;
             --i, ++shift_offset) {
            lsb = n & right_bit;
            msb = n & left_bit;
            result = result ^ lsb << i - shift_offset;
            result = result ^ msb >> i - shift_offset;
            left_bit = left_bit >> 1;
            right_bit = right_bit << 1;
        }

        return result;
    }
};