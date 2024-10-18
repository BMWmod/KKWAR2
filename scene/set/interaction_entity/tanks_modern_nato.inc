{"magach7"
	{on spawn
		{add_view "flash_gun_big" "flashbarrel3" "Foresight2"}
    	}
	("m60_sound")
	("m68_type_gun")	
	{on fire "mgun"
		{view start "flashbarrel3"}
	}
	("auto_gren_launcher" mgun(gun1))
}
{"leopard"
	{on spawn
		{add_view "flash_gun_small" "flashbarrel3" "Foresight5"}
		{add_view "flash_gun_small" "flashbarrel4" "Foresight6"}						
    }
	("leopard_sound")
	("m256_type_gun")
	("zpu_params" gunner(gunner2) zpu_mgun(mgun1) anim(into_hatch_leo) pose(M1a1_mgun2))
}
{"leopard2"
	{on spawn
		{add_view "flash_gun_small" "flashbarrel3" "Foresight5"}
		{add_view "flash_gun_small" "flashbarrel4" "Foresight6"}						
    }
	("leopard2_sound")
	("m256_type_gun")
	("zpu_params" gunner(gunner2) zpu_mgun(mgun1) anim(into_hatch_leo) pose(M1a1_mgun2))
	{on "blow_panels1" overload
		{tear "piece_medium_steel" bone "part1" {impulse up 5 rnd_dir 2}}
		{add_view "burnout_blow_panel1" "blow_burnout1" "FXfire_bk1"}
		{add_view "burnout_blow_panel2" "blow_burnout2" "FXfire_bk1"}
		{add_view "burnout_blow_panel3" "blow_burnout3" "FXfire_bk1"}
		{add_view "burnout_blow_panel4" "blow_burnout4" "FXfire_bk1"}
	}
	{on "_explosion"
		{tear "piece_medium_steel" bone "part1" {impulse up 5 rnd_dir 2}}
		{tear "piece_medium_steel" bone "part2" {impulse up 5 rnd_dir 2}}
	}
	{on break
		{if volume "ammo_storage_main1"
			{tear "piece_medium_steel" bone "part1" {impulse up 5 rnd_dir 2}}
			{tear "piece_medium_steel" bone "part2" {impulse up 5 rnd_dir 2}}
		}
	}
}
{"leopard2a7plus"
	{on spawn
		{add_view "flash_gun_big" "flashbarrel4" "Foresight6"}						
    }
}
{"leopard2a7plus_gmg"
	("auto_gren_launcher" mgun(mgun1))
}
{"challenger_2"
	{on spawn
		{add_view "flash_gun_small" "flashbarrel3" "Foresight5"}
		{add_view "flash_gun_small" "flashbarrel4" "Foresight6"}						
    	}
	("challenger_2_sound")
	("m256_type_gun")
	("zpu_params" gunner(gunner2) zpu_mgun(mgun1) anim(into_hatch_common) pose(seat_gunner_stand))
}
{"leclerc"
	("leclerc_sound")
	("m256_type_gun")	
	{on fire "mgun1" 
		{view start "shell_m1"}
		{kill_delay "shell_m1"}
		{delay 0.2 "shell_m1"
			{view pause "shell_m1"}
		}
	}
	{on "blow_panels" overload
		{tear "piece_medium_steel" bone "part1" {impulse up 5 rnd_dir 2}}
		{tear "piece_medium_steel" bone "part2" {impulse up 5 rnd_dir 2}}
		{tear "piece_medium_steel" bone "part3" {impulse up 5 rnd_dir 2}}
		{add_view "burnout_blow_panel1" "blow_burnout1" "FXfire_bk"}
		{add_view "burnout_blow_panel2" "blow_burnout2" "FXfire_bk"}
		{add_view "burnout_blow_panel3" "blow_burnout3" "FXfire_bk"}
		{add_view "burnout_blow_panel4" "blow_burnout4" "FXfire_bk"}
	}
}
{"merkava_mk4"
	{on spawn
		{volumes "apploque_inter4" enable bullet blast}				
		{add_view	"flash_gun_big"	"flashbarrel7"	"Foresight7"}
		{add_view "flash_gun_big" "flashbarrel5" "Foresight5"}
   	}
	("merkava4_sound")
	("zpu_params" gunner(gunner2) zpu_mgun(mgun) anim(into_hatch_abrams) pose(seat_gunner_stand))
	{on break overload
		{if component "ammo_storage_autocannon"
			{spawn "ex_air_big2"} {fragments c4 6 r0 4 r1 8 position}
			{delay_ex 0.2 0.5 {spawn "ex_air_big2" inv_normal} {fragments c4 6 r0 4 r1 8 position}}
			{delay_ex 0.6 1 {spawn "ex_air_big2" inv_normal} {fragments c4 6 r0 4 r1 8 position}}
			{delay_ex 1 1.2 {spawn "ex_air_big2" inv_normal} {fragments c4 6 r0 4 r1 8 position}}
			{delay_ex 1.3 1.5 {spawn "ex_air_big2" inv_normal} {fragments c4 6 r0 4 r1 8 position}}
		else component "fuel_tank_internal_a"
			{if not tagged "destroyed"
				{damage_report "fuel_tank_external_a" "fuel:fuel_tank_damaged"}
				{if rand 0.8
					{burn fx "smoke_dead_norm" fake}
					{if rand 0.8
						{spawn "ex_air_big"}
					}
				}
			}
		else {inherited}
		}
	}
	{on "init_gun"
		{add_view 	"smoke_ejector_fast" 	"zenite_smoke" 		"foresight1"}
	}
	{on fire "gun" 
		{view start "flashbarrel_gun"}
		{view start "smoke_add"}
		{delay 0.2 "shell_off"
			{view start "zenite_smoke"}
			{view pause "smoke_add"}
			{view pause "flashbarrel_gun"}
			{delay 0.8 {view pause "zenite_smoke"}}
		}
;		{spawn "proj_probe" "Foresight1" x}
		{set "gun"}{call "proj_probe"}
      		{spawn "dust_shot_big" "basis"}
    	 	{spawn "tank_canon_fire_3" "Foresight1" x}
		{spawn "cw_human_tankgun_contusion" "Foresight1"}
		{volumes "apploque_inter4" disable bullet blast}
		{delay 3
			{volumes "apploque_inter4" enable bullet blast}
		}
	}
	{on fire "mgun2" overload
		{view start "flashbarrel7"}
		("cw_check_shooting" weap_id(mgun2))
	}
	{on fire "mgun"
		{view start "flashbarrel5"}
	}
	("auto_gren_launcher" mgun(gun1))
}
{"namer"
	("merkava4_sound")
	("auto_gren_launcher" mgun(gun1))
}
{"eitan"
	("boxer_sound")
	("zpu_params" gunner(gunner2) zpu_mgun(mgun2) anim(into_hatch_abrams) pose(seat_gunner_stand))
	{on fire "mgun2" overload
		{view start "flashbarrel3"}
		("cw_check_shooting" weap_id(mgun2))
	}
	{on break overload
		{if component "fuel_tank_internal_a"
			{if not tagged "destroyed"
				{damage_report "fuel_tank_external_a" "fuel:fuel_tank_damaged"}
				{if rand 0.8
					{burn fx "smoke_dead_norm" fake}
					{if rand 0.8
						{spawn "ex_air_big"}
;						{blastwave c4 3 r0 2 r1 6 position}
					}
				}
			}
		else {inherited}
		}
	}
	{on operatable on
		{tags remove "cwsh_active"}
		{tags add "cwsh_passive"}
		{call "cwsh_disable_zpu"}
    }

}
{"eitan_apc_mg"
	{on fire "mgun" overload
		{view start "flashbarrel4"}
		("cw_check_shooting" weap_id(mgun))
	}
}
{"eitan_apc_ags"
	("auto_gren_launcher" mgun(mgun))
}
{"marder_1a3"
	{on spawn		
		{add_view	 	"flash_gun_big"	"flashbarrel5"		"Foresight5"}
		{add_view	"rok_tail"	"rok_tail_gun2"	"tail"}
    }
	("marder_sound")
	{on fire "mgun" overload
		{view start "flashbarrel5"}
		("cw_check_shooting" weap_id(mgun))
	}
    ("autocannon")
	("25-50mm_gilza" fxshell(fxshell))
;	("custom_single_launcher" weapon(gun2) tail(tail) foresight(foresight6) missile(milan_rock))
	("atgm_single_launcher" weapon(gun2) foresight(foresight6) tail(tail))
}
{"ifvboxer"
	("boxer_sound")
	{on "cut_parts"
		{if rand 0.5 ("cut_part" args "doorback")}
	}
}
{"boxer_gmg"
	("auto_gren_launcher" mgun(mgun))
}
{"boxer_lance"
	{on spawn		
		{add_view	 	"flash_gun_big"	"flashbarrel5"		"Foresight5"}
    }
	{on fire "mgun" overload
		{view start "flashbarrel5"}
		("cw_check_shooting" weap_id(mgun))
	}
    ("autocannon")
	("25-50mm_gilza" fxshell(fxshell))
	("custom_multi_launcher"	weapon(gun2) tail(tail) shooter(shooter) missile(spike-lr))
}
{"puma"
	{on spawn		
		{add_view	 	"flash_gun_big"	"flashbarrel5"		"Foresight5"}
    }
	("puma_sound")
	{on fire "mgun" overload
		{view start "flashbarrel5"}
		("cw_check_shooting" weap_id(mgun))
	}
    ("autocannon")
	("25-50mm_gilza" fxshell(fxshell))
	("custom_multi_launcher"	weapon(gun2) tail(tail) shooter(shooter) missile(spike-lr))
}
{"wiesel1_gun"
	("wiesel_sound")
	{on spawn		
		{add_view	 	"flash_gun_big"	"flashbarrel5"		"Foresight5"}
    }
    ("autocannon")
	("25-50mm_gilza" fxshell(fxshell))
}
{"wiesel1_tow"
	("wiesel_sound")
	("atgm_single_launcher" weapon(gun2) tail(tail) foresight(foresight6))
	("zpu_params" gunner(gunner2) zpu_mgun(gun2) anim(into_hatch_leo) pose(seat_m7_mgunner))
	{on "update_gun23" overload
	     {if work "gun2" 
	          {if tagged "cwsh_zpu_off"
					{weapon_work "gun2" 0}
				else {inherited}
	           }
	     }
	}
	{on operatable on
         {tags add "cwsh_active"}
         {if  tagged "cwsh_tempdisable_zpu"
          {call "cwsh_enable_zpu"}
          {tags remove "cwsh_tempdisable_zpu"}
         }
    }

}
{"wiesel_2_leflasys"
	("wiesel_sound")
	{on operatable on
		{if not flag "radar_up"
			{set "radar_up" 1}
			{ani_play "launcher_deploy"}
		}
	}
	{on repair
		{if component "body"
			{set "radar_up" 1}
			{ani_play "launcher_deploy"}
		}
	}
	("custom_multi_launcher"	weapon(gun2) tail(tail) shooter(shooter) missile(fim-92a))
}
{"warrior"
	{on spawn		
		{add_view	 	"flash_gun_big"	"flashbarrel5"		"Foresight5"}
		{add_view	"rok_tail"	"rok_tail_gun2"	"tail"}
    }
	("warrior_sound")
	{on fire "mgun" overload
		{view start "flashbarrel5"}
		("cw_check_shooting" weap_id(mgun))
	}
    ("autocannon")
	("25-50mm_gilza" fxshell(fxshell))
}
{"warrior_milan"
;	("custom_single_launcher" weapon(gun2) tail(tail) foresight(foresight6) missile(milan_rock))
	("atgm_single_launcher" weapon(gun2) foresight(foresight6) tail(tail))

	{on "update_hatch_on_spawn"
		("update_hatch" wind(true) place(commander))
	}
	("update_hatch_event" event(operatable on) place(commander))
	("update_hatch_event" event(operatable off) place(commander))
	("update_hatch_event" event(crew in) place(commander))
	("update_hatch_event" event(crew out) place(commander))
	("zpu_params" gunner(commander) zpu_mgun(gun2) anim(into_hatch_common) pose(seat_gunner_stand))
	{on "update_gun23" overload
	     {if work "gun2" 
	          {if tagged "cwsh_zpu_off"
					{weapon_work "gun2" 0}
				else {inherited}
	           }
	     }
	}
}
{"ajax"
	{on spawn
		{add_view	"flash_gun_big"			"flashbarrel5"			"Foresight5"}
		{add_view "zenit_gilz"		"shell_mgun"	"fxshell_mg"}	
	}
	("25mm_bushmaster")
	("ajax_sound")
	{on fire "mgun" 
		{view start "flashbarrel5"}
		{view start "shell_mgun"}
		{kill_delay "flashbarrel5"}
		{delay 0.08 "flashbarrel5"
			{view pause "flashbarrel5"}
			{view pause "shell_mgun"}
		}
		("cw_check_shooting" weap_id(mgun))
	}
}
{"vbci_vpc"
	{on spawn
		{add_view	"flash_gun_big"			"flashbarrel1"			"Foresight1"}
		{add_view 	"smoke_zenit" 	"zenite_smoke" 		"foresight1"}
		{add_view "zenit_gilz"		"shell"	"fxshell"}	
	}
	("vbci_sound")
	{on fire "mgun" 
		{view start "flashbarrel1"}
		{view start "shell"}
		{kill_delay "flashbarrel1"}
		{delay 0.08 "flashbarrel1"
			{view pause "flashbarrel1"}
			{view pause "shell"}
		}
		("cw_check_shooting" weap_id(mgun))
	}
}
{"vbci"
	{on spawn
		{add_view	"flash_gun_big"			"flashbarrel3"			"Foresight3"}
		{add_view "zenit_gilz"		"shell_mgun"	"fxshell_mgun"}	
	}
	("25mm_bushmaster")
	("vbci_sound")
	{on fire "mgun" 
		{view start "flashbarrel3"}
		{view start "shell_mgun"}
		{kill_delay "flashbarrel3"}
		{delay 0.08 "flashbarrel3"
			{view pause "flashbarrel3"}
			{view pause "shell_mgun"}
		}
		("cw_check_shooting" weap_id(mgun))
	}
}
{"vbci_2"
	{on spawn
		{add_view	"flash_gun_big"			"flashbarrel3"			"Foresight3"}
		{add_view "zenit_gilz"		"shell_mgun"	"fxshell_mgun"}	
	}
;	("custom_single_launcher" weapon(gun2) foresight(foresight4) missile(mmp_missile) tail(taill_01))
;	("custom_single_launcher" weapon(gun3) foresight(foresight5) missile(mmp_missile) tail(taill_00))
	("custom_multi_launcher" weapon(gun2) tail(tail_) shooter(shooter_) missile(mmp_missile))
	("25mm_bushmaster")
	("vbci_sound")
	{on fire "mgun" 
		{view start "flashbarrel3"}
		{view start "shell_mgun"}
		{kill_delay "flashbarrel3"}
		{delay 0.08 "flashbarrel3"
			{view pause "flashbarrel3"}
			{view pause "shell_mgun"}
		}
		("cw_check_shooting" weap_id(mgun))
	}
}
{"kto_rosomak"
	{on spawn
		{add_view	"flash_gun_big"			"flashbarrel3"			"Foresight3"}
		{add_view "zenit_gilz"		"shell_mgun"	"fxshell_mgun"}	
	}
	("25mm_bushmaster")
	("patria_sound")
	{on fire "mgun" 
		{view start "flashbarrel3"}
		{view start "shell_mgun"}
		{kill_delay "flashbarrel3"}
		{delay 0.08 "flashbarrel3"
			{view pause "flashbarrel3"}
			{view pause "shell_mgun"}
		}
		("cw_check_shooting" weap_id(mgun))
	}
}
{"amx10rc_common"
	{on spawn		
		{add_view "flash_gun_big" "flashbarrel2" "Foresight1"}	
		{add_view "flash_gun_small" "flashbarrel3" "Foresight3"}
	}
	("amx10rc_sound")
	("90-105mm_gun_with_cm")
	("custom_gilza" bone(fxshell) type(shell_cannon) scale(1.0) up(0.1) forward(2))
	{on "cwsh_switch_hatch"
	  {if operatable
	   {if not tagged "contusion"
		{if not flag "radar_up"
			{ik_enable "hydro_steering" 0}
			{set "radar_up" 1}
			{damage_report "body" "hydro_steering_off"}
		else
		  {if not tagged "no_power"
			{ik_enable "hydro_steering" 1}
			{set "radar_up" 0}
			{damage_report "body" "hydro_steering_on"}
		  }
		}
	   }
	  }
	}
	{on "update_turret"
		{if tagged "no_power"	{ik_enable "hydro_steering" 0}
		else not flag "radar_up" {ik_enable "hydro_steering" 1}
		}
	}
}
{"amx10rc"
	("smokegun_nospread" smokegun(mgun19))
	("smokegun_nospread" smokegun(mgun20))
}
{"roland"
	("man_kat_sound")
	("custom_multi_launcher"	weapon(gun2) tail(tail) shooter(r_shooter) missile(xmim-115avt1))
	("radar_params" triplex(additional_triplex) visor(visor3) anim_rotate(radar_loop) marker(antirad_generator_usa))
	
	("update_hatch_event" event(operatable on) place(gunner2))
	("update_hatch_event" event(operatable off) place(gunner2))
	("update_hatch_event" event(crew in) place(gunner2))
	("update_hatch_event" event(crew out) place(gunner2))

}
{"sampt_arabel"
	("sampt_sound")
	{on spawn {delay 5 {call "update_antiradar"}}}
	{on "update_radar"
		{if tagged "radar_off" {weapon_work "radar" 0}
		else not work "commander_triplex" {weapon_work "radar" 0}
		else not work "body" {weapon_work "radar" 0}
		else not work "turret" {weapon_work "radar" 0}
		else not work "radar" {weapon_work "radar" 0}
		else tagged "no_power" {weapon_work "radar" 0}
		else {weapon_work "radar" 1}
		}
	}
	{on crew out
		{if crew_in_place "driver" {tags add "arabel_moves"}{call "update_antiradar"}}
		{if not crew_in_place "commander" {call "update_antiradar"}}
	}
	{on crew in
		{if crew_in_place "commander" {delay 4 {call "update_antiradar"}}}
	}
	{on break
		{if component "commander_triplex" {call "update_antiradar"}}
	}
	{on repair
		{if component "commander_triplex" {call "update_antiradar"}}
	}
	{on "update_antiradar" overload
			{if crew_in_place "commander"
			  {if not tagged "no_power"
			   {if not tagged "cwsh_passive"
				 {if work "commander_triplex"
				   {if tagged "arabel_moves"
					{call "cwsh_radar_on"}
				   else not tagged "radar_off"
				    {call "cwsh_radar_on"}
				   else 
				    {call "cwsh_radar_off"}
				   }
				 else
					{call "cwsh_radar_off"}
				}
			   else
				{call "cwsh_radar_off"}
			   }
			  else
				{call "cwsh_radar_off"}
			  }
			else
				{call "cwsh_radar_off"}
			}
	}
	{on "specability" overload	}
	{on "cwsh_radar_on"
		{tags remove "arabel_moves"}
		{if work "commander_triplex"
		  {if crew_in_place "commander"
			{ani_play "radar_loop" loop}
			{delay 0.1 {ani_play "visor1" -1}}
			{with_linked_entity "vehicle9"
				{call "start"}
			}
		   }
		}
	}
	{on "cwsh_radar_off"
		{ani_stop "radar_loop"}
		{delay 0.1 {ani_play "visor1"}}
		{with_linked_entity "vehicle9"
			{call "stop"}
		}
	}
}

{"sampt_mamba"
	("sampt_sound")
	("custom_multi_vertlauncher" weapon(gun2) tail(tail) shooter(shooter) missile(sampt) tailfx(proj_jet_sam))
	{on "_explosion"
		{bone cut "wires"}
		{tear "piece_medium_steel" bone "launcher"
			{impulse up 4 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 6 no_position}
			{delay_effect 20 5 "stop"}
		}
	}
}
{"tpz1a6"
	("tpz_sound")
	("zpu_params" gunner(gunner2) zpu_mgun(mgun) anim(into_hatch_common) pose(seat_gunner_stand))
}
{"vab_reco"
	{on spawn
		{add_view "zenit_gilz"		"shell_mgun"	"fxshell_mgun"}	
	}
	{on fire "mgun" 
		{view start "flashbarrel3"}
		{view start "shell_mgun"}
		{kill_delay "flashbarrel3"}
		{delay 0.08 "flashbarrel3"
			{view pause "flashbarrel3"}
			{view pause "shell_mgun"}
		}
		("cw_check_shooting" weap_id(mgun))
	}
	("vab_sound")
	("commonzpu_params" gunner(gunner) zpu_mgun(mgun) anim(into_hatch_car) pose(pose_dodge_sg2))
	("zpu_one_hatch" gunner(gunner) hatch_anim(open1))
}
{"vab_mephisto"
	("vab_sound")	
	{on operatable on
		{if not flag "radar_up"
			{set "radar_up" 1}
			{ani_play "launcher_deploy"}
		}
	}
	{on repair
		{if component "body"
			{set "radar_up" 1}
			{ani_play "launcher_deploy"}
		}
	}
	{on ik begin "turret" {play_sound "rotate_turret" 1}}
	{on ik end "turret" {stop_sound "rotate_turret"}}
	{on fire "gun2" 
		("low_speed_bullet")
		{if name "00"	{delay 0.1 {spawn "hot_rock_carrier" "shooter00"   x}{spawn "startsmoke" "shooter00" x}{spawn "startsmoke" "taill_00" x}}
		else name "01"	{delay 0.1 {spawn "hot_rock_carrier" "shooter01"   x}{spawn "startsmoke" "shooter01" x}{spawn "startsmoke" "taill_01" x}}
		else name "02"	{delay 0.1 {spawn "hot_rock_carrier" "shooter02"   x}{spawn "startsmoke" "shooter02" x}{spawn "startsmoke" "taill_02" x}}
		else name "03"	{delay 0.1 {spawn "hot_rock_carrier" "shooter03"   x}{spawn "startsmoke" "shooter03" x}{spawn "startsmoke" "taill_03" x}}
		}
	}
}
{"vab_t20"
    ("autocannon")
	("25-50mm_gilza" fxshell(fxshell_gun))

	("vab_sound")
}
{"vbl_common"
	{on spawn
		{add_view "zenit_gilz"		"shell_mgun"	"fxshell"}	
	}
	("vbl_sound")
}
{"vbl_reco"
	{on fire "mgun" 
		{view start "flashbarrel3"}
		{view start "shell_mgun"}
		{kill_delay "flashbarrel3"}
		{delay 0.08 "flashbarrel3"
			{view pause "flashbarrel3"}
			{view pause "shell_mgun"}
		}
		("cw_check_shooting" weap_id(mgun))
	}
	("zpu_params" gunner(gunner2) zpu_mgun(mgun) anim(into_hatch_btr90) pose(hmmwv_mgun))
}
{"vbl_anf"
	{on fire "mgun" 
		{view start "flashbarrel3"}
		{view start "shell_mgun"}
		{kill_delay "flashbarrel3"}
		{delay 0.08 "flashbarrel3"
			{view pause "flashbarrel3"}
			{view pause "shell_mgun"}
		}
		("cw_check_shooting" weap_id(mgun))
	}
	("commonzpu_params" gunner(gunner2) zpu_mgun(mgun) anim(into_hatch_btr90) pose(hmmwv_mgun))
	("zpu_one_hatch" gunner(gunner2) hatch_anim(open1))
}
{"vbl_milan"
	("atgm_single_launcher" weapon(gun2) foresight(foresight1) tail(tail1))
	("zpu_params" gunner(gunner2) zpu_mgun(gun2) anim(into_hatch_btr90) pose(pose_mgun_pz6))
	{on "update_gun23" overload
	     {if work "gun2" 
	          {if tagged "cwsh_zpu_off"
					{weapon_work "gun2" 0}
				else {inherited}
	           }
	     }
	}
}
{"vbl_mistral"
	{on spawn		
		{add_view	 	"flash_gun_big"	"gun_flash00"		"shooter00"}
		{add_view	 	"flash_gun_big"	"gun_flash01"		"shooter01"}
	}
	("custom_multi_launcher"	weapon(gun2) tail(tail) shooter(shooter) missile(mistral_missile))
	("zpu_params" gunner(gunner2) zpu_mgun(gun2) anim(into_hatch_btr90) pose(hmmwv_mgun))
	{on "update_gun23" overload
	     {if work "gun2" 
	          {if tagged "cwsh_zpu_off"
					{weapon_work "gun2" 0}
				else {inherited}
	           }
	     }
	}
}
{"gepard"
	{on spawn		
		{add_view "autocannon_gilz"	"gilz00" "fxshell00"}
		{add_view "autocannon_gilz"	"gilz01" "fxshell01"}
		{add_view	"gabarit_yellow"	"light"			"Fxgabarit1"}
		{add_view	"gabarit_yellow"	"light"			"Fxgabarit2"}
		{add_view	"gabarit_yellow"	"light"			"Fxgabarit3"}
		{add_view	"gabarit_yellow"	"light"			"Fxgabarit4"}

		{add_view	"lampa_red"	"lampa"			"Fxlampa1"}
		{view hide "lampa"}
	}
	("leopard_sound")
	("radar_lifting90_params" triplex(additional_triplex) visor(visor3) anim_rotate(radar_loop) anim_lift(radar_lift) marker(antirad_generator_usa))
	{on "init_gun" overload	}
	{on fire "gun" overload
		(define "fire_barrel"
			name "%0"
				{ani_play "fire%0"}
				{spawn "autocannon_fire_smoke" "shooter%0" x scale 2}
				{spawn "mgun_smoke" "fxshell%0" x}
				{view show	"gilz%0"}
				{view start	"gilz%0"}
				{delay 0.2 {view pause	"gilz%0"}}
		)
		{if    ("fire_barrel" args 00)	  else ("fire_barrel" args 01)	}
		{kill_delay "lampa"}
		{view start "lampa"}
		{view show "lampa"}
		{ani_play "lampa_rot" 1}
		{delay 3 "lampa"
			{view stop "lampa"}
			{view hide "lampa"}
			{ani_stop "lampa_rot"}
		}
		("cw_check_shooting" weap_id(gun))
	}
	{on "cut_parts"
		{view stop "lampa"}
		{view hide "lampa"}
		{ani_stop "lampa_rot"}
		{if rand 0.5
		     {tear "piece_large_steel" bone "Gun_rot1" id "Gun_rot"
			{impulse dir 0.5 1}
			{if rand 0.2 {add_view "smoke_dead_norm" "smoke" "basis"}
			else {add_view "smoke_black" "smoke" "basis"}}
			{view start "smoke"}
			{delay_effect 30 5 "pause"}
			{delay 0.1 {volumes "gun" disable obstacle}}
		     }
		}
		{if rand 0.5
		     {tear "piece_large_steel" bone "Gun_rot2" id "Gun_rot"
			{impulse dir 0.5 1}
			{if rand 0.2 {add_view "smoke_dead_norm" "smoke" "basis"}
			else {add_view "smoke_black" "smoke" "basis"}}
			{view start "smoke"}
			{delay_effect 30 5 "pause"}
			{delay 0.1 {volumes "gun" disable obstacle}}
		     }
		}
		{if rand 0.5
		     {tear "piece_large_steel" bone "GUN_Turr"
			{impulse dir 0.5 1}
			{if rand 0.2 {add_view "smoke_dead_norm" "smoke" "basis"}
			else {add_view "smoke_black" "smoke" "basis"}}
			{view start "smoke"}
			{delay_effect 30 5 "pause"}
		     }
		}
		{if rand 0.5
		     {tear "piece_large_steel" bone "Radar_Tu"
			{impulse dir 0.5 1}
			{if rand 0.2 {add_view "smoke_dead_norm" "smoke" "basis"}
			else {add_view "smoke_black" "smoke" "basis"}}
			{view start "smoke"}
			{delay_effect 30 5 "pause"}
		     }
		}
	}
}

{ "dana_152mm"
	{on spawn
		{add_view "zenit_gilz"		"shell_m1"	"fxshell"}	
		{add_view "flash_gun_big" "flashbarrel4" "foresight4"}	
    	}
	("dana_sound")
    	{on fire "gun" 
		("tank_gun")
      		{spawn "dust_shot_big" "basis"}
    	 	{spawn "canon_gaub_fire" "Foresight1" x}
		{spawn "cw_human_tankgun_contusion" "Foresight1"}
		{ani_play "start"}
	}
	("135-180mm_gilza")
    ;gun can be disabled by specability
	{on "update_gun"
		{if work "gun"
			 {if work "stabilizer"
			  {if work "gunner_panel"
				{if not flag "specability"
				  {if not tagged "contusion"
					{if not tagged "cw_autoloader_stuck"
						{weapon_work "gun" 1}
					else {weapon_work "gun" 0}}
				  else {weapon_work "gun" 0}}
				else {weapon_work "gun" 0}}
			  else {weapon_work "gun" 0}}
			 else {weapon_work "gun" 0}}
		else {weapon_work "gun" 0}}
	}
	{on fire "mgun" 
		 {spawn "mgun_smoke" "fxshell" x}  
        		{spawn "mgun_smoke" "Foresight4" x}  
		{view start "flashbarrel4"}
		{view start "shell_m1"}
		{kill_delay "shell_m1"}
		{delay 0.2 "shell_m1"
			{view pause "shell_m1"}
		}
	}
	("zpu_params" gunner(gunner2) zpu_mgun(mgun) anim(into_hatch_dana) pose(pose_dodge_sg2))
	
}
{"pzh2000"
	{on spawn
		{add_view 	"smoke_zenit" 	"zenite_smoke" 		"foresight1"}
		{add_view "flash_gun_big" "flashbarrel3" "Foresight4"}
    }
	("leopard2_sound")
    ("135-180mm_sph_gun")
	("zpu_params" gunner(gunner2) zpu_mgun(mgun) anim(into_hatch_high) pose(seat_gunner_stand))
	{on contact 
		{if effector "vulcano_sal_spawner"
			{if not tagged "vulcano_sal_spawned"
				{tags add "vulcano_sal_spawned"}
				{spawn "vulcano_sal" "Foresight1" x}
				{delay 1.0 {tags remove "vulcano_sal_spawned"}}
			}
		}
	}
}
{"as_90"
	{on spawn
		{add_view 	"smoke_zenit" 	"zenite_smoke" 		"foresight1"}
		{add_view "flash_gun_big" "flashbarrel3" "Foresight4"}
    }
	("challenger_2_sound")
    ("135-180mm_sph_gun")
	("zpu_params" gunner(gunner2) zpu_mgun(mgun) anim(into_hatch_high) pose(pose_dodge_sg2))
	("smokegun_as90" smokegun(mgun18))
	("smokegun_as90" smokegun(mgun19))
}
{"caesar"
	("caesar_sound")
    {on fire "gun" 
		("tank_gun")
      		{spawn "dust_shot_big" "basis"}
    	 	{spawn "canon_gaub_fire" "Foresight1" x}
		{view start "flashbarrel1"}
		{view start "flashbarrel1s"}
		{ani_play "fire"}
		{delay 2.5 {ani_play "fire" 1.3 resume}}
		{delay 0.8
			{view pause "flashbarrel1"}
		}
		{delay 0.2
			{view pause "flashbarrel1s"}
		}
	}
}
{"fv432_mk2"
	("fv432_sound")
	{on "update_hatch_on_spawn"
		("update_hatch" wind(true) place(gunner))
	}
	("update_hatch_event" event(operatable on) place(gunner))
	("update_hatch_event" event(operatable off) place(gunner))
	("update_hatch_event" event(crew in) place(gunner))
	("update_hatch_event" event(crew out) place(gunner))
	("zpu_params" gunner(gunner2) zpu_mgun(mgun) anim(into_hatch_high) pose(seat_gunner_stand))
}
{"fv103_spartan"
	("fv432_sound")
}
{"fv107scimitar_mk2"
	{on spawn		
		{add_view	 	"flash_gun_big"	"flashbarrel5"		"Foresight5"}
    }
	("fv107_sound")
	{on fire "mgun" overload
		{view start "flashbarrel5"}
		("cw_check_shooting" weap_id(mgun))
	}
    ("autocannon")
	("25-50mm_gilza" fxshell(fxshell))
}
{"fennek"
	("fennek_sound")
	("zpu_params" gunner(gunner2) zpu_mgun(mgun) anim(into_hatch_btr90) pose(seat_gunner_stand))
	{on "uprise_anten"	
	       {if not flag "radar_up" 
		{ani_play "close_anten" -0.3}	
		{set "radar_up" 1}
	        }
	}
	{on "lower_anten"	
	       {if flag "radar_up" 
		{ani_play "close_anten" 0.3}
		{set "radar_up" 0}
	       }
	}
	{on move on	{kill_delay "anten"}			{call "lower_anten"}}
	{on move off	{delay 2 "anten"			{call "uprise_anten"}}}
	{on operatable off	{kill_delay "anten"}			{call "lower_anten"}}
	{on operatable on	{call "uprise_anten"}}
}