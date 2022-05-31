// 로그인
LoginUI::LoginUI() {}

void LoginUI::startInterface(Login* pLogin)
{
  char userID[MAX_STRING], userPassword[MAX_STRING];
    
  fin >> userID;
  fin >> userPassword;
  fout << "2.1. 로그인\n";
  if(pLogin->checkAccount(userID, userPassword)) {
      fout << "> " <<userID << " " << userPassword << endl;
  } else {
      fout << "> " << "로그인 실패" << endl;;
  }
}
// login boundary


// 로그아웃
LogoutUI::LogoutUI() {}

void LogoutUI::startInterface(Logout* pLogout) {
    string currentUserName;
    currentUserName = pLogout->userLogout();
    fout << "2.2. 로그아웃" << endl;;
    fout << "> " << currentUserName << endl;
}
// logout boundary


// 회원가입
SignUpUI:SignUpUI() {}

void SignUpUI::startInterface(SignUp* pSignUp)
{
    string userName, userID, userPassword;
    int userNumber;
    
    fin >> userName >> userNumber >> userID >> userPassword;
    pSignUp->addNewMem(userName, userNumber, userID, userPassword);
    
    fout << "1.1. 회원가입" << endl;
    fout << "> " << userName << " " << userNumber << " " << userID << " " << userPassword << endl;
}
// signup boundary

// 회원탈퇴
DeleteAccountUI::DeleteAccountUI() {}
void DeleteAccountUI::startInterface(DeleteAccount* pDeleteAccount) 
{
    string userID;
    
    userID = pDeleteAccount->deleteMem();
    fout << "1.2. 회원탈퇴" << endl;
    fout << "> " << userID << endl;
}
