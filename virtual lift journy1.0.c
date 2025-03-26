#include<stdio.h>
#include<stdbool.h>
#include<unistd.h>
int main()
{
    int currentfloor= 1;
    int requestedfloor;
    bool stop=false;
    printf("Elevator simulation (Floor 1 To 12)\n");
    printf("Press 1 To 12 or 0 for emergency stop\n");
    while(1)
    {
        printf("Current floor %d\n",currentfloor);
        printf("Enteer the floor you want to go: ");
        scanf("%d",&requestedfloor);
        if(requestedfloor == 0)
        {
            printf("Emergency stop activated! evevator halting immediately.\n");
            stop=true;
            printf("Simulation ended,Elevator stopped at floor %d",currentfloor);
            break;
        }
        if(requestedfloor < 1 || requestedfloor > 12)
        {
            printf("Not a valid floor number, please input the right one.");
            break;
        }
        while(currentfloor != requestedfloor)
        {
            if(stop)
            {
                printf("Emergency stop activated during movement! Elevator stop at floor %d",currentfloor);
                break;
            }
            if(currentfloor < requestedfloor)
            {
                currentfloor++;
            }
            if(currentfloor > requestedfloor)
            {
                currentfloor--;
            }
            printf("Passing floor... %d\n",currentfloor);
            sleep(1);
        }
        printf("Arrived at floor %d\n",currentfloor);
    }
    return 0;
}