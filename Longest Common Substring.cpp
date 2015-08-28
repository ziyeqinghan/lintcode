class Solution {
public:    
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        // write your code here
        int m = A.size(), n = B.size();
        vector<vector<int>> f(m+1, vector<int>(n+1, 0));
        for(int i = 0; i <= m; i++) f[i][0] = 0;
        for(int i = 0; i <= n; i++) f[0][i] = 0;
        int ans = 0;
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++) {
                f[i][j] = A[i-1] == B[j-1]?f[i-1][j-1]+1:0;
                ans = max(ans, f[i][j]);
            }
        return ans;
    }
};

