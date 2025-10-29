#include <iostream>
#include <vector>
// using namespace std;
class Student
{   std::string m_first = "first";
    std::string m_last  = "last";
    int         m_age   = 0;
    int         m_id    = 0;


    public:

    Student(std::string first, std::string last, int age, int id)
        :m_first(first),
         m_last(last), 
         m_age(age), 
         m_id(id)
    {

    }

    int getAge()
    {
        return m_age;
    }
    std::string getFirst()
    {
        return m_first;
    }
    std::string getLast()
    {
        return m_last;
    }
    int getId()
    {
        return m_id;
    }
};

int main(int argc, char* argv[])
{
    std::vector<Student> students;
    students.emplace_back("John", "Doe", 20, 1);
    students.emplace_back("Jane", "Smith", 22, 2);
    students.emplace_back("Alice", "Johnson", 19, 3);

    for (const auto& student : students)
    {
        std::cout << "ID: " << student.getId() 
                  << ", Name: " << student.getFirst() << " " << student.getLast() 
                  << ", Age: " << student.getAge() << "\n";
    }

    return 0;
}

// int main(int argc, char* argv[]) {
//     std::vector<int> vec;
//     vec.push_back(20);
//     vec.push_back(29);
//     vec.push_back(30);
//     for (size_t i = 0; i < vec.size();++i)
//     {
//         std::cout << vec[i] <<"\n";
//     }
//     std::cout << "----\n";
//     for (auto it = vec.begin(); it != vec.end(); ++it)
//     {
//         std::cout << *it << "\n";   
//     }
//     std::cout << "----\n";
//     for (int val : vec)
//     {
//         std::cout << val << "\n";   
//     }
//     std::cout << "----\n";
//     for(auto val:vec)
//     {
//         std::cout << val << "\n";   
//     }
//     return 0;
// }