class Solution {
public:
    /**
     * @param A an integer array
     * @param k an integer
     * @return an integer
     */
    int postOffice(vector<int>& A, int k) {
        // Write your code here
        int n = A.size();
        if(n == 0) return 0;
        if(k == 0) return INT_MAX;
        sort(A.begin(), A.end());
        int dist[n][n];
        memset(dist, 0, sizeof(dist));
        for(int i = 0; i < n-1; i++)
            dist[i][i+1] = A[i+1]-A[i];
        for(int i = n-3; i >= 0; i--)
            for(int j = i+2; j < n; j++)
                dist[i][j] = dist[i+1][j-1] + A[j]-A[i];
        int f[n][k];
        memset(f, 0, sizeof(f));
        for(int i = 0; i < n; i++) f[i][0] = dist[0][i];
        for(int i = 1; i < n; i++) 
            for(int j = 1;j < k; j++) {
                f[i][j] = dist[0][i];
                for(int l = 0; l < i; l++)
                    f[i][j] = min(f[i][j], f[l][j-1]+dist[l+1][i]);
            }
        return f[n-1][k-1];
    }
};
