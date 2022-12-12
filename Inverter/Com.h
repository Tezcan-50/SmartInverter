/*
 * Com.h
 *
 *  Created on: Dec 11, 2022
 *      Author: Business
 */

#ifndef COM_H_
#define COM_H_

#include "Protocol.h"
#include "stdint.h"
#include "stm32h7xx.h"
#include "stm32h7xx_hal_uart.h"

class Com {

public:
  Com();

  void setModbusProtocol(ModbusRegNum reg_addr, uint16_t reg_nr) {
    my_modbus_read_request_.reg_addr_ = reg_addr;
    my_modbus_read_request_.reg_number_ = reg_nr;
  }

  ModbusProtocolReadRequest getModbusReadProtocol() {
    return my_modbus_read_request_;
  }
  ModbusProtocolReadResponse getModbusResponseProtocol() {
    return my_modbus_read_response_;
  }

  void RegisterExternalComponents(UART_HandleTypeDef *modbus_uart);

  void PackTxData(ModbusProtocolReadRequest readrequest);
  void PackRxData();

  UART_HandleTypeDef *GetModBusUartHandler() { return modbus_uart_; }

  uint8_t *GetTxData() { return txData_; }
  uint8_t *GetRxData() { return rxData_; }

private:
  uint8_t txData_[10];
  uint8_t rxData_[10];
  ModbusProtocolReadRequest my_modbus_read_request_;
  ModbusProtocolReadResponse my_modbus_read_response_;
  UART_HandleTypeDef *modbus_uart_;
};

#endif /* COM_H_ */
