#include <iostream>
#include <list>

enum class Colors {
   RED,
   ORANGE,
   YELLOW,
   GREEN,
   CYAN,
   BLUE,
   VIOLET,
   WHITE
};

class Light{
public:
   Light():state(false), color(Colors::WHITE){};
   void On(){
       if(!state){
           state = true;
           std::cout << "lamp on" << std::endl;
       }
   };

   void Off(){
       if(state){
           state = false;
           std::cout << "lamp off" << std::endl;
       }
   };

   void changeColor(Colors newColor){
       color = newColor;
   }

   bool getState() const {
       return state;
   }

private:
   bool state;
   Colors color;
};

class Command{
protected:
    Light* lamp;
public:
    virtual  void lampOn() = 0;
    virtual  void lampOff() = 0;
    virtual  void setLampColor(Colors) = 0;
    virtual  bool getState() = 0;
    virtual ~Command() {};

    void setLight(Light* lamp){
        this->lamp = lamp;
    }
};

class InsertCommand : public Command{
private:
    bool _state;
public:
    void lampOn() override{
        lamp->On();
        _state = lamp->getState();
    }
    void lampOff() override{
        lamp->Off();
        _state = lamp->getState();
    }
    void setLampColor(Colors color) override{
        lamp->changeColor(color);
    }
    bool getState() override{
        return _state;
    }
};

class Invoker{
    std::list<Command*> DoneCommands;
    Light lamp;
    Command* pCommand;
    std::list<Command*>::const_iterator it; // Итератор текущей позиции при перемещении по истории

public:
    Invoker() : pCommand(nullptr), it(DoneCommands.end()) {
    }
    ~Invoker(){
        for(Command* ptr: DoneCommands){
            delete ptr;
        }
    }
    void On(){
        if(!lamp.getState()) { // Если лампа включена то повторно не нужно логгировать,
            //так как она уже не включится, но если нужны все попытки, то убираем условие
            pCommand = new InsertCommand();
            pCommand->setLight(&lamp);
            pCommand->lampOn();
            DoneCommands.push_back(pCommand);
            it = DoneCommands.end(); // При совершении действия итератор сдвигается в конец списка, на текущее действие
        }
    }
    void Off(){
        if(lamp.getState()) {// Если лампа выключена то повторно не нужно логгировать,
            //так как она уже не вылючится, но если нужны все попытки, то убираем условие
            pCommand = new InsertCommand();
            pCommand->setLight(&lamp);
            pCommand->lampOff();
            DoneCommands.push_back(pCommand);
            it = DoneCommands.end(); // При совершении действия итератор сдвигается в конец списка, на текущее действие
        }
    }
    void changeColor(Colors color){ // Здесь мы не ведем запись в список команд, т.к. в задании только выкл./вкл.
        pCommand = new InsertCommand();
        pCommand->setLight(&lamp);
        pCommand->setLampColor(color);// При изменеии цвета итератор не сдвигаем
    }
    void next(){
        if (DoneCommands.size() != 0){
           if(it == DoneCommands.end()) {
               std::cerr << "This is END" << std::endl;
           } else {
               ++it;
               std::cout << "Current state: " << (*it)->getState() << std::endl;
           }

        }
        else{
            std::cerr << "No any commands" << std::endl;
        }
    }
    void prev(){
        if (DoneCommands.size() != 0){
           if(it == DoneCommands.begin()) {
               std::cerr << "This is BEGIN" << std::endl;
           } else {
               --it;
               std::cout << "Current state: " << (*it)->getState() << std::endl;
           }

        }
        else{
            std::cerr << "No any commands" << std::endl;
        }
    }
    void showStatesHistory() {
        std::cout << "*** History ***" << std::endl;
        for(Command* ptr : DoneCommands) {
            std::cout << ptr->getState() << std::endl;
        }
        std::cout << "*** END History ***" << std::endl;
    }
};


int main() {
    Invoker inv;

    inv.On();
    inv.Off();
    inv.On();
    inv.On();
    inv.On();
    inv.Off();
    inv.On();
    inv.changeColor(Colors::GREEN);

    inv.next();
    inv.prev();
    inv.prev();
    inv.prev();
    inv.prev();
    inv.prev();
    inv.prev();
    inv.prev();
    inv.Off();
    inv.prev();
    inv.prev();

    inv.showStatesHistory();

    return 0;
}
