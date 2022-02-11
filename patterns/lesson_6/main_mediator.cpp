#include <iostream>

class Device;

class Mediator {
public:
    bool isWeekDay;
    virtual void Notify(Device *sender, std::string event) const = 0;
};

class Device {
protected:
    Mediator *mediator_;

public:
    Device(Mediator *mediator = nullptr) : mediator_(mediator) {}
    void set_mediator(Mediator *mediator) { this->mediator_ = mediator; }
};

class Calendar : public Device {
private:
    bool b = true;

public:
    void checkCalendar() { // Просто делаем через день выходной
        b = !b;
        this->mediator_->isWeekDay = b;
        this->mediator_->Notify(this, "newday");
    }
};

class Coffee : public Device {
public:
    void doCoffee() { std::cout << "Coffee is ready!" << std::endl; }
};

class TeaPot : public Device {
public:
    void doTea() { std::cout << "Tea is ready!" << std::endl; }
};

class Alarm : public Device {
private:
    int alarmHour_;    // Часы срабатывания будильника
    int alarmMinutes_; // Минуты
public:
    Alarm(int h, int m) : alarmHour_(h), alarmMinutes_(m) {}
    void doAlarm() {
        std::cout << "Alarm went off at " << alarmHour_ << ":" << alarmMinutes_
                  << std::endl;
        // this->mediator_->Notify(this, "alarmoff"); /*Если используем
        //  ConcreteMediator2 - то необходимо расскометрировать*/
    }
};

class ConcreteMediator : public Mediator {
private:
    Alarm *alarmWeekDay_;
    Alarm *alarmDayOff_;
    TeaPot *teaPot_;
    Coffee *coffee_;
    Calendar *calendar_;

public:
    ConcreteMediator(Alarm *alwd, Alarm *aldo, TeaPot *tp, Coffee *cf,
                     Calendar *cl)
        : alarmWeekDay_(alwd), alarmDayOff_(aldo), teaPot_(tp), coffee_(cf),
          calendar_(cl) {
        this->calendar_->set_mediator(this);
    }
    void Notify(Device *sender, std::string event) const override {
        if (event ==
            "newday") { // Можно оставить так и без остальных подисчиков,
            //а можно второй вариант (ConcreteMediator2), что кажется более
            //логичным в контексте паттерна
            if (isWeekDay) {
                std::cout << "New Day - Week Day." << std::endl;
                alarmWeekDay_->doAlarm();
                coffee_->doCoffee();
            } else {
                std::cout << "New Day - Day Off." << std::endl;
                alarmDayOff_->doAlarm();
                teaPot_->doTea();
            }
        }
    }
};

class ConcreteMediator2 : public Mediator {
private:
    Alarm *alarmWeekDay_;
    Alarm *alarmDayOff_;
    TeaPot *teaPot_;
    Coffee *coffee_;
    Calendar *calendar_;

public:
    ConcreteMediator2(Alarm *alwd, Alarm *aldo, TeaPot *tp, Coffee *cf,
                      Calendar *cl)
        : alarmWeekDay_(alwd), alarmDayOff_(aldo), teaPot_(tp), coffee_(cf),
          calendar_(cl) {
        this->alarmWeekDay_->set_mediator(this);
        this->alarmDayOff_->set_mediator(this);
        this->calendar_->set_mediator(this);
    }
    void Notify(Device *sender, std::string event) const override {
        if (event == "newday") {
            if (isWeekDay) {
                std::cout << "New Day - Week Day." << std::endl;
                alarmWeekDay_->doAlarm();

            } else {
                std::cout << "New Day - Day Off." << std::endl;
                alarmDayOff_->doAlarm();
            }
        }
        if (event == "alarmoff") {
            if (isWeekDay)
                coffee_->doCoffee();
            else
                teaPot_->doTea();
        }
    }
};

int main() {
    Alarm *alarmWeekDay =
        new Alarm(7, 30); // Логично что для разных дней свои будильники
    Alarm *alarmDayOff = new Alarm(10, 15);
    TeaPot *teaPot = new TeaPot;
    Coffee *coffee = new Coffee;
    Calendar *calendar = new Calendar;

    ConcreteMediator *mediator = new ConcreteMediator(alarmWeekDay, alarmDayOff,
                                                      teaPot, coffee, calendar);

    calendar->checkCalendar();
    std::cout << "\n\n";
    calendar->checkCalendar();

    delete alarmWeekDay;
    delete alarmDayOff;
    delete teaPot;
    delete coffee;
    delete calendar;
    delete mediator;
    std::cout << "\n\n";
    return 0;
}
