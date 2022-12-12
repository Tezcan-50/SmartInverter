/*
 * Com.cpp
 *
 *  Created on: Dec 11, 2022
 *      Author: Business
 */

#include "Com.h"
#include "Application.h"

Com::Com()
    : txData_{}, rxData_{}, my_modbus_read_request_{}, modbus_uart_{nullptr} {};

uint16_t CRC16(const uint8_t *nData, uint16_t wLength) {
  uint8_t nTemp;
  uint16_t wCRCWord = 0xFFFF;

  while (wLength--) {
    nTemp = *nData++ ^ wCRCWord;
    wCRCWord >>= 8;
    wCRCWord ^= wCRCTable[nTemp];
  }
  return wCRCWord;
}

void Com::RegisterExternalComponents(UART_HandleTypeDef *modbus_uart) {
  modbus_uart_ = modbus_uart;
}

void Com::PackTxData(ModbusProtocolReadRequest readrequest) {
  uint16_t temp_crc;
  txData_[0] = readrequest.slave_address_;
  txData_[1] = readrequest.function_code_;
  txData_[2] = (readrequest.reg_addr_ >> 8);
  txData_[3] = (uint8_t)readrequest.reg_addr_;
  txData_[4] = (readrequest.reg_number_ >> 8);
  txData_[5] = (uint8_t)readrequest.reg_number_;
  temp_crc = CRC16(txData_, 6u);
  txData_[6] = (uint8_t)temp_crc;
  txData_[7] = (temp_crc >> 8);
}

void Com::PackRxData() {
  uint8_t i = 0;
  my_modbus_read_response_.slave_address_ = rxData_[0];
  my_modbus_read_response_.function_code_ = rxData_[1];
  my_modbus_read_response_.nr_of_bytes_ = rxData_[2];
  for (i = 0; i < my_modbus_read_response_.nr_of_bytes_; i++) {
    my_modbus_read_response_.data_[i] = rxData_[3 + i];
  }
  my_modbus_read_response_.crc_ = rxData_[4 + i];
  my_modbus_read_response_.crc_ = (my_modbus_read_response_.crc_ << 8);
  my_modbus_read_response_.crc_ |= rxData_[3 + i];
}
