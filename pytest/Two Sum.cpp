class Solution {
public:
    vector&lt;int&gt; twoSum(vector&lt;int&gt; &amp;numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector&lt;pair&lt;int, int&gt; &gt; pairs;
      int n = numbers.size();

      for (int i = 0; i &lt; n; ++i) {
        pairs.push_back(make_pair(numbers[i], i));
      }
      sort(pairs.begin(), pairs.end());
      int left = 0; 
      int right = n - 1;
      while(left &lt; right) {
          if(pairs[left].first + pairs[right].first == target) {
              vector&lt;int&gt; ans;
              ans.push_back(pairs[left].second + 1);
              ans.push_back(pairs[right].second + 1);
              sort(ans.begin(), ans.end());
              return ans;
          } else if(pairs[left].first + pairs[right].first &lt; target) {
              left++;
          } else {
              right--;
          }
      }
    }
};