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
  int h, w;
  cin >> h >> w;
  vector<string> grid(h);
  rep(i, h) cin >> grid[i];
  vi mp(26);
  rep(i, h) rep(j, w) mp[grid[i][j] - 'a']++;
  int one, two = 0, four = 0;
  if ((h & 1) && (w & 1))
    one = 1;
  else
    one = 0;
  if (h & 1)
    two += w / 2;
  if (w & 1)
    two += h / 2;
  four = (h * w - one - 2 * two) / 4;
  // cout << one << two << four << endl;
  sort(all(mp));
  bool ok = true;
  rep(i, 26) {
    if (mp[i] & 1) {
      if (one) {
        one = 0;
        mp[i]--;
      } else {
        ok = false;
        break;
      }
    }
    if (mp[i] == 0)
      continue;
    while (mp[i] >= 4 && four) {
      four--;
      mp[i] -= 4;
    }
    while (mp[i] >= 2 && two) {
      two--;
      mp[i] -= 2;
    }
    if (mp[i] % 2 == 1) {
      if (one) {
        one = 0;
        mp[i]--;
      } else {
        ok = false;
        break;
      }
    } else if (mp[i]) {
      ok = false;
      break;
    }
  }
  ok();
  return 0;
}
