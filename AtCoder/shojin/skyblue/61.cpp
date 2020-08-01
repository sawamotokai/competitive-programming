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
  int N; cin >> N;
  vi R(N), H(N);
  rep(i,N) {
    cin >> R[i] >> H[i];
    H[i]--;
  }
  vi SR(100005);
  rep(i,N) SR[R[i]]++;
  rep(i,100005) SR[i+1] += SR[i];
  vvi hand(100005, vi(3, 0));
  rep(i,N) hand[R[i]][H[i]]++;
  rep(i,N) {
    int r = R[i], h = H[i];
    int win = SR[r - 1];
    int lose = SR[100004] - SR[r];
    int tie = 0;
    if (h == 0) {
      win += hand[r][1]; 
      lose += hand[r][2];
      tie += hand[r][0]-1;
    } 
    if (h == 1) {
      win += hand[r][2]; 
      lose += hand[r][0];
      tie += hand[r][1]-1;
    }
    if (h == 2) {
      win += hand[r][0]; 
      lose += hand[r][1];
      tie += hand[r][2]-1;
    }
    printf("%d %d %d\n", win, lose, tie);
  }
  return 0;
}