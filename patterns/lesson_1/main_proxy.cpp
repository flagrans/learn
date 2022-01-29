#include <iostream>
#include <map>
#include <ctime>

using namespace std;

class ISellSystem{
public:
    virtual void changePrice(string, float) = 0;
    virtual void sellProduct(string) = 0;
    virtual void addProduct(string, size_t) = 0;
};


class Automaton: ISellSystem {
private:
   string location;
   double recieved_money;
   double spent_money;
   map <string, float> goods_price;
   map <string, size_t> goods_count;

public:
   Automaton(const string &location, double recievedMoney) : location(location), recieved_money(recievedMoney) {
       spent_money = 0.0;
   }

   void changePrice(string name, float newPrice) override {
       goods_price[name] = newPrice;
   }

   void sellProduct(string name) override {
       if(goods_count[name] > 0){
           recieved_money += goods_price[name];
       }
       else{
           cerr << "Not enough goods" << endl;
       }
   }

   void addProduct(string name, size_t count) override {
       goods_count[name] += count;
   }

   double allMoneyReport() const{
       return recieved_money - spent_money;
   }

   const string& getLocationReport() const {
       return location;
   }

   map <string, size_t> goodsCountReport() const{
       return goods_count;
   }

   map <string, float> goodsPriceReport() const{
       return goods_price;
   }
};

class AutoProxy : public ISellSystem {
private:
    Automaton* _real_auto;
    time_t _last_time; // Все нижеприведенные поля - для кэширования
    double _cache_allMoneyReport;
    string _cache_getLocationReport;
    map <string, float> _cache_goods_price;
    map <string, size_t> _cache_goods_count;

    bool _passedTime() { // Проверка времени обновления
        time_t current_time = time(nullptr);
        if ((current_time - _last_time) > 3600)
            return true;
        else
            return false;
    }

public:
    AutoProxy(Automaton* real_auto): _real_auto(new Automaton(*real_auto)) {
        _last_time = time(nullptr) - 3700; // Вводим первоначальное значение больше часа
    }
    ~AutoProxy() {
        delete _real_auto;
    }
// Здесь т.к. "Заместитель должен предоставлять доступ только к отчетам не обязательно реализовывать
// я так понимаю закомментированные методы, но на всякий случай реализовал в комментариях
    //   void changePrice(string name, float newPrice) override {
    //       this->_real_auto->changePrice(name, newPrice);
    //   }

    //   void sellProduct(string name) override {
    //       this->_real_auto->sellProduct(name);
    //   }

    //   void addProduct(string name, size_t count) override {
    //       this->_real_auto->addProduct(name, count);
    //   }

    double allMoneyReport() {
        if(_passedTime())
            _cache_allMoneyReport = this->_real_auto->allMoneyReport(); // Если времени прошло более часа,
        // то в кэш закидываем актуальную информацию и возвращаем данные из кэша
        // анологично в последующих методах
        return _cache_allMoneyReport;
    }

    const string& getLocationReport() {
        if(_passedTime())
            _cache_getLocationReport = this->_real_auto->getLocationReport();
        return _cache_getLocationReport;
    }
    map <string, size_t> goodsCountReport() {
        if (_passedTime())
            _cache_goods_count = this->_real_auto->goodsCountReport();
        return _cache_goods_count;
    }

    map <string, float> goodsPriceReport() {
        if (_passedTime())
            _cache_goods_price = this->_real_auto->goodsPriceReport();
        return _cache_goods_price;
    }
};

int main() {
    Automaton a1("Lenina st.", 2.5);
    Automaton a2("Krasnaya st.", 1.5);
    a1.addProduct("apple", 3);
    a1.addProduct("banana", 5);
    a2.addProduct("papper a4", 4);
    a2.addProduct("papper a3", 2);
    a1.changePrice("apple", 1.33);
    a1.changePrice("banana", 5.66);
    a2.changePrice("papper a4", 100);
    a2.changePrice("papper a3", 150);
    a2.changePrice("papper a4", 90);

    cout << "*** a1 ***" << endl;
    cout << a1.getLocationReport() << endl;
    a1.goodsCountReport();
    a1.goodsPriceReport();
    cout << a1.allMoneyReport() << endl;

    cout << "*** a2 ***" << endl;
    cout << a2.getLocationReport() << endl;
    a2.goodsCountReport();
    a2.goodsPriceReport();
    a2.sellProduct("papper a5");
    cout << a2.allMoneyReport() << endl;

    time_t start = time(nullptr);
    int g;
    cin >> g;
    time_t end = time(nullptr);
    cout << difftime(end, start);

    return 0;
}
