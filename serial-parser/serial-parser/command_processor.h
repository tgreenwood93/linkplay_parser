#include "Arduino.h"

#ifndef command_processor_h
#define command_processor_h


enum 
{
      e_no_internet_connection = 0,
      e_connected_to_internet,
};

enum {
    e_none = 0,
    e_airplay = 1,
    e_DLNA = 2,
    e_thumb_drive = 42,
    e_line_in = 40,
    e_bluetooth = 41,
    e_optical = 43,
    e_rca = 44,
    e_coaxial = 45,
    e_mirror = 50,
    e_slave = 99,
};

enum {
    e_failed_to_connect = 0,
    e_succesfully_connected,
    e_connecting_to_ap,
    e_bad_rssi,
    e_wrong_password,
    e_wrong_security_type,
    e_cant_find_ap,
    e_failed_to_get_ip_address
  };

enum {
    e_stereo = 0,
    e_left_chan,
    e_right_chan,
};

enum {
    e_ethernet_disconnected = 0,
    e_ethernet_connected  
};

enum {
    e_sunday = 0,
    e_monday,
    e_tuesday,
    e_wednesday,
    e_thursday,
    e_friday,
    e_saturday,
};

enum {
    e_repeat_all = 0,
    e_repeat_current,
    e_shuffle_repeat,
    e_shuffle_no_repeat
};

enum {
    e_hotspot_off = 0,
    e_hotspot_on
};

enum {
    e_stopped_playback = 0,
    e_playback_started
};


enum {
    e_mute = 0,
    e_unmute
};

enum {
    e_ap_ssid = 0,
    e_ap_rssi,
    e_ap_channel,
 };

void processCommand(char* msgAddr);
uint8_t process_linkplay_commands(char* linkplay_command);

uint8_t process_b_commands(char* linkplay_command);
uint8_t process_c_commands(char* linkplay_command);
uint8_t process_d_commands(char* linkplay_command);
uint8_t process_e_commands(char* linkplay_command);
uint8_t process_f_commands(char* linkplay_command);
uint8_t process_g_commands(char* linkplay_command);
uint8_t process_i_commands(char* linkplay_command);
uint8_t process_l_commands(char* linkplay_command);
uint8_t process_m_commands(char* linkplay_command);
uint8_t process_p_commands(char* linkplay_command);
uint8_t process_r_commands(char* linkplay_command);
uint8_t process_s_commands(char* linkplay_command);
uint8_t process_v_commands(char* linkplay_command);
uint8_t process_w_commands(char* linkplay_command);

uint8_t process_bur_command(char* linkplay_command);                    // Linkplay firmware updating commands
uint8_t process_bot_command(char* linkplay_command);                    // Linkplay firmware updating commands
uint8_t process_cap_command(char* linkplay_command);                    // Linkplay commands after factory reset
uint8_t process_chn_command(char* linkplay_command);                    // Linkplay channel information (stereo / mono left / mono right)
uint8_t process_dev_command(char* linkplay_command);                    // Linkplay device query commands
uint8_t process_eth_command(char* linkplay_command);                    // Linkplay ethernet commands
uint8_t process_fac_command(char* linkplay_command);                    // Linkplay factory reset commands
uint8_t process_get_command(char* linkplay_command);                    // Linkplay get commands
uint8_t process_inf_command(char* linkplay_command);                    // Linkplay i2s commands
uint8_t process_i2s_command(char* linkplay_command);                    // Linkplay i2s commands
uint8_t process_led_command(char* linkplay_command);                    // Linkplay factory teset commands
uint8_t process_mcu_command(char* linkplay_command);                    // Linkplay queries of our microprocessor
uint8_t process_mea_command(char* linkplay_command);                    // Linkplay meadia metadata commands
uint8_t process_mic_command(char* linkplay_command);                    // process microphone commands
uint8_t process_mut_command(char* linkplay_command);                    // Linkplay command to mute audio
uint8_t process_m2s_command(char* linkplay_command);                    // Linkplay master to slave command pass through
uint8_t process_nxt_command(char* linkplay_command);                    // Linkplay alarm commands
uint8_t process_plm_command(char* linkplay_command);                    // Linkplay playback mode commands
uint8_t process_plp_command(char* linkplay_command);                    // Linkplay repeat mode commands
uint8_t process_ply_command(char* linkplay_command);                    // Linkplay playback commands
uint8_t process_pmt_command(char* linkplay_command);                    // Linkplay voice prompt commands
uint8_t process_ra0_command(char* linkplay_command);                    // Linkplay wifi access point information commands
uint8_t process_set_command(char* linkplay_command);                    // Linkplay set time change commands (YYYYMMDDHHMMSS and mon/tue/wed/.../sun)
uint8_t process_sta_command(char* linkplay_command);                    // Linkplay wireless status commands
uint8_t process_s2m_command(char* linkplay_command);                    // Linkplay slave to master command pass through
uint8_t process_vol_command(char* linkplay_command);                    // Linkplay volume adjusting commands
uint8_t process_wan_command(char* linkplay_command);                    // Linkplay wireless acress points 
uint8_t process_wps_command(char* linkplay_command);                    // Linkplay wireless WPS config commands
uint8_t process_www_command(char* linkplay_command);                    // Linkplay internet connection commands
uint16_t linkplay_command_data_extraction(char* linkplay_command);
void error_handler(void);
int16_t hex2ascii(const char *hexArray, char *asciiArray, uint8_t hexArrayLength, uint8_t charArrayLength);

static const uint8_t max_wan_status = 2; 
static const uint8_t num_status_per_wan = 3; 

#endif
