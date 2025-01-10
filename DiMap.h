#ifndef DIMAP_H
#define DIMAP_H

// #include <QMainWindow>
#include <QTableWidget>
#include <QModbusDataUnit>
#include "param_struct.h"

class DiMap
{
public:
    DiMap(QTableWidget *tableWidget);
    ~DiMap();

    uint16_t get_read_di_addr(); // 获取读取DI地址
    uint16_t get_read_di_num();  // 获取读取DI数量

    void readCurrentPage_Result(QModbusDataUnit::RegisterType table, int address, QVector<quint16> values); // 读取当前页结果

private:
    void initTableWidget();

private:
    QTableWidget *tableWidget;
};

#endif // DIMAP_H