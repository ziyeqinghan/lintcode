class Solution {
public:
    /**
     * @param S: A list of integers
     * @return: An integer
     */
    int triangleCount(vector<int> &S) {
        // write your code here
        sort(S.begin(), S.end());
        int ans = 0, n = S.size();
        for(int i = 2; i < n; i++) {
            int j = 0, k = i-1;
            while(j < k) {
                if(S[j]+S[k]>S[i]) {
                    ans += k-j;
                    k--;
                } else j++;
            }
        }
        return ans;
    }
};
