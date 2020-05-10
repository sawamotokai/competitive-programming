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
  bitset<200005> a;
  rep(i,n) {
    bool b; cin >> b; 
    a[i+1] = b;
  }

  auto factorize = [](ll n) {
    vi ret;
    ret.push_back(1);
    ret.push_back(n);
    for (int i=2; i*i<=n; i++) {
      if (i*i==n) {
        ret.push_back(i);
        return ret;
      }
      if (n%i==0) {
        ret.push_back(i);
        ret.push_back(n/i);
      }
    }
    return ret;
  };
int count = 0;
vi ans;
for (int i=n; i>0; i--) {
  if (a[i]) {
    count ++;
    ans.push_back(i);
    vi factors= factorize(i);
    for (int num: factors) {
      a[num] = !a[num];
    }
  }
}
reverse(ans.begin(), ans.end());
cout << ans.size() << endl;
rep(i,ans.size()) cout << ans[i] << endl;
 return 0;
}