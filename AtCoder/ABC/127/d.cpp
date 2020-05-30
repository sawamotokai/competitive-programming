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

int main() {
  int n,m; cin >> n>>m;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  vii ch(m);
  rep(i,m) {
    int b, c; cin >> b >> c;
    ch[i] = make_pair(b,c);
  }
  sort(ch.begin(), ch.end(), [](ii a, ii b) {return a.second > b.second;} );
  int cnt = 0;
  [&] {
    rep(i, m)
    {
      rep(j, ch[i].first)
      {
        cnt++;
        a.push_back(ch[i].second);
        if (cnt > n)
          return;
      }
    }
  }();
  sort(a.begin(), a.end(), [](ll a, ll b) {return a>b;});
  ll ans = 0;
  rep(i,n) ans += a[i];
  cout << ans << endl; 
  return 0;
}