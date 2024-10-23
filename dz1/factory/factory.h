#ifndef _FACTORY_H_
#define _FACTORY_H_

#include <unordered_map>
#include <unordered_set>
#include <functional>
#include "../c_station/c_station.h"

class Factory {
    unsigned int id;

    std::unordered_map<unsigned int, C_station> factory;
    std::unordered_set<unsigned int> selected;
public:
    void add(C_station c_station);

    std::string string_selected();
    std::string string_factory();

    // int select(std::function<bool(const C_station & station)> f);

    const std::unordered_set<unsigned int>& select_by_name(std::string name);
    const std::unordered_set<unsigned int>& select_by_working_workshops(int working_workshops);

    void clear_selection();

    bool change(int id, int workshops);

    void load(std::ifstream &file);
    void save(std::ofstream &file);
};

#endif
