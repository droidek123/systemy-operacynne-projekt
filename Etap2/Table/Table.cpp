//
// Created by Andrzej on 06.05.2022.
//

#include "Table.hpp"

Table::Table(int amount_of_forks){
    for (int i = 0; i < amount_of_forks; i++)
        forks.emplace_back(i);
}

const std::atomic<bool> &Table::getIsReady() const {
    return is_ready;
}
