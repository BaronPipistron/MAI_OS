#include "../../include/calls/calls.h"

namespace calls {

pid_t create_process() {
    pid_t pid = fork();

    if (pid == -1) throw std::runtime_error("Failed with creating child process");
    return pid;
}

int open_file(const char* file_name) {
    int file = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

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

void create_pipe(int* fd) {
    int pipe_num = pipe(fd);
    
    if (pipe_num == -1) throw std::runtime_error("Failed with creating pipe");
    return;
}

void run_process(const char* child_process, const char* file_name, const char* mmf_file_name, const char* mutex_name, const char* is_empty_sem_name, const char* is_full_sem_name) {
    int execl_num = execl(child_process, child_process, file_name, mmf_file_name, mutex_name, is_empty_sem_name, is_full_sem_name, NULL);

    if (execl_num == -1) throw std::runtime_error("Failed with run child process");
    return;
}

int open_shm_file(const char* file_name) {
  int fd = shm_open(file_name, O_CREAT | O_RDWR, 0777);
   
  if (fd < 0) {
    throw std::runtime_error("error shm_open in func open_shm_file!");
  }

  int flag = ftruncate(fd, BUFFER);

  if (flag < 0) {
    throw std::runtime_error("error ftruncate in open_shm_file!");
  }

  return fd;
}

void* create_shm_ptr(int fd) {
  void* ptr = mmap(nullptr, BUFFER, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

  if (ptr == MAP_FAILED) {
    throw std::runtime_error("error mmap in create_shm_ptr!");
  }

  return ptr;
}

sem_t* open_semaphore(const char* sem_name, int value) {
  sem_t* sem = sem_open(sem_name, O_CREAT | O_RDWR, 0777, value);

  if (sem == SEM_FAILED) {
    throw std::runtime_error("error sem_open in open_semaphore");
  }

  return sem;
}

}; // namespace calls