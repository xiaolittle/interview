class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> ans;
        int n = words.size();
        for(int i = 0; i < n; ) {
            int tl = 0;
            int j = i;
            while(j < n && tl+words[j].length()+j-i <= L) {
                tl += words[j].length();
                j++;
            }
            int x, r;
            if(j < n && j-i >1){
                x = (L-tl)/(j-i-1);
                r = (L-tl)%(j-i-1);
            } else {
                x = 1, r = 0;
            }
            string line = words[i];
            i++;
            for(; i < j; i++) {
                line += string(x+(r>0), ' ');
                r--;
                line += words[i];
            }
            line += string(L-line.length(), ' ');
            ans.push_back(line);
        }
        return ans;
    }
};

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ans;
        string tmp;
        int word_len = 0, blank_len, gaps;
        for (int i = 0; i < words.size(); i++) {
            int j = i + 1;
            tmp = words[i];
            word_len = words[i].length();
            blank_len = 0;
            while (j < words.size() && word_len + blank_len + words[j].length() < L) {
                word_len += words[j].length();
                blank_len++;
                j++;
            }
            blank_len = L - word_len;
            if (j == i + 1) { //only one word in that line
                while (blank_len--) {
                    tmp += ' ';
                }
            } else if (j < words.size()){
                for (int k = i + 1; k < j; k++) {
                    gaps = ((blank_len % (j - k)) ? 1 : 0);
                    gaps += (blank_len / (j - k));
                    blank_len -= gaps;
                    while (gaps--) {
                        tmp += ' ';
                    }
                    tmp += words[k];
                }
            } else { // last line
                for (int k = i + 1; k < j; k++) {
                    tmp += ' ';
                    tmp += words[k];
                }
                while (tmp.length() < L) {
                    tmp += ' ';
                }
            }
            ans.push_back(tmp);
            i = j - 1;
        }
        return ans;
    }
};