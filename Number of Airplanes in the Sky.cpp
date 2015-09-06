class Solution {
public:
    /**
     * @param intervals: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        // write your code here
        vector<pair<int, int>> v;
        for(auto &a:airplanes) {
            v.push_back(make_pair(a.start, 1));
            v.push_back(make_pair(a.end, -1));
        }
        sort(v.begin(), v.end());
        int ans = 0, count = 0;
        for(auto& a:v) {
            count += a.second;
            ans = max(ans, count);
        }
        return ans;
    }
};
