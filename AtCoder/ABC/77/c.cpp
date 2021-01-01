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
template <class T> void takeUnique(vector<T> &v) {
  auto last = std::unique(v.begin(), v.end());
  v.erase(last, v.end());
}
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int dxx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dyy[] = {1, 1, 0, -1, -1, -1, 0, 1};
// clang++ -std=c++11 -stdlib=libc++

int main() {
  int N;
  cin >> N;
  vll A(N);
  vll B(N);
  vll C(N);
  rep(i, N) cin >> A[i];
  rep(i, N) cin >> B[i];
  rep(i, N) cin >> C[i];
  sort(all(A));
  sort(all(B));
  sort(all(C));

  vll bb(N);     // num of c lemenets smaller tahn B[i]
  vll ss(N + 1); // num of c lemenets smaller tahn B[i]
  int p = 0;
  rep(i, N) {
    if (i)
      bb[i] = bb[i - 1];
    while (p < N && A[p] < B[i]) {
      bb[i]++;
      p++;
    }
  }
  rep(i, N) ss[i + 1] += ss[i] + bb[i];
  ll ans = 0;
  rep(i, N) {
    int c = C[i];
    auto itB = lower_bound(all(B), c);
    int idx = itB - B.begin() - 1;
    ans += ss[idx + 1];
  }
  cout << ans << endl;
  return 0;
}
