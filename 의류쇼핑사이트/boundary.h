#ifndef BOUNDARY_H
#define BOUNDARY_H

class LoginUI {
  public:
    LoginUI(Login* pLogin);
    void login(Login* pLogin);
};

class EnrollProductUI {
  public:
    EnrollProductUI(EnrollProduct* pEnrollProduct);
    void createNewProduct(EnrollProduct* pEnrollProduct);
};

class BuyListUI {
  public:
    BuyListUI(BuyList* pBuyList);
    void selectBuyProduct(BuyList* pBuyList);
};
#endif