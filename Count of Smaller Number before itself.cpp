class treeNode {
public:
    int count;
    int start, end;
    treeNode* left, *right;
    treeNode(int a, int b):start(a), end(b), count(0), left(NULL), right(NULL) {}
    
    ~treeNode() {
        if(left) delete left;
        if(right) delete right;
    }
};
class Solution {
public:
   /**
     * @param A: An integer array
     * @return: Count the number of element before this element 'ai' is 
     *          smaller than it and return count number array
     */
    void insert(treeNode* root, int a) {
        if(root == NULL || root->start > a || root->end < a) return;
        root->count++;
        int m = root->start+(root->end-root->start)/2;
        if(m >= a) {
            if(root->left)
                insert(root->left, a);
            else if(root->start != root->end) {
                root->left = new treeNode(root->start, m);
                insert(root->left, a);
            }
        } else { 
            if(root->right)
                insert(root->right, a);
            else if(root->start != root->end) {
                root->right = new treeNode(m+1, root->end);
                insert(root->right, a);
            }
        }
    }
    int query(treeNode* root, int a) {
        if(root == NULL || root->start > a) return 0;
        if(root->end < a) return root->count;
        return query(root->left, a)+query(root->right, a);
    
        
    }
    vector<int> countOfSmallerNumberII(vector<int> &A) {
        // write your code here
        if(A.size() == 0) return {};
        int minv = *min_element(A.begin(), A.end());
        int maxv = *max_element(A.begin(), A.end());
        treeNode root(minv, maxv);
        vector<int> ans;
        for(auto a:A) {
            ans.push_back(query(&root, a));
            insert(&root, a);
        }
        return ans;
    }
};
