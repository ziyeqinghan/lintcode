class Solution {
public:
    /**
     * @param n: An integer.
     * return : An array storing 1 to the largest number with n digits.
     */
    vector<int> numbersByRecursion(int n) {
        // write your code here
        if(n <= 0) return {};
        if(n == 1) return {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> v = numbersByRecursion(n-1), ans = v;
        int base = 1;
        for(int i = 1; i < n; i++) base *= 10;
        for(int i = 1; i <= 9; i++) {
            ans.push_back(base*i);
            for(auto a:v) ans.push_back(base*i+a);
        }
        return ans;
    }
};
