#include "DoMap.h"
#include <QComboBox>

DoMap::DoMap(QTableWidget *tableWidget)
{
  this->tableWidget = tableWidget;
  initTableWidget();
}

DoMap::~DoMap()
{
}

/**
 * @brief 初始化表格
 * @param none
 * @return none
 */
void DoMap::initTableWidget()
{
  // 设置30行
  tableWidget->setRowCount(30);
  // 设置3列
  tableWidget->setColumnCount(3);
  // 设置表头
  QStringList header;
  header << "名称" << "功能" << "电平有效性";
  tableWidget->setHorizontalHeaderLabels(header);
  // 依次向表格中添加元素
  for (int i = 0; i < 30; i++)
  {
    // 第一列 设置 label 名称O1-O30
    QTableWidgetItem *item = new QTableWidgetItem(QString("O%1").arg(i + 1));
    tableWidget->setItem(i, 0, item);
    // 第二列 设置 comboBox 功能
    QComboBox *comboBox = new QComboBox();
    comboBox->addItem("无");       // 0
    comboBox->addItem("高压");     // 1
    comboBox->addItem("低/高压");  // 2
    comboBox->addItem("开门");     // 3
    comboBox->addItem("关门");     // 4
    comboBox->addItem("前进");     // 5
    comboBox->addItem("后退");     // 6
    comboBox->addItem("输送带");   // 7
    comboBox->addItem("主泵1");    // 8
    comboBox->addItem("后退回油"); // 9
    comboBox->addItem("辅助回油"); // 10
    comboBox->addItem("前进回油"); // 11
    comboBox->addItem("小溢流阀"); // 12
    comboBox->addItem("捆报");     // 13
    comboBox->addItem("主泵2");    // 14
    comboBox->addItem("油温");     // 15
    tableWidget->setCellWidget(i, 1, comboBox);
    // 第三列 设置 comboBox 电平有效性
    QComboBox *comboBox2 = new QComboBox();
    comboBox2->addItem("0"); // 0
    comboBox2->addItem("1"); // 1
    tableWidget->setCellWidget(i, 2, comboBox2);
    // 1-8行设置为不可编辑
    if (i < 8)
    {
      item->setFlags(item->flags() & (~Qt::ItemIsEditable));
      comboBox->setEnabled(false);
      comboBox2->setEnabled(false);
    }
  }
}

/**
 * @brief get_read_do_addr 获取读取DO地址
 * @param none
 * @return uint16_t 读取DO地址
 */
uint16_t DoMap::get_read_do_addr()
{
  size_t offset = offsetof(systemParam, doMap);
  uint16_t addr = MODBUS_RTU_REG_SYSTEM_PARAM_START + static_cast<uint16_t>(offset);
  return addr;
}

/**
 * @brief get_read_do_num 获取读取DO数量
 * @param none
 * @return uint16_t 读取DO数量
 */
uint16_t DoMap::get_read_do_num()
{
  return sizeof(doMap) / 2;
}

/**
 * @brief readCurrentPage_Result 读取当前页结果
 * @param table   读取的表
 * @param address 读取的地址
 * @param values  读取的值
 * @return none
 */
void DoMap::readCurrentPage_Result(QModbusDataUnit::RegisterType table, int address, QVector<quint16> values)
{
  if (table == QModbusDataUnit::HoldingRegisters)
  {
    doMap *new_domap = new doMap();

    // 将数据写入 new_domap
    if (values.size() == sizeof(doMap) / 2)
    {
      memcpy(reinterpret_cast<uint8_t *>(new_domap), reinterpret_cast<uint8_t *>(values.data()), sizeof(doMap));
    }
    else
    {
      return;
    }
    // 依次修改表格中的元素
    // highPressure 高压
    if (new_domap->highPressure >= 0 && new_domap->highPressure <= 30)
    {
      QComboBox *comboBox = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_domap->highPressure - 1, 1));
      comboBox->setCurrentIndex(1);
      if (new_domap->highPressureLevel >= 0 && new_domap->highPressureLevel <= 1)
      {
        QComboBox *comboBox2 = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_domap->highPressure - 1, 2));
        comboBox2->setCurrentIndex(new_domap->highPressureLevel);
      }
    }
    // lowHighPressure 低/高压
    if (new_domap->lowHighPressure >= 0 && new_domap->lowHighPressure <= 30)
    {
      QComboBox *comboBox = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_domap->lowHighPressure - 1, 1));
      comboBox->setCurrentIndex(2);
      if (new_domap->lowHighPressureLevel >= 0 && new_domap->lowHighPressureLevel <= 1)
      {
        QComboBox *comboBox2 = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_domap->lowHighPressure - 1, 2));
        comboBox2->setCurrentIndex(new_domap->lowHighPressureLevel);
      }
    }
    // openDoor 开门
    if (new_domap->openDoor >= 0 && new_domap->openDoor <= 30)
    {
      QComboBox *comboBox = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_domap->openDoor - 1, 1));
      comboBox->setCurrentIndex(3);
      if (new_domap->openDoorLevel >= 0 && new_domap->openDoorLevel <= 1)
      {
        QComboBox *comboBox2 = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_domap->openDoor - 1, 2));
        comboBox2->setCurrentIndex(new_domap->openDoorLevel);
      }
    }
    // closeDoor 关门
    if (new_domap->closeDoor >= 0 && new_domap->closeDoor <= 30)
    {
      QComboBox *comboBox = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_domap->closeDoor - 1, 1));
      comboBox->setCurrentIndex(4);
      if (new_domap->closeDoorLevel >= 0 && new_domap->closeDoorLevel <= 1)
      {
        QComboBox *comboBox2 = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_domap->closeDoor - 1, 2));
        comboBox2->setCurrentIndex(new_domap->closeDoorLevel);
      }
    }
    // forward 前进
    if (new_domap->forward >= 0 && new_domap->forward <= 30)
    {
      QComboBox *comboBox = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_domap->forward - 1, 1));
      comboBox->setCurrentIndex(5);
      if (new_domap->forwardLevel >= 0 && new_domap->forwardLevel <= 1)
      {
        QComboBox *comboBox2 = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_domap->forward - 1, 2));
        comboBox2->setCurrentIndex(new_domap->forwardLevel);
      }
    }
    // back 后退
    if (new_domap->back >= 0 && new_domap->back <= 30)
    {
      QComboBox *comboBox = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_domap->back - 1, 1));
      comboBox->setCurrentIndex(6);
      if (new_domap->backLevel >= 0 && new_domap->backLevel <= 1)
      {
        QComboBox *comboBox2 = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_domap->back - 1, 2));
        comboBox2->setCurrentIndex(new_domap->backLevel);
      }
    }
    // conveyor 输送带
    if (new_domap->conveyor >= 0 && new_domap->conveyor <= 30)
    {
      QComboBox *comboBox = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_domap->conveyor - 1, 1));
      comboBox->setCurrentIndex(7);
      if (new_domap->conveyorLevel >= 0 && new_domap->conveyorLevel <= 1)
      {
        QComboBox *comboBox2 = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_domap->conveyor - 1, 2));
        comboBox2->setCurrentIndex(new_domap->conveyorLevel);
      }
    }
    // mainPump1 主泵1
    if (new_domap->mainPump1 >= 0 && new_domap->mainPump1 <= 30)
    {
      QComboBox *comboBox = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_domap->mainPump1 - 1, 1));
      comboBox->setCurrentIndex(8);
      if (new_domap->mainPump1Level >= 0 && new_domap->mainPump1Level <= 1)
      {
        QComboBox *comboBox2 = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_domap->mainPump1 - 1, 2));
        comboBox2->setCurrentIndex(new_domap->mainPump1Level);
      }
    }
    // backOil 后退回油
    if (new_domap->backOil >= 0 && new_domap->backOil <= 30)
    {
      QComboBox *comboBox = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_domap->backOil - 1, 1));
      comboBox->setCurrentIndex(9);
      if (new_domap->backOilLevel >= 0 && new_domap->backOilLevel <= 1)
      {
        QComboBox *comboBox2 = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_domap->backOil - 1, 2));
        comboBox2->setCurrentIndex(new_domap->backOilLevel);
      }
    }
    // auxiliaryBackOil 辅助回油
    if (new_domap->auxiliaryBackOil >= 0 && new_domap->auxiliaryBackOil <= 30)
    {
      QComboBox *comboBox = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_domap->auxiliaryBackOil - 1, 1));
      comboBox->setCurrentIndex(10);
      if (new_domap->auxiliaryBackOilLevel >= 0 && new_domap->auxiliaryBackOilLevel <= 1)
      {
        QComboBox *comboBox2 = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_domap->auxiliaryBackOil - 1, 2));
        comboBox2->setCurrentIndex(new_domap->auxiliaryBackOilLevel);
      }
    }
    // forwardBackOil 前进回油
    if (new_domap->forwardBackOil >= 0 && new_domap->forwardBackOil <= 30)
    {
      QComboBox *comboBox = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_domap->forwardBackOil - 1, 1));
      comboBox->setCurrentIndex(11);
      if (new_domap->forwardBackOilLevel >= 0 && new_domap->forwardBackOilLevel <= 1)
      {
        QComboBox *comboBox2 = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_domap->forwardBackOil - 1, 2));
        comboBox2->setCurrentIndex(new_domap->forwardBackOilLevel);
      }
    }
    // smallOverflowValve 小溢流阀
    if (new_domap->smallOverflowValve >= 0 && new_domap->smallOverflowValve <= 30)
    {
      QComboBox *comboBox = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_domap->smallOverflowValve - 1, 1));
      comboBox->setCurrentIndex(12);
      if (new_domap->smallOverflowValveLevel >= 0 && new_domap->smallOverflowValveLevel <= 1)
      {
        QComboBox *comboBox2 = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_domap->smallOverflowValve - 1, 2));
        comboBox2->setCurrentIndex(new_domap->smallOverflowValveLevel);
      }
    }
    // bale 捆报
    if (new_domap->bale >= 0 && new_domap->bale <= 30)
    {
      QComboBox *comboBox = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_domap->bale - 1, 1));
      comboBox->setCurrentIndex(13);
      if (new_domap->baleLevel >= 0 && new_domap->baleLevel <= 1)
      {
        QComboBox *comboBox2 = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_domap->bale - 1, 2));
        comboBox2->setCurrentIndex(new_domap->baleLevel);
      }
    }
    // mainPump2 主泵2
    if (new_domap->mainPump2 >= 0 && new_domap->mainPump2 <= 30)
    {
      QComboBox *comboBox = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_domap->mainPump2 - 1, 1));
      comboBox->setCurrentIndex(14);
      if (new_domap->mainPump2Level >= 0 && new_domap->mainPump2Level <= 1)
      {
        QComboBox *comboBox2 = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_domap->mainPump2 - 1, 2));
        comboBox2->setCurrentIndex(new_domap->mainPump2Level);
      }
    }
    // oilTemperature 油温
    if (new_domap->oilTemperature >= 0 && new_domap->oilTemperature <= 30)
    {
      QComboBox *comboBox = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_domap->oilTemperature - 1, 1));
      comboBox->setCurrentIndex(15);
      if (new_domap->oilTemperatureLevel >= 0 && new_domap->oilTemperatureLevel <= 1)
      {
        QComboBox *comboBox2 = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_domap->oilTemperature - 1, 2));
        comboBox2->setCurrentIndex(new_domap->oilTemperatureLevel);
      }
    }
    delete new_domap;
  }
}
