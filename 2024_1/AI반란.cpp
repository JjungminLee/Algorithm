#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    long a;
    long b;
    long c;
    long sum;

    Node(long a, long b, long c, long sum) : a(a), b(b), c(c), sum(sum) {}
};

int T;
vector<long> vAns;
bool canInsertCapArr(int N, int* cap, int idx) {

    cout<<"현재 capArr"<<endl;
     for(int i=0;i<3;i++){
        cout<<cap[i]<<" ";
     }
    cout<<endl;

    cap[idx-1]+=1;
     

    int zeroIdxCnt = 0; //능력 안채워진 idx
    int nonZeroIdxCnt = 0;
    for(int i=0;i<3;i++){
        if(cap[i]==0){
            zeroIdxCnt+=1;
        }else if(cap[i]!=0){
            nonZeroIdxCnt+=cap[i];
        }
    }
    cout<<"zero"<<zeroIdxCnt<<" Non zero"<<nonZeroIdxCnt<<endl;
    //cout<<"나눗셈 "<<(N-nonZeroIdxCnt)/zeroIdxCnt<<endl;
    if(zeroIdxCnt==0){
        return true;
    }
    if((N-nonZeroIdxCnt)/zeroIdxCnt>=1){
        // cout<<"넣을수 있다!"<<idx<<endl;
         
        return true;
    }
    else{
        cap[idx-1]-=1;
        return false;
    }
}

long selectCapability(int N, Node& node, int* cap) {
    long a = node.a;
    long b = node.b;
    long c = node.c;
    vector<pair<int, long>> capVector;
    capVector.push_back({1, a});
    capVector.push_back({2, b});
    capVector.push_back({3, c});
    sort(capVector.begin(), capVector.end(), [](const pair<int, long>& lhs, const pair<int, long>& rhs) {
        return lhs.second > rhs.second;
    });
    int target=0;
    for (int i = 0; i < 3; i++) {
        
        if (canInsertCapArr(N,cap, capVector[i].first)) {
            cout<<"i번째 순회"<<capVector[i].first<<endl;
            target = i;
            cout<<"빼야하는 능력치"<<capVector[i].second<<endl;
            break;
        }
    }
    // cout<<"target"<<target<<endl;
    return capVector[target].second;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> T;
    

    for (int i = 0; i < T; i++) {
        // cout<<"i"<<i<<endl;
        int N;
        cin >> N;
        // cout<<"N "<<N<<endl;
    
        if (N <= 2) {
            vAns.push_back(-1);
        } else {
           
            int cap[] = {0,0,0};
            vector<Node> v;
            long long minCnt = 0;

            v.clear(); // 벡터 초기화
            for (int j = 0; j < N; j++) {
                long a, b, c;
                cin >> a >> b >> c;
                long sum = a + b + c;
                minCnt += sum;
                v.push_back(Node(a, b, c, sum));
            }
            

            sort(v.begin(), v.end(), [](const Node& lhs, const Node& rhs) {
                return lhs.sum > rhs.sum;
            });

            for (int j = 0; j < N; j++) {
                long capNum = selectCapability(N,v[j], cap);
                
                minCnt -= capNum;
            }
            vAns.push_back(minCnt);
        }
    }


    for(int i=0;i<vAns.size();i++){
        cout<<vAns[i]<<endl;
    }

    return 0;
}
