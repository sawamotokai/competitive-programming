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
string getName() {
  string s;
  cin >> s;
  s = s.substr(1, s.size() - 1);
  while (1) {
    string t;
    cin >> t;
    s += " " + t;
    if (t.back() == '"') {
      s = s.substr(0, s.size() - 1);
      return s;
    }
  }
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  priority_queue<pair<string, int>, vector<pair<string, int>>,
                 greater<pair<string, int>>>
      pq;
  pq.emplace("Jane Eyre", k);
  rep(i, n) {
    string s = getName();
    int page;
    cin >> page;
    pq.emplace(s, page);
  }
  vector<pair<ll, pair<string, int>>> pres(m);

  rep(i, m) {
    ll t;
    string s;
    int page;
    cin >> t;
    s = getName();
    cin >> page;
    pres[i] = make_pair(t, make_pair(s, page));
  }
  sort(all(pres));
  int ptr = 0;
  ll time = 0;
  while (pq.size()) {
    while (ptr < m && time >= pres[ptr].fi) {
      pq.push(pres[ptr].se);
      ptr++;
    }
    time += pq.top().se;
    if (pq.top().fi == "Jane Eyre") {
      cout << time << endl;
      return 0;
    }
    pq.pop();
  }
  return 0;
}
