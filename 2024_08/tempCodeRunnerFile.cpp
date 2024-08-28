if(sum+v[idx]<=l){
            dq.push_back(v[idx]);
            sum+=v[idx];
            idx++;
        }else{
            // 최대하중을 넘기는 경우
            dq.push_back(0);
        }