#include "LevelTests.cpp"
#include "SquareTests.cpp"

int main(){
    int fails = 0;
    std::cout << "\n" <<"RUNNING LEVEL TEST ----------------------------------" << "\n" << std::endl;
    fails += level_test();

    std::cout << "\n" <<"RUNNING SQUARE TEST ----------------------------------" << "\n" << std::endl;
    fails += square_test();

    std::cout << "\n" <<"TEST FINISHED WITH: " << fails << " ERRORS" << "\n" << std::endl;

    return 0;
}