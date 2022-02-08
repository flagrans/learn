#include <iostream>
#include <vector>

class IHerald;

class ICitizen {
protected:
    std::string _name = "";
    int _hearingPower = 100;
    IHerald *_herald = nullptr;

public:
    ICitizen(std::string name, int hearingPower)
        : _name(name), _hearingPower(hearingPower) {}
    void setHerald(IHerald *herald) { _herald = herald; }
    virtual void listen(int, std::string) = 0;
};

class Doctor : public ICitizen {
public:
    Doctor(std::string name, int hearingPower) : ICitizen(name, hearingPower) {}

    void listen(int voicePower, std::string announcement) override {
        if ((100 - _hearingPower) <= voicePower) // Измнил немного условия слуха
            // т.к. не логично получается что при 100% слухе у Доктора он не
            // слышит что говорит глашатай с 90 силой голоса но при этом его
            // слышут дети с 50% слухом
            std::cout << "The doctor " << _name
                      << " received a message: " << announcement << std::endl;
    }
};

class Blacksmith : public ICitizen {
public:
    Blacksmith(std::string name, int hearingPower)
        : ICitizen(name, hearingPower) {}
    void listen(int voicePower, std::string announcement) override {
        if ((100 - _hearingPower) <= voicePower)
            std::cout << "The blacksmith " << _name
                      << " received a message: " << announcement << std::endl;
    }
};

class Child : public ICitizen {
public:
    Child(std::string name, int hearingPower) : ICitizen(name, hearingPower) {}
    void listen(int voicePower, std::string announcement) override {
        if ((100 - _hearingPower) <= voicePower)
            std::cout << "The child " << _name
                      << " received a message: " << announcement << std::endl;
    }
};

class IHerald { // Создадим интерфейс - ведь у нас может быть более одного
                // глашатая
public:
    virtual void registerCitizen(ICitizen *citizen) = 0;
    virtual void removeCitizen(ICitizen *citizen) = 0;
    virtual void notifyCitizens() = 0;
};
class Herald : IHerald {
private:
    int _voicePower = 100;
    std::string _announcement;
    std::vector<ICitizen *> _citizens;

public:
    // Здесь я считаю не нужен конструктор, т.к. мы будем подписываться
    // немного по другому, ведь у нас для этого есть метод registerCitizen
    // И получается на уроке тоже избыточно в конструкторе было добавлять
    // наблюдателей
    void registerCitizen(ICitizen *citizen) override {
        if (!checkCitizen(citizen)) { // Проверяем что горожанин еще не подписан
            _citizens.push_back(citizen);
            citizen->setHerald(this);
        }
    }
    void removeCitizen(ICitizen *citizen) override {
        std::vector<ICitizen *>::iterator iter; // Без промежуточного
        // сохранения найденого итератора и вызова erase в цикле при
        // дебаге seg failure, хотя просто при выполении программы нет
        bool t = false;
        for (auto it = _citizens.begin(); it != _citizens.end(); ++it) {
            if (*it == citizen) {
                iter = it;
                t = true;
            }
        }
        if (t) {
            citizen->setHerald(nullptr);
            _citizens.erase(iter);
        }
    }
    void notifyCitizens() override {
        for (auto citizen : _citizens)
            citizen->listen(_voicePower, _announcement);
    }

    bool checkCitizen(ICitizen *citizen) {
        for (auto it = _citizens.begin(); it != _citizens.end(); ++it) {
            if (*it == citizen) {
                return true;
            }
        }
        return false;
    }

    int getVoicePower() { return _voicePower; }
    std::string getAnnouncement() { return _announcement; };
    void setVoicePower(int voicePower) { _voicePower = voicePower; }

    void setAnnouncement(std::string announcement) {
        _announcement = announcement;
        notifyCitizens();
    }

    // тут тоже непонятно что данный метод делает и зачем он здесь
    // сделал как на уроке через setAnnouncement и notifyCitizens
    // зачем мы получаем voicePower = getVoicePower(); если это метод и
    // мы можем напрямую обратиться к полю announcement

    //    void changeAnnouncment() {
    //        voicePower = getVoicePower();
    //        announcement = getAnnouncement();

    //        for (const auto citizen : citizens) {
    //            citizen->listen(voicePower, announcement);
    //        }
    //    }
};

int main() {
    Herald *h1 = new Herald;
    Doctor *d1 = new Doctor("Ivan", 100);
    Doctor *d2 = new Doctor("Sasha", 100);
    Blacksmith *b1 = new Blacksmith("Timur", 30);
    Blacksmith *b2 = new Blacksmith("Nikita", 40);
    Child *c1 = new Child("Klim", 40);

    h1->registerCitizen(d1);
    h1->registerCitizen(b2);
    h1->registerCitizen(c1);
    h1->setAnnouncement("TEST");
    std::cout << std::endl;
    h1->setVoicePower(50);
    h1->notifyCitizens();
    h1->setVoicePower(100);
    h1->registerCitizen(b1);
    h1->registerCitizen(b1);
    h1->removeCitizen(c1);
    std::cout << std::endl;
    h1->setAnnouncement("TEST2");

    delete d1;
    delete d2;
    delete b1;
    delete b2;
    delete c1;
    delete h1;
    return 0;
}
