#include <bits/stdc++.h>
#include <cassert>
#define rep(i, N) for (int i = 0; i < (N); ++i)
#define rep2(i, a, b) for (ll i = a; i <= b; ++i)
#define rep3(i, a, b) for (ll i = a; i >= b; --i)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define nl '\n'
#define endl '\n'
#define all(c) begin(c), end(c)
#define ok() puts(ok ? "Yes" : "No");
#define pcnt(x) __builtin_popcountll(x)
#define df(x) ll x = in();
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
using vvll = vector<vll>;
using ii = pair<int, int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vs = vector<string>;
using P = pair<ll, ll>;
using gt = greater<P>;
using minq = priority_queue<P, vector<P>, gt>;
using vP = vector<P>;
inline ll in() {
  ll x;
  scanf("%lld", &x);
  return x;
}
template <class T> void takeUnique(vector<T> &v) {
  auto last = std::unique(v.begin(), v.end());
  v.erase(last, v.end());
}
template <class T> void print(const initializer_list<T> &il) {
  for (auto x : il) {
    cout << x << " ";
  }
  cout << "\n";
}
inline void priv(vi a) {
  rep(i, (int)a.size())
      printf("%d%c", a[i], i == (int)a.size() - 1 ? '\n' : ' ');
}
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int dxx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dyy[] = {1, 1, 0, -1, -1, -1, 0, 1};
// clang++ -std=c++11 -stdlib=libc++

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int H, W, A, B;
  cin >> H >> W >> A >> B;
  int HW = H * W;
  ll ans = 0;
  rep(i, 1 << HW) {
    if (__builtin_popcountll(i) != A)
      continue;
    vvi grid(H, vi(W));
    rep(j, HW) {
      if ((i >> j) & 1) {
        int h = j / W;
        int w = j % W;
        grid[h][w] = 1;
      }
    }
    rep(h, H) {
      rep(w, W) { cout << grid[h][w]; }
      cout << nl;
    }
    ll now = 1;
    int dup = 0;
    rep(h, H) {
      rep(w, W) {
        if (grid[h][w]) {
          if (h + 1 >= H and w + 1 >= W) {
            now = 0;
            break;
          }
          if (h + 1 >= H)
            now *= grid[h][w + 1] == 0;
          else if (w + 1 >= W)
            now *= grid[h + 1][w] == 0;
          else
            now *= (2 - grid[h + 1][w] - grid[h][w + 1]);
          if (h + 1 < H and w and grid[h + 1][w - 1])
            dup++;
          if (h and w + 1 < W and grid[h - 1][w + 1])
            dup++;
        }
      }
    }
    ans += (now >> dup);
  }
  cout << ans << nl;
  return 0;
}
