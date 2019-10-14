#include <bits/stdc++.h>

using namespace std;
#define MAX 2000001
#define VMAX 10000

int main() {
  int C[VMAX + 1];
  int n; cin >> n;

  int A[n + 1], B[n + 1];
  for (int i = 0; i <= VMAX; i++) C[i] = 0;
  for (int i = 1; i <= n; i++) { // ここでi = 0からではなく1から入れるのがポイント
    cin >> A[i];
    C[A[i]]++;
  }
  for (int i = 0; i < VMAX; i++) {
    C[i + 1] += C[i];
  }
  for (int i = 1; i <= n; i++) {
    B[C[A[i]]] = A[i];
    C[A[i]]--;
  }
  for (int i = 1; i <= n; i++) {
    if (i != 1) cout << " ";
    cout << B[i];
  }
  cout << endl;

  return 0;
}
