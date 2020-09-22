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
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
// clang++ -std=c++11 -stdlib=libc++
//

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<ii>> st(M + 1);
  rep(i, M) {
    int p;
    int y;
    cin >> p >> y;
    st[p].eb(y, i + 1);
  }
  vector<string> ans(M + 1);
  for (int i = 0; i < st.size(); i++) {
    vector<ii> s = st[i];
    if (s.size() == 0)
      continue;
    sort(all(s));
    string p = to_string(i);
    int b = 6 - p.size();
    string s1 = string(b, '0') + p;
    for (int x = 1; x <= s.size(); x++) {
      string c = to_string(x);
      b = 6 - c.size();
      string s2 = string(b, '0') + c;
      int id = s[x - 1].se;
      ans[id] = s1 + s2;
    }
  }
  rep2(i, 1, M) cout << ans[i] << endl;
  return 0;
}
