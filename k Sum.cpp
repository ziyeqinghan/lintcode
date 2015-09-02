
class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return an integer
     */
     
    int kSum(vector<int> A, int k, int target) {
        // wirte your code here
        if(k == 0) return 0;
        int n = A.size();
        int f[k+1][n+1][target+1];
        memset(f, 0, sizeof(f));
        for(int i = 0; i < n; i++) 
            if(A[i] <= target) {
                for(int j = i+1; j <= n; j++)
                    f[1][j][A[i]] = 1;
            }
    
        for(int i = 2; i <= k; i++)
            for(int j = 1; j <= n; j++)
                for(int l = 1; l <= target; l++)
                    f[i][j][l] = f[i][j-1][l]+(l >= A[j-1]?f[i-1][j-1][l-A[j-1]]:0);
        return f[k][n][target];
    }
};


