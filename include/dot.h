#ifndef DOT_H_INCLUDED
#define DOT_H_INCLUDED
#include <fstream>
#include <string>
#include <iostream>
#include <unistd.h>

class Dot {
 public:
  std::string name, path;
  Dot(std::string n = "", std::string p = ""):
    name(n),
    path(p) {}; //constructor
  ~Dot() { };       // destructor 
		 
  
  // Link
  // Creates symlink to dot
  // Removes dot from data
  int link() {
    if (symlink(name.c_str(), path.c_str())) {
      std::cerr << "Error Occurred creating symlink: " << name << " in "
                << path;
      return 1;
    }
    return 0;
  }
  //
  int remove() {
    if (unlink(path.c_str())) {
      std::cerr << "Error Occurred removing symlink: " << name << " in "
                << path;
      return 1;
    }
    return 0;
  }
};

#endif //DOT_H_INCLUDED
