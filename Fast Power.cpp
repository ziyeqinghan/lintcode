class Solution {
public:
    /*
     * @param a, b, n: 32bit integers
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        // write your code here
        if(n < 0) return 0;
        if(n == 0) return 1%b;
        long long c = fastPower(a, b, n/2);
        c = (c*c)%b;
        if(n%2 == 1) c = (a*c)%b;
        return (int)c;
    }
};
