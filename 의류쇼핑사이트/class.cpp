#include "class.h"

ifstream fin(INPUT_FILE_NAME);
ofstream fout(OUTPUT_FILE_NAME);

// Member
string Member::deleteMem()
{
  string deleteID;

  deleteID = getUserID();
  currentUser = NULL;

  return deleteID;
}

bool Member::checkIDandPW(string userID, string userPassword)
{
  if ((getUserID() == userID) && (getUserPassword() == userPassword))
    return true;
  else
    return false;
}

string Member::logoutUser()
{
  this->logState = false;
  //currentUser->logState = false (?)
  return getUserID();
}

// Product
Product::Product(string name, string company, int price, int stock)
{
  productName = name;
  productCompany = company;
  productPrice = price;
  productStock = stock;
  productSold = 0;
  productScore = 0;
  scoreCount = 0;
  sellerID = "seller";
}

int Product::getProductStock()
{
  return productStock;
}

Product* Product::getProductDetails()
{
  return (this);
}

void Product::addBuyScore(double score)
{
  productScore += score;
  scoreCount += 1;
}

void Product::buyProduct(int num)
{
  productSold += num;
}

int Product::getIncome()
{
  return (productPrice * productSold);
}

double Product::getScore()
{
  return (productScore / scoreCount);
}

string Product::getProductName()
{
  return (productName);
}

//ProductList
Product* ProductList::searchProduct(string productName)
{
  int i = 0;
  while(productList[i])
  {
    if (productList[i]->productName == productName)
    {
      return productList[i];
      i++
    }
  }
}

// SellProductList
SellProductList::SellProductList() {
    //productList = null;
}

void SellProductList::showSoldProduct() {
    int i;
    for(i=0; i < sellCount; i++) {
        if(productList[i]->getProductStock() == 0)
            productList[i]->getProductDetails();    // 판매 완료 상품 목록 출력  
    }
}

Product* SellProductList::showSellProductList(int index) {
    /*int i;
    for(i=0; i < sellCount; i++) {
        productList[i]->getProductDetails();    // 판매 물품 배열 순회 -> 출력
    }*/
    return productList[index]->getProductDetails();
}

void SellProductList::addNewProduct(string productName, string productCompany, int productPrice, int productStock) 
{
    Product* product = new Product(productName, productCompany, productPrice, productStock); 
    productList[sellCount++] = product; // 판매 물품 배열 삽입
    // 전체 product 배열에도 추가 
}

void SellProductList::showProductStatistics() {
    int i = 0;
    for(i; i < sellCount; i++) {
        cout << productList[i]->getIncome(); // file write
        cout << productList[i]->getScore(); // file write
    }
}

BuyProductList::BuyProductList() {
    //productList = null;
}

void BuyProductList::addBuyProduct(Product * currentproduct) {
    productList[buyCount++] = currentproduct;   // 구매 목록 배열 삽입
    currentproduct->buyProduct();   // 구매하는 상품 정보 업데이트
}

void BuyProductList::showBuyProductList()
{
  int i;
  for(i=0; i < buyCount; i++) {
    productList[i]->getProductDetails();   // 구매한 상품 목록 정보 출력
  }
}

void BuyProductList::evaluateProduct(string productName, int productScore) {
     Product * productToevaluate = findProduct(productName);    // 상품명으로 상품 포인터 찾기
     productToevaluate->addBuyScore(productScore);  // 찾은 상품 평가
}

Product* BuyProductList::findProduct(string productName) { // 구매한 상품 순회하면서 상품명으로 상품 찾기
     int i;
     for(i=0; i < buyCount; i++) {
        if(productList[i]->getProductName().compare(productName) == 0) {
            return productList[i];
        }
     }
}