class Solution {
public:
    vector&lt;int&gt; plusOne(vector&lt;int&gt; &amp;digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector&lt;int&gt; ans;
        int n = digits.size() - 1;
        int carry = 1;
        while(n &gt;= 0) {
            carry += digits[n];
            ans.push_back(carry % 10);
            carry /= 10;
            --n;
        }
        if(carry) {
            ans.push_back(carry);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};