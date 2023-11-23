/*************************************************************************
        > File Name: test.cpp
        > Author: tml
        > Mail: 3200035928@qq.com
        > Created Time: 2023年11月19日 星期日 11时19分11秒
 ************************************************************************/
#include <iostream>
#include <string>

int main() {
    std::string line;
    std::cout << "Please enter a line of text: ";
    std::getline(std::cin, line);
    std::cout << "You entered: " << line << std::endl;
    return 0;
}
