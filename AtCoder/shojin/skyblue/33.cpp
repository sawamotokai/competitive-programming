#include <bits/stdc++.h>
#include <cassert>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ok() puts(ok?"Yes":"No");
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using ii = pair<int, int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using gt = greater<int>;
using minq = priority_queue<int, vector<int>, gt>;
using P = pair<ll,ll>;
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
//clang++ -std=c++11 -stdlib=libc++ 





int main() {
  int ans = INF;
  int d, g;
  cin >> d >> g;
  vi p(d), c(d);
  rep(i,d) cin >> p[i] >> c[i];
  rep(i, 1<<d) {
    vector<bool> used(d, false);
    int score = 0;
    int num = 0;
    int maxUsable = -1;
    rep(j, d) {
      if ((1<<j) & i) {
        used[j] = true;
        score += p[j] * 100 * (j+1);
        score += c[j];
        num += p[j];
      } else {
        chmax(maxUsable, j);
      }
    }    
    if (score < g) {
      int want = g-score;
      int z = ceil(want/(double)((maxUsable+1)*100));
      if (z >= p[maxUsable]) {
        continue;
      } else {
        score += (maxUsable+1) * 100 * z;
      }
      num += z;
    }
    chmin(ans, num);
  }
  cout << ans << endl;  
  return 0;
}