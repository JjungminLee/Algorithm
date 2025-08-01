  for(auto it = city1.begin();it!=city1.end();it++){
        int p1 = province1[it->first];
        string c2 = city2[p1];
        if(province1[c2]==it->second){
            cout<<"c2 "<<c2<<endl;
            ans++;
        }

    }