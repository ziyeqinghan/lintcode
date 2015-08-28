class Solution {
public:
    /**
     * @param str: a string
     * @param offset: an integer
     * @return: nothing
     */
    void rotateString(string &str,int offset){
        //wirte your code here
        int n = str.size();
        if(n == 0) return;
        offset %= n;
        reverse(str.begin(), str.end());
        reverse(str.begin(), str.begin()+offset);
        reverse(str.begin()+offset, str.end());
    }
};

