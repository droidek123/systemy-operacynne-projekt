//
// Created by Andrzej on 22.05.2022.
//

#ifndef ETAP2_PHILOSOPHER_HPP
#define ETAP2_PHILOSOPHER_HPP

#include <random>
#include <thread>
#include "../Fork/Fork.hpp"

using namespace std;

class Philosopher {

    string name;
    int appetite;
    int food_eaten;
    Fork &left_fork;
    Fork &right_fork;
    thread td;
    mutex &g_lock;
    mt19937 rng{random_device{}()};
    bool stopped;

public:
    Philosopher(string, int, Fork &, Fork &, mutex &);
    ~Philosopher();
    void eat();
    void think();
    void randomize(int, int);
    void print(const string &);
    void stop();
    void run();
    void join();
};


#endif //ETAP2_PHILOSOPHER_HPP
