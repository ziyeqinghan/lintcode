class Solution {
public:    
    /**
     * @param source: A string
     * @param target: A string
     * @return: A string denote the minimum window
     *          Return "" if there is no such a string
     */
    string minWindow(string &source, string &target) {
        // write your code here
        int dict[128], mapping[128];
        memset(dict, 0, sizeof(dict));
        memset(mapping, 0, sizeof(mapping));
        for(char c:target) dict[c]++;
        int m = source.size(), n = target.size();
        int i = 0, j = 0, count = 0, ansl = 0, ansr = 0;
        while(i+n <= m) {
            if(count < n) {
                if(j >= m) break;
                if(++mapping[source[j]] <= dict[source[j]]) count++;
                j++;
            }
            else {
                if(ansr == ansl || ansr-ansl > j-i) {
                    ansr = j;
                    ansl = i;
                }
                if(--mapping[source[i]] < dict[source[i]]) count--;
                i++;
            }
        }
        return source.substr(ansl, ansr-ansl);
    }
};

