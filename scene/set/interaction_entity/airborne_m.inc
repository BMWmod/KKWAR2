{"airborne_M"
;	{friction 0.2}
;	{restitution 0.01}
	{on spawn 
		{link_sound "fall"				"vehicle/airborne/fw_deep"			}
		{add_view 	"headlight"		"light"			"headlightc"}
		{if not props "small_uav"
			{link_sound "flaps"				"vehicle/airborne/avionics/flaps"			}
			{link_sound "air_brake"				"vehicle/airborne/avionics/airbrake"			}
		}

		{call "link_engine_effects"}
		{call "link_flare_fx"}

		{add_view "aero_die_fire"		"fire_body"		"fxfire_body_1"}
		{add_view "aero_die_fire"		"fire_body"		"fxfire_body_2"}
		{add_view "aero_die_fire"		"fire_body_l"		"fxfire_body_3"}
		{add_view "aero_die_fire"		"fire_body_r"		"fxfire_body_4"}

		{add_view "aero_die_fire"		"fire_wingl1_1"		"fxfire_wingl1_1"}
		{add_view "aero_die_fire"		"fire_wingl1_2"		"fxfire_wingl1_2"}
		{add_view "aero_die_fire"		"fire_wingr1_1"		"fxfire_wingr1_1"}
		{add_view "aero_die_fire"		"fire_wingr1_2"		"fxfire_wingr1_2"}
		{add_view "aero_die_fire"		"fire_wingl2_1"		"fxfire_wingl2_1"}
		{add_view "aero_die_fire"		"fire_wingl2_2"		"fxfire_wingl2_2"}
		{add_view "aero_die_fire"		"fire_wingr2_1"		"fxfire_wingr2_1"}
		{add_view "aero_die_fire"		"fire_wingr2_2"		"fxfire_wingr2_2"}

		{if not rain
			{add_view	"dustrun_big"			"on_ground"				"fxtracefront"}
			{add_view	"dustrun_big"			"on_ground"				"fxtraceleft"}
			{add_view	"dustrun_big"			"on_ground"				"fxtraceright"}
			{add_view	"dustrun_small"			"on_grass"				"fxtracefront"}
			{add_view	"dustrun_small"			"on_grass"				"fxtraceleft"}
			{add_view	"dustrun_small"			"on_grass"				"fxtraceright"}
			{add_view	"dustrun_sand_big" 		"on_sand"				"fxtracefront"}
			{add_view	"dustrun_sand_big" 		"on_sand"				"fxtraceleft"}
			{add_view	"dustrun_sand_big" 		"on_sand"				"fxtraceright"}
			{add_view	"dustrun_snow_big" 		"on_snow"				"fxtracefront"}
			{add_view	"dustrun_snow_big" 		"on_snow"				"fxtraceleft"}
			{add_view	"dustrun_snow_big" 		"on_snow"				"fxtraceright"}
			{add_view	"dustrun_small"			"on_country_road"				"fxtracefront"}
			{add_view	"dustrun_small"			"on_country_road"				"fxtraceleft"}
			{add_view	"dustrun_small"			"on_country_road"				"fxtraceright"}
                	}

		{add_view	"drops_water"			"on_water"			"fxtracefront"}
		{add_view	"drops_water"			"on_water"			"fxtraceleft"}
		{add_view	"drops_water"			"on_water"			"fxtraceright"}
		{add_view	"drops_water_moto"		"on_puddle"			"fxtracefront"}
		{add_view	"drops_water_moto"		"on_puddle"			"fxtraceleft"}
		{add_view	"drops_water_moto"		"on_puddle"			"fxtraceright"}

		{add_view	"rok_tail"		"flare_left"			"flare1_shooter"}
		{add_view	"rok_tail"		"flare_right"			"flare2_shooter"}
;		{add_view	"_flare_fly"	"flare_left"			"flare1_shooter"}
;		{add_view	"_flare_fly"	"flare_right"			"flare2_shooter"}
		{add_view	"_chaff_fly"	"chaff_left"			"chaff1_shooter"}
		{add_view	"_chaff_fly"	"chaff_right"			"chaff2_shooter"}

		{call "update_weaponry"}
		{call "update_hatch_on_spawn"}
		{components "flare_fly_l" break}
		{components "flare_fly_r" break}
		{components "chaff_fly_l" break}
		{components "chaff_fly_r" break}
		("spawn")
		{delay 0.1
			{if chassis "airborne"
				 {if not linked
				{tags add "takeoff"}
				{tags add "takeoff_speed"}
				{ani_play "flaps_off"}
				{tags add "flaps_off"}
				{tags add "plane_in_flight"}
				 }
			}
		}
		{view pause "engine1_overburn"}
		{view pause "engine2_overburn"}
		{volumes "steering_elev" disable contact contact_ground}
		{volumes "steering_rudder" disable contact contact_ground}
		{volumes "steering_eler_r" disable contact contact_ground}
		{volumes "steering_eler_l" disable contact contact_ground}
		
		{call "disable_aututakeoff_on_spawn"}
		{tags remove "need_auto_landing"}
	}
;	{on "disable_aututakeoff_on_spawn"
;		{tags add "cw_autotakeoff_activated"}
;	}
	{on "link_flare_fx"
		{link_sound "flare"	"weapon/shot/reactive/flare"}
	}
	{on "link_engine_effects"
		{add_view	"airstream_exhaust"	"engine_exhaust"		"engine_exhaust"	}
		{add_view	"airstream_exhaust"	"engine1_exhaust"		"engine1_exhaust"	}
		{add_view	"airstream_exhaust"	"engine2_exhaust" 		"engine2_exhaust"	}
		{add_view	"overburn"		"engine_overburn"		"engine_exhaust"	}
		{add_view	"overburn"		"engine1_overburn"		"engine1_exhaust"	}
		{add_view	"overburn"		"engine2_overburn" 		"engine2_exhaust"	}
	}

	(define "terrain_fx_"
            {if terrain_fx "%0"
			 {if not chassis "airborne"
				 {if tagged "takeoff_speed"
					{view start "on_%0"}
					{view start "on_%0_time_short"}
					{delay 0.1
						{view pause "on_%0_time_short"}
					}
		         }
		     }
			 {if terrain_pp "%0"
			  {if not chassis "airborne"
				{movement_limit %1}
			  }
			 }
			 
			 
	        }
	)
	(define "terrain_fx"
		{on terrain_fx %0 enter overload
			("terrain_fx_" args %1 %2)
		}
		{on terrain_fx %0 leave
			{view pause "on_%1"}
		}
	)
	("terrain_fx" args "ground"			ground slow)
	("terrain_fx" args "sand"			sand slow)
	("terrain_fx" args "grass" 			grass slow)
	("terrain_fx" args "deep_water" 			water slow)
	("terrain_fx" args "water" 			water slow)
	("terrain_fx" args "shallow_water" 	puddle slow)
	("terrain_fx" args "puddle"			puddle slow)
	("terrain_fx" args "mud"			mud slow)
	("terrain_fx" args "road"	road fast)
	("terrain_fx" args "country_road"	country_road fast)
	("terrain_fx" args "snow"			snow slow)

	{on "add_movement_sound" overload
		{link_sound "fly"			"vehicle/airborne/jet_fly"			}
		{link_sound "engine_start"		"vehicle/airborne/jet_engine_start"			}
		{link_sound "engine_work"		"vehicle/airborne/jet_engine_work"			}
		{link_sound "engine_stop"		"vehicle/airborne/jet_engine_stop"			}
		{link_sound "overburn"		"vehicle/airborne/overburn"			}
	}


;=============Проверка состояния общая.

;=================При достижении скорости - анимация подъема носа.


	{on "takeoff" overload
			{tags add "cwfs_set_fuel"}
	      {call "update_lights" }
	      {if tagged "air_brake" {ani_play "air_brake" -1} {tags remove "air_brake"} {play_sound "air_brake"}}
	      {if tagged "takeoff_speed" 
			{call "takeoff_actions"}
		   else not user_control
			{call "takeoff_actions"}
		  }
	}
{on "takeoff_actions"
			{if work "targeting_pod"
				{ani_play "targeting_pod" 0.3 loop}
			}
			{if not dead
				{ani_play "wheels"}
				{play_sound "fly" 1}
			}
			{call "check_moveability"}
			{call "update_weaponry"}
			{tags add "plane_in_flight"}
			{if not tagged "flaps_off" {ani_play "flaps_off"} {tags add "flaps_off"} {play_sound "flaps"}}
			{delay 2 {ani_play "nose_up" -1}}
			{delay 4 
				   {if chassis "airborne"
					  {if not linked
				{ani_play "fly" 0.2 loop}
				{ani_play "basis" 0.4}
				{view pause "engine_overburn"}
				{view pause "engine1_overburn"}
				{view pause "engine2_overburn"}
				{stop_sound "overburn"}
				{call "check_moveability"}
					   }
				   }
			}
			{view pause "on_ground"}
			{view pause "on_sand"}
			{view pause "on_grass"}
			{view pause "on_water"}
			{view pause "on_puddle"}
			{view pause "on_mud"}
			{view pause "on_country_road"}
			{view pause "on_snow"}
			{delay 0.3 "start_check_altitude" {call "check_altitude"}}
}
	{on "check_altitude"
		{if has_order "withdraw" 
			{kill_delay "takeoff_again"}
			{delay 25 "takeoff_again" {tags remove "cw_autotakeoff_activated"}{tags add "return_after_withdraw"}}
		}
		
	    {if altitude 65 {components "target_hight" break}
		else
		{components "target_hight" repair}
		}
	    {if flag "engine_started"
			{if not altitude -3
				{impulse up 0.5 forward 5}
				{call "fall"}
				{call "collide"}
				{call "tear_wheelright"}
				{call "tear_wheelleft"}
				{call "tear_wheelfront"}
				{call "tear_wingl1"}
				{call "tear_wingl2"}
				{call "tear_wingr1"}
				{call "tear_wingr2"}
				{call "tear_part"}
				{call "mp_destroy"}
				{delay 0.05 {constrain_velocity 80}}
				{delay 0.1 {constrain_velocity 80}}
				{delay 0.2 {constrain_velocity 80}}
				{delay 0.3 {constrain_velocity 80}}
				{delay 0.4 {constrain_velocity 80}}
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
	}

	{on "takeoff_load" overload
		{tags add "cwfs_set_fuel"}
		{call "update_lights" }
		{ani_wind "wheels" end}
		{play_sound "fly" 1}
		{if tagged "air_brake" {ani_play "air_brake" -1} {tags remove "air_brake"} {play_sound "air_brake"}}
		{if not tagged "flaps_off" {ani_play "flaps_off"} {tags add "flaps_off"}{play_sound "flaps"}}
		{call "check_moveability"}
		{call "update_weaponry"}
		{tags add "plane_in_flight"}
		{delay 4 
		       {if chassis "airborne"
		          {if not linked
			{ani_play "fly" 0.2 loop}
			{ani_wind "basis" end}
			{view pause "engine_overburn"}
			{view pause "engine1_overburn"}
			{view pause "engine2_overburn"}
			{stop_sound "overburn"}
			{call "check_moveability"}
		           }
		       }
		}
		{view pause "on_ground"}
		{view pause "on_sand"}
		{view pause "on_grass"}
		{view pause "on_water"}
		{view pause "on_puddle"}
		{view pause "on_mud"}
		{view pause "on_country_road"}
		{view pause "on_snow"}
		{delay 0.3 "start_check_altitude" {call "check_altitude"}{tags remove "return_after_withdraw"}}
	}

	{on "landing" overload
		{ani_stop "targeting_pod"}
		{call "update_lights"}
		{ani_stop "fly"}
		{ani_stop "damage_fly"}
		{tags remove "damage_fly"}
		{ani_play "wheels" -1 callback}
		{ani_play "basis" -2}
		{ani_play "nose_up"}
		{stop_sound "fly"}
		{if not tagged "air_brake" {ani_play "air_brake"} {tags add "air_brake"} {play_sound "air_brake"}}
		{if tagged "flaps_off" {ani_play "flaps_off" -1} {tags remove "flaps_off"}{play_sound "flaps"}}
		{tags remove "return_after_withdraw"}
	}
	{on "landing_load" overload
		{call "update_lights"}
		{ani_stop "fly"}
		{ani_stop "damage_fly"}
		{tags remove "damage_fly"}
		{ani_play "wheels" -2 callback}
		{ani_play "basis" -4}
		{stop_sound "fly"}
		{if not tagged "air_brake" {ani_play "air_brake"} {tags add "air_brake"} {play_sound "air_brake"}}
		{if tagged "flaps_off" {ani_play "flaps_off" -1} {tags remove "flaps_off"}{play_sound "flaps"}}
		{tags remove "return_after_withdraw"}
	}
	{on engine on overload
		{call "engine_on"}
		{call "check_altitude"}
	}

	{on engine off overload 
		{if tagged "air_brake" {ani_play "air_brake" -1} {tags remove "air_brake"} {play_sound "air_brake"}}
		{if not tagged "flaps_off" {ani_play "flaps_off"} {tags add "flaps_off"}{play_sound "flaps"}}
		{call "engine_stop"}
		{play_sound "engine_stop"}
		{if tagged "plane_in_flight"
			{tags add "cwfs_set_fuel"}
			{if not work "wheel_back"
				 {if rand 0.2
				{components "body" break}
				 }
			}
			{if not work "retract_wheelR"
				 {if rand 0.5
				{components "body" break}
				 }
			}
			{if not work "retract_wheelL"
				 {if rand 0.5
				{components "body" break}
				 }
			}
		}
		{call "check_moveability"}
		{tags remove "plane_in_flight"}
	}


	{on "engine_on" overload
		{if tagged "air_brake" {ani_play "air_brake" -1} {tags remove "air_brake"} {play_sound "air_brake"}}
		{if tagged "flaps_off" {ani_play "flaps_off" -1} {tags remove "flaps_off"}{play_sound "flaps"}}
		{if not flag "engine_started"
			{set "engine_started" 1}
			{play_sound "engine_start"}
			{ani_play "engine_start" callback}
			{call "check_takeoff_speed"}
			{if work "engine1"
				{ani_play "engine1_start" callback}
				{view start "engine1_exhaust"}
			}
			{if work "engine2"
				{ani_play "engine2_start" callback}
				{view start "engine2_exhaust"}
			}
			{if work "enginea"
				{ani_play "enginea_start" callback}
				{view start "enginea_exhaust"}
			}
			{if work "engineb"
				{ani_play "engineb_start" callback}
				{view start "engineb_exhaust"}
			}
			{if work "enginec"
				{ani_play "enginec_start" callback}
				{view start "enginec_exhaust"}
			}
			{if work "engined"
				{ani_play "engined_start" callback}
				{view start "engined_exhaust"}
			}
			{delay 1
			     {if work "engine"
				{view start "engine_exhaust"}
			     }
			     {if work "engine1"
				{view start "engine1_exhaust"}
			     }
			     {if work "engine2"
				{view start "engine2_exhaust"}
			     }
			}
		}
	}

	(define "enough_takeoff_speed"
		{if not tagged "takeoff_speed"
			{tags add "takeoff"}
			{tags add "takeoff_speed"}
			{ani_play "nose_up"}
			("terrain_fx_" args 	ground slow)
			("terrain_fx_" args 	sand slow)
			("terrain_fx_" args 	grass slow)
			("terrain_fx_" args 	water slow)
			("terrain_fx_" args 	water slow)
			("terrain_fx_" args 	puddle slow)
			("terrain_fx_" args 	puddle slow)
			("terrain_fx_" args 	mud slow)
			("terrain_fx_" args 	road fast)
			("terrain_fx_" args 	country_road fast)
			("terrain_fx_" args 	snow slow)
		}
	)
	(define "not_enough_takeoff_speed"
		{if tagged  "takeoff_speed"
			{tags remove "takeoff"}
			{tags remove "takeoff_speed"}
			{ani_play "nose_up" -1}
			("terrain_fx_" args 	ground slow)
			("terrain_fx_" args 	sand slow)
			("terrain_fx_" args 	grass slow)
			("terrain_fx_" args 	water slow)
			("terrain_fx_" args 	water slow)
			("terrain_fx_" args 	puddle slow)
			("terrain_fx_" args 	puddle slow)
			("terrain_fx_" args 	mud slow)
			("terrain_fx_" args 	road fast)
			("terrain_fx_" args 	country_road fast)
			("terrain_fx_" args 	snow slow)
		}
	)


{on "check_takeoff_speed"
      {if not chassis "airborne"
		{if velocity 30
			{if terrain_pp "road"
			else terrain_pp "country_road"
			else not tagged "return_after_withdraw" 
				{components "wheel_back" break}
				{components "retract_wheelR" break}
				{components "retract_wheelL" break}
			}
		}
		{if work "flap1"
			{if work "flap2"
				{if velocity 30	("enough_takeoff_speed")	else	("not_enough_takeoff_speed")}
			else
				{if velocity 32	("enough_takeoff_speed")	else	("not_enough_takeoff_speed")}
			}
		else
			{if work "flap2"
				{if velocity 32	("enough_takeoff_speed")	else	("not_enough_takeoff_speed")}
			else
				{if velocity 35	("enough_takeoff_speed")	else	("not_enough_takeoff_speed")}
			}
		}
       }
	{delay 0.2
	    {if flag "engine_started"
	        {if not chassis "airborne"
				{call "check_takeoff_speed"}
	         else  not tagged "takeoff_speed"
			  {if user_control
				{impulse forward 5 3 no_position}
				{chassis_work 0}
				{call "tear_wheelright"}
				{call "tear_wheelleft"}
				{call "tear_wheelfront"}
				{call "mp_destroy"}
			  }
	        }
	    }
		{tags remove "return_after_withdraw"}
	}

}

	{on animation_end "engine_start" overload
		{ani_play "engine_work" loop}
		{play_sound "engine_work" 1}
	}

	{on animation_end "enginea_start" overload
		{ani_play "enginea_work" loop}
		{play_sound "engine_work" 1}
	}
	{on animation_end "engineb_start" overload
		{ani_play "engineb_work" loop}
		{play_sound "engine_work" 1}
	}
	{on animation_end "enginec_start" overload
		{ani_play "enginec_work" loop}
		{play_sound "engine_work" 1}
	}
	{on animation_end "engined_start" overload
		{ani_play "engined_work" loop}
		{play_sound "engine_work" 1}
	}

	{on "engine_stop" overload
		{kill_delay "engine_stopped"}
		{view pause "engine_exhaust"}
		{view pause "engine1_exhaust"}
		{view pause "engine2_exhaust"}
		{view pause "enginea_exhaust"}
		{view pause "engineb_exhaust"}
		{view pause "enginec_exhaust"}
		{view pause "engined_exhaust"}
		{if flag "engine_started"
			{set "engine_started" 0}
			{ani_stop "engine_start"}
			{ani_stop "engine_work"}
			{ani_play "engine_stop"}
			{ani_stop "engine1_work"}
			{ani_play "engine1_stop"}
			{ani_stop "engine2_work"}
			{ani_play "engine2_stop"}
			{ani_stop "enginea_start"}
			{ani_stop "enginea_work"}
			{ani_play "enginea_stop"}
			{ani_stop "engineb_start"}
			{ani_stop "engineb_work"}
			{ani_play "engineb_stop"}
			{ani_stop "enginec_start"}
			{ani_stop "enginec_work"}
			{ani_play "enginec_stop"}
			{ani_stop "engined_start"}
			{ani_stop "engined_work"}
			{ani_play "engined_stop"}
			{stop_sound "engine_start"}
			{stop_sound "engine_work"}
			{stop_sound "fly"}
		}
	}


	{on "update_moveable" overload
		{if not chassis "airborne"
			{inherited}
		}
	}

	{on turn on	{call "check_moveability"}}
	{on turn off	{call "check_moveability"}}
	{on move on	{call "check_moveability"}}
	{on move off	{call "check_moveability"}
		{view pause "engine_overburn"}
		{view pause "engine1_overburn"}
		{view pause "engine2_overburn"}
		{stop_sound "overburn"}
	}
	{on accelerate on	{call "check_moveability"} 
		{if work "engine" {view start "engine_overburn"} {play_sound "overburn" 1}}
		{if work "engine1" {view start "engine1_overburn"} {play_sound "overburn" 1}}
		{if work "engine2" {view start "engine2_overburn"}{play_sound "overburn" 1}}
	}
	{on accelerate off	{call "check_moveability"}}
	{on brake on	{call "check_moveability"}}
	{on brake off	{call "check_moveability"}
		{view pause "engine_overburn"}
		{view pause "engine1_overburn"}
		{view pause "engine2_overburn"}
		{stop_sound "overburn"}
	}

	{on "script_overburn_on" 
		{if work "engine" {view start "engine_overburn"} {play_sound "overburn" 1}}
		{if work "engine1" {view start "engine1_overburn"} {play_sound "overburn" 1}}
		{if work "engine2" {view start "engine2_overburn"}{play_sound "overburn" 1}}
	}
	{on "script_overburn_off" 
		{view pause "engine_overburn"}
		{view pause "engine1_overburn"}
		{view pause "engine2_overburn"}
		{play_sound "overburn" 0}
	}
;=================Обработка экипажа

	(define "update_hatch_aero"
		{if not operatable
			{if %wind
				{ani_wind "open" end}
			else
				{ani_play "open" +1.0 resume}
			}
		else
			{if crew_in_place "driver"
				{call "fonar_open"}
			else
				{if %wind
					{ani_wind "open" begin}
				else
					{ani_play "open" -1.0 resume}
				}
			}
		}
	)
{on "fonar_open"
	{ani_wind "open" end}
}

{on "update_hatch_on_spawn"
	("update_hatch_aero" wind(true))
}

{on operatable on
	("update_hatch_aero" wind(false))
}
{on operatable off
;	{if chassis "airborne" {call "fall"}}	;приводит к падению самолета при возврате
	("update_hatch_aero" wind(false))
}
{on crew in
	("update_hatch_aero" wind(false))
}
{on crew out
	("update_hatch_aero" wind(false))
}


;=================Обработка повреждений.

{on "secondary_damage"
	{if  stuff "fg" 
		{fragments c4 0.5 r0 1.4 r1 1.5 position}
	else stuff  "hmgun"
		{fragments c4 0.5 r0 0.1 r1 0.2 position}
	else stuff "rok"
		{fragments c4 3 r0 0.8 r1 0.9 position}
		{fragments c4 0.5 r0 1.0 r1 1.1 position}
	else stuff "ptrk"
		{fragments c4 3 r0 0.8 r1 0.9 position}
		{fragments c4 0.5 r0 1.0 r1 1.1 position}
	else stuff "cm"
		{fragments c4 3 r0 0.7 r1 0.8 position}
		{fragments c4 0.5 r0 0.9 r1 1.0 position}
	else stuff "rocketlauncher"
		{fragments c4 3 r0 0.7 r1 0.8 position}
		{fragments c4 0.5 r0 0.9 r1 1.0 position}
	else stuff  "autocannon_small"
		{fragments c4 0.5 r0 0.3 r1 0.4 position}
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

(define "pierce_bomb"
	volume "%bomb_name"
		{bone cut "%bomber_name"}
		{if rand %expl_chance
			{spawn "ex_air_big"}
			{tear "destroyed_bomb_small" bone "%bomb_name"
				{impulse up -2 1 forward 50 rnd_dir 5 no_position}
				{stuff_detonate}
			}
		else 
		  {if chassis "airborne"
			{tear "destroyed_bomb_small" bone "%bomb_name"
				{impulse up -2 1 forward 50 rnd_dir 5 no_position}
			}
		  else
			{tear "destroyed_bomb_small" bone "%bomb_name"
				{impulse up -2 1 forward 0.1 rnd_dir 1 no_position}
			}
		  }
		}
)
(define "cut_glass"
	else volume "%glass_name" 
	 	{spawn "glass_hit2"}
	 	{delay 0.1
		 	{tear "piece_big_airborne_wing" bone "%glass_name"
				{delete}
			}
	 	}
)
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
	else component "hydrosystem" 
		{burn fx "drops_oil_small_long" fake}
		{if rand 0.03
			{call "_burn"}
		}
	else component "ammo_storage_autocannon"
		{if not tagged "no_messages" {damage_report "ammo_storage_autocannon" "ammo_storage_autocannon_damaged"}}
		{spawn "metal_hit_bul"}
		{if rand 0.55 {components "ammo_storage_autocannon" break}}
	else component "ammo_storage_mgun"
		{if not tagged "no_messages" {damage_report "ammo_storage_mgun" "ammo_storage_mgun_damaged"}}
		{spawn "metal_hit_bul"}
		{if rand 0.45 {components "ammo_storage_mgun" break}}
	else component "radarx"
		{if not tagged "radarx_break"
			{components "radarx" break}
			{tear "piece_medium_steel" bone "Visor_radarx"
              	  			{impulse up 2 1 dir 2 1}
			}
			{spawn "metal_hit_bul"}
		}
	else component "radarl"
		{if not tagged "radarl_break"
			{components "radarl" break}
			{tear "piece_medium_steel" bone "Visor_radarl"
              	  			{impulse up 2 1 dir 2 1}
			}
			{tear "piece_medium_steel" bone "Visor_radarl1"
              	  			{impulse up 2 1 dir 2 1}
			}
			{spawn "metal_hit_bul"}
		}
	else component "ols"	;ОЛС - оптико-локационная станция. То есть, прицел.
		{if not tagged "ols_break"
			{tags add "ols_break"}
			("stop_damage_sound")
			{play_sound "ols_damage"}
			{if not tagged "no_messages" {damage_report "ols" "ols_damaged"}}
			{tear "piece_medium_steel" bone "visor_ols"
              	  			{impulse up 2 1 dir 2 1}
			}
		}
		{spawn "glass_hit" }
	else component "ols1"	;ОЛС - оптико-локационная станция. То есть, прицел.
		{if not tagged "ols1_break"
			{tags add "ols1_break"}
			("stop_damage_sound")
			{play_sound "ols_damage"}
			{if not tagged "no_messages" {damage_report "ols" "ols_damaged"}}
			{tear "piece_medium_steel" bone "visor_ols1"
              	  			{impulse up 2 1 dir 2 1}
			}
		}
		{spawn "glass_hit" }
	else component "ols2"	;ОЛС - оптико-локационная станция. То есть, прицел.
		{if not tagged "ols2_break"
			{tags add "ols2_break"}
			("stop_damage_sound")
			{play_sound "ols_damage"}
			{if not tagged "no_messages" {damage_report "ols" "ols_damaged"}}
			{tear "piece_medium_steel" bone "visor_ols2"
              	  			{impulse up 2 1 dir 2 1}
			}
		}
		{spawn "glass_hit" }
	else component "targeting_pod"	
		{if not tagged "targeting_pod_break"
			{tags add "targeting_pod_break"}
			{components "targeting_pod" break}
			("stop_damage_sound")
			{play_sound "ols_damage"}
			{tear "piece_medium_steel" bone "visor_pod"
              	  			{impulse up 2 1 dir 2 1}
			}
		}
		{spawn "glass_hit" }
	else component "body" 
		{call "secondary_damage"}
	else component "cabin" 
		{spawn "glass_hit" }
	else volume "glass" 
		{volume disable bullet contact}
	 	{spawn "glass_hit2"}
	 	{delay 0.1
		 	{tear "piece_big_airborne_wing" bone from_volume
				{delete}
			}
	 	}
	else volume "glass1" 
		{volume disable bullet contact}
	 	{spawn "glass_hit2"}
	 	{delay 0.1
		 	{tear "piece_big_airborne_wing" bone from_volume
				{delete}
			}
	 	}
	("cut_glass" glass_name(glass))
	("cut_glass" glass_name(glass1))
	("cut_glass" glass_name(glass2))
	("cut_glass" glass_name(glass3))
	("cut_glass" glass_name(glass4))
	("cut_glass" glass_name(glass5))
	("cut_glass" glass_name(glass6))
	("cut_glass" glass_name(glass7))
	("cut_glass" glass_name(glass8))
	("cut_glass" glass_name(glass9))
;bombs do not explode when pierced, only from electric detonator
	}
      };конец запрета на пробивание указателем ПТУР
;===========================================другие компоненты, авионика?
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
;У однодвигательного самолета ЕСТЬ engine, НЕТ engine1, engine2, у четырехмоторного - есть ТОЛЬКО enginea, engineb, enginec, engined
;У двухдвигательного самолета НЕТ engine, ЕСТЬ engine1 (левый), engine2 (правый)
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
	else component "enginea"
	     {if work "enginea"
		{components "enginea" break}
		{burn fx "smoke_aero_small" fake}
	     }
	else component "engineb"
	     {if work "engineb"
		{components "engineb" break}
		{burn fx "smoke_aero_small" fake}
	     }
	else component "enginec"
	     {if work "enginec"
		{components "enginec" break}
		{burn fx "smoke_aero_small" fake}
	     }
	else component "engined"
	     {if work "engined"
		{components "engined" break}
		{burn fx "smoke_aero_small" fake}
	     }
;======Авионика=====
	else component "wingr1"
	     {if work "wingr1"
		{components "wingr1" break}
		{burn fx "smoke_aero_small" fake}
	     }
	else component "wingr2"
	     {if work "wingr2"
		{components "wingr2" break}
		{burn fx "smoke_aero_small" fake}
	     }
	else component "wingl1"
	     {if work "wingl1"
		{components "wingl1" break}
		{burn fx "smoke_aero_small" fake}
	     }
	else component "wingl2"
	     {if work "wingl2"
		{components "wingl2" break}
		{burn fx "smoke_aero_small" fake}
	     }
	else component "aileron_l"
	     {if work "aileron_l"
		{components "aileron_l" break}
		{burn fx "smoke_aero_small" fake}
	     }
	else component "aileron_r"
	     {if work "aileron_r"
		{components "aileron_r" break}
		{burn fx "smoke_aero_small" fake}
	     }
	else component "elevator"
	     {if work "elevator"
		{components "elevator" break}
		{burn fx "smoke_aero_small" fake}
	     }
	else component "elevator_l"
	     {if work "elevator_l"
		{components "elevator_l" break}
		{burn fx "smoke_aero_small" fake}
	     }
	else component "elevator_r"
	     {if work "elevator_r"
		{components "elevator_r" break}
		{burn fx "smoke_aero_small" fake}
	     }
	else component "rudder"
	     {if work "rudder"
		{components "rudder" break}
		{burn fx "smoke_aero_small" fake}
	     }
	else component "rudder_l"
	     {if work "rudder_l"
		{components "rudder_l" break}
		{burn fx "smoke_aero_small" fake}
	     }
	else component "rudder_r"
	     {if work "rudder_r"
		{components "rudder_r" break}
		{burn fx "smoke_aero_small" fake}
	     }
	else component "stabilizer"
	     {if work "stabilizer"
		{components "stabilizer" break}
		{burn fx "smoke_aero_small" fake}
	     }
	else component "stabilizer_l"
	     {if work "stabilizer_l"
		{components "stabilizer_l" break}
		{burn fx "smoke_aero_small" fake}
	     }
	else component "stabilizer_r"
	     {if work "stabilizer_r"
		{components "stabilizer_r" break}
		{burn fx "smoke_aero_small" fake}
	     }
	else component "tail"
	     {if work "tail"
		{components "tail" break}
		{burn fx "smoke_aero_small" fake}
	     }
	else component "tail_l"
	     {if work "tail_l"
		{components "tail_l" break}
		{burn fx "smoke_aero_small" fake}
	     }
	else component "tail_r"
	     {if work "tail_r"
		{components "tail_r" break}
		{burn fx "smoke_aero_small" fake}
	     }
	else component "flap_l"
	     {if work "flap_l"
		{components "flap_l" break}
		{burn fx "smoke_aero_small" fake}
	     }
	else component "flap_r"
	     {if work "flap_r"
		{components "flap_r" break}
		{burn fx "smoke_aero_small" fake}
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
	else component "antifire"
	     {if work "antifire"
		{components "antifire" break}
		{burn fx "smoke_aero_small" fake}
	     }
	else component "apu"
	     {if work "apu"
		{components "apu" break}
		{burn fx "smoke_aero_small" fake}
	     }
	else component "ppu"
	     {if work "ppu"
		{components "ppu" break}
		{burn fx "smoke_aero_small" fake}
	     }
	else component "ecm"
	     {if work "ecm"
		{components "ecm" break}
		{burn fx "smoke_aero_small" fake}
	     }
	else component "ecm_pod"
	     {if work "ecm_pod"
		{components "ecm_pod" break}
		{burn fx "smoke_aero_small" fake}
	     }
	else component "towed_decoy1"
	     {if work "towed_decoy1"
			{components "towed_decoy1" break}	
	     }
	else component "towed_decoy2"
	     {if work "towed_decoy2"
			{components "towed_decoy2" break}	
	     } 
	else component "targeting_pod"
	     {if work "targeting_pod"
		{components "targeting_pod" break}
		{burn fx "smoke_aero_small" fake}
	     }
	else component "electronics"
	     {if work "electronics"
		{components "electronics" break}
		{burn fx "smoke_aero_small" fake}
	     }
	else  component "ir_active_def"
	     {if work "ir_active_def"
		{components "ir_active_def" break}
		{burn fx "smoke_aero_small" fake}
	     }
	else  component "ir_active_def_2gen"
	     {if work "ir_active_def_2gen"
		{components "ir_active_def_2gen" break}
		{burn fx "smoke_aero_small" fake}
	     }
;=====Вооружение=====
	else  component "laser_td" ;ус-во лазерного наведения
	    {if work "laser_td" 
		{components "laser_td" break}
		{burn fx "smoke_aero_small" fake}
		{spawn "glass_hit" }
	     }
	else  component "radar_td" ;ус-во радарного наведения
	    {if work "radar_td" 
		{components "radar_td" break}
		{burn fx "smoke_aero_small" fake}
		{spawn "glass_hit" }
	     }

	else   component "gun"     {if work "gun" 	{components "gun" break}	{spawn "metal_hit_bul"}     }
	else   component "mgun"     {if work "mgun" 	{components "mgun" break}	{spawn "metal_hit_bul"}     }
	else component "mgun1"     {if work "mgun1" 	{components "mgun1" break}	{spawn "metal_hit_bul"}     }
	else component "mgun2"     {if work "mgun2" 	{components "mgun2" break}	{spawn "metal_hit_bul"}     }	

	else component "ptur"     {if work "ptur" 	{components "ptur" break}	{spawn "metal_hit_bul"}     }
	else component "ptur1"     {if work "ptur1" 	{components "ptur1" break}	{spawn "metal_hit_bul"}     }
	else component "ptur2"     {if work "ptur2" 	{components "ptur2" break}	{spawn "metal_hit_bul"}     }	
	else component "ptur3"     {if work "ptur3" 	{components "ptur3" break}	{spawn "metal_hit_bul"}     }
	else component "ptur4"     {if work "ptur4" 	{components "ptur4" break}	{spawn "metal_hit_bul"}     }	
	else component "ptur5"     {if work "ptur5" 	{components "ptur5" break}	{spawn "metal_hit_bul"}     }
	else component "ptur6"     {if work "ptur6" 	{components "ptur6" break}	{spawn "metal_hit_bul"}     }

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
       }
}

{on blast_hit
    {if min_energy 10
	{call "tear_wingl2"}
	{call "tear_wingr2"}
	{call "tear_wingr1"}
	{call "tear_wingl1"}
	{if volume "part"
		{call "tear_part"}
	}
    else min_energy 4
	{if rand 0.05	{call "tear_wingl2"}}
	{if rand 0.05	{call "tear_wingr2"}}
	{if rand 0.05	{call "tear_wingl1"}}
	{if rand 0.05	{call "tear_wingr1"}}
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


{on "update_weaponry"
	{if not tagged "destroyed"
		{weapon_work "gun" 1}
		{weapon_work "mgun" 1}
		{weapon_work "mgun1" 1}
		{weapon_work "mgun2" 1}
		{weapon_work "ptur" 1}
		{weapon_work "ptur1" 1}
		{weapon_work "ptur2" 1}
		{weapon_work "ptur3" 1}
		{weapon_work "ptur4" 1}
		{weapon_work "ptur5" 1}
		{weapon_work "ptur6" 1}
		{weapon_work "nar" 1}
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
		{weapon_work "bomber" 1}
		{weapon_work "bomber1" 1}
		{weapon_work "bomber2" 1}
		{tags remove "no_missile_control"}
	}

	     {if not work "hydrosystem" 
		{call "u_w_hydrosystem_damaged"}
	      }
	     {if not work "targeting_pod" 
		{call "u_w_targeting_pod_damaged"}
	      }
	     {if not work "radarx" 
		{call "u_w_radarx_damaged"}
	      }
	     {if not work "radarl" 
		{call "u_w_radarl_damaged"}
	      }
	     {if not work "laser_td" 
		{call "u_w_laser_td_damaged"}
	      }
	     {if not work "radar_td" 
		{call "u_w_radar_td_damaged"}
	      }
	     {if not work "electronics" 
		{call "u_w_electronics_damaged"}
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
	     {if not work "ptur5" {weapon_work "ptur5" 0} }
	     {if not work "ptur6" {weapon_work "ptur6" 0} }
	     {if flag "specability" 
		{weapon_work "ptur" 0}
		{weapon_work "ptur1" 0}
		{weapon_work "ptur2" 0}
		{weapon_work "ptur3" 0}
		{weapon_work "ptur4" 0}
		{weapon_work "ptur5" 0}
		{weapon_work "ptur6" 0}
	     }
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
	     {if not work "ecm" {components "ecm_defence_sys" break} else {components "ecm_defence_sys" repair}}
	     {if not work "ecm_pod" {components "ecm_pod_defence_sys" break}  else {components "ecm_pod_defence_sys" repair}}
}

{on "u_w_hydrosystem_damaged"
	{weapon_work "gun" 0}
}
{on "u_w_targeting_pod_damaged"
}
{on "u_w_radarx_damaged"
}
{on "u_w_radarl_damaged"
}
{on "u_w_laser_td_damaged"
}
{on "u_w_radar_td_damaged"
}
{on "u_w_electronics_damaged"
	{weapon_work "gun" 0}
	{weapon_work "ptur" 0}
	{weapon_work "ptur1" 0}
	{weapon_work "ptur2" 0}
	{weapon_work "ptur3" 0}
	{weapon_work "ptur4" 0}
	{weapon_work "ptur5" 0}
	{weapon_work "ptur6" 0}
	{weapon_work "bomber" 0}
	{weapon_work "bomber1" 0}
	{weapon_work "bomber2" 0}
}

{on "check_moveability"
	     {if not work "engine"
		{view pause "engine_exhaust"}
	     }
	     {if not work "engine1"
		{view pause "engine1_exhaust"}
	     }
	    {if not work "engine2"
		{view pause "engine2_exhaust"}
	    }
	     {if not work "enginea"
		{view pause "enginea_exhaust"}
		{ani_stop "enginea_start"}
		{ani_stop "enginea_work"}
		{ani_play "enginea_stop"}
	     }
	     {if not work "engineb"
		{view pause "engineb_exhaust"}
		{ani_stop "engineb_start"}
		{ani_stop "engineb_work"}
		{ani_play "engineb_stop"}
	     }
	     {if not work "enginec"
		{view pause "enginec_exhaust"}
		{ani_stop "enginec_start"}
		{ani_stop "enginec_work"}
		{ani_play "enginec_stop"}
	     }
	     {if not work "engined"
		{view pause "engined_exhaust"}
		{ani_stop "engined_start"}
		{ani_stop "engined_work"}
		{ani_play "engined_stop"}
	     }


;=============в воздухе
	{if chassis "airborne"
	     {if not work "engine" {call "fall"} }
	     {if not work "engine1"  {if not work "engine2" {call "fall"}  }  }
	     {if not work "enginea"  {if not work "engineb" {if not work "enginec" {call "fall"}  }  }  }
	     {if not work "engineb"  {if not work "enginec" {if not work "engined" {call "fall"}  }  }  }
	     {if not work "enginec"  {if not work "engined" {if not work "enginea" {call "fall"}  }  }  }
	     {if not work "engined"  {if not work "enginea" {if not work "engineb" {call "fall"}  }  }  }

	     {if not work "pilot_panel" {call "fall"} }
	     {if not work "hydrosystem_tank" {if not flag "delayed_fall_long"     {set "delayed_fall_long" 1}    {call "delayed_fall_long"}} }
	     {if not work "body" {call "fall"} {call "mp_destroy"}}
;=============на земле
	else
	     {chassis_work 1}
	     {set "delayed_fall_long" 0}
	     {if not work "engine"	{chassis_work 0}  }
	     {if not work "engine1"      {if not work "engine2" {chassis_work 0}     }     }

	     {if not work "enginea"      {if not work "engineb" {chassis_work 0}     }     }
	     {if not work "enginea"      {if not work "enginec" {chassis_work 0}     }     }
	     {if not work "enginea"      {if not work "engined" {chassis_work 0}     }     }
	     {if not work "engineb"      {if not work "enginec" {chassis_work 0}     }     }
	     {if not work "engineb"      {if not work "engined" {chassis_work 0}     }     }
	     {if not work "enginec"      {if not work "engined" {chassis_work 0}     }     }

	     {if not work "ppu"      {if not work "apu" {chassis_work 0}     }     }
	     {if not work "wheel_back" {chassis_work 0}   }
	     {if not work "retract_wheelR" {chassis_work 0}    }
	     {if not work "retract_wheelL" {chassis_work 0}    }

;=============обработка поломок авионики

	     {if not work "pilot_panel" {chassis_work 0} }
	     {if not work "hydrosystem" {chassis_work 0} }
	     {if not work "apu" {chassis_work 0} }
	     {if not work "body" {chassis_work 0} {call "mp_destroy"} {call "fall"}}
	}
;=============обработка поломок авионики
	{call "check_wings"}
	{call "update_weaponry"}
}

{on "avionics_damaged"
      {if not tagged "damage_fly"
	{if chassis "airborne"
		{tags add "damage_fly"}
		{ani_stop "fly"}
		{ani_play "damage_fly" 0.2 loop}
	}
      }
}

{on "check_wings"
	{if not work "steering_elev" {if not work "steering_rudder" {call "fall"}}}
	{if not work "steering_elev" {if not work "steering_eler_r" {call "fall"}}}
	{if not work "steering_elev" {if not work "steering_eler_l" {call "fall"}}}
	{if not work "steering_rudder" {if not work "steering_eler_r" {call "fall"}}}
	{if not work "steering_rudder" {if not work "steering_eler_l" {call "fall"}}}
	{if not work "steering_eler_r" {if not work "steering_eler_l" {call "fall"}}}

	{if tagged "aileron_l_teared" 
		{if tagged "aileron_r_teared" {call "fall"}}
	}
	{if tagged "elevator_teared"  {call "fall"}}
	{if tagged "elevator_l_teared" 
		{if tagged "elevator_r_teared" {call "fall"}}
	}
	{if tagged "rudder_teared"  {call "fall"}}
	{if tagged "rudder_l_teared" 
		{if tagged "rudder_r_teared"  {call "fall"}}
	}
	{if tagged "stabilizer_teared" {call "fall"}}
	{if tagged "stabilizer_l_teared" 
		{if tagged "stabilizer_r_teared" {call "fall"}}
	}
	{if tagged "tail_teared" {call "fall"}}
	{if tagged "tail_l_teared" 
		{if tagged "tail_r_teared" {call "fall"}}
	}

	{if tagged "aileron_l_teared"  {call "avionics_damaged"}}
	{if tagged "aileron_r_teared" {call "avionics_damaged"}}
	{if broken "aileron_l" {if broken "aileron_r" {call "avionics_damaged"}}}
	{if broken "steering_eler_l" {if broken "aileron_r" {call "avionics_damaged"}}}
	{if broken "aileron_l" {if broken "steering_eler_r" {call "avionics_damaged"}}}

	{if tagged "elevator_l_teared" {call "avionics_damaged"}}
	{if tagged "elevator_r_teared" {call "avionics_damaged"}}
	{if broken "elevator_l" {if broken "elevator_r" {call "avionics_damaged"}}}
	{if broken "elevator"  {call "avionics_damaged"}}

	{if tagged "rudder_teared"  {call "avionics_damaged"}}
	{if tagged "rudder_r_teared"   {call "avionics_damaged"}}
	{if broken "rudder_l" {if broken "rudder_r" {call "avionics_damaged"}}}
	{if broken "rudder"  {call "avionics_damaged"}}

	{if tagged "stabilizer_l_teared" {call "avionics_damaged"}}
	{if tagged "stabilizer_r_teared" {call "avionics_damaged"}}
	{if broken "stabilizer_l" {if broken "stabilizer_r" {call "avionics_damaged"}}}
	{if broken "stabilizer" {call "avionics_damaged"}}
	{if tagged "tail_l_teared"  {call "avionics_damaged"}}
	{if tagged "tail_r_teared"  {call "avionics_damaged"}}
	{if broken "tail_l" {if broken "tail_r" {call "avionics_damaged"}}}
	{if broken "tail" {call "avionics_damaged"}}

	{if tagged "wingr1_teared"  {call "fall"}}
	{if tagged "wingr2_teared"   {call "fall"}}
	{if tagged "wingl1_teared"   {call "fall"}}
	{if tagged "wingl2_teared"   {call "fall"}}

	{if not work "wingr1" {if not work "wingr2" {if not work "wingl1" {call "fall"}}}}
	{if not work "wingr1" {if not work "wingr2" {if not work "wingl2" {call "fall"}}}}
	{if not work "wingr1" {if not work "wingl1" {if not work "wingl2" {call "fall"}}}}
	{if not work "wingr2" {if not work "wingl1" {if not work "wingl2" {call "fall"}}}}

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
				  {blastwave c4 (+ %e 0.2) r0 0.04 r1 0.05 position} 
				 }
			)
		min_energy %e 
		{if component "body"  {blastwave c4 %e r0 0.01 r1 0.02 position}{spawn "metal_hit_bul"}
		("check_damage_frag" component(wingr1)  p(0.05) splitter(%splitter))
		("check_damage_frag" component(wingl1)  p(0.05) splitter(%splitter))
		("check_damage_frag" component(wingr2)  p(0.05) splitter(%splitter))
		("check_damage_frag" component(wingl2)  p(0.05) splitter(%splitter))
		("check_damage_frag" component(aileron_l)  p(0.05) splitter(%splitter))
		("check_damage_frag" component(aileron_r)  p(0.05) splitter(%splitter))
		("check_damage_frag" component(elevator)  p(0.05) splitter(%splitter))
		("check_damage_frag" component(elevator_l)  p(0.05) splitter(%splitter))
		("check_damage_frag" component(elevator_r)  p(0.05) splitter(%splitter))
		("check_damage_frag" component(rudder)  p(0.05) splitter(%splitter))
		("check_damage_frag" component(rudder_l)  p(0.05) splitter(%splitter))
		("check_damage_frag" component(rudder_r)  p(0.05) splitter(%splitter))
		("check_damage_frag" component(stabilizer)  p(0.05) splitter(%splitter))
		("check_damage_frag" component(stabilizer_l)  p(0.05) splitter(%splitter))
		("check_damage_frag" component(stabilizer_r)  p(0.05) splitter(%splitter))
		("check_damage_frag" component(tail)  p(0.05) splitter(%splitter))
		("check_damage_frag" component(tail_l)  p(0.05) splitter(%splitter))
		("check_damage_frag" component(tail_r)  p(0.05) splitter(%splitter))
		("check_damage_frag" component(flap_l)  p(0.05) splitter(%splitter))
		("check_damage_frag" component(flap_r)  p(0.05) splitter(%splitter))
		
		("check_damage_frag" component(wheel_back)  p(0.2) splitter(%splitter))
		("check_damage_frag" component(retract_wheelR)  p(0.2) splitter(%splitter))
		("check_damage_frag" component(retract_wheelL)  p(0.2) splitter(%splitter))
		("check_damage_frag" component(engine)  p(1) splitter(%splitter))
		("check_damage_frag" component(engine1)  p(1) splitter(%splitter))
		("check_damage_frag" component(engine2)  p(1) splitter(%splitter))
		("check_damage_frag" component(enginea)  p(1) splitter(%splitter))
		("check_damage_frag" component(engineb)  p(1) splitter(%splitter))
		("check_damage_frag" component(enginec)  p(1) splitter(%splitter))
		("check_damage_frag" component(engined)  p(1) splitter(%splitter))
		
		("check_damage_frag" component(pilot_panel)  p(0.25) splitter(%splitter))
		("check_damage_frag" component(steering_eler_l)  p(0.2) splitter(%splitter))
		("check_damage_frag" component(steering_eler_r)  p(0.2) splitter(%splitter))
		("check_damage_frag" component(steering_elev)  p(0.2) splitter(%splitter))
		("check_damage_frag" component(steering_rudder)  p(0.2) splitter(%splitter))
		("check_damage_frag" component(hydrosystem)  p(0.2) splitter(%splitter))
		("check_damage_frag" component(hydrosystem_tank)  p(0.1) splitter(%splitter))
		("check_damage_frag" component(antifire)  p(0.1) splitter(%splitter))
		("check_damage_frag" component(PPU)  p(0.75) splitter(%splitter))
		("check_damage_frag" component(APU)  p(0.75) splitter(%splitter))
		("check_damage_frag" component(ECM)  p(0.25) splitter(%splitter))
		("check_damage_frag" component(ECM_pod)  p(0.5) splitter(%splitter))
		("check_damage_frag" component(targeting_pod)  p(0.5) splitter(%splitter))
		("check_damage_frag" component(ir_active_def)  p(0.1) splitter(%splitter))
		("check_damage_frag" component(ir_active_def_2gen)  p(0.1) splitter(%splitter))
		("check_damage_frag" component(radarX)  p(0.25) splitter(%splitter))
		("check_damage_frag" component(radarL)  p(0.25) splitter(%splitter))
		("check_damage_frag" component(OLS)  p(0.15) splitter(%splitter))
		("check_damage_frag" component(ols1)  p(0.15) splitter(%splitter))
		("check_damage_frag" component(ols2)  p(0.15) splitter(%splitter))
		("check_damage_frag" component(electronics)  p(0.2) splitter(%splitter))
		("check_damage_frag" component(laser_td)  p(0.15) splitter(%splitter))
		("check_damage_frag" component(radar_td)  p(0.15) splitter(%splitter))
		
		("check_damage_frag" component(gun)  p(0.1) splitter(%splitter))
		("check_damage_frag" component(ptur)  p(0.3) splitter(%splitter))
		("check_damage_frag" component(ptur1)  p(0.3) splitter(%splitter))
		("check_damage_frag" component(ptur2)  p(0.3) splitter(%splitter))
		("check_damage_frag" component(ptur3)  p(0.3) splitter(%splitter))
		("check_damage_frag" component(ptur4)  p(0.3) splitter(%splitter))
		("check_damage_frag" component(ptur5)  p(0.3) splitter(%splitter))
		("check_damage_frag" component(ptur6)  p(0.3) splitter(%splitter))
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
		
		("check_damage_frag" component(fuel_tank_internal_a)  p(1) splitter(%splitter))
		("check_damage_frag" component(fuel_tank_internal_b)  p(1) splitter(%splitter))
		("check_damage_frag" component(fuel_tank_internal_c)  p(1) splitter(%splitter))
		("check_damage_frag" component(fuel_tank_internal_d)  p(1) splitter(%splitter))
		("check_damage_frag" component(fuel_tank_external_a)  p(1) splitter(%splitter))
		("check_damage_frag" component(fuel_tank_external_b)  p(1) splitter(%splitter))
		("check_damage_frag" component(fuel_tank_external_c)  p(1) splitter(%splitter))
		("check_damage_frag" component(fuel_tank_external_d)  p(1) splitter(%splitter))

		("check_damage_frag" component(ammo_storage_autocannon)  p(0.25) splitter(%splitter))
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
		{if not tagged "crit_system_destroyed"
			{tags add "crit_system_destroyed"}
		else
			{components "body" break}
			{call "mp_destroy"}
		}
	)
	(define "avionics_break"
		else component "%component"
		{tags add "%component_damaged"}
		{if not tagged "destroyed" {if not tagged "no_messages" {damage_report "%component" "%msg:%msg_damaged"}} }
	)	
	(define "engine_break"
	  else component "%engine"
		{tags add "%engine_damaged"}
		{spawn "tank_die_particle"}
		{burn fx "smoke_black" fake}
		{if not tagged "destroyed"
			("stop_damage_sound")
			{play_sound "%engine_damage"}
			{if not tagged "no_messages" {damage_report "%engine" "engine1_damaged"}}
		}
		{if rand %crit_sys
			("critical_system")
		}
		{if rand %fire_chance
			{call "_burn"}
		}
		{view start "%engine_smoke"}
		{delay 20
			{view pause "%engine_smoke"}
		}
	)
	(define "fuel_tank_break"
	  else component "%fuel_tank"
		{if not tagged "destroyed"
			("stop_damage_sound")
			{play_sound "fuel_tank_damage"}
		     {if not tagged "no_messages" {damage_report "%fuel_tank" "fuel:fuel_tank_damaged"}}
		     {if rand 0.8
			{burn fx "smoke_dead_norm" fake}
			{fire radius 4 time 1 heating 3}
			{call "_burn"}
			{if rand 0.8
				{spawn "ex_air_big"}
				{fragments c4 1 r0 2 r1 6 position}
			}
		     }
		}
	)
	(define "ptur_break"
	   else component "%ptur"
		{tags add "%ptur_damaged"}
		{if not tagged "no_messages" {if not tagged "destroyed"	{damage_report "%ptur" "ptur_damaged"}}}
		{spawn "ex_air_big"}
		{if not tagged "destroyed"	{fragments c4 2 r0 3 r1 4 position}}
	)
	(define "nar_break"
	   else component "%nar"
		{tags add "%nar_damaged"}
		{if not tagged "no_messages" {if not tagged "destroyed"	{damage_report "%nar" "nar:nar_damaged"}}}
		{spawn "ex_air_big"}
		{if not tagged "destroyed"	{fragments c4 1.5 r0 2 r1 3.5 position}}
	)
;======Корпус=====
	{if component "body"
		{tags add "body_brake"}
		{call "stat_break"}
		{chassis_work 0}
		{call "mp_destroy"}
		

	("avionics_break" component(wingl1) msg(wing)) {if rand 0.5 {if not work "wingl2" {call "fall"} } }
	("avionics_break" component(wingl2) msg(wing)) 	{if rand 0.5 {if not work "wingl1" {call "fall"} } }
	("avionics_break" component(wingr1) msg(wing)) 	{if rand 0.5 {if not work "wingr2" {call "fall"} } }
	("avionics_break" component(wingr2) msg(wing)) 	{if rand 0.5 {if not work "wingr1" {call "fall"} } }
;======Авионика=====
	("avionics_break" component(aileron_l) msg(aileron)) 
	("avionics_break" component(aileron_r) msg(aileron)) 
	("avionics_break" component(elevator) msg(elevator)) 
	("avionics_break" component(elevator_l) msg(elevator)) 
	("avionics_break" component(elevator_r) msg(elevator)) 
	("avionics_break" component(rudder) msg(rudder)) 
	("avionics_break" component(rudder_l) msg(rudder)) 
	("avionics_break" component(rudder_r) msg(rudder)) 
	("avionics_break" component(stabilizer) msg(stabilizer)) 
	("avionics_break" component(stabilizer_l) msg(stabilizer)) 
	("avionics_break" component(stabilizer_r) msg(stabilizer)) 
	("avionics_break" component(tail) msg(tail)) 
	("avionics_break" component(tail_l) msg(tail)) 
	("avionics_break" component(tail_r) msg(tail)) 
	("avionics_break" component(flap_l) msg(flap)) 
	("avionics_break" component(flap_r) msg(flap)) 
;======Шасси=====
	else component "wheel_back"
		{tags add "wheel_back_damaged"}
		{if not tagged "destroyed"
			{if not tagged "no_messages" {damage_report "wheel_back" "wheel:wheels_damaged"}}
		}
	else component "retract_wheelr"
		{tags add "retract_wheelR_damaged"}
		{if not tagged "destroyed"
			{if not tagged "no_messages" {damage_report "retract_wheelr" "wheel:wheels_damaged"}}
		}
	else component "retract_wheell"
		{tags add "retract_wheelL_damaged"}
		{if not tagged "destroyed"
			{if not tagged "no_messages" {damage_report "retract_wheell" "wheel:wheels_damaged"}}
		}
;======Двигатели=====
;У однодвигательного самолета ЕСТЬ engine, НЕТ engine1, engine2, у четырехмоторного - есть ТОЛЬКО enginea, engineb, enginec, engined
;У двухдвигательного самолета НЕТ engine, ЕСТЬ engine1 (левый), engine2 (правый).
	else component "engine"
		{tags add "engine_damaged"}
		{spawn "tank_die_particle"}
		{burn fx "smoke_black" fake}
		{if not tagged "destroyed"
			{if not tagged "no_messages" {damage_report "engine" "engine_damaged"}}
		}
		("critical_system")
		{if rand 0.4
			{call "_burn"}
		}
		("engine_break" engine(engine1) fire_chance(0.4) crit_sys(1))
		("engine_break" engine(engine2) fire_chance(0.4) crit_sys(1))
		("engine_break" engine(enginea) fire_chance(0.2) crit_sys(0))
		("engine_break" engine(engineb) fire_chance(0.2) crit_sys(0))
		("engine_break" engine(enginec) fire_chance(0.2) crit_sys(0))
		("engine_break" engine(engined) fire_chance(0.2) crit_sys(0))
;======Управление=====
	else component "pilot_panel"
		{tags add "driver_panel_damaged"}
		{if not tagged "destroyed"
			{if not tagged "no_messages" {damage_report "driver_panel" "driver_panel_damaged"}}
		}
		{spawn "tank_die_particle"}
		("critical_system")
	else component "steering_eler_l"
		{tags add "steering_eler_l_damaged"}
		{if not tagged "destroyed"
			{if not tagged "no_messages" {damage_report "steering_eler_l" "steering:steering_damaged"}}
		}
		{spawn "tank_die_particle"}
	else component "steering_eler_r"
		{tags add "steering_eler_r_damaged"}
		{if not tagged "destroyed"
			{if not tagged "no_messages" {damage_report "steering_eler_r" "steering:steering_damaged"}}
		}
		{spawn "tank_die_particle"}
	else component "steering_elev"
		{tags add "steering_elev_damaged"}
		{if not tagged "destroyed"
			{if not tagged "no_messages" {damage_report "steering_elev" "steering:steering_damaged"}}
		}
		{spawn "tank_die_particle"}
	else component "steering_rudder"
		{tags add "steering_rudder_damaged"}
		{if not tagged "destroyed"
			{if not tagged "no_messages" {damage_report "steering_rudder" "steering:steering_damaged"}}
		}
		{spawn "tank_die_particle"}

;======Оборудование=====

	else component "hydrosystem" 
		{tags add "hydrosystem_damaged"}
		{if not tagged "destroyed"
			("stop_damage_sound")
			{play_sound "hydrosystem_damage"}
			{if not tagged "no_messages" {damage_report "hydrosystem" "hydrosystem_damaged"}}
		}
		{if rand 0.15
			{call "_burn"}
		}
	else component "antifire" 
		{tags add "antifire_damaged"}
		{if not tagged "destroyed"
			{if not tagged "no_messages" {damage_report "antifire" "antifire_damaged"}}
		}
	else component "hydrosystem_tank" 
		{tags add "hydrosystem_tank_damaged"}
		{if not tagged "destroyed"
			("stop_damage_sound")
			{play_sound "hydrosystem_damage"}
			{if not tagged "no_messages" {damage_report "hydrosystem_tank" "hydrosystem_tank_damaged"}}
		}
		{if rand 0.15
			{call "_burn"}
		}
	else component "ppu"
		{tags add "ppu_damaged"}
		{if not tagged "destroyed"
			{if not tagged "no_messages" {damage_report "ppu" "ppu_damaged"}}
		}
		{spawn "tank_die_particle"}
		{if rand 0.15
			{call "_burn"}
		}
	else component "apu"
		{tags add "apu_damaged"}
		{if not tagged "destroyed"
			("stop_damage_sound")
			{play_sound "apu_damage"}
			{if not tagged "no_messages" {damage_report "apu" "apu_damaged"}}
		}
		{spawn "tank_die_particle"}
		{if rand 0.15
			{call "_burn"}
		}
	else component "ir_active_def"
		{tags add "ir_active_def_damaged"}
		{if not tagged "destroyed"
			{if not tagged "no_messages" {damage_report "ir_active_def" "ir_active_def_damaged"}}
		}
		{spawn "tank_die_particle"}
	else component "ir_active_def_2gen"
		{tags add "ir_active_def_2gen_damaged"}
		{if not tagged "destroyed"
			{if not tagged "no_messages" {damage_report "ir_active_def_2gen" "ir_active_def:ir_active_def_damaged"}}
		}
		{spawn "tank_die_particle"}
	else component "ecm"
		{tags add "ecm_damaged"}
		{if not tagged "destroyed"
			("stop_damage_sound")
			{play_sound "ecm_damage"}
			{if not tagged "no_messages" {damage_report "ecm" "ecm_damaged"}}
		}
		{spawn "tank_die_particle"}
	else component "ecm_pod"
		{tags add "ecm_pod_damaged"}
		{if not tagged "destroyed"
			("stop_damage_sound")
			{play_sound "ecm_damage"}
			{if not tagged "no_messages" {damage_report "ecm_pod" "ecm:ecm_damaged"}}
		}
		{spawn "tank_die_particle"}
	else component "towed_decoy1"
		{tags add "towed_decoy1_damaged"}
		{ani_wind "towed_decoy1_deploy" begin}{tags remove "towed_decoy1_deployed"}
		{if not tagged "destroyed"
			{if not tagged "no_messages" {damage_report "towed_decoy1" "ecm:ecm_damaged"}}
		}
		{spawn "tank_die_particle" "towdecoy1"}
	else  component "towed_decoy2"
		{tags add "towed_decoy2_damaged"}
		{ani_wind "towed_decoy2_deploy" begin}{tags remove "towed_decoy2_deployed"}
		{if not tagged "destroyed"
			{if not tagged "no_messages" {damage_report "towed_decoy2" "ecm:ecm_damaged"}}
		}
		{spawn "tank_die_particle" "towdecoy2"}
	else component "targeting_pod"
		{tags add "targeting_pod_damaged"}
		{if not tagged "destroyed"
			{if not tagged "no_messages" {damage_report "targeting_pod" "targeting_pod_damaged"}}
		}
		{spawn "tank_die_particle"}
	else component "electronics"     
		{tags add "electronics_damaged"}
		{if not tagged "destroyed"
			("stop_damage_sound")
			{play_sound "electronics_damage"}
			{if not tagged "no_messages" {damage_report "electronics" "electronics_damaged"}}
		}
		{spawn "tank_die_particle"}
	else component "radarx"     
		{tags add "radarx_damaged"}
		{if not tagged "destroyed"
			("stop_damage_sound")
			{play_sound "radar_damage"}
			{if not tagged "no_messages" {damage_report "radarx" "radar:radar_damaged"}}
		}
		{spawn "tank_die_particle"}
	else component "radarl"     
		{tags add "radarl_damaged"}
		{if not tagged "destroyed"
			("stop_damage_sound")
			{play_sound "radar_damage"}
			{if not tagged "no_messages" {damage_report "radarl" "radar:radar_damaged"}}
		}
		{spawn "tank_die_particle"}
	else component "laser_td"     
		{tags add "laser_td_damaged"}
		{if not tagged "no_messages" {if not tagged "destroyed"	{damage_report "laser_td" "laser_td_damaged"}}}
		{spawn "tank_die_particle"}
	else component "radar_td"     
		{tags add "radar_td_damaged"}
		{if not tagged "no_messages" {if not tagged "destroyed"	{damage_report "radar_td" "radar_td_damaged"}}}
		{spawn "tank_die_particle"}

;=====Баки=====
	("fuel_tank_break" fuel_tank(fuel_tank_internal_a))
	("fuel_tank_break" fuel_tank(fuel_tank_internal_b))
	("fuel_tank_break" fuel_tank(fuel_tank_internal_c))
	("fuel_tank_break" fuel_tank(fuel_tank_internal_d))
	("fuel_tank_break" fuel_tank(fuel_tank_external_a))
	("fuel_tank_break" fuel_tank(fuel_tank_external_b))
	("fuel_tank_break" fuel_tank(fuel_tank_external_c))
	("fuel_tank_break" fuel_tank(fuel_tank_external_d))
;=====Вооружение=====

	else component "gun"
		{tags add "gun_damaged"}
		{if not tagged "destroyed"
			("stop_damage_sound")
			{play_sound "gun_damage"}
			{if not tagged "no_messages" {damage_report "gun" "gun_damaged"}}
		}
		{spawn "tank_die_particle"}
		

	("ptur_break" ptur(ptur))
	("ptur_break" ptur(ptur1))
	("ptur_break" ptur(ptur2))
	("ptur_break" ptur(ptur3))
	("ptur_break" ptur(ptur4))
	("ptur_break" ptur(ptur5))
	("ptur_break" ptur(ptur6))
	("nar_break" nar(nar))
	("nar_break" nar(nar1))
	("nar_break" nar(nar2))
	("nar_break" nar(nar3))
	("nar_break" nar(nar4))
	("nar_break" nar(nar5))
	("nar_break" nar(nar6))
	else component "flares1"
		{tags add "flares1_damaged"}
		{if not tagged "no_messages" {if not tagged "destroyed"	{damage_report "flares1" "flares:flares_damaged"}}}
	else component "flares2"
		{tags add "flares2_damaged"}
		{if not tagged "no_messages" {if not tagged "destroyed"	{damage_report "flares2" "flares:flares_damaged"}}}
	else component "chaff1"
		{tags add "chaff1_damaged"}
		{if not tagged "no_messages" {if not tagged "destroyed"	{damage_report "chaff1" "chaff:chaff_damaged"}}}
	else component "chaff2"
		{tags add "chaff2_damaged"}
		{if not tagged "no_messages" {if not tagged "destroyed"	{damage_report "chaff2" "chaff:chaff_damaged"}}}

	else component "ammo_storage_autocannon"
		{if not tagged "destroyed"
		{spawn "ex_air_big"}
		{fragments c4 1.2 r0 2 r1 6}
		{delay 0.2 0.5	{spawn "ex_air_big"}	{fragments c4 1.2 r0 2 r1 6 position}}
		{delay  0.6 1	{spawn "ex_air_big"}	{fragments c4 1.2 r0 2 r1 6 position}}
		{delay 1 1.2	{spawn "ex_air_big"}	{fragments c4 1.2 r0 2 r1 6 position}}
		{delay 1.3 1.5	{spawn "ex_air_big"}	{fragments c4 1.2 r0 2 r1 6 position}}
		{if rand 0.3 {clear_inventory}{tags add "cwfs_set_fuel"}}
		{if rand 0.2 {call "_explosion"}}
		}
	}
	{call "check_moveability"}
	{call "update_lights"}
}

{on repair
;=================Корпус
	{if component "wingl1"
		{tags remove "wingl1_damaged"}
		{damage_report "wingl1" "wing:wing_repaired"}
	else component "wingr1"
		{tags remove "wingr1_damaged"}
		{damage_report "wingr1" "wing:wing_repaired"}
	else component "wingl2"
		{tags remove "wingl2_damaged"}
		{damage_report "wingl2" "wing:wing_repaired"}
	else component "wingr2"
		{tags remove "wingr2_damaged"}
		{damage_report "wingr2" "wing:wing_repaired"}


	else component "aileron_l"
		{tags remove "aileron_l_damaged"}
		{damage_report "aileron_l" "aileron:aileron_repaired"}
	else component "aileron_r"
		{tags remove "aileron_r_damaged"}
		{damage_report "aileron_r" "aileron:aileron_repaired"}
	else component "elevator"
		{tags remove "elevator_damaged"}
		{damage_report "elevator" "elevator:elevator_repaired"}
	else component "elevator_l"
		{tags remove "elevator_l_damaged"}
		{damage_report "elevator_l" "elevator:elevator_repaired"}
	else component "elevator_r"
		{tags remove "elevator_r_damaged"}
		{damage_report "elevator_r" "elevator:elevator_repaired"}
	else component "rudder"
		{tags remove "rudder_damaged"}
		{damage_report "rudder" "rudder:rudder_repaired"}
	else component "rudder_l"
		{tags remove "rudder_l_damaged"}
		{damage_report "rudder_l" "rudder:rudder_repaired"}
	else component "rudder_r"
		{tags remove "rudder_r_damaged"}
		{damage_report "rudder_r" "rudder:rudder_repaired"}

	else component "stabilizer"
		{tags remove "stabilizer_damaged"}
		{damage_report "stabilizer" "airstabilizer:stabilizer_repaired"}
	else component "stabilizer_l"
		{tags remove "stabilizer_l_damaged"}
		{damage_report "stabilizer_l" "airstabilizer:stabilizer_repaired"}
	else component "stabilizer_r"
		{tags remove "stabilizer_r_damaged"}
		{damage_report "stabilizer_r" "airstabilizer:stabilizer_repaired"}
	else component "tail"
		{tags remove "tail_damaged"}
		{damage_report "tail" "tail:tail_repaired"}
	else component "tail_l"
		{tags remove "tail_l_damaged"}
		{damage_report "tail_l" "tail:tail_repaired"}
	else component "tail_r"
		{tags remove "tail_r_damaged"}
		{damage_report "tail_r" "tail:tail_repaired"}

	else component "flap_l"
		{tags remove "flap_l_damaged"}
		{damage_report "flap_l" "flap:flap_repaired"}
	else component "flap_r"
		{tags remove "flap_r_damaged"}
		{damage_report "flap_r" "flap:flap_repaired"}

;=================Шасси
	else component "wheel_back"
		{tags remove "wheel_back_damaged"}
		{damage_report "wheel_back" "wheels:wheels_repaired"}
	else component "retract_wheelR"
		{tags remove "retract_wheelR_damaged"}
		{damage_report "retract_wheelR" "wheels:wheels_repaired"}
	else component "retract_wheelL"
		{tags remove "retract_wheelL_damaged"}
		{damage_report "retract_wheelL" "wheels:wheels_repaired"}
;=================Двигатели
	else component "engine"
		{tags remove "engine_damaged"}
		{damage_report "engine" "engine_repaired"}
		{tags remove "crit_system_destroyed"}
		{components "ammo_storage_autocannon" repair}
		{components "fuel_tank_internal_a" repair}
		{components "fuel_tank_internal_b" repair}
		{components "fuel_tank_internal_c" repair}
		{components "fuel_tank_internal_d" repair}
	else  component "engine1"
		{tags remove "engine1_damaged"}
		{damage_report "engine1" "engine1_repaired"}
		{tags remove "crit_system_destroyed"}
		{components "ammo_storage_autocannon" repair}
		{components "fuel_tank_internal_a" repair}
		{components "fuel_tank_internal_b" repair}
		{components "fuel_tank_internal_c" repair}
		{components "fuel_tank_internal_d" repair}
	else  component "engine2"
		{tags remove "engine2_damaged"}
		{damage_report "engine2" "engine2_repaired"}
		{tags remove "crit_system_destroyed"}
		{components "ammo_storage_autocannon" repair}
		{components "fuel_tank_internal_a" repair}
		{components "fuel_tank_internal_b" repair}
		{components "fuel_tank_internal_c" repair}
		{components "fuel_tank_internal_d" repair}
	else  component "enginea"
		{tags remove "enginea_damaged"}
		{damage_report "enginea" "enginea_repaired"}
		{components "ammo_storage_autocannon" repair}
		{components "fuel_tank_internal_a" repair}
		{components "fuel_tank_internal_b" repair}
		{components "fuel_tank_internal_c" repair}
		{components "fuel_tank_internal_d" repair}
	else  component "engineb"
		{tags remove "engineb_damaged"}
		{damage_report "engineb" "engineb_repaired"}
		{components "ammo_storage_autocannon" repair}
		{components "fuel_tank_internal_a" repair}
		{components "fuel_tank_internal_b" repair}
		{components "fuel_tank_internal_c" repair}
		{components "fuel_tank_internal_d" repair}
	else  component "enginec"
		{tags remove "enginec_damaged"}
		{damage_report "enginec" "enginec_repaired"}
		{components "ammo_storage_autocannon" repair}
		{components "fuel_tank_internal_a" repair}
		{components "fuel_tank_internal_b" repair}
		{components "fuel_tank_internal_c" repair}
		{components "fuel_tank_internal_d" repair}
	else  component "engined"
		{tags remove "engined_damaged"}
		{damage_report "engined" "engined_repaired"}
		{components "ammo_storage_autocannon" repair}
		{components "fuel_tank_internal_a" repair}
		{components "fuel_tank_internal_b" repair}
		{components "fuel_tank_internal_c" repair}
		{components "fuel_tank_internal_d" repair}

;=================Управление
	else component "pilot_panel" 
		{tags remove "driver_panel_damaged"}
		{damage_report "driver_panel" "driver_panel_repaired"}
		{tags remove "crit_system_destroyed"}
		{components "ammo_storage_autocannon" repair}
		{components "fuel_tank_internal_a" repair}
		{components "fuel_tank_internal_b" repair}
		{components "fuel_tank_internal_c" repair}
		{components "fuel_tank_internal_d" repair}
	else component "steering_eler_l"
		{tags remove "steering_eler_l_damaged"}
		{damage_report "steering_eler_l" "steering:steering_repaired"}
	else component "steering_eler_r"
		{tags remove "steering_eler_r_damaged"}
		{damage_report "steering_eler_r" "steering:steering_repaired"}
	else component "steering_elev"
		{tags remove "steering_elev_damaged"}
		{damage_report "steering_elev" "steering:steering_repaired"}
	else component "steering_rudder"
		{tags remove "steering_rudder_damaged"}
		{damage_report "steering_rudder" "steering:steering_repaired"}

;=================Оборудование

	else component "hydrosystem" 
		{tags remove "hydrosystem_damaged"}
		{damage_report "hydrosystem" "hydrosystem_repaired"}
	else component "hydrosystem_tank" 
		{tags remove "hydrosystem_tank_damaged"}
		{damage_report "hydrosystem_tank" "hydrosystem_tank_repaired"}
	else component "antifire" 
		{tags remove "antifire_damaged"}
		{damage_report "antifire" "antifire_repaired"}
	else component "ppu" 
		{tags remove "ppu_damaged"}
		{damage_report "ppu" "ppu_repaired"}
	else component "apu" 
		{tags remove "apu_damaged"}
		{damage_report "apu" "apu_repaired"}
	else component "ir_active_def" 
		{tags remove "ir_active_def_damaged"}
		{damage_report "ir_active_def" "ir_active_def_repaired"}
	else component "ir_active_def_2gen" 
		{tags remove "ir_active_def_2gen_damaged"}
		{damage_report "ir_active_def_2gen" "ir_active_def:ir_active_def_repaired"}
	else component "ecm" 
		{tags remove "ecm_damaged"}
		{damage_report "ecm" "ecm_repaired"}
	else component "ecm_pod" 
		{tags remove "ecm_pod_damaged"}
		{damage_report "ecm_pod" "ecm:ecm_repaired"}
	else component "towed_decoy1" 
		{tags remove "towed_decoy1_damaged"}
		{damage_report "towed_decoy1" "ecm:ecm_repaired"}
	else component "towed_decoy2" 
		{tags remove "towed_decoy2_damaged"}
		{damage_report "towed_decoy2" "ecm:ecm_repaired"}
	else component "targeting_pod" 
		{tags remove "targeting_pod_damaged"}
		{damage_report "targeting_pod" "targeting_pod_repaired"}
	else component "electronics" 
		{tags remove "electronics_damaged"}
		{damage_report "electronics" "electronics_repaired"}
	else component "radarx" 
		{tags remove "radarx_damaged"}
		{damage_report "radarx" "radar:radar_repaired"}
	else component "radarl" 
		{tags remove "radarl_damaged"}
		{damage_report "radarl" "radar:radar_repaired"}
	else component "laser_td" 
		{tags remove "laser_td_damaged"}
		{damage_report "laser_td" "laser_td_repaired"}
	else component "radar_td" 
		{tags remove "radar_td_damaged"}
		{damage_report "radar_td" "radar_td_repaired"}

;=================Вооружение

	else component "gun" 
		{tags remove "gun_damaged"}
		{damage_report "gun" "gun_repaired"}

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
	else component "ptur5" 
		{tags remove "ptur5_damaged"}
		{damage_report "ptur5" "ptur:ptur_repaired"}
	else component "ptur6" 
		{tags remove "ptur6_damaged"}
		{damage_report "ptur6" "ptur:ptur_repaired"}

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
	}
	{call "update_lights"}
	{call "check_moveability"}
}

;===============
;Anti-fire system 1.1 by Timosh
(define "burn_engine" 
	{if not tagged "burned"
		{if not able "exploded"
			{if not tagged "no_messages" {damage_report "engine" "burn_engine"}}
			{if rand %engine 
				{add_view "smoke_dead_norm" "burn_fire" "engine_exhaust"}
				{add_view "smoke_dead_norm" "burn_fire" "engine1_exhaust"} 
				{add_view "smoke_dead_norm" "burn_fire" "engine2_exhaust"}
			}
			{if rand %engine1 {add_view "smoke_dead_norm" "burn_fire" "engine1_exhaust"}}
			{if rand %engine2 {add_view "smoke_dead_norm" "burn_fire" "engine2_exhaust"}}
			{view start "burn_fire"}
			{components "fire_indicator" break}
			{if rand %engine 
				{add_view "smoke_black" "burn_fire" "engine_exhaust"}
				{add_view "smoke_black" "burn_fire" "engine1_exhaust"}
				{add_view "smoke_black" "burn_fire" "engine2_exhaust"}
			}
			{if rand %engine1 {add_view "smoke_black" "burn_fire" "engine1_exhaust"}}
			{if rand %engine2 {add_view "smoke_black" "burn_fire" "engine2_exhaust"}}
			{play_sound "flame" 1}
			{view start "burn_fire"}
			{set "burn_fire" 1}
			{if rand %engine {components "engine" break}}
			{if rand %engine1 {components "engine1" break}}
			{if rand %engine2 {components "engine2" break}}
			{if rand %enginea {components "enginea" break}}
			{if rand %engineb {components "engineb" break}}
			{if rand %enginec {components "enginec" break}}
			{if rand %engined {components "engined" break}}
			{icon_event "burning" 10.0}
			{if work "antifire" ;если работает пожаротушение
			      {if rand 0.1  ;вероятность сгорания
					{call "antifire_not_work"}
					{delay 10
						{if rand %engine {components "engine" break}}
						{components "fire_indicator" repair}
					}
			      else
					{call "antifire_work"}
			      }
			  else ;если не работает пожаротушение
			    {call "antifire_not_work"}
				{delay 10
					{if rand %engine {components "engine" break}}
					{components "fire_indicator" repair}
				}
			}
		}
	}
)
	{on "antifire_work"
		{delay 12
			{if not tagged "no_messages" {damage_report "engine" "antifire"}}
			{view stop "burn_fire"}
			{stop_sound "flame"}
			{set "burn_fire" 0}
			{set "burning" 0}
			{components "antifire" break}
			{components "fire_indicator" repair}
		}	
	}
	{on "antifire_not_work"
	 			{explosive 1}
				{tags add "burned"}
				{burn time 12}
				{delay 10
					{start_sound "crush/medium/metal"}
					{call "check_moveability"}
              	      			{delay 5 4
						{if rand 0.5 {call "mp_destroy"}}
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
					{call "mp_destroy"}
					{if rand 0.3
						{call "_explosion"}
					else
						{able "burning" 0}
					}
				}	
	}
	{on "_burn" overload
		{if not tagged "no_messages" {damage_report "engine" "burn_fire"}}
		{log "burn_volume"}
		{if not burned
			{if rand 0.5
				{log "burn_engine"}				
				("burn_engine" engine(0) engine1(1) engine2(0) enginea(0) engineb(0) enginec(0) engined(0))
			else 
				{log "burn_engine"}				
				("burn_engine" engine(0) engine1(0) engine2(1) enginea(0) engineb(0) enginec(0) engined(0))
			}
		}
	}

	{on "burn_volume" overload
		{log "burn_volume"}
		{if not burned
			{if volume "engine"
				{log "burn_engine"}				
				("burn_engine" engine(1) engine1(0) engine2(0) enginea(0) engineb(0) enginec(0) engined(0))
			else volume "engine1"
				{log "burn_engine"}				
				("burn_engine" engine(0) engine1(1) engine2(0) enginea(0) engineb(0) enginec(0) engined(0))
			else volume "engine2"
				{log "burn_engine"}				
				("burn_engine" engine(0) engine1(0) engine2(1) enginea(0) engineb(0) enginec(0) engined(0))
			else volume "enginea"
				{log "burn_engine"}				
				("burn_engine" engine(0) engine1(0) engine2(0) enginea(1) engineb(0) enginec(0) engined(0))
			else volume "engineb"
				{log "burn_engine"}				
				("burn_engine" engine(0) engine1(0) engine2(0) enginea(0) engineb(1) enginec(0) engined(0))
			else volume "enginec"
				{log "burn_engine"}				
				("burn_engine" engine(0) engine1(0) engine2(0) enginea(0) engineb(0) enginec(1) engined(0))
			else volume "engined"
				{log "burn_engine"}				
				("burn_engine" engine(0) engine1(0) engine2(0) enginea(0) engineb(0) enginec(0) engined(1))
			}
		}
	}

;End of anti-fire system
;===============
	{on "mp_destroy"
		{ani_stop "fly"}
		{ani_stop "damage_fly"}
		{view start "fire_body"}
		{call "stat_break"}
		{delay 60 20 {view stop "fire_body"}}
		{call "engine_stop"}
		{drop_orders}
		{reset_manual_control}
		{able select 0}
		{able repaired 0}
		{unlink_trailer}
		{view pause "engine_overburn"}
		{view pause "engine1_overburn"}
		{view pause "engine2_overburn"}

		{if not tagged "destroyed"
			{if not tagged "no_messages" {damage_report "body" "body_broken"}}
			{if not tagged "body_break"
				{components "body" break}
				{components "wingl1" break}
				{components "wingl2" break}
				{components "wingr1" break}
				{components "wingr2" break}
				{call "stat_break"}
			}
		}
		
		{delay 2
			{crew_emit}
			{ani_stop "fly"}
			{ani_stop "damage_fly"}
			{tags add "destroyed"}
			{kick_entity_manager}
		}
		{call "burn_emit"}
	}

	{on "delayed_fall_long"
		{set "delayed_fall_long" 1}
		{delay 35
			{if flag "delayed_fall_long"
				{call "fall"}
			}
		}
	}

	{on "fall" overload
		{call "eject_all"}
		{ani_stop "fly"}
		{ani_stop "damage_fly"}
		{if not flag "fall"
			{set "fall" 1}
			{if altitude 5
			{impulse up 0.1 rnd_dir 1 2}
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
		}
		{delay 10
			{set "fall" 0}
		}
	}

	{on ground_hit overload
		{spawn "spheredust_big_short"}
		{call "collide"}
		{if velocity 40
			{call "explosion"}
		}
		{constrain_velocity 40}
	}
	{on contact overload
		{if effector "small_UAV"
			{if volume "part"
				{component destroy}
				{call "tear_part"}
			else component "body"
			else {component break}
			}
		else effector "vehicle"
		   {if not effector  "proj_dummy" {call "collide"}}
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

;===============Столкновения

	{on "collide" overload
		{view pause "flare_right"}
		{view pause "flare_left"}
		{view pause "chaff_right"}
		{view pause "chaff_left"}
		{if volume "body"
			{call "mp_destroy"}
		else volume "wheelright"
			{call "tear_wheelright"}
		else volume "wheelleft"
			{call "tear_wheelleft"}
		else volume "wheelfront"
			{call "tear_wheelfront"}
		else volume "wingl1"
			{call "tear_wingl1"}
		else volume "wingl2"
			{call "tear_wingl2"}
		else volume "wingr1"
			{call "tear_wingr1"}
		else volume "wingr2"
			{call "tear_wingr2"}
		else volume "part"
			{call "tear_part"}
		}

		{delay 0.1 {call "check_moveability"}}
	}
	(define "tear_wheel"
		{spawn "spheredust_big_short"}
		{component destroy}
		{volume disable contact contact_ground}
		{if velocity 30
			{tear "piece_big_airborne_wing" bone from_volume {impulse up 0 1 forward 10 2} }
		else
			{tear "piece_big_airborne_wing" bone from_volume {impulse up 2 1 dir 2 1} }
		}
	)
	{on "tear_wheelright" overload
		("tear_wheel")
	}
	{on "tear_wheelleft" overload
		("tear_wheel")
	}
	{on "tear_wheelfront" overload
		("tear_wheel")
	}
	(define "tear_wing"
		{tags add "%wing_teared"}
		{spawn "spheredust_big_short"}
		{components "%wing" destroy}
		{volume disable contact contact_ground}
		{view start "%fire_fueltank"}
		{if velocity 30
			{tear "piece_big_airborne_wing" bone "%wing"
				{impulse up 0 1 forward 10 2}
				{add_view "aero_die_fire"		"fire_%wing"		"fxfire_%wing_1"}
				{add_view "aero_die_fire"		"fire_%wing"		"fxfire_%wing_2"}
				{view start "fire_%wing"}
				{delay 60 20 {view stop "fire_%wing"}}
			}
		else
			{tear "piece_big_airborne_wing" bone "%wing"
				{impulse up 2 1 dir 2 1}
				{add_view "aero_die_fire"		"fire_%wing"		"fxfire_%wing_1"}
				{add_view "aero_die_fire"		"fire_%wing"		"fxfire_%wing_2"}
				{view start "fire_%wing"}
				{delay 60 20 {view stop "fire_%wing"}}
			}
		}
		{delay 60 20 {view stop "%fire_fueltank"}}
	)
	{on "tear_wingl1" overload
		("tear_wing" wing(wingl1) fire_fueltank(fire_body_l))
	}
	{on "tear_wingr1" overload
		("tear_wing" wing(wingr1) fire_fueltank(fire_body_r))
	}
	{on "tear_wingl2" overload
		("tear_wing" wing(wingl2) fire_fueltank(fire_wingl1_2))
	}
	{on "tear_wingr2" overload
		("tear_wing" wing(wingr2) fire_fueltank(fire_wingr1_2))
	}
	{on "tear_part" overload
		{if component "aileron_l" {tags add "aileron_l_teared"}
		else component "aileron_r" {tags add "aileron_r_teared"}
		else component "elevator" {tags add "elevator_teared"}
		else component "elevator_r" {tags add "elevator_r_teared"}
		else component "elevator_l" {tags add "elevator_l_teared"}
		else component "rudder" {tags add "rudder_teared"}
		else component "rudder_l" {tags add "rudder_l_teared"}
		else component "rudder_r" {tags add "rudder_r_teared"}
		else component "stabilizer" {tags add "stabilizer_teared"}
		else component "stabilizer_l" {tags add "stabilizer_l_teared"}
		else component "stabilizer_r" {tags add "stabilizer_r_teared"}
		else component "tail" {tags add "tail_teared"}
		else component "tail_l" {tags add "tail_l_teared"}
		else component "tail_r" {tags add "tail_r_teared"}
		}
		{if not component "body"
			{spawn "spheredust_big_short"}
			{component destroy}
			{volume disable contact contact_ground}
			{if velocity 30
				{tear "piece_big_airborne_wing" bone from_volume {impulse up 0 1 forward 10 2} }
			else
				{tear "piece_big_airborne_wing" bone from_volume {impulse up 2 1 dir 2 1} }
			}
		}
	}

	{on "explosion" overload
		{if not able "exploded"
			{able "exploded" 1}
			{link_sound "ground_crash"		"vehicle/airborne/crash/crash"}
			{play_sound "ground_crash"}
			{call "_explosion"}
		}
	}
	{on "_explosion_effects"
		{add_view "aero_die" "fire" "body"}
		{add_view "aero_die_fire" "fire" "body"}
		{view start "fire"}
		{spawn "aero_die_particle"}
		{blastwave c4 7 r0 5 r1 8}
		{fire radius 10 time 5 heating 7}
	}
	{on "_explosion" overload
		{call "mp_destroy"}
		{view pause "flare_right"}
		{view pause "flare_left"}
		{view pause "chaff_right"}
		{view pause "chaff_left"}
		{components "wingl1" destroy}
		{components "wingl2" destroy}
		{components "wingr1" destroy}
		{components "wingr2" destroy}
		{components "body" destroy}
		{kill_crew}
		{able select 0}
		{clear_inventory}
;		{remove_grass 4}
		{call "die"}
		{call "_explosion_effects"}
		{tags add "destroyed"}
		{tags remove "air"}

		{impulse up 0.1 com}
		{delay 0.1
			(define "cut_part"
				{if rand %1
					{tear "piece_big_airborne_wing" bone %0
						{impulse up 2 1 dir 2 1}
					}
				}
			)
			{delay_ex 0
				{set "no_burn_volumes" 1}
				{set_skeleton "_xx" sync}
				{ani_play "death"}

				("cut_part" args "part1"		0.5)
				("cut_part" args "part2"		0.5)
				("cut_part" args "part3"		0.5)
				("cut_part" args "part4"		0.5)
				("cut_part" args "part5"		0.5)
				("cut_part" args "part6"		0.5)
				("cut_part" args "part7"		0.5)
				("cut_part" args "part8"		0.5)
				("cut_part" args "part9"		0.5)
				("cut_part" args "part10"		0.5)
				("cut_part" args "part11"		0.5)
				("cut_part" args "part12"		0.5)
				("cut_part" args "part13"		0.5)
				("cut_part" args "part14"		0.5)
				("cut_part" args "part15"		0.5)
				("cut_part" args "part16"		0.5)
				("cut_part" args "part17"		0.5)
				("cut_part" args "part18"		0.5)
				("cut_part" args "part19"		0.5)
				("cut_part" args "part20"		0.5)
				{bone cut "glass"}
				{bone cut "glass1"}

				{if rand 0.2 {call "tear_wingr1"}}
				{if rand 0.2 {call "tear_wingr2"}}
				{if rand 0.2 {call "tear_wingl1"}}
				{if rand 0.2 {call "tear_wingl2"}}
				("cut_part" args "body_back"	0.5)

				{volumes disable obstacle}
				{volumes "body" enable obstacle}
				{volumes "body_back" disable obstacle}
				{volumes "balancer" disable all}
				{area rebuild}
				{delay 5
					{view pause "flare_right"}
					{view pause "flare_left"}
					{view pause "chaff_right"}
					{view pause "chaff_left"}
				}
			}
		}
	}

	{on "air_attack" overload
		{start_sound "vehicle/airborne/low_pass" ambient}
		{tags add "air_attacking"}
		{delay 5 {tags remove "air_attacking"}}
	}

	
;=================Ловушки!!!!!!!!!!!!!!!!!

	{on fire "flare_dropper" overload
		{call "drop_flares"}
	}

;=================Катапультирование

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

	}
	(define "eject_end"
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
	)
	{on animation_end "eject"
	 {view pause "fx_eject"}
	 {tear "piece_big_airborne_wing" bone "catapult"	{impulse up 2 1 forward -1 1}}
		("eject_end" crewman(driver))
	}
	{on animation_end "eject1"
	 {view pause "fx_eject1"}
	 {tear "piece_big_airborne_wing" bone "catapult1"	{impulse up 2 1 forward -1 1}}
		("eject_end" crewman(driver1))
		("eject_end" crewman(gunner))
	}

	{on fire "gun"
		{view start "flashbarrel1"}
		{kill_delay "shell_off"}
		{ani_play "gun"}
		{kill_delay "gun_stop"}
		{delay 0.2 "gun_stop"	{ani_stop "gun"}}
		{delay 0.42	"shell_off" {view pause "flashbarrel1"}}
	}
	{on "crew_emit"
		{crew_emit}
	}
	{on "specability"
		{if not flag "specability"
			{set "specability" 1}
			{damage_report "body" "guided_weap_disabled"}
			{call "update_weaponry"}
		else 
			{set "specability" 0}
			{damage_report "body" "guided_weap_enabled"}
			{call "update_weaponry"}
		}
	}
	
	{on "cwsh_switch_hatch" overload
		{if chassis "airborne"
			{tags add "need_auto_landing"}	{delay 5 {tags remove "need_auto_landing"}}
		}
	}

	{on "diagnostics"
		{if component "wingl1"
			{damage_report "wingl1" "wing:wing_damaged"}
		else not work "wingl2"
			{damage_report "wingl2" "wing:wing_damaged"}
		else not work "wingr1"
			{damage_report "wingr1" "wing:wing_damaged"}
		else not work "wingr2"
			{damage_report "wingr2" "wing:wing_damaged"}
		}
		{if not work "aileron_l"
			{damage_report "aileron_l" "aileron:aileron_damaged"}
		else not work "aileron_r"
			{damage_report "aileron_r" "aileron:aileron_damaged"}
		}
		{if not work "elevator"
			{damage_report "elevator" "elevator:elevator_damaged"}
		else not work "elevator_l"
			{damage_report "elevator_l" "elevator:elevator_damaged"}
		else not work "elevator_r"
			{damage_report "elevator_r" "elevator:elevator_damaged"}
		}
		{if not work "rudder"
			{damage_report "rudder" "rudder:rudder_damaged"}
		else not work "rudder_l"
			{damage_report "rudder_l" "rudder:rudder_damaged"}
		else not work "rudder_r"
			{damage_report "rudder_r" "rudder:rudder_damaged"}
		}
		{if not work "stabilizer"
			{damage_report "stabilizer" "airstabilizer:stabilizer_damaged"}
		else not work "stabilizer_l"
			{damage_report "stabilizer_l" "airstabilizer:stabilizer_damaged"}
		else not work "stabilizer_r"
			{damage_report "stabilizer_r" "airstabilizer:stabilizer_damaged"}
		}
		{if not work "tail"
			{damage_report "tail" "tail:tail_damaged"}
		else not work "tail_l"
			{damage_report "tail_l" "tail:tail_damaged"}
		else not work "tail_r"
			{damage_report "tail_r" "tail:tail_damaged"}
		}
		{if not work "flap_l"
			{damage_report "flap_l" "flap:flap_damaged"}
		else not work "flap_r"
			{damage_report "flap_r" "flap:flap_damaged"}
		}
		{if not work "wheel_back"
			{damage_report "wheel_back" "wheel:wheels_damaged"}
		else not work "retract_wheelR_damaged"
			{damage_report "retract_wheelr" "wheel:wheels_damaged"}
		else not work "retract_wheelL"
			{damage_report "retract_wheell" "wheel:wheels_damaged"}
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
		{if not work "enginea"
			{damage_report "enginea" "enginea_damaged"}
		}
		{if not work "engineb"
			{damage_report "engineb" "engineb_damaged"}
		}
		{if not work "enginec"
			{damage_report "enginec" "enginec_damaged"}
		}
		{if not work "engined"
			{damage_report "engined" "engined_damaged"}
		}
		{if not work "pilot_panel"
			{damage_report "driver_panel" "driver_panel_damaged"}
		}
		{if not work "steering_eler_l"
			{damage_report "steering_eler_l" "steering:steering_damaged"}
		else not work "steering_eler_r"
			{damage_report "steering_eler_r" "steering:steering_damaged"}
		else not work "steering_elev"
			{damage_report "steering_elev" "steering:steering_damaged"}
		else not work "steering_rudder"
			{damage_report "steering_rudder" "steering:steering_damaged"}
		}
		{if not work "hydrosystem" 
			{damage_report "hydrosystem" "hydrosystem_damaged"}
		}
		{if not work "antifire" 
			{damage_report "antifire" "antifire_damaged"}
		}
		{if not work "hydrosystem_tank" 
			{damage_report "hydrosystem_tank" "hydrosystem_tank_damaged"}
		}
		{if not work "ppu"
			{damage_report "ppu" "ppu_damaged"}
		}
		{if not work "apu"
			{damage_report "apu" "apu_damaged"}
		}
		{if not work "ir_active_def"
			{damage_report "ir_active_def" "ir_active_def_damaged"}
		else not work "ir_active_def_2gen"
			{damage_report "ir_active_def_2gen" "ir_active_def:ir_active_def_damaged"}
		}
		{if not work "ecm"
			{damage_report "ecm" "ecm_damaged"}
		else not work "ecm_pod"
			{damage_report "ecm_pod" "ecm:ecm_damaged"}
		else not work "towed_decoy1"
			{damage_report "ecm_pod" "ecm:ecm_damaged"}
		else not work "towed_decoy2"
			{damage_report "ecm_pod" "ecm:ecm_damaged"}
		else not work "towed_decoy1"
			{damage_report "towed_decoy1" "ecm:ecm_damaged"}
		else  component "towed_decoy2"
			{damage_report "towed_decoy2" "ecm:ecm_damaged"}
		}
		{if not work "targeting_pod"
			{damage_report "targeting_pod" "targeting_pod_damaged"}
		}
		{if not work "electronics"     
			{damage_report "electronics" "electronics_damaged"}
		}
		{if not work "radarx"     
			{damage_report "radarx" "radar_damaged"}
		else not work "radarl"     
			{damage_report "radarl" "radar_damaged"}
		}
		{if not work "laser_td"     
			{damage_report "laser_td" "laser_td_damaged"}
		}
		{if not work "radar_td"     
			{damage_report "radar_td" "radar_td_damaged"}
		}
		{if not work "gun"
			{damage_report "gun" "gun_damaged"}
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
		else not work "ptur5"
			{damage_report "ptur5" "ptur:ptur_damaged"}
		else not work "ptur6"
			{damage_report "ptur6" "ptur:ptur_damaged"}
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
	}

}
;=========end of Aicraft_M definition

{"fighter"
	{on "check_wings" overload
		{if not work "steering_elev" {if not work "steering_rudder" {call "fall"}}}
		{if not work "steering_elev" {if not work "steering_eler_r" {call "fall"}}}
		{if not work "steering_elev" {if not work "steering_eler_l" {call "fall"}}}
		{if not work "steering_rudder" {if not work "steering_eler_r" {call "fall"}}}
		{if not work "steering_rudder" {if not work "steering_eler_l" {call "fall"}}}
		{if not work "steering_eler_r" {if not work "steering_eler_l" {call "fall"}}}

		{if tagged "aileron_l_teared" 
			{if tagged "aileron_r_teared" {call "fall"}}
		}
		{if tagged "elevator_teared"  {call "fall"}}
		{if tagged "elevator_l_teared" 
			{if tagged "elevator_r_teared" {call "fall"}}
		}
		{if tagged "rudder_teared"  {call "fall"}}
		{if tagged "rudder_l_teared" 
			{if tagged "rudder_r_teared"  {call "fall"}}
		}
		{if tagged "stabilizer_teared" {call "fall"}}
		{if tagged "tail_teared" {call "fall"}}


		{if tagged "aileron_l_teared"  {call "avionics_damaged"}}
		{if tagged "aileron_r_teared" {call "avionics_damaged"}}
		{if broken "aileron_l" {if broken "aileron_r" {call "fall"}}}
		{if broken "steering_eler_l" {if broken "aileron_r" {call "avionics_damaged"}}}
		{if broken "aileron_l" {if broken "steering_eler_r" {call "avionics_damaged"}}}
		{if broken "aileron_l" {call "avionics_damaged"}}
		{if broken "aileron_r" {call "avionics_damaged"}}

		{if tagged "elevator_l_teared" {call "avionics_damaged"}}
		{if tagged "elevator_r_teared" {call "avionics_damaged"}}
		{if broken "elevator_l" {if broken "elevator_r" {call "fall"}}}
		{if broken "elevator"  {call "avionics_damaged"}}
		{if broken "elevator_l" {call "avionics_damaged"}}
		{if broken "elevator_r" {call "avionics_damaged"}}

		{if tagged "rudder_teared"  {call "avionics_damaged"}}
		{if tagged "rudder_r_teared"   {call "avionics_damaged"}}
		{if broken "rudder_l" {if broken "rudder_r" {call "fall"}}}
		{if broken "rudder"  {call "avionics_damaged"}}
		{if broken "rudder_l" {call "avionics_damaged"}}
		{if broken "rudder_r" {call "avionics_damaged"}}

		{if tagged "stabilizer_l_teared" {call "fall"}}
		{if tagged "stabilizer_r_teared" {call "fall"}}
		{if broken "stabilizer_l" {if broken "stabilizer_r" {call "fall"}}}
		{if broken "stabilizer_l" {call "avionics_damaged"}}
		{if broken "stabilizer_r" {call "avionics_damaged"}}
		{if broken "stabilizer" {call "avionics_damaged"}}

		{if tagged "tail_l_teared"  {call "fall"}}
		{if tagged "tail_r_teared"  {call "fall"}}
		{if broken "tail_l" {if broken "tail_r" {call "fall"}}}

		{if broken "tail_l" {call "avionics_damaged"}}
		{if broken "tail_r" {call "avionics_damaged"}}
		{if broken "tail" {call "avionics_damaged"}}

		{if tagged "wingr1_teared"  {call "fall"}}
		{if tagged "wingr2_teared"   {call "fall"}}
		{if tagged "wingl1_teared"   {call "fall"}}
		{if tagged "wingl2_teared"   {call "fall"}}

		{if not work "wingr1" {if not work "wingr2" {call "fall"}}}
		{if not work "wingl1" {if not work "wingl2" {call "fall"}}}
	}
	{on "delayed_fall_long"
		{set "delayed_fall_long" 1}
		{delay 20
			{if flag "delayed_fall_long"
				{call "fall"}
			}
		}
	}

}

{"destroyed_bomb"
	{on ground_hit
		{stuff_detonate}
	}
	{on contact
		{stuff_detonate}
	}
}

{"dispencer"
   (define "spread_pbk"
	{delay %delay (* 0.5 %delay) {spawn "spbe-d" offset %x %y 0}}
	)
	{on spawn
		{volumes "body" disable contact}
		{delay 1 {call "loop_detect"} {volumes "body" enable contact}}
	}
	{on "loop_detect"
		{if not altitude 15 {call "dispence"}
		else {delay 0.2 {call "loop_detect"}}}
	}
	{on "dispence"
		{volumes disable all}
		{spawn "spbe-d"}
		("spread_pbk" delay(0.3) x(0) y(0))
		("spread_pbk" delay(0.3) x(250) y(0))
		("spread_pbk" delay(0.3) x(-250) y(0))
		("spread_pbk" delay(0.3) x(0) y(250))
		("spread_pbk" delay(0.3) x(0) y(-250))
		("spread_pbk" delay(0.3) x(250) y(250))
		("spread_pbk" delay(0.3) x(250) y(-250))
		("spread_pbk" delay(0.3) x(-250) y(-250))
		("spread_pbk" delay(0.3) x(-250) y(250))
		("spread_pbk" delay(0.3) x(450) y(0))
		("spread_pbk" delay(0.3) x(-450) y(0))
		("spread_pbk" delay(0.3) x(0) y(450))
		("spread_pbk" delay(0.3) x(0) y(-450))
		("spread_pbk" delay(0.3) x(450) y(-600))
		("spread_pbk" delay(0.3) x(-450) y(600))
		;{delay 0.03 {spawn "spbe-d"}}
		;{delay 0.06 {spawn "spbe-d"}}
		;{delay 0.09 {spawn "spbe-d"}}
		;{delay 0.12 {spawn "spbe-d"}}
		;{delay 0.15 {spawn "spbe-d"}}
		;{delay 0.18 {spawn "spbe-d"}}
		;{delay 0.21 {spawn "spbe-d"}}
		;{delay 0.24 {spawn "spbe-d"}}
		;{delay 0.27 {spawn "spbe-d"}}
		;{delay 0.30 {spawn "spbe-d"}}
		;{delay 0.33 {spawn "spbe-d"}}
		;{delay 0.36 {spawn "spbe-d"}}
		;{delay 0.39 {spawn "spbe-d"}}
		{delay 1.0
			{spawn "aero_die_particle"}
			{delete}
		}
	}
	{on ground_hit
		{spawn "aero_die_particle"}
		{delete}
	}
	{on contact
		{spawn "aero_die_particle"}
		{delete}
	}
}

{"cbu-97_impactor"
	{on "dispence" overload
		{volumes disable all}
		{spawn "blu108b" "root" x}
		{spawn "blu108b" "root" x}
		{spawn "blu108b" "root" x}
		{spawn "blu108b" "root" x}
		{spawn "blu108b" "root" x}
		{delay 0.2 
			{spawn "blu108b" "root" x}
			{spawn "blu108b" "root" x}
			{spawn "blu108b" "root" x}
			{spawn "blu108b" "root" x}
			{spawn "blu108b" "root" x}
		}
		{delay 0.3
			{spawn "aero_die_particle"}
			{delete}
		}
	}
}

{"RBK_250_impactor"
	{on "dispence" overload
		{volumes "body" disable contact bullet blast}
;		{spawn "rbk250_cluster"}
		{delay 0.4
;			{spawn "rbk250_cluster"}	;for ao-1 variant
			{spawn "ex_rbk250zab"}
			{spawn "aero_die_particle"}
			{delete}
		}
	}
}
{"zab_submunition"
	{on spawn
		;{gravity 0.8}

		{delay 0.2
			{add_view "fire_flame_thrower_fly4" "fire2" "root"}
			{view start "fire2"}
		}
		{delay 0.3
			{add_view "fire_flame_thrower_fly5" "fire" "root"}
			{add_view "fire_napalm" "fire" "root"}
			{view start "fire"}
		}
		{delay 0.05
			{volumes "body" enable contact}
			{fire radius 0.7 time 3 heating 0.1 follow}
		}
		{delay 50 4 {hide 5}}
	}
	{on contact
		{view stop "fire1"}
		{view stop "fire2"}
		{call "end"}
	}
	{on ground_hit
		{view stop "fire1"}
		{view stop "fire2"}
		{delay 0.1
		  {if terrain_fx "water"
		  else terrain_fx "shallow_water"
		  else terrain_fx "deep_water"
		  else
			{call "end"}
		  }
		}
	}
}
{"zab_2_5_var1"
	{on "end"
	  {if not under_water
	   {if not rain
		{fire radius 2 time 45 heating 0.8 follow}
		{fire radius 0.5 time 45 heating 1.5 follow}
	   else
	    {fire radius 1 time 45 heating 0.2 follow}
		{fire radius 0.5 time 45 heating 0.3 follow}
	   }
	  }
	}
}
{"zab_2_5_var2"
	{on spawn
		{delay 32 8 {stuff_detonate}}
	}
	{on "end"
	  {if not under_water
	   {if not rain
		{fire radius 2 time 45 heating 0.7 follow}
		{fire radius 0.5 time 45 heating 1.4 follow}
	   else
	    {fire radius 1 time 45 heating 0.2 follow}
		{fire radius 0.5 time 45 heating 0.3 follow}
	   }
	  }
	}
}
{"zab_2_5_var3"
	{on spawn
		{delay 17 5 
			{fire radius 3.5 time 1 heating 1.5 follow}
			{fire radius 1.5 time 1 heating 3 follow}
			{spawn "zab_2_5_var4" {impulse up 3 0.5 rnd_dir 6}}
			{if rand 0.5 {spawn "zab_2_5_var4" {impulse up 3 1 rnd_dir 6}}}
			{if rand 0.5 {spawn "zab_2_5_var4" {impulse up 3 1 rnd_dir 6}}}
			{if rand 0.5 {spawn "zab_2_5_var4" {impulse up 3 1 rnd_dir 6}}}
			{if rand 0.5 {spawn "zab_2_5_var4" {impulse up 3 1 rnd_dir 6}}}
		
		{stuff_detonate}}
	}
	{on "end"
	  {if not under_water
	   {if not rain
		{fire radius 2 time 25 heating 0.5 follow}
		{fire radius 0.5 time 25 heating 1.1 follow}
	   else
	    {fire radius 1 time 25 heating 0.2 follow}
		{fire radius 0.5 time 25 heating 0.3 follow}
	   }
	  }
	}
}
{"zab_2_5_var4"
	{on "end"
	  {if not under_water
	   {if not rain
		{fire radius 2 time 55 heating 0.3 follow}
		{fire radius 0.5 time 55 heating 0.5 follow}
		{delay 45 7 {delete}}
	   else
	    {fire radius 1 time 15 heating 0.1 follow}
		{fire radius 0.5 time 15 heating 0.2 follow}
		{delay 10 3 {delete}}
	   }
	  }
	}
}
{"blu108b"
	{on spawn
		{impulse up 0.01 0.5 forward 5 rnd_dir 5 com}
		{delay 0.2 0.2
			{ani_play "on_start" 1 callback}
			{delay 0.7
				{impulse up 4 com}
				{tear "piece_small_steel" bone "part1"
					{impulse up 2 1 dir 2 1} {delay 20 {hide 5}}
				}
				{add_view	"rok_tail"	"engine_fx"		"engine_fx1"	}
				{add_view	"rok_tail"	"engine_fx" 		"engine_fx2"	}
				{view start "engine_fx"}
				{delay 0.32
					{view pause "engine_fx"}
				}
			}
		}
		{delay 20 {hide 5}}
	}
	{on animation_end "on_start"
		{bone cut "skeet1"}{bone cut "skeet2"}{bone cut "skeet3"}{bone cut "skeet4"}
		{spawn "blu108b_skeet" "drop1" x {impulse up 0.1 forward 10 com}}
		{spawn "blu108b_skeet" "drop2" x {impulse up 0.1 forward 10 com}}
		{spawn "blu108b_skeet" "drop3" x {impulse up 0.1 forward 10 com}}
		{spawn "blu108b_skeet" "drop4" x {impulse up 0.1 forward 10 com}}
		{impulse up 0.1 dir 0.5 0.5}
		{tags add "empty_blu108"}
	}
	{on ground_hit
		{call "self_destruct"}
	}
	{on contact
		{call "self_destruct"}
	}
	{on blast
		{call "self_destruct"}
	}
	{on "self_destruct"
		{if not tagged "empty_blu108"
			{spawn "ex_air_norm"}	{delete}
		}
	}
}

{"blu108b_skeet"
	{on spawn
		{ani_play "rotation" 0.7 loop}
		{delay 0.1
			{volumes "detector" enable overlap}
			{volumes "body" enable contact}
			{call "loop_detect"}
		}
		{delay 7 {call "self_destruct"}}
	}
	{on "loop_detect"
		{delay 0.2 {call "loop_detect"}}
		{if not altitude 1 {call "self_destruct"}}
	}
	{on ground_hit
		{call "self_destruct"}
	}
	{on contact
		{call "self_destruct"}
	}
	{on blast
		{call "self_destruct"}
	}
	{on "self_destruct"
		{spawn "ex_air_norm"}
		{delete}
	}
	{on overlap begin
		{if effector "vehicle"
			{spawn "spbe-d_fire" "visor" x}
			{spawn "skeet_core" "visor" x
				{impulse up 0.1 forward 100 com}
			}
			{call "self_destruct"}
		else 
			{volumes "detector" disable overlap} 
			{delay 0.01 {volumes "detector" enable overlap}}
		}
	}
}
{"spbe_pktm1r"
	{on spawn
		{ani_play "rotation" 1.5 loop}
		{gravity 0.1}
		{delay 0.2
;		        {volumes "detector_overlap" enable overlap}
		        {volumes "detector" enable contact}
		        {volumes "body" enable contact blast contact_ground}
				{add_view	"rok_tail"	"engine_fx"		"tail1"	}
				{add_view	"rok_tail"	"engine_fx" 		"tail2"	}
				{view start "engine_fx"}
				{delay 0.32
					{view pause "engine_fx"}
					{view stop "engine_fx"}
					{view hide "engine_fx"}
				}
		}
		{delay 7 {call "self_destruct"}}
	}
	{on ground_hit
		{call "self_destruct"}
	}
	{on contact
	
	  {if volume "sensor"
		{if effector "vehicle"
;			{volumes "detector" enable contact}
;			{delay 0.01 {volumes "detector" disable contact}}
			{volumes "detector" disable all}
			{call "self_destruct"}
		else 
;			{volumes "detector_overlap" disable overlap} 
;			{delay 0.01 {volumes "detector_overlap" enable overlap}}
			{volumes "detector" disable contact} 
			{delay 0.01 {volumes "detector" enable contact}}
		}
	   else
	    {volumes "detector" disable all}
		{call "self_destruct"}
	   }
	}
	{on blast
		{call "self_destruct"}
	}
	{on "self_destruct"
		{volumes disable all}
		{spawn "spbe-d_fire" "visor" x}
		{spawn "spbe_pktm1r_core" "visor" x
			{impulse up 0.1 forward 300 com}
		}
		{stuff_detonate}
	}
	{on overlap begin
		{if effector "vehicle"
			{volumes "detector" enable contact}
			{delay 0.01 {volumes "detector" disable contact}}
		else 
			{volumes "detector_overlap" disable overlap} 
			{delay 0.01 {volumes "detector_overlap" enable overlap}}
		}
	}
}
{"para_spbe"
	{on spawn
		{volumes "body" disable blast}
		{delay 1 {volumes "body" enable blast}}
	}
	{on "loop_detect"
		{impulse up -0.1 com}
		{impulse up 0.135 com}
		{delay 0.1 {call "loop_detect"}}
		{if not altitude 1 {call "self_destruct"}}
		{constrain_velocity 30}
	}
	{on ground_hit
		{call "self_destruct"}
	}
	{on contact
	  {if not effector "para_spbe"
	    {volumes "detector" disable all}
		{call "self_destruct"}
	   }
	}
	{on blast overload
		{if min_energy 1.5
			{call "self_destruct"}
		}
	}
	{on "self_destruct"
		{stuff_detonate}
	}
	{on overlap begin
		{if effector "vehicle"
			{volumes "detector" enable contact}
			{delay 0.01 {volumes "detector" disable contact}}
		else 
			{volumes "detector_overlap" disable overlap} 
			{delay 0.02 {volumes "detector_overlap" enable overlap}}
		}
	}
	{on "detonate"
		{delay 0.01 {stuff_detonate}}
	}
}

{"spbe-d"
	{on spawn
		{bone hide "parashute"}
		{impulse up 2 com}
		{impulse rnd_dir 2 1 com}
		{gravity 0.1}
		{delay 1.7
			{impulse up 0.1 com}
			{ani_play "rotation" 0.7 loop}
			{bone show "parashute"}
			{volumes "body" enable contact}
			{volumes "detector_overlap" enable overlap}
			{constrain_velocity 0.5}
			{call "loop_detect"}
			{gravity 5.1}
			{delay 80.0 15.0 {call "self_destruct"}}
		}
	}
	{on "loop_detect"
		{constrain_velocity 0.5}
	}
	{on "self_destruct"
		{spawn "spbe-d_fire" "visor" x}
		{spawn "spbe-d_core" "visor" x
			{impulse up 0.1 forward 300 com}
		}
	}
}

{"spbe_9n282"
	{on spawn
		{bone hide "parachute"}
		{gravity 0.4}
		{ani_play "open" 0.7}
		{delay 0.4
			{impulse up 0.1 com}
			{gravity 0.25}
			{ani_play "rotation" 0.4 loop}
			{bone show "parachute"}
			{volumes "body" enable contact}
			{volumes "detector_overlap" enable overlap}
			{constrain_velocity 33.5}
			{call "loop_detect"}
			{delay 60.0 {call "self_destruct"}}
		}
	}
	{on "self_destruct"
		{spawn "spbe-d_fire" "visor" x}
		{spawn "spbe_9n282_core" "visor" x
			{impulse up 0.1 forward 300 com}
		}
	}
}
{"smart155"
	{on spawn
		{bone hide "parachute"}
		{gravity 0.4}
		{ani_play "open" 0.7}
		{delay 0.4
			{impulse up 1 rnd_dir 2 1 com}
			{gravity 0.25}
			{ani_play "rotation" 0.4 loop}
			{bone show "parachute"}
			{volumes "body" enable contact}
			{volumes "detector_overlap" enable overlap}
			{constrain_velocity 33.5}
			{call "loop_detect"}
			{delay 60.0 {call "self_destruct"}}
		}
	}
	{on "self_destruct"
		{spawn "spbe-d_fire" "visor" x}
		{spawn "smart155_core" "visor" x
			{impulse up 0.1 forward 300 com}
		}
	}
}

{"parashute_torch"
	{on spawn
		{impulse up 0.1 com}
		{gravity 0.3}
		{delay 0.1 {volumes "body" enable contact}}
		{constrain_velocity 1.5}
		{call "loop_detect"}
	}
	{on "loop_detect"
		;{impulse up -0.5 com}
		{delay 1 {call "loop_detect"}}
		{if not altitude 1 {call "self_destruct"}}
		{constrain_velocity 5}
	}
	{on ground_hit
		{call "self_destruct"}
	}
	{on contact
		{call "self_destruct"}
	}
	{on blast
		{call "self_destruct"}
	}
	{on "self_destruct"
		{delete}
	}
}
{"paratorch"
	{on spawn
		{add_view "signal_rocket_big" "flare" "body"}
		{view start "flare"}
		{delay 60 {call "self_destruct"}}
	}
}
{"paratorch_small"
	{on spawn
		{add_view "signal_rocket" "flare" "body"}
		{view start "flare"}
		{delay 30 {call "self_destruct"}}
	}
}

{"odab_500_impactor"
	{on "loop_detect" overload
		{if not altitude 10 {call "dispence"}
		else {delay 0.2 {call "loop_detect"}}}
	}
	{on "dispence" overload
;		{spawn "odab_500_dispencer" "root" x}
;		{spawn "odab_500_dispencer" "root" x}
;		{spawn "odab_500_dispencer" "root" x}
;		{spawn "odab_500_dispencer" "root" x}
;		{spawn "odab_500_dispencer" "root" x}
;		{spawn "odab_500_dispencer" "root" x}
;		{spawn "odab_500_dispencer" "root" x}
;		{spawn "odab_500_dispencer" "root" x}
;		{spawn "odab_500_dispencer" "root" x}
;		{spawn "odab_500_dispencer" "root" x}
		{spawn "aero_die_particle"}
		{spawn "ex_odab"}
		{delete}
	}
}

{"odab_500_dispencer"
	{on spawn
;		{impulse up 0 2 rnd_dir 12 com}
		{delay 1 {stuff_detonate}}
	}
}
{"carrier_based"
	{on "cwsh_switch_hatch" overload
		{if chassis "airborne"
			{tags add "cwss_land_me"}
			{tags add "need_auto_landing"}{delay 5 {tags remove "need_auto_landing"}}
		}
	}
}
{"transport_plane"
	{on spawn
		{link_sound "CargoOpen" "vehicle/turret_cw/t-72-turret"}
		{volumes disable overlap}
		{volumes "vehicle" enable overlap}
		{bone hide "platform1"}
		{bone hide "platform2"}
		{bone hide "platform3"}
		{bone hide "platform4"}
		{bone hide "platform5"}
		{bone hide "platform6"}
		{bone hide "platform7"}
		{bone hide "platform8"}
		{bone hide "platform9"}
		{ani_wind "driver_open" end}
		{if tagged "place1_busy" {ani_wind "vehicle1_in" end} {if not tagged "dont_drop" {bone show "platform1"}}}
		{if tagged "place2_busy" {ani_wind "vehicle2_in" end} {if not tagged "dont_drop" {bone show "platform2"}}}
		{if tagged "place3_busy" {ani_wind "vehicle3_in" end} {if not tagged "dont_drop" {bone show "platform3"}}}
		{if tagged "place4_busy" {ani_wind "vehicle4_in" end} {if not tagged "dont_drop" {bone show "platform4"}}}
		{if tagged "place5_busy" {ani_wind "vehicle5_in" end} {if not tagged "dont_drop" {bone show "platform5"}}}
		{if tagged "place6_busy" {ani_wind "vehicle6_in" end} {if not tagged "dont_drop" {bone show "platform6"}}}
		{if tagged "place7_busy" {ani_wind "vehicle7_in" end} {if not tagged "dont_drop" {bone show "platform7"}}}
		{if tagged "place8_busy" {ani_wind "vehicle8_in" end} {if not tagged "dont_drop" {bone show "platform8"}}}
		{if tagged "place9_busy" {ani_wind "vehicle9_in" end} {if not tagged "dont_drop" {bone show "platform9"}}}
		{if tagged "cargo_open" {ani_wind "cargo_open" end}}
		{if tagged "rampa_open" {ani_wind "pandus_open" end}}
	}
	{on "_burn" overload
		{damage_report "engine" "burn_fire"}
		{log "burn_volume"}
		{if not burned
			{if rand 0.25
				{log "burn_engine"}				
				("burn_engine" engine(0) engine1(0) engine2(0) enginea(1) engineb(0) enginec(0) engined(0))
			else rand 0.5
				{log "burn_engine"}				
				("burn_engine" engine(0) engine1(0) engine2(0) enginea(0) engineb(1) enginec(0) engined(0))
			else rand 0.75
				{log "burn_engine"}				
				("burn_engine" engine(0) engine1(0) engine2(0) enginea(0) engineb(0) enginec(1) engined(0))
			else
				{log "burn_engine"}				
				("burn_engine" engine(0) engine1(0) engine2(0) enginea(0) engineb(0) enginec(0) engined(1))
			}
		}
	}

	{on crew in
		{call "emit_desant1"}
		{call "emit_desant2"}
		{call "emit_desant3"}
		{call "emit_desant4"}
		{call "emit_desant5"}
		{call "emit_desant6"}
		{call "emit_desant7"}
		{call "emit_desant8"}
		{call "emit_desant9"}
	}
	{on "mp_destroy"
		{with_linked_entity "vehicle1" {call "mp_destroy"}}
		{with_linked_entity "vehicle2" {call "mp_destroy"}}
		{with_linked_entity "vehicle3" {call "mp_destroy"}}
		{with_linked_entity "vehicle4" {call "mp_destroy"}}
		{with_linked_entity "vehicle5" {call "mp_destroy"}}
		{with_linked_entity "vehicle6" {call "mp_destroy"}}
		{with_linked_entity "vehicle7" {call "mp_destroy"}}
		{with_linked_entity "vehicle8" {call "mp_destroy"}}
		{with_linked_entity "vehicle9" {call "mp_destroy"}}
	}
		
	{on crew out
		{kill_delay "door"}
		{if not flag "radar_up"
			{ani_play "driver_open"}
		}
		{set "radar_up" 1}
		{delay 5 "door" {ani_play "driver_open" -1} {set "radar_up" 0}}
	}
	{on "engine_on"
		{if not velocity 5 {ani_play "ladder_in"} {ani_play "ladder_in_d"} {call "close_rampa"}}
	}
	{on "engine_stop"
		{if not velocity 5 {if not tagged "destroyed" {ani_play "ladder_in" -1}{ani_play "ladder_in_d" -1} {call "open_rampa"}}}
	}
	{on "open_cargo"
		{if not tagged "cargo_open"
			{ani_play "cargo_open" callback}
			{play_sound "ParachuteOpen" 1}
			{tags add "cargo_open"}
			{call "open_rampa"}
		}
	}
	{on "open_rampa"
		{if not tagged "rampa_open"
		    {if tagged "cargo_open"
		       {if chassis "airborne"
		       else
			{ani_play "pandus_open"}
			{tags add "rampa_open"}
		       }
		     }
		}
	}
	{on "close_cargo"
		{if tagged "cargo_open"
			{ani_play "cargo_open" -1}
			{tags remove "cargo_open"}
			{call "close_rampa"}
			{play_sound "ParachuteOpen" 1}
		}
	}
	{on "close_rampa"
		{if tagged "rampa_open"
			{ani_play "pandus_open" -1}
			{tags remove "rampa_open"}
		}
	}
	{on "takeoff"
		{if flag "specability" {call "specability" }}
		{ani_play "driver_open" -1}
	}

	{on "specability" overload
		{if not flag "specability"
			{set "specability" 1}
			{damage_report "body" "cargobay_opened"}
			{call "open_cargo"}
		else 
			{set "specability" 0}
			{damage_report "body" "cargobay_closed"}
			{call "close_cargo"}
		}
	}


	(define "load_vehicle"
		        {tags add "cargo_inside"}
		        {if not tagged "place1_busy"
			{delay 0.1 {ani_play "vehicle1_in" callback} {ani_play "cargo_lift"}}
			{tags add "vdv_link_place1"} {delay 3 {tags remove "vdv_link_place1"}}
			{tags add "place1_busy"}
			{call "emit_desant1"}
			{with_effector {tags add "vdv_link_to_place1"} {call "emit_desant"} {delay 3 {tags remove "vdv_link_to_place1"}}}
		        else not tagged "place2_busy"
			{delay 0.1 {ani_play "vehicle2_in" callback} {ani_play "cargo_lift"}}
			{tags add "vdv_link_place2"} {delay 3 {tags remove "vdv_link_place2"}}
			{tags add "place2_busy"}
			{call "emit_desant2"}
			{with_effector {tags add "vdv_link_to_place2"} {call "emit_desant"} {delay 3 {tags remove "vdv_link_to_place2"}}}
		        else not tagged "place3_busy"
			{delay 0.1 {ani_play "vehicle3_in" callback} {ani_play "cargo_lift"}}
			{tags add "vdv_link_place3"} {delay 3 {tags remove "vdv_link_place3"}}
			{tags add "place3_busy"}
			{call "emit_desant3"}
			{with_effector {tags add "vdv_link_to_place3"} {call "emit_desant"} {delay 3 {tags remove "vdv_link_to_place3"}}}
		        }
	)


	{on animation_end "cargo_open"	
	     {if chassis "airborne"
	          {if not tagged "dont_drop"
				{if tagged "place3_busy"
					{volumes disable overlap}
					{ani_play "vehicle3_out" callback}
					{delay 2.5 {ani_play "vehicle2_out" callback}}
					{delay 5 {ani_play "vehicle1_out" callback}}
				else tagged "place2_busy"
					{volumes disable overlap}
					{ani_play "vehicle2_out" callback}
					{delay 3 {ani_play "vehicle1_out" callback}}
					{delay 5.5 {call "drop_desant3"}}
				else tagged "place1_busy"
					{volumes disable overlap}
					{ani_play "vehicle1_out" callback}
					{delay 3 {call "drop_desant2"}}
					{delay 4 {call "drop_desant3"}}
				else 
					{call "drop_desant1"}
					{delay 1 {call "drop_desant2"}}
					{delay 2 {call "drop_desant3"}}
				}
	          }
	     else not chassis "airborne"
	          {if tagged "cargo_inside"
				{tags remove "cargo_inside"}
				{if tagged "place3_busy"
					{volumes disable overlap}
					{bone hide "platform3"} {ani_play "cargo_unload"} {ani_play "vehicle3_unload" callback}
					{delay 10 {bone hide "platform2"}  {ani_play "cargo_unload"} {ani_play "vehicle2_unload" callback}}
					{delay 20 {bone hide "platform1"}  {ani_play "cargo_unload"} {ani_play "vehicle1_unload" callback}}
				else tagged "place2_busy"
					{volumes disable overlap}
					{bone hide "platform2"}  {ani_play "cargo_unload"} {ani_play "vehicle2_unload" callback}
					{delay 10 {bone hide "platform1"}  {ani_play "cargo_unload"} {ani_play "vehicle1_unload" callback}}
				else tagged "place1_busy"
					{volumes disable overlap}
					{bone hide "platform1"}  {ani_play "cargo_unload"} {ani_play "vehicle1_unload" callback}
				}
	          }
	     }

	}
     (define "drop_vehicle"
		{on animation_end "vehicle%0_in"
			{if not tagged "dont_drop"
				 {bone show "platform%0"}
			}
		}
		{on "drop_vehicle_%0"
			{ani_play "vehicle%0_out" callback}
		}
		{on animation_end "vehicle%0_out"
			{with_linked_entity "vehicle%0"
				{delay 0.1 {tags add "heli_paradrop%0"} }
			}
			{spawn "parachute_vehicle"  "vehicle%0_spawner" x 
				{tags add "heli_parashute%0"} 
				{call "start"}
			}
			{bone hide "platform%0"}
			{bone cut "vehicle%0"}
		}
		{on animation_end "vehicle%0_unload"
			{bone cut "vehicle%0"}
		}
     )
	("drop_vehicle" args 1)
	("drop_vehicle" args 2)
	("drop_vehicle" args 3)

}

{"transport_ship"
     (define "drop_vehicle"
		{on animation_end "vehicle%0_in"
			{if not tagged "dont_drop"
				 {bone show "platform%0"}
			}
		}
		{on "drop_vehicle_%0"
			{ani_play "vehicle%0_out" callback}
		}
		{on animation_end "vehicle%0_out"
			{with_linked_entity "vehicle%0"
				{delay 0.1 {tags add "heli_paradrop%0"} }
			}
			{spawn "parachute_vehicle"  "vehicle%0_spawner" x 
				{tags add "heli_parashute%0"} 
				{call "start"}
			}
			{bone cut "vehicle%0"}
		}
		{on animation_end "vehicle%0_unload"
			{bone cut "vehicle%0"}
		}
     )
	("drop_vehicle" args 4)
	("drop_vehicle" args 5)
	("drop_vehicle" args 6)
	("drop_vehicle" args 7)
	("drop_vehicle" args 8)
	("drop_vehicle" args 9)
}
{"small_UAV"
	{on spawn
		{tags remove "smalluav_no_connect"}
		{tags remove "smalluav_land"}
		{tags remove "smalluav_return"}
	}
	{on "disable_aututakeoff_on_spawn" overload
	}
	{on "check_alt" overload
	}
	{on "eject_all" overload}
	{on "takeoff" overload
	      {if tagged "takeoff_speed" 
			{if not dead
				{play_sound "fly" 1}
			}
			{call "check_moveability"}
			{call "update_weaponry"}
			{tags add "plane_in_flight"}
			{delay 4 
		       {if chassis "airborne"
		          {if not linked
					{ani_play "fly" 0.2 loop}
					{ani_play "basis" 0.4}
					{call "check_moveability"}
		           }
		       }
		}
		{delay 0.3 "start_check_altitude" {call "check_altitude"}}
	   }
	}
	{on "u_w_electronics_damaged"
		{call "fall"}
	}
	{on "mp_destroy"
		{delay 0.1
			{tear "piece_medium_steel" bone "visor_ols"
				{impulse up 2 1 dir 2 1}
			}
			{tear "piece_medium_steel" bone "visor_ols1"
				{impulse up 2 1 dir 2 1}
			}
		}
	}
	{on "check_takeoff_speed" overload
	      {if not chassis "airborne"
				("enough_takeoff_speed")
			{if velocity 30
				{if terrain_pp "road"
				else terrain_pp "country_road"
				else 
					{components "wheel_back" break}
					{components "retract_wheelR" break}
					{components "retract_wheelL" break}
				}
			}
	       }
		{delay 0.2
		   {if flag "engine_started"
		        {if not chassis "airborne"
					{call "check_takeoff_speed"}
		         else  not tagged "takeoff_speed"
			{impulse forward 5 3 no_position}
			{chassis_work 0}
			{call "tear_wheelright"}
			{call "tear_wheelleft"}
			{call "tear_wheelfront"}
			{call "mp_destroy"}
		        }
		    }
		}
	}
	{on blast_hit
		{if min_energy  1
			{call "fall"}
		}
	}
	{on pierce
		{if not stuff "proj_pointer"
			{if not stuff "bullet"
				{call "fall"}
			}
		}
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
		{tags remove "smalluav_no_connect"}
		{tags remove "smalluav_land"}
		{tags remove "smalluav_return"}
	}
	{on contact overload
		{if effector "vehicle"
			{call "collide"}
		else effector "stack"
			{call "collide"}
		else effector "construction"
			{call "collide"}
		else effector "tree"
			{call "collide"}
		else effector "fence"
			{call "collide"}
		else effector "human"
			{call "collide"}
		}
	}
	{on "explosion" overload
		{if not able "exploded"
			{able "exploded" 1}
			{call "_explosion"}
		}
	}
	{on "_explosion_effects" overload}
	{on ground_hit overload
		{spawn "spheredust_big_short"}
		{call "collide"}
		{if velocity 1
			{call "explosion"}
			{tear "piece_medium_steel" bone "body"
				{impulse up 2 1 dir 2 1}
			}
			{delay 0.1 {delete}}
		}
		{constrain_velocity 15}
	}
	{on "check_altitude" overload
	       {if flag "engine_started"
			{if not altitude 0
				{call "fall"}
				{call "collide"}
				{delay 0.1 {constrain_velocity 40}}
				{delay 0.3 {constrain_velocity 40}}
			
			}
			{delay 0.5 "check_altitude"
				{call "check_altitude"}
			}
	      }
	}
	{on "check_wings"
		{if not work "wingr1" {call "fall"}}{if not work "wingr2" {call "fall"}}
		{if not work "wingl1" {call "fall"}}{if not work "wingl2" {call "fall"}}
	}
	{on "specability" overload
		{if not flag "specability"
			{set "specability" 1}
			{tags add "smalluav_return"}
			{damage_report "body" "return_to_base"}
		else 
			{set "specability" 0}
			{tags remove "smalluav_land"}{tags remove "smalluav_return"}
			{damage_report "body" "return_to_base_cancel"}
		}
	}
	{on bullet_hit
		{if stuff "detect_uav_hit"
			{with_effector {call "single_launch"}}
		}
	}
}
(define "jammable_uav"
{"small_UAV ecm_vulnerable_%side"
	{on spawn {tags remove "uav_jammed"}}
	{on "ecm_jammed"
		{if tagged "ecm_effect_2" 
			{tags add "uav_jammed"}  {tags add "smalluav_return"} 
			{delay 0.5 {tags remove "smalluav_land"}}
			{delay 1 {tags remove "smalluav_land"}}
			{delay 2 {tags remove "smalluav_return"}{tags remove "smalluav_land"}}
			{delay 5 {call "ecm_jammed"}}
		else {tags remove "uav_jammed"} 
		}
	}
}
)
("jammable_uav" side(rus))
("jammable_uav" side(usa))
{"loitering_uav"
	{on spawn
		{ani_play "on_start"}
	}
	{on blast_hit
		{if min_energy  1
			{call "detonate"}
		}
	}
	{on "collide" overload
		{call "detonate"}
	}
	{on engine off
		{call "detonate"}
	}
	{on "detonate"
	    {if altitude 0
		 {spawn "proj_restrictor" "root" x}
		 {stuff_detonate}
		  else   			  
			{gravity 0}
			{impulse up 2.0}
			{call "underground_detonate"}
		}
	}

	{on "underground_detonate"
	    {if altitude 0
		 {stuff_detonate}
		  else   		  
		    {impulse up 2.0}
			{delay 0.01 {call "underground_detonate"}}
		}
	}
	{on ground_hit overload
		{spawn "spheredust_big_short"}
		{call "collide"}
	}


}
(define "loitering_munition"
	{on fire "mark"
	   {delay 0.1
		{volumes disable all}
		{spawn "%missilename_carrier" "foresight_spawn" x}
		{bone hide "basis"}
		{delete}
	   }
	}
)
(include "airborne_modern.inc")