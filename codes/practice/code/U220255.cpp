#include <bits/stdc++.h>
using namespace std;
int maze[102][102][102];
int n;
void read(){
  for(int z = 1;z <= n;z++)
    for(int y = 1;y <= n;y++)
      for(int x = 1;x <= n;x++)
        scanf("%d",&maze[z][y][x]);
}
