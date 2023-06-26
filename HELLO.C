#include<reg51.h>
sbit led1 = P2^0;
sbit led2 = P2^1;
sbit led3 = P2^2;
sbit led4 = P2^3;
PORT2=0X00;
void initialize() // Initialize Timer 1 for serial communication

{

TMOD=0x20; //Timer1, mode 2, baud rate 9600 bps

TH1=0XFD; //Baud rate 9600 bps

SCON=0x50; 

TR1=1; //Start timer 1


}



void receive() //Function to receive serial data

{

char value;

while(RI==0); //wait till RI flag is set
value=SBUF; 

RI=0; //Clear the RI flag
	
	switch(value){
		case 'a': led1= 0;break;
		case 'b': led2= 0;break;
		case 'c': led3= 0;break;
		case 'd': led4= 0;break;
		case 'A': led1= 1;break;
		case 'B': led2= 1;break;
		case 'C': led3= 1;break;
		case 'D': led4= 1;break;
	default:break;
	}
	
}
void Delay(void)
{
    int j;
    int i;
    for(i=0;i<10;i++)
    {
        for(j=0;j<10000;j++)
        {
        }
    }
}

void main()

{
led1 =0;
led2 =0;
led3 =0;
led4 =0;
while(1)

{

initialize();
receive();
Delay();
}

}
