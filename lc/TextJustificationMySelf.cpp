#include <vector>
#include <string>
#include <string.h>
#include <stdio.h>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = words.size();
		vector<string> ans;
		for(int i = 0; i < len;) {
			int word_len = words[i].size();
			string tmp = words[i];
			int blank_len = 1;
			int j = i + 1;
			//printf("1 i = %d,j = %d,wordlen = %d\n",i, j, word_len);
			while(j < len && ((word_len + blank_len + words[j].size()) <= L)) {
				word_len += words[j].size();
				blank_len++;
				j++;
			}
			//printf("i = %d,j = %d,wordlen = %d\n",i, j, word_len);
			blank_len = L - word_len;
			if(j == i + 1) {	// only one word in that line
				while(blank_len) {
					tmp += ' ';
					blank_len--;
				}
			} else if(j < len) {	// not last line
				//printf("haha i = %d,j = %d,blank_len = %d\n",i, j, blank_len);
				while(i < (j - 1)) {
					int gaps = blank_len % (j - i - 1) ? 1 : 0;
					gaps += blank_len / (j - i - 1);
					blank_len -= gaps;
					while(gaps) {
						tmp += ' ';
						--gaps;
					}
					tmp += words[i + 1];
					++i;
				}
				//printf("heihei i = %d,j = %d,wordlen = %d\n",i, j, word_len);
			} else {	// last line
				for(int k = i + 1; k < len; ++k) {
					tmp += ' ';
					tmp += words[k];
				}
				while(tmp.size() < L) {
					tmp += ' ';
				}
			}
			ans.push_back(tmp);
			i = j;
		}

		return ans;
    }
};

int main(int argc, char *argv[])
{
	Solution s;
	vector<string> str;
	str.push_back("a");
	str.push_back("b");
	str.push_back("c");
	str.push_back("d");
	str.push_back("e");//= ["a","b","c","d","e"];
	s.fullJustify(str, 3);
	
	return 0;
}