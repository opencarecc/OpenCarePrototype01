#include <LGPS.h>      // GPS library
#include <stdio.h>
#include <LDisplay.h>  // LCD Display library

void setup()
{
//    Serial.begin(115200);
//    Serial.print("GPS test.\r\n");

    // initialize LCD Display    
    Lcd.init();
    Lcd.font_init();
    Lcd.back_light_level(50);
    Lcd.screen_set(0xffff00);  // set background color
    Lcd.draw_font(10, 10, "GPS test:", 0xffff00, 0, 20);  // write "GPS test" on the Display
}

void loop()
{
    // initalize variables
    unsigned char *utc_date_time = 0;
    char buffer[50] = {0,};
    
    // check if GPS module is connected
    if(LGPS.check_online())
    {
        Lcd.draw_font(100, 10, "online", 0xffff00, 0, 20);  // write "GPS online" on the Display since the GPS is connected
        
        // get GPS data
        utc_date_time = LGPS.get_utc_date_time();
        
        // print Date and Time
        sprintf(buffer, "UTC:%d-%d-%d  %d:%d:%d\r\n", utc_date_time[0], utc_date_time[1], utc_date_time[2], utc_date_time[3], utc_date_time[4],utc_date_time[5]);
        Lcd.draw_font(10, 40, buffer, 0xffff00, 0, 20);
        // Serial.print(buffer);
        
        
        // print Status
        sprintf(buffer, "Status %c\r\n", LGPS.get_status());
        Lcd.draw_font(10, 60, buffer, 0xffff00, 0, 20);
        // Serial.print(buffer);
        
        // print Latitude
        sprintf(buffer, "Lat %c:%f\r\n", LGPS.get_ns(), LGPS.get_latitude());
        Lcd.draw_font(10, 80, buffer, 0xffff00, 0, 20);
        // Serial.print(buffer);
        
        // print Longitude
        sprintf(buffer, "Long %c:%f\r\n", LGPS.get_ew(), LGPS.get_longitude());
        Lcd.draw_font(10, 100, buffer, 0xffff00, 0, 20);
        // Serial.print(buffer);
        
        // print Altitude
        sprintf(buffer, "Alt %f\r\n", LGPS.get_altitude());
        Lcd.draw_font(10, 120, buffer, 0xffff00, 0, 20);
        // Serial.print(buffer);
        
        // print Speed
        sprintf(buffer, "Speed %f\r\n", LGPS.get_speed());
        Lcd.draw_font(10, 140, buffer, 0xffff00, 0, 20);
        // Serial.print(buffer);
        
        // print number of satellites
        sprintf(buffer, "Sats %d\r\n", LGPS.get_sate_used());
        Lcd.draw_font(10, 160, buffer, 0xffff00, 0, 20);
        // Serial.print(buffer);
        
        // print Course
        sprintf(buffer, "Course %f\r\n", LGPS.get_course());
        Lcd.draw_font(10, 180, buffer, 0xffff00, 0, 20);
        // Serial.print(buffer);
        
        // print Position fix
        sprintf(buffer, "Position fix %c\r\n", LGPS.get_position_fix());
        Lcd.draw_font(10, 200, buffer, 0xffff00, 0, 20);
        // Serial.print(buffer);
        
        // print Mode
        sprintf(buffer, "Mode %c   Mode2 %c\r\n\r\n", LGPS.get_mode(), LGPS.get_mode2());
        Lcd.draw_font(10, 220, buffer, 0xffff00, 0, 20);
        // Serial.print(buffer);
        
    } else {
        Lcd.draw_font(100, 10, "offline", 0xffff00, 0, 20);  // write "GPS offline" on the Display since the GPS is not connected
    }    
    delay(1000);

    Lcd.draw_updata();
}
