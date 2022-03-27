//
// Created by Andrzej on 26.03.2022.
//

#include <iostream>
#include <pthread.h>
#include <unistd.h>

void *fibonacci(void *numberOfThread) {
    long long n1 = 0;
    long long n2 = 1;
    long long n3 = 0;
    int n = rand() % 50;
    std::cout << "Watek numer " << (long) numberOfThread << ": Zaczyna prace" << std::endl;

    for (int i = 0; i < n; i++) {
        n3 = n1 + n2;
        n1 = n2;
        n2 = n3;
        std::cout << "Watek numer " << (long) numberOfThread << ": Obliczyl " << i << " z " << n
                  << " wyrazow do obliczenia" << std::endl;
        sleep(rand() % 4);

    }
    std::cout << "Watek numer " << (long) numberOfThread << ": Wartość" << n <<" wyrazu ciągu to " << n3 << std::endl;
    std::cout << "Watek numer " << (long) numberOfThread << ": Zakonczyl prace" << std::endl;
    return nullptr;
}


int main(int argc, char **argv) {
    int result_code;
    int threadNumber = std::stoi(argv[1]);

    pthread_t t[threadNumber];
    for (int i = 0; i < threadNumber; i++) {
        result_code = pthread_create(&t[i], nullptr, fibonacci, (void *) i);
        if (result_code) {
            std::cout << "Bład podczas tworzenia watku" << std::endl;
            return -1;
        }
    }

    for (int i = 0; i < threadNumber; i++) {
        result_code = pthread_join(t[i], nullptr);
        if (result_code) {
            std::cout << "Bład podczas konczenia watku" << std::endl;
            return -1;
        }
        std::cout << "Poprawnie zakonczony watek " << i << std::endl;
    }
    std::cout << "Koniec Programu!" << std::endl;
    return 0;
}