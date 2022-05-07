//
// Created by Andrzej on 06.05.2022.
//

#ifndef ETAP2_TABLE_HPP
#define ETAP2_TABLE_HPP


#include <vector>
#include <atomic>
#include "../Fork/Fork.hpp"

class Table {
    std::vector<Fork> forks;
    std::atomic<bool> is_ready;

public:
    explicit Table(int amountOfForks);

    const std::atomic<bool> &getIsReady() const;
};


#endif //ETAP2_TABLE_HPP
