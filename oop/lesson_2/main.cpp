#include <iostream>
#include <vector>

// 1 task
class Person {
protected:
    std::string name = "";
    int age = 0;
    double ves = 0;
    char pol = 'm';

public:
    Person(){}
    Person(std::string m_name, int m_age, double m_ves, char m_pol)
        : name(m_name), age(m_age), ves(m_ves), pol(m_pol) {}
    void setName(std::string m_name) {
        name = m_name;
    }
    void setAge(int m_age) {
        age = m_age;
    }
    void setVes(double m_ves) {
        ves = m_ves;
    }
    void print() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Ves: " << ves << std::endl;
        std::cout << "Pol: " << pol << std::endl;
    }
};

class Student : public Person {
    int ageLearn = 1;
    static int count;
public:
    Student() : Person() {count++;}
    Student (std::string m_name, int m_age, double m_ves, char m_pol, int m_ageLearn)
        : Person (m_name, m_age, m_ves, m_pol), ageLearn(m_ageLearn) {count++;}
    void set_ageLearn(int m_ageLearn) {
        ageLearn = m_ageLearn;
    }
    std::string getName() {
        return name;
    }
    void plus_ageLearn() {
        ageLearn++;
    }
    void print() { // В данном варианте переопределяем метод print(), чтобы выводить год обучения
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Ves: " << ves << std::endl;
        std::cout << "Pol: " << pol << std::endl;
        std::cout << "AgeLearn: " << ageLearn << std::endl;
    }
    static int getCount() {
         return count;
    }
};
int Student::count = 0;

// 2 task

class Fruit {
    std::string name;
    std::string color;
public:
    Fruit () {};
    Fruit (std::string m_name, std::string m_color) : name(m_name), color(m_color) {};
    std::string getColor() {
        return color;
    }
    std::string getName() {
        return name;
    }
};
class Apple : public Fruit {
public:
    Apple (std::string m_color = "green", std::string m_name = "apple") : Fruit (m_name, m_color) {};
};
class Banana : public Fruit {
public:
    Banana (std::string m_name = "banana", std::string m_color = "yellow") : Fruit (m_name, m_color) {};

};
class GrannySmith : public Apple {
public:
    GrannySmith (std::string m_color = "green") : Apple (m_color) {};
    std::string getName() {
        return "Granny Smith " + Fruit::getName();
    }
};

int main(){
// 1 task
    std::cout << "1 Task:" << std::endl; // Если я правильно понял по поводу вывода по запросу
    std::vector<Student> v;
    v.push_back(Student("Vasya", 21, 59.1, 'f', 2));
    v.push_back(Student("Anna", 22, 51.2, 'm', 3));
    v.push_back(Student("Anton", 23, 65.8, 'f', 5));
    // Вопрос почему когда я когда прописываю декструктор в классе Student и там делаю count--
    // то при данном варианте у меня в счетчике получаются вообще минусовые значения... а точнее при том же коде "-6"
    //такое ощущение


    std::string name;
    std::cout << "Enter name student: ";
    std::cin >> name;
    for (auto i : v) {
        if (i.getName() == name) i.print();
    }
    int i; // Либо так если по номеру, и использовать счетчик
    std::cout << "Count: " << Student::getCount() << std::endl;
    std::cout << "Enter number student: ";
    std::cin >> i;
    if (i > Student::getCount()) {
        std::cout << "No student";
    } else {
        v[i-1].print();
    }
    std::cout << std::endl;

// 2 task
    std::cout << "2 Task:" << std::endl;
    Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
    std::cout << std::endl;

// 3 task
// Опять же не совсем понял задание
// Я думаю что в данной игре необходимо будет использовать как минимум 3 класса
// 1 - класс 1 карты
// 2 - класс игровой колоды
// 3 - класс игрока
// возможно 4 - клас дилера (наследуемый от игрока, со своими дополнительными методами)
// еще так же перечисление для номинала карты
// "Продумать реализацию игры с помощью классов и записать результаты." - эту фразу я не совсем понял
// Необходимо написать игру или...

    return 0;
}
