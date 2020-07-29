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

int dp[100005][3];
int main() {
  int n; cin >> n;
  vi hand(n);
  vi cnt_mp(n);
  vii a(n);
  rep(i,n) {
    a[i].second = i;
    cin >>  a[i].first;
    int h; cin >> h;
    h--;
    hand[i] = h;
    dp[a[i].first][h]++;
  }
  sort(a.rbegin(), a.rend());
  rep(i,n) cnt_mp[a[i].first]++;
  int prev = 0;
  int gt = 0;

  vvi ans(n, vi(3));
  rep(i,n) {
    int win = 0, lose = 0, tie = 0;
    int id = a[i].second;
    int eq = 0;
    if (cnt_mp[a[i].first] != 1) {
      int h = hand[a[i].second];
      win += (h==0)?dp[a[i].first][1]:(h==1)?dp[a[i].first][2]:dp[a[i].first][0];
      lose += (h==0)?dp[a[i].first][2]:(h==1)?dp[a[i].first][0]:dp[a[i].first][1];     
      tie += (h==0)?dp[a[i].first][0]:(h==1)?dp[a[i].first][1]:dp[a[i].first][2];     
      tie--;
      eq++;
    } else {
      gt += eq;
      cout << eq << endl;
      eq=0;
      // gt += cnt_mp[prev];
    }
    int lt = n - gt - cnt_mp[a[i].first];
    lose += gt;
    win += lt;
    prev = a[i].first;
    ans[id][0] = win;
    ans[id][1] = lose;
    ans[id][2] = tie;
  }
  rep(i,n) printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);
  return 0;
}