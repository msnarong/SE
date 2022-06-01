#include "class.h"
#include "control.h"
#include "boundary.h"

ifstream fin(INPUT_FILE_NAME);
ofstream fout(OUTPUT_FILE_NAME);

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

// 4.1 상품 정보 검색
SearchProductUI::SearchProductUI() {}

void SearchProductUI::startInterface(SearchProduct* pSearchProduct)
{
  string productName;

  fin >> productName;

  fout << "4.1. 상품 정보 검색" << endl;
  fout << "> " << pSearchProduct->searchProduct(productName)->getProductName() << " " << pSearchProduct->searchProduct(productName)->getProductCompany() << endl; 

}

BuyListUI::BuyListUI(BuyList* pBuyList)
{
  selectBuyProduct(pBuyList);
}

void BuyListUI::selectBuyProduct(BuyList* pBuyList)
{
  pBuyList->printBuyList();
}