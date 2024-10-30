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
    Factory();

    void add(C_station c_station);

    const std::unordered_set<unsigned int>& get_selected();

    std::string string_selected();
    std::string string_factory();

    // int select(std::function<bool(const C_station & station)> f);

    const std::unordered_set<unsigned int>& select_by_name(std::string name);
    const std::unordered_set<unsigned int>& select_by_not_working_workshops(unsigned int not_working_workshops);

    void clear_selection();

    bool change(int id);

    void load(std::ifstream &file);
    void save(std::ofstream &file);
};

#endif
