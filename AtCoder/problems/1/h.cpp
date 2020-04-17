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
  int N; cin>>N;
  vi A(N), B(N);
  vi ab(N);
  rep(i,N) {
    int a, b; cin>>a>>b;
    A[i]=a;
    B[i]=b;
    ab[i] = a+b;
  }
  ll aoki = 0;
  rep(i,N) aoki -= B[i];
  sort(ab.begin(), ab.end(), [](int a, int b){return a>b;});
  rep(i, N) {
    if (!(i&1)) aoki += ab[i];
  }
  cout << aoki << endl;


  return 0;
}