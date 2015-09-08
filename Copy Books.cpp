class Solution {
public:
    /**
     * @param pages: a vector of integers
     * @param k: an integer
     * @return: an integer
     */
    bool __copyBooks(vector<int> &pages, int k, int m) {
        int sum = 0, count = 1;
        for(auto& a:pages) {
            sum += a;
            if(sum > m) {
                count++;
                if(count > k) return false;
                sum = a;
                if(sum > m) return false;
            }
        }
        return true;
    }
    int copyBooks(vector<int> &pages, int k) {
        // write your code here
        if(pages.size() == 0) return 0;
        int l = 0, r = INT_MAX;
        while(l < r) {
            int m = l + (r-l)/2;
            if(__copyBooks(pages, k, m))
                r = m;
            else l = m+1;
        }
        return l;
    }
};
