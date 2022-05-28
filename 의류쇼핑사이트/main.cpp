#include "class.h"
#include "control.h"
#include "boundary.h"

ifstream fin(INPUT_FILE_NAME);
ofstream fout(OUTPUT_FILE_NAME);

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
          case 1:   // "1.1. 회원가입" 메뉴 부분
          {
            addMember();
            break;
          }
          case 2:   // 1.2. 회원탈퇴
          {
            break;
          }
        }
      }
      case 2:
      {
        switch(menu_level_2)
        {
          case 1:  // 2.1. 로그인
          {
            Login Login1; //control class 생성
            break;
          }
          case 2:  // 2.2. 로그아웃
          {
            break;
          }
        }
      }
      case 3:
      {
        switch(menu_level_2)
        {
          case 1: // 3.1. 판매 의류 등록
          {
            EnrollProduct EnrollProduct1; //control class 생성
            break;
          }
          case 2: // 3.2. 등록 상품 조회
          {
            break;
          }
          case 3: // 3.3 판매 완료 상품 조회
          {
            break;
          }
        }
      }
      case 4:
      {
        switch(menu_level_2)
        {
          case 1: // 4.1. 상품 정보 검색'
          {
            break;
          }
          case 2: // 4.2. 상품 구매
          {
            break;
          }
          case 3: // 4.3. 상품 구매 내역 조회
          {
            break;
          }
          case 4: // 4.4. 상품 구매만족도 평가
          {
            break;
          }
        }
      }
      case 5:
      {
        switch(menu_level_2)
        {
          case 1: // 5.1. 판매 상품 통계
          {
            break;
          }
        }
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
      }
   } // end switch
  } // end while
  return;
} // end doTask()


void addMember()
{
  char userID[MAX_STRING], userPassword[MAX_STRING], userName[MAX_STRING];
  int userNumber;

   // 입력 형식 : 이름, 주민번호, ID, Password를 파일로부터 읽음
   fin >> userName;
   fin >> userNumber;
   fin >> userID;
   fin >> userPassword;

   // 출력 형식
   fout << "1.1. 회원가입" << endl;
   fout << userName << " " << userNumber << " " << userID << " " << userPassword << endl;
}


void program_exit()
{

}