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

bool isAlphabet(char c) {
  if (c-'a' >= 0 && c-'a' < 26) return true;
  return false;
}

int main() {
  string s;
  getline(cin, s);
  s+= ' ';
  set<string> ans;
  rep(i,s.length()) {
    if (s[i] == '@') {
      if (i+1<s.length() && isAlphabet(s[i+1])) {
        for (int j=i+1; j<s.length(); j++) {
          if(!isAlphabet(s[j])) {
            ans.insert(s.substr(i+1, j-i-1));
            break;
          }
        }
      }
    }
  }
  for (auto t :ans) cout << t << endl;
  return 0;
}