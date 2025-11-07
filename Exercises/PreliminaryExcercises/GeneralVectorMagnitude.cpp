# include <iostream>
# include <cmath>

float x;
float y;
float z;

int main()
{
    std::cout << "Type the x value of the vector" << std::endl;
    std::cin >> x;

    std::cout << "Type the y value of the vector" << std::endl;
    std::cin >> y;

    z = sqrt(x*x + y*y);

    std::cout << "The magnitude of the vector is " << z << std::endl;
}

