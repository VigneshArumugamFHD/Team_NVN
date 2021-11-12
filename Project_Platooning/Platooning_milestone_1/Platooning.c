#include<stdio.h>
#include<conio.h>
#include <pthread.h>
#include <omp.h>
#include <stdbool.h>

pthread_mutex_t count_mutex     = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t condition_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  condition_cond  = PTHREAD_COND_INITIALIZER;

void *MeasureRvelocity();
void *MeasureDistance();
void *GetAcceleration();
void *GetCoordinates();
void *Decoupling();
void *Coupling();

int *initializePlatoon(int n,int d, int x1, int y1);


/*Initializing the variables of Platoon*/
int nTrucks;
int dis;
int x1, y1;
int rVelocity;
int accel;
int choice;
int nSteps = 5;
int j = 0;
bool platooning;



void main()
{
	
	/*Threads for the platooning*/
#pragma omp parallel num_threads(8)
   {

   pthread_t thread1, thread2,thread3,thread4,thread5,thread6;

   pthread_create( &thread1, NULL, &MeasureRvelocity, NULL);
   pthread_create( &thread2, NULL, &MeasureDistance, NULL);
   pthread_create( &thread3, NULL, &GetAcceleration, NULL);
   pthread_create( &thread4, NULL, &Decoupling, NULL);
   pthread_create( &thread5, NULL, &Coupling, NULL);
   pthread_create( &thread5, NULL, &GetCoordinates, NULL);
   
   pthread_join( thread1, NULL);
   pthread_join( thread2, NULL);
   pthread_join( thread3, NULL);
   pthread_join( thread4, NULL);
   pthread_join( thread5, NULL);
   pthread_join( thread6, NULL);
   }

	
	while(true)
	{
		for(int k = j*nSteps; k < nSteps*(j+1); k++)
		{
			for(int i = 0; i < nTrucks; i++)
			{
				printf("x%d:%d-y%d:%d\n",i+1,arrx[i] + k*dis,i+1,arry[i] + k*dis);
			}
			printf("\n");
			
		}
		
		printf("run or stop ");
		printf("\n");
		scanf("%d",&platooning);
		//printf("%d",platooning);
		switch(platooning)
		{
			case 0:
				goto EndWhile;
				break;
		
		}		
		j++;
	}
	EndWhile: ;
	return 0;
    
    //initializePlatoon();

    Update_Leader_coordinates();


    while()
    {

        /*Error handling*/
		/*Checking for coupling & de-coupling*/
    }

}



void* GetCoordinates()
{
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
	for(int i = 1; i < nTrucks; i++)
	{
		arrx[i] = arrx[i-1] + dis;
		arry[i] = arry[i-1] + dis;
	}
}

int *initilizePlatoon(int n,int d, int x1, int y1)
{
	
	
	
}