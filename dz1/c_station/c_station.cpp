#include "c_station.h"
#include <sstream>

C_station::C_station(int id, std::string name, int workshops, int working_workshops,float efficiency) {
    this->id = id;
    this->name = name;
    this->workshops = workshops;
    this->working_workshops = working_workshops;
    this->efficiency = efficiency;
}

C_station::C_station() {
    this->id = 0;
    this->name = "";
    this->workshops = 0;
    this->working_workshops = 0;
    this->efficiency = 0;
}

int C_station::get_id() {
    return this->id;
}

std::string C_station::get_name() {
    return this->name;
}

int C_station::get_workshops() {
    return this->workshops;
}

int C_station::get_working_workshops() {
    return this->working_workshops;
}

float C_station::get_efficiency() {
    return this->efficiency;
}

void C_station::set_name(std::string name) {
    this->name = name;
}

void C_station::set_workshops(int workshops) {
    this->name = workshops;
}

bool C_station::set_working_workshops(int working_workshops) {
    if (this->working_workshops > this->workshops) {
        return false;
    }
    this->working_workshops = working_workshops;
    return true;
}

void C_station::set_efficiency(float efficiency) {
    this->efficiency = efficiency;
}


std::string C_station::string() {
    std::stringstream str;
    str << "id=" << this->id <<
           " name=" << this->name <<
           " workshops=" << this->workshops <<
           " working workshops" << this->working_workshops <<
           " efficiency" << this->efficiency;
    return str.str();
}
