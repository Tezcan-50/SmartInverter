/*
 * Protocol.h
 *
 *  Created on: Dec 11, 2022
 *      Author: Business
 */

#ifndef PROTOCOL_H_
#define PROTOCOL_H_

#include "stdint.h"

static const uint16_t wCRCTable[] = {
    0X0000, 0XC0C1, 0XC181, 0X0140, 0XC301, 0X03C0, 0X0280, 0XC241, 0XC601,
    0X06C0, 0X0780, 0XC741, 0X0500, 0XC5C1, 0XC481, 0X0440, 0XCC01, 0X0CC0,
    0X0D80, 0XCD41, 0X0F00, 0XCFC1, 0XCE81, 0X0E40, 0X0A00, 0XCAC1, 0XCB81,
    0X0B40, 0XC901, 0X09C0, 0X0880, 0XC841, 0XD801, 0X18C0, 0X1980, 0XD941,
    0X1B00, 0XDBC1, 0XDA81, 0X1A40, 0X1E00, 0XDEC1, 0XDF81, 0X1F40, 0XDD01,
    0X1DC0, 0X1C80, 0XDC41, 0X1400, 0XD4C1, 0XD581, 0X1540, 0XD701, 0X17C0,
    0X1680, 0XD641, 0XD201, 0X12C0, 0X1380, 0XD341, 0X1100, 0XD1C1, 0XD081,
    0X1040, 0XF001, 0X30C0, 0X3180, 0XF141, 0X3300, 0XF3C1, 0XF281, 0X3240,
    0X3600, 0XF6C1, 0XF781, 0X3740, 0XF501, 0X35C0, 0X3480, 0XF441, 0X3C00,
    0XFCC1, 0XFD81, 0X3D40, 0XFF01, 0X3FC0, 0X3E80, 0XFE41, 0XFA01, 0X3AC0,
    0X3B80, 0XFB41, 0X3900, 0XF9C1, 0XF881, 0X3840, 0X2800, 0XE8C1, 0XE981,
    0X2940, 0XEB01, 0X2BC0, 0X2A80, 0XEA41, 0XEE01, 0X2EC0, 0X2F80, 0XEF41,
    0X2D00, 0XEDC1, 0XEC81, 0X2C40, 0XE401, 0X24C0, 0X2580, 0XE541, 0X2700,
    0XE7C1, 0XE681, 0X2640, 0X2200, 0XE2C1, 0XE381, 0X2340, 0XE101, 0X21C0,
    0X2080, 0XE041, 0XA001, 0X60C0, 0X6180, 0XA141, 0X6300, 0XA3C1, 0XA281,
    0X6240, 0X6600, 0XA6C1, 0XA781, 0X6740, 0XA501, 0X65C0, 0X6480, 0XA441,
    0X6C00, 0XACC1, 0XAD81, 0X6D40, 0XAF01, 0X6FC0, 0X6E80, 0XAE41, 0XAA01,
    0X6AC0, 0X6B80, 0XAB41, 0X6900, 0XA9C1, 0XA881, 0X6840, 0X7800, 0XB8C1,
    0XB981, 0X7940, 0XBB01, 0X7BC0, 0X7A80, 0XBA41, 0XBE01, 0X7EC0, 0X7F80,
    0XBF41, 0X7D00, 0XBDC1, 0XBC81, 0X7C40, 0XB401, 0X74C0, 0X7580, 0XB541,
    0X7700, 0XB7C1, 0XB681, 0X7640, 0X7200, 0XB2C1, 0XB381, 0X7340, 0XB101,
    0X71C0, 0X7080, 0XB041, 0X5000, 0X90C1, 0X9181, 0X5140, 0X9301, 0X53C0,
    0X5280, 0X9241, 0X9601, 0X56C0, 0X5780, 0X9741, 0X5500, 0X95C1, 0X9481,
    0X5440, 0X9C01, 0X5CC0, 0X5D80, 0X9D41, 0X5F00, 0X9FC1, 0X9E81, 0X5E40,
    0X5A00, 0X9AC1, 0X9B81, 0X5B40, 0X9901, 0X59C0, 0X5880, 0X9841, 0X8801,
    0X48C0, 0X4980, 0X8941, 0X4B00, 0X8BC1, 0X8A81, 0X4A40, 0X4E00, 0X8EC1,
    0X8F81, 0X4F40, 0X8D01, 0X4DC0, 0X4C80, 0X8C41, 0X4400, 0X84C1, 0X8581,
    0X4540, 0X8701, 0X47C0, 0X4680, 0X8641, 0X8201, 0X42C0, 0X4380, 0X8341,
    0X4100, 0X81C1, 0X8081, 0X4040};

enum ModbusRegNum : uint16_t {
  Model = 30000,
  Firmware_Master = 30016,
  Firmware_Slave = 30017,
  Firmware_Manager = 30018,
  Firmware_Battery_Master = 30019,
  Firmware_Battery_Slave1 = 30020,
  Firmware_Battery_Slave2 = 30021,
  Firmware_Battery_Slave3 = 30022,
  Firmware_Battery_Slave4 = 30023,
  Firmware_Battery_Slave5 = 30024,
  Firmware_Battery_Slave6 = 30025,
  Firmware_Battery_Slave7 = 30026,
  Firmware_Battery_Slave8 = 30027,
  Modbus_Protocol_Version = 30100,
  PV1_Voltage = 31000,
  PV1_Current = 31001,
  PV1_Power = 31002,
  PV2_Voltage = 31003,
  PV2_Current = 31004,
  PV2_Power = 31005,
  Grid_Voltage_R = 31006,
  Grid_Voltage_S = 31007,
  Grid_Voltage_T = 31008,
  Inv_Current_R = 31009,
  Inv_Current_S = 31010,
  Inv_Current_T = 31011,
  Inv_Power_R = 31012,
  Inv_Power_S = 31013,
  Inv_Power_T = 31014,
  Grid_Frequency = 31015,
  Eps_Voltage_R = 31016,
  Eps_Voltage_S = 31017,
  Eps_Voltage_T = 31018,
  Eps_Current_R = 31019,
  Eps_Current_S = 31020,
  Eps_Current_T = 31021,
  Eps_Power_R = 31022,
  Eps_Power_S = 31023,
  Eps_Power_T = 31024,
  Eps_Frequency = 31025,
  Meter_Power_R = 31026,
  Meter_Power_S = 31027,
  Meter_Power_T = 31028,
  Meter_Load_R = 31029,
  Meter_Load_S = 31030,
  Meter_Load_T = 31031,
  Inverter_Temperature = 31032,
  Internal_Temperature = 31033,
  Battery_Voltage = 31034,
  Battery_Current = 31035,
  Battery_Power = 31036,
  Battery_Temperature = 31037,
  SoC = 31038,
  Maximum_Charge_Current = 31039,
  Maximum_Discharge_Current = 31040,
  Inverter_State = 31041,
  BMS_Connect_State = 31042,
  Meter_Connect_State = 31043,
  Fault1 = 31044,
  Fault2 = 31045,
  Fault3 = 31046,
  Fault4 = 31047,
  Fault5 = 31048,
  Fault6 = 31049,
  Fault7 = 31050,
  Fault8 = 31051,
  Total_PV_Energy = 32000,
  Today_PV_Energy = 32002,
  Total_Charge_Energy = 32003,
  Today_Charge_Energy = 32005,
  Total_Discharge_Energy = 32006,
  Today_Discarge_Energy = 32008,
  Total_Feed_In_Energy = 32009,
  Today = 32011,
  Total_Consumption_Energy = 32012,
  Today_Consumption_Energy = 32014,
  Total_Output_Energy = 32015,
  Today_Output_Energy = 32017,
  Total_Input_Energy = 32018,
  Today_Input_Energy = 32020,
  Total_Load_Energy = 32021,
  Today_Load_Energy = 32023,
  Remote_Power_Control_Enable = 44000,
  Remote_Power_Control_Timeoout = 44001,
  Remote_Control_Active_Power_Command = 44002,
  Remote_Control_ReActive_Power_Command = 44004,
};

struct ModbusProtocolReadRequest {
  static constexpr uint8_t slave_address_ = {0xF7};
  static constexpr uint8_t function_code_ = {0x03};
  ModbusRegNum reg_addr_;
  uint16_t reg_number_;
};

struct ModbusProtocolReadResponse {
  uint8_t slave_address_;
  uint8_t function_code_;
  uint8_t nr_of_bytes_;
  uint16_t data_[10];
  uint16_t crc_;
};

#endif /* PROTOCOL_H_ */
