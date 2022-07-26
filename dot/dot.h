#ifndef DOT_H_INCLUDED
#define DOT_H_INCLUDED
#include <fstream>

class Dot {
 public:
  std::string name, path;
  Dot(std::string n = "", std::string p = ""):
    name(n),
    path(p) {}; //constructor
  ~Dot() { };       // destructor 
  int link();   // links an individual dot
  int remove();
};

#endif //DOT_H_INCLUDED
