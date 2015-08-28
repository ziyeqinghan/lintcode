class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySumClosest(vector<int> nums){
        // write your code here
        if(nums.size() == 0) return {};
        vector<pair<int, int>> sum;
        sum.push_back(make_pair(-1, 0));
        int n = nums.size();
        for(int i = 0; i < n; i++)
            sum.push_back(make_pair(i, sum.back().second+nums[i]));
        sort(sum.begin(), sum.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
           return a.second < b.second; 
        });
        int closesum = sum[1].second-sum[0].second, l = -1, r = -1;
        for(int i = 0; i < sum.size()-1; i++) {
            if(sum[i+1].second-sum[i].second <= closesum) {
                closesum = sum[i+1].second-sum[i].second;
                l = min(sum[i].first, sum[i+1].first)+1;
                r = max(sum[i].first, sum[i+1].first);
            }
        }
        return {l, r};
    }
};

