/******************************************************************************

                              It is C++ 17 code, that fill both containers with
                              random numbers and delete unique elements
                              in STL containers (map & vector)

*******************************************************************************/

#include <ctime>
#include "ContainerController.h"

int main()
{
    std::srand(static_cast<int>(time(NULL)));
    std::vector<int> vec;
    vec.resize(30);
    std::map<int, int> m;
    ContainerController container_controller;

    container_controller.FillRandomNumbers(vec);
    container_controller.FillRandomNumbers(m);

    std::cout << "\nVector numbers:\n";
    container_controller.PrintContainer(vec);
    std::cout << "\nMap numbers:\n";
    container_controller.PrintContainer(m);
    std::cout << std::endl;

    container_controller.DeleteRandomCountOfElements(vec);
    std::cout << "Vector after delete:\n";
    container_controller.PrintContainer(vec);
    std::cout << "\nvector size = " << vec.size() << "\n\n";

    container_controller.DeleteRandomCountOfElements(m);
    std::cout << "Map after delete:\n";
    container_controller.PrintContainer(m);
    std::cout << "\nmap size = " << m.size() << "\n\n";

    container_controller.DeleteUniqueElements(vec, m);
    
    std::cout << "VECTOR after delete UNIQUE elements:\n";
    container_controller.PrintContainer(vec);
    std::cout << "MAP after delete UNIQUE elements:\n";
    container_controller.PrintContainer(m);

    return 0;
}
