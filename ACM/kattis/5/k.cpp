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
inline void priv(vll a) {
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

vector<ll> ans;
void f(ll lo, ll hi) {
  if (lo + 1 == hi) {
    ans.pb(lo);
    return;
  }
  ll mid = (lo + hi) / 2;
  cout << "q"
       << " " << lo << " " << mid - 1 << flush;
  ll left;
  cin >> left;
  cout << "q"
       << " " << mid << " " << hi - 1 << flush;
  ll right;
  cin >> right;
  if (left) {
    if (left == mid - lo) {
      rep2(i, left, mid - 1) ans.pb(i);
      return;
    }
    f(lo, mid);
  } else {
    if (right == hi - mid) {
      rep2(i, mid, right - 1) ans.pb(i);
      return;
    }
    f(mid, hi);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ll lo = 0;
  ll hi = (1 << 63);
  f(lo, hi);
  sort(all(ans));
  cout << "a"
       << " " << ans.size() << " ";
  priv(ans);
  return 0;
}
