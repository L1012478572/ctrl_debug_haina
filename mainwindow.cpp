#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initTableWidget();
    modbusDevice = new QModbusRtuSerialMaster(this);

    connect(ui->pushButton_searchSerialPort, &QPushButton::clicked, this, &MainWindow::pushButton_searchSerialPort_clicked);
    connect(ui->pushButton_openPort, &QPushButton::clicked, this, &MainWindow::pushButton_openPort_clicked);

    connect(&ReadDI_Timer, &QTimer::timeout, this, &MainWindow::readDI_TimerOut);
    ReadDI_Timer.start(1000); // 1s
    connect(&ReadDO_Timer, &QTimer::timeout, this, &MainWindow::readDO_TimerOut);
    ReadDO_Timer.start(3333); // 1s
    connect(&ReadEncoder_Timer, &QTimer::timeout, this, &MainWindow::readEncoder_TimerOut);
    ReadEncoder_Timer.start(1377); // 1s
    connect(&ReadSystemStatus_Timer, &QTimer::timeout, this, &MainWindow::readSystemStatus_TimerOut);
    ReadSystemStatus_Timer.start(1000); // 1s
    connect(modbusDevice, &QModbusClient::stateChanged, [this](QModbusDevice::State state)
            {
        if (state == QModbusDevice::ConnectedState)
        {
            qDebug() << "Modbus connected";
        }
        else if (state == QModbusDevice::ConnectingState)
        {
            qDebug() << "Modbus connecting";
        }
        else if (state == QModbusDevice::UnconnectedState)
        {
            qDebug() << "Modbus unconnected";
        } });
    connect(modbusDevice, &QModbusClient::errorOccurred, [this](QModbusDevice::Error error)
            { qDebug() << "Modbus error: " << modbusDevice->errorString(); });

    ui->comboBox_bound->addItem("1200");
    ui->comboBox_bound->addItem("2400");
    ui->comboBox_bound->addItem("4800");
    ui->comboBox_bound->addItem("9600");
    ui->comboBox_bound->addItem("19200");
    ui->comboBox_bound->addItem("38400");
    ui->comboBox_bound->addItem("57600");
    ui->comboBox_bound->addItem("115200");
    ui->comboBox_bound->addItem("128000");
    ui->comboBox_bound->addItem("256000");
    ui->comboBox_bound->setCurrentIndex(7);
    ui->comboBox_serialData->addItem("8");
    ui->comboBox_serialData->addItem("7");
    ui->comboBox_serialData->addItem("6");
    ui->comboBox_serialData->setCurrentIndex(0);
    ui->comboBox_serialStop->addItem("1");
    ui->comboBox_serialStop->addItem("2");
    ui->comboBox_serialStop->setCurrentIndex(0);
    ui->comboBox_serialParity->addItem("无");
    ui->comboBox_serialParity->addItem("奇");
    ui->comboBox_serialParity->addItem("偶");
    ui->comboBox_serialParity->setCurrentIndex(0);

    connect(ui->pushButton_O_1, &QPushButton::clicked, this, &MainWindow::on_pushButton_O_1_clicked);
    connect(ui->pushButton_O_2, &QPushButton::clicked, this, &MainWindow::on_pushButton_O_2_clicked);
    connect(ui->pushButton_O_3, &QPushButton::clicked, this, &MainWindow::on_pushButton_O_3_clicked);
    connect(ui->pushButton_O_4, &QPushButton::clicked, this, &MainWindow::on_pushButton_O_4_clicked);
    connect(ui->pushButton_O_5, &QPushButton::clicked, this, &MainWindow::on_pushButton_O_5_clicked);
    connect(ui->pushButton_O_6, &QPushButton::clicked, this, &MainWindow::on_pushButton_O_6_clicked);
    connect(ui->pushButton_O_7, &QPushButton::clicked, this, &MainWindow::on_pushButton_O_7_clicked);
    connect(ui->pushButton_O_8, &QPushButton::clicked, this, &MainWindow::on_pushButton_O_8_clicked);
    connect(ui->pushButton_O_9, &QPushButton::clicked, this, &MainWindow::on_pushButton_O_9_clicked);
    connect(ui->pushButton_O_10, &QPushButton::clicked, this, &MainWindow::on_pushButton_O_10_clicked);
    connect(ui->pushButton_O_11, &QPushButton::clicked, this, &MainWindow::on_pushButton_O_11_clicked);
    connect(ui->pushButton_O_12, &QPushButton::clicked, this, &MainWindow::on_pushButton_O_12_clicked);
    connect(ui->pushButton_O_13, &QPushButton::clicked, this, &MainWindow::on_pushButton_O_13_clicked);
    connect(ui->pushButton_O_14, &QPushButton::clicked, this, &MainWindow::on_pushButton_O_14_clicked);
    connect(ui->pushButton_O_15, &QPushButton::clicked, this, &MainWindow::on_pushButton_O_15_clicked);
    connect(ui->pushButton_O_16, &QPushButton::clicked, this, &MainWindow::on_pushButton_O_16_clicked);
    connect(ui->pushButton_O_17, &QPushButton::clicked, this, &MainWindow::on_pushButton_O_17_clicked);
    connect(ui->pushButton_O_18, &QPushButton::clicked, this, &MainWindow::on_pushButton_O_18_clicked);
    connect(ui->pushButton_O_19, &QPushButton::clicked, this, &MainWindow::on_pushButton_O_19_clicked);
    connect(ui->pushButton_O_20, &QPushButton::clicked, this, &MainWindow::on_pushButton_O_20_clicked);
    connect(ui->pushButton_O_21, &QPushButton::clicked, this, &MainWindow::on_pushButton_O_21_clicked);
    connect(ui->pushButton_O_22, &QPushButton::clicked, this, &MainWindow::on_pushButton_O_22_clicked);
    connect(ui->pushButton_O_23, &QPushButton::clicked, this, &MainWindow::on_pushButton_O_23_clicked);
    connect(ui->pushButton_O_24, &QPushButton::clicked, this, &MainWindow::on_pushButton_O_24_clicked);
    connect(ui->pushButton_O_25, &QPushButton::clicked, this, &MainWindow::on_pushButton_O_25_clicked);
    connect(ui->pushButton_O_26, &QPushButton::clicked, this, &MainWindow::on_pushButton_O_26_clicked);
    connect(ui->pushButton_O_27, &QPushButton::clicked, this, &MainWindow::on_pushButton_O_27_clicked);
    connect(ui->pushButton_O_28, &QPushButton::clicked, this, &MainWindow::on_pushButton_O_28_clicked);
    connect(ui->pushButton_O_29, &QPushButton::clicked, this, &MainWindow::on_pushButton_O_29_clicked);
    connect(ui->pushButton_O_30, &QPushButton::clicked, this, &MainWindow::on_pushButton_O_30_clicked);
    connect(ui->lineEdit_encoder1, &QLineEdit::returnPressed, this, &MainWindow::on_lineEdit_encoder1_returnPressed); // lineEdit_encoder1 值改变后按回车键发送
    connect(ui->lineEdit_encoder2, &QLineEdit::returnPressed, this, &MainWindow::on_lineEdit_encoder2_returnPressed);
    connect(ui->lineEdit_encoder3, &QLineEdit::returnPressed, this, &MainWindow::on_lineEdit_encoder3_returnPressed);
    connect(ui->pushButton_save, &QPushButton::clicked, this, &MainWindow::on_pushButton_save_clicked);
    connect(ui->pushButton_reboot, &QPushButton::clicked, this, &MainWindow::on_pushButton_reboot_clicked);
    connect(ui->pushButton_restore, &QPushButton::clicked, this, &MainWindow::on_pushButton_restore_clicked);

    diMap = new DiMap(ui->tableWidget_DI_Map);
    doMap = new DoMap(ui->tableWidget_DO_Map);
    otherMap = new OtherMap(ui->tableWidget_Other_Map);
}

MainWindow::~MainWindow()
{
    delete modbusDevice;
    delete diMap;
    delete ui;
}

/**
 * @brief MainWindow::initTableWidget
 *
 */
void MainWindow::initTableWidget()
{
    ui->tableWidget_projectPar->clear();

    // 设置2列 26行
    ui->tableWidget_projectPar->setColumnCount(2);
    ui->tableWidget_projectPar->setRowCount(31);
    // 第一列名称  参数名
    QStringList header;
    header << "参数名" << "参数值";
    ui->tableWidget_projectPar->setHorizontalHeaderLabels(header);
    // 依次向表格中添加元素
    // 第一行 第一列 QLabel 料位延时   第二列 QLineEdit
    QTableWidgetItem *item = new QTableWidgetItem(QString("料位延时:"));
    ui->tableWidget_projectPar->setItem(0, 0, item);
    QLineEdit *lineEdit = new QLineEdit();
    lineEdit->setPlaceholderText("0");
    ui->tableWidget_projectPar->setCellWidget(0, 1, lineEdit);
    // 第二行 第一列 QLabel 齿轮比  第二列 QLineEdit
    item = new QTableWidgetItem(QString("齿轮比:"));
    ui->tableWidget_projectPar->setItem(1, 0, item);
    lineEdit = new QLineEdit();
    lineEdit->setPlaceholderText("0");
    ui->tableWidget_projectPar->setCellWidget(1, 1, lineEdit);
    // 第三行 第一列 QLabel 包箱总长度 第二列 QLineEdit
    item = new QTableWidgetItem(QString("包箱总长度:"));
    ui->tableWidget_projectPar->setItem(2, 0, item);
    lineEdit = new QLineEdit();
    lineEdit->setPlaceholderText("0");
    ui->tableWidget_projectPar->setCellWidget(2, 1, lineEdit);
    // 第四行 第一列 QLabel 打包长度 第二列 QLineEdit
    item = new QTableWidgetItem(QString("打包长度:"));
    ui->tableWidget_projectPar->setItem(3, 0, item);
    lineEdit = new QLineEdit();
    lineEdit->setPlaceholderText("0");
    ui->tableWidget_projectPar->setCellWidget(3, 1, lineEdit);
    // 第五行 第一列 QLabel 后退低压位置设定 第二列 QLineEdit
    item = new QTableWidgetItem(QString("后退低压位置设定:"));
    ui->tableWidget_projectPar->setItem(4, 0, item);
    lineEdit = new QLineEdit();
    lineEdit->setPlaceholderText("0");
    ui->tableWidget_projectPar->setCellWidget(4, 1, lineEdit);
    // 第六行 第一列 QLabel 出包长度设定 第二列 QLineEdit
    item = new QTableWidgetItem(QString("出包长度设定:"));
    ui->tableWidget_projectPar->setItem(5, 0, item);
    lineEdit = new QLineEdit();
    lineEdit->setPlaceholderText("0");
    ui->tableWidget_projectPar->setCellWidget(5, 1, lineEdit);
    // 第七行 第一列 QLabel 后退关门长度 第二列 QLineEdit
    item = new QTableWidgetItem(QString("后退关门长度:"));
    ui->tableWidget_projectPar->setItem(6, 0, item);
    lineEdit = new QLineEdit();
    lineEdit->setPlaceholderText("0");
    ui->tableWidget_projectPar->setCellWidget(6, 1, lineEdit);
    // 第八行 第一列 QLabel 前进行走长度 第二列 QLineEdit
    item = new QTableWidgetItem(QString("前进行走长度:"));
    ui->tableWidget_projectPar->setItem(7, 0, item);
    lineEdit = new QLineEdit();
    lineEdit->setPlaceholderText("0");
    ui->tableWidget_projectPar->setCellWidget(7, 1, lineEdit);
    // 第九行 第一列 QLabel 温度上限 第二列 QLineEdit
    item = new QTableWidgetItem(QString("温度上限:"));
    ui->tableWidget_projectPar->setItem(8, 0, item);
    lineEdit = new QLineEdit();
    lineEdit->setPlaceholderText("0");
    ui->tableWidget_projectPar->setCellWidget(8, 1, lineEdit);
    // 第十行 第一列 QLabel 温度下限 第二列 QLineEdit
    item = new QTableWidgetItem(QString("温度下限:"));
    ui->tableWidget_projectPar->setItem(9, 0, item);
    lineEdit = new QLineEdit();
    lineEdit->setPlaceholderText("0");
    ui->tableWidget_projectPar->setCellWidget(9, 1, lineEdit);
    // 第十一行 第一列 QLabel 前进压力保护计时 第二列 QLineEdit
    item = new QTableWidgetItem(QString("前进压力保护计时:"));
    ui->tableWidget_projectPar->setItem(10, 0, item);
    lineEdit = new QLineEdit();
    lineEdit->setPlaceholderText("0");
    ui->tableWidget_projectPar->setCellWidget(10, 1, lineEdit);
    // 第十二行 第一列 QLabel 料满延时 第二列 QLineEdit
    item = new QTableWidgetItem(QString("料满延时:"));
    ui->tableWidget_projectPar->setItem(11, 0, item);
    lineEdit = new QLineEdit();
    lineEdit->setPlaceholderText("0");
    ui->tableWidget_projectPar->setCellWidget(11, 1, lineEdit);
    // 第十三行 第一列 QLabel 运行时间 秒
    item = new QTableWidgetItem(QString("运行时间(秒):"));
    ui->tableWidget_projectPar->setItem(12, 0, item);
    lineEdit = new QLineEdit();
    lineEdit->setPlaceholderText("0");
    ui->tableWidget_projectPar->setCellWidget(12, 1, lineEdit);
    // 第十四行 第一列 QLabel 运行时间 分 第二列 QLineEdit
    item = new QTableWidgetItem(QString("运行时间(分):"));
    ui->tableWidget_projectPar->setItem(13, 0, item);
    lineEdit = new QLineEdit();
    lineEdit->setPlaceholderText("0");
    ui->tableWidget_projectPar->setCellWidget(13, 1, lineEdit);
    // 第十五行 第一列 QLabel 运行时间 时 第二列 QLineEdit
    item = new QTableWidgetItem(QString("运行时间(时):"));
    ui->tableWidget_projectPar->setItem(14, 0, item);
    lineEdit = new QLineEdit();
    lineEdit->setPlaceholderText("0");
    ui->tableWidget_projectPar->setCellWidget(14, 1, lineEdit);
    // 第十六行 第一列 QLabel 运行时间计数 h 第二列 QLineEdit
    item = new QTableWidgetItem(QString("运行时间计数(h):"));
    ui->tableWidget_projectPar->setItem(15, 0, item);
    lineEdit = new QLineEdit();
    lineEdit->setPlaceholderText("0");
    ui->tableWidget_projectPar->setCellWidget(15, 1, lineEdit);
    // 第十七行 第一列 QLabel 激活时间 h 第二列 QLineEdit
    item = new QTableWidgetItem(QString("激活时间(h):"));
    ui->tableWidget_projectPar->setItem(16, 0, item);
    lineEdit = new QLineEdit();
    lineEdit->setPlaceholderText("0");
    ui->tableWidget_projectPar->setCellWidget(16, 1, lineEdit);
    // 第十八行 第一列 QLabel 剩余时间 h 第二列 QLineEdit
    item = new QTableWidgetItem(QString("剩余时间(h):"));
    ui->tableWidget_projectPar->setItem(17, 0, item);
    lineEdit = new QLineEdit();
    lineEdit->setPlaceholderText("0");
    ui->tableWidget_projectPar->setCellWidget(17, 1, lineEdit);
    // 第十九行 第一列 QLabel 快慢切换压力  float 第二列 QLineEdit
    item = new QTableWidgetItem(QString("快慢切换压力:"));
    ui->tableWidget_projectPar->setItem(18, 0, item);
    lineEdit = new QLineEdit();
    lineEdit->setPlaceholderText("0");
    ui->tableWidget_projectPar->setCellWidget(18, 1, lineEdit);
    // 第二十行 第一列 QLabel 第一次预压次数 第二列 QLineEdit
    item = new QTableWidgetItem(QString("第一次预压次数:"));
    ui->tableWidget_projectPar->setItem(19, 0, item);
    lineEdit = new QLineEdit();
    lineEdit->setPlaceholderText("0");
    ui->tableWidget_projectPar->setCellWidget(19, 1, lineEdit);
    // 第二十一行 第一列 QLabel 第二次预压次数 第二列 QLineEdit
    item = new QTableWidgetItem(QString("第二次预压次数:"));
    ui->tableWidget_projectPar->setItem(20, 0, item);
    lineEdit = new QLineEdit();
    lineEdit->setPlaceholderText("0");
    ui->tableWidget_projectPar->setCellWidget(20, 1, lineEdit);
    // 第二十二行 第一列 QLabel 主缸前进压力设定 float 第二列 QLineEdit
    item = new QTableWidgetItem(QString("主缸前进压力设定:"));
    ui->tableWidget_projectPar->setItem(21, 0, item);
    lineEdit = new QLineEdit();
    lineEdit->setPlaceholderText("0");
    ui->tableWidget_projectPar->setCellWidget(21, 1, lineEdit);
    // 第二十三行 第一列 QLabel 最高保护压力停止 float 第二列 QLineEdit
    item = new QTableWidgetItem(QString("最高保护压力停止:"));
    ui->tableWidget_projectPar->setItem(22, 0, item);
    lineEdit = new QLineEdit();
    lineEdit->setPlaceholderText("0");
    ui->tableWidget_projectPar->setCellWidget(22, 1, lineEdit);
    // 第二十四行 第一列 QLabel 主缸后退压力保护 float 第二列 QLineEdit
    item = new QTableWidgetItem(QString("主缸后退压力保护:"));
    ui->tableWidget_projectPar->setItem(23, 0, item);
    lineEdit = new QLineEdit();
    lineEdit->setPlaceholderText("0");
    ui->tableWidget_projectPar->setCellWidget(23, 1, lineEdit);
    // 第二十五行 第一列 QLabel 泄压延时时间 第二列 QLineEdit
    item = new QTableWidgetItem(QString("泄压延时时间:"));
    ui->tableWidget_projectPar->setItem(24, 0, item);
    lineEdit = new QLineEdit();
    lineEdit->setPlaceholderText("0");
    ui->tableWidget_projectPar->setCellWidget(24, 1, lineEdit);
    // 第二十六行 第一列 QLabel 主缸后退计时 第二列 QLineEdit
    item = new QTableWidgetItem(QString("主缸后退计时:"));
    ui->tableWidget_projectPar->setItem(25, 0, item);
    lineEdit = new QLineEdit();
    lineEdit->setPlaceholderText("0");
    ui->tableWidget_projectPar->setCellWidget(25, 1, lineEdit);
    // 第二十七行 第一列 QLabel 预压行走长度设定 第二列 QLineEdit
    item = new QTableWidgetItem(QString("预压行走长度设定:"));
    ui->tableWidget_projectPar->setItem(26, 0, item);
    lineEdit = new QLineEdit();
    lineEdit->setPlaceholderText("0");
    ui->tableWidget_projectPar->setCellWidget(26, 1, lineEdit);
    // 第二十八行 第一列 QLabel 第一次预压次数设定 第二列 QLineEdit
    item = new QTableWidgetItem(QString("第一次预压次数设定:"));
    ui->tableWidget_projectPar->setItem(27, 0, item);
    lineEdit = new QLineEdit();
    lineEdit->setPlaceholderText("0");
    ui->tableWidget_projectPar->setCellWidget(27, 1, lineEdit);
    // 第二十九行 第一列 QLabel 第二次预压次数设定 第二列 QLineEdit
    item = new QTableWidgetItem(QString("第二次预压次数设定:"));
    ui->tableWidget_projectPar->setItem(28, 0, item);
    lineEdit = new QLineEdit();
    lineEdit->setPlaceholderText("0");
    ui->tableWidget_projectPar->setCellWidget(28, 1, lineEdit);
    // 第三十行 第一列 QLabel 第三次预压次数设定 第二列 QLineEdit
    item = new QTableWidgetItem(QString("第三次预压次数设定:"));
    ui->tableWidget_projectPar->setItem(29, 0, item);
    lineEdit = new QLineEdit();
    lineEdit->setPlaceholderText("0");
    ui->tableWidget_projectPar->setCellWidget(29, 1, lineEdit);
}

/**
 * @brief MainWindow::pushButton_searchSerialPort_clicked
 * 这个函数是在mainwindow.ui中的pushButton_searchSerialPort按钮被点击时触发的
 */
void MainWindow::pushButton_searchSerialPort_clicked()
{
    ui->comboBox_serialName->clear();
    QList<QSerialPortInfo> Info = QSerialPortInfo::availablePorts();
    QStringList InfoString;
    for (int i = 0; i < Info.size(); i++)
    {
        InfoString.append(Info.at(i).portName());
    }
    ui->comboBox_serialName->addItems(InfoString);
}

/**
 * @brief MainWindow::pushButton_openPort_clicked
 * 这个函数是在mainwindow.ui中的pushButton_openPort按钮被点击时触发的
 */
void MainWindow::pushButton_openPort_clicked()
{
    if (ui->pushButton_openPort->text() == "打开串口")
    {
        // serial->Open_port(ui->comboBox_serialName->currentText(),
        //                   ui->comboBox_bound->currentText().toInt(),
        //                   ui->comboBox_serialData->currentIndex(),
        //                   ui->comboBox_serialStop->currentIndex(),
        //                   ui->comboBox_serialParity->currentIndex());
        ui->pushButton_openPort->setText("关闭串口");
        //        modbusDevice->setConnectionParameter(QModbusDevice::SerialParityParameter, ui->comboBox_serialParity->currentText().toInt());   // 校验位
        if (!modbusDevice)
        {
            qCritical() << "Failed to create Modbus device";
            return;
        }

        // Configure Modbus RTU device
        modbusDevice->setConnectionParameter(QModbusDevice::SerialPortNameParameter, ui->comboBox_serialName->currentText());
        modbusDevice->setConnectionParameter(QModbusDevice::SerialBaudRateParameter, QSerialPort::Baud19200);
        modbusDevice->setConnectionParameter(QModbusDevice::SerialDataBitsParameter, QSerialPort::Data8);
        modbusDevice->setConnectionParameter(QModbusDevice::SerialStopBitsParameter, QSerialPort::OneStop);
        modbusDevice->setConnectionParameter(QModbusDevice::SerialParityParameter, QSerialPort::NoParity);

        modbusDevice->setTimeout(500);       // 超时设置为 5000 毫秒
        modbusDevice->setNumberOfRetries(2); // 重试 5 次

        // 捕获状态变化
        connect(modbusDevice, &QModbusDevice::stateChanged, this, [](QModbusDevice::State state)
                { qDebug() << "Modbus device state changed to:" << state; });

        connect(modbusDevice, &QModbusDevice::errorOccurred, this, [](QModbusDevice::Error error)
                { qCritical() << "Modbus device error occurred:" << error; });

        if (!modbusDevice->connectDevice())
        {
            qCritical() << "Failed to connect to Modbus device:" << modbusDevice->errorString();
            return;
        }

        qDebug() << "Modbus device connected successfully!"; // 连接设备
    }
    else
    {
        // serial->ClosePort();
        ui->pushButton_openPort->setText("打开串口");
        modbusDevice->disconnectDevice(); // 断开连接
    }
}

/**
 * @brief MainWindow::readDI_TimerOut
 * 这个函数是在mainwindow.ui中的pushButton_readDI按钮被点击时触发的
 */
void MainWindow::readDI_TimerOut()
{
    ReadDI_Timer.stop();
    ReadDI_Timer.start(2333); // 1s
    if (ui->tabWidget->currentIndex() != 0)
    {
        return;
    }
    if (!modbusDevice)
    {
        return;
    }
    QModbusDevice::State connectedState = modbusDevice->state();
    if (connectedState != QModbusDevice::ConnectedState)
    {
        return;
    }
    // 读离散输入 0-29
    // QModbusDataUnit readDI = QModbusDataUnit(QModbusDataUnit::DiscreteInputs, 0, 30);
    QModbusDataUnit readUnit(QModbusDataUnit::DiscreteInputs, 0, 30);
    if (auto *reply = modbusDevice->sendReadRequest(readUnit, 1))
    {
        if (!reply->isFinished())
        {
            connect(reply, &QModbusReply::finished, this, [this, reply]()
                    {
                    if (reply->error() == QModbusDevice::NoError)
                    {
                        const QModbusDataUnit result = reply->result();
                        qDebug() << "Read successful! Data:";
                        readDI_Result(result.registerType(), result.startAddress(), result.values()); // 读取DI结果处理
                    }
                    else
                    {
                        qDebug() << "Read error:" << reply->errorString();
                    }
                    reply->deleteLater(); });
        }
        else
        {
            qDebug() << "Reply is already finished!";
            reply->deleteLater();
        }
    }
    else
    {
        qDebug() << "Read DI error: " << modbusDevice->errorString();
    }
}

/**
 * @brief MainWindow::readDO_TimerOut
 * 这个函数是在mainwindow.ui中的pushButton_readDO按钮被点击时触发的
 */
void MainWindow::readDO_TimerOut()
{
    ReadDO_Timer.stop();
    // ReadDO_Timer.start(2555); // 1s
    if (ui->tabWidget->currentIndex() != 0)
    {
        return;
    }
    if (!modbusDevice)
    {
        return;
    }
    if (modbusDevice->state() != QModbusDevice::ConnectedState)
    {
        return;
    }
    // 读线圈 0-29
    QModbusDataUnit readUnit(QModbusDataUnit::Coils, 0, 30);
    if (auto *reply = modbusDevice->sendReadRequest(readUnit, 1))
    {
        if (!reply->isFinished())
        {
            connect(reply, &QModbusReply::finished, this, [this, reply]()
                    {
                    if (reply->error() == QModbusDevice::NoError)
                    {
                        const QModbusDataUnit result = reply->result();
                        qDebug() << "Read successful! Data:";
                        readDO_Result(result.registerType(), result.startAddress(), result.values()); // 读取DI结果处理
                    }
                    else
                    {
                        qDebug() << "Read error:" << reply->errorString();
                    }
                    reply->deleteLater(); });
        }
        else
        {
            qDebug() << "Reply is already finished!";
            reply->deleteLater();
        }
    }
    // if (auto *reply = modbusDevice->sendReadRequest(readDO, 1))
    // {
    //     if (!reply->isFinished())
    //     {
    //         connect(reply, &QModbusReply::finished, this, [this, reply]()
    //                 {
    //             if (reply->error() == QModbusDevice::NoError)
    //             {
    //                 const QModbusDataUnit unit = reply->result();
    //                 readDO_Result(unit.registerType(), unit.startAddress(), unit.values()); // 读取DO结果处理
    //             }
    //             reply->deleteLater(); });
    //     }
    //     else
    //     {
    //         delete reply;
    //     }
    // }
    else
    {
        qDebug() << "Read DO error: " << modbusDevice->errorString();
    }
}

/**
 * @brief MainWindow::readEncoder_TimerOut
 * 这个函数是在mainwindow.ui中的pushButton_readEncoder按钮被点击时触发的
 */
void MainWindow::readEncoder_TimerOut()
{
    ReadEncoder_Timer.stop();
    // ReadEncoder_Timer.start(5333); // 1s
    if (ui->tabWidget->currentIndex() != 0)
    {
        return;
    }
    if (!modbusDevice)
    {
        return;
    }
    if (modbusDevice->state() != QModbusDevice::ConnectedState)
    {
        return;
    }
    // 读保持寄存器 0-29
    // 初始化Modbus设备时增加超时设置
    modbusDevice->setTimeout(2000);
    modbusDevice->setNumberOfRetries(3);

    // 发送读取请求
    // QModbusDataUnit readEncoder = QModbusDataUnit(QModbusDataUnit::HoldingRegisters, MODBUS_RTU_REG_ENCODER1_COUNT, 6);
    QModbusDataUnit readUnit(QModbusDataUnit::HoldingRegisters, MODBUS_RTU_REG_ENCODER1_COUNT, 6);
    if (auto *reply = modbusDevice->sendReadRequest(readUnit, 1))
    {
        if (!reply->isFinished())
        {
            connect(reply, &QModbusReply::finished, this, [this, reply]()
                    {
                    if (reply->error() == QModbusDevice::NoError)
                    {
                        const QModbusDataUnit result = reply->result();
                        qDebug() << "Read successful! Data:";
                        for (uint i = 0; i < result.valueCount(); ++i)
                        {
                            qDebug() << "Register" << result.startAddress() + i << ":" << result.value(i);
                        }
                        readEncoder_Result(result.registerType(), result.startAddress(), result.values());
                    }
                    else
                    {
                        qDebug() << "Read error:" << reply->errorString();
                    }
                    reply->deleteLater(); });
        }
        else
        {
            qDebug() << "Reply is already finished!";
            reply->deleteLater();
        }
    }
    else
    {
        qWarning() << "Failed to send read request:" << modbusDevice->errorString();
    }
}

/**
 * @brief MainWindow::readDI_Result
 * @param table     读取的表
 * @param address   读取的地址
 * @param values    读取的值
 */
void MainWindow::readDI_Result(QModbusDataUnit::RegisterType table, int address, QVector<quint16> values)
{
    if (table == QModbusDataUnit::DiscreteInputs)
    {
        for (int i = 0; i < values.size(); i++)
        {
            //            qDebug() << "DI" << i << ":" << values.at(i);
            switch (i)
            {
            case 0:
                // 根据值 设置 label 的颜色
                ui->label_IN_1->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 1:
                ui->label_IN_2->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 2:
                ui->label_IN_3->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 3:
                ui->label_IN_4->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 4:
                ui->label_IN_5->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 5:
                ui->label_IN_6->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 6:
                ui->label_IN_7->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 7:
                ui->label_IN_8->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 8:
                ui->label_IN_9->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 9:
                ui->label_IN_10->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 10:
                ui->label_IN_11->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 11:
                ui->label_IN_12->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 12:
                ui->label_IN_13->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 13:
                ui->label_IN_14->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 14:
                ui->label_IN_15->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 15:
                ui->label_IN_16->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 16:
                ui->label_IN_17->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 17:
                ui->label_IN_18->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 18:
                ui->label_IN_19->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 19:
                ui->label_IN_20->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 20:
                ui->label_IN_21->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 21:
                ui->label_IN_22->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 22:
                ui->label_IN_23->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 23:
                ui->label_IN_24->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 24:
                ui->label_IN_25->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 25:
                ui->label_IN_26->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 26:
                ui->label_IN_27->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 27:
                ui->label_IN_28->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 28:
                ui->label_IN_29->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 29:
                ui->label_IN_30->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            }
        }
    }
}

/**
 * @brief MainWindow::readDO_Result
 * @param table     读取的表
 * @param address   读取的地址
 * @param values    读取的值
 */
void MainWindow::readDO_Result(QModbusDataUnit::RegisterType table, int address, QVector<quint16> values)
{
    if (table == QModbusDataUnit::Coils)
    {
        for (int i = 0; i < values.size(); i++)
        {
            //            qDebug() << "DO" << i << ":" << values.at(i);
            switch (i)
            {
            case 0:
                ui->pushButton_O_1->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 1:
                ui->pushButton_O_2->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 2:
                ui->pushButton_O_3->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 3:
                ui->pushButton_O_4->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 4:
                ui->pushButton_O_5->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 5:
                ui->pushButton_O_6->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 6:
                ui->pushButton_O_7->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 7:
                ui->pushButton_O_8->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 8:
                ui->pushButton_O_9->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 9:
                ui->pushButton_O_10->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 10:
                ui->pushButton_O_11->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 11:
                ui->pushButton_O_12->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 12:
                ui->pushButton_O_13->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 13:
                ui->pushButton_O_14->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 14:
                ui->pushButton_O_15->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 15:
                ui->pushButton_O_16->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 16:
                ui->pushButton_O_17->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 17:
                ui->pushButton_O_18->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 18:
                ui->pushButton_O_19->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 19:
                ui->pushButton_O_20->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 20:
                ui->pushButton_O_21->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 21:
                ui->pushButton_O_22->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 22:
                ui->pushButton_O_23->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 23:
                ui->pushButton_O_24->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 24:
                ui->pushButton_O_25->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 25:
                ui->pushButton_O_26->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 26:
                ui->pushButton_O_27->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 27:
                ui->pushButton_O_28->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 28:
                ui->pushButton_O_29->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            case 29:
                ui->pushButton_O_30->setStyleSheet(values.at(i) == 1 ? "background-color: green" : "background-color: red");
                break;
            default:
                break;
            }
        }
    }
}

/**
 * @brief MainWindow::readEncoder_Result
 * @param table     读取的表
 * @param address   读取的地址
 * @param values    读取的值
 */
void MainWindow::readEncoder_Result(QModbusDataUnit::RegisterType table, int address, QVector<quint16> values)
{
    if (table == QModbusDataUnit::HoldingRegisters)
    {
        if (values.size() == 6)
        {
            int32_t encoder1_count = (values.at(0) << 16) + values.at(1);
            int32_t encoder2_count = (values.at(2) << 16) + values.at(3);
            int32_t encoder3_count = (values.at(4) << 16) + values.at(5);
            //            qDebug() << "Encoder1 count: " << encoder1_count << " Encoder2 count: " << encoder2_count << " Encoder3 count: " << encoder3_count;
            // 判断line_edit是否处于选中状态
            if (!ui->lineEdit_encoder1->hasFocus())
            {
                ui->lineEdit_encoder1->setText(QString::number(encoder1_count));
            }
            if (!ui->lineEdit_encoder2->hasFocus())
            {
                ui->lineEdit_encoder2->setText(QString::number(encoder2_count));
            }
            if (!ui->lineEdit_encoder3->hasFocus())
            {
                ui->lineEdit_encoder3->setText(QString::number(encoder3_count));
            }
        }
    }
}

void MainWindow::on_pushButton_O_1_clicked()
{
    writeDO(0, ui->pushButton_O_1->styleSheet() == "background-color: green" ? false : true);
    readDO_TimerOut();
}

void MainWindow::on_pushButton_O_2_clicked()
{
    writeDO(1, ui->pushButton_O_2->styleSheet() == "background-color: green" ? false : true);
    readDO_TimerOut();
}

void MainWindow::on_pushButton_O_3_clicked()
{
    writeDO(2, ui->pushButton_O_3->styleSheet() == "background-color: green" ? false : true);
    readDO_TimerOut();
}

void MainWindow::on_pushButton_O_4_clicked()
{
    writeDO(3, ui->pushButton_O_4->styleSheet() == "background-color: green" ? false : true);
    readDO_TimerOut();
}

void MainWindow::on_pushButton_O_5_clicked()
{
    writeDO(4, ui->pushButton_O_5->styleSheet() == "background-color: green" ? false : true);
    readDO_TimerOut();
}

void MainWindow::on_pushButton_O_6_clicked()
{
    writeDO(5, ui->pushButton_O_6->styleSheet() == "background-color: green" ? false : true);
    readDO_TimerOut();
}

void MainWindow::on_pushButton_O_7_clicked()
{
    writeDO(6, ui->pushButton_O_7->styleSheet() == "background-color: green" ? false : true);
    readDO_TimerOut();
}

void MainWindow::on_pushButton_O_8_clicked()
{
    writeDO(7, ui->pushButton_O_8->styleSheet() == "background-color: green" ? false : true);
    readDO_TimerOut();
}

void MainWindow::on_pushButton_O_9_clicked()
{
    writeDO(8, ui->pushButton_O_9->styleSheet() == "background-color: green" ? false : true);
    readDO_TimerOut();
}

void MainWindow::on_pushButton_O_10_clicked()
{
    writeDO(9, ui->pushButton_O_10->styleSheet() == "background-color: green" ? false : true);
    readDO_TimerOut();
}

void MainWindow::on_pushButton_O_11_clicked()
{
    writeDO(10, ui->pushButton_O_11->styleSheet() == "background-color: green" ? false : true);
    readDO_TimerOut();
}

void MainWindow::on_pushButton_O_12_clicked()
{
    writeDO(11, ui->pushButton_O_12->styleSheet() == "background-color: green" ? false : true);
    readDO_TimerOut();
}

void MainWindow::on_pushButton_O_13_clicked()
{
    writeDO(12, ui->pushButton_O_13->styleSheet() == "background-color: green" ? false : true);
    readDO_TimerOut();
}

void MainWindow::on_pushButton_O_14_clicked()
{
    writeDO(13, ui->pushButton_O_14->styleSheet() == "background-color: green" ? false : true);
    readDO_TimerOut();
}

void MainWindow::on_pushButton_O_15_clicked()
{
    writeDO(14, ui->pushButton_O_15->styleSheet() == "background-color: green" ? false : true);
    readDO_TimerOut();
}

void MainWindow::on_pushButton_O_16_clicked()
{
    writeDO(15, ui->pushButton_O_16->styleSheet() == "background-color: green" ? false : true);
    readDO_TimerOut();
}

void MainWindow::on_pushButton_O_17_clicked()
{
    writeDO(16, ui->pushButton_O_17->styleSheet() == "background-color: green" ? false : true);
    readDO_TimerOut();
}

void MainWindow::on_pushButton_O_18_clicked()
{
    writeDO(17, ui->pushButton_O_18->styleSheet() == "background-color: green" ? false : true);
    readDO_TimerOut();
}

void MainWindow::on_pushButton_O_19_clicked()
{
    writeDO(18, ui->pushButton_O_19->styleSheet() == "background-color: green" ? false : true);
    readDO_TimerOut();
}

void MainWindow::on_pushButton_O_20_clicked()
{
    writeDO(19, ui->pushButton_O_20->styleSheet() == "background-color: green" ? false : true);
    readDO_TimerOut();
}

void MainWindow::on_pushButton_O_21_clicked()
{
    writeDO(20, ui->pushButton_O_21->styleSheet() == "background-color: green" ? false : true);
    readDO_TimerOut();
}

void MainWindow::on_pushButton_O_22_clicked()
{
    writeDO(21, ui->pushButton_O_22->styleSheet() == "background-color: green" ? false : true);
    readDO_TimerOut();
}

void MainWindow::on_pushButton_O_23_clicked()
{
    writeDO(22, ui->pushButton_O_23->styleSheet() == "background-color: green" ? false : true);
    readDO_TimerOut();
}

void MainWindow::on_pushButton_O_24_clicked()
{
    writeDO(23, ui->pushButton_O_24->styleSheet() == "background-color: green" ? false : true);
    readDO_TimerOut();
}

void MainWindow::on_pushButton_O_25_clicked()
{
    writeDO(24, ui->pushButton_O_25->styleSheet() == "background-color: green" ? false : true);
    readDO_TimerOut();
}

void MainWindow::on_pushButton_O_26_clicked()
{
    writeDO(25, ui->pushButton_O_26->styleSheet() == "background-color: green" ? false : true);
    readDO_TimerOut();
}

void MainWindow::on_pushButton_O_27_clicked()
{
    writeDO(26, ui->pushButton_O_27->styleSheet() == "background-color: green" ? false : true);
    readDO_TimerOut();
}

void MainWindow::on_pushButton_O_28_clicked()
{
    writeDO(27, ui->pushButton_O_28->styleSheet() == "background-color: green" ? false : true);
    readDO_TimerOut();
}

void MainWindow::on_pushButton_O_29_clicked()
{
    writeDO(28, ui->pushButton_O_29->styleSheet() == "background-color: green" ? false : true);
    readDO_TimerOut();
}

void MainWindow::on_pushButton_O_30_clicked()
{
    writeDO(29, ui->pushButton_O_30->styleSheet() == "background-color: green" ? false : true);
    readDO_TimerOut();
}

/**
 * @brief MainWindow::writeDO
 * @param address   写DO的地址
 * @param value     写DO的值
 */
void MainWindow::writeDO(int address, bool value)
{
    if (!modbusDevice)
    {
        return;
    }
    if (modbusDevice->state() != QModbusDevice::ConnectedState)
    {
        return;
    }
    // 写线圈
    QModbusDataUnit writeDO = QModbusDataUnit(QModbusDataUnit::Coils, address, 1);
    writeDO.setValue(0, value);
    if (auto *reply = modbusDevice->sendWriteRequest(writeDO, 1))
    {
        if (!reply->isFinished())
        {
            connect(reply, &QModbusReply::finished, this, [this, reply]()
                    {
                if (reply->error() == QModbusDevice::NoError)
                {
                    const QModbusDataUnit unit = reply->result();
                    qDebug() << "Write DO result: " << unit.values().at(0);
                }
                reply->deleteLater(); });
        }
        else
        {
            delete reply;
        }
    }
    else
    {
        qDebug() << "Write DO error: " << modbusDevice->errorString();
    }
}

/**
 * @brief MainWindow::on_lineEdit_encoder1_returnPressed
 * 这个函数是在mainwindow.ui中的lineEdit_encoder1输入完成后按回车键触发的
 */
void MainWindow::on_lineEdit_encoder1_returnPressed()
{
    if (!modbusDevice)
    {
        return;
    }
    if (modbusDevice->state() != QModbusDevice::ConnectedState)
    {
        return;
    }
    // 写保持寄存器
    QModbusDataUnit writeEncoder = QModbusDataUnit(QModbusDataUnit::HoldingRegisters, MODBUS_RTU_REG_ENCODER1_COUNT, 2);
    writeEncoder.setValue(0, ui->lineEdit_encoder1->text().toInt() >> 16);
    writeEncoder.setValue(1, ui->lineEdit_encoder1->text().toInt() & 0xFFFF);
    if (auto *reply = modbusDevice->sendWriteRequest(writeEncoder, 1))
    {
        if (!reply->isFinished())
        {
            connect(reply, &QModbusReply::finished, this, [this, reply]()
                    {
                if (reply->error() == QModbusDevice::NoError)
                {
                    const QModbusDataUnit unit = reply->result();
                    qDebug() << "Write Encoder1 result: " << unit.values().at(0) << " " << unit.values().at(1);
                }
                reply->deleteLater(); });
        }
        else
        {
            delete reply;
        }
    }
    else
    {
        qDebug() << "Write Encoder1 error: " << modbusDevice->errorString();
    }
}

/**
 * @brief MainWindow::on_lineEdit_encoder2_returnPressed
 * 这个函数是在mainwindow.ui中的lineEdit_encoder2输入完成后按回车键触发的
 */
void MainWindow::on_lineEdit_encoder2_returnPressed()
{
    if (!modbusDevice)
    {
        return;
    }
    if (modbusDevice->state() != QModbusDevice::ConnectedState)
    {
        return;
    }
    // 写保持寄存器
    QModbusDataUnit writeEncoder = QModbusDataUnit(QModbusDataUnit::HoldingRegisters, MODBUS_RTU_REG_ENCODER1_COUNT + 2, 2);
    writeEncoder.setValue(0, ui->lineEdit_encoder2->text().toInt() >> 16);
    writeEncoder.setValue(1, ui->lineEdit_encoder2->text().toInt() & 0xFFFF);
    if (auto *reply = modbusDevice->sendWriteRequest(writeEncoder, 1))
    {
        if (!reply->isFinished())
        {
            connect(reply, &QModbusReply::finished, this, [this, reply]()
                    {
                if (reply->error() == QModbusDevice::NoError)
                {
                    const QModbusDataUnit unit = reply->result();
                    qDebug() << "Write Encoder2 result: " << unit.values().at(0) << " " << unit.values().at(1);
                }
                reply->deleteLater(); });
        }
        else
        {
            delete reply;
        }
    }
    else
    {
        qDebug() << "Write Encoder2 error: " << modbusDevice->errorString();
    }
}

/**
 * @brief MainWindow::on_lineEdit_encoder3_returnPressed
 * 这个函数是在mainwindow.ui中的lineEdit_encoder3输入完成后按回车键触发的
 */
void MainWindow::on_lineEdit_encoder3_returnPressed()
{
    if (!modbusDevice)
    {
        return;
    }
    if (modbusDevice->state() != QModbusDevice::ConnectedState)
    {
        return;
    }
    // 写保持寄存器
    QModbusDataUnit writeEncoder = QModbusDataUnit(QModbusDataUnit::HoldingRegisters, MODBUS_RTU_REG_ENCODER1_COUNT + 4, 2);
    writeEncoder.setValue(0, ui->lineEdit_encoder3->text().toInt() >> 16);
    writeEncoder.setValue(1, ui->lineEdit_encoder3->text().toInt() & 0xFFFF);
    if (auto *reply = modbusDevice->sendWriteRequest(writeEncoder, 1))
    {
        if (!reply->isFinished())
        {
            connect(reply, &QModbusReply::finished, this, [this, reply]()
                    {
                if (reply->error() == QModbusDevice::NoError)
                {
                    const QModbusDataUnit unit = reply->result();
                    qDebug() << "Write Encoder3 result: " << unit.values().at(0) << " " << unit.values().at(1);
                }
                reply->deleteLater(); });
        }
        else
        {
            delete reply;
        }
    }
    else
    {
        qDebug() << "Write Encoder3 error: " << modbusDevice->errorString();
    }
}

/**
 * @brief MainWindow::on_pushButton_save_clicked
 * 这个函数是在mainwindow.ui中的pushButton_save按钮被点击时触发的
 */
void MainWindow::on_pushButton_save_clicked()
{
    if (!modbusDevice)
    {
        return;
    }
    if (modbusDevice->state() != QModbusDevice::ConnectedState)
    {
        return;
    }
    // 写线圈
    QModbusDataUnit writeDO = QModbusDataUnit(QModbusDataUnit::Coils, MODBUS_RTU_COIL_SYSTEM_SAVE_PARAM, 1);
    writeDO.setValue(0, true);
    if (auto *reply = modbusDevice->sendWriteRequest(writeDO, 1))
    {
        if (!reply->isFinished())
        {
            connect(reply, &QModbusReply::finished, this, [this, reply]()
                    {
                if (reply->error() == QModbusDevice::NoError)
                {
                    const QModbusDataUnit unit = reply->result();
                    qDebug() << "Save param result: " << unit.values().at(0);
                }
                reply->deleteLater(); });
        }
        else
        {
            delete reply;
        }
    }
    else
    {
        qDebug() << "Save param error: " << modbusDevice->errorString();
    }
}

/**
 * @brief MainWindow::on_pushButton_reset_clicked
 * 这个函数是在mainwindow.ui中的pushButton_reset按钮被点击时触发的
 */
void MainWindow::on_pushButton_reboot_clicked()
{
    if (!modbusDevice)
    {
        return;
    }
    if (modbusDevice->state() != QModbusDevice::ConnectedState)
    {
        return;
    }
    // 写线圈
    QModbusDataUnit writeDO = QModbusDataUnit(QModbusDataUnit::Coils, MODBUS_RTU_COIL_SYSTEM_REBOOT, 1);
    writeDO.setValue(0, true);
    if (auto *reply = modbusDevice->sendWriteRequest(writeDO, 1))
    {
        if (!reply->isFinished())
        {
            connect(reply, &QModbusReply::finished, this, [this, reply]()
                    {
                if (reply->error() == QModbusDevice::NoError)
                {
                    const QModbusDataUnit unit = reply->result();
                    qDebug() << "Reboot result: " << unit.values().at(0);
                }
                reply->deleteLater(); });
        }
        else
        {
            delete reply;
        }
    }
    else
    {
        qDebug() << "Reboot error: " << modbusDevice->errorString();
    }
}

/**
 * @brief MainWindow::on_pushButton_restore_clicked
 * 这个函数是在mainwindow.ui中的pushButton_reset按钮被点击时触发的
 */
void MainWindow::on_pushButton_restore_clicked()
{
    if (!modbusDevice)
    {
        return;
    }
    if (modbusDevice->state() != QModbusDevice::ConnectedState)
    {
        return;
    }
    // 写线圈
    QModbusDataUnit writeDO = QModbusDataUnit(QModbusDataUnit::Coils, MODBUS_RTU_COIL_SYSTEM_RESTORE_FACTORY_SETTINGS, 1);
    writeDO.setValue(0, true);
    if (auto *reply = modbusDevice->sendWriteRequest(writeDO, 1))
    {
        if (!reply->isFinished())
        {
            connect(reply, &QModbusReply::finished, this, [this, reply]()
                    {
                if (reply->error() == QModbusDevice::NoError)
                {
                    const QModbusDataUnit unit = reply->result();
                    qDebug() << "Restore param result: " << unit.values().at(0);
                }
                reply->deleteLater(); });
        }
        else
        {
            delete reply;
        }
    }
    else
    {
        qDebug() << "Restore param error: " << modbusDevice->errorString();
    }
}

/**
 * @brief MainWindow::readSystemStatus_TimerOut
 * 这个函数是在mainwindow.ui中的pushButton_readSystemStatus按钮被点击时触发的
 */
void MainWindow::readSystemStatus_TimerOut()
{
    ReadSystemStatus_Timer.stop();
    ReadSystemStatus_Timer.start(2000); // 1s

    if (readSystemStatusCount == 0)
    {
        if (ui->checkBox_t1->isChecked())
        {
            readSystemStatus(MODBUS_RTU_REG_TASK1_STACK_SIZE);
        }
    }
    else if (readSystemStatusCount == 1)
    {
        if (ui->checkBox_t2->isChecked())
        {
            readSystemStatus(MODBUS_RTU_REG_TASK2_STACK_SIZE);
        }
    }
    else if (readSystemStatusCount == 2)
    {
        if (ui->checkBox_t3->isChecked())
        {
            readSystemStatus(MODBUS_RTU_REG_TASK3_STACK_SIZE);
        }
    }
    else if (readSystemStatusCount == 3)
    {
        if (ui->checkBox_t4->isChecked())
        {
            readSystemStatus(MODBUS_RTU_REG_TASK4_STACK_SIZE);
        }
    }
    else if (readSystemStatusCount == 4)
    {
        if (ui->checkBox_t5->isChecked())
        {
            readSystemStatus(MODBUS_RTU_REG_TASK5_STACK_SIZE);
        }
    }
    else if (readSystemStatusCount == 5)
    {
        if (ui->checkBox_t6->isChecked())
        {
            readSystemStatus(MODBUS_RTU_REG_TASK6_STACK_SIZE);
        }
    }
    else if (readSystemStatusCount == 6)
    {
        if (ui->checkBox_t7->isChecked())
        {
            readSystemStatus(MODBUS_RTU_REG_TASK7_STACK_SIZE);
        }
    }
    else if (readSystemStatusCount == 7)
    {
        if (ui->checkBox_t8->isChecked())
        {
            readSystemStatus(MODBUS_RTU_REG_TASK8_STACK_SIZE);
        }
    }
    else if (readSystemStatusCount == 8)
    {
        if (ui->checkBox_t9->isChecked())
        {
            readSystemStatus(MODBUS_RTU_REG_TASK9_STACK_SIZE);
        }
    }
    else if (readSystemStatusCount == 9)
    {
        if (ui->checkBox_t10->isChecked())
        {
            readSystemStatus(MODBUS_RTU_REG_TASK10_STACK_SIZE);
        }
    }

    readSystemStatusCount++;
    if (readSystemStatusCount > 9)
    {
        readSystemStatusCount = 0;
    }
}

/**
 * @brief MainWindow::readSystemStatus
 * @param address   读取的地址
 */
void MainWindow::readSystemStatus(uint16_t address)
{
    if (!modbusDevice)
    {
        return;
    }
    if (modbusDevice->state() != QModbusDevice::ConnectedState)
    {
        return;
    }
    // 读保持寄存器
    QModbusDataUnit readSystemStatus = QModbusDataUnit(QModbusDataUnit::HoldingRegisters, address, 1);
    if (auto *reply = modbusDevice->sendReadRequest(readSystemStatus, 1))
    {
        if (!reply->isFinished())
        {
            connect(reply, &QModbusReply::finished, this, [this, reply, address]()
                    {
                if (reply->error() == QModbusDevice::NoError)
                {
                    const QModbusDataUnit unit = reply->result();
                    readSystemStatus_Result(address, unit.values().at(0)); // 读取系统状态结果处理
                }
                reply->deleteLater(); });
        }
        else
        {
            delete reply;
        }
    }
    else
    {
        qDebug() << "Read System Status error: " << modbusDevice->errorString();
    }
}

/**
 * @brief MainWindow::readSystemStatus_Result
 * @param address   读取的地址
 * @param value     读取的值
 */
void MainWindow::readSystemStatus_Result(int address, uint16_t value)
{
    switch (address)
    {
    case MODBUS_RTU_REG_TASK1_STACK_SIZE:
        ui->lineEdit_t1->setText(QString::number(value));
        break;
    case MODBUS_RTU_REG_TASK2_STACK_SIZE:
        ui->lineEdit_t2->setText(QString::number(value));
        break;
    case MODBUS_RTU_REG_TASK3_STACK_SIZE:
        ui->lineEdit_t3->setText(QString::number(value));
        break;
    case MODBUS_RTU_REG_TASK4_STACK_SIZE:
        ui->lineEdit_t4->setText(QString::number(value));
        break;
    case MODBUS_RTU_REG_TASK5_STACK_SIZE:
        ui->lineEdit_t5->setText(QString::number(value));
        break;
    case MODBUS_RTU_REG_TASK6_STACK_SIZE:
        ui->lineEdit_t6->setText(QString::number(value));
        break;
    case MODBUS_RTU_REG_TASK7_STACK_SIZE:
        ui->lineEdit_t7->setText(QString::number(value));
        break;
    case MODBUS_RTU_REG_TASK8_STACK_SIZE:
        ui->lineEdit_t8->setText(QString::number(value));
        break;
    case MODBUS_RTU_REG_TASK9_STACK_SIZE:
        ui->lineEdit_t9->setText(QString::number(value));
        break;
    case MODBUS_RTU_REG_TASK10_STACK_SIZE:
        ui->lineEdit_t10->setText(QString::number(value));
        break;
    default:
        break;
    }
}

/**
 * @brief MainWindow::readHDRegisters
 * @param serverAddress         modbus rtu 从机地址
 * @param startAddress          起始地址
 * @param numberOfRegisters     寄存器数量
 */
void MainWindow::readHDRegisters(int serverAddress, int startAddress, int numberOfRegisters)
{
    if (!modbusDevice || modbusDevice->state() != QModbusDevice::ConnectedState)
    {
        qCritical() << "Modbus device is not connected!";
        return;
    }
    QModbusDataUnit readUnit(QModbusDataUnit::HoldingRegisters, startAddress, numberOfRegisters);
    if (auto *reply = modbusDevice->sendReadRequest(readUnit, serverAddress))
    {
        if (!reply->isFinished())
        {
            connect(reply, &QModbusReply::finished, this, [this, reply]()
                    {
                    if (reply->error() == QModbusDevice::NoError)
                    {
                        const QModbusDataUnit result = reply->result();
                            // qDebug() << "Register" << result.startAddress() + i << ":" << result.value(i);
                        int start_reg_addr = result.startAddress();
                        if (start_reg_addr == MDBS_HD_MATERIAL_DELAY + MODBUS_RTU_HD_REG_OFFSET)
                        {
                            // 料位延时 修改 tabWidget的第一行  第二列 QLineEdit
                            QWidget *widget = ui->tableWidget_projectPar->cellWidget(0, 1);
                            QLineEdit *lineEdit = qobject_cast<QLineEdit*>(widget);
                            if (lineEdit) {
                                lineEdit->setText(QString::number(result.value(0)));
                            }
                        }
                        else if (start_reg_addr == MDBS_HD_GEAR_RATIO + MODBUS_RTU_HD_REG_OFFSET)
                        {
                            // 齿轮比 修改 tabWidget的第二行  第二列 QLineEdit 读了两个寄存器 4字节转float
                            float gear_ratio = 0.0f;
                            uint16_t gear_ratio_c[2];
                            gear_ratio_c[0] = result.value(0);
                            gear_ratio_c[1] = result.value(1);
                            memcpy(&gear_ratio, gear_ratio_c, 4);
                            // 保留4位小数
                            QWidget *widget = ui->tableWidget_projectPar->cellWidget(1, 1);
                            QLineEdit *lineEdit = qobject_cast<QLineEdit*>(widget);
                            if (lineEdit) {
                                lineEdit->setText(QString("%1").arg(gear_ratio, 0, 'f', 4));
                            }
                        }
                        else if (start_reg_addr == MDBS_HD_BOX_TOTAL_LEN + MODBUS_RTU_HD_REG_OFFSET)
                        {
                            // 箱体总长 修改 tabWidget的第三行  第二列 QLineEdit
                            QWidget *widget = ui->tableWidget_projectPar->cellWidget(2, 1);
                            QLineEdit *lineEdit = qobject_cast<QLineEdit*>(widget);
                            if (lineEdit) {
                                lineEdit->setText(QString::number(result.value(0)));
                            }
                        }
                        else if (start_reg_addr == MDBS_HD_BOX_LEN + MODBUS_RTU_HD_REG_OFFSET)
                        {
                            // 打包长度 修改 tabWidget的第四行  第二列 QLineEdit
                            QWidget *widget = ui->tableWidget_projectPar->cellWidget(3, 1);
                            QLineEdit *lineEdit = qobject_cast<QLineEdit*>(widget);
                            if (lineEdit) {
                                lineEdit->setText(QString::number(result.value(0)));
                            }
                        }
                        else if (start_reg_addr == MDBS_HD_BACKWARD_LOW_PRESSURE_POS + MODBUS_RTU_HD_REG_OFFSET)
                        {
                            // 后退低压位置设定 修改 tabWidget的第五行  第二列 QLineEdit
                            QWidget *widget = ui->tableWidget_projectPar->cellWidget(4, 1);
                            QLineEdit *lineEdit = qobject_cast<QLineEdit*>(widget);
                            if (lineEdit) {
                                lineEdit->setText(QString::number(result.value(0)));
                            }
                        }
                        else if (start_reg_addr == MDBS_HD_OUT_BOX_LEN + MODBUS_RTU_HD_REG_OFFSET)
                        {
                            // 出包长度设定 修改 tabWidget的第六行  第二列 QLineEdit
                            QWidget *widget = ui->tableWidget_projectPar->cellWidget(5, 1);
                            QLineEdit *lineEdit = qobject_cast<QLineEdit*>(widget);
                            if (lineEdit) {
                                lineEdit->setText(QString::number(result.value(0)));
                            }
                        }
                        else if (start_reg_addr == MDBS_HD_BACKWARD_CLOSE_DOOR_LEN + MODBUS_RTU_HD_REG_OFFSET)
                        {
                            // 后退关门长度 修改 tabWidget的第七行  第二列 QLineEdit
                            QWidget *widget = ui->tableWidget_projectPar->cellWidget(6, 1);
                            QLineEdit *lineEdit = qobject_cast<QLineEdit*>(widget);
                            if (lineEdit) {
                                lineEdit->setText(QString::number(result.value(0)));
                            }
                        }
                        else if (start_reg_addr == MDBS_HD_FORWARD_WALK_LEN + MODBUS_RTU_HD_REG_OFFSET)
                        {
                            // 前进行走长度 修改 tabWidget的第八行  第二列 QLineEdit
                            QWidget *widget = ui->tableWidget_projectPar->cellWidget(7, 1);
                            QLineEdit *lineEdit = qobject_cast<QLineEdit*>(widget);
                            if (lineEdit) {
                                lineEdit->setText(QString::number(result.value(0)));
                            }
                        }
                        else if (start_reg_addr == MDBS_HD_TEMP_MAXLIMIT + MODBUS_RTU_HD_REG_OFFSET)
                        {
                            // 温度上限 修改 tabWidget的第九行  第二列 QLineEdit
                            QWidget *widget = ui->tableWidget_projectPar->cellWidget(8, 1);
                            QLineEdit *lineEdit = qobject_cast<QLineEdit*>(widget);
                            if (lineEdit) {
                                lineEdit->setText(QString::number(result.value(0)));
                            }
                        }
                        else if (start_reg_addr == MDBS_HD_TEMP_MINLIMIT + MODBUS_RTU_HD_REG_OFFSET)
                        {
                            // 温度下限 修改 tabWidget的第十行  第二列 QLineEdit
                            QWidget *widget = ui->tableWidget_projectPar->cellWidget(9, 1);
                            QLineEdit *lineEdit = qobject_cast<QLineEdit*>(widget);
                            if (lineEdit) {
                                lineEdit->setText(QString::number(result.value(0)));
                            }
                        }
                        else if (start_reg_addr == MDBS_HD_PRESSURE_FORWARD_PROTECT_TIME + MODBUS_RTU_HD_REG_OFFSET)
                        {
                            // 前进保护时间 修改 tabWidget的第十一行  第二列 QLineEdit
                            QWidget *widget = ui->tableWidget_projectPar->cellWidget(10, 1);
                            QLineEdit *lineEdit = qobject_cast<QLineEdit*>(widget);
                            if (lineEdit) {
                                lineEdit->setText(QString::number(result.value(0)));
                            }
                        }
                        else if (start_reg_addr == MDBS_HD_MATERIAL_FULL_DELAY + MODBUS_RTU_HD_REG_OFFSET)
                        {
                            // 料满延时 修改 tabWidget的第十二行  第二列 QLineEdit
                            QWidget *widget = ui->tableWidget_projectPar->cellWidget(11, 1);
                            QLineEdit *lineEdit = qobject_cast<QLineEdit*>(widget);
                            if (lineEdit) {
                                lineEdit->setText(QString::number(result.value(0)));
                            }
                        }
                        else if (start_reg_addr == MDBS_HD_RUNTIME_S + MODBUS_RTU_HD_REG_OFFSET)
                        {
                            // 运行时间S 修改 tabWidget的第十三行  第二列 QLineEdit
                            QWidget *widget = ui->tableWidget_projectPar->cellWidget(12, 1);
                            QLineEdit *lineEdit = qobject_cast<QLineEdit*>(widget);
                            if (lineEdit) {
                                lineEdit->setText(QString::number(result.value(0)));
                            }
                        }
                        else if (start_reg_addr == MDBS_HD_RUNTIME_MIN + MODBUS_RTU_HD_REG_OFFSET)
                        {
                            // 运行时间M 修改 tabWidget的第十四行  第二列 QLineEdit
                            QWidget *widget = ui->tableWidget_projectPar->cellWidget(13, 1);
                            QLineEdit *lineEdit = qobject_cast<QLineEdit*>(widget);
                            if (lineEdit) {
                                lineEdit->setText(QString::number(result.value(0)));
                            }
                        }
                        else if (start_reg_addr == MDBS_HD_RUNTIME_H + MODBUS_RTU_HD_REG_OFFSET)
                        {
                            // 运行时间H 修改 tabWidget的第十五行  第二列 QLineEdit
                            QWidget *widget = ui->tableWidget_projectPar->cellWidget(14, 1);
                            QLineEdit *lineEdit = qobject_cast<QLineEdit*>(widget);
                            if (lineEdit) {
                                lineEdit->setText(QString::number(result.value(0)));
                            }
                        }
                        else if (start_reg_addr == MDBS_HD_RUNTIME_TOTAL_H + MODBUS_RTU_HD_REG_OFFSET)
                        {
                            // 总运行时间H 修改 tabWidget的第十六行  第二列 QLineEdit
                            QWidget *widget = ui->tableWidget_projectPar->cellWidget(15, 1);
                            QLineEdit *lineEdit = qobject_cast<QLineEdit*>(widget);
                            if (lineEdit) {
                                lineEdit->setText(QString::number(result.value(0)));
                            }
                        }
                        else if (start_reg_addr == MDBS_HD_RUNTIME_ACTIVATE_H + MODBUS_RTU_HD_REG_OFFSET)
                        {
                            // 激活时间H 修改 tabWidget的第十七行  第二列 QLineEdit
                            QWidget *widget = ui->tableWidget_projectPar->cellWidget(16, 1);
                            QLineEdit *lineEdit = qobject_cast<QLineEdit*>(widget);
                            if (lineEdit) {
                                lineEdit->setText(QString::number(result.value(0)));
                            }
                        }
                        else if (start_reg_addr == MDBS_HD_RUNTIME_REMAIN_H + MODBUS_RTU_HD_REG_OFFSET)
                        {
                            // 剩余时间H 修改 tabWidget的第十八行  第二列 QLineEdit
                            QWidget *widget = ui->tableWidget_projectPar->cellWidget(17, 1);
                            QLineEdit *lineEdit = qobject_cast<QLineEdit*>(widget);
                            if (lineEdit) {
                                lineEdit->setText(QString::number(result.value(0)));
                            }
                        }
                        else if (start_reg_addr == MDBS_HD_PRESSURE_FASTORLOW + MODBUS_RTU_HD_REG_OFFSET)
                        {
                            // 快慢压力 修改 tabWidget的第十九行  第二列 QLineEdit float
                            float pressure = 0.0f;
                            uint16_t pressure_c[2];
                            pressure_c[0] = result.value(0);
                            pressure_c[1] = result.value(1);
                            memcpy(&pressure, pressure_c, 4);
                            // 保留4位小数
                            QWidget *widget = ui->tableWidget_projectPar->cellWidget(18, 1);
                            QLineEdit *lineEdit = qobject_cast<QLineEdit*>(widget);
                            if (lineEdit) {
                                lineEdit->setText(QString("%1").arg(pressure, 0, 'f', 4));
                            }
                        }
                        else if (start_reg_addr == MDBS_HD_FIRST_PRESSURE_COUNT + MODBUS_RTU_HD_REG_OFFSET)
                        {
                            // 第一次预压次数 修改 tabWidget的第二十行  第二列 QLineEdit
                            QWidget *widget = ui->tableWidget_projectPar->cellWidget(19, 1);
                            QLineEdit *lineEdit = qobject_cast<QLineEdit*>(widget);
                            if (lineEdit) {
                                lineEdit->setText(QString::number(result.value(0)));
                            }
                        }
                        else if (start_reg_addr == MDBS_HD_SECOND_PRESSURE_COUNT + MODBUS_RTU_HD_REG_OFFSET)
                        {
                            // 第二次预压次数 修改 tabWidget的第二十一行  第二列 QLineEdit
                            QWidget *widget = ui->tableWidget_projectPar->cellWidget(20, 1);
                            QLineEdit *lineEdit = qobject_cast<QLineEdit*>(widget);
                            if (lineEdit) {
                                lineEdit->setText(QString::number(result.value(0)));
                            }
                        }
                        else if (start_reg_addr == MDBS_HD_PRESSURE_MAINCYLINDER_FORWARD + MODBUS_RTU_HD_REG_OFFSET)
                        {
                            // 主缸前进压力设定 float 修改 tabWidget的第二十二行  第二列 QLineEdit
                            float pressure_maincylinder_forward = 0.0f;
                            uint16_t pressure_maincylinder_forward_c[2];
                            pressure_maincylinder_forward_c[0] = result.value(0);
                            pressure_maincylinder_forward_c[1] = result.value(1);
                            memcpy(&pressure_maincylinder_forward, pressure_maincylinder_forward_c, 4);
                            // 保留4位小数
                            QWidget *widget = ui->tableWidget_projectPar->cellWidget(21, 1);
                            QLineEdit *lineEdit = qobject_cast<QLineEdit*>(widget);
                            if (lineEdit) {
                                lineEdit->setText(QString("%1").arg(pressure_maincylinder_forward, 0, 'f', 4));
                            }
                        }
                        else if (start_reg_addr == MDBS_HD_PRESSURE_MAXPROTECT_STOP + MODBUS_RTU_HD_REG_OFFSET)
                        {
                            // 最高保护压力停止 float 修改 tabWidget的第二十三行  第二列 QLineEdit
                            float pressure_maxprotect_stop = 0.0f;
                            uint16_t pressure_maxprotect_stop_c[2];
                            pressure_maxprotect_stop_c[0] = result.value(0);
                            pressure_maxprotect_stop_c[1] = result.value(1);
                            memcpy(&pressure_maxprotect_stop, pressure_maxprotect_stop_c, 4);
                            // 保留4位小数
                            QWidget *widget = ui->tableWidget_projectPar->cellWidget(22, 1);
                            QLineEdit *lineEdit = qobject_cast<QLineEdit*>(widget);
                            if (lineEdit) {
                                lineEdit->setText(QString("%1").arg(pressure_maxprotect_stop, 0, 'f', 4));
                            }
                        }
                        else if (start_reg_addr == MDBS_HD_PRESSURE_MAINCYLINDER_BACKWARD + MODBUS_RTU_HD_REG_OFFSET)
                        {
                            // 主缸后退压力保护 float   修改 tabWidget的第二十四行  第二列 QLineEdit
                            float pressure_maincylinder_backward = 0.0f;
                            uint16_t pressure_maincylinder_backward_c[2];
                            pressure_maincylinder_backward_c[0] = result.value(0);
                            pressure_maincylinder_backward_c[1] = result.value(1);
                            memcpy(&pressure_maincylinder_backward, pressure_maincylinder_backward_c, 4);
                            // 保留4位小数
                            QWidget *widget = ui->tableWidget_projectPar->cellWidget(23, 1);
                            QLineEdit *lineEdit = qobject_cast<QLineEdit*>(widget);
                            if (lineEdit) {
                                lineEdit->setText(QString("%1").arg(pressure_maincylinder_backward, 0, 'f', 4));
                            }
                        }
                        else if (start_reg_addr == MDBS_HD_PRESSURE_RELIEF_DELAY + MODBUS_RTU_HD_REG_OFFSET)
                        {
                            // 泄压延时时间     修改 tabWidget的第二十五行  第二列 QLineEdit
                            QWidget *widget = ui->tableWidget_projectPar->cellWidget(24, 1);
                            QLineEdit *lineEdit = qobject_cast<QLineEdit*>(widget);
                            if (lineEdit) {
                                lineEdit->setText(QString::number(result.value(0)));
                            }
                        }
                        else if (start_reg_addr == MDBS_HD_MAINCYLINDER_BACKWARD_PROTECT_TIME + MODBUS_RTU_HD_REG_OFFSET)
                        {
                            // 主缸后退计时    修改 tabWidget的第二十六行  第二列 QLineEdit
                            QWidget *widget = ui->tableWidget_projectPar->cellWidget(25, 1);
                            QLineEdit *lineEdit = qobject_cast<QLineEdit*>(widget);
                            if (lineEdit) {
                                lineEdit->setText(QString::number(result.value(0)));
                            }
                        }
                        else if(start_reg_addr == MDBS_HD_PRESSURE_WALK_LEN + MODBUS_RTU_HD_REG_OFFSET)
                        {
                            // 预压行走长度设定    修改 tabWidget的第二十七行  第二列 QLineEdit
                            QWidget *widget = ui->tableWidget_projectPar->cellWidget(26, 1);
                            QLineEdit *lineEdit = qobject_cast<QLineEdit*>(widget);
                            if (lineEdit) {
                                lineEdit->setText(QString::number(result.value(0)));
                            }
                        }
                        else if (start_reg_addr == MDBS_HD_FIRST_PRESSURE_COUNT_SET + MODBUS_RTU_HD_REG_OFFSET)
                        {
                            // 第一次预压次数设定    修改 tabWidget的第二十八行  第二列 QLineEdit
                            QWidget *widget = ui->tableWidget_projectPar->cellWidget(27, 1);
                            QLineEdit *lineEdit = qobject_cast<QLineEdit*>(widget);
                            if (lineEdit) {
                                lineEdit->setText(QString::number(result.value(0)));
                            }
                        }
                        else if (start_reg_addr == MDBS_HD_SECOND_PRESSURE_COUNT_SET + MODBUS_RTU_HD_REG_OFFSET)
                        {
                            // 第二次预压次数设定    修改 tabWidget的第二十九行  第二列 QLineEdit
                            QWidget *widget = ui->tableWidget_projectPar->cellWidget(28, 1);
                            QLineEdit *lineEdit = qobject_cast<QLineEdit*>(widget);
                            if (lineEdit) {
                                lineEdit->setText(QString::number(result.value(0)));
                            }
                        }
                        else if (start_reg_addr == MDBS_HD_THIRD_PRESSURE_COUNT_SET + MODBUS_RTU_HD_REG_OFFSET)
                        {
                            // 第三次预压次数设定    修改 tabWidget的第三十行  第二列 QLineEdit
                            QWidget *widget = ui->tableWidget_projectPar->cellWidget(29, 1);
                            QLineEdit *lineEdit = qobject_cast<QLineEdit*>(widget);
                            if (lineEdit) {
                                lineEdit->setText(QString::number(result.value(0)));
                            }
                        }
                    }
                    else
                    {
                        qDebug() << "Read error:" << reply->errorString();
                    }
                    reply->deleteLater(); });
        }
        else
        {
            qDebug() << "Reply is already finished!";
            reply->deleteLater();
        }
    }
    else
    {
        qDebug() << "Failed to send read request:" << modbusDevice->errorString();
    }
}

void MainWindow::writeHDRegisters(int serverAddress, QModbusDataUnit data)
{
    if (!modbusDevice || modbusDevice->state() != QModbusDevice::ConnectedState)
    {
        qCritical() << "Modbus device is not connected!";
        return;
    }
    if (auto *reply = modbusDevice->sendWriteRequest(data, serverAddress))
    {
        if (!reply->isFinished())
        {
            connect(reply, &QModbusReply::finished, this, [this, reply]()
                    {
                    if (reply->error() == QModbusDevice::NoError)
                    {
                        const QModbusDataUnit result = reply->result();
                        qDebug() << "Write result:" << result.values().at(0);
                    }
                    else
                    {
                        qDebug() << "Write error:" << reply->errorString();
                    }
                    reply->deleteLater(); });
        }
        else
        {
            qDebug() << "Reply is already finished!";
            reply->deleteLater();
        }
    }
    else
    {
        qDebug() << "Failed to send write request:" << modbusDevice->errorString();
    }
}

/**
 * @brief MainWindow::on_pushButton_readSystemStatus_clicked
 * 这个函数是在mainwindow.ui中的 读取当前页 按钮
 */
void MainWindow::on_pushButton_readCurrentPage_clicked()
{
    if (!modbusDevice)
    {
        return;
    }
    if (modbusDevice->state() != QModbusDevice::ConnectedState)
    {
        return;
    }
    // 判断tabWidget_paramTab的当前页
    int index = ui->tabWidget_paramTab->currentIndex();
    int readAddress = 0;
    int readCount = 0;
    if (index == 0) // 读取DI
    {
        readAddress = this->diMap->get_read_di_addr();
        readCount = this->diMap->get_read_di_num();
        // 读取保持寄存器
        QModbusDataUnit readCurrentPage = QModbusDataUnit(QModbusDataUnit::HoldingRegisters, readAddress, readCount);
        if (auto *reply = modbusDevice->sendReadRequest(readCurrentPage, 1))
        {
            if (!reply->isFinished())
            {
                connect(reply, &QModbusReply::finished, this, [this, reply, readAddress, readCount]()
                        {
                if (reply->error() == QModbusDevice::NoError)
                {
                    const QModbusDataUnit unit = reply->result();
                    this->diMap->readCurrentPage_Result(QModbusDataUnit::HoldingRegisters, readAddress, unit.values());
                }
                reply->deleteLater(); });
            }
            else
            {
                delete reply;
            }
        }
        else
        {
            qDebug() << "Read Current Page error: " << modbusDevice->errorString();
        }
    }
    else if (index == 1)
    {
        readAddress = this->doMap->get_read_do_addr();
        readCount = this->doMap->get_read_do_num();
        // 读取保持寄存器
        QModbusDataUnit readCurrentPage = QModbusDataUnit(QModbusDataUnit::HoldingRegisters, readAddress, readCount);
        if (auto *reply = modbusDevice->sendReadRequest(readCurrentPage, 1))
        {
            if (!reply->isFinished())
            {
                connect(reply, &QModbusReply::finished, this, [this, reply, readAddress, readCount]()
                        {
                if (reply->error() == QModbusDevice::NoError)
                {
                    const QModbusDataUnit unit = reply->result();
                    this->doMap->readCurrentPage_Result(QModbusDataUnit::HoldingRegisters, readAddress, unit.values());
                }
                reply->deleteLater(); });
            }
            else
            {
                delete reply;
            }
        }
        else
        {
            qDebug() << "Read Current Page error: " << modbusDevice->errorString();
        }
    }
    else if (index == 2) // 读取其他寄存器映射
    {
        // 读 AI
        readAddress = this->otherMap->get_read_ai_addr();
        readCount = this->otherMap->get_read_ai_num();
        // 读取保持寄存器
        QModbusDataUnit readCurrentPage = QModbusDataUnit(QModbusDataUnit::HoldingRegisters, readAddress, readCount);
        if (auto *reply = modbusDevice->sendReadRequest(readCurrentPage, 1))
        {
            if (!reply->isFinished())
            {
                connect(reply, &QModbusReply::finished, this, [this, reply, readAddress, readCount]()
                        {
                if (reply->error() == QModbusDevice::NoError)
                {
                    const QModbusDataUnit unit = reply->result();
                    this->otherMap->readCurrentPageAi_Result(QModbusDataUnit::HoldingRegisters, readAddress, unit.values());
                }
                reply->deleteLater(); });
            }
            else
            {
                delete reply;
            }
        }
        else
        {
            qDebug() << "Read Current Page error: " << modbusDevice->errorString();
        }
        // read encoder
        readAddress = this->otherMap->get_read_encoder_addr();
        readCount = this->otherMap->get_read_encoder_num();
        // 读取保持寄存器
        readCurrentPage = QModbusDataUnit(QModbusDataUnit::HoldingRegisters, readAddress, readCount);
        if (auto *reply = modbusDevice->sendReadRequest(readCurrentPage, 1))
        {
            if (!reply->isFinished())
            {
                connect(reply, &QModbusReply::finished, this, [this, reply, readAddress, readCount]()
                        {
                if (reply->error() == QModbusDevice::NoError)
                {
                    const QModbusDataUnit unit = reply->result();
                    this->otherMap->readCurrentPageEncoder_Result(QModbusDataUnit::HoldingRegisters, readAddress, unit.values());
                }
                reply->deleteLater(); });
            }
            else
            {
                delete reply;
            }
        }
        else
        {
            qDebug() << "Read Current Page error: " << modbusDevice->errorString();
        }
        // read modbus rtu slave
        readAddress = this->otherMap->get_read_modbusRtuSlaveParam_addr();
        readCount = this->otherMap->get_read_modbusRtuSlaveParam_num();
        // 读取保持寄存器
        readCurrentPage = QModbusDataUnit(QModbusDataUnit::HoldingRegisters, readAddress, readCount);
        if (auto *reply = modbusDevice->sendReadRequest(readCurrentPage, 1))
        {
            if (!reply->isFinished())
            {
                connect(reply, &QModbusReply::finished, this, [this, reply, readAddress, readCount]()
                        {
                if (reply->error() == QModbusDevice::NoError)
                {
                    const QModbusDataUnit unit = reply->result();
                    this->otherMap->readCurrentPageModbusRtuSlaveParam_Result(QModbusDataUnit::HoldingRegisters, readAddress, unit.values());
                }
                reply->deleteLater(); });
            }
            else
            {
                delete reply;
            }
        }
        else
        {
            qDebug() << "Read Current Page error: " << modbusDevice->errorString();
        }
    }
}

/**
 * @brief 读取全部工程参数按钮
 */
void MainWindow::on_pushButton_clicked()
{
    // 读取全部工程参数
    // 1 料位延时
    readHDRegisters(1, MDBS_HD_MATERIAL_DELAY + MODBUS_RTU_HD_REG_OFFSET, 1);
    // 2 齿轮比
    readHDRegisters(1, MDBS_HD_GEAR_RATIO + MODBUS_RTU_HD_REG_OFFSET, 2);
    // 3 包箱总长度
    readHDRegisters(1, MDBS_HD_BOX_TOTAL_LEN + MODBUS_RTU_HD_REG_OFFSET, 1);
    // 4 打包长度
    readHDRegisters(1, MDBS_HD_BOX_LEN + MODBUS_RTU_HD_REG_OFFSET, 1);
    // 后退低压位置设定
    readHDRegisters(1, MDBS_HD_BACKWARD_LOW_PRESSURE_POS + MODBUS_RTU_HD_REG_OFFSET, 1);
    // 出包长度设定
    readHDRegisters(1, MDBS_HD_OUT_BOX_LEN + MODBUS_RTU_HD_REG_OFFSET, 1);
    // 后退关门长度
    readHDRegisters(1, MDBS_HD_BACKWARD_CLOSE_DOOR_LEN + MODBUS_RTU_HD_REG_OFFSET, 1);
    // 前进行走长度
    readHDRegisters(1, MDBS_HD_FORWARD_WALK_LEN + MODBUS_RTU_HD_REG_OFFSET, 1);
    // 温度上限
    readHDRegisters(1, MDBS_HD_TEMP_MAXLIMIT + MODBUS_RTU_HD_REG_OFFSET, 1);
    // 温度下限
    readHDRegisters(1, MDBS_HD_TEMP_MINLIMIT + MODBUS_RTU_HD_REG_OFFSET, 1);
    // 前进压力保护计时
    readHDRegisters(1, MDBS_HD_PRESSURE_FORWARD_PROTECT_TIME + MODBUS_RTU_HD_REG_OFFSET, 1);
    // 料满延时
    readHDRegisters(1, MDBS_HD_MATERIAL_FULL_DELAY + MODBUS_RTU_HD_REG_OFFSET, 1);
    // 运行时间 秒
    readHDRegisters(1, MDBS_HD_RUNTIME_S + MODBUS_RTU_HD_REG_OFFSET, 1);
    // 运行时间 分
    readHDRegisters(1, MDBS_HD_RUNTIME_MIN + MODBUS_RTU_HD_REG_OFFSET, 1);
    // 运行时间 时
    readHDRegisters(1, MDBS_HD_RUNTIME_H + MODBUS_RTU_HD_REG_OFFSET, 1);
    // 总运行时间 时
    readHDRegisters(1, MDBS_HD_RUNTIME_TOTAL_H + MODBUS_RTU_HD_REG_OFFSET, 1);
    // 运行时间激活
    readHDRegisters(1, MDBS_HD_RUNTIME_ACTIVATE_H + MODBUS_RTU_HD_REG_OFFSET, 1);
    // 运行时间剩余
    readHDRegisters(1, MDBS_HD_RUNTIME_REMAIN_H + MODBUS_RTU_HD_REG_OFFSET, 1);
    // 快慢压力
    readHDRegisters(1, MDBS_HD_PRESSURE_FASTORLOW + MODBUS_RTU_HD_REG_OFFSET, 2);
    // 第一次预压次数
    readHDRegisters(1, MDBS_HD_FIRST_PRESSURE_COUNT + MODBUS_RTU_HD_REG_OFFSET, 1);
    // 第二次预压次数
    readHDRegisters(1, MDBS_HD_SECOND_PRESSURE_COUNT + MODBUS_RTU_HD_REG_OFFSET, 1);
    // 主缸前进压力设定
    readHDRegisters(1, MDBS_HD_PRESSURE_MAINCYLINDER_FORWARD + MODBUS_RTU_HD_REG_OFFSET, 2);
    // 最高保护压力停止
    readHDRegisters(1, MDBS_HD_PRESSURE_MAXPROTECT_STOP + MODBUS_RTU_HD_REG_OFFSET, 2);
    // 主缸后退压力保护
    readHDRegisters(1, MDBS_HD_PRESSURE_MAINCYLINDER_BACKWARD + MODBUS_RTU_HD_REG_OFFSET, 2);
    // 泄压延时时间
    readHDRegisters(1, MDBS_HD_PRESSURE_RELIEF_DELAY + MODBUS_RTU_HD_REG_OFFSET, 1);
    // 主缸后退计时
    readHDRegisters(1, MDBS_HD_MAINCYLINDER_BACKWARD_PROTECT_TIME + MODBUS_RTU_HD_REG_OFFSET, 1);
    // 预压行走长度设定
    readHDRegisters(1, MDBS_HD_PRESSURE_WALK_LEN + MODBUS_RTU_HD_REG_OFFSET, 1);
    // 第一次预压次数设定
    readHDRegisters(1, MDBS_HD_FIRST_PRESSURE_COUNT_SET + MODBUS_RTU_HD_REG_OFFSET, 1);
    // 第二次预压次数设定
    readHDRegisters(1, MDBS_HD_SECOND_PRESSURE_COUNT_SET + MODBUS_RTU_HD_REG_OFFSET, 1);
    // 第三次预压次数设定
    readHDRegisters(1, MDBS_HD_THIRD_PRESSURE_COUNT_SET + MODBUS_RTU_HD_REG_OFFSET, 1);
}

/**
 * @brief 设置单个参数按钮
 */
void MainWindow::on_pushButton_setone_clicked()
{
    // 获取tabwidget 当前选中的行和列
    int row = ui->tableWidget_projectPar->currentRow();
    int col = ui->tableWidget_projectPar->currentColumn();
    col = 1;
    switch (row)
    {
    case 0: // 料位延时
    {
        // 获取lineEdit的值
        QWidget *widget = ui->tableWidget_projectPar->cellWidget(row, col);
        QLineEdit *lineEdit = qobject_cast<QLineEdit *>(widget);
        if (lineEdit)
        {
            // 获取lineEdit的值
            int value = lineEdit->text().toInt();
            // 写入寄存器
            QModbusDataUnit Data(QModbusDataUnit::HoldingRegisters, MDBS_HD_MATERIAL_DELAY + MODBUS_RTU_HD_REG_OFFSET, 1);
            Data.setValue(0, value);
            writeHDRegisters(1, Data);
        }
    }
    break;
    case 1: // 齿轮比
    {
        QWidget *widget = ui->tableWidget_projectPar->cellWidget(row, col);
        QLineEdit *lineEdit = qobject_cast<QLineEdit *>(widget);
        if (lineEdit)
        {
            float gear_ratio = lineEdit->text().toFloat();
            uint16_t gear_ratio_c[2];
            memcpy(gear_ratio_c, &gear_ratio, 4);
            // 写入寄存器
            QModbusDataUnit Data(QModbusDataUnit::HoldingRegisters, MDBS_HD_GEAR_RATIO + MODBUS_RTU_HD_REG_OFFSET, 2);
            Data.setValue(0, gear_ratio_c[0]);
            Data.setValue(1, gear_ratio_c[1]);
            writeHDRegisters(1, Data);
        }
    }
    break;
    case 2: // 箱体总长
    {
        QWidget *widget = ui->tableWidget_projectPar->cellWidget(row, col);
        QLineEdit *lineEdit = qobject_cast<QLineEdit *>(widget);
        if (lineEdit)
        {
            int value = lineEdit->text().toInt();
            // 写入寄存器
            QModbusDataUnit Data(QModbusDataUnit::HoldingRegisters, MDBS_HD_BOX_TOTAL_LEN + MODBUS_RTU_HD_REG_OFFSET, 1);
            Data.setValue(0, value);
            writeHDRegisters(1, Data);
        }
    }
    break;
    case 3: // 打包长度
    {
        QWidget *widget = ui->tableWidget_projectPar->cellWidget(row, col);
        QLineEdit *lineEdit = qobject_cast<QLineEdit *>(widget);
        if (lineEdit)
        {
            int value = lineEdit->text().toInt();
            // 写入寄存器
            QModbusDataUnit Data(QModbusDataUnit::HoldingRegisters, MDBS_HD_BOX_LEN + MODBUS_RTU_HD_REG_OFFSET, 1);
            Data.setValue(0, value);
            writeHDRegisters(1, Data);
        }
    }
    break;
    case 4: // 后退低压位置设定
    {
        QWidget *widget = ui->tableWidget_projectPar->cellWidget(row, col);
        QLineEdit *lineEdit = qobject_cast<QLineEdit *>(widget);
        if (lineEdit)
        {
            int value = lineEdit->text().toInt();
            // 写入寄存器
            QModbusDataUnit Data(QModbusDataUnit::HoldingRegisters, MDBS_HD_BACKWARD_LOW_PRESSURE_POS + MODBUS_RTU_HD_REG_OFFSET, 1);
            Data.setValue(0, value);
            writeHDRegisters(1, Data);
        }
    }
    break;
    case 5: // 出包长度设定
    {
        QWidget *widget = ui->tableWidget_projectPar->cellWidget(row, col);
        QLineEdit *lineEdit = qobject_cast<QLineEdit *>(widget);
        if (lineEdit)
        {
            int value = lineEdit->text().toInt();
            // 写入寄存器
            QModbusDataUnit Data(QModbusDataUnit::HoldingRegisters, MDBS_HD_OUT_BOX_LEN + MODBUS_RTU_HD_REG_OFFSET, 1);
            Data.setValue(0, value);
            writeHDRegisters(1, Data);
        }
    }
    break;
    case 6: // 后退关门长度
    {
        QWidget *widget = ui->tableWidget_projectPar->cellWidget(row, col);
        QLineEdit *lineEdit = qobject_cast<QLineEdit *>(widget);
        if (lineEdit)
        {
            int value = lineEdit->text().toInt();
            // 写入寄存器
            QModbusDataUnit Data(QModbusDataUnit::HoldingRegisters, MDBS_HD_BACKWARD_CLOSE_DOOR_LEN + MODBUS_RTU_HD_REG_OFFSET, 1);
            Data.setValue(0, value);
            writeHDRegisters(1, Data);
        }
    }
    break;
    case 7: // 前进行走长度
    {
        QWidget *widget = ui->tableWidget_projectPar->cellWidget(row, col);
        QLineEdit *lineEdit = qobject_cast<QLineEdit *>(widget);
        if (lineEdit)
        {
            int value = lineEdit->text().toInt();
            // 写入寄存器
            QModbusDataUnit Data(QModbusDataUnit::HoldingRegisters, MDBS_HD_FORWARD_WALK_LEN + MODBUS_RTU_HD_REG_OFFSET, 1);
            Data.setValue(0, value);
            writeHDRegisters(1, Data);
        }
    }
    break;
    case 8: // 温度上限
    {
        QWidget *widget = ui->tableWidget_projectPar->cellWidget(row, col);
        QLineEdit *lineEdit = qobject_cast<QLineEdit *>(widget);
        if (lineEdit)
        {
            int value = lineEdit->text().toInt();
            // 写入寄存器
            QModbusDataUnit Data(QModbusDataUnit::HoldingRegisters, MDBS_HD_TEMP_MAXLIMIT + MODBUS_RTU_HD_REG_OFFSET, 1);
            Data.setValue(0, value);
            writeHDRegisters(1, Data);
        }
    }
    break;
    case 9: // 温度下限
    {
        QWidget *widget = ui->tableWidget_projectPar->cellWidget(row, col);
        QLineEdit *lineEdit = qobject_cast<QLineEdit *>(widget);
        if (lineEdit)
        {
            int value = lineEdit->text().toInt();
            // 写入寄存器
            QModbusDataUnit Data(QModbusDataUnit::HoldingRegisters, MDBS_HD_TEMP_MINLIMIT + MODBUS_RTU_HD_REG_OFFSET, 1);
            Data.setValue(0, value);
            writeHDRegisters(1, Data);
        }
    }
    break;
    case 10: // 前进保护时间 前进压力保护计时
    {
        QWidget *widget = ui->tableWidget_projectPar->cellWidget(row, col);
        QLineEdit *lineEdit = qobject_cast<QLineEdit *>(widget);
        if (lineEdit)
        {
            int value = lineEdit->text().toInt();
            // 写入寄存器
            QModbusDataUnit Data(QModbusDataUnit::HoldingRegisters, MDBS_HD_PRESSURE_FORWARD_PROTECT_TIME + MODBUS_RTU_HD_REG_OFFSET, 1);
            Data.setValue(0, value);
            writeHDRegisters(1, Data);
        }
    }
    break;
    case 11: // 料满延时
    {
        QWidget *widget = ui->tableWidget_projectPar->cellWidget(row, col);
        QLineEdit *lineEdit = qobject_cast<QLineEdit *>(widget);
        if (lineEdit)
        {
            int value = lineEdit->text().toInt();
            // 写入寄存器
            QModbusDataUnit Data(QModbusDataUnit::HoldingRegisters, MDBS_HD_MATERIAL_FULL_DELAY + MODBUS_RTU_HD_REG_OFFSET, 1);
            Data.setValue(0, value);
            writeHDRegisters(1, Data);
        }
    }
    break;
    case 12: // 运行时间 秒
    {
        QWidget *widget = ui->tableWidget_projectPar->cellWidget(row, col);
        QLineEdit *lineEdit = qobject_cast<QLineEdit *>(widget);
        if (lineEdit)
        {
            int value = lineEdit->text().toInt();
            // 写入寄存器
            QModbusDataUnit Data(QModbusDataUnit::HoldingRegisters, MDBS_HD_RUNTIME_S + MODBUS_RTU_HD_REG_OFFSET, 1);
            Data.setValue(0, value);
            writeHDRegisters(1, Data);
        }
    }
    break;
    case 13: // 运行时间 分
    {
        QWidget *widget = ui->tableWidget_projectPar->cellWidget(row, col);
        QLineEdit *lineEdit = qobject_cast<QLineEdit *>(widget);
        if (lineEdit)
        {
            int value = lineEdit->text().toInt();
            // 写入寄存器
            QModbusDataUnit Data(QModbusDataUnit::HoldingRegisters, MDBS_HD_RUNTIME_MIN + MODBUS_RTU_HD_REG_OFFSET, 1);
            Data.setValue(0, value);
            writeHDRegisters(1, Data);
        }
    }
    break;
    case 14: // 运行时间 时
    {
        QWidget *widget = ui->tableWidget_projectPar->cellWidget(row, col);
        QLineEdit *lineEdit = qobject_cast<QLineEdit *>(widget);
        if (lineEdit)
        {
            int value = lineEdit->text().toInt();
            // 写入寄存器
            QModbusDataUnit Data(QModbusDataUnit::HoldingRegisters, MDBS_HD_RUNTIME_H + MODBUS_RTU_HD_REG_OFFSET, 1);
            Data.setValue(0, value);
            writeHDRegisters(1, Data);
        }
    }
    break;
    case 15: // 总运行时间 时
    {
        QWidget *widget = ui->tableWidget_projectPar->cellWidget(row, col);
        QLineEdit *lineEdit = qobject_cast<QLineEdit *>(widget);
        if (lineEdit)
        {
            int value = lineEdit->text().toInt();
            // 写入寄存器
            QModbusDataUnit Data(QModbusDataUnit::HoldingRegisters, MDBS_HD_RUNTIME_TOTAL_H + MODBUS_RTU_HD_REG_OFFSET, 1);
            Data.setValue(0, value);
            writeHDRegisters(1, Data);
        }
    }
    break;
    case 16: // 运行时间激活
    {
        QWidget *widget = ui->tableWidget_projectPar->cellWidget(row, col);
        QLineEdit *lineEdit = qobject_cast<QLineEdit *>(widget);
        if (lineEdit)
        {
            int value = lineEdit->text().toInt();
            // 写入寄存器
            QModbusDataUnit Data(QModbusDataUnit::HoldingRegisters, MDBS_HD_RUNTIME_ACTIVATE_H + MODBUS_RTU_HD_REG_OFFSET, 1);
            Data.setValue(0, value);
            writeHDRegisters(1, Data);
        }
    }
    break;
    case 17: // 运行时间剩余
    {
        QWidget *widget = ui->tableWidget_projectPar->cellWidget(row, col);
        QLineEdit *lineEdit = qobject_cast<QLineEdit *>(widget);
        if (lineEdit)
        {
            int value = lineEdit->text().toInt();
            // 写入寄存器
            QModbusDataUnit Data(QModbusDataUnit::HoldingRegisters, MDBS_HD_RUNTIME_REMAIN_H + MODBUS_RTU_HD_REG_OFFSET, 1);
            Data.setValue(0, value);
            writeHDRegisters(1, Data);
        }
    }
    break;
    case 18: // 快慢压力
    {
        QWidget *widget = ui->tableWidget_projectPar->cellWidget(row, col);
        QLineEdit *lineEdit = qobject_cast<QLineEdit *>(widget);
        if (lineEdit)
        {
            float pressure = lineEdit->text().toFloat();
            uint16_t pressure_c[2];
            memcpy(pressure_c, &pressure, 4);
            // 写入寄存器
            QModbusDataUnit Data(QModbusDataUnit::HoldingRegisters, MDBS_HD_PRESSURE_FASTORLOW + MODBUS_RTU_HD_REG_OFFSET, 2);
            Data.setValue(0, pressure_c[0]);
            Data.setValue(1, pressure_c[1]);
            writeHDRegisters(1, Data);
        }
    }
    break;
    case 19: // 第一次预压次数
    {
        QWidget *widget = ui->tableWidget_projectPar->cellWidget(row, col);
        QLineEdit *lineEdit = qobject_cast<QLineEdit *>(widget);
        if (lineEdit)
        {
            int value = lineEdit->text().toInt();
            // 写入寄存器
            QModbusDataUnit Data(QModbusDataUnit::HoldingRegisters, MDBS_HD_FIRST_PRESSURE_COUNT + MODBUS_RTU_HD_REG_OFFSET, 1);
            Data.setValue(0, value);
            writeHDRegisters(1, Data);
        }
    }
    break;
    case 20: // 第二次预压次数
    {
        QWidget *widget = ui->tableWidget_projectPar->cellWidget(row, col);
        QLineEdit *lineEdit = qobject_cast<QLineEdit *>(widget);
        if (lineEdit)
        {
            int value = lineEdit->text().toInt();
            // 写入寄存器
            QModbusDataUnit Data(QModbusDataUnit::HoldingRegisters, MDBS_HD_SECOND_PRESSURE_COUNT + MODBUS_RTU_HD_REG_OFFSET, 1);
            Data.setValue(0, value);
            writeHDRegisters(1, Data);
        }
    }
    break;
    case 21: // 主缸前进压力设定
    {
        QWidget *widget = ui->tableWidget_projectPar->cellWidget(row, col);
        QLineEdit *lineEdit = qobject_cast<QLineEdit *>(widget);
        if (lineEdit)
        {
            float pressure_maincylinder_forward = lineEdit->text().toFloat();
            uint16_t pressure_maincylinder_forward_c[2];
            memcpy(pressure_maincylinder_forward_c, &pressure_maincylinder_forward, 4);
            // 写入寄存器
            QModbusDataUnit Data(QModbusDataUnit::HoldingRegisters, MDBS_HD_PRESSURE_MAINCYLINDER_FORWARD + MODBUS_RTU_HD_REG_OFFSET, 2);
            Data.setValue(0, pressure_maincylinder_forward_c[0]);
            Data.setValue(1, pressure_maincylinder_forward_c[1]);
            writeHDRegisters(1, Data);
        }
    }
    break;
    case 22: // 最高保护压力停止
    {
        QWidget *widget = ui->tableWidget_projectPar->cellWidget(row, col);
        QLineEdit *lineEdit = qobject_cast<QLineEdit *>(widget);
        if (lineEdit)
        {
            float pressure_maxprotect_stop = lineEdit->text().toFloat();
            uint16_t pressure_maxprotect_stop_c[2];
            memcpy(pressure_maxprotect_stop_c, &pressure_maxprotect_stop, 4);
            // 写入寄存器
            QModbusDataUnit Data(QModbusDataUnit::HoldingRegisters, MDBS_HD_PRESSURE_MAXPROTECT_STOP + MODBUS_RTU_HD_REG_OFFSET, 2);
            Data.setValue(0, pressure_maxprotect_stop_c[0]);
            Data.setValue(1, pressure_maxprotect_stop_c[1]);
            writeHDRegisters(1, Data);
        }
    }
    break;
    case 23: // 主缸后退压力保护
    {
        QWidget *widget = ui->tableWidget_projectPar->cellWidget(row, col);
        QLineEdit *lineEdit = qobject_cast<QLineEdit *>(widget);
        if (lineEdit)
        {
            float pressure_maincylinder_backward = lineEdit->text().toFloat();
            uint16_t pressure_maincylinder_backward_c[2];
            memcpy(pressure_maincylinder_backward_c, &pressure_maincylinder_backward, 4);
            // 写入寄存器
            QModbusDataUnit Data(QModbusDataUnit::HoldingRegisters, MDBS_HD_PRESSURE_MAINCYLINDER_BACKWARD + MODBUS_RTU_HD_REG_OFFSET, 2);
            Data.setValue(0, pressure_maincylinder_backward_c[0]);
            Data.setValue(1, pressure_maincylinder_backward_c[1]);
            writeHDRegisters(1, Data);
        }
    }
    break;
    case 24: // 泄压延时时间
    {
        QWidget *widget = ui->tableWidget_projectPar->cellWidget(row, col);
        QLineEdit *lineEdit = qobject_cast<QLineEdit *>(widget);
        if (lineEdit)
        {
            int value = lineEdit->text().toInt();
            // 写入寄存器
            QModbusDataUnit Data(QModbusDataUnit::HoldingRegisters, MDBS_HD_PRESSURE_RELIEF_DELAY + MODBUS_RTU_HD_REG_OFFSET, 1);
            Data.setValue(0, value);
            writeHDRegisters(1, Data);
        }
    }
    break;
    case 25: // 主缸后退计时
    {
        QWidget *widget = ui->tableWidget_projectPar->cellWidget(row, col);
        QLineEdit *lineEdit = qobject_cast<QLineEdit *>(widget);
        if (lineEdit)
        {
            int value = lineEdit->text().toInt();
            // 写入寄存器
            QModbusDataUnit Data(QModbusDataUnit::HoldingRegisters, MDBS_HD_MAINCYLINDER_BACKWARD_PROTECT_TIME + MODBUS_RTU_HD_REG_OFFSET, 1);
            Data.setValue(0, value);
            writeHDRegisters(1, Data);
        }
    }
    break;
    case 26: // 预压行走长度设定
    {
        QWidget *widget = ui->tableWidget_projectPar->cellWidget(row, col);
        QLineEdit *lineEdit = qobject_cast<QLineEdit *>(widget);
        if (lineEdit)
        {
            int value = lineEdit->text().toInt();
            // 写入寄存器
            QModbusDataUnit Data(QModbusDataUnit::HoldingRegisters, MDBS_HD_PRESSURE_WALK_LEN + MODBUS_RTU_HD_REG_OFFSET, 1);
            Data.setValue(0, value);
            writeHDRegisters(1, Data);
        }
    }
    break;
    case 27: // 第一次预压次数设定
    {
        QWidget *widget = ui->tableWidget_projectPar->cellWidget(row, col);
        QLineEdit *lineEdit = qobject_cast<QLineEdit *>(widget);
        if (lineEdit)
        {
            int value = lineEdit->text().toInt();
            // 写入寄存器
            QModbusDataUnit Data(QModbusDataUnit::HoldingRegisters, MDBS_HD_FIRST_PRESSURE_COUNT_SET + MODBUS_RTU_HD_REG_OFFSET, 1);
            Data.setValue(0, value);
            writeHDRegisters(1, Data);
        }
    }
    break;
    case 28: // 第二次预压次数设定
    {
        QWidget *widget = ui->tableWidget_projectPar->cellWidget(row, col);
        QLineEdit *lineEdit = qobject_cast<QLineEdit *>(widget);
        if (lineEdit)
        {
            int value = lineEdit->text().toInt();
            // 写入寄存器
            QModbusDataUnit Data(QModbusDataUnit::HoldingRegisters, MDBS_HD_SECOND_PRESSURE_COUNT_SET + MODBUS_RTU_HD_REG_OFFSET, 1);
            Data.setValue(0, value);
            writeHDRegisters(1, Data);
        }
    }
    break;
    case 29: // 第三次预压次数设定
    {
        QWidget *widget = ui->tableWidget_projectPar->cellWidget(row, col);
        QLineEdit *lineEdit = qobject_cast<QLineEdit *>(widget);
        if (lineEdit)
        {
            int value = lineEdit->text().toInt();
            // 写入寄存器
            QModbusDataUnit Data(QModbusDataUnit::HoldingRegisters, MDBS_HD_THIRD_PRESSURE_COUNT_SET + MODBUS_RTU_HD_REG_OFFSET, 1);
            Data.setValue(0, value);
            writeHDRegisters(1, Data);
        }
    }
    break;
    default:
        break;
    }
}
