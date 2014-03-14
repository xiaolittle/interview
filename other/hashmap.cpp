/*
MyHashMap *p_hash = new MyHashMap();
p_hash->put("ff", "gg")
p_hash->get("ff")
for(int i=0;i<65535;++i)
2^31 - 1
*/
    p_hash->doubleSize()

class MyHashMap { 
    private:
   int hashSize_;
   vector<vector<pair<string, string> > >* buckets;
   
   public:
   
   MyHashMap(int hashSize) : hashSize_(hashSize) {
       if(hashSize_ <= 0) {
           hashSize_ = 1;
       }
       buckets = new vector<vector<pair<string, string> > >(hashSize_);
   }

    ~MyHashMap() {
        delete buckets;
    }
    
    void put(const string& key, const string& val) {
        int pos = hashFunc(key) % hashSize_;
        for(int i = 0; i < buckets[pos].size(); ++i) {
            if(buckets[pos][i].first == key) {
                buckets[pos][i].second = val;
                return;
            }
        }
        buckets[pos].push_back(pair<string, string>(key, val));
    }
    
    string get(const string& key) const{
        int pos = hashFunc(key) % hashSize_;
        for(int i = 0; i < buckets[pos].size(); ++i) {
            if(buckets[pos][i].first == key) {
                return buckets[pos][i].second;
            }
        }
        return "";
    }
    
    bool doubleSize() {
        if(hashSize_ > MAX_INT / 2) {
            return false;
        }
        vector<vector<pair<string, string> > >* newBuckets;
        newBuckets = new vector<vector<pair<string, string> > > (hashSize_ * 2);
        
        for(int i = 0; i < hashSize_; ++i) {
            for(int j = 0; j < buckets[i].size(); ++j) {
                int pos = hashFunc(buckets[i][j].first) % (hashSize_ * 2);
                newBuckets[pos].push_back(buckets[i][j]);
            }
        }
        
        delete buckets;
        buckets = newBuckets;
        hashSize_ *= 2;
        return true;
    }
    
}
