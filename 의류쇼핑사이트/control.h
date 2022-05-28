#ifndef CONTROL_H
#define CONTROL_H

class Login {
  public:
    Login();
    void checkAccount(string userID, string userPassword);
};

class EnrollProduct {
  public:
    EnrollProduct();
    void addNewProduct(string productName, string productCompany, int productPrice);
};

class BuyList {
  public:
    BuyList();
    void printBuyList();
};
#endif