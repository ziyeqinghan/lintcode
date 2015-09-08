class Solution {
public:
    /**
     * @param nodes a array of directed graph node
     * @return a connected set of a directed graph
     */
    unordered_map<int, int> father;
    int findRoot(int x) {
        int a = x;
        while(father[a] != a) a = father[a];
        while(father[x] != x) {
            int t = father[x];
            father[x] = a;
            x = t;
        }
        return a;
    }
    vector<vector<int>> connectedSet2(vector<DirectedGraphNode*>& nodes) {
        // Write your code here
        father.clear();
        for(auto &a:nodes) father[a->label] = a->label;
        for(auto &a:nodes) {
            int fa = findRoot(a->label);
            for(auto &b:a->neighbors) {
                int fb = findRoot(b->label);
                if(fa != fb) {
                    father[fb] = fa;
                }
            }
        }
        unordered_map<int, vector<int>> m;
        for(auto &a:nodes) {
            int fa = findRoot(a->label);
            m[fa].push_back(a->label);
        }
        vector<vector<int>> ans;
        for(auto &p:m) {
            sort(p.second.begin(), p.second.end());
            ans.push_back(p.second);
        }
        return ans;
    }
};
