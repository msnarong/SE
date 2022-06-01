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
  string deleteID;

  for (int n = 0; n < MAX_MEMBER_NUM; n++) {
		if (currentUser == memberList[n])
      deleteID = memberList[n]->getUserID();
			memberList[n] = NULL;
	}
	currentUser = NULL;
  return deleteID;
  //return currentUser->deleteMem(); 
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
      currentUser = memberList[i];
      //currentUser->logState = true;
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
  string userID;
  userID = currentUser->logoutUser();
  currentUser = NULL;
  return userID;
  //return currentUser->logoutUser();
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

SellProductList* CheckSoldProduct::showSoldProduct()
{
  return (currentUser->getSellList());
}

// 4.1 상품 정보 검색
SearchProduct::SearchProduct()
{
  SearchProductUI searchProductUI;
  searchProductUI.startInterface(this);
}

Product* SearchProduct::searchProduct(string productName)
{
  currentProduct = allProduct->searchProduct(productName);
  return currentProduct;
};

// 4.2 상품 구매
BuyProduct::BuyProduct()
{
  BuyProductUI buyProductUI;
  buyProductUI.startInterface(this);
}

void BuyProduct::buyProduct()
{
  currentProduct->buyProduct();
}

// 4.3 상품 구매 내역 조회
BuyList::BuyList()
{
  BuyListUI buyListUI;
  buyListUI.startInterface(this);
}

BuyProductList* BuyList::printBuyList()
{
  return (currentUser->getBuyList());
}

// 4.4. 상품 구매만족도 평가
Evaluate::Evaluate()
{
   EvaluateUI evaluateUI;
   evaluateUI.startInterface(this);
}
string Evaluate::evaluateProduct(string productName, double productScore)
{
    BuyProductList* userBuyProductList = currentUser->getBuyList(); // 구매 목록 포인터 받아오기
    return userBuyProductList->evaluateProduct(productName, productScore);  // 상품 평가 후 판매자ID 반환
}

// 5.1. 판매 상품 통계
ShowStats::ShowStats()
{
    ShowStatsUI showstatsUI;
    showstatsUI.startInterface(this);
}
SellProductList* ShowStats::printStats()
{
    return currentUser->getSellList();  // 판매 목록 포인터 반환
}
