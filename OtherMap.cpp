#include "OtherMap.h"

#include <QComboBox>
#include <QLineEdit>

OtherMap::OtherMap(QTableWidget *tableWidget)
{
  this->tableWidget = tableWidget;
  initTableWidget();
}

OtherMap::~OtherMap()
{
}

/**
 * @brief 初始化表格
 * @param none
 * @return none
 */
void OtherMap::initTableWidget()
{
  // 设置30行
  tableWidget->setRowCount(30);
  // 设置3列
  tableWidget->setColumnCount(3);
  // 设置表头
  QStringList header;
  header << "名称" << "功能" << "其他";
  tableWidget->setHorizontalHeaderLabels(header);
  // 依次向表格中添加元素
  // 设置AI映射 油泵压力输入引脚
  QTableWidgetItem *item_oilPumpPressure = new QTableWidgetItem(QString("油泵压力通道"));
  tableWidget->setItem(0, 0, item_oilPumpPressure);
  QComboBox *comboBox_oilPumpPressure = new QComboBox();
  comboBox_oilPumpPressure->addItem("无");
  comboBox_oilPumpPressure->addItem("AI1");
  comboBox_oilPumpPressure->addItem("AI2");
  comboBox_oilPumpPressure->addItem("AI3");
  comboBox_oilPumpPressure->addItem("AI4");
  comboBox_oilPumpPressure->addItem("AI5");
  comboBox_oilPumpPressure->addItem("AI6");
  tableWidget->setCellWidget(0, 1, comboBox_oilPumpPressure);
  // 设置AI映射 温度输入引脚
  QTableWidgetItem *item_temperature = new QTableWidgetItem(QString("温度通道"));
  tableWidget->setItem(1, 0, item_temperature);
  QComboBox *comboBox_temperature = new QComboBox();
  comboBox_temperature->addItem("无");
  comboBox_temperature->addItem("AI1");
  comboBox_temperature->addItem("AI2");
  comboBox_temperature->addItem("AI3");
  comboBox_temperature->addItem("AI4");
  comboBox_temperature->addItem("AI5");
  comboBox_temperature->addItem("AI6");
  tableWidget->setCellWidget(1, 1, comboBox_temperature);
  // 设置AI映射 电压输入引脚
  QTableWidgetItem *item_voltage = new QTableWidgetItem(QString("电压通道"));
  tableWidget->setItem(2, 0, item_voltage);
  QComboBox *comboBox_voltage = new QComboBox();
  comboBox_voltage->addItem("无");
  comboBox_voltage->addItem("AI1");
  comboBox_voltage->addItem("AI2");
  comboBox_voltage->addItem("AI3");
  comboBox_voltage->addItem("AI4");
  comboBox_voltage->addItem("AI5");
  comboBox_voltage->addItem("AI6");
  tableWidget->setCellWidget(2, 1, comboBox_voltage);
  // 设置AI映射 电流输入引脚
  QTableWidgetItem *item_current = new QTableWidgetItem(QString("电流通道"));
  tableWidget->setItem(3, 0, item_current);
  QComboBox *comboBox_current = new QComboBox();
  comboBox_current->addItem("无");
  comboBox_current->addItem("AI1");
  comboBox_current->addItem("AI2");
  comboBox_current->addItem("AI3");
  comboBox_current->addItem("AI4");
  comboBox_current->addItem("AI5");
  comboBox_current->addItem("AI6");
  tableWidget->setCellWidget(3, 1, comboBox_current);
  // 设置modbusRtuSlaveParam 映射 从机地址
  QTableWidgetItem *item_slave_address = new QTableWidgetItem(QString("从机地址"));
  tableWidget->setItem(4, 0, item_slave_address);
  QLineEdit *lineEdit_slave_address = new QLineEdit();
  lineEdit_slave_address->setPlaceholderText("1"); // 设置默认值
  tableWidget->setCellWidget(4, 1, lineEdit_slave_address);
  // 设置modbusRtuSlaveParam 映射 波特率
  QTableWidgetItem *item_baud_rate = new QTableWidgetItem(QString("波特率"));
  tableWidget->setItem(5, 0, item_baud_rate);
  QLineEdit *lineEdit_baud_rate = new QLineEdit();
  lineEdit_baud_rate->setPlaceholderText("9600"); // 设置默认值
  tableWidget->setCellWidget(5, 1, lineEdit_baud_rate);
  // 设置modbusRtuSlaveParam 映射 数据位
  QTableWidgetItem *item_data_bits = new QTableWidgetItem(QString("数据位"));
  tableWidget->setItem(6, 0, item_data_bits);
  QLineEdit *lineEdit_data_bits = new QLineEdit();
  lineEdit_data_bits->setPlaceholderText("8"); // 设置默认值
  tableWidget->setCellWidget(6, 1, lineEdit_data_bits);
  // 设置modbusRtuSlaveParam 映射 停止位
  QTableWidgetItem *item_stop_bits = new QTableWidgetItem(QString("停止位"));
  tableWidget->setItem(7, 0, item_stop_bits);
  QLineEdit *lineEdit_stop_bits = new QLineEdit();
  lineEdit_stop_bits->setPlaceholderText("1"); // 设置默认值
  tableWidget->setCellWidget(7, 1, lineEdit_stop_bits);
  // 设置modbusRtuSlaveParam 映射 校验位
  QTableWidgetItem *item_parity = new QTableWidgetItem(QString("校验位"));
  tableWidget->setItem(8, 0, item_parity);
  QComboBox *comboBox_parity = new QComboBox();
  comboBox_parity->addItem("无");
  comboBox_parity->addItem("奇校验");
  comboBox_parity->addItem("偶校验");
  tableWidget->setCellWidget(8, 1, comboBox_parity);
  // 设置编码器映射 编码器通道
  QTableWidgetItem *item_main_channel = new QTableWidgetItem(QString("编码器通道"));
  tableWidget->setItem(9, 0, item_main_channel);
  QComboBox *comboBox_main_channel = new QComboBox();
  comboBox_main_channel->addItem("无");
  comboBox_main_channel->addItem("CH1_IN17-18");
  comboBox_main_channel->addItem("CH2_IN19-20");
  comboBox_main_channel->addItem("CH3_IN21-22");
  tableWidget->setCellWidget(9, 1, comboBox_main_channel);
  QComboBox *comboBox_main_direction = new QComboBox();
  comboBox_main_direction->addItem("正转");
  comboBox_main_direction->addItem("反转");
  tableWidget->setCellWidget(9, 2, comboBox_main_direction);
}

/**
 * @brief 获取读取AI地址
 * @param none
 * @return uint16_t
 */
uint16_t OtherMap::get_read_ai_addr()
{
  size_t offset = offsetof(systemParam, aiMap);
  uint16_t addr = MODBUS_RTU_REG_SYSTEM_PARAM_START + static_cast<uint16_t>(offset);
  return addr;
}

/**
 * @brief 获取读取AI数量
 * @param none
 * @return uint16_t
 */
uint16_t OtherMap::get_read_ai_num()
{
  return sizeof(aiMap) / 2;
}

/**
 * @brief 获取读取编码器地址
 * @param none
 * @return uint16_t
 */
uint16_t OtherMap::get_read_encoder_addr()
{
  size_t offset = offsetof(systemParam, encoderMap);
  uint16_t addr = MODBUS_RTU_REG_SYSTEM_PARAM_START + static_cast<uint16_t>(offset);
  return addr;
}

/**
 * @brief 获取读取编码器数量
 * @param none
 * @return uint16_t
 */
uint16_t OtherMap::get_read_encoder_num()
{
  return sizeof(encoderMap) / 2;
}

/**
 * @brief 获取读取Modbus RTU Slave 参数地址
 * @param none
 * @return uint16_t
 */
uint16_t OtherMap::get_read_modbusRtuSlaveParam_addr()
{
  size_t offset = offsetof(systemParam, modbusRtuSlaveParam);
  uint16_t addr = MODBUS_RTU_REG_SYSTEM_PARAM_START + static_cast<uint16_t>(offset);
  return addr;
}

/**
 * @brief 获取读取Modbus RTU Slave 参数数量
 * @param none
 * @return uint16_t
 */
uint16_t OtherMap::get_read_modbusRtuSlaveParam_num()
{
  return sizeof(modbusRtuSlaveParam) / 2;
}

/**
 * @brief 读取当前页结果  Ai映射
 * @param table   读取的表
 * @param address 读取的地址
 * @param values  读取的值
 * @return none
 */
void OtherMap::readCurrentPageAi_Result(QModbusDataUnit::RegisterType table, int address, QVector<quint16> values)
{
  aiMap *new_aimap = new aiMap();
  if (values.size() == sizeof(aiMap) / 2)
  {
    memcpy(reinterpret_cast<uint8_t *>(new_aimap), reinterpret_cast<uint8_t *>(values.data()), sizeof(aiMap));
  }
  else
  {
    return;
  }
  // 依次修改表格中的元素
  // oilPumpPressure 油泵压力
  if (new_aimap->oilPumpPressure >= 0 && new_aimap->oilPumpPressure <= 6)
  {
    QComboBox *comboBox = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_aimap->oilPumpPressure, 1));
    comboBox->setCurrentIndex(1);
  }
  // temperature 温度
  if (new_aimap->temperature >= 0 && new_aimap->temperature <= 6)
  {
    QComboBox *comboBox = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_aimap->temperature, 1));
    comboBox->setCurrentIndex(2);
  }
  // voltage 电压
  if (new_aimap->voltage >= 0 && new_aimap->voltage <= 6)
  {
    QComboBox *comboBox = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_aimap->voltage, 1));
    comboBox->setCurrentIndex(3);
  }
  // current 电流
  if (new_aimap->current >= 0 && new_aimap->current <= 6)
  {
    QComboBox *comboBox = dynamic_cast<QComboBox *>(tableWidget->cellWidget(new_aimap->current, 1));
    comboBox->setCurrentIndex(4);
  }
}

/**
 * @brief 读取当前页结果  编码器映射
 * @param table   读取的表
 * @param address 读取的地址
 * @param values  读取的值
 * @return none
 */
void OtherMap::readCurrentPageEncoder_Result(QModbusDataUnit::RegisterType table, int address, QVector<quint16> values)
{
  encoderMap *new_encodermap = new encoderMap();
  if (values.size() == sizeof(encoderMap) / 2)
  {
    memcpy(reinterpret_cast<uint8_t *>(new_encodermap), reinterpret_cast<uint8_t *>(values.data()), sizeof(encoderMap));
  }
  else
  {
    return;
  }
  // 依次修改表格中的元素
  // main_channel 编码器通道
  if (new_encodermap->main_channel >= 0 && new_encodermap->main_channel <= 4)
  {
    QComboBox *comboBox = dynamic_cast<QComboBox *>(tableWidget->cellWidget(9, 1));
    comboBox->setCurrentIndex(new_encodermap->main_channel);
  }
  // main_direction 编码器方向
  if (new_encodermap->main_direction >= 0 && new_encodermap->main_direction <= 1)
  {
    QComboBox *comboBox = dynamic_cast<QComboBox *>(tableWidget->cellWidget(9, 2));
    comboBox->setCurrentIndex(new_encodermap->main_direction);
  }
}

/**
 * @brief 读取当前页结果  Modbus RTU Slave 参数
 * @param table   读取的表
 * @param address 读取的地址
 * @param values  读取的值
 * @return none
 */
void OtherMap::readCurrentPageModbusRtuSlaveParam_Result(QModbusDataUnit::RegisterType table, int address, QVector<quint16> values)
{
  modbusRtuSlaveParam *new_modbusRtuSlaveParam = new modbusRtuSlaveParam();
  if (values.size() == sizeof(modbusRtuSlaveParam) / 2)
  {
    memcpy(reinterpret_cast<uint8_t *>(new_modbusRtuSlaveParam), reinterpret_cast<uint8_t *>(values.data()), sizeof(modbusRtuSlaveParam));
  }
  else
  {
    return;
  }
  // 依次修改表格中的元素
  // address 从机地址
  if (new_modbusRtuSlaveParam->address >= 0 && new_modbusRtuSlaveParam->address <= 255)
  {
    QLineEdit *lineEdit = dynamic_cast<QLineEdit *>(tableWidget->cellWidget(4, 1));
    lineEdit->setText(QString::number(new_modbusRtuSlaveParam->address));
  }
  // baud_rate 波特率
  if (new_modbusRtuSlaveParam->baudRate >= 0 && new_modbusRtuSlaveParam->baudRate <= 115200)
  {
    QLineEdit *lineEdit = dynamic_cast<QLineEdit *>(tableWidget->cellWidget(5, 1));
    lineEdit->setText(QString::number(new_modbusRtuSlaveParam->baudRate));
  }
  // data_bits 数据位
  if (new_modbusRtuSlaveParam->dataBits >= 5 && new_modbusRtuSlaveParam->dataBits <= 8)
  {
    QLineEdit *lineEdit = dynamic_cast<QLineEdit *>(tableWidget->cellWidget(6, 1));
    lineEdit->setText(QString::number(new_modbusRtuSlaveParam->dataBits));
  }
  // stop_bits 停止位
  if (new_modbusRtuSlaveParam->stopBits >= 1 && new_modbusRtuSlaveParam->stopBits <= 2)
  {
    QLineEdit *lineEdit = dynamic_cast<QLineEdit *>(tableWidget->cellWidget(7, 1));
    lineEdit->setText(QString::number(new_modbusRtuSlaveParam->stopBits));
  }
  // parity 校验位
  if (new_modbusRtuSlaveParam->parity >= 0 && new_modbusRtuSlaveParam->parity <= 2)
  {
    QComboBox *comboBox = dynamic_cast<QComboBox *>(tableWidget->cellWidget(8, 1));
    comboBox->setCurrentIndex(new_modbusRtuSlaveParam->parity);
  }
}
