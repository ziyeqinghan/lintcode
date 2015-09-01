class Solution {
public:
    /**
     * @param A : An integer array
     * @return : Two integers
     */
    vector<int> singleNumberIII(vector<int> &A) {
        // write your code here
        int a = 0;
        for(int i:A) a ^= i;
        a = a&(-a);
        int x = 0, y = 0;
        for(int i:A) {
            if(i&a) x ^= i;
            else y ^= i;
        }
        return {x, y};
    }
};
