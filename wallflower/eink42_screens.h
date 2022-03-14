#pragma once

#include "helpers.h"

void wgTemeratureHumidity(uint16_t x0, uint16_t y0, char* label, float temp, float humi){
    auto it = id(eink42);

    uint16_t x = x0;
    uint16_t y = y0;
    const uint16_t h = 12+6+40;
    const uint16_t w = 12+6+40;

    it.printf(x, y, &id(NotoSansMonoRegular12), COLOR_ON, TextAlign::TOP_LEFT, label);
    
    int value = int( abs(temp) );
    int  frac = int( (abs(temp) - value) * 10);
    char sign = (temp<0) ? '-':'+';

    x=x0; y=y0+h;
    it.printf(x, y, &id(NotoSansMonoRegular40), COLOR_ON, TextAlign::BOTTOM_LEFT, "%c", sign );
    x += 22;
    it.printf(x, y, &id(NotoSansMonoRegular40), COLOR_ON, TextAlign::BOTTOM_LEFT, "%2d", value );
    x += 41;
    it.printf(x, y, &id(NotoSansMonoRegular40), COLOR_ON, TextAlign::BOTTOM_LEFT, "." );
    x += 17;
    it.printf(x, y, &id(NotoSansMonoRegular40), COLOR_ON, TextAlign::BOTTOM_LEFT, "%1d", frac );
    x += 21;
    it.printf(x, y, &id(NotoSansMonoRegular40), COLOR_ON, TextAlign::BOTTOM_LEFT, "°" );
    x += 20;
    it.printf(x, y, &id(NotoSansMonoRegular40), COLOR_ON, TextAlign::BOTTOM_LEFT, "C" );
    // Humidity
    x += 33;
    it.printf(x, y, &id(NotoSansMonoRegular28), COLOR_ON, TextAlign::BOTTOM_LEFT, "%2.0f", humi );
    x += 32; y -= 30;
    it.image(x, y, &id(water_percent_24));
}

void wgTemerature40(uint16_t x0, uint16_t y0){
    auto it = id(eink42);
    uint16_t x = x0;
    uint16_t y = y0;

    int minus = 0;
    int value = 0;
    float f_value = 0;
    int frac = 0;
    const char label_outdoor[] = "Outdoor";
    const char label_indoor[] = "Indoor";

    wgTemeratureHumidity(x0, y0, (char*)label_outdoor, id(outdoor_t).state, id(outdoor_h).state);
    wgTemeratureHumidity(x0, y0+58, (char*)label_indoor, id(local_t).state, id(local_h).state);

    uint16_t x01 = x0 + 22;
    uint16_t x02 = x01 + 41;
    uint16_t x03 = x02 + 17;
    uint16_t x04 = x03 + 21;
    uint16_t x05 = x04 + 20;
    uint16_t x06 = x01 + 24;
    uint16_t x07 = x06 + 10;
    uint16_t x08 = x07 + 13;
    uint16_t x09 = x08 + 12;
    uint16_t x1 = x0+155;
    uint16_t y01 = y0 + 6;
    uint16_t y02 = y01 + 52;
    uint16_t y03 = y02 + 6;
    uint16_t y04 = y03 + 48;
    uint16_t y11 = y01 - 0;
    uint16_t y12 = y01 + 12;
    uint16_t y13 = y03 + 12;
    uint16_t y14 = y04;

    // x=x0;
    // y=y0;

    // it.printf(x, y, &id(NotoSansMonoRegular12), COLOR_ON, "Outdoor");
    // f_value = id(outdoor_t).state;
    // x=x0;
    // y=y01;
    // if ( f_value < 0) {
    //     value = int( f_value * -1 );
    //     frac = int( (f_value + value) * -10);
    //     it.printf(x, y, &id(NotoSansMonoRegular40), COLOR_ON, TextAlign::TOP_LEFT, "-" );
    // }
    // else {
    //     value = int( f_value );
    //     frac = int( (f_value - value) * 10);
    //     it.printf(x, y, &id(NotoSansMonoRegular40), COLOR_ON, TextAlign::TOP_LEFT, "+" );
    // }
    // x = x01;
    // it.printf(x, y, &id(NotoSansMonoRegular40), COLOR_ON, TextAlign::TOP_LEFT, "%2d", value );
    // x = x02;
    // it.printf(x, y, &id(NotoSansMonoRegular40), COLOR_ON, TextAlign::TOP_LEFT, "." );
    // x = x03;
    // it.printf(x, y, &id(NotoSansMonoRegular40), COLOR_ON, TextAlign::TOP_LEFT, "%1d", frac );
    // x = x04;
    // it.printf(x, y, &id(NotoSansMonoRegular40), COLOR_ON, TextAlign::TOP_LEFT, "°" );
    // x = x05;
    // it.printf(x, y, &id(NotoSansMonoRegular40), COLOR_ON, TextAlign::TOP_LEFT, "C" );

    // x=x0;
    // y=y02;
    // it.printf(x, y, &id(NotoSansMonoRegular12), COLOR_ON, "Indoor");
    // f_value = id(local_t).state;
    // x=x0;
    // y=y03;
    // if ( f_value < 0) {
    //     value = int( f_value * -1 );
    //     frac = int( (f_value + value) * -10);
    //     it.printf(x, y, &id(NotoSansMonoRegular40), COLOR_ON, TextAlign::TOP_LEFT, "-" );
    // }
    // else {
    //     value = int( f_value );
    //     frac = int( (f_value - value) * 10);
    //     it.printf(x, y, &id(NotoSansMonoRegular40), COLOR_ON, TextAlign::TOP_LEFT, "+" );
    // }
    // x = x01;
    // it.printf(x, y, &id(NotoSansMonoRegular40), COLOR_ON, TextAlign::TOP_LEFT, "%2d", value );
    // x = x02;
    // it.printf(x, y, &id(NotoSansMonoRegular40), COLOR_ON, TextAlign::TOP_LEFT, "." );
    // x = x03;
    // it.printf(x, y, &id(NotoSansMonoRegular40), COLOR_ON, TextAlign::TOP_LEFT, "%1d", frac );
    // x = x04;
    // it.printf(x, y, &id(NotoSansMonoRegular40), COLOR_ON, TextAlign::TOP_LEFT, "°" );
    // x = x05;
    // it.printf(x, y, &id(NotoSansMonoRegular40), COLOR_ON, TextAlign::TOP_LEFT, "C" );

    if( id(heating).state ) {
        x=x0;
        y=y04;
        it.image(x, y, &id(radiator_24));
    }
    f_value = id(target_t).state;
    x = x01 + 3;
    y = y04;
    // if ( id(mode) == id(mode_scr1_settemp)) {
    //     it.line(x, y+24, x09+8, y+24);
    // }
    value = int( f_value );
    frac = int( (f_value - value) * 10);
    it.printf(x, y, &id(NotoSansMonoRegular22), COLOR_ON, TextAlign::TOP_LEFT, "%2d", value );
    x = x06;
    it.printf(x, y, &id(NotoSansMonoRegular22), COLOR_ON, TextAlign::TOP_LEFT, "." );
    x = x07;
    it.printf(x, y, &id(NotoSansMonoRegular22), COLOR_ON, TextAlign::TOP_LEFT, "%1d", frac );
    x = x08;
    it.printf(x, y, &id(NotoSansMonoRegular22), COLOR_ON, TextAlign::TOP_LEFT, "°" );
    x = x09;
    it.printf(x, y, &id(NotoSansMonoRegular22), COLOR_ON, TextAlign::TOP_LEFT, "C" );

    f_value = id(target_h).state;
    x=x1;
    y=y14;
    it.printf(x, y, &id(NotoSansMonoRegular22), COLOR_ON, TextAlign::TOP_LEFT, "%2.0f%%", f_value );

    /////////////////////////////////////////////////
    // Humidity
    // x=x1;
    // y=y11;
    // f_value = id(outdoor_h).state;
    // x=x1;
    // y=y12;
    // it.printf(x, y, &id(NotoSansMonoRegular28), COLOR_ON, TextAlign::TOP_LEFT, "%2.0f", f_value );
    // x+=32;
    // y+=9;
    // it.image(x, y, &id(water_percent_24));

    // f_value = id(local_h).state;
    // x=x1;
    // y=y13;
    // it.printf(x, y, &id(NotoSansMonoRegular28), COLOR_ON, TextAlign::TOP_LEFT, "%2.0f", f_value );
    // x+=32;
    // y+=9;
    // it.image(x, y, &id(water_percent_24));
}

void wgDateTime(uint16_t x, uint16_t y){
    auto it = id(eink42);
    uint16_t y0 = y;

    it.strftime(x, y, &id(NotoSansMonoRegular20), COLOR_ON, TextAlign::TOP_RIGHT, "%b %d", id(sntp_time).now());
    it.strftime(x, y+18, &id(NotoSansMonoRegular64), COLOR_ON, TextAlign::TOP_RIGHT, "%H", id(sntp_time).now());
    it.strftime(x, y+72, &id(NotoSansMonoRegular64), COLOR_ON, TextAlign::TOP_RIGHT, "%M", id(sntp_time).now());
}

void wgBus(uint16_t x, uint16_t y){
    auto it = id(eink42);
    uint16_t y0 = y;
    // Bus schedule
    it.image(x, y0-48, &id(bus_clock_48));
    it.printf(x+51, y0-21-24, &id(NotoSansMonoRegular20), COLOR_ON, TextAlign::TOP_LEFT, "31: %dmin", 5 );
    it.printf(x+51, y0-21, &id(NotoSansMonoRegular20), COLOR_ON, TextAlign::TOP_LEFT, " 4: %dmin", 7 );
}

void wgForecasts(uint16_t x, uint16_t y){
    auto it = id(eink42);
    uint16_t y0 = y;
    y = y0 - 120;
    if ( not strcmp(id(forcast_condition)[0], "cloudy" )) {
        it.image(x, y, &id(weather_cloudy_120));
    }
    else if ( not strcmp(id(forcast_condition)[0], "fog" )) {
        it.image(x, y, &id(weather_fog_120));
    }
    else if ( not strcmp(id(forcast_condition)[0], "hail" )) {
        it.image(x, y, &id(weather_hail_120));
    }
    else if ( not strcmp(id(forcast_condition)[0], "lightning" )) {
        it.image(x, y, &id(weather_lightning_120));
    }
    else if ( not strcmp(id(forcast_condition)[0], "lightning-rainy" )) {
        it.image(x, y, &id(weather_lightningrainy_120));
    }
    else if ( not strcmp(id(forcast_condition)[0], "partlycloudy" )) {
        it.image(x, y, &id(weather_partlycloudy_120));
    }
    else if ( not strcmp(id(forcast_condition)[0], "pouring" )) {
        it.image(x, y, &id(weather_pouring_120));
    }
    else if ( not strcmp(id(forcast_condition)[0], "rainy" )) {
        it.image(x, y, &id(weather_rainy_120));
    }
    else if ( not strcmp(id(forcast_condition)[0], "snowy" )) {
        it.image(x, y, &id(weather_snowy_120));
    }
    else if ( not strcmp(id(forcast_condition)[0], "snowy-rainy" )) {
        it.image(x, y, &id(weather_snowyrainy_120));
    }
    else if ( not strcmp(id(forcast_condition)[0], "sunny" )) {
        it.image(x, y, &id(weather_sunny_120));
    }
    else if ( not strcmp(id(forcast_condition)[0], "windy" )) {
        it.image(x, y, &id(weather_windy_120));
    }
    else if ( not strcmp(id(forcast_condition)[0], "windy-variant" )) {
        it.image(x, y, &id(weather_windy_120));
    }
    else {
        it.image(x, y, &id(weather_hazy_120));
    }

    x = x + 130;
    y = y0 - 72;
    if ( not strcmp(id(forcast_condition)[1], "cloudy" )) {
        it.image(x, y, &id(weather_cloudy_72));
    }
    else if ( not strcmp(id(forcast_condition)[1], "fog" )) {
        it.image(x, y, &id(weather_fog_72));
    }
    else if ( not strcmp(id(forcast_condition)[1], "hail" )) {
        it.image(x, y, &id(weather_hail_72));
    }
    else if ( not strcmp(id(forcast_condition)[1], "lightning" )) {
        it.image(x, y, &id(weather_lightning_72));
    }
    else if ( not strcmp(id(forcast_condition)[1], "lightning-rainy" )) {
        it.image(x, y, &id(weather_lightningrainy_72));
    }
    else if ( not strcmp(id(forcast_condition)[1], "partlycloudy" )) {
        it.image(x, y, &id(weather_partlycloudy_72));
    }
    else if ( not strcmp(id(forcast_condition)[1], "pouring" )) {
        it.image(x, y, &id(weather_pouring_72));
    }
    else if ( not strcmp(id(forcast_condition)[1], "rainy" )) {
        it.image(x, y, &id(weather_rainy_72));
    }
    else if ( not strcmp(id(forcast_condition)[1], "snowy" )) {
        it.image(x, y, &id(weather_snowy_72));
    }
    else if ( not strcmp(id(forcast_condition)[1], "snowy-rainy" )) {
        it.image(x, y, &id(weather_snowyrainy_72));
    }
    else if ( not strcmp(id(forcast_condition)[1], "sunny" )) {
        it.image(x, y, &id(weather_sunny_72));
    }
    else if ( not strcmp(id(forcast_condition)[1], "windy" )) {
        it.image(x, y, &id(weather_windy_72));
    }
    else if ( not strcmp(id(forcast_condition)[1], "windy-variant" )) {
        it.image(x, y, &id(weather_windy_72));
    }
    else {
        it.image(x, y, &id(weather_hazy_72));
    }

    x = x+82;
    y = y0 - 72;
    if ( not strcmp(id(forcast_condition)[2], "cloudy" )) {
        it.image(x, y, &id(weather_cloudy_72));
    }
    else if ( not strcmp(id(forcast_condition)[2], "fog" )) {
        it.image(x, y, &id(weather_fog_72));
    }
    else if ( not strcmp(id(forcast_condition)[2], "hail" )) {
        it.image(x, y, &id(weather_hail_72));
    }
    else if ( not strcmp(id(forcast_condition)[2], "lightning" )) {
        it.image(x, y, &id(weather_lightning_72));
    }
    else if ( not strcmp(id(forcast_condition)[2], "lightning-rainy" )) {
        it.image(x, y, &id(weather_lightningrainy_72));
    }
    else if ( not strcmp(id(forcast_condition)[2], "partlycloudy" )) {
        it.image(x, y, &id(weather_partlycloudy_72));
    }
    else if ( not strcmp(id(forcast_condition)[2], "pouring" )) {
        it.image(x, y, &id(weather_pouring_72));
    }
    else if ( not strcmp(id(forcast_condition)[2], "rainy" )) {
        it.image(x, y, &id(weather_rainy_72));
    }
    else if ( not strcmp(id(forcast_condition)[2], "snowy" )) {
        it.image(x, y, &id(weather_snowy_72));
    }
    else if ( not strcmp(id(forcast_condition)[2], "snowy-rainy" )) {
        it.image(x, y, &id(weather_snowyrainy_72));
    }
    else if ( not strcmp(id(forcast_condition)[2], "sunny" )) {
        it.image(x, y, &id(weather_sunny_72));
    }
    else if ( not strcmp(id(forcast_condition)[2], "windy" )) {
        it.image(x, y, &id(weather_windy_72));
    }
    else if ( not strcmp(id(forcast_condition)[2], "windy-variant" )) {
        it.image(x, y, &id(weather_windy_72));
    }
    else {
        it.image(x, y, &id(weather_hazy_72));
    }
}

void pageMain(){
    auto it = id(eink42);
    it.fill(COLOR_OFF);

    int x;
    int y;
    it.fill(COLOR_OFF);

    // Weather forecase
    x=200-132;
    y=250;
    wgForecasts(x, y);

    // Bus schedule
    x=0;
    y=300;
    wgBus(x,y);

    // Time and Date
    x = 395;
    y = 2;
    wgDateTime(x,y);

    // Temerature 40:
    int x0 = 0;
    int y0 = 0;
    wgTemerature40(x0,y0);
}

void pageClock(){
    auto it = id(eink42);
    it.fill(COLOR_OFF);

    uint16_t x = id(eink42_max_x)/2;
    uint16_t y = id(eink42_max_y)/2;
    it.strftime(x, y, &id(NotoSansMonoRegular96), COLOR_ON, TextAlign::CENTER, "%H:%M", id(sntp_time).now());
    // it.printf(x, y, &id(NotoSansMonoRegular22), COLOR_ON, TextAlign::TOP_LEFT, "Text" );
    // it.strftime(x, y, &id(NotoSansMonoRegular20), COLOR_ON, TextAlign::TOP_RIGHT, "%b %d", id(sntp_time).now());
    // //it.strftime(x+43, y+24, id(NotoSansMonoRegular20), COLOR_ON, TextAlign::TOP_RIGHT, "%d", id(sntp_time).now());
    // it.strftime(x, y+72, &id(NotoSansMonoRegular80), COLOR_ON, TextAlign::TOP_RIGHT, "%M", id(sntp_time).now());
}

void pageSwitch(){
    auto it = id(eink42);
    it.fill(COLOR_OFF);

    uint16_t x = id(eink42_max_x)/2;
    uint16_t y = id(eink42_max_y)/2;
    const uint16_t icon_size = 120;

    it.filled_circle(x, y, 10);
    it.circle(x, y, y-icon_size-1);

    it.image(x-icon_size/2, 0, &id(weather_cloudy_120));
    it.image(x-icon_size/2, id(eink42_max_y)-icon_size, &id(weather_fog_120));

    it.image(x+y-icon_size, y-icon_size/2, &id(weather_sunny_120));
    it.image(x-y, y-icon_size/2, &id(weather_windy_120));

}

void pageAlarms(){
    auto it = id(eink42);
    it.fill(COLOR_OFF);
}

void eink42Draw() {
    if ( id(eink42_page) == PAGESWITCHES)
        pageSwitch();
    else if ( id(eink42_page) == PAGEALARMS)
        pageAlarms();
    else if ( id(eink42_page) == PAGECLOCK)
        pageClock();
    else
        pageMain();
}

// void drawZigZag(int y, int l){
//     it.line(0, y, l, y);
//     it.line(l, y, l, y+l);
// }

// void drawRaster(void* it){
//     int y = 0;
//     int x;
//     for( int i=1;i<6;i++) {
//         y = 50*i;
//         it.line(0, y, 400, y);
//     }
//     for( int i=1;i<8;i++) {
//         x = 50*i;
//         it.line(x, 0, x, 300);
//     }
// }