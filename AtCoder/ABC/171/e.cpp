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
  int n; cin >> n; vector<ll> a(n); rep(i,n) cin >> a[i];
  vector<string> b(n, "");
  rep(i, 32) {
    int cnt = 0;
    rep(j, n) {
      if (a[j] & 1) cnt++; 
    }
    rep(j,n) {
      if (cnt & 1)
      {
        char c = !(a[j] & 1) + 48;
        b[j] += c;
      }
      else
      {
        char c = (a[j] & 1) + 48;
        b[j] += c;
      }
      a[j] >>= 1;
    }
  }
  vector<ll> ans(n);
  rep(i,n) {
    std::string s = b[i];
    reverse(s.begin(), s.end());
    unsigned long long value = std::bitset<64>(s).to_ullong();
    std::cout << value << std::endl;
  }
  return 0;
}