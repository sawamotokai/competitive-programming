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
  vii a(n);
  map<int, set<int>> mp;
  rep(i,n) {
    int h; cin >> h;
    if (h>=n) continue;
    mp[h].insert(i);
  }
  ll ans = 0;
  for(auto p: mp) {
    int height = p.first;
    set<int> set1 = p.second;
    for (auto p2: mp) {
      int height2 = p2.first;
      set<int> set2 = p2.second;
      int tot = height + height2;
      if (set2)
    }
  }
 return 0;
}