// File : boundary.h
// Description: declaration of boundary class
#ifndef BOUNDARY_H
#define BOUNDARY_H

// Class : SignUpUI
// Description: This is a sign up UI class
// boundary class
// 1.1 회원가입
class SignUpUI {
  public:
    SignUpUI();
    void startInterface(SignUp* pSignUp);
};

// Class : DeleteAccountUI
// Description: This is a delete account UI class
// boundary class
// 1.2 회원탈퇴
class DeleteAccountUI {
  public:
    DeleteAccountUI();
    void startInterface(DeleteAccount* pDeleteAccount);
};

// Class : LoginUI
// Description: This is a login UI class
// boundary class
// 2.1 로그인 
class LoginUI {
  public:
    LoginUI();
    void startInterface(Login* pLogin);
};

// Class : LogoutUI
// Description: This is a logout UI class
// boundary class
// 2.2 로그아웃
class LogoutUI {
  public:
    LogoutUI();
    void startInterface(Logout* pLogout);
};

// Class : EnrollProductUI
// Description: This is a enroll product UI class
// boundary class
// 3.1 판매 의류 등록
class EnrollProductUI {
  public:
    EnrollProductUI();
    void startInterface(EnrollProduct* pEnrollProduct);
};

// Class : CheckSellProductUI
// Description: This is a check sell product UI class
// boundary class
// 3.2 등록 상품 조회
class CheckSellProductUI {
  public:
    CheckSellProductUI();
    void startInterface(CheckSellProduct* pCheckSellProduct);
};

// Class : CheckSoldProdutUI
// Description: This is a check sold product UI class
// boundary class
// 3.3 판매 완료 상품 조회
class CheckSoldProductUI {
  public:
    CheckSoldProductUI();
    void startInterface(CheckSoldProduct* pCheckSoldProduct);
};

// Class : SearchProductUI
// Description: This is a search product UI class
// boundary class
// 4.1 상품 정보 검색
class SearchProductUI {
  public:
    SearchProductUI();
    void startInterface(SearchProduct* pSearchProduct);
};

// Class : BuyProductUI
// Description: This is a buy product UI class
// boundary class
// 4.2 상품 구매
class BuyProductUI {
  public:
    BuyProductUI();
    void startInterface(BuyProduct* pBuyProduct);
};

// Class : BuyListUI
// Description: This is a buy list UI class
// boundary class
// 4.3 상품 구매 내역 조회
class BuyListUI {
  public:
    BuyListUI();
    void startInterface(BuyList* pBuyList);
};

// Class : EvaluateUI
// Description: This is a evaluate UI class
// boundary class
// 4.4. 상품 구매만족도 평가
class EvaluateUI {
  public:
    EvaluateUI();
    void startInterface(Evaluate* pEvaluate);
};

// Class : ShowStatsUI
// Description: This is a show stats UI class
// boundary class
// 5.1. 판매 상품 통계
class ShowStatsUI {
  public:
    ShowStatsUI();
    void startInterface(ShowStats* pShowStats);
};

#endif