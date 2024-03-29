class Solution {
public:
    int findMin(int a, int b) {
        if (a < b)
            return a;

        return b;
    }

    int findMax(int a, int b) {
        if (a > b)
            return a;

        return b;
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        vector<vector<int>> res;

        for (int i = 0; i < intervals.size(); ++i) {
            // Add newInterval and then all subsequent intervals to res
            if (newInterval[1] < intervals[i][0]) {
                res.push_back(newInterval);
                for (int j = i; j < intervals.size(); ++j) {
                    res.push_back(intervals[j]);
                }
                return res;
            }
            // newInterval should be after current interval
            else if (newInterval[0] > intervals[i][1]) {
                res.push_back(intervals[i]);
            } else {
                newInterval[0] = findMin(newInterval[0], intervals[i][0]);
                newInterval[1] = findMax(newInterval[1], intervals[i][1]);
            }
        }

        res.push_back(newInterval);

        return res;
    }
};