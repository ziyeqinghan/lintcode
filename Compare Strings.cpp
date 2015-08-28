class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true 
     *           else return false
     */
    bool compareStrings(string A, string B) {
        // write your code here
        int dict[128], mapping[128];
        memset(dict, 0, sizeof(dict));
        memset(mapping, 0, sizeof(mapping));
        for(char c:B) dict[c]++;
        int n = B.size(), count = 0;
        if(n == 0) return true;
        for(char c:A) {
            if(mapping[c]++ < dict[c]) count++;
            if(count == n) return true;
        }
        return false;
    }
};

