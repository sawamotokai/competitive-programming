#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ok() puts(ok?"Yes":"No");
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using gt = greater<int>;
using minq = priority_queue<int, vector<int>, gt>;
using P = pair<ll,ll>;
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
//clang++ -std=c++11 -stdlib=libc++ 

// abc119d
int main() {
  int A,B,Q; cin >> A >> B >> Q;
  vector<ll> s(A+2), t(B+2);
  rep(i,A) cin >> s[i+1];
  rep(i,B) cin >> t[i+1];
  s[0] = t[0] = -LINF;
  s[A+1] = t[B+1] = LINF;

  rep(_,Q) {
    ll ans = LINF;
    ll x; cin >> x;
    rep(i,2) {
      if (i==1) swap(s,t);
      rep(j,2) {
        int idx = lower_bound(s.begin(), s.end(), x) - s.begin() -1 + j;
        ll sx = s[idx];
        rep(k,2) {
          int tIdx = lower_bound(t.begin(), t.end(), sx) - t.begin() -1 + k; 
          ll tx = t[tIdx];
          ll num = abs(sx - x);
          num += abs(sx - tx);
          chmin(ans, num);
        }
      }
    }
    swap(s,t);
    printf("%lld\n", ans);
  }
  return 0;
}