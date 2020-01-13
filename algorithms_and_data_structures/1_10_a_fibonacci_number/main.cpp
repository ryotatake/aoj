#include <bits/stdc++.h>

using namespace std;

int dp[50];

void makeFib(int n) {
  dp[0] = 1;
  dp[1] = 1;
  for (int i = 2; i <= n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }
}

int main()
{
  int n; cin >> n;
  makeFib(n);

  cout << dp[n] << endl;
  return 0;
}
