class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @param k: an integer
     * @return: the kth smallest number in the matrix
     */
    int kthSmallest(vector<vector<int> > &matrix, int k) {
        // write your code here
        if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int m = matrix.size(), n = matrix[0].size();
        if(m*n < k) return 0;
        pair<int,int> h[m];
        auto cmp = [&matrix](const pair<int, int>& a, const pair<int, int>& b) {
            return matrix[a.first][a.second] > matrix[b.first][b.second];
        };
        for(int i = 0;i < m; i++) {
            h[i] = make_pair(i, 0);
            push_heap(h, h+i+1, cmp);
        }
        int ans = 0,heap_size = m;
        for(int i = 0; i < k; i++) {
            auto t = h[0];
            ans = matrix[t.first][t.second];
            pop_heap(h, h+heap_size--, cmp);
            if(t.second+1 < n) {
                h[heap_size++] = make_pair(t.first, t.second+1);
                push_heap(h, h+heap_size, cmp);
            }
        }
        return ans;
    }
};
