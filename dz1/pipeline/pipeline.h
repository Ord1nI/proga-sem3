//Перенес id
#ifndef _PIPELINE_H_
#define _PIPELINE_H_

#include <fstream>
#include <unordered_map>
#include <unordered_set>

#include "../pipe/pipe.h"

class Pipeline {
    unsigned int id;

    std::unordered_map<unsigned int, Pipe> pipeline;
    std::unordered_set<unsigned int> selected;

public:
    Pipeline();

    void add(Pipe pipe);

    std::string string_selected();
    std::string string_pipelines();

    // int select(std::function<bool(const  Pipe & pipe)> f);

    const std::unordered_set<unsigned int>& select_by_name(std::string name);
    const std::unordered_set<unsigned int>& select_by_is_reparing(bool is_reparing);

    bool change(int id);

    void clear_selection();

    void load(std::ifstream &file);
    void save(std::ofstream &file);
};


#endif
