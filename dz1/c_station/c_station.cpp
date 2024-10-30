#include "c_station.h"
#include <sstream>
#include <assert.h>

C_station::C_station(std::string name, unsigned int workshops, unsigned int working_workshops,float efficiency) {
    assert(working_workshops <= workshops);
    if (working_workshops > workshops) {
        // ERR("in c_station with name ", name, " working_workshops > workshops");
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
    this->not_working_workshops = (unsigned int)(workshops-working_workshops)/float(workshops)*100;
}

std::string C_station::get_name() const{
    return this->name;
}

unsigned int C_station::get_workshops() const {
    return this->workshops;
}

unsigned int C_station::get_working_workshops() const {
    return this->working_workshops;
}

float C_station::get_not_working_workshops() const {
    return this->not_working_workshops;
}

float C_station::get_efficiency() const {
    return this->efficiency;
}

bool C_station::inc_working_workshops() {
    if (this->working_workshops + 1 > this->workshops) {
        return false;
    }
    this->working_workshops++;
    return true;

}

std::string C_station::string() {
    std::stringstream str;
    str << " name=" << this->name <<
           " workshops=" << this->workshops <<
           " working workshops=" << this->working_workshops <<
           " efficiency=" << this->efficiency <<
           " not working percent=" << this->not_working_workshops;
    return str.str();
}

bool C_station::good() {
    if (this->error !=0) {
        return false;
    }
    return true;
}
