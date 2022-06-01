#ifndef CONTROL_H
#define CONTROL_H

// 1.1 회원가입
class SignUp {
  public:
    SignUp(); // 생성자
    void addNewMem(string userName, int userNumber, string userID, string userPassword);
};

// 1.2 회원탈퇴
class DeleteAccount {
  public:
    DeleteAccount(); // 생성자
    string deleteMem();
};

// 2.1 로그인
class Login {
  public:
    Login(); // 생성자
    bool checkAccount(string userID, string userPassword);
};

// 2.2 로그아웃
class Logout {
  public:
    Logout(); // 생성자
    string userLogout();
};

// 3.1 판매 의류 등록
class EnrollProduct {
  public:
    EnrollProduct(); // 생성자
    void addNewProduct(string productName, string productCompany, int productPrice, int productStock);
};

// 3.2 등록 상품 조회
class CheckSellProduct {
  public:
    CheckSellProduct(); // 생성자
    SellProductList* checkSellList(); 
};

// 3.3 판매 완료 상품 조회
class CheckSoldProduct {
  public:
    CheckSoldProduct(); // 생성자
};

// 4.1 상품 정보 검색
class SearchProduct {
  public:
    SearchProduct();
    Product* searchProduct(string);
};

class BuyList {
  public:
    BuyList();
    void printBuyList();
};


#endif