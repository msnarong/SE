#ifndef CLASS_H
#define CLASS_H

// 헤더 선언
#include <iostream>
#include <fstream>
using namespace std;

// 상수 선언
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

#define MAX_MEMBER_NUM 50
#define MAX_PRODUCT_NUM 100

Member* memberList[MAX_MEMBER_NUM];
Member* currentUser;

class Member {
  private:
    string userID;
    string userPassword;
    string userName;
    int userNumber;
    bool logState;              // 로그인 상태
    BuyProductList* buyList;    // 구매 목록 포인터
    SellProductList* sellList;  // 판매 목록 포인터
    
    void setUserID(string);
    string getUserID();
    
    void setUserNumber(int);
    int getUserNumber();
    
    void setUserPassword(string);
    string getUserPassword();
    
    void setUserName(string);
    string getUserName();
  public:
    Member(string, int, string, string); // 생성자
    //void addMember(Member);
    bool checkIDandPW(string, string); // 로그인 (id, pw)
    //void deleteMem(Member);          // 회원탈퇴 
    void LogoutUser();              // 로그아웃
    BuyProductList* getBuyList();   // 구매목록 
    SellProductList* getSellList(); // 판매목록
    
};

class ProductList {
  private:
    Product* productList[MAX_PRODUCT_NUM];
  public:
    void searchProduct(string);
};

class Product {
  private:
    string productName;
    string productCompany;
    int productPrice;       // 가격
    int productStock;       // 재고
    int productSold;        // 판매량
    double productScore;    // 평점..
    int scoreCount;         // 평가 수
    string sellerID;
  public:
    Product(string, string, int, int); // 생성자
    void getProductDetails();   // 물품 상세 정보 출력
    //void createNewProduct();    // 새 물품추가 # 생성자로 대신 
    void addBuyScore(double);   // 물품 평가 (평점)
    void buyProduct(int);       // 물품 구매 (구매 수량)
    int getIncome();            // 물품 총판매금액 반환 
    double getScore();          // 물품 평점 반환 
};

class BuyProductList {
  private:
    Product* productList[MAX_PRODUCT_NUM];
  public:
    void addBuyProduct(string, int);    // 물품 구매
    void showBuyProductList();  // 구매 목록 출력
    void evaluateProduct(int);  // 물품 평가
};

class SellProductList {
  private:
    Product* productList[MAX_PRODUCT_NUM];
  public:
    void showSoldProduct();     // 판매 완료 목록 출력
    int getTotalIncome();       // 총 판매액 출력
    double getScoreAvg();       // 평균 구매만족도 출력
    void showSellProductList(); // 판매 물품 목록 출력
    void addSellProduct();       // 판매 물품 등록(이름변경!)
};

#endif