#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ok() puts(ok ? "Yes" : "No");
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
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

int main() {
  int N, K;
  cin >> N >> K;
  string S;
  cin >> S;
  vi st, re;
  char prev = S[0];
  int cnt = 0;
  rep(i, N) {
    if (prev == S[i])
      cnt++;
    else {
      if (prev == '1')
        re.push_back(cnt);
      else
        st.push_back(cnt);
      prev = S[i];
      cnt = 1;
    }
  }
  if (prev == '1')
    re.push_back(cnt);
  else
    st.push_back(cnt);
  int t = min(K, (int)st.size());
  int ans = 0;
  if (S[0] == '1') {
    int now = 0;
    rep(i, min(t + 1, (int)re.size())) now += re[i];
    rep(i, t) now += st[i];
    chmax(ans, now);
    int left = 0;
    for (int i = t; i < st.size(); i++) {
      now -= st[left] + re[left];
      left++;
      now += st[i];
      if (i + 1 < re.size())
        now += re[i + 1];
      chmax(ans, now);
    }
  } else {
    int now = 0;
    rep(i, t) now += st[i] + re[i];
    chmax(ans, now);
    int left = 0;
    for (int i = t; i < st.size(); i++) {
      now -= st[left];
      if (left - 1)
        now -= re[left];
      left++;
      now += st[i];
      if (i < re.size())
        now += re[i];
      chmax(ans, now);
    }
  }
  cout << ans << endl;
  // for (int n : re)
  //   cout << n << " ";
  // cout << '\n';
  // for (int n : st)
  //   cout << n << " ";
  // cout << '\n';
  return 0;
}
