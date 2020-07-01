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

int main() {
  int n,m,k; cin >> n >> m >> k;
  vector<ll> a(n+1), b(m+1);
  rep(i, n) cin >> a[i+1];
  rep(i, n) a[i+1] += a[i];
  rep(i,m) cin >> b[i+1];
  rep(i,m) b[i+1] += b[i];
  int ans =0;
  int ptr = m;
  rep(i, n+1) {
    int num = i;
    int rest = k-a[i];
    while (ptr >=0 && rest < b[ptr]) ptr--;
    if (ptr < 0) break;
    num += ptr;
    chmax(ans, num);
  }
  cout << ans << endl;
  return 0;
}