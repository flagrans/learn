#include <iostream>
#include <vector>

class Events{
public:
   virtual void getEvent() = 0;
   virtual ~Events() {};
};

class Hotel: public Events{
public:
   void getEvent() {
       std::cout << "Booking Hotel" << std::endl;
   }
};

class Park: public Events{
   void getEvent() {
       std::cout << "Park visiting" << std::endl;
   }
};

class Food: public Events{
public:
   virtual void getEvent() = 0;
   virtual ~Food() {};
};

class Dinner: public Food{
public:
   Dinner() : _type("dinner") {}
   void getEvent(){
       std::cout << "Food " << _type << std::endl;
   } ;
private:
   std::string _type;
};

class Lunch: public Food{
public:
   Lunch() : _type("lunch") {}
   void getEvent(){
       std::cout << "Food " << _type << std::endl;
   } ;
private:
   std::string _type;
};

class Breakfast: public Food{
public:
   Breakfast() : _type("breakfast") {}
   void getEvent(){
       std::cout << "Food " << _type << std::endl;
   } ;
private:
   std::string _type;
};

class Special: public Events{
public:
   virtual void getEvent() = 0;
   virtual ~Special() {};
};

class Skating:public Special{
public:
   Skating() : _type("skating") {}
   void getEvent(){
       std::cout << _type << std::endl;
   } ;
private:
   std::string _type;
};

class Circus:public Special{
public:
   Circus() : _type("circus") {}
   void getEvent(){
       std::cout << _type << std::endl;
   } ;
private:
   std::string _type;
};

class Day {
    std::vector<Events*> events;
public:
    void printEvents() {
        std::cout << "*** List of Events ***" << std::endl;
        for(const auto i: events)
            i->getEvent();
        std::cout << "*** ************** ***" << std::endl;

    }
    void addEvent(Events* ev) {
        events.push_back(ev);
    }
};

class eventsBuilder{
private:
    Day* _day = nullptr;
public:
    eventsBuilder(){
        reset();
    }
    void reset(){
        _day = new Day();
    }
    virtual ~eventsBuilder(){}

    void addHotel(){
        this->_day->addEvent(new Hotel());
    }
    void addPark(){
        this->_day->addEvent(new Park());
    }
    void addDinner(){
        this->_day->addEvent(new Dinner());
    }
    void addLunch(){
        this->_day->addEvent(new Lunch());
    }
    void addBreakfast(){
        this->_day->addEvent(new Breakfast());
    }
    void addSkating(){
        this->_day->addEvent(new Skating());
    }
    void addCircus(){
        this->_day->addEvent(new Circus());
    }

    Day* getDay() {
        Day* result= _day;
        this->reset();
        return result;
    }
};

class Director {
private:
    eventsBuilder* _eBuilder;
public:
    void setBuilder(eventsBuilder* eb) {
        _eBuilder = eb;
    }
    void buildSampleDay() {
        _eBuilder->addCircus();
        _eBuilder->addHotel();
        _eBuilder->addDinner();
        _eBuilder->addPark();
    }
};


int main() {
    Director* director= new Director();
    eventsBuilder* builder = new eventsBuilder();
    director->setBuilder(builder);
    director->buildSampleDay();

    Day* p= builder->getDay();
    p->printEvents();
    delete p;

// Далее мы "строим" день без участия "директора"
    builder->addBreakfast();
    builder->addPark();
    builder->addPark();
    builder->addPark();
    p = builder->getDay();
    p->printEvents();

    delete p;
    delete builder;
    delete director;

    return 0;
}
