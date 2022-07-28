#ifndef DAT_H_INCLUDED
#define DAT_H_INCLUDED

#include "../include/dot.h"
#include <algorithm>
#include <cctype>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>


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
  void add_dot(std::string &, std::string &, bool);    // adds a dot to dot list
  void remove_dot(std::string &); // removes a dot from dot list, unlinks dot
  // int link_dot();    // links all dots
  void unlink_a_dot(std::string &); // unlinks a dot specified by dot name
  void unlink_all_dots(); // unlinks every dot.
  void link_a_dot(std::string &); // links a dot specified by dot name
  void link_all_dots(); // links every specified dotfile
  void print();
 private:
  std::unordered_map<std::string,Dot,std::hash<std::string>,std::equal_to<std::string>> dotlist;
  DatMgr() {
    if(debug) std::cout << "DatMgr private ctor\n";
    DatMgr::get_dots(dotlist);
  };

  void get_dots(std::unordered_map<std::string,Dot,std::hash<std::string>,std::equal_to<std::string>> &dots) {
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
      dotlist[row.at(0)] = (Dot(row.at(0), row.at(1), to_bool( row.at(2) ) ) );
      row.clear();
    }
    fin.close();
  }

  // helper fn for reading data
  bool to_bool(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    std::istringstream is(s);
    bool b;
    is >> std::boolalpha >> b;
    return b;
  }
};


#endif
