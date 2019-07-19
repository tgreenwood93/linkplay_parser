#include "Arduino.h"
#include "command_processor.h"
#include "linkplay_manager.h"

#ifndef "linkplay_error_handler.h"
#define "linkplay_error_handler.h"

enum 
{
  e_no_error = 0,
  e_unknown_AXX_command,
  e_unknown_command,
  e_unknown_b_command,
  e_unknown_c_command,
  e_unknown_d_command,
  e_unknown_e_command,
  e_unknown_f_command,
  e_unknown_g_command,
  e_unknown_i_command,
  e_unknown_k_command,
  e_unknown_l_command,
  e_unknown_m_command,
  e_unknown_n_command,
  e_unknown_p_command,
  e_unknown_r_command,
  e_unknown_s_command,
  e_unknown_v_command,
  e_unknown_w_command,
  e_unknown_bot_command,
  e_unknown_bur_command,
  e_unknown_cap_command,
  e_unknown_chn_command,
  e_unknown_dev_command,
  e_unknown_eth_command,
  e_unknown_fac_command,
  e_unknown_get_command,
  e_unknown_inf_command,
  e_unknown_i2s_command,
  e_unknown_key_command,
  e_unknown_led_command,
  e_unknown_mcu_command,
  e_unknown_mea_command,
  e_unknown_mic_command,
  e_unknown_mut_command,
  e_unknown_m2s_command,
  e_unknown_nxt_command,
  e_unknown_plm_command,
  e_unknown_plp_command,
  e_unknown_ply_command,
  e_unknown_pmt_command,
  e_unknown_pow_command,
  e_unknown_ra0_command,
  e_unknown_set_command,
  e_unknown_sli_command,
  e_unknown_sta_command,
  e_unknown_s2m_command,
  e_unknown_uid_command,
  e_unknown_vol_command,
  e_unknown_wan_command,
  e_unknown_wps_command,
  e_unknown_www_command,
  e_unknown_chan_config,
  e_empty_i2s_command,
  e_unknown_playback_status,
  e_unknown_connection_status,
  e_volume_out_of_bounds,
};

void linkplay_error_handler(uint8_t error_handler, char* linkplay_command);

#endif
