class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number occurs more than 1/3.
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        int num1 = 0, num2 = 1, count1 = 0, count2 = 0;
        for(auto n:nums) {
            if(num1 == n) count1++;
            else if(num2 == n) count2++;
            else if(count1 == 0) {
                num1 = n;
                count1++;
            }
            else if(count2 == 0) {
                num2 = n;
                count2++;
            }
            else {
                count1--;
                count2--;
            }
        }
        count1 = 0, count2 = 0;
        for(auto n:nums) {
            if(n == num1) count1++;
            else if(n == num2) count2++;
        }
        if(count1 > nums.size()/3) return num1;
        return num2;
    }
};

