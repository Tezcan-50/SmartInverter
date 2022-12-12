/*
 * Application.cpp
 *
 *  Created on: Dec 11, 2022
 *      Author: Business
 */

#include "Application.h"
#include "ApplicationSetup.h"
#include "main.h"

Application::Application() : com_{} {};

void Application::Init() {
  com_.setModbusProtocol(ModbusRegNum::Battery_Voltage, 0x0003);
  com_.PackTxData(com_.getModbusReadProtocol());
  HAL_UART_Receive_IT(com_.GetModBusUartHandler(), com_.GetRxData(),
                      com_.getModbusReadProtocol().reg_number_);
}

void Application::sendTestData() {
  HAL_UART_Transmit(com_.GetModBusUartHandler(), com_.GetTxData(), 8u, 1000u);
}

void Application::RegisterAllExernalComponents() {
  com_.RegisterExternalComponents(&huart4);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
  HAL_UART_Receive_IT(application_.getComObj()->GetModBusUartHandler(),
                      application_.getComObj()->GetRxData(), 4u);
}
