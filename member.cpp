#include <string>
#include <iostream>
using namespace std;
#define MAX_MEMBER_NUM 50

Member* memberList[MAX_MEMBER_NUM];
Member* currentUser;

class Member {
private:
	string userID;
	string userPassword;
	string userName;
	string userNumber;
	bool logState;
	BuyProductList* buyList;
	SellProductList* sellList;

	/*void setUserID(string);
	string getUserID();

	void setUserNumber(int);
	int getUserNumber();

	void setUserPassword(string);
	string getUserPassword();

	void setUserName(string);
	string getUserName(); */

public:
	Member(string, int, string, string); //회원가입
	bool checkIDandPW(string, string); //로그인 시
	void deleteMem(); //회원탈퇴
	void LogoutUser(); //로그아웃
	BuyProductList* getBuyList(); //구매 내역
	SellProductList* getSellList();  //판매 내역
};



bool Member::checkIDandPW(string uID, string uPW) {
	for (int n = 0; n < MAX_MEMBER_NUM; n++) {
		int a = 0; int b = 0;
		a = uID.compare(memberList[n]); 
		b= uPW.compare(memberList[n]);
		if (a == 0 && b == 0)
			return true;
	}
	return false;
}


void Member::LogoutUser() {
	currentUser->logState = false;
	currentUser = NULL;
}

