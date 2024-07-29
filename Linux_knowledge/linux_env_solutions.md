# WSL环境（Linux环境）

## 为什么是wsl?
我一共尝试过四种方案：
1. 虚拟机： 
2. 双系统
3. linux单系统
4. **wsl(windows的Linux子系统)**


*虚拟机的体验感不是很好,字体特别小；双系统基本上不会打开Linux。*

*单系统。
优点：环境ubuntu24.04版本虽然QQ、微信、输入法都已经比较成熟了。
缺点：vpn设置比较麻烦,cuda什么的得不科学上网下的特别慢，下好了以后系统报了内部错误。*

**WSL**默认没有图形化界面，但支持code连接，我现在就在code里边写markdown，在终端里运行，体验感也不错。

## 如何安装WSL?

1. 开启windows系统功能
```
-> 控制面板 -> 程序和功能 ->启用或关闭windows功能
```

![](Linux_knowledge/pictures/控制面板.png)

在启动勾选以下两项：**适用于Linux的windows子系统、虚拟机平台**，然后确认。（这个过程会提示关机重启才能启动功能）。

2. 根据官方文档进行设置
[WSL官方文档](https://learn.microsoft.com/zh-cn/windows/wsl/),建议看完整的**安装说明**再进行安装，我的安装目录如下，仅供参考。

- 查看WSL版本
```
win+r //打开命令行

wsl --install //安装wsl

wsl --set-default-version 2  //设置wsl版本为2,因为2的版本支持一些图形化应用

wsl --list --online //查看可用的发行版

wsl --install -d Ubuntu-24.04 //我安装的子系统是ubuntu24.04
```

最后出现了错误，错误代码如下：
```
Installing, this may take a few minutes...
WslRegisterDistribution failed with error: 0x800701bc
Error: 0x800701bc WSL 2 ?????????????????? https://aka.ms/wsl2kernel

Press any key to continue..
```

百度了下，这是需要下载linux内核更新包，[下载地址](https://wslstorestorage.blob.core.windows.net/wslblob/wsl_update_x64.msi)

下载后安装就解决了，然后设置用户名和密码。

3. 进行环境配置
这部分按照官方教程走，我只进行了软件包的更新、**vscode的安装**、terminal的安装。

这部分官方教程非常详细。![教程导航](Linux_knowledge/pictures/vscode的配置.png)

这里要说明的是,code装在windows，提供子系统的连接，用起来非常丝滑。
![](Linux_knowledge/pictures/配置结果.png)
其他所需配置文档也有，学起来吧。
