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
  ll a,b; cin >>a >> b;
  int lena = floor(sqrt(a));
  int lenb = floor(sqrt(b));
  vi aa;
  vi bb;
  for (ll i=1; i*i <= a; i++) {
    if (a%i == 0)  {
      aa.push_back(i);
      aa.push_back(a/i);
    }
  }
  for (ll i=1; i*i <= b; i++) {
    if (b%i == 0)  {
      bb.push_back(i);
      bb.push_back(b/i);
    }
  }
  set<int> ab;
   rep(i,aa.size()) {
    if (b%aa[i] == 0) {
      ab.insert(aa[i]);
    }
  }
  rep(i,bb.size()) {
    if (a%bb[i] == 0) ab.insert(bb[i]);
  }
  vi arr;
  for (auto it=ab.begin() ; it!=ab.end(); it++) arr.push_back(*it);
  sort(arr.begin(), arr.end(), [] (int a,int b) {return a>b;});
  int ans = 0;
  rep(i, arr.size()) {
    bool ok =true;
    for (int j=i+1; j<arr.size()-1; j++) {
      if (arr[i] == 1) break;
      if (arr[i] % arr[j] == 0) {
        ok = false;
        break;
      }
    }
    if (ok) ans++;
  }
 cout << ans << endl;
  return 0;
}