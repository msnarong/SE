// File : boundary.cpp
// Description: definition of boundary class and member function
#include "class.h"
#include "control.h"
#include "boundary.h"

extern ifstream fin;
extern ofstream fout;

extern Member* memberList[MAX_MEMBER_NUM];
extern Member* currentUser;
extern Product* currentProduct; // 회원 상품 정보 검색한 상품
extern ProductList* allProduct;

// Constructor : SellProductList()
// Description: This is the constructor of the sign up UI class
// 1.1 회원가입
SignUpUI::SignUpUI() {}

// Function : void startInterface(SignUp* pSignUp)
// Description: This is a function that start interface
// Parameters :   SignUp* pSignUp – SignUp class pointer
void SignUpUI::startInterface(SignUp* pSignUp)
{
    string userName, userID, userPassword;
    int userNumber;

    fin >> userName >> userNumber >> userID >> userPassword;
    pSignUp->addNewMem(userName, userNumber, userID, userPassword);

    fout << "1.1. 회원가입" << endl;
    fout << "> " << userName << " " << userNumber << " " << userID << " " << userPassword << endl;
    fout << endl;
}

// Constructor : DeleteAccountUI()
// Description: This is the constructor of the delete account UI class
// 1.2 회원탈퇴
DeleteAccountUI::DeleteAccountUI() {}

// Function : void startInterface(DeleteAccount* pDeleteAccount)
// Description: This is a function that start interface
// Parameters :   DeleteAccount* pDeleteAccount – DeleteAccount class pointer
void DeleteAccountUI::startInterface(DeleteAccount* pDeleteAccount)
{
    string userID;

    userID = pDeleteAccount->deleteMem();
    fout << "1.2. 회원탈퇴" << endl;
    fout << "> " << userID << endl;
    fout << endl;
}

// Constructor : LoginUI()
// Description: This is the constructor of the login UI class
// 2.1 로그인
LoginUI::LoginUI() {}

// Function : void startInterface(Login* pLogin)
// Description: This is a function that start interface
// Parameters :   Login* pLogin – Login class pointer
void LoginUI::startInterface(Login* pLogin)
{
  char userID[MAX_STRING], userPassword[MAX_STRING];

  fin >> userID >> userPassword;
  fout << "2.1. 로그인\n";
  if(pLogin->checkAccount(userID, userPassword)) {
      fout << "> " <<userID << " " << userPassword << endl;
  } else {
      fout << "> " << "로그인 실패" << endl;
  }
  fout << endl;
}

// Constructor : LogoutUI()
// Description: This is the constructor of the logout UI class
// 2.2 로그아웃
LogoutUI::LogoutUI() {}

// Function : void startInterface(Logout* pLogout)
// Description: This is a function that start interface
// Parameters :   Logout* pLogout – Logout class pointer
void LogoutUI::startInterface(Logout* pLogout) {
    string currentUserName;

    currentUserName = pLogout->userLogout();
    fout << "2.2. 로그아웃" << endl;
    fout << "> " << currentUserName << endl;
    fout << endl;
}

// Constructor : EnrollProductUI()
// Description: This is the constructor of the enroll product UI class
// 3.1 판매 의류 등록
EnrollProductUI::EnrollProductUI() {}

// Function : void startInterface(EnrollProduct* pEnrollProduct)
// Description: This is a function that start interface
// Parameters :   EnrollProduct* pEnrollProduct – EnrollProduct class pointer
void EnrollProductUI::startInterface(EnrollProduct* pEnrollProduct)
{
  string productName, productCompany;
  int productPrice, productStock;

  fin >> productName;
  fin >> productCompany;
  fin >> productPrice;
  fin >> productStock;
  pEnrollProduct->addNewProduct(productName, productCompany, productPrice, productStock);
  fout << "3.1. 판매 의류 등록" << endl;
  fout << "> " << productName << " " << productCompany << " " << productPrice << " " << productStock << endl;
  fout << endl;
}

// Constructor : CheckSellProductUI()
// Description: This is the constructor of the check sell product UI class
// 3.2 등록 상품 조회
CheckSellProductUI::CheckSellProductUI() {}

// Function : void startInterface(CheckSellProduct* pCheckSellProduct)
// Description: This is a function that start interface
// Parameters :   CheckSellProduct* pCheckSellProduct – CheckSellProduct class pointer
void CheckSellProductUI::startInterface(CheckSellProduct* pCheckSellProduct)
{
  vector<string> productDataList;

  int sellCount = pCheckSellProduct->checkSellList()->getSellCount();
  SellProductList* userSellList = pCheckSellProduct->checkSellList();

  fout << "3.2. 등록 상품 조회" << endl;
  for (int i=0; i < sellCount; i++)
  {
     productDataList.push_back(userSellList->showSellProductList(i)->getProductName() + " " +
     userSellList->showSellProductList(i)->getProductCompany() + " " +
     to_string(userSellList->showSellProductList(i)->getProductPrice()) + " " +
     to_string(userSellList->showSellProductList(i)->getProductStock()));
  }

  sort(productDataList.begin(), productDataList.end());

  for (int i=0; i < sellCount; i++)
  {
    fout << "> " << productDataList[i] << endl;
  }
  fout << endl;
}

// Constructor : CheckSoldProductUI()
// Description: This is the constructor of the check sold product UI class
// 3.3 판매 완료 상품 조회
CheckSoldProductUI::CheckSoldProductUI() {}

// Function : void startInterface(CheckSoldProduct* pCheckSoldProduct)
// Description: This is a function that start interface
// Parameters :   CheckSoldProduct* pCheckSoldProduct – CheckSoldProduct class pointer
void CheckSoldProductUI::startInterface(CheckSoldProduct* pCheckSoldProduct)
{

  vector<string> userSoldProductList;

  SellProductList* userSellProductList = pCheckSoldProduct->showSoldProduct();
  int sellCount = pCheckSoldProduct->showSoldProduct()->getSellCount();

  fout << "3.3. 판매 완료 상품 조회" << endl;
  int productStock;
  for (int i=0; i < sellCount; i++)
  {
    productStock = userSellProductList->showSellProductList(i)->getProductStock();
    if (productStock == 0)
    {
      userSoldProductList.push_back(userSellProductList->showSellProductList(i)->getProductName() + " " +
      userSellProductList->showSellProductList(i)->getProductCompany() + " " +
      to_string(userSellProductList->showSellProductList(i)->getProductPrice()) + " " +
      to_string(userSellProductList->showSellProductList(i)->getProductSold()) + " " +
      to_string(userSellProductList->showSellProductList(i)->getProductScore()));
    }
  }

  sort(userSoldProductList.begin(), userSoldProductList.end());

  for (int i=0; i < userSoldProductList.size(); i++)
  {
    fout << "> " << userSoldProductList[i] << endl;
  }
  fout << endl;
}

// Constructor : SearchProductUI()
// Description: This is the constructor of the search product UI class
// 4.1 상품 정보 검색
SearchProductUI::SearchProductUI() {}

// Function : void startInterface(SearchProduct* pSearchProduct)
// Description: This is a function that start interface
// Parameters :   SearchProduct* pSearchProduct – SearchProduct class pointer
void SearchProductUI::startInterface(SearchProduct* pSearchProduct)
{
  string productName;

  fin >> productName;
  Product * searchproduct = pSearchProduct->searchProduct(productName);
  fout << "4.1. 상품 정보 검색" << endl;
  fout << "> " << searchproduct->getSellerID() << " " << searchproduct->getProductName() << " " << searchproduct->getProductCompany() << " " << searchproduct->getProductPrice() << " " << searchproduct->getProductStock() << " " << searchproduct->getProductScore() << endl;
  fout << endl;
}

// Constructor : BuyProductUI()
// Description: This is the constructor of the buy product UI class
// 4.2 상품 구매
BuyProductUI::BuyProductUI() {}

// Function : void startInterface(BuyProduct* pBuyProduct)
// Description: This is a function that start interface
// Parameters :   BuyProduct* pBuyProduct – BuyProduct class pointer
void BuyProductUI::startInterface(BuyProduct* pBuyProduct)
{
  pBuyProduct->buyProduct();

  fout << "4.2. 상품 구매" << endl;
  fout << "> " << currentProduct->getSellerID() << " " << currentProduct->getProductName() << endl;

  fout << endl;
}

// Constructor : BuyListUI()
// Description: This is the constructor of the buy list UI class
// 4.3 상품 구매 내역 조회
BuyListUI::BuyListUI() {}

// Function : void startInterface(BuyList* pBuyList)
// Description: This is a function that start interface
// Parameters :   BuyList* pBuyList – BuyList class pointer
void BuyListUI::startInterface(BuyList* pBuyList)
{
  int buyCount = pBuyList->printBuyList()->getBuyCount();
  BuyProductList* userbuyList = pBuyList->printBuyList();
  fout << "4.3. 상품 구매 내역 조회" << endl;
  for (int i=0; i < buyCount; i++)
  {
    fout << "> " << userbuyList->showBuyProductList(i)->getSellerID() << " "
                 << userbuyList->showBuyProductList(i)->getProductName() << " "
                 << userbuyList->showBuyProductList(i)->getProductCompany() << " "
                 << userbuyList->showBuyProductList(i)->getProductPrice() << " "
                 << userbuyList->showBuyProductList(i)->getProductStock() << " "
                 << userbuyList->showBuyProductList(i)->getProductScore() << endl;;
  }
  fout << endl;
}

// Constructor : EvaluateUI()
// Description: This is the constructor of the evaluate UI class
// 4.4. 상품 구매만족도 평가
EvaluateUI::EvaluateUI() {}

// Function : void startInterface(Evaluate* pEvaluate)
// Description: This is a function that start interface
// Parameters :   Evaluate* pEvaluate – Evaluate class pointer
void EvaluateUI::startInterface(Evaluate* pEvaluate)
{
    string productName;
    double productScore;
    fin >> productName >> productScore;

    string sellerID = pEvaluate->evaluateProduct(productName, productScore); // 상품만족도 평가 정보 추가 후 판매자ID 받아오기
    fout << "4.4. 상품 구매만족도 평가" << endl;
    fout << "> " << sellerID << " " << productName << " " << productScore << endl;  // 파일 입력

    fout << endl;
}

// Constructor : ShowStatsUI()
// Description: This is the constructor of the show stats UI class
// 5.1. 판매 상품 통계
ShowStatsUI::ShowStatsUI() {}

// Function : void startInterface(ShowStats* pShowStats)
// Description: This is a function that start interface
// Parameters :   ShowStats* pShowStats – ShowStats class pointer
void ShowStatsUI::startInterface(ShowStats* pShowStats)
{

    vector<string> productStatsList;

    fout << "5.1. 판매 상품 통계" << endl;

    SellProductList* userSellProductList = pShowStats->printStats();
    int sellCount = userSellProductList->getSellCount();
    int i = 0;
    string productStatistics; // 상품명 + 상품 판매 총액 + 평균 구매만족도
    for(i; i < sellCount; i++) {
        productStatistics = userSellProductList->showProductStatistics(i);
        productStatsList.push_back(productStatistics);
    }

    sort(productStatsList.begin(), productStatsList.end());

    i = 0;
    for(i; i < productStatsList.size(); i++) {
        fout << "> " << productStatsList[i] << endl;
    }
    fout << endl;
}
