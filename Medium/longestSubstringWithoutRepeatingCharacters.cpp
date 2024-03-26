class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0)
            return 0;
        int max = 1;
        set<char> chars;
        char* start = &s[0];

        for (int i = 0; i < s.size(); ++i) {
            // Move the "start" of our window until we have no more duplicates
            // in window
            while (chars.find(s[i]) != chars.end()) {
                chars.erase(chars.find(*start));
                ++start; // Move to next char in string. Should be our new
                         // "start" of the window
            }
            // Insert current char once we know all duplicates are gone
            // (including current char)
            chars.insert(s[i]);
            // Update max
            if (chars.size() > max)
                max = chars.size();
        }

        return max;
    }
};