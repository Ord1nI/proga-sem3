#include "factory.h"
#include <sstream>
#include <fstream>


Factory::Factory() {
    this->id = 1;
}

void Factory::add(C_station c_station) {
    factory.emplace(id++, c_station);
}

const std::unordered_set<unsigned int>& Factory::get_selected() {
    return selected;
}

std::string Factory::string_selected() {
    std::stringstream str;
    for (auto id : selected) {
        str << "id: "<< id << factory.at(id).string() << '\n';
    }
    return str.str();
}

std::string Factory::string_factory() {
    std::stringstream str;
    for (auto c_station : factory) {
        str << "id: " << c_station.first <<c_station.second.string() << '\n';
    }
    return str.str();
}

// int Factory::select(std::function<bool(const C_station & station)> f) {
//     int count = 0;
//     for (auto& c_station : factory) {
//         if(f(c_station.second)) {
//             this->selected.emplace(c_station.first);
//             count++;
//         }
//     }
//     return count;
// }

const std::unordered_set<unsigned int>& Factory::select_by_name(std::string name) {
    int count = 0;
    for (auto& c_station : factory) {
        if (c_station.second.get_name().find(name) != std::string::npos) {
            selected.emplace(c_station.first);
            count++;
        }
    }
    return this->selected;
}

const std::unordered_set<unsigned int>& Factory::select_by_not_working_workshops(unsigned int not_working_workshops) {
    int count = 0;
    for (auto& c_station : factory) {
        if (c_station.second.get_not_working_workshops() == not_working_workshops) {
           selected.emplace(c_station.first);
           count++;
        }
    }
    return this->selected;
}

void Factory::clear_selection() {
    this->selected.clear();
}

bool Factory::change(int id) {
    if (this->selected.find(id) != selected.end()) {
        return this->factory.at(id).inc_working_workshops();
    }
    return false;
}



void Factory::load(std::ifstream &file) {
    // INFO("Load factory");

    size_t n;
    file >> n;
    for (size_t i = 0; i < n; i++) {
        std::string tmp_name;
        unsigned int id;
        unsigned int tmp_workshops;
        unsigned int tmp_working_workshops;
        float tmp_efficiency;

        std::getline(file>>std::ws, tmp_name, '\n');
        file >> id >> tmp_workshops >> tmp_working_workshops >> tmp_efficiency;

        this->factory.emplace(id, C_station(tmp_name, tmp_workshops, tmp_working_workshops,tmp_efficiency));

        if(id > this->id) {
            this->id = id+1;
        }
    }
}

void Factory::save(std::ofstream &file) {
    // INFO("Save factory");

    file << "FACTORY\n";
    file << factory.size() << '\n';
    for (auto &f : factory) {
        file << f.second.get_name() << '\n' <<
                f.first << '\n' <<
                f.second.get_workshops() << '\n' <<
                f.second.get_working_workshops()  << '\n' <<
                f.second.get_efficiency() << '\n';

    }
}
