#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QModbusRtuSerialMaster>
#include <QModbusDataUnit>
#include <QScopedPointer> // 使用智能指针

#include <QTimer>

#include "DiMap.h"
#include "DoMap.h"
#include "OtherMap.h"

#include "param_struct.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initTableWidget();

private slots:
    void pushButton_searchSerialPort_clicked();                                                         // 搜索串口
    void pushButton_openPort_clicked();                                                                 // 打开串口
    void readDI_TimerOut();                                                                             // 定时读取DI
    void readDI_Result(QModbusDataUnit::RegisterType table, int address, QVector<quint16> values);      // 读取DI结果
    void readDO_TimerOut();                                                                             // 定时读取DO
    void readDO_Result(QModbusDataUnit::RegisterType table, int address, QVector<quint16> values);      // 读取DO结果
    void readEncoder_TimerOut();                                                                        // 定时读取编码器
    void readEncoder_Result(QModbusDataUnit::RegisterType table, int address, QVector<quint16> values); // 读取编码器结果

    void on_pushButton_O_1_clicked();
    void on_pushButton_O_2_clicked();
    void on_pushButton_O_3_clicked();
    void on_pushButton_O_4_clicked();
    void on_pushButton_O_5_clicked();
    void on_pushButton_O_6_clicked();
    void on_pushButton_O_7_clicked();
    void on_pushButton_O_8_clicked();
    void on_pushButton_O_9_clicked();
    void on_pushButton_O_10_clicked();
    void on_pushButton_O_11_clicked();
    void on_pushButton_O_12_clicked();
    void on_pushButton_O_13_clicked();
    void on_pushButton_O_14_clicked();
    void on_pushButton_O_15_clicked();
    void on_pushButton_O_16_clicked();
    void on_pushButton_O_17_clicked();
    void on_pushButton_O_18_clicked();
    void on_pushButton_O_19_clicked();
    void on_pushButton_O_20_clicked();
    void on_pushButton_O_21_clicked();
    void on_pushButton_O_22_clicked();
    void on_pushButton_O_23_clicked();
    void on_pushButton_O_24_clicked();
    void on_pushButton_O_25_clicked();
    void on_pushButton_O_26_clicked();
    void on_pushButton_O_27_clicked();
    void on_pushButton_O_28_clicked();
    void on_pushButton_O_29_clicked();
    void on_pushButton_O_30_clicked();
    // lineEdit_encoder1 值改变后按回车键发送
    void on_lineEdit_encoder1_returnPressed();
    // lineEdit_encoder2 值改变后按回车键发送
    void on_lineEdit_encoder2_returnPressed();
    // lineEdit_encoder3 值改变后按回车键发送
    void on_lineEdit_encoder3_returnPressed();
    // 保存参数按钮
    void on_pushButton_save_clicked();
    // 重启按钮
    void on_pushButton_reboot_clicked();
    // 恢复出厂设置按钮
    void on_pushButton_restore_clicked();
    // 定时读取系统状态
    void readSystemStatus_TimerOut();

    void on_pushButton_readCurrentPage_clicked();

    void on_pushButton_clicked();

    void on_pushButton_setone_clicked();

private:
    void writeDO(int address, bool value);   // 写DO
    void readSystemStatus(uint16_t address); // 读取系统状态

    // 应答回调函数
    void readSystemStatus_Result(int address, uint16_t values); // 读取系统状态结果
    void readHDRegisters(int serverAddress, int startAddress, int numberOfRegisters);
    void writeHDRegisters(int serverAddress, QModbusDataUnit data);

private:
    Ui::MainWindow *ui;
    // QScopedPointer<QModbusRtuSerialMaster> modbusDevice;
    QModbusRtuSerialMaster *modbusDevice;

    QTimer ReadDI_Timer;           // 定时读取DI
    QTimer ReadDO_Timer;           // 定时读取DO
    QTimer ReadEncoder_Timer;      // 定时读取编码器
    QTimer ReadSystemStatus_Timer; // 定时读取系统状态

    int readSystemStatusCount = 0; // 读取系统状态计数

    DiMap *diMap;       // DI 映射
    DoMap *doMap;       // DO 映射
    OtherMap *otherMap; // 其他映射
};

#endif // MAINWINDOW_H
