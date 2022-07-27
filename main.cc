#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "./include/dat.cc"

using namespace std;

// main is still worthless

int main() {
  static DatMgr& s = DatMgr::getInstance();
  //s.remove_dot(testdot);
  s.print();
  s.save();
}
