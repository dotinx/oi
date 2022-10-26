#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
struct stu{
  string sid;
  int cid;
  string name;
  ld chinese;
  ld maths;
  ld english;
  ld program;
};
unordered_map<string,stu> students;// sid -> stu object
unordered_map<string,vector<string> > nametable;//name -> sid
bool running = true;
int oper;
const string MENU_STR = "Welcome to Student Performance Management System (SPMS).\n\n1 - Add\n2 - Remove\n3 - Query\n4 - Show ranking\n5 - Show Statistics\n0 - Exit\n";
const string STUADD_STR = "Please enter the SID, CID, name and four scores. Enter 0 to finish.\n";
const string STUREMOVE_STR = "Please enter SID or name. Enter 0 to finish.\n";
void handle_add_stu(){
  cout << STUADD_STR;
  string sid;
  int cid;
  string name;
  ld chinese;
  ld maths;
  ld english;
  ld program;
  cin >> sid;
  if(sid == "0"){
    return;
  }
  cin >> cid >> name >> chinese >> maths >> english >> program;
  if(students.find(sid) != students.end()){
    cout << "Duplicated SID." << endl;
  }else{
    stu newstu = (stu){sid,cid,name,chinese,maths,english,program};
    students[sid] = newstu;
    nametable[name].push_back(sid);
  }
  handle_add_stu();
}
void handle_remove_stu(){
  cout << STUREMOVE_STR;
  string gussingstr;
  int x;
  cin >> gussingstr;
  if(gussingstr == "0")
    return;
  if(students.find(gussingstr) != students.end()){//SID
    x = 1;
    stu that = students[gussingstr];
    string sid = that.sid,name = that.name;
    for(int i = 0,siz = nametable[name].size();i < siz;i++){
      if(nametable[name][i] == sid){
        nametable[name].erase(nametable[name].begin()+i);
        break;
      }
    }
    students.erase(gussingstr);
  }else if(nametable.find(gussingstr) != nametable.end()){
    vector<string> that = nametable[gussingstr];
    x = that.size();
    for(auto s : nametable[gussingstr]){
      students.erase(s);
    }
    that.clear();
  }else{
    x = 0;
  }
  cout << x << " student(s) removed.\n";
  handle_remove_stu();
}
int main(){
  while(running){
    cout << MENU_STR;
    cin >> oper;
    switch (oper) {
      case 0:
        return 0;
        break;
      case 1:
        handle_add_stu();
        break;
      case 2:
        handle_remove_stu();
        break;
      case 3:
        break;
      case 4:
        break;
      case 5:
        break;
    }
  }
  return 0;
}
