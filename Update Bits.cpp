class Solution {
public:
    /**
     *@param n, m: Two integer
     *@param i, j: Two bit positions
     *return: An integer
     */
    int updateBits(int n, int m, int i, int j) {
        // write your code here
        int a = 0;
        for(int k = i;k <= j;k++) {
            a |= (1 << k);
        }
        a = ~a;
        return (n&a) | (m << i);
            
    }
};
