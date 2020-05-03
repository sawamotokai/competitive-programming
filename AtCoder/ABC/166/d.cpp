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
  ll x; cin >> x;
  int a = 0;
  while(pow(a, 5) < x) {
    a++;
  }
  int b = 0;
  cout << a << endl;
  // while(pow(a,5) - pow(b, 5) > x) {
    while (true) {
    b=0;
    // while(pow(a,5) - pow(b, 5) > x) {
    while (true) {
      b++;
      ll ans1 = pow(a,5) - pow(b, 5);
      ll ans2 = pow(a,5) - pow(-b, 5);
      printf("Ans1: %lld, Ans2: %lld\n", ans1, ans2); 
      if (pow(a,5) - pow(b, 5) == x || pow(a,5) - pow(-b, 5) == x ) {
        printf("%d %d\n", a, b);
        return 0;
      }
      
      if (pow(a,5) - pow(b, 5) < x &&  pow(a,5) - pow(-b, 5) > x) break;
    }
    a++;
    
    printf("Currently %d %d\n", a, b);
  }
  return 0;
}