
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "dat.h"
#include <algorithm>
using namespace std;

// print - just shows everything currently in the vec. Mostly for debug purposes
void DatMgr::print() {
  for (const Dot &i: dotlist) {    
    cout << i.name << " " << i.path << '\n';
  }
}

// writes all current data to file
void DatMgr::save() {
  if(debug) cout << "DatMgr::save()\n";
  ofstream f("state");
  //dotlist.insert(Dot("Test", "Test"));
  for (Dot i : dotlist) {
    f << i.name << "," << i.path << '\n';
  }
  f.close();
}

// adds dotfile to list 
void DatMgr::add_dot(string &n, string &p) {
  if(debug) cout << "DatMgr::add_dot(" << n << ',' << p << ")\n";
  dotlist.insert(Dot(n, p));
}

// removes dotfile from list
void DatMgr::remove_dot(string &n) {
  if(debug) cout << "DatMgr::remove_dot(" << n << ")\n";
  Dot tmp = Dot(n,"path");
  dotlist.erase(tmp);
}

// adds a dot to dot list
//void DatMgr::unlink_dot(); // removes a dot from dot list, unlinks dot
//int DatMgr::link_dot();    // links all dots
