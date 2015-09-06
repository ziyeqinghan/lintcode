class Solution{
public:
    /**
     * @param n: an integer
     * @return an integer f(n)
     */
    int fibonacci(int n) {
        // write your code here
        int f[2] = {0, 1};
        for(int i = 1; i < n; i++) f[i&1] = f[(i+1)&1] + f[i&1];
        return f[(n-1)&1];
    }
};

