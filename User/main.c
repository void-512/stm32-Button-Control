#include "stm32f10x.h"                  // Device header
#include "delay.h"

int main(void) {
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructureInput;
	GPIO_InitStructureInput.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructureInput.GPIO_Pin = GPIO_Pin_4;
	GPIO_InitStructureInput.GPIO_Speed = GPIO_Speed_10MHz;
	
	GPIO_InitTypeDef GPIO_InitStructureOutput;
	GPIO_InitStructureInput.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructureInput.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStructureInput.GPIO_Speed = GPIO_Speed_10MHz;
	
	GPIO_Init(GPIOE, &GPIO_InitStructureOutput);
	GPIO_Init(GPIOE, &GPIO_InitStructureInput);
	
	while(1) {
		
		if (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_4) == Bit_RESET) {
			delay_ms(10);
			if (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_4) == Bit_RESET)
				GPIO_WriteBit(GPIOE, GPIO_Pin_5, Bit_SET);
		}
		else 
			GPIO_WriteBit(GPIOE, GPIO_Pin_5, Bit_RESET);
	}
}
