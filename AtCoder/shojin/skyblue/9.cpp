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
typedef pair<ll,ll> P;
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
//clang++ -std=c++11 -stdlib=libc++ 

int main() {
  int N,D,A; cin >> N >> D>> A;
  vector<P> monsters(N);
  rep(i,N) {
    cin >> monsters[i].first >> monsters[i].second;
  }
  sort(monsters.begin(), monsters.end(), [](P a, P b){return a.first < b.first;});
  ll ans =0;
  ll tot = 0;
  queue<P> q;
  rep(i,N) {
    ll x = monsters[i].first; 
    ll h = monsters[i].second;
    while (q.size() && q.front().first < x) {
      tot -= q.front().second; q.pop();
    }
    h -= tot;
    if (h>0) {
      ll num = (h-1+A)/A ;
      ans += num;
      ll damage = num*A;
      tot += damage;
      q.emplace(x+2*D, damage);
    }
  }
  printf("%lld\n", ans);
  return 0;
}