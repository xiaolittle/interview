class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = gas.size();
        vector<int> diffs(2 * n);
        for (int i = 0; i < n; ++i) {
            diffs[i] = gas[i] - cost[i];
            diffs[i + n] = diffs[i];
        }
        
        for (int i = 0; i < n; ) {
            if (diffs[i] < 0) {
                ++i;
                continue;
            }
            int sum = 0;
            for (int j = 0; j < n; ++j) {
                sum += diffs[i + j];
                if (sum < 0) {
                    i = i + j + 1;
                    break;
                }
            }
            if (sum >= 0) {
                return i;
            }
        }
        return -1;
    }
};
