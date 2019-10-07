#include <bits/stdc++.h>

using namespace std;

int partition(int A[], int p, int r) {
  int x = A[r];
  int i = p - 1;
  int tmp;
  for (int j = p; j < r; j++) {
    if (A[j] <= x) {
      i++;
      tmp = A[i]; A[i] = A[j]; A[j] = tmp;
    }
  }
  tmp= A[i + 1]; A[i + 1] = A[r]; A[r] = tmp;
  return i + 1;
}

int main() {
  int n; cin >> n;
  int A[n + 1];
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  int base_index = partition(A, 0, n - 1);
  for (int i = 0; i < n; i++) {
    if (i) cout << " ";
    if (i == base_index) {
      cout << "[" << A[i] << "]";
    } else {
      cout << A[i];
    }
  }
  cout << endl;

  return 0;
}
