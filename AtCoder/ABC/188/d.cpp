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
  int N;
  ll C;
  cin >> N >> C;
  vll a(N), b(N), c(N);
  rep(i, N) cin >> a[i] >> b[i] >> c[i];
  // vll imos(N + 1);
  //// map<ll, ll> imos;
  // rep(i, N) {
  //  imos[a[i] - 1] += c[i];
  //  imos[b[i]] -= c[i];
  //}
  // ll sum = 0;
  // rep(i, N) { imos[i + 1] += imos[i]; }
  // rep2(i, 0, N - 1) sum += min(imos[i], C);
  ll ans = 0;
  vii hidari(N);
  rep(i, N) hidari[i] = {a[i], i};
  sort(all(hidari));
  priority_queue<P, vector<P>, greater<P>> pq;
  ll sum = 0;
  rep(i, N) {
    int idx = hidari[i].se;
    ll range = 1;
    if (!pq.empty()) {
      while (pq.size() && hidari[i].fi > pq.top().fi) {
        sum -= c[pq.top().se];
        pq.pop();
      }
    }
    if (pq.size()) {
      range = pq.top().fi - a[idx] + 1;
    } else {
      range = b[idx] - a[idx] + 1;
    }
    sum += c[idx];
    pq.emplace(b[idx], idx);
    ans += min(C, sum) * range;
    cout << sum << " " << range << endl;
  }
  cout << ans << endl;
  return 0;
}
