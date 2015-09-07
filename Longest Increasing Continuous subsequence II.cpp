class Solution {
public:
    /**
     * @param A an integer matrix
     * @return  an integer
     */
    int getF(vector<vector<int>>& A, vector<vector<int>>& f, int x, int y) {
        if(f[x][y] > 0) return f[x][y];
        int a = 1;
        int g[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for(int i = 0;i < 4; i++) {
            int j = x + g[i][0], k = y + g[i][1];
            if(j >= 0 && j < A.size() && k >= 0 && k < A[0].size() && A[j][k] > A[x][y])
                a = max(a, 1+getF(A, f, j, k));
        }
        f[x][y] = a;
        return a;
    }
    int longestIncreasingContinuousSubsequenceII(vector<vector<int>>& A) {
        // Write your code here
        if(A.size() == 0 || A[0].size() == 0) return 0;
        int m = A.size(), n = A[0].size();
        vector<vector<int>> f(m, vector<int>(n, 0));
        int ans = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                ans = max(ans, getF(A, f, i, j));
        return ans;
    }
};
