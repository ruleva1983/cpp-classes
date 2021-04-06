#include "abstract.hpp"
#include <iostream>

using namespace std;

int main(){

  
  IOJson json;
  json.read("sample.json");
  json.write();

  IOCSV csv;
  csv.read("sample.csv");
  csv.write();
  csv.say_something();
}
