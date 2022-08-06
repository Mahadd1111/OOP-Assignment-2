//Mahad Ahmed 20i0426
#include<iostream>
using namespace std;
//I didnt have time to finish this Question
class task{
private:
int id;
int dur;
int stime; //start time of each task
int etime; //end time of each task
int* dep; /*list of predecessors of this task - To simplify we assume that a higher number task will
depend on a lower number task e.g. T2 can depend on T1 OR T4 can depend on T2 but the
opposite is not true.*/
bool critical=0;
char skill; //required for PART B
//Resource res; //required for PART B
public:
void addtasks(int n,int j,int d,int s,int e){
id=j;
dur=d;
stime=s;
etime=e;
int temp=0;
for(int i=0;i<10;i++){
        if(i<n){
        dep[temp]=i;
        temp++;
        }
}
}
/*setTaskDuration();//change task duration of all tasks
set_nth_TaskDuration();//change duration of a specific task
printTaskDependencyList();//print dependencies of a specific task*/
};


class project{
private:
int id;
int t; //duration of project
task* tasks;
public:
// provide definitions of following functions...
project(){}// default constructor
project(task* ts, int n){//initialized the project with n tasks
for(int i=0;i<n;i++){
tasks[i]=ts[i];
}
}
void setproject(int a){
id=a;
}
//you have to implement the following functions
// think about the parameters required and return type of the following functions
/*completiontime();//print completion time of the project
printcriticaltasks();/*returns array of critical tasks and displays them – sum of their duration
should be equal to project completion time*/
//completionTimeWithResources();//for PART B
};

int main(){
int id,num;
cout<<"Enter Information for Project: "<<endl;
cout<<"Enter ID: ";
cin>>id;
cout<<"Enter Number of Tasks: ";
cin>>num;
task t[num];
cout<<"________________________________________________"<<endl;
cout<<"I didnt get to finish the rest of this Question :("<<endl;
cout<<"________________________________________________"<<endl;
//project p1(t,num);
//p1.setproject(id);

}
