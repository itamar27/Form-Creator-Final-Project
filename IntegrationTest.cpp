#include "./View/CLI.h"

int main() {
    CLI* myCLI = new CLI(std::cout, std::cin);

    myCLI->start();

    return 0;
}