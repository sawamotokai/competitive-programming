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
inline void priv(vll a) {
  rep(i, (int)a.size() - 1) cout << a[i] << " ";
  cout << a.back() << nl;
}
inline void priv(vi a) {
  rep(i, (int)a.size() - 1) cout << a[i] << " ";
  cout << a.back() << nl;
}
const ll LINF = 8e18L + 1;
const int INF = 8e9 + 1;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int dxx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dyy[] = {1, 1, 0, -1, -1, -1, 0, 1};
// g++ -std=c++17 -stdlib=libc++
#define _GLIBCXX_DEBUG
// This slows down the execution; even the time complexity, since it checks if
// std funcs such as lower_bound meets prereqs

class RangeMexQuery {
private:
  int n, m;
  vector<array<int, 3>> ptr;
  vector<int> arr, st;
  int update(const int prv, const int id, const int val, const int l,
             const int r) {
    const int cur = (int)ptr.size();
    ptr.push_back({0, 0, id});
    if (r - l == 1)
      return cur;
    const int mid = (l + r) / 2;
    if (val < mid) {
      const int res = update(ptr[prv][0], id, val, l, mid);
      ptr[cur][0] = res, ptr[cur][1] = ptr[prv][1];
    } else {
      const int res = update(ptr[prv][1], id, val, mid, r);
      ptr[cur][0] = ptr[prv][0], ptr[cur][1] = res;
    }
    ptr[cur][2] = min(ptr[ptr[cur][0]][2], ptr[ptr[cur][1]][2]);
    return cur;
  }
  void preprocessing(const vector<int> &vec) {
    arr[0] = 0;
    for (int i = 0; i < n; ++i)
      arr[2 * i + 1] = vec[i], arr[2 * i + 2] = vec[i] + 1;
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    m = (int)arr.size(), st[0] = 0, ptr.push_back({0, 0, -1});
    for (int i = 0; i < n; ++i) {
      const int val =
          (int)(lower_bound(arr.begin(), arr.end(), vec[i]) - arr.begin());
      st[i + 1] = update(st[i], i, val, 0, m);
    }
  }
  int query(const int cur, const int cri, const int l, const int r) {
    if (cur == 0 || r - l == 1)
      return arr[l];
    const int mid = (l + r) / 2;
    if (ptr[ptr[cur][0]][2] < cri)
      return query(ptr[cur][0], cri, l, mid);
    else
      return query(ptr[cur][1], cri, mid, r);
  }

public:
  RangeMexQuery(const vector<int> &vec)
      : n((int)vec.size()), arr(2 * n + 1), st(n + 1) {
    preprocessing(vec);
  }
  int query(const int l, const int r) { return query(st[r], l, 0, m); }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout << fixed << setprecision(16);
  int n;
  vi c(n);
  vi a(n);
  rep(i, n) { cin >> c[i + 1] >> a[i + 1]; }
  vi grundy(n);
  RangeMexQuery seg();
  rep(i, n) { grundy[i] = seg.query(i - c[i], i); }
  return 0;
}
