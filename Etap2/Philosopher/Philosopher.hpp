//
// Created by Andrzej on 06.05.2022.
//

#ifndef ETAP2_PHILOSOPHER_HPP
#define ETAP2_PHILOSOPHER_HPP

#include <atomic>
#include "../Fork/Fork.hpp"
#include "../Table/Table.hpp"

enum PhilosopherState {
    NONE,
    THINKING,
    EATING,
    WAITING
};

class Philosopher {
    int id;
    Fork &left_hand;
    Fork &right_hand;
    Table &table;
    std::thread t;
    int progress_in_eating;
    std::atomic<PhilosopherState> philosopher_state = {WAITING};
    std::atomic<bool> is_living = {false};
    std::mutex mutex;
public:
    Philosopher(int id, Fork &leftHand, Fork &rightHand, Table &t);

    void eat();
    void think();
    void live();

    int getId() const;

    int getProgressInEating() const;

    Fork &getLeftHand() const;

    Fork &getRightHand() const;

    const std::atomic<PhilosopherState> &getPhilosopherState() const;

    void setIsLiving(const std::atomic<bool> &isLiving);
};


#endif //ETAP2_PHILOSOPHER_HPP
