#include <bits/stdc++.h>
using namespace std;

int main() {
  int deg, dis, W;
  cin >> deg >> dis;
  string dir;
  if (deg >= 112.5 && deg < 337.5) {
    dir = "NNE";
  } else if (deg >= 337.5 && deg < 562.5) {
    dir = "NE";
  } else if (deg >= 562.5 && deg < 787.5) {
    dir = "ENE";
  } else if (deg >= 787.5 && deg < 1012.5) {
    dir = "E";
  } else if (deg >= 1012.5 && deg < 1237.5) {
    dir = "ESE";
  } else if (deg >= 1237.5 && deg < 1462.5) {
    dir = "SE";
  } else if (deg >= 1462.5 && deg < 1687.5) {
    dir = "SSE";
  } else if (deg >= 1687.5 && deg < 1912.5) {
    dir = "S";
  } else if (deg >= 1912.5 && deg < 2137.5) {
    dir = "SSW";
  } else if (deg >= 2137.5 && deg < 2362.5) {
    dir = "SW";
  } else if (deg >= 2362.5 && deg < 2587.5) {
    dir = "WSW";
  } else if (deg >= 2587.5 && deg < 2812.5) {
    dir = "W";
  } else if (deg >= 2812.5 && deg < 3037.5) {
    dir = "WNW";
  } else if (deg >= 3037.5 && deg < 3262.5) {
    dir = "NW";
  } else if (deg >= 3262.5 && deg < 3487.5) {
    dir = "NNW";
  } else {
    dir = "N";
  }
  if (dis >= 0 && dis < 15) {
    W = 0;
    dir = "C";
  } else if (dis >= 15 && dis < 93) {
    W = 1;
  } else if (dis >= 93 && dis < 201) {
    W = 2;
  } else if (dis >= 201 && dis < 327) {
    W = 3;
  } else if (dis >= 327 && dis < 477) {
    W = 4;
  } else if (dis >= 477 && dis < 645) {
    W = 5;
  } else if (dis >= 645 && dis < 831) {
    W = 6;
  } else if (dis >= 831 && dis < 1029) {
    W = 7;
  } else if (dis >= 1029 && dis < 1245) {
    W = 8;
  } else if (dis >= 1245 && dis < 1467) {
    W = 9;
  } else if (dis >= 1467 && dis < 1707) {
    W = 10;
  } else if (dis >= 1707 && dis < 1959) {
    W = 11;
  } else if (dis >= 1959) {
    W = 12;
  }
  cout << dir << " " << W << endl;
}
