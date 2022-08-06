//Mahad Ahmed 20i0426
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

class player{
private:
char* name;//=new char[15];
//string name;
string type; //type of the player “attacking” or “defensive”
double points; //randomly assign points between 30 to 40 randomly
bool avail;
public:
// constructors
//set functions
void addplayers(char* n,string t,double p,int a){
name=n;
type=t;
points=p;
avail=a;
}

//get or display functions
void displayplayer(){
cout<<name<<"\t"<<type<<"\t"<<points<<"\t"<<endl;
}

//UPdate points function that is called from simulate match
void updatepoints(double a){
points+=a;
}

string gettype(){
return type;
}

char* getname(){
return name;
}

double getpoints(){
return points;
}

}p[12];


class team{
char* teamname;//=new char[15];
int teamrank;
string strategy;
player* teamplayers=new player[3];

public:
double teampoints;
void setrank(int i){
teamrank=i;
}

void setteam(char* n,string s){
teamname=n;
strategy=s;
}

//sets players that come from playerselection() global function
void setplayers(player &p1,player &p2,player &p3){
for(int i=0;i<3;i++){
        if(i==0){
        *(teamplayers+i)=p1;
        }
        else if(i==1){
        *(teamplayers+i)=p2;
        }
        else if(i==2){
        *(teamplayers+i)=p3;
        }
}
}

//returns teamname
char* getteamname(){
return teamname;
}

//displays teamname
void display(){
cout<<teamname<<endl;
}

//returns teamplayers
player& getteamplayers(int i){
return *(teamplayers+i);
}

//finds best players in match and returns them
player  bestplayersinmatch(){
        if(teamplayers[0].getpoints()>=teamplayers[1].getpoints() and teamplayers[0].getpoints()>=teamplayers[2].getpoints()){
        return teamplayers[0];
        }
        else if(teamplayers[1].getpoints()>=teamplayers[0].getpoints() and teamplayers[1].getpoints()>=teamplayers[2].getpoints()){
        return teamplayers[1];
        }
        else if(teamplayers[2].getpoints()>=teamplayers[0].getpoints() and teamplayers[2].getpoints()>=teamplayers[1].getpoints()){
        return teamplayers[2];
        }
}

void sortplayers(){
for(int i=0;i<3;i++){
        for(int p=0;p<2;p++){
                if(teamplayers[p].getpoints()>=teamplayers[p+1].getpoints()){
                player temp=teamplayers[p];
                teamplayers[p]=teamplayers[p+1];
                teamplayers[p+1]=temp;
                }
        }
}
}

void printleaderboard(){
cout<<"Ranking for "<<teamname<<endl;
for(int i=2,n=0;i>=0;i--,n++){
cout<<n+1<<"-"<<teamplayers[i].getname()<<" with points: "<<teamplayers[i].getpoints()<<endl;
}
}

void setteampoints(){
teampoints=teamplayers[0].getpoints() + teamplayers[1].getpoints() +teamplayers[2].getpoints();
}

double getteampoints(){
return teampoints;
}

}t[4];


class match{
int matchno;
team hometeam;
team awayteam;
team* winner;
team* loser;

public:
//match simulation
void simulatematch(team t1,team t2,int d){
cout<<"______________________________________________________________________"<<endl;
srand(d);
int r=(rand()%2)+1;//random number to find winner
if(r==1){//t1 is winner
winner=&t1;
loser=&t2;
}
else{
winner=&t2;
loser=&t1;
}
double w1,w2,w3,l1,l2,l3;
srand(d);
w1=(rand()%10)+20;// all these find random numbers to give players points for this match
srand(d+5);
w2=(rand()%10)+20;
srand(d+10);
w3=(rand()%10)+20;
srand(d+15);
l1=(rand()%10)+10;
srand(d+20);
l2=(rand()%10)+10;
srand(d+25);
l3=(rand()%10)+10;
winner->getteamplayers(0).updatepoints(w1);
winner->getteamplayers(1).updatepoints(w2);
winner->getteamplayers(2).updatepoints(w3);
loser->getteamplayers(0).updatepoints(l1);
loser->getteamplayers(1).updatepoints(l2);
loser->getteamplayers(2).updatepoints(l3);   
cout<<"Match "<<d<<" : Winner is team "<<winner->getteamname()<<" || Loser is "<<loser->getteamname()<<endl;
cout<<"Best player from Winner is: "<<winner->bestplayersinmatch().getname()<<endl;
cout<<"Best player from Loser is: "<<loser->bestplayersinmatch().getname()<<endl;
cout<<"_____________________________________________________________________________"<<endl;
}

}m1,m2,m3,m4,m5,m6,m7,m8,m9,m10,m11,m12;

void returnplayers(int a){
if(a==1){
        for(int i=0;i<12;i++){
                if(p[i].gettype()=="defender"){
                   p[i].displayplayer();
                }
        }
}
else if(a==0){
        for(int i=0;i<12;i++){
                if(p[i].gettype()=="attacker"){
                   p[i].displayplayer();
                }
        }
}
}

void assignranks(){
for(int i=0;i<4;i++){
t[i].setrank(i+1);
}
}

void teamselection(){
t[0].setteam("Barcalona","defensive");
t[1].setteam("Bayern","attacking");
t[2].setteam("Mancity","defensive");
t[3].setteam("Psg","attacking");
}

void playerselection(){
t[0].setplayers(p[0],p[1],p[2]);
t[1].setplayers(p[3],p[4],p[5]);
t[2].setplayers(p[6],p[7],p[8]);
t[3].setplayers(p[9],p[10],p[11]);

//Now lets display Players and which team they play for 
for(int i=0;i<4;i++){
cout<<"Players for team "<<t[i].getteamname()<<" are: ";
        for(int j=0;j<3;j++){
        cout<<t[i].getteamplayers(j).getname()<<",";
        }
cout<<endl;
}
}

void printteamranks(){
for(int j=0;j<4;j++){
t[j].setteampoints();
}
        for(int i=0;i<4;i++){
                for(int p=0;p<3;p++){
                        if(t[p].getteampoints()>=t[p+1].getteampoints()){
                        team temp;
                        temp=t[p];
                        t[p]=t[p+1];
                        t[p+1]=temp;
                        }
                }
        }
        
for(int i=3,n=0;i>=0;i--,n++){
cout<<n+1<<"-"<<t[i].getteamname()<<" with total points "<< t[i].getteampoints()<<endl;
}
}

int main(){
//assigning players
p[0].addplayers("Mahad","defender",35,1);
p[1].addplayers("Ronaldo","attacker",36,1);
p[2].addplayers("Vidic","defender",31,1);
p[3].addplayers("Messi","attacker",30,1);
p[4].addplayers("Lovren","defender",35.5,1);
p[5].addplayers("Neymar","attacker",39.2,1);
p[6].addplayers("Ramos","defender",34.1,1);
p[7].addplayers("Hazard","attacker",32.3,1);
p[8].addplayers("Alaba","defender",35.8,1);
p[9].addplayers("Bale","attacker",33.3,1);
p[10].addplayers("Kante","defender",38,1);
p[11].addplayers("Reus","attacker",37,1);

/*The Functions I have used will Call upon member Functions*/

//returning players of a certain type
int ad;
cout<<"Enter 1 to search defenders and 0 to search attackers: ";
cin>>ad;
returnplayers(ad);

//Assign ranks to the teams randomly
assignranks();

//setting up teams
teamselection();

//teams select their players
playerselection();

//simulating the 12 matches
m1.simulatematch(t[0],t[1],1);
m1.simulatematch(t[0],t[2],2);
m1.simulatematch(t[0],t[3],3);
m1.simulatematch(t[1],t[2],4);
m1.simulatematch(t[1],t[3],5);
m1.simulatematch(t[2],t[3],6);
m1.simulatematch(t[0],t[1],7);
m1.simulatematch(t[0],t[2],8);
m1.simulatematch(t[0],t[3],9);
m1.simulatematch(t[1],t[2],10);
m1.simulatematch(t[1],t[3],11);
m1.simulatematch(t[2],t[3],12);


//printing sorted lists of players in each team
for(int i=0;i<4;i++){
t[i].sortplayers();
t[i].printleaderboard();
}

//printing team ranks
cout<<"_______________________________________________"<<endl<<"Team Ranks are: "<<endl;
printteamranks();


return 0;
}
