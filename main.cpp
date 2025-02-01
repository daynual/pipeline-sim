#include <cstddef>
#include <iostream>
#include <pthread.h>

using namespace std;

#define NUM_STAGES 5

void* fetch(void* arg) {
    int number = *static_cast<int*>(arg);
    cout << "Task: " << number << endl;
    pthread_exit(NULL);
}

void* decode(void* arg) {
    int number = *static_cast<int*>(arg);
    cout << "Task: " << number << endl;
    pthread_exit(NULL);
}

void* execute(void* arg) {
    int number = *static_cast<int*>(arg);
    cout << "Task: " << number << endl;
    pthread_exit(NULL);
}

void* readback(void* arg) {
    int number = *static_cast<int*>(arg);
    cout << "Task: " << number << endl;
    pthread_exit(NULL);
}

void* writeback(void* arg) {
    int number = *static_cast<int*>(arg);
    cout << "Task: " << number << endl;
    pthread_exit(NULL);
}

int main() {
    int nums[5] = {0, 1, 2, 3, 4};

    // static array of threads and array of thread's func pointers
    pthread_t threads[NUM_STAGES];
    void* (*stages[NUM_STAGES])(void*) = {fetch, decode, execute, readback, writeback};


    // init threads
    for(int i = 0; i < NUM_STAGES; i++) {
        if(pthread_create(&threads[i], nullptr, stages[i], &nums[i])) {
            cerr << "Error creating thread" << endl;
            return 1;
        }
    }

    for(int i = 0; i < NUM_STAGES; i++) {
        if(pthread_join(threads[i], nullptr) != 0) {
            return 1;
        }
    }

    return 0;
}
