#include <bits/stdc++.h>

using namespace std;

struct Card { char suit, value; };

void bubbleSort(struct Card A[], int N) {
  bool flag = 1;
  for (int i = 0; flag; i++) {
    flag = 0;
    for (int j = N - 1; j > i; j--) {
      if (A[j].value < A[j - 1].value) {
        swap(A[j], A[j - 1]);
        flag = 1;
      }
    }
  }
}

void selectionSort(struct Card A[], int N) {
  for (int i = 0; i < N; i++) {
    int minj = i;
    for (int j = i; j < N; j++) {
      if (A[minj].value > A[j].value) minj = j;
    }
    swap(A[i], A[minj]);
  }
}

void print(struct Card A[], int N) {
  for (int i = 0; i < N; i++) {
    cout << A[i].suit << A[i].value;
    if (i != N - 1) cout << " ";
  }
  cout << endl;
}

bool isStable(struct Card C1[], struct Card C2[], int N) {
  for (int i = 0; i < N; i++) {
    if (C1[i].suit != C2[i].suit) return false;
  }
  return true;
}

int main() {
  int N;
  cin >> N;
  Card C1[N], C2[N];
  for (int i = 0; i < N; i++) cin >> C1[i].suit >> C1[i].value;
  for (int i = 0; i < N; i++) C2[i] = C1[i];

  bubbleSort(C1, N);
  selectionSort(C2, N);
  print(C1, N);
  cout << "Stable" << endl;
  print(C2, N);
  if (isStable(C1, C2, N)) cout << "Stable";
  else cout << "Not stable";
  cout << endl;

  return 0;
}
