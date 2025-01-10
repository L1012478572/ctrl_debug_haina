#ifndef DOMAP_H
#define DOMAP_H

#include <QTableWidget>
#include <QModbusDataUnit>
#include "param_struct.h"

class DoMap
{
public:
    DoMap(QTableWidget *tableWidget);
    ~DoMap();

    uint16_t get_read_do_addr(); // 获取读取DO地址
    uint16_t get_read_do_num();  // 获取读取DO数量

    void readCurrentPage_Result(QModbusDataUnit::RegisterType table, int address, QVector<quint16> values); // 读取当前页结果

private:
    void initTableWidget();

    QTableWidget *tableWidget;
};

#endif // DOMAP_H