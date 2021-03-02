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
using gt = greater<ii>;
using minq = priority_queue<ii, vector<ii>, gt>;
using P = pair<ll, ll>;
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

template <typename T> struct BIT {
  int n;
  vector<T> d;
  BIT(int n = 0) : n(n), d(n + 1) {}
  void add(int i, T x = 1) {
    for (i++; i <= n; i += i & -i) {
      d[i] += x;
    }
  }
  T sum(int i) {
    T x = 0;
    for (i++; i; i -= i & -i) {
      x += d[i];
    }
    return x;
  }
  T sum(int l, int r) { return sum(r - 1) - sum(l - 1); }
};

int MAX_S = 1000001;

int main() {
  int n, q;
  cin >> n;
  vi S(n);
  rep(i, n) cin >> S[i];
  cin >> q;
  vii K(q);
  rep(i, q) {
    cin >> K[i].fi;
    K[i].se = i;
  }
  BIT<int> bit(MAX_S);
  sort(all(S));
  sort(K.rbegin(), K.rend());
  int cnt = 0;
  for (int s : S) {
    if (s == 0)
      continue;
    bit.add(s, 1);
    cnt++;
  }
  int border = 0;
  vi ans(q);
  // cout << K.size() << endl;
  for (auto [k, idx] : K) {
    while (1) {
      if (border > MAX_S)
        break;
      int ppl = cnt - bit.sum(border - 1);
      // cout << "border: " << border << " ppl: " << ppl << " " << k << endl;
      if (ppl <= k) {
        // cout << bit.sum(6) << endl;
        ans[idx] = border;
        break;
      } else {
        border++;
      }
    }
  }
  rep(i, q) { cout << ans[i] << endl; }
  return 0;
}
