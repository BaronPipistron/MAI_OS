#pragma once

#include <iostream>
#include <cstring>

#define BUFFER 16
#define ITERATIONS 5

namespace processes {

class ChildProcess final {
public:
    static void child_process_handler(
                                      const char*,
                                      const char*,
                                      const char*, 
                                      const char*, 
                                      const char*
                                      );
};

}; // namespace processes