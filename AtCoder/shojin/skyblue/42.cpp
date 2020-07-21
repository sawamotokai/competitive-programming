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

int main() {
  int N,C; cin >> N >> C;
  vii time(N);
  map<ii, int> c;
  rep(i,N) {
    cin >> time[i].first >> time[i].second;
    time[i].first--;
    cin >> c[ii(time[i].first, time[i].second)];
  }
  sort(time.begin(), time.end());
  vi line(100005);
  rep(i, N) {
    int st = time[i].first;
    int ed = time[i].second;
    line[st]++; line[ed]--;
  }
  int ans = 0;
  rep(i, 100003) {
    line[i+1] += line[i];
  }
  rep(i, 100003) chmax(ans, line[i]);
  cout << ans << endl;
  return 0;

}