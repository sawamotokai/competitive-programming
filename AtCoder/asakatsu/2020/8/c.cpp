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

  string s; 


bool match(string s, string t) {
  if (s.length() != t.length()) return false;
  rep(i,s.length()) {
    if (t[i]=='*')continue;
    if (t[i]!=s[i]) return false;
  }
  return true;
}

void solve(vector<string> good , vector<string> ngWords) {
  rep(i,good.size()) {
    rep(j, ngWords.size()) {
      if (match(good[i], ngWords[j])) {
        good[i] = string(ngWords[j].length(), '*'); 
      }

    }
  }
  cout << good[0];
  rep(i,good.size()-1) cout << ' ' << good[i+1];
  cout << endl;
}
int main() {
  getline(cin, s);
  int n; cin >>n;
  s+= ' ';
  vector<string> ngWords(n);
  vector<string> good;
  int start = 0;
  rep(i, s.length()) {
    if (s[i] == ' ') {
      good.push_back(s.substr(start, i-start));
      start = i+1; i++;
    }
  }
  rep (_,n) {
    cin >> ngWords[_];
  }
  solve(good,ngWords);
  return 0;
}