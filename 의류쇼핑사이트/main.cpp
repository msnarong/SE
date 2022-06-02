// File : main.cpp
// Description: receives input from a file and creates a corresponding control class
#include "class.h"
#include "control.h"
#include "boundary.h"

ifstream fin(INPUT_FILE_NAME);
ofstream fout(OUTPUT_FILE_NAME);

Member* memberList[MAX_MEMBER_NUM];
Member* currentUser; // 현재 로그인한 유저
Product* currentProduct; // 회원이 상품 정보 검색한 상품
ProductList* allProduct = new ProductList();

void doTask();
void program_exit();

// Function : int main()
// Description: This is a main function
// Return Value :  1(file error) or 0
int main()
{
  if (!fin | !fout)
  {
    cout << "file error" << endl;
    return 1;
  }
  doTask();
  return 0;
}

// Function : void doTask()
// Description: This is a function that receives input from a file and creates a corresponding control class
void doTask()
{
  // 메뉴 파싱을 위한 level 구분을 위한 변수
  int menu_level_1 = 0, menu_level_2 = 0;
  int is_program_exit = 0;

  while(!is_program_exit)
  {
    // 입력파일에서 메뉴 숫자 2개를 읽기
    fin >> menu_level_1;
    fin >> menu_level_2;

    // 메뉴 구분 및 해당 연산 수행
    switch(menu_level_1)
    {
      case 1:
      {
        switch(menu_level_2)
        {
          case 1:   // 1.1. 회원가입
          {
            SignUp signUp; // control class 생성
            break;
          }
          case 2:   // 1.2. 회원탈퇴
          {
            DeleteAccount deleteAccount;
            break;
          }
        }
        break;
      }
      case 2:
      {
        switch(menu_level_2)
        {
          case 1:  // 2.1. 로그인
          {
            Login login; //control class 생성
            break;
          }
          case 2:  // 2.2. 로그아웃
          {
            Logout logout;
            break;
          }
        }
        break;
      }
      case 3:
      {
        switch(menu_level_2)
        {
          case 1: // 3.1. 판매 의류 등록
          {
            EnrollProduct enrollProduct; //control class 생성
            break;
          }
          case 2: // 3.2. 등록 상품 조회
          {
            CheckSellProduct checkSellProduct;
            break;
          }
          case 3: // 3.3 판매 완료 상품 조회
          {
            CheckSoldProduct checkSoldProduct;
            break;
          }
        }
        break;
      }
      case 4:
      {
        switch(menu_level_2)
        {
          case 1: // 4.1. 상품 정보 검색'
          {
            SearchProduct SearchProduct1;
            break;
          }
          case 2: // 4.2. 상품 구매
          {
            BuyProduct buyProduct;
            break;
          }
          case 3: // 4.3. 상품 구매 내역 조회
          {
            BuyList buyList;
            break;
          }
          case 4: // 4.4. 상품 구매만족도 평가
          {
            Evaluate evaluate;
            break;
          }
        }
        break;
      }
      case 5:
      {
        switch(menu_level_2)
        {
          case 1: // 5.1. 판매 상품 통계
          {
            ShowStats showStats;
            break;
          }
        }
        break;
      }
      case 6:
      {
        switch(menu_level_2)
        {
          case 1:   // "6.1. 종료“ 메뉴 부분
          {
            program_exit();
            is_program_exit = 1;
            break;
          }
        }
        break;
      }
   } // end switch
  } // end while
  return;
} // end doTask()

// Function : program_exit()
// Description: This is a function that close the file and program exit
void program_exit()
{
  fout << "6.1. 종료" << endl;
  fin.close();
  fout.close();
}