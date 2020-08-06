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


void solve() {
  int n; cin >> n;
  vi ans;
  int k = 0;
  // int zero = 0;
  // int one = 0;
  vi zero,one;
  char prev = 'x';
  int cnt = 1;
  rep(i,n) {
    char c; cin >> c;
    if (c == '0') {
      int num;
      if (one.size()) {
        num = one.back();
        one.pop_back();
      } else {
        num = zero.size() + 1;
      }
      zero.push_back(num);
      ans.push_back(num);
      chmax(k,num);
    } else {
      int num;
      if (zero.size()) {
        num = zero.back();
        zero.pop_back();
      } else {
        num = one.size() + 1;
      }
      one.push_back(num);
      ans.push_back(num);
      chmax(k,num);
    }
  }
  cout << k << endl;
  rep(i,ans.size()) printf("%d%c",ans[i],i==ans.size()-1?'\n':' ');
}

int main() {
  int t; cin >> t;
  rep(i,t) solve();
  return 0;
}