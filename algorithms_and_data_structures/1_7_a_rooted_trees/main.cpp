#include <bits/stdc++.h>

using namespace std;
#define MAX 100005
#define NIL -1

struct Node {
  int parent;
  int left; // 子の一番左
  int right; // 右の兄弟
};

Node T[MAX];
int n, D[MAX];

void print(int id) {
  int i, c;
  cout << "node " << id << ": ";
  cout << "parent = " << T[id].parent << ", ";
  cout << "depth = " << D[id] << ", ";

  if (T[id].parent == NIL) cout << "root, ";
  else if (T[id].left == NIL) cout << "leaf, ";
  else cout << "internal node, ";

  cout << "[";
  for (i = 0, c = T[id].left; c != NIL; i++, c = T[c].right) {
    if (i) cout << ", ";
    cout << c;
  }
  cout << "]" << endl;
}

void setDepth(int id, int depth) {
  D[id] = depth;
  if (T[id].right != NIL) setDepth(T[id].right, depth);
  if (T[id].left != NIL) setDepth(T[id].left, depth + 1);
}

int main() {
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    T[i].parent = T[i].left = T[i].right = NIL;
  }
  for (int i = 0; i < n; i++) {
    int id, k; cin >> id >> k;
    int before;
    for (int j = 0; j < k; j++) {
      int child; cin >> child;
      if (j == 0) T[id].left = child;
      else T[before].right = child;
      before = child;
      T[child].parent = id;
    }
  }
  int root;
  for (int i = 0; i < n; i++) {
    if (T[i].parent == NIL) root = i;
  }
  setDepth(root, 0);
  for (int i = 0; i < n; i++) print(i);
  return 0;
}


