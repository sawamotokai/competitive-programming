#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ok() puts(ok?"Yes":"No");
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using gt = greater<int>;
using minq = priority_queue<int, vector<int>, gt>;
using P = pair<ll,ll>;
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
//clang++ -std=c++11 -stdlib=libc++ 


int table[9];
int bamboo[9];
int n, a, b, c;
int ans =INF;

void dfs(int len=0) {
  if (len == n) {
    int sumA=0, sumB=0, sumC=0;
    int now = 0;
    for (int i=0; i<n;i++) {
      int num = table[i];
      if (num==3) {
        if (sumC) now+=10;
        sumC += bamboo[i];
      }
      if (num==2) {
        if (sumB) now+=10;
        sumB += bamboo[i];
      }
      if (num==1) {
        if (sumA) now += 10;
        sumA += bamboo[i];
      }
    }
    if (sumA==0 || sumB==0 || sumC==0) return;
    now += abs(sumC-c);
    now += abs(sumB-b);
    now += abs(sumA-a);
    chmin(ans, now);
    return ;
  }
  for (int i=1; i<5;i++) {
    table[len] = i;
    dfs(len+1);
  }
}

int main() {
  cin >> n >> a >> b >> c;
  rep(i,n) cin >> bamboo[i];
  dfs();
  cout << ans << endl;
  return 0;
}