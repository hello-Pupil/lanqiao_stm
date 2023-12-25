#include "interrupt.h"

struct keys key[4]={0,0,0};

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance==TIM3)
	{
		key[0].keyJudge=HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0);
		key[1].keyJudge=HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_1);
		key[2].keyJudge=HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_2);
		key[3].keyJudge=HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0);
		
		for(uchar i=0;i<4;i++)
		{
			switch(key[i].keyMode){
				
				case 0:{
					if(key[i].keyJudge==0){
						key[i].keyMode=1;
					}
				}break;
				
				case 1:{
					if(key[i].keyJudge==0){
						key[i].keyValue=1;
						key[i].keyMode=2;
					}
				}break;
				
				case 2:{
					if(key[i].keyJudge==1){
						key[i].keyValue=0;
						key[i].keyMode=0;
					}
				}break;
					
			}
		}
	}
}
