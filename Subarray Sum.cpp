class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        // write your code here
        if(nums.size() == 0) return {};
        int n = nums.size(), sum = 0;
        unordered_map<int, int> m;
        m[0] = -1;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            if(m.find(sum) != m.end()) return {m[sum]+1, i};
            m[sum] = i;
        }
        return {};
    }
};
