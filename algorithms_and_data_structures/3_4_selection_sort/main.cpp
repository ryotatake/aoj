#include <bits/stdc++.h>

using namespace std;

int selectionSort(int A[], int N) {
  int count = 0;
  for (int i = 0; i < N; i++) {
    int minj = i;
    for (int j = i; j < N; j++) {
      if (A[minj] > A[j]) {
        minj = j;
      }
    }
    if (minj != i) {
      swap(A[minj], A[i]);
      count++;
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
  int count = selectionSort(A, N);
  for (int i = 0; i < N; i++) {
    cout << A[i];
    if (i != N - 1) cout << " ";
  }
  cout << endl;
  cout << count << endl;
  return 0;
}
