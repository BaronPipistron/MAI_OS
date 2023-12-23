#pragma once

#define BUFFER 16
#define ITERATIONS 5

#include <iostream>
#include <cstring>

namespace processes {

class ChildProcess final {
public:
    static void child_process_handler(
        const char* file_name,
        const char* mmf_file_name,
        const char* mutex_name, 
        const char* is_empty_sem_name, 
        const char* is_full_sem_name);
};

}; // namespace processes