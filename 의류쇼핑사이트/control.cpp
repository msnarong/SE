#include "class.h"
#include "control.h"
#include "boundary.h"

Login::Login()
{
  Login* pLogin;
  LoginUI LoginUI1(pLogin);
}

void Login::checkAccount(string id, string password)
{
  int i = 0;
  while (memberList[i])
  {
    if(memberList[i]->checkIDandPW(id, password))
    {
      currentUser = &memberList[i];
      currentUser->logState = true;
    }
  }
}

EnrollProduct::EnrollProduct()
{
  EnrollProduct* pEnrollProduct;
  EnrollProductUI EnrollUI1(pEnrollProduct); // boundary class 생성
}

void EnrollProduct::addNewProduct(string productName, string productCompany, int productPrice)
{
  currentUser->getSellList()->addSellProduct();
}

BuyList::BuyList()
{
  BuyList* pBuyList;
  BuyListUI BuyListUI1(pBuyList);
}

void BuyList::printBuyList()
{
  currentUser->getBuyList()->showBuyProductList();
}