#include <iostream>

class IShape{
public:
    virtual void scale(double scale_percentage) = 0;// Масштабируем фигуру
    virtual void rotate(double angle) = 0;          // Поворачиваем фигуру
    virtual void flip() = 0;                        // Отражаем фигуру
    virtual void showAllProp() = 0;
};

class Figure: IShape{
private:
    int _width;
    int _height;
    double _angle;
    bool _isFlipped;
public:
    Figure(){}
    Figure(int width, int height) : _width(width), _height(height), _angle(0.0), _isFlipped(false) {}
    virtual ~Figure(){};
    void scale(double scale_percentage) override {
        _width *= scale_percentage;
        _height *= scale_percentage;
    }

    void rotate(double angle) override {
        _angle += angle;
    }

    void flip() override {
        _isFlipped = !_isFlipped;
    }
    void showAllProp() override{} // введена для отображения результатов в классе TextView и Text
};

class IText{
    virtual void newSize(int size) = 0;   // Изменяем размер шрифта текста
    virtual void rotate(double angle) = 0;   // Поворачиваем текст
    virtual void reverse() = 0;              // Изменяем направление текста
};

class Text: IText{
private:
    std::string _text;
    int _size;
    double _angle;
    bool _isReversed;
public:
    Text(){}
    Text(const std::string text, int size, double angle = 0.0, bool isReversed = false) : _text(text), _size(size), _angle(angle), _isReversed(isReversed) {}
    void printText(){
        std::cout << _text << std::endl;
    }
    virtual ~Text(){};
//private:
    void newSize(int newSize) override {
        _size = newSize;
    }
    int getSize() {
        return _size;
    }

    void rotate(double newAngle) override {
        _angle = newAngle;
    }
    void reverse() override {
        for (size_t i = 0; i < _text.size()/2; ++i) {
            char c = _text[i];
            _text[i] = _text[_text.size() - 1 - i];
            _text[_text.size() - 1 - i] = c;
        }
        _isReversed = !_isReversed;
    }

    void showAllProp(){ // Эта функция введена для отображения результатов
        std::cout << "*** All Property ***" << std::endl;
        std::cout << "Text = " << _text << std::endl;
        std::cout << "Size = " << _size << std::endl;
        std::cout << "Angle = " << _angle << std::endl;
        std::cout << "isReversed = " << _isReversed << std::endl;
        std::cout << "*** ************ ***" << std::endl;
    }
};

class TextView : public Figure {
private:
    Text _text;
public:
    TextView(const Text &text): _text(text) {}
    void scale(double scale_percentage) override {// Здесь не знаю как подразумевается,
    // но я вижу это как увеличение размера текста исходя из коэффициента масштабирования
    // поэтому пришлось ввести в классе Text дополнительный метод getSize()
        int size = _text.getSize();
        _text.newSize(size * scale_percentage);
    }
    void rotate(double angle) { // Здесь и далее в 2-х методах у меня IDE выдает предупреждение
        // 'rotate' overrides a member function but is not marked 'override', когда ставишь override то все норм, прокомментируйте пожалуйста
        _text.rotate(angle);
    }
    void flip() {
        _text.reverse();
    }
    void showAllProp() { // Эта функция введена для отображения результатов
        _text.showAllProp();
    }
};

int main() {
    Figure figure;
    Text text("Per aspera ad astra", 10);

    Figure* textView = new TextView(text);

    textView->showAllProp();
    textView->rotate(10.2);
    textView->flip();
    textView->scale(2.35);
    textView->showAllProp();

    delete textView;
    return 0;
}
