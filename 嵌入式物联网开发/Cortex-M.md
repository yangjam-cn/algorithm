<!--
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 
 * @Author: yangjam
 * @Version: demo
 * @Date: 2020-06-29 15:13:56
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-06-29 16:07:27
--> 
# ARM
## ARM
* IP核：一段具有特定电路功能的硬件描述语言程序
* ARM早期命名规则简析
  * ARM = Advanced RISC Machines
  * ARM{x}{y}{z}{T}{D}{M}{I}{E}{J}{F}{S}
    * x:处理器系列
    * y:存储单元/保护单元
      * y=2表示带cache和MMU
      * y=3表示物理地址标记的cache和MMU
      * y=4表示cache和MPU
      * y=6表示写缓冲但无cache大小
    * z:cache
      * z=0表示标准cache大小
      * z=2表示缩小的cache大小
      * z=6表示包含紧密耦合SRAM
    * T:支持Thumb指令
    * D:支持片上debug
    * M:内嵌硬件乘法器
    * I:嵌入式ICE，支持片上断点和调试点
    * E:DSP运算的增强指令
    * J:使用Jazelle技术
    * F:ARM核通过浮点结构支持硬件浮点
    * S:综合版本，意味着以源代码的形式提供
* 特点
  * 支持RISC指令集
  * 体积小
  * 功耗低
  * 成本低
  * 性能高
  * 集成度高
  * 种类繁多，应用广泛
## Cortex
* ARM11以后的产品改用cortex命名
* Cortex架构采用ARMv7指令
  * "A"系列面向尖端基于虚拟内存的操作系统核用户应用
  * "R"系列针对实时系统
  * "M"系列针对低功耗成本的微控制器应用
* cortex-M特点
  * 低成本
  * 低功耗
  * 对代码需求更小
  * 代码可重用性好
  * 性能强大
  * 可选厂家和型号多 
* Cortex-M家族三兄弟-M0、M3、M4