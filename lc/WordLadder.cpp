class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = start.size();
		if(start == end) {
			return 0;
		}

		unordered_set<string> visit;
		queue<string> q;
		if(!dict.count(start)) {
			return 0;
		}
		q.push(start);
		//visit.insert(start);

		unordered_map<string, int> dis;
		dis[start] = 1;

		while(!q.empty()) {
			string curstr = q.front();
			q.pop();
			int cur = dis[curstr];
			for(int i = 0; i < curstr.size(); ++i) {
				char ori = curstr[i];
				for(int j = 0; j < 26; ++j) {
					if(curstr[i] == j + 'a') {
						continue;
					}
					//string repstr = curstr;
					//repstr.replace(i, 1, 1, j + 'a'); 
					curstr[i] = j + 'a';
					if(dis.count(curstr) || !dict.count(curstr)) {
						continue;
					}
					if(curstr == end) {
						return cur + 1;
					}
					q.push(curstr);
					//visit.insert(repstr);
					dis[curstr] = cur + 1;
				}
				curstr[i] = ori;
			}
		}

		return 0;


    }
};

//1 void bfs(int src) {
//2 deque<int> q.push_back(src);
//3 unordered_set<int> visited;
//4 
//5 visited.insert(src);
//6 while (!q.empty()) {
//7 int cur = q.front();
//8 q.pop_front();
//9 //visited.insert(cur);
//10 if (/*something to do*/) {
//11 //generate a new node from cur
//12 if (newNode == target) {
//13 // Do something.
//14 return;
//15 }
//16 if (!visited.count(newNode)) {
//17 q.push_back(newNode);
//18 visited.insert(newNode);
//19 }
//20 }
//21 }
//22 }