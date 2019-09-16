#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  long long int S[n + 1];
  for (int i = 0; i < n; i++) {
    long long int s;
    cin >> s;
    S[i] = s;
  }

  int q;
  cin >> q;
  long long int T[q + 1];
  for (int i = 0; i < q; i++) {
    long long int t;
    cin >> t;
    T[i] = t;
  }

  int total = 0;

  for (int i = 0; i < q; i++) {
    for (int j = 0; j < n; j++) {
      if (T[i] == S[j]) {
        total++;
        break;
      }
    }
  }

  cout << total << endl;
  return 0;
}
