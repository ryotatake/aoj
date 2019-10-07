#include <bits/stdc++.h>

using namespace std;

int n, A[21];

int solve(int i, int m) {
  if (m == 0) return 1;
  if (i >= n) return 0;
  int result = solve(i + 1, m) || solve(i + 1, m - A[i]);
  return result;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  int q, m;
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> m;
    if (solve(0, m)) cout << "yes" << endl;
    else cout << "no" << endl;
  }
  return 0;
}
