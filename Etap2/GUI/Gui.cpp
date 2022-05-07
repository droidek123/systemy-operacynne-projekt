//
// Created by Andrzej on 06.05.2022.
//

#include "Gui.hpp"
#include <ncurses.h>
#include <cmath>
#include <thread>

Gui::Gui() {
    initscr();
    noecho();
    raw();
    nodelay(stdscr, TRUE);
    start_color();
    use_default_colors();
    curs_set(0);
    init_pair(1, COLOR_MAGENTA, -1);
    init_pair(2, COLOR_GREEN, -1);
    init_pair(3, COLOR_RED, -1);
    getmaxyx(stdscr, col, row);
    x = row / 2 - max_len;
    y = col / 2;
}

Gui::~Gui() {
    endwin();
}

void Gui::start() {

}

void Gui::update_particular(Philosopher *p) {
    int id = p->getId();
    PhilosopherState state = p->getPhilosopherState();
    std::lock_guard<std::mutex> guard(m);
    move(y + id - 10, 0);
    clrtoeol();
    move(y + id - 10, x);
    if (state == 2) {
        attron(COLOR_PAIR(3));
        printw("Philosopher %d is %s", id, states[state]);
    } else {
        int progress = p->getProgressInEating();
        int lpad = (int)std::round((float)progress / 100.0f * LENGTH);
        int rpad = LENGTH - lpad;
        attron(COLOR_PAIR(state + 1));
        if (p->getPhilosopherState()==0){
            printw("Philosopher %d is %s            %3d%% [%.*s%*s]", id, states[state],
                   progress, lpad, PBAR, rpad, "");
        } else{
            printw("Philosopher %d is %s              %3d%% [%.*s%*s]", id, states[state],
                   progress, lpad, PBAR, rpad, "");
        }

        if (p->getPhilosopherState()==0){
            attron(COLOR_PAIR(2));
            move(y + p->getLeftHand().getId() - 8 + 10 , 0);
            clrtoeol();
            move(y + p->getLeftHand().getId() - 8 + 10 , x);
            printw("Widelec nr  %d jest wolny", p->getLeftHand().getId()+1);

            move(y + p->getRightHand().getId() - 8 + 10 , 0);
            clrtoeol();
            move(y + p->getRightHand().getId() - 8 + 10 , x);
            printw("Widelec nr  %d jest wolny", p->getRightHand().getId()+1);
        } else {
            attron(COLOR_PAIR(3));
            move(y + p->getLeftHand().getId() - 8 + 10 , 0);
            clrtoeol();
            move(y + p->getLeftHand().getId() - 8 + 10 , x);
            printw("Widelec nr  %d jest zajety", p->getLeftHand().getId()+1);

            move(y + p->getRightHand().getId() - 8 + 10 , 0);
            clrtoeol();
            move(y + p->getRightHand().getId() - 8 + 10 , x);
            printw("Widelec nr  %d jest zajety", p->getRightHand().getId()+1);
        }
    }
    refresh();
}

void Gui::update(std::vector<Philosopher *> philosophers) {
    while (true) {
        int c = getch();
        if (c == 113) {
            // Wyjście z programu
            for (auto phil : philosophers) {
                phil->setIsLiving(true);
            }
            return;
        }
        std::vector<std::thread> v;
        for (auto p : philosophers) {
            v.emplace_back(std::thread(&gui::update_particular, this, p));
        }

        for (auto &p : v) {
            p.join();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

void Gui::update_state(int id, const char *state, int progress) {

}
