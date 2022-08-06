//Mahad Ahmed 20i0426
#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class screen{
  public:
  string tasks[5];
  string quote,date,Time;
  int hour,minute,s; 
  
  //set functions
  void setdatef1(string d,string m,string y){
      date=d+"/"+m+"/"+y;
  }
  void setdatef2(string d,string m,string y){
      date=d+" "+m+","+y;
  }
  void setTimef1(int h,int m,string z){
      Time=to_string(h)+":"+to_string(m)+" "+z;
  }
  void setTimef2(int h,int m,string z){
      if(z=="PM"){
         h=h+12;
      }
      Time=to_string(h)+":"+to_string(m);
  }
  void setquote(string q){
      quote=q;
  }
  void setsize(int num){
      s=num;
  }
  void setTasks(int n){
      s=n;
      for(int i=0;i<s;i++){
          cout<<"Enter Task # "<<i+1<<" :\n";
          string value;
          getline(cin,value);
          tasks[i]=value;
      }
  }
  void removetask(int n,int r){
      tasks[r]=" ";
      for(int i=r+1;i<s;i++){
          tasks[i]=tasks[i-1];
      }
      s=n-1;
  }  
  //Get functions
  string getTime(){
      return Time;
  }
  string getDate(){
      return date;
  }
  string getquote(){
      return quote;
  }
  void getTasks(){
      cout<<"Tasks: "<<endl;
      for(int i=0;i<s;i++){
          cout<<i+1<<"-"<<tasks[i]<<endl;
      }
  }
}object;

void functionadd(){
    int press,press1,press2,press3,n,rem,hour,minute;
    int choice;
    string quote;
    cout<<"Which value would you like to add/edit:\n1-Date\n2-Time\n3-Quote\n4-Tasks\n";
    cin>>choice;
    switch(choice){
        case 1:
        {
        cout<<"Enter which format to enter date in:\n1-day/month/year\n2-day Month,year\n";
        cin>>press;
            string day,month,year;
            cout<<"Enter Day: ";
            cin>>day;
            cout<<"\nEnter month: ";
            cin>>month;
            cout<<"\nEnter Year: ";
            cin>>year;
        if(press==1){
            object.setdatef1(day,month,year);
        }
        else if(press==2){
            object.setdatef2(day,month,year);
        }
        }
        break;
        
        case 2:
        {
        cout<<"\nWhich format would you like time in?\n1-12 Hour\n2-24 Hour\n";
        cin>>press1;
        cout<<"Enter Hour: ";
        cin>>hour;
        cout<<"\nEnter Minute: ";
        cin>>minute;
        string zone;
        cout<<"Enter AM or PM (capitals)"<<endl;
        cin>>zone;
        if(press1==1){
            object.setTimef1(hour,minute,zone);
        }
        else if(press1==2){
            object.setTimef2(hour,minute,zone);
        }
        }
        break;
        
        case 3:
        {
        cout<<"Enter quote: ";
        cin.ignore();
        getline(cin,quote);
        cout<<endl;
        object.setquote(quote);
        }
        break;
        
        case 4:
        {
        cout<<"Do you want to set 1-New Tasks or 2-Delete a task?\n";
        cin>>press2;
        if(press2==1){
            cout<<"\nHow many tasks are there?";
            cin>>n;
            cin.ignore();
            object.setsize(n);
            object.setTasks(n);
        }
        else if(press2==2){
            cout<<"\nHow many tasks are there Currently?";
            cin>>n;
            cout<<"\nwhich task number do you want to remove?";
            cin>>rem;
            object.removetask(n,rem);
        }
        }
        break;
        
    }
}

void displaymainscreen(){
    cout<<"MAIN SCREEN"<<endl;
    cout<<"_______________________________________"<<endl;
    cout<<"Time: "<<object.getTime()<<endl;
    cout<<"_______________________________________"<<endl;
    cout<<"Date: "<<object.getDate()<<endl;
    cout<<"_______________________________________"<<endl;
    cout<<"Favourite Quote: "<<object.getquote()<<endl;
    cout<<"_______________________________________"<<endl;
    object.getTasks();
    cout<<"_______________________________________"<<endl;
}


int main(){
    int option;
    cout<<"Choose Which Screen to go to: "<<endl<<"1-Main Screen\n2-Add/Edit Main screen"<<endl<<"Enter Option: ";
    cin>>option;
    if(option==1){
        displaymainscreen();
    }
    else if(option==2){
        int x=0;
        while(x!=5){
        functionadd();
        cout<<"Press any number to Add/Edit again, press 5 to Leave Add/Edit"<<endl;
        cin>>x;
        }
        cout<<"Press 1 to see Main Screen: ";
        int press;
        cin>>press;
        cout<<endl;
        if(press==1){
            displaymainscreen();
        }
    }
    else{
        cout<<"Invalid option"<<endl;    
    }
    cout<<endl;
    return 0;
}


