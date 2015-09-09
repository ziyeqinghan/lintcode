class Solution {
public:
    /**
     * @param matrix an integer matrix
     * @return the coordinate of the left-up and right-down number
     */
    vector<vector<int>> submatrixSum(vector<vector<int>>& matrix) {
        // Write your code here
        if(matrix.size() == 0 || matrix[0].size() == 0) return {};
        int m = matrix.size(), n = matrix[0].size();
        int sum[n];
        for(int i = 0; i < m; i++) {
            memset(sum, 0, sizeof(sum));
            for(int j = i; j < m; j++) {
                unordered_map<int, int> sum_index;
                sum_index[0] = 0;
                int a = 0;
                for(int k = 0; k < n; k++) {
                    a += matrix[j][k];
                    sum[k] += a;
                    if(sum_index.find(sum[k]) != sum_index.end()) {
                        return {{i, sum_index[sum[k]]}, {j, k}};
                    }
                    sum_index[sum[k]] = k+1;
                }
            }
        }
        return {};
    }
};
