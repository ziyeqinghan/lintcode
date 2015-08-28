class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: As described
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums, int k) {
        // write your code here
        unordered_map<int, int> m;
        for(int n:nums) {
            if(m.find(n) != m.end()) m[n]++;
            else if(m.size() < k-1) m[n] = 1;
            else {
                vector<int> v;
                for(auto &p:m) {
                    p.second--;
                    if(p.second == 0) v.push_back(p.first);
                }
                for(auto a:v)
                    m.erase(a);
            }
        }
        unordered_map<int, int> count;
        for(int n:nums) {
            if(m.find(n) != m.end()) count[n]++;
        }
        for(auto &p:count) {
            if(p.second > nums.size()/k) return p.first;
        }
        return 0;
    }
};

