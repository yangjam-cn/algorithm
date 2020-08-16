<!--
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description:    
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-08-15 15:10:20
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-08-15 18:58:37
-->
# 目录结构
    * / 根目录
      * mnt：临时文件挂载
      * opt：用来进行软件测试，存放软件
      * proc：存放正在运行的程序
      * root：系统管理员目录
      * sbin：二进制命令，仅root用户可以使用
      * bin：二进制命令，供所有用户使用
      * srv：网络服务相关
      * sys：外设控制
      * tmp：临时存储文件
      * usr：存放大部分软件
      * var：存放易变文件
      * etc：程序配置文件
    * shell配置文件
      * /etc/profile : 所有用户第一次登录时执行
      * ~/bashrc：当前用户登录bash时执行
