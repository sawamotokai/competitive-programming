#include <bits/stdc++.h>
using namespace std;

// a < b か？
bool comp(char a, char b) {
  if (a == 'R')
    return (b == 'P');
  else if (a == 'P')
    return (b == 'S');
  else
    return (b == 'R');
}
// a と b のどちらが勝つか？
char which(char a, char b) {
  if (comp(a, b))
    return b;
  else
    return a;
}

int main() {
  int N, K;
  string S;
  cin >> N >> K >> S;

  auto run = [&]() -> void {
    string T = S + S;
    S = "";
    for (int i = 0; i < N * 2; i += 2)
      S += which(T[i], T[i + 1]);
  };
  for (int k = 0; k < K; ++k)
    run();
  cout << S[0] << endl;
}
