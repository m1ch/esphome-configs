#include "esphome.h"


uint8_t calcLedNumber(int8_t addr){
    return (id(neopixa_12h_led) + addr) % id(neopixa_num_leds);
}

void ledRotate(){

    // auto &it = id(rgb_led).get_output();
    // auto it = (AddressableLight) id(rgb_led).get_output();

    auto *it = (AddressableLight *) id(rgb_led).get_output();

    uint8_t led_size = it->size();

    static boolean is_running = false;
    static uint32_t cnt = 0;
    static Color ring_colors[16];
    static boolean rotate_right = false;
    static boolean rotate_on = false;
    static int rot_enc1_old = 0;
    
    if ( rot_enc1_old < int(id(rot_enc1).state) ){
        rotate_right = true;
        rotate_on = true;
    }
    else if ( rot_enc1_old > int(id(rot_enc1).state) ){
        rotate_right = false;
        rotate_on = true;
    }
    else {
        rotate_on = false;
    }
    rot_enc1_old = int(id(rot_enc1).state);
    
    if ( !id(neopixel_effect_running)){
        id(neopixel_effect_running) = true;
        it->all() = Color::BLACK;
        (*it)[calcLedNumber(-1)] = Color(120, 0, 0, 0);
        (*it)[calcLedNumber(0)] = Color(174, 0, 0, 0);
        (*it)[calcLedNumber(1)] = Color(120, 0, 0, 0);
        return;
    }

    if ( !rotate_on ){
        return;
    }

    Color new_color;

    if (rotate_right){
        new_color = (*it)[0].get();
        for (int i = 0; i < it->size() - 1; i++) {
        (*it)[i] = (*it)[i + 1].get();
        }
        (*it)[it->size() - 1] = new_color;
    }
    else {
        new_color = (*it)[it->size() - 1].get();
        for (int i = it->size() - 1; i > 0; i--) {
        (*it)[i] = (*it)[i - 1].get();
        }
        (*it)[0] = new_color;
    }
}

void ledRisingLevel(AddressableLight *it, float level, Color clr){
    static uint8_t num_leds = it->size();
    // const uint8_t led_12h = 0;
    const uint8_t led_6h = num_leds/2;
    // One more level than half, since on top and bottom is only one led:
    const uint8_t levels = num_leds/2+1;

    // static boolean rotate_right = false;
    // static boolean rotate_on = false;
    // static int rot_enc1_old = int(id(rot_enc1).state);

    // if ( rot_enc1_old < int(id(rot_enc1).state) ){
    //   rotate_right = true;
    //   rotate_on = true;
    //   level = level + 0.05;
    // }
    // else if ( rot_enc1_old > int(id(rot_enc1).state) ){
    //   rotate_right = false;
    //   rotate_on = true;
    //   level = level - 0.05;
    // }
    // else {
    //   rotate_on = false;
    // }
    // rot_enc1_old = int(id(rot_enc1).state);

    float dist;
    for (uint8_t i = 0; i < num_leds; i++){
      dist = abs(led_6h - i);
      if(dist < levels*level){
        // ESP_LOGI("neopix", "dist: %d, lev: %f, lvs: %d, clr", dist, level, levels);
        (*it)[calcLedNumber(i)] = clr;
      }
      else {
        // ESP_LOGI("neopix", "dist: %d, lev: %f, lvs: %d, blk", dist, level, levels);
        (*it)[calcLedNumber(i)] = Color::BLACK;
      }      
    }
}

void ledSectorSelect(){

}

void inputEffects(AddressableLight *it){
    // ESP_LOGI("neopix", "Inputs effect running");
    id(neopixel_effect_running) = true;
    int enc_dif = int(id(rot_enc1).state) - id(rot_enc1_old);
    if (id(eink42_page) == PAGEMAIN){
        if (id(input_select_main) == INPUTSMAINTEMPERATURE){
            Color clr = Color(170,0,0);
            float level = (id(target_t).state - id(target_t_min)) / (id(target_t_max) - id(target_t_min));
            ledRisingLevel(it, level, clr);
        }
        else if (id(input_select_main) == INPUTSMAINHUMIDITY){
            Color clr = Color(0,0,170);
            float level = (id(target_h).state - id(target_h_min)) / (id(target_h_max) - id(target_h_min));
            ledRisingLevel(it, level, clr);
        }
    }
}
