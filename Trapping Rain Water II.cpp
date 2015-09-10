class Solution {
public:
    /**
     * @param heights: a matrix of integers
     * @return: an integer
     */
    int trapRainWater(vector<vector<int> > &heights) {
        // write your code here
        if(heights.size() == 0 || heights[0].size() == 0) return 0;
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n, false));
        vector<tuple<int, int, int>> h;
        auto cmp = [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
            return get<2>(a) > get<2>(b);
        };
        for(int i = 0;i < n; i++) {
            if(!visited[0][i]) h.push_back(make_tuple(0, i, heights[0][i]));
            if(!visited[m-1][i]) h.push_back(make_tuple(m-1, i, heights[m-1][i]));
            visited[0][i] = visited[m-1][i] = true;
        }
        for(int i = 0;i < m; i++) {
            if(!visited[i][0]) h.push_back(make_tuple(i, 0, heights[i][0]));
            if(!visited[i][n-1]) h.push_back(make_tuple(i, n-1, heights[i][n-1]));
            visited[i][0] = visited[i][n-1] = true;
        }
        make_heap(h.begin(), h.end(), cmp);
        int ans = 0;
        int f[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!h.empty()) {
            auto t = h[0];
            pop_heap(h.begin(), h.end(), cmp);
            h.pop_back();
            for(int i = 0; i < 4; i++) {
                int x = f[i][0] + get<0>(t);
                int y = f[i][1] + get<1>(t);
                if(x >= 0 && x < m && y >= 0 && y < n && !visited[x][y]) {
                    visited[x][y] = true;
                    ans += max(0, get<2>(t)-heights[x][y]);
                    h.push_back(make_tuple(x, y, max(heights[x][y], get<2>(t))));
                    push_heap(h.begin(), h.end(), cmp);
                }
            }
        }
        return ans;
    }
};
