//Mahad Ahmed 20i0426
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

//void contact(double,double);
//void checkoverlap(double,double);

struct runway{
string id;
bool aslot=1;
bool clash;
bool overlap; 
double reserved[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

void checkaslot(){
for(int i=0;i<10;i++){
if(reserved[0]==1 and reserved[1]==2 and reserved[2]==3 and reserved[3]==4 and reserved[4]==5 and reserved[5]==6 and reserved[6]==7 and reserved[7]==8 and reserved[8]==9 and reserved[9]==10){

}
}
}

void setnewreserved(double r1, double r2){
int l1=(int)r1;
int l2=(int)r2;
reserved[l1-1]=r1;
reserved[l2-1]=r2;
}

void setreserved(int i){
if(i==0){
reserved[0]=1;
reserved[1]=2;
reserved[3]=4;
reserved[4]=5;
reserved[7]=8;
reserved[8]=9;
}
else if(i==1){
reserved[1]=2;
reserved[2]=3;
reserved[5]=6;
reserved[6]=7;
reserved[7]=8;
reserved[8]=9;
}
else if(i==2){
reserved[2]=3;
reserved[3]=4;
reserved[4]=5;
reserved[5]=6;
reserved[6]=7;
reserved[7]=8;
}
}

}r[3];

class flight{
private:
// think about the private data members...
string fnum; //
string city;
double arrtime; //arrival time which is known at the departure.
double rflytime; //how long can the fuel last it no runway is available
double stime; //
runway rn; //
public:
// constructors
// provide definitions of following functions...
void addflight(string f,string c,double at,double rft,runway &r){ //function to add flight information
fnum=f;
city=c;
arrtime=at;
rflytime=rft;
rn=r;
}

void setrn(runway &r){
rn=r;
}

void setarrtime(double a){// get landing time from air controller depending on availability of runway
if(a==0){
    arrtime=0;
}
else{
arrtime=arrtime+a;
}
}

//getfunctions for flights
string getfnum(){
        return fnum;
}

string getcity(){
        return city;
}

double getarrtime(){
        return arrtime;
}

double getrflytime(){
        return rflytime;
}

runway getrn(){
        return rn;
}

void updateremainingflytime(){ //This is updated once the flight contacts AirController
rflytime--;
}

}f[10];

class aircontroller{
private:
// think about the private data members...
public:
// constructors
// provide definitions of following functions...
/*Special class with only one instance during execution of the program, there is only air traffic
controller and landing time is allocated to plans in a centralized fashion*/

void runwaystatus(){//prints the status of all the runways
cout<<"STATUS OF RUNWAYS"<<endl;
for(int i=0;i<3;i++){
cout<<"------------------------------------------------------------------------------------------"<<endl;
cout<<"Slot Availibility on Runway "<<i+1<<" : "<<r[i].aslot<<endl;
cout<<"Clash status on Runway "<<i+1<<" : "<<r[i].clash<<endl;
cout<<"Status of flight overlap on Runway "<<i+1<<" : "<<r[i].overlap<<endl;
cout<<"--------------------------------------------------------------------------------------------"<<endl;
}
}

void assignrunway(int i){//assigns runway to a flight incase its exsiting one is out of slots
        if(r[0].aslot==1){
        f[i].setrn(r[0]);
        }
        else if(r[1].aslot==1){
        f[i].setrn(r[1]);
        }
        else if(r[2].aslot==1){
        f[i].setrn(r[2]);
        }
}

//checks and fixes overlaps
void checkoverlap(double t,int i){
bool flag=false;
int index;
double val;
double res1=f[i].getarrtime();// first slot to be reserved
double res2=f[i].getarrtime()+1;//second slot to be reserved
if(f[i].getrn().aslot==0){//if no slot available , change runway
assignrunway(i);
}
for(int x=0;x<10;x++){//traverse through array of reserved timings
        while(flag==false){
                if(res1==f[i].getrn().reserved[x] or res2==f[i].getrn().reserved[x]){// if overlap occurred
                cout<<"Overlap Occured for flight: "<<f[i].getfnum()<<endl;
                        if(f[i].getarrtime()<9){
                        f[i].setarrtime(1);
                        res1=f[i].getarrtime();
                        res2=f[i].getarrtime()+1;
                        }
                        else{
                        f[i].setarrtime(0);
                        res1=f[i].getarrtime();
                        res2=f[i].getarrtime()+1;
                        }
                }
                else{
                val=f[i].getarrtime();
                cout<<"New Arrival Time for flight: "<<f[i].getfnum()<<" is 3:3"<<val<<endl;
                f[i].getrn().setnewreserved(val,val+1);// this will update the reserved timings list
                flag=true;
                }
        }
}
}


void contact(double t,int i){
//checking for clashes
for(int k=0;k<10;k++){
        if(f[i].getarrtime()==f[k].getarrtime() and f[i].getrn().id==f[k].getrn().id and f[i].getfnum()!=f[k].getfnum()){
        //clash has occured
        cout<<"Clash occured between: "<<f[i].getfnum()<<" and "<<f[k].getfnum()<<endl;
                if(f[i].getrflytime()>=f[k].getrflytime()){
                f[i].setarrtime(2);
                checkoverlap(t,i);
                cout<<"Clash fixed between: "<<f[i].getfnum()<<" and "<<f[k].getfnum()<<endl;
                }
                else{
                f[k].setarrtime(2);
                checkoverlap(t,k);
                cout<<"CLash fixed between: "<<f[i].getfnum()<<" and "<<f[k].getfnum()<<endl;
                }
        }
        else if(f[i].getarrtime()==f[k].getarrtime()+1 and f[i].getfnum()!=f[k].getfnum() and f[i].getrn().id==f[k].getrn().id){// means overlap occurred
            cout<<"Overlap happening between "<<f[i].getfnum()<<" and "<<f[k].getfnum()<<endl;
            if(f[i].getrflytime()>=f[k].getrflytime()){
            f[i].setarrtime(1);
            checkoverlap(t,i);
            cout<<"Overlap fixed between: "<<f[i].getfnum()<<" and "<<f[k].getfnum()<<endl;
            }
            else if(f[i].getrflytime()<=f[k].getrflytime()){
            f[k].setarrtime(1);
            checkoverlap(t,k);
            cout<<"Overlap fixed between: "<<f[i].getfnum()<<" and "<<f[k].getfnum()<<endl;
            }
        }
}

}

void flightcontact(double t){ //prints the data of flights who have contacted the controller
for(int i=0;i<10;i++){
        if(f[i].getarrtime()==t){
        cout<<"Flight "<<f[i].getfnum()<<" has Contacted Air controller"<<endl;
        contact(t,i);
        }
}
}

}ac;

//function to print recent updates of flight timings 
void printflights(double n){
cout<<"___________________________________Time=3:3"<<(int)n<<"_______________________________________________________________________"<<endl;
cout<<setw(15)<<left<<"Arrival time"<<setw(10)<<left<<"From"<<setw(15)<<left<<"Flight No."<<setw(15)<<left<<"Runway"<<endl;
for(int i=0;i<10;i++){
cout<<setw(15)<<left<<"3:3"+to_string((int)f[i].getarrtime())<<setw(10)<<left<<f[i].getcity()<<setw(15)<<left<<f[i].getfnum()<<setw(15)<<left<<f[i].getrn().id<<endl;
cout<<"_____________________________________________________________________________________________________________________________"<<endl;
}
}

int main(){
//Our Window will be from 3:30 to 3:40 with starting time =0 (3:30) , and ending time = 10 (3:40)
double t=0;
//initialising runways
r[0].id="RRR 111";
r[1].id="RRR 222";
r[2].id="RRR 333";
r[0].setreserved(0);
r[1].setreserved(1);
r[2].setreserved(2);
//adding flights
f[0].addflight("111aaa","Jakarta",1,5,r[0]);
f[1].addflight("222aaa","Moscow",1,2,r[0]);
f[2].addflight("333aaa","Dubai",8,4,r[0]);
f[3].addflight("444aaa","Munich",2,10,r[1]);
f[4].addflight("555aaa","Madinah",8,3,r[1]);
f[5].addflight("666aaa","Seoul",2,1,r[1]);
f[6].addflight("777aaa","Sydney",6,6,r[1]);
f[7].addflight("888aaa","NewYork",3,2,r[2]);
f[8].addflight("999aaa","London",4,5,r[2]);
f[9].addflight("000aaa","Madeirah",7,1,r[2]);

//printing all the flights initially
printflights(t);

//Now time will move in a loop
for(double time=1;time<10;time++){
ac.runwaystatus();
ac.flightcontact(time);
for(int x=0;x<10;x++){
f[x].updateremainingflytime();
}
printflights(time);
}

cout<<"In this program we fixed arrival times of 111aaa,444aaa, and 999aaa because they encountered clashes/overlaps, We can change any of the flights timings and the program will fix the arrivals regardless"<<endl;

return 0;
}





