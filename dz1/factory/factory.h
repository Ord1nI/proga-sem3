#ifndef _FACTORY_H_
#define _FACTORY_H_

#include <unordered_map>
#include <unordered_set>
#include "../c_station/c_station.h"

class Factory {
    std::unordered_map<int, C_station> factory;
    std::unordered_set<int> selected;
public:
    void add(C_station c_station);

    std::string string_selected();
    std::string string_factory();

    int select_by_name(std::string name);
    int select_by_working_workshops(int working_workshops);

    void clear_selection();

    bool change(int id, int workshops);
};

#endif
