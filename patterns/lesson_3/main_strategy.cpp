#include <iostream>
#include <fstream>

enum class DivideMethod{
    ByScreenWidth,
    ByUserWidth,
    BySentence
};

class DivideStrategy{
public:
    virtual void Divide(std::string &) = 0;
    virtual void setWidth(int) {}; // Метод необходим только для пользовательской ширины
};

class DivideByScreenWidth: public DivideStrategy {
    size_t _editorWidth; // Храним ширину окна
public:
    virtual ~DivideByScreenWidth() {};
    void Divide(std::string & all_text) override {
        _editorWidth = 99; // Либо в коде вычисляем и устанавливаем ширину окна
        std::cout << "DivideByScreenWidth by screen width = " << _editorWidth << std::endl;
        std::cout << all_text << std::endl;
    }
};

class DivideBySentence : public DivideStrategy {
public:
    virtual ~DivideBySentence() {};
    void Divide(std::string & all_text) override {
        std::cout << "Divided by Sentences" << std::endl;
        std::cout << all_text << std::endl;
    }
};

class DivideByUserWidth : public DivideStrategy {
    int _userWidth = 0; // Пользовательский перенос по умолчанию
public:
    virtual ~DivideByUserWidth() {};
    void Divide(std::string & all_text) override {
        std::cout << "DivideByScreenWidth by screen width = " << _userWidth << std::endl;
        std::cout << all_text << std::endl;
    }
    void setWidth(int width) override { // Переопределяем метод set для установки пользовательской ширины
        _userWidth = width;
    }
};


class Editor{
protected:
    DivideStrategy* divideStrategy;
public:
    virtual void useStrategy() = 0;
    virtual void setStrategy(DivideStrategy*) = 0;
    virtual void setStrategy(DivideStrategy*, int) = 0; // Переопределяем для использования
    // передачи в параметрах пользовательского значения
    virtual ~Editor() {}
};

class TextEditor: public Editor{
private:
    std::string all_text;
    DivideStrategy* divideStrategy;
public:
    TextEditor(){};
    TextEditor(const std::string &text) : all_text(text) {};

    TextEditor(std::ifstream& file) {
        std::string line;
        if (file.is_open()){
            while (getline(file, line))
            {
                all_text+=line;
            }
        }
    }
    virtual ~TextEditor() {};

    void PrintText() const{
        std::cout << all_text << std::endl;
    }

    void useStrategy() override {
        divideStrategy->Divide(all_text);
    }


    void setStrategy(DivideStrategy* strategy) override {
        divideStrategy = strategy;
    }
    void setStrategy(DivideStrategy* strategy, int width) override {
        divideStrategy = strategy;
        divideStrategy->setWidth(width);
    }

};


int main() {
    TextEditor* test = new TextEditor("asdfgaergjawo;hadadsasdlkjgha;");
    DivideByScreenWidth* sw = new DivideByScreenWidth();
    DivideBySentence* s = new DivideBySentence();
    DivideByUserWidth* uw = new DivideByUserWidth();

    test->setStrategy(s);
    test->useStrategy();

    std::cout << std::endl;

    test->setStrategy(sw);
    test->useStrategy();

    std::cout << std::endl;

    test->setStrategy(uw, 5);
    test->useStrategy();

    delete uw;
    delete s;
    delete sw;
    delete test;
    return 0;
}
