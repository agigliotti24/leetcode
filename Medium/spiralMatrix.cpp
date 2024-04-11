class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left = 0;
        int right = matrix[0].size() - 1;
        int top = 0;
        int bottom = matrix.size() - 1;
        vector<int> res;

        while (left <= right && top <= bottom) {
            // output top row
            for (int i = left; i <= right; ++i) {
                cout << "1 " << matrix[top][i] << endl;
                ;
                res.push_back(matrix[top][i]);
            }
            ++top;

            // output right columm
            for (int i = top; i <= bottom; ++i) {
                cout << "2 " << matrix[i][right] << endl;
                res.push_back(matrix[i][right]);
            }
            --right;

            // Break if we have added all elements already
            // (Without this you will overadd in certain cases)
            if (res.size() == (matrix.size() * matrix[0].size()))
                break;

            // output bottom row
            for (int i = right; i >= left; --i) {
                cout << "3 " << matrix[bottom][i] << endl;
                res.push_back(matrix[bottom][i]);
            }
            --bottom;

            // output left column
            for (int i = bottom; i >= top; i--) {
                cout << "4 " << matrix[i][left] << endl;
                res.push_back(matrix[i][left]);
            }
            ++left;
        }

        return res;
    }
};