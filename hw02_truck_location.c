#include <stdio.h>
#include <math.h>

int main(void) {
    int x_cord= 0, y_cord = 0;
    int change = 0;
    int n1 = 0, newn1 = 0, n2 = 0;
    scanf("%d", &newn1);
    do{
        switch (change){
    	    case 0:
    	    y_cord += (newn1-n1) * 10;
            break;
            case 1:
            x_cord += (newn1-n1) * 10;
            break;
            case 2:
    	    y_cord -= (newn1-n1) * 10;
            break;
            default:
            x_cord -= (newn1-n1) * 10;
        }
        scanf("%d", &n2);
        change = (4 + change + (int)pow(-1,n2)) % 4;
        n1 = newn1;
        scanf("%d", &newn1);
    }while (n2 != 3);
    printf("%d ", x_cord);
    printf("%d", y_cord);
	return 0;
}
