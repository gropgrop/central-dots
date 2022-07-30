#include "dat.cc"
#include <vector>
using namespace std;


class Ctl {
private:
  static DatMgr data;
  enum cmd { REMOVE_DOT, ADD_DOT, UNLINK, LINK, EXIT, HELP, UNKNOWN, NEXT};
  unordered_map<string, cmd> const mapcmd =
    { { "rm" , cmd::REMOVE_DOT } , // takes: (name), -a (all)
      { "add", cmd::ADD_DOT } ,    // takes: (name)
      { "unlink", cmd::UNLINK} ,   // takes: (name), -a (all)
      { "link", cmd::LINK} ,       // takes: (name), -a (all)
      { "exit", cmd::EXIT} ,
      { "help", cmd::HELP} ,
      { "?", cmd::HELP } ,
      { "h", cmd::HELP } ,
      { "quit", cmd::EXIT },
      { "stop", cmd::EXIT },
      { "=", cmd::UNKNOWN } };
  
  void prompt() {
    cout << "\n(dotmgr): ";
  }
  
  vector<string> sanitize(string s) {
    transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ return std::tolower(c); });
    string tmp;
    vector<string> svec;
    int startindex = 0, endindex = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s.at(i) == ' ') {
	tmp.append(s, startindex, i-startindex);
	startindex = i + 1;
	svec.push_back(tmp);
      }
    }
    return svec;
  } 
  
public:
  Ctl() {
    data = DatMgr::getInstance();
  }

  ~Ctl(){};
  
  vector<string> await() {
    string input;
    prompt();
    cin >> input;
    return sanitize(input);
  }

  cmd readinput(vector<string> vs) {
    if(vs.size() > 3) return mapcmd.at("?");
    switch (mapcmd.at(vs.at(0))) {
    case ADD_DOT:
      if (vs.size() == 1) return cmd::UNKNOWN;
      if (vs.at(1) == "-a") return cmd::UNKNOWN;
      data.add_dot(vs.at(1), vs.at(2), false);
      return cmd::NEXT;
    case REMOVE_DOT:
      if (vs.size() == 1) return cmd::UNKNOWN;
      if (vs.at(1) == "-a") return cmd::UNKNOWN;
      data.unlink_a_dot(vs.at(1));
      data.remove_dot(vs.at(1));
      return cmd::NEXT;
    case LINK:
      if (vs.size() == 1 || vs.size() == 2) return cmd::UNKNOWN;
      if (count(vs.begin(), vs.end(), "-a")) {
	data.link_all_dots();
	return cmd::NEXT;
      }
      data.link_a_dot(vs.at(1));
      return cmd::NEXT;
    case UNLINK:
      if (vs.size() == 1 || vs.size() == 2) return cmd::UNKNOWN;
      if (count(vs.begin(), vs.end(), "-a")) {
	data.unlink_all_dots();
	return cmd::NEXT;
      }
      data.unlink_a_dot(vs.at(1));
      return cmd::NEXT;
      
    case EXIT:
      return cmd::EXIT;
      
    case HELP:
      help();
      return cmd::NEXT;
      
    case UNKNOWN:
      usage();
      return cmd::NEXT;
      
    case NEXT: // LEGIT << THIS SHOULD NEVER BE PASSED. THERES SOMETHING HORRIBLY WRONG.
      cout << "WHAT THE FUCK HAPPENED LOL. "; 
      return cmd::EXIT;
    }
    return mapcmd.at("?");
  }

  int handler(cmd command) {
    data.save();
    if(command == cmd::EXIT) return 0;
    if(command == cmd::NEXT) return 1;
    cout << "SOMETHING'S GONE HORRIBLY FUCKING WRONG. ";
    return 1;
  };

  void loop() {
    int i = 1;
    while( i ) {
      i = handler(readinput(await()));
    }
    this -> ~Ctl();
  }

  void help() {}
  void usage() {}
};
