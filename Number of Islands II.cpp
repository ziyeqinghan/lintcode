class Solution {
public:
    /**
     * @param n an integer
     * @param m an integer
     * @param operators an array of point
     * @return an integer array
     */
    unordered_map<int, int> father;
    int findRoot(int a) {
        int b = a;
        while(father[b] != b) b = father[b];
        while(father[a] != a) {
            int t = father[a];
            father[a] = b;
            a = t;
        }
        return b;
    }
    vector<int> numIslands2(int n, int m, vector<Point>& operators) {
        // Write your code here
        father.clear();
        vector<int> ans;
        int f[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}}, num = 0;
        for(auto& p:operators) {
            int fp = -1;
            for(int i = 0; i < 4; i++) {
                int x = p.x+f[i][0], y = p.y+f[i][1];
                if(x >= 0 && x < n && y >= 0 && y < m && father.find(x*m+y) != father.end()) {
                    int fa = findRoot(x*m+y);
                    if(fp == -1) fp = fa;
                    else if(fp != fa) {
                        father[fa] = fp;
                        num--;
                    }
                }
            }
            if(fp == -1) {
                father[p.x*m+p.y] = p.x*m+p.y;
                num++;
            }
            else father[p.x*m+p.y] = fp;
            ans.push_back(num);
        }
        return ans;
    }
};