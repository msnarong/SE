#include "class.h"

static ifstream fin(INPUT_FILE_NAME);
static ofstream fout(OUTPUT_FILE_NAME);

// Member
Member::Member(string uName, int uNumber, string uID, string uPassword) {
	userName = uName;
	userNumber = uNumber;
	userID = uID;
	userPassword = uPassword;
}

string Member::getUserID()
{
  return userID;
}

string Member::getUserPassword()
{
  return userPassword;
}

void Member::setLogState(bool b)
{
  logState = b;
}


/*string Member::deleteMem()
{
  string deleteID;

  deleteID = getUserID();
  currentUser = NULL;

  return deleteID;
}*/
/*
string Member::deleteMem() {
  string deleteID;

	for (int n = 0; n < MAX_MEMBER_NUM; n++) {
		if (currentUser == memberList[n])
      deleteID = memberList[n]->userID;
			memberList[n] = NULL;
	}
	currentUser = NULL;
  return deleteID;
  
}*/

/*bool Member::checkIDandPW(string userID, string userPassword)
{
  if ((getUserID() == userID) && (getUserPassword() == userPassword))
    return true;
  else
    return false;
}*/
bool Member::checkIDandPW(string userID, string userPW) {
	for (int n = 0; n < MAX_MEMBER_NUM; n++) {
		int a = 0; 
    int b = 0;
		a = userID.compare(getUserID()); 
		b = userPW.compare(getUserPassword());
		if (a == 0 && b == 0)
    {
      logState = true;
			return true;
    }
	}
	return false;
}

string Member::logoutUser()
{
  logState = false;
  //currentUser = NULL;
  return getUserID();
}

BuyProductList* Member::getBuyList() {
	return buyList;
}

SellProductList* Member::getSellList() {
	return sellList;
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

string Product::addBuyScore(double score)
{
  productScore += score;
  scoreCount += 1;
  return sellerID;
}

void Product::buyProduct()
{
  productStock--;
  productSold++;
}

int Product::getIncome()
{
  return (productPrice * productSold);
}

double Product::getProductScore()
{
  return (productScore / scoreCount);
}

string Product::getProductName()
{
  return (productName);
}

string Product::getProductCompany() {
  return productCompany;
}
int Product::getProductPrice() {
  return productPrice;
}

int Product::getProductSold() {
  return productSold;
}
string Product::getSellerID() {
  return sellerID;
}

//ProductList
Product* ProductList::searchProduct(string productName)
{
  int i = 0;
  while(productList[i])
  {
    if (productList[i]->getProductName() == productName)
    {
      return productList[i];
    }
    i++;
  }
  return NULL;
}

// SellProductList
SellProductList::SellProductList() {
    //productList = null;
}

Product* SellProductList::showSoldProduct(int index) {
    return productList[index]->getProductDetails();
}

Product* SellProductList::showSellProductList(int index) 
{
    return productList[index]->getProductDetails();
}

void SellProductList::addNewProduct(string productName, string productCompany, int productPrice, int productStock) 
{
    Product* product = new Product(productName, productCompany, productPrice, productStock); 
    productList[sellCount++] = product; // 판매 물품 배열 삽입
    // 전체 product 배열에도 추가 
}

string SellProductList::showProductStatistics(int index) {
    return (productList[index]->getProductName() + " " + to_string(productList[index]->getIncome()) + " " + to_string(productList[index]->getProductScore()));
}

int SellProductList::getSellCount()
{
  return sellCount;
}

BuyProductList::BuyProductList() {
    //productList = null;
}

void BuyProductList::addBuyProduct() {
    productList[buyCount++] = currentProduct;   // 구매 목록 배열 삽입
    currentProduct->buyProduct();   // 구매하는 상품 정보 업데이트
}

Product* BuyProductList::showBuyProductList(int index)
{
  return productList[index]->getProductDetails();
}

string BuyProductList::evaluateProduct(string productName, int productScore) {
    Product * productToevaluate = findProduct(productName);    // 상품명으로 상품 포인터 찾기
    return productToevaluate->addBuyScore(productScore);  // 찾은 상품 평가
}

Product* BuyProductList::findProduct(string productName) { // 구매한 상품 순회하면서 상품명으로 상품 찾기
     int i;
     for(i=0; i < buyCount; i++) {
        if(productList[i]->getProductName().compare(productName) == 0) {
            return productList[i];
        }
     }
     return NULL;
}

int BuyProductList::getBuyCount()
{
  return buyCount;
}