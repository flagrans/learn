#include <iostream>
#include <memory>

class Player {
private:
    class Impl;
    std::unique_ptr<Impl> pImpl;

public:
    Player(float hp, int speed, const std::string &name);
    ~Player();

    Player(const Player &other);
    Player &operator=(Player &other);

    void changeSpeed(int);
    void changeHp(int);
    float getHp() const;
    int getSpeed() const;
    const std::string &getName() const;
};

class Player::Impl {
public:
    float hp;
    int speed;
    std::string name;

    Impl(float hp, int speed, const std::string &name)
        : hp(hp), speed(speed), name(name) {
        std::cout << "Create Impl object." << std::endl;
    }
};

Player::~Player() = default;
Player::Player(const Player &other) : pImpl(new Impl(*other.pImpl)) {}
Player &Player::operator=(Player &other) {
    std::swap(pImpl, other.pImpl);
    return other;
}

Player::Player(float hp, int speed, const std::string &name)
    : pImpl(new Impl(hp, speed, name)) {}

float Player::getHp() const { return pImpl->hp; }

int Player::getSpeed() const { return pImpl->speed; }

const std::string &Player::getName() const { return pImpl->name; }

void Player::changeSpeed(int change) {
    pImpl->speed += change;
    std::cout << "Speed change on " << change
              << ", current speed = " << pImpl->speed << std::endl;
}

void Player::changeHp(int change) {
    pImpl->hp += change;
    std::cout << "HP change on " << change << ", current HP = " << pImpl->hp
              << std::endl;
}

int main() {

    Player player1(100, 50, "Ivashka");
    std::cout << "Player NAME - " << player1.getName() << std::endl;
    std::cout << "Player HP - " << player1.getHp() << std::endl;
    std::cout << "Player SPEED - " << player1.getSpeed() << std::endl;

    player1.changeHp(20);
    player1.changeSpeed(100);

    std::cout << std::endl;
    return 0;
}
