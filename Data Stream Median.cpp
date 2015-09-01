class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        vector<int> maxh, minh;
        auto mycmp = [](const int& a, const int& b) {
            return a > b;
        };
        vector<int> ans;
        for(int a:nums) {
            if(maxh.empty()) maxh.push_back(a);
            else {
                if(a <= maxh[0]) {
                    maxh.push_back(a);
                    push_heap(maxh.begin(), maxh.end());
                } else {
                    minh.push_back(a);
                    push_heap(minh.begin(), minh.end(), mycmp);
                }
                if(maxh.size() > minh.size()+1) {
                    minh.push_back(maxh[0]);
                    push_heap(minh.begin(), minh.end(), mycmp);
                    pop_heap(maxh.begin(), maxh.end());
                    maxh.pop_back();
                }
                if(minh.size() > maxh.size()) {
                    maxh.push_back(minh[0]);
                    push_heap(maxh.begin(), maxh.end());
                    pop_heap(minh.begin(), minh.end(), mycmp);
                    minh.pop_back();                    
                }
            }
            ans.push_back(maxh[0]);
        }
        return ans;
    }
};

