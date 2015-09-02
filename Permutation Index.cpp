class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndex(vector<int>& A) {
        // Write your code here
        long long ans = 1, base = 1, a = 2;
        int n = A.size();
        for(int i = n-2; i >= 0; i--) {
            int k = 0;
            for(int j = i+1; j < n; j++)
                if(A[j] < A[i]) k++;
            ans += k*base;
            base *= a;
            a++;
        }
        return ans;
    }
};
