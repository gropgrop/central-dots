
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "dat.h"
using namespace std;

// print - just shows everything currently in the vec. Mostly for debug purposes
void DatMgr::print() {
  for (Dot &i: dotlist) {    
    cout << i.name << " " << i.path << '\n';
  }
}
//void DatMgr::save();       // rewrites data file
//void DatMgr::add_dot();    // adds a dot to dot list
//void DatMgr::remove_dot(); // removes a dot from dot list, unlinks dot
//int DatMgr::link_dot();    // links all dots
