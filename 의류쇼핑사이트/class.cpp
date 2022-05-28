#include "class.h"

ifstream fin(INPUT_FILE_NAME);
ofstream fout(OUTPUT_FILE_NAME);

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

void BuyProductList::showBuyProductList()
{
  int i = 0;
  while(productList[i])
  {
    productList[i]->getProductDetails();
    i++;
  }
}

void Product::getProductDetails()
{
  // [판매자ID] [상품명] [제작회사명] [가격] [남은수량] [평균 구매만족도]
  fout << sellerID << " " << productName << " " << productCompany << " " << productPrice << " " << productStock << " " << productScore << endl;
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