#ifndef _PIPELINE_H_
#define _PIPELINE_H_

#include <unordered_map>
#include <unordered_set>
#include "../pipe/pipe.h"

class Pipeline {
    std::unordered_map<int, Pipe> pipeline;
    std::unordered_set<int> selected;
public:
    void add(Pipe pipe);


    std::string string_selected();
    std::string string_pipelines();

    int select_by_name(std::string name);
    int select_by_is_reparing(bool is_reparing);

    bool change(int id);

    void clear_selection();
};


#endif
