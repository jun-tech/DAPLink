# Keil环境搭建

- **CMSIS DAP Link 调试器**

![](.\images\IMG_20230618_151301.jpg)

- 调试器与STM32接线


![IMG_20230618_152229](.\images\IMG_20230618_152229.jpg)

- DAPLink连接电脑，识别不了尝试卸载设备再重插

  ![](.\images\devices.bmp)

- **Keil配置V5.38.0，安装compiler version5**

  打开nanoDAP-master\software\test\led_test例子led_test.uvprojx

  1. 安装compiler version5，安装包在百度网盘

     链接：https://pan.baidu.com/s/1i89-tnlr0O6jkvvcAHeZnw 
     提取码：083r

  2. 下载、解压到D:\Keil_v5\ARM\ARM_Compiler_5.06u7

     本人的Keil在D:\Keil_v5，为了方便管理，直接放在同级ARM目录

     ![](.\images\1.jpg)

  3. 添加编译ARM_v5版本

     ![](.\images\20230618154810.jpg)

     ![](.\images\20230618154947.jpg)

- **Keil5配置DAPLink调试器**

  ![](.\images\20230618160604.jpg)![](.\images\20230618160715.jpg)

- 最后按F7 Build构建，F8烧录，闪灯效果

  ![](.\images\1687076316887.jpg)

​		

# Arduino环境搭建

准备USB转串口调备及接线，烧录前先按下boot

![](.\images\ttl.jpg)



STM32有2个跳线帽

- 运行模式

  ![](.\images\run_state.jpg)

- 烧录模式（右侧下移跳线）

  ![](E:\stm32\images\fireupload.png)



1、Arduino IDE

![image-20230405202945435](.\images\image-20230405202945435.png)

2、stm32-cubeprg（这个不清楚是什么库，估计是stm32的编译及烧录工具）

![image-20230405203048813](.\images\image-20230405203048813.png)

3、Arduino IDE配置

![image-20230405203718512](.\images\image-20230405203718512.png)

本人使用的是STM32F1系列

![image-20230405203752251](.\images\image-20230405203752251.png)

如果你使用USB转串口方式烧录，配置此选项

![image-20230405204041697](.\images\image-20230405204041697.png)