#include <iostream>
#include <game.hpp>

int main(){
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    Game tower_defence;
    tower_defence.run();
    std::cout << "Im src exec-----------------------------------------" << std::endl;
    return 0;
}
