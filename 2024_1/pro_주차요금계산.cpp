#include <string>
#include <vector>
#include <algorithm>
#include<iostream>
#include<cmath>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    // 입차와 출차 시간 계산
    // 입차 pair 출차 pair
    // <차량번호,입차시간> 
    // <차량번호,출차시간>

    vector<int> answer;
    vector<pair<int,int>> answerPair; // 차량변호,요금
    vector<pair<int,int>> carAns; // 차량번호, 시간
    vector<pair<int, pair<int, int>>> inTimeVector;
    vector<pair<int, pair<int, int>>> outTimeVector;

    int defaultTime = fees[0];
    int defaultFee = fees[1];
    int unitTime = fees[2];
    int unitFee = fees[3];
    for (int i = 0; i < records.size(); i++) {
        string time = records[i].substr(0, 5);
        int hour = stoi(records[i].substr(0, 2));
        int minute = stoi(records[i].substr(3, 5));
        int carNum = stoi(records[i].substr(6, 10));
        string flag = records[i].substr(11, 13);
      

        if (flag == "IN") {
            inTimeVector.push_back({carNum, {hour, minute}});
        } else {
            outTimeVector.push_back({carNum, {hour, minute}});
        }
    }

    for (int i = 0; i < inTimeVector.size(); i++) {
        int carNum = inTimeVector[i].first;
        int startHour = inTimeVector[i].second.first;
        int startMinute = inTimeVector[i].second.second;
        int endHour = 0;
        int endMinute = 0;


       
        for (int j = 0; j < outTimeVector.size(); j++) {
            if (outTimeVector[j].first == carNum) {
                endHour = outTimeVector[j].second.first;
                endMinute = outTimeVector[j].second.second;
                outTimeVector[j].first=-1;
                break;
            }
        }
     
        if(endHour==0&&endMinute==0){
            endHour=23;
            endMinute=59;
        }

        bool flag = true;
        for(int j=0;j<carAns.size();j++){
            if(carAns[j].first==carNum){
                flag=false;
                if(endMinute<startMinute){
                    endHour-=1;
                    endMinute+=60;
                }
                carAns[j].second+=((endHour-startHour)*60 + (endMinute-startMinute));
                break;
            }
        }
        if(flag){
            if(endMinute<startMinute){
                    endHour-=1;
                    endMinute+=60;
            }
            carAns.push_back({carNum,(endHour-startHour)*60 + (endMinute-startMinute)});

        }
    }


    for(int i=0;i<carAns.size();i++){
       
     
        if(carAns[i].second>defaultTime){
            int newFee = 0;
            if((carAns[i].second-defaultTime)%unitTime!=0){
                newFee = (carAns[i].second-defaultTime)/unitTime+1;

            }else{
                newFee = (carAns[i].second-defaultTime)/unitTime;
            }
            int fee =defaultFee+(newFee)*unitFee;
            carAns[i].second=fee;
        }else{
            carAns[i].second=defaultFee;
        }

    }
     sort(carAns.begin(), carAns.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    });


    for(int i=0;i<carAns.size();i++){
        answer.push_back(carAns[i].second);
         cout<<carAns[i].second<< endl;
      
    }
    


    return answer;
}

int main(){
    vector<int> a = {180, 5000, 10, 600};
    vector<string> b = {"05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"};

   solution(a,b);
 
    return 0;
}