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
  int X,Y,A,B,C; cin >>X>>Y>>A>>B>>C;
  vii apples(A+B+C);
  rep(i,A) {
    int a; cin >> a;
    apples.push_back(ii(a,0));   
  }rep(i,B) {
    int a; cin >> a;
    apples.push_back(ii(a,1));   
  }
  rep(i,C) {
    int a; cin >> a;
    apples.push_back(ii(a,2));   
  }
  
  sort(apples.begin(), apples.end(), [](ii x, ii y) {return x.first > y.first;});
  int a=0,b=0,c=0, total=0;
  ll ans = 0;
  rep(i, A+B+C) {
    ii apple = apples[i];
    int color = apple.second;
    if (color==0 && a<X && total < X+Y) {
      a++;
      total++;
      ans+=apple.first;
    } else if (color == 1 && b<Y && total < X+Y) {
      b++; total++;
      ans+=apple.first;
    } else if (color == 2 && total < X+Y) {
      total++;
      ans+=apple.first;
    }
  }
  cout << ans << endl;
  return 0;
}