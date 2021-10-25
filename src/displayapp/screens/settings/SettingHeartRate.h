#pragma once

#include <cstdint>
#include <lvgl/lvgl.h>
#include "components/settings/Settings.h"
#include "components/heartrate/HeartRateController.h"
#include "displayapp/screens/Screen.h"

namespace Pinetime {

  namespace Applications {
    namespace Screens {

      class SettingHeartRate : public Screen {
      public:
        SettingHeartRate(DisplayApp* app, Pinetime::Controllers::Settings& settingsController);
        ~SettingHeartRate() override;

        void UpdateSelected(lv_obj_t* object, lv_event_t event);

      private:
        Controllers::Settings& settingsController;

        lv_obj_t* gainValue;
        lv_obj_t* btnPlus;
        lv_obj_t* btnMinus;
      };
    }
  }
}
