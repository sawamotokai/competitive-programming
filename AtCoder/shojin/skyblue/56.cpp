#include <bits/stdc++.h>
#include <cassert>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ok() puts(ok?"Yes":"No");
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using ii = pair<int, int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using gt = greater<int>;
using minq = priority_queue<int, vector<int>, gt>;
using P = pair<ll,ll>;
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
//clang++ -std=c++11 -stdlib=libc++ 

int main() {
  int N,Q; cin >> N >> Q;
  vi X(N), R(N), H(N);
  rep(i,N) cin >> X[i] >> R[i] >> H[i];
  auto in = [](int a, int b, int left, int right) {
    if (right > b && left > b) return false;
    if (right < a && left < a) return false;
    return true;
  };
  auto getArea =  [](int r, int a, int b, int left, int right) {
    // if (right < b) {
    //   int out = max(0, b-left);
    //   int in = min(right-a, right-left);
    //   int height = right - left;
    //   double ratio = in*in*in/(height*height*height);
    // } else {
    //   int out = right-b;
    //   int height = right - left;
    //   double ratio = 1. - (out * out * out / (height*height*height));
    //   vol = r*r*M_PI*ratio;
    // }
    int x = max(0, right-b);
    int z = max(0, a - left);
    int y = right - left - x - z;
    int height = right - left;
    double ratio = ((x+y)*(x+y)*(x+y))/(height*height*height);
    ratio *= (1 - x*x*x/((x+y)*(x+y)*(x+y)));
    double vol = r * r * M_PI / 3. * ratio * height;
    return vol;
  };
  rep(i, Q) {
    double sum = 0;
    int a, b; cin >> a >> b;
    rep(j, N)  {
      int left = X[i];
      int right = X[i] + H[i];
      if (!in(a,b,left, right)) continue;
      sum += getArea(R[i],a,b,left, right);
    }
    printf("%.8f\n",sum);
  }
  
  return 0;
}