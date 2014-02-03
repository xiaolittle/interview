int getMaxValue(int t, vector<pair<int, int> > bag) {
    int ans = 0;
    int n = bag.size();
    vector<int> v(w + 1, 0);
    for(int i = 0; i < n; ++i) {
        for(int j = t; j >= bag[i].first; --j) {
            v[j] = max(v[j], v[j - bag[i].first] + bag[i].second);
        }
    }
    return v[w];
}
