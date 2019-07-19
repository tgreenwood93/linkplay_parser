#include "linkplay_manager.h"


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
