#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "dat.h"
#include <algorithm>

using namespace std;


// print - just shows everything currently in the vec. Mostly for debug purposes
void DatMgr::print() {
  Dot i;
  for (pair<string,Dot> d: dotlist) {
    i = d.second;
    cout << i.name << " " << i.path << '\n';
  }
}

// writes all current data to file
void DatMgr::save() {
  if(debug) cout << "DatMgr::save()\n";
  ofstream f("state");
  //dotlist.insert(Dot("Test", "Test"));
  Dot i;
  for (pair<string,Dot> n : dotlist) {
    i = n.second;
    f << i.name << "," << i.path << ',' << boolalpha << i.linked << '\n';
  }
  f.close();
}

// adds dotfile to list 
void DatMgr::add_dot(string &n, string &p, bool ln = false) {
  if(debug) cout << "DatMgr::add_dot(" << n << ',' << p << ")\n";
  dotlist[n] = (Dot(n, p, false));
}

// removes dotfile from list
void DatMgr::remove_dot(string &n) {
  if(debug) cout << "DatMgr::remove_dot(" << n << ")\n";
  dotlist.erase(n);
}

// unlinks all dotfiles 
void DatMgr::unlink_all_dots() {
  if(debug) cout << "DatMgr::remove_all_dots\n";
  Dot d;
  for(pair<string,Dot> pr: dotlist) {
    d = pr.second;
    if(d.linked) {
      if(debug) cout << "---> Unlinking: " << d.name << " from " << d.path << '\n';
      d.unlink_dot();
    }
  }
};

// links all dotfiles
void DatMgr::link_all_dots() {
  if(debug) cout << "DatMgr::remove_all_dots\n";
  for(pair<string,Dot> d: dotlist) {
    if(!d.second.linked) {
      if(debug) cout << "---> Linking: " << d.second.name << " from " << d.second.path << '\n';
      d.second.link_dot();
    }
  }
};


// removes a dot from dot list, unlinks dot
// int DatMgr::link_dot();    // links all dots
void DatMgr::link_a_dot(string &name) {
  dotlist.at(name).link_dot();
}

void DatMgr::unlink_a_dot(string &name) {
  dotlist.at(name).unlink_dot();
}
