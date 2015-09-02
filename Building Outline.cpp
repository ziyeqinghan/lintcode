class Solution {
public:
    /**
     * @param buildings: A list of lists of integers
     * @return: Find the outline of those buildings
     */
    vector<vector<int> > buildingOutline(vector<vector<int> > &buildings) {
        // write your code here
        map<int, int> m;
        vector<pair<int, int>> v;
        vector<vector<int>> ans;
        for(auto &a:buildings) {
            v.push_back(make_pair(a[0], a[2]));
            v.push_back(make_pair(a[1], -a[2]));
        }
        sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b){
              if(a.first != b.first) return a.first < b.first;
              return a.second > b.second;
        });
        int h = 0, b = 0;
        for(auto &a:v) {
            if(a.second > 0) m[a.second]++;
            else {
                m[-a.second]--;
                if(m[-a.second] == 0) m.erase(-a.second);
            }
            int maxh = 0;
            if(!m.empty()) maxh = prev(m.end())->first;
            if(h != maxh) {
                if(h != 0) ans.push_back({b, a.first, h}); 
                b = a.first;
            }
            h = maxh;
         }
         return ans;
    }
};
