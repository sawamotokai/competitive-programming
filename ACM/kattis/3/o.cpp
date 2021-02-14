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

int n, k, r;
int main() {
  cin >> n >> k >> r;
  vi cam(k);
  rep(i, k) cin >> cam[i];
  sort(all(cam));
  int cnt = 0;
  int ans = 0;
  int t = r;
  vi C(n + 1);
  rep(i, k) C[cam[i]]++;
  rep2(i, 1, r) cnt += C[i];
  if (cnt == 0) {
    C[r]++;
    C[r - 1]++;
    ans += 2;
  }
  if (cnt == 1) {
    if (!C[r])
      C[r]++;
    else
      C[r - 1]++;
    ans += 1;
  }
  chmax(cnt, 2);

  rep2(i, 1, n - r) {
    // rep(i, n + 1) printf("%d%c", C[i], i == n ? '\n' : ' ');
    cnt += C[i + r];
    cnt -= C[i];
    if (cnt == 1) {
      if (!C[i + r])
        C[i + r]++;
      else
        C[i + r - 1]++;
      ans += 1;
    } else if (cnt == 0) {
      C[i + r]++;
      C[i + r - 1]++;
      ans += 2;
    }
    chmax(cnt, 2);
  }
  cout << ans << endl;
  return 0;
}
