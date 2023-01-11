#include <iostream>
#include "Arkanoid.h"
#include <iostream>
#include <sstream>
#include <fstream>
void set_raw(bool set) {
    if (set) {
        system("stty raw");  // enable raw
    } else {
        system("stty -raw"); // disable raw
    }
}
int main(int argc, char *argv[]) {
    if(argc<2) {
        printf("Usage: %s {random|filepath}", argv[0]);
        return 1;
    }

    set_raw(true);
    auto ss=std::ifstream(argv[1]);
    std::istream* is=&ss;
    auto ark=Arkanoid(new Map(*is));
    printf("\n\r");
    auto inputThread = [](Arkanoid& a) {
        std::cout << "\rStart input thread\n";
        a.control();
        std::cout << "\rExit input thread\n";
    };
    auto computeThread = [](Arkanoid& a) {
        std::cout << "\rStart compute thread\n";
        a.run();
        std::cout << "\rExit compute thread\n";
    };
    auto outputThread = [](Arkanoid& a) {
        std::cout << "\rStart output thread\n\r";
        a.print();
        std::cout << "\rExit output thread\n";
    };
    std::thread t1(inputThread, std::ref(ark));
    std::thread t2(computeThread, std::ref(ark));
    std::thread t3(outputThread, std::ref(ark));
    t1.join();
    t2.join();
    t3.join();

    set_raw(false);

    std::cout << "\rExit main thread\n";

    return 0;
}
