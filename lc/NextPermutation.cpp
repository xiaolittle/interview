class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = num.size();
        int pos = n - 1;
        while(pos > 0 && num[pos - 1]  >= num[pos]) {
            --pos;
        }
        if(pos == 0) {
            sort(num.begin(), num.end());
            return;
        }
        int pos2 = n - 1;
        while(pos2 > pos && num[pos2] <= num[pos - 1]) {
            --pos2;
        }
        swap(num[pos - 1], num[pos2]);
        reverse(num.begin() + pos, num.end());
    }
};