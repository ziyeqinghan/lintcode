class Solution {
public:
    /*
     * @param k: The number k.
     * @return: The kth prime number as description.
     */
    long long kthPrimeNumber(int k) {
        // write your code here
        long long f[k+1];
        f[0] = 1;
        int i1 = 0, i2 = 0, i3 = 0;
        for(int i = 1; i <= k; i++) {
            f[i] = min({3*f[i1], 5*f[i2], 7*f[i3]});
            if(3*f[i1] == f[i]) i1++;
            if(5*f[i2] == f[i]) i2++;
            if(7*f[i3] == f[i]) i3++;
        }
        return f[k];
    }
};
