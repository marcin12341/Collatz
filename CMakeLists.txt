cmake_minimum_required(VERSION 3.10)
project(Collatz)

set(CMAKE_CXX_STANDARD 11)

add_executable(Collatz main.cpp MinHeap.cpp MinHeap.h MaxHeap.cpp MaxHeap.h Heap.cpp Heap.h)