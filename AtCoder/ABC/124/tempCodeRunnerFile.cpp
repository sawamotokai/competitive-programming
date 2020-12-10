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
  int N, K; cin >> N>>K;
  string S; cin >> S;
  int cnt=1;
  char prev = S[0];
  vi nums;
  vii zeros;
  for(int i=1;i<N;i++) {
    if (S[i] == prev) cnt++;
    else {
      nums.push_back(i-cnt);
      if (prev == '0') zeros.emplace_back(i-cnt, nums.size());
      cnt = 0;
      prev = S[i];
    }
  }
  int ans = 0;
  rep(i,zeros.size()) {
    int l = zeros[i].first;
    if (l != 0) l = nums[zeros[i].second - 2];
    int hoge = min(i+K,(int) zeros.size());
    int r = zeros[hoge].first;
    if (zeros[hoge].second + 2 < nums.size()) r = nums[zeros[hoge].second + 2];
    else if (zeros[hoge].second + 1 < nums.size()) r = N-1;
    int num = SA[r] - SA[l];
    chmax(ans, num);
  }
  cout << ans << endl;
  return 0;
}