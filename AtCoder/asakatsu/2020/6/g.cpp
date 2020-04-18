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
  int N; cin >>N;
  auto isTokyoTech = [](string s) {
    bool ok = false;
    rep(i,s.length()) {
      if (s[i] == 'o') {
        if (s.length()-1 >= i+3 && s.substr(i, 4) == "okyo") {
          for (int j=i+3; j<s.length(); j++) {
            if (s[j] == 'e' && s.length() - 1 >= j+2 && s.substr(j, 3) == "ech") {
              ok = true;
              break;
            }
          }
        }
      }
    }
    ok(); return;
  };
  rep(_,N) {
    string s;
    cin>>s;
    isTokyoTech(s);
  }
  return 0;
} 