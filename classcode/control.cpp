// 로그인
Login::Login() 
{
  LoginUI loginUI;
  loginUI.startInterface(this);
}

bool Login::checkAccount(string userID, string userPassword)
{
  int i = 0;
  for(i; i < MAX_MEMBER_NUM; i++) // 전체 유저 for문 돌면서 id,pw 확인
  {
    if(memberList[i]->checkIDandPW(userID, userPassword))
    {
      currentUser = &memberList[i];
      currentUser->logState = true;
      return true;  // 로그인 성공
    }
  }
  return false; // 로그인 실패
}
// login control 

// 로그아웃
Logout::Logout() 
{
    LogoutUI logoutUI;
    logoutUI.startInterface(this);
}

string Logout::userLogout()
{
    return currentUser->LogoutUser();
}
// logout control

// 회원가입
SignUp::SignUp() 
{
    SignUpUI signupUI;
    signupUI.startInterface(this);
}

void SignUp::addNewMem(string userName, int userNumber, string userID, string userPassword) 
{
    Member* NewMem(userName, userNumber, userID, userPassword);
    memberList[memberCount++] = NewMem;
}
// signup control

// 회원탈퇴
DeleteAccount::DeleteAccount()
{
    DeleteAccountUI deleteUI;
    deleteUI.startInterface(this);
}

string DeleteAccount::deleteMem()
{
    return currentUser->deleteMem(); 
}
// delete control
