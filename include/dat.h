#ifndef DAT_H_INCLUDED
#define DAT_H_INCLUDED

#include "../include/dot.h"
#include <algorithm>
#include <cctype>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_set>


class DatMgr {
 public:
  static DatMgr& getInstance()
  {
    if(debug) std::cout << "DatMgr ctor\n";
    static DatMgr instance;
    return instance;
  };          // constructor, reads file initially
  ~DatMgr() { };         // destructor - idk honestly
  void save();       // rewrites data file
  void add_dot(std::string &, std::string &);    // adds a dot to dot list
  void remove_dot(std::string &); // removes a dot from dot list, unlinks dot
  // int link_dot();    // links all dots
  void print();
 private:
  std::unordered_set<Dot,std::hash<Dot>,std::equal_to<Dot>> dotlist;
  DatMgr() {
    if(debug) std::cout << "DatMgr private ctor\n";
    DatMgr::get_dots(dotlist);
  };

  void get_dots(std::unordered_set<Dot,std::hash<Dot>,std::equal_to<Dot>> &dots) {
    if(debug) std::cout << "DatMgr::get_dots\n";
    std::fstream fin;
    fin.open("state", std::ios::in);
    std::vector<std::string> row;
    std::string line, word, temp;
    while (fin >> temp) {
      getline(fin, line);
      std::stringstream s(temp);
      while (getline(s, word, ',')) {
        row.push_back(word);
      }
      dotlist.insert(Dot(row.at(0), row.at(1)));
      row.clear();
    }
    fin.close();
  }
};

#endif
