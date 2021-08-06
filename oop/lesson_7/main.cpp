#include <iostream>
#include <memory>

using namespace std;

// 1 task
template<typename T>
class SPointer {
    T *pointer;
public:
    SPointer(T *ptr) {
        pointer = ptr;
    }
    ~SPointer() {
        if (pointer != nullptr) delete pointer;
    }
    T& operator*() {
        return *pointer;
    }
    bool operator==(T *ptr) const {
      return pointer == ptr;
    }
    T* operator=(T *ptr) {
        pointer = ptr;
        return pointer;
    }
};

class Date
{
private:
    int day;
    int mouth;
    int year;

public:
    Date(int m_day=1, int m_mouth=1, int m_year=2000): day(m_day), mouth(m_mouth), year(m_year) { }
    int getDay () const;
    int getMouth () const;
    int getYear () const;
    void setDay (int);
    void setMouth (int);
    void setYear (int);
    friend ostream& operator<< (ostream &out, const Date &date);
};

int Date::getDay() const { return day; }
int Date::getMouth() const { return mouth; }
int Date::getYear() const { return year; }

void Date::setDay(int m_day) { day = m_day; }
void Date::setMouth(int m_mouth) { mouth = m_mouth; }
void Date::setYear(int m_year) { year = m_year; }

ostream& operator<< (ostream &out, const Date &date)
{
    out << date.day << "." << date.mouth << "." << date.year;
    return out;
}

// 2 task
template<typename T>
SPointer<T>& func(SPointer<T>& t1, SPointer<T>& t2) {
    if ((*t1).getYear() == (*t2).getYear()) {
        if ((*t1).getMouth() == (*t2).getMouth()) {
            if ((*t1).getDay() >= (*t2).getDay()) {
                return t1;
            } else {
                return t2;
            }
        } else if ((*t1).getMouth() > (*t2).getMouth()) {
            return t1;
        } else {
            return t2;
        }
    } else if ((*t1).getYear() > (*t2).getYear()) {
        return t1;
    } else {
        return t2;
    }
}

template<typename T>
void change(SPointer<T>& t1, SPointer<T>& t2) {
    SPointer<Date> temp = new Date();
    *temp = *t1;
    *t1 = *t2;
    *t2 = *temp;
}

int main(){
    std::cout << "***************" << std::endl;
// 1 task
    std::cout << "Task 1:" << std::endl << "-------" << std::endl;
    SPointer<Date> today = new Date(5, 8, 2021);
    SPointer<Date> day = new Date();
    std::cout << "Day - " << (*today).getDay() << std::endl;
    std::cout << "Mouth - " << (*today).getMouth() << std::endl;
    std::cout << "Year - " << (*today).getYear() << std::endl;
    std::cout << "Date - " << *today << std::endl;
    std::cout << "Year - " << (*day).getYear() << std::endl;
    *day = *today;
    //today = nullptr;
    std::cout << "Year - " << (*day).getYear() << std::endl;
    if (day == nullptr) std::cout << "Pointer day = nullptr" << std::endl;
    if (today == nullptr) std::cout << "Pointer today = nullptr" << std::endl;

    std::cout << "***************" << std::endl;

// 1 task
        std::cout << "Task 2:" << std::endl << "-------" << std::endl;
        SPointer<Date> date1 = new Date(5, 7, 2025);
        SPointer<Date> date2 = new Date(17, 8, 2021);
        std::cout << "Greater date: " << *(func(date1, date2)) << std::endl;
        std::cout << "date1 - " << *date1 << std::endl;
        std::cout << "date2 - " << *date2 << std::endl;

        change(date1, date2);
        std::cout << "***Change***" << std::endl;
        std::cout << "date1 - " << *date1 << std::endl;
        std::cout << "date2 - " << *date2 << std::endl;

        std::cout << "***************" << std::endl;
    return 0;
}
