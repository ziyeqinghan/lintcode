class Solution {
public:
    /**
      * @param n: n
      * @param k: the kth permutation
      * @return: return the k-th permutation
      */
    string getPermutation(int n, int k) {
        int base = 1, b = n-1;
        for(int i = 2; i < n; i++) base *= i;
        string ans;
        bool visited[n];
        k--;
        memset(visited, 0, sizeof(visited));
        for(int i = 0; i < n; i++) {
            int j = k/base, a = 0;
            k %= base;
            if(i != n-1)
                base /= (n-1-i);
            for(int l = 0;l < n; l++) {
                if(!visited[l]) {
                    a++;
                    if(a == j+1) {
                        visited[l] = true;
                        ans.push_back((l+'1'));
                        break;
                    }
                }
            }
        }
        return ans;
    }
       
};
