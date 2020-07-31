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

// arc46b
ll N,A,B;
const int taka = 0;
const int aoki = 1;

int main() {
  cin>>N;
  cin >> A >> B;
  int winner = 0;
  if (N<=A) {
    winner = taka;
  } else {
    if (A == B) {
      if (N % (A+1) == 0) {
        winner = aoki;
      } else {
        winner = taka;
      }
    } else {
      if (A>B) winner = taka;
      else winner = aoki;
    }
  }
  puts(winner?"Aoki":"Takahashi");
  return 0;
}