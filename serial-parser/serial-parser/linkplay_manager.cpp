#include "linkplay_manager.h"


static LinkPlay_firmware_update_t linkplay_update_status; 
static LinkPlay_Audio_Channel_Options_t linkplay_channel_config; 
static LinkPlay_firmware_update_t linkplay_; 
static LinkPlay_firmware_update_t linkplay_; 
static LinkPlay_firmware_update_t linkplay_; 
static LinkPlay_firmware_update_t linkplay_; 
static LinkPlay_firmware_update_t linkplay_; 
static LinkPlay_firmware_update_t linkplay_; 
static LinkPlay_firmware_update_t linkplay_; 
static LinkPlay_firmware_update_t linkplay_; 
static LinkPlay_firmware_update_t linkplay_; 
static LinkPlay_firmware_update_t linkplay_; 
static LinkPlay_firmware_update_t linkplay_; 


void LP_Set_linkplay_firmware_update_status(LinkPlay_firmware_update_t update_status)
{
    linkplay_update_status = update_status;
}

LinkPlay_firmware_update_t LP_Get_linkplay_firmware_update_status()
{
    return linkplay_update_status; 
}

void LP_Set_linkplay_audio_channel_status(LinkPlay_Audio_Channel_Options_t channel_config);
{
    linkplay_channel_config = channel_config;
}

LinkPlay_Audio_Channel_Options_t LP_Get_linkplay_audio_channel_status();
{
    return linkplay_channel_config;
}




void send_linkplay_pic_volume()
{
    switch (CS_GetOutputType())
    {   
        case(e_OUTPUT_TYPE_Headphones):
            Serial1.print("MCU+VOL+")
            Serial1.println(CS_GetHeadphoneVolume());
            break;    
        case(e_OUTPUT_TYPE_Main):
            Serial1.print("MCU+VOL+")
            Serial1.println(CS_GetVolume());
            break;
        default:
            break;
    }
}

void LP_set_pic_volume(uint8_t lp_volume); 
{
    switch (CS_GetOutputType())
    {   
        case(e_OUTPUT_TYPE_Headphones):
            CS_SetHeadphoneVolume(lp_volume));
            break;    
        case(e_OUTPUT_TYPE_Main):
            CS_GetVolume(lp_volume);
            break;
        default:
            break;
    }
}
