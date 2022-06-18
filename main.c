/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "string.h"
#include "stdio.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */
uint8_t BinNum = 0;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);
/* USER CODE BEGIN PFP */
//char y[15] = {0};

 /*void __io_putchar(uint8_t ch)
 {
	 HAL_UART_Transmit(&huart1, &ch, 1, 1);
 }*/

uint8_t BinToDec(int arr[], int size){
		int temp = 0;
		for (int i = 0; i < size; i++){

			temp *= 2;
			temp += arr[i];

    }

    return temp;
}

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */


/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

	HAL_GPIO_TogglePin(GPIOB, LED_Pin);

	uint8_t MassEnc[128] = {127,63,62,58,56,184,152,24,8,
							72,73,77,79,15,47,175,191,159,
							 31,29,28,92,76,12,4,36,164,166,
							 167,135,151,215,223,207,143,142,
							 14,46,38,6,2,18,82,83,211,195,203,
							 235,239,231,199,71,7,23,19,3,1,9,
							 41,169,233,225,229,245,247,243,227,
							 163,131,139,137,129,128,132,148,212,
							 244,240,242,250,251,249,241,209,193,
							 197,196,192,64,66,74,106,122,120,121,
							 125,253,252,248,232,224,226,98,96,32,33,
							 37,53,61,60,188,190,254,126,124,116,112,
							 113,49,48,16,144,146,154,158,30,94,95};
	int InPuts[7] = {0};

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

	  	  	    if (HAL_GPIO_ReadPin(GPIOA, PIN1_Pin) == GPIO_PIN_RESET){


	  	  	  	  		  	  InPuts[7] = 1;
	  	  	  	  	  	}
	  	  	  	  	  	else{

	  	  	  	  	  		  InPuts[7] = 0;
	  	  	  	  	      }
	  	    	if (HAL_GPIO_ReadPin(GPIOA, PIN2_Pin) == GPIO_PIN_RESET){

	  	  	  	  	  	  InPuts[6] = 1;

	  	  	  	  	      }
	  	  	  	  	  	else{

	  	  	  	  	  	  InPuts[6] = 0;

	  	  	  	  	  	}
	  	  	  	 if (HAL_GPIO_ReadPin(GPIOA, PIN3_Pin) == GPIO_PIN_RESET){

	  	  	  		          InPuts[5] = 1;

	  	  	  	  	  	}
	  	  	  	  	  	else{

	  	  	  	  	  		  InPuts[5] = 0;

	  	  	  	  	  	}
	  	  	  	 if (HAL_GPIO_ReadPin(GPIOA, PIN4_Pin) == GPIO_PIN_RESET){

	  	  	  		  	  InPuts[4] = 1;

	  	  	  	  	  	}
	  	  	  	  	  	else{
	  	  	  	  	  		  InPuts[4] = 0;

	  	  	  	  	  	}
	  	  	  	 if (HAL_GPIO_ReadPin(GPIOA, PIN5_Pin) == GPIO_PIN_RESET){

	  	  	  			 	  InPuts[3] = 1;

	  	  	  	  	  	}
	  	  	  	  	  	else{
	  	  	  	  			  InPuts[3] = 0;

	  	  	  	  	  	}
	  	  	  	 if (HAL_GPIO_ReadPin(GPIOA, PIN6_Pin) == GPIO_PIN_RESET){

	  	  	  		          InPuts[2] = 1;

	  	  	  	  	  	}
	  	  	  	  	  	else{
	  	  	  	  	  		  InPuts[2] = 0;

	  	  	  	  	  	}
	  	  	  	 if (HAL_GPIO_ReadPin(GPIOA, PIN7_Pin) == GPIO_PIN_RESET){

	  	  	  		        InPuts[1] = 1;


	  	  	  	  	  	}
	  	  	  	  	  	else{
	  	  	  	  	 		  InPuts[1] = 0;

	  	  	  	  	  	}
	  	  	  	 if (HAL_GPIO_ReadPin(GPIOA, PIN8_Pin) == GPIO_PIN_RESET){

	  	  	  		        InPuts[0] = 1;

	  	  	  	  	  	}
	  	  	  	  	  	else{
	  	  	  	  	  			InPuts[0] = 0;

	  	  	  	  	  	}


	  	  	  	     BinNum = BinToDec(InPuts,8);

	  	  	    	 char p[64] = {0};

	  	  	  	  	  	for(int i = 0; i <= 127; i++){
	  	  	  	  	  		if(MassEnc[i] == BinNum)
	  	  	  	  	  		{

	  	  	  	  	  			 sprintf(p,"DecNum: %d\n\r",BinNum);

	  	  	  	  	  		  	 HAL_UART_Transmit(&huart1, p , sizeof(p) , -1);
	  	  	  	  	  			 HAL_Delay(1000);
	  	  	  	  	  		}

	  	  	  	  	  	}

  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART1;
  PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);

  /*Configure GPIO pins : PIN5_Pin PIN6_Pin PIN7_Pin PIN8_Pin
                           PIN4_Pin PIN3_Pin PIN2_Pin PIN1_Pin */
  GPIO_InitStruct.Pin = PIN5_Pin|PIN6_Pin|PIN7_Pin|PIN8_Pin
                          |PIN4_Pin|PIN3_Pin|PIN2_Pin|PIN1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : LED_Pin */
  GPIO_InitStruct.Pin = LED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

