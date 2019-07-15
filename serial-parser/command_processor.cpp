#include "Arduino.h"
#include "command_processor.h"

void processCommand(char* msgAddr)
{       
    if (strncmp(msgAddr, "AXX", 3) != 0)
      return; // not a linkplay command
      
    process_linkplay_commands(msgAddr);
}

 
uint8_t process_linkplay_commands(char* linkplay_command)
{
    switch (linkplay_command[4])
    {
        case 'B':
            process_b_commands(linkplay_command);
            break;
        case 'C':
            process_c_commands(linkplay_command);
            break;
        case 'D':
            process_d_commands(linkplay_command);
            break;
        case 'E':
            process_e_commands(linkplay_command);
            break;
        case 'F':
            process_f_commands(linkplay_command);
            break;
        case 'L':
            process_l_commands(linkplay_command);
            break;
        case 'M':
            process_m_commands(linkplay_command);
            break;
        case 'P':
           process_p_commands(linkplay_command);
            break; 
        case 'R':
            process_r_commands(linkplay_command);
            break;
        case 'S':
            process_s_commands(linkplay_command);
            break;
        case 'V':
            process_v_commands(linkplay_command);
            break;
        case 'W':
            process_w_commands(linkplay_command);
            break;
        default:
            break;
    }
}
 
uint8_t process_b_commands(char* linkplay_command)
{
    switch (linkplay_command[5])
    {
        case 'O':
            process_bot_command(linkplay_command);                      // Linkplay boot commnads
            break;
        case 'U':
            process_bur_command(linkplay_command);                      // Linkplay firmware updating commands
            break;
        default:
            //error_handler();
            break;
    }
}
 
uint8_t process_c_commands(char* linkplay_command)
{
    switch (linkplay_command[5])
    {
        case 'A':
            process_cap_command(linkplay_command);                      // Linkplay commands after factory reset
            break;
        case 'H':
            process_chn_command(linkplay_command);                      // Linkplay channel information (stereo / mono left / mono right)
            break;
        default:
            //error_handler();
            break;
    }
}
 
uint8_t process_d_commands(char* linkplay_command)
{
    switch (linkplay_command[5])
    {
        case 'E':
            process_dev_command(linkplay_command);                      // Linkplay device query commands
            break;
        default:
            //error_handler();
            break;  
    }   
}
 
uint8_t process_e_commands(char* linkplay_command)
{
    switch (linkplay_command[5])
    {
        case 'T':
            process_eth_command(linkplay_command);                      // Linkplay ethernet commands
            break;
        default:
            //error_handler();
            break;  
    }  
}
 
uint8_t process_f_commands(char* linkplay_command)
{
    switch (linkplay_command[5])
    {
        case 'A':
            process_fac_command(linkplay_command);                      // Linkplay factory reset commands
            break;
        default:
            //error_handler();
            break;  
    }  
}
 
uint8_t process_l_commands(char* linkplay_command)
{
    switch (linkplay_command[5])
    {
        case 'E':
            process_led_command(linkplay_command);                      // Linkplay factory teset commands
            break;
        default:
            //error_handler();
            break;  
    }  
}
 
uint8_t process_m_commands(char* linkplay_command)
{
    switch (linkplay_command[5])
    {
        case 'C':
            process_mcu_command(linkplay_command);                      // Linkplay queries of our microprocessor
            break;
        case 'E':
            process_mea_command(linkplay_command);                      // Linkplay meadia metadata commands
            break;
        case 'U':
            process_mut_command(linkplay_command);                      // Linkplay command to mute audio
            break;
        case '2':
            process_m2s_command(linkplay_command);                      // Linkplay master to slave command pass through
            break;        
        default:
            //error_handler();
            break;
    }
}
 
uint8_t process_p_commands(char* linkplay_command)
{
    switch (linkplay_command[6])
    {
        case 'M':
            process_plm_command(linkplay_command);                      // Linkplay playback mode commands
            break;
        case 'P':
            process_plp_command(linkplay_command);                      // Linkplay repeat mode commands
            break;
        case 'Y':
           process_ply_command(linkplay_command);                      // Linkplay playback commands
            break;     
        default:
            //error_handler();
            break;  
    }
}
 
uint8_t process_r_commands(char* linkplay_command)
{
    switch (linkplay_command[5])
    {
        case 'A':
            process_ra0_command(linkplay_command);                      // Linkplay wifi access point information commands
            break;
        default:
            //error_handler();
            break;  
    }  
}
 
uint8_t process_s_commands(char* linkplay_command)
{
    switch (linkplay_command[5])
    {
        case 'E':
            process_set_command(linkplay_command);                      // Linkplay set time change commands (YYYYMMDDHHMMSS and mon/tue/wed/.../sun)
            break;
        case 'T':
            process_sta_command(linkplay_command);                      // Linkplay wireless status commands
            break;
        case '2':
            process_s2m_command(linkplay_command);                      // Linkplay slave to master command pass through
            break;  
        default:
            //error_handler();
            break;
    }
}
 
uint8_t process_v_commands(char* linkplay_command)
{
    switch (linkplay_command[5])
    {
        case 'O':
            process_vol_command(linkplay_command);                      // Linkplay volume adjusting commands
            break;
        default:
            //error_handler();
            break;  
    }  
}
 
uint8_t process_w_commands(char* linkplay_command)
{
    switch (linkplay_command[5])
    {
        case 'A':
            process_wan_command(linkplay_command);
            break;
        case 'P':
            process_wps_command(linkplay_command);                      // Linkplay wireless WPS config commands
            break;  
        case 'W':
            process_www_command(linkplay_command);                      // Linkplay internet connection commands
            break;  
        default:
            //error_handler();
            break;  
    }
}





uint8_t process_bot_command(char* linkplay_command)                   // Linkplay firmware updating commands
{
  digitalWrite(13, HIGH);


}


uint8_t process_bur_command(char* linkplay_command)                   // Linkplay firmware updating commands
{
    /*switch(linkplay_command[])
    {
        case "G"
            process_set_command(linkplay_command);                      // Linkplay set time change commands (YYYYMMDDHHMMSS and mon/tue/wed/.../sun)
            break;
        case "1":
            process_sta_command(linkplay_command);                      // Linkplay wireless status commands
            break;
        case "2":
            process_s2m_command(linkplay_command);                      // Linkplay slave to master command pass through
            break;  
        default:
            error_handler();
            break;
 
    }*/
     //   "AXX+BURNING"                                                   // wifi is updating firmware
    //   "AXX+BURN002"                                                   // wifi update was succesful
     //   "AXX+BURN003"                                                   // WiFi update failed
}
 
uint8_t process_cap_command(char* linkplay_command)                   // Linkplay commands after factory reset
{   /*
        "AXX+CAP+GET"                                                   // command on the first boot after a factory reset. The returned information will be saved permanently.
    */
    Serial.println("Linkplay booted after factory reset, needs pertinent information");
    //reset_linplay_product_information();
}
 
uint8_t process_chn_command(char* linkplay_command)                    // Linkplay channel information (stereo / mono left / mono right)
{   /*
        "AXX+CHN+nnn"                                                   // WiFi sends this command to update the channel information
                                                                        // 000 Stereo
                                                                        // 001 Left channel
                                                                        // 002 Right channel
    */
   
    uint16_t audio_channel_status = 0;
 
    audio_channel_status = linkplay_command_data_extraction(linkplay_command);
 
    switch(audio_channel_status)
    {
      case e_stereo:
          Serial.println("audio is in stereo");
          break;
      case e_left_chan:
          Serial.println("audio is only left chan");
          break;
      case e_right_chan:
          Serial.println("audio is only righ chan");
          break;
      default:
          break;
    }
    
    return 0;
}
 
uint8_t process_dev_command(char* linkplay_command)                    // Linkplay device query commands
{
       // "AXX+DEV+RST"                                                   // MCU should NOT automatically reboot or power off WiFi module after updating the firmware.
                                                                        // It should wait for WiFi module to send AXX+DEV+RST or AXX+DEV+RST in case AXX+DEV+RST gets lost.

       Serial.println("linplay is resetting - don't poll it until it gives the ok");
}
 
uint8_t process_eth_command(char* linkplay_command)                    // Linkplay ethernet commands
{
    /*
        "AXX+ETH+xxx"                                                   // WiFi sends this command to update the Ethernet status to MCU,
                                                                        // or reply MCU's MCU+ETH+GET command where xxx is the status code
                                                                        // 000 Unplugged
                                                                        // 001 Plugged
                                                                        // FFF Disabled
    */
  
    uint16_t ethernet_status = 0;
 
    ethernet_status = linkplay_command_data_extraction(linkplay_command);
 
    switch(ethernet_status)
    {
      case e_ethernet_disconnected:
          Serial.print("Ethernet is disconnected");
          break;
      case e_ethernet_connected:
          Serial.print("Ethernet is connected!");
          break;
      default:
          break;
    }
    return 0;
}
 
uint8_t process_fac_command(char* linkplay_command)                    // Linkplay factory reset commands
{
     //   "AXX+FACTORY"                                                   // WiFi sends this command to notify MCU that it is going to do a factory reset
     Serial.println("Linkplay is factory resetting.\nWe'll need to supply it information upon it rebooting.");
}
 
uint8_t process_led_command(char* linkplay_command)                    // Linkplay factory teset commands
{
      //  "AXX+LED+TES"                                                   // Notify MCU that the module is in factory test mode
      Serial.println("Linkplay is in test mode. flashing LEDs (not hooked up)");
}
 
uint8_t process_mcu_command(char* linkplay_command)                    // Linkplay queries of our microprocessor
{
      /*  
        "AXX+MCU+VER"                                                   // command to check MCU frimware version"
        "AXX+MCU+UPDversion:len:name&"                                  // command to request a MCU firmware upgrade, where version is the new version number,
                                                                        // len is the total length and name is the project name.
        "AXX+MCU+RUNindex:len:data&"                                    // command where index is the index of firmware packet, ranging from 000 to 999,
                                                                        // len is the length of this packet, usually 1024, and data is the actual data.
                                                                        // Data is sent as is, except special bytes, including '\0', '&', '0', '+'.
                                                                        // The first 4-byte is the check-sum, sent in little endian format.
                                                                        // Special bytes  '\0', '&', '0', '+' are converted as follows
                                                                        // '\0' -> "01"
                                                                        // '&' -> "02"
                                                                        // '0' -> "00"
             */                                                           // '+' -> "03
}
 
uint8_t process_mea_command(char* linkplay_command)                    // Linkplay meadia metadata commands
{
    /*
        "AXX+MEA+RDY"                                                   // Notify MCU that the WiFi module is ready to respond to MCU+MEA+GET
        "AXX+MEA+DAT(metadata)&"                                        // Update metadata, where metadata is a JSON message
    */
    char hex_title[100];
    char hex_artist[100];
    char hex_album[100];
    char ascii_title[100];
    char ascii_artist[100];
    char ascii_album[100];
    uint16_t n = 0; 
    uint16_t l = 0; 
    uint16_t m = 0; 
    uint16_t p = 0; 
    uint16_t q = 0; 
    uint16_t i = 0; 


    memset(hex_title, 0, 100);
    memset(hex_artist, 0, 100);    
    memset(hex_album, 0, 100);
    
    if (strncmp((linkplay_command + 8), "RDY", 3) == 0)
    {
      Serial.println("media is ready!");
      Serial1.write("MCU+MEA+DAT");
    }
    else
    {
      for(i = 11; i < 1024; i++)
      {
          if (linkplay_command[i] == ';')
          {
              n = i; 
              break; 
          }
      }
      strncpy(hex_title, (linkplay_command + 11), n-12);
      strncat(hex_title, "\0", n);
      hex2ascii(hex_title, ascii_title, strlen(hex_title), strlen(ascii_title));
      Serial.println(ascii_title);

      for(i = n+1; i < 1024; i++)
      {
          if (linkplay_command[i] == ';')
          {
              l = i; 
              break; 
          }
      }   
      strncpy(hex_artist, (linkplay_command + n+1), l-(1+n));
      strncat(hex_artist, "\0", l);
      hex2ascii(hex_artist, ascii_artist, strlen(hex_artist), strlen(ascii_artist));
      Serial.println(ascii_artist);

      for(i = l+1; i < 1024; i++)
      {
          if (linkplay_command[i] == '&')
          {
              m = i; 
              break; 
          }
      }   
      strncpy(hex_album, (linkplay_command + l+1), m-l); 
      strncat(hex_album, "\0", m);
      hex2ascii(hex_album, ascii_album, strlen(hex_album), strlen(ascii_album));
      Serial.println(ascii_album);
      i = m = n = l = 0;
    }
}
 
uint8_t process_mut_command(char* linkplay_command)                    // Linkplay command to mute audio
{
    /*
        "AXX+MUT+000"                                                   // WiFi sends this command to request MCU to unmute the spekaer
        "AXX+MUT+001"                                                   // WiFi sends this command to request MCU to mute the speaker
    */
    uint16_t mute_status = 0;
 
    mute_status = linkplay_command_data_extraction(linkplay_command);
 
   /* if (mute_status > mute_states)
        return 1;  //error
   */
   // set_system_mute_status(mute_status);
    return 0;
}
 
uint8_t process_m2s_command(char* linkplay_command)                    // Linkplay master to slave command pass through
{
       // "AXX+M2S+nnn"                                                   // When a pass-through session starts, slave speakers will receive AXX+M2S+nnn
}
 
uint8_t process_plm_command(char* linkplay_command)                    // Linkplay playback mode commands
{
    /*
        "AAX+PLM+GET"
        "AXX+PLM+nnn"                                                   // WiFi sends this command to notify MCU mode switch, where nnn is defined below
                                                                        // 000 None
                                                                        // 001 Airplay
                                                                        // 002 DLNA
                                                                        // 010 to 019 A play list played by Wiimu protocol, where 011 means a play list for music stroed in USB disk,
                                                                        // 016 means a play list for music stored in T-Flash card
                                                                        // 020 to 029 A play list played by third party HTTP APIs, where 021 means a play list for music stroed in USB disk,
                                                                        // 026 means a play list for music stored in T-Flash card
                                                                        // 040 - Line in (aka Aux-In)
                                                                        // 041 - BT
                                                                        // 042 - External USB Disk or T-Flash
                                                                        // 043 - Optical
                                                                        // 044 - RCA
                                                                        // 045 - Coaxial
                                                                        // 050 - Mirror
                                                                        // 099 - Slave
    */
 
    uint16_t playback_mode_status = 0;
 
    playback_mode_status = linkplay_command_data_extraction(linkplay_command);
 
    /*switch(playback_mode_status)   
    {
        case e_none:
        case e_airplay:
        case e_DLNA:
        case e_thumb_drive:
        case e_line_in:
        case e_bluetooth:
        case e_optical:
        case e_rca:
        case e_coaxial:
        case e_mirror:
        case e_slave:
            //set_system_linkplay_repeat_status(repeat_status);
            return 0;
        default:
            error_handle();
            return 1;
    }
 */
}
 
uint8_t process_plp_command(char* linkplay_command)                    // Linkplay repeat mode commands
{
    /*
        "AXX+PLP+xxx"                                                   // WiFi sends this command to update the repeat mode, where xxx is
                                                                        // 000 Repeat all
                                                                        // 001 Repeat current
                                                                        // 002 Shuffle, repeat all
                                                                        // 003 Shuffle, no repeat
                                                                        // Other No repeat
    */
 
    uint16_t repeat_status = 0;

    repeat_status = linkplay_command_data_extraction(linkplay_command);

    switch (repeat_status)
    {
        case e_repeat_all:
            Serial.print("repeat all songs");
            break;
        case e_repeat_current:
            Serial.print("repeat all currnet song");
            break;
        case e_shuffle_repeat:
            Serial.print("shuffle and repeat playlist");
            break;
        case e_shuffle_no_repeat:
            Serial.print("shuffle, no repeat");
            break;  
        default:
            break;
    }
    return 0;
}
 
uint8_t process_ply_command(char* linkplay_command)                    // Linkplay playback commands
{
    /*
        "AXX+PLY+xxx"                                                   // WiFi sends this command to update the playback status, where xxx is the status
                                                                        // 000 Stopped
                                                                        // 001 Playing
    */
  
    uint16_t playback_status_int = 0;
 
    playback_status_int = linkplay_command_data_extraction(linkplay_command);

    switch (playback_status_int)
    {
        case e_stopped_playback:
            Serial.println("playback started");
            break;
          
        case e_playback_started:
            Serial.println("playback started");
            break;
    }
    return 0;
}
 
uint8_t process_ra0_command(char* linkplay_command)                    // Linkplay wifi access point information commands
{
    /*
        "AXX+RA0+xxx"                                                   // WiFi sends this command to update its hotspot status to MCU,
                                                                        // or reply MCU's MCU+RA0+GET command where xxx is the status code
                                                                        // 000 No client
                                                                        // 001 New client connected
                                                                        // 002 One client disconnected but there are still some clients connected
                                                                        // FFF Hotspot is hidden
    */
 
    uint16_t access_point_status = 0;
 
    access_point_status = linkplay_command_data_extraction(linkplay_command);

    switch(access_point_status)
    {
        case e_hotspot_off:
          Serial.println("the wifi hotspot is on");
          break;
        case e_hotspot_on:  
          Serial.println("the wifi hotspot is off");
          break;
        default:
            break;
    }

    return 0;
}
 
uint8_t process_set_command(char* linkplay_command)                    // Linkplay set time change commands (YYYYMMDDHHMMSS and mon/tue/wed/.../sun)
{
    /*   
        "AXX+SET+RTCYYYYMMDDHHMMSS&"                                    // Notify MCU the time change, where YYYYMMDDHHMMSS is the new time                           
        "AXX+SET+WEKn&"                                                 // Notify MCU the day of week, where n means Sun to Sat 0 - Sun 1 - Mon ... 6 - Sat
    */
    uint8_t day_of_the_week = 0;
    uint16_t current_year = 0;
    uint8_t current_month = 0;
    uint8_t current_day = 0;
    uint8_t current_hour = 0;
    uint8_t current_minute = 0;
    uint8_t current_second = 0;
    char c_day_of_the_week[2];
    char c_current_year[5];
    char c_current_month[5];
    char c_current_day[5];
    char c_current_hour[5];
    char c_current_minute[5];
    char c_current_second[5];
    
    if (strncmp((linkplay_command + 8), "RTC", 3) == 0)
    {
        strncpy(c_current_year, linkplay_command+11, 4);
        current_year = atoi(c_current_year);

        strncpy(c_current_month, linkplay_command+15, 2);
        current_month = atoi(c_current_month);

        strncpy(c_current_day, linkplay_command+17, 2);
        current_day = atoi(c_current_day);

        strncpy(c_current_hour, linkplay_command+19, 2);
        current_hour = atoi(c_current_hour);

        strncpy(c_current_minute, linkplay_command+21, 2);
        current_minute = atoi(c_current_minute);

        strncpy(c_current_second, linkplay_command+23, 2);
        current_second = atoi(c_current_second);

        Serial.print("current YYYY: ");
        Serial.println(current_year); 
      
        Serial.print("MM: ");
        Serial.println(current_month); 
      
        Serial.print("DD: ");
        Serial.println(current_day); 
      
        Serial.print("HH: ");
        Serial.println(current_hour); 
      
        Serial.print("MM: ");
        Serial.println(current_minute); 
      
        Serial.print("SS: ");
        Serial.println(current_second); 
    }
    else
    {
        strncpy(c_day_of_the_week, linkplay_command+11, 1);
        day_of_the_week = atoi(c_day_of_the_week);
        
        switch(day_of_the_week)
        {
            case e_sunday:
                Serial.println("Sunday"); 
                break;
            case e_monday:
                Serial.println("Monday"); 
                break;
            case e_tuesday:
                Serial.println("Tuesday"); 
                break;
            case e_wednesday:
                Serial.println("Wednesday"); 
                break;
            case e_thursday:
                Serial.println("Thursday"); 
                break;
            case e_friday:
                Serial.println("Friday"); 
                break;
            case e_saturday:
                Serial.println("Saturday"); 
                break;
            default:
                break;
        }    
    }
     
}
 
uint8_t process_sta_command(char* linkplay_command)                    // Linkplay wireless status commands
{
    /*
        "AXX+STA+000"                                                   // Failed to connect to the AP
        "AXX+STA+001"                                                   // Successfully connected to the AP
        "AXX+STA+002"                                                   // Connecting to the AP
        "AXX+STA+003"                                                   // Following the AXX+STA+000 command, indicating bad RSSI
        "AXX+STA+004"                                                   // Following the AXX+STA+000 command, indicating wrong password
        "AXX+STA+005"                                                   // Following the AXX+STA+000 command, indicating wrong security type
        "AXX+STA+006"                                                   // Following the AXX+STA+000 command, can't find (scan) AP
        "AXX+STA+007"                                                   // Following the AXX+STA+000 command, failed to get IP address from a DHCP server
    */
    uint16_t wireless_status = 0;
 
    wireless_status = linkplay_command_data_extraction(linkplay_command);
 
    switch(wireless_status)
    {
      case e_failed_to_connect:
          Serial.println("failed to connect to access point"); 
          break;
      case e_succesfully_connected:
          Serial.println("successfully connected to access point!"); 
          break;
      case e_connecting_to_ap:
          Serial.println("connecting to access point..."); 
          break;
      case e_bad_rssi:
          Serial.println("failed to connect, bad rssi"); 
          break;
      case e_wrong_password:
          Serial.println("failed to connect, wrong password"); 
          break;
      case e_wrong_security_type:
          Serial.println("failed to connect, wrong security type"); 
          break;
      case e_cant_find_ap:
          Serial.println("failed to connect, can't find access point"); 
          break;
      case e_failed_to_get_ip_address: 
          Serial.println("failed to connect, can't get ip address"); 
          break;
       default:
          break; 
    }
    return 0;
}
 
uint8_t process_s2m_command(char* linkplay_command)                    // Linkplay slave to master command pass through
{
       // "AXX+S2M+nnn"                                                   // When a pass-through session starts, master speaker MCU will receive AXX+S2M+nnn
      Serial.println("PIC initiated master pass thorugh to slave linkplays");
}
 
uint8_t process_vol_command(char* linkplay_command)                    // Linkplay volume adjusting commands
{
    /*
        "AXX+VOL+GET"                                                   // Get the current volume level
        "AXX+VOL+xxx"                                                   // WiFi module will confirm volume change by replying AXX+VOL+xxx
        "AXX+VOL+nnn"                                                   // WiFi module sends this command to request volume change,
                                                                        // where nnn is the volume (0 to 100)
    */
    uint16_t volume_int = 0;

    if (strncmp((linkplay_command + 8), "GET", 3) == 0)
    {
        Serial.println("Get the PIC current volume");
    }
    else
    {
        volume_int = linkplay_command_data_extraction(linkplay_command);
        Serial.print("set volume to: ");
        Serial.println(volume_int);
    }  
}
uint8_t process_wan_command(char *linkplay_command)
{
    //  AXX+WAN+LST4E4554474541523137,0,1;7866696E69747977696669,0,0;726F636C6F6E65,0,1&
    char hex_ap[100];
    char ascii_ap[100];

    uint16_t i = 0;
    uint8_t num_aps = 0;

    if (linkplay_command[11] != '&')
    {
        num_aps += 1;
    }
    
    for (i = 12; i < 1024; i++)
    {
        if (linkplay_command[i] == ';')
        {
            num_aps += 1;
        }

        if (linkplay_command[i] == '&')
        {
            break;
        }
    }
    
    Serial.println(num_aps);
    
    /*
    strncpy(hex_ap, (linkplay_command + 11), m); 
    strncat(hex_ap, "\0", m);
    hex2ascii(hex_ap, ascii_ap, strlen(hex_ap), strlen(ascii_ap));
    Serial.println(ascii_ap);*/
}

uint8_t process_wps_command(char* linkplay_command)                    // Linkplay wireless WPS config commands
{
    /*
        "AXX+WPS++ON"                                                   // WPS/Smart Config process starts
    */
     switch(linkplay_command[11])
     {
        case 'F':
            Serial.println("WPS has been turned off");
            break;
        case 'N':
            Serial.println("WPS has been turned on");
            break;
        default:
            break;
     }      
}
 
uint8_t process_www_command(char* linkplay_command)                    // Linkplay internet connection commands
{  
    /*
        "AXX+WWW+xxx"                                                   // WiFi sends this command to update its Internet connection status to MCU,
                                                                        // or reply MCU's MCU+WWW+GET command where xxx is the status code
                                                                        // 000 No Internet connection 
                                                                        // 001 Internet connection is available
    */
    
    uint16_t cunnection_status = 0;
    
    cunnection_status = linkplay_command_data_extraction(linkplay_command);
    
    switch(cunnection_status)
    {
      case e_no_internet_connection:
          Serial.println("no internet connection!");
          break;
      case e_connected_to_internet:
          Serial.println("connected to the internet!");
          break;   
      default: 
          break;
    }
    return 0;
}
 
uint16_t linkplay_command_data_extraction(char* linkplay_command)
{
    char status_str[4] = "";
 
    strncpy(status_str, linkplay_command + 8, 3);                       // copy last three chars into string "AXX+WWW+xxx"
    strcat(status_str, "\0");  
    return(atoi(status_str));
}






int16_t hex2ascii(const char *hexArray, char *asciiArray, uint8_t hexArrayLength, uint8_t charArrayLength)
{
        int16_t i = 0;
        int16_t j = 0;
        memset(asciiArray, 0, charArrayLength);
        
        for (i = 0; i<hexArrayLength; i+=2 )
        {
            char val1 = hexArray[i];
            char val2 = hexArray[i+1];
                
            if( val1 > 0x60) 
            {
                val1 -= 0x57;
            }
            else if(val1 > 0x40) 
            {
                val1 -= 0x37;
            }
            else 
            {
                val1 -= 0x30;
            }
                
            if( val2 > 0x60)
            {
                val2 -= 0x57;
            }
            else if(val2 > 0x40)
            {
                val2 -= 0x37;
            }
            else 
            {
                val2 -= 0x30;
            }
                
            if(val1 > 15 || val2 > 15 || val1 < 0 || val2 < 0)
            {
                return 0;
            }
                        
            asciiArray[j] = val1*16 + val2;        
            j++;
        }
        return j;
}

/*
AXX+MUT+001
AXX+PMT+001
AXX+WAN+LST&
AXX+WAN+LST43656E747572794C696E6B34373338,0,1&
AXX+BOT+DON
AXX+WAN+LST&
AXX+WAN+LST4E4554474541523137,0,1;7866696E69747977696669,0,0;726F636C6F6E65,0,1&
AXX+STA+000
AXX+STA+006
*/

// AXX+MEA+DAT54686520536967687473;456e746572205368696b617269;54686520537061726b&
