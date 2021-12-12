#pragma once
#include <vector>
#include <optional>
#include <iostream>


struct Person {
public:
    Person(std::string surname, std::string name, std::optional<std::string> patronymic);

    bool operator==(const Person &rhs);
    bool operator<(const Person &rhs);
    friend class PhoneBook;
    friend std::ostream& operator<<(std::ostream &out, const Person &person);

private:
    std::string mSurname;
    std::string mName;
    std::optional<std::string> mPatronymic;

};

struct PhoneNumber {
public:
    PhoneNumber();
    PhoneNumber(int codeCountry, int codeCity, std::string number, std::optional<int> addNumber);

    bool operator<(const PhoneNumber &rhs);
    bool operator==(const PhoneNumber &rhs);

    friend std::ostream& operator<<(std::ostream &out, const PhoneNumber &person);
    friend class PhoneBook;
private:
    int mCodeCountry = 0;
    int mCodeCity = 0;
    std::string mNumber = "";
    std::optional<int> mAddNumber = std::nullopt;

};

typedef std::vector<std::pair<Person, PhoneNumber>> pairVector;

class PhoneBook {
public:
    PhoneBook(std::ifstream & f);

    bool sortByName();

    bool sortByPhone();

    std::tuple<std::string, PhoneNumber> getPhoneNumber(const std::string &fam) const;

    bool changePhoneNumber(const Person &person, const PhoneNumber &phonenumber);


    friend std::ostream& operator<<(std::ostream &out, const PhoneBook &book);
private:
    pairVector mMember;
};
