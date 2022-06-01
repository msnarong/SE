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
	int userNumber;
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
	Member(string uName, int uNumber, string uID, string uPassword); //회원가입
	bool checkIDandPW(string uID, string uPW); //로그인 시
	void deleteMem(); //회원탈퇴
	void LogoutUser(); //로그아웃
	BuyProductList* getBuyList(); //구매 내역
	SellProductList* getSellList();  //판매 내역
};

Member::Member(string uName, int uNumber, string uID, string uPassword) {
	userName = uName;
	userNumber = uNumber;
	userID = uID;
	userPassword = uPassword;
}

bool Member::checkIDandPW(string userID, string userPW) {
	for (int n = 0; n < MAX_MEMBER_NUM; n++) {
		int a = 0; int b = 0;
		a = userID.compare(memberList[n]); 
		b= userPW.compare(memberList[n]);
		if (a == 0 && b == 0)
			return true;
	}
	return false;
}

void Member::deleteMem() {
	for (int n = 0; n < MAX_MEMBER_NUM; n++) {
		if (currentUser->userNumber == memberList[n]->userNumber)
			memberList[n] = NULL;
	}
	currentUser = NULL;
}


void Member::LogoutUser() {
	currentUser->logState = false;
	currentUser = NULL;
}

void Member::getBuyList() {
	return BuyProductList;
}

void Member::getSellList() {
	return SellProductList;
}