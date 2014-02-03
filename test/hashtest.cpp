#include <unordered_set>
#include <stdio.h>

using namespace std;

struct MyHasher {
    size_t operator()(const int&key) const {
        return key % 13;
    }
};
int main() {
    unordered_set<int, MyHasher> s;
    s.insert(13);
    s.insert(5);
    s.insert(26);
    s.insert(13);
    for(int a:s) {
        printf("%d\n",a);
    }
}
