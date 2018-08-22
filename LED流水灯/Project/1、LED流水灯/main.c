/**
  ******************************************************************************
  * @file    Project/STM32F10x_StdPeriph_Template/main.c 
  * @author  MCD Application Team
  * @version V3.3.0
  * @date    04/16/2010
  * @brief   Main program body
  ******************************************************************************
  * @copy
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2010 STMicroelectronics</center></h2>
  */ 

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include <stdio.h>


/** @addtogroup Template_Project
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
#define RCC_GPIO_LED                                 RCC_APB2Periph_GPIOD
#define GPIO_LED_PORT                                GPIOD    
#define GPIO_LED1                                    GPIO_Pin_2    
#define GPIO_LED2                                    GPIO_Pin_3    
#define GPIO_LED3                                    GPIO_Pin_4    
#define GPIO_LED4                                    GPIO_Pin_7
#define GPIO_LED_ALL                                 GPIO_LED1 |GPIO_LED2 |GPIO_LED3 |GPIO_LED4 

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/


///////////////////////////////////////LED//////////////////////////////////////
void LED_config(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  /* Enable GPIOB, GPIOC and AFIO clock */
  RCC_APB2PeriphClockCmd(RCC_GPIO_LED | RCC_APB2Periph_AFIO , ENABLE);  //RCC_APB2Periph_AFIO
  
  /* LEDs pins configuration */
  GPIO_InitStructure.GPIO_Pin = GPIO_LED_ALL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(GPIO_LED_PORT, &GPIO_InitStructure);
}

void Led_Turn_on_all(void)
{
	/* Turn On All LEDs */
    GPIO_ResetBits(GPIO_LED_PORT, GPIO_LED_ALL);
}

void Led_Turn_on_1(void)
{
	/* Turn On LED1 */
    GPIO_ResetBits(GPIO_LED_PORT, GPIO_LED1);
}

void Led_Turn_on_2(void)
{
	/* Turn On LED2 */
    GPIO_ResetBits(GPIO_LED_PORT, GPIO_LED2 );
}

void Led_Turn_on_3(void)
{
	/* Turn On LED3 */
    GPIO_ResetBits(GPIO_LED_PORT, GPIO_LED3);
}


void Led_Turn_on_4(void)
{
	/* Turn On LED3 */
    GPIO_ResetBits(GPIO_LED_PORT, GPIO_LED4);
}

void Led_Turn_off_all(void)
{
	/* Turn Off All LEDs */
    GPIO_SetBits(GPIO_LED_PORT, GPIO_LED_ALL);
}

void Led_Turn_on(u8 led)
{
    Led_Turn_off_all();

	/* Turn Off Select LED */
    switch(led)
    {
        case 0:
          Led_Turn_on_1();
          break;

        case 1:
          Led_Turn_on_2();
          break;

        case 2:
          Led_Turn_on_3();
          break;

        case 3:
          Led_Turn_on_4();
          break;
          
        default:
          Led_Turn_on_all();
          break;
    }
}


static void Delay_ARMJISHU(__IO uint32_t nCount)
{
  for (; nCount != 0; nCount--);
}


void testGit(void)
{

}
void testGit2(void)
{

}

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
  u8 KeyNum = 0;

  LED_config();
  Led_Turn_on_all();
  Delay_ARMJISHU(6000000);
  Led_Turn_off_all();
  Delay_ARMJISHU(6000000);

  KeyNum=0;
  /* Main loop */
  while (1)
  {
      //Led_Turn_on_Hex(KeyNum);
      Led_Turn_off_all();
      Led_Turn_on(KeyNum%4);
      KeyNum++;

      Delay_ARMJISHU(1000000);
  }  
}


#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */


/******************* (C) COPYRIGHT 2010 STMicroelectronics *****END OF FILE****/
