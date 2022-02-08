#include <iostream>
#include <map>
#include <vector>
// Добавлено немного своего кода, но думаю общей концепции это не нарушает.
class Menu;
class MenuItem;
class Ingredient;

class IVisitor {
public:
    virtual void VisitMenuItem(MenuItem *) = 0;
    virtual void VisitIngredient(Ingredient *) = 0;
    virtual void tempPrepare(Menu *) = 0;
};

class Menu {
public:
    virtual ~Menu() {}
    virtual void getState(IVisitor *) = 0;
    virtual const std::string &getName() const = 0;
    virtual std::map<std::string, float> getIng() = 0;
};

class Ingredient
    : public Menu { // И все-таки ингредиент наверное не должен наследоваться от
                    // MenuItem, а то получается чтобы создать картошку или
                    // свеклу, мы должны вызвать конструктор MenuItem
private:
    std::string _name;
    int _healthRating;
    float _calories;
    float _protein;
    float _carbs;
    float _fats;

public:
    Ingredient(std::string name, float calories, float protein, float carbs,
               float fats)
        : _name(name), _calories(calories), _protein(protein), _carbs(carbs),
          _fats(fats) {
        _healthRating = (_calories + _protein + _carbs + _fats) / 4;
    }

    const std::string &getName() const override { return _name; }

    std::map<std::string, float>
    getIng() override { // тут как и договаривались метод который мы "дергаем" в
                        // посетителе
        std::map<std::string, float> m;
        m.insert(std::make_pair("calories", _calories));
        m.insert(std::make_pair("protein", _protein));
        m.insert(std::make_pair("carbs", _carbs));
        m.insert(std::make_pair("fats", _fats));
        return m;
    }

    void getState(IVisitor *visitor) override {
        visitor->VisitIngredient(this);
    }
};

class MenuItem : public Menu {
private:
    std::string _name;
    std::string _description;
    float _price;
    std::vector<Ingredient *> _ingredients;

public:
    MenuItem(const std::string &name, const std::string &description,
             float price)
        : _name(name), _description(description), _price(price) {}

    const std::string &getName() const override { return _name; }

    const std::string &getDescription() const { return _description; }

    float getPrice() const { return _price; }

    void addIngredient(Ingredient *ingredient) {
        _ingredients.push_back(ingredient);
    }

    std::map<std::string, float>
    getIng() override { // тут как и договаривались метод который мы "дергаем" в
        // посетителе, полчилось не очень, но суть я думаю
        // реализовывает
        std::map<std::string, float> temp_map;
        temp_map.insert(std::make_pair("calories", 0));
        temp_map.insert(std::make_pair("protein", 0));
        temp_map.insert(std::make_pair("carbs", 0));
        temp_map.insert(std::make_pair("fats", 0));

        for (auto it = _ingredients.begin(); it != _ingredients.end(); ++it) {
            std::map<std::string, float> m = (*it)->getIng();
            temp_map["calories"] += m["calories"];
            temp_map["protein"] += m["protein"];
            temp_map["carbs"] += m["carbs"];
            temp_map["fats"] += m["fats"];
        }
        return temp_map;
    }

    void getState(IVisitor *visitor) override { visitor->VisitMenuItem(this); }
};

class VisitorOne : public IVisitor {
public:
    void VisitMenuItem(MenuItem *menuItem) override {
        std::cout << menuItem->getDescription() << ":" << std::endl;
        tempPrepare(menuItem); // вынес в отдельный метод
    };

    void VisitIngredient(Ingredient *ingredient) override {
        std::cout << ingredient->getName() << ":" << std::endl;
        tempPrepare(ingredient); // вынес в отдельный метод
    };

    void tempPrepare(Menu *t) override { // чтобы не повторяться
        std::map<std::string, float> m = t->getIng(); // метод который "дергаем"
        std::cout << "calories: " << m["calories"] << std::endl;
        std::cout << "protein: " << m["protein"] << std::endl;
        std::cout << "carbs: " << m["carbs"] << std::endl;
        std::cout << "fats: " << m["fats"] << std::endl;
    }
};

int main() {
    Ingredient *potato = new Ingredient("potato", 85, 2, 19, 0.1);
    Ingredient *egg = new Ingredient("egg", 151, 12, 0.94, 11);
    Ingredient *meat = new Ingredient("meat", 204, 18, 1, 18);
    MenuItem *pwm = new MenuItem("pwm", "Potato with meat", 5.33);
    MenuItem *pwe = new MenuItem("pwe", "Potato with egg`s", 3.12);
    pwm->addIngredient(potato);
    pwm->addIngredient(meat);
    pwe->addIngredient(potato);
    pwe->addIngredient(egg);

    VisitorOne *vo = new VisitorOne;
    pwm->getState(vo);
    std::cout << std::endl;
    egg->getState(vo);
    std::cout << std::endl;

    delete potato;
    delete egg;
    delete meat;
    delete pwm;
    delete pwe;
    delete vo;

    return 0;
}
