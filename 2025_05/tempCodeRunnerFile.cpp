    while(!nq.empty()){
        int curx=nq.front().first;
        int cury = nq.front().second;
        nq.pop();
        for(int i=0;i<4;i++){
            int nx = curx+dx[i];
            int ny = cury+dy[i];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=n){
                if(visited[nx][ny]&&!light[nx][ny]){
                    visited[nx][ny]=true;
                    light[nx][ny]=true;
                    nq.push({nx,ny});
                }

            }
        }
    }