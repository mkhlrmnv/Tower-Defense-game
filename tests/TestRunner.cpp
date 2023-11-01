#include <iostream>

int main() {
    // Run your tests here
    std::cout << "Running ObjectTests..." << std::endl;
    int objectTestsResult = system("ObjectTests");

    // You can add more test runners for other classes in your project.

    if (objectTestsResult == 0) {
        std::cout << "All tests passed." << std::endl;
    } else {
        std::cout << "Some tests failed." << std::endl;
    }

    return objectTestsResult;
}
