#include <bits/stdc++.h>

using namespace std;
stack<int> stack1;
stack<int> stack2;
stack<int> stack3;
stack<int> stack4;
stack<int> stack5;
stack<int> stack6;
int ans;
int n,p;
int main(){
    
    cin>>n>>p;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        cout<<"---------"<<endl;
        cout<<"a: "<<a<<"b: "<<b<<endl;
        if(a==1){
            while(true){
                
                if(stack1.empty()){
                    stack1.push(b);
                    ans++;
                    cout<<"ans1: "<<ans<<"b: "<<b<<endl;
                    break;
                }
                else{
                    int num = stack1.top();
                    cout<<"num1: "<<num<<endl;
                    if(num==b){
                        cout<<"ans1*: "<<ans<<"b: "<<b<<endl;
                        stack1.pop();
                        break;
                    }else if(num<b){
                        stack1.push(b);
                        ans++;
                        cout<<"ans1**: "<<ans<<"b: "<<b<<endl;
                        
                    }else{
                        stack1.pop();
                        ans++;
                        cout<<"ans1***: "<<ans<<"b: "<<b<<endl;
                        break;
                    }
                }
            }
        }
        else if(a==2){
            while(true){
                if(stack2.empty()){
                    stack2.push(b);
                    ans++;
                    cout<<"ans2: "<<ans<<"b: "<<b<<endl;
                    break;
                }
                else{
                    int num = stack2.top();
                    cout<<"num2: "<<num<<endl;
           
                    if(num==b){
                        stack2.pop();
                        cout<<"ans2*: "<<ans<<"b: "<<b<<endl;
                        break;
                    }else if(num<b){
                        stack2.push(b);
                        ans++;
                        cout<<"ans2**: "<<ans<<"b: "<<b<<endl;
                        break;
                     
                    }else{
                        stack2.pop();
                        ans++;
                        cout<<"ans2***: "<<ans<<"b: "<<b<<endl;
                
                    }
                }
            }
        }
        else if(a==3){
            while(true){
                if(stack3.empty()){
                    stack3.push(b);
                    ans++;
                    break;
                }
                else{
                    int num = stack3.top();
                    if(num==b){
                        stack3.pop();
                        break;
                    }else if(num<b){
                        stack3.pop();
                        ans++;
                    }else{
                        stack3.push(b);
                        ans++;
                        break;
                    }
                }
            }
        }
        else if(a==4){
            while(true){
                if(stack4.empty()){
                    stack4.push(b);
                    ans++;
                    break;
                }
                else{
                    int num = stack4.top();
                    if(num==b){
                        stack4.pop();
                        break;
                    }else if(num<b){
                        stack4.pop();
                        ans++;
                    }else{
                        stack4.push(b);
                        ans++;
                        break;
                    }
                }
            }
        }
        else if(a==5){
            while(true){
                if(stack5.empty()){
                    stack5.push(b);
                    ans++;
                    break;
                }
                else{
                    int num = stack5.top();
                    if(num==b){
                        stack5.pop();
                        break;
                    }else if(num<b){
                        stack5.pop();
                        ans++;
                    }else{
                        stack5.push(b);
                        ans++;
                        break;
                    }
                }
            }
        }
        else if(a==6){
            while(true){
                if(stack6.empty()){
                    stack6.push(b);
                    ans++;
                    break;
                }
                else{
                    int num = stack6.top();
                    if(num==b){
                        stack6.pop();
                        break;
                    }else if(num<b){
                        stack6.pop();
                        ans++;
                    }else{
                        stack6.push(b);
                        ans++;
                        break;
                    }
                }
            }
        }
    }
    cout<<ans<<endl;

}