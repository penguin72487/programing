#include <iostream>
#include <string>

// 基礎類別
class Animal {
public:
    virtual ~Animal() = default; // 虛擬解構子
    virtual void move() const { // 虛擬函數
        std::cout << "The animal makes a sound\n";
    }
};

// 衍生類別
class Fish : public Animal {
public:
    void move() const override {
        std::cout << "swimming\n";
    }
};

class Frog : public Animal {
public:
    void move() const override {
        std::cout << "Jump\n";
    }
};

class Bird : public Animal {
public:
    void move() const override {
        std::cout << "flying\n";
    }
};

int main() {
    // 靜態繫結
    Fish myFish;
    myFish.move(); // 輸出 "Blub blub"

    // 動態繫結
    Animal* myAnimal = new Fish();
    myAnimal->move(); // 輸出 "Blub blub"

    delete myAnimal;

    myAnimal = new Frog();
    myAnimal->move(); // 輸出 "Frog

    delete myAnimal;

    myAnimal = new Bird();
    myAnimal->move(); // 輸出 "Tweet tweet"

    delete myAnimal;




    return 0;
}