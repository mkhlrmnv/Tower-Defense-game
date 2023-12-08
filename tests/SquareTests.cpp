<<<<<<< HEAD
#include "square.hpp"
#include "tower.hpp"
#include <iostream>
=======
// #include "square.hpp"
// #include <iostream>
>>>>>>> bc314f0c80edd1a43211ae786e65d3543ca5d1d9

// bool testCenter(){
//     Vector2D cent(2, 3);
//     Square sq(cent);
//     return sq.get_center() == cent;
// }

<<<<<<< HEAD
bool testOccupied(){
    Vector2D cent(2, 3), cent2(4, 5), cent3(6, 7);
    Square sq(cent), sq2(cent2), sq3(cent3);
    sq.occupy_by_grass();
    sq2.occupy_by_road();
    sq3.occupy_by_tower();
    return sq.get_occupied() == grass && sq2.get_occupied() == road && sq3.get_occupied() == tower;
}
=======
// bool testOccupied(){
//     Vector2D cent(2, 3), cent2(4, 5), cent3(6, 7);
//     Square sq(cent), sq2(cent2), sq3(cent3);
//     sq.occupy_by_grass();
//     sq2.occupy_by_road();
//     sq3.occupy_by_tower();
//     return sq.get_occupied() == grass && sq2.get_occupied() == road && sq3.get_occupied() == tower;
// }

// static int square_test() {
//     int fails = 0;
>>>>>>> bc314f0c80edd1a43211ae786e65d3543ca5d1d9

//     if (testCenter()){
//         std::cout << "testCenter: Passed" << std::endl;
//     } else {
//         std::cout << "testCenter: Failed" << std::endl;
//         fails++;
//     }

//     if (testOccupied()){
//         std::cout << "testOccupied: Passed" << std::endl;
//     } else {
//         std::cout << "testOccupied: Failed" << std::endl;
//         fails++;
//     }

//     if (fails == 0){
//         std::cout << "All Square test passed" << std::endl;
//     } else {
//         std::cout << fails << " Square test failed" << std::endl;
//     }

<<<<<<< HEAD
    if (fails == 0){
        std::cout << "All Square test passed" << std::endl;
    } else {
        std::cout << fails << " Square test failed" << std::endl;
    }

    return fails;
}
=======
//     return fails;
// }
>>>>>>> bc314f0c80edd1a43211ae786e65d3543ca5d1d9
