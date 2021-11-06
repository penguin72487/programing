#include <iostream>
using namespace std;
class AbCar{
    protected: std::string str_Name;
    protected: std::string str_Type;
    protected: float f_Price;

    public: virtual std::string fn_ShowCarName()= 0;
    public: virtual std::string fn_ShowCarType()= 0;
    public: virtual float fn_ShowCarPrice()= 0;
};

class Car: public AbCar{
    public: Car(std::string str_N, std::string str_T, float f_P){
		str_Name=str_N;
		str_Type=str_T;
		f_Price=f_P;
    }

    public: std::string fn_ShowCarName(){
    	return str_Name;
    }
    public: std::string fn_ShowCarType(){
		return str_Type;
    }
    public: float fn_ShowCarPrice(){
		return f_Price;
    }
};

int main(){
    Car o_Car("Marz", "General", 800000);
    std::cout<< o_Car.fn_ShowCarName()<< "\n";
    std::cout<< o_Car.fn_ShowCarType()<< "\n";
    std::cout<< o_Car.fn_ShowCarPrice()<< "\n";
    return 0;
}

