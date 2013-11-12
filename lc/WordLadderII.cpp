class Solution {
public:
    void dfs(string &curstr, unordered_map<string, int> &dis,
		vector<vector<string> > &ans, vector<string> cur) {
		if(dis[curstr] == 1) {
			reverse(cur.begin(), cur.end());
			ans.push_back(cur);
			return;
		}
		int cnt = dis[curstr];
		for(int i = 0; i < curstr.size(); ++i) {
			char ori = curstr[i];
			for(int j = 0; j < 26; ++j) {
				if(curstr[i] == j + 'a') {
					continue;
				}
				curstr[i] = j + 'a';
				if(!dis.count(curstr)) {
					continue;
				}
				if(dis[curstr] != (cnt - 1)) {
					continue;
				}
				cur.push_back(curstr);
				dfs(curstr, dis, ans, cur);
				cur.pop_back();
			}
			curstr[i] = ori;
		}
	}

    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = start.size();
		vector<vector<string> > ans;
		if(start == end) {
			vector<string> tmp;
			tmp.push_back(start);
			ans.push_back(tmp);
			return ans;
		}
		if(!dict.count(start)) {
			return ans;
		}
		int mini = -1;
		queue<string> q;
		q.push(start);

		unordered_map<string, int> dis;
		dis[start] = 1;

		bool have = false;

		while(!q.empty()) {
			string curstr = q.front();
			q.pop();
			int cur = dis[curstr];
			if(mini != -1 && cur + 1 > mini) {
				break;
			}
			for(int i = 0; i < curstr.size(); ++i) {
				char ori = curstr[i];
				for(int j = 0; j < 26; ++j) {
					if(curstr[i] == j + 'a') {
						continue;
					}
					curstr[i] = j + 'a';
					if(dis.count(curstr) || !dict.count(curstr)) {
						continue;
					}
					if(curstr == end) {
						have = true;
						//return cur + 1;
						mini = cur + 1;
					}
					q.push(curstr);
					dis[curstr] = cur + 1;
				}
				curstr[i] = ori;
			}
		}

		if(!have) {
			return ans;
		}
		vector<string> tmp;
		tmp.push_back(end);
		dfs(end, dis, ans, tmp);
		return ans;
    }
};