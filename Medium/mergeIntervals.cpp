bool sortcol(vector<int>& v1, vector<int>& v2) { return v1[0] < v2[0]; }

class Solution {

public:
    int findMax(int a, int b) {
        if (a > b)
            return a;

        return b;
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;

        // Sort intervals based on start of each interval
        sort(intervals.begin(), intervals.end(), sortcol);

        res.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); ++i) {
            // Current interval overlaps with last interval of res
            if (intervals[i][0] <= res[res.size() - 1][1]) {
                res[res.size() - 1][1] =
                    findMax(intervals[i][1], res[res.size() - 1][1]);
            } else {
                res.push_back(intervals[i]);
            }
        }

        return res;
    }
};