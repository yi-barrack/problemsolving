#include <stdio.h>
#include <math.h>

/* C언어에서는 bool type이 없으므로 따로 정의*/
typedef enum
{
    false = 0, true = 1
}bool;

/*원안에 포함되어있는지 체크하는 함수 */
bool get_ready(int x,int y, int cx, int cy, int r);

int main(){
    
    int T;
    scanf("%d", &T);
   
    for(int t=0; t<T ; t++){
         
        int x1, y1, x2, y2, num, count=0;
         
               scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
   
        scanf("%d", &num);
            
        for (int i=0; i<num; i++){
            /* 원안에 몇개가 들어가있는지 검사한다 */
            int xt,yt,rt;
            scanf("%d %d %d", &xt, &yt, &rt);
                  

/* XOR */ 
            if (get_ready(x1,y1,xt,yt,rt) != get_ready(x2,y2,xt,yt,rt)) {
            count ++;
            }
        }
        printf("%d\n", count);
/* 출력값에 \n 빼먹지말자. 삽질함; */
           
    }
       
    return 0;
}


bool get_ready(int x, int y, int cx, int cy, int r) {  
   if ( (x - cx)*(x - cx) + (y - cy)*(y - cy) > r*r )  
     return false;  
   else  
     return true;  
 }  