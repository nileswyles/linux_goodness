## Installation Instructions

1. create user...
2. restore linux_goodness (Xresources, etc.)
3. config Display Manager
4. gdm/gnome_shell/nautilus/gnome-control-center/networkmanager?,etc... (suspend/resume works out of the box (twss, lol)?)
or 
5. lightdm/i3/i3lock/suspend/resume (PM/ACPI - upowerd)
config AppArmor or SELinux to isolate cookies and workspace folders (only select applications can access those files)
6. cookies == edge and git
7. software_workspace == vscode, vim (xterm?)
8. hardware_workspace == kicad
9. zsh because defaults aren't the fad?

10. symlink configuration files in linux_goodness/misc
11. copy systemd files from linux_goodness/systemd directory
	- make sure permissions are set properly... i.e. system services should only be modifiable by root.

***** see package manifest below for more details... *****

## Installation Instructions from Backup 

1. BOOT with live CD.
2. Create partitions:
	/boot
	/
	/swap
3. Mount partitions (configure swap?)
4. Extract distro tar file.
    -- tar -xvzf <tar_file>.tar.gz -C <mounted_root_dir>
5. chroot
6. edit grub.cfg, /etc/fstab to use new drive GUIDs

## GNOME config

- Accessibility
	- Reduce animation = ON
- Privacy & Security
	- Screen Lock
		- Blank Screen Delay = 5 minutes
		- Automatic Screen Lock = ON
		- Automatic Screen Lock Delay = Screen Turns Off 
		- Lock Screen Notifications = ON

... also review all options and use common sense lol.

### Tiles supported by GNOME by default

- Half Horizontal Left
	- <Super>Left
- Half Horizontal Right
	- <Super>Right
- "Full"
	- <Super>Up
- Undo tile/Float
	- <Super>Down

### gTile extension

- Quarter Horizontal and Vertical
	- <Control><Super>Left --- 2x2 1:1 1:1, 2:1 2:1, 1:2 1:2, 2:2, 2:2
- Thirds Horizontal
	- <Control><Super>Down --- 3x1 1:1 1:1, 2:1 2:1, 3:1 3:1
- Two Thirds Horizontal
	- <Control><Super>Right --- 3x1 1:1 2:1, 2:1 3:1
- Half Vertical
	- <Control><Super>Up --- 1x2 1:1 1:1, 1:2 1:2
- Quarter Horizontal
	- <Control><Super><Alt>Left --- 4x1 1:1 1:1, 2:1 2:1, 3:1 3:1, 4:1 4:1
- Half Horizontal Quarter Steps
	- <Control><Super><Alt>Down --- 4x1 1:1 2:1, 2:1 3:1, 3:1 4:1

## TODO

- [ ] clean this up...
- [ ] add more detail

## ARCH Package names below (pacman -S <package_name>) - split on ``` to get list of packages.
```
perl
sudo
git
meld
nvidia
gdm
nautilus
gnome-control-center
apparmor
vim
qemu
```
