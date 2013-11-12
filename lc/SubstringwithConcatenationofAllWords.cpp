class Solution {
public:
	vector<int> findIndex(vector<int> &numbers, vector<int> &counts, const int &sum) {
		int n = numbers.size();
		vector<int> curans;
		int curnum = 0;
		for(int i = 0; i < n;) {
			vector<int> tmp(counts.size(), 0);
			if(numbers[i] == 0) {
				++i;
				continue;
			}
			int cur = 0;
			int j = i;
			while(j < n && numbers[j] != 0) {
				if(tmp[numbers[j]] < counts[numbers[j]]) {
					++cur;
					++tmp[numbers[j]];
					if(cur == sum) {
						curans.push_back(i);
						++j;
						--tmp[numbers[i]];
						++i;
						--cur;
					} else {
						++j;
					}
				} else {
					while(i < j && numbers[i] != numbers[j]) { // jend exceed
						++i;
						--tmp[numbers[i]];
						--cur;
					}
					if(numbers[i] == numbers[j]) {
						++i;
						++j;
					}
				}
			}
			i = j + 1;
		}

		return curans;
	}

    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<int> ans;
		if(L.size() == 0) {
			return ans;
		}
        map<string, int> hash;
		vector<int> counts(L.size() + 1, 0);
		for(int i = 0; i < L.size(); ++i) {
			if(hash.count(L[i]) <= 0) {
				hash[L[i]] = i + 1;
			}
			++counts[hash[L[i]]];
		}

		int len = S.size();
		int wordlen = L[0].size();
		for(int i = 0; i < wordlen; ++i) {
			int k = 0;
			vector<int> numbers;
			for(int j = 0; i + j + wordlen <= len; j += wordlen, ++k) {
				if(hash.count(S.substr(i + j, wordlen)) > 0) {
					numbers.push_back(hash[S.substr(i + j, wordlen)]);
				} else {
					numbers.push_back(0);
				}
			}
			vector<int> cur = findIndex(numbers, counts, L.size());

			for(int x = 0; x < cur.size(); ++x) {
				ans.push_back(i + cur[x] * wordlen);
			}
		}

		return ans;
    }
};