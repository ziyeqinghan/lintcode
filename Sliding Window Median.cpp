class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of the element inside the window at each moving
     */
    vector<int> medianSlidingWindow(vector<int> &nums, int k) {
        // write your code here
        map<int, int> maxnum, minnum;
        int n = nums.size(), maxcount = 0, mincount = 0;
        vector<int> ans;
        if(k > n) k = n;
        for(int i = 0; i < n; i++) {
            if(i >= k) {
                if(maxnum.find(nums[i-k]) != maxnum.end()) {
                    maxnum[nums[i-k]]--;
                    if(maxnum[nums[i-k]] == 0) maxnum.erase(nums[i-k]);
                    maxcount--;
                } else {
                    minnum[nums[i-k]]--;
                    if(minnum[nums[i-k]] == 0) minnum.erase(nums[i-k]);
                    mincount--;                    
                }
            }
            
            if(minnum.empty() ||(!maxnum.empty() && prev(maxnum.end())->first >= nums[i])) {
                maxnum[nums[i]]++;
                maxcount++;
            } else {
                minnum[nums[i]]++;
                mincount++;
            }
            if(maxcount > mincount+1) {
                auto iter = prev(maxnum.end());
                minnum[iter->first]++;
                iter->second--;
                if(iter->second == 0) maxnum.erase(iter);
                maxcount--; mincount++;
            } else if (mincount > maxcount) {
                auto iter = minnum.begin();
                maxnum[iter->first]++;
                iter->second--;
                if(iter->second == 0) minnum.erase(iter);
                maxcount++; mincount--;
            }
            if(i >= k-1) ans.push_back(prev(maxnum.end())->first);
        }
        return ans;
    }
};

