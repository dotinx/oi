#include<bits/stdc++.h>
using namespace std;
const int nums[] = {1,2,3,4,5,6,7,8,9};
int main(){
  for(int d0 = 0;d0 < 9;d0++)
    for(int d1 = 0;d1 < 9;d1++)
      for(int d2 = 0;d2 < 9;d2++)
        for(int d3 = 0;d3 < 9;d3++)
          for(int d4 = 0;d4 < 9;d4++)
            for(int d5 = 0;d5 < 9;d5++)
              for(int d6 = 0;d6 < 9;d6++)
                for(int d7 = 0;d7 < 9;d7++)
                  for(int d8 = 0;d8 < 9;d8++){
                      if(d0 == d1 || d1 == d2 || d2 == d3 || d3 == d4 || d4 == d5 || d5 == d6 || d6 == d7 || d7 == d8 || d8 == d0) continue;
                      if(d0 == d2 || d1 == d3 || d2 == d4 || d3 == d5 || d4 == d6 || d5 == d7 || d6 == d8 || d7 == d0 || d8 == d1) continue;
                      if(d0 == d3 || d1 == d4 || d2 == d5 || d3 == d6 || d4 == d7 || d5 == d8 || d6 == d0 || d7 == d1 || d8 == d2) continue;
                      if(d0 == d4 || d1 == d5 || d2 == d6 || d3 == d7 || d4 == d8 || d5 == d0 || d6 == d1 || d7 == d2 || d8 == d3) continue;
                      if(d0 == d5 || d1 == d6 || d2 == d7 || d3 == d8 || d4 == d0 || d5 == d1 || d6 == d2 || d7 == d3 || d8 == d4) continue;
                      if(d0 == d6 || d1 == d7 || d2 == d8 || d3 == d0 || d4 == d1 || d5 == d2 || d6 == d3 || d7 == d4 || d8 == d5) continue;
                      if(d0 == d7 || d1 == d8 || d2 == d0 || d3 == d1 || d4 == d2 || d5 == d3 || d6 == d4 || d7 == d5 || d8 == d6) continue;
                      if(d0 == d8 || d1 == d0 || d2 == d1 || d3 == d2 || d4 == d3 || d5 == d4 || d6 == d5 || d7 == d6 || d8 == d7) continue;
                      int i1 = nums[d0] * 100 + nums[d1] * 10 + nums[d2],i2 = nums[d3] * 100 + nums[d4] * 10 + nums[d5],i3 = nums[d6] * 100 + nums[d7] * 10 + nums[d8];
                      if(2 * i1 == i2 && 3 * i1 == i3){
                        printf("%d %d %d\n",i1,i2,i3);
                      }
                    }
  return 0;
}
