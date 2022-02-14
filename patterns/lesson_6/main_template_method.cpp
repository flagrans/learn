#include <iostream>
#include <vector>

class IImage {
private:
    std::string filename = "";

protected:
    virtual void openFile(const std::string &filename) final {
        std::cout << "Open file " << filename << std::endl;
    }

    virtual void readFile() = 0;
    virtual void draw() = 0;

    virtual void final() final {
        std::cout << "Drawing image complete" << std::endl;
    }

public:
    IImage(const std::string &filename) : filename(filename) {}
    virtual void drawImage() final {
        openFile(filename);
        readFile();
        draw();
        final();
    }
};

struct Pixel {
    int x;
    int y;
    std::string color;

    void draw() { std::cout << "(" << x << ", " << y << ", " << color << ") "; }
};

class BitmapImage : public IImage { // Растровое изображение
private:
    std::vector<Pixel *> pixels; // это пиксели, которые хранятся в файле
    std::vector<Pixel>
        buffer; // это пиксели, которые мы читаем для отображение на экране

    void readBitmapFile() {
        for (const auto pixel : pixels) {
            buffer.push_back(
                *pixel); // Имитируем чтение пикселей из файла в буфер
        }
    }
    void readFile() override {
        readBitmapFile();
        std::cout << "Read Bitmap File" << std::endl;
    }

    void draw() override {
        for (const auto pixel : pixels) {
            pixel->draw(); // Рисуем каждый пиксель из буфера
        }
        std::cout << "Draw Bitmap Image" << std::endl;
    }

public:
    BitmapImage(const std::string &filename) : IImage(filename) {}
};

struct Figure {
    int x;
    int y;
    std::string figure;

    void draw() {
        std::cout << "(" << x << ", " << y << ", " << figure << ") ";
    }
};

class VectorImage : public IImage { // Векторное изображение
private:
    std::vector<Figure *>
        figures; // это описание фигур, которые хранятся в файле
    std::vector<Figure> buffer; // это описание фигур, которые мы читаем для
                                // отображение на экране
    void readVectorFile() {
        for (const auto figure : figures) {
            buffer.push_back(
                *figure); // Имитируем чтение фигур из файла в буфер
        }
    }
    void readFile() override {
        readVectorFile();
        std::cout << "Read Vector File" << std::endl;
    }
    void draw() override {
        for (const auto figure : figures) {
            figure->draw(); // Рисуем каждую фигуру из буфера
        }
        std::cout << "Draw Vector Figure" << std::endl;
    }

public:
    VectorImage(const std::string &filename) : IImage(filename) {}
};

int main() {
    VectorImage i1("asd");
    BitmapImage b1("tre");

    i1.drawImage();
    std::cout << std::endl;
    b1.drawImage();
    std::cout << std::endl;
    return 0;
}
