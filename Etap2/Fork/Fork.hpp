//
// Created by Andrzej on 22.05.2022.
//

#ifndef ETAP2_FORK_HPP
#define ETAP2_FORK_HPP

#include <mutex>

using namespace std;

class Fork {
    string id;
public:
    mutex mtx;
    Fork();
};

#endif //ETAP2_FORK_HPP
