#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
#include <stdexcept>
#include "test.pb.h" //Лежит в папке cmake-build-debug

std::random_device rd;
std::mt19937_64 random2(static_cast<unsigned int>(time(0)));

void setGrades(mySpace::Student & stud) { // Функция для заполения оценок.
    for (int i = 0; i < 10; ++i) stud.add_grades((random2() % 4) + 2);
}

class IRepository {
    virtual void Open() = 0; // бинарная десериализация в файл
    virtual void Save() = 0; // бинарная сериализация в файл
};

class IMethods {
    virtual double GetAverageScore(const mySpace::FullName& name) = 0;
    virtual std::string GetAllInfo(const mySpace::FullName& name) = 0;
    virtual std::string GetAllInfo() = 0;
};

class StudentsGroup : public IRepository, public IMethods { // Опять же из задания четко не понятно, что за класс и как он должен взаимодействовать с классом из 2-го задания
public:                                                     // Поэтому реализовал как понял.
    void Open() override {
        std::ifstream in("../students.bin", std::ios_base::binary);
        if (!sg.ParseFromIstream(&in)) throw std::runtime_error("Could not open file.");
        in.close();
    }
    void Save() override {  // Не совсем понятно зачем в данном классе реализовывать метод Save() - если все данные у нас только читаются, ну пусть будет
        std::ofstream out("../students.bin", std::ios_base::binary);
        sg.SerializeToOstream(&out);
        out.close();
    }
    double GetAverageScore(const mySpace::FullName& name) override {
        auto iter = std::find_if(sg.students().begin(), sg.students().end(), [&](const mySpace::Student &st){
            return tie(st.fname().name(), st.fname().surname(), st.fname().patronymic()) == tie(name.name(), name.surname(), name.patronymic());
        });
        if(iter == sg.students().end()) return 0;
        else return iter->ascore();
    }
    std::string GetAllInfo(const mySpace::FullName& name) override {
        if(sg.students().size() == 0) Open();
        auto iter = std::find_if(sg.students().begin(), sg.students().end(), [&](const mySpace::Student &st){
            return tie(st.fname().name(), st.fname().surname(), st.fname().patronymic()) == tie(name.name(), name.surname(), name.patronymic());
        });
        if (iter == sg.students().end()) return "";
        std::string temp;
        temp = "Фамилия:" + iter->fname().surname() + "\n";
        temp += "Имя: " + iter->fname().name() + "\n";
        temp += "Отчество: " + iter->fname().patronymic() + "\n";
        temp += "Список оценок: ";
        for (const auto &i : iter->grades()) {
            temp += std::to_string(i) + " ";
        }
        temp += "\nСредний балл: " + std::to_string(iter->ascore()) + "\n";
        return temp;
    }
    std::string GetAllInfo() override {
        std::string sTemp;
        sTemp = "Полная информация о студентах:\n";
        for (const auto &i: sg.students()) sTemp += "\n" + GetAllInfo(i.fname());
        return sTemp;
    }

private:
    mySpace::StudentsGroup sg;
};

int main() {
    {
        // Наполнение файла students.bin
        mySpace::FullName n1;
        mySpace::FullName n2;
        mySpace::FullName n3;
        mySpace::FullName n4;

        n1.set_name("Andrei");
        n1.set_surname("Kraynov");
        n1.set_patronymic("Ivanovich");

        n2.set_name("Ivan");
        n2.set_surname("Reshetnikov");
        n2.set_patronymic("Fomich");

        n3.set_name("Alexsandr");
        n3.set_surname("Ivanov");
        n3.set_patronymic("Kuzmich");

        n4.set_name("Ilya");
        n4.set_surname("Berezkin");
        n4.set_patronymic("Petrovich");

        mySpace::Student s1;
        *s1.mutable_fname() = n1;
        setGrades(s1);
        s1.set_ascore(std::accumulate(s1.grades().begin(), s1.grades().end(), 0.0) / s1.grades().size());

        mySpace::Student s2;
        *s2.mutable_fname() = n2;
        setGrades(s2);
        s2.set_ascore(std::accumulate(s2.grades().begin(), s2.grades().end(), 0.0) / s2.grades().size());

        mySpace::Student s3;
        *s3.mutable_fname() = n3;
        setGrades(s3);
        s3.set_ascore(std::accumulate(s3.grades().begin(), s3.grades().end(), 0.0) / s3.grades().size());

        mySpace::Student s4;
        *s4.mutable_fname() = n4;
        setGrades(s4);
        s4.set_ascore(std::accumulate(s4.grades().begin(), s4.grades().end(), 0.0) / s4.grades().size());

        mySpace::StudentsGroup g1;
        *g1.add_students() = s1;
        *g1.add_students() = s2;
        *g1.add_students() = s3;
        *g1.add_students() = s4;

//        std::ofstream out("../students.bin", std::ios_base::binary);
//        g1.SerializeToOstream(&out);
//        out.close();
}

    try {
        StudentsGroup SG;
        SG.Open();

        std::cout << "Тест GetAllInfo(const mySpace::FullName& name):\n";
        mySpace::FullName fn;
        fn.set_name("Andrei");
        fn.set_surname("Kraynov");
        fn.set_patronymic("Ivanovich");
        std::cout << SG.GetAllInfo(fn) << std::endl;

        std::cout << "Тест GetAverageScore(const mySpace::FullName& name):\n";
        std::cout << SG.GetAverageScore(fn) << std::endl;

        std::cout << "Тест GetAllInfo():\n";
        std::cout << SG.GetAllInfo() << std::endl;
        
    } catch (std::exception &ex) {
        std::cout << "Error: " << ex.what() << std::endl;
    }
}