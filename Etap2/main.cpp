#include <iostream>
#include "Table/Table.hpp"
#include "GUI/Gui.hpp"
#include "Philosopher/Philosopher.hpp"

int main(int argc, char **argv) {
    if (argc != 1) {
        std::cout << "Zla liczba argumentow" << std::endl;
        return 1;
    }

    int numberOfPhilosophers = (int)strtol(argv[1], nullptr, 10);

    Table table(numberOfPhilosophers);
    Gui gui;
    std::vector<Philosopher> philosophers;
    for (int i = 0; i < numberOfPhilosophers; i++) {

    }

}
