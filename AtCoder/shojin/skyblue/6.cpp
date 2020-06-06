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

// abc157e
int main() {
  int n,q; string s; 
  cin >> n;
  cin >> s;
  cin >> q; 
  vector<set<int>> sets(26);
  rep(i, n) {
    sets[s[i]- 'a'].insert(i);
  }
  rep(_,q) {
    int a; cin >> a;
    if (a==1) {
      int i; char c; cin >> i >> c; --i;
      sets[s[i] - 'a'].erase(i);
      s[i] = c;
      sets[s[i]-'a'].insert(i);
    }
    else {
      int l, r; cin >> l >> r;
      --l; --r;
      int num = 0;
      rep(i,26) {
        auto it = sets[i].lower_bound(l);
        if (it != sets[i].end() && *it <= r) ++num;
      }
      cout << num << endl;
    }
  }
  return 0;
}