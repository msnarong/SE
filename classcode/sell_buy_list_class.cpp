/*
control -> boundary -> SellProductList, BuyProductList 
*/


class SellProductList {
  private:
    Product* productList[];
    int sellCount = 0;
  public:
    void showSoldProduct();     // 판매 완료 목록 출력
    //int getTotalIncome();       // 총 판매액 출력
    //double getScoreAvg();       // 평균 구매만족도 출력
    void showSellProductList(); // 판매 물품 목록 출력
    void addNewProduct(string, string, int, int);       // 판매 물품 등록
    void showProductStatistics();
};

void SellProductList::showSoldProduct() {
    int i = 0;
    for(i; i < sellCount; i++) {
        if(productList[i]->getproductStock() == 0)
            productList[i]->getProductDetails();
    }
}

void SellProductList::showSellProductList() {
    int i = 0;
    for(i; i < sellCount; i++) {
        productList[i]->getProductDetails();
    }
}

void SellProductList::addNewProduct(string productName, string productCompany, int productPrice, int productStock) {
    Product* product = new Product(productName, productCompany, productPrice, productStock); 
    productList[sellCount++] = product;
    ProductList[~~~] = product; // 전체 물품에도 추가
}

void SellProductList::showProductStatistics() {
    int i = 0;
    for(i; i < sellCount; i++) {
        cout << productList[i]->getIncome(); // file write
        cout << productList[i]->getScore(); // file write
    }
}
