//
// Created by Andrzej on 22.05.2022.
//

#include <array>
#include <iostream>
#include <mutex>
#include <csignal>


#include "Philosopher/Philosopher.hpp"

using namespace std;

array<Philosopher *, 5> philosophers;
array<Fork *, 5> forks;

mutex global_lock;

array<string, 5> names = {"Plato", "Socrates", "Kant", "Descartes", "Confucius"};

array<string, 6> colors = {
        "\033[31m", // red
        "\033[33m", // yellow
        "\033[32m", // green
        "\033[34m", // blue
        "\033[35m", // purple
        "\033[00m", // white
};

void quit(int s) {
    for (Philosopher *p: philosophers)
        p->stop();
    cout << "\nDinner is over. Letting philosophers finish up..." << endl;
}

int main() {
    cout << "Dinner is served! (Ctl+C to end)" << endl;

    for (auto &fork: forks)
        fork = new Fork();

    cout << "\nPhilosophers: " << endl;
    for (int i = 0; i < names.size(); i++) {
        int rf = (i + 1) % (int)names.size();
        philosophers[i] = new Philosopher(colors[i] + names[i] + colors[5], 5, *forks[i], *forks[rf],
                                          global_lock);
    }
    cout << endl << endl;

    signal(SIGINT, quit);

    for (Philosopher *p: philosophers)
        p->join();

    return 0;
}
