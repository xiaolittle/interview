#include <stdio.h>

class RankNode {
	public:
	int val;
	int leftsize;
	RankNode* left;
	RankNode* right;
	
	RankNode(int d): val(d), leftsize(0), left(NULL), right(NULL) {}

	void insert(const int &d) {
		if(d == val) {
			return;
		} else if(d < val) {
			if(left != NULL) {
				left->insert(d);
			} else {
				left = new RankNode(d);
			}
			leftsize++;
		} else {
			if(right != NULL) {
				right->insert(d);
			} else {
				right = new RankNode(d);
			}
		}
	}

	int getRank(const int &d) {
		if(d == val) {
			return leftsize;
		} else if(d < val) {
			if(left != NULL) {
				return left->getRank(d);
			} else {
				return -1;
			}
		} else {
			if(right != NULL) {
				int rightrank = right->getRank(d);
				if(rightrank != -1) {
					return (leftsize + 1 + rightrank);
				} else {
					return -1;
				}
			} else {
				return -1;
			}
		}
	}
};

int main(int argc, char *argv[])
{
	RankNode* root = new RankNode(20);
	root->insert(15);
	root->insert(10);
	root->insert(5);
	root->insert(13);
	root->insert(25);
	root->insert(23);
	root->insert(24);
	printf("%d\n",root->getRank(23));
	
	return 0;
}
