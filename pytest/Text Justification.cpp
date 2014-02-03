class Solution {
public:
    vector&lt;string&gt; fullJustify(vector&lt;string&gt; &amp;words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = words.size();
        vector&lt;string&gt; ans;
        for(int i = 0; i &lt; n;) {
            int word_len = words[i].size();
            int blank_len = 0;
            int j = i + 1;
            string tmp = words[i];
            while(j &lt; n &amp;&amp; word_len + blank_len + words[j].size() &lt; L) {
                blank_len++;
                word_len += words[j].size();
                ++j;
            }
            blank_len = L - word_len;
            if(j == i + 1) {
                while(blank_len &gt; 0) {
                    tmp += &#39; &#39;;
                    --blank_len;
                }
            } else {
                if(j &lt; n) {
                    for(int k = i + 1; k &lt; j; ++k) {
                        int gaps = (blank_len % (j - k)) ? 1:0;
                        gaps += (blank_len / (j - k));
                        blank_len -= gaps;
                        while(gaps) {
                            tmp += &#39; &#39;;
                            gaps--;
                        }
                        tmp += words[k];
                    }
                } else {
                   for(int k = i + 1; k &lt; j; ++k) {
                       tmp += &#39; &#39;;
                       tmp += words[k];
                   }
                   while(tmp.size() &lt; L) {
                       tmp += &#39; &#39;;
                   }
                }
            }
            i = j;
            ans.push_back(tmp);
        }
        return ans;
    }
};