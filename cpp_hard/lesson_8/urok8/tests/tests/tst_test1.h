#pragma once
#include <fstream>
#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "classes.h"

using namespace testing;

//Для тестирования создан отдельный проект(чтобы не засорять оснофной файл) и подключено все с первого урока

TEST(Class_Phonebook_test, test_getPhoneNumber_1) { // Правильность формирования вывода номера
    std::ifstream fin ("../Phonebook.txt"); // Открываем тот же файл, чтобы создавать отдельные методы, тем более в конструкторе у нас прописано создание объекта именно из файла
    if(!fin.is_open()){
        std::cerr << "File not found." << std::endl;
        ASSERT_EQ(0, 1);

    } else {
        PhoneBook book(fin);
        auto temp = book.getPhoneNumber("Ivanov");
        PhoneNumber ph = {7, 366, "7508887", std::nullopt};
        fin.close();
        ASSERT_TRUE(ph == std::get<1>(temp));
    }

}

TEST(Class_Phonebook_test, test_getPhoneNumber_2) { // Проверяем правильность возвращения первого ключа из пары
    std::ifstream fin ("../Phonebook.txt"); // Открываем тот же файл, чтобы создавать отдельные методы, тем более в конструкторе у нас прописано создание объекта именно из файла
    if(!fin.is_open()){
        std::cerr << "File not found." << std::endl;
        ASSERT_EQ(0, 1);

    } else {
        PhoneBook book(fin);
        auto temp = book.getPhoneNumber("Ivanov");
        fin.close();
        ASSERT_TRUE("" == std::get<0>(temp));
    }

}

TEST(Class_Phonebook_test, test_getPhoneNumber_3) { // Проверяем правильность возвращения первого ключа из пары, если найден
    std::ifstream fin ("../Phonebook.txt"); // Открываем тот же файл, чтобы создавать отдельные методы, тем более в конструкторе у нас прописано создание объекта именно из файла
    if(!fin.is_open()){
        std::cerr << "File not found." << std::endl;
        ASSERT_EQ(0, 1);

    } else {
        PhoneBook book(fin);
        auto temp = book.getPhoneNumber("Karpov");
        fin.close();
        ASSERT_TRUE("not found" == std::get<0>(temp));
    }

}

TEST(Class_Phonebook_test, test_getPhoneNumber_4) { // Проверяем правильность возвращения первого ключа из пары, если найдено более одной фамилии
    std::ifstream fin ("../Phonebook.txt"); // Открываем тот же файл, чтобы создавать отдельные методы, тем более в конструкторе у нас прописано создание объекта именно из файла
    if(!fin.is_open()){
        std::cerr << "File not found." << std::endl;
        ASSERT_EQ(0, 1);

    } else {
        PhoneBook book(fin);
        auto temp = book.getPhoneNumber("Solovev");
        fin.close();
        ASSERT_TRUE("found more than 1" == std::get<0>(temp));
    }

}

TEST(Class_Phonebook_test, test_getPhoneNumber_5) { // заведомо неправильный тест
    std::ifstream fin ("../Phonebook.txt"); // Открываем тот же файл, чтобы создавать отдельные методы, тем более в конструкторе у нас прописано создание объекта именно из файла
    if(!fin.is_open()){
        std::cerr << "File not found." << std::endl;
        ASSERT_EQ(0, 1);

    } else {
        PhoneBook book(fin);
        auto temp = book.getPhoneNumber("Solovev");
        fin.close();
        ASSERT_TRUE("" == std::get<0>(temp));
    }

}

TEST(Class_Phonebook_test, test_cahgePhoneNumber_1) { // Проверка метода cahgePhoneNumber на предмет изменения
    std::ifstream fin ("../Phonebook.txt"); // Открываем тот же файл, чтобы создавать отдельные методы, тем более в конструкторе у нас прописано создание объекта именно из файла
    if(!fin.is_open()){
        std::cerr << "File not found." << std::endl;
        ASSERT_EQ(0, 1);

    } else {
        PhoneBook book(fin);

        auto currentNum = book.getPhoneNumber("Ilin");
        std::cerr << "Old_number: " << std::get<1>(currentNum) << std::endl;
        PhoneNumber ph = {7, 17, "4559767", std::nullopt};
        PhoneNumber newNumber = {9, 22, "457597", 177};
        Person p = {"Ilin", "Petr", "Artemovich"};
        book.changePhoneNumber(p, newNumber);
        currentNum = book.getPhoneNumber("Ilin");
        fin.close();
        ASSERT_TRUE(newNumber == std::get<1>(currentNum));
    }

}

TEST(Class_Phonebook_test, test_cahgePhoneNumber_2) { // Проверка метода cahgePhoneNumber на предмет возвращаемого значения
    std::ifstream fin ("../Phonebook.txt"); // Открываем тот же файл, чтобы создавать отдельные методы, тем более в конструкторе у нас прописано создание объекта именно из файла
    if(!fin.is_open()){
        std::cerr << "File not found." << std::endl;
        ASSERT_EQ(0, 1);

    } else {
        PhoneBook book(fin);
        PhoneNumber newNumber = {9, 22, "457597", 177};
        Person p = {"Ilini", "Petr", "Artemovich"};
        bool b = book.changePhoneNumber(p, newNumber);
        fin.close();
        ASSERT_EQ(false, b);
    }

}

TEST(Struct_Person_test, test_operator_lt) { // Проверка оператора <
    Person p1 = {"Gerasimov", "Miroslav", "Stanislavovich"};
    Person p2 = {"Orekhov", "Matvei", "Petrovich"};
    ASSERT_TRUE(p1 < p2);
}

TEST(Struct_Person_test, test_operator_lt_2) { // Проверка оператора < Ложный тест
    Person p1 = {"Gerasimov", "Miroslav", "Stanislavovich"};
    Person p2 = {"Orekhov", "Matvei", "Petrovich"};
    ASSERT_TRUE(p2 < p1);
}

TEST(Struct_Person_test, test_operator_eq) { // Проверка оператора ==
    Person p1 = {"Gerasimov", "Miroslav", "Stanislavovich"};
    Person p2 = {"Gerasimov", "Miroslav", "Stanislavovich"};
    ASSERT_TRUE(p1 == p2);
}

TEST(Struct_PhoneNumber_test, test_operator_lt) { // Проверка оператора <
    PhoneNumber n1 = {9, 22, "457597", 177};
    PhoneNumber n2 = {10, 23, "457597", 177};
    ASSERT_TRUE(n1 < n2);
}

