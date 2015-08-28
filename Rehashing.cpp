class Solution {
public:
    /**
     * @param hashTable: A list of The first node of linked list
     * @return: A list of The first node of linked list which have twice size
     */    
    vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
        // write your code here
        int n = hashTable.size();
        if(n == 0) return {};
        int m = n*2;
        vector<ListNode*> ans(m, NULL), tail(m, NULL);
        for(ListNode* h:hashTable) {
            while(h) {
                ListNode* t = h->next;
                h->next = NULL;
                int a = (h->val%m+m)%m;
                if(tail[a] == NULL) ans[a] = tail[a] = h;
                else {
                    tail[a]->next = h;
                    tail[a] = h;
                }
                h = t;
            }
        }
        return ans;
    }
};
