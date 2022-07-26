
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include "../dot/dot.h"
#include "dat.h"
using namespace std;

// helper function to get all saved dots
void get_dots(vector<Dot> &dots)
{
  fstream fin;
  fin.open("state", ios::in);
  vector<string> row;
  string line, word, temp;
  while (fin >> temp) {;
    getline(fin, line);
    stringstream s(temp);
    while (getline(s, word, ',')) {
      row.push_back(word);
    }
    dots.push_back(Dot(row.at(0), row.at(1)));
    row.clear();
  }
  fin.close();
}

// constructor, reads file initially
DatMgr::DatMgr() {
  get_dots(dotlist);
}

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
