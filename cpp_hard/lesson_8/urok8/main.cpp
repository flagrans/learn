#include <iostream>
#include <fstream>
#include <tuple>
#include "include/classes.h"

int main (){
// Task 1
    {
        std::cout << "********** Task 1 **********" << std::endl;

        std::ifstream fin ("Phonebook.txt");
        if(!fin.is_open()){
            std::cout << "File not found." << std::endl;

        } else {
            PhoneBook book(fin);
            std::cout << book;

            std::cout << "------SortByName--------" << std::endl;
            book.sortByName();
            std::cout << book;

            std::cout << "------SortByPhone--------" << std::endl;
            book.sortByPhone();
            std::cout << book;

            std::cout << "------GetPhoneNumber--------" << std::endl;
            auto print_phone_number = [&book](const std::string& surname) {
                std::cout << surname << "\t";
                auto answer = book.getPhoneNumber(surname);
                if (std::get<0>(answer).empty())
                    std::cout << std::get<1>(answer);
                else
                    std::cout << std::get<0>(answer);
                std::cout << std::endl;
            };
            print_phone_number("Ivanov");
            print_phone_number("Petrov");
            print_phone_number("Solovev");

            std::cout << "------ChangePhoneNumber--------" << std::endl;
            book.changePhoneNumber(Person{"Kotov", "Vasilii", "Eliseevich"}, PhoneNumber{7, 123, "15344458", std::nullopt});
            book.changePhoneNumber(Person{"Mironova", "Margarita", "Vladimirovna"}, PhoneNumber{ 16, 465, "9155448", 13 });
            std::cout << book;
        }





        std::cout << "****************************" << std::endl;
        std::cout << std::endl << std::endl;
    }

    return 0;
}
