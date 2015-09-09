class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // write your code here
        int f[2] = {0, 0}, n = values.size();
        if(n == 0) return false;
        f[(n-1)&1] = values[n-1];
        for(int i = n-2; i >= 0; i--)
            f[i&1] = max(values[i]-f[(i+1)&1], values[i]+values[i+1]-f[i&1]);
        return f[0]>0;
    }
};
