class Solution {
public:
    /**
     * @param A: Given an integer array
     * @return: void
     */
    void heapify(vector<int> &A) {
        // write your code here
        int n = A.size();
        for(int i = n-1; i >= 0; i--) {
            int j = i;
            while(j < n) {
                int k = j;
                if(j*2+1 < n && A[k] > A[j*2+1]) k = j*2+1;
                if(j*2+2< n && A[k] > A[j*2+2]) k = j*2+2;
                if(j == k) break;
                swap(A[j], A[k]);
                j = k;
            }
        }
    }
};
