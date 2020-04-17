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
  string s; cin >>s;
  stack<char> stk;
  if (s=="{}") {
    cout << "dict" << endl; return 0;
  }
  for (int i=0; i<s.length(); i++) {
    if (s[i] == '{') {
      stk.push('{');
    } else if (s[i] == '}') {
      stk.pop();
    }else if (stk.size() == 1 && s[i] == ':') {
      cout << "dict" << endl; return 0;
    }
    if (stk.size()==0) {
      cout << "set" << endl; return 0;
    }
  }
  return 0;
}