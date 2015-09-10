class Solution {
public:
    /**
     *@param n: Given a decimal number that is passed in as a string
     *@return: A string
     */
    string binaryRepresentation(string n) {
        // wirte your code here
        int a = stoi(n.substr(0, n.find('.')));
        double b = stod(n.substr(n.find('.')));
        string s;
        if(a == 0) s.push_back('0');
        else {
            while(a) {
                s.push_back((a%2)+'0');
                a /= 2;
            }
            reverse(s.begin(), s.end());
        }
        if(b == 0) return s;
        s.push_back('.');
        string frac;
        while(b) {
            b *= 2;
            char c = '0';
            if(b >= 1) {
                c = '1';
                b -= 1;
            }
            frac.push_back(c);
            if(frac.size() > 32) return "ERROR";
        }
        s.append(frac);
        return s;
    }
};

