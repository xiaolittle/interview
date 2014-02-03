class Solution {
public:
    void dfs(vector&lt;vector&lt;string&gt; &gt; &amp;ans, unordered_map&lt;string, int&gt; &amp;dis, string curstr, vector&lt;string&gt; cur) {
        if(dis[curstr] == 1) {
            reverse(cur.begin(), cur.end());
            ans.push_back(cur);
            return;
        }
        int last = dis[curstr];
        for(int i = 0; i &lt; curstr.size(); ++i) {
            char ori = curstr[i];
            for(int j = 0; j &lt; 26; ++j) {
                char ch = j + &#39;a&#39;;
                if(ch == ori) {
                    continue;
                }
                curstr[i] = ch;
                if(!dis.count(curstr) || dis[curstr] != last - 1) {
                    continue;
                }
                cur.push_back(curstr);
                dfs(ans, dis, curstr, cur);
                cur.pop_back();
            }
            curstr[i] = ori;
        }
    }

    vector&lt;vector&lt;string&gt;&gt; findLadders(string start, string end, unordered_set&lt;string&gt; &amp;dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = start.size();
        vector&lt;vector&lt;string&gt; &gt; ans;
        if(start == end) {
            vector&lt;string&gt; tmp;
            tmp.push_back(start);
            tmp.push_back(end);
            ans.push_back(tmp);
            return ans;
        }
        unordered_map&lt;string, int&gt; dis;
        dis[start] = 1;
        
        queue&lt;string&gt; q;
        q.push(start);
        bool find = false;
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
                        find = true;
                        //return last + 1;
                    }
                    dis[curstr] = last + 1;
                    q.push(curstr);
                }
                curstr[i] = ori;
            }
        }
        vector&lt;string&gt; cur;
        if(!find) {
            return ans;
        }
        cur.push_back(end);
        dfs(ans, dis, end, cur);
        return ans;
    }
};