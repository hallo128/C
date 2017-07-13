#include <stdio.h>

int main(int argc, const char * argv[]) {
    int i,j,k,m,n;
    
    for (i=1; i<12; i++) {
        for (j=i+1; j<12; j++) {
            for (k=j+1; k<12; k++) {
                for (m=k+1; m<12; m++) {
                    for (n=m+1; n<12; n++) {
                        if (i+j+k+m+n == 16) {
                            printf("%d\t%d\t%d\t%d\t%d\t\n",i,j,k,m,n);
                        }
                    }
                }
            }
        }
    }

    return 0;
}
