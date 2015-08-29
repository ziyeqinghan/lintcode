class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @param s: the starting Directed graph node
     * @param t: the terminal Directed graph node
     * @return: a boolean value
     */
    bool hasRoute(vector<DirectedGraphNode*> graph,
                  DirectedGraphNode* s, DirectedGraphNode* t) {
        // write your code here
        unordered_set<DirectedGraphNode*> visited;
        queue<DirectedGraphNode*> q;
        q.push(s);
        visited.insert(s);
        while(!q.empty()) {
            DirectedGraphNode* a = q.front();
            q.pop();
            if(a == t) return true;
            for(auto l:a->neighbors) {
                if(visited.find(l) == visited.end()) {
                    q.push(l);
                    visited.insert(l);
                }
            }
        }
        return false;
    }
};