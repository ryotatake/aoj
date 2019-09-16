#include <bits/stdc++.h>

using namespace std;

long long cnt;
int A[1000000];
int n;
vector<int> G;

// 間隔gを指定した挿入ソート
void insertionSort(int A[], int n, int g) {
  for (int i = g; i < n; i++) {
    int v = A[i];
    int j = i - g;
    while (j >= 0 && A[j] > v) {
      A[j + g] = A[j];
      j -= g;
      cnt++;
    }
  A[j + g] = v;
  }
}

void shellSort(int A[], int n) {
  // 数列Gを生成
  for (int h = 1; ;) {
    if (h > n) break;
    G.push_back(h);
    h = h * 3 + 1;
  }
  for (int i = G.size() - 1; i >= 0; i--) {
    insertionSort(A, n, G[i]);
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) scanf("%d", &A[i]);
  cnt = 0;

  shellSort(A, n);

  cout << G.size() << endl;
  for (int i = G.size() - 1; i >= 0; i--) {
    cout << G[i];
    if (i) cout << " ";
  }
  cout << endl;
  cout << cnt << endl;
  for (int i = 0; i < n; i++) {
    cout << A[i] << endl;
  }
  return 0;
}