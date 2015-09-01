class Solution {
public:
    /**
     * @param A: An integer array.
     * @param target: An integer.
     */
    int MinAdjustmentCost(vector<int> A, int target) {
        // write your code here
        int f[2][101];
        for(int i = 0; i < 2; i++)
            for(int j = 0;j <= 100; j++)
                f[i][j] = 0;
        for(int i = 0; i < A.size(); i++) {
            for(int j = 1; j <= 100; j++)
                f[i%2][j] = *min_element(f[(i+1)%2]+max(1, j-target), f[(i+1)%2]+min(100, j+target)+1) + abs(A[i]-j); 
        }
        return *min_element(f[(A.size()+1)%2]+1, f[(A.size()+1)%2]+101);
    }
};
