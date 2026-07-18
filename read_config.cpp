#include "json.hpp"
#include <fstream>
#include <iostream>

using json = nlohmann::json;

struct Engine_Config {
  std::string engine_name;
  std::string author;
  int search_depth;
  bool use_opening_book;
  int threads;
};

Engine_Config load_config(const std::string& path) {
  std::ifstream file(path);
  if (!file.is_open()) {
    throw std::runtime_error("could not open config file " + path);
  }

  json data;
  file >> data;

  Engine_Config conf;
  conf.engine_name    = data.value("engine_name", "UnnamedEngine");
  conf.author         = data.value("author", "unknown");
  conf.search_depth   = data.value("search_depth", 12);
  conf.use_opening_book   = data.value("use_opening_book", false);
  conf.threads            = data.value("threads", 1);

  return conf;
}
  
int main()
{
      try {
        Engine_Config conf = load_config("config.json");
 
        std::cout << "Loaded config for: " << conf.engine_name
                  << " by " << conf.author << "\n";
        std::cout << "  search depth:     " << conf.search_depth << "\n";
        std::cout << "  threads:          " << conf.threads << "\n";
 
    } catch (const std::exception& e) {
        std::cerr << "Error loading config: " << e.what() << "\n";
        return 1;
    }
 
  return 0;
}
