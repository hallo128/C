#include <stdio.h>

int main(){
    
    int i;
    double high=100,y=0;
    
    for (i=0; i<10; i++) {
        high = high / 2;
        y += (3 * high);
    }
    printf("%lf\t%lf\n",high,y);
    
    return 0;
}