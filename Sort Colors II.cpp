class Solution{
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */    
    void sortColors2(vector<int> &colors, int k) {
        // write your code here
        int n = colors.size(), i = 0;
        while(i < n) {
            if(colors[i] <= 0) i++;
            else if(colors[colors[i]-1] <= 0) {
                colors[colors[i]-1]--;
                colors[i] = 0;
                i++;
            }
            else {
                int t = colors[i];
                colors[i] = colors[t-1];
                colors[t-1] = -1;
            }
        }
        int j = n-1;
        for(i = k-1; i >= 0; i--) {
            for(int l = colors[i]; l < 0; l++) 
                colors[j--] = i+1;
        }
    }
};
