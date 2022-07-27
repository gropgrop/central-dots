#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "./include/dat.cc"

using namespace std;

int main() {
  static DatMgr& s = DatMgr::getInstance();
  s.print();
}
