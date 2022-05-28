#include "class.h"
#include "control.h"
#include "boundary.h"

ifstream fin(INPUT_FILE_NAME);
ofstream fout(OUTPUT_FILE_NAME);

LoginUI::LoginUI(Login* pLogin)
{
  login(pLogin);
}

void LoginUI::login(Login* pLogin)
{
  char userID[MAX_STRING], userPassword[MAX_STRING];

  fin >> userID;
  fin >> userPassword;
  pLogin->checkAccount(userID, userPassword);
}

EnrollProductUI::EnrollProductUI(EnrollProduct* pEnrollProduct)
{
  createNewProduct(pEnrollProduct);
}

void EnrollProductUI::createNewProduct(EnrollProduct* pEnrollProduct)
{
  char productName[MAX_STRING], productCompany[MAX_STRING];
  int productPrice, num;

  fin >> productName;
  fin >> productCompany;
  fin >> productPrice;
  fin >> num;
  pEnrollProduct->addNewProduct(productName, productCompany, productPrice);
}

BuyListUI::BuyListUI(BuyList* pBuyList)
{
  selectBuyProduct(pBuyList);
}

void BuyListUI::selectBuyProduct(BuyList* pBuyList)
{
  pBuyList->printBuyList();
}