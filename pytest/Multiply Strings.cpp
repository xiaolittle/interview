class Solution {
public:
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = num1.size();
        int n = num2.size();
        if(m == 0 || n == 0) {
            return &quot;&quot;;
        }
        if(num1 == &quot;0&quot; || num2 == &quot;0&quot;) {
            return &quot;0&quot;;
        }
        vector<int> ans(m + n, 0);
        for(int i = m - 1; i >= 0; --i) {
            int carry = 0;
            for(int j = n - 1; j >= 0 || carry; --j) {
                carry += ans[i + j + 1];
                if(j >= 0) {
                    carry += (num1[i] - '0') * (num2[j] - '0');
                }
                ans[i + j + 1] = carry % 10;
                carry /= 10;
            }
        }
        
        int begin = 0;
        while(ans[begin] == 0) {
            ++begin;
        }
        string result;
        while(begin < (m + n)) {
            result.push_back(ans[begin] + '0');
            ++begin;
        }
        return result;
        
    }
};
