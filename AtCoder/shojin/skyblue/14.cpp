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

// mitsubishi2019 f
int main() {
  ll t1, t2, a1, a2, b1, b2; cin >> t1 >> t2 >> a1 >> a2 >> b1 >>  b2;
  ll dist1 = (t1*(a1-b1));
  ll dist2 = (t1*a1+t2*a2 - t1*b1 - t2*b2);
  if (dist2 == 0) {
    cout << "infinity" << endl; return 0;
  }
  if ((dist1 > 0 && dist2 > 0) || (dist1 <0 && dist2 < 0)) {
    cout << 0 << endl; return 0;
  }

  ll ans = (abs(dist1)-1)/abs(dist2) + 1;
  // cout << dist1 << " " << dist2 << endl;
  // cout << dist1 % dist2 << endl;
  ans *= 2;
  ans--;
  if (abs(dist1) % abs(dist2) == 0) ans++;
  cout << ans << endl;
  return 0;
}