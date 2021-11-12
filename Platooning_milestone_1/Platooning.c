#include<stdio.h>
#include<conio.h>
#include<pthread.h>

int *initializePlatoon(int n,int d, int x1, int y1);


void main()
{

   /*Starting of PLatoon*/
       /* - */	
	int nTrucks;
	int dis;
	int x1, y1;
	int rVelocity;
	int accel;
	int choice;
	int nSteps = 5;
	int j = 0;
	bool platooning;
	
	printf("Please enter number of trucks: ");
	scanf("%d", &nTrucks);
	printf("Please enter number of distance: ");
	scanf("%d", &dis);
	printf("Please enter start of x coordinate: ");
	scanf("%d", &x1);
	printf("Please enter start of y coordinate: ");
	scanf("%d", &y1);
	
	
	int * arr;
	
	
	int arrx[nTrucks];
	int arry[nTrucks];
	arrx[0] = x1;
	arry[0] = y1;
	for(int i = 1; i < nTrucks; i++){
		arrx[i] = arrx[i-1] + dis;
		arry[i] = arry[i-1] + dis;
	}
	
	while(true){
		for(int k = j*nSteps; k < nSteps*(j+1); k++){
			for(int i = 0; i < nTrucks; i++){
				printf("x%d:%d-y%d:%d\n",i+1,arrx[i] + k*dis,i+1,arry[i] + k*dis);
			}
			printf("\n");
			
		}
		
		printf("run or stop ");
		printf("\n");
		scanf("%d",&platooning);
		//printf("%d",platooning);
		switch(platooning){
			case 0:
				goto EndWhile;
				break;
		
		}
		
		
		j++;
	}
	EndWhile: ;
	return 0;
    
    initializePlatoon();

    Update_Leader_coordinates();



   /*Loop of the PLatoon*/
       /* - coordinates of the truck want to be tracked*/
       /* -*/

    while()
    {
        /*Error handling*/
		/*Checking for coupling & de-coupling*/
    }

}

int *initilizePlatoon(int n,int d, int x1, int y1){
	
	
	
}
