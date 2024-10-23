#include "c_station.h"
#include <sstream>

C_station::C_station(std::string name, unsigned int workshops, unsigned int working_workshops,float efficiency) {
    if (working_workshops > workshops) {
        this->error = 1;
        this->name = "";
        this->workshops = 0;
        this->working_workshops = 0;
        this->efficiency = 0;
        return;
    }

    this->name = name;
    this->workshops = workshops;
    this->working_workshops = working_workshops;
    this->efficiency = efficiency;
}

C_station::C_station() {
    this->name = "";
    this->workshops = 0;
    this->working_workshops = 0; this->efficiency = 0;
}


std::string C_station::get_name() const{
    return this->name;
}

int C_station::get_workshops() const {
    return this->workshops;
}

int C_station::get_working_workshops() const {
    return this->working_workshops;
}

float C_station::get_efficiency() const {
    return this->efficiency;
}

void C_station::set_name(std::string name) {
    this->name = name;
}

void C_station::set_workshops(unsigned int workshops) {
    this->name = workshops;
}

void C_station::set_working_workshops(unsigned int working_workshops) {
    if (this->working_workshops > this->workshops) {
        this->error = 1;
    }
    this->working_workshops = working_workshops;
}

void C_station::set_efficiency(float efficiency) {
    this->efficiency = efficiency;
}


std::string C_station::string() {
    std::stringstream str;
    str << " name=" << this->name <<
           " workshops=" << this->workshops <<
           " working workshops" << this->working_workshops <<
           " efficiency" << this->efficiency;
    return str.str();
}

bool C_station::good() {
    if (this->error !=0) {
        return false;
    }
    return true;
}
