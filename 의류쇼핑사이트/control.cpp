// File : control.cpp
// Description: definition of control class and member function
#include "class.h"
#include "control.h"
#include "boundary.h"

extern Member* memberList[MAX_MEMBER_NUM];
extern Member* currentUser;
extern Product* currentProduct; // 회원 상품 정보 검색한 상품
extern ProductList* allProduct;

// Constructor : SignUp()
// Description: This is the constructor of the sign up class
// 1.1 회원가입
SignUp::SignUp()
{
    SignUpUI signupUI; // boundary class 생성
    signupUI.startInterface(this);
}

// Function : void addNewMem(string userName, int userNumber, string userID, string userPassword)
// Description: This is a function that add new member
// Parameters :   string userName – newly userName
// Parameters :   int userNumber – newly userNumber
// Parameters :   string userID – newly userID
// Parameters :   string userPassword – newly userPassword
void SignUp::addNewMem(string userName, int userNumber, string userID, string userPassword)
{
    Member* NewMem = new Member(userName, userNumber, userID, userPassword);
    for(int i=0; i < MAX_MEMBER_NUM; i++)
    {
      if (memberList[i] == NULL)
      {
        memberList[i] = NewMem;
        return;
      }
    }
}

// Constructor : DeleteAccount()
// Description: This is the constructor of the delete account class
// 1.2 회원탈퇴
DeleteAccount::DeleteAccount()
{
    DeleteAccountUI deleteUI;
    deleteUI.startInterface(this);
}

// Function : string deleteMem()
// Description: This is a function that delete member
// Return Value :  deleted userID value
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
}

// Constructor : Login()
// Description: This is the constructor of the login class
// 2.1 로그인
Login::Login()
{
  LoginUI loginUI;
  loginUI.startInterface(this);
}

// Function : bool checkAccount(string userID, string userPassword)
// Description: This is a function that check account
// Parameters :   string userID – entered user ID
// Parameters :   string userPW – entered user Password
// Return Value :  true or false
bool Login::checkAccount(string userID, string userPassword)
{
  int i;
  for(i=0; i < MAX_MEMBER_NUM; i++) // 전체 유저 for문 돌면서 id,pw 확인
  {
    if(memberList[i] != NULL && memberList[i]->checkIDandPW(userID, userPassword))
    {
      currentUser = memberList[i];
      return true;  // 로그인 성공
    }
  }
  return false; // 로그인 실패
}

// Constructor : Logout()
// Description: This is the constructor of the logout class
// 2.2 로그아웃
Logout::Logout()
{
    LogoutUI logoutUI;
    logoutUI.startInterface(this);
}

// Function : string userLogout()
// Description: This is a function that logout user
// Return Value :  userID value
string Logout::userLogout()
{
  string userID;
  userID = currentUser->logoutUser();
  currentUser = NULL;
  return userID;
}

// Constructor : EnrollProduct()
// Description: This is the constructor of the enroll product class
// 3.1 판매 의류 등록
EnrollProduct::EnrollProduct()
{
  EnrollProductUI enrollProductUI; // boundary class 생성
  enrollProductUI.startInterface(this);
}

// Function : addNewProductaddNewProduct(string productName, string productCompany, int productPrice, int productStock)
// Description: This is a function that add new product
// Parameters :   string productName – newly product name
// Parameters :   string productCompany – newly product company name
// Parameters :   string productPrice – newly product price
// Parameters :   string productStock – newly product stock
void EnrollProduct::addNewProduct(string productName, string productCompany, int productPrice, int productStock)
{
  Product * product = currentUser->getSellList()->addNewProduct(productName, productCompany, productPrice, productStock, currentUser->getUserID());
  allProduct->addNewProduct(product);
}

// Constructor : CheckSellProduct()
// Description: This is the constructor of the check sell product class
// 3.2 등록 상품 조회
CheckSellProduct::CheckSellProduct()
{
  CheckSellProductUI checkSellProductUI;
  checkSellProductUI.startInterface(this);
}

// Function : SellProductList* checkSellList()
// Description: This is a function that check sell product list
// Return Value :  current user SellProductList pointer
SellProductList* CheckSellProduct::checkSellList()
{
  return (currentUser->getSellList());
}

// Constructor : CheckSoldProduct()
// Description: This is the constructor of the check sold product class
// 3.3 판매 완료 상품 조회
CheckSoldProduct::CheckSoldProduct()
{
  CheckSoldProductUI checkSoldProductUI;
  checkSoldProductUI.startInterface(this);
}

// Function : SellProductList* showSoldProduct()
// Description: This is a function that show sold product
// Return Value :  current user SellProductList pointer
SellProductList* CheckSoldProduct::showSoldProduct()
{
  return (currentUser->getSellList());
}

// Constructor : SearchProduct()
// Description: This is the constructor of the search product class
// 4.1 상품 정보 검색
SearchProduct::SearchProduct()
{
  SearchProductUI searchProductUI;
  searchProductUI.startInterface(this);
}

// Function : Product* searchProduct(string productName)
// Description: This is a function that search product
// Parameters :   string productName – product name to find
// Return Value :  found product pointer
Product* SearchProduct::searchProduct(string productName)
{
  currentProduct = allProduct->searchProduct(productName);
  return currentProduct;
};

// Constructor : BuyProduct()
// Description: This is the constructor of the buy product class
// 4.2 상품 구매
BuyProduct::BuyProduct()
{
  BuyProductUI buyProductUI;
  buyProductUI.startInterface(this);
}

// Function : void buyProduct()
// Description: This is a function that buy product
void BuyProduct::buyProduct()
{
  currentUser->getBuyList()->addBuyProduct();
}

// Constructor : BuyList()
// Description: This is the constructor of the buy list class
// 4.3 상품 구매 내역 조회
BuyList::BuyList()
{
  BuyListUI buyListUI;
  buyListUI.startInterface(this);
}

// Function : BuyProductList* printBuyList()
// Description: This is a function that print buy product list
// Return Value :  current user BuyProductList pointer
BuyProductList* BuyList::printBuyList()
{
  return (currentUser->getBuyList());
}

// Constructor : Evaluate()
// Description: This is the constructor of the evaluate class
// 4.4. 상품 구매만족도 평가
Evaluate::Evaluate()
{
   EvaluateUI evaluateUI;
   evaluateUI.startInterface(this);
}

// Function : string evaluateProduct(string productName, double productScore)
// Description: This is a function that evaluate product
// Parameters :   string productName – product name to evaluate
// Parameters :   double productScore – entered score
// Return Value :  product seller ID value
string Evaluate::evaluateProduct(string productName, double productScore)
{
    BuyProductList* userBuyProductList = currentUser->getBuyList(); // 구매 목록 포인터 받아오기
    return userBuyProductList->evaluateProduct(productName, productScore);  // 상품 평가 후 판매자ID 반환
}

// Constructor : ShowStats()
// Description: This is the constructor of the show stats class
// 5.1. 판매 상품 통계
ShowStats::ShowStats()
{
    ShowStatsUI showstatsUI;
    showstatsUI.startInterface(this);
}

// Function : SellProductList* printStats()
// Description: This is a function that print product statistics
// Return Value :  current user SellProductList pointer
SellProductList* ShowStats::printStats()
{
    return currentUser->getSellList();  // 판매 목록 포인터 반환
}