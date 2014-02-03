class Solution {
public:
    void nextPermutation(vector&lt;int&gt; &amp;num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = num.size();
        if(n &lt; 2) {
            return;
        }
        int high = n - 1;
        while(high &gt; 0 &amp;&amp; num[high] &lt;= num[high - 1]) {
            --high;
        }
        if(high == 0) {
            sort(num.begin(), num.end());
            return;
        }
        int low = high - 1;
        int change = high;
        while(change &lt; n &amp;&amp; num[change] &gt; num[low]) {
            change++;
        }
        --change;
        swap(num[low], num[change]);
        sort(num.begin() + high, num.end());
    }
};