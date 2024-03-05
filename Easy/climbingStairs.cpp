class Solution {
public:
    int climbStairs(int n) {
        vector<int> steps(n+1);

        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 2;

        steps[0] = 0;
        steps[1] = 1;
        steps[2] = 2;

        for(int i = 3; i < n+1; ++i){
            steps[i] = steps[i-2] + steps[i-1];
        }

        return steps[n];
    }
};