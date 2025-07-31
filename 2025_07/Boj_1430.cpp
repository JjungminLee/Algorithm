#include<bits/stdc++.h>
using namespace std;

struct Node{
    int x;
    int y;
    double power;
};

double powers[51];
int n;
double r,d;
int x,y;
vector<Node>v;

bool calcDist(int x1,int y1,int x2,int y2){
    return (sqrt(pow(x1-x2,2)+pow(y1-y2,2)))<=r;
}


int main(){
    cin>>n;
    cin>>r>>d>>x>>y;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b,0});
    }

    queue<Node>q;

    for(int i=0;i<n;i++){
        if(calcDist(x,y,v[i].x,v[i].y)){
            q.push({v[i].x,v[i].y,d});
            powers[i]=d;
        }
    }

    while(!q.empty()){
        Node cur = q.front();
        q.pop();

        for(int i=0;i<n;i++){
            if(calcDist(cur.x,cur.y,v[i].x,v[i].y)){
                double newPower = (cur.power/2.0);
                if(powers[i]<newPower){
                    powers[i]=newPower;
                    q.push({v[i].x,v[i].y,newPower});
                }
            }
        }
    }
    double total=0;
    for(int i=0;i<n;i++){
       total+=powers[i];
    }
    cout<<total<<endl;

   


}