#include "../include/processes/child_process.h"

int main(int argc, char** argv) {
    processes::ChildProcess::child_process_handler(
                                                   argv[1], 
                                                   argv[2], 
                                                   argv[3], 
                                                   argv[4], 
                                                   argv[5]
                                                   );

    return 0;
}