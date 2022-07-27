#ifndef DAT_H_INCLUDED
#define DAT_H_INCLUDED

#include "../include/dot.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <string>


class DatMgr {
 public:
  static DatMgr& getInstance()
  {
    static DatMgr instance;
    return instance;
  };          // constructor, reads file initially
  ~DatMgr() {};         // destructor - idk honestly
  void save();       // rewrites data file
  void add_dot();    // adds a dot to dot list
  void remove_dot(); // removes a dot from dot list, unlinks dot
  // int link_dot();    // links all dots
  void print();
 private:
  std::vector<Dot> dotlist;
  DatMgr() { DatMgr::get_dots(dotlist); }
  void get_dots(std::vector<Dot> &dots) {
    std::fstream fin;
    fin.open("state", std::ios::in);
    std::vector<std::string> row;
    std::string line, word, temp;
    while (fin >> temp) {
      ;
      getline(fin, line);
      std::stringstream s(temp);
      while (getline(s, word, ',')) {
        row.push_back(word);
      }
      dots.push_back(Dot(row.at(0), row.at(1)));
      row.clear();
    }
    fin.close();
  }
};

#endif
