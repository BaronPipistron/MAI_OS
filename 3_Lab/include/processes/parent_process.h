#pragma once

#include <iostream>
#include <string>
#include <cstring>

#define BUFFER 16
#define CHILD_NAME "./build/lab3_run_child"

namespace processes {

class ParentProcess final {
public:
    static void parent_process_handler();

private:
    [[nodiscard]] static std::string get_file_name();
};

}; // namespace processes