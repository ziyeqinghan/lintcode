class Solution {
public:
   /**
     * @param A: An integer array
     * @return: The number of element in the array that 
     *          are smaller that the given integer
     */
    int findq(vector<int> &A, int a) {
        int l = 0, r = A.size();
        while(l < r) {
            int m = (l+r)/2;
            if(A[m] < a) l = m+1;
            else r = m;
        }
        return l;
    }
    vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
        // write your code here
        sort(A.begin(), A.end());
        vector<int> ans;
        for(auto q:queries) {
            ans.push_back(findq(A, q));
        }
        return ans;
    }
};
