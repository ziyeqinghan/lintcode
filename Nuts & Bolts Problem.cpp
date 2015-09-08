class Solution {
public:
    /**
     * @param nuts: a vector of integers
     * @param bolts: a vector of integers
     * @param compare: a instance of Comparator
     * @return: nothing
     */
    void __sortNutsAndBolts(vector<string> &nuts, vector<string> &bolts, Comparator compare, int l, int r) {
        if(l >= r) return;
        int i = l, j = r-1;
        while(i < j) {
            if(compare.cmp(nuts[l], bolts[i]) == 1) i++;
            else if(compare.cmp(nuts[l], bolts[j]) == -1) j--;
            else swap(bolts[i], bolts[j]);
        }
        int m = i;
        i = l, j = r-1;
        while(i < j) {
            if(compare.cmp(nuts[i], bolts[m]) == -1) i++;
            else if(compare.cmp(nuts[j], bolts[m]) == 1) j--;
            else swap(nuts[i], nuts[j]);
        }        
        __sortNutsAndBolts(nuts, bolts, compare, l, m);
        __sortNutsAndBolts(nuts, bolts, compare, m+1, r);
    } 
    void sortNutsAndBolts(vector<string> &nuts, vector<string> &bolts, Comparator compare) {
        // write your code here
        __sortNutsAndBolts(nuts, bolts, compare, 0, nuts.size());
    }
};
