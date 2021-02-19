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
string s;
int main() {
  cin >> n >> s;
  rep(self, 2) {
    rep(side, 2) {
      vector<char> ans(n, '.');
      if (self) {
        ans[0] = 'S';
        if (s[0] == 'o') {
          if (side)
            ans[n - 1] = 'W', ans[1] = 'W';
          else
            ans[n - 1] = 'S', ans[1] = 'S';
        } else {
          if (side)
            ans[n - 1] = 'W', ans[1] = 'S';
          else
            ans[n - 1] = 'S', ans[1] = 'W';
        }
      } else {
        ans[0] = 'W';
        if (s[0] == 'x') {
          if (side)
            ans[n - 1] = 'W', ans[1] = 'W';
          else
            ans[n - 1] = 'S', ans[1] = 'S';
        } else {
          if (side)
            ans[n - 1] = 'W', ans[1] = 'S';
          else
            ans[n - 1] = 'S', ans[1] = 'W';
        }
      }
      rep2(i, 1, n - 2) {
        // rep(i, n) cout << ans[i];
        // cout << endl;
        char nx;
        if (s[i] == 'x') {
          if (ans[i] == 'S') {
            if (ans[i - 1] == 'S')
              nx = 'W';
            else
              nx = 'S';
          } else {
            nx = ans[i - 1];
          }
        } else {
          if (ans[i] == 'S') {
            nx = ans[i - 1];
          } else {
            nx = ans[i - 1] == 'S' ? 'W' : 'S';
          }
        }
        if (i == n - 2 && ans[i + 1] == nx) {
          if (ans[n - 1] == 'S') {
            if (s[n - 1] == 'x') {
              if (ans[n - 2] == ans[0])
                break;
            } else {
              if (ans[n - 2] != ans[0])
                break;
            }
          } else {
            if (s[n - 1] == 'x') {
              if (ans[n - 2] != ans[0])
                break;
            } else {
              if (ans[n - 2] == ans[0])
                break;
            }
          }
          rep(j, n) cout << ans[j];
          cout << endl;
          return 0;
        }
        ans[i + 1] = nx;
      }
    }
  }
  cout << -1 << endl;
  return 0;
}
