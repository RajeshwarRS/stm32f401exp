#include "stm32f401x_gpio.h"

void GPIO_Init(GPIO_Handle_t *pGPIOHandle){
uint32_t temp=0;
if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG){
 temp=(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2* pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
 pGPIOHandle->pGPIOx->MODER &= ~(0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->MODER |= temp;

}

else{

}

temp=0;
temp=(pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2* pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));

pGPIOHandle->pGPIOx->OSPEEDR &= ~(0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
pGPIOHandle->pGPIOx->OSPEEDR |= temp;

temp=0;
temp=(pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl << (2* pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
pGPIOHandle->pGPIOx->PUPDR &= ~(0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
pGPIOHandle->pGPIOx->PUPDR |= temp;

temp=0;
temp=(pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType << ( pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
pGPIOHandle->pGPIOx->OTYPER &= ~(0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
pGPIOHandle->pGPIOx->OTYPER |= temp;

temp=0;

if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode== GPIO_MODE_ALTFN)
{
 	uint8_t temp1,temp2;
	temp1= (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber /8);
	temp2= (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber %8);
	pGPIOHandle->pGPIOx->AFR[temp1] &= ~(0xF << (4* temp2)); 
	pGPIOHandle->pGPIOx->AFR[temp1] |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << (4* temp2)); 
	
}



}


void GPIO_DeInit(GPIO_RegDef_t *pGPIOx){

	if(pGPIOx == GPIOA){
                GPIOA_REG_RESET();
        }


         if(pGPIOx == GPIOB){
                GPIOB_REG_RESET();
        }

         if(pGPIOx == GPIOC){
                GPIOC_REG_RESET();
        }

}






/*peripheral clock init*/
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx,uint8_t EnorDi){

if(EnorDi == ENABLE){
	if(pGPIOx == GPIOA){
		GPIOA_PCLK_EN();
	}


	 else if(pGPIOx == GPIOB){
                GPIOB_PCLK_EN();
        }

	 else if(pGPIOx == GPIOC){
                GPIOC_PCLK_EN();
        }


}

else
{
	if(pGPIOx == GPIOA){
                GPIOA_PCLK_DI();
        }


         else if(pGPIOx == GPIOB){
                GPIOB_PCLK_DI();
        }

         else if(pGPIOx == GPIOC){
                GPIOC_PCLK_DI();
        }


}

}




uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber){

uint8_t value;
value = (uint8_t)((pGPIOx->IDR >> PinNumber) & 0x1);
return value;
}


uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx){
uint16_t value;
value = (uint16_t)pGPIOx->IDR;
return value;
}

void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber,uint8_t Value){

	if(Value==GPIO_PIN_SET){
	pGPIOx->ODR |= (1<<PinNumber);	
	}
	else{
	pGPIOx->ODR &= ~(1<< PinNumber);
	}

}

void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx,uint16_t Value){

	pGPIOx->ODR=Value;
}


void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber){
	pGPIOx->ODR ^= (1<<PinNumber);
}

void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority,uint8_t EnorDi){


}

void GPIO_IRQHandling(uint8_t PinNumber);





