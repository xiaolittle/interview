class Solution {
public:
    int maxArea(vector&lt;int&gt; &amp;height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left = 0;
        int right = height.size() - 1;
        int ans = 0;
        while(left &lt; right) {
            ans = max(ans, min(height[left], height[right]) * (right - left));
            if(height[left] &lt; height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return ans;
    }
};