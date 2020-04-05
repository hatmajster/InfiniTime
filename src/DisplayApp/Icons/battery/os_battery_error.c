#include "lvgl/lvgl.h"

#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_CK_OS_BATTERY_ERROR
#define LV_ATTRIBUTE_IMG_CK_OS_BATTERY_ERROR
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_IMG_CK_OS_BATTERY_ERROR uint8_t ck_os_battery_error_map[] = {
  0x6c, 0xfe, 0x6c, 0xff, 	/*Color of index 0*/
  0xc4, 0xc2, 0xc4, 0xff, 	/*Color of index 1*/
  0xe4, 0xe6, 0xe4, 0xff, 	/*Color of index 2*/
  0xff, 0xff, 0xff, 0xff, 	/*Color of index 3*/

  0x00, 0x05, 0x55, 0x55, 0x50, 0x00, 
  0x00, 0x15, 0x55, 0x55, 0x54, 0x00, 
  0x00, 0x55, 0x55, 0x55, 0x55, 0x00, 
  0x00, 0x55, 0x55, 0x55, 0x55, 0x00, 
  0x55, 0x55, 0x00, 0x00, 0x55, 0x55, 
  0x55, 0x55, 0x00, 0x00, 0x55, 0x55, 
  0x55, 0x55, 0x00, 0x00, 0x55, 0x55, 
  0x55, 0x54, 0x00, 0x00, 0x15, 0x55, 
  0x55, 0x00, 0x0a, 0xa0, 0x00, 0x55, 
  0x55, 0x00, 0xaa, 0xaa, 0x00, 0x55, 
  0x55, 0x02, 0xaa, 0xaa, 0x80, 0x55, 
  0x55, 0x02, 0xaa, 0xaa, 0x80, 0x55, 
  0x55, 0x0a, 0xa8, 0x2a, 0xa0, 0x55, 
  0x55, 0x0a, 0xa0, 0x0a, 0xa0, 0x55, 
  0x55, 0x00, 0x00, 0x0a, 0xa0, 0x55, 
  0x55, 0x00, 0x00, 0x2a, 0xa0, 0x55, 
  0x55, 0x00, 0x02, 0xaa, 0x80, 0x55, 
  0x55, 0x00, 0x0a, 0xaa, 0x80, 0x55, 
  0x55, 0x00, 0x0a, 0xaa, 0x00, 0x55, 
  0x55, 0x00, 0x0a, 0xa0, 0x00, 0x55, 
  0x55, 0x00, 0x0a, 0xa0, 0x00, 0x55, 
  0x55, 0x00, 0x0a, 0xa0, 0x00, 0x55, 
  0x55, 0x00, 0x00, 0x00, 0x00, 0x55, 
  0x55, 0x00, 0x00, 0x00, 0x00, 0x55, 
  0x55, 0x00, 0x02, 0x80, 0x00, 0x55, 
  0x55, 0x00, 0x0a, 0xa0, 0x00, 0x55, 
  0x55, 0x00, 0x0a, 0xa0, 0x00, 0x55, 
  0x55, 0x00, 0x02, 0x80, 0x00, 0x55, 
  0x55, 0x55, 0x40, 0x01, 0x55, 0x55, 
  0x55, 0x55, 0x50, 0x05, 0x55, 0x55, 
  0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 
  0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 
};

const lv_img_dsc_t ck_os_battery_error = {
  .header.always_zero = 0,
  .header.w = 24,
  .header.h = 32,
  .data_size = 208,
  .header.cf = LV_IMG_CF_INDEXED_2BIT,
  .data = ck_os_battery_error_map,
};