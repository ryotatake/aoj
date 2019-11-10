#include <bits/stdc++.h>

using namespace std;

#define NIL -1
#define MAX 10000

struct Node { int parent, left, right; };
struct Node Nodes[MAX];
int n;

void preParse(int id) {
  if (id == NIL) return;
  printf(" %d", id);
  preParse(Nodes[id].left);
  preParse(Nodes[id].right);
}

void inParse(int id) {
  if (id == NIL) return;
  inParse(Nodes[id].left);
  printf(" %d", id);
  inParse(Nodes[id].right);
}

void postParse(int id) {
  if (id == NIL) return;
  postParse(Nodes[id].left);
  postParse(Nodes[id].right);
  printf(" %d", id);
}

int getRoot() {
  for (int i = 0; i < n; i++) {
    if (Nodes[i].parent == NIL) return i;
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    Nodes[i].parent = -1;
  }
  for (int i = 0; i < n; i++) {
    int id, left, right;
    cin >> id >> left >> right;
    Nodes[id].left = left;
    Nodes[id].right = right;
    Nodes[left].parent = id;
    Nodes[right].parent = id;
  }

  int root = getRoot();

  printf("Preorder\n");
  preParse(root);
  printf("\n");
  printf("Inorder\n");
  inParse(root);
  printf("\n");
  printf("Postorder\n");
  postParse(root);
  printf("\n");

  return 0;
}
