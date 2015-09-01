class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return a list of lists of integer 
     */
    vector<vector<int>> ans;
    vector<int> v;
    void __kSum(vector<int> &A, int l, int k, int target) {
        if(k == 0 && target == 0) {
            ans.push_back(v);
            return;
        }
        int n = A.size();
        if(k != 2) {
            for(int i = l; i < n-k+1 && k*A[i] <= target; i++) { 
                v.push_back(A[i]);
                __kSum(A, i+1, k-1, target-A[i]);
                v.pop_back();
            }
        }
        else if(k == 2) {
            int i = l, j = n-1;
            while(i < j) {
                int sum = A[i]+A[j];
                if(sum == target) {
                    v.push_back(A[i]);
                    v.push_back(A[j]);
                    ans.push_back(v);
                    v.pop_back();
                    v.pop_back();
                    i++; j--;
                }
                else if(sum < target) i++;
                else j--;
            }
        }
        
    } 

    vector<vector<int> > kSumII(vector<int> A, int k, int target) {
        // write your code here
        ans.clear(); v.clear();
        sort(A.begin(), A.end());
        __kSum(A, 0, k, target);
        return ans;
    }
};

