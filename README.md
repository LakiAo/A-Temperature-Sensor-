# A-Temperature-Sensor-  
学校远景实验室的作业 push到github一份  
### 材料准备：  
Arduino UNO  
SSD1306的oled屏幕  
DHT11温湿度传感器  
有源蜂鸣器（低电平触发）  
按键模块  

### 文章参考：  
显示屏：https://blog.csdn.net/weixin_43662566/article/details/121259723  
温湿度传感器：https://blog.csdn.net/acktomas/article/details/117073078  
有源蜂鸣器（低电平触发）: https://blog.csdn.net/c80486/article/details/52620972  
五向导航按键模块：https://blog.csdn.net/weixin_41659040/article/details/131271131  
（到手后发现该模块按键有问题 故放弃）  
以及部分问题答案来源于ChatGPT  

### 制作过程：  
分别对显示屏、温湿度传感器、蜂鸣器、按钮编写了测试代码  
后续便是作为缝合怪整合四个模块的功能  
对于切换设置界面，我选择通过使用一个按钮来更改变量的值，让程序检测变量的数值从而切换温度提示界面/设置阈值界面  
