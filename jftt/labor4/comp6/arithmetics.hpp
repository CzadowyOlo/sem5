#include <iostream> 
#include <vector>
#include <algorithm>    // std::find_if
#include <map>
#include <string>
using namespace std;

void add       (string& dupa, size_t& k, map<string, int> p, string v1, string v2);
void write_val (string& dupa, size_t& k, map<string, int> p, string val);
void read_val  (string& dupa, size_t& k, map<string, int> p, string val);
void assign_val(string& dupa, size_t& k, map<string, int> p, string val);
void set_val   (string& dupa, size_t& k, map<string, int> p, string val);
void is_greater   (string& dupa, size_t& k, map<string, int> p, string v1, string v2);
void is_equal   (string& dupa, size_t& k, map<string, int> p, string v1, string v2);
void is_notequal   (string& dupa, size_t& k, map<string, int> p, string v1, string v2);


