class Solution {
public:
    /**
     * @param expression: A string array
     * @return: The Polish notation of this expression
     */
    vector<string> ans;
    void popStk(stack<char> &stk, int b, int a[128]) {
        while(!stk.empty() && a[stk.top()] > b) {
            ans.push_back(string(1, stk.top()));
            stk.pop();
        }
    }
    vector<string> convertToPN(vector<string> &expression) {
        // write your code here
        ans.clear();
        int n = expression.size();
        int a[128];
        stack<char> stk;
        a['+'] = a['-'] = 1;
        a['/'] = a['*'] = 2;
        a[')'] = a['('] = 0;
        for(int i = n-1; i >= 0; i--) {
            switch(expression[i].back()) {
                case ')':
                    stk.push(')'); break;
                case '(':
                    popStk(stk, a[expression[i].back()], a);
                    stk.pop(); break;
                case '+':
                case '-':
                case '*':
                case '/':
                    popStk(stk, a[expression[i].back()], a);
                    stk.push(expression[i].back()); break;
                default:
                    ans.push_back(expression[i]);
            }
        }
        popStk(stk, 0, a);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
