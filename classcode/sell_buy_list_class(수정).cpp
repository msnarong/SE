/*
control -> boundary -> SellProductList, BuyProductList 
*/

Product * currentProduct = null // 회원 상품 정보 검색한 상품


class SellProductList {
  private:
    Product* productList[];
    int sellCount = 0;
  public:
    SellProductList();
    void showSoldProduct();     // 판매 완료 목록 출력
    //int getTotalIncome();       // 총 판매액 출력
    //double getScoreAvg();       // 평균 구매만족도 출력
    void showSellProductList(); // 판매 물품 목록 출력
    void addNewProduct(string, string, int, int);       // 판매 물품 등록
    void showProductStatistics();
};


SellProductList::SellProductList() {
    productList = null;
}

void SellProductList::showSoldProduct() {
    int i = 0;
    for(i; i < sellCount; i++) {
        if(productList[i]->getproductStock() == 0)
            productList[i]->getProductDetails();    // 판매 완료 상품 목록 출력  
    }
}

void SellProductList::showSellProductList() {
    int i = 0;
    for(i; i < sellCount; i++) {
        productList[i]->getProductDetails();    // 판매 물품 배열 순회 -> 출력
    }
}

void SellProductList::addNewProduct(string productName, string productCompany, int productPrice, int productStock) {
    Product* product = new Product(productName, productCompany, productPrice, productStock); 
    productList[sellCount++] = product; // 판매 물품 배열 삽입
    AllProductList[~~~] = product; // 전체 물품에도 추가
}

void SellProductList::showProductStatistics() {
    int i = 0;
    for(i; i < sellCount; i++) {
        cout << productList[i]->getIncome(); // file write
        cout << productList[i]->getScore(); // file write
    }
}


class BuyProductList {
  private:
    Product* productList[];
    int buyCount = 0;
  public:
    BuyProductList();
    void addBuyProduct();    // 물품 구매
    void showBuyProductList();  // 구매 목록 출력
    void evaluateProduct(string, int);  // 물품 평가
    Product* findProduct(string); // 이름으로 구매한 물품 찾기
};


BuyProductList::BuyProductList() {
    productList = null;
}

void BuyProductList::addBuyProduct(Product * currentproduct) {
    productList[buyCount++] = currentproduct;   // 구매 목록 배열 삽입
    currentproduct->buyProduct();   // 구매하는 상품 정보 업데이트
}


void BuyProductList::showBuyProductList() {
    int i = 0;
    for(i; i < buyCount; i++) {
        productList->getProductDetails();   // 구매한 상품 목록 정보 출력
    }
}


void BuyProductList::evaluateProduct(string productName, int productScore) {
     Product * productToevaluate = findProduct(productName);    // 상품명으로 상품 포인터 찾기
     productToevaluate->addBuyScore(productScore);  // 찾은 상품 평가
}


Product* BuyProductList::findProduct(string productName) { // 구매한 상품 순회하면서 상품명으로 상품 찾기
     int i = 0;
     for(i; i < buyCount; i++) {
        if(productList[i]->getProductName().compare(productName) == 0) {
            return productList[i];
        }
     }
}
