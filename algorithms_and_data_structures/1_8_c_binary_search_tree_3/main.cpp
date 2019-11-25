#include <bits/stdc++.h>

using namespace std;

struct Node {
  int key;
  Node *parent, *left, *right;
};

Node *root, *NIL;

void insert(int key) {
  Node *y = NIL;
  Node *x = root;
  Node *z;

  z = (Node *)malloc(sizeof(Node));
  z->key = key;
  z->left = NIL;
  z->right = NIL;

  while (x != NIL) {
    y = x;
    if (z->key < x->key) {
      x = x->left;
    } else {
      x = x->right;
    }
  }
  z->parent = y;

  if (y == NIL) {
    root = z;
  } else {
    if (z->key < y->key) {
      y->left = z;
    } else {
      y->right = z;
    }
  }
}

Node * find(Node *node, int key) {
  while (node != NIL && key != node->key) {
    if (key < node->key) {
      node = node->left;
    } else if (key > node->key) {
      node = node->right;
    }
  }
  return node;
}

Node * treeMinimum(Node *x) {
  while (x->left != NIL) x = x->left;
  return x;
}

Node * treeSuccessor(Node *x) {
  if (x->right != NIL) return treeMinimum(x->right);
  Node *y = x->parent;
  while (y != NIL && x == y->right) {
    x = y;
    y = y->parent;
  }
  return y;
}

void treeDelete(Node *z) {
  Node *target; // 削除対象
  Node *target_child;

  if (z->left == NIL || z->right == NIL) target = z;
  else target = treeSuccessor(z);

  if (target->left != NIL) {
    target_child = target->left;
  } else {
    target_child = target->right;
  }

  if (target_child != NIL) {
    target_child->parent = target->parent;
  }

  if (target->parent == NIL) {
    root = target_child;
  } else {
    if (target == target->parent->left) {
      target->parent->left = target_child;
    } else {
      target->parent->right = target_child;
    }
  }

  if (target != z) {
    z->key = target->key;
  }

  free(target);
}

void inorder(Node *node) {
  if (node == NIL) return;
  inorder(node->left);
  printf(" %d", node->key);
  inorder(node->right);
}
void preorder(Node *node) {
  if (node == NIL) return;
  printf(" %d", node->key);
  preorder(node->left);
  preorder(node->right);
}


int main() {
  int n; cin >> n;

  for (int i = 0; i < n; i++) {
    string s; int key;
    cin >> s;
    if (s == "insert") {
      cin >> key;
      insert(key);
    } else if (s == "find") {
      cin >> key;
      Node *node = find(root, key);
      if (node != NIL) cout << "yes" << endl;
      else cout << "no" << endl;
    } else if (s == "print") {
      inorder(root);
      printf("\n");
      preorder(root);
      printf("\n");
    } else if (s == "delete") {
      cin >> key;
      treeDelete(find(root, key));
    }
  }

  return 0;
}
