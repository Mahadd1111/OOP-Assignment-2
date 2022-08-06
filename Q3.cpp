//Mahad Ahmed 20i0426
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;


struct Book{
int id;
string type;
string bookname;
string authorname;
double price;
bool avail;

void setbook(int d,string t,string bn,string an,double p,bool av){
id=d;
type=t;
bookname=bn;
authorname=an;
price=p;
avail=av;
}

void displaybooks(){
cout<<setw(10)<<left<<id<<setw(10)<<left<<type<<setw(15)<<left<<bookname<<setw(15)<<left<<authorname<<setw(15)<<left<<price<<endl;
}

}b[10];

struct Salary{
double fixedsalary=15000.0; //every salesperson has a fixed salary for a daily wager Rs. 15000/-
double comission; //2% of sale price of all the books sold
double totalsalary;

void setcomission(double s){
comission=s*((double)((double)2/(double)100));
}
void settotalsalary(){
totalsalary=(double)comission+(double)fixedsalary;
}
};




struct Customer{
int custNo;
string custName; 
string custAddress; //structure itself
Book bk; 
void setcustomer(int no,string na,string a){
custNo=no;
custName=na;
custAddress=a;
}
};

struct SalesPerson{//to store data of each sales person
int empID;
string empName; //duration of project
double sales;
Customer custarray[3]; //array of customers that salesperson sold books to
Salary empsal; //salary of the employee

void setempsalary(){
empsal.setcomission(sales);
empsal.settotalsalary();
}


}s1,s2,s3,s4;


double totalsales(){
return s1.sales+s2.sales+s3.sales;
}

double totalsalesbyperson(string s){
if(s=="Junaid"){
        return s1.sales;
}
else if(s=="Ali"){
        return s2.sales;
}
else if(s=="Mahad"){
        return s3.sales;
}
else if(s=="Haleema"){
        return s4.sales;
}
else{
cout<<"invalid input"<<endl;
}

}


void topsalesperson4(double s[],string n[]){
double dtemp;
string stemp;
for(int i=0;i<4;i++){
        for(int p=0;p<3;p++){
                if(s[p]>=s[p+1]){
                dtemp=s[p];
                stemp=n[p];
                s[p]=s[p+1];
                n[p]=n[p+1];
                s[p+1]=dtemp;
                n[p+1]=stemp;
                }
        }
}

cout<<"Sorted List of Salesman by Sales: "<<endl;
for(int k=3;k>=0;k--){
cout<<"Name: "<<n[k]<<" with Sales: Rs "<<s[k]<<endl;
}

}

double commissionsalesperson(string s){
if(s=="Junaid"){
        return s1.empsal.comission;
}
else if(s=="Ali"){
        return s2.empsal.comission;
}
else if(s=="Mahad"){
        return s3.empsal.comission;
}
else if(s=="Haleema"){
        return s4.empsal.comission;
}
else{
cout<<"invalid input"<<endl;
}

}

double totalsalary(){
return s1.empsal.totalsalary + s2.empsal.totalsalary + s3.empsal.totalsalary + s4.empsal.totalsalary;
}


void booksinventory(){
int count =0;
for(int i=0;i<10;i++){
        if(b[i].avail==1){
        count++;
        }
}
cout<<"remaining Books in inventory are: "<<count<<endl;
}

void booksinventorybytype(){
int hcount=0,fcount=0, acount=0;
for(int i=0;i<10;i++){
        if(b[i].avail==1){
                if(b[i].type=="History"){
                hcount++;
                }
                else if(b[i].type=="Fiction"){
                fcount++;
                }
                else if(b[i].type=="Adventure"){
                acount++;
                }
        }
}

cout<<"Adventure books left are: "<<acount<<endl;
cout<<"Fiction books left are: "<<fcount<<endl;
cout<<"History books left are: "<<hcount<<endl;
}

int main(){
string namesearch;
//sales person 1,2,3,4 and their customers
s1.empID=111;
s1.empName="Junaid";
s1.sales=5000;
s1.custarray[0].setcustomer(11,"John","111xxx");
s1.custarray[1].setcustomer(12,"Josh","111yyy");
s1.custarray[2].setcustomer(13,"Jordan","111zzz");
s1.setempsalary();

s2.empID=222;
s2.empName="Ali";
s2.sales=3000;
s2.custarray[0].setcustomer(21,"Alex","222xxx");
s2.custarray[1].setcustomer(22,"Alfred","222yyy");
s2.custarray[2].setcustomer(23,"Alison","222zzz");
s2.setempsalary();

s3.empID=333;
s3.empName="Mahad";
s3.sales=10350;
s3.custarray[0].setcustomer(31,"Mark","333xxx");
s3.custarray[1].setcustomer(32,"Mary","333yyy");
s3.custarray[2].setcustomer(33,"Mia","333zzz");
s3.setempsalary();

s4.empID=444;
s4.empName="Haleema";
s4.sales=7800;
s4.custarray[0].setcustomer(41,"Harry","444xxx");
s4.custarray[1].setcustomer(42,"Howard","444yyy");
s4.custarray[2].setcustomer(43,"Helen","444zzz");
s4.setempsalary();

//setting books available in inventory
b[0].setbook(1,"History","book 1","author 1",300,1);
b[1].setbook(2,"Adventure","book 2","author 2",350,1);
b[2].setbook(3,"Fiction","book 3","author 3",250,1);
b[3].setbook(4,"History","book 4","author 4",300,1);
b[4].setbook(5,"Adventure","book 5","author 5",350,1);
b[5].setbook(6,"Fiction","book 6","author 6",250,1);
b[6].setbook(7,"History","book 7","author 7",300,1);
b[7].setbook(8,"Adventure","book 8","author 8",350,1);
b[8].setbook(9,"Fiction","book 9","author 9",250,1);
b[9].setbook(10,"Adventure","book 10","author 10",400,1);


//displaying book options
cout<<"BOOK OPTIONS"<<endl<<"_____________________________________________________"<<endl;
cout<<setw(10)<<left<<"ID"<<setw(10)<<left<<"Type"<<setw(15)<<left<<"Name"<<setw(15)<<left<<"Author"<<setw(15)<<left<<"Price"<<endl;
for(int i=0;i<10;i++){
b[i].displaybooks();
}
cout<<"______________________________________________________________"<<endl;

//buying books
cout<<"Sales man ID's are : 1-Junaid (111) , 2-Ali (222), 3-Mahad(333) , 4-Haleema(444) "<<endl;
int num,booksearch,cn,sid;
bool flag=true;
while(flag==true){
cout<<"Enter Salesmans ID: ";
cin>>sid;
cout<<"\nEnter which number customer (1/2/3) : ";
cin>>cn;
cn--;
cout<<"\nHow many books do you want to buy? : ";
cin>>num;
for(int i=0;i<num;i++){
cout<<"\nEnter ID of book to buy: ";
cin>>booksearch;
        for(int j=0;j<10;j++){
                if(booksearch==b[j].id){
                        if(b[j].avail==1){
                                if(sid==111){
                                  s1.custarray[cn].bk=b[j];
                                  s1.sales=s1.sales+b[j].price;
                                  s1.setempsalary();
                                  b[j].avail=0;
                                }
                                else if(sid==222){
                                  s2.custarray[cn].bk=b[j];
                                  s2.sales=s2.sales+b[j].price;
                                  s2.setempsalary();
                                  b[j].avail=0;
                                }
                                else if(sid==333){
                                  s3.custarray[cn].bk=b[j];
                                  s3.sales=s4.sales+b[j].price;
                                  s3.setempsalary();
                                  b[j].avail=0;
                                }
                                else if(sid==444){
                                  s4.custarray[cn].bk=b[j];
                                  s4.sales=s4.sales+b[j].price;
                                  s4.setempsalary();
                                  b[j].avail=0;
                                }
                        }
                        else{
                        cout<<"Book Unavailable"<<endl;
                        }
                }
        }
}
cout<<"Enter 1 if you want to buy more books, 0 to stop buying: ";
cin>>flag;
cout<<endl;
}
//Total sales done
double xtotalsales=totalsales();
cout<<"Total sales done are: "<<xtotalsales<<endl;

//Searching sales of one Sales person
cout<<"The sales persons are 1-Junaid, 2-Ali, 3-Mahad, 4-Haleema , Enter Name of sales person to check sales: ";
cin>>namesearch;
cout<<endl;
double xpersonsales=totalsalesbyperson(namesearch);
cout<<"Total sales by "<<namesearch<<" are: "<<xpersonsales<<endl;

//Finding top sales person
double slist[4];
string nlist[4];
slist[0]=s1.sales;
nlist[0]=s1.empName;
slist[1]=s2.sales;
nlist[1]=s2.empName;
slist[2]=s3.sales;
nlist[2]=s3.empName;
slist[3]=s4.sales;
nlist[3]=s4.empName;
topsalesperson4(slist,nlist);

//Finding commission of a sales person
cout<<"The sales persons are 1-Junaid, 2-Ali, 3-Mahad, 4-Haleema , Enter Name of sales person to check Commission: ";
cin>>namesearch;
cout<<endl;
double xpersoncom=commissionsalesperson(namesearch);
cout<<"Total Commission by "<<namesearch<<" is: Rs "<<xpersoncom<<endl;

//total salary owner has to play
double stot=totalsalary();
cout<<"Total Salary owner has to pay is Rs "<<stot<<endl;

//Calculating total books
booksinventory();

//calculating each type of book in inventory
booksinventorybytype();
return 0;
}

