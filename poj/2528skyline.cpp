#include <stdio.h>
#include <set>

using namespace std;

struct Segment {
    int l;
    int r;
    int id;
    Segment(int ll, int rr, int idd) : l(ll), r(rr), id(idd) {};
    bool operator< (const Segment &other) const{
        return l < other.l;
    }
};

void inserts(set<Segment> &ori, Segment s) {
    if(ori.size() == 0) {
        ori.insert(s);
        return;
    }
    set<Segment>::iterator pos = ori.lower_bound(s);
    set<Segment>::iterator pre = pos;
    if(pos == ori.begin()) {
        pre = ori.end();
    } else {
        --pre;
    }
    if(pre != ori.end() && pre->r >= s.l) {
//        printf("hahaha\n");
        int left = pre->l;
        int right = pre->r;
        int idd = pre->id;
        ori.erase(pre);
        ori.insert(Segment(left, s.l - 1, idd));
        pos = (ori.insert(Segment(s.l, right, idd))).first;
    }
    set<Segment>::iterator it,nxt;
    nxt = pos;
    while(nxt != ori.end()) {
        if(nxt->r > s.r) {
            break;
        }
        it = nxt;
        ++it;
        ori.erase(nxt);
        nxt = it;
    }
    if(nxt == ori.end()) {
        ori.insert(s);
        return;
    } else {
        int right = nxt->r;
        int idd = nxt->id;
        ori.erase(nxt);
        ori.insert(s);
        ori.insert(Segment(s.r + 1, right, idd));
    }

}

int main() {
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; ++i) {
        int m;
        scanf("%d",&m);
        set<Segment> segments;
        set<int> ha;
        for(int j = 0; j < m; ++j) {
            int left,right;
            scanf("%d%d",&left,&right);
            inserts(segments, Segment(left, right, j));
        }
        set<Segment>::iterator op;
        int count = 0;
        for(op = segments.begin(); op != segments.end(); ++op) {
  //          printf("[%d, %d], id = %d\n",op->l, op->r, op->id);
            if(ha.count(op->id) > 0) {
                continue;
            } else {
                ha.insert(op->id);
                ++count;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
