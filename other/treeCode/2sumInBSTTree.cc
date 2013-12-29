#include <stdio.h>
#include <stack>

using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int x): val(x), left(NULL), right(NULL) {}
};

Node* begin(Node* cur, stack<Node*>& stk) {
  if (cur == NULL) {
    return NULL;
  }
  while (cur->left) {
    stk.push(cur);
    cur = cur->left;
  }
  return cur;
}

Node* end(Node* cur, stack<Node*>& stk) {
  if (cur == NULL) {
    return NULL;
  }
  while (cur->right) {
    stk.push(cur);
    cur = cur->right;
  }
  return cur;
}

Node* next(Node* cur, stack<Node*>& stk) {
  if (cur == NULL) {
    NULL;
  }
  if (cur->right) {
    stk.push(cur);
    cur = cur->right;
    while (cur->left) {
      stk.push(cur);
      cur = cur->left;
    }
  } else {
    while (true) {
      Node* old = cur;
      if (stk.empty()) {
        cur = NULL;
      } else {
        cur = stk.top();
        stk.pop();
      }
      if (!cur || cur->left == old) {
        break;
      }
    }
  }
  return cur;
}

Node* prev(Node* cur, stack<Node*>& stk) {
  if (cur == NULL) {
    NULL;
  }
  if (cur->left) {
    stk.push(cur);
    cur = cur->left;
    while (cur->right) {
      stk.push(cur);
      cur = cur->right;
    }
  } else {
    while (true) {
      Node* old = cur;
      if (stk.empty()) {
        cur = NULL;
      } else {
      cur = stk.top();
      stk.pop();
      }
      if(!cur || cur->right == old) {
          break;
      }
    }
  }
  return cur;
}

void get2Sum(Node* &root, const int target) {
    stack<Node*> st;
    stack<Node*> st2;
    Node* beg = begin(root, st);
    Node* en = end(root, st2);
    if(beg && en) {
    while(beg != en) {
        if(beg->val + en->val == target) {
            printf("%d, %d\n",beg->val, en->val);
            return;
        }
        if(beg->val + en->val > target) {
            en = prev(en, st2);
        } else {
            beg = next(beg, st);
        }
    }
    }
    printf("No such pair\n");
}

int main() {
    Node* root = new Node(15);
    Node* p5 = new Node(5);
    Node* p6 = new Node(6);
    Node* p17 = new Node(17);
    Node* p16 = new Node(16);
    Node* p20 = new Node(20);
    root->left = p5;
    root->right = p17;
    p5->right = p6;
    p17->left = p16;
    p17->right = p20;
    int target;
    scanf("%d",&target);
    get2Sum(root, target);
}
