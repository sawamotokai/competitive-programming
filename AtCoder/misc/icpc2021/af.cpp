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
using gt = greater<ii>;
using minq = priority_queue<ii, vector<ii>, gt>;
using P = pair<ll, ll>;
using vP = vector<P>;
template <class T> void takeUnique(vector<T> &v) {
  auto last = std::unique(v.begin(), v.end());
  v.erase(last, v.end());
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
int mod = 998244353;
ll dp[100005][10][2][2];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string lo, hi;
  cin >> lo >> hi;
  lo = string(hi.size() - lo.size(), '0') + lo;
  int n = hi.size();
  // dp[i][j][bg][sm] := seen i digits from the left; current digit is j; same
  // as upper; same as lower;
  rep(i, 10) {
    int upper = hi[0] - '0';
    int lower = lo[0] - '0';
    if (i == upper and i == lower)
      dp[1][i][0][0] = 1;
    else if (i == upper)
      dp[1][i][1][0] = 1;
    else if (i == lower)
      dp[1][i][0][1] = 1;
    else if (i < upper and i > lower)
      dp[1][i][1][1] = 1;
  }
  rep2(i, 1, n - 1) {
    rep(j, 10) {
      rep(bg, 2) {
        rep(sm, 2) {
          rep(k, 10) {
            // k := prev digit
            if (j == k)
              continue;
            int hid = hi[i] - '0';
            int lod = lo[i] - '0';
            if (!bg and !sm) {
              if (j == hid and j == lod)
                (dp[i + 1][j][bg][sm] += dp[i][k][bg][sm]) %= mod;
              else if (j == hid) {
                (dp[i + 1][j][bg][1] += dp[i][k][bg][sm]) %= mod;
              } else if (j == lod) {
                (dp[i + 1][j][1][sm] += dp[i][k][bg][sm]) %= mod;
              } else {
                if (j < hid and j > lod) {
                  (dp[i + 1][j][1][1] += dp[i][k][bg][sm]) %= mod;
                }
              }
            } else if (bg and !sm) {
              if (j < hid)
                (dp[i + 1][j][bg][1] += dp[i][k][bg][sm]) %= mod;
              else if (j == hid)
                (dp[i + 1][j][bg][sm] += dp[i][k][bg][sm]) %= mod;
            } else if (sm and !bg) {
              if (j > lod) {
                (dp[i + 1][j][1][sm] += dp[i][k][bg][sm]) %= mod;
              } else if (j == lod) {
                (dp[i + 1][j][bg][sm] += dp[i][k][bg][sm]) %= mod;
              }
            } else {
              (dp[i + 1][j][bg][sm] += dp[i][k][bg][sm]) %= mod;
            }
          }
        }
      }
    }
  }
  ll ans = 0;
  rep(i, 10) {
    rep(j, 2) { rep(k, 2)(ans += dp[n][i][j][k]) %= mod; }
  }
  cout << ans << endl;
  return 0;
}
