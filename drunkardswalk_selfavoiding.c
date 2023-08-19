#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

int trapcheck(int x, int y, int xlocks[], int ylocks[], int tot) {
	int count = 0;
	int check = 0;
	for (int i=0;i<tot;i++) {
		if (xlocks[i] == x - 1 && ylocks[i] == y) {
			count = count + 1;
			break;
		}
	}
	for (int i=0;i<tot;i++) {
		if (xlocks[i] == x + 1 && ylocks[i] == y) {
			count = count + 1;
			break;
		}
	}
	for (int i=0;i<tot;i++) {
		if (xlocks[i] == x && ylocks[i] == y + 1) {
			count = count + 1;
			break;
		}
	}
	for (int i=0;i<tot;i++) {
		if (xlocks[i] == x && ylocks[i] == y - 1) {
			count = count + 1;
			break;
		}
	}
	
	if (count == 4) {
		check = 1;
	}
	
	return check;
}

int main()
{
	char rerun = 'y';
	do {
		int steps;
		printf("How many steps for this simulation?: ");
		scanf("%d",&steps);
		
		int hfinal = 0, vfinal = 0, num, xlocks[steps], ylocks[steps], check=1, trap, totallocks = 0;
		char direction[6];
		
		srand(time(NULL));
		
		for (int i=0;i<steps;i++) {
			xlocks[i] = hfinal;
			ylocks[i] = vfinal;
			totallocks = totallocks + 1;
			check = 1;
			
			while (check == 1) {
				num = rand() % 100;
				
				//coordinate check
				if (num < 25) {
					for (int p=0;p<totallocks;p++) {
						if (xlocks[p] == hfinal - 1 && ylocks[p] == vfinal) {
							check = 1;
							trap = trapcheck(hfinal,vfinal,xlocks,ylocks,totallocks);
							break;
						} else {check=0;}
					}
				}
				else if (num >= 25 && num < 50) {
					for (int p=0;p<totallocks;p++) {
						if (xlocks[p] == hfinal + 1 && ylocks[p] == vfinal) {
							check = 1;
							trap = trapcheck(hfinal,vfinal,xlocks,ylocks,totallocks);
							break;
						} else {check=0;}
					}
				}
				else if (num >= 50 && num < 75) {
					for (int p=0;p<totallocks;p++) {
						if (xlocks[p] == hfinal && ylocks[p] == vfinal - 1) {
							check = 1;
							trap = trapcheck(hfinal,vfinal,xlocks,ylocks,totallocks);
							break;
						} else {check=0;}
					}
				}
				else if (num >=75 && num <= 100) {
					for (int p=0;p<totallocks;p++) {
						if (xlocks[p] == hfinal && ylocks[p] == vfinal + 1) {
							check = 1;
							trap = trapcheck(hfinal,vfinal,xlocks,ylocks,totallocks);
							break;
						} else {check=0;}
					}
				}
				
				//checks trap status and breaks while loop if necessary
				if (trap == 1) {
					int remaining = steps - i - 1;
					printf("\n\nThere are no remaining moves, %d steps were left over.",remaining);
					break;
				}
				
			}
			
			//breaks for loop if necessary
			if (trap == 1) {
					break;
			}
			
			//label each step
			if (num < 25) {
				strcpy(direction,"left");
			}
			if (num >= 25 && num < 50) {
				strcpy(direction,"right");
			}
			if (num >= 50 && num < 75) {
				strcpy(direction,"up");
			}
			if (num >=75 && num <= 100) {
				strcpy(direction,"down");
			}
			printf("\n\nNum=%d / %s",num,direction);
			
			//left
			if (num < 25) {
				hfinal = hfinal - 1;
			}
			//right
			if (num >= 25 && num < 50) {
				hfinal = hfinal + 1;
			}
			//up
			if (num >= 50 && num < 75) {
				vfinal = vfinal + 1;
			}
			//down
			if (num >=75 && num <= 100) {
				vfinal = vfinal - 1;
			}
		}
		
		//calculates displacement
		float dpmt = sqrt(pow(hfinal,2) + pow(vfinal,2));
		
		printf("\n\nThe horizontal value was %d and the vertical value was %d",hfinal,vfinal);
		printf("\n\nThe displacement was %f",dpmt);
		printf("\n\nRun again? (y/n):");
		scanf(" %c",&rerun);
		
	} while (rerun == 'y');
	return 0;
}
