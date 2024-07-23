# Keil环境搭建

- **CMSIS DAP Link 调试器**

![](images\IMG_20230618_151301.jpg)

- 调试器与STM32接线


![IMG_20230618_152229](images\IMG_20230618_152229.jpg)

- DAPLink连接电脑，识别不了尝试卸载设备再重插

  ![](images\devices.bmp)

- **Keil配置V5.38.0，安装compiler version5**

  打开nanoDAP-master\software\test\led_test例子led_test.uvprojx

  1. 安装compiler version5，安装包在百度网盘

     链接：https://pan.baidu.com/s/1i89-tnlr0O6jkvvcAHeZnw 
     提取码：083r

  2. 下载、解压到D:\Keil_v5\ARM\ARM_Compiler_5.06u7

     本人的Keil在D:\Keil_v5，为了方便管理，直接放在同级ARM目录

     ![](images\1.jpg)

  3. 添加编译ARM_v5版本

     ![](images\20230618154810.jpg)

     ![](images\20230618154947.jpg)

- **Keil5配置DAPLink调试器**

  ![](images\20230618160604.jpg)![](images\20230618160715.jpg)

- 最后按F7 Build构建，F8烧录，闪灯效果

  ![](images\1687076316887.jpg)

​		

# Arduino环境搭建

准备USB转串口调备及接线，烧录前先按下boot

![](images\ttl.jpg)



STM32有2个跳线帽

- 运行模式

  ![](images\run_state.jpg)

- 烧录模式（右侧下移跳线）

  ![](images\fireupload.png)



1、Arduino IDE

![image-20230405202945435](images\image-20230405202945435.png)

2、stm32-cubeprg（这个不清楚是什么库，估计是stm32的编译及烧录工具）

![image-20230405203048813](images\image-20230405203048813.png)

3、Arduino IDE配置

![image-20230405203718512](images\image-20230405203718512.png)

本人使用的是STM32F1系列

![image-20230405203752251](images\image-20230405203752251.png)

如果你使用USB转串口方式烧录，配置此选项

![image-20230405204041697](images\image-20230405204041697.png)



# OpenOCD编译Win10

- openocd-code官方下载

《How to Build OpenOCD and Picotool for the Raspberry Pi Pico on Windows - Shawn Hymel.html》

安装并打开mingw64.exe

```shell
# 更新系统文件
$ pacman -Syuu
# 安装库win64
$ pacman -S libtool autoconf automake texinfo pkg-config make autogen git unzip bzip2 base-devel mingw-w64-x86_64-toolchain mingw-w64-x86_64-libusb mingw-w64-x86_64-libusb-compat-git mingw-w64-x86_64-hidapi mingw-w64-x86_64-libftdi mingw-w64-x86_64-arm-none-eabi-gcc mingw-w64-x86_64-capstone
# 下载openocd，保存了一份openocd
$ git clone https://git.code.sf.net/p/openocd/code openocd-code
$ cd openocd-code
$ mkdir build
$ ./bootstrap
$ cd build
$ ../configure --enable-ftdi
$ make
$ make install
# 新建bin目录，抽取放到可执行文件。从build/src里拷贝openocd.exe到bin
$ cd ..
$ mkdir bin
$ cp build/src/openocd.exe bin/
```

最后把其它依赖dll（从mysys64安装目录D:\msys64\mingw64\bin中获取依赖bin）复制到bin下

- openocd树莓派官网下载

《(5条消息) [开发工具]Windows下编译OpenOCD过程分享（基于MSYS2）_windows openocd_21ic电子工程师的博客-CSDN博客.html》

跟上面类似，只是configure有所区别，注意要加上--disable-werror

```shell
...
$ git clone https://github.com/raspberrypi/openocd.git --branch picoprobe --depth=1
...
$ ../configure --enable-picoprobe --enable-cmsis-dap --enable-cmsis-dap-v2 --disable-werror
...
```

清除make文件，重新编译可以使用下面的命令

```shell
make clean #清除上一次make命令生成的文件
make distclean #清除上一次make以及configure命令生成的文件
```



# VS+PlatformIO+Ardunio调试

STM32F103C6T6调试，见项目，主要配置platformio.ini

另外2处地方要修改

- genericSTM32F103C6.json

D:\Users\Administrator\.platformio\platforms\ststm32\boards\genericSTM32F103C6.json

![](images\iocfg1.jpg)

- cmsis-dap.cfg

  报错时

  ![](images\dapv2err.jpg)

  解决方法：

  增加 **cmsis_dap_backend hid**

  ![](images\iocfg2.jpg)

  Linux

  /home/jun/.platformio/packages/tool-openocd-raspberrypi/share/openocd/scripts/interface

- 树莓派pico调试

  | Pin RP Pico                        | Pin DAP   |
  | ---------------------------------- | --------- |
  | **“DEBUG” “SWCLK”**                | **SWCLK** |
  | **“DEBUG” “GND”**                  | **GND**   |
  | **“DEBUG” “SWDIO”**                | **SWDIO** |
  | **“3V3” Pad 36**（右侧第5个脚3v3） | **VCC**   |
  
  ![](images\rp2040line.jpg)
  
  原来配置rp2040.cfg，发现D:\Users\Administrator\.platformio\packages\tool-openocd\scripts\target并没有rp2040.cfg配置，只有rp2040-core0.cfg，更正过来后正常调试，或者拷贝一份E:\DAPLink\openocd\tcl\target\rp2040.cfg到对应目录
  
  ![](images\rp2040.jpg)