class Solution {
public:
    /** 
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    int woodCut(vector<int> L, int k) {
        // write your code here
        if(L.size() == 0) return 0;
        int n = L.size(), maxl = 0;
        maxl = *max_element(L.begin(), L.end());
        int l = 0, r = maxl;
        while(l < r) {
            int m = l+(r-l)/2+1, count = 0;
            for(auto a:L) count += a/m;
            if(count < k) r = m-1;
            else l = m;
        }
        return l;
    }
};
