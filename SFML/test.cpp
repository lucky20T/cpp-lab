#include<iostream>
using namespace std;


char Grade(); 

int main()
{
    Grade();
}

char Grade(){
    int math,cs,py;

    cout << "Enter marks of Math, CS, Python: ";
    cin >> math >> cs >> py;

    double total = ((math + cs + py)/3);

    if (total >= 90){
        cout << "Grade A" << endl;
    }
    else if (total >= 80){
        cout << "Grade B" << endl;
    }
    else if (total >= 70){
        cout << "Grade C" << endl;
    }
    else if (total >= 60){
        cout << "Grade D" << endl;
    }
    else {
        cout << "Grade F" << endl;
    }
}