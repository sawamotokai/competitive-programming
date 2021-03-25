// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) { return a + rand() % (b - a + 1); }

int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  srand(t); // atoi(s) converts an array of chars to int
  int n = rand(2, 10);
  printf("%d\n", n);
  vector<int> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    int x = rand(1, 10);
    int y = rand(1, 10);
    a[i] = x;
    b[i] = y;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d%c", a[i] + b[j], j == n - 1 ? '\n' : ' ');
    }
  }
  puts("");
}
