class Solution {
public:
    void getPermutations(vector&lt;vector&lt;int&gt; &gt; &amp;ans, vector&lt;int&gt; &amp;num, int dep) {
        if(dep == num.size()) {
            ans.push_back(num);
            return;
        }
        
        for(int i = dep; i &lt; num.size(); ++i) {
 //           if(dep == i) {
 //               getPermutations(ans, num, dep + 1);
 //           } else {
 //               if(num[dep] == num[i]) {
 //                   continue;
//                }
                swap(num[dep], num[i]);
                getPermutations(ans, num, dep + 1);
                swap(num[dep], num[i]);
 //               }
        }
    }
    
    vector&lt;vector&lt;int&gt; &gt; permuteUnique(vector&lt;int&gt; &amp;num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector&lt;vector&lt;int&gt; &gt; ans;
        int n = num.size();
        if(n == 0) {
            return ans;
        }
        sort(num.begin(), num.end());
        ans.push_back(num);
        while(true) {
            int high = n - 1;
            while(high &gt; 0 &amp;&amp; num[high - 1] &gt;= num[high]) {
                --high;
            }
            if(high == 0) {
                break;
            }
            int low = high - 1;
            while(high &lt; n &amp;&amp; num[high] &gt; num[low]) {
                high++;
            }
            --high;
            swap(num[low], num[high]);
            sort(num.begin() + low + 1, num.end());
            ans.push_back(num);
        }
        return ans;
    }
};