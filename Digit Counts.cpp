class Solution {
public:
    /*
     * param k : As description.
     * param n : As description.
     * return: How many k's between 0 and n.
     */
    int digitCounts(int k, int n) {
        // write your code here
        if(n < 0) return 0;
        if(n == 0) {
            if(k == 0) return 1;
            else return 0;
        }
        long long t=1;
        int ans = 0;
        while(t <= n) {
            ans += n/(10*t)*t;
            int a = n/t%10;
            if(a == k) ans += n%t+1;
            else if(a > k) ans += t;
            t *= 10;
        }
        return ans;
    }
};
