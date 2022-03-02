#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

char *argv0;

void
usage(void)
{
	fprintf(stderr, "usage: %s <x1> <y1> <x2> <y2>\n", argv0);
	exit(1);
}

void
printline(int x1, int y1, int x2, int y2)
{
	int px, py, dx, dy;
	float x, y, l, c, dl, dlb;
	px = x1 ; py = y1 ;
	dl = 1 ;
	dlb = dl/10 ;
	dx = x2 - x1 ;
	dy = y2 - y1 ;
	c = sqrt(dx*dx + dy*dy) ;

	l = dl ;
	printf("%d %d\n", x1, y1);
	do{
		start:
		x = (float)x1 + (l/c) * dx ;
		y = (float)y1 + (l/c) * dy ;

		/* Every next point must differ max' for 1. */
		while(abs(px - (int)x) > 1 || abs(py - (int)y) > 1){
			l -= dlb ;
			goto start;
		}

		/* Skip repeating values. */
		if(px != (int)x || py != (int)y )
			printf("%d %d\n", (int)x, (int)y);

		l += dl ;
		px = (int)x ;
		py = (int)y ;
	}while(l <= c);

	if((int)x != x2 || (int)y!=y2)
		printf("%d %d\n", x2, y2);
}

int
main(int argc, char *argv[])
{
	int x1, y1, x2, y2;

	argv0 = argv[0] ;
	if(argc!=5)
		usage();

	x1 = atoi(argv[1]) ; 
	y1 = atoi(argv[2]) ;
	x2 = atoi(argv[3]) ;
	y2 = atoi(argv[4]) ;
	
	printline(x1, y1, x2, y2);

	return 0 ;
}
