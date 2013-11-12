class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //vector<int> hash(26, 0);
		map<char, int> hash;
		for(int i = 0; i < T.size(); ++i) {
			//hash[T[i] - 'A']++;
			if(hash.count(T[i]) > 0) {
				++hash[T[i]];
			} else {
				hash[T[i]] = 1;
			}
		}
		int sum = T.size();
		string ans = "";
		int n = S.size();
		if(n < sum || n == 0) {
			return ans;
		}
		int begin = 0;
		int end = begin;
		int cur = 0;

		//vector<int> shash(26, 0);
		map<char, int> shash;
		int curlen = n + 1;
		while(end < n) {
			if(shash.count(S[end]) > 0) {
				shash[S[end]]++;
			} else {
				shash[S[end]] = 1;
			}
			if(shash[S[end]] <= hash[S[end]]) {
				++cur;
			}
			while(begin <= end && shash[S[begin]] > hash[S[begin]]) {
				--shash[S[begin]];
				++begin;
			}
			if(cur == sum) {
				if(end + 1 - begin <= curlen) {
					ans = S.substr(begin, end + 1 - begin);
					curlen = end + 1 - begin;
				}
			}
			++end;
		}

		return ans;
    }
};