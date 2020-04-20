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
  int N,T; cin>>N>>T;
  vector<pll> work(N);
  ll time=0;
  rep(i, N) {
    ll a,b;
    cin >> a>>b;
    work[i] = pll(a,b);
    time += a;
  }
  int ans =0;
  sort(work.begin(), work.end(), [](pll a, pll b) { return a.first - a.second > b.first - b.second;} );
  while(time > T && ans < N) {
    time -= (work[ans].first - work[ans].second);
    ans++;
    if (ans == N && time > T) {
      ans = -1; break;
    }
  }
  cout << ans << endl;
  return 0;
}