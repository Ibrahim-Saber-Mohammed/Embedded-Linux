#include <iostream>
#include "MathLib.hpp"


int main(int argc, char * argv[])
{
    
    auto l = Lib::min(4,5,-110,-200,6,-1.5, 0.25);
    auto h = Lib::max(4,5,-110,2,-6,1.5,0.25);
    auto M = Lib::max(4);
    auto m = Lib::min(4);
    std::cout << "Lib::min = "<< l << "\n";
    std::cout << "Lib::max = "<< h << "\n";
    std::cout << "Lib::max = "<< M << "\n";
    std::cout << "Lib::min = "<< m << "\n";
    return 0;
}