#include "../../include/processes/child_process.h"
#include "../../include/calls/calls.h"

using namespace processes;
using namespace calls;

void ChildProcess::child_process_handler(
                                         const char* file_name,
                                         const char* mmf_file_name,
                                         const char* mutex_name, 
                                         const char* is_empty_sem_name, 
                                         const char* is_full_sem_name
                                         ) 
{
    int file = open_file(file_name);

    create_dup2FD(file, STDOUT_FILENO);
    closeFD(file);

    sem_t* is_empty_sem = open_semaphore(is_empty_sem_name, 1);
    sem_t* is_full_sem = open_semaphore(is_full_sem_name, 0);
    sem_t* mutex = open_semaphore(mutex_name, 1);

    int mmf_file_desc = open_shm_file(mmf_file_name);
    uint64_t* mmf_file_ptr = static_cast<uint64_t*>(create_shm_ptr(mmf_file_desc));

    int64_t sum = 0;
    int64_t num = 0;

    for (size_t i = 0; i < ITERATIONS; ++i) {
        sem_wait(is_full_sem);
        sem_wait(mutex);

        memcpy(&num, mmf_file_ptr, sizeof(num));

        sem_post(mutex);
        sem_post(is_empty_sem);

        sum += num;
    }

    std::cout << "Result sum: " << sum;

    sem_unlink(mutex_name);
    sem_unlink(is_empty_sem_name);
    sem_unlink(is_full_sem_name);
    shm_unlink(mmf_file_name);
      
    return;
}
