#include "class.h"
#include "control.h"
#include "boundary.h"

// 1.1 회원가입
SignUp::SignUp() 
{
    SignUpUI signupUI; // boundary class 생성
    signupUI.startInterface(this);
}

void SignUp::addNewMem(string userName, int userNumber, string userID, string userPassword) 
{
    Member* NewMem = new Member(userName, userNumber, userID, userPassword);
    for(int i=0; i < MAX_MEMBER_NUM; i++)
    {
      if (memberList[i] == NULL)
      {
        memberList[i] = NewMem;
      }
    }
}
// signup control

// 1.2 회원탈퇴
DeleteAccount::DeleteAccount()
{
    DeleteAccountUI deleteUI;
    deleteUI.startInterface(this);
}

string DeleteAccount::deleteMem()
{
    return currentUser->deleteMem(); 
}
// delete control

// 2.1 로그인
Login::Login()
{
  LoginUI loginUI;
  loginUI.startInterface(this);
}

bool Login::checkAccount(string userID, string userPassword)
{
  int i;
  for(i=0; i < MAX_MEMBER_NUM; i++) // 전체 유저 for문 돌면서 id,pw 확인
  {
    if(memberList[i]->checkIDandPW(userID, userPassword))
    {
      currentUser = &memberList[i];
      currentUser->logState = true;
      return true;  // 로그인 성공
    }
  }
  return false; // 로그인 실패
}
// login control 

// 2.2 로그아웃
Logout::Logout() 
{
    LogoutUI logoutUI;
    logoutUI.startInterface(this);
}

string Logout::userLogout()
{
    return currentUser->logoutUser();
}
// logout control

// 3.1 판매 의류 등록
EnrollProduct::EnrollProduct()
{
  EnrollProductUI enrollProductUI; // boundary class 생성
  enrollProductUI.startInterface(this);
}

void EnrollProduct::addNewProduct(string productName, string productCompany, int productPrice, int productStock)
{
  currentUser->getSellList()->addNewProduct(productName, productCompany, productPrice, productStock);
}

// 3.2 등록 상품 조회
CheckSellProduct::CheckSellProduct()
{
  CheckSellProductUI checkSellProductUI;
  checkSellProductUI.startInterface(this);
}

SellProductList* CheckSellProduct::checkSellList()
{
  return (currentUser->getSellList());
}

// 3.3 판매 완료 상품 조회
CheckSoldProduct::CheckSoldProduct()
{
  CheckSoldProductUI checkSoldProductUI;
  checkSoldProductUI.startInterface(this);
}

// 4.1 상품 정보 검색
SearchProduct::SearchProduct()
{
  SearchProductUI searchProductUI;
  searchProductUI.startInterface(this);
}

Product* SearchProduct::searchProduct(string productName)
{
  return allProduct->searchProduct(productName);
};

BuyList::BuyList()
{
  BuyList* pBuyList;
  BuyListUI BuyListUI1(pBuyList);
}

void BuyList::printBuyList()
{
  currentUser->getBuyList()->showBuyProductList();
}