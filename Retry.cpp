#include <iostream>
#include <vector>
// using namespace std;

int main(int argc, char* argv[]) {
    std::vector<int> vec;
    vec.push_back(20);
    vec.push_back(29);
    vec.push_back(30);
    for (size_t i = 0; i < vec.size();++i)
    {
        std::cout << vec[i] <<"\n";
    }
    return 0;
}