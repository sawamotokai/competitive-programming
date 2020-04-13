#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
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
const ll INF = 1e18L + 1;
//clang++ -std=c++11 -stdlib=libc++ 

int main() {
  int N,K; cin >>N>>K;
  int r,s,p; cin >>r>>s>>p;
  string T; cin >>T;
  ll score = 0;
  
  map<int, int> mp;
  mp['r'] = 1e9;
  mp['s'] = 1e9;
  mp['p'] = 1e9;
  for (int i=0; i<N; i++) {
    if (i - mp[T[i]] != K) {
      if (T[i] == 'r') score += p;
      if (T[i] == 'p') score += s;
      if (T[i] == 's') score += r;
      mp[T[i]] = i;
    }
  }
  cout << score << endl;
  return 0;
}