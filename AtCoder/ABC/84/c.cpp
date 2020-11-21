#include <bits/stdc++.h>
#include <cassert>
#define rep(i, N) for (int i = 0; i < (N); ++i)
#define rep2(i, a, b) for (ll i = a; i <= b; ++i)
#define rep3(i, a, b) for (ll i = a; i >= b; --i)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(c) begin(c), end(c)
#define ok() puts(ok ? "Yes" : "No");
template <class T> bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T> bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using ii = pair<int, int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using gt = greater<int>;
using minq = priority_queue<int, vector<int>, gt>;
using P = pair<ll, ll>;
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
// clang++ -std=c++11 -stdlib=libc++

int N;
int C[505];
int S[505];
int F[505];

int main() {
  cin >> N;
  rep(i, N - 1) cin >> C[i] >> S[i] >> F[i];

  rep(i, N - 1) {
    ll t = S[i];
    rep2(j, i, N - 2) {
      if (S[j] > t)
        t = S[j];
      if ((t + F[j]) % F[j] != 0)
        t += (F[j] - (t + F[j]) % F[j]);
      t += C[j];
    }
    cout << t << endl;
  }
  cout << 0 << endl;
  return 0;
}
