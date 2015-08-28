class Solution {
 public:
    // param n : description of n
    // return: description of return 
    long long trailingZeros(long long n) {
        long long t = 5, ans = 0;
        while(t <= n) {
            ans += n/t;
            n /= 5;
        }
        return ans;
    }
};

