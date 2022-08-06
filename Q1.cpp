//Mahad Ahmed 20i0426
#include<iostream>
#include<cmath>
using namespace std;

struct rectangle{
  int x1,y1,x2,y2,x3,y3,x4,y4;
};

rectangle* function1(int n){
    cout<<"Implementing function 1"<<endl;
    rectangle *r=new rectangle[n];
    for(int i=0;i<n;i++){
        cout<<"Enter Information for Rectangle # "<<i+1<<endl;
        cout<<"x1= ";
        cin>>r[i].x1;
        cout<<"\ny1= ";
        cin>>r[i].y1;
        cout<<"\nx2= ";
        cin>>r[i].x2;
        cout<<"\ny2= ";
        cin>>r[i].y2;
        cout<<"\nx3= ";
        cin>>r[i].x3;
        cout<<"\ny3= ";
        cin>>r[i].y3;
        cout<<"\nx4= ";
        cin>>r[i].x4;
        cout<<"\ny4= ";
        cin>>r[i].y4;
    }    
  return r;   
}

void function2(int a[],int n, rectangle*r){
    cout<<"Implementing Function 2"<<endl;
    int l,w;
    for(int i=0;i<n;i++){
        l=sqrt(((r[i].x2 - r[i].x1)*(r[i].x2 - r[i].x1))+((r[i].y2 - r[i].y1)*(r[i].y2 - r[i].y1)));
        w=sqrt(((r[i].x2 - r[i].x4)*(r[i].x2 - r[i].x4))+((r[i].y2 - r[i].y4)*(r[i].y2 - r[i].y4)));
        int area=l*w;
        a[i]=area;
        cout<<"Area of Rectangle # "<<i+1<<" is : "<<a[i]<<endl;
    }
}

void function3(int a[],int n,rectangle*r){
    cout<<"Implementing function3"<<endl;
    rectangle t;
    for(int i=0;i<n;i++){
        for(int p=0;p<n-1;p++){
            if(a[p]>=a[p+1]){
                r[p]=t;
                r[p]=r[p+1];
                r[p+1]=r[p];
                int temp=a[p];
                a[p]=a[p+1];
                a[p+1]=temp;
            }
        }
    }
    cout<<"Sorted Order of areas is: "<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }
}

bool function5(int l1x,int l1y,int r1x,int r1y,int l2x,int l2y,int r2x,int r2y){
    if(l1x==r1x or l1y==r2y or l2x==r2x or l2y==r2y){
        return false;
    }
    if(l1x>=r2x or l2x>=r1x){
        return false;
    }
    if(l1y<=r2y or l2y<=r1y){
        return false;
    }
    return true;
}

void function4(int a[],rectangle *r,int n){
    rectangle largest=r[n-1];
    for(int i=0;i<n-1;i++){
        bool flag=function5(r[i].x1,r[i].y1,r[i].x4,r[i].y4,largest.x1,largest.y1,largest.x4,largest.y4);
        if(flag==true){
            cout<<"Rectangle with area "<<a[i]<<" overlaps the largest rectangle"<<endl;
        }
    }
    
    
}

int main(){
    int n; 
    cout<<"Enter the number of rectangles to make: ";
    cin>>n;
    int area[n];
    int *aptr=area; 
    rectangle *rec=function1(n);
    function2(area,n,rec); 
    function3(area,n,rec);
    function4(area,rec,n);
    return 0;
}
