//
// Created by Andrzej on 06.05.2022.
//

#ifndef ETAP2_GUI_HPP
#define ETAP2_GUI_HPP

#define PBAR "##################################################"
#define LENGTH 50

#include <mutex>
#include <map>
#include "../Philosopher/Philosopher.hpp"

class Gui {
    int row;
    int col;
    int x;
    int y;
    const int max_len = 46;
    std::mutex m;
    std::map<int, const char *> states = {
            std::pair<int, const char *>(-1, "waiting for dining_table"),
            std::pair<int, const char *>(0, "thinking"),
            std::pair<int, const char *>(1, "eating"),
            std::pair<int, const char *>(2, "waiting for forks")};
public:
    Gui();

    virtual ~Gui();

    void start();
    void update_particular(Philosopher *p);
    void update(std::vector<Philosopher *> philosophers);
};


#endif //ETAP2_GUI_HPP
