class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long frac(unordered_map<int, int>& m) {
        long long ret = 1;
        for(auto& p:m) {
            ret *= calFactorial(p.second);
        }
        return ret;
    }
    long long calFactorial(int a) {
        long long ret = a;
        while(--a > 1) ret *= a;
        return ret;
    }
    long long permutationIndexII(vector<int>& A) {
        // Write your code here
        long long base = 1, ans = 1;
        int n = A.size();
        unordered_map<int, int> m;
        for(int i = n-1; i >= 0; i--) {
            int r = 0;
            m[A[i]]++;
            for(int j = i+1; j < n; j++) 
                if(A[j] < A[i]) r++;
            ans += r*base/frac(m);
            base *= (n-i);
        }
        return ans;
    }
    
};
