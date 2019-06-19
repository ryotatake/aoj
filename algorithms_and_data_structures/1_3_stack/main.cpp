#include <bits/stdc++.h>
using namespace std;

int top, S[200];

void push(int x) {
  S[++top] = x;
}

int pop() {
  return S[top--];
}

int main() {
  int a, b;
  top = 0;
  char c[10];
  while (cin >> c) {
    if (c[0] == '+') {
      a = pop();
      b = pop();
      push(a + b);
    }
    else if (c[0] == '-') {
      b = pop();
      a = pop();
      push(a - b);
    }
    else if (c[0] == '*') {
      a = pop();
      b = pop();
      push(a * b);
    }
    else {
      push(atoi(c));
    }
  }
  cout << pop() << endl;
  return 0;
}
