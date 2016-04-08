// CSE 101 Winter 2016, PA 1
//
// Name: TODO put both partners' info if applicable
// PID: TODO
// Sources of Help: TODO
// Due: 1/22/2016 at 11:59 PM

#include <iostream>
#include <chrono>
#include <list>
#include <stdlib.h>

// you can change SIZE to vary the size of array
#define SIZE 1000

// returns the index of the element found in the list
int naive_search(int * list, int e) {
    // TODO implement naive search
    return -1;
}

// returns the index of the found element
int DQ_search(int * list, int e) {
    // TODO implement DQ search
    // you may want to implement a recursive helper method
    return -2;
}

// This main is already fully implemented. However, you are free
// to modify it if you feel necessary (i.e. running multiple queries
// for larger array sizes instead of running one query per run)
int main(int argc, char * argv[]) {
    std::cout << "Running Rotated Sorted Array with size: " << SIZE << std::endl;
    int * arr = new int[SIZE];

    // build the rotated array using the random rotation point
    srand(time(0));
    int rotation = rand() % SIZE;
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = (i + rotation) % SIZE + 1;
    }

    int target = rand() % SIZE + 1;

    // time the naive approach
    auto begin = std::chrono::high_resolution_clock::now();

    int loc_naive = naive_search(arr, target);

    auto end = std::chrono::high_resolution_clock::now();

    int elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count();

    std::cout << "Time for Naive Search: " << elapsed_time << "ms" << std::endl;

    // time the DQ approach
    begin = std::chrono::high_resolution_clock::now();

    int loc_DQ = DQ_search(arr, target);

    end = std::chrono::high_resolution_clock::now();

    elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count();

    std::cout << "Time for DQ Search: " << elapsed_time << "ms" << std::endl;

    if (loc_naive != loc_DQ) {
        std::cout << "ERROR, indicies returned by naive and DQ do not match." << std::endl;
    }
    if (target != arr[loc_naive]) {
        std::cout << "ERROR, index found by naive does not match target." << std::endl;
    }
    if (target != arr[loc_DQ]) {
        std::cout << "ERROR, index found by DQ does not match target." << std::endl;
    }

    delete arr;
    return 0;
}
