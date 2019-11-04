#include <bits/stdc++.h>
#define NIL -1
#define MAX 10000

using namespace std;

struct Node {
  int parent, left, right;
};

Node Nodes[MAX];
int n, Depth[MAX], Height[MAX];

int setHeight(int id) {
  int h1 = 0, h2 = 0;
  if (Nodes[id].left != NIL) {
    h1 = setHeight(Nodes[id].left) + 1;
  }
  if (Nodes[id].right != NIL) {
    h2 = setHeight(Nodes[id].right) + 1;
  }
  return Height[id] = max(h1, h2);
}

void setDepth(int id, int depth) {
  if (id == NIL) return;
  Depth[id] = depth;
  setDepth(Nodes[id].left, depth + 1);
  setDepth(Nodes[id].right, depth + 1);
}

int getSibling(int id) {
  int parent_id = Nodes[id].parent;
  Node parent = Nodes[parent_id];
  if (parent_id == NIL) return NIL;
  if (parent.left != id) return parent.left;
  if (parent.right != id) return parent.right;
}

int getDegree(int id) {
  int degree = 0;
  if (Nodes[id].left != NIL) degree++;
  if (Nodes[id].right != NIL) degree++;
  return degree;
}

string getType(int id) {
  Node node = Nodes[id];
  if (node.parent == NIL) {
    return "root";
  }
  else if (node.left == NIL && node.right == NIL) {
    return "leaf";
  } else {
    return "internal node";
  }
}

void print(int id) {
  printf("node %d: ", id);
  printf("parent = %d, ", Nodes[id].parent);
  printf("sibling = %d, ", getSibling(id));
  printf("degree = %d, ", getDegree(id));
  printf("depth = %d, ", Depth[id]);
  printf("height = %d, ", Height[id]);
  printf("%s\n", getType(id).c_str());
}

int getRoot() {
  for (int i = 0; i < (int)(sizeof(Nodes)/sizeof(Nodes[0])); i++) {
    if (Nodes[i].parent == NIL) return i;
  }
}

int main() {
  int nodes; cin >> nodes;
  for (int i = 0; i < nodes; i++) {
    Nodes[i].parent = -1;
  }
  for (int i = 0; i < nodes; i++) {
    int id, left, right;
    cin >> id >> left >> right;
    Nodes[id].left = left;
    Nodes[id].right = right;
    if (left != NIL) Nodes[left].parent = id;
    if (right != NIL) Nodes[right].parent = id;
  }

  int root = getRoot();
  setHeight(root);
  setDepth(root, 0);

  for (int i = 0; i < nodes; i++) {
    print(i);
  }

  return 0;
}
