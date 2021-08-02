#include <iostream>
#include <sstream>

using namespace std;

// 2 task
ostream &endll (ostream &out) {
    cout << "\n" << endl;
return out;
}

int main(){
    std::cout << "***************" << std::endl;
// 1 task
    std::cout << "Task 1:" << std::endl << "-------" << std::endl;

    cout << "Enter integer number: ";
    string st;
    cin >> st;
    stringstream myString;
    myString << st;
    int iValue = 1;
    string sValue="";
    if (myString >> iValue) {
        myString >> sValue;
        if (sValue == "") {

        } else {
            cerr << "Error" << endl;
            return 1;
        }
    } else {
        cerr << "Error" << endl;
        return 1;
    }
    cout << "You number: " << iValue << endl;

    std::cout << "***************" << std::endl;
// 2 task
    std::cout << "Task 2:" << std::endl << "-------" << std::endl;

    cout << endll;

    std::cout << "***************" << std::endl;

    return 0;
}
