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
  int n;
  cin >> n;
  vi a(n);
  vi b(n);
  rep(i, n) {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
  }
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                 greater<pair<int, pair<int, int>>>>
      pq;
  vi cnt(n + 1);
  rep(i, n) {
    cnt[a[i]]++;
    cnt[b[i]]++;
  }
  rep(i, n) {
    pq.push({cnt[a[i]], {a[i], i}});
    pq.push({cnt[b[i]], {b[i], i}});
  }
  set<int> st;
  while (pq.size()) {
    auto [c, p] = pq.top();
    pq.pop();
    if (st.count(p.fi))
      continue;
    st.insert(p.fi);
    cnt[p.fi]--;
    if (a[p.se] != p.fi) {
      cnt[a[p.se]]--;
      if (cnt[a[p.se]] > 0)
        pq.push({cnt[a[p.se]], {a[p.se], p.se}});
    } else if (b[p.se] != p.fi) {
      cnt[b[p.se]]--;
      if (cnt[b[p.se]] > 0)
        pq.push({cnt[b[p.se]], {b[p.se], p.se}});
    }
  }
  cout << st.size() << nl;
  return 0;
}
