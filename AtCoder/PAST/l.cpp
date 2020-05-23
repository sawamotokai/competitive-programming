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
  int n; cin >> n;
  vvi items(n, vi());
  rep(i,n) {
    int k; cin >>k;
    rep(j, k) {
      int t; cin >>t ;
      items[i].push_back(t);
    }
  }
  int m; cin >> m;
  vvi bestItem(n, vi());
  rep(i,n) {
    int temp=items[i][0];
    rep(j, items[i].size()) {
      temp=max(temp, items[i][j]);
      bestItem[i][j] = temp;
    }
  }
  vi counter()
  rep(i, m) {
    int a; cin >> a;

  }
  return 0;
}