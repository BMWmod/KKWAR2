{"su-34_umpk3000"
	("air_multibomb_launcher" weapon(bomber) shooter(ympk_body_) missile(umpk_3000_guided))
}
{"umpk_3000_guided"
    {on "on_spawn_custom"
		{impulse up -1.5 0.5 forward 35 4 com} {constrain_velocity 50}
		{delay 0.1
			{with_linked_entity "missile"  
				{ani_play "flip_bomb" 0.25 callback}
			}
		}
		{delay 1.5
			{with_linked_entity "missile"  
			 {add_view	"flash_cannon_small"	 "flash_cannon_small"	 "tail"} 
			 {view start "flash_cannon_small"}
			 {ani_play "open_wing" 1.0}
			}
		}
		{delay 22  {call "fall"}}

	}
	("proj_impulse_movement" cont_impulse(10) main_impulse(20) const_vel(20))
}