#include "pipeline.h"
#include <sstream>

void Pipeline::add(Pipe pipe) {
        pipeline.emplace(pipe.get_id(), pipe);
}

int Pipeline::select_by_name(std::string name) {
    int count = 0;
    for (auto& pipe : pipeline) {
        if (pipe.second.get_name().find(name) != std::string::npos) {
            selected.emplace(pipe.first);
            count++;
        }
    }
    return count;
}

int Pipeline::select_by_is_reparing(bool is_reparing) {
    int count = 0;
    for (auto& pipe : pipeline) {
        if (pipe.second.get_is_reapring() == is_reparing) {
           selected.emplace(pipe.first);
           count++;
        }
    }
    return count;
}

std::string Pipeline::string_selected() {
    std::stringstream str;
    for (auto id : selected) {
        str << pipeline.at(id).string() << '\n';
    }
    return str.str();
}

std::string Pipeline::string_pipelines() {
    std::stringstream str;
    for (auto pipe : pipeline) {
        str << pipe.second.string() << '\n';
    }
    return str.str();
}

void Pipeline::clear_selection() {
    this->selected.clear();
}

bool Pipeline::change(int id) {
    if (this->selected.find(id) != selected.end()) {
        this->pipeline.at(id).change_is_reparing();
        return true;
    }
    return false;
}
