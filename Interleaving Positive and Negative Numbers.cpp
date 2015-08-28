class Solution {
public:
    /**
     * @param A: An integer array.
     * @return: void
     */
    void rerange(vector<int> &A) {
        // write your code here
        int sum1 = 0, sum2 = 0;
        for(auto a:A) {
            if(a < 0) sum1++;
            else sum2++;
        }
        int i = sum1>=sum2?0:1, j = sum1>=sum2?1:0, n = A.size();
        while(i < n && j < n) {
            while(i < n && A[i] < 0) i += 2;
            while(j < n && A[j] > 0) j += 2;
            if(i < n && j < n) swap(A[i], A[j]);
        }
        if(i < n) {
            int k = (n-i)%2 == 0? n-2:n-1;
            while(i < k) {
                while(i < k && A[i] < 0) i += 2;
                if(i < k && A[k] < 0) swap(A[i], A[k]);
                else k -= 2;
            }
        }
        if(j < n) {
            int k = (n-j)%2 == 0? n-2:n-1;
            while(j < k) {
                while(j < k && A[j] > 0) j += 2;
                if(j < k && A[k] > 0) swap(A[j], A[k]);
                else k-= 2;
            }            
        }
    }
};
