{"skirmish_bonus_pointer"
     {on spawn
        {call "add_number"}
	{delay 0
	    {start_sound "mission/bonus/"}
            {view start "fx"}
	}
;        {call "add_smoke"}
;        {delay 0.5
;            {view start "smoke"}
;        }
;        {delay 1.5
;            {view start "smoke2"}
;        }

     }
	{on "add_number" overload
		{add_view "bonus_pointer"	"fx" "fx_mp_pointer"}
;		{add_view "smoke_yellow_small"	"smoke" "fx_mp_pointer"}
;		{add_view "smoke_yellow_norm"	"smoke2" "fx_mp_pointer"}
	}
}



{"skirmish_fx_5_rocket"
    {on spawn
        {call "add_number"}
        {delay 1
            {view start "fx"}
        }
    }
	{on "add_number" overload
		{add_view "5_rocket"	"fx" "fx_number"}
	}
}
{"skirmish_fx_5_heavy"
    {on spawn
        {call "add_number"}
        {delay 1
            {view start "fx"}
        }
    }
	{on "add_number" overload
		{add_view "5_heavy"	"fx" "fx_number"}
	}
}
{"skirmish_fx_5_victory"
    {on spawn
        {call "add_number"}
        {delay 1
            {view start "fx"}
        }
    }
	{on "add_number" overload
		{add_view "5_victory"	"fx" "fx_number"}
	}
}


{"skirmish_fx_15_bonus"
    {on spawn
        {call "add_number"}
        {delay 1
            {view start "fx"}
        }
    }
	{on "add_number" overload
		{add_view "15_bonus"	"fx" "fx_number"}
	}
}
{"skirmish_fx_15_tank"
    {on spawn
        {call "add_number"}
        {delay 1
            {view start "fx"}
        }
    }
	{on "add_number" overload
		{add_view "15_tank"	"fx" "fx_number"}
	}
}


{"skirmish_fx_victory"
    {on spawn
        {call "add_number"}
        {delay 1
            {view start "fx"}
        }
    }
	{on "add_number" overload
		{add_view "victory"	"fx" "fx_number"}
	}
}
{"skirmish_fx_20_victory"
    {on spawn
        {call "add_number"}
        {delay 1
            {view start "fx"}
        }
    }
	{on "add_number" overload
		{add_view "20_victory"	"fx" "fx_number"}
	}
}
{"skirmish_fx_250_victory"
    {on spawn
        {call "add_number"}
        {delay 1
            {view start "fx"}
        }
    }
	{on "add_number" overload
		{add_view "250_victory"	"fx" "fx_number"}
	}
}

{"skirmish_fx_30_defence"
    {on spawn
        {call "add_number"}
        {delay 1
            {view start "fx"}
        }
    }
	{on "add_number" overload
		{add_view "30_defence"	"fx" "fx_number"}
	}
}
{"skirmish_fx_30_infantry"
    {on spawn
        {call "add_number"}
        {delay 1
            {view start "fx"}
        }
    }
	{on "add_number" overload
		{add_view "30_infantry"	"fx" "fx_number"}
	}
}
{"skirmish_fx_30_special"
    {on spawn
        {call "add_number"}
        {delay 1
            {view start "fx"}
        }
    }
	{on "add_number" overload
		{add_view "30_special"	"fx" "fx_number"}
	}
}
{"skirmish_fx_30_tank"
    {on spawn
        {call "add_number"}
        {delay 1
            {view start "fx"}
        }
    }
	{on "add_number" overload
		{add_view "30_tank"	"fx" "fx_number"}
	}
}
{"skirmish_fx_30_jeep"
    {on spawn
        {call "add_number"}
        {delay 1
            {view start "fx"}
        }
    }
	{on "add_number" overload
		{add_view "30_jeep"	"fx" "fx_number"}
	}
}
{"mp_flag"
	{on "specability" overload
		{call "mp_destroy"}
	}
	{on "switch_hatch" overload
			{call "mp_destroy"}
	}
	{on "cwsh_switch_hatch" overload
			{tags add "give_me_ai_units"}
			{delay 15 {tags remove "give_me_ai_units"}}
	}
	{on "mp_destroy"
	  {if not tagged "destroyed"
		{tags add "destroyed"}
		{call "stat_break"}
		{drop_orders}
		{reset_manual_control}
		{able select 0}
		{able repaired 0}
		{ani_play "down"}
		{delay 1
			{kick_entity_manager}
		}
		{delay 8 {delete}}
	   }
	}
}
{"mp_flag abn_mp_flag" {on spawn {delay 0.1{tex_morph "abn" 0.1}}}}
{"mp_flag artbr_mp_flag" {on spawn {delay 0.1{tex_morph "artbr" 0.1}}}}
{"mp_flag bund_mp_flag" {on spawn {delay 0.1{tex_morph "bund" 0.1}}}}
{"mp_flag cbn_mp_flag" {on spawn {delay 0.1{tex_morph "cbn" 0.1}}}}
{"mp_flag fra_mp_flag" {on spawn {delay 0.1{tex_morph "fra" 0.1}}}}
{"mp_flag gb_mp_flag" {on spawn {delay 0.1{tex_morph "gb" 0.1}}}}
{"mp_flag mot_mp_flag" {on spawn {delay 0.1{tex_morph "mot" 0.1}}}}
{"mp_flag nrf_mp_flag" {on spawn {delay 0.1{tex_morph "nrf" 0.1}}}}
{"mp_flag specbr_mp_flag" {on spawn {delay 0.1{tex_morph "specbr" 0.1}}}}
{"mp_flag usaf_mp_flag" {on spawn {delay 0.1{tex_morph "usaf" 0.1}}}}
{"mp_flag usarmy_mp_flag" {on spawn {delay 0.1{tex_morph "usarmy" 0.1}}}}
{"mp_flag usart_mp_flag" {on spawn {delay 0.1{tex_morph "usart" 0.1}}}}
{"mp_flag usmc_mp_flag" {on spawn {delay 0.1{tex_morph "usmc" 0.1}}}}
{"mp_flag idf_mp_flag" {on spawn {delay 0.1{tex_morph "idf" 0.1}}}}
{"mp_flag vdv_mp_flag" {on spawn {delay 0.1{tex_morph "vdv" 0.1}}}}
{"mp_flag vvs_mp_flag" {on spawn {delay 0.1{tex_morph "vvs" 0.1}}}}
{"mp_flag cnair_mp_flag" {on spawn {delay 0.1{tex_morph "cnair" 0.1}}}}
{"mp_flag cnart_mp_flag" {on spawn {delay 0.1{tex_morph "cnart" 0.1}}}}
{"mp_flag cnheavy_mp_flag" {on spawn {delay 0.1{tex_morph "cnheavy" 0.1}}}}
{"mp_flag cnmed_mp_flag" {on spawn {delay 0.1{tex_morph "cnmed" 0.1}}}}
{"mp_flag cnsam_mp_flag" {on spawn {delay 0.1{tex_morph "cnsam" 0.1}}}}
{"mp_flag cnsco_mp_flag" {on spawn {delay 0.1{tex_morph "cnsco" 0.1}}}}
