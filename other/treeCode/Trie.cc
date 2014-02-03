class Trie {
public:
    Trie(): root(nullptr) {}

    void insert(const string& s) {
        if (root == nullptr) {
            root = new TrieNode();
        }   
        TrieNode* x = root;
        for (int i = 0; i < s.length(); ++i) {
            TrieNode* &child = x->next[s[i] - 'a'];
            if (!child) {
                child = new TrieNode();
            }   
            x = child;
        }   
        if (!x->isWord) {
            x->isWord = true;
        }   
    }   

    bool find(const string& s) {
        TrieNode* x = root;
        for (int i = 0; x && i < s.length(); ++i) {
            x = x->next[s[i] - 'a'];
            if (!x) {
                return false;
            }   
        }   
        return x && x->isWord;
    }   
