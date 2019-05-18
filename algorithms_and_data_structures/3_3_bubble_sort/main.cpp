#include <bits/stdc++.h>

using namespace std;

int bubbleSort(int A[], int N) {
  int count = 0;
  bool flag = 1;
  for (int i = 1; flag; i++) {
    flag = 0;
    for (int j = N - 1; j >= i; j--) {
      if (A[j] < A[j - 1]) {
        swap(A[j], A[j - 1]);
        flag = 1;
        count++;
      }
    }
  }
  return count;
}

int main() {
  int N;
  cin >> N;
  int A[N];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  int count = bubbleSort(A, N);
  for (int i = 0; i < N; i++) {
    cout << A[i];
    if (i != N - 1) cout << " ";
  }
  cout << endl;
  cout << count << endl;
  return 0;
}
