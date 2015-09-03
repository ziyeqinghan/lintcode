class Solution {
public:
    /**
     * @param expression: A string array
     * @return: The Reverse Polish notation of this expression
     */
    vector<string> convertToRPN(vector<string> &expression) {
        // write your code here
        stack<char> ops;
        vector<string> ans;
        int a[128];
        a['*'] = a['/'] = 2;
        a['+'] = a['-'] = 1;
        a['('] = 0;
        for(auto& s:expression) {
            if(isdigit(s[0])) ans.push_back(s);
            else {
                switch(s[0]) {
                    case ')':
                        while(ops.top() != '(') { 
                            ans.push_back(string(1, ops.top())); 
                            ops.pop();
                        }
                        ops.pop(); break;
                    case '(':
                        ops.push('('); break;
                    default:
                        while(!ops.empty() && a[ops.top()] >= a[s[0]]) {
                            ans.push_back(string(1, ops.top()));
                            ops.pop();
                        }
                        ops.push(s[0]);
                }
            }
        }
        while(!ops.empty()) { 
            ans.push_back(string(1, ops.top())); 
            ops.pop();
        }
        return ans; 
    }
};
