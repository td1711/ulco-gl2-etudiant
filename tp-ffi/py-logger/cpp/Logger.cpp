#include "Logger.hpp"
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <sstream>

void Logger::addItem(Level l, const std::string & m) {
  _items.push_back({l,m});
}

std::string Logger::getLevelId(Item t) const{
    std::string id;
    switch(std::get<0>(t)){
      case Level::Info:
        id = "I";
        break;
      case Level::Warning:
        id = "W";
        break;
      case Level::Error:
        id = "E";
    }
    return id;
}

std::string Logger::reportByAdded() const {
  for(auto t : _items){
    std::cout << "[" << getLevelId(t) << "] " << std::get<1>(t) << std::endl;
  }
  return "TODO Logger::reportByAdded";
}

std::string Logger::reportByLevel() const {
  std::map<std::string, std::vector<Item>> map;
  for(auto t : _items){
    std::string id = getLevelId(t);
    if(map[id].empty())
      map[id] = {t};
    else
      map[id].push_back(t);
  }
  for(auto it=map.begin(); it!=map.end(); ++it){
    for(auto item : map[it->first]){
      std::cout << "[" << it->first << "]" << std::get<1>(item) << std::endl;
    }
  }
  return "TODO Logger::reportByLevel";
}

