#include "pipe.h"
#include <iostream>
#include <sstream>

Pipe::Pipe(int id, std::string name, float length, float diameter, bool is_reparing) {
    this->id = id;
    this->name = name; 
    this->length = length;
    this->diameter = diameter;
    this->is_reparing = is_reparing;
}

Pipe::Pipe() {
    this->id = 0;
    this->name = "";
    this->length = 0;
    this->diameter = 0;
    this->is_reparing = false;
}

int Pipe::get_id() {
    return this->id;
}
std::string Pipe::get_name() {
    return this->name;
}

float Pipe::get_length() {
    return this->length;
}

float Pipe::get_diameter() {
    return this->diameter;
}

bool Pipe::get_is_reapring() {
    return this->is_reparing;
}


void Pipe::change_is_reparing() {
    this->is_reparing = !(this->is_reparing);
}

std::string Pipe::string() {
    std::stringstream s_string;
    s_string <<  "id=" << this->id <<
                 " name=" << this->name <<
                 " length="  << this->length <<
                 " diameter=" << this->diameter <<
                 " is_reparing=" << ((this->is_reparing) ? "true" : "false") << '\n';
    return s_string.str(); 
}

/*void Pipe::sava(std::ofstream &file){ */
/*    file << "Pipe\n" <<*/
/*            this->name << '\n' <<*/
/*            this->length << '\n' <<*/
/*            this->diameter << '\n' <<*/
/*            this->is_reparing << '\n';*/
/*}*/
/**/
/*void Pipe::load(std::ifstream &file) {*/
/*    std::getline(file>>std::ws, this->name,'\n');*/
/*    file >> this->length >> this->diameter >> this->is_reparing;*/
/*}*/
