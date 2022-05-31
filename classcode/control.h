// 로그인
class Login {
  public:
    Login(); // 생성자
    bool checkAccount(string userID, string userPassword);
};

// 로그아웃
class Logout {
  public:
    Logout();   // 생성자
    string userLogout();
};

// 회원가입
class SignUp {
  public:
    SignUp(); // 생성자
    void addNewMem(string userName, int userNumber, string userID, string userPassword);
};

// 회원탈퇴
class DeleteAccount {
  public:
    DeleteAccount(); // 생성자
    void deleteMem();
};