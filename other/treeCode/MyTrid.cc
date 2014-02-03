#include <stdio.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <iostream>

using namespace std;

const int MAX_S = 26;
struct TreeNode {
    bool isWord;
    TreeNode* next[MAX_S];

    TreeNode():isWord(false) {
        fill_n(next, MAX_S, nullptr);
    }
};

class Trie {
    public:
    void insert(const string &s) {
        int n = s.size();
        if(n == 0) {
            return;
        }
        if(root == nullptr) {
            root = new TreeNode();
        }
        TreeNode* cur = root;
        for(int i = 0; i < n; ++i) {
            TreeNode* &child = cur->next[s[i] - 'a'];
            if(child == nullptr) {
                child = new TreeNode();
            }
            cur = child;
        }
        if(!cur->isWord) {
            cur->isWord = true;
        }
    }

    bool find(const string& s) {
        if(root == nullptr) {
            return false;
        }
        TreeNode* cur = root;
        for(int i = 0; i < s.size() && cur != nullptr; ++i) {
            cur = cur->next[s[i] - 'a'];
        }
        if(!cur || !cur->isWord) {
            return false;
        }
        return true;
    }

    Trie(): root(nullptr) {};
    private:
    TreeNode* root;
};

int main() {
    char a;
    Trie t;
    while(true) {
        string a;
        cin >> a;
        if(a == "i") {
            string s;
            cin >> s;
            t.insert(s);
        } else if(a == "f") {
            string s;
            cin >> s;
            bool canFind = t.find(s);
            if(canFind) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        } else {
            break;
        }
    }
    return 0;
}
