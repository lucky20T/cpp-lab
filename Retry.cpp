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
    std::cout << "----\n";
    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it << "\n";   
    }
    std::cout << "----\n";
    for (int val : vec)
    {
        std::cout << val << "\n";   
    }
    std::cout << "----\n";
    for(auto val:vec)
    {
        std::cout << val << "\n";   
    }
    return 0;
}