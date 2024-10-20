	(define "link_damage_sound_rus"
		{link_sound "engine1_damage"	"vehicle/helicopter_damage/rus/engine1"}
		{link_sound "engine2_damage"	"vehicle/helicopter_damage/rus/engine2"}
		{link_sound "fuel_tank_damage"	"vehicle/helicopter_damage/rus/fuel_tank"}
		{link_sound "main_reductor_damage"	"vehicle/helicopter_damage/rus/main_reductor"}
		{link_sound "propeller_damage"	"vehicle/helicopter_damage/rus/propeller"}
		{link_sound "tail_shaft_damage"	"vehicle/helicopter_damage/rus/tail_shaft"}
		{link_sound "apu_damage"	"vehicle/helicopter_damage/rus/apu"}
		{link_sound "ecm_damage"	"vehicle/helicopter_damage/rus/ecm"}
		{link_sound "electronics_damage"	"vehicle/helicopter_damage/rus/electronics"}
		{link_sound "gun_damage"	"vehicle/helicopter_damage/rus/gun"}
		{link_sound "hydrosystem_damage"	"vehicle/helicopter_damage/rus/hydrosystem"}
		{link_sound "ols_damage"	"vehicle/helicopter_damage/rus/ols"}
		{link_sound "prpnk_damage"	"vehicle/helicopter_damage/rus/prpnk"}
		{link_sound "radar_damage"	"vehicle/helicopter_damage/rus/radar"}
		{link_sound "spo"	"vehicle/helicopter_damage/rus/spo"}
	)
	(define "link_damage_sound_usa"
		{link_sound "engine1_damage"	"vehicle/helicopter_damage/usa/engine1"}
		{link_sound "engine2_damage"	"vehicle/helicopter_damage/usa/engine2"}
		{link_sound "ecm_damage"	"vehicle/helicopter_damage/usa/ecm"}
		{link_sound "electronics_damage"	"vehicle/helicopter_damage/usa/electronics"}
		{link_sound "hydrosystem_damage"	"vehicle/helicopter_damage/usa/hydrosystem"}
		{link_sound "ols_damage"	"vehicle/helicopter_damage/usa/ols"}
		{link_sound "radar_damage"	"vehicle/helicopter_damage/usa/radar"}
		{link_sound "spo"	"vehicle/helicopter_damage/usa/spo"}
	)
	(define "stop_damage_sound"
		{stop_sound "engine1_damage"	}
		{stop_sound "engine2_damage"	}
		{stop_sound "fuel_tank_damage"	}
		{stop_sound "main_reductor_damage"	}
		{stop_sound "propeller_damage"	}
		{stop_sound "tail_shaft_damage"	}
		{stop_sound "apu_damage"	}
		{stop_sound "ecm_damage"	}
		{stop_sound "electronics_damage"	}
		{stop_sound "gun_damage"	}
		{stop_sound "hydrosystem_damage"	}
		{stop_sound "ols_damage"	}
		{stop_sound "prpnk_damage"	}
		{stop_sound "radar_damage"	}
		{stop_sound "spo"	}
	)
{"Helicopter_M"
;	{friction 0.2}
;	{restitution 0.01}
	{on spawn 
		{link_sound "fall"				"vehicle/airborne/fw_deep"			}
		{call "link_flare_fx"}

		{add_view	"exhaust_dark_big"	"engine_exhaust"		"FXsmoke1"	}
		{add_view	"exhaust_dark_big"	"engine_exhaust" 		"FXsmoke2"	}
		{add_view	"exhaust_dark_big"	"engine_exhaust"		"FXsmoke3"	}
		{add_view	"exhaust_dark_big"	"engine_exhaust" 		"FXsmoke4"	}
		{add_view	"exhaust_dark_big"	"engine_exhaust"		"FXsmoke5"	}
		{add_view	"exhaust_dark_big"	"engine_exhaust" 		"FXsmoke6"	}
		{add_view	"exhaust_dark_big"	"engine_exhaust"		"FXsmoke7"	}
		{add_view	"exhaust_dark_big"	"engine_exhaust" 		"FXsmoke8"	}
		{add_view 	"smoke_black" 		"engine1_smoke" 		"FXsmoke1"}
		{add_view 	"smoke_black" 		"engine2_smoke" 		"FXsmoke2"}
		{call "init_gun"}
		{add_view	"rok_tail"		"flare_left"			"flare1_shooter"}
		{add_view	"rok_tail"		"flare_right"			"flare2_shooter"}
		{add_view	"_chaff_fly"	"chaff_left"			"chaff1_shooter"}
		{add_view	"_chaff_fly"	"chaff_right"			"chaff2_shooter"}

		{call "update_power"}
		{components "flare_fly_l" break}
		{components "flare_fly_r" break}
		{components "chaff_fly_l" break}
		{components "chaff_fly_r" break}
		{if tagged  "cwhs_deccelerate_me" {call "cwhs_change_speed"}
		else tagged  "cwhs_accelerate_me" {call "cwhs_change_speed"}}
		("spawn")
		;added until good air mechanics will exist
		;{tags add "cw_autotakeoff_activated"}
		{tags remove "time_to_escape_after_hit"}
	}
	{on "link_flare_fx"
		{link_sound "flare"	"weapon/shot/reactive/Flare"}
	}
	{on "add_movement_sound" 
		{link_sound "fly"			"vehicle/helicopter/engine"			}
		{link_sound "engine_start"		"vehicle/helicopter/en_start"				}
		{link_sound "engine_work"		"vehicle/helicopter/en_work"				}
		{link_sound "engine_stop"		"vehicle/helicopter/en_stop"				}
	}
	{on "cwsh_switch_hatch" overload
	  {if chassis "airborne"
		{if tagged "heli_in_flight" 
			{if tagged "cwhs_hovering"
				{tags add "cwhs_accelerate_me"}
				{components "zpu_indicator" repair}
				{tags remove "cwhs_hovering"}
				{tags remove "cwhs_deccelerate_me"}
			else tagged "cwhs_deccelerate_me"
				{tags add "cwhs_accelerate_me"}
				{components "zpu_indicator" repair}
				{tags remove "cwhs_deccelerate_me"}
			else 
				{tags add "cwhs_deccelerate_me"}
				{components "zpu_indicator" break}
				{tags remove "cwhs_accelerate_me"}
			}
			{call "cwhs_change_speed"}
		else
			{if tagged "cwhs_hovering"
				{tags remove "cwhs_hovering"}
			else
				{tags add "cwhs_hovering"}
			}
		}
	  else chassis "helicopter"
		{call "paradrop"}
	  }
	}
	{on "hover" overload
		{if not tagged "hovering"
			{tags add "hovering"}
			{ani_play "cwhs_nose_down" -1}
			{ani_play "cwhs_nose_up" 1}
			{if velocity 30
				{impulse forward 10.1 com} {constrain_velocity 40} ; гашение скорости
				{delay 0.5 {constrain_velocity 35}}
				{delay 1.0 {constrain_velocity 25}}
				{delay 1.5 {constrain_velocity 15}}
				{delay 2.0 {constrain_velocity 10}}
				{delay 2.5 {constrain_velocity 5}}
			}
			{delay 3.0 
				{physics_work 0} ; сброс энергии
				{physics_work 1}
				{chassis_work 0}
				{gravity 0}
				{ani_play "cwhs_hover" 2 loop}
			}
		else  ; восстановление шасси
			{chassis_work 1}
			{physics_work 1}
			{tags remove "hovering"}
			{ani_play "cwhs_nose_down" 1}
			{ani_play "cwhs_nose_up" -1}
		}
	}
	
	{on "land" overload
		{call "hover"}
		{delay 5
			{tags add "go_land"}
			{ani_play "wheels" -0.3}
			{delay 0.1 
				{call "go_land"}
				{physics_work 1}
			}
		}
	}
	{on "up" overload
		{if not tagged "hovering"
			{call "hover"}
		}
		{delay 2
			{tags add "go_up"}
			{delay 0.1 
				{call "go_up"}
				{physics_work 1}
			}
		}
		{delay 4 {ani_play "wheels" 0.3}}
	}
	{on "land_and_emit_pass" overload
		{tags add "land_and_emit_pass"}
		{call "land"}
	}
	{on "hover_and_rope" overload
		{tags add "hover_and_rope"}
		{call "land"}
	}
	
	{on "go_land" overload
		{if tagged "go_land"
			{physics_work 1}
			{impulse up -2.1 com}
			{delay 0.01 
				{physics_work 0} 
				{call "go_land"}
			}
			{if not altitude 16 and tagged "hover_and_rope"
				{tags remove "go_land"}
				{call "specability"}
				{call "ropes_down"}
				{delay 1.0
					{call "passengers_off"} 
					{tags remove "hover_and_rope"}
				}
			}
			{if not altitude 2
				{delay 3.0
					{tags remove "go_land"}
					{tags remove "hovering"}
					{ani_stop "cwhs_hover"}
					{if tagged "land_and_emit_pass" 
						{call "passengers_off"} 
						{tags remove "land_and_emit_pass"}
					}
				}
			}
		else
			{physics_work 0}
			{physics_work 1}
			{chassis_work 1}
		}
	}
	{on "go_up" overload
		{if tagged "go_up"
			{physics_work 1}
			{impulse up 2.1 com}
			{delay 0.01 
				{physics_work 0} 
				{call "go_up"}
			}
			{if altitude 16
				{tags remove "go_up"}
			}
		else
			{physics_work 0}
			{physics_work 1}
			{chassis_work 1}
		}
	}
	{on "cwhs_change_speed"
		{kill_delay "cwhs_tags"}
		{delay 2 "cwhs_tags"
			{tags remove "cwhs_speed_60"} {tags remove "cwhs_speed_55"} {tags remove "cwhs_speed_50"}
			{tags remove "cwhs_speed_45"} {tags remove "cwhs_speed_40"} {tags remove "cwhs_speed_35"}
			{tags remove "cwhs_speed_30"} {tags remove "cwhs_speed_20"} {tags remove "cwhs_speed_10"}
		}
	}
	{on "takeoff" overload
		{tags add "cwfs_set_fuel"}
		{tags remove "cwhs_landing"}
		{tags remove "go_land"}
		{if tagged "heli_in_flight" 
			{if user_control {call "cwsh_switch_hatch"}}
		else 
			{if tagged "cwhs_hovering" {tags remove "cwhs_hovering"} {call "max_speed"}
				{delay 0.1 {components "hover" break}  {components "hover" repair} {tags add "cwhs_speed_1"}}
			else	{call "max_speed"}
				{delay 0.1 {components "hover" break}  {components "hover" repair}}
			}
		}
		{if not dead
			{ani_play "wheels" 0.2}
			{ani_play "basis" 0.4}
			{play_sound "fly" 1}
		}
		{call "check_moveability"}
		{call "update_weaponry"}
		{tags add "heli_in_flight"}
		{ani_play "cwhs_hover" 2 loop}
		{call "update_lights"}
	}
	{on "takeoff_load" overload
		{ani_wind "wheels" end}
		{ani_wind "basis" end}
		{ani_play "cwhs_hover" 2 loop}
		{call "check_moveability"}
	}
	{on "landing" overload
		{ani_play "wheels" -0.2}
		{ani_play "basis" -2}
		{stop_sound "fly"}
		{ani_stop "cwhs_hover"}
		{tags add "cwhs_landing"}
	}
	{on "landing_load" overload
		{call "update_lights"}
		{ani_stop "cwhs_hover"}
		{ani_play "wheels" -2 callback}
		{ani_play "basis" -4}
		{stop_sound "fly"}
	}
	{on engine on overload
		{call "engine_on"}
		{call "check_altitude"}
		{delay 1
			{view start "engine_steam1"}
			{view start "engine_steam2"}
        }
	}
	{on animation_end "engine_start" overload
		{ani_play "engine_work" loop}
		{play_sound "engine_work" 1}
		{delay 0.3 "start_check_altitude" {call "check_altitude"}}
	}
	{on "check_altitude"
		{if not altitude 30 {tags add "low_altitude"}
			else {tags remove "low_altitude"}
		}
		{if has_order "withdraw" 
			{kill_delay "takeoff_again"}
			{delay 15 "takeoff_again" {tags remove "cw_autotakeoff_activated"}}
		}
		{if flag "engine_started"
			{if altitude 10
			else altitude -3
				{spawn "heli_wind_dummy" {impulse up -35 com}}
				{delay 0.2 {spawn "heli_wind_dummy" {impulse up -35 com}}}
				{delay 0.4 {spawn "heli_wind_dummy" {impulse up -35 com}}}
			else 
				{impulse up 0.5 forward 5}
				{call "fall"}
				{call "collide"}
				{call "mp_destroy"}
				{delay 0.05 {constrain_velocity 40}}
				{delay 0.1 {constrain_velocity 40}}
				{delay 0.2 {constrain_velocity 40}}
				{delay 0.3 {constrain_velocity 40}}
				{delay 0.4 {constrain_velocity 40}}
			}
	      }
			{kill_delay "check_altitude"}
			{if altitude 15
				{delay 1.5 "check_altitude"
					{call "check_altitude"}
				}
			else
				{delay 0.5 "check_altitude"
					{call "check_altitude"}
				}
			}
		  {if tagged "cwhs_speed_changed"
			  {if tagged "cwhs_accelerate_me"
				  {if not tagged "cwhs_nose_down"
					{ani_play "cwhs_nose_down"}
					{tags add "cwhs_nose_down"}
					{tags remove "cwhs_nose_up"}
				  }
			  else tagged "cwhs_deccelerate_me"
				{if not tagged "cwhs_nose_up"
					{ani_play "cwhs_nose_up"}
					{tags add "cwhs_nose_up"}
					{tags remove "cwhs_nose_down"}
				}
			  }
			  {tags remove "cwhs_speed_changed"}
		  else tagged "cwhs_landing"
			{if tagged "cwhs_nose_up"
				{ani_play "cwhs_nose_up" -1}
				{tags remove "cwhs_nose_down"}
				{tags remove "cwhs_nose_up"}
			else tagged "cwhs_nose_down"
				{ani_play "cwhs_nose_down" -1}
				{tags remove "cwhs_nose_down"}
				{tags remove "cwhs_nose_up"}
			}
		  else velocity 20
		   {if tagged "heli_in_flight"
			{if not tagged "cwhs_nose_down"
				{ani_play "cwhs_nose_down"}
				{tags add "cwhs_nose_down"}
				{tags remove "cwhs_nose_up"}
			}
		   }
		  else tagged "cwhs_nose_down"
		  	{if not velocity 20 
				{ani_play "cwhs_nose_down" -1}
				{tags remove "cwhs_nose_down"}
				{tags remove "cwhs_nose_up"}
			}
		  else tagged "cwhs_nose_up"
		  	{if not velocity 20 
				{ani_play "cwhs_nose_up" -1}
				{tags remove "cwhs_nose_down"}
				{tags remove "cwhs_nose_up"}
			}
		 }
	}
	{on engine off overload 
		{if tagged "heli_in_flight"{tags add "cwfs_set_fuel"}}
		{view pause "engine_steam1"}
		{view pause "engine_steam2"}
		{tags remove "cwhs_landing"}
		{tags remove "cwhs_deccelerate_me"}
		{tags remove "cwhs_accelerate_me"}
		{call "engine_stop"}
		{call "update_power"}
		{if not work "wheel_back"
		     {if rand 0.2
			{components "engine" break}
			{components "engine1" break}
			{components "engine2" break}
		     }
		}
		{if not work "retract_wheelR"
		     {if rand 0.5
				{components "engine" break}
				{components "engine1" break}
				{components "engine2" break}
		     }
		}
		{if not work "retract_wheelL"
		     {if rand 0.5
				{components "engine" break}
				{components "engine1" break}
				{components "engine2" break}
		     }
		}
		{call "check_moveability"}
		{tags remove "heli_in_flight"}
		{kill_delay "delayed_fall_long"}
		{kill_delay "delayed_fall"}
	}
	{on "engine_on" overload
		{if not flag "engine_started"
			{call "update_power"}
			{set "engine_started" 1}
			{tags add "engine_started"}
			{play_sound "engine_start"}
			{ani_play "engine_start" callback}
			{view start "engine_exhaust"}
			{delay 1
				{view pause "engine_exhaust"}
			}
		}
	}
	{on "update_moveable" overload
		{if not chassis "airborne"
			{if not chassis "helicopter"
				{inherited}
			}
		}
	}

	{on "engine_stop" overload
		{kill_delay "engine_stopped"}
		{if flag "engine_started"
		{stop_sound "fly"}
		{kill_delay "start_check_altitude"}
			{kill_delay "check_altitude"}
		 {delay 15
		  {if not velocity 1 and not tagged "hovering"
			{set "engine_started" 0}
			{tags remove "engine_started"}
			{ani_stop "engine_start"}
			{ani_stop "engine_work"}
			{play_sound "engine_stop"}
			{ani_play "engine_stop" 0.1}
			{stop_sound "engine_start"}
			{stop_sound "engine_work"}
		  }
		 }
		}
	}

	{on turn on	{call "check_moveability"}}
	{on turn off	{call "check_moveability"}}
	{on move on	{call "check_moveability"}}
	{on move off	{call "check_moveability"}}
	{on accelerate on	{call "check_moveability"}}
	{on accelerate off	{call "check_moveability"}}
	{on brake on	{call "check_moveability"}}
	{on brake off	{call "check_moveability"}}



;{on "secondary_damage"
;	{if stuff "AA_missile" 
;	else stuff "fg" 
;		{fragments c4 0.5 r0 1.4 r1 1.5 position}
;	else stuff  "hmgun"
;		{fragments c4 0.5 r0 0.1 r1 0.2 position}
;	else stuff "rok"
;		{blastwave c4 3 r0 0.8 r1 0.9 position}
;		{fragments c4 0.5 r0 1.0 r1 1.1 position}
;	else stuff "ptrk"
;		{blastwave c4 3 r0 0.8 r1 0.9 position}
;		{fragments c4 0.5 r0 1.0 r1 1.1 position}
;	else stuff "cm"
;		{blastwave c4 3 r0 0.7 r1 0.8 position}
;		{fragments c4 0.5 r0 0.9 r1 1.0 position}
;	else stuff "rocketlauncher"
;		{blastwave c4 3 r0 0.7 r1 0.8 position}
;		{fragments c4 0.5 r0 0.9 r1 1.0 position}
;	else stuff  "autocannon_small"
;		{fragments c4 0.5 r0 0.3 r1 0.4 position}
;	}
;}

{on crew out
	{if not tagged "destroyed"
	  {if chassis "airborne"
		  {delay 0.2
			{if not crew_in_place "driver"
			  {if not crew_in_place "gunner"
				{if not crew_in_place "commander"
				   {if not crew_in_place "driver1"
					 {call "fall"}
				   }
				}
			  }
			}
		  }	
	  }
	}
}


;//////////////////////VRT System by Pheonix 1.0\\\\\\\\\\\\\\\\\\

{on bullet_hit overload
;=============part of projectile system by Timosh=============
		{if stuff "rus_radar_beam ammo"
			{tags add "rus_target_radar"}
			{delay 0.7
				{tags remove "rus_target_radar"}
			}
		else stuff "usa_radar_beam ammo"
			{tags add "usa_target_radar"}
			{delay 0.7
				{tags remove "usa_target_radar"}
			}
		else stuff "rus_IR_ff_beam ammo"
			{tags add "rus_target_IR_ff"}
			{delay 10
				{tags remove "rus_target_IR_ff"}
			}
		else stuff "usa_IR_ff_beam ammo"
			{tags add "usa_target_IR_ff"}
			{delay 10
				{tags remove "usa_target_IR_ff"}
			}
		}
		{if stuff "proj_pointer"
			{call "check_proj_type"}
			else volume "LampL" {if work "LampL" {spawn "glass_hit"} {components "LampL" break}}
			else  volume "LampR" {if work "LampR" {spawn "glass_hit"} {components "LampR" break}}
			else  volume "LampT" {if work "LampT" {spawn "glass_hit"} {components "LampT" break}}
			else  volume "LampT1" {if work "LampT1" {spawn "glass_hit"} {components "LampT1" break}}
			else  volume "LampT2" {if work "LampT2" {spawn "glass_hit"} {components "LampT2" break}}
		}
		{if stuff "hesh_type_dmg" {spawn "cw_cumulative_frestrict" inv_normal}
		else stuff "cm_type_dmg cm" {spawn "rpg_restrictor" inv_normal}}
;==========================
		{if volume "glass" {if not stuff "proj_pointer" {spawn "glass_hit"}}
		else  volume "glass1" {if not stuff "proj_pointer" {spawn "glass_hit"}}
		else  volume "glass2" {if not stuff "proj_pointer" {spawn "glass_hit"}}
		else  volume "glass3" {if not stuff "proj_pointer" {spawn "glass_hit"}}
		else  volume "glass4" {if not stuff "proj_pointer" {spawn "glass_hit"}}
		else  volume "glass5" {if not stuff "proj_pointer" {spawn "glass_hit"}}
		else  volume "glass6" {if not stuff "proj_pointer" {spawn "glass_hit"}}
		else  volume "cabin" {if not stuff "proj_pointer" {spawn "glass_hit"}}
		else
			{if stuff "proj_pointer"
			else stuff "bullet"
				{spawn "metal_hit_bul"}
			else stuff "mortar"
				{spawn "metal_hit_br"}
			else stuff "zenite"
				{spawn "metal_hit_bul"}
				{spawn "ex_air_sm"}
			else stuff "size4"
				{spawn "metal_hit_fg_big"}
			else stuff "shell small fg"
				{spawn "metal_hit_fg"}
			else stuff "shell small"
				{spawn "metal_hit_br_small"}
			else stuff "shell fg"
				{spawn "metal_hit_fg"}
			else stuff "shell"
				{spawn "metal_hit_br"}
			}
		}
	{call "update_weaponry"}
}; end of bullet_hit
;//===========================================

	{on pierce overload
	     {if not stuff "proj_pointer"
		{if stuff "bullet"
			{spawn "part_gun_big"}
		 else 
			{spawn "aero_die_particle"}
		}
		{if stuff "ic hmgun"
			{fire radius 0.5 time 0.3 heating 30}
		else stuff "ic autocannon_small"
			{fire radius 0.5 time 0.3 heating 60}
		}
;		{if component "body" {call "secondary_damage"}
;		else component "engine" {call "secondary_damage"}
;		else component "engine1" {call "secondary_damage"}
;		else component "engine2" {call "secondary_damage"}
;		else component "tail_shaft" {call "secondary_damage"}
;		else component "main_reductor" {call "secondary_damage"}
;		else component "glass" {call "secondary_damage"}
;		else component "parts" {call "secondary_damage"}
;		}
;=====баки=====
	{if component "fuel_tank_internal_a"
		{burn fx "smoke_aero_big" fake}
		{if stuff "cm" 
			{if rand 0.85 {components "fuel_tank_internal_a" break}}
		else stuff "rok"
			{if rand 0.85 {components "fuel_tank_internal_a" break}}
		else stuff "fg"
			{if rand 0.8 {components "fuel_tank_internal_a" break}}
		else stuff "ap"
			{if rand 0.25 {components "fuel_tank_internal_a" break}}
		else stuff "apcr"
			{if rand 0.2 {components "fuel_tank_internal_a" break}}
		else stuff "apcr_h"
			{if rand 0.2 {components "fuel_tank_internal_a" break}}
		else 
			{if rand 0.5 {components "fuel_tank_internal_a" break}}
		}
	else component "fuel_tank_internal_b"
		{burn fx "smoke_aero_big" fake}
		{if stuff "cm" 
			{if rand 0.85 {components "fuel_tank_internal_b" break}}
		else stuff "rok"
			{if rand 0.85 {components "fuel_tank_internal_b" break}}
		else stuff "fg"
			{if rand 0.8 {components "fuel_tank_internal_b" break}}
		else stuff "ap"
			{if rand 0.25 {components "fuel_tank_internal_b" break}}
		else stuff "apcr"
			{if rand 0.2 {components "fuel_tank_internal_b" break}}
		else stuff "apcr_h"
			{if rand 0.2 {components "fuel_tank_internal_b" break}}
		else 
			{if rand 0.5 {components "fuel_tank_internal_b" break}}
		}
	else component "fuel_tank_internal_c"
		{burn fx "smoke_aero_big" fake}
		{if stuff "cm" 
			{if rand 0.85 {components "fuel_tank_internal_c" break}}
		else stuff "rok"
			{if rand 0.85 {components "fuel_tank_internal_c" break}}
		else stuff "fg"
			{if rand 0.8 {components "fuel_tank_internal_c" break}}
		else stuff "ap"
			{if rand 0.25 {components "fuel_tank_internal_c" break}}
		else stuff "apcr"
			{if rand 0.2 {components "fuel_tank_internal_c" break}}
		else stuff "apcr_h"
			{if rand 0.2 {components "fuel_tank_internal_c" break}}
		else 
			{if rand 0.5 {components "fuel_tank_internal_c" break}}
		}
	else component "fuel_tank_internal_d"
		{burn fx "smoke_aero_big" fake}
		{if stuff "cm" 
			{if rand 0.85 {components "fuel_tank_internal_d" break}}
		else stuff "rok"
			{if rand 0.85 {components "fuel_tank_internal_d" break}}
		else stuff "fg"
			{if rand 0.8 {components "fuel_tank_internal_d" break}}
		else stuff "ap"
			{if rand 0.25 {components "fuel_tank_internal_d" break}}
		else stuff "apcr"
			{if rand 0.2 {components "fuel_tank_internal_d" break}}
		else stuff "apcr_h"
			{if rand 0.2 {components "fuel_tank_internal_d" break}}
		else 
			{if rand 0.5 {components "fuel_tank_internal_d" break}}
		}
	else component "fuel_tank_external_a"
		{burn fx "smoke_aero_big" fake}
		{if stuff "cm" 
			{if rand 0.85 {components "fuel_tank_external_a" break}}
		else stuff "rok"
			{if rand 0.85 {components "fuel_tank_external_a" break}}
		else stuff "fg"
			{if rand 0.8 {components "fuel_tank_external_a" break}}
		else stuff "ap"
			{if rand 0.25 {components "fuel_tank_external_a" break}}
		else stuff "apcr"
			{if rand 0.2 {components "fuel_tank_external_a" break}}
		else stuff "apcr_h"
			{if rand 0.2 {components "fuel_tank_external_a" break}}
		else 
			{if rand 0.5 {components "fuel_tank_external_a" break}}
		}
	else component "fuel_tank_external_b"
		{burn fx "smoke_aero_big" fake}
		{if stuff "cm" 
			{if rand 0.85 {components "fuel_tank_external_b" break}}
		else stuff "rok"
			{if rand 0.85 {components "fuel_tank_external_b" break}}
		else stuff "fg"
			{if rand 0.8 {components "fuel_tank_external_b" break}}
		else stuff "ap"
			{if rand 0.25 {components "fuel_tank_external_b" break}}
		else stuff "apcr"
			{if rand 0.2 {components "fuel_tank_external_b" break}}
		else stuff "apcr_h"
			{if rand 0.2 {components "fuel_tank_external_b" break}}
		else 
			{if rand 0.5 {components "fuel_tank_external_b" break}}
		}
	else component "fuel_tank_external_c"
		{burn fx "smoke_aero_big" fake}
		{if stuff "cm" 
			{if rand 0.85 {components "fuel_tank_external_c" break}}
		else stuff "rok"
			{if rand 0.85 {components "fuel_tank_external_c" break}}
		else stuff "fg"
			{if rand 0.8 {components "fuel_tank_external_c" break}}
		else stuff "ap"
			{if rand 0.25 {components "fuel_tank_external_c" break}}
		else stuff "apcr"
			{if rand 0.2 {components "fuel_tank_external_c" break}}
		else stuff "apcr_h"
			{if rand 0.2 {components "fuel_tank_external_c" break}}
		else 
			{if rand 0.5 {components "fuel_tank_external_c" break}}
		}
	else component "fuel_tank_external_d"
		{burn fx "smoke_aero_big" fake}
		{if stuff "cm" 
			{if rand 0.85 {components "fuel_tank_external_d" break}}
		else stuff "rok"
			{if rand 0.85 {components "fuel_tank_external_d" break}}
		else stuff "fg"
			{if rand 0.8 {components "fuel_tank_external_d" break}}
		else stuff "ap"
			{if rand 0.25 {components "fuel_tank_external_d" break}}
		else stuff "apcr"
			{if rand 0.2 {components "fuel_tank_external_d" break}}
		else stuff "apcr_h"
			{if rand 0.2 {components "fuel_tank_external_d" break}}
		else 
			{if rand 0.5 {components "fuel_tank_external_d" break}}
		}
	}
	{if component "hydrosystem" 
		{burn fx "drops_oil_small_long" fake}
		{if rand 0.03
			{call "_burn"}
		}
	}
	{if component "ammo_storage_autocannon"
		{damage_report "ammo_storage_autocannon" "ammo_storage_autocannon_damaged"}
		{spawn "metal_hit_bul"}
		{if rand 0.55 {components "ammo_storage_autocannon" break}}
	}
	{if component "ammo_storage_mgun"
		{damage_report "ammo_storage_mgun" "ammo_storage_mgun_damaged"}
		{spawn "metal_hit_bul"}
		{if rand 0.45 {components "ammo_storage_mgun" break}}
	}
	{if component "radar"
		{if not tagged "radar_break"
			("stop_damage_sound")
			{play_sound "radar_damage"}
			{damage_report "radar" "radar_damaged"}
			{tear "piece_medium_steel" bone "Visor_radar"
              	  			{impulse up 2 1 dir 2 1}
			}
			{spawn "metal_hit_bul"}
		}

	}
	{if component "ols"	;ОЛС - оптико-локационная станция. То есть, прицел.
		{if not tagged "ols_break"
			{tags add "ols_break"}
			("stop_damage_sound")
			{play_sound "ols_damage"}
			{damage_report "ols" "ols_damaged"}
			{tear "piece_medium_steel" bone "visor2"
              	  			{impulse up 2 1 dir 2 1}
			}
		}
		{spawn "glass_hit" }
	}
	{if volume "glass" 
		{volume disable bullet contact}
	 	{spawn "glass_hit2"}
	 	{delay 0.1
		 	{tear "piece_big_airborne_wing" bone from_volume
				{delete}
			}
	 	}
	}
      }	;конец запрета на пробивание указателем ПТУР
}
{on blast_hit
    {if min_energy 10
	{call "fall"}
	{if volume "part"
		{call "tear_part"}
	}
    else min_energy 4
	;{if rand 0.5	{call "fall"}}
	{if volume "part"
		{call "tear_part"}
	}
    else min_energy 3
	{if rand 0.5
		{if volume "part"
			{call "tear_part"}
		}
	}
   }
}

{on blast
	{delay 1.0 {call "time_to_escape_after_hit"}}
	{if min_energy 1.2
		;{if rand 0.75
			{if tagged "time_to_escape_after_hit"
				{call "fall"}
			}
		;}
	}
}

{on break_armor overload
;======Шасси=====
	{if component "wheel_back"
	     {if work "wheel_back"
		{components "wheel_back" break}
		{burn fx "smoke_dead_tank2" fake}
	     }
	else component "retract_wheelR"
	     {if work "retract_wheelR"
		{components "retract_wheelR" break}
		{burn fx "smoke_dead_tank2" fake}
	     }
	else component "retract_wheelL"
	     {if work "retract_wheelL"
		{components "retract_wheelL" break}
		{burn fx "smoke_dead_tank2" fake}
	     }
	
;======Двигатели=====
;У однодвигательного вертолета ЕСТЬ engine, НЕТ engine1, engine2
;У двухдвигательного вертолета НЕТ engine, ЕСТЬ engine1 (левый), engine2 (правый)
	else component "engine"
	     {if work "engine"
		{components "engine" break}
		{burn fx "smoke_aero_small" fake}
	     }
	else component "engine1"
	     {if work "engine1"
		{components "engine1" break}
		{burn fx "smoke_aero_small" fake}
	     }
	else component "engine2"
	     {if work "engine2"
		{components "engine2" break}
		{burn fx "smoke_aero_small" fake}
	     }
	
;======Трансмиссия и винты=====
	else component "main_reductor"
	     {if work "main_reductor"
		{components "main_reductor" break}
		{burn fx "smoke_aero_small" fake}
	     }
	else component "tail_shaft"	;хвостовой вал
	     {if work "tail_shaft"
		{components "tail_shaft" break}
		{burn fx "smoke_aero_small" fake}
	     }
	else component "propeller"
	     {if work "propeller"
		{components "propeller" break}
	     }
	else component "tail_rotor"
	     {if work "tail_rotor"
		{components "tail_rotor" break}
	     }
;======Оборудование=====
	else component "pilot_panel"
	     {if work "pilot_panel"
		{components "pilot_panel" break}
		{burn fx "smoke_aero_small" fake}
	     }
	else component "hydrosystem"
	     {if work "hydrosystem"
		{components "hydrosystem" break}
		{burn fx "smoke_aero_small" fake}
	     }
	else component "apu"
	     {if work "apu"
		{components "apu" break}
		{burn fx "smoke_aero_small" fake}
	     }
	else component "ir_active_def"
	     {if work "ir_active_def"
		{components "ir_active_def" break}
		{burn fx "smoke_aero_small" fake}
	     }
	else component "ir_active_def_2gen"
	     {if work "ir_active_def_2gen"
		{components "ir_active_def_2gen" break}
		{burn fx "smoke_aero_small" fake}
	     }
;=====Вооружение=====
	else component "prpnk" ;прицельно-пилотажно-навигационный комплекс.
	    {if work "prpnk" 
		{components "prpnk" break}
		{burn fx "smoke_aero_small" fake}
		{spawn "glass_hit" }
	     }
	else component "gun"     {if work "gun" 	{components "gun" break}	{spawn "metal_hit_bul"}     }
	else component "mgun"     {if work "mgun" 	{components "mgun" break}	{spawn "metal_hit_bul"}     }
	else component "mgun1"     {if work "mgun1" 	{components "mgun1" break}	{spawn "metal_hit_bul"}     }	
	else component "mgun2"     {if work "mgun2" 	{components "mgun2" break}	{spawn "metal_hit_bul"}     }	

	else component "ptur"     {if work "ptur" 	{components "ptur" break}	{spawn "metal_hit_bul"}     }	
	else component "ptur1"     {if work "ptur1" 	{components "ptur1" break}	{spawn "metal_hit_bul"}     }	
	else component "ptur2"     {if work "ptur2" 	{components "ptur2" break}	{spawn "metal_hit_bul"}     }	
	else component "ptur3"     {if work "ptur3" 	{components "ptur3" break}	{spawn "metal_hit_bul"}     }	
	else component "ptur4"     {if work "ptur4" 	{components "ptur4" break}	{spawn "metal_hit_bul"}     }	

	else component "nar"     {if work "nar" 	{components "nar" break}	{spawn "metal_hit_bul"}     }	
	else component "nar1"     {if work "nar1" 	{components "nar1" break}	{spawn "metal_hit_bul"}     }	
	else component "nar2"     {if work "nar2" 	{components "nar2" break}	{spawn "metal_hit_bul"}     }	
	else component "nar3"     {if work "nar3" 	{components "nar3" break}	{spawn "metal_hit_bul"}     }	
	else component "nar4"     {if work "nar4" 	{components "nar4" break}	{spawn "metal_hit_bul"}     }	
	else component "nar5"     {if work "nar5" 	{components "nar5" break}	{spawn "metal_hit_bul"}     }	
	else component "nar6"     {if work "nar6" 	{components "nar6" break}	{spawn "metal_hit_bul"}     }	

	else component "flares1"     {if work "flares1" 	{components "flares1" break}	{spawn "metal_hit_bul"}     }	
	else component "flares2"     {if work "flares2" 	{components "flares2" break}	{spawn "metal_hit_bul"}     }	
	else component "chaff1"     {if work "chaff1"     {components "chaff1" break}	{spawn "metal_hit_bul"}     }
	else component "chaff2"     {if work "chaff2"     {components "chaff2" break}	{spawn "metal_hit_bul"}     }

	else component "electronics"     {if work "electronics"     {components "electronics"     break}	{spawn "metal_hit_bul"}     }	}
}


{on "update_weaponry"
	{if not tagged "time_to_escape_after_hit"
		{weapon_work "gun" 1}
		{weapon_work "ptur" 1}
		{weapon_work "ptur1" 1}
		{weapon_work "ptur2" 1}
		{weapon_work "ptur3" 1}
		{weapon_work "ptur4" 1}
		{weapon_work "nar1" 1}
		{weapon_work "nar2" 1}
		{weapon_work "nar3" 1}
		{weapon_work "nar4" 1}
		{weapon_work "nar5" 1}
		{weapon_work "nar6" 1}
		{weapon_work "flares1" 1}
		{weapon_work "flares2" 1}
		{weapon_work "IR_designator" 1}
		{weapon_work "laser" 1}
		{tags remove "no_missile_control"}

		{if not work "prpnk" 
			{weapon_work "gun" 0}
			{weapon_work "ptur" 0}
			{weapon_work "ptur1" 0}
			{weapon_work "ptur2" 0}
			{weapon_work "ptur3" 0}
			{weapon_work "ptur4" 0}
			{weapon_work "IR_designator" 0}
			{weapon_work "laser" 0}
			{tags add "no_missile_control"}
		}

		{if not work "gun" {weapon_work "gun" 0} }
		{if not work "mgun" {weapon_work "mgun" 0} }
		{if not work "mgun1" {weapon_work "mgun1" 0} }
		{if not work "mgun2" {weapon_work "mgun2" 0} }

		{if not work "ptur" {weapon_work "ptur" 0} }
		{if not work "ptur1" {weapon_work "ptur1" 0} }
		{if not work "ptur2" {weapon_work "ptur2" 0} }
		{if not work "ptur3" {weapon_work "ptur3" 0} }
		{if not work "ptur4" {weapon_work "ptur4" 0} }

		{if not work "nar" {weapon_work "nar" 0} }
		{if not work "nar1" {weapon_work "nar1" 0} }
		{if not work "nar2" {weapon_work "nar2" 0} }
		{if not work "nar3" {weapon_work "nar3" 0} }
		{if not work "nar4" {weapon_work "nar4" 0} }
		{if not work "nar5" {weapon_work "nar5" 0} }
		{if not work "nar6" {weapon_work "nar6" 0} }

		{if not work "flares1" {weapon_work "flares1" 0} }
		{if not work "flares2" {weapon_work "flares2" 0} }
		{if not work "ir_active_def" {components "ir_defence_sys_1gen" break} else {components "ir_defence_sys_1gen" repair}}
		{if not work "ir_active_def_2gen" {components "ir_defence_sys_2gen" break}  else {components "ir_defence_sys_2gen" repair}}

		{if not work "electronics"     
			{if rand 0.5   {weapon_work "gun" 0} }
			{if rand 0.5   {weapon_work "ptur" 0} }
			{if rand 0.5   {weapon_work "ptur1" 0} }
			{if rand 0.5   {weapon_work "ptur2" 0} }
			{if rand 0.5   {weapon_work "ptur3" 0} }
			{if rand 0.5   {weapon_work "ptur4" 0} }
			{if rand 0.5   {weapon_work "IR_designator" 0}}
		}
		{if flag "specability" 
			{weapon_work "ptur" 0}
			{weapon_work "ptur1" 0}
			{weapon_work "ptur2" 0}
			{weapon_work "ptur3" 0}
			{weapon_work "ptur4" 0}
			{weapon_work "IR_designator" 0}
			{weapon_work "laser" 0}
		}
	}
	{call  "check_pilot_existance"}
}
{on "time_to_escape_after_hit"
	{tags add "time_to_escape_after_hit"}
	{weapon_work "gun" 0}
	{weapon_work "ptur" 0}
	{weapon_work "ptur1" 0}
	{weapon_work "ptur2" 0}
	{weapon_work "ptur3" 0}
	{weapon_work "ptur4" 0}
	{weapon_work "nar1" 0}
	{weapon_work "nar2" 0}
	{weapon_work "nar3" 0}
	{weapon_work "nar4" 0}
	{weapon_work "nar5" 0}
	{weapon_work "nar6" 0}
	{delay 15 {tags remove "time_to_escape_after_hit"} {call "update_weaponry"}}
}
{on "check_pilot_existance"
	(define "check_drivers"
		  {delay 0.2
			{if not crew_in_place "driver"
			  {if not crew_in_place "gunner"
				{if not crew_in_place "commander"
				   {if not crew_in_place "driver1"
					 {call "fall"}
				   }
				}
			  }
			}
		  }	
	)
	{if not tagged "destroyed"
	  {if chassis "airborne"
	    {if crew_in_place "driver"
		  ("check_drivers")
		else crew_in_place "gunner"
		  ("check_drivers")
		else crew_in_place "commander"
		  ("check_drivers")
		else crew_in_place "driver1"
		  ("check_drivers")
	    }
	  }
	}
}

{on "check_moveability"
	     {if not work "engine1"
		{view pause "engine_steam1"}
	     }
	    {if not work "engine2"
		{view pause "engine_steam2"}
	    }
;=============в воздухе
	{if chassis "airborne"
	     {if not work "engine" {call "fall"} }
	     {if not work "engine1"  {if not work "engine2" {call "fall"}  }  }
	     {if not work "propeller" {call "fall"}  }
	     {if not work "engine1"
		{if not flag "overheating"     {set "overheating" 1}     {call "overheat"}}
	     }
	     {if not work "engine2"
		{if not flag "overheating"     {set "overheating" 1}     {call "overheat"}}
	     }
	     {if not work "main_reductor"
		{if not flag "overheating_fast" 
		   {if not flag "fall"     {set "overheating_fast" 1}     {call "overheat_fast"}   }
		}
	     }
	     {if not work "tail_shaft"	
		{call "fall"}
	     }
;	     {if not work "tail_rotor"
;		{call "fall"}
;	     }
	     {if not work "pilot_panel" {call "fall"} }
	     {if not work "hydrosystem" {if not flag "delayed_fall_long"     {set "delayed_fall_long" 1}    {call "delayed_fall_long"}} }
	     {if not work "body" {call "fall"} {call "mp_destroy"}}
		else altitude 1
	     {if not work "engine" {call "fall"} }
	     {if not work "engine1"  {if not work "engine2" {call "fall"}  }  }
	     {if not work "propeller" {call "fall"}  }
	     {if not work "engine1"
		{if not flag "overheating"     {set "overheating" 1}     {call "overheat"}}
	     }
	     {if not work "engine2"
		{if not flag "overheating"     {set "overheating" 1}     {call "overheat"}}
	     }
	     {if not work "main_reductor"
		{if not flag "overheating_fast" 
		   {if not flag "fall"     {set "overheating_fast" 1}     {call "overheat_fast"}   }
		}
	     }
	     {if not work "tail_shaft"	
		{if not flag "delayed_fall"     {set "delayed_fall" 1}    {call "delayed_fall"}}
	     }
	     {if not work "tail_rotor"
		{if not flag "delayed_fall"      {set "delayed_fall" 1}     {call "delayed_fall"}}
	     }
	     {if not work "pilot_panel" {call "fall"} }
	     {if not work "hydrosystem" {if not flag "delayed_fall_long"     {set "delayed_fall_long" 1}    {call "delayed_fall_long"}} }
	     {if not work "body" {call "fall"} {call "mp_destroy"}}
;=============на земле
	else
	     {chassis_work 1}
	     {set "overheating_fast" 0}
	     {set "overheating_fast_1" 0}
	     {set "overheating_fast_2" 0}
	     {set "overheating_1" 0}
	     {set "overheating_2" 0}
	     {set "overheating" 0}
	     {set "delayed_fall" 0}
	     {set "delayed_fall_long" 0}
	     {if not work "engine"	{chassis_work 0}  }
	     {if not work "engine1"      {if not work "engine2" {chassis_work 0}     }     }
	     {if not work "wheel_back" {chassis_work 0}   }
	     {if not work "retract_wheelR" {chassis_work 0}    }
	     {if not work "retract_wheelL" {chassis_work 0}    }
	     {if not work "main_reductor" {chassis_work 0}    }
	     {if not work "propeller" {chassis_work 0}    }
	     {if not work "tail_rotor" {chassis_work 0}    }
	     {if not work "tail_shaft" {chassis_work 0}    }
	     {if not work "pilot_panel" {chassis_work 0} }
	     {if not work "hydrosystem" {chassis_work 0} }
	     {if not work "apu" {chassis_work 0} }
	     {if not work "body" {chassis_work 0} {call "mp_destroy"} {call "fall"}}
	}

	{call "update_weaponry"}
}
	{on fragments
		;при срабатывании on fragments осколок только один, но дамажатся все волумы юнита
		;и вдобавок сечение юнита порядка 10м2, а компоненты маленькие.
		;p - это вероятность того, что осколок попал в данный компонент, если он попал в площадь 2м2
		;например, прицел имеет площадь проекции в целом 0,3м2, так что шанс 0.3/2=0.15

		(define "frag_to_blast" 
		
			(define "check_damage_frag"
				else component "%component" 
				 {if rand %p or not stuff "ammo"
				  {if rand %splitter {spawn "metal_hit_bul"}}
				  {blastwave c4 (+ %e 0.2) r0 0.1 r1 0.2 position} 
				 }
			)
		min_energy %e 
		{if component "wing"  {blastwave c4 %e r0 0.01 r1 0.02 position}{spawn "metal_hit_bul"}
		("check_damage_frag" component(wheel_back)  p(0.2) splitter(%splitter))
		("check_damage_frag" component(retract_wheelR)  p(0.2) splitter(%splitter))
		("check_damage_frag" component(retract_wheelL)  p(0.2) splitter(%splitter))
		("check_damage_frag" component(engine)  p(1) splitter(%splitter))
		("check_damage_frag" component(engine1)  p(1) splitter(%splitter))
		("check_damage_frag" component(engine2)  p(1) splitter(%splitter))
		("check_damage_frag" component(propeller)  p(0.1) splitter(%splitter))
		("check_damage_frag" component(tail_rotor)  p(0.1) splitter(%splitter))
		
		("check_damage_frag" component(main_reductor)  p(0.5) splitter(%splitter))
		("check_damage_frag" component(tail_shaft)  p(0.2) splitter(%splitter))
		("check_damage_frag" component(pilot_panel)  p(0.25) splitter(%splitter))
		("check_damage_frag" component(hydrosystem)  p(0.2) splitter(%splitter))
		("check_damage_frag" component(APU)  p(0.75) splitter(%splitter))
		("check_damage_frag" component(radar)  p(0.25) splitter(%splitter))
		("check_damage_frag" component(OLS)  p(0.15) splitter(%splitter))
		("check_damage_frag" component(PrPNK)  p(0.15) splitter(%splitter))
		("check_damage_frag" component(electronics)  p(0.2) splitter(%splitter))
		
		("check_damage_frag" component(gun)  p(0.1) splitter(%splitter))
		("check_damage_frag" component(mgun)  p(0.1) splitter(%splitter))
		("check_damage_frag" component(mgun1)  p(0.1) splitter(%splitter))
		("check_damage_frag" component(mgun2)  p(0.1) splitter(%splitter))
		("check_damage_frag" component(ptur)  p(0.3) splitter(%splitter))
		("check_damage_frag" component(ptur1)  p(0.3) splitter(%splitter))
		("check_damage_frag" component(ptur2)  p(0.3) splitter(%splitter))
		("check_damage_frag" component(ptur3)  p(0.3) splitter(%splitter))
		("check_damage_frag" component(ptur4)  p(0.3) splitter(%splitter))
		("check_damage_frag" component(nar)  p(0.3) splitter(%splitter))
		("check_damage_frag" component(nar1)  p(0.3) splitter(%splitter))
		("check_damage_frag" component(nar2)  p(0.3) splitter(%splitter))
		("check_damage_frag" component(nar3)  p(0.3) splitter(%splitter))
		("check_damage_frag" component(nar4)  p(0.3) splitter(%splitter))
		("check_damage_frag" component(nar5)  p(0.3) splitter(%splitter))
		("check_damage_frag" component(nar6)  p(0.3) splitter(%splitter))
		
		("check_damage_frag" component(flares1)  p(0.1) splitter(%splitter))
		("check_damage_frag" component(flares2)  p(0.1) splitter(%splitter))
		("check_damage_frag" component(chaff1)  p(0.1) splitter(%splitter))
		("check_damage_frag" component(chaff2)  p(0.1) splitter(%splitter))
		("check_damage_frag" component(ir_active_def)  p(0.1) splitter(%splitter))
		("check_damage_frag" component(ir_active_def_2gen)  p(0.1) splitter(%splitter))
		
		("check_damage_frag" component(fuel_tank_internal_a)  p(1) splitter(%splitter))
		("check_damage_frag" component(fuel_tank_internal_b)  p(1) splitter(%splitter))
		("check_damage_frag" component(fuel_tank_internal_c)  p(1) splitter(%splitter))
		("check_damage_frag" component(fuel_tank_internal_d)  p(1) splitter(%splitter))
		("check_damage_frag" component(fuel_tank_external_a)  p(1) splitter(%splitter))
		("check_damage_frag" component(fuel_tank_external_b)  p(1) splitter(%splitter))
		("check_damage_frag" component(fuel_tank_external_c)  p(1) splitter(%splitter))
		("check_damage_frag" component(fuel_tank_external_d)  p(1) splitter(%splitter))

		("check_damage_frag" component(ammo_storage_autocannon)  p(0.25) splitter(%splitter))
		("check_damage_frag" component(ammo_storage_mgun)  p(0.1) splitter(%splitter))
		 else {blastwave c4 %e r0 0.01 r1 0.02 position}{spawn "metal_hit_bul"}
		}
		)
		{if ("frag_to_blast" e(54.9) splitter(1))
		else ("frag_to_blast" e(49.9) splitter(1))
		else ("frag_to_blast" e(44.9) splitter(1))
		else ("frag_to_blast" e(39.9) splitter(1))
		else ("frag_to_blast" e(34.9) splitter(1))
		else ("frag_to_blast" e(29.9) splitter(1))
		else ("frag_to_blast" e(27.9) splitter(1))
		else ("frag_to_blast" e(24.9) splitter(1))
		else ("frag_to_blast" e(21.9) splitter(1))
		else ("frag_to_blast" e(19.9) splitter(1))
		else ("frag_to_blast" e(17.9) splitter(1))
		else ("frag_to_blast" e(15.9) splitter(1))
		else ("frag_to_blast" e(13.4) splitter(1))
		else ("frag_to_blast" e(10.9) splitter(1))
		else ("frag_to_blast" e(9.9) splitter(1))
		else ("frag_to_blast" e(7.9) splitter(1))
		else ("frag_to_blast" e(6.4) splitter(1))
		else ("frag_to_blast" e(4.9) splitter(1))
		else ("frag_to_blast" e(3.9) splitter(0.7))
		else ("frag_to_blast" e(2.9) splitter(0.4))
		else ("frag_to_blast" e(2.4) splitter(0.2))
		else ("frag_to_blast" e(1.9) splitter(0.2))
		else ("frag_to_blast" e(1.4) splitter(0.2))
		else ("frag_to_blast" e(0.9) splitter(0.2))
		else ("frag_to_blast" e(0.6) splitter(0.2))
		else ("frag_to_blast" e(0.4) splitter(0))
		}
		
	}
{on break overload
	(define "critical_system"
;		{if not tagged "crit_system_destroyed"
;			{tags add "crit_system_destroyed"}
;		else
;			{components "body" break}
;			{call "mp_destroy"}
;		}
	)
	(define "engine_break"
	  else component "%engine"
		{tags add "%engine_damaged"}
		{spawn "tank_die_particle"}
		{burn fx "smoke_black" fake}
		{if not tagged "destroyed"
			{damage_report "%engine" "%engine_damaged"}
		}
		("critical_system")
		{if rand 0.2
			{call "_burn"}
		}
		{call "update_power"}
		{view start "%engine_smoke"}
		{delay 20
			{view pause "%engine_smoke"}
		}
	)

;======Корпус=====
	{if component "body"
		{tags add "body_brake"}
		{call "stat_break"}
		{chassis_work 0}
		{call "mp_destroy"}
;======Шасси=====
	else component "wheel_back"
		{tags add "wheel_back_damaged"}
		{if not tagged "destroyed"
			{damage_report "wheel_back" "wheels_damaged"}
		}
	else component "retract_wheelR_damaged"
		{tags add "retract_wheelR_damaged"}
		{if not tagged "destroyed"
			{damage_report "retract_wheelR" "wheels_damaged"}
		}
	else component "retract_wheelL"
		{tags add "retract_wheelL_damaged"}
		{if not tagged "destroyed"
			{damage_report "retract_wheelL" "wheels_damaged"}
		}
;======Двигатели=====
;У однодвигательного вертолета ЕСТЬ engine, НЕТ engine1, engine2
;У двухдвигательного вертолета НЕТ engine, ЕСТЬ engine1 (левый), engine2 (правый).
	("engine_break" engine(engine))
	("engine_break" engine(engine1))
	("engine_break" engine(engine2))
	else component "main_reductor" 
		{tags add "main_reductor_damaged" }
		{spawn "tank_die_particle"}
		{if not tagged "destroyed"
			("stop_damage_sound")
			{play_sound "main_reductor_damage"}
;		     {if chassis "airborne"
			 {if altitude 1
				{if rand 0.5
					{damage_report "main_reductor" "main_reductor_malfunction"}
				 else
					{call "fall"}
					{damage_report "main_reductor" "main_reductor_damaged"}
				}
		     else
				{damage_report "main_reductor" "main_reductor_damaged"}
		     }
		}
		("critical_system")
		{if rand 0.4
			{call "_burn"}
		}
	else component "propeller"
		{tags add "propeller_damaged"}
		{spawn "tank_die_particle" "propeller"}
		{if not tagged "destroyed"
			("stop_damage_sound")
			{play_sound "propeller_damage"}
			{damage_report "propeller" "propeller_damaged"}
			{link_sound "heli_damage_rotor"		"vehicle/helicopter/crash/heli_damage_rotor"}
			{play_sound "heli_damage_rotor"}
		}
		("critical_system")
	else component "tail_shaft" 
		{tags add "tail_shaft_damaged"}
		{spawn "tank_die_particle"}
		{if not tagged "destroyed"
			("stop_damage_sound")
			{play_sound "tail_shaft_damage"}
			{damage_report "tail_shaft" "tail_shaft_damaged"}
		}
		("critical_system")
	else component "tail_rotor" 
		{tags add "tail_rotor_damaged"}
		{spawn "tank_die_particle"}
		{if not tagged "destroyed"
			{damage_report "tail_rotor" "tail_rotor_damaged"}
			{link_sound "heli_damage_tail"		"vehicle/helicopter/crash/heli_damage_tail"}
			{play_sound "heli_damage_tail"}

		}
		("critical_system")
;======Оборудование=====
	else component "pilot_panel"
		{tags add "driver_panel_damaged"}
		{if not tagged "destroyed"
			{damage_report "driver_panel" "driver_panel_damaged"}
		}
		{spawn "tank_die_particle"}
		("critical_system")
	else component "hydrosystem" 
		{tags add "hydrosystem_damaged"}
		{if not tagged "destroyed"
			("stop_damage_sound")
			{play_sound "hydrosystem_damage"}
			{damage_report "hydrosystem" "hydrosystem_damaged"}
		}
		{if rand 0.15
			{call "_burn"}
		}
	else component "apu"
		{tags add "apu_damaged"}
		{if not tagged "destroyed"
			("stop_damage_sound")
			{play_sound "apu_damage"}
			{damage_report "apu" "apu_damaged"}
		}
		{spawn "tank_die_particle"}
		{if rand 0.15
			{call "_burn"}
		}
	else component "ir_active_def"
		{tags add "ir_active_def_damaged"}
		{if not tagged "destroyed"
			{damage_report "ir_active_def" "ir_active_def_damaged"}
		}
		{spawn "tank_die_particle"}
	else component "ir_active_def_2gen"
		{tags add "ir_active_def_2gen_damaged"}
		{if not tagged "destroyed"
			{damage_report "ir_active_def_2gen" "ir_active_def:ir_active_def_damaged"}
		}
		{spawn "tank_die_particle"}
	else component "fuel_tank_internal_a"
		{if not tagged "destroyed"
			("stop_damage_sound")
			{play_sound "fuel_tank_damage"}
		     {damage_report "fuel_tank_internal_a" "fuel:fuel_tank_damaged"}
		     {if rand 0.8
			{burn fx "smoke_dead_norm" fake}
			{fire radius 4 time 1 heating 3}
			{call "_burn"}
			{if rand 0.8
				{spawn "ex_air_big"}
				;{blastwave c4 3 r0 2 r1 6 position}
			}
		     }
		}
	else component "fuel_tank_internal_b"
		{if not tagged "destroyed"
			("stop_damage_sound")
			{play_sound "fuel_tank_damage"}
		     {damage_report "fuel_tank_internal_b" "fuel:fuel_tank_damaged"}
		     {if rand 0.8
			{burn fx "smoke_dead_norm" fake}
			{fire radius 4 time 1 heating 3}
			{call "_burn"}
			{if rand 0.8
				{spawn "ex_air_big"}
				;{blastwave c4 3 r0 2 r1 6 position}
			}
		     }
		}
	else component "fuel_tank_internal_c"
		{if not tagged "destroyed"
			("stop_damage_sound")
			{play_sound "fuel_tank_damage"}
		     {damage_report "fuel_tank_internal_c" "fuel:fuel_tank_damaged"}
		     {if rand 0.8
			{burn fx "smoke_dead_norm" fake}
			{fire radius 4 time 1 heating 3}
			{call "_burn"}
			{if rand 0.8
				{spawn "ex_air_big"}
				;{blastwave c4 3 r0 2 r1 6 position}
			}
		     }
		}
	else component "fuel_tank_internal_d"
		{if not tagged "destroyed"
			("stop_damage_sound")
			{play_sound "fuel_tank_damage"}
		     {damage_report "fuel_tank_internal_d" "fuel:fuel_tank_damaged"}
		     {if rand 0.8
			{burn fx "smoke_dead_norm" fake}
			{fire radius 4 time 1 heating 3}
			{call "_burn"}
			{if rand 0.8
				{spawn "ex_air_big"}
				;{blastwave c4 3 r0 2 r1 6 position}
			}
		     }
		}
	else component "fuel_tank_external_a"
		{if not tagged "destroyed"
			("stop_damage_sound")
			{play_sound "fuel_tank_damage"}
		     {damage_report "fuel_tank_external_a" "fuel:fuel_tank_damaged"}
		     {if rand 0.8
			{burn fx "smoke_dead_norm" fake}
			{fire radius 4 time 1 heating 3}
			{call "_burn"}
			{if rand 0.8
				{spawn "ex_air_big"}
				;{blastwave c4 3 r0 2 r1 6 position}
			}
		     }
		}
	else component "fuel_tank_external_b"
		{if not tagged "destroyed"
			("stop_damage_sound")
			{play_sound "fuel_tank_damage"}
		     {damage_report "fuel_tank_external_b" "fuel:fuel_tank_damaged"}
		     {if rand 0.8
			{burn fx "smoke_dead_norm" fake}
			{fire radius 4 time 1 heating 3}
			{call "_burn"}
			{if rand 0.8
				{spawn "ex_air_big"}
				;{blastwave c4 3 r0 2 r1 6 position}
			}
		     }
		}
	else component "fuel_tank_external_c"
		{if not tagged "destroyed"
			("stop_damage_sound")
			{play_sound "fuel_tank_damage"}
		     {damage_report "fuel_tank_external_c" "fuel:fuel_tank_damaged"}
		     {if rand 0.8
			{burn fx "smoke_dead_norm" fake}
			{fire radius 4 time 1 heating 3}
			{call "_burn"}
			{if rand 0.8
				{spawn "ex_air_big"}
				;{blastwave c4 3 r0 2 r1 6 position}
			}
		     }
		}
	else component "fuel_tank_external_d"
		{if not tagged "destroyed"
			("stop_damage_sound")
			{play_sound "fuel_tank_damage"}
		     {damage_report "fuel_tank_external_d" "fuel:fuel_tank_damaged"}
		     {if rand 0.8
			{burn fx "smoke_dead_norm" fake}
			{fire radius 4 time 1 heating 3}
			{call "_burn"}
			{if rand 0.8
				{spawn "ex_air_big"}
				;{blastwave c4 3 r0 2 r1 6 position}
			}
		     }
		}
;=====Вооружение=====
	else component "prpnk"
		{tags add "prpnk_damaged"}
		{if not tagged "destroyed"	
			("stop_damage_sound")
			{play_sound "prpnk_damage"}
			{damage_report "prpnk" "prpnk_damaged"}
		}
		{spawn "tank_die_particle"}
	else component "gun"
		{tags add "gun_damaged"}
		{if not tagged "destroyed"	
			("stop_damage_sound")
			{play_sound "gun_damage"}
			{damage_report "gun" "gun_damaged"}
		}
		{spawn "tank_die_particle"}
	else component "mgun"
		{tags add "mgun_damaged"}
		{if not tagged "destroyed"	{damage_report "mgun" "mgun_damaged"}}
		{spawn "tank_die_particle"}
	else component "mgun1"
		{tags add "mgun1_damaged"}
		{if not tagged "destroyed"	{damage_report "mgun1" "mgun:mgun_damaged"}}
		{spawn "tank_die_particle"}
	else component "mgun2"
		{tags add "mgun2_damaged"}
		{if not tagged "destroyed"	{damage_report "mgun2" "mgun:mgun_damaged"}}
		{spawn "tank_die_particle"}
	else component "ptur"
		{tags add "ptur_damaged"}
		{if not tagged "destroyed"	{damage_report "ptur" "ptur_damaged"}}
		{spawn "ex_air_big"}
		{if not tagged "destroyed"	{fragments c4 2 r0 3 r1 4 position}}
	else component "ptur1"
		{tags add "ptur1_damaged"}
		{if not tagged "destroyed"	{damage_report "ptur1" "ptur:ptur_damaged"}}
		{spawn "ex_air_big"}
		;{if not tagged "destroyed"	{fragments c4 2 r0 3 r1 4 position}}
	else component "ptur2"
		{tags add "ptur2_damaged"}
		{if not tagged "destroyed"	{damage_report "ptur2" "ptur:ptur_damaged"}}
		{spawn "ex_air_big"}
		;{if not tagged "destroyed"	{fragments c4 2 r0 3 r1 4 position}}
	else component "ptur3"
		{tags add "ptur3_damaged"}
		{if not tagged "destroyed"	{damage_report "ptur3" "ptur:ptur_damaged"}}
		{spawn "ex_air_big"}
		;{if not tagged "destroyed" {fragments c4 2 r0 3 r1 4 position}}
	else component "ptur4"
		{tags add "ptur4_damaged"}
		{if not tagged "destroyed"	{damage_report "ptur4" "ptur:ptur_damaged"}}
		{spawn "ex_air_big"}
		;{if not tagged "destroyed"	{fragments c4 2 r0 3 r1 4 position}}
	else component "nar"
		{tags add "nar_damaged"}
		{if not tagged "destroyed"	{damage_report "nar" "nar_damaged"}}
		{spawn "ex_air_big"}
		;{if not tagged "destroyed"	{blastwave c4 4 r0 0.3 r1 0.5 position}	{fragments c4 1.5 r0 2 r1 3.5 position}}
	else component "nar1"
		{tags add "nar1_damaged"}
		{if not tagged "destroyed"	{damage_report "nar1" "nar:nar_damaged"}}
		{spawn "ex_air_big"}
		;{if not tagged "destroyed"	{blastwave c4 4 r0 0.3 r1 0.5 position}	{fragments c4 1.5 r0 2 r1 3.5 position}}
	else component "nar2"
		{tags add "nar2_damaged"}
		{if not tagged "destroyed"	{damage_report "nar2" "nar:nar_damaged"}}
		{spawn "ex_air_big"}
		;{if not tagged "destroyed"	{blastwave c4 4 r0 0.3 r1 0.5 position}	{fragments c4 1.5 r0 2 r1 3.5 position}}
	else component "nar3"
		{tags add "nar3_damaged"}
		{if not tagged "destroyed"	{damage_report "nar3" "nar:nar_damaged"}}
		{spawn "ex_air_big"}
		;{if not tagged "destroyed"	{blastwave c4 4 r0 0.3 r1 0.5 position}	{fragments c4 1.5 r0 2 r1 3.5 position}}
	else component "nar4"
		{tags add "nar4_damaged"}
		{if not tagged "destroyed"	{damage_report "nar4" "nar:nar_damaged"}}
		{spawn "ex_air_big"}
		;{if not tagged "destroyed"	{blastwave c4 4 r0 0.3 r1 0.5 position}	{fragments c4 1.5 r0 2 r1 3.5 position}}
	else component "nar5"
		{tags add "nar5_damaged"}
		{if not tagged "destroyed"	{damage_report "nar5" "nar:nar_damaged"}}
		{spawn "ex_air_big"}
		;{if not tagged "destroyed"	{blastwave c4 4 r0 0.3 r1 0.5 position}	{fragments c4 1.5 r0 2 r1 3.5 position}}
	else component "nar6"
		{tags add "nar6_damaged"}
		{if not tagged "destroyed"	{damage_report "nar6" "nar:nar_damaged"}}
		{spawn "ex_air_big"}
		;{if not tagged "destroyed"	{blastwave c4 4 r0 0.3 r1 0.5 position}	{fragments c4 1.5 r0 2 r1 3.5 position}}
	else component "flares1"
		{tags add "flares1_damaged"}
		{if not tagged "destroyed"	{damage_report "flares1" "flares:flares_damaged"}}
	else component "flares2"
		{tags add "flares2_damaged"}
		{if not tagged "destroyed"	{damage_report "flares2" "flares:flares_damaged"}}
	else component "chaff1"
		{tags add "chaff1_damaged"}
		{if not tagged "destroyed"	{damage_report "chaff1" "chaff:chaff_damaged"}}
	else component "chaff2"
		{tags add "chaff2_damaged"}
		{if not tagged "destroyed"	{damage_report "chaff2" "chaff:chaff_damaged"}}
	else component "ammo_storage_autocannon"
		{if not tagged "destroyed"
		{spawn "ex_air_big"}
		{fragments c4 3 r0 2 r1 6}
		{delay 0.2 0.5	{spawn "ex_air_big"}	{fragments c4 3 r0 2 r1 6 position}}
		{delay  0.6 1	{spawn "ex_air_big"}	{fragments c4 3 r0 2 r1 6 position}}
		{delay 1 1.2	{spawn "ex_air_big"}	{fragments c4 3 r0 2 r1 6 position}}
		{delay 1.3 1.5	{spawn "ex_air_big"}	{fragments c4 3 r0 2 r1 6 position}}
		{if rand 0.3 {clear_inventory}{tags add "cwfs_set_fuel"}}
		{if rand 0.2 {call "_explosion"}}
		}
	else component "ammo_storage_mgun" 
		{if not tagged "destroyed"
		{spawn "ex_air_norm"}
		{fragments c4 2 r0 1 r1 3 position}
		{delay 0.2 0.5	{spawn "ex_air_norm"}	{fragments c4 2 r0 1 r1 3 position}}
		{delay  0.6 1	{spawn "ex_air_norm"}	{fragments c4 2 r0 1 r1 3 position}}
		{delay 1 1.2	{spawn "ex_air_norm"}	{fragments c4 2 r0 1 r1 3 position}}
		{delay 1.3 1.5	{spawn "ex_air_norm"}	{fragments c4 2 r0 1 r1 3 position}}
		}
	else component "electronics"     
		{tags add "electronics_damaged"}
		{if not tagged "destroyed"	
			("stop_damage_sound")
			{play_sound "electronics_damage"}
			{damage_report "electronics" "electronics_damaged"}
		}
		{spawn "tank_die_particle"}
	}
	{call "update_lights"}
	{call "check_moveability"}
}
{on repair
	{if component "wheel_back"
		{tags remove "wheel_back_damaged"}
		{damage_report "wheel_back" "wheels_repaired"}
	else component "retract_wheelR"
		{tags remove "retract_wheelR_damaged"}
		{damage_report "retract_wheelR" "wheels_repaired"}
	else component "retract_wheelL"
		{tags remove "retract_wheelL_damaged"}
		{damage_report "retract_wheelL" "wheels_repaired"}
	else component "engine"
		{tags remove "engine_damaged"}
		{damage_report "engine" "engine_repaired"}
		{tags remove "crit_system_destroyed"}
		{components "ammo_storage_mgun" repair}
		{components "ammo_storage_autocannon" repair}
		{components "fuel_tank_internal_a" repair}
		{components "fuel_tank_internal_b" repair}
		{components "fuel_tank_internal_c" repair}
		{components "fuel_tank_internal_d" repair}
	else component "engine1"
		{tags remove "engine1_damaged"}
		{damage_report "engine1" "engine1_repaired"}
		{tags remove "crit_system_destroyed"}
		{components "ammo_storage_mgun" repair}
		{components "ammo_storage_autocannon" repair}
		{components "fuel_tank_internal_a" repair}
		{components "fuel_tank_internal_b" repair}
		{components "fuel_tank_internal_c" repair}
		{components "fuel_tank_internal_d" repair}
	else component "engine2"
		{tags remove "engine2_damaged"}
		{damage_report "engine2" "engine2_repaired"}
		{tags remove "crit_system_destroyed"}
		{components "ammo_storage_mgun" repair}
		{components "ammo_storage_autocannon" repair}
		{components "fuel_tank_internal_a" repair}
		{components "fuel_tank_internal_b" repair}
		{components "fuel_tank_internal_c" repair}
		{components "fuel_tank_internal_d" repair}
	else component "main_reductor" 
		{tags remove "main_reductor_damaged"}
		{damage_report "main_reductor" "main_reductor_repaired"}
		{tags remove "crit_system_destroyed"}
		{components "ammo_storage_mgun" repair}
		{components "ammo_storage_autocannon" repair}
		{components "fuel_tank_internal_a" repair}
		{components "fuel_tank_internal_b" repair}
		{components "fuel_tank_internal_c" repair}
		{components "fuel_tank_internal_d" repair}
	else component "propeller" 
		{tags remove "propeller_damaged"}
		{damage_report "propeller" "propeller_repaired"}
		{tags remove "crit_system_destroyed"}
		{components "ammo_storage_mgun" repair}
		{components "ammo_storage_autocannon" repair}
		{components "fuel_tank_internal_a" repair}
		{components "fuel_tank_internal_b" repair}
		{components "fuel_tank_internal_c" repair}
		{components "fuel_tank_internal_d" repair}
	else component "tail_shaft" 
		{tags remove "tail_shaft_damaged"}
		{damage_report "tail_shaft" "tail_shaft_repaired"}
		{tags remove "crit_system_destroyed"}
		{components "ammo_storage_mgun" repair}
		{components "ammo_storage_autocannon" repair}
		{components "fuel_tank_internal_a" repair}
		{components "fuel_tank_internal_b" repair}
		{components "fuel_tank_internal_c" repair}
		{components "fuel_tank_internal_d" repair}
	else component "tail_rotor" 
		{tags remove "tail_rotor_damaged"}
		{damage_report "tail_rotor" "tail_rotor_repaired"}
		{tags remove "crit_system_destroyed"}
		{components "ammo_storage_mgun" repair}
		{components "ammo_storage_autocannon" repair}
		{components "fuel_tank_internal_a" repair}
		{components "fuel_tank_internal_b" repair}
		{components "fuel_tank_internal_c" repair}
		{components "fuel_tank_internal_d" repair}
	else component "pilot_panel" 
		{tags remove "pilot_panel_damaged"}
		{damage_report "pilot_panel" "pilot_panel_repaired"}
		{tags remove "crit_system_destroyed"}
		{components "ammo_storage_mgun" repair}
		{components "ammo_storage_autocannon" repair}
		{components "fuel_tank_internal_a" repair}
		{components "fuel_tank_internal_b" repair}
		{components "fuel_tank_internal_c" repair}
		{components "fuel_tank_internal_d" repair}
	else component "hydrosystem" 
		{tags remove "hydrosystem_damaged"}
		{damage_report "hydrosystem" "hydrosystem_repaired"}
	else component "apu" 
		{tags remove "apu_damaged"}
		{damage_report "apu" "apu_repaired"}
	}
	{if component "prpnk" 
		{tags remove "prpnk_damaged"}
		{damage_report "prpnk" "prpnk_repaired"}
	else component "gun" 
		{tags remove "gun_damaged"}
		{damage_report "gun" "gun_repaired"}
	else component "mgun" 
		{tags remove "mgun_damaged"}
		{damage_report "mgun" "mgun_repaired"}
	else component "mgun1" 
		{tags remove "mgun1_damaged"}
		{damage_report "mgun1" "mgun:mgun_repaired"}
	else component "mgun2" 
		{tags remove "mgun2_damaged"}
		{damage_report "mgun2" "mgun:mgun_repaired"}
	else component "ptur" 
		{tags remove "ptur_damaged"}
		{damage_report "ptur" "ptur_repaired"}
	else component "ptur1" 
		{tags remove "ptur1_damaged"}
		{damage_report "ptur1" "ptur:ptur_repaired"}
	else component "ptur2" 
		{tags remove "ptur2_damaged"}
		{damage_report "ptur2" "ptur:ptur_repaired"}
	else component "ptur3" 
		{tags remove "ptur3_damaged"}
		{damage_report "ptur3" "ptur:ptur_repaired"}
	else component "ptur4" 
		{tags remove "ptur4_damaged"}
		{damage_report "ptur4" "ptur:ptur_repaired"}
	else component "nar" 
		{tags remove "nar_damaged"}
		{damage_report "nar" "nar_repaired"}
	else component "nar1" 
		{tags remove "nar1_damaged"}
		{damage_report "nar1" "nar:nar_repaired"}
	else component "nar2" 
		{tags remove "nar2_damaged"}
		{damage_report "nar2" "nar:nar_repaired"}
	else component "nar3" 
		{tags remove "nar3_damaged"}
		{damage_report "nar3" "nar:nar_repaired"}
	else component "nar4" 
		{tags remove "nar4_damaged"}
		{damage_report "nar4" "nar:nar_repaired"}
	else component "nar5" 
		{tags remove "nar5_damaged"}
		{damage_report "nar5" "nar:nar_repaired"}
	else component "nar6" 
		{tags remove "nar6_damaged"}
		{damage_report "nar6" "nar:nar_repaired"}
	else component "flares1" 
		{tags remove "flares1_damaged"}
		{damage_report "flares1" "flares:flares_repaired"}
	else component "flares2" 
		{tags remove "flares2_damaged"}
		{damage_report "flares2" "flares:flares_repaired"}
	else component "chaff1" 
		{tags remove "chaff1_damaged"}
		{damage_report "chaff1" "chaff:chaff_repaired"}
	else component "chaff2" 
		{tags remove "chaff2_damaged"}
		{damage_report "chaff2" "chaff:chaff_repaired"}
	else component "electronics"     
		{tags remove "electronic_damaged"}
		{damage_report "electronics" "electronics_repaired"}
	else component "ir_active_def"
		{tags remove "ir_active_def_damaged"}
		{damage_report "ir_active_def" "ir_active_def_repaired"}
	else component "ir_active_def_2gen"
		{tags remove "ir_active_def_2gen_damaged"}
		{damage_report "ir_active_def_2gen" "ir_active_def:ir_active_def_repaired"}
	}
	{call "update_lights"}
	{call "check_moveability"}
}

;===============
;Anti-fire system 1.1 by Timosh
(define "burn_engine" 
	{if not tagged "burned"
		{if not able "exploded"
			{damage_report "engine" "burn_engine"}
			{if rand %engine {add_view "smoke_dead_norm" "burn_fire" "FXsmoke1"} {add_view "smoke_dead_norm" "burn_fire" "FXsmoke2"}}
			{if rand %engine1 {add_view "smoke_dead_norm" "burn_fire" "FXsmoke1"}}
			{if rand %engine2 {add_view "smoke_dead_norm" "burn_fire" "FXsmoke2"}}
			{view start "burn_fire"}
			{if rand %engine {add_view "smoke_black" "burn_fire" "FXsmoke1"} {add_view "smoke_black" "burn_fire" "FXsmoke2"}}
			{if rand %engine1 {add_view "smoke_black" "burn_fire" "FXsmoke1"}}
			{if rand %engine2 {add_view "smoke_black" "burn_fire" "FXsmoke2"}}
			{play_sound "flame" 1}
			{view start "burn_fire"}
			{set "burn_fire" 1}
			{components "fire_indicator" break}
			{if rand %engine1 {components "engine1" break}}
			{if rand %engine2 {components "engine2" break}}

			{if rand 0.5  ;вероятность сгорания
					{explosive 1}
					{tags add "burned"}
					{burn time 12}
					{icon_event "burning" 12.0}
					{delay 10
						{if tagged "heli_in_flight"
							{if rand %engine {components "engine" break}}
							{start_sound "crush/medium/metal"}
							{call "check_moveability"}
										{delay 5 4
								{if rand 0.5 {call "mp_destroy"}}
							}
						}
						{call "check_moveability"}
					}
					{delay 12
							{explosive 0}
							{view stop "burn_fire"}
							{stop_sound "flame"}
							{set "burn_fire" 0}
							{call "burn_emit"}
							{set "burning" 0}
							{if tagged "heli_in_flight"
								{call "mp_destroy"}
								{if rand 0.3
									{call "_explosion"}
									else
									{able "burning" 0}
								}
							}
							{components "fire_indicator" repair}
							{able "burning" 0}
							{damage_report "engine" "component/antifire"}
					}
			else
				{icon_event "burning" 12.0}
				{delay 12
					{damage_report "engine" "antifire"}
					{view stop "burn_fire"}
					{stop_sound "flame"}
					{set "burn_fire" 0}
					{set "burning" 0}
					{components "fire_indicator" repair}
				}
			}
		}
	}
)


	{on "_burn" overload
		{damage_report "engine" "burn_fire"}
		{log "burn_volume"}
		{if not burned
			{if rand 0.5
				{log "burn_engine"}				
				("burn_engine" engine(0) engine1(1) engine2(0))
			else 
				{log "burn_engine"}				
				("burn_engine" engine(0) engine1(0) engine2(1))
			}
		}
	}


	{on "burn_volume" overload
		{log "burn_volume"}
		{if not burned
			{if volume "engine"
				{log "burn_engine"}				
				("burn_engine" engine(1) engine1(0) engine2(0))
			else volume "engine1"
				{log "burn_engine"}				
				("burn_engine" engine(0) engine1(1) engine2(0))
			else volume "engine2"
				{log "burn_engine"}				
				("burn_engine" engine(0) engine1(0) engine2(1))
			}
		}
	}

;End of anti-fire system
;===============
	{on "mp_destroy" overload

		{drop_orders}
		{reset_manual_control}
		{able select 0}
		{able repaired 0}
		{unlink_trailer}
		{call "engine_stop"}

		{if not tagged "destroyed"
			{damage_report "body" "body_broken"}
			{if not tagged "body_break"
				{components "body" break}
				{call "stat_break"}
			}
		}
		{crew_emit}
		
		{delay 2
			{tags add "destroyed"}
			{kick_entity_manager}
			{kill_crew}
		}

		{call "burn_emit"}
	}

	{on "overheat_fast"
	     {if not tagged "destroyed"
		{set "overheating_fast" 1}
		{set "overheating_fast_1" 0}
		{set "overheating_fast_2" 0}
		{delay 6
			{if flag "overheating_fast" 
				{damage_report "body" "overheat"}
				{if rand 0.15
					{call "_burn"}
				}
				{set "overheating_fast_1" 1}
			}
		}
		{delay 12
			{if flag "overheating_fast_1" 
				{damage_report "body" "strong_overheat"}
				{if rand 0.15
					{call "_burn"}
				}
				{set "overheating_fast_2" 1}
				{set "overheating_fast_1" 0}
			}
		}
		{delay 18
			{if flag "overheating_fast_2" 
				{call "fall"}
				{call "_burn"}
				{set "overheating_fast_2" 0}
			}
		}
	     }
	}
	{on "overheat"
	     {if not tagged "destroyed"
		{set "overheating" 1}
		{set "overheating_1" 0}
		{set "overheating_2" 0}
		{delay 25
			{if flag "overheating" 
				{damage_report "body" "overheat"}
				{if rand 0.15
					{call "_burn"}
				}
				{set "overheating_1" 1}
			}
		}
		{delay 50
			{if flag "overheating_1" 
				{damage_report "body" "strong_overheat"}
				{if rand 0.15
					{call "_burn"}
				}
				{set "overheating_2" 1}
				{set "overheating_1" 0}
			}
		}
		{delay 75
			{if flag "overheating_2" 
				{call "fall"}
				{call "_burn"}
				{set "overheating_2" 0}
			}
		}
	     }
	}
	{on "delayed_fall"
		{set "delayed_fall" 1}
		{delay 18 "delayed_fall"
			{if flag "delayed_fall"
				{call "fall"}
			}
		}
	}
	{on "delayed_fall_long"
		{set "delayed_fall_long" 1}
		{delay 35 "delayed_fall_long"
			{if flag "delayed_fall_long"
				{call "fall"}
			}
		}
	}
	{on "fall" overload
		{if not flag "fall"
			{set "fall" 1}
			{if altitude 3
				{impulse up -1 cy 150}
				{if not altitude 30
					{ani_play "wheels" -0.2}
					{ani_play "basis" -2}
					{ani_stop "cwhs_hover"}
					{tags add "cwhs_landing"}
				}
				else
				{if not tagged "heli_in_flight" {impulse up 0.1}}
			}
			{delay 2
				{add_view "smoke_aero_dead_big" "fire" "body"}
				{view start "fire"}
				{delay 10
					{view stop "fire"}
				}
				{burn volume "body" fx "smoke_aero_big" time 10 fake}
				{burn volume "engine" fx "smoke_aero_big" time 10 fake}
				{delay 10.1
					{burn volume "body" fx "smoke_black" time 40 10 fake}
				}
			}
			{tags remove "air"}
			{ani_stop "cwhs_hover"}
		}
		{delay 10
			{set "fall" 0}
			{kill_crew}
			{call "mp_destroy"}
		}
	}

	{on ground_hit overload
		{spawn "spheredust_big_short"}
		{call "collide"}
		{constrain_velocity 40}
		{set "engine_started" 0}
	    {tags remove "engine_started"}
	    {ani_stop "engine_start"}
	    {ani_stop "engine_work"}
	    {play_sound "engine_stop"}
	    {ani_play "engine_stop" 0.1}
	    {stop_sound "engine_start"}
	    {stop_sound "engine_work"}	
	}
	{on "die"
		{chassis_work 0}
		{drop_orders}
		{call "engine_stop"}
		{stop_sound "fall"}
		{stop_sound "engine_stop"}
		{explosive 0}
		{burn stop}
		{bone hide "engine_work"}
		{tags add "destroyed"}
	}
	{on contact overload
		{if effector "vehicle"
			{call "collide"}
		else effector "stack"
		else effector "construction"
			{call "collide"}
		else effector "tree"
			{call "collide"}
		else effector "fence"
			{if volume "part"
				{call "tear_part"}
			}
		}
	}

	{on "collide" overload
		{view pause "flare_right"}
		{view pause "flare_left"}
		{view pause "chaff_right"}
		{view pause "chaff_left"}
		{if volume "body"
		     {if work "propeller" 
			{if velocity 93
				{call "explosion"}
				
			}
			{if velocity 87
				{kill_crew}
			}
;если сломан винт
		     else
			{if velocity 85
				{call "explosion"}
			}
			{if velocity 77
				{kill_crew}
			}
		     }

			{call "mp_destroy"}
		else volume "propeller_up"
			{call "tear_propeller_up"}
		else volume "propeller_down"
			{call "tear_propeller_down"}
		else volume "propeller_tail"
			{call "tear_propeller_tail"}
		else volume "wheelright"
			{call "tear_wheelright"}
		else volume "wheelleft"
			{call "tear_wheelleft"}
		else volume "wheelfront"
			{call "tear_wheelfront"}
		else volume "part"
			{call "tear_part"}
		}
	}
	{on "tear_propeller_up"
		{spawn "propeller_hit"}
		{spawn "propeller_hit2" "propeller" x}
		{spawn "propeller_hit2" "propeller" x}
		{spawn "propeller_hit2" "propeller" x}
		{ani_stop "engine_work"}
		{ani_play "engine_stop"}
;		{delay 0.1
;			{spawn "spheredust_big_short"}
			{components "propeller" destroy}
;			{volumes "propeller_up" disable all}
;			{volumes "propeller_up_part" enable all}
;			{tear "piece_big_airborne_wing" bone "propeller"
;				{impulse up 2 1 dir 2 1}
;			}
			{volumes "propeller_up" disable all}
			{volumes "propeller_up_part" disable all}
			{call "tear_propeller_up1"}
;		}
	}
	{on "tear_propeller_up1"
			{bone cut "propeller"}
	}
	{on "tear_propeller_down"
		{ani_stop "engine_work"}
		{ani_play "engine_stop"}
		{spawn "propeller_hit"}
		{spawn "propeller_hit2" "propeller1" x}
		{spawn "propeller_hit2" "propeller1" x}
		{spawn "propeller_hit2" "propeller1" x}
;		{delay 0.1
;			{spawn "spheredust_big_short"}
			{components "propeller" destroy}
;			{volumes "propeller_down" disable all}
;			{volumes "propeller_down_part" enable all}
;			{tear "piece_big_airborne_wing" bone "propeller1"
;				{impulse up 2 1 dir 2 1}
;			}
			{volumes "propeller_down" disable all}
			{volumes "propeller_down_part" disable all}
			{call "tear_propeller_down1"}
;		}
	}
	{on "tear_propeller_down1"
			{bone cut "propeller1"}
	}
	{on "tear_propeller_tail"
		{ani_stop "engine_work"}
		{ani_play "engine_stop"}
		{spawn "propeller_hit"}
		{spawn "propeller_hit3" "propeller1" x}
		{spawn "propeller_hit3" "propeller1" x}
		{spawn "propeller_hit3" "propeller1" x}
;		{delay 0.1
			{ani_stop "engine_work"}
;			{spawn "spheredust_big_short"}
			{components "tail_rotor" destroy}
;			{volumes "propeller_tail" disable all}
;			{volumes "propeller_tail_part" enable all}
;			{tear "piece_big_airborne_wing" bone "propeller_tail"
;				{impulse up 2 1 dir 2 1}
;			}
			{volumes "propeller_tail" disable all}
			{volumes "propeller_tail_part" disable all}
			{call "tear_propeller_tail1"}
;		}
		{call "fall"}
	}
	{on "tear_propeller_tail1"
			{bone cut "propeller1"}
	}
	{on "tear_wheelright" overload
		{spawn "spheredust_big_short"}
		{component destroy}
		{volume disable contact contact_ground}
		{tear "piece_big_airborne_wing" bone from_volume
			{impulse up 2 1 dir 2 1}
		}
	}
	{on "tear_wheelleft" overload
		{spawn "spheredust_big_short"}
		{component destroy}
		{volume disable contact contact_ground}
		{tear "piece_big_airborne_wing" bone from_volume
			{impulse up 2 1 dir 2 1}
		}
	}
	{on "tear_wheelfront" overload
		{spawn "spheredust_big_short"}
		{component destroy}
		{volume disable contact contact_ground}
		{tear "piece_big_airborne_wing" bone from_volume
			{impulse up 2 1 dir 2 1}
		}
	}
	{on "tear_part" overload
		{spawn "spheredust_big_short"}
		{component destroy}
		{volume disable contact contact_ground}
		{tear "piece_big_airborne_wing" bone from_volume
			{impulse up 2 1 dir 2 1}
		}
	}

	{on "_explosion" overload
		{link_sound "ground_crash"		"vehicle/Helicopter/crash/crash"}
		{play_sound "ground_crash"}
		{call "mp_destroy"}
		{view pause "flare_right"}
		{view pause "flare_left"}
		{view pause "chaff_right"}
		{view pause "chaff_left"}
		{kill_crew}
		{able select 0}
		{clear_inventory}
;		{remove_grass 4}
		{call "die"}
		{add_view "aero_die" "fire" "body"}
		{add_view "aero_die_fire" "fire" "body"}
		{view start "fire"}
		{spawn "aero_die_particle"}
		{tags add "destroyed"}
		{tags remove "air"}
		{ani_stop "cwhs_hover"}
		
		{impulse up 0.1 com}
		{delay 0.1
			(define "cut_part"
				{if rand %1
					{components %0 destroy }
					{tear "piece_big_airborne_wing" bone %0
						{impulse up 2 1 dir 2 1}
					}
				}
			)
			{delay_ex 0
				{set "no_burn_volumes" 1}
				{set_skeleton "_xx" sync}
				{ani_play "death"}

			}
			("cut_part" args "part1"		0.5)
			("cut_part" args "part2"		0.5)
			("cut_part" args "part3"		0.5)
			("cut_part" args "part4"		0.5)
			("cut_part" args "part5"		0.5)
			("cut_part" args "part6"		0.5)
			("cut_part" args "wingr1"		0.5)
			("cut_part" args "wingl1"		0.5)
			("cut_part" args "wingr2"		0.5)
			("cut_part" args "wingl2"		0.5)
			("cut_part" args "body_back"	0.5)
			("cut_part" args "propeller"	1.0)	;это названия костей, не волумов!
			("cut_part" args "propeller1"	1.0)
			("cut_part" args "tail_rotor"	1.0)
			{volumes "propeller" disable all}
			{volumes "propeller1" disable all}
			{volumes "propeller2" disable all}
			{volumes "propeller3" disable all}
			{volumes "propeller4" disable all}
			{volumes "propeller5" disable all}
			{volumes "propeller6" disable all}
			{volumes "propeller11" disable all}
			{volumes "propeller21" disable all}
			{volumes "propeller31" disable all}
			{volumes "propeller41" disable all}
			{volumes "propeller51" disable all}
			{volumes "propeller61" disable all}

			{volumes "propeller11_part" enable all}
			{volumes "propeller21_part" enable all}
			{volumes "propeller31_part" enable all}
			{volumes "propeller41_part" enable all}
			{volumes "propeller51_part" enable all}
			{volumes "propeller61_part" enable all}
			{volumes "propeller1_part" enable all}
			{volumes "propeller2_part" enable all}
			{volumes "propeller3_part" enable all}
			{volumes "propeller4_part" enable all}
			{volumes "propeller5_part" enable all}
			{volumes "propeller6_part" enable all}


			{volumes disable obstacle}
			{volumes "body" enable obstacle}
			{volumes "body_back" disable obstacle}
			{area rebuild}
			{delay 5
				{view pause "flare_right"}
				{view pause "flare_left"}
				{view pause "chaff_right"}
				{view pause "chaff_left"}
			}
		}
		{blastwave c4 7 r0 5 r1 8}
		{fire radius 8 time 4 heating 6}
	}
	{on "air_attack" overload
		{start_sound "vehicle/helicopter/low_pass" ambient}
		{call "drop_flares"}
		{delay 2
			{call "drop_flares"}
		}
		{delay 4
			{call "drop_flares"}
		}
		{tags add "air_attacking"}
		{delay 5 {tags remove "air_attacking"}}
	}
{on "update_power"
	{if not work "engine"
		{tags add "no_power"}
		{components "power_indicator" break}
	else not work "engine1"
	  {if not work "engine2"
		{tags add "no_power"}
		{components "power_indicator" break}
	  else {tags remove "no_power"} {components "power_indicator" repair}
	  }
	else {tags remove "no_power"} {components "power_indicator" repair}
	}
	{call "update_weaponry"}
}

	{on "IR_ff_missile_launch" 
		{weapon_work "IR_designator" 0}
		{delay 5 {call "update_weaponry"}}
	}

	{on fire "flare_dropper" overload
		{call "drop_flares"}
	}
	{on fire "gun" overload
		{view start "flashbarrel1"}
		{view start "shell"} {kill_delay "shell"}
		{delay 0.12 
			{view start "zenite_smoke"}
			{delay 8 5 {view pause "zenite_smoke"} }
		}
		{delay 0.2 "shell" {view pause "shell"} }
		{delay 0.42 {view pause "flashbarrel1"} }
		{ani_play "fire"}
	}
	{on fire "ptur" ("cw_check_shooting" weap_id(ptur))}
	{on fire "ptur1" ("cw_check_shooting" weap_id(ptur1))}
	{on fire "ptur2" ("cw_check_shooting" weap_id(ptur2))}
	{on fire "ptur3" ("cw_check_shooting" weap_id(ptur3))}
	{on fire "ptur4" ("cw_check_shooting" weap_id(ptur4))}
	{on fire "nar" ("cw_check_shooting" weap_id(nar))}
	{on fire "nar1" ("cw_check_shooting" weap_id(nar1))}
	{on fire "nar2" ("cw_check_shooting" weap_id(nar2))}
	{on fire "nar3" ("cw_check_shooting" weap_id(nar3))}
	{on fire "nar4" ("cw_check_shooting" weap_id(nar4))}
	{on fire "nar5" ("cw_check_shooting" weap_id(nar5))}
	{on fire "nar6" ("cw_check_shooting" weap_id(nar6))}
	
	
;==============================
;paradrop system by Timosh
	(define "paradrop_crew" 
;	     {if altitude 30
;		("paradrop_crew_with_alt" args %0 5)
;	      else altitude 25
;		("paradrop_crew_with_alt" args %0 4)
;	      else altitude 20
;		("paradrop_crew_with_alt" args %0 3)
;	      else altitude 12
;		("paradrop_crew_with_alt" args %0 2)
;	      else altitude 8
;		("paradrop_crew_with_alt" args %0 1)
;	      else 
;	      }
{with_linked_entity "%0"	{get_off}	    }
	)
;	(define "paradrop_crew_with_alt" 
;	     {with_linked_entity "%0"	{get_off}	    }
;	)
;==============================
	{on "passengers_off"
		{with_linked_entity "passenger00"	{get_off}	}
		{with_linked_entity "passenger01"	{get_off}	}
		{with_linked_entity "passenger02"	{get_off}	}
		{with_linked_entity "passenger03"	{get_off}	}
		{with_linked_entity "passenger04"	{get_off}	}
		{with_linked_entity "passenger05"	{get_off}	}
		{with_linked_entity "passenger06"	{get_off}	}
		{with_linked_entity "passenger07"	{get_off}	}
		{with_linked_entity "passenger08"	{get_off}	}
		{with_linked_entity "passenger09"	{get_off}	}
		{with_linked_entity "passenger10"	{get_off}	}
		{with_linked_entity "passenger11"	{get_off}	}
		{with_linked_entity "passenger12"	{get_off}	}
		{with_linked_entity "passenger13"	{get_off}	}
		{with_linked_entity "passenger14"	{get_off}	}
		{with_linked_entity "passenger15"	{get_off}	}
		{with_linked_entity "seat1"	{get_off}	}
		{with_linked_entity "seat2"	{get_off}	}
		{with_linked_entity "seat3"	{get_off}	}
		{with_linked_entity "seat4"	{get_off}	}
		{with_linked_entity "seat5"	{get_off}	}
		{with_linked_entity "seat6"	{get_off}	}
		{with_linked_entity "seat7"	{get_off}	}
		{with_linked_entity "seat8"	{get_off}	}
		{with_linked_entity "seat9"	{get_off}	}
		{with_linked_entity "seat01"	{get_off}	}
		{with_linked_entity "seat02"	{get_off}	}
		{with_linked_entity "seat03"	{get_off}	}
		{with_linked_entity "seat04"	{get_off}	}
		{with_linked_entity "seat05"	{get_off}	}
		{with_linked_entity "seat06"	{get_off}	}
		{with_linked_entity "seat07"	{get_off}	}
		{with_linked_entity "seat08"	{get_off}	}
		{with_linked_entity "seat09"	{get_off}	}
		{with_linked_entity "seat10"	{get_off}	}
		{with_linked_entity "seat11"	{get_off}	}
		{with_linked_entity "seat12"	{get_off}	}
		{with_linked_entity "seat13"	{get_off}	}
		{with_linked_entity "seat14"	{get_off}	}
		{with_linked_entity "seat15"	{get_off}	}
	}
	{on "paradrop"
		{call "passengers_off"}
		{delay 1 {call "passengers_off"}}
		{delay 2 {call "passengers_off"}}
		{delay 3 {call "passengers_off"}}
		{delay 4 {call "passengers_off"}}
		{delay 5 {call "passengers_off"}}
		{delay 6 {call "passengers_off"}}
		{delay 7 {call "passengers_off"}}
		{delay 8 {call "passengers_off"}}
		{delay 9 {call "passengers_off"}}
		{delay 10 {call "passengers_off"}}
		{delay 11 {call "passengers_off"}}
		{delay 12 {call "passengers_off"}}
		{delay 13 {call "passengers_off"}}
		{delay 14 {call "passengers_off"}}
		{delay 15 {call "passengers_off"}}
		{delay 16 {call "passengers_off"}}
		{delay 17 {call "passengers_off"}}
		{delay 18 {call "passengers_off"}}
		{delay 19 {call "passengers_off"}}

	}
	{on "specability"
;		{if chassis "airborne"
			{if not flag "specability"
				{set "specability" 1}
				{damage_report "body" "guided_weap_disabled"}
				{components "hweap_indicator" break}
				{call "update_weaponry"}
			else 
				{set "specability" 0}
				{damage_report "body" "guided_weap_enabled"}
				{components "hweap_indicator" repair}
				{call "update_weaponry"}
			}
;		else
;			;added until good air mechanics will exist
;			{tags remove "cw_autotakeoff_activated"}
;		}
		
	}
	
	{on "diagnostics"
		{if not work "wheel_back"
			{damage_report "wheel_back" "wheels_damaged"}
		else not work "retract_wheelR_damaged"
			{damage_report "retract_wheelR" "wheels_damaged"}
		else not work "retract_wheelL"
			{damage_report "retract_wheelL" "wheels_damaged"}
		}
		{if not work "engine"
			{damage_report "engine" "engine_damaged"}
		}
		{if not work "engine1"
			{damage_report "engine1" "engine1_damaged"}
		}
		{if not work "engine2"
			{damage_report "engine2" "engine2_damaged"}
		}
		{if not work "main_reductor" 
			{damage_report "main_reductor" "main_reductor_damaged"}
		}
		{if not work "propeller"
			{damage_report "propeller" "propeller_damaged"}
		}
		{if not work "tail_shaft" 
			{damage_report "tail_shaft" "tail_shaft_damaged"}
		}
		{if not work "tail_rotor" 
			{damage_report "tail_rotor" "tail_rotor_damaged"}
		}
		{if not work "pilot_panel"
			{damage_report "driver_panel" "driver_panel_damaged"}
		}
		{if not work "hydrosystem" 
			{damage_report "hydrosystem" "hydrosystem_damaged"}
		}
		{if not work "apu"
			{damage_report "apu" "apu_damaged"}
		}
		{if not work "ir_active_def"
			{damage_report "ir_active_def" "ir_active_def_damaged"}
		else not work "ir_active_def_2gen"
			{damage_report "ir_active_def_2gen" "ir_active_def:ir_active_def_damaged"}
		}
		{if not work "prpnk"
			{damage_report "prpnk" "prpnk_damaged"}
		}
		{if not work "gun"
			{damage_report "gun" "gun_damaged"}
		}
		{if not work "mgun"
			{damage_report "mgun" "mgun_damaged"}
		else not work "mgun1"
			{damage_report "mgun1" "mgun:mgun_damaged"}
		else not work "mgun2"
			{damage_report "mgun2" "mgun:mgun_damaged"}
		}
		{if not work "ptur"
			{damage_report "ptur" "ptur_damaged"}
		else not work "ptur1"
			{damage_report "ptur1" "ptur:ptur_damaged"}
		else not work "ptur2"
			{damage_report "ptur2" "ptur:ptur_damaged"}
		else not work "ptur3"
			{damage_report "ptur3" "ptur:ptur_damaged"}
		else not work "ptur4"
			{damage_report "ptur4" "ptur:ptur_damaged"}
		}
		{if not work "nar"
			{damage_report "nar" "nar_damaged"}
		else not work "nar1"
			{damage_report "nar1" "nar:nar_damaged"}
		else not work "nar2"
			{damage_report "nar2" "nar:nar_damaged"}
		else not work "nar3"
			{damage_report "nar3" "nar:nar_damaged"}
		else not work "nar4"
			{damage_report "nar4" "nar:nar_damaged"}
		else not work "nar5"
			{damage_report "nar5" "nar:nar_damaged"}
		else not work "nar6"
			{damage_report "nar6" "nar:nar_damaged"}
		}
		{if not work "flares1"
			{damage_report "flares1" "flares:flares_damaged"}
		else not work "flares2"
			{damage_report "flares2" "flares:flares_damaged"}
		}
		{if not work "chaff1"
			{damage_report "chaff1" "chaff:chaff_damaged"}
		else not work "chaff2"
			{damage_report "chaff2" "chaff:chaff_damaged"}
		}
		{if not work "electronics"     
				{damage_report "electronics" "electronics_damaged"}
		}
	}	
}

{"heli_speed_60"
	{on "max_speed" {tags add "cwhs_speed_60"}}
	{on "cwhs_change_speed"
		{if tagged "cwhs_accelerate_me"
			{if velocity 54 {tags add "cwhs_speed_60"}  {delay 0.2 {tags remove "cwhs_accelerate_me"}{components "hover" break}  {components "hover" repair}}
			else velocity 49 {tags add "cwhs_speed_55"}	else velocity 44 {tags add "cwhs_speed_50"}
			else velocity 39 {tags add "cwhs_speed_45"}	else velocity 34 {tags add "cwhs_speed_40"}
			else velocity 29 {tags add "cwhs_speed_35"}	else velocity 19 {tags add "cwhs_speed_30"}
			else velocity 9 {tags add "cwhs_speed_20"}	else {tags add "cwhs_speed_10"}
			}
		else  tagged "cwhs_deccelerate_me"
			{if velocity 59 {tags add "cwhs_speed_55"}	else velocity 54 {tags add "cwhs_speed_50"}
			else velocity 49 {tags add "cwhs_speed_45"}	else velocity 44 {tags add "cwhs_speed_40"}
			else velocity 39 {tags add "cwhs_speed_35"}	else velocity 34 {tags add "cwhs_speed_30"}
			else velocity 29 {tags add "cwhs_speed_20"}	else velocity 19 {tags add "cwhs_speed_10"}
			else velocity 9 {tags add "cwhs_speed_1"} {tags add "cwhs_hovering"} {delay 0.2 {tags remove "cwhs_deccelerate_me"}}
			}
		}
	}
}
{"heli_speed_55"
	{on "max_speed" {tags add "cwhs_speed_55"}}
	{on "cwhs_change_speed"
		{if tagged "cwhs_accelerate_me"
			{if velocity 49 {tags add "cwhs_speed_55"} {delay 0.2 {tags remove "cwhs_accelerate_me"}{components "hover" break}  {components "hover" repair}}
			else velocity 44 {tags add "cwhs_speed_50"}
			else velocity 39 {tags add "cwhs_speed_45"}	else velocity 34 {tags add "cwhs_speed_40"}
			else velocity 29 {tags add "cwhs_speed_35"}	else velocity 19 {tags add "cwhs_speed_30"}
			else velocity 9 {tags add "cwhs_speed_20"}	else {tags add "cwhs_speed_10"}
			}
		else  tagged "cwhs_deccelerate_me"
			{if velocity 54 {tags add "cwhs_speed_50"}
			else velocity 49 {tags add "cwhs_speed_45"}	else velocity 44 {tags add "cwhs_speed_40"}
			else velocity 39 {tags add "cwhs_speed_35"}	else velocity 34 {tags add "cwhs_speed_30"}
			else velocity 29 {tags add "cwhs_speed_20"}	else velocity 19 {tags add "cwhs_speed_10"}
			else velocity 9 {tags add "cwhs_speed_1"} {tags add "cwhs_hovering"} {delay 0.2 {tags remove "cwhs_deccelerate_me"}}
			}
		}
	}
}	
{"heli_speed_50"
	{on "max_speed" {tags add "cwhs_speed_50"}}
	{on "cwhs_change_speed"
		{if tagged "cwhs_accelerate_me"
			{if velocity 44 {tags add "cwhs_speed_50"} {delay 0.2 {tags remove "cwhs_accelerate_me"}{components "hover" break}  {components "hover" repair}}
			else velocity 39 {tags add "cwhs_speed_45"}	else velocity 34 {tags add "cwhs_speed_40"}
			else velocity 29 {tags add "cwhs_speed_35"}	else velocity 19 {tags add "cwhs_speed_30"}
			else velocity 9 {tags add "cwhs_speed_20"}	else {tags add "cwhs_speed_10"}
			}
		else  tagged "cwhs_deccelerate_me"
			{if velocity 49 {tags add "cwhs_speed_45"}	else velocity 44 {tags add "cwhs_speed_40"}
			else velocity 39 {tags add "cwhs_speed_35"}	else velocity 34 {tags add "cwhs_speed_30"}
			else velocity 29 {tags add "cwhs_speed_20"}	else velocity 19 {tags add "cwhs_speed_10"}
			else velocity 9 {tags add "cwhs_speed_1"} {tags add "cwhs_hovering"} {delay 0.2 {tags remove "cwhs_deccelerate_me"}}
			}
		}
	}
}	
{"heli_speed_45"
	{on "max_speed" {tags add "cwhs_speed_45"}}
	{on "cwhs_change_speed"
		{if tagged "cwhs_accelerate_me"
			{if velocity 39 {tags add "cwhs_speed_45"} {delay 0.2 {tags remove "cwhs_accelerate_me"}{components "hover" break}  {components "hover" repair}}
			else velocity 34 {tags add "cwhs_speed_40"}
			else velocity 29 {tags add "cwhs_speed_35"}	else velocity 19 {tags add "cwhs_speed_30"}
			else velocity 9 {tags add "cwhs_speed_20"}	else {tags add "cwhs_speed_10"}
			}
		else  tagged "cwhs_deccelerate_me"
			{if velocity 44 {tags add "cwhs_speed_40"}
			else velocity 39 {tags add "cwhs_speed_35"}	else velocity 34 {tags add "cwhs_speed_30"}
			else velocity 29 {tags add "cwhs_speed_20"}	else velocity 19 {tags add "cwhs_speed_10"}
			else velocity 9 {tags add "cwhs_speed_1"} {tags add "cwhs_hovering"} {delay 0.2 {tags remove "cwhs_deccelerate_me"}}
			}
		}
	}
}	
{"heli_speed_40"
	{on "max_speed" {tags add "cwhs_speed_40"}}
	{on "cwhs_change_speed"
		{if tagged "cwhs_accelerate_me"
			{if velocity 34 {tags add "cwhs_speed_40"} {delay 0.2 {tags remove "cwhs_accelerate_me"}{components "hover" break}  {components "hover" repair}}
			else velocity 29 {tags add "cwhs_speed_35"}	else velocity 19 {tags add "cwhs_speed_30"}
			else velocity 9 {tags add "cwhs_speed_20"}	else {tags add "cwhs_speed_10"}
			}
		else  tagged "cwhs_deccelerate_me"
			{if velocity 39 {tags add "cwhs_speed_35"}	else velocity 34 {tags add "cwhs_speed_30"}
			else velocity 29 {tags add "cwhs_speed_20"}	else velocity 19 {tags add "cwhs_speed_10"}
			else velocity 9 {tags add "cwhs_speed_1"} {tags add "cwhs_hovering"} {delay 0.2 {tags remove "cwhs_deccelerate_me"}}
			}
		}
	}
}	
{"heli_speed_35"
	{on "max_speed" {tags add "cwhs_speed_35"}}
	{on "cwhs_change_speed"
		{if tagged "cwhs_accelerate_me"
			{if velocity 29 {tags add "cwhs_speed_35"} {delay 0.2 {tags remove "cwhs_accelerate_me"}{components "hover" break}  {components "hover" repair}}
			else velocity 19 {tags add "cwhs_speed_30"}
			else velocity 9 {tags add "cwhs_speed_20"}	else {tags add "cwhs_speed_10"}
			}
		else  tagged "cwhs_deccelerate_me"
			{if velocity 34 {tags add "cwhs_speed_30"}
			else velocity 29 {tags add "cwhs_speed_20"}	else velocity 19 {tags add "cwhs_speed_10"}
			else velocity 9 {tags add "cwhs_speed_1"} {tags add "cwhs_hovering"} {delay 0.2 {tags remove "cwhs_deccelerate_me"}}
			}
		}
	}
}	
{"heli_speed_30"
	{on "max_speed" {tags add "cwhs_speed_30"}}
	{on "cwhs_change_speed"
		{if tagged "cwhs_accelerate_me"
			{if velocity 19 {tags add "cwhs_speed_30"} {delay 0.2 {tags remove "cwhs_accelerate_me"}{components "hover" break}  {components "hover" repair}}
			else velocity 9 {tags add "cwhs_speed_20"}	else {tags add "cwhs_speed_10"}
			}
		else  tagged "cwhs_deccelerate_me"
			{if velocity 29 {tags add "cwhs_speed_20"}	else velocity 19 {tags add "cwhs_speed_10"}
			else velocity 9 {tags add "cwhs_speed_1"} {tags add "cwhs_hovering"} {delay 0.2 {tags remove "cwhs_deccelerate_me"}}
			}
		}
	}
}	

{"heli_with_ropes"
	{on spawn
		{if not flag "specability"
			{bone hide "ropel"}{bone hide "roper"}
			{ani_wind "down_ropel1" begin}
			{ani_wind "down_ropel2" begin}
			{ani_wind "down_ropel3" begin}
			{ani_wind "down_ropel4" begin}
			{ani_wind "down_ropel5" begin}
			{ani_wind "down_roper1" begin}
			{ani_wind "down_roper2" begin}
			{ani_wind "down_roper3" begin}
			{ani_wind "down_roper4" begin}
			{ani_wind "down_roper5" begin}
		}
	}
	{on "specability" overload
		{if chassis "airborne"
			{if not flag "specability"
				{if not velocity 5
					{if not altitude 16
						{set "specability" 1} {bone show "ropel"}{bone show "roper"} {tags add "ropes_down"}
					}
				}
			else 
				{call "ropes_up"}
			}
		;still doesn't work with helis
		else chassis "helicopter"
			{if not flag "specability"
				{if not velocity 5
					{if not altitude 16
						{set "specability" 1} {bone show "ropel"}{bone show "roper"} {tags add "ropes_down"}
					}
				}
			else 
				{call "ropes_up"}
			}
		;still doesn't work with helis
		else
			;added until good air mechanics will exist
			;{tags remove "cw_autotakeoff_activated"}
		}
	}
	{on "specability_on"
			{if not velocity 5
				{if not altitude 16
					{set "specability" 1} {bone show "ropel"}{bone show "roper"} {tags add "ropes_down"}
				}
			}
	}

	{on "landing"
		{call "ropes_up"}
	}
	{on "engine_stop"
		{call "ropes_up"}
	}
	{on "fall"
		{bone show "ropel"}{bone show "roper"}
		{call "ropes_up"}
	}
	(define "remove_alt_tags"
		{tags remove "ropes_alt1"}{tags remove "ropes_alt2"}{tags remove "ropes_alt3"}{tags remove "ropes_alt4"}{tags remove "ropes_alt5"}
		{tags remove "ropes_need_seg1"}{tags remove "ropes_need_seg2"}{tags remove "ropes_need_seg3"}
		{tags remove "ropes_need_seg4"}{tags remove "ropes_need_seg5"}
	)


	(define "check_rope_part"
		{if tagged "ropes_seg%0" 
			{if not tagged "ropes_need_seg%0" 
				{ani_play "down_ropel%0" -0.2}{ani_play "down_roper%0" -0.2} {tags remove "ropes_seg%0"}
				{ani_stop "rope_driftl%0"} {ani_stop "rope_driftr%0"}
			}
		else 
			{if tagged "ropes_need_seg%0" 
				{ani_play "rope_driftl%0" 0.2 loop} {ani_play "rope_driftr%0" 0.2 loop}
				{ani_play "down_ropel%0" 0.2}{ani_play "down_roper%0" 0.2} {tags add "ropes_seg%0"}

			}
		}
	)

	(define "change_length"
		("check_rope_part" args 1)("check_rope_part" args 2)("check_rope_part" args 3)("check_rope_part" args 4)("check_rope_part" args 5)
	)
	{on "ropes_up"
		("remove_alt_tags"){tags remove "ropes_down"} {set "specability" 0} ("change_length")
	}
	{on "ropes_down"
		{tags add "ropes_need_seg1"}{tags add "ropes_need_seg2"}{tags add "ropes_need_seg3"}
		{tags add "ropes_need_seg4"}{tags add "ropes_need_seg5"}
		{tags add "ropes_alt5"}("change_length")
	}
	{on "check_altitude"
	     {if tagged "ropes_down"
		("remove_alt_tags")
		{if altitude 16
			{call "ropes_up"}
		else velocity 5
			{call "ropes_up"}
		else altitude 13
			{tags add "ropes_need_seg1"}{tags add "ropes_need_seg2"}{tags add "ropes_need_seg3"}
			{tags add "ropes_need_seg4"}{tags add "ropes_need_seg5"}
			{tags add "ropes_alt5"}("change_length")
		else altitude 10
			{tags add "ropes_need_seg1"}{tags add "ropes_need_seg2"}{tags add "ropes_need_seg3"}
			{tags add "ropes_need_seg4"}
			{tags add "ropes_alt4"}("change_length")
		else altitude 7
			{tags add "ropes_need_seg1"}{tags add "ropes_need_seg2"}{tags add "ropes_need_seg3"}
			{tags add "ropes_alt3"}("change_length")
		else altitude 4
			{tags add "ropes_need_seg1"}{tags add "ropes_need_seg2"}
			{tags add "ropes_alt2"}("change_length")
		else altitude 1
			{tags add "ropes_need_seg1"}
			{tags add "ropes_alt1"}("change_length")

		}
	       }
	}
}

{"with_vitebsk"
	{on spawn
		{add_view	"shtora_work"	"vitebsk1"	"vitebsk1"}
		{add_view	"shtora_work"	"vitebsk2"	"vitebsk2"}
		{add_view	"shtora_work"	"vitebsk3"	"vitebsk3"}
	}
	(define "vitebsk_work"
	{if rand 1
		    ;("cwps3_stop" country(rus) type(ir))
		    ;("cwps3_stop" country(usa) type(ir))
	    {delay 0.5
			{spawn "proj_point_usa_ir"  "basis" x
				{impulse up 0 10 rnd_dir 20 com}
				{gravity 0.5}
				{tags add "proj_vitebsk"}
				 {kill_delay "normal_hide" }
					 {delay 1.5 {delete}}
			}
		
			{spawn "proj_point_rus_ir"  "basis" x
				{impulse up 0 10 rnd_dir 20 com}
				{gravity 0.5}
				 {kill_delay "normal_hide" }
				    {delay 1.5 {delete}}
			}
		}
	}
	)
	{on fire "soep1"
		("vitebsk_work")
		{view show "vitebsk1"}
		{view start "vitebsk1"}
		{delay 0.3
			{view hide "vitebsk1"}
		}
	}
	{on fire "soep2"
		("vitebsk_work")
		{view show "vitebsk2"}
		{view start "vitebsk2"}
		{delay 0.3
			{view hide "vitebsk2"}
		}
	}
	{on fire "soep3"
		("vitebsk_work")
		{view show "vitebsk3"}
		{view start "vitebsk3"}
		{delay 0.3
			{view hide "vitebsk3"}
		}
	}
	{on break
		{if component "ir_active_def_2gen"
			{weapon_work "soep1" 0}	{weapon_work "soep2" 0}	{weapon_work "soep3" 0}
		}
	}
	{on repair
		{if component "ir_active_def_2gen"
			{weapon_work "soep1" 1}	{weapon_work "soep2" 1}	{weapon_work "soep3" 1}
		}
	}	
}



(include "helicopter_modern.inc")