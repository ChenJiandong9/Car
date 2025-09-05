#include "stm32f10x.h" // Device header
#include "FreeRTOS.h"
#include "task.h"
#include "usart1.h"
#include "MyTask.h"
// #include "DHT11Task.h"
#include "delay.h"
#include "BH1750.h"
// #include "queue.h"
#include "RGB.h"
#include "MyTask.h"
#include "INA219.h"
extern SemaphoreHandle_t xSemaphore_MyI2C, xSemaphore_Usart1Send;
extern TaskHandle_t StartTask_Handle;
// void ReadLux(void *pvParameters);
// void test(void);
int main()
{
    // float voltage, current;

    // xTaskCreate(myTask1, "Task1", 128, NULL, 2, NULL);
    SystemInit();
    delay_Init();
    MyI2C_Init();
    relay_init();
    RGB_Init();
    // BH1750_Init();
    USART1_Init(115200);
    delay_s(1);
    while (INA219_Init() != INA219_OK)
        delay_ms(100);

    // RGB_Set(255, 255, 255);

    // INA219_Init(); // INA219_Init()会初始化调用i2c才对，但是它会因为信号量而被阻塞，所以不能放在初始化区域
    // xSemaphore_MyI2C = xSemaphoreCreateBinary();
    // xSemaphore_Usart1Send = xSemaphoreCreateBinary();
    // xSemaphoreGive(xSemaphore_MyI2C);
    // xSemaphoreGive(xSemaphore_Usart1Send);
    xTaskCreate(start_task, "start_task", 128, NULL, 5, &StartTask_Handle);
    vTaskStartScheduler();

    // uint16_t i;
    while (1)
    {
        // USART1_SendByte(0);
        // delay_ms(1000);
        // INA219_GetBusVoltage_mV(&voltage);
        // delay_ms(100);
        // INA219_GetCurrent_uA(&current);
        // //  USART1_SendString("Voltage:");
        // USART1_Send((uint8_t *)&voltage, 4);
        // //  USART1_SendString("current:");
        // delay_ms(800);
        // USART1_Send((uint8_t *)&current, 4);
        // // USART1_SendString("\r\n");
        // delay_ms(800);
    }
}
// extern TaskHandle_t myTaskHandler;
// if (myTaskHandler != NULL)
// {
//     vTaskDelete(myTaskHandler);
//     myTaskHandler = NULL;
// }

// void ReadLux(void *pvParameters)
// {
//     float lux_value;
//     uint8_t Buff[2];
//     uint16_t data;
//     // 发送测量指令并读取
//     uint8_t power=BH1750_ORDER_POWER;
//     uint8_t measurement = BH1750_ORDER_MEASUREMENT;
//     while (1)
//     {
//         // 通过xSemaphore_MyI2C信号避免冲突
//         // xSemaphoreTake(xSemaphore_MyI2C, portMAX_DELAY);
//         MyI2C_Write(BH1750_ADDRESS, &power, 1);
//         MyI2C_Write(BH1750_ADDRESS, &measurement, 1);
//         // xSemaphoreGive(xSemaphore_MyI2C);
//         // vTaskDelay(19);
//         delay_ms(19);
//         // xSemaphoreTake(xSemaphore_MyI2C, portMAX_DELAY);
//         MyI2c_Read(BH1750_ADDRESS, Buff, 2);
//         // xSemaphoreGive(xSemaphore_MyI2C);

//         //数据处理
//         data = Buff[0];
//         data <<= 8;
//         data |= Buff[1];
//         lux_value = data * BH1750_RESOLUTION / 1.2;
//         // xQueueSend(xQueue_Lux, &lux_value,portMAX_DELAY);
//         // vTaskDelay(500);
//         delay_ms(1000);
//     }
// }
//  void test(void)
//  {
//      RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
//      GPIO_InitTypeDef GPIO_InitStructure;
//      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
//      GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
//      GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//      GPIO_Init(GPIOB, &GPIO_InitStructure);
//      while (1)
//      {
//          /* code */
//          GPIO_ResetBits(GPIOB,GPIO_Pin_10);
//          delay_ms(1000);
//          GPIO_SetBits(GPIOB,GPIO_Pin_10);
//          delay_ms(1000);
//      }

//  }
