#include "hw_encoder.h"
#include "mid_encoder.h"

unsigned char encoder_old_num;
long long encoder_num = 0;

static unsigned char encoder_to_dec(void)
{
    unsigned char dec ;
    if(encoder_10.signed_bit & 0b01 )
    {
        dec = 7 - (encoder_10.height_bit*4+encoder_10.mid_bit*2+encoder_10.low_bit*1);
    }
    else
    {
        dec = 15 - (encoder_10.height_bit*4+encoder_10.mid_bit*2+encoder_10.low_bit*1);
    }
    return dec;
}

void encoder_num_update(void)
{
	
	unsigned int sign_times = 0;
	unsigned char old_num;
	unsigned char num = encoder_to_dec();
	if(num > 9) return; //³¬·¶Î§ÅÐ¶Ï
	//Ïû¶¶ÅÐ¶Ï
	for(unsigned int i = 0 ; i< 250; i++)
	{
		encoder_10 = mdr_scan();
		old_num = num;
		num = encoder_to_dec();
		if((old_num ^ num) == 0)	sign_times++;
		else sign_times = 0;
	}
	if(sign_times < 240 ) return;
	//Âß¼­ÔËËã
	if(encoder_old_num == num) return;
	else if(encoder_old_num > num)
	{
		if(encoder_old_num == 9 && num == 0) encoder_num++;
		else encoder_num--;
	}
	else 
	{
		if(num == 9 && encoder_old_num == 0) encoder_num--;
		else encoder_num++;
	}
	encoder_old_num = num;
}