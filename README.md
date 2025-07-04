## 项目简介

这是一个突发奇想的创意，用pid控制编码电机，实验太过单调了
所以我想赋予功能以意义，以控制转速和转角度，成为旋转的特殊，做一个旋转展台
（仍在完善）

## 硬件介绍

采用立创地猛星作为主控板，自主设计外围电路连接，具体详见立创开源广场
[pid旋转展台](https://oshwhub.com/xingmanghi/pid-rotary-product-booth)

## 软件介绍

采用keil + MSP_SDK配置环境进行开发，学习立创文档分为硬件层，中间层，应用层三层，方便管理和移植

整体实现思路为: 主函数循环内部进行OLED屏幕和电机PID更新的循环；定时器周期扫描按键、旋转编码器情况并进行更新；中断中获取电机编码器数据

### 硬件层

包括基础的硬件端口驱动，gpio电平获取，中断设置等

* GPIO中断处理
* 按键扫描
* 电机结构体定义和状态更新
* 定时器
* 编码器状态更新
* ws2812（未完成）

### 中间层

包括串口等通信相关文件，第三方库文件以及对硬件信号的二次处理

* 开源按键库及移植
* 编码器译码和信号处理
* 串口通信
* OLED屏驱动库

### 应用层

包括具体功能逻辑的实现

* 屏幕显示
* 按键事件任务
* 电机速度更新

## 项目使用说明

本项目文件是一个单独的MSPM0项目文件，从keil文件夹内的keil文件打开进行查看和使用。

具体环境配置参考[立创开发文档环境配置](https://wiki.lckfb.com/zh-hans/tmx-mspm0g3507/training/easy-pid-beginner-kit/install.html)

配置完成后将文件作为一个单独项目文件存放打开，自行配置keil中的头文件变量等即可使用