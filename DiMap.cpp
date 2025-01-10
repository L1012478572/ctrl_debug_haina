#include "DiMap.h"
#include <cstddef> // 包含 offsetof 宏
#include <QComboBox>

DiMap::DiMap(QTableWidget *tableWidget)
{
  this->tableWidget = tableWidget;
  initTableWidget();
}

DiMap::~DiMap()
{
}

/**
 * @brief 初始化表格
 * @param none
 * @return none
 */
void DiMap::initTableWidget()
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
    // 第一列 设置 label 名称IN1-IN30
    QTableWidgetItem *item = new QTableWidgetItem(QString("IN%1").arg(i + 1));
    tableWidget->setItem(i, 0, item);
    // 第二列 设置 comboBox 功能
    QComboBox *comboBox = new QComboBox();
    comboBox->addItem("无");          // 0
    comboBox->addItem("主泵1启停");   // 1
    comboBox->addItem("开门+出包");   // 2
    comboBox->addItem("自动");        // 3
    comboBox->addItem("半自动");      // 4
    comboBox->addItem("原点位置");    // 5
    comboBox->addItem("开门限位");    // 6
    comboBox->addItem("关门限位");    // 7
    comboBox->addItem("急停");        // 8
    comboBox->addItem("主泵1热保护"); // 9
    comboBox->addItem("关门+后退");   // 10
    comboBox->addItem("料位信号");    // 11
    comboBox->addItem("料满信号");    // 12
    comboBox->addItem("输送带手动");  // 13
    comboBox->addItem("输送带自动");  // 14
    comboBox->addItem("出包到位");    // 15
    comboBox->addItem("前进按钮");    // 16
    comboBox->addItem("后退按钮");    // 17
    comboBox->addItem("提门按钮");    // 18
    comboBox->addItem("关门按钮");    // 19
    comboBox->addItem("主泵2启停");   // 20
    comboBox->addItem("遥控停止");    // 21
    tableWidget->setCellWidget(i, 1, comboBox);
    // 第三列 设置 comboBox 电平有效性
    QComboBox *comboBox2 = new QComboBox();
    comboBox2->addItem("0");
    comboBox2->addItem("1");
    tableWidget->setCellWidget(i, 2, comboBox2);
    // 17-22行设置为不可编辑
    if (i >= 16 && i <= 21)
    {
      comboBox->setEnabled(false);
      comboBox2->setEnabled(false);
    }
  }
}

/**
 * @brief 获取读取DI地址
 * @param none
 * @return uint16_t 读取DI地址
 */
uint16_t DiMap::get_read_di_addr()
{
  size_t offset = offsetof(systemParam, diMap);
  uint16_t addr = MODBUS_RTU_REG_SYSTEM_PARAM_START + static_cast<uint16_t>(offset);
  return addr;
}

/**
 * @brief 获取读取DI数量
 * @param none
 * @return uint16_t 读取DI数量
 */
uint16_t DiMap::get_read_di_num()
{
  return sizeof(diMap) / 2;
}

/**
 * @brief 读取当前页结果
 * @param table     读取的表
 * @param address   读取的地址
 * @param values    读取的值
 * @return none
 */
void DiMap::readCurrentPage_Result(QModbusDataUnit::RegisterType table, int address, QVector<quint16> values)
{
  diMap *new_dimap = new diMap();
  if (values.size() == sizeof(diMap) / 2)
  {
    // 将数据写入 new_dimap
    memcpy(reinterpret_cast<uint8_t *>(new_dimap), reinterpret_cast<uint8_t *>(values.data()), sizeof(diMap));
  }
  else
  {
    return;
  }
  // 根据各个diMap的值设置表格中的值
  // 设置mainPump1StartStop引脚对应的列
  if (new_dimap->mainPump1StartStop >= 0 && new_dimap->mainPump1StartStop <= 30)
  {
    QComboBox *comboBox = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_dimap->mainPump1StartStop - 1, 1));
    comboBox->setCurrentIndex(1);
    if (new_dimap->mainPump1StartStopLevel >= 0 && new_dimap->mainPump1StartStopLevel <= 1)
    {
      QComboBox *comboBox2 = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_dimap->mainPump1StartStop - 1, 2));
      comboBox2->setCurrentIndex(new_dimap->mainPump1StartStopLevel);
    }
  }
  // 开门+出包
  if (new_dimap->openDoorPlusOutPackage >= 0 && new_dimap->openDoorPlusOutPackage <= 30)
  {
    QComboBox *comboBox = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_dimap->openDoorPlusOutPackage - 1, 1));
    comboBox->setCurrentIndex(2);
    if (new_dimap->openDoorPlusOutPackageLevel >= 0 && new_dimap->openDoorPlusOutPackageLevel <= 1)
    {
      QComboBox *comboBox2 = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_dimap->openDoorPlusOutPackage - 1, 2));
      comboBox2->setCurrentIndex(new_dimap->openDoorPlusOutPackageLevel);
    }
  }
  // 自动
  if (new_dimap->automatic >= 0 && new_dimap->automatic <= 30)
  {
    QComboBox *comboBox = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_dimap->automatic - 1, 1));
    comboBox->setCurrentIndex(3);
    if (new_dimap->automaticLevel >= 0 && new_dimap->automaticLevel <= 1)
    {
      QComboBox *comboBox2 = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_dimap->automatic - 1, 2));
      comboBox2->setCurrentIndex(new_dimap->automaticLevel);
    }
  }
  // 半自动
  if (new_dimap->semiAutomatic >= 0 && new_dimap->semiAutomatic <= 30)
  {
    QComboBox *comboBox = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_dimap->semiAutomatic - 1, 1));
    comboBox->setCurrentIndex(4);
    if (new_dimap->semiAutomaticLevel >= 0 && new_dimap->semiAutomaticLevel <= 1)
    {
      QComboBox *comboBox2 = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_dimap->semiAutomatic - 1, 2));
      comboBox2->setCurrentIndex(new_dimap->semiAutomaticLevel);
    }
  }
  // 原点位置
  if (new_dimap->originPosition >= 0 && new_dimap->originPosition <= 30)
  {
    QComboBox *comboBox = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_dimap->originPosition - 1, 1));
    comboBox->setCurrentIndex(5);
    if (new_dimap->originPositionLevel >= 0 && new_dimap->originPositionLevel <= 1)
    {
      QComboBox *comboBox2 = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_dimap->originPosition - 1, 2));
      comboBox2->setCurrentIndex(new_dimap->originPositionLevel);
    }
  }
  // 开门限位
  if (new_dimap->openDoorLimit >= 0 && new_dimap->openDoorLimit <= 30)
  {
    QComboBox *comboBox = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_dimap->openDoorLimit - 1, 1));
    comboBox->setCurrentIndex(6);
    if (new_dimap->openDoorLimitLevel >= 0 && new_dimap->openDoorLimitLevel <= 1)
    {
      QComboBox *comboBox2 = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_dimap->openDoorLimit - 1, 2));
      comboBox2->setCurrentIndex(new_dimap->openDoorLimitLevel);
    }
  }
  // 关门限位
  if (new_dimap->closeDoorLimit >= 0 && new_dimap->closeDoorLimit <= 30)
  {
    QComboBox *comboBox = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_dimap->closeDoorLimit - 1, 1));
    comboBox->setCurrentIndex(7);
    if (new_dimap->closeDoorLimitLevel >= 0 && new_dimap->closeDoorLimitLevel <= 1)
    {
      QComboBox *comboBox2 = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_dimap->closeDoorLimit - 1, 2));
      comboBox2->setCurrentIndex(new_dimap->closeDoorLimitLevel);
    }
  }
  // 急停
  if (new_dimap->emergencyStop >= 0 && new_dimap->emergencyStop <= 30)
  {
    QComboBox *comboBox = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_dimap->emergencyStop - 1, 1));
    comboBox->setCurrentIndex(8);
    if (new_dimap->emergencyStopLevel >= 0 && new_dimap->emergencyStopLevel <= 1)
    {
      QComboBox *comboBox2 = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_dimap->emergencyStop - 1, 2));
      comboBox2->setCurrentIndex(new_dimap->emergencyStopLevel);
    }
  }
  // mainPump1ThermalProtection 主泵1热保护
  if (new_dimap->mainPump1ThermalProtection >= 0 && new_dimap->mainPump1ThermalProtection <= 30)
  {
    QComboBox *comboBox = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_dimap->mainPump1ThermalProtection - 1, 1));
    comboBox->setCurrentIndex(9);
    if (new_dimap->mainPump1ThermalProtectionLevel >= 0 && new_dimap->mainPump1ThermalProtectionLevel <= 1)
    {
      QComboBox *comboBox2 = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_dimap->mainPump1ThermalProtection - 1, 2));
      comboBox2->setCurrentIndex(new_dimap->mainPump1ThermalProtectionLevel);
    }
  }
  // closeDoorPlusBack 关门+后退
  if (new_dimap->closeDoorPlusBack >= 0 && new_dimap->closeDoorPlusBack <= 30)
  {
    QComboBox *comboBox = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_dimap->closeDoorPlusBack - 1, 1));
    comboBox->setCurrentIndex(10);
    if (new_dimap->closeDoorPlusBackLevel >= 0 && new_dimap->closeDoorPlusBackLevel <= 1)
    {
      QComboBox *comboBox2 = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_dimap->closeDoorPlusBack - 1, 2));
      comboBox2->setCurrentIndex(new_dimap->closeDoorPlusBackLevel);
    }
  }
  // levelSignal 料位信号
  if (new_dimap->levelSignal >= 0 && new_dimap->levelSignal <= 30)
  {
    QComboBox *comboBox = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_dimap->levelSignal - 1, 1));
    comboBox->setCurrentIndex(11);
    if (new_dimap->levelSignalLevel >= 0 && new_dimap->levelSignalLevel <= 1)
    {
      QComboBox *comboBox2 = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_dimap->levelSignal - 1, 2));
      comboBox2->setCurrentIndex(new_dimap->levelSignalLevel);
    }
  }
  // fullMaterialSignal 料满信号
  if (new_dimap->fullMaterialSignal >= 0 && new_dimap->fullMaterialSignal <= 30)
  {
    QComboBox *comboBox = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_dimap->fullMaterialSignal - 1, 1));
    comboBox->setCurrentIndex(12);
    if (new_dimap->fullMaterialSignalLevel >= 0 && new_dimap->fullMaterialSignalLevel <= 1)
    {
      QComboBox *comboBox2 = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_dimap->fullMaterialSignal - 1, 2));
      comboBox2->setCurrentIndex(new_dimap->fullMaterialSignalLevel);
    }
  }
  // conveyorManual 输送带手动
  if (new_dimap->conveyorManual >= 0 && new_dimap->conveyorManual <= 30)
  {
    QComboBox *comboBox = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_dimap->conveyorManual - 1, 1));
    comboBox->setCurrentIndex(13);
    if (new_dimap->conveyorManualLevel >= 0 && new_dimap->conveyorManualLevel <= 1)
    {
      QComboBox *comboBox2 = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_dimap->conveyorManual - 1, 2));
      comboBox2->setCurrentIndex(new_dimap->conveyorManualLevel);
    }
  }
  // conveyorAutomatic 输送带自动
  if (new_dimap->conveyorAutomatic >= 0 && new_dimap->conveyorAutomatic <= 30)
  {
    QComboBox *comboBox = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_dimap->conveyorAutomatic - 1, 1));
    comboBox->setCurrentIndex(14);
    if (new_dimap->conveyorAutomaticLevel >= 0 && new_dimap->conveyorAutomaticLevel <= 1)
    {
      QComboBox *comboBox2 = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_dimap->conveyorAutomatic - 1, 2));
      comboBox2->setCurrentIndex(new_dimap->conveyorAutomaticLevel);
    }
  }
  // outPackageInPlace 出包到位
  if (new_dimap->outPackageInPlace >= 0 && new_dimap->outPackageInPlace <= 30)
  {
    QComboBox *comboBox = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_dimap->outPackageInPlace - 1, 1));
    comboBox->setCurrentIndex(15);
    if (new_dimap->outPackageInPlaceLevel >= 0 && new_dimap->outPackageInPlaceLevel <= 1)
    {
      QComboBox *comboBox2 = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_dimap->outPackageInPlace - 1, 2));
      comboBox2->setCurrentIndex(new_dimap->outPackageInPlaceLevel);
    }
  }
  // forwardButton 前进按钮
  if (new_dimap->forwardButton >= 0 && new_dimap->forwardButton <= 30)
  {
    QComboBox *comboBox = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_dimap->forwardButton - 1, 1));
    comboBox->setCurrentIndex(16);
    if (new_dimap->forwardButtonLevel >= 0 && new_dimap->forwardButtonLevel <= 1)
    {
      QComboBox *comboBox2 = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_dimap->forwardButton - 1, 2));
      comboBox2->setCurrentIndex(new_dimap->forwardButtonLevel);
    }
  }
  // backButton 后退按钮
  if (new_dimap->backButton >= 0 && new_dimap->backButton <= 30)
  {
    QComboBox *comboBox = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_dimap->backButton - 1, 1));
    comboBox->setCurrentIndex(17);
    if (new_dimap->backButtonLevel >= 0 && new_dimap->backButtonLevel <= 1)
    {
      QComboBox *comboBox2 = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_dimap->backButton - 1, 2));
      comboBox2->setCurrentIndex(new_dimap->backButtonLevel);
    }
  }
  // liftDoorButton 提门按钮
  if (new_dimap->liftDoorButton >= 0 && new_dimap->liftDoorButton <= 30)
  {
    QComboBox *comboBox = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_dimap->liftDoorButton - 1, 1));
    comboBox->setCurrentIndex(18);
    if (new_dimap->liftDoorButtonLevel >= 0 && new_dimap->liftDoorButtonLevel <= 1)
    {
      QComboBox *comboBox2 = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_dimap->liftDoorButton - 1, 2));
      comboBox2->setCurrentIndex(new_dimap->liftDoorButtonLevel);
    }
  }
  // closeDoorButton 关门按钮
  if (new_dimap->closeDoorButton >= 0 && new_dimap->closeDoorButton <= 30)
  {
    QComboBox *comboBox = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_dimap->closeDoorButton - 1, 1));
    comboBox->setCurrentIndex(19);
    if (new_dimap->closeDoorButtonLevel >= 0 && new_dimap->closeDoorButtonLevel <= 1)
    {
      QComboBox *comboBox2 = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_dimap->closeDoorButton - 1, 2));
      comboBox2->setCurrentIndex(new_dimap->closeDoorButtonLevel);
    }
  }
  // mainPump2StartStop 主泵2启停
  if (new_dimap->mainPump2StartStop >= 0 && new_dimap->mainPump2StartStop <= 30)
  {
    QComboBox *comboBox = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_dimap->mainPump2StartStop - 1, 1));
    comboBox->setCurrentIndex(20);
    if (new_dimap->mainPump2StartStopLevel >= 0 && new_dimap->mainPump2StartStopLevel <= 1)
    {
      QComboBox *comboBox2 = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_dimap->mainPump2StartStop - 1, 2));
      comboBox2->setCurrentIndex(new_dimap->mainPump2StartStopLevel);
    }
  }
  // remoteStopSignal 遥控停止
  if (new_dimap->remoteStopSignal >= 0 && new_dimap->remoteStopSignal <= 30)
  {
    QComboBox *comboBox = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_dimap->remoteStopSignal - 1, 1));
    comboBox->setCurrentIndex(21);
    if (new_dimap->remoteStopSignalLevel >= 0 && new_dimap->remoteStopSignalLevel <= 1)
    {
      QComboBox *comboBox2 = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_dimap->remoteStopSignal - 1, 2));
      comboBox2->setCurrentIndex(new_dimap->remoteStopSignalLevel);
    }
  }

  delete new_dimap;
}
