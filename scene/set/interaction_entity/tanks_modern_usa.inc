(define "mlrs_m270"
	{on spawn
		{add_view 	"startsmoke_big" 		"rok_tail00" 		"shooter00"}
		{add_view 	"startsmoke_big" 		"rok_tail01" 		"shooter01"}
		{add_view 	"startsmoke_big" 		"rok_tail02" 		"shooter02"}
		{add_view 	"startsmoke_big" 		"rok_tail03" 		"shooter03"}
		{add_view 	"startsmoke_big" 		"rok_tail04" 		"shooter04"}
		{add_view 	"startsmoke_big" 		"rok_tail05" 		"shooter05"}
		{add_view 	"startsmoke_big" 		"rok_tail06" 		"shooter06"}
		{add_view 	"startsmoke_big" 		"rok_tail07" 		"shooter07"}
		{add_view 	"startsmoke_big" 		"rok_tail08" 		"shooter08"}
		{add_view 	"startsmoke_big" 		"rok_tail09" 		"shooter09"}
		{add_view 	"startsmoke_big" 		"rok_tail10" 		"shooter10"}
		{add_view 	"startsmoke_big" 		"rok_tail11" 		"shooter11"}
	}
;ходовая сильно унифицирована с бредли, двиг и трансмисси€ те же.
	{on ik begin "turret"
		{play_sound "rotate_turret" 1}
	}
	{on ik end "turret"
		{stop_sound "rotate_turret"}
	}
	{on fire "mgun1" overload
		{view start "flashbarrel3"}
		("cw_check_shooting" weap_id(mgun1))
	}
	{on fire "gun" 
		{spawn "startsmoke_big"}
     		{spawn "dust_shot_big_2" "basis"}
		{ani_play "fire"}
		{view start "flashbarrel_gun"}
		{view start "smoke_add"}
		{delay 0.16 "shell_off"
			{view pause "smoke_add"}
			{view pause "flashbarrel_gun"}
		}
		(define "fire_barrel"
			name "%0"
				{view start "rok_tail%0"}
				{delay 0.42
					{view pause "rok_tail%0"}
				}
		)
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
	}
	{on "__explosion"
		{set "big_explosion" 0}
		{if explosive_amount 400
			{blastwave c4 25 r0 15 r1 35}
			{spawn "train_die" "basis"}
			{set "big_explosion" 1}
			{con "big explosive"}
		}
	}
	{on "explosion"
		{set "big_explosion" 0}
		{if explosive_amount 400
			{blastwave c4 25 r0 15 r1 35}
			{spawn "train_die" "basis"}
			{set "big_explosion" 1}
			{con "big explosive"}
		}
	}
	{on "spawn_shellhole"
		{if flag "big_explosion"                                        
			{spawn "crater_extra_big" "basis" terrain_texmod}
                        			{spawn "shellhole_big_dead" "basis"}
		}
	}
)
;------------Addon USA-----------------
{"m60a3 tank"
	{on spawn
		{add_view "flash_gun_big" "flashbarrel2" "Foresight2"}	
		{add_view "flash_gun_small" "flashbarrel3" "Foresight3"}
		{add_view "flash_gun_small" "flashbarrel4" "Foresight4"}						
    	}
	("m60_sound")
	("m68_type_gun")	
	{on fire "mgun" overload
		{view start "flashbarrel2"}
		("cw_check_shooting" weap_id(mgun))
	}
	{on fire "mgun1" overload
		{view start "flashbarrel3"}
		("cw_check_shooting" weap_id(mgun1))
	}
	{on fire "mgun2" overload
		{view start "flashbarrel4"}
		("cw_check_shooting" weap_id(mgun2))
	}
}
{"m1a1 tank"
	{on spawn
		{add_view	"exhaust_dark"	"exhaust"	"FXsmoke1"}			
		{add_view	"exhaust_dark"	"exhaust"	"FXsmoke2"}
    	}
	("abrams_sound")
	("m256_type_gun")
	("zpu_params" gunner(gunner2) zpu_mgun(mgun) anim(into_hatch_abrams) pose(seat_gunner_stand))
}	
{"m1_Abrams tank"
	{on spawn
		{add_view	"exhaust_dark"	"exhaust"	"FXsmoke1"}			
		{add_view	"exhaust_dark"	"exhaust"	"FXsmoke2"}	
		{add_view "zenit_gilz"		"shell_m1"	"fxshell_m1"}
    	}
	("abrams_sound")
	("m68_type_gun")
	{on fire "mgun3" overload
		{view start "flashbarrel4"}
		{ani_play "fire_mgun2"}
		{view start "shell_m1"}
		{kill_delay "shell_m1"}
		{delay 0.2 "shell_m1"
			{view pause "shell_m1"}
		}
		("cw_check_shooting" weap_id(mgun3))
	}
	("doublezpu_params" gunner(gunner2) zpu_mgun(mgun) anim(into_hatch_abrams) pose(seat_gunner_stand) hatch_anim(open)
	secgunner(gunner3) seczpu_mgun(mgun3) secanim(into_hatch_abrams) secpose(seat_gunner_stand) sechatch_anim(open2))
}	
{"m1a2tusk tank"
	{on spawn
		{add_view	"exhaust_dark"	"engine_steam1" "FXsmoke1"}			
		{add_view	"exhaust_dark"	"engine_steam2" "FXsmoke2"}	
		{add_view "zenit_gilz"		"shell_m1"	"fxshell_m1"}
    	}
	("abrams_sound")
	("m256_type_gun")
	{on fire "mgun3" overload
		{view start "flashbarrel6"}
		{ani_play "fire_mgun2"}
		{view start "shell_m1"}
		{kill_delay "shell_m1"}
		{delay 0.2 "shell_m1"
			{view pause "shell_m1"}
		}
		("cw_check_shooting" weap_id(mgun3))
	}
	("commonzpu_params" gunner(gunner3) zpu_mgun(mgun3) anim(into_hatch_abrams) pose(seat_gunner_stand))
	("zpu_one_hatch" gunner(gunner3) hatch_anim(open2))

	{on "update_hatch_on_spawn"
		("update_hatch" wind(true) place(gunner3))
	}
	("update_hatch_event" event(operatable on) place(gunner3))
	("update_hatch_event" event(operatable off) place(gunner3))
	("update_hatch_event" event(crew in) place(gunner3))
	("update_hatch_event" event(crew out) place(gunner3))
}
{"m1a1_new"
	("abrams_sound")
	("m256_type_gun")
	("doublezpu_params" gunner(gunner2) zpu_mgun(mgun1) anim(into_hatch_abrams) pose(M1a1_mgun1) hatch_anim(open)
	secgunner(gunner3) seczpu_mgun(mgun4) secanim(into_hatch_abrams) secpose(M1a1_mgun2) sechatch_anim(open2))
	{on "blow_panels" overload
		{tear "piece_medium_steel" bone "part1" {impulse up 5 rnd_dir 2}}
		{tear "piece_medium_steel" bone "part2" {impulse up 5 rnd_dir 2}}
		{add_view "burnout_blow_panel1" "blow_burnout1" "FXfire_bk1"}
		{add_view "burnout_blow_panel2" "blow_burnout2" "FXfire_bk1"}
		{add_view "burnout_blow_panel3" "blow_burnout3" "FXfire_bk1"}
		{add_view "burnout_blow_panel4" "blow_burnout4" "FXfire_bk1"}
		{add_view "burnout_blow_panel1" "blow_burnout1" "FXfire_bk2"}
		{add_view "burnout_blow_panel2" "blow_burnout2" "FXfire_bk2"}
		{add_view "burnout_blow_panel3" "blow_burnout3" "FXfire_bk2"}
		{add_view "burnout_blow_panel4" "blow_burnout4" "FXfire_bk2"}
		{ani_play "knockout"}
	}
	{on "blow_panels2" overload
		{add_view "burnout_blow_panel1" "blow_burnout1" "FXfire_bk3"}
		{add_view "burnout_blow_panel2" "blow_burnout2" "FXfire_bk3"}
		{add_view "burnout_blow_panel3" "blow_burnout3" "FXfire_bk3"}
		{add_view "burnout_blow_panel4" "blow_burnout4" "FXfire_bk3"}
	}
	{on "_explosion"
		{tear "piece_medium_steel" bone "part1" {impulse up 5 rnd_dir 2}}
		{tear "piece_medium_steel" bone "part2" {impulse up 5 rnd_dir 2}}
	}
	{on break
		{if volume "ammo_storage_main"
			{if explosive_amount 120
				{tear "piece_medium_steel" bone "part1" {impulse up 5 rnd_dir 2}}
				{tear "piece_medium_steel" bone "part2" {impulse up 5 rnd_dir 2}}
			}
		}
	}
	{on fire "mgun5" overload
		{view start "flashbarrel6"}
		("cw_check_shooting" weap_id(mgun5))
	}
	{on fire "mgun4" overload
		{view start "flashbarrel7"}
		("cw_check_shooting" weap_id(mgun4))
	}
}
{"m1a2tusk_new"
	("abrams_sound")
	("m256_type_gun")
	("commonzpu_params" gunner(gunner3) zpu_mgun(mgun4) anim(into_hatch_abrams) pose(M1a2_mgun))
	("zpu_one_hatch" gunner(gunner3) hatch_anim(open2))
	{on "blow_panels" overload
		{tear "piece_medium_steel" bone "part1" {impulse up 5 rnd_dir 2}}
		{tear "piece_medium_steel" bone "part2" {impulse up 5 rnd_dir 2}}
		{add_view "burnout_blow_panel1" "blow_burnout1" "FXfire_bk1"}
		{add_view "burnout_blow_panel2" "blow_burnout2" "FXfire_bk1"}
		{add_view "burnout_blow_panel3" "blow_burnout3" "FXfire_bk1"}
		{add_view "burnout_blow_panel4" "blow_burnout4" "FXfire_bk1"}
		{add_view "burnout_blow_panel1" "blow_burnout1" "FXfire_bk2"}
		{add_view "burnout_blow_panel2" "blow_burnout2" "FXfire_bk2"}
		{add_view "burnout_blow_panel3" "blow_burnout3" "FXfire_bk2"}
		{add_view "burnout_blow_panel4" "blow_burnout4" "FXfire_bk2"}
		{ani_play "knockout"}
	}
	{on "blow_panels2" overload
		{add_view "burnout_blow_panel1" "blow_burnout1" "FXfire_bk3"}
		{add_view "burnout_blow_panel2" "blow_burnout2" "FXfire_bk3"}
		{add_view "burnout_blow_panel3" "blow_burnout3" "FXfire_bk3"}
		{add_view "burnout_blow_panel4" "blow_burnout4" "FXfire_bk3"}
	}
	{on "_explosion"
		{tear "piece_medium_steel" bone "part1" {impulse up 5 rnd_dir 2}}
		{tear "piece_medium_steel" bone "part2" {impulse up 5 rnd_dir 2}}
	}
	{on break
		{if volume "ammo_storage_main"
;			{if explosive_amount 30
				{tear "piece_medium_steel" bone "part1" {impulse up 5 rnd_dir 2}}
				{tear "piece_medium_steel" bone "part2" {impulse up 5 rnd_dir 2}}
;			}
		}
	}
	{on fire "mgun" overload
		{view start "flashbarrel4"}
		("cw_check_shooting" weap_id(mgun))
	}
	{on fire "mgun2" overload
		{view start "flashbarrel5"}
		("cw_check_shooting" weap_id(mgun2))
	}
	{on fire "mgun3" overload
		{view start "flashbarrel6"}
		("cw_check_shooting" weap_id(mgun3))
	}
	{on fire "mgun4" overload
		{view start "flashbarrel7"}
		("cw_check_shooting" weap_id(mgun4))
	}
}
{"m1a2tusk_2_new"
	("auto_gren_launcher" mgun(mgun3))
}
{"bredly"
	{on spawn		
		{add_view	 	"flash_gun_big"	"flashbarrel2"		"Foresight2"}
		{add_view	"rok_tail"	"rok_tail_gun2"	"tail00"}
		{add_view	"rok_tail"	"rok_tail_gun3"	"tail01"}
    	}
	("bredly_sound")
	{on fire "mgun" overload
		{view start "flashbarrel2"}
		("cw_check_shooting" weap_id(mgun))
	}
    	("25mm_bushmaster")
	("atgm_multi_launcher"	weapon(gun2) tail(tail) foresight(foresight6))
		{on "update_cw_panorama" overload
	   {if operatable
		{if work "additional_triplex"
			 {if work "commander_triplex"
				  {if not tagged "contusion"
					{if crew_in_place "charger"
						{if not tagged "no_power"
							{call "cw_panorama_work"}
						else {call "cw_panorama_off"}}
					else {call "cw_panorama_off"}}
				  else {call "cw_panorama_off"}}
			 else {call "cw_panorama_off"}}
		else {call "cw_panorama_off"}}
	   else {call "cw_panorama_instant_off"}}
	}
}
{"m2_adats"
	("bredly_sound")
	{on "init_gun2"
		{add_view 	"rok_tail"		"tail00"			"tail00"}
		{add_view 	"rok_tail"		"tail01"			"tail01"}
		{add_view 	"rok_tail"		"tail02"			"tail02"}
		{add_view 	"rok_tail"		"tail03"			"tail03"}
		{add_view 	"rok_tail"		"tail04"			"tail04"}
		{add_view 	"rok_tail"		"tail05"			"tail05"}
		{add_view 	"rok_tail"		"tail06"			"tail06"}
		{add_view 	"rok_tail"		"tail07"			"tail07"}
	}
	{on fire "gun2" overload
		(define "fire_barrel"
			name "%0"
				{delay 0.1 
					{if not tagged "radar_off"
						{spawn "adats_carrier" "shooter%0"   x}
					else
			;radar_off indicates shooting without proximity_charge
						{spawn "adats_carrier" "shooter%0"   x
							{delay 1.05 
								{volumes "proximity" disable all}
							}
						}
					}
				}
				{view start "tail%0"}
				{spawn "startsmoke" "shooter%0" x}
				{spawn "startsmoke" "tail%0" x}
				{delay 0.4	{view pause "tail%0"}}
		)
			{if    ("fire_barrel" args 00)  else ("fire_barrel" args 01)
			  else ("fire_barrel" args 02)  else ("fire_barrel" args 03)
			  else ("fire_barrel" args 04)  else ("fire_barrel" args 05)	
			  else ("fire_barrel" args 06)  else ("fire_barrel" args 07)	
			}
		("cw_check_shooting" weap_id(gun2))
	}
	{on "cut_parts"
		{if rand 0.5
		     {tear "piece_large_steel" bone "Missile" id "Gun_rot"
			{impulse dir 0.5 1}
			{if rand 0.2 {add_view "smoke_dead_norm" "smoke" "basis"}
			else {add_view "smoke_black" "smoke" "basis"}}
			{view start "smoke"}
			{delay_effect 30 5 "pause"}
			{delay 0.1 {volumes "gun" disable obstacle}}
		     }
		}
		{if rand 0.5
		     {tear "piece_large_steel" bone "Missile2" id "Gun_rot"
			{impulse dir 0.5 1}
			{if rand 0.2 {add_view "smoke_dead_norm" "smoke" "basis"}
			else {add_view "smoke_black" "smoke" "basis"}}
			{view start "smoke"}
			{delay_effect 30 5 "pause"}
			{delay 0.1 {volumes "gun" disable obstacle}}
		     }
		}
		{if rand 0.5
		     {tear "piece_large_steel" bone "Radar"
			{impulse dir 0.5 1}
			{if rand 0.2 {add_view "smoke_dead_norm" "smoke" "basis"}
			else {add_view "smoke_black" "smoke" "basis"}}
			{view start "smoke"}
			{delay_effect 30 5 "pause"}
		     }
		}
	}
	("radar_params" triplex(additional_triplex) visor(visor3) anim_rotate(radar_loop) marker(antirad_generator_usa))
}
{"m113a"
	("m113_sound")
	{on "update_hatch_on_spawn"
		("update_hatch" wind(true) place(gunner))
	}
	("update_hatch_event" event(operatable on) place(gunner))
	("update_hatch_event" event(operatable off) place(gunner))
	("update_hatch_event" event(crew in) place(gunner))
	("update_hatch_event" event(crew out) place(gunner))
	("zpu_params" gunner(gunner) zpu_mgun(mgun) anim(into_hatch_high) pose(seat_gunner_stand))
}
{"m163"
	("m113_sound")
	("gatling_gun" FXshell(FXshell))
	("radar_params" triplex(additional_triplex) visor(visor3) anim_rotate(none) marker(antirad_generator_usa))
}
{"m163machbet"
	("m113_sound")
	("gatling_gun" FXshell(FXshell))
	("custom_multi_launcher"	weapon(gun2) tail(tail) shooter(shooter) missile(fim-92a))
}

{"mrls"
	("mlrs_m270")
	("m270_sound")
}
{"mrls_atacms"
	("mlrs_m270")
	("m270_sound")
}
{"m142_himars"
	("mlrs_m270")
	("hemtt_sound")
}
{"nasams_ii_launcher"
	("hemtt_sound")
	{on "init_gun2"
		{add_view 	"rok_tail"		"tail00"			"tail00"}
		{add_view 	"rok_tail"		"tail01"			"tail01"}
		{add_view 	"rok_tail"		"tail02"			"tail02"}
		{add_view 	"rok_tail"		"tail03"			"tail03"}
		{add_view 	"rok_tail"		"tail04"			"tail04"}
		{add_view 	"rok_tail"		"tail05"			"tail05"}
	}
	{on fire "gun2" overload
		(define "fire_barrel"
			name "%0"
				{delay 0.1 {spawn "aim-120c7_nasams_carrier" "shooter%0"   x}}
				{ani_play "fire%0"}
				{view start "tail%0"}
				{spawn "startsmoke" "shooter%0" x}
				{spawn "startsmoke" "tail%0" x}
				{delay 0.4
					{view pause "tail%0"}
				}
				
		)
			{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			  else ("fire_barrel" args 02)
			  else ("fire_barrel" args 03)
			  else ("fire_barrel" args 04)
			  else ("fire_barrel" args 05)	
			}
		("cw_check_shooting" weap_id(gun2))
	}
	{on ik begin "turret" {play_sound "rotate_turret" 1}}
	{on ik end "turret" {stop_sound "rotate_turret"}}
	{on move on	
		{delay 0.1 {call "update_gun23"}}		
		{delay 3.0 {if velocity 5 {call "uprise_outriggers"}}}
	}
	{on move off	{delay 0.1 {call "update_gun23"}{call "lower_outriggers"}}}
	{on "uprise_outriggers"	
	       {if not flag "feather" 
		{ani_play "close" 1}	
		{set "feather" 1}
	        }
	}
	{on "lower_outriggers"	
	       {if flag "feather" 
		{ani_play "close" -1}
		{set "feather" 0}
	       }
	}
	{on "update_gun23" overload
		{if work "gun2"
		      {if work "stabilizer"
			    {if work "gunner_panel"
			  	  {if not tagged "no_power"
					{if not flag "specability"
					  {if not velocity 0
						  {weapon_work "gun2" 1}
					   else {weapon_work "gun2" 0}}
					else {weapon_work "gun2" 0}}
				  else {weapon_work "gun2" 0}}
				else {weapon_work "gun2" 0}}
		      else {weapon_work "gun2" 0}}
		else {weapon_work "gun2" 0}}
	}
}
{"lav25"
	{on spawn		
		{add_view	 	"flash_gun_big"	"flashbarrel2"		"Foresight2"}
		{add_view "zenit_gilz"		"shells_mg"	"fxshell1"}

 	}
	("lav25_sound")
	{on fire "mgun1" overload
		{view start "flashbarrel2"}
		("cw_check_shooting" weap_id(mgun1))
	}
	{on fire "mgun2"
		{view show	"shells_mg"}
		{view start	"shells_mg"}
		{delay 0.2
			{view pause	"shells_mg"}
		}
	}
	("25mm_bushmaster")
	("zpu_params" gunner(gunner2) zpu_mgun(mgun2) anim(into_hatch_common) pose(seat_gunner_stand))
}
{"lav25_2"
	("zpu_params" gunner(gunner2) zpu_mgun(mgun) anim(into_hatch_common) pose(seat_m7_mgunner))
}
{"lav-ad"
	("gatling_gun" FXshell(FX_shell))
	("custom_multi_launcher"	weapon(gun2) tail(tail) shooter(shooter) missile(fim-92a))
}
{"lav-atws"
	("lav25_sound")
	("atgm_multi_launcher"	weapon(gun) tail(tail) foresight(foresight1))
}
{"m1126"
	("stryker_sound")
}
{"m1126_jav"
	("stryker_sound")
	("atgm_single_launcher" weapon(gun2) tail(tail) foresight(foresight2))
}
{"m1128"
	{on spawn		
		{add_view "flash_gun_big" "flashbarrel2" "Foresight1"}	
		{add_view "flash_gun_small" "flashbarrel3" "Foresight3"}
		{add_view "zenit_gilz"		"shells_we"	"fxshell"}
	}
	("zpu_params" gunner(gunner2) zpu_mgun(mgun1) anim(into_hatch_m1128) pose(seat_gunner_stand))
	("stryker_sound")
	{on fire "mgun"
		{view show	"shells_we"}
		{view start	"shells_we"}
		{delay 0.2
			{view pause	"shells_we"}
		}
	}
	{on "init_gun"
		{add_view 	"smoke_ejector" 	"zenite_smoke" 		"foresight1"}
	}
	("90-105mm_gun_with_cm")
	("90-105mm_gilza_back")
}
{"m1134"
	("stryker_sound")
	("atgm_multi_launcher"	weapon(gun) tail(tail) foresight(foresight1))
}
{"m-1129"
	("stryker_sound")
	("auto_gren_launcher" mgun(mgun))
}
{"shorad"
	("stryker_sound")
	("autocannon_muzzle_brake")
	("25-50mm_gilza" fxshell(fxshell))
	("radar_params" triplex(commander_triplex) visor(visor1) anim_rotate(none) marker(antirad_generator_usa))
;	("custom_sh_multi_launcher" weapon(gun3) foresight(foresight5) tail(tailL_) shooter(shooterl))
	{on "init_gun2"	{add_view 	"rok_tail"		"tailL_00"			"tailL_00"}		{add_view 	"rok_tail"		"tailL_01"			"tailL_01"}}
	{on fire "gun2" overload
		("low_speed_bullet")
		(define "fire_barrel"
			name "%0"
				{view start "%tail%0"}	{spawn "startsmoke" "shooterl%0" x}		{spawn "startsmoke" "tailL_%0" x}
;				{spawn "proj_probe" "foresight5" x  {tags add "shooterl%0"}}
				{set "gun2"}{call "proj_probe"}
				{delay 0.4		{view pause "tailL_%0"}	}
		)
		{if    ("fire_barrel" args 00)	  else ("fire_barrel" args 01)}
		{ani_play "fire2"}
		("cw_check_shooting" weap_id(gun2))
	}	
	("custom_multi_launcher"	weapon(gun3) tail(tail_) shooter(shooter) missile(fim-92a))
}
{"m1296"
	("stryker_sound")
	{on spawn		
		{add_view	 	"flash_gun_big"	"flashbarrel3"		"Foresight3"}
 		{add_view "zenit_gilz"		"shells_mg"	"fxshell_mgun"}
   }
	{on fire "mgun" overload
		{view start "flashbarrel3"}
		{view show	"shells_mg"}
		{view start	"shells_mg"}
		{delay 0.2
			{view pause	"shells_mg"}
		}
		("cw_check_shooting" weap_id(mgun))
		
	}
    ("autocannon")
	("25-50mm_gilza" fxshell(fxshell))
}
{"paladin"
	{on spawn
		{add_view		"exhaust_dark"	"engine_steam1" 		"FXsmoke1"}	
		{add_view 	"smoke_zenit" 	"zenite_smoke" 		"foresight1"}
		{add_view "zenit_gilz"		"shell_m1"	"fxshell"}	
		{add_view "flash_gun_big" "flashbarrel3" "Foresight4"}
    	}
	("paladin_sound")
    	("135-180mm_sph_gun")
    ;gun can be disabled by specability
	;gun can work without electric power
	{on "update_gun"
		{if work "gun"
			 {if work "stabilizer"
			  {if work "gunner_panel"
				{if not flag "specability"
				  {if not tagged "contusion"
					{weapon_work "gun" 1}
				  else {weapon_work "gun" 0}}
				else {weapon_work "gun" 0}}
			  else {weapon_work "gun" 0}}
			 else {weapon_work "gun" 0}}
		else {weapon_work "gun" 0}}
	}
	 
	{on fire "mgun" 
		{view start "shell_m1"}
		{kill_delay "shell_m1"}
		{delay 0.2 "shell_m1"
			{view pause "shell_m1"}
		}
		
	}
	("zpu_params" gunner(gunner2) zpu_mgun(mgun) anim(into_hatch_high) pose(seat_gunner_stand))
}

{"aavp7"
	{on spawn		
		{add_view	 	"flash_gun_big"	"flashbarrel4"		"Foresight4"}
 	}
	("aavp7_sound")
	("auto_gren_launcher" mgun(mgun))
	{on fire "mgun2" overload
		{view start "flashbarrel4"}
		("cw_check_shooting" weap_id(mgun2))
	}
}

;=======================================
{"m551"	;Sheridan
	("2a46_type_gun_nogilz")
}
;----------------------------------Pheonix game(c) 2012---------------