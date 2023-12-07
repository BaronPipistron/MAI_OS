#pragma once

#include <iostream>
#include <string>
#include <fcntl.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <unistd.h>

#define BUFFER_SIZE 16

namespace calls {

[[nodiscard]] pid_t create_process();
[[nodiscard]] int open_file(const char*);

void create_dup2FD(const int, const int);
void closeFD(const int);

int open_shm_file(const char*);
void* create_shm_ptr(const int);

sem_t* open_semaphore(const char*, const int);

void run_process(
                 const char*, 
                 const char*, 
                 const char*, 
                 const char*, 
                 const char*, 
                 const char*
                 );
}; // namespace calls