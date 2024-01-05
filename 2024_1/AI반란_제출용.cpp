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
bool canInsertCapArr(int N, long* cap, int idx) {
    cap[idx-1]+=1;
     

    long zeroIdxCnt = 0; //능력 안채워진 idx
    long nonZeroIdxCnt = 0;
    for(int i=0;i<3;i++){
        if(cap[i]==0){
            zeroIdxCnt+=1;
        }else if(cap[i]!=0){
            nonZeroIdxCnt+=cap[i];
        }
    }

    if(zeroIdxCnt==0){
        return true;
    }
    if((N-nonZeroIdxCnt)/zeroIdxCnt>=1){
         
        return true;
    }
    else{
        cap[idx-1]-=1;
        return false;
    }
}

long selectCapability(int N, Node& node, long* cap) {
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
            target = i;
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

        int N;
        cin >> N;


    
        if (N <= 2) {
            for(int j=0;j<N;j++){
                int a,b,c;
                cin>>a>>b>>c;
            }
            vAns.push_back(-1);
        } else {
           
            long cap[] = {0,0,0};
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
        cout<<"#"<<i+1<<" "<<vAns[i]<<endl;
    }

    return 0;
}
