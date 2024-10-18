;==========================================================
;KAZ system by Timosh
;==========================================================
(define "low_speed_bullet"
	{tags add "low_speed_bullet"}
	{delay 0.5 {tags remove "low_speed_bullet"}}
)
(define "hksmoke"
	{if bone "foresight%foresight"
	    {spawn "startsmoke" "foresight%foresight" x}
	    {spawn "smoke_shell_fly" "foresight%foresight" x 
			{impulse up 50 2 forward 100 rnd_dir 2.5 com}
			{gravity 0.9}
			{delay 0.1
				{physics_work 0}
			}
			{delay 0.5
				{spawn "ex_smokeshell"}
				{spawn "smoke_volume"}
				{delete}
			}
	    }
	}
)
;=========================================================
{"explosion_throw_crew vehicle"
	{on "_explosion"
		{crew_throw_off up 4 1 dir 5 1 turn 0 180 forward 2 rnd_die 0.5}
	}
}
{"turret_rotator"
	{on spawn
		{set "rotate_turret" 0}
	}
	{on ik begin "turret"
		{kill_delay "rotate_turret"}
		{if not flag "rotate_turret"
			{play_sound "rotate_turret" 1}
			{set "rotate_turret" 1}
		}
	}
	{on ik end "turret"
		{delay 0.5 "rotate_turret"
			{stop_sound "rotate_turret"}
			{set "rotate_turret" 0}
		}
	}
	
}

{"vehicle_common"
	{inflammation_time 10}
	{on spawn
		{add_view	"stop_signal"	"stop_signal"	"fxstop1"}
		{add_view	"stop_signal"	"stop_signal"	"fxstop2"}
		{add_view	"stop_signal"	"stop_signal"	"fxstop3"}
		{add_view	"stop_signal"	"stop_signal"	"fxstop4"}
		

		{add_view 	"headlight"	"lightl"		"headlightl"}
		{add_view 	"headlight"	"lightr"		"headlightr"}
		{add_view 	"headlight"	"lightt"		"turret_light"}
		{add_view 	"headlight"	"lightt1"		"turret_light1"}
		{add_view 	"headlight"	"lightt2"		"turret_light2"}
		{add_view 	"light_vehicle"	"light_ground"		"fxlight"}
		{add_view 	"light_vehicle"	"light_ground"		"fxlight1"}
		{add_view 	"light_vehicle"	"light_ground"		"fxlight2"}

		{link_sound "round_sandbag" "fortification/install/reinforcement_sandbags_install"}
		{link_sound "camouflage" 	"fortification/install/camouflage_bushes_install"}
		{link_sound "build_supp_point" 	"fortification/install/field_warehouse_install"}
		{link_sound "trailer_link" 	"vehicle/gun_clutch_in"}
		{link_sound "detach" 		"vehicle/gun_clutch_out"}

		{link_sound "track_broken"	"vehicle/tracks_broken_clunk"}
		{link_sound "engine_broken"	"vehicle/engine_broken"}

		{view hide "stop_signal"}
		{view hide "light"}
		{view hide "lightl"}
		{view hide "lightr"}
		{view hide "lightt"}
		{view hide "lightt1"}
		{view hide "lightt2"}
		{view hide "light_ground"}
		{view hide "highlight"}

		{call "init_gun"}
		{call "init_gun1"}
		{call "init_gun2"}
		{call "init_mgun"}
		{call "init_mgun1"}
		{call "init_mgun2"}
		{call "init_mgun3"}
		{call "add_movement_sound"}
		{call "add_hatch_sound"}
		{call "update_moveable"}
		{set "stop" 0}	;lights are off on spawn
		{call "update_lights"}
		{set "burn_fire" 0}
		{call "update_hatch_on_spawn"}
		{call "cwps_semi_rem_tags"}
		{crew_enable place "cwps_proj_point" 0}
		{crew_enable place "nisha_link" 0}
		{if flag "crew_tempdisabled"
		   {crew_enable place "driver" 1}
		   {crew_enable place "driver1" 1}
		   {crew_enable place "gunner" 1}	
		   {crew_enable place "gunner1" 1}	
		   ;{crew_enable place "gunner2" 1}	
		   {crew_enable place "charger" 1}	
		   {crew_enable place "commander" 1}	
		   {crew_enable place "commander1" 1}
		}
	   {tags remove "smoke_reload"}
		{tags remove "pierce_damage_contusion_1"}	
	}
	{on "init_gun"
		{add_view	 "grenade_tail"	"smoke_mgun"                      "foresight3"}
		{add_view	 "flash_gun_big"	"flashbarrel3"	"foresight3"}
		{add_view	 "flash_gun_big"	"flashbarrel4"	"foresight4"}
		{add_view	 "flash_gun_big"	"flashbarrel5"	"foresight5"}
		{add_view	 "flash_gun_big"	"flashbarrel6"	"foresight6"}
		{add_view	 "flash_gun_big"	"flashbarrel7"	"foresight7"}
		{add_view	 "flash_cannon_small"	"flashbarrel20"	"foresight20"}
		{add_view	 "flash_cannon_small"	"flashbarrel21"	"foresight21"}
	}
	{on "stop_on"
		{ani_stop "start"}
		{ani_play "stop"}
	}
	{on "stop_signal_on"
		{if not tagged "no_power"
			{view show "stop_signal"}
			{view start "stop_signal"}
		}
	}
	{on "stop_signal_off"
		{view hide "stop_signal"}
	}
	{on "exhaust_on"
		{play_sound "exhaust" 1}
		{view start "exhaust"}
	}
	{on "exhaust_off"
		{stop_sound "exhaust"}
		{view pause "exhaust"}
	}
	
	{on turn on
		{call "stop_on"}
		{call "exhaust_on"}
	}
	{on turn off
		{call "exhaust_off"}
	}
	{on move on
		{stop_sound "move_end"}
		{play_sound "move" 1}
		{call "exhaust_on"}
		{ani_stop "stop"}
		{ani_play "start"}
	}
	{on move off
		{stop_sound "move"}
		{play_sound "move_end"}
		{call "exhaust_off"}
	}
	{on accelerate on
		{call "exhaust_on"}
		{if move_backward
			{call "stop_signal_on"}
		}
	}
	{on accelerate off
		{call "exhaust_off"}
		{if move_backward
			{call "stop_signal_off"}
		}
	}
	{on brake on
		{call "stop_on"}
		{call "stop_signal_on"}
	}
	{on brake off
		{call "stop_signal_off"}
	}
	{on engine on
		{kill_delay "engine_stopped"}
		{kill_delay "engine_steam_stopped"}
		{stop_sound "engine_end"}
		{play_sound "engine" 1}
		{set "engine_started" 1}
		{view start "engine_steam"}

	}
	{on engine off
		{delay 2 "engine_stopped"
			{stop_sound "engine"}
			{play_sound "engine_end"}
			{set "engine_started" 0}
		}
		{delay 12 "engine_steam_stopped"
			{view pause "engine_steam"}
		}
	}
	{on pierce
	    {if tagged "body_brake"
		    {if not stuff "bullet"
	        {call "mp_destroy"}
	        }
	    }
	}

;==========CW projectile system part by Timosh
	(include "flares_and_chaff.inc")
	
	(define "proj_point_spawn_distributor"
		{with_effector
			{if tagged "launch_00" 
				{with_effector {spawn "proj_point_%bomb_gps_ground_00" ("proj_point_settings")}}
			else tagged "launch_01" 
				{with_effector  {spawn "proj_point_%bomb_gps_ground_01" ("proj_point_settings")}}
			else tagged "launch_02" 
				{with_effector  {spawn "proj_point_%bomb_gps_ground_02" ("proj_point_settings")}}
			else tagged "launch_03" 
				{with_effector  {spawn "proj_point_%bomb_gps_ground_03" ("proj_point_settings")}}
			else tagged "launch_04" 
				{with_effector  {spawn "proj_point_%bomb_gps_ground_04" ("proj_point_settings")}}
			else tagged "launch_05" 
				{with_effector  {spawn "proj_point_%bomb_gps_ground_05" ("proj_point_settings")}}
			else tagged "launch_06" 
				{with_effector  {spawn "proj_point_%bomb_gps_ground_06" ("proj_point_settings")}}
			else tagged "launch_07" 
				{with_effector  {spawn "proj_point_%bomb_gps_ground_07" ("proj_point_settings")}}
			else tagged "launch_08" 
				{with_effector  {spawn "proj_point_%bomb_gps_ground_08"("proj_point_settings")}}
			else tagged "launch_09" 
				{with_effector  {spawn "proj_point_%bomb_gps_ground_09" ("proj_point_settings")}}
			else tagged "launch_10" 
				{with_effector  {spawn "proj_point_%bomb_gps_ground_10" ("proj_point_settings")}}
			else tagged "launch_11" 
				{with_effector  {spawn "proj_point_%bomb_gps_ground_11" ("proj_point_settings")}}
			else tagged "launch_12" 
				{with_effector  {spawn "proj_point_%bomb_gps_ground_12" ("proj_point_settings")}}
			else tagged "launch_13" 
				{with_effector  {spawn "proj_point_%bomb_gps_ground_13" ("proj_point_settings")}}
			else tagged "launch_14" 
				{with_effector  {spawn "proj_point_%bomb_gps_ground_14" ("proj_point_settings")}}
			else tagged "launch_15" 
				{with_effector  {spawn "proj_point_%bomb_gps_ground_15" ("proj_point_settings")}}	
			}
		} 
	)
	(define "proj_point_settings"
		"root"
		{tags add "gps_target"} 
		{tags add "cwps_ground_attack"} 
		(mod "mp"{player 1}) 
		(mod not "mp"{player 7}) 
		{delay 25 {delete}}
	)
	(include "/lists/glide_bomb.inc")
	
	{on bullet_hit
		{if stuff "blinding_laser"
			{tags add "blinding_laser"}
			{ani_wind "visor1" end}{ani_wind "visor2" end}{ani_wind "visor3" end}{ani_wind "visor4" end}
			{ani_wind "visor5" end}{ani_wind "visor6" end}{ani_wind "visor7" end}{ani_wind "visor8" end}
			{tags add "no_missile_control"}
			{kill_delay "blinding_laser"}
			{delay 2 "blinding_laser"
				{tags remove "blinding_laser"}
				{if work "driver_triplex" {ani_wind "visor2" begin}{ani_wind "visor90deg_2" begin}}
				{if work "commander_triplex" {ani_wind "visor1" begin}{ani_wind "visor90deg_1" begin}}
				{if work "additional_triplex" {ani_wind "visor3" begin}{ani_wind "visor90deg_3" begin}}
				{if work "additional_triplex1" {ani_wind "visor4" begin}{ani_wind "visor90deg_4" begin}}
				{if work "additional_triplex2" {ani_wind "visor5" begin}{ani_wind "visor90deg_5" begin}}
				{if work "additional_triplex3" {ani_wind "visor6" begin}{ani_wind "visor90deg_6" begin}}
				{if work "additional_triplex4" {ani_wind "visor7" begin}{ani_wind "visor90deg_7" begin}}
				{if work "additional_triplex5" {ani_wind "visor8" begin}{ani_wind "visor90deg_8" begin}}
				{call "update_weaponry"}
				{call "update_power"}
			}
		("list_glide_bomb_inc")
		else stuff "proj_pointer" {call "check_proj_type"}
;===================== Allows ATGM to hit the player-selected zones	
			{if not tagged "cannon_proj"	
				{if stuff "ground_laser_rus" {spawn "proj_point_rus_laser_acc" (mod "mp"{player 1}) (mod not "mp"{player 7})
				{delay 10 {delete}}}
				}
				{if stuff "ground_laser_usa" {spawn "proj_point_usa_laser_acc" (mod "mp"{player 1}) (mod not "mp"{player 7})
				{delay 10 {delete}}}
				}
				{if stuff "rus_laser_spot" {spawn "proj_point_rus_laser_des_ground" (mod "mp"{player 1}) (mod not "mp"{player 7})
				{delay 5 {delete}}}
				}
				{if stuff "usa_laser_spot" {spawn "proj_point_usa_laser_des_ground" (mod "mp"{player 1}) (mod not "mp"{player 7})
				{delay 5 {delete}}}
				}
				{if stuff "ground_other_rus" {spawn "proj_point_rus_other_acc" (mod "mp"{player 1}) (mod not "mp"{player 7})
				{delay 10 {delete}}}
				}
				{if stuff "ground_other_usa" {spawn "proj_point_usa_other_acc" (mod "mp"{player 1}) (mod not "mp"{player 7})
				{delay 10 {delete}}}
				}
				{if stuff "ground_other_usa_far" {spawn "proj_point_usa_other_acc" (mod "mp"{player 1}) (mod not "mp"{player 7})
				{delay 27 {delete}}}
				}
				
				{if stuff "ground_active_rus" {spawn "proj_point_rus_active_acc" (mod "mp"{player 1}) (mod not "mp"{player 7})
				{delay 10 {delete}}}
				}
				{if stuff "ground_active_usa" {spawn "proj_point_usa_active_acc" (mod "mp"{player 1}) (mod not "mp"{player 7})
				{delay 10 {delete}}}
				}
				
				{if stuff "ground_ir_rus" {spawn "proj_point_rus_ir_acc" (mod "mp"{player 1}) (mod not "mp"{player 7})
				{delay 10 {delete}}}
				}
				{if stuff "ground_ir_usa" {spawn "proj_point_usa_ir_acc" (mod "mp"{player 1}) (mod not "mp"{player 7})
				{delay 10 {delete}}}
				}
			}		
;=====================	
		else volume "LampL" {if work "LampL" {spawn "glass_hit"} {components "LampL" break}}
		else  volume "LampR" {if work "LampR" {spawn "glass_hit"} {components "LampR" break}}
		else  volume "LampT" {if work "LampT" {spawn "glass_hit"} {components "LampT" break}}
		else  volume "LampT1" {if work "LampT1" {spawn "glass_hit"} {components "LampT1" break}}
		else  volume "LampT2" {if work "LampT2" {spawn "glass_hit"} {components "LampT2" break}}
		}
		{if stuff "hesh_type_dmg" {spawn "cw_cumulative_frestrict" inv_normal}
		else stuff "cm_type_dmg cm" {spawn "rpg_restrictor" inv_normal}}
;=============end of CW projectile system part
	}
	
	{on break
		{if component "body"
			{call "stat_break"}
		}
		{call "update_moveable"}
		{call "update_lights"}
	}
	{on repair
		{call "update_moveable"}
		{call "update_lights"}
		{able "burning" 0}
		{able "sinking" 0}
		(mod "mp"  
		{if tagged "break_manager"  
		    {tags remove "break_manager"}
		}
		)
	}
    {on "check_body_break"
	    {delay 600 
		    {if tagged "break_manager" 
		        {call "mp_destroy"}
				{tags remove "break_manager"}
		    }
		}
	}
	{on "break_light"
		{if component "engine"
			{bone cut "headlightL"}
			{bone cut "headlightR"}
			{bone cut "fxlight"}
		}
	}
	{on "repair_light"
		{if component "engine"}
	}
	{on "lights_on"
	  {if not flag "stop"
		{set "stop" 1}	;lights are on
		{if work "LampL" {view start "lightL"} {view show "lightL"}
		else {view stop "lightL"} {view hide "lightL"} }
		{if work "LampR" {view start "lightR"} {view show "lightR"}
		else {view stop "lightR"} {view hide "lightR"} }
		{if work "LampT" {view start "lightT"} {view show "lightT"}
		else {view stop "lightT"} {view hide "lightT"} }
		{if work "LampT1" {view start "lightT1"} {view show "lightT1"}
		else {view stop "lightT1"} {view hide "lightT1"} }
		{if work "LampT2" {view start "lightT2"} {view show "lightT2"}
		else {view stop "lightT2"} {view hide "lightT2"} }
		{view start "light"}
		{view show "light"}
	   }
	   {call "check_ground_lights"}
		
	}
	{on "check_ground_lights"
		{if not work "lampl"
			{if not work "lampr"
				{view stop "light_ground"}
				{view hide "light_ground"}
			else
				{view start "light_ground"}
				{view show "light_ground"}
			}
		else
			{view start "light_ground"}
			{view show "light_ground"}
		}
	}
	{on "lights_off"
		{set "stop" 0}	;lights are off
		{view stop "light"}
		{view hide "light"}
		{view stop "light_ground"}
		{view hide "light_ground"}	
		{view stop "lightL"}
		{view hide "lightL"}
		{view stop "lightR"}
		{view hide "lightR"}
		{view stop "lightT"}
		{view hide "lightT"}
		{view stop "lightT1"}
		{view hide "lightT1"}
		{view stop "lightT2"}
		{view hide "lightT2"}
	}
	{on "update_lights" overload
		{if not sunlight
			{if operatable
			      {if not chassis "airborne"
			        {if not tagged "no_power"
					  {if not tagged "cwsh_zpu_off"
						{call "lights_on"}
					  else {call "lights_off"}
					  }
			        else {call "lights_off"}
			        }
			       else
					{call "lights_off"}
			      }
			else
				{call "lights_off"}
			}
		else
			{call "lights_off"}
		}
		{if rain 
			{if operatable {ani_play "rain" 0.5 loop} 
			else {ani_stop "rain"}}
		else {ani_stop "rain"}}
		{call "update_crew"}
		{if withdrawn_recovering {call "repair_d_a"}}
	}
	{on "start_update_lights"
		{call "update_lights"}
		{delay 5 2 "update_lights"
			{call "start_update_lights"}
		}
	}
	{on "update_crew"
		(define "tags_remove"
			{tags remove "cwcs_%place_master"}		;obsolete
			{tags remove "cwcs_%place_expert"}		;obsolete
			{tags remove "cwcs_%place_advanced"}	;obsolete
			{tags remove "cwcs_%place_basic"}		;obsolete
			{tags remove "cwcs_%place_none"}		;obsolete
			{tags remove "cwcs_master"}
			{tags remove "cwcs_expert"}
			{tags remove "cwcs_advanced"}
			{tags remove "cwcs_basic"}
			{tags remove "cwcs_none"}
		)
		("tags_remove" place(driver))
		("tags_remove" place(gunner))
		("tags_remove" place(commander))
		("tags_remove" place(charger))
		(define "check_crew_ability"
			{with_linked_entity "%place"
				{call "check_level_%skill"}
			}		
		)
		(define "check_ground_veh"
			("check_crew_ability" place(driver) skill(%skill))
			("check_crew_ability" place(gunner) skill(%skill))
			("check_crew_ability" place(commander) skill(%skill))
			("check_crew_ability" place(charger) skill(%skill))
			("check_crew_ability" place(gunner2) skill(%skill))
			("check_crew_ability" place(charger) skill(%skill))
			("check_crew_ability" place(commander1) skill(%skill))
		)
		
		{if props "skill_override_tank" ("check_ground_veh" skill(skill_tank))
		else props "skill_override_apc" ("check_ground_veh" skill(skill_apc))
		else props "skill_override_car" ("check_ground_veh" skill(skill_car))
		else props "skill_override_stan" ("check_ground_veh" skill(skill_stan))
		else props "skill_override_airborne" ("check_ground_veh" skill(skill_plane))
		else props "medium_m" or props "heavy_m"
			("check_ground_veh" skill(skill_tank))
		else props "armored_car_m" or props "light_m"
			("check_ground_veh" skill(skill_apc))
		else props "moto" or props "car"
			("check_ground_veh" skill(skill_car))
		else props "cannon"
			("check_ground_veh" skill(skill_stan))
		else props "airborne"
			("check_crew_ability" place(gunner) skill(skill_plane))
			("check_crew_ability" place(driver) skill(skill_plane))
			("check_crew_ability" place(driver1) skill(skill_plane))
		}
	}
	
	
	{on operatable on
		{tags remove "selfdestruct"}
		{call "start_update_lights"}
	}
	{on operatable off
		{call "update_lights"}
		{if not game "cooperative"	;правка не для сингла
			{delay 0.5 {if not operatable and not props "cannon" {player -1}}}	;фикс вылета прицепленного юнита
			;также убирает из левой панели и из КО пустые юниты
		}
	}
;	{on crew in
;		{play_sound "hatch_in"}
;	}
;	{on crew out
;		{play_sound "hatch_out"}
;	}
	{on "link_weapon"
		{if name "mgun"
			{add_view "flash_gun_big"	"flashbarrel3"	"Foresight3"}
			{add_view "zenit_gilz"		"shell"			"fxshell"}
		else
			{view hide	"flashbarrel3"}
			{view pause	"flashbarrel3"}
			{view pause "shell"}
		}
	}
	;hatch, sights
	{on "gunner_hatch_open"
		{ani_wind "open" end}
	}
	{on "gunner_hatch_close"
		{ani_wind "open" begin}
	}
	{on "gunner_hatch_opening"
		{ani_play "open" resume}
	}
	{on "gunner_hatch_closing"
		{ani_play "open" -1 resume}
	}
	{on "sight_open"
		{ani_wind "sight_open" end}
		{ani_wind "open_sight" end}
	}
	{on "sight_close"
		{ani_wind "sight_open" begin}
		{ani_wind "open_sight" begin}
	}
	{on "sight_opening"
		{ani_play "sight_open" resume}
		{ani_play "open_sight" resume}
	}
	{on "sight_closing"
		{ani_play "sight_open" -1 resume}
		{ani_play "open_sight" -1 resume}
	}
	{on "zpu_gunner2_hatch_close"
		{call "gunner_hatch_close"}
	}
	{on "zpu_gunner2_hatch_closing"
		{call "gunner_hatch_closing"}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{call "gunner_hatch_open"}
				{call "sight_open"}
			else
				{call "gunner_hatch_opening"}
				{call "sight_opening"}
			}
		else
			{if crew_in_place "%place"
			   {if %wind
			      {if tagged "cwsh_zpu_off"
			    {call "zpu_%place_hatch_close"}
			      else
				{call "zpu_%place_hatch_open"}
			       }
			    else
			      {if tagged "cwsh_zpu_off"
			    {call "zpu_%place_hatch_closing"}
			      else
				{call "zpu_%place_hatch_opening"}
			       }
			    }
			else
				{if %wind
					 {call "zpu_%place_hatch_close"}
				else
					{call "zpu_%place_hatch_closing"}
				}
			}
			{if %wind
				 {call "sight_close"}
			else
				{call "sight_closing"}
			}
		}
	)
	{on "update_hatch_on_spawn"
		("update_hatch" wind(true) place(gunner2))
		{tags remove "cw_panorama_work"}
		{call "update_cw_panorama"}
	}
	{on "cwsh_update_hatch"
		("update_hatch" wind(false) place(gunner2))
	}
	(define "update_hatch_event"
		{on %event
			("update_hatch" wind(false) place(%place))
			{call "update_zpu"}
			{call "update_cw_panorama"}
			{call "update_moveability"}
		}
	)
;============CW shooting detection system for single
	(define "cw_check_shooting"
		{if tagged "cw_check_shooting_once"
			{tags add "cw_i_am_shooting"}
			{tags add "cw_i_am_shooting_%weap_id"}
			{kill_delay "cw_shooting_%weap_id"}
			{delay 3 "cw_shooting_%weap_id"
				{tags remove  "cw_i_am_shooting"}
				{tags remove  "cw_i_am_shooting_%weap_id"}
				{tags remove  "cw_check_shooting_once"}
			}
		else tagged "cw_check_shooting"
			{tags add "cw_i_am_shooting"}
			{tags add "cw_i_am_shooting_%weap_id"}
			{kill_delay "cw_shooting_%weap_id"}
			{delay 3 "cw_shooting_%weap_id"
				{tags remove  "cw_i_am_shooting_%weap_id"}
				{tags remove  "cw_i_am_shooting"}
			}
		}
	)
;============CW shooting detection system for single	
	{on fire "gun" ("cw_check_shooting" weap_id(gun))}
	{on fire "gun1" ("cw_check_shooting" weap_id(gun1))}
	{on fire "gun2" ("cw_check_shooting" weap_id(gun2))}
	{on fire "gun3" ("cw_check_shooting" weap_id(gun3))}


	{on fire "mgun"
		{view start "flashbarrel3"}
		{ani_play "fire_mgun"}
		{view start "shell"}
		{kill_delay "shell"}
		{delay 0.2 "shell"
			{view pause "shell"}
		}
		("cw_check_shooting" weap_id(mgun))
	}
	{on fire "mgun1"
		("cw_check_shooting" weap_id(mgun1))
		{view start "flashbarrel4"}
	}
	{on fire "mgun2"
		("cw_check_shooting" weap_id(mgun2))
		{view start "flashbarrel5"}
	}
	{on fire "mgun3"
		("cw_check_shooting" weap_id(mgun3))
		{view start "flashbarrel6"}
	}
	;---------------------default spread pattern for most smokeguns - spread by arc. {call "vehicle_mining_start"}
	;(define "fire_smokegun"
	;	{spawn "startsmoke" inv_normal}
	;	{if name "00" {spawn "smoke_probe" inv_normal {tags add "0_0"}}
	;	else name "01" {spawn "smoke_probe" inv_normal {tags add "0_m10"}}
	;	else name "02" {spawn "smoke_probe" inv_normal {tags add "0_10"}}
	;	else name "03" {spawn "smoke_probe" inv_normal {tags add "0_m20"}}
	;	else name "04" {spawn "smoke_probe" inv_normal {tags add "0_20"}}
	;	else name "05" {spawn "smoke_probe" inv_normal {tags add "0_m30"}}
	;	else name "06" {spawn "smoke_probe" inv_normal {tags add "0_30"}}
	;	else name "07" {spawn "smoke_probe" inv_normal {tags add "0_m40"}}
	;	else name "08" {spawn "smoke_probe" inv_normal {tags add "0_40"}}
	;	else name "09" {spawn "smoke_probe" inv_normal {tags add "0_0"}}
	;	else name "10" {spawn "smoke_probe" inv_normal {tags add "0_m20"}}
	;	else name "11" {spawn "smoke_probe" inv_normal {tags add "0_20"}}
	;	else {spawn "smoke_probe" inv_normal {tags add "0_0"}}
	;	}
	;)
	(define "fire_smokegun"
		{spawn "startsmoke" inv_normal}
		{if name "00"  {call "smokescreen"}
		else name "01" {call "smokescreen"}
		else name "02" {call "smokescreen"}
		else name "03" {call "smokescreen"}
		else name "04" {call "smokescreen"}
		else name "05" {call "smokescreen"}
		else name "06" {call "smokescreen"}
		else name "07" {call "smokescreen"}
		else name "08" {call "smokescreen"}
		else name "09" {call "smokescreen"}
		else name "10" {call "smokescreen"}
		else name "11" {call "smokescreen"}
		else {call "smokescreen"}
		}
	)
	{on fire "mgun15" 
		("fire_smokegun")
	}
	{on fire "mgun16" 
		("fire_smokegun")
	}
	{on fire "mgun17" 
		("fire_smokegun")
	}
	{on fire "mgun18" 
		("fire_smokegun")
	}
	{on fire "mgun19" 
		("fire_smokegun")
	}
	{on fire "mgun20" ;can be breakable
		("fire_smokegun")
	}
	{on fire "mgun21"  ;can be breakable
		("fire_smokegun")
	}
	{on fire "mgun22" 
		("fire_smokegun")
	}

	;---------------------
	{on contact
		{if volume "sticky"
			{if effector "grenade"
				{if not effector "contact"
					{call "grenade_stick"}
				}
			}
		}
		{if not impregnable
			{if effector_velocity 3
				{if effector "small_UAV"
				else effector "airborne"
					{call "contact_airborne"}
				else effector "piece_big_stone"
					{component break}
				}
			}
		}
		{if effector "cw_cumassist_1gen"
			{call "comp_armor_on_1gen"}
		else effector "cw_cumassist_2gen"
			{call "comp_armor_on_2gen"}
		else effector "cw_cumassist_3gen"
			{call "comp_armor_on_3gen"}
		else effector "proj_dummy supertandem"
			{call "comp_armor_on_3gen"}
		else effector "proj_dummy tandem"
			{call "comp_armor_on_2gen"}
		else effector "proj_dummy"
			{call "comp_armor_on_1gen"}
		else effector "submunition"
			{call "comp_armor_on_1gen"}
		else effector "rkg3"
			{call "comp_armor_on_1gen"}
		}
	}
	{on "comp_armor_on_1gen"
;		{call "kaz_work"}
		{kill_delay "comp_armor"}
		{volumes "comp_armor" enable bullet}
		{volumes "1gen_ERA" enable bullet}
		{volumes "2gen_ERA" enable bullet}
		
;		{spawn "proj_restrictor" inv_normal}
		
		{delay 0.7 "comp_armor"
			{volumes "comp_armor" disable bullet}
			{volumes "1gen_ERA" disable bullet}
			{volumes "2gen_ERA" disable bullet}
		}
	}
	{on "comp_armor_on_2gen"
;		{call "kaz_work"}
		{kill_delay "comp_armor"}
		{volumes "comp_armor" enable bullet}
		{volumes "2gen_ERA" enable bullet}
		
;		{spawn "proj_restrictor" inv_normal}	
		
		{delay 0.7 "comp_armor"
			{volumes "comp_armor" disable bullet}
			{volumes "2gen_ERA" disable bullet}
		}
	}
	{on "comp_armor_on_3gen"
;		{call "kaz_work"}
		{kill_delay "comp_armor"}
		{volumes "comp_armor" enable bullet}
		
;		{spawn "proj_restrictor"}		
		
		{delay 0.7 "comp_armor"
			{volumes "comp_armor" disable bullet}
		}
	}
	{on "grenade_stick"
		{with_effector
			{link_grenade_to_nearest_human}
		}
	}
	{on "contact_airborne"
		{if not flag "contact_airborne_first"
			{set "contact_airborne_first" 1}
			{component break}
			{delay 0.1
				{set "contact_airborne_second" 1}
				{delay 0.1
					{set "contact_airborne_first" 0}
					{set "contact_airborne_second" 0}
				}
			}
		else flag "contact_airborne_second"
			{call "explosion"}
		}
	}

	{on "update_moveable"
		{if work "body"
			{view stop "smoke4"}
		else
			{view start "smoke4"}
		}
		{if work "engine"
			{call "check_work_mover"}
		else
			{chassis_work 0} {components "move_indicator" break}
		}
	}
	{on "check_work_mover"
		{if work "mover"

;==================================
;part of AAS system by Timosh
			{if work "transmission"
			  {if work "driver_panel"
				{if work "panel_engine_connectors"
					{if work "engine"
					   {if work "trackright"
						{if work "trackleft"
							{if not tagged "engine_shutdown_by_fire"
					    			{chassis_work 1} {components "move_indicator" repair}
									{tags remove "chassis_brake"}
							}
						}
					   }
					}
				}
			  }
			}
;=================================
		else
			{chassis_work 0} {components "move_indicator" break}
		}
	}

	{on "explosion"
		{if not able "exploded"
			{damage_report "body" "empty"}			
			{damage_report "engine" "empty"}
			{damage_report "trackright" "empty"}			
			{damage_report "trackleft" "empty"}
			{damage_report "turret" "empty"}			
			{damage_report "gun" "empty"}
			{able "exploded" 1}
			{call "_explosion"}
		}
	}
	{on "_explosion"
		{call "__explosion"}
;		{call "stat_break"}
		{tags add "destroyed"}
		{call "break_all"}
		{stop_sound "move"}
		{stop_sound "move_end"}
		{stop_sound "engine"}
		{stop_sound "engine_end"}
		{stop_sound "exhaust"}
		{view stop "fire1"}
		{view stop "fire2"}
;		{tags add "destroyed"}
		{kick_entity_manager}
		{call "explosion_sound"}
		{tags add "exploded"}

		{if not terrain_fx "bridge"
			{if not under_water
				{call "spawn_shellhole"}
			}
		}
		
		{volumes "trackleft" disable blast}
		{volumes "trackright" disable blast}
		{delay_ex 0
			{set "no_burn_volumes" 1}
			{set_skeleton "_xx" sync}
			{ani_play "death"}
			{call "cut_parts"}
		}
	}
	{on "explosion_blastwave"
		;{blastwave c4 4 r0 3 r1 8}
	}
	{on "explosion_sound"
		{if flag "crush"
			{start_sound "crush/medium/vehicle"}
		else
			{call "explosion_blastwave"}
			{start_sound "crush/big/vehicle"}
		}
	}
	{on "burnout"
		{if not able "exploded"
			{damage_report "body" "empty"}			
			{damage_report "engine" "empty"}
			{damage_report "trackright" "empty"}			
			{damage_report "trackleft" "empty"}
			{damage_report "turret" "empty"}			
			{damage_report "gun" "empty"}
			{able "exploded" 1}
			{call "_burnout"}
		}
	}
	{on "_burnout"
		{tags add "destroyed"}
		{components "body" break}
		{components "turret" break}
		{components "gun" break}
		{components "engine" break}
		{if rand 0.3 {call "kill_crew"}}
		{drop_orders}
		{reset_manual_control}
		{able select 0}
		{able repaired 0}
		{unlink_trailer}
		{clear_inventory}
		{tags add "cwfs_set_fuel"}
		{stop_sound "move"}
		{stop_sound "move_end"}
		{stop_sound "engine"}
		{stop_sound "engine_end"}
		{stop_sound "exhaust"}
		{view stop "fire1"}
		{view stop "fire2"}
		{kick_entity_manager}
		{if flag "crush"
			{start_sound "crush/medium/vehicle"}
		else
			{start_sound "crush/big/vehicle"}
		}
		{delay_ex 0
			{set "no_burn_volumes" 1}
			{ani_play "death"}
			{add_view "smoke_black_big5" "smoke_turret" "basis"}
			{spawn "fire_shellhole" "basis"}
			{if rand 0.3 {add_view "fire_napalm" "smoke_turret" "fxtracel1"}}
			{if rand 0.3 {add_view "fire_napalm" "smoke_turret" "fxtracel2"}}
			{if rand 0.3 {add_view "fire_napalm" "smoke_turret" "fxtracer1"}}
			{if rand 0.3 {add_view "fire_napalm" "smoke_turret" "fxtracer2"}}
			{view start "smoke_turret"}
			{delay 60 15
				{view stop "smoke_turret"}
				{stop_sound "flame"}
			}
		}
	}

	{on "break_all"
		{call "kill_crew"}
		{drop_orders}
		{components destroy}
		{reset_manual_control}
		{able select 0}
		{able repaired 0}
		{unlink_trailer}
		{clear_inventory}
	}
	
	{on "kill_crew"
		{kill_crew}
	}
	
	{on "_burn"
		{if not tagged "burned"
			{if not able "exploded"
				{damage_report "engine" "burn_engine"}
				{add_view		"smoke_dead_norm"	"burn_fire"		"FXfire1"}
				{view start "burn_fire"}
				{burn time 12}
				{tags add "burned"}
				{add_view "smoke_black" "burn_fire" "FXfire1"}
				{play_sound "flame" 1}
				{view start "burn_fire"}
				{set "burn_fire" 1}
				{components "fire_indicator" break}
				{call "stat_break"}
				{delay 4 2
					{call "check_burn_emit"}
				}
				(mod not "mp"
					{explosive 1}
				)
				{delay 10 2
						{call "mp_destroy"}
						{start_sound "crush/medium/metal"}
				}
				{delay 10 2
					{components "engine" break}
					{start_sound "crush/medium/metal"}
					{delay 5 4
						{call "mp_destroy"}
					}
				}
				{delay 12
					{explosive 0}
					{set "burn_fire" 0}
					{components "fire_indicator" repair}
					{call "check_burn_emit"}
					{if rand 0.3
						{view stop "burn_fire"}
						{stop_sound "flame"}
						{call "explosion"}
					else rand 0.6
						{delay 10 2 {view stop "burn_fire"} {stop_sound "flame"}}
						{call "burnout"}
					else
						{view stop "burn_fire"}
						{stop_sound "flame"}
						{able "burning" 0}
					}
				}
			}
    		}
	}

	{on "burn_emit"
		{if not able "burning"
			{able "burning" 1}
			{set_heater}
			{reset_manual_control}
		}
	}

;	{on "burn_volume"
;		{log "burn_volume"}
;		{if not burned
;			{if volume "engine"
;				{log "burn_engine"}
;				{call "_burn"}
;			else volume "engine1"
;				{log "burn_engine"}				
;				{call "_burn"}
;			else
;				{burn volume fx "smoke_dead_small" time 5 1 fake even_law}
;			}
;		}
;	}


	{on "burn_volume"
		{log "burn_volume"}
		{if not burned
			{if volume "wheel"
				{burn volume fx "smoke_dead_small" time 20 5 fake even_law}
				{component break}
			else volume "bodyback"
				{burn volume fx "smoke_dead_small" time 20 5 fake even_law}
				{component break}
			else volume "track"
				{burn volume fx "smoke_dead_small" time 20 5 fake even_law}
			else volume "engine"
				{if tagged "burning_stage1"
					{tags remove "burning_stage1"}
					{tags add "burning_stage2"}
					{call "burn_stage2"}
				else tagged "burning_stage2"
					{tags remove "burning_stage2"}
					{tags add "burning_stage3"}
					{call "burn_stage3"}
				else tagged "burning_stage3"
					{tags remove "burning_stage3"}
					{call "burn_stage4"}
				else
					{tags add "burning_stage1"}
					{call "burn_stage1"}
				}
				{call "cooldown"}
			else volume "engine1"
				{if tagged "burning_stage1"
					{tags remove "burning_stage1"}
					{tags add "burning_stage2"}
					{call "burn_stage2"}
				else tagged "burning_stage2"
					{tags remove "burning_stage2"}
					{tags add "burning_stage3"}
					{call "burn_stage3"}
				else tagged "burning_stage3"
					{tags remove "burning_stage3"}
					{call "burn_stage4"}
				else
					{tags add "burning_stage1"}
					{call "burn_stage1"}
				}
				{call "cooldown"}
			}
		}
	}
	{on "burn_stage1"
		{chassis_work 0} {components "move_indicator" break}
		{tags add "engine_shutdown_by_fire"}
	}
	{on "burn_stage2"
		{burn volume fx "smoke_dead_small" time 20 5 fake even_law}
		{log "burn_engine"}				
		{call "_burn"}
	}
	{on "cooldown"
		{kill_delay "cooldown"}
		{delay 15 "cooldown"
			{if tagged "burning_stage3"
				{tags remove "burning_stage3"}
				{tags add "burning_stage2"}
				{call "cooldown"}
			else tagged "burning_stage2"
				{tags remove "burning_stage2"}
				{tags add "burning_stage1"}
				{call "cooldown"}
			else tagged "burning_stage1"
				{tags remove "burning_stage1"}
				{tags remove "engine_shutdown_by_fire"}
				{call "update_moveable"}
			}
		}
	}

	{on "stat_break"	
		{if not tagged "body_break"
			{if not flag "broken"
				{set "broken" 1}
				{if flag "burn_fire"
					{stat_notify break burned}
			else
					{stat_notify break}
				}
			}
		}		
	}
	{on "reset_manual_control"
		{reset_manual_control}
	}
	{on "smokescreen"
	 {if operatable
	  {if not tagged "smoke_reload"
	  ("hksmoke" foresight(16))
      ("hksmoke" foresight(17))
	  ("hksmoke" foresight(18))
      ("hksmoke" foresight(19))
	  ("hksmoke" foresight(20))
      ("hksmoke" foresight(21))
	  ("hksmoke" foresight(22))
	  ("hksmoke" foresight(23))
	  ("hksmoke" foresight(24))
	  
	  {if tagged "1smoke"
		{tags add "2smoke"} {tags remove "1smoke"}
	  else tagged "2smoke"
		{tags add "3smoke"}  {tags remove "2smoke"}
	  else tagged "3smoke"
		{tags add "4smoke"} {tags remove "3smoke"}
	  else tagged "4smoke"
		{tags add "5smoke"} {tags remove "4smoke"}
	  else tagged "5smoke"
		{tags add "6smoke"} {tags remove "5smoke"}
	  else tagged "6smoke"
		{tags add "7smoke"}  {tags remove "6smoke"}
	  else tagged "7smoke"
		{tags add "8smoke"} {tags remove "7smoke"}
	  else tagged "8smoke"
		{tags add "9smoke"} {tags remove "8smoke"}
	  else tagged "9smoke"
		{tags add "10smoke"} {tags remove "9smoke"}
	  else tagged "10smoke"
		{tags add "11smoke"} {tags remove "10smoke"}
	  else tagged "11smoke"
		{tags add "12smoke"} {tags remove "11smoke"}
	  else {tags add "1smoke"}
	  }
	  (define "smoke_reload"
		{if tagged "%nsmoke"
			{tags add "smoke_reload"} {tags remove "%nsmoke"} {damage_report "basis" "smoke_reloading"} {icon_event "smoke_reload" 120}
			{delay 120 {tags remove "smoke_reload"} {damage_report "basis" "smoke_reloaded"}}
		}
	  )
	  {if props "1_barrels_smoke"
		("smoke_reload" n(1))
	  else props "2_barrels_smoke"
		("smoke_reload" n(2))
	  else props "3_barrels_smoke"
		("smoke_reload" n(3))
	  else props "4_barrels_smoke"
		("smoke_reload" n(4))
	  else props "5_barrels_smoke"
		("smoke_reload" n(5))
	  else props "6_barrels_smoke"
		("smoke_reload" n(6))
	  else props "7_barrels_smoke"
		("smoke_reload" n(7))
	  else props "8_barrels_smoke"
		("smoke_reload" n(8))
	  else props "9_barrels_smoke"
		("smoke_reload" n(9))
	  else props "10_barrels_smoke"
		("smoke_reload" n(10))
	  else props "11_barrels_smoke"
		("smoke_reload" n(11))
	  else props "12_barrels_smoke"
		("smoke_reload" n(12))
	  else
		("smoke_reload" n(3))
	  }
      else	  
		  {damage_report "basis" "smoke_reloading"}
	  }
	 }
	}
	{on "vehicle_mining_start"
	  {if operatable
		{if not tagged "selfdestruct"
			{unlink_trailer}
			{reset_manual_control}
			{crew_emit}
			{delay 1	{crew_emit}}
			{delay 2	{crew_emit}}
			{delay 3	{crew_emit}}
;			{tags add "abandoned"}	;prevents selection
			{tags add "selfdestruct"}
				
				;{delay 0 {if not tagged "destroyed" {if not operatable {damage_report "basis" "delay_120"}}}}
				;{delay 1 {if not tagged "destroyed" {if not operatable {damage_report "basis" "delay_130"}}}}
				;{delay 2 {if not tagged "destroyed" {if not operatable {damage_report "basis" "delay_140"}}}}
				;{delay 3 {if not tagged "destroyed" {if not operatable {damage_report "basis" "delay_150"}}}}
				;{delay 4 {if not tagged "destroyed" {if not operatable {damage_report "basis" "delay_160"}}}}
				{delay 5 {if not tagged "destroyed" {if not operatable {damage_report "basis" "delay_170"}}}}
				{delay 6 {if not tagged "destroyed" {if not operatable {damage_report "basis" "delay_171"}}}}
				{delay 7 {if not tagged "destroyed" {if not operatable {damage_report "basis" "delay_172"}}}}
				{delay 8 {if not tagged "destroyed" {if not operatable {damage_report "basis" "delay_173"}}}}
				{delay 9 {if not tagged "destroyed" {if not operatable {damage_report "basis" "delay_174"}}}}
				{delay 10 {if not tagged "destroyed" {if not operatable {damage_report "basis" "delay_175"}}}}
				{delay 11 {if not tagged "destroyed" {if not operatable {damage_report "basis" "delay_176"}}}}
				{delay 12 {if not tagged "destroyed" {if not operatable {damage_report "basis" "delay_177"}}}}
				{delay 13 {if not tagged "destroyed" {if not operatable {damage_report "basis" "delay_178"}}}}
				{delay 14 {if not tagged "destroyed" {if not operatable {damage_report "basis" "delay_179"}}}}
		}
;change condition on emit_label to avoid explos of captured veh
;takeoff emit_label when on operatable on

		{delay 15
		  {if tagged "selfdestruct"
			{if not operatable
				{set "broken" 1}
				{able select 0}
				{able repaired 0}
				{explosive 1}
				{player -1}
				{stat_notify leave}
				{kick_entity_manager}
				{explosive 1}
				{damage_report "body" "empty"}
				{damage_report "trackright" "empty"}
				{damage_report "trackleft" "empty"}
				{damage_report "gun" "empty"}
				{damage_report "turret" "empty"}
				{damage_report "engine" "empty"}
				{delay 3 1
				{if explosive_amount 4000	;bit more than fully loaded Msta-S
					{call "ammo_damage800"}
				else explosive_amount 3000
					{call "ammo_damage400"}
				else explosive_amount 2000		
					{call "ammo_damage200"}
				else explosive_amount 1000		;fully loaded M1A1HA or T-72
					{call "ammo_damage130"}
				else explosive_amount 750		;M1A1HA or T-72 after several shots - 1/4 ammo depleted
					{call "ammo_damage100"}
				else explosive_amount 500
					{call "ammo_damage70"}
				else explosive_amount 250
					{call "ammo_damage30"}
				else explosive_amount 100
					{call "ammo_damage10"}
				}
				}
				{delay 5					
					{explosive 0}
					{tags add "destroyed"}
					{call "explosion"}
				}
			}
		  }
		}
       else
       	{if not tagged "selfdestruct"
			{unlink_trailer}
			{reset_manual_control}
			{crew_emit}
			{delay 1	{crew_emit}}
			{delay 2	{crew_emit}}
			{delay 3	{crew_emit}}
;			{tags add "abandoned"}	;prevents selection
			{tags add "selfdestruct"}
				{delay 0 {if not tagged "destroyed" {if not operatable {damage_report "basis" "delay_0"}}}}
				{delay 10 {if not tagged "destroyed" {if not operatable {damage_report "basis" "delay_10"}}}}
				{delay 20 {if not tagged "destroyed" {if not operatable {damage_report "basis" "delay_20"}}}}
				{delay 30 {if not tagged "destroyed" {if not operatable {damage_report "basis" "delay_30"}}}}
				{delay 40 {if not tagged "destroyed" {if not operatable {damage_report "basis" "delay_40"}}}}
				{delay 50 {if not tagged "destroyed" {if not operatable {damage_report "basis" "delay_50"}}}}
				{delay 60 {if not tagged "destroyed" {if not operatable {damage_report "basis" "delay_60"}}}}
				{delay 70 {if not tagged "destroyed" {if not operatable {damage_report "basis" "delay_70"}}}}
				{delay 80 {if not tagged "destroyed" {if not operatable {damage_report "basis" "delay_80"}}}}
				{delay 90 {if not tagged "destroyed" {if not operatable {damage_report "basis" "delay_90"}}}}
				{delay 100 {if not tagged "destroyed" {if not operatable {damage_report "basis" "delay_100"}}}}
				{delay 110 {if not tagged "destroyed" {if not operatable {damage_report "basis" "delay_110"}}}}
				{delay 120 {if not tagged "destroyed" {if not operatable {damage_report "basis" "delay_120"}}}}
				{delay 130 {if not tagged "destroyed" {if not operatable {damage_report "basis" "delay_130"}}}}
				{delay 140 {if not tagged "destroyed" {if not operatable {damage_report "basis" "delay_140"}}}}
				{delay 150 {if not tagged "destroyed" {if not operatable {damage_report "basis" "delay_150"}}}}
				{delay 160 {if not tagged "destroyed" {if not operatable {damage_report "basis" "delay_160"}}}}
				{delay 170 {if not tagged "destroyed" {if not operatable {damage_report "basis" "delay_170"}}}}
				{delay 171 {if not tagged "destroyed" {if not operatable {damage_report "basis" "delay_171"}}}}
				{delay 172 {if not tagged "destroyed" {if not operatable {damage_report "basis" "delay_172"}}}}
				{delay 173 {if not tagged "destroyed" {if not operatable {damage_report "basis" "delay_173"}}}}
				{delay 174 {if not tagged "destroyed" {if not operatable {damage_report "basis" "delay_174"}}}}
				{delay 175 {if not tagged "destroyed" {if not operatable {damage_report "basis" "delay_175"}}}}
				{delay 176 {if not tagged "destroyed" {if not operatable {damage_report "basis" "delay_176"}}}}
				{delay 177 {if not tagged "destroyed" {if not operatable {damage_report "basis" "delay_177"}}}}
				{delay 178 {if not tagged "destroyed" {if not operatable {damage_report "basis" "delay_178"}}}}
				{delay 179 {if not tagged "destroyed" {if not operatable {damage_report "basis" "delay_179"}}}}
		}
;change condition on emit_label to avoid explos of captured veh
;takeoff emit_label when on operatable on

		{delay 180
		  {if tagged "selfdestruct"
			{if not operatable
				{set "broken" 1}
				{able select 0}
				{able repaired 0}
				{explosive 1}
				{player -1}
				{stat_notify leave}
				{kick_entity_manager}
				{explosive 1}
				{damage_report "body" "empty"}
				{damage_report "trackright" "empty"}
				{damage_report "trackleft" "empty"}
				{damage_report "gun" "empty"}
				{damage_report "turret" "empty"}
				{damage_report "engine" "empty"}
				
				{delay 3 1
				{if explosive_amount 4000	;bit more than fully loaded Msta-S
					{call "ammo_damage800"}
				else explosive_amount 3000
					{call "ammo_damage400"}
				else explosive_amount 2000		
					{call "ammo_damage200"}
				else explosive_amount 1000		;fully loaded M1A1HA or T-72
					{call "ammo_damage130"}
				else explosive_amount 750		;M1A1HA or T-72 after several shots - 1/4 ammo depleted
					{call "ammo_damage100"}
				else explosive_amount 50
					{call "ammo_damage70"}
				else explosive_amount 250
					{call "ammo_damage30"}
				else explosive_amount 100
					{call "ammo_damage10"}
				}
				}
				{delay 5					
					{explosive 0}
					{tags add "destroyed"}
					{call "explosion"}
				}
			}
		  }
		}   
	  }
	}

	(define "terrain_fx"
		{on terrain_fx %0 enter
			{view start "on_%1"}
			{view start "on_%1_time_short"}
			{delay 0.1
				{view pause "on_%1_time_short"}
			}
		}
		{on terrain_fx %0 leave
			{view pause "on_%1"}
		}
	)
	("terrain_fx" args "ground"			ground)
	("terrain_fx" args "sand"			sand)
	("terrain_fx" args "grass" 			grass)
	("terrain_fx" args "deep_water" 			water)
	("terrain_fx" args "water" 			water)
	("terrain_fx" args "puddle"			puddle)
	("terrain_fx" args "mud"			mud)
	("terrain_fx" args "country_road"	country_road)
	("terrain_fx" args "snow"			snow)
;	("terrain_fx" args "shallow_water" 	puddle)
	{on terrain_fx "shallow_water" enter
		{view start "on_puddle"}
		{view start "on_puddle_time_short"}
		{delay 0.1
			{view pause "on_puddle_time_short"}
		}
		{if velocity 15	{spawn "spherewater_big3" "FXtraceR1"}{spawn "spherewater_big3" "FXtraceL1"}}
	}
	{on terrain_fx "shallow_water" leave
		{view pause "on_puddle"}
	}
	
	{on "explosion_delete"
		{set "delete_parts" 1}
		{call "explosion"}
		{delay 20
			{hide 3}
		}
	}
	{on "sink"
		{able "sinking" 1}
	}
	{on "crew_emit"
		{crew_emit}
	}
	{on "camouflage"
		{spawn "vehnet" "basis" x no_normal no_position}
	}
}

{"emit_on_sink vehicle"
	{on operatable on
		{delay 0.3 "start_check_sinking"
			{call "check_sinking"}
		}
	}
	{on operatable off
		{kill_delay "start_check_sinking"}
		{kill_delay "check_sinking"}
	}
	(define "sink_terrain"
		{on terrain_pp "%0" enter
			{reset_manual_control}
			{call "sink"}
;			{able "sinking" 1}
		}
		{on terrain_pp "%0" leave
			{reset_manual_control}
;			{able "sinking" 0} ;do not use this because of leaving terrain on stop
		}
	)
;	("sink_terrain" args water)
	("sink_terrain" args swamp)
	{on "check_sinking"
		{call "check_water_level"}
		{if able "sinking"
			{reset_manual_control}
		}
		{delay 0.5 "check_sinking"
			{call "check_sinking"}
		}
	}
	{on "check_water_level"
		{if water_level 1.2
			{call "sink"}
;			{able "sinking" 1}
		}
	}
	{on "crew_emit"
		{crew_emit}
	}
}

{"with_gun vehicle"
	{on spawn
		{call "update_gun"}
	}
	{on break
		{if component "gun"
			{call "update_gun"}
                        {tags add "gun_brake"}
		}
	}
	{on repair
		{if component "gun"
			{call "update_gun"}
                        {tags remove "gun_brake"}
		}
	}
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
}

{"open_with_land"
	{on "open"
		{ani_stop "drift"}
		{ani_play "dooropen" callback}
		{land on}
		{chassis_work 0} {components "move_indicator" break}
		{physics_work 0}
		{area enable}
	}
	{on "close"
		{ani_play "dooropen" -1 callback}
		{ani_play "drift" loop}
		{land off}
		{chassis_work 1} {components "move_indicator" repair}
		{physics_work 1}
		{area disable}
	}
	{on animation_end "dooropen"
		{update_visibility_patch}
	}
}

{"open_without_land"
	{on "open"
		{ani_stop "drift"}
		{ani_play "dooropen" callback}
	}
	{on "close"
		{ani_play "dooropen" -1 callback}
		{ani_play "drift" loop}
	}
	{on animation_end "dooropen"
		{update_visibility_patch}
	}
}

{"amphibia vehicle"
	{on spawn
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_small_center1"}
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_small_center2"}
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_small_center3"}
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_small_center4"}
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_small_center5"}
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_small_center6"}
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_small_center7"}
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_small_center8"}
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_small_center9"}
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_small_center10"}
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_norm_front1"}
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_norm_front2"}
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_norm_engine1"}
		{add_view	"wash_ship_motion"	"on_move"	"FX_bulb_small_center1"}
		{add_view	"wash_ship_motion"	"on_move"	"FX_bulb_small_center2"}
		{add_view	"wash_ship_motion"	"on_move"	"FX_bulb_small_center3"}
		{add_view	"wash_ship_motion"	"on_move"	"FX_bulb_small_center4"}
		{add_view	"wash_ship_motion"	"on_move"	"FX_bulb_small_center5"}
		{add_view	"wash_ship_motion"	"on_move"	"FX_bulb_small_center6"}
		{add_view	"wash_ship_motion"	"on_move"	"FX_bulb_small_center7"}
		{add_view	"wash_ship_motion"	"on_move"	"FX_bulb_small_center8"}
		{add_view	"wash_ship_motion"	"on_move"	"FX_bulb_small_center9"}
		{add_view	"wash_ship_motion"	"on_move"	"FX_bulb_small_center10"}
		{add_view	"wash_ship_motion"	"on_move"	"FX_bulb_small_back1"}
		{add_view	"wash_ship_motion"	"on_move"	"FX_bulb_small_back2"}
		{add_view	"wash_front_small"	"on_move"	"FX_bulb_small_front1"}
		{add_view	"wash_front_small"	"on_move"	"FX_bulb_small_front2"}
		{add_view	"wash_front_norm"	"on_move"	"FX_bulb_norm_front1"}
		{add_view	"wash_front_norm"	"on_move"	"FX_bulb_norm_front2"}
		{add_view	"wash_ship_motion_norm"	"on_move"	"FX_bulb_norm_front1"}
		{add_view	"wash_ship_motion_norm"	"on_move"	"FX_bulb_norm_front2"}
		{add_view	"wash_engine_small"	"on_move"	"FX_bulb_small_engine1"}
		{add_view	"wash_engine_norm"	"on_move"	"FX_bulb_norm_engine1"}
	}
	{on terrain_pp "deep_water" enter
		{if not flag "in_water" {ani_play "open_volnorez"}}
		{set "in_water" 1}
		{call "update_bulbs"}
;		{unlink_trailer}	do not use - causes crush when entering water
	}
	{on terrain_pp "water" enter
		{if not flag "in_water" {ani_play "open_volnorez"}}
		{set "in_water" 1}
		{call "update_bulbs"}
	}
	{on terrain_pp "shallow_water" enter
		{if not flag "in_water" {ani_play "open_volnorez"}}
		{set "in_water" 1}
		{call "update_bulbs"}
	}
	{on terrain_pp "shallow_water" leave
		{if flag "in_water" {ani_play "open_volnorez" -1}}
		{set "in_water" 0}
		{call "update_bulbs"}
	}
	{on "update_bulbs"
		{if flag "in_water"
			{if not velocity 0.001
				{view start "on_stead"}
				{view pause "on_move"}
			else
				{view start "on_move"}
				{view pause "on_stead"}
			}
		else
			{view pause "on_stead"}
			{view pause "on_move"}
		}
	}
	{on "check_water_level" overload}
	{on "sink" overload
		{if not work "hull_integrity"
			{able "sinking" 1}
		}
	}
	{on repair
		{if component "hull_integrity" {able "sinking" 0}}
	}
	{on move on
		{call "update_bulbs"}
	}
	{on move off
		{call "update_bulbs"}
	}
}

{"autotrack_suo"
	{on "cwps_noadjust_rus_laser" overload}
	{on "cwps_noadjust_usa_laser" overload}
	{on "cwps_noadjust_rus_other" overload}
	{on "cwps_noadjust_usa_other" overload}
	{on "cwps_noadjust_rus_active" overload}
	{on "cwps_noadjust_usa_active" overload}
}
;====================================================
{"with_open_zpu"
	{on "cwsh_enable_zpu"
		{tags remove "cwsh_zpu_off"}
		{delay 1 {call "update_weaponry"}}
		{call "cwsh_update_hatch"}
		{call "cwsh_gunner_out"}
		{call "update_lights"}
	}
	{on "cwsh_disable_zpu"
		{tags add "cwsh_zpu_off"}
		{delay 0.2 {call "update_weaponry"}}
		{delay 0.5 {call "cwsh_update_hatch"}}
		{call "cwsh_gunner_in"}
		{call "update_lights"}
	}
}
{"DUM"
    {on break
		{if component "mgun"
		 {weapon_work "mgun" 0}
		 {tags add "mgun_damaged"}
		  {if not tagged "destroyed"
		   {damage_report "mgun" "mgun_damaged"}
		  }
		   {spawn "metal_hit_bul"}
			{if not tagged "crit_system_destroyed"
			 {tags add "crit_system_destroyed"}
			  else
			    {if not tagged "crit_system_destroyed2"
			     {tags add "crit_system_destroyed2"}
				  else
				  {components "body" break}
				  ;{call "mp_destroy"}  
			    }	  
			}
		}
	}	
}
(define "commonzpu_params"
	{on "update_zpu"
		{if tagged "cwsh_zpu_off"
			{with_linked_entity "%gunner" {ani_wind "%anim" end}}
		}
		{kill_delay "cwsh_disable_zpu"}
		{if tagged "cwsh_tempdisable_zpu"
			{delay 15 "cwsh_disable_zpu"
			     {if  tagged "cwsh_tempdisable_zpu"
				{tags remove "cwsh_tempdisable_zpu"}
				{call "cwsh_enable_zpu"}
			     }
			}
		}
	}
	{on "cwsh_gunner_in" overload
		{with_linked_entity "%gunner" {ani_play "%anim"}}
	}
	{on "cwsh_gunner_out" overload
		{with_linked_entity "%gunner" {ani_play "%anim" -1}}
		{delay 1.5
		   {if not tagged "cwsh_tempdisable_zpu"
		     {if not tagged "cwsh_zpu_off"
			{with_linked_entity "%gunner" {ani_wind "%pose" end}}
		     }
		   }
		}
	}
	{on "update_%zpu_mgun" overload
	     {if work "%zpu_mgun" 
	          {if tagged "cwsh_zpu_off"
					{weapon_work "%zpu_mgun" 0}
				else {inherited}
	           }
	     }
	}
)
{"tank with_open_zpu"
	{on "cwsh_switch_hatch"
		{if tagged "cwsh_active"
			{tags remove "cwsh_active"}
			{tags add "cwsh_passive"}
			{call "cwsh_disable_zpu"}
			{damage_report "body" "zpu_disabled"}
		else tagged "cwsh_passive"
			{tags remove "cwsh_active"}
			{tags remove "cwsh_passive"}
			{call "cwsh_enable_zpu"}
			{damage_report "body" "zpu_careful"}
		else 
			{tags add "cwsh_active"}
			{if  tagged "cwsh_tempdisable_zpu"
				{call "cwsh_enable_zpu"}
				{tags remove "cwsh_tempdisable_zpu"}
			}
			{damage_report "body" "zpu_enabled"}
		}
	}
	(define "check_attack_on_zpu"
	     {if not tagged "cwsh_active"
	          {if not tagged "cwsh_passive"
				{if not effector "airborne"
					{kill_delay "cwsh_disable_zpu"}
					{if not tagged "cwsh_tempdisable_zpu"
						{call "cwsh_disable_zpu"}
						{tags add "cwsh_tempdisable_zpu"}
					}
					{delay 15 "cwsh_disable_zpu"
						 {if  tagged "cwsh_tempdisable_zpu"
						{tags remove "cwsh_tempdisable_zpu"}
						{call "cwsh_enable_zpu"}
						 }
					}
				}
	          }
	     }
	)
	{on bullet_hit
		("check_attack_on_zpu")
	}
	{on blast_hit
	       {if not component "gun"
		    {if not stuff "turret_dir_detector"
			  ("check_attack_on_zpu")
			}
	       }
	}
}
{"car with_open_zpu"
	{on spawn
		{call "update_weaponry"}
	}
	{on operatable on {call "update_zpu"}}
	{on operatable off {call "update_zpu"}}
	{on crew in {call "update_zpu"}}
	{on crew out {call "update_zpu"}}
	{on "cwsh_switch_hatch"
		{if tagged "cwsh_passive"
			{tags add "cwsh_careful"}
			{tags remove "cwsh_passive"}
			{call "cwsh_enable_zpu"}
			{damage_report "body" "zpu_careful"}
		else tagged "cwsh_careful"
			{tags remove "cwsh_careful"}
			{if  tagged "cwsh_tempdisable_zpu"
				{call "cwsh_enable_zpu"}
				{tags remove "cwsh_tempdisable_zpu"}
			}
			{damage_report "body" "zpu_enabled"}
		else 
			{tags remove "cwsh_careful"}
			{tags add "cwsh_passive"}
			{call "cwsh_disable_zpu"}
			{damage_report "body" "zpu_disabled"}
		}
	}
	(define "check_attack_on_zpu"
	     {if tagged "cwsh_careful"
			{if not effector "airborne"
				{kill_delay "cwsh_disable_zpu"}
				{if not tagged "cwsh_tempdisable_zpu"
					{call "cwsh_disable_zpu"}
					{tags add "cwsh_tempdisable_zpu"}
				}
				{delay 15 "cwsh_disable_zpu"
					 {if  tagged "cwsh_tempdisable_zpu"
					{tags remove "cwsh_tempdisable_zpu"}
					{call "cwsh_enable_zpu"}
					 }
				}
			}
	      }
	)
	{on bullet_hit
		("check_attack_on_zpu")
	}
	{on blast_hit
	       {if not component "gun"
		("check_attack_on_zpu")
	        }
	}
}
{"open_zpu_hide"
    {on operatable on
		{call "cwsh_disable_zpu"}
		 {tags add "cwsh_passive"}  
		
    }
}
{"supply_5t"
  {on "_explosion"
	{if not warehouse_consumable_empty
		{spawn "smoke_black_big4" "basis" {delay 15 4 {delete}}}
		{if is_warehouse_consumable "restoring" or is_warehouse_consumable "restore_someone"
			{if min_energy 10 {spawn "cw_explosion_1000kg" "basis" x}
			else rand 0.6 {spawn "cw_explosion_1000kg" "basis" x}
			else rand 0.6 {spawn "ammo_detonation" "basis"}
			}	
		else
			{if min_energy 20 {spawn "cw_explosion_1000kg" "basis" x}
			else rand 0.3 {spawn "cw_explosion_1000kg" "basis" x}
			else rand 0.3 {spawn "ammo_detonation" "basis"}
			}		
		}
	}
  }
  {on "blast_body"
    {call "explosion"}
  }
}

;====================================================
{"cw_tractored"
	{on "install_buksir"
		{bone hide "link2"}   
	}
}
{"cw_tractored car"
	{on "install_buksir"
		{spawn "buksir" "basis" x   {if not tagged "cargo_inside"
				{call "load_heavy_vehicle"} {tags add "cwts_car_linked"}
	       }} {tags add "vdv_link_to_place1"} {delay 3 {tags remove "vdv_link_to_place1"}}
	}
}
{"cw_tractored armored_car_m"
	{on "install_buksir"
		{spawn "buksir" "basis" x   {if not tagged "cargo_inside"
				{call "load_heavy_vehicle"} {tags add "cwts_btr_linked"}
	       }} {tags add "vdv_link_to_place1"} {delay 3 {tags remove "vdv_link_to_place1"}}
	}
}
{"cw_tractored tank light_m"
	{on "install_buksir"
		{spawn "buksir" "basis" x   {if not tagged "cargo_inside"
				{call "load_heavy_vehicle"} {tags add "cwts_bmp_linked"}
	       }} {tags add "vdv_link_to_place1"} {delay 3 {tags remove "vdv_link_to_place1"}}
	}
}
{"cw_tractored tank medium_m"
	{on "install_buksir"
		{spawn "buksir" "basis" x   {if not tagged "cargo_inside"
				{call "load_heavy_vehicle"} {tags add "cwts_tank_linked"}
	       }} {tags add "vdv_link_to_place1"} {delay 3 {tags remove "vdv_link_to_place1"}}
	}
}
{"cw_tractored tank heavy_m"
	{on "install_buksir"
		{spawn "buksir" "basis" x   {if not tagged "cargo_inside"
				{call "load_heavy_vehicle"} {tags add "cwts_tank_linked"}
	       }} {tags add "vdv_link_to_place1"} {delay 3 {tags remove "vdv_link_to_place1"}}
	}
}
;====================================================
(define "sam_radar_add_marker"
{"sam_radar_%type"
     {on "spawn_antirad_point_resrve"
	    {tags add "vdv_link_place9"}
		{spawn "proj_point_%type_antirad_spawner"
			{tags add "vdv_link_to_place9"}
			{delay 0.7 {tags remove "vdv_link_to_place9"}}
		}
		{delay 0.3 {call "update_antiradar"}{tags remove "vdv_link_place9"}}
	 }
    {on "spawn_antirad_point_rand"
	    {if not tagged "antirad_linked" 
		    {if rand 0.1 {call "spawn_antirad_point"}
		    else 
		        {delay 0.5 0.1 {call "spawn_antirad_point_rand"}}
		    }
		}
	}
	{on operatable on
		{with_linked_entity "vehicle9" {delete}}
		{delay 1
			{call "spawn_antirad_point_rand"}
		}
		{delay 0.1 {tags remove "vdv_link_place9"}}
		{delay 11 2
		     {if not tagged "antirad_linked" {call "spawn_antirad_point"}}
		}
		{delay 20 {call "spawn_antirad_point_resrve"}}
		
	}
	{on "antirad_linked"	{if not linked {tags add "antirad_linked"}}}
	{on "spawn_antirad_point"
		{if not linked
		  {if not tagged "radar_off"
			{tags add "vdv_link_place9"}
			{spawn "proj_point_%type_antirad_spawner"
				{tags add "vdv_link_to_place9"}
				{delay 0.7 {tags remove "vdv_link_to_place9"}}
			}
			{delay 0.3 {call "update_antiradar"}{tags remove "vdv_link_place9"}}
		  }
		}
		{delay 3 2 {if not tagged "antirad_linked" {call "spawn_antirad_point"}}}
	}
}
)

;these 4 strings are applied in mp only
("sam_radar_add_marker" type(rus))
("sam_radar_add_marker" type(usa))
("sam_radar_add_marker" type(rus_large))
("sam_radar_add_marker" type(usa_large))

{"sam_radar"
;на маркер смотрят пехотинцы по всей карте
;    {on move off
;	    {if not linked
;		    {if not tagged "radar_off"
;		        {delay 1 {spawn "radar_minimap"}}
;		    }
;		}
;	}
    {on "smokescreen" overload
	 {if operatable
		{call "cwsh_switch_hatch"}
	 }	
	}
	{on operatable on
	 {if not tagged "radar_off"
	  {call "cwsh_radar_on"}
	 }
	}
	{on operatable off
		{call "cwsh_radar_off"}
	}
	{on "update_antiradar"
	  {if  tagged "radar_off" {call "cwsh_radar_off"}
	  else not operatable {call "cwsh_radar_off"}
	  else tagged "no_power" {call "cwsh_radar_off"}
	  else {call "cwsh_radar_on"}
	  }
	}
	{on "mp_destroy"
		{with_linked_entity "vehicle9"
			{delete}
		}
	}
	{on "cwsh_switch_hatch"
		{if tagged "cwsh_passive"
		    {damage_report "body" "radar_turns_on"}
			{tags remove "cwsh_passive"}
			{tags remove "cwsh_careful"}
			{tags remove "cwsh_tempdisable_radar"}
			{delay 5.0 "cwsh_radar_on"
			{call "cwsh_radar_on"}
			{damage_report "body" "radar_enabled"}
			}
		else 
;		tagged "cwsh_careful"
            {kill_delay "cwsh_radar_on"}
			{tags remove "cwsh_careful"}
			{tags add "cwsh_passive"}
			{tags remove "cwsh_tempdisable_radar"}
			{call "cwsh_disable_zpu"}
			{delay 2.0 {call "cwsh_radar_off"}}
			{tags remove "antirad_linked"}
			{damage_report "body" "radar_disabled"}
;		else 
;			{tags remove "cwsh_passive"}
;			{tags add "cwsh_careful"}
;			{kill_delay "cwsh_disable_radar"}
;			{if not tagged "cwsh_tempdisable_radar"
;				{tags add "cwsh_tempdisable_radar"}
;				{call "cwsh_radar_off"}
;			}
;			{delay 15 "cwsh_disable_zpu"
;				 {if  tagged "cwsh_tempdisable_radar"
;					{tags remove "cwsh_tempdisable_radar"}
;					{call "cwsh_radar_on"}
;					{tags remove "cwsh_passive"}
;					{tags remove "cwsh_careful"}
;				 }
;			}
;			{damage_report "body" "radar_careful"}
		}
	}
	{on "cwsh_radar_on"
		{tags remove "radar_off"}
		{components "zpu_indicator" repair}
;		{call "update_radar"}
		{call "update_weaponry"}
;			{delay 1 {spawn "radar_minimap"}}
	}
	{on "cwsh_radar_off"
		{tags add "radar_off"}
		{if not tagged "cwsh_tempdisable_radar"
			{components "zpu_indicator" break}
		}
		{call "update_weaponry"}
		{blastwave c4 0.001 r0 0.1 r1 1}
	}
}

{"laser_spo"
	{on "shtora_warn"
	    {if operatable
		  {if not tagged "no_power"
		    {if not work "electronics"
			else
				{burn fx "spo_warn" time 5 fake}
				{play_sound "spo"}
				{if not user_control
		         {delay 1.5
		          {if rand 0.9
	                 {call "smokescreen"}
		          }
	             }
	            }
			}
		  }
	    }
	}
}
{"IR_spo"
	{on spawn {components "spo_indicator" repair}}
	{on "ir_warn"
	    {if operatable
		  {if not tagged "no_power"
		    {if not work "electronics"
			else
				{burn fx "spo_warn" time 5 fake}
				{play_sound "spo"}
				{components "spo_indicator" break}
				{kill_delay "spo_indicator"}
				{delay 0.5 "spo_indicator" {components "spo_indicator" repair}}
				{delay 1.0 "spo_indicator" {components "spo_indicator" break}}
				{delay 1.5 "spo_indicator" {components "spo_indicator" repair}}
				{delay 2.0 "spo_indicator" {components "spo_indicator" break}}
				{delay 2.5 "spo_indicator" {components "spo_indicator" repair}}
				{delay 3.0 "spo_indicator" {components "spo_indicator" break}}
				{delay 3.5 "spo_indicator" {components "spo_indicator" repair}}
			}
		  }
	    }
	}
}
{"radar_spo"
	{on spawn {components "spo_indicator" repair}}
	{on "radar_warn"
	    {if operatable
		  {if not tagged "no_power"
		    {if not work "electronics"
			else
				{burn fx "spo_warn" time 5 fake}
				{play_sound "spo"}
				{components "spo_indicator" break}
				{kill_delay "spo_indicator"}
				{delay 0.5 "spo_indicator" {components "spo_indicator" repair}}
				{delay 1.0 "spo_indicator" {components "spo_indicator" break}}
				{delay 1.5 "spo_indicator" {components "spo_indicator" repair}}
				{delay 2.0 "spo_indicator" {components "spo_indicator" break}}
				{delay 2.5 "spo_indicator" {components "spo_indicator" repair}}
				{delay 3.0 "spo_indicator" {components "spo_indicator" break}}
				{delay 3.5 "spo_indicator" {components "spo_indicator" repair}}
			}
		  }
	    }
	}
}
{"ecm_vulnerable_usa"
	{on spawn
		{tags remove "ecm_effect_6"}{tags remove "ecm_effect_5"}{tags remove "ecm_effect_4"}
		{tags remove "ecm_effect_3"}{tags remove "ecm_effect_2"}{tags remove "ecm_effect_1"}
	}
	{on "mp_destroy"
		{tags remove "ecm_effect_6"}{tags remove "ecm_effect_5"}{tags remove "ecm_effect_4"}
		{tags remove "ecm_effect_3"}{tags remove "ecm_effect_2"}{tags remove "ecm_effect_1"}
	}
}
{"ecm_vulnerable_rus"
	{on spawn
		{tags remove "ecm_effect_6"}{tags remove "ecm_effect_5"}{tags remove "ecm_effect_4"}
		{tags remove "ecm_effect_3"}{tags remove "ecm_effect_2"}{tags remove "ecm_effect_1"}
	}
	{on "mp_destroy"
		{tags remove "ecm_effect_6"}{tags remove "ecm_effect_5"}{tags remove "ecm_effect_4"}
		{tags remove "ecm_effect_3"}{tags remove "ecm_effect_2"}{tags remove "ecm_effect_1"}
	}
}