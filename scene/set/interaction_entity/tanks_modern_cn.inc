{"zbl08"
	("zsl92_sound")
    ("autocannon")
	("25-50mm_gilza" fxshell(fxshell))
	("custom_sh_multi_launcher" weapon(gun2) foresight(foresight5) tail(tail_) shooter(ShooterR_))
	("smokegun_nospread" smokegun(mgun18))
	("smokegun_nospread" smokegun(mgun19))
}
{"zsl-92_series"
	("zsl92_sound")
}
{"zsl-92a"
    ("autocannon")
	("25-50mm_gilza" fxshell(fxshell))
}
{"zsl-92b"
    ("autocannon")
	("25-50mm_gilza" fxshell(fxshell))
	("atgm_single_launcher" weapon(gun2) foresight(foresight5) tail(tail))
	("smokegun_nospread" smokegun(mgun18))
	("smokegun_nospread" smokegun(mgun19))
}
{"zbd-86"
	("bmp1_sound")
    	("73mm_2a28_grom")
	("atgm_single_launcher" weapon(gun2) foresight(foresight2) tail(tail))
}
{"zbd86a"
	("bmp1_sound")
    ("autocannon")
	("25-50mm_gilza" fxshell(fxshell))
	("atgm_single_launcher" weapon(gun2) foresight(foresight5) tail(tail))
	("smokegun_nospread" smokegun(mgun18))
	("smokegun_nospread" smokegun(mgun19))
}
{"aft-9"
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
		{if name "00"	{delay 0.1 {spawn "hj9_missile_carrier" "shooter00"   x}{spawn "startsmoke" "shooter00" x}{spawn "startsmoke" "tail_00" x}}
		else name "01"	{delay 0.1 {spawn "hj9_missile_carrier" "shooter01"   x}{spawn "startsmoke" "shooter01" x}{spawn "startsmoke" "tail_01" x}}
		else name "02"	{delay 0.1 {spawn "hj9_missile_carrier" "shooter02"   x}{spawn "startsmoke" "shooter02" x}{spawn "startsmoke" "tail_02" x}}
		else name "03"	{delay 0.1 {spawn "hj9_missile_carrier" "shooter03"   x}{spawn "startsmoke" "shooter03" x}{spawn "startsmoke" "tail_03" x}}
		}
	}
}
{"zbd04a"
	("zbd04_sound")
	{on spawn		
		{add_view 	"flash_zenit"	"flashbarrel2"		"foresight6"}
    	}
	("100mm_2a70")
	("90-105mm_gilza")
	("30mm_2a42_gun1")
	{on "gunner_hatch_open" overload}
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
}
{"aft-10"
	("zbd04_sound")
	("custom_sh_multi_launcher" weapon(gun2) foresight(foresight5) tail(tail) shooter(shooter))
	("radar_params" triplex(additional_triplex) visor(visor3) anim_rotate(none) marker(antirad_generator_rus))
}
{"plz-05"
	{on spawn
		{add_view "zenit_gilz"		"shell_m1"	"fxshell"}	
    	}
	("zbd04_sound")
    	("135-180mm_sph_gun")
	{on fire "mgun" 
		{view start "shell_m1"}
		{kill_delay "shell_m1"}
		{delay 0.2 "shell_m1"
			{view pause "shell_m1"}
		}
	}
	("zpu_params" gunner(gunner2) zpu_mgun(mgun) anim(into_hatch_high) pose(seat_gunner_stand))
	("135-180mm_gilza_forward")

}
{"plz-07a"
	("zbd04_sound")
    ("135-180mm_sph_gun")
}
{"pgz-09"
	{on spawn		
		{add_view "autocannon_gilz"	"gilz00" "fxshell00"}
		{add_view "autocannon_gilz"	"gilz01" "fxshell01"}
	}
	("zbd04_sound")
	("radar_lifting90_params" triplex(additional_triplex) visor(visor3) anim_rotate(radar_loop) anim_lift(radar_lift) marker(antirad_generator_rus))
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
		("cw_check_shooting" weap_id(gun))
	}
	{on "cut_parts"
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
		     {tear "piece_large_steel" bone "rlsfront_Turr"
			{impulse dir 0.5 1}
			{if rand 0.2 {add_view "smoke_dead_norm" "smoke" "basis"}
			else {add_view "smoke_black" "smoke" "basis"}}
			{view start "smoke"}
			{delay_effect 30 5 "pause"}
		     }
		}
		{if rand 0.5
			{bone cut "support_foot"}
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
{"pgz-04"
	("zbd04_sound")
	("small_multibarrel_gun" shooter(shooter) fxshell(fxshell))
	("radar_lifting90_params" triplex(additional_triplex1) visor(visor4) anim_rotate(radar_loop) anim_lift(radar_lift) marker(antirad_generator_rus))
	("custom_multi_launcher"	weapon(gun2) tail(tail) shooter(R_shooter) missile(fn6a_ammo))
}
{"hq_7b"
	("zsl92_sound")
	("radar_params" triplex(commander_triplex) visor(visor1) anim_rotate(radar_loop) marker(antirad_generator_rus))
	("custom_multi_launcher"	weapon(gun2) tail(tail) shooter(shooter) missile(hq7b))
	{on "uprise_stand"	
	       {if not flag "started" 
		{ani_play "stand" -0.3}	
		{set "started" 1}
	        }
	}
	{on "lower_stand"	
	       {if flag "started" 
		{ani_play "stand" 0.3}
		{set "started" 0}
	       }
	}
	{on move on	{kill_delay "stand"}			{call "uprise_stand"}}
	{on move off	{delay 2 "stand"			{call "lower_stand"}}}
	{on operatable off	{kill_delay "anten"}			{call "uprise_stand"}}
	{on operatable on	{call "lower_stand"}}
	
	{on "update_gun23" overload
		{if work "gun2"
		      {if work "stabilizer"
			    {if work "gunner_panel"
			  	  {if not tagged "no_power"
					{if not tagged "radar_off"
						  {weapon_work "gun2" 1}
					   else {weapon_work "gun2" 0}}
				  else {weapon_work "gun2" 0}}
				else {weapon_work "gun2" 0}}
		      else {weapon_work "gun2" 0}}
		else {weapon_work "gun2" 0}}
	}
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
}
{"ztz-96a"
	{on spawn
		{add_view		"exhaust_dark"	"engine_steam1" 		"FXsmoke1"}			
    	}
	("ztz_sound")
	("2a46_type_gun")
;	("zpu_params" gunner(gunner2) zpu_mgun(mgun) anim(into_hatch_common) pose(t72_gunner2))
	{on "update_hatch_on_spawn"
		("update_hatch" wind(true) place(commander))
	}
	("update_hatch_event" event(operatable on) place(commander))
	("update_hatch_event" event(operatable off) place(commander))
	("update_hatch_event" event(crew in) place(commander))
	("update_hatch_event" event(crew out) place(commander))
	("zpu_params" gunner(commander) zpu_mgun(mgun) anim(into_hatch_common) pose(t72_zpy))

}

{"ztz_99"
	{on spawn
		{add_view		"exhaust_dark"	"engine_steam1" 		"FXsmoke1"}			
		{add_view		"exhaust_dark"	"engine_steam1" 		"FXsmoke2"}		
		{add_view	"shtora_work"	"ldsw"	"foresight4"}
    }
	("ztz_sound")
	("2a46_type_gun")
;	("zpu_params" gunner(gunner2) zpu_mgun(mgun) anim(into_hatch_common) pose(t72_gunner2))
	{on "update_hatch_on_spawn"
		("update_hatch" wind(true) place(commander))
	}
	("update_hatch_event" event(operatable on) place(commander))
	("update_hatch_event" event(operatable off) place(commander))
	("update_hatch_event" event(crew in) place(commander))
	("update_hatch_event" event(crew out) place(commander))
	("zpu_params" gunner(commander) zpu_mgun(mgun) anim(into_hatch_common) pose(t72_zpy))

	(define "ldsw_work"
		{if rand 0.25
		    ("cwps3_stop" country(rus) type(laser))
		    ("cwps3_stop" country(usa) type(laser))
		    ("cwps3_stop" country(rus) type(other))
		    ("cwps3_stop" country(usa) type(other))
			{spawn "proj_point_usa_laser"  "basis" x
				{impulse up 0 10 rnd_dir 20 com}
				{gravity 0.5}
				 {kill_delay "normal_hide" }
			}
			{spawn "proj_point_rus_laser"  "basis" x
				{impulse up 0 10 rnd_dir 20 com}
				{gravity 0.5}
				 {kill_delay "normal_hide" }
			}
			{spawn "proj_point_usa_other"  "basis" x
				{impulse up 0 10 rnd_dir 20 com}
				{gravity 0.5}
				 {kill_delay "normal_hide" }
			}
			{spawn "proj_point_rus_other"  "basis" x
				{impulse up 0 10 rnd_dir 20 com}
				{gravity 0.5}
				 {kill_delay "normal_hide" }
			}
		}
	)
	{on fire "mgun1" overload
;		("ldsw_work")	;should work on client side
		{view show "ldsw"}
		{view start "ldsw"}
		{delay 0.3
			{view hide "ldsw"}
		}
		("cw_check_shooting" weap_id(mgun1))
	}	
}
{"ztq-15"
	{on spawn		
		{add_view "zenit_gilz"		"shells_we"	"fxshell"}
	}
	("ztz_sound")
	{on "_explosion"
		{tear "piece_medium_steel" bone "part1" {impulse up 5 rnd_dir 2}}
	}
	{on break
		{if volume "ammo_storage_main"
				{tear "piece_medium_steel" bone "part1" {impulse up 5 rnd_dir 2}}
		}
	}
	{on fire "mgun1"
		{view show	"shells_we"}
		{view start	"shells_we"}
		{delay 0.2
			{view pause	"shells_we"}
		}
	}
	("auto_gren_launcher" mgun(mgun2))
	("m68_type_gun")	
}
{"hq-16b_radar"
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
	{on "explosion"
		{components "cabin" destroy}
		{components "bodyback" destroy}
	}
}

{"hq-16b_launcher"
	("sampt_sound")
	("custom_sh_vertlauncher_ej" weapon(gun2) tail(tail) foresight(foresight1) shooter(shooter) tailfx(proj_jet_sam))
	{on "_explosion"
		{tear "piece_medium_steel" bone "launcher"
			{impulse up 4 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 6 no_position}
			{delay_effect 20 5 "stop"}
		}
	}
	{on "explosion"
		{components "cabin" destroy}
		{components "bodyback" destroy}
	}

}

{"dong_feng_15b"
	{on spawn
		{Volumes "ammo_storage_main" enable contact bullet blast}
		{set "radar_up" 0}
	}
	("9k72_sound")
    {on fire "gun" 
      	{spawn "dust_shot_big_2" "basis"}
      	{spawn "dust_shot_big_2" "FXtraceL4"}
      	{spawn "dust_shot_big_2" "FXtraceR4"}
      	{spawn "startsmoke_otrk" "turret"}
		{spawn "df15b_missilelaunch" "turret" x
			{ani_play "start"}
			{add_view	"rocket_smokebig_short"	"start"	"fxtail"}
			{view start "start"}
			{view show "start"}
			{delay 2.5 {delete}}
		}
		
		{Volumes "ammo_storage_main" disable contact bullet blast}
		{delay 300 {Volumes "ammo_storage_main" enable contact bullet blast}}

		
	}
	{on break_armor
		{if volume "cabin" {components "cabin" break} 
		}
	}
	{on pierce
		{if component "ammo_storage_main"
			{spawn "ex_anti_size5" "Gun_rot"}
			{spawn "iskander_ammo" "basis" x {stuff_detonate}}
			{call "_explosion"}
		}
	}
	{on bullet_hit
		(define "check_break_glass"
		     else volume "glass%0"
			{volumes "glass%0" disable bullet contact blast}
	 		{spawn "glass_hit2" "glass%0" x}
	 		{delay 0.1
			 	{bone cut "glass%0"}
	 		}
		)
		{if stuff "radar_ammo"
		else stuff "laser_ammo"
		else stuff "rus_IR_ff_beam ammo"
		else stuff "usa_IR_ff_beam ammo"
		else stuff "IR_ff_ammo"
		("check_break_glass" args 1)
		("check_break_glass" args 2)
		("check_break_glass" args 3)
		("check_break_glass" args 4)
		("check_break_glass" args 5)
		("check_break_glass" args 6)
		("check_break_glass" args 7)
		}
	}
	{on break 
		{if component "cabin"  {spawn "tank_die_particle" "cabin"}
		else component "telo1" {spawn "tank_die_particle" "telo1"}
		else component "telo2" {spawn "tank_die_particle" "telo2"}
		else component "body"
			{Volumes "ammo_storage_main" enable contact_ground}
			{tear "piece_medium_steel" bone "launch_table"
				{impulse up 4 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 6 no_position}
				{delay_effect 20 5 "stop"}
			}
		}
	}
	{on repair 
		{if component "cabin"
		else component "telo1"
		else component "telo2"
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
}
{"zlt_11"
	{on spawn		
		{add_view "flash_gun_big" "flashbarrel2" "Foresight1"}	
		{add_view "zenit_gilz"		"shells_we"	"fxshell"}
	}
	("zpu_params" gunner(gunner2) zpu_mgun(mgun2) anim(into_hatch_high) pose(t72_zpy))
	("zsl92_sound")
	{on fire "mgun2"
		{view show	"shells_we"}
		{view start	"shells_we"}
		{delay 0.2
			{view pause	"shells_we"}
		}
	}
	("m68_type_gun")	
}
{"ptl-02"
	{on spawn		
		{add_view "flash_gun_big" "flashbarrel2" "Foresight1"}	
		{add_view "zenit_gilz"		"shells_we"	"fxshell"}
	}
	("zpu_params" gunner(gunner2) zpu_mgun(mgun2) anim(into_hatch_high) pose(t72_zpy))
	("zsl92_sound")
	{on fire "mgun2"
		{view show	"shells_we"}
		{view start	"shells_we"}
		{delay 0.2
			{view pause	"shells_we"}
		}
	}
	("m68_type_gun")	
}
{"pll-05"
	{on spawn		
		{add_view "flash_gun_big" "flashbarrel2" "Foresight1"}	
		{add_view "zenit_gilz"		"shells_we"	"fxshell"}
	}
	("zpu_params" gunner(gunner2) zpu_mgun(mgun2) anim(into_hatch_high) pose(t72_zpy))
	("zsl92_sound")
	{on fire "mgun2"
		{view show	"shells_we"}
		{view start	"shells_we"}
		{delay 0.2
			{view pause	"shells_we"}
		}
	}
}
{"llq305_radar"
	("mercedes_sound")
	{on spawn {delay 5 {call "update_antiradar"}}}
	{on crew out
		{if crew_in_place "driver" {tags add "arabel_moves"}{call "update_antiradar"}}
		{if not crew_in_place "commander" {call "update_antiradar"}}
	}
	{on crew in
		{if crew_in_place "commander" {delay 6 {call "update_antiradar"}}}
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
	{on "_explosion"
		{tear "piece_medium_steel" bone "radar"
			{impulse up 4 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 6 no_position}
			{delay_effect 20 5 "stop"}
		}
	}
}
{"ee9_cascavel"
	{on spawn		
		{add_view "flash_gun_big" "flashbarrel2" "Foresight1"}	
	}
	("ee9_cascavel_sound")
	("90-105mm_gun_with_cm")
	("no_gilza_ejection")
}
{"zulfiqar-3"
	{on spawn
		{add_view		"exhaust_dark"	"engine_steam1" 		"FXsmoke1"}			
		{add_view		"exhaust_dark"	"engine_steam1" 		"FXsmoke2"}			
		{add_view	 	"flash_gun_big"	"shooter_00"		"shooter_00"}
		{add_view	 	"flash_gun_big"	"shooter_01"		"shooter_01"}
    }
	("zulfiqar_sound")
    ("2a46_type_gun")	;
	{on fire "mgun" overload
		(define "fire_barrel"
			name "%0"
				{view start "shooter_%0"}
				{spawn "mgun_smoke" "shooter_%0" x}
		)
		{if ("fire_barrel" args 00)
		 else ("fire_barrel" args 01)
		}
		("cw_check_shooting" weap_id(mgun))
	}
}