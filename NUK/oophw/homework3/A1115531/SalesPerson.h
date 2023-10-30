#ifndef SALESP_H
#define SALESP_H

class SalesPerson{
    public:
    SalesPerson();
    void getSalesFromUser();
    void setSales(int ,int);// 改成 int
    void printAnnualSales();
    int totalAnnualSales();//改public
    private:

    int sales[4];//銷售額改int
};

#endif