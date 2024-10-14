#include "factory.h"
#include <sstream>

void Factory::add(C_station c_station) {
    factory.emplace(c_station.get_id(), c_station);
}

std::string Factory::string_selected() {
    std::stringstream str;
    for (auto id : selected) {
        str << factory.at(id).string() << '\n';
    }
    return str.str();
}

std::string Factory::string_factory() {
    std::stringstream str;
    for (auto c_station : factory) {
        str << c_station.second.string() << '\n';
    }
    return str.str();
}

int Factory::select_by_name(std::string name) {
    int count = 0;
    for (auto& c_station : factory) {
        if (c_station.second.get_name().find(name) != std::string::npos) {
            selected.emplace(c_station.first);
            count++;
        }
    }
    return count;
}

int Factory::select_by_working_workshops(int working_workshops) {
    int count = 0;
    for (auto& c_station : factory) {
        if (c_station.second.get_working_workshops() >= working_workshops) {
           selected.emplace(c_station.first);
           count++;
        }
    }
    return count;
}

void Factory::clear_selection() {
    this->selected.clear();
}

bool Factory::change(int id, int workshops) {
    if (this->selected.find(id) != selected.end()) {
        if (this->factory.at(id).get_workshops() >= workshops) {
            this->factory.at(id).set_working_workshops(workshops);
            return true;
        }
    }
    return false;
}
