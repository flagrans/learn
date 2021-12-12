#include <iomanip>
#include <algorithm>
#include <fstream>
#include "include/classes.h"

Person::Person(std::string surname, std::string name, std::optional<std::string> patronymic)
    : mSurname{surname}, mName{name}, mPatronymic{patronymic} {}

bool Person::operator==(const Person &rhs) {
    return std::tie(mSurname, mName, mPatronymic) == std::tie(rhs.mSurname, rhs.mName, rhs.mPatronymic);
}

bool Person::operator<(const Person &rhs) {
    return std::tie(mSurname, mName, mPatronymic) < std::tie(rhs.mSurname, rhs.mName, rhs.mPatronymic);
}

std::ostream& operator<<(std::ostream &out, const Person &person) {
    out << std::setw(12) << person.mSurname << std::setw(12) << person.mName;

    if (person.mPatronymic) {
        out << std::setw(15) << *person.mPatronymic;
    } else {
        out << std::setw(15) << " ";
    }

    return out;
}



PhoneNumber::PhoneNumber(){}
PhoneNumber::PhoneNumber(int codeCountry, int codeCity, std::string number, std::optional<int> addNumber)
    : mCodeCountry{codeCountry}, mCodeCity{codeCity}, mNumber(number), mAddNumber{addNumber} {}

bool PhoneNumber::operator<(const PhoneNumber &rhs) {
    return std::tie(mCodeCountry, mCodeCity, mNumber, mAddNumber) < std::tie(rhs.mCodeCountry, rhs.mCodeCity, rhs.mNumber, rhs.mAddNumber);
}
bool PhoneNumber::operator==(const PhoneNumber &rhs) {
    return std::tie(mCodeCountry, mCodeCity, mNumber, mAddNumber) == std::tie(rhs.mCodeCountry, rhs.mCodeCity, rhs.mNumber, rhs.mAddNumber);
}

std::ostream& operator<<(std::ostream &out, const PhoneNumber &ph) {
    out << "+" << ph.mCodeCountry << "(" << ph.mCodeCity << ")" << ph.mNumber;
    if (ph.mAddNumber) out << " " << *ph.mAddNumber;
    return out;
}




PhoneBook::PhoneBook(std::ifstream & f) { // Понимаю, реализация немного кривая....
    std::string s;
    std::array<std::string, 5> c;
    while(getline(f, s)) {
        std::string temp = "";
        std::array<std::string, 7> c;
        int count = 0;
        for (const auto &it : s) {
            if(it != ' ') {
                temp.push_back(it);
            } else {
                c[count] = temp;
                count++;
                temp = "";
            }
        }
        c[count] = temp;
        auto no = std::nullopt;

        Person p(c[0], c[1], no);
        if (c[2] != "-") p.mPatronymic = c[2];

        PhoneNumber n(std::stoi(c[3]), std::stoi(c[4]), c[5], no);
        if (c[6] != "-") n.mAddNumber = std::stoi(c[6]);

        mMember.push_back(std::make_pair(p, n));
    }
}

bool PhoneBook::sortByName() {
    std::sort(mMember.begin(), mMember.end(),
              [](std::pair<Person, PhoneNumber> a, std::pair<Person, PhoneNumber> b) {return a.first < b.first;});
    return true;
}

bool PhoneBook::sortByPhone() {
    std::sort(mMember.begin(), mMember.end(),
              [](std::pair<Person, PhoneNumber> a, std::pair<Person, PhoneNumber> b) {return a.second < b.second;});
    return true;
}

std::tuple<std::string, PhoneNumber> PhoneBook::getPhoneNumber(const std::string &fam) const {
    int count = 0;
    PhoneNumber p;
    std::string s = "not found";
    std::for_each(mMember.begin(), mMember.end(), [&p, &fam, &count](std::pair<Person, PhoneNumber> par) mutable {
        if (par.first.mSurname == fam) {
            p = par.second;
            ++count;
        }
    });
    if (count == 1) s = "";
    else if(count > 1) s = "found more than 1";

    return tie(s, p);
}

bool PhoneBook::changePhoneNumber(const Person &person, const PhoneNumber &phonenumber) {
    auto it = std::find_if(mMember.begin(), mMember.end(), [&](std::pair<Person, PhoneNumber> par){return par.first == person;});
    if(it != mMember.end()) {
        (*it).second = phonenumber;
        return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream &out, const PhoneBook &book) {
    for (const auto &it : book.mMember) {
        out << it.first << "   " << it.second << std::endl;
    }
    return out;
}
