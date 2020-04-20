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
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
//clang++ -std=c++11 -stdlib=libc++ 

int main() {
  string s; cin >> s;
  string t="";
  rep(i,s.length()) {
    if (s[i]=='B') {
      if (i+1 < s.length() && s[i+1] == 'C') {
        t+='D'; i++; continue;
      } else {
        t+='B';
      }
    }
    t+=s[i];
  }
 ll ans=0;
  int d = 0;
  for (int i=t.length()-1; i>=0; i--) {
    if (t[i]=='D') d++;
    if (t[i]=='A') ans+=d;
    if (t[i]=='B' || t[i] == 'C') d = 0;
  }
   cout << ans << endl;

  return 0;
}