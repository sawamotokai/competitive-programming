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
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
//clang++ -std=c++11 -stdlib=libc++ 

ll square(ll n) {
if (n==0) return 1;
ll ret = square(n/2);
  ret *= ret;
if (n&1) ret *= 2;
return ret;
}

int main() {

ll c,d; cin >>c>>d;
ll upper = d, lower = c;
int n = ;
while (1) {
    ll sq = square(n);
    ll l = 140 * sq;
    if (c<=l && d>l) lower = l;
    ll u = 170 * sq;
    if (c<=u && d>u) upper = u;
    if (sq*140 >= d || sq*170>=d) break;
    n++;
  }
  ll ans = abs(upper - lower);
  printf("%lld\n",ans);
  return 0;
}