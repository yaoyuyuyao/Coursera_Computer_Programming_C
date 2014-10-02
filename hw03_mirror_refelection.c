#include <stdio.h>

int main(void) {
	int d, w;
	scanf ("%d", &d);
	scanf ("%d", &w);
	int cell[w][d];
	int i, j;
	int c, r;
	int direction, location = 0;
	for (i=0;i<w;i++){
		for (j=0;j<d;j++){
			scanf("%d", &cell[i][j]);
		}
	}
	for (location = 0; location<2*(w+d);location++){
        if (location < d){
        	r = w-1;
        	c = location;
            direction = 0;
        }
        else if (location >= d && location < w+d){
        	r = w+d-location-1;
        	c = d - 1;
            direction = 3;
        }
        else if (location >= w+d && location < 2*d+w){
        	r = 0;
            c = 2*d+w-location-1;
            direction = 2;
        }
        else {
            r = location-2*d-w;
            c = 0;
            direction = 1;
        }
        do {
        	switch(cell[r][c]){
        		case 1:
        		switch (direction){
        			case 0:
        			direction = 1;
        			break;
        			case 1:
        			direction = 0;
        			break;
        			case 2:
        			direction = 3;
        			break;
        			default:
        			direction = 2;
        		}
        		break;
        		case 2:
        		switch (direction){
        			case 0:
        			direction = 3;
        			break;
        			case 1:
        			direction = 2;
        			break;
        			case 2:
        			direction = 1;
        			break;
        			default:
        			direction = 0;
        		}
        	}
        	switch (direction){
        		case 0:
        		r -= 1;
        		break;
        		case 1:
        		c += 1;
        		break;
        		case 2:
        		r += 1;
        		break;
        		default:
        		c -= 1;
        	}
        	if (r == w){ 
                printf("%d ", c);
            }
            if (c == d) {
                printf("%d ", w+d-r-1);
            }
            if (r == -1){ 
                printf("%d ", 2*d+w-c-1);
            }
            if (c == -1){
        	    printf("%d ", 2*d+w+r);
        	}
        }while (r < w && c < d && r>-1 && c > -1);
    }
	return 0;
}
