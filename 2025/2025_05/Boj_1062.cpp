#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int>words;
int ans=0;
int requiredMask;
// 알파벳에서 현재 위치(단어가 아님!), 글자 몇개 읽었는지, bitmask
void dfs(int idx,int count,int mask){
    if(count==k-5){
        int read=0;
        for(int word:words){
            if((mask&word)==word){
                read++;
            }
        }
        ans=max(read,ans);
        return;
    }
    for(int i=idx;i<26;i++){ // 알파벳은 26개 0번부터 25번까지
        // antc면 건너뜀
        if(requiredMask&(1<<i)){
            continue;
        }
        // 이미 포함된 글자여도 건너뜀
        if(mask&(1<<i)){
            continue;
        }
        dfs(i+1,count+1,mask|(1<<i));
    }
}
int main(){
    cin>>n>>k;
    if(k<5){
        cout<<0<<endl;
        return 0;
    }
    requiredMask |= (1<<('a'-'a'));
    requiredMask |= (1<<('n'-'a'));
    requiredMask |= (1<<('t'-'a'));
    requiredMask |= (1<<('i'-'a'));
    requiredMask |= (1<<('c'-'a'));

    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        int bit=0;
        for(char ch:str){
            bit |= (1<<(ch-'a'));
        }
        words.push_back(bit);
    }
    dfs(0,0,requiredMask);
    cout<<ans<<endl;
    

}