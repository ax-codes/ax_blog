---
title: virtualbox中ubuntu和windows共享文件夹设置
date: 2015/01/15 08:00:00
categories: 技术
toc: True
tags: [linux,windows,开发工具/插件]
---
## 系统平台
系统平台：win8.1、virtualbox4.3.8、ubuntu12.04
安装VBoxGuestAdditions_4.3.8.iso增强工具，安装完毕后根据提示重启Ubuntu，具体操作如下：

### Step 1
<img src="1.png"/>

### Step 2.安装virtualbox增强包
```shell
linjiqin@ubuntu:~$ cd ~
linjiqin@ubuntu:~$ su -
密码： 
root@ubuntu:~# cd /media/
root@ubuntu:/media# ls
sf_share  VBOXADDITIONS_4.3.8_92456
root@ubuntu:/media# cd VBOXADDITIONS_4.3.8_92456/
root@ubuntu:/media/VBOXADDITIONS_4.3.8_92456# ls
32Bit        cert                    VBoxSolarisAdditions.pkg
64Bit        OS2                     VBoxWindowsAdditions-amd64.exe
AUTORUN.INF  runasroot.sh            VBoxWindowsAdditions.exe
autorun.sh   VBoxLinuxAdditions.run  VBoxWindowsAdditions-x86.exe
root@ubuntu:/media/VBOXADDITIONS_4.3.8_92456# sudo ./VBoxLinuxAdditions.run #安装virtualbox增强包
....
root@ubuntu:/media/VBOXADDITIONS_4.3.8_92456# 
```

### Step 3
先关闭ubuntu，在virtualbox“设置”中找到“共享文件夹”，点击进入，点击右边添加目录按钮，添加windows中要共享的目录，取一个名。比如我在D盘建一个名为share的文件夹，如下图：
<img src="2.png"/>

### Step 4
重启ubuntu，在ubuntu系统最上端“设备”中找到“共享文件夹”，点击进入，点击右边添加目录按钮，添加第二步操作的共享目录，如下图：
<img src="3.png"/>

### Step 5
进入虚拟Ubuntu，在命令行终端下输入：
sudo mkdir /mnt/shared
sudo mount -t vboxsf share /mnt/shared
其中"share"是之前创建的共享文件夹的名字。OK，现在Ubuntu和主机可以互传文件了。
要想自动挂载的话，可以在/etc/fstab中添加一项
share /mnt/shared vboxsf rw,gid=100,uid=1000,auto 0 0

### 卸载的话使用下面的命令:
sudo umount -f /mnt/shared

### <font color=red>注意</font>
共享文件夹的名称千万不要和挂载点的名称相同。比如，上面的挂载点是/mnt/shared，如果共享文件夹的名字也是shared的话，在挂载的时候就会出现如下的错误信息：/sbin/mount.vboxsf: mounting failed with the error: Protocol error