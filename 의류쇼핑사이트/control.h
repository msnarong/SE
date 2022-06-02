// File : control.h
// Description: declaration of control class
#ifndef CONTROL_H
#define CONTROL_H

// Class : SignUp
// Description: This is a sign up class
// control class
// 1.1 회원가입
class SignUp {
  public:
    SignUp(); // 생성자
    void addNewMem(string userName, int userNumber, string userID, string userPassword);
};

// Class : DeleteAccount
// Description: This is a delete account class
// control class
// 1.2 회원탈퇴
class DeleteAccount {
  public:
    DeleteAccount(); // 생성자
    string deleteMem();
};

// Class : Login
// Description: This is a login class
// control class
// 2.1 로그인
class Login {
  public:
    Login(); // 생성자
    bool checkAccount(string userID, string userPassword);
};

// Class : Logout
// Description: This is a logout class
// control class
// 2.2 로그아웃
class Logout {
  public:
    Logout(); // 생성자
    string userLogout();
};

// Class : EnrollProduct
// Description: This is a enroll product class
// control class
// 3.1 판매 의류 등록
class EnrollProduct {
  public:
    EnrollProduct(); // 생성자
    void addNewProduct(string productName, string productCompany, int productPrice, int productStock);
};

// Class : CheckSellProduct
// Description: This is a check sell product class
// control class
// 3.2 등록 상품 조회
class CheckSellProduct {
  public:
    CheckSellProduct(); // 생성자
    SellProductList* checkSellList();
};

// Class : CheckSoldProdut
// Description: This is a check sold product class
// control class
// 3.3 판매 완료 상품 조회
class CheckSoldProduct {
  public:
    CheckSoldProduct(); // 생성자
    SellProductList* showSoldProduct();
};

// Class : SearchProduct
// Description: This is a search product class
// control class
// 4.1 상품 정보 검색
class SearchProduct {
  public:
    SearchProduct();
    Product* searchProduct(string);
};

// Class : BuyProduct
// Description: This is a buy product class
// control class
// 4.2 상품 구매
class BuyProduct {
  public:
    BuyProduct();
    void buyProduct();
};

// Class : BuyList
// Description: This is a buy list class
// control class
// 4.3 상품 구매 내역 조회
class BuyList {
  public:
    BuyList();
    BuyProductList* printBuyList();
};

// Class : Evaluate
// Description: This is a evaluate class
// control class
// 4.4. 상품 구매만족도 평가
class Evaluate {
  public:
    Evaluate();
    string evaluateProduct(string productName, double productScore);
};

// Class : ShowStats
// Description: This is a show stats class
// control class
// 5.1. 판매 상품 통계
class ShowStats {
  public:
    ShowStats();
    SellProductList* printStats();
};

#endif