#include <bits/stdc++.h>

using namespace std;

vector<string> v;

void insert(string s) {
  auto pos = lower_bound(v.begin(), v.end(), s);
  v.insert(pos, s);
}

void find(string s) {
  if (*lower_bound(v.begin(), v.end(), s) == s) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }
}

int main() {
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    string method, s;
    cin >> method >> s;
    if (method == "insert") insert(s);
    if (method == "find") find(s);
  }
  return 0;
}
