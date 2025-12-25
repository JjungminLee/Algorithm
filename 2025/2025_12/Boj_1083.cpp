#include<bits/stdc++.h>

using namespace std;

int n;
vector<int>a;
int s;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        a.push_back(num);
    }
    cin>>s;
    int curPos = 0;

    for(int i=0;i<n&&s>0;i++){
        int best = i;
        for(int j=i+1;j<n&&j<=i+s;j++){
            if(a[best]<a[j]) best=j;
        }

        for(int j=best;j>i;j--){
            swap(a[j],a[j-1]);
        }
        s-=(best-i);
    }

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";

}

/*

인접한 걸 고려하지 않아 틀린 문제

#include<bits/stdc++.h>

using namespace std;

int n;
vector<int>a;
int s;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        a.push_back(num);
    }
    cin>>s;
    int curPos = 0;
    while(1){
        if(s==0) break;
        if(curPos>=n){
            curPos-=n;
        }
        int curNum = a[curPos];
        int nextPos=0;
        int nextNum = 0;
        for(int i=curPos+1;i<n;i++){
            if(curNum<a[i]){
                nextPos=i;
                nextNum = a[i];
                break;
            }
        }
        a[curPos]=nextNum;
        a[nextPos]=curNum;
        curPos+=2;
        s--;
        // for(int i=0;i<n;i++){
        //     cout<<a[i]<<" ";
        // }
        // cout<<"\n";
        // cout<<"========"<<endl;
        

    }

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";

}

*/