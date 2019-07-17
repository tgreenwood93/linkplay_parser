#include "Arduino.h"
#include "command_processor.h"

void processCommand(char* linkplay_command)
{   
    uint8_t error_handler = 0;
        
    if (strncmp(linkplay_command, "AXX", 3) != 0)
      return; // not a linkplay command
      
    error_handler = process_linkplay_commands(linkplay_command);

    if (error_handler != 0)
    {
      Serial.print(linkplay_command);
      Serial.print(" ");
    }
               
    switch (error_handler)
    {
        case 0: 
            //Serial.println("command read sucess");
            break;
        case 1:    
            Serial.println("command was not found in first layer of filtering");
            break;
        case 2: 
            Serial.println("command was not found in b commands");
            break;
        case 3:
            Serial.println("command was not found in c commands");
            break;
        case 4: 
            Serial.println("command was not found in d commands");
            break;
        case 5:
            Serial.println("command was not found in e commands");
            break;
        case 6: 
            Serial.println("command was not found in f commands");
            break;
        case 7:
            Serial.println("command was not found in g commands");
            break;
        case 8:
            Serial.println("command was not found in i commands");
            break;
        case 9: 
            Serial.println("command was not found in l commands");
            break;
        case 10:
            Serial.println("command was not found in m commands");
            break;
        case 11: 
            Serial.println("command was not found in p commands");
            break;
        case 12:
            Serial.println("command was not found in r commands");
            break;
        case 13: 
            Serial.println("command was not found in s commands");
            break;
        case 14:
            Serial.println("command was not found in v commands");
            break;
        case 15:
            Serial.println("command was not found in w commands");
            break;
    }
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
            return 1;
            break;
    }
    return 0;
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
            return 2;
            break;
    }
    return 0;
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
            return 3;
            break;
    }    
    return 0;
}
 
uint8_t process_d_commands(char* linkplay_command)
{
    switch (linkplay_command[5])
    {
        case 'E':
            process_dev_command(linkplay_command);                      // Linkplay device query commands
            break;
        default:
            return 4;
            break;  
    }       
    return 0;
}
 
uint8_t process_e_commands(char* linkplay_command)
{
    switch (linkplay_command[5])
    {
        case 'T':
            process_eth_command(linkplay_command);                      // Linkplay ethernet commands
            break;
        default:
            return 5;
            break;  
    }    
    return 0;  
}
 
uint8_t process_f_commands(char* linkplay_command)
{
    switch (linkplay_command[5])
    {
        case 'A':
            process_fac_command(linkplay_command);                      // Linkplay factory reset commands
            break;
        default:
            return 6;
            break;  
    }    
    return 0;  
}

uint8_t process_g_commands(char* linkplay_command)
{
    switch (linkplay_command[5])
    {
        case 'E':
            process_get_command(linkplay_command);                     // Linkplay factory get commands
            break;
        default:
            return 7;
            break;  
    }    
    return 0;  
}

uint8_t process_i_commands(char* linkplay_command)
{
    switch (linkplay_command[5])
    { 
        case 'N':
            process_inf_command(linkplay_command);                    // Linkplay i2s commands
            break;
        case '2':
            process_i2s_command(linkplay_command);                     // Linkplay factory get commands
            break;
        default:
            return 8;
            break;  
    }    
    return 0;
}
uint8_t process_l_commands(char* linkplay_command)
{
    switch (linkplay_command[5])
    {
        case 'E':
            process_led_command(linkplay_command);                      // Linkplay factory reset commands
            break;
        default:
            return 9;
            break;  
    }    
    return 0;  
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
            return 10;
            break;
    }    
    return 0;
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
            return 11;
            break;  
    }    
    return 0;
}
 
uint8_t process_r_commands(char* linkplay_command)
{
    switch (linkplay_command[5])
    {
        case 'A':
            process_ra0_command(linkplay_command);                      // Linkplay wifi access point information commands
            break;
        default:
            return 12;
            break;  
    }    
    return 0;  
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
            return 13;
            break;
    }    
    return 0;
}
 
uint8_t process_v_commands(char* linkplay_command)
{
    switch (linkplay_command[5])
    {
        case 'O':
            process_vol_command(linkplay_command);                      // Linkplay volume adjusting commands
            break;
        default:
            return 14;
            break;  
    }    
    return 0;  
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
            return 15;
            break;  
    }    
    return 0;
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
    //   "AXX+FACTORY"                                                 // WiFi sends this command to notify MCU that it is going to do a factory reset
    Serial.println("Linkplay is factory resetting.\nWe'll need to supply it information upon it rebooting.");
}

uint8_t process_get_command(char* linkplay_command)
{
    Serial.println("Set SSID of linkplay");
    Serial1.println("MCU+SID+StellarIntegrated");
}

uint8_t process_inf_command(char* linkplay_command)                    // Linkplay inf commands
{ 
/*
        AXX+INF+INF{ "language": "en_us", "ssid": "LinkPlayA31_1CB8", "hideSSID": "1", "SSIDStrategy": "2", 
        "firmware": "3.8.5710", "build": "release", "project": "a31srcoutwm8918", "priv_prj": "a31srcoutwm8918", 
        "Release": "20180510", "branch": "stable\/wiimu-3.8", "group": "0", "expired": "0", "internet": "0", 
        "uuid": "FF3100368405108353A7AD6C", "MAC": "00:22:6C:68:1C:B8", "STA_MAC": "00:22:6C:68:1C:BA", 
        "date": "1970:01:01", "time": "00:27:42", "tz": "-7", "netstat": "0", "essid": "", "apcli0": "0.0.0.0",    //22
        "eth2": "0.0.0.0", "hardware": "A31", "VersionUpdate": "0", "NewVer": "0", "mcu_ver": "0", "mcu_ver_new": "0", 
        "dsp_ver_new": "0", "ra0": "10.10.10.254", "temp_uuid": "58F491488457B1B7", "cap1": "0x500", 
        "capability": "0x280800", "languages": "0x0", "dsp_ver": "", "streams_all": "0x7ffffffe", "streams": "0x7f9833fe", //37
        "region": "unknown", "external": "0x0", "preset_key": "6", "plm_support": "0x2", "spotify_active": "0", 
        "WifiChannel": "11", "RSSI": "0", "battery": "0", "battery_percent": "0", "securemode": "0", 
        "upnp_version": "1004", "upnp_uuid": "uuid:FF31F008-8405-1083-53A7-AD6CFF31F008", "uart_pass_port": "8899", 
        "communication_port": "8819", "web_firmware_update_hide": "0", "web_login_result": "-1", "ignore_talkstart": "0", 
        "silenceOTATime": "", "ignore_silenceOTATime": "1", "iheartradio_new": "1", "privacy_mode": "0", 
        "user1": "315:524", "user2": "5935:6291", "DeviceName": "Linkplay Demo", "GroupName": "Linkplay Demo" }&
*/  

    uint16_t num_args = 1;
    uint16_t data_start_point = 0;
    uint16_t data_end_point = 0;
    char char_buf[100];
    uint16_t store_pos[100] = {0};
    uint16_t command_length = strlen(linkplay_command);
    
    for (data_start_point = 12; data_start_point < command_length; data_start_point++)
    {
        if ((linkplay_command[data_start_point] == ':') && (linkplay_command[data_start_point-1] == '"'))
        {
            for (data_end_point = (data_start_point+data_offset); data_end_point < command_length; data_end_point++)
            {     
                if ((linkplay_command[data_end_point] == '"') && (linkplay_command[data_end_point+1] == ','))
                {
                    strncpy(char_buf, (linkplay_command+(data_start_point+data_offset)), (data_end_point-(data_start_point+data_offset)));
                    inf_command_parser((num_args-1), char_buf);
                    memset(char_buf, 0, 100);
                    break;
                }  
            }
            num_args ++;
        }
    }
    return 0; 
}

uint8_t inf_command_parser(uint16_t current_inf, char* char_buf)
{
    switch (current_inf)
    {
        case e_inf_language:
            Serial.print("language: ");
            Serial.println(char_buf);
            break;
        case e_inf_ssid:
            Serial.print("ssid: ");
            Serial.println(char_buf);
            break;
        case e_inf_hide_ssid:
            Serial.print("hide ssid: ");
            Serial.println(char_buf);
            break;
        case e_inf_ssid_strategy:
            Serial.print("ssid strategy: ");
            Serial.println(char_buf);
            break;
        case e_inf_link_play_fimrware:
            Serial.print("linkplay firmware: ");
            Serial.println(char_buf);
            break;
        case e_inf_build:
            Serial.print("linkplay build: ");
            Serial.println(char_buf);
            break;
        case e_inf_project:
            Serial.print("linkplay project: ");
            Serial.println(char_buf);
            break;
        case e_inf_firmware_private_project:
            Serial.print("linkplay private project: ");
            Serial.println(char_buf);
            break;
        case e_inf_firmware_release:
            Serial.print("linkplay firmware release: ");
            Serial.println(char_buf);
            break;
        case e_inf_firmware_branch:
            Serial.print("linkplay firmware branch: ");
            Serial.println(char_buf);
            break;
        case e_inf_group:
            Serial.print("group: ");
            Serial.println(char_buf);
            break;
        case e_inf_expired:
            Serial.print("expired: ");
            Serial.println(char_buf);
            break;
        case e_inf_internet:
            Serial.print("internet status: ");
            Serial.println(char_buf);
            break;
        case e_inf_uuid:
            Serial.print("uuid: ");
            Serial.println(char_buf);
            break;
        case e_inf_mac:
            Serial.print("mac address: ");
            Serial.println(char_buf);
            break;
        case e_inf_sta_mac:
            Serial.print("sta mac address: ");
            Serial.println(char_buf);
            break;
        case e_inf_date:
            Serial.print("date: ");
            Serial.println(char_buf);
            break;
        case e_inf_time:
            Serial.print("time: ");
            Serial.println(char_buf);
            break;
        case e_inf_tz:
            Serial.print("time zone: ");
            Serial.println(char_buf);
            break;
        case e_inf_netstat:
            Serial.print("network status: ");
            Serial.println(char_buf);
            break;
        case e_inf_essid:
            Serial.print("essid: ");
            Serial.println(char_buf);
            break;
        case e_inf_apcli0:
            Serial.print("wifi IP: ");
            Serial.println(char_buf);
            break;
        case e_inf_eth2:
            Serial.print("ethernet IP: ");
            Serial.println(char_buf);
            break;
        case e_inf_hardware:
            Serial.print("hardware: ");
            Serial.println(char_buf);
            break;
        case e_inf_version_update:
            Serial.print("version update: ");
            Serial.println(char_buf);
            break;
        case e_inf_new_version:
            Serial.print("new linkplay firmware version: ");
            Serial.println(char_buf);
            break;
        case e_inf_mcu_version:
            Serial.print("pic firmware version: ");
            Serial.println(char_buf);
            break;
        case e_inf_mcu_new_version:
            Serial.print("pic new firmware version: ");
            Serial.println(char_buf);
            break;
        case e_inf_dsp_ver_new:
            Serial.print("dsp new firmware version: ");
            Serial.println(char_buf);
            break;
        case e_inf_ra0:
            Serial.print("internal server IP: ");
            Serial.println(char_buf);
            break;
        case e_inf_temp_uuid:
            Serial.print("temp uuid: ");
            Serial.println(char_buf);
            break;
        case e_inf_cap1:
            Serial.print("capl: ");
            Serial.println(char_buf);
            break;
        case e_inf_capability:
            Serial.print("capability: ");
            Serial.println(char_buf);
            break;
        case e_inf_languages:
            Serial.print("language: ");
            Serial.println(char_buf);
            break;
        case e_inf_dsp_ver:
            Serial.print("dsp version: ");
            Serial.println(char_buf);
            break;
        case e_inf_streams_all:
            Serial.print("steaming settings: ");
            Serial.println(char_buf);
            break;
        case e_inf_streams:
            Serial.print("streams: ");
            Serial.println(char_buf);
            break;
        case e_inf_region:
            Serial.print("region: ");
            Serial.println(char_buf);
            break;
        case e_inf_external:
            Serial.print("external: ");
            Serial.println(char_buf);
            break;
        case e_inf_preset_key:
            Serial.print("preset key: ");
            Serial.println(char_buf);
            break;
        case e_inf_plm_support:
            Serial.print("plm support: ");
            Serial.println(char_buf);
            break;
        case e_inf_spotify_active:
            Serial.print("spotify active: ");
            Serial.println(char_buf);
            break;
        case e_inf_WifiChannel:
            Serial.print("wifi channel: ");
            Serial.println(char_buf);
            break;
        case e_inf_RSSI:
            Serial.print("rssi: ");
            Serial.println(char_buf);
            break;
        case e_inf_battery:
            Serial.print("battery: ");
            Serial.println(char_buf);
            break;
        case e_inf_battery_percent:
            Serial.print("battery percent: ");
            Serial.println(char_buf);
            break;
        case e_inf_securemode:
            Serial.print("secure mode: ");
            Serial.println(char_buf);
            break;
        case e_inf_upnp_version:
            Serial.print("upnp version: ");
            Serial.println(char_buf);
            break;
        case e_inf_upnp_uuid:
            Serial.print("upnp uuid: ");
            Serial.println(char_buf);
            break;
        case e_inf_uart_pass_port:
            Serial.print("pass port: ");
            Serial.println(char_buf);
            break;
        case e_inf_communication_port:
            Serial.print("communication port: ");
            Serial.println(char_buf);
            break;
        case e_inf_web_firmware_update_hide:
            Serial.print("firmware update hidden: ");
            Serial.println(char_buf);
            break;
        case e_inf_web_login_result:
            Serial.print("web login result: ");
            Serial.println(char_buf);
            break;
        case e_inf_ignore_talkstart:
            Serial.print("ignore talk start: ");
            Serial.println(char_buf);
            break;
        case e_inf_silenceOTATime:
            Serial.print("silence OTA time: ");
            Serial.println(char_buf);
            break;
        case e_inf_ignore_silenceOTATime:
            Serial.print("ignore silence OTA time: ");
            Serial.println(char_buf);
            break;
        case e_inf_iheartradio_new:
            Serial.print("iHeartRadio new: ");
            Serial.println(char_buf);
            break;
        case e_inf_privacy_mode:
            Serial.print("privacy mode: ");
            Serial.println(char_buf);
            break;
        case e_inf_user1:
            Serial.print("user1: ");
            Serial.println(char_buf);
            break;
        case e_inf_user2:
            Serial.print("user2: ");
            Serial.println(char_buf);
            break;
        case e_inf_DeviceName:
            Serial.print("device name: ");
            Serial.println(char_buf);
            break;
        case e_inf_GroupName:
            Serial.print("group name: ");
            Serial.println(char_buf);
            break;
        default:
            break; 
    }
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
        Serial.print("Title: ");
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
        Serial.print("Artist: ");
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
        Serial.print("Album: ");
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
          Serial1.println("MCU+INF+GET");
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

int16_t hex2ascii(const char *hexArray, char *asciiArray, uint8_t hexArrayLength, uint8_t asciiArrayLength)
{
    int16_t i = 0;
    int16_t j = 0;
    memset(asciiArray, 0, asciiArrayLength);
    
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
