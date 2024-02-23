#include <iostream>
#include <string>

// 基礎類別 Package
class Package {
private:
    std::string name;
    std::string address;
    std::string city;
    std::string state;
    std::string zip;
    double weight; // 重量
    double costPerOunce; // 每盎司的費用

public:
    Package(const std::string &name, const std::string &addr, const std::string &city,
            const std::string &state, const std::string &zip, double weight, double costPerOunce)
        : name(name), address(addr), city(city), state(state), zip(zip), weight(weight), costPerOunce(costPerOunce) {
        // 這裡應該加入檢查重量和每盎司費用是否為正的代碼
    }

    // 計算運費的函數
    virtual double calculateCost() const {
        return weight * costPerOunce;
    }
    double getWeight() const {
        return weight;
    }
    double getCostPerOunce() const {
        return costPerOunce;
    }

};

// 衍生類別 TwoDayPackage
class TwoDayPackage : public Package {
private:
    double flatFee; // 額外的固定費用

public:
    TwoDayPackage(const std::string &name, const std::string &addr, const std::string &city,
                  const std::string &state, const std::string &zip, double weight, double costPerOunce, double flatFee)
        : Package(name, addr, city, state, zip, weight, costPerOunce), flatFee(flatFee) {}

    // 覆蓋計算運費的函數
    double calculateCost() const override {
        return Package::calculateCost() + flatFee;
    }

};

// 衍生類別 OvernightPackage
class OvernightPackage : public Package {
private:
    double overnightFeePerOunce; // 每盎司的額外費用

public:
    OvernightPackage(const std::string &name, const std::string &addr, const std::string &city,
                     const std::string &state, const std::string &zip, double weight, double costPerOunce, double overnightFee)
        : Package(name, addr, city, state, zip, weight, costPerOunce), overnightFeePerOunce(overnightFee) {}

    // 覆蓋計算運費的函數
    double calculateCost() const override {
        return Package::calculateCost() + getWeight() * overnightFeePerOunce;
    }

    // ... 其他成員函數 ...
};

// 主函數
int main() {
    // 創建 Package 對象
    Package package("John Doe", "123 Main St", "Anytown", "Anystate", "12345", 10.0, 0.5);
    std::cout << "Standard Package Cost: $" << package.calculateCost() << std::endl;

    // 創建 TwoDayPackage 對象
    TwoDayPackage twoDayPackage("Jane Smith", "456 Oak St", "Elsewhere", "Otherstate", "67890", 5.0, 0.5, 2.0);
    std::cout << "Two Day Package Cost: $" << twoDayPackage.calculateCost() << std::endl;

    // 創建 OvernightPackage 對象
    OvernightPackage overnightPackage("Alice Jones", "789 Pine St", "Smalltown", "Sidestate", "13579", 2.0, 0.5, 1.0);
    std::cout << "Overnight Package Cost: $" << overnightPackage.calculateCost() << std::endl;

    return 0;
}
