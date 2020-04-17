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
  auto isEvenStr = [](string t) {
    int mid=t.length()/2;
    for (int i=0; i<mid; i++) {
      if (t[i]!=t[i+mid]) return false;
    }
    return true;
  };
  int j = 1;
  while(1) {
    string t = s.substr(0, s.length()-2*j);
    if (isEvenStr(t)) {
      cout << t.length() << endl; return 0;
    }
    j++;
  }
  return 0;
}