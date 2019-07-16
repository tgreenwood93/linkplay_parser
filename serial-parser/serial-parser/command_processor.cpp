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
        case 'G':
            process_g_commands(linkplay_command);
            break;
        case 'I':
            process_i_commands(linkplay_command);
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
            break;  
    }  
}

uint8_t process_g_commands(char* linkplay_command)
{
    switch (linkplay_command[5])
    {
        case 'E':
            process_get_command(linkplay_command);                     // Linkplay factory get commands
            break;
        default:
            break;  
    }  
}

uint8_t process_i_commands(char* linkplay_command)
{
    switch (linkplay_command[5])
    {
         case '2':
            process_i2s_command(linkplay_command);                     // Linkplay factory get commands
            break;
        default:
            break;  
    }
}
uint8_t process_l_commands(char* linkplay_command)
{
    switch (linkplay_command[5])
    {
        case 'E':
            process_led_command(linkplay_command);                      // Linkplay factory reset commands
            break;
        default:
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
        case 'I':
            process_mic_command(linkplay_command);                      // Linkplay meadia metadata commands
            break;            
        case 'U':
            process_mut_command(linkplay_command);                      // Linkplay command to mute audio
            break;
        case '2':
            process_m2s_command(linkplay_command);                      // Linkplay master to slave command pass through
            break;        
        default:
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
        case 'T':
            process_pmt_command(linkplay_command);
            break;
        case 'Y':
            process_ply_command(linkplay_command);                      // Linkplay playback commands
            break;     
        default:
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
            break;  
    }
}

uint8_t process_bot_command(char* linkplay_command)                   // Linkplay firmware updating commands
{
    if (strncmp((linkplay_command + 8), "DON", 3) == 0)
    {   
        Serial.println("Linkplay is done booting. This is also the heartbeat command");
    }
    else
    {
        Serial.println("Linkplay is done booting. This one time command acknowledges that");  
    }
}


uint8_t process_bur_command(char* linkplay_command)                   // Linkplay firmware updating commands
{
/*
        "AXX+BURNING"                                                   // wifi is updating firmware
        "AXX+BURN002"                                                   // wifi update was succesful
        "AXX+BURN003"                                                   // WiFi update failed
*/
    switch(linkplay_command[10])
    {
        case 'G':
            Serial.println("Linkplay is updating its firmware!");
            break;
        case '1':
            Serial.println("Linkplay firmware update successful");
            break;
        case '2':
            Serial.println("Linkplay firmware update failed!");
            break;  
        default:
            break;
    }       
}
 
uint8_t process_cap_command(char* linkplay_command)                   // Linkplay commands after factory reset
{   /*
        "AXX+CAP+GET"                                                   // command on the first boot after a factory reset. The returned information will be saved permanently.
    */
    Serial.println("Linkplay booted after factory reset, needs pertinent information");
    Serial1.print("MCU+CAP+PRJPSAUDIO_Stellar&");
    Serial1.print("MCU+PTV+000");
    Serial1.print("MCU+SPY+BRNPSAUDIO&");
    Serial1.print("MCU+SPY+NAMStellarIntegrated&");
    Serial1.print("MCU+SPY+TYP0&");
    Serial1.print("MCU+CAP+00100001100&");
    Serial1.print("MCU+CAP+00200000800&");
    Serial1.print("MCU+CAP+LAUen_us&");
    
    Serial1.print("MCU+CAP+STMfffffffc&");
    Serial1.print("MCU+CAP+PLM00000000&");
    Serial1.print("MCU+PRESET+3&");
}
 
uint8_t process_chn_command(char* linkplay_command)                    // Linkplay channel information (stereo / mono left / mono right)
{   /*
        "AXX+CHN+GET"                                                   // What is our output channel config set to?
        "AXX+CHN+nnn"                                                   // WiFi sends this command to update the channel information
                                                                        // 000 Stereo
                                                                        // 001 Left channel
                                                                        // 002 Right channel
    */
    uint16_t audio_channel_status = 0;

    if (strncmp((linkplay_command + 8), "GET", 3) == 0)
    {
        Serial.println("Get the output channel congifuration for linkplay: Stereo, Left, or Right");
    }
    else
    { 
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
}
 
uint8_t process_dev_command(char* linkplay_command)                    // Linkplay device query commands
{
       // "AXX+DEV+RST"                                                   // MCU should NOT automatically reboot or power off WiFi module after updating the firmware.
                                                                        // It should wait for WiFi module to send AXX+DEV+RST or AXX+DEV+RST in case AXX+DEV+RST gets lost.

       Serial.println("linkplay is resetting - don't poll it until it gives the ok");
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

    if (strncmp((linkplay_command + 8), "FFF", 3) == 0)
    {
        Serial.println("Ethernet is disabled");
    }
    else
    {
        ethernet_status = linkplay_command_data_extraction(linkplay_command);
     
        switch(ethernet_status)
        {
            case e_ethernet_disconnected:
                Serial.println("Ethernet is disconnected");
                break;
            case e_ethernet_connected:
                Serial.println("Ethernet is connected!");
                break;
            default:
                break;
        }
    }
    return 0;
}
 
uint8_t process_fac_command(char* linkplay_command)                    // Linkplay factory reset commands
{
    //   "AXX+FACTORY"                                                   // WiFi sends this command to notify MCU that it is going to do a factory reset
    Serial.println("Linkplay is factory resetting.\nWe'll need to supply it information upon it rebooting.");
}

uint8_t process_get_command(char* linkplay_command)
{
    Serial.println("Set SSID of linkplay");
    Serial1.println("MCU+SID+StellarIntegrated");
}

uint8_t process_i2s_command(char* linkplay_command)
{
    // AXX+I2S+INF44100_16&
    char c_sample_rate[100];
    char c_bit_depth[100];
    uint8_t sample_rate_chars = 0; 
    uint16_t i = 0; 
    uint16_t off_set = 11; 
    uint16_t samp_depth = 0; 
    
    if (linkplay_command[11] == '&')
    {
        return 1;  
    }
  
    for (i = off_set; i < strlen(linkplay_command); i++)
    {
        sample_rate_chars++; 
        if ((linkplay_command[i] == '_') || (linkplay_command[i] == '&'))
        {
            break; 
        }
    }
 
        strncpy(c_sample_rate,linkplay_command+11, sample_rate_chars);
        switch(atoi(c_sample_rate))
        {
            case 44100:
                Serial.println("44.1 k");
                break;
            case 48000:
                Serial.println("48 k");
                break;
            case 88200:
                Serial.println("88.2 k");
                break;
            case 96000:
                Serial.println("96 k");
                break;
            case 176400:
                Serial.println("176.4 k");
                break;
            case 192000:
                Serial.println("192.2 k");
                break;
        }

        strncpy(c_bit_depth,linkplay_command+(11+sample_rate_chars), 2);
        Serial.print(atoi(c_bit_depth));
        Serial.println(" bit");
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
                                                                        // '+' -> "03
    */
    if (strncmp((linkplay_command + 8), "RDY", 3) == 0)
    {
        Serial.println("Linkplay is ready for communication!");
    }
    else if (strncmp((linkplay_command + 8), "VER", 3) == 0)
    {
        Serial.println("Send PIC firmware version ex: 0119");;
        Serial1.println("MCU+VER+0119&");
    }
}
 
uint8_t process_mea_command(char* linkplay_command)                    // Linkplay meadia metadata commands
{
    /*
        "AXX+MEA+RDY"                                                   // Notify MCU that the WiFi module is ready to respond to MCU+MEA+GET
        "AXX+MEA+DAT(metadata)&"                                        // Update metadata, where metadata is a JSON message
         AXX+MEA+DAT{ "title": "49277665204C6561726E656420546F204C6F7665204D7973656C66", "artist": "6C65746C6976652E", "album": "49662049276D2054686520446576696C2E2E2E", "vendor": "" }&

    */
    // linkplay song titles can only be 64 chars

    
    char hex_title[100];
    char hex_artist[100];
    char hex_album[100];
    char ascii_title[100];
    char ascii_artist[100];
    char ascii_album[100];
    uint16_t n = 0; 
    uint16_t l = 0; 
    uint16_t m = 0; 
    uint16_t z = 0; 
    uint16_t p = 0; 
    uint16_t q = 0; 
    uint16_t i = 0; 


    memset(hex_title, 0, 100);
    memset(hex_artist, 0, 100);    
    memset(hex_album, 0, 100);

    memset(ascii_title, 0, 100);
    memset(ascii_artist, 0, 100);    
    memset(ascii_album, 0, 100);
    
    if (strncmp((linkplay_command + 8), "RDY", 3) == 0)
    {
        Serial.println("media is ready!");
        Serial1.write("MCU+MEA+GET");
    }
    else
    {
        for(i = 23; i <= strlen(linkplay_command); i++)
        {
            if (linkplay_command[i] == '"')
            {
                n = i; 
                break; 
            }
        }
        strncpy(hex_title, (linkplay_command + 23), n-23);
        hex_title[n-22] = '\0';
        hex2ascii(hex_title, ascii_title, strlen(hex_title), strlen(ascii_title));
        Serial.println(ascii_title);

        for(i = (n+14); i < 1024; i++)
        {
            if (linkplay_command[i] == '"')
            {
                l = i; 
                break; 
            }
        }   
        q = l - (n+14);
        strncpy(hex_artist, (linkplay_command + (n+14)), q);
        hex_artist[q+1] = '\0';
        hex2ascii(hex_artist, ascii_artist, strlen(hex_artist), strlen(ascii_artist));
        Serial.println(ascii_artist);

        for(i = l+13; i < 1024; i++)
        {
            if (linkplay_command[i] == '"')
            {
                m = i; 
                break; 
            }
        }   
        z = m - (l+13);
        strncpy(hex_album, (linkplay_command + l+13), z); 
        hex_album[z+1] = '\0';
        hex2ascii(hex_album, ascii_album, strlen(hex_album), strlen(ascii_album));
        Serial.println(ascii_album);
        i = m = n = l = q = z = 0;
    }
}

uint8_t process_mic_command(char* linkplay_command)
{
    switch(linkplay_command_data_extraction(linkplay_command))
    {
        case 0: 
            Serial.println("Microphones turned off");
            break;
        default: 
            break;
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

    switch(mute_status)
    {
        case e_mute:
            Serial.println("mute output");
            break; 
        case e_unmute:
            Serial.println("unmute output");
            break; 
        default:
            break;  
    }
    return 0;
}
 
uint8_t process_m2s_command(char* linkplay_command)                    // Linkplay master to slave command pass through
{
       // "AXX+M2S+nnn"                                                // When a pass-through session starts, slave speakers will receive AXX+M2S+nnn
}

uint8_t process_nxt_command(char* linkplay_command)                    // Linkplay alarm commands
{
    uint16_t alarm_time = 0; 
    char c_alarm_time[100];
    uint16_t i = 0; 
    uint16_t num_chars = 0; 
    
    if (linkplay_command[11] == '-')
    {
        Serial.println("Linkplay alarm feature is disabled");  
    }
    for (i = 11; i < 1024; i++)
    {
        if (linkplay_command[i] == '&')
        {
            num_chars = (i - 1);
            break; 
        }    
    }
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
 
    switch(playback_mode_status)   
    {
        case e_none:
            Serial.println("no Linkplay input selected");
            break;
        case e_airplay:
            Serial.println("Airplay input selected");
            break;
        case e_DLNA:
            Serial.println("DLNA input selected");
            break;
        case e_thumb_drive:
            Serial.println("thumb drive input selected");
            break;
        case e_line_in:
            Serial.println("line-in input selected");
            break;
        case e_bluetooth:
            Serial.println("bluetooth input selected");
            break;
        case e_optical:
            Serial.println("optical input selected");
            break;
        case e_rca:
            Serial.println("rca input selected");
            break;
        case e_coaxial:
            Serial.println("coaxial Linkplay input selected");
            break;
        case e_mirror:
            Serial.println("mirror input selected");
            break;
        case e_slave:
            Serial.println("slave input selected");
            break;
        default:
            return 1;
    }
    return 0;
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
    // spotify doesn't trigger these messages. 
    
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
            Serial.println("playback stopped");
            break;  
        case e_playback_started:
            Serial.println("playback started");
            break;
    }
    return 0;
}
uint8_t process_pmt_command(char* linkplay_command)                    // Linkplay voice prompt commands
{
    switch(linkplay_command_data_extraction(linkplay_command))
    {
        case 0: 
            Serial.println("voice prompt start");
            break;
        case 1:
            Serial.println("voice prompt stopped");
            break; 
        case 2:
            Serial.println("voice prompt disabled");
            break; 
        case 3: 
            Serial.println("voice prompt can be triggered by PIC");
            break;        
    }
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
    
    if (strncmp((linkplay_command + 8), "+ON", 3) == 0)
    {
        Serial.println("Linkplay hotspot is on");           
    }
    else if (strncmp((linkplay_command + 8), "OFF", 3) == 0)
    {
        Serial.println("Linkplay hotspot is off");           
    }
    else if (strncmp((linkplay_command + 8), "FFF", 3) == 0)
    {
        Serial.println("Linkplay hotspot is hidden");           
    }
    else
    {
        access_point_status = linkplay_command_data_extraction(linkplay_command);

        Serial.print("there are/is ");
        Serial.print(access_point_status);
        Serial.println(" device(s) connected to the hotspot");           
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
        strncpy(c_current_month, linkplay_command+15, 2);
        strncpy(c_current_day, linkplay_command+17, 2);
        strncpy(c_current_hour, linkplay_command+19, 2);
        strncpy(c_current_minute, linkplay_command+21, 2);
        strncpy(c_current_second, linkplay_command+23, 2);

        Serial.print("current YYYY: ");
        Serial.println(atoi(c_current_year)); 
      
        Serial.print("MM: ");
        Serial.println(atoi(c_current_month)); 
      
        Serial.print("DD: ");
        Serial.println(atoi(c_current_day)); 
      
        Serial.print("HH: ");
        Serial.println(atoi(c_current_hour)); 
      
        Serial.print("MM: ");
        Serial.println(atoi(c_current_minute)); 
      
        Serial.print("SS: ");
        Serial.println(atoi(c_current_second)); 
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
    //  AXX+WAN+LST5053415544494F,10,1;50534755455354,10,1;5053417564696F5850,10,1&

    /*
        "AXX+VOL+GET"                                                   // Get the current volume level
        "AXX+VOL+xxx"                                                   // WiFi module will confirm volume change by replying AXX+VOL+xxx
        "AXX+VOL+nnn"                                                   // WiFi module sends this command to request volume change,
                                                                        // where nnn is the volume (0 to 100)
    */
    
    char hex_ap[100];
    char ascii_ap[100];
    
    uint16_t string_size = 0; 
    uint16_t current_wan_status = 0;
    uint16_t pos = 0;
    uint16_t status_type = 0;
    uint8_t num_aps = 0;
    uint16_t string_begin = 11;

    if (linkplay_command[11] != '&')
    {
        num_aps += 1;
    }
    else
    {
        Serial.println("Can't find any networks");
        return 1; 
    }
    
    for (pos = 12; pos < 1024; pos++)
    {
        if (linkplay_command[pos] == ';')
        {
            num_aps += 1;
        }
        else if (linkplay_command[pos] == '&')
        {
            break;
        }
    }
    
    Serial.print("Found ");
    Serial.print(num_aps);
    Serial.println(" network(s):");   
    
    for ( current_wan_status = 0; current_wan_status < (num_aps * num_status_per_wan); current_wan_status++)
    {
        for (pos = string_begin; pos < 1024; pos++)
        {
            string_size++;
            if ((linkplay_command[pos] == ',') || (linkplay_command[pos] == ';') || ((linkplay_command[pos] == '&')))
            {
                break;
            } 
        }
        
        strncpy(hex_ap, (linkplay_command + string_begin), string_size-1); 
        strncat(hex_ap, "\0", string_size);

        switch (status_type)
        {
            case e_ap_ssid:
                hex2ascii(hex_ap, ascii_ap, strlen(hex_ap), strlen(ascii_ap));
                Serial.print("Network: ");
                Serial.println(ascii_ap);
                break;
            case e_ap_rssi: 
                Serial.print("RSSI: ");
                Serial.println(atoi(hex_ap));
                break;
            case e_ap_channel:
                Serial.print("Channel: ");
                Serial.println(atoi(hex_ap));
                break;
        }
        
        status_type < max_wan_status ? status_type++ : status_type = 0;
        memset(hex_ap, 0, 100);
        memset(ascii_ap, 0, 100);
        string_begin += string_size;
        string_size = 0;
    }
    return 0;
}

uint8_t process_wps_command(char* linkplay_command)                    // Linkplay wireless WPS config commands
{
    /*
        "AXX+WPS++ON"                                                   // WPS/Smart Config process starts
    */
     switch(linkplay_command[10])
     {
        case 'F':
            Serial.println("WPS has been turned off");
            break;
        case 'N':
            Serial.println("WPS has been turned on");
            break;
        case 'D':
            Serial.println("WPS connection setup has ended");
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
AXX+MEA+DAT54686520536967687473;456e746572205368696b617269;54686520537061726b&
*/
