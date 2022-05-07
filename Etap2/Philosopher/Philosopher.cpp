//
// Created by Andrzej on 06.05.2022.
//

#include <thread>
#include "Philosopher.hpp"

void Philosopher::live() {
    while (!table.getIsReady()) {
        std::this_thread::yield();
    }
    while(!is_living) {
        think();
        this->philosopher_state = WAITING;
        eat();
    }
}

void Philosopher::eat() {
    std::lock(left_hand.mut, right_hand.mut);
    std::lock_guard<std::mutex> unlock_left (left_hand.mut, std::adopt_lock);
    std::lock_guard<std::mutex> unlock_right (right_hand.mut, std::adopt_lock);
    philosopher_state = EATING;
    srand (time(nullptr));
    int random_number = rand() % 100;
    for (int i = 0; i < random_number; i++) {
        if(is_living)
            return;
        progress_in_eating = (i/random_number)*100;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void Philosopher::think() {
    philosopher_state = THINKING;
    srand (time(nullptr));
    int r = rand() % 100;
    for (int i = 0; i < r; i++) {
        if (is_living)
            return;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

Philosopher::Philosopher(int id, Fork &leftHand, Fork &rightHand, Table &t) : id(id), left_hand(leftHand),
                                                                                          right_hand(rightHand),
                                                                                          table(t), t(&Philosopher::live ,this) {}

int Philosopher::getProgressInEating() const {
    return progress_in_eating;
}

int Philosopher::getId() const {
    return id;
}

const std::atomic<PhilosopherState> &Philosopher::getPhilosopherState() const {
    return philosopher_state;
}

Fork &Philosopher::getLeftHand() const {
    return left_hand;
}

Fork &Philosopher::getRightHand() const {
    return right_hand;
}

void Philosopher::setIsLiving(const std::atomic<bool> &isLiving) {
    is_living = isLiving;
}

