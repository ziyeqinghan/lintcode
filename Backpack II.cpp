class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> A, vector<int> V) {
        // write your code here
        int maxval[m+1];
        memset(maxval, 0, sizeof(maxval));
        for(int i = 0; i < A.size(); i++) {
            for(int j = m; j >= A[i]; j--) 
                maxval[j] = max(maxval[j],maxval[j-A[i]]+V[i]);
        }
        int ans = 0;
        for(int i = m; i >= 0; i--)
            ans = max(ans, maxval[i]);
        return ans;
    }
};
