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
  string s; cin >> s;
  string ans = "NA";
  string front = s.substr(0,2);
  string back = s.substr(2,2);
  auto isMonth = [](string s) {
    if (s[0] == '0' || s[0] == '1') {
      if (s[1] == '0' && s[0] == '0') return false;
      if (s[1] - '0' > 2 && s[0] == '1') return false;
      else return true;
    } 
    return false;
  };
  if (isMonth(back)) {
    if (isMonth(front)) ans = "AMBIGUOUS";
    else ans = "YYMM";
  } else {
    if (isMonth(front)) ans = "MMYY";
  }
  cout << ans << endl;
  return 0;
}