## Installation Instructions

1. Install Linux Distro (i.e. Arch Linux, Ubuntu, Debian)
2. Restore linux_goodness (scripts, etc.)
3. Configure Display Manager
	- gdm/gnome_shell/nautilus/gnome-control-center/networkmanager?,etc. (suspend/resume works out of the box (twss, lol))
	- lightdm/i3/i3lock/suspend/resume (PM/ACPI - upowerd)
4. Configure solution to isolate workloads (cookies and workspace folders).
	- Leverage things like AppArmor, SELinux or even a clever user and Display Manager configuration.
		- cookies == edge and git
		- software_workspace == vscode, vim (xterm?)
		- hardware_workspace == kicad
5. Symlink configuration files in misc, systemd and other folders to appropriate locations.
	- Make sure permissions are set properly. For example, system services should only be Read-Writable by the root user.

***** see package manifest below for list of packages to install... *****

## Installation Instructions from Backup 

1. Boot with live CD.
2. Create partitions:
	/boot
	/
	/swap
3. Mount partitions (configure swap?)
4. Extract distro tar file.
    -- tar -xvzf <tar_file>.tar.gz -C <mounted_root_dir>
5. Chroot
6. Edit grub.cfg, /etc/fstab to use the new drive's GUIDs

## GNOME Config

- Accessibility
	- Reduce animation = ON
- Privacy & Security
	- Screen Lock
		- Blank Screen Delay = 5 minutes
		- Automatic Screen Lock = ON
		- Automatic Screen Lock Delay = Screen Turns Off 
		- Lock Screen Notifications = ON

... also review all options and use common sense lol.

### Tiles Supported by GNOME by Default

- Half Horizontal Left
	- <Super>Left
- Half Horizontal Right
	- <Super>Right
- "Full"
	- <Super>Up
- Undo tile/Float
	- <Super>Down

### gTile Extension

- Eighthsies
	- \<Control\>\<Super\>Left
		- 4x2 1:1 1:1, 1:2 1:2, 1:1 1:2, 1:1 2:1, 1:1 2:2, 2:1 2:1, 2:2 2:2, 2:1 2:2, 2:1 3:1, 2:1 3:2, 3:1 3:1, 3:2 3:2, 3:1 3:2, 3:1 4:1, 3:1 4:2, 4:1 4:1, 4:2 4:2, 4:1 4:2
- Sixthsies
	- \<Control\>\<Super\>Right
		- 3x2 1:1 1:1, 1:2 1:2, 1:1 1:2, 1:1 2:1, 1:1 2:2, 2:1 2:1, 2:2 2:2, 2:1 2:2, 2:1 3:1, 2:1 3:2, 3:1 3:1, 3:2 3:2, 3:1 3:2

## TODO

- [ ] clean this up...
- [ ] add more detail
- [ ] zsh?

## ArchLinux Package Names
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
