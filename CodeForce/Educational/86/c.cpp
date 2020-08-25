#include <bits/stdc++.h>
#include <cassert>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ok() puts(ok?"Yes":"No");
template<class T> bool chmax(T &a, const T &b) { if(a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if(a > b) { a = b; return true; } return false; }
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

void solve() {
  string s; int x; cin >> s >> x;
  int n = s.length();
  vector<double> ans(n,0.5);
  auto f = [&](int i) {
    if (i - x >= 0 && s[i-x] == '1') return true;
    if (i + x < n && s[i-x] == '1') return true;
    return false;
  };
  rep(i,n) {
    if (i-x < 0) {
      double nx = s[i]-'0';
      if (ans[i+x] == 0.5) ans[i+x] = nx;
      else if (ans[i+x] == nx) ans[i+x] = nx;
      else {
        cout << -1 << endl;
        return;
      }
    }

  }
}

int t;
int main() {
  cin>>t;
  rep(i,t)solve();
  return 0;
}