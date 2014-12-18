class LRUCache{
public:
    struct LRUNode {
      int v;
      int k;
    };
    typedef list<LRUNode>::iterator NodeIterator;
    list<LRUNode> nodes_;
    map<int, NodeIterator> map_;
    int size_,maxSize_;
    LRUCache(int capacity) {
        size_ = 0;
        maxSize_ = capacity;
    }
    
    int get(int key) {
        map<int, NodeIterator>::iterator lookup = map_.find(key);
        if(lookup == map_.end()) {
            return -1;
        }
        NodeIterator it = lookup->second;
        int curv = it->v;
        nodes_.insert(nodes_.begin(), *it);
        nodes_.erase(it);
        map_[key] = nodes_.begin();
        return curv;
    }
    
    void set(int key, int value) {
        map<int, NodeIterator>::iterator lookup = map_.find(key);
        if(lookup != map_.end()) {  // Aleardy exist
            NodeIterator it = lookup->second;
            it->v = value;
            nodes_.insert(nodes_.begin(), *it);
            nodes_.erase(it);
            map_[key] = nodes_.begin();
            return;
        }
        if(size_ == maxSize_) {  // The cache aleardy full, delete the tail node
            NodeIterator tailIter = --nodes_.end();
            map_.erase(tailIter->k);
            nodes_.erase(tailIter);
            --size_;
        }
        // insert the new node into the head of the list
        LRUNode newnode;
        newnode.k = key;
        newnode.v = value;
        map_[key] = nodes_.insert(nodes_.begin(), newnode);
        ++size_;
    }
};
