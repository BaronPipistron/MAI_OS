#include "../../include/processes/parent_process.h"
#include "../../include/calls/calls.h"

using namespace processes;
using namespace calls;

void ParentProcess::parent_process_handler() {
    std::cout << "Parent process with pid " << getpid() << " started" << std::endl; 

    std::string file_name = get_file_name();

    const char* mmf_file_name = "lab3_mmf_file";
    const char* mutex_name = "lab3_mutex";
    const char* is_empty_sem_name = "lab3_is_empty";
    const char* is_full_sem_name = "lab3_is_full";

    pid_t pid = create_process();

    if (pid == 0) {
        run_process(
                    CHILD_NAME, 
                    file_name.c_str(), 
                    mmf_file_name, 
                    mutex_name, 
                    is_empty_sem_name, 
                    is_full_sem_name
                    );
                    
    } else {
        sem_t* is_empty_sem = open_semaphore(is_empty_sem_name, 1);
        sem_t* is_full_sem = open_semaphore(is_full_sem_name, 0);
        sem_t* mutex = open_semaphore(mutex_name, 1);

        int mmf_file_desc = open_shm_file(mmf_file_name);
        uint64_t* mmf_file_ptr = static_cast<uint64_t*>(create_shm_ptr(mmf_file_desc));

        for (size_t i = 0; i < ITERATIONS; ++i) {
            uint64_t num;
            std::cout << "Input number: ";
            std::cin >> num;

            sem_wait(is_empty_sem);
            sem_wait(mutex);
            
            memcpy(mmf_file_ptr, &num, sizeof(num));

            sem_post(mutex);
            sem_post(is_full_sem);
        }
    }

    return;
}

std::string ParentProcess::get_file_name() {
    std::string file_name;

    std::cout << "Input file name: ";
    std::cin >> file_name;

    if (file_name.length() > 255) throw std::invalid_argument("File name must be less than 256 symbols");

    for (char c: file_name) {
        if (c == '/' || c == '\\' || c == '?' || c == '<' || c == '>' || c == '*' || c == '|') {
            throw std::invalid_argument("File name can't contains /, \\, ?, <, >, *, |");
        }
    }
    file_name = "output_files/" + file_name + ".txt";
    
    return file_name;
}