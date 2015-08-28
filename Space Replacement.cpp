class Solution {
public:
    /**
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char string[], int length) {
        // Write your code here
        int sum = 0;
        for(int i = 0; i < length; i++)
            if(string[i] == ' ') sum++;
        int j = length+2*sum-1;
        for(int i = length-1;i>=0;i--)
            if(string[i] == ' ') {
                string[j--] = '0';
                string[j--] = '2';
                string[j--] = '%';
            }
            else string[j--] = string[i];
        return length+2*sum;
    }
};  
