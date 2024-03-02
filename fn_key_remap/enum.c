#include <libudev.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

int main(void) {
  struct udev * udev_ptr;
  struct udev_enumerate * enumerate;

  udev_ptr = udev_new();
  enumerate = udev_enumerate_new(udev_ptr);

  //udev_enumerate_add_match_subsystem(enumerate, "input");
  udev_enumerate_add_match_is_initialized(enumerate);
  udev_enumerate_add_match_property(enumerate, "NAME", "\"Apple SPI Keyboard\"");

  udev_enumerate_scan_devices(enumerate);

  struct udev_list_entry * entry = udev_enumerate_get_list_entry(enumerate);

  while (entry != NULL) {    
    const char * name = udev_list_entry_get_name(entry);
    struct udev_device * device = udev_device_new_from_syspath(udev_ptr, name);
    const char * dev_path = udev_device_get_devpath(device);
    const char * dev_type = udev_device_get_devtype(device);
    const char * dev_sysname = udev_device_get_sysname(device);
    const char * dev_sysnum = udev_device_get_sysnum(device);
    const char * dev_driver = udev_device_get_driver(device);
    const char * dev_node = udev_device_get_devnode(device);
    const char * sys_path = udev_device_get_syspath(device);
    const dev_t dev_num = udev_device_get_devnum(device);

      //printf("ENTRY NAME: %s, VALUE: %s\n", name, udev_list_entry_get_value(entry)); 
      //printf("PATH: %s, TYPE: %s, SYSNAME: %s, SYSNUM: %s, DRIVER: %s, DEV_NAME: %s\n", dev_path, dev_type, dev_sysname, dev_sysnum, dev_driver, device_name);
      //printf("DEV_NODE: %s, SYSPATH: %s\n", dev_node, sys_path);
     
      const char * device_name = udev_device_get_property_value(device, "NAME");
      if (device_name != NULL) {
        printf("DEVICE NAME: %s\n", device_name);
      }

      //if (device_name != NULL && strcmp(device_name, "\"Apple SPI Keyboard\"") == 0) {
      if (device_name != NULL) {
        printf("DEVNUM: %d:%d\n", ((uint8_t *)&dev_num)[0], ((uint8_t *)&dev_num)[4]);
        const char * MAJOR = udev_device_get_property_value(device, "MAJOR");
        if (MAJOR != NULL) {
          printf("MAJOR: %s\n", MAJOR);
        }
        const char * minor = udev_device_get_property_value(device, "minor");
        if (minor != NULL) {
          printf("minor: %s\n", minor);
        }

        printf("DEVICE NAME: %s\n", device_name);
        struct udev_list_entry * props = udev_device_get_properties_list_entry(device);
        while (props != NULL) {
          const char * name = udev_list_entry_get_name(props);
	  const char * value = udev_list_entry_get_value(props);
          printf("props KEY: %s, VALUE: %s\n", name, value); 
          props = udev_list_entry_get_next(props);
        }
        struct udev_list_entry * attrs = udev_device_get_sysattr_list_entry(device);
        while (attrs != NULL) {
          printf("KEY: %s, VALUE: %s\n", udev_list_entry_get_name(attrs), udev_list_entry_get_value(attrs)); 
          attrs = udev_list_entry_get_next(attrs);
        }
        struct udev_list_entry * devlinks = udev_device_get_devlinks_list_entry(device);
        while (devlinks != NULL) {
          printf("KEY: %s, VALUE: %s\n", udev_list_entry_get_name(devlinks), udev_list_entry_get_value(devlinks)); 
          devlinks = udev_list_entry_get_next(devlinks);
        }
        struct udev_list_entry * tags = udev_device_get_tags_list_entry(device);
        while (tags != NULL) {
          printf("KEY: %s, VALUE: %s\n", udev_list_entry_get_name(tags), udev_list_entry_get_value(tags)); 
          tags = udev_list_entry_get_next(tags);
        }
      }
    entry = udev_list_entry_get_next(entry);
  }
  

  return 0;
}


