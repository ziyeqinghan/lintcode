class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // write your code here
        int n = values.size();
        if(n == 0) return false;
        vector<vector<int>> f(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) f[i][i] = values[i];
        for(int i = n-2; i >= 0; i--)
            for(int j = i+1; j < n; j++)
                f[i][j] = max(values[i]-f[i+1][j], values[j]-f[i][j-1]);
        return f[0][n-1] > 0;
    }
};
