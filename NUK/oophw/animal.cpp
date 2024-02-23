#include <iostream>
#include <string>
#include<vector>
// 基礎類別
class Animal {
public:
    virtual ~Animal() = default;
    virtual void move() const = 0; // pure virtual function
};
// 衍生類別
class Fish : public Animal {
public:
    void move() const override {
        std::cout << moveType << "\n";
    }
private:
    std::string moveType = "swimming";
};

class Frog : public Animal {
public:
    void move() const override {
        std::cout << moveType << "\n";
    }
private:
    std::string moveType = "hopping";
};

class Bird : public Animal {
public:
    void move() const override {
        std::cout << moveType << "\n";
    }
private:
    std::string moveType = "flying";

};
void moveAnimal(const Animal &animal) {
    animal.move();
}
void moveAnimal(const Animal *animal) {
    animal->move();
}
int main() {
    // 靜態繫結
    Fish myFish;
    Frog myFrog;
    Bird myBird;
    myFish.move();
    myFrog.move();
    myBird.move();

    // 動態繫結
    std::vector <Animal *> animals(3);
    animals[0] = &myFish;
    animals[1] = &myFrog;
    animals[2] = &myBird;
    for (auto *animalPtr : animals) {
        moveAnimal(animalPtr);
    }
    for (auto *animalPtr : animals) {
        moveAnimal(*animalPtr);
    }




    return 0;
}