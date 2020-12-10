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

int n;
int cnt[100005];

int main() {
  cin >> n;
  vi A(n);
  rep(i, n) cin >> A[i];
  rep(i, n) { cnt[A[i]]++; }
  int kinds = 0;
  rep(i, 100005) if (cnt[i] >= 1) kinds++;
  cout << kinds << endl;
  int dup = n - kinds;
  if (dup & 1) {
    cout << kinds - 1 << endl;
    return 0;
  }
  int tot = 0;
  rep(i, 100005) {
    int now = cnt[A[i]];
    if (now > 1)
      tot += now - 1;
    if (now == 1 && dup / 2 == tot) {
      cout << kinds << endl;
      return 0;
    }
  }
  cout << kinds - 1 << endl;
  return 0;
}
