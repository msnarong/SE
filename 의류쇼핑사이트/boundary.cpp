#include "class.h"
#include "control.h"
#include "boundary.h"

static ifstream fin(INPUT_FILE_NAME);
static ofstream fout(OUTPUT_FILE_NAME);

// 1.1 회원가입
SignUpUI::SignUpUI() {}

void SignUpUI::startInterface(SignUp* pSignUp)
{
    string userName, userID, userPassword;
    int userNumber;
    
    fin >> userName >> userNumber >> userID >> userPassword;
    pSignUp->addNewMem(userName, userNumber, userID, userPassword);
    
    fout << "1.1. 회원가입" << endl;
    fout << "> " << userName << " " << userNumber << " " << userID << " " << userPassword << endl;
}
// signup boundary

// 1.2 회원탈퇴
DeleteAccountUI::DeleteAccountUI() {}

void DeleteAccountUI::startInterface(DeleteAccount* pDeleteAccount) 
{
    string userID;
    
    userID = pDeleteAccount->deleteMem();
    fout << "1.2. 회원탈퇴" << endl;
    fout << "> " << userID << endl;
}

// 2.1 로그인
LoginUI::LoginUI() {}

void LoginUI::startInterface(Login* pLogin)
{
  char userID[MAX_STRING], userPassword[MAX_STRING];
    
  fin >> userID;
  fin >> userPassword;
  fout << "2.1. 로그인\n";
  if(pLogin->checkAccount(userID, userPassword)) {
      fout << "> " <<userID << " " << userPassword << endl;
  } else {
      fout << "> " << "로그인 실패" << endl;
  }
}
// login boundary

// 2.2 로그아웃
LogoutUI::LogoutUI() {}

void LogoutUI::startInterface(Logout* pLogout) {
    string currentUserName;

    currentUserName = pLogout->userLogout();
    fout << "2.2. 로그아웃" << endl;
    fout << "> " << currentUserName << endl;
}
// logout boundary

// 3.1 판매 의류 등록
EnrollProductUI::EnrollProductUI() {}

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
}

// 3.2 등록 상품 조회
CheckSellProductUI::CheckSellProductUI() {}

void CheckSellProductUI::startInterface(CheckSellProduct* pCheckSellProduct)
{
  int sellCount = pCheckSellProduct->checkSellList()->getSellCount();
  fout << "3.2. 등록 상품 조회" << endl;
  for (int i=0; i < sellCount; i++)
  {
    fout << "> " << pCheckSellProduct->checkSellList()->showSellProductList(i)->getProductName() << endl;
  }
}

// 3.3 판매 완료 상품 조회
CheckSoldProductUI::CheckSoldProductUI() {}

void CheckSoldProductUI::startInterface(CheckSoldProduct* pCheckSoldProduct)
{
  int sellCount = pCheckSoldProduct->showSoldProduct()->getSellCount();

  fout << "3.3. 판매 완료 상품 조회" << endl;
  int productStock;
  for (int i=0; i < sellCount; i++)
  {
    productStock = pCheckSoldProduct->showSoldProduct()->showSellProductList(i)->getProductStock();
    if (productStock == 0)
    {
      fout << "> " << pCheckSoldProduct->showSoldProduct()->showSellProductList(i)->getProductName() << " " << pCheckSoldProduct->showSoldProduct()->showSellProductList(i)->getProductCompany() << " " << pCheckSoldProduct->showSoldProduct()->showSellProductList(i)->getProductPrice() << " " << pCheckSoldProduct->showSoldProduct()->showSellProductList(i)->getProductSold() << " " << pCheckSoldProduct->showSoldProduct()->showSellProductList(i)->getProductScore() << endl;
    }
  }
}

// 4.1 상품 정보 검색
SearchProductUI::SearchProductUI() {}

void SearchProductUI::startInterface(SearchProduct* pSearchProduct)
{
  string productName;

  fin >> productName;

  fout << "4.1. 상품 정보 검색" << endl;
  fout << "> " << pSearchProduct->searchProduct(productName)->getSellerID() << " " << pSearchProduct->searchProduct(productName)->getProductName() << " " << pSearchProduct->searchProduct(productName)->getProductCompany() << " " << pSearchProduct->searchProduct(productName)->getProductPrice() << " " << pSearchProduct->searchProduct(productName)->getProductStock() << " " << pSearchProduct->searchProduct(productName)->getProductScore() << endl;

}

// 4.2 상품 구매
BuyProductUI::BuyProductUI() {}

void BuyProductUI::startInterface(BuyProduct* pBuyProduct)
{
  pBuyProduct->buyProduct();
  fout << "4.2. 상품 구매" << endl;
  fout << "> " << currentProduct->getSellerID() << " " << currentProduct->getProductName() << endl;
}

// 4.3 상품 구매 내역 조회
BuyListUI::BuyListUI() {}

void BuyListUI::startInterface(BuyList* pBuyList)
{
  int buyCount = pBuyList->printBuyList()->getBuyCount();

  fout << "4.3. 상품 구매 내역 조회" << endl;
  for (int i=0; i < buyCount; i++)
  {
    fout << "> " << pBuyList->printBuyList()->showBuyProductList(i)->getProductName() << endl;
  }
}

// 4.4. 상품 구매만족도 평가
EvaluateUI::EvaluateUI() {}

void EvaluateUI::startInterface(Evaluate* pEvaluate) 
{
    string productName;
    double productScore;
    fin >> productName >> productScore;
    
    string sellerID = pEvaluate->evaluateProduct(productName, productScore); // 상품만족도 평가 정보 추가 후 판매자ID 받아오기
    fout << "4.4. 상품 구매만족도 평가" << endl;
    fout << "> " << sellerID << " " << productName << " " << productScore;  // 파일 입력
}

// 5.1. 판매 상품 통계
ShowStatsUI::ShowStatsUI() {}

void ShowStatsUI::startInterface(ShowStats* pShowStats) 
{
    
    fout << "5.1. 판매 상품 통계" << endl;
    
    SellProductList* userSellProductList = pShowStats->printStats();
    int sellCount = userSellProductList->getSellCount();
    int i = 0;
    string productStatistics; // 상품명 + 상품 판매 총액 + 평균 구매만족도
    for(i; i < sellCount; i++) {
        productStatistics = userSellProductList->showProductStatistics(i);
        fout << "> " << productStatistics;  // 파일 입력
    
    }
}
