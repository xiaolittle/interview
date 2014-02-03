class Solution {
public:
    int candy(vector&lt;int&gt; &amp;ratings) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = ratings.size();
        if(n == 0) {
            return 0;
        } else if(n == 1) {
            return 1;
        }
        vector<int> ans(n, 1);
        for(int i = 1; i < n; ++i) {
            if(ratings[i] > ratings[i - 1]) {
                ans[i] = ans[i - 1] + 1;
            }
        }
        int sum = ans[n - 1];
        for(int i = n - 2; i >= 0; --i) {
            if(ratings[i] > ratings[i + 1]) {
                ans[i] = max(ans[i], ans[i + 1] + 1);
            }
            sum += ans[i];
        }
        return sum;
    }
};
