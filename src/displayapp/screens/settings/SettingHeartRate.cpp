#include "SettingHeartRate.h"
#include <lvgl/lvgl.h>
#include "displayapp/DisplayApp.h"
#include "displayapp/screens/Symbols.h"

using namespace Pinetime::Applications::Screens;

namespace {
  static void event_handler(lv_obj_t* obj, lv_event_t event) {
    SettingHeartRate* screen = static_cast<SettingHeartRate*>(obj->user_data);
    screen->UpdateSelected(obj, event);
  }
}

SettingHeartRate::SettingHeartRate(Pinetime::Applications::DisplayApp* app, Pinetime::Controllers::Settings& settingsController)
  :

    Screen(app),
    settingsController {settingsController} {

  lv_obj_t* container1 = lv_cont_create(lv_scr_act(), nullptr);

  // lv_obj_set_style_local_bg_color(container1, LV_CONT_PART_MAIN, LV_STATE_DEFAULT, lv_color_hex(0x111111));
  lv_obj_set_style_local_bg_opa(container1, LV_CONT_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_TRANSP);
  lv_obj_set_style_local_pad_all(container1, LV_CONT_PART_MAIN, LV_STATE_DEFAULT, 10);
  lv_obj_set_style_local_pad_inner(container1, LV_CONT_PART_MAIN, LV_STATE_DEFAULT, 5);
  lv_obj_set_style_local_border_width(container1, LV_CONT_PART_MAIN, LV_STATE_DEFAULT, 0);
  lv_obj_set_pos(container1, 30, 60);
  lv_obj_set_width(container1, LV_HOR_RES - 50);
  lv_obj_set_height(container1, LV_VER_RES - 60);
  lv_cont_set_layout(container1, LV_LAYOUT_COLUMN_LEFT);

  lv_obj_t* title = lv_label_create(lv_scr_act(), NULL);
  lv_label_set_text_static(title, "HRS Gain");
  lv_label_set_align(title, LV_LABEL_ALIGN_CENTER);
  lv_obj_align(title, lv_scr_act(), LV_ALIGN_IN_TOP_MID, 15, 15);

  lv_obj_t* icon = lv_label_create(lv_scr_act(), NULL);
  lv_obj_set_style_local_text_color(icon, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_ORANGE);

  lv_label_set_text_static(icon, Symbols::heartBeat);
  lv_label_set_align(icon, LV_LABEL_ALIGN_CENTER);
  lv_obj_align(icon, title, LV_ALIGN_OUT_LEFT_MID, -10, 0);

  gainValue = lv_label_create(lv_scr_act(), NULL);
  lv_obj_set_style_local_text_font(gainValue, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &jetbrains_mono_42);
  lv_label_set_text_fmt(gainValue, "%d", static_cast<uint8_t>(settingsController.GetHeartSensorGain()));
  lv_label_set_align(gainValue, LV_LABEL_ALIGN_CENTER);
  lv_obj_align(gainValue, lv_scr_act(), LV_ALIGN_CENTER, 0, -10);

  btnPlus = lv_btn_create(lv_scr_act(), NULL);
  btnPlus->user_data = this;
  lv_obj_set_size(btnPlus, 80, 50);
  lv_obj_align(btnPlus, lv_scr_act(), LV_ALIGN_CENTER, 55, 80);
  lv_obj_set_style_local_value_str(btnPlus, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, "+");
  lv_obj_set_event_cb(btnPlus, event_handler);

  btnMinus = lv_btn_create(lv_scr_act(), NULL);
  btnMinus->user_data = this;
  lv_obj_set_size(btnMinus, 80, 50);
  lv_obj_set_event_cb(btnMinus, event_handler);
  lv_obj_align(btnMinus, lv_scr_act(), LV_ALIGN_CENTER, -55, 80);
  lv_obj_set_style_local_value_str(btnMinus, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, "-");
}

SettingHeartRate::~SettingHeartRate() {
  lv_obj_clean(lv_scr_act());
  settingsController.SaveSettings();
}

void SettingHeartRate::UpdateSelected(lv_obj_t* object, lv_event_t event) {
  auto old_value = settingsController.GetHeartSensorGain();
  if (object == btnPlus && (event == LV_EVENT_PRESSED)) {
    settingsController.HeartSensorGainIncrease();
  }
  if (object == btnMinus && (event == LV_EVENT_PRESSED)) {
    settingsController.HeartSensorGainDecrease();
  }
  auto new_value = settingsController.GetHeartSensorGain();
  bool changed = old_value != new_value;

  if (changed) {
    lv_label_set_text_fmt(gainValue, "%d", static_cast<uint8_t>(new_value));
    lv_obj_align(gainValue, lv_scr_act(), LV_ALIGN_CENTER, 0, -10);
  }
}