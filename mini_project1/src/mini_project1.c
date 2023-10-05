/*
 ============================================================================
 Name        : mini_project1.c
 Author      :Esraa Fawzy
 Version     :
 Copyright   : Your copyright notice
 Description : mini_project1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define WITH_ENGINE_TEMP_CONTROLLER 1
//#define WITH_ENGINE_TEMP_CONTROLLER 0
enum state{OFF,ON};
typedef enum state state ;
typedef struct
{

	state Engine_state;
	state AC;
	state Engine_Temp_Controller_State;
	int   Vehicle_Speed;
	float room_temp;
	float   Engine_temp;
}state_of_system;


void display();
void display_set_menu();
void display_system_state(state_of_system *s1);
void traffic_c_speed (char color , state_of_system *s1);
void set_room_temp (state_of_system *s1);
void set_engine_temp (state_of_system *s1);
void speed_check(state_of_system *s1);


int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	char input;
	char color='r';
	state_of_system system1={OFF,OFF,OFF,40,35,90}; //default values
	char input_2;
	//do..while loop to display menu if the user choose to turn off engine
	do{

		display();
		scanf(" %c",&input);
		switch (input)
		{
		//when user choose 'a' engine will turn on
		case 'a':
			printf( "Turn on the vehicle engine\n\n");
			system1.Engine_state=ON;
			//while loop to display set menu after every iteration till the engine turn off
			while(system1.Engine_state!=OFF){
				display_set_menu();
				scanf(" %c",&input_2);

				switch (input_2)
				{
				case 'a':
					printf("Turn off the engine\n\n");
					system1.Engine_state=OFF;
					break;
				case 'b':
					traffic_c_speed (color,&system1); //call function to set speed of vehicle
					display_system_state(&system1);

					break;
				case 'c':
					set_room_temp (&system1);
					display_system_state(&system1);

					break;
#if (WITH_ENGINE_TEMP_CONTROLLER) // if condition is true , it will execute this part of code .
				case 'd':
					set_engine_temp (&system1);
					display_system_state(&system1);

					break;
#endif
				}
			}
			break;


		case 'b':
			printf( "Turn off the vehicle engine\n\n");
			break;
		case 'c':
			printf("Quit the system\n");
			return 0; // exit from system if the user choose c
			break;
		}}
	while(system1.Engine_state==OFF);
	return 0 ;
}
// function to ask user what want to do
void display()
{
	printf("what do you want to do ?\n");
	printf("a. Turn on the vehicle engine\n");
	printf("b. Turn off the vehicle engine\n");
	printf("c. Quit the system\n\n");
}
// function to display sensor menu , when the engine turned on
void display_set_menu()
{
	printf("a. Turn off the engine\n");
	printf("b. Set the traffic light color\n");
	printf("c. Set the room temperature (Temperature Sensor)\n");
#if (WITH_ENGINE_TEMP_CONTROLLER) // to execute line if condition is true
	printf("d. Set the engine temperature\n\n");
#endif

}
//function to display state of system
void display_system_state(state_of_system *s1)
{
	speed_check(s1); // call function to check before display , if the speed is equal 30
	if (s1->Engine_state==1)
		printf("Engine state :ON\n"); // to print ON and OFF as enum print as %d
	else
		printf("Engine state : OFF\n ");
	if (s1->AC==1)
		printf("AC :ON\n");
	else
		printf("AC : OFF\n");
#if (WITH_ENGINE_TEMP_CONTROLLER)

	if (s1->Engine_Temp_Controller_State==1)
		printf("Engine Temperature Controller State :ON\n");
	else
		printf("Engine Temperature Controller State : OFF\n");
	printf("Engine Temperature= %.2f\n\n",s1->Engine_temp);
#endif
	printf("Vehicle Speed= %d Km/hr \n",s1->Vehicle_Speed);
	printf("Room Temperature= %.2f\n\n",s1-> room_temp);
}
// function to set speed depend on color of traffic light and if the user enter not valid color , it will ask for another input
void traffic_c_speed (char color , state_of_system *s1)
{
	do{
		printf("Enter the required color \n");
		printf(" g:green \n o:orange \n r:red");
		scanf(" %c",&color); // scan input from user , depend on it set vehicle speed
		if (color == 'G'|| color == 'g' ) // if green color , speed will be 100
			s1->Vehicle_Speed=100;
		else if (color == 'O'|| color == 'o' )// if yellow color , speed will be 30
			s1->Vehicle_Speed=30;
		else if (color == 'r'|| color == 'R' )// if red color , vehicle stops
			s1->Vehicle_Speed=0;
		else
			printf("Not Valid input ,please enter valid one \n ");
	}
	while (color !='o' && color !='g' && color !='r' && color !='G'&& color !='O'&& color !='R'); // to enter valid input


}
// function to set room temperature has parameter as pointer to structure  to can modify on it
void set_room_temp (state_of_system *s1)
{
	float temp;
	printf("Enter the room temperature \n");
	scanf("%f",&temp); // scan temperature from user
	/*if temperature is less than 10 or greater than 30 ,
	 * turn on AC and set room temperature to 20
	 * else , turn off AC */

	if(temp<10.00 || temp >30.00 )
	{
		s1->AC=ON;
		s1->room_temp=20;
	}
	else
		s1->AC=OFF;
}
// function to set engine temperature has parameter as pointer to structure  to can modify on it
void set_engine_temp (state_of_system *s1)
{
	float temp;
	printf("Enter the engine temperature \n");
	scanf("%f",&temp);

	/*if temperature is less than 100 or greater than 150 ,
	 * turn on engine temperature controller and set engine temperature to 125
	 * else , turn off Engine temperature */

	if(temp<100 ||temp>150 )
	{
		s1->Engine_Temp_Controller_State=ON;
		s1->Engine_temp=125;
	}

	else
		s1->Engine_Temp_Controller_State=OFF;
}
/*function to check if speed ==30 before display */

void speed_check(state_of_system *s1)
{
	if (s1->Vehicle_Speed==30)
	{
		s1->AC=ON; //Turn ON AC
#if (WITH_ENGINE_TEMP_CONTROLLER)
		s1->Engine_temp=s1->Engine_temp*(5.00/4.00)+1.00; //set engine temperature to: current temperature * (5/4) + 1
		s1->Engine_Temp_Controller_State=ON;	//Turn ON “Engine Temperature Controller”
#endif
		s1->room_temp=s1->room_temp*(5.00/4.00)+1.00; //set room temperature to current temperature * (5/4) + 1
	}
}
