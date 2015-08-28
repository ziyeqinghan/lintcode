class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        // write your code here
        int m = A.size(), n = B.size();
        vector<vector<int>> f(m+1, vector<int>(n+1, 0));
        for(int i = 0; i <= m; i++) f[i][0] = 0;
        for(int i = 0; i <= n; i++) f[0][i] = 0;
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
                if(A[i-1] == B[j-1]) f[i][j] = f[i-1][j-1]+1;
                else f[i][j] = max(f[i][j-1], f[i-1][j]);
        return f[m][n];
    }
};

