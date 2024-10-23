#include "pipe.h"
#include <iostream>
#include <sstream>
#include <assert.h>

Pipe::Pipe(std::string name, float length, float diameter, bool is_reparing) {
    assert(length>=0.0f);
    assert(diameter>=0.0f);

    if (diameter<0.0f || length <0.0f) {
        error = 1;
        this->name = "";
        this->length = 0;
        this->diameter = 0;
        this->is_reparing = false;
    }

    this->name = name;
    this->length = length;
    this->diameter = diameter;
    this->is_reparing = is_reparing;
}

Pipe::Pipe() {
    this->name = "";
    this->length = 0;
    this->diameter = 0;
    this->is_reparing = false;
}

std::string Pipe::get_name() const{
    return this->name;
}

float Pipe::get_length() const{
    return this->length;
}

float Pipe::get_diameter() const{
    return this->diameter;
}

bool Pipe::get_is_reapring() const{
    return this->is_reparing;
}


void Pipe::change_is_reparing() {
    this->is_reparing = !(this->is_reparing);
}

std::string Pipe::string() {
    std::stringstream s_string;
    s_string <<  " name=" << this->name <<
                 " length="  << this->length <<
                 " diameter=" << this->diameter <<
                 " is_reparing=" << ((this->is_reparing) ? "true" : "false") << '\n';
    return s_string.str(); 
}
