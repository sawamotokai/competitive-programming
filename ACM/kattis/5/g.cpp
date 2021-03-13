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
  int W, H, D;
  cin >> W >> H >> D;
  vs front(H);
  vs right(H);
  vs top(D);
  rep(i, H) cin >> front[i];
  rep(i, H) cin >> right[i];
  rep(i, D) cin >> top[i];
  // check depth
  rep(i, D) {
    int any = 0;
    rep(j, H) if (right[j][i] == '#') any = 1;
    if (any) {
      int any2 = 0;
      rep(j, W) if (top[D - i - 1][j] == '#') any2 = 1;
      if (!any2) {
        puts("invalid");
        return 0;
      }
    }
  }
  // check height
  rep(i, H) {
    int any = 0;
    rep(j, W) if (front[i][j] == '#') any = 1;
    if (any) {
      int any2 = 0;
      rep(j, D) if (right[i][j] == '#') any2 = 1;
      if (!any2) {
        puts("invalid");
        return 0;
      }
    }
  }
  // check iwdth
  rep(i, W) {
    int any = 0;
    rep(j, H) if (front[j][i] == '#') any = 1;
    if (any) {
      int any2 = 0;
      rep(j, D) if (top[j][i] == '#') any2 = 1;
      if (!any2) {
        puts("invalid");
        return 0;
      }
    }
  }
  int ans = 0;
  rep(i, H) {
    rep(j, W) {
      rep(k, D) {
        if (front[i][j] == '#' and right[i][D - k - 1] == '#' and
            top[k][j] == '#') {
          ans++;
        }
      }
    }
  }
  int mx = 0;
  int cnt = 0;
  rep(i, H) {
    rep(j, W) {
      if (front[i][j] == '#')
        cnt++;
    }
  }
  chmax(mx, cnt);
  cnt = 0;
  rep(i, H) rep(k, D) if (right[i][k] == '#') cnt++;
  chmax(mx, cnt);
  cnt = 0;
  rep(k, D) rep(j, W) if (top[k][j] == '#') cnt++;
  chmax(mx, cnt);
  if (ans < mx) {
    puts("invalid");
  } else {
    cout << ans << nl;
  }
  return 0;
}
