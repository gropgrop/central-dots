#ifndef DOT_H_INCLUDED
#define DOT_H_INCLUDED
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <unistd.h>

const bool debug = true;

class Dot {
 public:
  std::string name, path;
  mutable bool linked;
  Dot() { Dot("DEFAULT","/dev/null",false); };
  Dot(std::string n, std::string p, bool ln):
    name(n),
    path(p),
    linked(ln)
  {
    if(debug) std::cout << "---->Dot ctor:" << name << "\n";
  }; //constructor
  ~Dot() { };       // destructor 


		       //assignment operator
  Dot& operator=(const Dot &rhs) {
    name = rhs.name;
    path = rhs.path;
    linked = rhs.linked;
    return *this;
  };
  
  // Link
  // Creates symlink to dot
  int link_dot() {
    if(debug) std::cout << "dot::link(): " << name << '\n';
    if (symlink(name.c_str(), path.c_str())) {
      std::cerr << "Error Occurred creating symlink: " << name << " in "
                << path;
      return 1;
    }
    linked = true;
    return 0;
  }
  
  // dunlink
  // removes symlink to dot
  int unlink_dot() {
    if(debug) std::cout << "dot::dunlink(): " << name << '\n';
    if (unlink(path.c_str())) {
      std::cerr << "Error Occurred removing symlink: " << name << " in "
                << path;
      return 1;
    }
    linked = false;
    return 0;
  }
};

// std::hash specialization
template<>
struct std::hash<Dot> {
public:
  size_t operator()(const Dot& e) const {
    if(debug) std::cout << "hash: " << e.name << '\n';
    return std::hash<std::string>()(e.name);
  }
};

// std::equal_to specialization
template <>
struct std::equal_to<Dot> {
  bool operator()(const Dot& lhs, const Dot& rhs) const {
    if(debug)
      std::cout << "std::equal_to<Dot>: "
		<< lhs.name << "::" << rhs.name << '\n';
    return !lhs.name.compare(rhs.name);
    // return value between compare and equal_to are reversed
  };
};

#endif //DOT_H_INCLUDED
