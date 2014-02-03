class Solution {
public:
    int ladderLength(string start, string end, unordered_set&lt;string&gt; &amp;dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = start.size();
        if(start == end) {
            return 1;
        }
        unordered_map&lt;string, int&gt; dis;
        dis[start] = 1;
        
        queue&lt;string&gt; q;
        q.push(start);
        
        while(!q.empty()) {
            string curstr = q.front();
            q.pop();
            int last = dis[curstr];
            for(int i = 0; i &lt; len; ++i) {
                char ori = curstr[i];
                for(int j = 0; j &lt; 26; ++j) {
                    char ch = j + &#39;a&#39;;
                    if(ch == ori) {
                        continue;
                    }
                    curstr[i] = ch;
                    if(!dict.count(curstr) || dis.count(curstr)) {
                        continue;
                    }
                    if(curstr == end) {
                        return last + 1;
                    }
                    dis[curstr] = last + 1;
                    q.push(curstr);
                }
                curstr[i] = ori;
            }
        }
        return 0;
    }
};