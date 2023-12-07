.PHONY: build run clean strace unlink-shm

build: clean
	mkdir build
	cd ./build; cmake ..; make all

run:
	./build/*_run_exe
	
clean:
	rm -rf ./build/

strace:
	strace -f ./build/*_run_exe

unlink-shm:
	rm /dev/shm/*lab3*