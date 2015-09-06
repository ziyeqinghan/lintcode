/**
 * Definition of ExpressionTreeNode:
 * class ExpressionTreeNode {
 * public:
 *     string symbol;
 *     ExpressionTreeNode *left, *right;
 *     ExpressionTreeNode(string symbol) {
 *         this->symbol = symbol;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param expression: A string array
     * @return: The root of expression tree
     */
    void popStk(stack<char> &stk, stack<ExpressionTreeNode*> &nodes, int b, int a[128]) {
        while(!stk.empty() && a[stk.top()] >= b) {
            ExpressionTreeNode* t = new ExpressionTreeNode(string(1, stk.top()));
            t->right = nodes.top();
            nodes.pop();
            t->left = nodes.top();
            nodes.pop();
            nodes.push(t);
            stk.pop();
        }
    }
    ExpressionTreeNode* build(vector<string> &expression) {
        // write your code here
        stack<ExpressionTreeNode*> nodes;
        stack<char> stk;
        int a[128];
        a['+'] = a['-'] = 1;
        a['*'] = a['/'] = 2;
        a['('] = 0;
        for(auto &s:expression) {
            switch(s.back()) {
                case '(':
                    stk.push('('); break;
                case ')':
                    popStk(stk, nodes,1, a);
                    stk.pop(); break;
                case '+':
                case '-':
                case '*':
                case '/':
                    popStk(stk, nodes, a[s.back()], a);
                    stk.push(s.back()); break;
                default:
                    ExpressionTreeNode* t = new ExpressionTreeNode(s);
                    nodes.push(t);
            }
        }
        popStk(stk, nodes, 1, a);
        if(nodes.empty()) return NULL;
        return nodes.top();
    }
};
