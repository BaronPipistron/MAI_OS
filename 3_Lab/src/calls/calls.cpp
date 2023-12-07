#include "../../include/calls/calls.h"

namespace calls {

pid_t create_process() {
    pid_t pid = fork();

    if (pid == -1) throw std::runtime_error("Failed with creating child process");
    return pid;
}

int open_file(const char* file_name) {
    int file = open(file_name, O_CREAT | O_WRONLY | O_TRUNC);

    if (file == -1) throw std::runtime_error("Failed with opening file");
    return file;
} 

void create_dup2FD(const int old_fd, const int new_fd) {
    int dup2_num = dup2(old_fd, new_fd);

    if (dup2_num == -1) throw std::runtime_error("Failed with creating dup2 to this file directories");
    return;
}

void closeFD(const int fd) {
    int closeFD_num = close(fd);

    if (closeFD_num == -1) throw std::runtime_error("Failed with closing fd");
    return;
}

int open_shm_file(const char* file_name) {
    int fd = shm_open(file_name, O_CREAT | O_RDWR, 0666);
    if (fd < 0) throw std::runtime_error("Failed with shared memory opening");

    int flag = ftruncate(fd, BUFFER_SIZE);
    if (flag < 0) throw std::runtime_error("Failed with ftruncate file");

    return fd;
}

void* create_shm_ptr(const int fd) {
    void* ptr = mmap(nullptr, BUFFER_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    if (ptr == MAP_FAILED) throw std::runtime_error("Failed with creting shared memory pointer");
    return ptr;
}

sem_t* open_semaphore(const char* semaphore_name, const int value) {
    sem_t* semaphore = sem_open(semaphore_name, O_CREAT | O_RDWR, 0666, value);

    if (semaphore == SEM_FAILED) throw std::runtime_error("Failed with opening semaphore");
    return semaphore;
}

void run_process(
                 const char* child_process, 
                 const char* file_name, 
                 const char* mmf_file_name, 
                 const char* mutex_name, 
                 const char* is_empty_sem_name, 
                 const char* is_full_sem_name
                 )
{
    int execl_num = execl(
                          child_process, 
                          child_process, 
                          file_name, 
                          mmf_file_name, 
                          mutex_name, 
                          is_empty_sem_name, 
                          is_full_sem_name, 
                          NULL
                          );

    if (execl_num == -1) throw std::runtime_error("Failed with run child process");
    return;
}

}; // namespace calls