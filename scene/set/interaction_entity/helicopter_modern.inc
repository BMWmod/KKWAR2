{"ka50"
;-------------------------------------------------------------
	{on spawn
		{add_view	"flash_zenit"		"flashbarrel1"			"Foresight1"}
		{add_view	"exhaust_dark"	"engine_steam1" "FXsmoke1"}			
		{add_view	"exhaust_dark"	"engine_steam2" "FXsmoke2"}
		{add_view       "autocannon_gilz"		"shell"	"fx_shell"}		
		{add_view 	"smoke_zenit" 	"zenite_smoke" 		"foresight1"}
;========================================================================================
		{add_view 	"rok_tail" 		"rok_tail00" 		"shooter_l00"}
		{add_view 	"rok_tail" 		"rok_tail01" 		"shooter_l01"}
		{add_view 	"rok_tail" 		"rok_tail02" 		"shooter_l02"}
		{add_view 	"rok_tail" 		"rok_tail03" 		"shooter_l03"}
		{add_view 	"rok_tail" 		"rok_tail04" 		"shooter_l04"}
		{add_view 	"rok_tail" 		"rok_tail05" 		"shooter_l05"}
		{add_view 	"rok_tail" 		"rok_tail06" 		"shooter_l06"}
		{add_view 	"rok_tail" 		"rok_tail07" 		"shooter_l07"}
		{add_view 	"rok_tail" 		"rok_tail08" 		"shooter_l08"}
		{add_view 	"rok_tail" 		"rok_tail09" 		"shooter_l09"}
		{add_view 	"rok_tail" 		"rok_tail10" 		"shooter_l10"}
		{add_view 	"rok_tail" 		"rok_tail11" 		"shooter_l11"}
		{add_view 	"rok_tail" 		"rok_tail12" 		"shooter_l12"}
		{add_view 	"rok_tail" 		"rok_tail13" 		"shooter_l13"}
		{add_view 	"rok_tail" 		"rok_tail14" 		"shooter_l14"}
		{add_view 	"rok_tail" 		"rok_tail15" 		"shooter_l15"}
		{add_view 	"rok_tail" 		"rok_tail16" 		"shooter_l16"}
		{add_view 	"rok_tail" 		"rok_tail17" 		"shooter_l17"}
		{add_view 	"rok_tail" 		"rok_tail18" 		"shooter_l18"}
		{add_view 	"rok_tail" 		"rok_tail19" 		"shooter_l19"}
;--------------------------------------------------------------------------------------------
		{add_view 	"rok_tail" 		"rok_tail_00" 		"shooter_r00"}
		{add_view 	"rok_tail" 		"rok_tail_01" 		"shooter_r01"}
		{add_view 	"rok_tail" 		"rok_tail_02" 		"shooter_r02"}
		{add_view 	"rok_tail" 		"rok_tail_03" 		"shooter_r03"}
		{add_view 	"rok_tail" 		"rok_tail_04" 		"shooter_r04"}
		{add_view 	"rok_tail" 		"rok_tail_05" 		"shooter_r05"}
		{add_view 	"rok_tail" 		"rok_tail_06" 		"shooter_r06"}
		{add_view 	"rok_tail" 		"rok_tail_07" 		"shooter_r07"}
		{add_view 	"rok_tail" 		"rok_tail_08" 		"shooter_r08"}
		{add_view 	"rok_tail" 		"rok_tail_09" 		"shooter_r09"}
		{add_view 	"rok_tail" 		"rok_tail_10" 		"shooter_r10"}
		{add_view 	"rok_tail" 		"rok_tail_11" 		"shooter_r11"}
		{add_view 	"rok_tail" 		"rok_tail_12" 		"shooter_r12"}
		{add_view 	"rok_tail" 		"rok_tail_13" 		"shooter_r13"}
		{add_view 	"rok_tail" 		"rok_tail_14" 		"shooter_r14"}
		{add_view 	"rok_tail" 		"rok_tail_15" 		"shooter_r15"}
		{add_view 	"rok_tail" 		"rok_tail_16" 		"shooter_r16"}
		{add_view 	"rok_tail" 		"rok_tail_17" 		"shooter_r17"}
		{add_view 	"rok_tail" 		"rok_tail_18" 		"shooter_r18"}
		{add_view 	"rok_tail" 		"rok_tail_19" 		"shooter_r19"}
;============================================================================================
		{add_view 	"rok_tail" 		"rok_tailA1" 		"tail02"}
		{add_view 	"rok_tail" 		"rok_tailA2" 		"tail01"}
;============================================================================================
		{add_view	"flash_cannon_big"		"flashbarrel2"			"Foresight2"}
		{add_view	"flash_cannon_big"		"flashbarrel3"			"Foresight3"}
			("link_damage_sound_rus")

    	}
	{on "add_movement_sound" overload
			{link_sound "fly"			"vehicle/helicopter/ka52_rotor"			}
			{link_sound "engine_start"		"vehicle/helicopter/mi-8en_start"				}
			{link_sound "engine_work"		"vehicle/helicopter/ka52_engine"				}
			{link_sound "engine_stop"		"vehicle/helicopter/mi-8en_stop"				}
	}
	{on fire "nar1" overload
		("low_speed_bullet")
		(define "fire_barrel"
			name "%0"
				;{ani_play "fire"}
				{view start "rok_tail%0"}
				{delay 0.42
					{view pause "rok_tail%0"}
				}
		)
		{spawn "startsmoke" inv_normal}
			{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			  else ("fire_barrel" args 02)
			else ("fire_barrel" args 03)
			  else ("fire_barrel" args 04)
			 else ("fire_barrel" args 05)
			else ("fire_barrel" args 06)
			else ("fire_barrel" args 07)
			else ("fire_barrel" args 08)
			else ("fire_barrel" args 09)
			else ("fire_barrel" args 10)
			else ("fire_barrel" args 11)	
			 else ("fire_barrel" args 12)
			else ("fire_barrel" args 13)
			  else ("fire_barrel" args 14)
			 else ("fire_barrel" args 15)
			else ("fire_barrel" args 16)
			else ("fire_barrel" args 17)
			else ("fire_barrel" args 18)
			else ("fire_barrel" args 19)
			
			 else ("fire_barrel" args 20)
			  else ("fire_barrel" args 21)
			else ("fire_barrel" args 22)
			  else ("fire_barrel" args 23)
			 else ("fire_barrel" args 24)
			else ("fire_barrel" args 25)
			else ("fire_barrel" args 26)
			else ("fire_barrel" args 27)
			else ("fire_barrel" args 28)
			else ("fire_barrel" args 29)
			else ("fire_barrel" args 30)	
			 else ("fire_barrel" args 31)
			else ("fire_barrel" args 32)
			  else ("fire_barrel" args 33)
			 else ("fire_barrel" args 34)
			else ("fire_barrel" args 35)
			else ("fire_barrel" args 36)
			else ("fire_barrel" args 37)
			else ("fire_barrel" args 38)
			else ("fire_barrel" args 39)
			}
		
	}

;-------------------------------------------------
	{on fire "ptur1" overload
		("low_speed_bullet")
		{delay 0.5 {spawn "vixr_carrier" "Foresight3"   x}}
		{view start "flashbarrel3"}
		{delay 0.42
			{view pause "flashbarrel3"}
		}
		{view start "rok_tailA1"}
		{spawn "startsmoke" "foresight3"}
		{delay 0.4
			{view pause "rok_tailA1"}
		}
	}
	{on fire "ptur2" overload
		("low_speed_bullet")
		{delay 0.5 {spawn "vixr_carrier" "Foresight2"  x}}
		{view start "flashbarrel2"}
		{delay 0.42
			{view pause "flashbarrel2"}
		}
		{view start "rok_tailA2"}
		{spawn "startsmoke" "foresight2"}
		{delay 0.4
			{view pause "rok_tailA2"}
		}
	}
	{on "tear_propeller_up1"
		{spawn "propeller_hit2" "propeller1" x}
		{spawn "propeller_hit2" "propeller1" x}
		{spawn "propeller_hit2" "propeller1" x}
		{bone cut "propeller1"}
	}
	{on "tear_propeller_down1"
		{spawn "propeller_hit2" "propeller" x}
		{spawn "propeller_hit2" "propeller" x}
		{spawn "propeller_hit2" "propeller" x}
		{bone cut "propeller"}
	}
}
{"ka52"
;-------------------------------------------------------------
	{on spawn

	{add_view	"flash_zenit"		"flashbarrel1"			"Foresight1"}
		{add_view	"exhaust_dark"	"engine_steam1" "FXsmoke1"}			
		{add_view	"exhaust_dark"	"engine_steam2" "FXsmoke2"}
		{add_view       "autocannon_gilz"		"shell"	"fx_shell"}		
		{add_view 	"smoke_zenit" 	"zenite_smoke" 		"foresight1"}
;========================================================================================
		{add_view 	"rok_tail" 		"rok_tail00" 		"shooter_l00"}
		{add_view 	"rok_tail" 		"rok_tail01" 		"shooter_l01"}
		{add_view 	"rok_tail" 		"rok_tail02" 		"shooter_l02"}
		{add_view 	"rok_tail" 		"rok_tail03" 		"shooter_l03"}
		{add_view 	"rok_tail" 		"rok_tail04" 		"shooter_l04"}
		{add_view 	"rok_tail" 		"rok_tail05" 		"shooter_l05"}
		{add_view 	"rok_tail" 		"rok_tail06" 		"shooter_l06"}
		{add_view 	"rok_tail" 		"rok_tail07" 		"shooter_l07"}
		{add_view 	"rok_tail" 		"rok_tail08" 		"shooter_l08"}
		{add_view 	"rok_tail" 		"rok_tail09" 		"shooter_l09"}
		{add_view 	"rok_tail" 		"rok_tail10" 		"shooter_l10"}
		{add_view 	"rok_tail" 		"rok_tail11" 		"shooter_l11"}
		{add_view 	"rok_tail" 		"rok_tail12" 		"shooter_l12"}
		{add_view 	"rok_tail" 		"rok_tail13" 		"shooter_l13"}
		{add_view 	"rok_tail" 		"rok_tail14" 		"shooter_l14"}
		{add_view 	"rok_tail" 		"rok_tail15" 		"shooter_l15"}
		{add_view 	"rok_tail" 		"rok_tail16" 		"shooter_l16"}
		{add_view 	"rok_tail" 		"rok_tail17" 		"shooter_l17"}
		{add_view 	"rok_tail" 		"rok_tail18" 		"shooter_l18"}
		{add_view 	"rok_tail" 		"rok_tail19" 		"shooter_l19"}
;--------------------------------------------------------------------------------------------
		{add_view 	"rok_tail" 		"rok_tail_00" 		"shooter_r00"}
		{add_view 	"rok_tail" 		"rok_tail_01" 		"shooter_r01"}
		{add_view 	"rok_tail" 		"rok_tail_02" 		"shooter_r02"}
		{add_view 	"rok_tail" 		"rok_tail_03" 		"shooter_r03"}
		{add_view 	"rok_tail" 		"rok_tail_04" 		"shooter_r04"}
		{add_view 	"rok_tail" 		"rok_tail_05" 		"shooter_r05"}
		{add_view 	"rok_tail" 		"rok_tail_06" 		"shooter_r06"}
		{add_view 	"rok_tail" 		"rok_tail_07" 		"shooter_r07"}
		{add_view 	"rok_tail" 		"rok_tail_08" 		"shooter_r08"}
		{add_view 	"rok_tail" 		"rok_tail_09" 		"shooter_r09"}
		{add_view 	"rok_tail" 		"rok_tail_10" 		"shooter_r10"}
		{add_view 	"rok_tail" 		"rok_tail_11" 		"shooter_r11"}
		{add_view 	"rok_tail" 		"rok_tail_12" 		"shooter_r12"}
		{add_view 	"rok_tail" 		"rok_tail_13" 		"shooter_r13"}
		{add_view 	"rok_tail" 		"rok_tail_14" 		"shooter_r14"}
		{add_view 	"rok_tail" 		"rok_tail_15" 		"shooter_r15"}
		{add_view 	"rok_tail" 		"rok_tail_16" 		"shooter_r16"}
		{add_view 	"rok_tail" 		"rok_tail_17" 		"shooter_r17"}
		{add_view 	"rok_tail" 		"rok_tail_18" 		"shooter_r18"}
		{add_view 	"rok_tail" 		"rok_tail_19" 		"shooter_r19"}
;============================================================================================
		{add_view 	"rok_tail" 		"ShooterH_l00" 		"ShooterH_l00"}
		{add_view 	"rok_tail" 		"ShooterH_l01" 		"ShooterH_l01"}
		{add_view 	"rok_tail" 		"ShooterH_l02" 		"ShooterH_l02"}
		{add_view 	"rok_tail" 		"ShooterH_l03" 		"ShooterH_l03"}
		{add_view 	"rok_tail" 		"ShooterH_l04" 		"ShooterH_l04"}
		{add_view 	"rok_tail" 		"ShooterH_r00" 		"ShooterH_r00"}
		{add_view 	"rok_tail" 		"ShooterH_r01" 		"ShooterH_r01"}
		{add_view 	"rok_tail" 		"ShooterH_r02" 		"ShooterH_r02"}
		{add_view 	"rok_tail" 		"ShooterH_r03" 		"ShooterH_r03"}
		{add_view 	"rok_tail" 		"ShooterH_r04" 		"ShooterH_r04"}

;============================================================================================
		{add_view 	"rok_tail" 		"tailL00" 		"tailL00"}
		{add_view 	"rok_tail" 		"tailL01" 		"tailL01"}
		{add_view 	"rok_tail" 		"tailL02" 		"tailL02"}
		{add_view 	"rok_tail" 		"tailL03" 		"tailL03"}
		{add_view 	"rok_tail" 		"tailL04" 		"tailL04"}
		{add_view 	"rok_tail" 		"tailL05" 		"tailL05"}
		{add_view 	"rok_tail" 		"tailR00" 		"tailR00"}
		{add_view 	"rok_tail" 		"tailR01" 		"tailR01"}
		{add_view 	"rok_tail" 		"tailR02" 		"tailR02"}
		{add_view 	"rok_tail" 		"tailR03" 		"tailR03"}
		{add_view 	"rok_tail" 		"tailR04" 		"tailR04"}
		{add_view 	"rok_tail" 		"tailR05" 		"tailR05"}
		
		{add_view 	"rok_tail" 		"TAil_iglaL00" 		"TAil_iglaL00"}
		{add_view 	"rok_tail" 		"TAil_iglaL01" 		"TAil_iglaL01"}
		{add_view 	"rok_tail" 		"TAil_iglaR00" 		"TAil_iglaR00"}
		{add_view 	"rok_tail" 		"TAil_iglaR01" 		"TAil_iglaR01"}
;============================================================================================
		{add_view	"flash_cannon_big"		"flashbarrel2"			"Foresight2"}
		{add_view	"flash_cannon_big"		"flashbarrel3"			"Foresight3"}
			("link_damage_sound_rus")

    	}
	{on "add_movement_sound" overload
			{link_sound "fly"			"vehicle/helicopter/ka52_rotor"			}
			{link_sound "engine_start"		"vehicle/helicopter/mi-8en_start"				}
			{link_sound "engine_work"		"vehicle/helicopter/ka52_engine"				}
			{link_sound "engine_stop"		"vehicle/helicopter/mi-8en_stop"				}
	}
	{on fire "nar1" overload
		("low_speed_bullet")
		(define "fire_barrel"
			name "%0"
				;{ani_play "fire"}
				{view start "tailL%0"}
				{delay 0.42
					{view pause "tailL%0"}
				}
		)
		{spawn "startsmoke" inv_normal}
			{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			  else ("fire_barrel" args 02)
			else ("fire_barrel" args 03)
			  else ("fire_barrel" args 04)
			 else ("fire_barrel" args 05)
			else ("fire_barrel" args 06)
			else ("fire_barrel" args 07)
			else ("fire_barrel" args 08)
			else ("fire_barrel" args 09)
			else ("fire_barrel" args 10)
			else ("fire_barrel" args 11)	
			 else ("fire_barrel" args 12)
			else ("fire_barrel" args 13)
			  else ("fire_barrel" args 14)
			 else ("fire_barrel" args 15)
			else ("fire_barrel" args 16)
			else ("fire_barrel" args 17)
			else ("fire_barrel" args 18)
			else ("fire_barrel" args 19)
			}
		{if name "00"
			{call "fire_gun_common"}
		}
	}
	{on fire "nar2" overload
		("low_speed_bullet")
		(define "fire_barrel"
			name "%0"
				;{ani_play "fire"}
				{view start "tailR_%0"}
				{delay 0.42
					{view pause "tailR_%0"}
				}
		)
		{spawn "startsmoke" inv_normal}
			{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			  else ("fire_barrel" args 02)
			else ("fire_barrel" args 03)
			  else ("fire_barrel" args 04)
			 else ("fire_barrel" args 05)
			else ("fire_barrel" args 06)
			else ("fire_barrel" args 07)
			else ("fire_barrel" args 08)
			else ("fire_barrel" args 09)
			else ("fire_barrel" args 10)
			else ("fire_barrel" args 11)	
			 else ("fire_barrel" args 12)
			else ("fire_barrel" args 13)
			  else ("fire_barrel" args 14)
			 else ("fire_barrel" args 15)
			else ("fire_barrel" args 16)
			else ("fire_barrel" args 17)
			else ("fire_barrel" args 18)
			else ("fire_barrel" args 19)							
			}
		{if name "00"
			{call "fire_gun_common"}
		}
	}
	{on fire "nar3" overload
		("low_speed_bullet")
		(define "fire_barrel"
			name "%0"
				;{ani_play "fire"}
				{view start "shooter_%0"}
				{delay 0.42
					{view pause "shooter_%0"}
				}
		)
		{spawn "startsmoke" inv_normal}
			{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			  else ("fire_barrel" args 02)
			else ("fire_barrel" args 03)
			  else ("fire_barrel" args 04)
			 else ("fire_barrel" args 05)
			else ("fire_barrel" args 06)
			else ("fire_barrel" args 07)
			else ("fire_barrel" args 08)
			else ("fire_barrel" args 09)
			else ("fire_barrel" args 10)
			else ("fire_barrel" args 11)	
			 else ("fire_barrel" args 12)
			else ("fire_barrel" args 13)
			  else ("fire_barrel" args 14)
			 else ("fire_barrel" args 15)
			else ("fire_barrel" args 16)
			else ("fire_barrel" args 17)
			else ("fire_barrel" args 18)
			else ("fire_barrel" args 19)
			}
		{if name "00"
			{call "fire_gun_common"}
		}
	}

;-------------------------------------------------
	{on fire "ptur3" overload
		("low_speed_bullet")
;		{spawn "proj_probe" "Foresight3" x  {tags add "Foresight3"}}
		{set "ptur3"}{call "proj_probe"}
		(define "fire_barrel"
			name "%0"
				{view start "tailL%0"}
				{delay 0.42
					{view pause "tailL%0"}
				}
		)
			{spawn "startsmoke" inv_normal}
			{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			  else ("fire_barrel" args 02)
			  else ("fire_barrel" args 03)
			  else ("fire_barrel" args 04)
			  else ("fire_barrel" args 05)
			}
	}
	{on fire "ptur4" overload
		("low_speed_bullet")
;		{spawn "proj_probe" "Foresight2" x  {tags add "Foresight2"}}
		{set "ptur4"}{call "proj_probe"}
		(define "fire_barrel"
			name "%0"
				{view start "tailR%0"}
				{delay 0.42
					{view pause "tailR%0"}
				}
		)
			{spawn "startsmoke" inv_normal}
			{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			  else ("fire_barrel" args 02)
			  else ("fire_barrel" args 03)
			  else ("fire_barrel" args 04)
			  else ("fire_barrel" args 05)
			}
	}
	{on fire "ptur1" overload
		("low_speed_bullet")
		{delay 0.5 {spawn "vixr_carrier" "Foresight3"   x}}
		(define "fire_barrel"
			name "%0"
				{view start "tailL%0"}
				{delay 0.42
					{view pause "tailL%0"}
				}
		)
			{spawn "startsmoke" inv_normal}
			{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			  else ("fire_barrel" args 02)
			  else ("fire_barrel" args 03)
			  else ("fire_barrel" args 04)
			  else ("fire_barrel" args 05)
			}
	}
	{on fire "ptur2" overload
		("low_speed_bullet")
		{delay 0.5 {spawn "vixr_carrier" "Foresight2"  x}}
		(define "fire_barrel"
			name "%0"
				{view start "tailR%0"}
				{delay 0.42
					{view pause "tailR%0"}
				}
		)
			{spawn "startsmoke" inv_normal}
			{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			  else ("fire_barrel" args 02)
			  else ("fire_barrel" args 03)
			  else ("fire_barrel" args 04)
			  else ("fire_barrel" args 05)
			}
	}
	{on fire "ptur5" overload
		{delay 0.1 {spawn "igla_s_carrier" "Foresight7"  x}}
		(define "fire_barrel"
			name "%0"
				{view start "TAil_iglaL%0"}
				{delay 0.42
					{view pause "TAil_iglaL%0"}
				}
		)
			{spawn "startsmoke" inv_normal}
			{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			}
	}
	{on fire "ptur6" overload
		{delay 0.1 {spawn "igla_s_carrier" "Foresight8"  x}}
		(define "fire_barrel"
			name "%0"
				{view start "TAil_iglaR%0"}
				{delay 0.42
					{view pause "TAil_iglaR%0"}
				}
		)
			{spawn "startsmoke" inv_normal}
			{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			}
	}
	{on "tear_propeller_up1"
		{spawn "propeller_hit2" "propeller1" x}
		{spawn "propeller_hit2" "propeller1" x}
		{spawn "propeller_hit2" "propeller1" x}
		{bone cut "propeller1"}
	}
	{on "tear_propeller_down1"
		{spawn "propeller_hit2" "propeller" x}
		{spawn "propeller_hit2" "propeller" x}
		{spawn "propeller_hit2" "propeller" x}
		{bone cut "propeller"}
	}

	{on "fall"
		{call "eject_all"}
	}
	{on "eject_all"
		(define "paradrop_crew_member_with_alt"	;случайно выбираем таг для уменьшения вероятности взаимодействия
			{if rand 0.5 
				{if rand 0.5 
					{if rand 0.5 ("paradrop_crew_member_with_alt_r" args %0 0)
					else ("paradrop_crew_member_with_alt_r" args %0 1)
					}
				else
					{if rand 0.5 ("paradrop_crew_member_with_alt_r" args %0 2)
					else ("paradrop_crew_member_with_alt_r" args %0 3)
					}
				}
			else
				{if rand 0.5 
					{if rand 0.5 ("paradrop_crew_member_with_alt_r" args %0 4)
					else ("paradrop_crew_member_with_alt_r" args %0 5)
					}
				else
					{if rand 0.5 ("paradrop_crew_member_with_alt_r" args %0 6)
					else ("paradrop_crew_member_with_alt_r" args %0 7)
					}
				}
			}
		)

		(define "paradrop_crew_member_with_alt_r" 
			{tags add "heli_paradrop%1"} 
			{spawn "parachute_new"  "basis" x no_position
				{tags add "heli_parashute%1"} 
				{call "start_alt_%0"}
			}
		)
		(define "eject_crewman"
		{delay 0.3
			{if not tagged "destroyed"
				{link_sound "eject" "vehicle/airborne/eject/eject"}
				{play_sound "eject"}
				{ani_play "%fx_bone_name" callback}
				{add_view	"eject"		"fx_%fx_bone_name" 		"fx_%fx_bone_name"}
				{add_view	"proj_smoke"		"fx_%fx_bone_name"		"fx_%fx_bone_name"}
				{view start "fx_%fx_bone_name"}
				{delay 0.3 {view pause "fx_%fx_bone_name"}}
			}
		}
		)
		{volumes "fonar" disable contact} {delay 0.5 {volumes "fonar" enable contact}}
		{delay 0.1 {tear "piece_big_airborne_wing" bone "fonar"	{impulse up 2 1 forward -5 1}}}
		{delay 0.6 {tear "piece_big_airborne_wing" bone "fonar1"	{impulse up 2 1 forward -5 1}}}
		("eject_crewman" fx_bone_name(eject))
		{delay 0.6 ("eject_crewman" fx_bone_name(eject1))}
		;fx_bone_name - имя анимации, а кость выхлопа - fx_<fx_bone_name>
		;eject_bone_name - имя кости катапультного кресла
		;Далее специфичное для Ка-52
		{add_view	"eject"		"fx_eject" 		"fx_ejecta"}
		{add_view	"eject"		"fx_eject1" 		"fx_eject1a"}
		{add_view	"proj_smoke"		"fx_eject" 		"fx_ejecta"}
		{add_view	"proj_smoke"		"fx_eject1" 		"fx_eject1a"}
		{tear "piece_big_airborne_wing" bone "blade1"	{impulse up 0 0.1 forward 10 1}}
		{tear "piece_big_airborne_wing" bone "blade2"	{impulse up 0 0.1 forward 10 1}}
		{tear "piece_big_airborne_wing" bone "blade3"	{impulse up 0 0.1 forward 10 1}}
		{tear "piece_big_airborne_wing" bone "blade4"	{impulse up 0 0.1 forward 10 1}}
		{tear "piece_big_airborne_wing" bone "blade5"	{impulse up 0 0.1 forward 10 1}}
		{tear "piece_big_airborne_wing" bone "blade6"	{impulse up 0 0.1 forward 10 1}}
		{delay 0.1 {spawn "glass_hit" "glass"}{spawn "glass_hit" "glass1"}{bone cut "glass"}{bone cut "glass1"}}
		
		
		
	}
	(define "eject_end"
		{on animation_end "%fx_bone_name"
		     {view pause "fx_%fx_bone_name"}
 		     {tear "piece_big_airborne_wing" bone "%eject_bone_name"	{impulse up 2 1 forward -1 1}}
		     {if altitude 26
		          {with_linked_entity "%crewman"
			{delay 0.2 ("paradrop_crew_member_with_alt" args 5)}
		          }
		      else altitude 21
		          {with_linked_entity "%crewman"
			{delay 0.2 ("paradrop_crew_member_with_alt" args 4)}
		          }
		      else altitude 16
		          {with_linked_entity "%crewman"
			{delay 0.2 ("paradrop_crew_member_with_alt" args 3)}
		          }
		      else altitude 8
		          {with_linked_entity "%crewman"
			{delay 0.2 ("paradrop_crew_member_with_alt" args 2)}
		          }
		      else altitude 4
		          {with_linked_entity "%crewman"
			{delay 0.2 ("paradrop_crew_member_with_alt" args 1)}
		          }
		      else
		      }
		}
	)
		("eject_end" crewman(driver) fx_bone_name(eject) eject_bone_name(catapult))
		("eject_end" crewman(driver1) fx_bone_name(eject1) eject_bone_name(catapult1))
}

{"ka52_germes"
	{on fire "ptur1" overload
		("low_speed_bullet")
		{delay 0.5 {spawn "germes_carrier" "Foresight3"   x}}
		(define "fire_barrel"
			name "%0"
				{view start "tailL%0"}
				{delay 0.42
					{view pause "tailL%0"}
				}
		)
			{spawn "startsmoke" inv_normal}
			{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			  else ("fire_barrel" args 02)
			  else ("fire_barrel" args 03)
			}
	}
	{on fire "ptur2" overload
		("low_speed_bullet")
		{delay 0.5 {spawn "germes_carrier" "Foresight2"  x}}
		(define "fire_barrel"
			name "%0"
				{view start "tailR%0"}
				{delay 0.42
					{view pause "tailR%0"}
				}
		)
			{spawn "startsmoke" inv_normal}
			{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			  else ("fire_barrel" args 02)
			  else ("fire_barrel" args 03)
			}
	}
	{on fire "nar1" overload
		("low_speed_bullet")
		(define "fire_barrel"
			name "%0"
				;{ani_play "fire"}
				{view start "rok_tail%0"}
				{delay 0.42
					{view pause "rok_tail%0"}
				}
		)
		{spawn "startsmoke" inv_normal}
			{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			  else ("fire_barrel" args 02)
			else ("fire_barrel" args 03)
			  else ("fire_barrel" args 04)
			 else ("fire_barrel" args 05)
			else ("fire_barrel" args 06)
			else ("fire_barrel" args 07)
			else ("fire_barrel" args 08)
			else ("fire_barrel" args 09)
			else ("fire_barrel" args 10)
			else ("fire_barrel" args 11)	
			 else ("fire_barrel" args 12)
			else ("fire_barrel" args 13)
			  else ("fire_barrel" args 14)
			 else ("fire_barrel" args 15)
			else ("fire_barrel" args 16)
			else ("fire_barrel" args 17)
			else ("fire_barrel" args 18)
			else ("fire_barrel" args 19)
			
			 else ("fire_barrel" args 20)
			  else ("fire_barrel" args 21)
			else ("fire_barrel" args 22)
			  else ("fire_barrel" args 23)
			 else ("fire_barrel" args 24)
			else ("fire_barrel" args 25)
			else ("fire_barrel" args 26)
			else ("fire_barrel" args 27)
			else ("fire_barrel" args 28)
			else ("fire_barrel" args 29)
			else ("fire_barrel" args 30)	
			 else ("fire_barrel" args 31)
			else ("fire_barrel" args 32)
			  else ("fire_barrel" args 33)
			 else ("fire_barrel" args 34)
			else ("fire_barrel" args 35)
			else ("fire_barrel" args 36)
			else ("fire_barrel" args 37)
			else ("fire_barrel" args 38)
			else ("fire_barrel" args 39)
			}
		
	}
}

{"mi17"
;-------------------------------------------------------------
	{on spawn
;========================================================================================
		{add_view 	"rok_tail" 		"rok_tail1" 		"Rok_tail01"}
		{add_view 	"rok_tail" 		"rok_tail2" 		"Rok_tail02"}
		{add_view 	"rok_tail" 		"rok_tail3" 		"Rok_tail03"}
		{add_view 	"rok_tail" 		"rok_tail4" 		"Rok_tail04"}
		{add_view 	"rok_tail" 		"rok_tail5" 		"Rok_tail05"}
		{add_view 	"rok_tail" 		"rok_tail6" 		"Rok_tail06"}
			("link_damage_sound_rus")
    	}
	{on "link_flare_fx" overload}
{on "add_movement_sound" overload
		{link_sound "fly"			"vehicle/helicopter/mi-8engine"			}
		{link_sound "engine_start"		"vehicle/helicopter/mi-8en_start"				}
		{link_sound "engine_work"		"vehicle/helicopter/en_work"				}
		{link_sound "engine_stop"		"vehicle/helicopter/mi-8en_stop"				}
}
	{on fire "nar1" overload
		("low_speed_bullet")
			{view start "rok_tail1"}
			{spawn "startsmoke" inv_normal}
			{delay 0.42
				{view pause "rok_tail1"}
			}
	}
	{on fire "nar2" overload
		("low_speed_bullet")
			{view start "rok_tail2"}
			{spawn "startsmoke" inv_normal}
			{delay 0.42
				{view pause "rok_tail2"}
			}
	}
	{on fire "nar3" overload
		("low_speed_bullet")
			{view start "rok_tail3"}
			{spawn "startsmoke" inv_normal}
			{delay 0.42
				{view pause "rok_tail3"}
			}
	}
	{on fire "nar4" overload
		("low_speed_bullet")
			{view start "rok_tail4"}
			{spawn "startsmoke" inv_normal}
			{delay 0.42
				{view pause "rok_tail4"}
			}
	}
	{on fire "nar5" overload
		("low_speed_bullet")
			{view start "rok_tail5"}
			{spawn "startsmoke" inv_normal}
			{delay 0.42
				{view pause "rok_tail5"}
			}
	}
	{on fire "nar6" overload
		("low_speed_bullet")
			{view start "rok_tail6"}
			{spawn "startsmoke" inv_normal}
			{delay 0.42
				{view pause "rok_tail6"}
			}
	}
;----------------------------------------
	{on "tear_propeller_up" overload
		{spawn "propeller_hit2" "propeller" x}
		{spawn "propeller_hit2" "propeller" x}
		{inherited}
	}
;==============================
;paradrop system by Timosh
	{on "paradrop"
		("paradrop_crew" args seat1)
		{delay 2.5 ("paradrop_crew" args seat2)}
		{delay 5 ("paradrop_crew" args seat3)}
		{delay 7.5 ("paradrop_crew" args seat4)}
		{delay 10 ("paradrop_crew" args seat5)}
		{delay 12.5 ("paradrop_crew" args seat6)}
		{delay 15 ("paradrop_crew" args seat7)}
		{delay 17.5 ("paradrop_crew" args seat8)}
		{delay 20 ("paradrop_crew" args seat9)}
		{delay 22.5 ("paradrop_crew" args seat10)}
		{delay 25 ("paradrop_crew" args seat11)}
		{delay 27.5 ("paradrop_crew" args seat12)}
	}
;==============================
}
{"mi8amtsh"
	{on spawn
		{add_view "zenit_gilz"		"shells_we_l"	"FXShell_L"}
		{add_view "flash_gun_big" "flashbarrel_l" "foresight3"}
		{add_view "zenit_gilz"		"shells_we_r"	"FXShell_R"}
		{add_view "flash_gun_big" "flashbarrel_r" "foresight4"}
		{add_view "flash_gun_big" "flashbarrel_b" "foresight5"}
		("link_damage_sound_rus")
    }
	{on "add_movement_sound" overload
		{link_sound "fly"			"vehicle/helicopter/mi-8engine"			}
		{link_sound "engine_start"		"vehicle/helicopter/mi-8en_start"				}
		{link_sound "engine_work"		"vehicle/helicopter/en_work"				}
		{link_sound "engine_stop"		"vehicle/helicopter/mi-8en_stop"				}
	}
;----------------------------------------
	{on "tear_propeller_up" overload
		{spawn "propeller_hit2" "propeller" x}
		{spawn "propeller_hit2" "propeller" x}
		{inherited}
	}
	{on fire "mgun1" overload
		{view start	"flashbarrel_l"}
		{view start	"shells_we_l"}
		{delay 0.2 {view pause	"shells_we_l"} }
		{delay 0.45 "fire" {view pause	"flashbarrel_l"} }
	}
	{on fire "mgun2" overload
		{view start	"flashbarrel_r"}
		{view start	"shells_we_r"}
		{delay 0.2 {view pause	"shells_we_r"} }
		{delay 0.45 "fire" {view pause	"flashbarrel_r"} }
	}
	{on fire "mgun3" overload
		{view start	"flashbarrel_b"}
		{delay 0.45 "fire" {view pause	"flashbarrel_b"} }
	}
	{on fire "nar1" overload
		("low_speed_bullet")
		{spawn "startsmoke" inv_normal}
	}
;==============================
;paradrop system by Timosh
	{on "paradrop"
		("paradrop_crew" args seat1)
		{delay 2.5 ("paradrop_crew" args seat2)}
		{delay 5 ("paradrop_crew" args seat3)}
		{delay 7.5 ("paradrop_crew" args seat4)}
		{delay 10 ("paradrop_crew" args seat5)}
		{delay 12.5 ("paradrop_crew" args seat6)}
		{delay 15 ("paradrop_crew" args seat7)}
		{delay 17.5 ("paradrop_crew" args seat8)}
		{delay 20 ("paradrop_crew" args seat9)}
		{delay 22.5 ("paradrop_crew" args seat10)}
		{delay 25 ("paradrop_crew" args seat11)}
		{delay 27.5 ("paradrop_crew" args seat12)}
	}
;==============================
}

{"Apache"
;-------------------------------------------------------------
	{on spawn
		{add_view	"flash_zenit"		"flashbarrel1"			"Foresight1"}
		{add_view	"exhaust_dark"	"engine_steam1" "FXsmoke1"}			
		{add_view	"exhaust_dark"	"engine_steam2" "FXsmoke2"}
		{add_view       "autocannon_gilz"		"shell"	"fx_shell"}		
		{add_view 	"smoke_zenit" 	"zenite_smoke" 		"foresight1"}
;========================================================================================
		{add_view 	"rok_tail" 		"rok_tail00" 		"shooter_l00"}
		{add_view 	"rok_tail" 		"rok_tail01" 		"shooter_l01"}
		{add_view 	"rok_tail" 		"rok_tail02" 		"shooter_l02"}
		{add_view 	"rok_tail" 		"rok_tail03" 		"shooter_l03"}
		{add_view 	"rok_tail" 		"rok_tail04" 		"shooter_l04"}
		{add_view 	"rok_tail" 		"rok_tail05" 		"shooter_l05"}
		{add_view 	"rok_tail" 		"rok_tail06" 		"shooter_l06"}
		{add_view 	"rok_tail" 		"rok_tail07" 		"shooter_l07"}
		{add_view 	"rok_tail" 		"rok_tail08" 		"shooter_l08"}
		{add_view 	"rok_tail" 		"rok_tail09" 		"shooter_l09"}
		{add_view 	"rok_tail" 		"rok_tail10" 		"shooter_l10"}
		{add_view 	"rok_tail" 		"rok_tail11" 		"shooter_l11"}
		{add_view 	"rok_tail" 		"rok_tail12" 		"shooter_l12"}
		{add_view 	"rok_tail" 		"rok_tail13" 		"shooter_l13"}
		{add_view 	"rok_tail" 		"rok_tail14" 		"shooter_l14"}
		{add_view 	"rok_tail" 		"rok_tail15" 		"shooter_l15"}
		{add_view 	"rok_tail" 		"rok_tail16" 		"shooter_l16"}
		{add_view 	"rok_tail" 		"rok_tail17" 		"shooter_l17"}
		{add_view 	"rok_tail" 		"rok_tail18" 		"shooter_l18"}
		{add_view 	"rok_tail" 		"rok_tail19" 		"shooter_l19"}
;--------------------------------------------------------------------------------------------
		{add_view 	"rok_tail" 		"rok_tail_00" 		"shooter_r00"}
		{add_view 	"rok_tail" 		"rok_tail_01" 		"shooter_r01"}
		{add_view 	"rok_tail" 		"rok_tail_02" 		"shooter_r02"}
		{add_view 	"rok_tail" 		"rok_tail_03" 		"shooter_r03"}
		{add_view 	"rok_tail" 		"rok_tail_04" 		"shooter_r04"}
		{add_view 	"rok_tail" 		"rok_tail_05" 		"shooter_r05"}
		{add_view 	"rok_tail" 		"rok_tail_06" 		"shooter_r06"}
		{add_view 	"rok_tail" 		"rok_tail_07" 		"shooter_r07"}
		{add_view 	"rok_tail" 		"rok_tail_08" 		"shooter_r08"}
		{add_view 	"rok_tail" 		"rok_tail_09" 		"shooter_r09"}
		{add_view 	"rok_tail" 		"rok_tail_10" 		"shooter_r10"}
		{add_view 	"rok_tail" 		"rok_tail_11" 		"shooter_r11"}
		{add_view 	"rok_tail" 		"rok_tail_12" 		"shooter_r12"}
		{add_view 	"rok_tail" 		"rok_tail_13" 		"shooter_r13"}
		{add_view 	"rok_tail" 		"rok_tail_14" 		"shooter_r14"}
		{add_view 	"rok_tail" 		"rok_tail_15" 		"shooter_r15"}
		{add_view 	"rok_tail" 		"rok_tail_16" 		"shooter_r16"}
		{add_view 	"rok_tail" 		"rok_tail_17" 		"shooter_r17"}
		{add_view 	"rok_tail" 		"rok_tail_18" 		"shooter_r18"}
		{add_view 	"rok_tail" 		"rok_tail_19" 		"shooter_r19"}
		{add_view	"flash_cannon_big"		"flashbarrel2"			"Foresight2"}
		{add_view	"flash_cannon_big"		"flashbarrel3"			"Foresight3"}
		{add_view	"flash_cannon_big"		"flashbarrel7"			"Foresight7"}
		{add_view	"flash_cannon_big"		"flashbarrel8"			"Foresight8"}
			("link_damage_sound_usa")
    	}
{on "add_movement_sound" overload
		{link_sound "fly"			"vehicle/helicopter/ah-64engine"			}
		{link_sound "engine_start"		"vehicle/helicopter/ah-64en_start"				}
		{link_sound "engine_work"		"vehicle/helicopter/en_work"				}
		{link_sound "engine_stop"		"vehicle/helicopter/ah-64en_stop"				}
}
	{on fire "nar1" overload
		(define "fire_barrel"
			name "%0"
				;{ani_play "fire"}
				{view start "rok_tail%0"}
				{delay 0.42
					{view pause "rok_tail%0"}
				}
		)
		{spawn "startsmoke" inv_normal}
			{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			  else ("fire_barrel" args 02)
			else ("fire_barrel" args 03)
			  else ("fire_barrel" args 04)
			 else ("fire_barrel" args 05)
			else ("fire_barrel" args 06)
			else ("fire_barrel" args 07)
			else ("fire_barrel" args 08)
			else ("fire_barrel" args 09)
			else ("fire_barrel" args 10)
			else ("fire_barrel" args 11)	
			 else ("fire_barrel" args 12)
			else ("fire_barrel" args 13)
			  else ("fire_barrel" args 14)
			 else ("fire_barrel" args 15)
			else ("fire_barrel" args 16)
			else ("fire_barrel" args 17)
			else ("fire_barrel" args 18)
			else ("fire_barrel" args 19)
			}
		{if name "00"
			{call "fire_gun_common"}
		}
	}
	{on fire "nar2" overload
		(define "fire_barrel"
			name "%0"
				;{ani_play "fire"}
				{view start "rok_tail_%0"}
				{delay 0.42
					{view pause "rok_tail_%0"}
				}
		)
		{spawn "startsmoke" inv_normal}
			{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			  else ("fire_barrel" args 02)
			else ("fire_barrel" args 03)
			  else ("fire_barrel" args 04)
			 else ("fire_barrel" args 25)
			else ("fire_barrel" args 06)
			else ("fire_barrel" args 07)
			else ("fire_barrel" args 08)
			else ("fire_barrel" args 09)
			else ("fire_barrel" args 10)
			else ("fire_barrel" args 11)	
			 else ("fire_barrel" args 12)
			else ("fire_barrel" args 13)
			  else ("fire_barrel" args 14)
			 else ("fire_barrel" args 15)
			else ("fire_barrel" args 16)
			else ("fire_barrel" args 17)
			else ("fire_barrel" args 18)
			else ("fire_barrel" args 19)							
			}
		{if name "00"
			{call "fire_gun_common"}
		}
	}
;----------------------------------------
	{on "die"
		{bone hide "rocketR00"}
		{bone hide "rocketR01"}
		{bone hide "rocketR02"}
		{bone hide "rocketR03"}
		{bone hide "rocketL00"}
		{bone hide "rocketL01"}
		{bone hide "rocketL02"}
		{bone hide "rocketL03"}
	}
;-------------------------------------------------
	{on fire "ptur1" overload
		("low_speed_bullet")
		{view start "flashbarrel3"}
;		{spawn "proj_probe" "Foresight3" x  {tags add "Foresight3"}}
		{set "ptur1"}{call "proj_probe"}
		{delay 0.42
			{view pause "flashbarrel3"}
		}
	}
	{on fire "ptur2" overload
		("low_speed_bullet")
		{view start "flashbarrel2"}
;		{spawn "proj_probe" "Foresight2" x  {tags add "Foresight2"}}
		{set "ptur2"}{call "proj_probe"}
		{delay 0.42
			{view pause "flashbarrel2"}
		}
	}
	{on fire "ptur3" overload
		{view start "flashbarrel7"}
		{delay 0.1 {spawn "aim-9l_carrier" "aim-9l_l"  x}}
		{delay 0.42
			{view pause "flashbarrel7"}
		}
	}
	{on fire "ptur4" overload
		{view start "flashbarrel8"}
		{delay 0.1 {spawn "aim-9l_carrier" "aim-9l_r"  x}}
		{delay 0.42
			{view pause "flashbarrel8"}
		}
	}
	{on "tear_propeller_tail"
		{spawn "propeller_hit3" "propeller2" x}
		{spawn "propeller_hit3" "propeller2" x}
		{spawn "propeller_hit3" "propeller2" x}
	}
	{on "tear_propeller_tail1"
			{bone cut "propeller2"}
	}
	{on "tear_propeller_up" overload
		{spawn "propeller_hit2" "propeller" x}
		{inherited}
	}
}
{"Apache_spike"
;-------------------------------------------------------------
	{on spawn
		{add_view	"flash_zenit"		"flashbarrel1"			"Foresight1"}
		{add_view	"exhaust_dark"	"engine_steam1" "FXsmoke1"}			
		{add_view	"exhaust_dark"	"engine_steam2" "FXsmoke2"}
		{add_view       "autocannon_gilz"		"shell"	"fx_shell"}		
		{add_view 	"smoke_zenit" 	"zenite_smoke" 		"foresight1"}
;========================================================================================
		{add_view	 "flash_gun_big"	"shooter_r00"	"shooter_r00"}
		{add_view	 "flash_gun_big"	"shooter_r01"	"shooter_r01"}
		{add_view	 "flash_gun_big"	"shooter_r02"	"shooter_r02"}
		{add_view	 "flash_gun_big"	"shooter_r03"	"shooter_r03"}
		{add_view	 "startsmoke_big"	"shooter_r00"	"tail_r00"}
		{add_view	 "startsmoke_big"	"shooter_r01"	"tail_r01"}
		{add_view	 "startsmoke_big"	"shooter_r02"	"tail_r02"}
		{add_view	 "startsmoke_big"	"shooter_r03"	"tail_r03"}
		{add_view	 "flash_gun_big"	"shooter_l00"	"shooter_l00"}
		{add_view	 "flash_gun_big"	"shooter_l01"	"shooter_l01"}
		{add_view	 "flash_gun_big"	"shooter_l02"	"shooter_l02"}
		{add_view	 "flash_gun_big"	"shooter_l03"	"shooter_l03"}
		{add_view	 "startsmoke_big"	"shooter_l00"	"tail_l00"}
		{add_view	 "startsmoke_big"	"shooter_l01"	"tail_l01"}
		{add_view	 "startsmoke_big"	"shooter_l02"	"tail_l02"}
		{add_view	 "startsmoke_big"	"shooter_l03"	"tail_l03"}
			("link_damage_sound_usa")
    	}
{on "add_movement_sound" overload
		{link_sound "fly"			"vehicle/helicopter/ah-64engine"			}
		{link_sound "engine_start"		"vehicle/helicopter/ah-64en_start"				}
		{link_sound "engine_work"		"vehicle/helicopter/en_work"				}
		{link_sound "engine_stop"		"vehicle/helicopter/ah-64en_stop"				}
}
;----------------------------------------
	{on "die"
		{bone hide "rocketR00"}
		{bone hide "rocketR01"}
		{bone hide "rocketR02"}
		{bone hide "rocketR03"}
		{bone hide "rocketL00"}
		{bone hide "rocketL01"}
		{bone hide "rocketL02"}
		{bone hide "rocketL03"}
	}
;-------------------------------------------------
	{on fire "ptur1" overload 
		(define "fire_barrel"
			name "%0"
				{spawn "startsmoke" "shooter_l%0"   x}
;				{spawn "proj_probe" "foresight3"   x {tags add "shooter_l%0"}}
				{set "ptur1"}{call "proj_probe"}
				{view start "shooter_l%0"}
				{delay 0.42
					{view pause "shooter_l%0"}
				}
		)
		{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			  else ("fire_barrel" args 02)
			else ("fire_barrel" args 03)
		}
	}
	{on fire "ptur2" overload 
		(define "fire_barrel"
			name "%0"
				{spawn "startsmoke" "shooter_r%0"   x}
;				{spawn "proj_probe" "foresight2"   x {tags add "shooter_r%0"}}
				{set "ptur2"}{call "proj_probe"}
				{view start "shooter_r%0"}
				{delay 0.42
					{view pause "shooter_r%0"}
				}
		)
		{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			  else ("fire_barrel" args 02)
			else ("fire_barrel" args 03)
		}
	}
	{on "tear_propeller_tail"
		{spawn "propeller_hit3" "propeller2" x}
		{spawn "propeller_hit3" "propeller2" x}
		{spawn "propeller_hit3" "propeller2" x}
	}
	{on "tear_propeller_tail1"
			{bone cut "propeller2"}
	}
	{on "tear_propeller_up" overload
		{spawn "propeller_hit2" "propeller" x}
		{inherited}
	}
}

{"ah1z"
;-------------------------------------------------------------
	{on spawn
		{add_view	"flash_zenit"		"flashbarrel1"			"Foresight1"}
		{add_view	"exhaust_dark"	"engine_steam1" "FXsmoke1"}			
		{add_view	"exhaust_dark"	"engine_steam2" "FXsmoke2"}
		{add_view 	"smoke_zenit" 	"zenite_smoke" 		"foresight1"}
;========================================================================================
		{add_view 	"rok_tail" 		"rok_tail00" 		"shooter_l00"}
		{add_view 	"rok_tail" 		"rok_tail01" 		"shooter_l01"}
		{add_view 	"rok_tail" 		"rok_tail02" 		"shooter_l02"}
		{add_view 	"rok_tail" 		"rok_tail03" 		"shooter_l03"}
		{add_view 	"rok_tail" 		"rok_tail04" 		"shooter_l04"}
		{add_view 	"rok_tail" 		"rok_tail05" 		"shooter_l05"}
		{add_view 	"rok_tail" 		"rok_tail06" 		"shooter_l06"}
		{add_view 	"rok_tail" 		"rok_tail07" 		"shooter_l07"}
		{add_view 	"rok_tail" 		"rok_tail08" 		"shooter_l08"}
		{add_view 	"rok_tail" 		"rok_tail09" 		"shooter_l09"}
		{add_view 	"rok_tail" 		"rok_tail10" 		"shooter_l10"}
		{add_view 	"rok_tail" 		"rok_tail11" 		"shooter_l11"}
		{add_view 	"rok_tail" 		"rok_tail12" 		"shooter_l12"}
		{add_view 	"rok_tail" 		"rok_tail13" 		"shooter_l13"}
		{add_view 	"rok_tail" 		"rok_tail14" 		"shooter_l14"}
		{add_view 	"rok_tail" 		"rok_tail15" 		"shooter_l15"}
		{add_view 	"rok_tail" 		"rok_tail16" 		"shooter_l16"}
		{add_view 	"rok_tail" 		"rok_tail17" 		"shooter_l17"}
		{add_view 	"rok_tail" 		"rok_tail18" 		"shooter_l18"}
		{add_view 	"rok_tail" 		"rok_tail19" 		"shooter_l19"}
;--------------------------------------------------------------------------------------------
		{add_view 	"rok_tail" 		"rok_tail_00" 		"shooter_r00"}
		{add_view 	"rok_tail" 		"rok_tail_01" 		"shooter_r01"}
		{add_view 	"rok_tail" 		"rok_tail_02" 		"shooter_r02"}
		{add_view 	"rok_tail" 		"rok_tail_03" 		"shooter_r03"}
		{add_view 	"rok_tail" 		"rok_tail_04" 		"shooter_r04"}
		{add_view 	"rok_tail" 		"rok_tail_05" 		"shooter_r05"}
		{add_view 	"rok_tail" 		"rok_tail_06" 		"shooter_r06"}
		{add_view 	"rok_tail" 		"rok_tail_07" 		"shooter_r07"}
		{add_view 	"rok_tail" 		"rok_tail_08" 		"shooter_r08"}
		{add_view 	"rok_tail" 		"rok_tail_09" 		"shooter_r09"}
		{add_view 	"rok_tail" 		"rok_tail_10" 		"shooter_r10"}
		{add_view 	"rok_tail" 		"rok_tail_11" 		"shooter_r11"}
		{add_view 	"rok_tail" 		"rok_tail_12" 		"shooter_r12"}
		{add_view 	"rok_tail" 		"rok_tail_13" 		"shooter_r13"}
		{add_view 	"rok_tail" 		"rok_tail_14" 		"shooter_r14"}
		{add_view 	"rok_tail" 		"rok_tail_15" 		"shooter_r15"}
		{add_view 	"rok_tail" 		"rok_tail_16" 		"shooter_r16"}
		{add_view 	"rok_tail" 		"rok_tail_17" 		"shooter_r17"}
		{add_view 	"rok_tail" 		"rok_tail_18" 		"shooter_r18"}
		{add_view 	"rok_tail" 		"rok_tail_19" 		"shooter_r19"}
		{add_view	"flash_cannon_big"		"flashbarrel2"			"Foresight2"}
		{add_view	"flash_cannon_big"		"flashbarrel3"			"Foresight3"}
		{add_view	"flash_cannon_big"		"flashbarrel7"			"Foresight7"}
		{add_view	"flash_cannon_big"		"flashbarrel8"			"Foresight8"}
			("link_damage_sound_usa")
    	}
{on "add_movement_sound" overload
		{link_sound "fly"			"vehicle/helicopter/ah-1zengine"			}
		{link_sound "engine_start"		"vehicle/helicopter/ah-1zen_start"				}
		{link_sound "engine_work"		"vehicle/helicopter/en_work"				}
		{link_sound "engine_stop"		"vehicle/helicopter/ah-1zen_stop"				}
}
	{on fire "nar1" overload
		(define "fire_barrel"
			name "%0"
				;{ani_play "fire"}
				{view start "rok_tail%0"}
				{delay 0.42
					{view pause "rok_tail%0"}
				}
		)
		{spawn "startsmoke" inv_normal}
			{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			  else ("fire_barrel" args 02)
			else ("fire_barrel" args 03)
			  else ("fire_barrel" args 04)
			 else ("fire_barrel" args 05)
			else ("fire_barrel" args 06)
			else ("fire_barrel" args 07)
			else ("fire_barrel" args 08)
			else ("fire_barrel" args 09)
			else ("fire_barrel" args 10)
			else ("fire_barrel" args 11)	
			 else ("fire_barrel" args 12)
			else ("fire_barrel" args 13)
			  else ("fire_barrel" args 14)
			 else ("fire_barrel" args 15)
			else ("fire_barrel" args 16)
			else ("fire_barrel" args 17)
			else ("fire_barrel" args 18)
			else ("fire_barrel" args 19)
			}
		{if name "00"
			{call "fire_gun_common"}
		}
	}
	{on fire "nar2" overload
		(define "fire_barrel"
			name "%0"
				;{ani_play "fire"}
				{view start "rok_tail_%0"}
				{delay 0.42
					{view pause "rok_tail_%0"}
				}
		)
		{spawn "startsmoke" inv_normal}
			{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			  else ("fire_barrel" args 02)
			else ("fire_barrel" args 03)
			  else ("fire_barrel" args 04)
			 else ("fire_barrel" args 25)
			else ("fire_barrel" args 06)
			else ("fire_barrel" args 07)
			else ("fire_barrel" args 08)
			else ("fire_barrel" args 09)
			else ("fire_barrel" args 10)
			else ("fire_barrel" args 11)	
			 else ("fire_barrel" args 12)
			else ("fire_barrel" args 13)
			  else ("fire_barrel" args 14)
			 else ("fire_barrel" args 15)
			else ("fire_barrel" args 16)
			else ("fire_barrel" args 17)
			else ("fire_barrel" args 18)
			else ("fire_barrel" args 19)							
			}
		{if name "00"
			{call "fire_gun_common"}
		}
	}
;----------------------------------------
	{on "die"
		{bone hide "rocketR00"}
		{bone hide "rocketR01"}
		{bone hide "rocketR02"}
		{bone hide "rocketR03"}
		{bone hide "rocketL00"}
		{bone hide "rocketL01"}
		{bone hide "rocketL02"}
		{bone hide "rocketL03"}
	}
;-------------------------------------------------
	{on fire "ptur1" overload
		("low_speed_bullet")
		{view start "flashbarrel3"}
;		{spawn "proj_probe" "Foresight3" x  {tags add "Foresight3"}}
		{set "ptur1"}{call "proj_probe"}
		{delay 0.42
			{view pause "flashbarrel3"}
		}
	}
	{on fire "ptur2" overload
		("low_speed_bullet")
		{view start "flashbarrel2"}
;		{spawn "proj_probe" "Foresight2" x  {tags add "Foresight2"}}
		{set "ptur2"}{call "proj_probe"}
		{delay 0.42
			{view pause "flashbarrel2"}
		}
	}
	{on fire "ptur3" overload
		{view start "flashbarrel7"}
		{delay 0.1 {spawn "aim-9l_carrier" "aim-9l_l"  x}}
		{delay 0.42
			{view pause "flashbarrel7"}
		}
	}
	{on fire "ptur4" overload
		{view start "flashbarrel8"}
		{delay 0.1 {spawn "aim-9l_carrier" "aim-9l_r"  x}}
		{delay 0.42
			{view pause "flashbarrel8"}
		}
	}
	{on "tear_propeller_up" overload
		{spawn "propeller_hit2" "propeller" x}
		{inherited}
	}
}

{"ka50sh"	;остальное в Ка-50
;-------------------------------------------------------------
	{on spawn
		{add_view	"flash_cannon_big"		"r73_launch_00"			"r73_launch_00"}
		{add_view	"flash_cannon_big"		"r73_launch_01"			"r73_launch_01"}
			("link_damage_sound_rus")
    }
	("air_multibarrel_launcher" weapon(ptur3) shooter(x-25_launch_) missile(x_25ml_su25_ammo) flashbarrel(x-25_launch_))
	("air_multibarrel_launcher" weapon(ptur4) shooter(r73_launch_) missile(r-73) flashbarrel(r73_launch_))

}
{"UH60"
;-------------------------------------------------------------
	{on spawn
;========================================================================================
			{add_view "zenit_gilz"		"shells_we_r"	"FXShell_R"}
			{add_view "flash_gun_big" "flashbarrel_r" "foresight2"}
			{add_view "smoke_zenit" "smoke_shell_r" "Foresight2"}
			{add_view "flash_gun_big" "flashbarrel_l" "foresight1"}
			{add_view "smoke_zenit" "smoke_shell_l" "Foresight1"}
			{add_view	"exhaust_dark"	"engine_steam1" "FXsmoke1"}			
			{add_view	"exhaust_dark"	"engine_steam2" "FXsmoke2"}
			("link_damage_sound_usa")
    	}
	{on "add_movement_sound" overload
		{link_sound "fly"			"vehicle/helicopter/uh-60engine"			}
		{link_sound "engine_start"		"vehicle/helicopter/uh-60en_start"				}
		{link_sound "engine_work"		"vehicle/helicopter/en_work"				}
		{link_sound "engine_stop"		"vehicle/helicopter/uh-60en_stop"				}
	}
	{on fire "mgun1" 
		{view start	"flashbarrel_r"}
		{view start	"shells_we_r"}
		{view start	"smoke_shell_r"}
		{delay 0.2
			{view pause	"shells_we_r"}
		}
		{delay 0.45 "fire"
			{view pause	"flashbarrel_r"}
			{view pause	"smoke_shell_r"}
		}
	}
	{on fire "mgun" 
		{view start	"flashbarrel_l"}
		{view start	"smoke_shell_l"}
		{delay 0.45 "fire"
			{view pause	"flashbarrel_l"}
			{view pause	"smoke_shell_l"}
		}
	}
;----------------------------------------
	{on "tear_propeller_up" overload
		{spawn "propeller_hit2" "propeller" x}
		{inherited}
	}
;==============================
;paradrop system by Timosh
	{on "paradrop"
		("paradrop_crew" args seat1)
		{delay 0.6 ("paradrop_crew" args seat2)}
		{delay 1.2 ("paradrop_crew" args seat3)}
		{delay 1.8 ("paradrop_crew" args seat4)}
		{delay 2.4 ("paradrop_crew" args seat5)}
		{delay 3 ("paradrop_crew" args seat6)}
		{delay 3.6 ("paradrop_crew" args seat7)}
		{delay 4.2 ("paradrop_crew" args seat8)}
		{delay 4.8 ("paradrop_crew" args seat9)}
		{delay 5.4 ("paradrop_crew" args seat10)}
		{delay 6 ("paradrop_crew" args seat11)}
	}
;==============================
}
{"uh1y"
	{on spawn
		{add_view	"exhaust_dark"	"engine_steam1" "FXsmoke1"}			
		{add_view	"exhaust_dark"	"engine_steam2" "FXsmoke2"}
		{add_view 	"rok_tail" 		"rok_tailR00" 		"shooterR00"}
		{add_view 	"rok_tail" 		"rok_tailR01" 		"shooterR01"}
		{add_view 	"rok_tail" 		"rok_tailR02" 		"shooterR02"}
		{add_view 	"rok_tail" 		"rok_tailR03" 		"shooterR03"}
		{add_view 	"rok_tail" 		"rok_tailR04" 		"shooterR04"}
		{add_view 	"rok_tail" 		"rok_tailR05" 		"shooterR05"}
		{add_view 	"rok_tail" 		"rok_tailR06" 		"shooterR06"}
		{add_view 	"rok_tail" 		"rok_tailL00" 		"shooterL00"}
		{add_view 	"rok_tail" 		"rok_tailL01" 		"shooterL01"}
		{add_view 	"rok_tail" 		"rok_tailL02" 		"shooterL02"}
		{add_view 	"rok_tail" 		"rok_tailL03" 		"shooterL03"}
		{add_view 	"rok_tail" 		"rok_tailL04" 		"shooterL04"}
		{add_view 	"rok_tail" 		"rok_tailL05" 		"shooterL05"}
		{add_view 	"rok_tail" 		"rok_tailL06" 		"shooterL06"}
	}
	{on "add_movement_sound" overload
		{link_sound "fly"			"vehicle/helicopter/UH-1engine"			}
		{link_sound "engine_start"		"vehicle/helicopter/UH-1en_start"				}
		{link_sound "engine_work"		"vehicle/helicopter/en_work"				}
		{link_sound "engine_stop"		"vehicle/helicopter/UH-1en_stop"				}
	}
	{on fire "nar1" overload
		(define "fire_barrel"
			name "%0"
				{view start "rok_tailL%0"}
				{delay 0.42
					{view pause "rok_tailL%0"}
				}
		)
		{spawn "startsmoke" inv_normal}
			{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			  else ("fire_barrel" args 02)
			else ("fire_barrel" args 03)
			  else ("fire_barrel" args 04)
			 else ("fire_barrel" args 05)
			else ("fire_barrel" args 06)
			}
		{if name "00"
			{call "fire_gun_common"}
		}
	}
	{on fire "nar2" overload
		(define "fire_barrel"
			name "%0"
				{view start "rok_tailR%0"}
				{delay 0.42
					{view pause "rok_tailR%0"}
				}
		)
		{spawn "startsmoke" inv_normal}
			{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			  else ("fire_barrel" args 02)
			else ("fire_barrel" args 03)
			  else ("fire_barrel" args 04)
			 else ("fire_barrel" args 25)
			else ("fire_barrel" args 06)
			}
		{if name "00"
			{call "fire_gun_common"}
		}
	}
	{on "tear_propeller_up" overload
		{spawn "propeller_hit2" "propeller" x}
		{inherited}
	}
}
{"mh-6"
	{on "add_movement_sound" overload
		{link_sound "fly"			"vehicle/helicopter/mh-6engine"			}
		{link_sound "engine_start"		"vehicle/helicopter/mh-6en_start"				}
		{link_sound "engine_work"		"vehicle/helicopter/en_work"				}
		{link_sound "engine_stop"		"vehicle/helicopter/mh-6en_stop"				}
	}
	{on "link_flare_fx" overload}
	{on "tear_propeller_up" overload
		{spawn "propeller_hit2" "propeller" x}
		{spawn "propeller_hit2" "propeller" x}
		{inherited}
	}
}
{"mi-24"
;-------------------------------------------------------------
	{on spawn
		{add_view	"flash_zenit"		"flashbarrel1"			"Foresight1"}
		{add_view 	"zenit_gilz"		"flashbarrel1"			"fx_shell"}
		{add_view	"exhaust_dark"	"engine_steam1" "FXsmoke1"}			
		{add_view	"exhaust_dark"	"engine_steam2" "FXsmoke2"}
;========================================================================================
		{add_view 	"rok_tail" 		"rok_tail00" 		"shooter_l00"}
		{add_view 	"rok_tail" 		"rok_tail01" 		"shooter_l01"}
		{add_view 	"rok_tail" 		"rok_tail02" 		"shooter_l02"}
		{add_view 	"rok_tail" 		"rok_tail03" 		"shooter_l03"}
		{add_view 	"rok_tail" 		"rok_tail04" 		"shooter_l04"}
		{add_view 	"rok_tail" 		"rok_tail05" 		"shooter_l05"}
		{add_view 	"rok_tail" 		"rok_tail06" 		"shooter_l06"}
		{add_view 	"rok_tail" 		"rok_tail07" 		"shooter_l07"}
		{add_view 	"rok_tail" 		"rok_tail08" 		"shooter_l08"}
		{add_view 	"rok_tail" 		"rok_tail09" 		"shooter_l09"}
		{add_view 	"rok_tail" 		"rok_tail10" 		"shooter_l10"}
		{add_view 	"rok_tail" 		"rok_tail11" 		"shooter_l11"}
		{add_view 	"rok_tail" 		"rok_tail12" 		"shooter_l12"}
		{add_view 	"rok_tail" 		"rok_tail13" 		"shooter_l13"}
		{add_view 	"rok_tail" 		"rok_tail14" 		"shooter_l14"}
		{add_view 	"rok_tail" 		"rok_tail15" 		"shooter_l15"}
		{add_view 	"rok_tail" 		"rok_tail16" 		"shooter_l16"}
		{add_view 	"rok_tail" 		"rok_tail17" 		"shooter_l17"}
		{add_view 	"rok_tail" 		"rok_tail18" 		"shooter_l18"}
		{add_view 	"rok_tail" 		"rok_tail19" 		"shooter_l19"}
;--------------------------------------------------------------------------------------------
		{add_view 	"rok_tail" 		"rok_tail_00" 		"shooter_r00"}
		{add_view 	"rok_tail" 		"rok_tail_01" 		"shooter_r01"}
		{add_view 	"rok_tail" 		"rok_tail_02" 		"shooter_r02"}
		{add_view 	"rok_tail" 		"rok_tail_03" 		"shooter_r03"}
		{add_view 	"rok_tail" 		"rok_tail_04" 		"shooter_r04"}
		{add_view 	"rok_tail" 		"rok_tail_05" 		"shooter_r05"}
		{add_view 	"rok_tail" 		"rok_tail_06" 		"shooter_r06"}
		{add_view 	"rok_tail" 		"rok_tail_07" 		"shooter_r07"}
		{add_view 	"rok_tail" 		"rok_tail_08" 		"shooter_r08"}
		{add_view 	"rok_tail" 		"rok_tail_09" 		"shooter_r09"}
		{add_view 	"rok_tail" 		"rok_tail_10" 		"shooter_r10"}
		{add_view 	"rok_tail" 		"rok_tail_11" 		"shooter_r11"}
		{add_view 	"rok_tail" 		"rok_tail_12" 		"shooter_r12"}
		{add_view 	"rok_tail" 		"rok_tail_13" 		"shooter_r13"}
		{add_view 	"rok_tail" 		"rok_tail_14" 		"shooter_r14"}
		{add_view 	"rok_tail" 		"rok_tail_15" 		"shooter_r15"}
		{add_view 	"rok_tail" 		"rok_tail_16" 		"shooter_r16"}
		{add_view 	"rok_tail" 		"rok_tail_17" 		"shooter_r17"}
		{add_view 	"rok_tail" 		"rok_tail_18" 		"shooter_r18"}
		{add_view 	"rok_tail" 		"rok_tail_19" 		"shooter_r19"}
;============================================================================================
		{add_view 	"rok_tail" 		"ptur1tail_00" 		"ptur1tail_00"}
		{add_view 	"rok_tail" 		"ptur1tail_01" 		"ptur1tail_01"}
		{add_view 	"rok_tail" 		"ptur2tail_00" 		"ptur2tail_00"}
		{add_view 	"rok_tail" 		"ptur2tail_01" 		"ptur2tail_01"}

		{add_view 	"flash_cannon_big"		"ptur1tail_00" 		"ptur1shooter_00"}
		{add_view 	"flash_cannon_big"		"ptur1tail_01" 		"ptur1shooter_01"}
		{add_view 	"flash_cannon_big"		"ptur2tail_00" 		"ptur2shooter_00"}
		{add_view 	"flash_cannon_big"		"ptur2tail_01" 		"ptur2shooter_01"}
;============================================================================================
		{add_view "flash_zenit"			"upk00"	"shooter_upk_00"}
		{add_view "flash_zenit"			"upk01"	"shooter_upk_01"}
		{add_view "flash_zenit"			"upk02"	"shooter_upk_02"}
		{add_view "flash_zenit"			"upk03"	"shooter_upk_03"}

		("link_damage_sound_rus")
    	}
{on "add_movement_sound" overload
		{link_sound "fly"			"vehicle/helicopter/mi-24engine"			}
		{link_sound "engine_start"		"vehicle/helicopter/mi-8en_start"				}
		{link_sound "engine_work"		"vehicle/helicopter/en_work"				}
		{link_sound "engine_stop"		"vehicle/helicopter/mi-8en_stop"				}
}
	{on fire "nar1" overload
		("low_speed_bullet")
		(define "fire_barrel"
			name "%0"
				;{ani_play "fire"}
				{view start "rok_tail%0"}
				{delay 0.42
					{view pause "rok_tail%0"}
				}
		)
		{spawn "startsmoke" inv_normal}
			{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			  else ("fire_barrel" args 02)
			else ("fire_barrel" args 03)
			  else ("fire_barrel" args 04)
			 else ("fire_barrel" args 05)
			else ("fire_barrel" args 06)
			else ("fire_barrel" args 07)
			else ("fire_barrel" args 08)
			else ("fire_barrel" args 09)
			else ("fire_barrel" args 10)
			else ("fire_barrel" args 11)	
			 else ("fire_barrel" args 12)
			else ("fire_barrel" args 13)
			  else ("fire_barrel" args 14)
			 else ("fire_barrel" args 15)
			else ("fire_barrel" args 16)
			else ("fire_barrel" args 17)
			else ("fire_barrel" args 18)
			else ("fire_barrel" args 19)
			}
		{if name "00"
			{call "fire_gun_common"}
		}
	}
	{on fire "nar2" overload
		("low_speed_bullet")
		(define "fire_barrel"
			name "%0"
				;{ani_play "fire"}
				{view start "rok_tail_%0"}
				{delay 0.42
					{view pause "rok_tail_%0"}
				}
		)
		{spawn "startsmoke" inv_normal}
			{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			  else ("fire_barrel" args 02)
			else ("fire_barrel" args 03)
			  else ("fire_barrel" args 04)
			 else ("fire_barrel" args 25)
			else ("fire_barrel" args 06)
			else ("fire_barrel" args 07)
			else ("fire_barrel" args 08)
			else ("fire_barrel" args 09)
			else ("fire_barrel" args 10)
			else ("fire_barrel" args 11)	
			 else ("fire_barrel" args 12)
			else ("fire_barrel" args 13)
			  else ("fire_barrel" args 14)
			 else ("fire_barrel" args 15)
			else ("fire_barrel" args 16)
			else ("fire_barrel" args 17)
			else ("fire_barrel" args 18)
			else ("fire_barrel" args 19)							
			}
		{if name "00"
			{call "fire_gun_common"}
		}
	}
;----------------------------------------
	{on operatable on
		{ani_play "open"}
	}
	{on operatable off
		{ani_play "open" -1}
	}
	{on fire "mgun" overload
		{kill_delay "fire"}
		{view start "flashbarrel1"}

		{delay 0.05
			{view pause "flashbarrel1"}
		}
		{ani_play "fire"}
	}
	{on fire "gun" overload
		{if name "00"
			{view start "upk00"}	{delay 0.42	{view pause "upk00"}}
		else  name "01"
			{view start "upk01"}	{delay 0.42	{view pause "upk01"}}
		else  name "02"
			{view start "upk02"}	{delay 0.42	{view pause "upk02"}}
		else  name "03"
			{view start "upk03"}	{delay 0.42	{view pause "upk03"}}
		}
	}
	{on "tear_part"
		{if volume "part6" {bone cut "shooter_upk_00"} {bone cut "shooter_upk_01"}
		else volume "WingL1" {bone cut "shooter_upk_00"} {bone cut "shooter_upk_01"}
		else volume "part7" {bone cut "shooter_upk_02"} {bone cut "shooter_upk_03"}
		else volume "WingR1" {bone cut "shooter_upk_02"} {bone cut "shooter_upk_03"}
		else volume "Part8" {bone cut "Anten_L"}
		else volume "Part9" {bone cut "Anten_R"}
		}
	}
	{on "tear_propeller_up" overload
		{spawn "propeller_hit2" "propeller" x}
		{spawn "propeller_hit2" "propeller" x}
		{inherited}
	}
}
{"mi-24v"
	{on fire "ptur1" overload
		("low_speed_bullet")
;		{spawn "proj_probe" "Foresight3" x  {tags add "Foresight3"}}
		{set "ptur1"}{call "proj_probe"}
		(define "fire_barrel"
			name "%0"
				{view start "ptur1tail_%0"}
				{delay 0.42
					{view pause "ptur1tail_%0"}
				}
		)
			{spawn "startsmoke" inv_normal}
			{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			}
	}
	{on fire "ptur2" overload
		("low_speed_bullet")
;		{spawn "proj_probe" "Foresight4" x  {tags add "Foresight4"}}
		{set "ptur2"}{call "proj_probe"}
		(define "fire_barrel"
			name "%0"
				{view start "ptur2tail_%0"}
				{delay 0.42
					{view pause "ptur2tail_%0"}
				}
		)
			{spawn "startsmoke" inv_normal}
			{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			}
	}
	{on fire "nar1" overload
		("low_speed_bullet")
		(define "fire_barrel"
			name "%0"
				;{ani_play "fire"}
				{view start "rok_tail%0"}
				{delay 0.42
					{view pause "rok_tail%0"}
				}
		)
		{spawn "startsmoke" inv_normal}
			{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			  else ("fire_barrel" args 02)
			else ("fire_barrel" args 03)
			  else ("fire_barrel" args 04)
			 else ("fire_barrel" args 05)
			else ("fire_barrel" args 06)
			else ("fire_barrel" args 07)
			else ("fire_barrel" args 08)
			else ("fire_barrel" args 09)
			else ("fire_barrel" args 10)
			else ("fire_barrel" args 11)	
			 else ("fire_barrel" args 12)
			else ("fire_barrel" args 13)
			  else ("fire_barrel" args 14)
			 else ("fire_barrel" args 15)
			else ("fire_barrel" args 16)
			else ("fire_barrel" args 17)
			else ("fire_barrel" args 18)
			else ("fire_barrel" args 19)
			
			 else ("fire_barrel" args 20)
			  else ("fire_barrel" args 21)
			else ("fire_barrel" args 22)
			  else ("fire_barrel" args 23)
			 else ("fire_barrel" args 24)
			else ("fire_barrel" args 25)
			else ("fire_barrel" args 26)
			else ("fire_barrel" args 27)
			else ("fire_barrel" args 28)
			else ("fire_barrel" args 29)
			else ("fire_barrel" args 30)	
			 else ("fire_barrel" args 31)
			else ("fire_barrel" args 32)
			  else ("fire_barrel" args 33)
			 else ("fire_barrel" args 34)
			else ("fire_barrel" args 35)
			else ("fire_barrel" args 36)
			else ("fire_barrel" args 37)
			else ("fire_barrel" args 38)
			else ("fire_barrel" args 39)
			}
		
	}
}
{"mi-35"
	{on fire "ptur1" overload
		("low_speed_bullet")
;		{spawn "proj_probe" "Foresight3" x  {tags add "Foresight3"}}
		{set "ptur1"}{call "proj_probe"}
		(define "fire_barrel"
			name "%0"
				{view start "ptur1tail_%0"}
				{delay 0.42
					{view pause "ptur1tail_%0"}
				}
		)
			{spawn "startsmoke" inv_normal}
			{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			  else ("fire_barrel" args 02)
			  else ("fire_barrel" args 03)
			  else ("fire_barrel" args 04)
			  else ("fire_barrel" args 05)
			  else ("fire_barrel" args 06)
			  else ("fire_barrel" args 07)
			}
	}
	{on fire "ptur2" overload
		("low_speed_bullet")
;		{spawn "proj_probe" "Foresight4" x  {tags add "Foresight4"}}
		{set "ptur2"}{call "proj_probe"}
		(define "fire_barrel"
			name "%0"
				{view start "ptur2tail_%0"}
				{delay 0.42
					{view pause "ptur2tail_%0"}
				}
		)
			{spawn "startsmoke" inv_normal}
			{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			  else ("fire_barrel" args 02)
			  else ("fire_barrel" args 03)
			  else ("fire_barrel" args 04)
			  else ("fire_barrel" args 05)
			  else ("fire_barrel" args 06)
			  else ("fire_barrel" args 07)
			}
	}
	{on fire "nar1" overload
		("low_speed_bullet")
		(define "fire_barrel"
			name "%0"
				;{ani_play "fire"}
				{view start "rok_tail%0"}
				{delay 0.42
					{view pause "rok_tail%0"}
				}
		)
		{spawn "startsmoke" inv_normal}
			{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			  else ("fire_barrel" args 02)
			else ("fire_barrel" args 03)
			  else ("fire_barrel" args 04)
			 else ("fire_barrel" args 05)
			else ("fire_barrel" args 06)
			else ("fire_barrel" args 07)
			else ("fire_barrel" args 08)
			else ("fire_barrel" args 09)
			else ("fire_barrel" args 10)
			else ("fire_barrel" args 11)	
			 else ("fire_barrel" args 12)
			else ("fire_barrel" args 13)
			  else ("fire_barrel" args 14)
			 else ("fire_barrel" args 15)
			else ("fire_barrel" args 16)
			else ("fire_barrel" args 17)
			else ("fire_barrel" args 18)
			else ("fire_barrel" args 19)
			
			 else ("fire_barrel" args 20)
			  else ("fire_barrel" args 21)
			else ("fire_barrel" args 22)
			  else ("fire_barrel" args 23)
			 else ("fire_barrel" args 24)
			else ("fire_barrel" args 25)
			else ("fire_barrel" args 26)
			else ("fire_barrel" args 27)
			else ("fire_barrel" args 28)
			else ("fire_barrel" args 29)
			else ("fire_barrel" args 30)	
			 else ("fire_barrel" args 31)
			else ("fire_barrel" args 32)
			  else ("fire_barrel" args 33)
			 else ("fire_barrel" args 34)
			else ("fire_barrel" args 35)
			else ("fire_barrel" args 36)
			else ("fire_barrel" args 37)
			else ("fire_barrel" args 38)
			else ("fire_barrel" args 39)
			}
		
	}
}
{"mi28n"
	{on spawn
		{add_view	"flash_zenit"		"flashbarrel1"			"Foresight1"}
		{add_view	"exhaust_dark"	"engine_steam1" "FXsmoke1"}			
		{add_view	"exhaust_dark"	"engine_steam2" "FXsmoke2"}
;========================================================================================
		{add_view 	"rok_tail" 		"rok_tail00" 		"shooter_l00"}
		{add_view 	"rok_tail" 		"rok_tail01" 		"shooter_l01"}
		{add_view 	"rok_tail" 		"rok_tail02" 		"shooter_l02"}
		{add_view 	"rok_tail" 		"rok_tail03" 		"shooter_l03"}
		{add_view 	"rok_tail" 		"rok_tail04" 		"shooter_l04"}
		{add_view 	"rok_tail" 		"rok_tail05" 		"shooter_l05"}
		{add_view 	"rok_tail" 		"rok_tail06" 		"shooter_l06"}
		{add_view 	"rok_tail" 		"rok_tail07" 		"shooter_l07"}
		{add_view 	"rok_tail" 		"rok_tail08" 		"shooter_l08"}
		{add_view 	"rok_tail" 		"rok_tail09" 		"shooter_l09"}
		{add_view 	"rok_tail" 		"rok_tail10" 		"shooter_l10"}
		{add_view 	"rok_tail" 		"rok_tail11" 		"shooter_l11"}
		{add_view 	"rok_tail" 		"rok_tail12" 		"shooter_l12"}
		{add_view 	"rok_tail" 		"rok_tail13" 		"shooter_l13"}
		{add_view 	"rok_tail" 		"rok_tail14" 		"shooter_l14"}
		{add_view 	"rok_tail" 		"rok_tail15" 		"shooter_l15"}
		{add_view 	"rok_tail" 		"rok_tail16" 		"shooter_l16"}
		{add_view 	"rok_tail" 		"rok_tail17" 		"shooter_l17"}
		{add_view 	"rok_tail" 		"rok_tail18" 		"shooter_l18"}
		{add_view 	"rok_tail" 		"rok_tail19" 		"shooter_l19"}
;--------------------------------------------------------------------------------------------
		{add_view 	"rok_tail" 		"rok_tail_00" 		"shooter_r00"}
		{add_view 	"rok_tail" 		"rok_tail_01" 		"shooter_r01"}
		{add_view 	"rok_tail" 		"rok_tail_02" 		"shooter_r02"}
		{add_view 	"rok_tail" 		"rok_tail_03" 		"shooter_r03"}
		{add_view 	"rok_tail" 		"rok_tail_04" 		"shooter_r04"}
		{add_view 	"rok_tail" 		"rok_tail_05" 		"shooter_r05"}
		{add_view 	"rok_tail" 		"rok_tail_06" 		"shooter_r06"}
		{add_view 	"rok_tail" 		"rok_tail_07" 		"shooter_r07"}
		{add_view 	"rok_tail" 		"rok_tail_08" 		"shooter_r08"}
		{add_view 	"rok_tail" 		"rok_tail_09" 		"shooter_r09"}
		{add_view 	"rok_tail" 		"rok_tail_10" 		"shooter_r10"}
		{add_view 	"rok_tail" 		"rok_tail_11" 		"shooter_r11"}
		{add_view 	"rok_tail" 		"rok_tail_12" 		"shooter_r12"}
		{add_view 	"rok_tail" 		"rok_tail_13" 		"shooter_r13"}
		{add_view 	"rok_tail" 		"rok_tail_14" 		"shooter_r14"}
		{add_view 	"rok_tail" 		"rok_tail_15" 		"shooter_r15"}
		{add_view 	"rok_tail" 		"rok_tail_16" 		"shooter_r16"}
		{add_view 	"rok_tail" 		"rok_tail_17" 		"shooter_r17"}
		{add_view 	"rok_tail" 		"rok_tail_18" 		"shooter_r18"}
		{add_view 	"rok_tail" 		"rok_tail_19" 		"shooter_r19"}
;============================================================================================
		{add_view 	"rok_tail" 		"ptur1tail_00" 		"ptur1tail_00"}
		{add_view 	"rok_tail" 		"ptur1tail_01" 		"ptur1tail_01"}
		{add_view 	"rok_tail" 		"ptur1tail_02" 		"ptur1tail_02"}
		{add_view 	"rok_tail" 		"ptur1tail_03" 		"ptur1tail_03"}
		{add_view 	"rok_tail" 		"ptur1tail_04" 		"ptur1tail_04"}
		{add_view 	"rok_tail" 		"ptur1tail_05" 		"ptur1tail_05"}
		{add_view 	"rok_tail" 		"ptur1tail_06" 		"ptur1tail_06"}
		{add_view 	"rok_tail" 		"ptur1tail_07" 		"ptur1tail_07"}
		{add_view 	"rok_tail" 		"ptur2tail_00" 		"ptur2tail_00"}
		{add_view 	"rok_tail" 		"ptur2tail_01" 		"ptur2tail_01"}
		{add_view 	"rok_tail" 		"ptur2tail_02" 		"ptur2tail_02"}
		{add_view 	"rok_tail" 		"ptur2tail_03" 		"ptur2tail_03"}
		{add_view 	"rok_tail" 		"ptur2tail_04" 		"ptur2tail_04"}
		{add_view 	"rok_tail" 		"ptur2tail_05" 		"ptur2tail_05"}
		{add_view 	"rok_tail" 		"ptur2tail_06" 		"ptur2tail_06"}
		{add_view 	"rok_tail" 		"ptur2tail_07" 		"ptur2tail_07"}

		{add_view 	"flash_cannon_big" 		"ptur1tail_00" 		"ptur1shooter_00"}
		{add_view 	"flash_cannon_big" 		"ptur1tail_01" 		"ptur1shooter_01"}
		{add_view 	"flash_cannon_big" 		"ptur1tail_02" 		"ptur1shooter_02"}
		{add_view 	"flash_cannon_big" 		"ptur1tail_03" 		"ptur1shooter_03"}
		{add_view 	"flash_cannon_big" 		"ptur1tail_04" 		"ptur1shooter_04"}
		{add_view 	"flash_cannon_big" 		"ptur1tail_05" 		"ptur1shooter_05"}
		{add_view 	"flash_cannon_big" 		"ptur1tail_06" 		"ptur1shooter_06"}
		{add_view 	"flash_cannon_big" 		"ptur1tail_07" 		"ptur1shooter_07"}
		{add_view 	"flash_cannon_big" 		"ptur2tail_00" 		"ptur2shooter_00"}
		{add_view 	"flash_cannon_big" 		"ptur2tail_01" 		"ptur2shooter_01"}
		{add_view 	"flash_cannon_big" 		"ptur2tail_02" 		"ptur2shooter_02"}
		{add_view 	"flash_cannon_big" 		"ptur2tail_03" 		"ptur2shooter_03"}
		{add_view 	"flash_cannon_big" 		"ptur2tail_04" 		"ptur2shooter_04"}
		{add_view 	"flash_cannon_big" 		"ptur2tail_05" 		"ptur2shooter_05"}
		{add_view 	"flash_cannon_big" 		"ptur2tail_06" 		"ptur2shooter_06"}
		{add_view 	"flash_cannon_big" 		"ptur2tail_07" 		"ptur2shooter_07"}
		("link_damage_sound_rus")
    	}
	{on "add_movement_sound" overload
			{link_sound "fly"			"vehicle/helicopter/mi-28engine"			}
			{link_sound "engine_start"		"vehicle/helicopter/mi-8en_start"				}
			{link_sound "engine_work"		"vehicle/helicopter/en_work"				}
			{link_sound "engine_stop"		"vehicle/helicopter/mi-8en_stop"				}
	}
	{on fire "ptur1" overload
		("low_speed_bullet")
;		{spawn "proj_probe" "Foresight3" x  {tags add "Foresight3"}}
		{set "ptur1"}{call "proj_probe"}
		(define "fire_barrel"
			name "%0"
				{view start "ptur1tail_%0"}
				{delay 0.42
					{view pause "ptur1tail_%0"}
				}
		)
			{spawn "startsmoke" inv_normal}
			{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			  else ("fire_barrel" args 02)
			  else ("fire_barrel" args 03)
			  else ("fire_barrel" args 04)
			  else ("fire_barrel" args 05)
			  else ("fire_barrel" args 06)
			  else ("fire_barrel" args 07)
			}
	}
	{on fire "ptur2" overload
		("low_speed_bullet")
;		{spawn "proj_probe" "Foresight4" x  {tags add "Foresight4"}}
		{set "ptur2"}{call "proj_probe"}
		(define "fire_barrel"
			name "%0"
				{view start "ptur2tail_%0"}
				{delay 0.42
					{view pause "ptur2tail_%0"}
				}
		)
			{spawn "startsmoke" inv_normal}
			{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			  else ("fire_barrel" args 02)
			  else ("fire_barrel" args 03)
			  else ("fire_barrel" args 04)
			  else ("fire_barrel" args 05)
			  else ("fire_barrel" args 06)
			  else ("fire_barrel" args 07)
			}
	}
	{on fire "nar1" overload
		("low_speed_bullet")
		(define "fire_barrel"
			name "%0"
				;{ani_play "fire"}
				{view start "rok_tail%0"}
				{delay 0.42
					{view pause "rok_tail%0"}
				}
		)
		{spawn "startsmoke" inv_normal}
			{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			  else ("fire_barrel" args 02)
			else ("fire_barrel" args 03)
			  else ("fire_barrel" args 04)
			 else ("fire_barrel" args 05)
			else ("fire_barrel" args 06)
			else ("fire_barrel" args 07)
			else ("fire_barrel" args 08)
			else ("fire_barrel" args 09)
			else ("fire_barrel" args 10)
			else ("fire_barrel" args 11)	
			 else ("fire_barrel" args 12)
			else ("fire_barrel" args 13)
			  else ("fire_barrel" args 14)
			 else ("fire_barrel" args 15)
			else ("fire_barrel" args 16)
			else ("fire_barrel" args 17)
			else ("fire_barrel" args 18)
			else ("fire_barrel" args 19)
			
			 else ("fire_barrel" args 20)
			  else ("fire_barrel" args 21)
			else ("fire_barrel" args 22)
			  else ("fire_barrel" args 23)
			 else ("fire_barrel" args 24)
			else ("fire_barrel" args 25)
			else ("fire_barrel" args 26)
			else ("fire_barrel" args 27)
			else ("fire_barrel" args 28)
			else ("fire_barrel" args 29)
			else ("fire_barrel" args 30)	
			 else ("fire_barrel" args 31)
			else ("fire_barrel" args 32)
			  else ("fire_barrel" args 33)
			 else ("fire_barrel" args 34)
			else ("fire_barrel" args 35)
			else ("fire_barrel" args 36)
			else ("fire_barrel" args 37)
			else ("fire_barrel" args 38)
			else ("fire_barrel" args 39)
			}
		
	}
	{on "update_lights"
		{if rain {ani_play "rain" loop} else {ani_stop "rain"}}
		{if not sunlight {ani_wind "lights" end} else {ani_wind "lights" begin}}
	}
	("autocannon")
	("25-50mm_gilza" fxshell(fxshell))
	{on "_explosion" 
		{delay 0.1
			("cut_part" args "radar"	1.0)
			("cut_part" args "ols2"	0.5)
			("cut_part" args "gun_rot2"	0.5)
		}
	}
	{on break overload
		{if component "ammo_storage_autocannon"
			{if not tagged "destroyed"
			{spawn "ex_air_big"}
			{blastwave c4 2 r0 1 r1 3 position}
			{delay 0.2 0.5	{spawn "ex_air_norm"}	{blastwave c4 2 r0 1 r1 3 position}}
			{delay  0.6 1	{spawn "ex_air_norm"}	{blastwave c4 2 r0 1 r1 3 position}}
			{delay 1 1.2	{spawn "ex_air_norm"}	{blastwave c4 2 r0 1 r1 3 position}}
			{delay 1.3 1.5	{spawn "ex_air_norm"}	{blastwave c4 2 r0 1 r1 3 position}}
			}
		else {inherited}
		}
	}
	{on "tear_propeller_up" overload
		{spawn "propeller_hit2" "propeller" x}
		{spawn "propeller_hit2" "propeller" x}
		{inherited}
	}
	{on "check_pilot_existance" overload
	;no ability to drive for gunner
		{if not tagged "destroyed"
		  {if chassis "airborne"
			{if crew_in_place "driver"
			   {delay 0.2
				{if not crew_in_place "driver"
					{call "fall"}
				}
			  }	
			}
		  }
		}
	}
	{on crew out
		{if not tagged "destroyed"
		  {if chassis "airborne"
			  {delay 0.2
				{if not crew_in_place "driver"
				 {call "fall"}
				}
			  }	
		  }
		}
	}
}
{"mi28ub"
	{on spawn
		{add_view	"flash_zenit"		"flashbarrel1"			"Foresight1"}
		{add_view	"exhaust_dark"	"engine_steam1" "FXsmoke1"}			
		{add_view	"exhaust_dark"	"engine_steam2" "FXsmoke2"}
;========================================================================================
		{add_view 	"rok_tail" 		"rok_tail00" 		"shooter_l00"}
		{add_view 	"rok_tail" 		"rok_tail01" 		"shooter_l01"}
		{add_view 	"rok_tail" 		"rok_tail02" 		"shooter_l02"}
		{add_view 	"rok_tail" 		"rok_tail03" 		"shooter_l03"}
		{add_view 	"rok_tail" 		"rok_tail04" 		"shooter_l04"}
		{add_view 	"rok_tail" 		"rok_tail05" 		"shooter_l05"}
		{add_view 	"rok_tail" 		"rok_tail06" 		"shooter_l06"}
		{add_view 	"rok_tail" 		"rok_tail07" 		"shooter_l07"}
		{add_view 	"rok_tail" 		"rok_tail08" 		"shooter_l08"}
		{add_view 	"rok_tail" 		"rok_tail09" 		"shooter_l09"}
		{add_view 	"rok_tail" 		"rok_tail10" 		"shooter_l10"}
		{add_view 	"rok_tail" 		"rok_tail11" 		"shooter_l11"}
		{add_view 	"rok_tail" 		"rok_tail12" 		"shooter_l12"}
		{add_view 	"rok_tail" 		"rok_tail13" 		"shooter_l13"}
		{add_view 	"rok_tail" 		"rok_tail14" 		"shooter_l14"}
		{add_view 	"rok_tail" 		"rok_tail15" 		"shooter_l15"}
		{add_view 	"rok_tail" 		"rok_tail16" 		"shooter_l16"}
		{add_view 	"rok_tail" 		"rok_tail17" 		"shooter_l17"}
		{add_view 	"rok_tail" 		"rok_tail18" 		"shooter_l18"}
		{add_view 	"rok_tail" 		"rok_tail19" 		"shooter_l19"}
;--------------------------------------------------------------------------------------------
		{add_view 	"rok_tail" 		"rok_tail_00" 		"shooter_r00"}
		{add_view 	"rok_tail" 		"rok_tail_01" 		"shooter_r01"}
		{add_view 	"rok_tail" 		"rok_tail_02" 		"shooter_r02"}
		{add_view 	"rok_tail" 		"rok_tail_03" 		"shooter_r03"}
		{add_view 	"rok_tail" 		"rok_tail_04" 		"shooter_r04"}
		{add_view 	"rok_tail" 		"rok_tail_05" 		"shooter_r05"}
		{add_view 	"rok_tail" 		"rok_tail_06" 		"shooter_r06"}
		{add_view 	"rok_tail" 		"rok_tail_07" 		"shooter_r07"}
		{add_view 	"rok_tail" 		"rok_tail_08" 		"shooter_r08"}
		{add_view 	"rok_tail" 		"rok_tail_09" 		"shooter_r09"}
		{add_view 	"rok_tail" 		"rok_tail_10" 		"shooter_r10"}
		{add_view 	"rok_tail" 		"rok_tail_11" 		"shooter_r11"}
		{add_view 	"rok_tail" 		"rok_tail_12" 		"shooter_r12"}
		{add_view 	"rok_tail" 		"rok_tail_13" 		"shooter_r13"}
		{add_view 	"rok_tail" 		"rok_tail_14" 		"shooter_r14"}
		{add_view 	"rok_tail" 		"rok_tail_15" 		"shooter_r15"}
		{add_view 	"rok_tail" 		"rok_tail_16" 		"shooter_r16"}
		{add_view 	"rok_tail" 		"rok_tail_17" 		"shooter_r17"}
		{add_view 	"rok_tail" 		"rok_tail_18" 		"shooter_r18"}
		{add_view 	"rok_tail" 		"rok_tail_19" 		"shooter_r19"}
;============================================================================================
		{add_view 	"rok_tail" 		"ptur1tail_00" 		"ptur1tail_00"}
		{add_view 	"rok_tail" 		"ptur1tail_01" 		"ptur1tail_01"}
		{add_view 	"rok_tail" 		"ptur1tail_02" 		"ptur1tail_02"}
		{add_view 	"rok_tail" 		"ptur1tail_03" 		"ptur1tail_03"}
		{add_view 	"rok_tail" 		"ptur1tail_04" 		"ptur1tail_04"}
		{add_view 	"rok_tail" 		"ptur1tail_05" 		"ptur1tail_05"}
		{add_view 	"rok_tail" 		"ptur1tail_06" 		"ptur1tail_06"}
		{add_view 	"rok_tail" 		"ptur1tail_07" 		"ptur1tail_07"}
		{add_view 	"rok_tail" 		"ptur2tail_00" 		"ptur2tail_00"}
		{add_view 	"rok_tail" 		"ptur2tail_01" 		"ptur2tail_01"}
		{add_view 	"rok_tail" 		"ptur2tail_02" 		"ptur2tail_02"}
		{add_view 	"rok_tail" 		"ptur2tail_03" 		"ptur2tail_03"}
		{add_view 	"rok_tail" 		"ptur2tail_04" 		"ptur2tail_04"}
		{add_view 	"rok_tail" 		"ptur2tail_05" 		"ptur2tail_05"}
		{add_view 	"rok_tail" 		"ptur2tail_06" 		"ptur2tail_06"}
		{add_view 	"rok_tail" 		"ptur2tail_07" 		"ptur2tail_07"}

		{add_view 	"flash_cannon_big" 		"ptur1tail_00" 		"ptur1shooter_00"}
		{add_view 	"flash_cannon_big" 		"ptur1tail_01" 		"ptur1shooter_01"}
		{add_view 	"flash_cannon_big" 		"ptur1tail_02" 		"ptur1shooter_02"}
		{add_view 	"flash_cannon_big" 		"ptur1tail_03" 		"ptur1shooter_03"}
		{add_view 	"flash_cannon_big" 		"ptur1tail_04" 		"ptur1shooter_04"}
		{add_view 	"flash_cannon_big" 		"ptur1tail_05" 		"ptur1shooter_05"}
		{add_view 	"flash_cannon_big" 		"ptur1tail_06" 		"ptur1shooter_06"}
		{add_view 	"flash_cannon_big" 		"ptur1tail_07" 		"ptur1shooter_07"}
		{add_view 	"flash_cannon_big" 		"ptur2tail_00" 		"ptur2shooter_00"}
		{add_view 	"flash_cannon_big" 		"ptur2tail_01" 		"ptur2shooter_01"}
		{add_view 	"flash_cannon_big" 		"ptur2tail_02" 		"ptur2shooter_02"}
		{add_view 	"flash_cannon_big" 		"ptur2tail_03" 		"ptur2shooter_03"}
		{add_view 	"flash_cannon_big" 		"ptur2tail_04" 		"ptur2shooter_04"}
		{add_view 	"flash_cannon_big" 		"ptur2tail_05" 		"ptur2shooter_05"}
		{add_view 	"flash_cannon_big" 		"ptur2tail_06" 		"ptur2shooter_06"}
		{add_view 	"flash_cannon_big" 		"ptur2tail_07" 		"ptur2shooter_07"}
		("link_damage_sound_rus")
    	}
	{on "add_movement_sound" overload
			{link_sound "fly"			"vehicle/helicopter/mi-28engine"			}
			{link_sound "engine_start"		"vehicle/helicopter/mi-8en_start"				}
			{link_sound "engine_work"		"vehicle/helicopter/en_work"				}
			{link_sound "engine_stop"		"vehicle/helicopter/mi-8en_stop"				}
	}
	{on fire "ptur1" overload
		("low_speed_bullet")
;		{spawn "proj_probe" "Foresight3" x  {tags add "Foresight3"}}
		{set "ptur1"}{call "proj_probe"}
		(define "fire_barrel"
			name "%0"
				{view start "ptur1tail_%0"}
				{delay 0.42
					{view pause "ptur1tail_%0"}
				}
		)
			{spawn "startsmoke" inv_normal}
			{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			  else ("fire_barrel" args 02)
			  else ("fire_barrel" args 03)
			  else ("fire_barrel" args 04)
			  else ("fire_barrel" args 05)
			  else ("fire_barrel" args 06)
			  else ("fire_barrel" args 07)
			}
	}
	{on fire "ptur2" overload
		("low_speed_bullet")
;		{spawn "proj_probe" "Foresight4" x  {tags add "Foresight4"}}
		{set "ptur2"}{call "proj_probe"}
		(define "fire_barrel"
			name "%0"
				{view start "ptur2tail_%0"}
				{delay 0.42
					{view pause "ptur2tail_%0"}
				}
		)
			{spawn "startsmoke" inv_normal}
			{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			  else ("fire_barrel" args 02)
			  else ("fire_barrel" args 03)
			  else ("fire_barrel" args 04)
			  else ("fire_barrel" args 05)
			  else ("fire_barrel" args 06)
			  else ("fire_barrel" args 07)
			}
	}
	{on fire "nar1" overload
		("low_speed_bullet")
		(define "fire_barrel"
			name "%0"
				;{ani_play "fire"}
				{view start "rok_tail%0"}
				{delay 0.42
					{view pause "rok_tail%0"}
				}
		)
		{spawn "startsmoke" inv_normal}
			{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			  else ("fire_barrel" args 02)
			else ("fire_barrel" args 03)
			  else ("fire_barrel" args 04)
			 else ("fire_barrel" args 05)
			else ("fire_barrel" args 06)
			else ("fire_barrel" args 07)
			else ("fire_barrel" args 08)
			else ("fire_barrel" args 09)
			else ("fire_barrel" args 10)
			else ("fire_barrel" args 11)	
			 else ("fire_barrel" args 12)
			else ("fire_barrel" args 13)
			  else ("fire_barrel" args 14)
			 else ("fire_barrel" args 15)
			else ("fire_barrel" args 16)
			else ("fire_barrel" args 17)
			else ("fire_barrel" args 18)
			else ("fire_barrel" args 19)
			
			 else ("fire_barrel" args 20)
			  else ("fire_barrel" args 21)
			else ("fire_barrel" args 22)
			  else ("fire_barrel" args 23)
			 else ("fire_barrel" args 24)
			else ("fire_barrel" args 25)
			else ("fire_barrel" args 26)
			else ("fire_barrel" args 27)
			else ("fire_barrel" args 28)
			else ("fire_barrel" args 29)
			else ("fire_barrel" args 30)	
			 else ("fire_barrel" args 31)
			else ("fire_barrel" args 32)
			  else ("fire_barrel" args 33)
			 else ("fire_barrel" args 34)
			else ("fire_barrel" args 35)
			else ("fire_barrel" args 36)
			else ("fire_barrel" args 37)
			else ("fire_barrel" args 38)
			else ("fire_barrel" args 39)
			}
		
	}

	{on "update_lights"
		{if rain {ani_play "rain" loop} else {ani_stop "rain"}}
		{if not sunlight {ani_play "lights"} else {ani_wind "lights" begin}}
	}
	("autocannon")
	("25-50mm_gilza" fxshell(fxshell))
	{on "_explosion" 
		{delay 0.1
			("cut_part" args "radar"	1.0)
			("cut_part" args "ols2"	0.5)
			("cut_part" args "gun_rot2"	0.5)
		}
	}
	{on break overload
		{if component "ammo_storage_autocannon"
			{if not tagged "destroyed"
			{spawn "ex_air_big"}
			{blastwave c4 2 r0 1 r1 3 position}
			{delay 0.2 0.5	{spawn "ex_air_norm"}	{blastwave c4 2 r0 1 r1 3 position}}
			{delay  0.6 1	{spawn "ex_air_norm"}	{blastwave c4 2 r0 1 r1 3 position}}
			{delay 1 1.2	{spawn "ex_air_norm"}	{blastwave c4 2 r0 1 r1 3 position}}
			{delay 1.3 1.5	{spawn "ex_air_norm"}	{blastwave c4 2 r0 1 r1 3 position}}
			}
		else {inherited}
		}
	}
	{on "tear_propeller_up" overload
		{spawn "propeller_hit2" "propeller" x}
		{spawn "propeller_hit2" "propeller" x}
		{inherited}
	}
	{on "check_pilot_existance" overload
	;no ability to drive for gunner
		{if not tagged "destroyed"
		  {if chassis "airborne"
			{if crew_in_place "driver"
			   {delay 0.2
				{if not crew_in_place "driver"
					{call "fall"}
				}
			  }	
			}
		  }
		}
	}
	{on crew out
		{if not tagged "destroyed"
		  {if chassis "airborne"
			  {delay 0.2
				{if not crew_in_place "driver"
				 {call "fall"}
				}
			  }	
		  }
		}
	}
}
{"tiger_hap"
;-------------------------------------------------------------
	{on spawn
		{add_view	"flash_zenit"		"flashbarrel1"			"Foresight1"}
		{add_view	"exhaust_dark"	"engine_steam1" "FXsmoke1"}			
		{add_view	"exhaust_dark"	"engine_steam2" "FXsmoke2"}
		{add_view       "autocannon_gilz"		"shell"	"fx_shell"}		
		{add_view 	"smoke_zenit" 	"zenite_smoke" 		"foresight1"}
;========================================================================================
		{add_view 	"rok_tail" 		"rok_tail_a00" 		"shooter_a00"}
		{add_view 	"rok_tail" 		"rok_tail_a01" 		"shooter_a01"}
		{add_view 	"rok_tail" 		"rok_tail_a02" 		"shooter_a02"}
		{add_view 	"rok_tail" 		"rok_tail_a03" 		"shooter_a03"}
		{add_view 	"rok_tail" 		"rok_tail_a04" 		"shooter_a04"}
		{add_view 	"rok_tail" 		"rok_tail_a05" 		"shooter_a05"}
		{add_view 	"rok_tail" 		"rok_tail_a06" 		"shooter_a06"}
		{add_view 	"rok_tail" 		"rok_tail_a07" 		"shooter_a07"}
		{add_view 	"rok_tail" 		"rok_tail_a08" 		"shooter_a08"}
		{add_view 	"rok_tail" 		"rok_tail_a09" 		"shooter_a09"}
		{add_view 	"rok_tail" 		"rok_tail_a10" 		"shooter_a10"}
		{add_view 	"rok_tail" 		"rok_tail_a11" 		"shooter_a11"}
		{add_view 	"rok_tail" 		"rok_tail_a12" 		"shooter_a12"}
		{add_view 	"rok_tail" 		"rok_tail_a13" 		"shooter_a13"}
		{add_view 	"rok_tail" 		"rok_tail_a14" 		"shooter_a14"}
		{add_view 	"rok_tail" 		"rok_tail_a15" 		"shooter_a15"}
		{add_view 	"rok_tail" 		"rok_tail_a16" 		"shooter_a16"}
		{add_view 	"rok_tail" 		"rok_tail_a17" 		"shooter_a17"}
		{add_view 	"rok_tail" 		"rok_tail_a18" 		"shooter_a18"}
		{add_view 	"rok_tail" 		"rok_tail_a19" 		"shooter_a20"}
		{add_view 	"rok_tail" 		"rok_tail_a19" 		"shooter_a21"}

		{add_view 	"rok_tail" 		"rok_tail_b00" 		"shooter_b00"}
		{add_view 	"rok_tail" 		"rok_tail_b01" 		"shooter_b01"}
		{add_view 	"rok_tail" 		"rok_tail_b02" 		"shooter_b02"}
		{add_view 	"rok_tail" 		"rok_tail_b03" 		"shooter_b03"}
		{add_view 	"rok_tail" 		"rok_tail_b04" 		"shooter_b04"}
		{add_view 	"rok_tail" 		"rok_tail_b05" 		"shooter_b05"}
		{add_view 	"rok_tail" 		"rok_tail_b06" 		"shooter_b06"}
		{add_view 	"rok_tail" 		"rok_tail_b07" 		"shooter_b07"}
		{add_view 	"rok_tail" 		"rok_tail_b08" 		"shooter_b08"}
		{add_view 	"rok_tail" 		"rok_tail_b09" 		"shooter_b09"}
		{add_view 	"rok_tail" 		"rok_tail_b10" 		"shooter_b10"}
		{add_view 	"rok_tail" 		"rok_tail_b11" 		"shooter_b11"}
		{add_view 	"rok_tail" 		"rok_tail_b12" 		"shooter_b12"}
		{add_view 	"rok_tail" 		"rok_tail_b13" 		"shooter_b13"}
		{add_view 	"rok_tail" 		"rok_tail_b14" 		"shooter_b14"}
		{add_view 	"rok_tail" 		"rok_tail_b15" 		"shooter_b15"}
		{add_view 	"rok_tail" 		"rok_tail_b16" 		"shooter_b16"}
		{add_view 	"rok_tail" 		"rok_tail_b17" 		"shooter_b17"}
		{add_view 	"rok_tail" 		"rok_tail_b18" 		"shooter_b18"}
		{add_view 	"rok_tail" 		"rok_tail_b19" 		"shooter_b20"}
		{add_view 	"rok_tail" 		"rok_tail_b19" 		"shooter_b21"}
		
		{add_view 	"rok_tail" 		"rok_tail_c00" 		"shooter_c00"}
		{add_view 	"rok_tail" 		"rok_tail_c01" 		"shooter_c01"}
		{add_view 	"rok_tail" 		"rok_tail_c02" 		"shooter_c02"}
		{add_view 	"rok_tail" 		"rok_tail_c03" 		"shooter_c03"}
		{add_view 	"rok_tail" 		"rok_tail_c04" 		"shooter_c04"}
		{add_view 	"rok_tail" 		"rok_tail_c05" 		"shooter_c05"}
		{add_view 	"rok_tail" 		"rok_tail_c06" 		"shooter_c06"}
		{add_view 	"rok_tail" 		"rok_tail_c07" 		"shooter_c07"}
		{add_view 	"rok_tail" 		"rok_tail_c08" 		"shooter_c08"}
		{add_view 	"rok_tail" 		"rok_tail_c09" 		"shooter_c09"}
		{add_view 	"rok_tail" 		"rok_tail_c10" 		"shooter_c10"}
		{add_view 	"rok_tail" 		"rok_tail_c11" 		"shooter_c11"}

		{add_view 	"rok_tail" 		"rok_tail_d00" 		"shooter_d00"}
		{add_view 	"rok_tail" 		"rok_tail_d01" 		"shooter_d01"}
		{add_view 	"rok_tail" 		"rok_tail_d02" 		"shooter_d02"}
		{add_view 	"rok_tail" 		"rok_tail_d03" 		"shooter_d03"}
		{add_view 	"rok_tail" 		"rok_tail_d04" 		"shooter_d04"}
		{add_view 	"rok_tail" 		"rok_tail_d05" 		"shooter_d05"}
		{add_view 	"rok_tail" 		"rok_tail_d06" 		"shooter_d06"}
		{add_view 	"rok_tail" 		"rok_tail_d07" 		"shooter_d07"}
		{add_view 	"rok_tail" 		"rok_tail_d08" 		"shooter_d08"}
		{add_view 	"rok_tail" 		"rok_tail_d09" 		"shooter_d09"}
		{add_view 	"rok_tail" 		"rok_tail_d10" 		"shooter_d10"}
		{add_view 	"rok_tail" 		"rok_tail_d11" 		"shooter_d11"}
;--------------------------------------------------------------------------------------------
		{add_view	"flash_cannon_big"		"flashbarrel2"			"Foresight2"}
		{add_view	"flash_cannon_big"		"flashbarrel3"			"Foresight3"}
		{add_view	"flash_cannon_big"		"flashbarrel7"			"Foresight7"}
		{add_view	"flash_cannon_big"		"flashbarrel8"			"Foresight8"}
			("link_damage_sound_usa")
    	}
{on "add_movement_sound" overload
		{link_sound "fly"			"vehicle/helicopter/tiger_engine"			}
		{link_sound "engine_start"		"vehicle/helicopter/tiger_start"				}
		{link_sound "engine_work"		"vehicle/helicopter/en_work"				}
		{link_sound "engine_stop"		"vehicle/helicopter/tiger_stop"				}
}
	{on fire "nar1" overload
		(define "fire_barrel"
			name "%0"
				{view start "rok_tail_a%0"}
				{delay 0.42	{view pause "rok_tail_a%0"}}
		)
		{spawn "startsmoke" inv_normal}
			{if    ("fire_barrel" args 00)  else ("fire_barrel" args 01)  else ("fire_barrel" args 02)
			else ("fire_barrel" args 03) else ("fire_barrel" args 04) else ("fire_barrel" args 05)
			else ("fire_barrel" args 06) else ("fire_barrel" args 07) else ("fire_barrel" args 08)
			else ("fire_barrel" args 09) else ("fire_barrel" args 10) else ("fire_barrel" args 11)	
			 else ("fire_barrel" args 12) else ("fire_barrel" args 13) else ("fire_barrel" args 14)
			 else ("fire_barrel" args 15) else ("fire_barrel" args 16) else ("fire_barrel" args 17)
			else ("fire_barrel" args 18) else ("fire_barrel" args 19) else ("fire_barrel" args 20)
			else ("fire_barrel" args 21)
			}
	}
	{on fire "nar2" overload
		(define "fire_barrel"
			name "%0"
				{view start "rok_tail_b%0"}
				{delay 0.42	{view pause "rok_tail_b%0"}}
		)
		{spawn "startsmoke" inv_normal}
			{if    ("fire_barrel" args 00)  else ("fire_barrel" args 01)  else ("fire_barrel" args 02)
			else ("fire_barrel" args 03) else ("fire_barrel" args 04) else ("fire_barrel" args 05)
			else ("fire_barrel" args 06) else ("fire_barrel" args 07) else ("fire_barrel" args 08)
			else ("fire_barrel" args 09) else ("fire_barrel" args 10) else ("fire_barrel" args 11)	
			 else ("fire_barrel" args 12) else ("fire_barrel" args 13) else ("fire_barrel" args 14)
			 else ("fire_barrel" args 15) else ("fire_barrel" args 16) else ("fire_barrel" args 17)
			else ("fire_barrel" args 18) else ("fire_barrel" args 19) else ("fire_barrel" args 20)
			else ("fire_barrel" args 21)
			}
	}
	{on fire "nar3" overload
		(define "fire_barrel"
			name "%0"
				{view start "rok_tail_c%0"}
				{delay 0.42	{view pause "rok_tail_c%0"}}
		)
		{spawn "startsmoke" inv_normal}
			{if    ("fire_barrel" args 00)  else ("fire_barrel" args 01)  else ("fire_barrel" args 02)
			else ("fire_barrel" args 03) else ("fire_barrel" args 04) else ("fire_barrel" args 05)
			else ("fire_barrel" args 06) else ("fire_barrel" args 07) else ("fire_barrel" args 08)
			else ("fire_barrel" args 09) else ("fire_barrel" args 10) else ("fire_barrel" args 11)
			}
	}
	{on fire "nar4" overload
		(define "fire_barrel"
			name "%0"
				{view start "rok_tail_d%0"}
				{delay 0.42	{view pause "rok_tail_d%0"}}
		)
		{spawn "startsmoke" inv_normal}
			{if    ("fire_barrel" args 00)  else ("fire_barrel" args 01)  else ("fire_barrel" args 02)
			else ("fire_barrel" args 03) else ("fire_barrel" args 04) else ("fire_barrel" args 05)
			else ("fire_barrel" args 06) else ("fire_barrel" args 07) else ("fire_barrel" args 08)
			else ("fire_barrel" args 09) else ("fire_barrel" args 10) else ("fire_barrel" args 11)
			}
	}
;-------------------------------------------------
	{on fire "ptur1" overload
		("low_speed_bullet")
		{view start "flashbarrel3"}
		{delay 0.1 {spawn "trigat_carrier" "Foresight3"  x}}
		{delay 0.42
			{view pause "flashbarrel3"}
		}
	}
	{on fire "ptur2" overload
		("low_speed_bullet")
		{view start "flashbarrel2"}
		{delay 0.1 {spawn "trigat_carrier" "Foresight2"  x}}
		{delay 0.42
			{view pause "flashbarrel2"}
		}
	}
	{on fire "ptur3" overload
		{view start "flashbarrel7"}
		{if name "00" {delay 0.1 {spawn "mistral_missile_carrier" "mistral_l_00"  x}}
		else name "01"  {delay 0.1 {spawn "mistral_missile_carrier" "mistral_l_01"  x}}
		}
		{delay 0.42
			{view pause "flashbarrel7"}
		}
	}
	{on fire "ptur4" overload
		{view start "flashbarrel8"}
		{if name "00" {delay 0.1 {spawn "mistral_missile_carrier" "mistral_r_00"  x}}
		else name "01"  {delay 0.1 {spawn "mistral_missile_carrier" "mistral_r_01"  x}}
		}
		{delay 0.42
			{view pause "flashbarrel8"}
		}
	}
}
	
	
{"nh90"
;-------------------------------------------------------------
	{on spawn
;========================================================================================
			{add_view	"exhaust_dark"	"engine_steam1" "FXsmoke1"}			
			{add_view	"exhaust_dark"	"engine_steam2" "FXsmoke2"}
			("link_damage_sound_usa")
    	}
	{on "add_movement_sound" overload
		{link_sound "fly"			"vehicle/helicopter/nh90_rotor"			}
		{link_sound "engine_start"		"vehicle/helicopter/nh90_start"				}
		{link_sound "engine_work"		"vehicle/helicopter/nh90_engine"				}
		{link_sound "engine_stop"		"vehicle/helicopter/nh90_stop"				}
	}
;----------------------------------------
	{on "tear_propeller_up" overload
		{spawn "propeller_hit2" "propeller" x}
		{inherited}
	}
;==============================
;paradrop system by Timosh
	{on "paradrop"
		("paradrop_crew" args seat1)
		{delay 0.6 ("paradrop_crew" args seat2)}
		{delay 1.2 ("paradrop_crew" args seat3)}
		{delay 1.8 ("paradrop_crew" args seat4)}
		{delay 2.4 ("paradrop_crew" args seat5)}
		{delay 3 ("paradrop_crew" args seat6)}
		{delay 3.6 ("paradrop_crew" args seat7)}
		{delay 4.2 ("paradrop_crew" args seat8)}
		{delay 4.8 ("paradrop_crew" args seat9)}
		{delay 5.4 ("paradrop_crew" args seat10)}
		{delay 6 ("paradrop_crew" args seat11)}
		{delay 6.6 ("paradrop_crew" args seat12)}
	}
;==============================
}
	
{"z-10"
;-------------------------------------------------------------
	{on spawn
		{add_view	"flash_zenit"		"flashbarrel1"			"Foresight1"}
		{add_view	"exhaust_dark"	"engine_steam1" "FXsmoke1"}			
		{add_view	"exhaust_dark"	"engine_steam2" "FXsmoke2"}
		{add_view       "autocannon_gilz"		"shell"	"fx_shell"}		
		{add_view 	"smoke_zenit" 	"zenite_smoke" 		"foresight1"}
;========================================================================================
		{add_view 	"rok_tail" 		"rok_tail_a00" 		"tailnarl_00"}
		{add_view 	"rok_tail" 		"rok_tail_a01" 		"tailnarl_01"}
		{add_view 	"rok_tail" 		"rok_tail_a02" 		"tailnarl_02"}
		{add_view 	"rok_tail" 		"rok_tail_a03" 		"tailnarl_03"}
		{add_view 	"rok_tail" 		"rok_tail_a04" 		"tailnarl_04"}
		{add_view 	"rok_tail" 		"rok_tail_a05" 		"tailnarl_05"}
		{add_view 	"rok_tail" 		"rok_tail_a06" 		"tailnarl_06"}

		{add_view 	"rok_tail" 		"rok_tail_b00" 		"tailnarr_00"}
		{add_view 	"rok_tail" 		"rok_tail_b01" 		"tailnarr_01"}
		{add_view 	"rok_tail" 		"rok_tail_b02" 		"tailnarr_02"}
		{add_view 	"rok_tail" 		"rok_tail_b03" 		"tailnarr_03"}
		{add_view 	"rok_tail" 		"rok_tail_b04" 		"tailnarr_04"}
		{add_view 	"rok_tail" 		"rok_tail_b05" 		"tailnarr_05"}
		{add_view 	"rok_tail" 		"rok_tail_b06" 		"tailnarr_06"}
;--------------------------------------------------------------------------------------------
		{add_view	"flash_cannon_big"		"flashbarrel2"			"Foresight2"}
		{add_view	"flash_cannon_big"		"flashbarrel3"			"Foresight3"}
    	}
{on "add_movement_sound" overload
		{link_sound "fly"			"vehicle/helicopter/wz10_engine"			}
		{link_sound "engine_start"		"vehicle/helicopter/tiger_start"				}
		{link_sound "engine_work"		"vehicle/helicopter/wz10_rotor"				}
		{link_sound "engine_stop"		"vehicle/helicopter/tiger_stop"				}
}
	{on fire "nar1" overload
		(define "fire_barrel"
			name "%0"
				{view start "rok_tail_a%0"}
				{delay 0.42	{view pause "rok_tail_a%0"}}
		)
		{spawn "startsmoke" inv_normal}
			{if    ("fire_barrel" args 00)  else ("fire_barrel" args 01)  else ("fire_barrel" args 02)
			else ("fire_barrel" args 03) else ("fire_barrel" args 04) else ("fire_barrel" args 05)
			else ("fire_barrel" args 06) 
			}
	}
	{on fire "nar2" overload
		(define "fire_barrel"
			name "%0"
				{view start "rok_tail_b%0"}
				{delay 0.42	{view pause "rok_tail_b%0"}}
		)
		{spawn "startsmoke" inv_normal}
			{if    ("fire_barrel" args 00)  else ("fire_barrel" args 01)  else ("fire_barrel" args 02)
			else ("fire_barrel" args 03) else ("fire_barrel" args 04) else ("fire_barrel" args 05)
			else ("fire_barrel" args 06) 
			}
	}
	{on fire "ptur1" overload
		("low_speed_bullet")
		{view start "flashbarrel3"}
		{delay 0.1 {spawn "akd-10_carrier" "Foresight3"  x}}
		{delay 0.42
			{view pause "flashbarrel3"}
		}
	}
	{on fire "ptur2" overload
		("low_speed_bullet")
		{view start "flashbarrel2"}
		{delay 0.1 {spawn "akd-10_carrier" "Foresight2"  x}}
		{delay 0.42
			{view pause "flashbarrel2"}
		}
	}
}
