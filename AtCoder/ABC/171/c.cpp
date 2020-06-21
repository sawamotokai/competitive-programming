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
  ll n; cin >> n;
  int len = ceil(log(n) / log(26));
  string ans = "";
  while (n > 0) {
    int d = n%26LL;
    char add = 'a' + d-1;
    if (d == 0) add = 'z';
    ans += add;
    n /= 26LL;
    if (d==0) n--;
  }
  reverse(ans.begin(), ans.end());
  cout << ans;
  int l = ans.size();
  if (l < len) {
    rep(i, len-l-1) cout << "z";
  }
  cout << endl;
  return 0;
}