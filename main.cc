#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "./include/dat.cc"

using namespace std;

int main() {
  static DatMgr& s = DatMgr::getInstance();
  string testdot = "balls";
  s.remove_dot(testdot);
  s.print();
  s.save();
}
