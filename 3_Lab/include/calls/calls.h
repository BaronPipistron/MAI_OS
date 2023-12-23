#pragma once

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>
#include <string>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/mman.h>

#define BUFFER 16

namespace calls {

[[nodiscard]] pid_t create_process();

[[nodiscard]] int open_file(const char*);

void create_dup2FD(const int, const int);

void closeFD(const int);

void run_process(const char* child_process, const char* file_name, const char* mmf_file_name, const char* mutex_name, const char* is_empty_sem_name, const char* is_full_sem_name);

int open_shm_file(const char* file_name);

void* create_shm_ptr(int fd);

sem_t* open_semaphore(const char* sem_name, int value);

}; // namespace calls