#include "pipeline.h"
#include <sstream>

Pipeline::Pipeline() {
    this->id = 0;
}

void Pipeline::add(Pipe pipe) {
    pipeline.emplace(id++, pipe);
}

// int Pipeline::select(std::function<bool(const Pipe & pipe)> f) {
//     int count = 0;
//     for (auto& pipe : pipeline) {
//         if (f(pipe.second)) {
//             selected.emplace(pipe.first);
//             count++;
//         }
//     }
//     return count;
// }

const std::unordered_set<unsigned int>& Pipeline::select_by_name(std::string name) {
    int count = 0;
    for (auto& pipe : pipeline) {
        if (pipe.second.get_name().find(name) != std::string::npos) {
            selected.emplace(pipe.first);
            count++;
        }
    }
    return this->selected;
}

const std::unordered_set<unsigned int>& Pipeline::select_by_is_reparing(bool is_reparing) {
    int count = 0;
    for (auto& pipe : pipeline) {
        if (pipe.second.get_is_reapring() == is_reparing) {
           selected.emplace(pipe.first);
           count++;
        }
    }
    return this->selected;
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

void Pipeline::save(std::ofstream &file) {
    file << "PIPELINE\n";
    file << pipeline.size() << '\n';
    for (auto &p : pipeline) {
        file << p.second.get_name() << '\n' <<
                p.first << '\n' <<
                p.second.get_length() << '\n' <<
                p.second.get_diameter()  << '\n' <<
                p.second.get_is_reapring() << '\n';
    }
}

void Pipeline::load(std::ifstream &file) {
    size_t n;
    file >> n;
    for (size_t i = 0; i < n; i++) {
        std::string tmp_name;
        unsigned int id;
        float tmp_length;
        float tmp_diameter;
        bool tmp_is_reparing;

        std::getline(file>>std::ws, tmp_name, '\n');
        file >> id >> tmp_length >> tmp_diameter >> tmp_is_reparing;

        this->pipeline.emplace(id, Pipe(tmp_name, tmp_length, tmp_diameter, tmp_is_reparing));
    }
}
