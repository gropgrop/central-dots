#include "dot.h"
#include <string>
#include <iostream>
#include <unistd.h>

using namespace std;

// Link
// Creates symlink to dot
// Removes dot from data
int Dot::link() {
  if(symlink(name.c_str(), path.c_str())) {
    cerr << "Error Occurred creating symlink: " << name << " in " << path;
    return 1;
  } return 0;
}
//
int Dot::remove() {
  if(unlink(path.c_str())) {
    cerr << "Error Occurred removing symlink: " << name << " in " << path;
    return 1;
  } return 0;
}

  

