//
// Created by Andrzej on 22.05.2022.
//

#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>
#include <utility>
#include "Philosopher.hpp"

using namespace std;

Philosopher::Philosopher(string name, int appetite, Fork &l_fork, Fork &r_fork, mutex &g_lock)
        : name(std::move(name)), appetite(appetite), left_fork(l_fork), right_fork(r_fork),
          g_lock(g_lock),
          td(&Philosopher::run, this) {

    food_eaten = 0;
    stopped = false;
    print("has joined");
}

Philosopher::~Philosopher() {
    print("is finished");
}

void Philosopher::eat() {
    lock_guard<mutex> lc(left_fork.mtx);
    lock_guard<mutex> rc(right_fork.mtx);

    print("is eating (" + to_string(++food_eaten) + "/" + to_string(appetite) + ")");
    randomize(3, 5);
}

void Philosopher::think() {
    print("is thinking");
    randomize(2, 4);
}

void Philosopher::randomize(int min_sec, int max_sec) {
    if (stopped) return;
    thread_local uniform_int_distribution<> dist(min_sec, max_sec);
    int t = dist(rng);
    this_thread::sleep_for(chrono::milliseconds(t * 1000));
    if (food_eaten >= appetite) stopped = true;
}

void Philosopher::print(const string &str) {
    lock_guard<mutex> lock(g_lock);
    cout << name << " " << str << endl;
}

void Philosopher::stop() {
    stopped = true;
}

void Philosopher::run() {
    this_thread::sleep_for(chrono::milliseconds(1000));

    while (!stopped) {
        think();
        if (stopped) break;
        eat();
    }
    print("is finished");
}

void Philosopher::join() {
    td.join();
}
