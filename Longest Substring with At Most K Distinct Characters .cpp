class Solution {
public:
    /**
     * @param s : A string
     * @return : The length of the longest substring 
     *           that contains at most k distinct characters.
     */
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        // write your code here
        if(k <= 0) return 0;
        int n = s.size(), mapping[128];
        memset(mapping, 0, sizeof(mapping));
        int i = 0, j = 0, ans = 0, count = 0;
        while(i+ans < n && j < n) {
            if(count == k && mapping[s[j]] == 0) {
                if(--mapping[s[i++]] == 0) count--;
            } else {
                if(mapping[s[j++]]++ == 0) count++;
                ans = max(ans, j-i);
            }
        }
        return ans;
    }
};
