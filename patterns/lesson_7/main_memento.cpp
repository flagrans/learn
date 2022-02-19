#include <conio.h>
#include <ctime>
#include <fstream>
#include <iostream>
#include <vector>

class Memento; // В данной вариации я вижу реализацию примерно так...

class Player {
private:
    float hp;
    int speed;
    std::string name;

public:
    Player(float hp, int speed, const std::string &name);
    Player();

    void changeSpeed(int change);
    void changeHp(int change);
    float getHp() const;
    int getSpeed() const;
    const std::string &getName() const;
};

class Memento {
public:
    void addSave(Player &p) { // Формируем строку включая текущее время и
                              // записываем в файл сохранений
        std::string temp = "";
        std::time_t time = std::time(nullptr);
        std::string s = std::asctime(std::localtime(&time));
        s = s.substr(0, s.size() - 1);
        temp += s;
        temp += "*";
        temp += p.getName();
        temp += "*";
        temp += std::to_string(p.getHp());
        temp += "*";
        temp += std::to_string(p.getSpeed());
        temp += "\n";
        std::ofstream out(filePath_, std::ios::binary | std::ios_base::app);
        out.write(temp.c_str(), temp.size());
        out.close();
    }

    Player loadSave() { // Выводим список всех сохранений и предлагаем
                        // пользователю выбрать необходимое сохранение
        printSaves();
        int ns;
        bool isNotFind = true;
        while (isNotFind) {
            std::cout << "Enter number save: ";
            std::cin >> ns;
            for (const int i : vi) {
                if (i == ns)
                    isNotFind = false;
            }
        }
        std::string
            buff; // Если выбран верный номер то считаем построчно пока не
                  // дойдем до нужной строки и формируем объект Player
        // и возвращаем его
        // Хотя можно было бы и сделать чтобы метод ничего не возвращал и
        // принимал объект Player по ссылке и исправлял значения на сохраненные
        std::ifstream in(filePath_, std::ios::binary);
        std::string name = "";
        float hp = 0;
        int speed = 0;
        for (int j = 1; j <= ns; j++) {
            getline(in, buff, '\n');
            if (j == ns) {
                std::string::size_type n, k;
                std::string s1, s2, s3, s4;
                n = buff.find("*");
                s1 = buff.substr(0, n);
                k = buff.find("*", n + 1);
                s2 = buff.substr(n + 1, k - n - 1);
                n = k;
                k = buff.find("*", n + 1);
                s3 = buff.substr(n + 1, k - n - 1);
                n = k;
                k = buff.find("*", n + 1);
                s4 = buff.substr(n + 1, k - n - 1);
                hp = std::stof(s3);
                speed = std::stoi(s4);
                name = s2;
            }
        }
        in.close();
        Player p(hp, speed, name);
        return p;
    }

private:
    void printSaves() { // Функция выводящая на экран список сохраннений с
                        // временем сохранения и сохраненными характеристиками
        vi.clear();
        std::string buff;
        std::ifstream in(filePath_, std::ios::binary);
        int i = 1;
        while (true) {
            getline(in, buff, '\n');
            if (!in.eof()) {
                vi.push_back(i);
                std::cout << i << ". ";
                std::string::size_type n, k;
                std::string s1, s2, s3, s4;
                n = buff.find("*");
                s1 = buff.substr(0, n);
                k = buff.find("*", n + 1);
                s2 = buff.substr(n + 1, k - n - 1);
                n = k;
                k = buff.find("*", n + 1);
                s3 = buff.substr(n + 1, k - n - 1);
                n = k;
                k = buff.find("*", n + 1);
                s4 = buff.substr(n + 1, k - n - 1);
                std::cout << s1 << " : " << s2 << " : " << s3 << " : " << s4
                          << std::endl;
                ++i;
            } else
                break;
        }
        in.close();
    }

    std::string filePath_ = "saves.bin"; // Файл для сохранения
    std::vector<int> vi;
};

Player::Player(float hp, int speed, const std::string &name)
    : hp(hp), speed(speed), name(name) {}

Player::Player() : hp(0), speed(0), name("") {}

void Player::changeSpeed(int change) { speed += change; }

void Player::changeHp(int change) { hp += change; }

float Player::getHp() const { return hp; }

int Player::getSpeed() const { return speed; }

const std::string &Player::getName() const { return name; }

int main() {
    Memento m; // Тут сделал как понял задание, если не верно понял отправьте на
               // доработку
    // Создаем объект Memento который хранит методы для работы с файлом
    // сохранений

    Player p(100, 50, "Ork");
    std::cout << p.getName() << " : " << p.getHp() << " : " << p.getSpeed()
              << std::endl;
    m.addSave(p); // Сохраняем в файл состояние Player p на данный момент

    getch();

    p.changeHp(70);
    p.changeSpeed(10);
    std::cout << p.getName() << " : " << p.getHp() << " : " << p.getSpeed()
              << std::endl;
    m.addSave(p); // Сохраняем в файл состояние Player p на данный момент

    getch();

    p.changeHp(80);
    p.changeSpeed(30);
    std::cout << p.getName() << " : " << p.getHp() << " : " << p.getSpeed()
              << std::endl;
    m.addSave(p); // Сохраняем в файл состояние Player p на данный момент

    p = m.loadSave(); // Вызываем метод для восстановления

    std::cout << p.getName() << " : " << p.getHp() << " : " << p.getSpeed()
              << std::endl;

    p = m.loadSave(); // Вызываем метод для восстановления

    std::cout << p.getName() << " : " << p.getHp() << " : " << p.getSpeed()
              << std::endl;

    std::cout << std::endl;
    return 0;
}
