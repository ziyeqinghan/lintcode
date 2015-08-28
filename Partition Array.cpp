class Solution {
public:
    int partitionArray(vector<int> &nums, int k) {
        // write your code here
        int n = nums.size();
        int i = 0, j = n-1;
        while(i <= j) {
            if(nums[i] < k) i++;
            else if(nums[j] >= k) j--;
            else swap(nums[i], nums[j]);
        }
        return i;
    }
};
