#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, q;
  cin >> n;
  vector<int> v;

  for (int i = 0; i < n; i++) {
    int s; cin >> s;
    v.push_back(s);
  }

  cin >> q;
  long long int ans = 0;

  for (int i = 0; i < q; i++) {
    int t; cin >> t;
    if ( *lower_bound(v.begin(), v.end(), t) == t ) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
