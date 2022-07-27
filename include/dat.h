#ifndef DAT_H_INCLUDED
#define DAT_H_INCLUDED

#include "../include/dot.h"
#include <vector>

class DatMgr {
 public:
  DatMgr();          // constructor, reads file initially
  ~DatMgr() {};         // destructor - idk honestly
  void save();       // rewrites data file
  void add_dot();    // adds a dot to dot list
  void remove_dot(); // removes a dot from dot list, unlinks dot
  // int link_dot();    // links all dots
  void print();
 private:
  std::vector<Dot> dotlist;
};

#endif
