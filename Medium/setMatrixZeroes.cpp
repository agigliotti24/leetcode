class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> x;
        vector<int> y;

        for (int i = 0; i < matrix.size(); ++i)
            x.push_back(1);

        for (int i = 0; i < matrix[0].size(); ++i)
            y.push_back(1);

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                    x[i] = 0;
                    y[j] = 0;
                }
            }
        }
        for (int i = 0; i < x.size(); ++i) {
            for (int j = 0; j < y.size(); ++j) {
                if (x[i] == 0 || y[j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};