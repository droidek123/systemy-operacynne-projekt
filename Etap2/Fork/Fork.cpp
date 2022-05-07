//
// Created by Andrzej on 06.05.2022.
//

#include "Fork.hpp"

int Fork::getId() const {
    return id;
}

void Fork::setId(int id) {
    Fork::id = id;
}

Fork::Fork(int id) : id(id) {}

Fork::~Fork() {

}
