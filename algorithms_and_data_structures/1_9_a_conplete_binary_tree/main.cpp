#include <bits/stdc++.h>

using namespace std;
#define MAX 300

int parent(int i) {
  return i / 2;
}
int left(int i) {
  return i * 2;
}
int right(int i) {
  return i * 2 + 1;
}

int main() {
  int A[MAX];
  int H; cin >> H;

  for (int i = 1; i <= H; i++) {
    cin >> A[i];
  }
  for (int i = 1; i <= H; i++) {
    cout << "node " << i << ": key = " << A[i] << ", ";
    if (parent(i) >= 1) cout << "parent key = " << A[parent(i)] << ", ";
    if (left(i) <= H) cout << "left key = " << A[left(i)] << ", ";
    if (right(i) <= H) cout << "right key = " << A[right(i)] << ", ";
    cout << endl;
  }

  return 0;
}
