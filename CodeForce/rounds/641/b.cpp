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

void solve() {
  int n; cin >> n;
  vi s(n);
  rep(i,n) cin >> s[i];
  vi dp(n, INF);
  rep(i,n) {
    auto it = lower_bound(dp.begin(), dp.end(), s[i]);
    if (*it != INF) {
      
    }
  }
}

int main() {
  int t; cin >> t;
  rep(i,t) solve();
  return 0;
}