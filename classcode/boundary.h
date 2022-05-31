// 로그인 
class LoginUI {
  public:
    LoginUI();
    void startInterface(Login* pLogin);
};

// 로그아웃
class LogoutUI {
  public:
    LogoutUI();
    void startInterface(Logout* pLogout);
}

// 회원가입
class SignUpUI {
  public:
    SignUpUI();
    void startInterface(SignUp* pSignUp);
}

// 회원탈퇴
class DeleteAccountUI {
  public:
    DeleteAccountUI();
    void startInterface(DeleteAccount* pDeleteAccount);
}