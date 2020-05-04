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
  int n; cin >> n;
  set<string> used;
  int result = -1;
  vector<string> words(n);
  rep(i,n) cin >> words[i];
  used.insert(words[0]);
  char last = words[0].back();
  for (int i=1; i<n; i++) {
    string w = words[i];
    if (w[0]!=last) {
      result = i&1; 
      break;
    }
    if (used.find(w) != used.end()) {
      result = i & 1;
      break;
    } 
    used.insert(w);
    last = w.back();
  }
  if (result == -1) puts("DRAW");
  if (result == 0) puts("LOSE");
  if (result == 1) puts("WIN");
  return 0;
}