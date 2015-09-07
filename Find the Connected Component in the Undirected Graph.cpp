/**
 * Definition for Undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param nodes a array of Undirected graph node
     * @return a connected set of a Undirected graph
     */
    unordered_set<UndirectedGraphNode*> s;
    vector<vector<int>> ans;
    vector<int> v;
    void dfs(UndirectedGraphNode* t) {
        if(s.find(t) != s.end()) return;
        s.insert(t);
        v.push_back(t->label);
        for(auto a:t->neighbors) dfs(a);
    }
    vector<vector<int>> connectedSet(vector<UndirectedGraphNode*>& nodes) {
        // Write your code here
        s.clear(); ans.clear(); v.clear();
        for(auto x:nodes) {
            if(s.find(x) == s.end()) {
                v.clear();
                dfs(x);
                ans.push_back(v);
            }
        }
        for(auto &a:ans) sort(a.begin(), a.end());
        return ans;
    }
};
