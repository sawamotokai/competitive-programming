#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ok() puts(ok?"Yes":"No");
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef set<int> si;
typedef map<string, int> msi;
typedef greater<int> gt;
typedef priority_queue<int, vector<int>, gt> minq;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
//clang++ -std=c++11 -stdlib=libc++ 

// abc159e
int main() {
  int h,w,k;
  cin >> h >> w >> k;
  vector<string> choco(h);
  rep(i,h) cin >> choco[i];

  ll ans1 = LINF;
  rep(i, 1<<(h-1)) {
    vi id(h);
    int g=0;
    rep(j, h) {
      id[j] = g;
      if (i>>j&1) g++;
    }
    g++;
    vvi c(g, vi(w));
    rep(j, w) {
      rep(l, h) {
        c[id[l]][j] += choco[l][j]-'0';
      } 
    }
    
    ll ans = g-1;
    vi now(g);
    auto add = [&](int j)->bool {
      rep(l, g) {
        now[l] += c[l][j];
        if (now[l] > k) return false;
      }
      return true;
    };
    rep(j,w) {
      if (!add(j)) {
        ans++;
        now = vi(g, 0);
        if (!add(j)) {
          ans = INF;
          break;
        }
      }
    }
    ans1 = min(ans1, ans);
  }
  cout << ans1 << endl;
  return 0;
}