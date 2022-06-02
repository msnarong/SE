// File : control.cpp
// Description: definition of entity class and member function
#include "class.h"

static ifstream fin(INPUT_FILE_NAME);
static ofstream fout(OUTPUT_FILE_NAME);

extern Member* memberList[MAX_MEMBER_NUM];
extern Member* currentUser;
extern Product* currentProduct; // 회원 상품 정보 검색한 상품
extern ProductList* allProduct;

// Constructor : Member(string uName, int uNumber, string uID, string uPassword)
// Description: This is the constructor of the member class
// Parameters :   string uName - newly user name
//                int uNumber – newly user number
//                string uID – newly user ID
//                string uPassword – newly user password
Member::Member(string uName, int uNumber, string uID, string uPassword) {
  userName = uName;
  userNumber = uNumber;
  userID = uID;
  userPassword = uPassword;
  buyList = new BuyProductList();
  sellList = new SellProductList();
}

// Function : string getUserID()
// Description: This is a function that return user ID
// Return Value :  userID value
string Member::getUserID()
{
  return userID;
}

// Function : string getUserPassword()
// Description: This is a function that return user password
// Return Value :  userPassword value
string Member::getUserPassword()
{
  return userPassword;
}

// Function : void setLogState(bool b)
// Description: This is a function that set log state
// Parameters :   bool b – newly log state
void Member::setLogState(bool b)
{
  logState = b;
}

// Function : bool checkIDandPW(string userID, string userPW)
// Description: This is a function that check Id and Password
// Parameters :   string userID – entered user ID
// Parameters :   string userPW – entered user Password
// Return Value :  true or false
bool Member::checkIDandPW(string userID, string userPW) {
  int a = 0;
  int b = 0;
  a = userID.compare(getUserID());
  b = userPW.compare(getUserPassword());
  if (a == 0 && b == 0)
  {
    logState = true;
    return true;
  }
  return false;
}

// Function : string logoutUser()
// Description: This is a function that logout user
// Return Value :  userID value
string Member::logoutUser()
{
  logState = false;
  return getUserID();
}

// Function : BuyProductList* getBuyList()
// Description: This is a function that get buy list
// Return Value :  BuyProductList pointer
BuyProductList* Member::getBuyList() {
  return buyList;
}

// Function : SellProductList* getSellList()
// Description: This is a function that get sell list
// Return Value :  SellProductList pointer
SellProductList* Member::getSellList() {
  return sellList;
}
// end Member

// Constructor : Product(string name, string company, int price, int stock, string sellerid)
// Description: This is the constructor of the product class
// Parameters :   string name - newly product name
//                string company – newly product company name
//                int price – newly product price
//                int stock – newly product stock
//                string sellerID – newly product seller ID
Product::Product(string name, string company, int price, int stock, string sellerID)
{
  productName = name;
  productCompany = company;
  productPrice = price;
  productStock = stock;
  productSold = 0;
  productScore = 0;
  scoreCount = 0;
  sellerID = sellerID;
}

// Function : int getProductStock()
// Description: This is a function that get product stock
// Return Value :  productStock value
int Product::getProductStock()
{
  return productStock;
}

// Function : Product* getProductDetails()
// Description: This is a function that get Product pointer
// Return Value :  Product pointer
Product* Product::getProductDetails()
{
  return (this);
}

// Function : string addBuyScore(double score)
// Description: This is a function that add buy score
// Parameters :   double score – entered buy score
// Return Value :  seller ID value
string Product::addBuyScore(double score)
{
  productScore += score;
  scoreCount += 1;
  return sellerID;
}

// Function : void buyProduct()
// Description: This is a function that buy product
void Product::buyProduct()
{
  if(productStock == 0)
        return;
  productStock--;
  productSold++;
}

// Function : int getIncome()
// Description: This is a function that get product income
// Return Value :  total product income value
int Product::getIncome()
{
  return (productPrice * productSold);
}

// Function : double getProductScore()
// Description: This is a function that get product score
// Return Value :  product average score value
double Product::getProductScore()
{
  if(scoreCount == 0)
    return 0;
  return (productScore / scoreCount);
}

// Function : string getProductName()
// Description: This is a function that get product name
// Return Value :  product name value
string Product::getProductName()
{
  return (productName);
}

// Function : string getProductCompany()
// Description: This is a function that get product company name
// Return Value :  product company name value
string Product::getProductCompany() {
  return productCompany;
}

// Function : int getProductPrice()
// Description: This is a function that get product price
// Return Value :  product price value
int Product::getProductPrice() {
  return productPrice;
}

// Function : int getProductPrice()
// Description: This is a function that get product sold
// Return Value :  product sold value
int Product::getProductSold() {
  return productSold;
}

// Function : string getSellerID()
// Description: This is a function that get seller ID
// Return Value :  product seller ID
string Product::getSellerID() {
  return sellerID;
}
// end Product

// Function : Product* searchProduct(string productName)
// Description: This is a function that search product
// Parameters :   string productName – entered product name
// Return Value :  found Product pointer 
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

// Function : addNewProduct(Product* newProduct)
// Description: This is a function that add new product
// Parameters :   Product* newProduct – newly product pointer
void ProductList::addNewProduct(Product* newProduct)
{
    productList[productCount++] = newProduct;
}
// end ProductList

// Constructor : SellProductList()
// Description: This is the constructor of the sell product list class
SellProductList::SellProductList() {}

// Function : Product* showSoldProduct(int index)
// Description: This is a function that show sold product list
// Parameters :   int index – productList index
// Return Value :  Product pointer to that index
Product* SellProductList::showSoldProduct(int index) {
    return productList[index]->getProductDetails();
}

// Function : Product* showSellProductList(int index)
// Description: This is a function that show sell product list
// Parameters :   int index – productList index
// Return Value :  Product pointer to that index
Product* SellProductList::showSellProductList(int index)
{
    return productList[index]->getProductDetails();
}

// Function : Product* addNewProduct(string productName, string productCompany, int productPrice, int productStock, string sellerId)
// Description: This is a function that add new product
// Parameters :   string productName – newly product name
// Parameters :   string productCompany – newly product name
// Parameters :   int productPrice – newly product name
// Parameters :   int productStock – newly product name
// Parameters :   string sellerId – newly product name
// Return Value :  newly Product pointer
Product* SellProductList::addNewProduct(string productName, string productCompany, int productPrice, int productStock, string sellerId)
{

    Product* product = new Product(productName, productCompany, productPrice, productStock, sellerId);
    productList[sellCount++] = product; // 판매 물품 배열 삽입
    // 전체 product 배열에도 추가
    return product;
}

// Function : string showProductStatistics(int index)
// Description: This is a function that show product statistics
// Parameters :   int index – productList index
// Return Value :  string productName + productIncome + productScore
string SellProductList::showProductStatistics(int index) {
    return (productList[index]->getProductName() + " " + to_string(productList[index]->getIncome()) + " " + to_string(productList[index]->getProductScore()));
}

// Function : int getSellCount()
// Description: This is a function that get sell count
// Return Value :  sell count value
int SellProductList::getSellCount()
{
  return sellCount;
}
// end SellProductList

// Constructor : BuyProductList()
// Description: This is the constructor of the buy product list class
BuyProductList::BuyProductList() {}

// Function : void addBuyProduct()
// Description: This is a function that add buy product
void BuyProductList::addBuyProduct() {

    if(currentProduct->getProductStock() == 0)
        return;

    productList[buyCount++] = currentProduct;   // 구매 목록 배열 삽입
    currentProduct->buyProduct();   // 구매하는 상품 정보 업데이트
}

// Function : Product showBuyProductList(int index)
// Description: This is a function that show buy product list
// Parameters :   int index – productList index
// Return Value :  Product pointer to that index
Product* BuyProductList::showBuyProductList(int index)
{
  return productList[index]->getProductDetails();
}

// Function : string evaluateProduct(string productName, int productScore)
// Description: This is a function that evaluate product
// Parameters :   string productName – product name to evaluate
// Parameters :   int productScore – entered score
// Return Value :  product seller ID value
string BuyProductList::evaluateProduct(string productName, int productScore) {
    Product * productToevaluate = findProduct(productName);    // 상품명으로 상품 포인터 찾기
    return productToevaluate->addBuyScore(productScore);  // 찾은 상품 평가
}

// Function : Product* findProduct(string productName)
// Description: This is a function that find product
// Parameters :   string productName – product name to find
// Return Value :  found product pointer
Product* BuyProductList::findProduct(string productName) { // 구매한 상품 순회하면서 상품명으로 상품 찾기
     int i;
     for(i=0; i < buyCount; i++) {
        if(productList[i]->getProductName().compare(productName) == 0) {
            return productList[i];
        }
     }
     return NULL;
}

// Function : getBuyCount()
// Description: This is a function that get buy count
// Return Value :  buy conut value
int BuyProductList::getBuyCount()
{
  return buyCount;
}
// end BuyProductList