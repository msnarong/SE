#ifndef BOUNDARY_H
#define BOUNDARY_H

// 1.1 회원가입
class SignUpUI {
  public:
    SignUpUI();
    void startInterface(SignUp* pSignUp);
};

// 1.2 회원탈퇴
class DeleteAccountUI {
  public:
    DeleteAccountUI();
    void startInterface(DeleteAccount* pDeleteAccount);
};

// 2.1 로그인 
class LoginUI {
  public:
    LoginUI();
    void startInterface(Login* pLogin);
};

// 2.2 로그아웃
class LogoutUI {
  public:
    LogoutUI();
    void startInterface(Logout* pLogout);
};

// 3.1 판매 의류 등록
class EnrollProductUI {
  public:
    EnrollProductUI();
    void startInterface(EnrollProduct* pEnrollProduct);
};

// 3.2 등록 상품 조회
class CheckSellProductUI {
  public:
    CheckSellProductUI();
    void startInterface(CheckSellProduct* pCheckSellProduct);
};

// 3.3 판매 완료 상품 조회
class CheckSoldProductUI {
  public:
    CheckSoldProductUI();
    void startInterface(CheckSoldProduct* pCheckSoldProduct);
};

// 4.1 상품 정보 검색
class SearchProductUI {
  public:
    SearchProductUI();
    void startInterface(SearchProduct* pSearchProduct);
};

// 4.2 상품 구매
class BuyProductUI {

};


class BuyListUI {
  public:
    BuyListUI(BuyList* pBuyList);
    void selectBuyProduct(BuyList* pBuyList);
};
#endif