#include <bits/stdc++.h>

using namespace std;

struct Point { double x, y; };

void koch(int d, Point p1, Point p2) {
  if (d == 0) return;
  Point s, u, t;
  double th = M_PI * 60.0 / 180.0;

  s.x = p2.x / 3 + p1.x / 3 * 2;
  s.y = p2.y / 3 + p1.y / 3 * 2;
  t.x = p2.x / 3 * 2 + p1.x / 3;
  t.y = p2.y / 3 * 2 + p1.y / 3;
  u.x = (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x;
  u.y = (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th) + s.y;

  koch(d - 1, p1, s);
  cout << s.x << " " << s.y << endl;
  koch(d - 1, s, u);
  cout << u.x << " " << u.y << endl;
  koch(d - 1, u, t);
  cout << t.x << " " << t.y << endl;
  koch(d - 1, t, p2);
}

int main() {
  int n; cin >> n;
  Point a, b;
  a.x = 0;
  a.y = 0;
  b.x = 100;
  b.y = 0;

  cout << 0 << " " << 0 << endl;
  koch(n, a, b);
  cout << 100 << " " << 0 << endl;
  return 0;
}
