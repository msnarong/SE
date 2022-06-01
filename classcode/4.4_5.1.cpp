boundary

// 4.4. 상품 구매만족도 평가
class EvaluateUI {
  public:
    EvaluateUI();
    void startInterface(Evaluate* pEvaluate);
};

// 5.1. 판매 상품 통계
class ShowStatsUI {
  public:
    ShowStatsUI();
    void startInterface(ShowStats* pShowStats);
};


// 4.4. 상품 구매만족도 평가
EvaluateUI::EvaluateUI() {}

void EvaluateUI::startInterface(Evaluate* pEvaluate) 
{
    string productName;
    double productScore;
    fin >> productName >> productScore;
    
    string sellerID = pEvaluate->evaluateProduct(productName, productScore); // 상품만족도 평가 정보 추가 후 판매자ID 받아오기
    fout << "4.4. 상품 구매만족도 평가" << endl;
    fout << "> " << sellerID << " " << productName << " " << productScore;  // 파일 입력
}

// 5.1. 판매 상품 통계
ShowStatsUI::ShowStatsUI() {}
void ShowStatsUI::startInterface(ShowStats* pShowStats) 
{
    
    fout << "5.1. 판매 상품 통계" << endl;
    
    SellProductList* userSellProductList = pShowStats->printStats();
    int sellCount = userSellProductList->getSellCount();
    int i = 0;
    string productStatistics // 상품명 + 상품 판매 총액 + 평균 구매만족도
    for(i; i < sellCount; i++) {
        productStatistics = userSellProductList->showProductStatistics(i);
        fout << "> " << productStatistics;  // 파일 입력
    
    }
}

----------------------------------------------------------------------------
// control

// 4.4. 상품 구매만족도 평가
class Evaluate {
  public:
    Evaluate();
    string evaluateProduct(string productName, double productScore);
};

// 5.1. 판매 상품 통계
class ShowStats {
  public:
    ShowStats();
    void printStats();
};


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



----------------------------------------------------------------------------
// class 


string BuyProductList::evaluateProduct(string productName, int productScore) {
    Product * productToevaluate = findProduct(productName);    // 상품명으로 상품 포인터 찾기
    return productToevaluate->addBuyScore(productScore);  // 찾은 상품 평가
}

string SellProductList::showProductStatistics(int index) {
    return (productList[i]->getProductName() + " " + productList[i]->getIncome() + " " + productList[i]->getScore());
}

Product* BuyProductList::showBuyProductList(int index)
{
    return productList[index]->getProductDetails();   // 구매한 상품 목록 정보 출력
}

Product* SellProductList::showSoldProduct(int index) {
    return productList[index]->getProductDetails();
}










