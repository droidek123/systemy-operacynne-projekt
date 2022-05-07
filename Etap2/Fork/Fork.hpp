//
// Created by Andrzej on 06.05.2022.
//

#ifndef ETAP2_FORK_HPP
#define ETAP2_FORK_HPP

#include <mutex>


class Fork {
    int id;

public:

    std::mutex mut;

    Fork(int id);

    virtual ~Fork();

    int getId() const;

    void setId(int id);
};


#endif //ETAP2_FORK_HPP
