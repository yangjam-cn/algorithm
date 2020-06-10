<!--
 * @Copyright: 版权说明
 * @File name: 文件名
 * @Description: 说明此程序文件的主要功能，与其它模块或函数的接口，输出值、取值范围、含义及参数间的控制、顺序、独立或依赖关系
 * @Author: yangjam
 * @Version: 
 * @Date: 2020-06-06 16:10:04
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-06-06 17:27:06
-->
 <!--cmd命令行教程-->
# 批处理教程
## 常用批处理命令
1. REM和::
    + REM为注释命令，注释内容可以在cmd回显
    + 任何以冒号：开头的的字符行，在批处理中都被视为标号，忽略其后内容
        * 有效标号：冒号后紧跟一个以字母数字开头的字符串
        * 无效标号：冒号后紧跟一个非字母数字的一个特殊符号，goto无法识别，可以起到注释作用
    + 与rem不同，::后的字符行不会在cmd回显
2. echo和@
    + @字符放在命令前将关闭该命令回显
    + echo命令作用
        1. 打开或关闭回显
            * echo on|off
        2. 显示当前echo设置状态
            * echo
        3. 输出提示信息
            * echo 提示信息
        4. 关闭DOS命令提示符
            * echo off，echo on恢复
        5. 输出空行
            * echo.
        6. 答复命令中的提问
            * echo 答复|命令文件名
        7. 建立新文件或增加文件内容
            * echo 文件内容>文件名
            * echo 文件内容>>文件名
        8. 向打印机输出打印内容或打印控制码
            * echo 打印机控制码>PRN
            * echo 打印内容>PRN
        9. 使喇叭鸣响
            * echo ^G
3. pause
    + 暂停并显示提示内容
4. errorlevel
    + 程序返回码
        * echo %errorlevel%
5. title
    + 设置cmd窗口标题
        * title 标题内容
6. color
    + 设置默认的控制台前景和背景颜色
7. mode
    + 配置系统设备
8. goto和:
    + 跳转
9. find
    + 在文件中搜索字符串
        * find [/V][/C][/N][/OFF[LINE]] "string" [[drive][path]filename]
            - /V 显示所有未包含指定字符串的行
            - /C 仅显示包含字符串的行数
            - /N 显示行数
            - /I 搜索字符串时忽略大小写
            - /OFF[LINE] 不要跳过具有脱机属性集的文件
    + 常和type一起使用，去除文件名提示
        * type [drive:][path]filename | find
10. start
    + 批处理中调用外部程序的命令
11. assoc和ftype
    + assoc 设置‘文件扩展名’关联，关联到文件类型
        * assoc 显示所有‘文件扩展名关联’
        * assoc .txt 显示.txt文件代表的文件类型
        * assoc .txt=filetype 更改文件类型关联
    + ftype 设置‘文件类型’关联，关联到执行程序和参数
        * 同上
12. pushd和popd
    + 切换当前目录
        * pushd F:\source 保存当前目录并进入指定目录
        * popd 恢复到前一目录
13. call
    + 在批处理执行过程中调用另一个批处理
14. shift
    + 更改批处理文件中可替换参数的位置
