class Solution {
public:
    /** 
     * @param chars: The letters array you should sort.
     */
    void sortLetters(string &letters) {
        // write your code here
        int n = letters.size();
        int l = 0, r = n-1;
        while(l < r) {
            if(letters[l] >= 'a' && letters[l] <= 'z') l++;
            else if(letters[r] >= 'A' && letters[r] <= 'Z') r--;
            else swap(letters[l], letters[r]);
        }
    }
};

