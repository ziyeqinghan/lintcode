class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        // write your code here
        bool canFill[m+1];
        memset(canFill, 0, sizeof(canFill));
        canFill[0] = true;
        for(auto a:A) {
            for(int i = m; i >= a; i--) 
                if(canFill[i-a]) canFill[i] = true;
        }
        for(int i = m; i >= 0; i--)
            if(canFill[i]) return i;
    }
};
