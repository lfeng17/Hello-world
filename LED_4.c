#include<reg52.h>

sbit ADDR0 = P1^0;
sbit ADDR1 = P1^1;
sbit ADDR2 = P1^2;
sbit ADDR3 = P1^3;
sbit ENLED = P1^4;


void main()
{
    char dir=0;
    unsigned int cnt = 0;
	unsigned int i=0;
    unsigned char shift = 0x01;
	ENLED = 0;
	ADDR3 = 1;
	ADDR2 = 1;
	ADDR1 = 1;
	ADDR0 = 0;
    TMOD = 0x01;
    TH0=0xB8;
    TL0=0x00;
    TR0=1;

    while(1)
    {   P0=~shift;
        if(TF0==1)
        {   
           TF0=0;
           TH0=0xB8;
           TL0=0x00;
           cnt++;
        if (cnt>=50)
        {  cnt=0;
           if (dir == 0)            
            {
                shift = shift << 1;  
                if (shift == 0x80)   
                {
                    dir = 1;
                }
            }
            else                     
            {
                shift = shift >> 1; 
                if (shift == 0x01)  
                {
                    dir = 0;
                }
            }

        }
       }
    }
        
}