#ifndef OTHERMAP_H
#define OTHERMAP_H

#include <QTableWidget>
#include <QModbusDataUnit>
#include "param_struct.h"

class OtherMap
{
public:
    OtherMap(QTableWidget *tableWidget);
    ~OtherMap();

    uint16_t get_read_ai_addr();                  // 获取读取AI地址
    uint16_t get_read_ai_num();                   // 获取读取AI数量
    uint16_t get_read_encoder_addr();             // 获取读取编码器地址
    uint16_t get_read_encoder_num();              // 获取读取编码器数量
    uint16_t get_read_modbusRtuSlaveParam_addr(); // 获取读取Modbus RTU Slave 参数地址
    uint16_t get_read_modbusRtuSlaveParam_num();  // 获取读取Modbus RTU Slave 参数数量

    void readCurrentPageAi_Result(QModbusDataUnit::RegisterType table, int address, QVector<quint16> values);                  // 读取当前页结果
    void readCurrentPageEncoder_Result(QModbusDataUnit::RegisterType table, int address, QVector<quint16> values);             // 读取当前页结果
    void readCurrentPageModbusRtuSlaveParam_Result(QModbusDataUnit::RegisterType table, int address, QVector<quint16> values); // 读取当前页结果

private:
    void initTableWidget();

private:
    QTableWidget *tableWidget;
};

#endif // OTHERMAP_H