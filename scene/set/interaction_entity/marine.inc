{"marine"
	{on spawn
		{add_view	"smoke_black"		"on_move"	"FX_smoke"             }
		{add_view	"smoke_black"		"on_move"	"FX_smoke1"             }
		{add_view	"smoke_black"		"on_move"	"FXsmoke2"             }
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
		{add_view	"wash_engine_small"	"on_move"	"FX_bulb_small_engine2"}
		{add_view	"wash_engine_norm"	"on_move"	"FX_bulb_norm_engine1"}
		{view start "on_stead"}
		{ani_play "drift" loop}
	}
	{on move on
		{view start "on_move"}
		{view pause "on_stead"}
		{ani_stop "drift"}
		{ani_play "move" loop}
	}
	{on move off
		{view start "on_stead"}
		{view pause "on_move"}
		{ani_play "drift" loop}
		{ani_stop "move"}
	}
	{on break_armor
		{component break}
		{if volume "float"
			{call "break_float"}
		}
	}
	{on "check_water_level" overload}
	{on "sinking"
		{delay 3
			{able "sinking" 1}
			{for_each_link
				{able "sinking" 1}
			}
		}
	}
	{on "break_float"
		{call "sinking"}
		{volumes "float" disable all}
		{impulse up 0.2}
		{ani_stop "drift"}
		{chassis_work 0}
		{volumes disable obstacle}
	}
	{on grounded on
		{ani_stop "drift"}
		{ani_stop "move"}
	}
	{on grounded off
		{ani_play "drift" loop}
	}
	{on "cut_parts"
		(define "cut_part"
			{tear "piece_large_steel" bone %0
				{impulse up 8 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 10 no_position}
;				{add_view "smoke_dead_wheel" "smoke" "basis"}
;				{view start "smoke"}
				{delay_effect 20 5 "stop"}
				{tags add "marine_part"}
				{delay 20
					{delete}
				}
			}
		)
		("cut_part" args "part1")
		("cut_part" args "part2")
		("cut_part" args "part3")
		("cut_part" args "part4")
		("cut_part" args "part5")
		("cut_part" args "part6")
		("cut_part" args "part7")
		("cut_part" args "part8")
	}
	{on bullet_hit
;=============part of projectile system by Timosh=============
		{if  stuff "rus_IR_ff_beam ammo"
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
;==========================
	}
	{on "smokescreen" overload
	 {if operatable
		{call "cwsh_switch_hatch"}
	 }	
	}
}

{"barge"
	{on break_armor overload
		{call "sink"}
;		{if name "blast"
;			{if min_energy 400
;				{call "sink"}
;			else min_energy 90
;				{call "shake"}
;			}
;		}
	}
	{on "sink"
		{call "explosion"}
		{ani_play "sink"}
	}
	{on "explosion"
		{delay 3
			{call "break_float"}
		}
	}
	{on "shake"
		{ani_play "hit"}
	}
}

{"platforma"
	{on break
		{if component "body1"
			{spawn "TANK_DIE" "fxdead_1a"}
		}
		{if component "body2"
			{spawn "TANK_DIE" "fxdead_2a"}
		}
		{if component "ballast_l1"
			{spawn "ex_water_extra_big" "fxdead_l1a"}
			{spawn "platform_par1" "fxdead_l1a"}
		}
		{if component "ballast_r1"
			{spawn "ex_water_extra_big" "fxdead_r1a"}
			{spawn "platform_par1" "fxdead_r1a"}
		}
		{if component "ballast_l2"
			{spawn "ex_water_extra_big" "fxdead_l2a"}
			{spawn "platform_par1" "fxdead_l2a"}
		}
		{if component "ballast_r2"
			{spawn "ex_water_extra_big" "fxdead_r2a"}
			{spawn "platform_par1" "fxdead_r2a"}
		}
	}
	{on break_armor overload
		{if name "blast"
			{if min_energy 10
				{component destroy}
				{if volume "float"
					{call "break_float"}
				}
			}
		}
	}
}

{"torpedo_boat marine"
	{on spawn
		{if flag "torpedo1"
			{bone cut "torpedo1"}
		}
		{if flag "torpedo2"
			{bone cut "torpedo2"}
		}
	}
	{on fire "gun"
		{if not flag "torpedo1"
			{set "torpedo1" 1}
			{ani_play "torpedo1" callback}
		else not flag "torpedo2"
			{set "torpedo2" 1}
			{ani_play "torpedo2" callback}
		}
	}
	{on animation_end "torpedo1"
		{call "launch_torpedo1"}
	}
	{on animation_end "torpedo2"
		{call "launch_torpedo2"}
	}
	{on "launch_torpedo1"
		{bone hide "torpedo1"}
		{volumes "torpedo1" disable all}
	}
	{on "launch_torpedo2"
		{bone hide "torpedo2"}
		{volumes "torpedo2" disable all}
	}
	{on operatable on
		{delay 0.1
			{play_sound "engine_operatable" 1}
		}
	}
	{on operatable off
		{stop_sound "engine_operatable"}
	}
	(define "torpedo_detonate"
		{delay 0.1
;			{spawn "tank_die" "fx_exp_torpedo%0"}
			{blastwave c4 8 r0 3 r1 6 bone "fx_exp_torpedo%0"}
			{bone cut "torpedo%0"}
			{set "torpedo%0" 1}
			{call "explosion_sequence"}
		}
	)
	(define "pierce_torpedo_detonate"
		{if volume "torpedo_det%0"
			("torpedo_detonate" args %0)
		}
	)
	(define "blast_torpedo_detonate"
		{if volume "torpedo%0"
			("torpedo_detonate" args %0)
		}
	)
	{on break_armor
		{if name "pierce"
			("pierce_torpedo_detonate" args 1)
			("pierce_torpedo_detonate" args 2)
			{if volume "body"
				{if stuff "shell big"
					("torpedo_detonate" args 1)
					("torpedo_detonate" args 2)
				}
			}
		else name "blast"
			{if min_energy 2
				("torpedo_detonate" args 1)
				("torpedo_detonate" args 2)
			}
		}
	}
	{on "_explosion"
		{call "break"}
	}
	{on "break"
		{stop_sound "engine_operatable"}
		{call "light_break"}
	}
	{on "light_break"}	; handled in extender
	{on "light_on"}		; handled in extender
	{on "light_off"}	; handled in extender
}

{"air-bag"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/lct"			}
		{link_sound "engine"			"vehicle/marine/airbag"			}
		{link_sound "engine_end"		"vehicle/marine/airbag_end"		}
		{link_sound "exhaust"			"vehicle/marine/airbag_up"		}
	}
	{on pierce
;		{if armor_health 1 and not flag "broken"
		{if not flag "broken"
			{call "mp_destroy"}
		else
;			{if component "engine" and armor_health 50
			{if component "engine"
				{if stuff "shell"
					{if rand 0.6
						{components "engine" break}
					}
					{spawn "boat_pierce"}
				else rand 0.15
					{components "engine" break}
				}
			}
			{if rand 0.25
				{spawn "boat_pierce"}
			}
		}
	}
	{on "mp_destroy" ;hack for "burn_damage"
		{if not tagged "destroyed"
			{tags add "destroyed"}
			{components break}
			{drop_orders}
			{reset_manual_control}
			{able select 0}
			{able repaired 0}
			{unlink_trailer}
			{volumes disable touch}
			{call "weapons_off"}
		}
	}
	{on break_armor
;		{if armor_health 1 and not flag "broken"
		{if not flag "broken"
			{if name "blast"
				{call "blast_body"}
			}
		}
	}
	{on bullet_hit
		{if relation "enemy" and stuff "rocketlauncher"
			{if volume "body"
			 	{if rand 0.5
					{call "blast_body"}
				else
					{components "body" break}
				}
			 else volume "engine"
				{call "blast_body"}
			}
		}
		{if volume "body"
			{spawn "boat_hit"}
		else volume "engine"
			{spawn "metal_hit_bul"}
		}
	}
	{on "blast_body"
		{if min_energy 8
			{impulse up 1.5 0.5 dir 1.5 0.5}
		 else min_energy 4
			{impulse up 0.8 0.3 dir 0.8 0.3}
		}
		{call "explosion"}
	}
	{on break
		{if component "body"
;			{if armor_health 1
				{call "break_float"}
;			}
			{spawn "boat_die"}
		else component "engine"
            {spawn "engine" "sterr"}
		}
	}
	{on "_explosion"
		{add_view "smoke_dead_norm" "deathfx" "fxfire1"}
		{if not flag "crush"
			{spawn "boat_die" "Basis"}
			{spawn "boat_die"}
			{impulse up 2.5 1.5 dir 2 1}
		}
	}		
	{on "add_flag"
		{add_view "flag_white" "flag" "skin_front"}
		{view start "flag"}
	}		
}
{"pg1"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/marine/lct_airbag/lct_loop/"	}
		{link_sound "move_end"			"vehicle/marine/lct_airbag/lct_end/"	}		
		{link_sound "engine"			"vehicle/marine/airbag"					}
		{link_sound "engine_end"		"vehicle/marine/airbag_end"				}
		{link_sound "exhaust"			"vehicle/marine/airbag_up"				}
	}
	{on break
		{call "break_float"}
	}
}
{"small_boat"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/lct"			}
		{link_sound "engine"			"vehicle/marine/airbag"			}
		{link_sound "engine_end"		"vehicle/marine/airbag_end"		}
		{link_sound "exhaust"			"vehicle/marine/airbag_up"		}
	}
	{on break
		{if name "blast"
			{if min_energy 4
				{delay_ex 0
					{set_skeleton "_xx" sync}
				}
				{components "body" destroy}
				{call "break_float"}
				{spawn "car_die" "basis"}
				{spawn "car_die_particle" "basis"}
			}
		}
		{if component "body" {call "break_float"}
		else component "engine"	{chassis_work 0}}
		
	}
}
(define "rhib_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/lct"			}
		{link_sound "engine"			"vehicle/marine/rhib_work"			}
		{link_sound "engine_end"		"vehicle/marine/rhib_stop"		}
		{link_sound "exhaust"			"vehicle/marine/rhib_start"		}
	}

)
{"boat_rhib" ("rhib_sound")}
{"lcvp"
    {on spawn
		{ani_play "open"}
	}
	{on move on
		{ani_play "open" -1 resume}
	}
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/d3"}
		{link_sound "move_end"			"vehicle/tracks/d3_end"}
		{link_sound "engine"			"vehicle/marine/d3"		}
		{link_sound "engine_end"		"vehicle/marine/d3_end"	}
		{link_sound "exhaust"			"vehicle/marine/d3_up"	}
	}
}
{"fishboat"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/lct"}
		{link_sound "move_end"			"vehicle/tracks/lct_end"}
		{link_sound "engine"			"vehicle/marine/d3"		}
		{link_sound "engine_end"		"vehicle/marine/lct_end"	}
		{link_sound "exhaust"			"vehicle/marine/lct_up"	}
	}
	{on break
		{call "break_float"}
	}
}
{"boat"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/d3"}
		{link_sound "move_end"			"vehicle/tracks/d3_end"}
		{link_sound "engine"			"vehicle/marine/d3"		}
		{link_sound "engine_end"		"vehicle/marine/d3_end"	}
		{link_sound "exhaust"			"vehicle/marine/d3_up"	}
	}
	(define "tear_marine_part"
		{components "%0" destroy}
		{tear "piece_large_steel" bone "%0"
;			{impulse up 5 2.3 dir 3 1.5 cx 5 2 cy 5 2 rnd_dir 10 no_position}
		}
	)

	(define "sink_volume"
		{delay %1 1
			{volumes %0 disable float bullet blast}
			{impulse up 0.2}
		}
	)
	(define "sink_sequence"
		{call "sinking"}
		{impulse up 0.2}
		("sink_volume" args %0 %1)
		("sink_volume" args %2 %3)
		("sink_volume" args %4 %5)
		("sink_volume" args %6 %7)
		{delay 3
			{call "light_flash"}
			{delay 0.7 0.1
				{kill_delay "light_flash"}
				{call "light_off"}
			}
		}
	)
	{on "light_flash"
		{delay 0 "light_flash"
			{if rand 0.3
				{if flag "light_on"
					{call "light_off"}
					{set "light_on" 0}
				else
					{call "light_on"}
					{set "light_on" 1}
				}
			}
			{call "light_flash"}
		}
	}

	{on break
		{if component "body_front"
			{call "break_body"}
		else component "body"
			{call "break_body"}
		else component "body_rear"
			{call "break_body"}
		}
	}
	{on "break_body"
		{if component "body_front"
			("sink_sequence" args "ballast1" 2 "ballast3" 4 "ballast2" 7 "ballast4" 8)
		}
		{if component "body"
			("sink_sequence" args "ballast3" 2 "ballast1" 4 "ballast4" 7 "ballast2" 8)
		}
		{if component "body_rear"
			("torpedo_detonate" args torpedo1)
			("torpedo_detonate" args torpedo2)
			("sink_sequence" args "ballast2" 2 "ballast4" 4 "ballast3" 7 "ballast1" 8)
		}
	}
	{on "explosion_sequence"
		{if not flag "explode"
			("sink_sequence" args "ballast2" 2 "ballast4" 4 "ballast3" 7 "ballast1" 8)
			{set "explode" 1}
			{spawn "marine_die" "fx_exp1"}
			{delay 0.3 0.1
				{spawn "marine_die" "fx_exp2"}
				{blastwave c4 8 r0 5 r1 6 bone "fx_exp2"}
				{components "body_rear" destroy}
				{delay 0.3 0.1
					{volumes "float" disable float bullet blast}
					{components "body" destroy}
;					{volumes disable contact blast}
					{call "cut_parts"}
					{spawn "marine_die" "fx_exp3"}
					{blastwave c4 8 r0 5 r1 6 bone "fx_exp3"}
					{call "explosion"}
;					{volumes disable contact blast}
					{delay 0.3 0.1
						{spawn "marine_die" "fx_exp4"}
						{blastwave c4 8 r0 5 r1 6 bone "fx_exp4"}
						{components "body_front" destroy}
					}
				}
			}
			{for_each_link
				{delay_effect 1 0.5 "explosion"}
			}
		}
	}
}
{"mtb_d3"
	{on "cut_parts"
		("tear_marine_part" args cabin)
		{bone cut "torpedo1"}
		{bone cut "torpedo2"}
;		{bone cut "cabin"}
	}
	{on "launch_torpedo1"
		{spawn "torpedo" "torpedo1" x no_normal no_position}
	}
	{on "launch_torpedo2"
		{spawn "torpedo" "torpedo2" x no_normal no_position}
	}
}

{"u-boat"
	{on spawn
		{if not flag "opened"
			{call "open"}
			{set "opened" 1}
		}
	}
	{on "launch_torpedo1"
		{spawn "torpedo_uboat" "torpedo1" x no_normal no_position}
	}
	{on "launch_torpedo2"
		{spawn "torpedo_uboat" "torpedo2" x no_normal no_position}
	}
}

{"boat big"
	(define "body_break_fx"
		{set "body_%0_broken" 1}
		{spawn "marine_die" "fire_%02"}
		{add_view "smoke_dead_norm"		"fire_%0"		"fire_%01"}
		{add_view "smoke_dead_norm"		"fire_%0"		"fire_%02"}
		{add_view "smoke_dead_norm"		"fire_%0"		"fire_%03"}
		{add_view "smoke_dead_norm"		"fire_%0"		"fire_%04"}
		{add_view "smoke_dead_norm"		"fire_%0"		"fire_%05"}
		{add_view "smoke_dead_norm"		"fire_%0"		"fire_%06"}
		{add_view "smoke_dead_small"	"smoke_%0"		"smoke_%01"}
		{add_view "smoke_dead_small"	"smoke_%0"		"smoke_%02"}
		{add_view "smoke_dead_small"	"smoke_%0"		"smoke_%03"}
		{add_view "smoke_dead_small"	"smoke_%0"		"smoke_%04"}
		{add_view "smoke_dead_small"	"smoke_%0"		"smoke_%05"}
		{add_view "smoke_dead_small"	"smoke_%0"		"smoke_%06"}
		{add_view "smoke_black_big4"	"fire_%0"		"fx_fire_%0_big01"}
		{add_view "smoke_black_big4"	"fire_%0"		"fx_fire_%0_big02"}
		{add_view "smoke_black_big4"	"fire_%0"		"fx_fire_%0_big03"}
		{add_view "smoke_dead_norm_nl"	"fire_%0"		"fx_fire_%001"}
		{add_view "smoke_dead_norm_nl"	"fire_%0"		"fx_fire_%002"}
		{add_view "smoke_dead_norm_nl"	"fire_%0"		"fx_fire_%003"}
		{add_view "smoke_dead_norm_nl"	"fire_%0"		"fx_fire_%004"}
		{add_view "smoke_dead_norm_nl"	"fire_%0"		"fx_fire_%005"}
		{add_view "smoke_dead_norm_nl"	"fire_%0"		"fx_fire_%006"}
		{add_view "smoke_dead_small"	"smoke_%0"		"fx_smoke_%001"}
		{add_view "smoke_dead_small"	"smoke_%0"		"fx_smoke_%002"}
		{add_view "smoke_dead_small"	"smoke_%0"		"fx_smoke_%003"}
		{add_view "smoke_dead_small"	"smoke_%0"		"fx_smoke_%004"}
		{add_view "smoke_dead_small"	"smoke_%0"		"fx_smoke_%005"}
		{add_view "smoke_dead_small"	"smoke_%0"		"fx_smoke_%006"}
		{view start "fire_%0"}
		{view start "smoke_%0"}
	)
	{on "cut_parts"
		{delay 0.1
			("sink_sequence" args "ballast2" 0.2 "ballast4" 0.8 "ballast3" 1.5 "ballast1" 1.5)
			{volumes disable contact blast}
		}
	}
	{on "update_moveable" overload}
	{on "break_body" overload
		{if component "body_front"
			("body_break_fx" args front)
		else component "body"
			("body_break_fx" args center)
		else component "body_rear"
			("body_break_fx" args rear)
		}
		{if flag "body_front_broken"
			{if flag "body_center_broken"
				{if flag "body_rear_broken"
					{delay 5 1
						{call "explosion_sequence"}
					}
				}
			}
		}
	}
}

{"pg1"
	{on "_burn"
		{add_view "smoke_dead_norm" "burn_fire" "fx_fire1"}
		{view start "burn_fire"}
	}
	{on "cut_parts"
		{if not flag "crush"
			{spawn "tank_die" "Basis"}
			{spawn "tank_die_particle"}
			{impulse up 2.5 1.5 dir 2 1}
		}
		{call "break_float"}
	}
	{on break_armor
		{if name "pierce"
			{call "burn"}
			{delay 5 1
				{call "explosion"}
			}
		}
	}
}

{"torpedomine"
	{on "cut_parts"
		{if not flag "crush"
			{spawn "ex_water_extra_big"}
			{blastwave c4 5 r0 4 r1 10}
			{fire radius 8 time 5 heating 10}
		}
		{call "break_float"}
	}
}

{"torpedo"
	{on spawn
		(define "spawn_spherewaters"
			{delay 0.03
			  {if not tagged "spawn_underwater"
				{spawn "spherewater_big"}
				{spawn "spherewater_big2" local_offset -40 0 0}
				{spawn "spherewater_big2" local_offset -80 0 0}
				{spawn "spherewater_big2" local_offset -120 0 0}
			  }
			}
			{add_view "wash_torpedo_small" "tail" "tail"}
			{view start "tail"}
		)
	
	  {if terrain_fx "water"
		("spawn_spherewaters")
	  else terrain_fx "shallow_water"
	  	("spawn_spherewaters")
	  else terrain_fx "deep_water"
	  	("spawn_spherewaters")
	  }
	}
	{on "explosion"
		{blastwave c4 15 r0 8 r1 15}
		{spawn "ex_water_extra_big" offset 0 0 20}
		{delete}
	}

	{on ground_hit
		{call "_explosion"}
		{call "explosion"}
	}
	{on contact
		{call "_explosion"}
		{call "explosion"}
	}
	{on bullet_hit
		{bullet_detonate}
	}
	{on break_armor
		{call "_explosion"}
		{call "explosion"}
	}
	{on overlap begin
		{if effector "submarine" {ani_play "down" 1} {volumes "precursor" disable all}}
	}
}
{"torpedo_mk46"
	{on "_explosion"
		{spawn "torpedo_mk46_impactor" "missle_foresight" x 
			{spawn "ex_water_maximum"}
			{impulse up 0.1 forward 30 com}
			{delay 0.3 {call "detonate"}}
		}
		{delete}
	}
	{on "explosion" overload
		{spawn "ex_water_maximum" offset 0 0 20}
		{bullet_detonate}
		{stuff_detonate}
	}
	{on spawn
;		{ani_play "move" loop}
;		{delay 7.5 {call "explosion"}}
		{delay 0.04
			{volumes disable all}
			{spawn "torpedo_mk46_carrier" "root" x}
			{delete}		
		}		
	}
}
{"53_65k_torpedo"
	{on "_explosion"
		{spawn "53_65k_torpedo_impactor" "missle_foresight" x 
			{spawn "ex_water_maximum"}
			{impulse up 0.1 forward 30 com}
			{delay 0.5 {call "detonate"}}
		}
		{delete}
	}
	{on "explosion" overload
		{spawn "ex_water_maximum" offset 0 0 20}
		{bullet_detonate}
		{stuff_detonate}
	}
	{on spawn
;		{ani_play "move" loop}
;		{delay 12.3 {call "explosion"}}
		{delay 0.04
			{volumes disable all}
			{spawn "53_65k_torpedo_carrier" "root" x}
			{delete}		
		}

	}
}
{"mk48_torpedo"
	{on "_explosion"
		{spawn "mk48_torpedo_impactor" "missle_foresight" x 
			{spawn "ex_water_maximum"}
			{impulse up 0.1 forward 30 com}
			{delay 0.5 {call "detonate"}}
		}
		{delete}
	}
	{on "explosion" overload
		{spawn "ex_water_maximum" offset 0 0 20}
		{bullet_detonate}
		{stuff_detonate}
	}
	{on spawn
;		{ani_play "move" loop}
;		{delay 14 {call "explosion"}}
		{delay 0.04
			{volumes disable all}
			{spawn "mk48_torpedo_carrier" "root" x}
			{delete}		
		}	
	}
}
{"torpedo_mk46_impactor"
	{on ground_hit overload
	 {if tagged "instant_detonate" {stuff_detonate}
	 else
		  {if terrain_fx "water"
			{spawn "torpedo_mk46" "root" x} {delete}
		  else terrain_fx "shallow_water"
			{spawn "torpedo_mk46" "root" x} {delete}
		  else terrain_fx "deep_water"
			{spawn "torpedo_mk46" "root" x} {delete}
		  else {inherited}
		  }
	 }
	}
}
{"ugmt1_torpedo"
	{on "_explosion"
		{spawn "ugmt1_torpedo_impactor" "missle_foresight" x 
			{spawn "ex_water_maximum"}
			{impulse up 0.1 forward 30 com}
			{delay 0.5 {call "detonate"}}
		}
		{delete}
	}
	{on "explosion" overload
		{spawn "ex_water_maximum" offset 0 0 20}
		{bullet_detonate}
		{stuff_detonate}
	}
	{on spawn
;		{delay 7 {call "explosion"}}
		{delay 0.04
			{volumes disable all}
			{spawn "ugmt1_torpedo_carrier" "root" x}
			{delete}		
		}
	}
}
{"ugmt1_torpedo_impactor"
	{on ground_hit overload
	 {if tagged "instant_detonate" {stuff_detonate}
	 else
	  {if terrain_fx "water"
		{spawn "ugmt1_torpedo" "root" x} {delete}
	  else terrain_fx "shallow_water"
	  	{spawn "ugmt1_torpedo" "root" x} {delete}
	  else terrain_fx "deep_water"
	  	{spawn "ugmt1_torpedo" "root" x} {delete}
	  else {inherited}
	  }
	 }
	}
}
{"lcvp"
	{on "link_weapon" overload
		{if name "mgun1"
			{add_view "flash_gun_big"	"flashbarrel4"	"Foresight4"}
		else name "mgun2"
			{add_view "flash_gun_big"	"flashbarrel5"	"Foresight5"}
		}
	}
}

{"lci(l)"
	{on "open"
		{ani_play "anchor1"}
		{delay 0.8
			{spawn "ex_water_big" "fx_water3"}
		}
		{delay 1.6
			{spawn "ex_water_big" "fx_water1"}
		}
		{delay 1.7
			{spawn "ex_water_big" "fx_water2"}
		}
	}
	{on "close"
		{ani_play "anchor2"}
	}
	{on break
		{if component "body1_1"
			{spawn "car_die_particle"	"fx_body1_1_break1"}
			{spawn "barrel_die"			"fx_body1_1_break2"}
			{spawn "car_die_particle"	"fx_body1_1_break3"}
			{spawn "tank_die"			"fx_body1_1_break4"}
			{spawn "car_die_particle"	"fx_body1_1_break5"}
		else component "body2_1"
			{spawn "car_die_particle"	"fx_body2_1_break1"}
			{spawn "car_die_particle"	"fx_body2_1_break2"}
			{spawn "barrel_die"			"fx_body2_1_break3"}
		else component "body3_1"
			{spawn "barrel_die_big"		"fx_body3_1_break1"}
			{spawn "car_die_particle"	"fx_body3_1_break2"}
			{spawn "car_die_particle"	"fx_body3_1_break3"}
			{spawn "car_die_particle"	"fx_body3_1_break4"}
		else component "body4_1"
			{spawn "tank_die"			"fx_body4_1_break1"}
			{spawn "car_die_particle"	"fx_body4_1_break2"}
			{spawn "car_die_particle"	"fx_body4_1_break3"}
			{spawn "car_die_particle"	"fx_body4_1_break4"}
			{spawn "barrel_die"			"fx_body4_1_break5"}
		else component "body5_1"
			{spawn "tank_die"			"fx_body5_1_break1"}
			{spawn "car_die_particle"	"fx_body5_1_break2"}
			{spawn "car_die_particle"	"fx_body5_1_break3"}
			{spawn "barrel_die"			"fx_body5_1_break4"}
			{spawn "car_die_particle"	"fx_body5_1_break5"}
		else component "body6_1"
			{spawn "tank_die"			"fx_body6_1_break1"}
			{spawn "car_die_particle"	"fx_body6_1_break2"}
			{spawn "car_die_particle"	"fx_body6_1_break3"}
		else component "body7_1"
			{spawn "tank_die"			"fx_body7_1_break1"}
			{spawn "car_die_particle"	"fx_body7_1_break2"}
			{spawn "car_die_particle"	"fx_body7_1_break3"}
			{spawn "barrel_die"			"fx_body7_1_break4"}
			{spawn "car_die_particle"	"fx_body7_1_break5"}
			{spawn "barrel_die_big"		"fx_body7_1_break6"}
		else component "body8_1"
			{spawn "car_die_particle"	"fx_body8_1_break1"}
			{spawn "tank_die"			"fx_body8_1_break2"}
			{spawn "car_die_particle"	"fx_body8_1_break3"}
		else component "body9_1"
			{spawn "car_die_particle"	"fx_body9_1_break1"}
			{spawn "barrel_die"			"fx_body9_1_break2"}
			{spawn "car_die_particle"	"fx_body9_1_break3"}
			{spawn "barrel_die_big"		"fx_body9_1_break4"}
			{spawn "tank_die"       	"fx_body9_1_break5"}
			{spawn "car_die_particle"	"fx_body9_1_break6"}
		else component "body10_1"
			{spawn "barrel_die_big"	    "fx_body10_1_break1"}
			{spawn "car_die_particle"	"fx_body10_1_break2"}
			{spawn "wood_hit_small"  	"fx_body10_1_break3"}
			{spawn "wood_hit_small"	    "fx_body10_1_break4"}
			{spawn "wood_hit_big"	    "fx_body10_1_break5"}
			{spawn "car_die_particle"	"fx_body10_1_break6"}
			{spawn "barrel_die_big"	    "fx_body10_1_break7"}
			{delay 1.3 {spawn "ex_water_big"	"fx_body10_1_water1"}}
		else component "body11_1"
			{spawn "car_die_particle"	"fx_body11_1_break1"}
			{spawn "tank_die"			"fx_body11_1_break2"}
			{spawn "car_die_particle"	"fx_body11_1_break3"}
			{spawn "barrel_die" 	    "fx_body11_1_break4"}
			{spawn "barrel_die_big"		"fx_body11_1_break5"}
			{spawn "car_die_particle"	"fx_body11_1_break6"}
			{delay 1.5 {spawn "ex_water_big"	"fx_body11_1_water1"}}
			{delay 1.5 {spawn "ex_water_big"	"fx_body11_1_water2"}}
			{delay 1.5 {spawn "ex_water_big"	"fx_body11_1_water3"}}
		else component "body12_1"
			{spawn "car_die_particle"	"fx_body12_1_break1"}
			{spawn "barrel_die"			"fx_body12_1_break2"}
			{spawn "car_die_particle"	"fx_body12_1_break3"}
			{spawn "tank_die"			"fx_body12_1_break4"}
			{spawn "barrel_die_big" 	"fx_body12_1_break5"}
		else component "body13_1"
			{spawn "car_die_particle"	"fx_body13_1_break1"}
			{spawn "wood_hit_small"		"fx_body13_1_break2"}
			{spawn "car_die_particle"	"fx_body13_1_break3"}
			{spawn "tank_die"			"fx_body13_1_break4"}
			{spawn "barrel_die_big" 	"fx_body13_1_break5"}
			{spawn "car_die_particle"	"fx_body13_1_break6"}
			{spawn "tank_die"			"fx_body13_1_break7"}
			{spawn "car_die_particle"	"fx_body13_1_break8"}
			{spawn "tank_die"	        "fx_body13_1_break9"}
			{spawn "barrel_die_big"	    "fx_body13_1_break10"}
			{delay 1 {spawn "ex_water_big"	"fx_body13_1_water1"}}
			{delay 1 {spawn "ex_water_big"	"fx_body13_1_water2"}}
			{delay 1 {spawn "ex_water_big"	"fx_body13_1_water3"}}
		else component "body14_1"
			{spawn "car_die_particle"	"fx_body14_1_break1"}
			{spawn "tank_die"			"fx_body14_1_break2"}
			{spawn "barrel_die_big" 	"fx_body14_1_break3"}
			{spawn "car_die_particle"	"fx_body14_1_break4"}
		else component "body15_1"
			{spawn "car_die_particle"	"fx_body15_1_break1"}
			{spawn "barrel_die_big"		"fx_body15_1_break2"}
			{spawn "tank_die"	        "fx_body15_1_break3"}
			{spawn "car_die_particle"	"fx_body15_1_break4"}
			{spawn "barrel_die"			"fx_body15_1_break5"}
			{spawn "barrel_die_big" 	"fx_body15_1_break6"}
			{spawn "barrel_die" 	    "fx_body15_1_break7"}
		else component "body16_1"
			{spawn "barrel_die"      	"fx_body16_1_break1"}
			{spawn "barrel_die_big"		"fx_body16_1_break2"}
			{spawn "car_die_particle"	"fx_body16_1_break3"}
			{spawn "car_die_particle"	"fx_body16_1_break4"}
			{spawn "tank_die"			"fx_body16_1_break5"}
		else component "body17_1"
			{spawn "barrel_die"     	"fx_body17_1_break1"}
			{spawn "barrel_die_big"		"fx_body17_1_break2"}
			{spawn "car_die_particle"	"fx_body17_1_break3"}
			{spawn "car_die_particle"	"fx_body17_1_break4"}
		else component "body18_1"
			{spawn "barrel_die_big" 	"fx_body18_1_break1"}
			{spawn "tank_die"			"fx_body18_1_break2"}
			{spawn "barrel_die"     	"fx_body18_1_break3"}
			{spawn "car_die_particle"	"fx_body18_1_break4"}
		else component "body19_1"
			{spawn "barrel_die_big" 	"fx_body19_1_break1"}
			{spawn "barrel_die_big"		"fx_body19_1_break2"}
			{spawn "car_die_particle"	"fx_body19_1_break3"}
			{spawn "tank_die"			"fx_body19_1_break4"}
			{spawn "car_die_particle"	"fx_body19_1_break4"}
		else component "body20_1"
			{spawn "barrel_die_big" 	"fx_body20_1_break1"}
			{spawn "car_die_particle"	"fx_body20_1_break2"}
			{spawn "barrel_die_big" 	"fx_body20_1_break3"}
			{spawn "barrel_die"     	"fx_body20_1_break4"}
			{spawn "tank_die"			"fx_body20_1_break5"}
			{spawn "car_die_particle"	"fx_body20_1_break6"}
		else component "body21_1"
			{spawn "barrel_die_big" 	"fx_body21_1_break1"}
			{spawn "car_die_particle"	"fx_body21_1_break2"}
			{spawn "barrel_die_big" 	"fx_body21_1_break3"}
			{spawn "car_die_particle"	"fx_body21_1_break4"}
			{spawn "tank_die"			"fx_body21_1_break5"}
			{delay 1.3 {spawn "ex_water_big"	"fx_body21_1_water1"}}
			{delay 1.3 {spawn "ex_water_big"	"fx_body21_1_water2"}}
			{delay 1.3 {spawn "ex_water_big"	"fx_body21_1_water3"}}
		}
	}
}

{"armor_barge"
	{on break
		{call "check_explosion"}
	}
	{on "check_explosion"
		; check 3 of 7 bodies broken (1,2,3,4,5,7,8)
		{set "broken_1" 0}
		{set "broken_2" 0}
		{set "broken_3" 0}
		{if broken "body_1" {call "inc_broken"}}
		{if broken "body_2" {call "inc_broken"}}
		{if broken "body_3" {call "inc_broken"}}
		{if broken "body_4" {call "inc_broken"}}
		{if broken "body_5" {call "inc_broken"}}
		{if broken "body_7" {call "inc_broken"}}
		{if broken "body_8" {call "inc_broken"}}
		{if flag "broken_3"
			{call "explosion"}
		}
	}
	{on "inc_broken"
		{if not flag "broken_1"
			{set "broken_1" 1}
		else not flag "broken_2"
			{set "broken_2" 1}
		else not flag "broken_3"
			{set "broken_3" 1}
		}
	}
	{on "explosion"
		{delay 3
			{call "break_float"}
		}
	}
}

{"armor_barge ger"
	{on break
		{if component "body_1"
			{spawn "marine_die"     	"fX_body_1_break01"}
			{spawn "barrel_die"			"fX_body_1_break02"}
			{with_linked_entity "sand1"		{call "stage2"}}
			{with_linked_entity "sand3"		{call "stage2"}}
			{with_linked_entity "sand14"	{call "stage2"}}
			{with_linked_entity "lamp26"	{delete}}
			{with_linked_entity "rear1"		{delete}}
		else component "body_2"
			{spawn "marine_die"     	"fX_body_2_break01"}
			{spawn "train_die"      	"fX_body_2_break02"}
			{with_linked_entity "side1"		{call "explosion_delete"}}
			{with_linked_entity "sand2"		{call "stage2"}}
			{with_linked_entity "sand17"	{call "stage2"}}
			{with_linked_entity "lamp24"	{delete}}
			{with_linked_entity "lamp27"	{delete}}
			{with_linked_entity "front"		{call "explosion_delete"}}
		else component "body_3"
			{spawn "marine_die"      	"fX_body_3_break01"}
			{spawn "car_die_particle"	"fX_body_3_break02"}
			{spawn "barrel_die"			"fX_body_3_break03"}
			{with_linked_entity "back"		{call "explosion_delete"}}
			{with_linked_entity "sand7"		{call "stage2"}}
			{with_linked_entity "sand8"		{call "stage2"}}
			{with_linked_entity "lamp23"	{delete}}
		else component "body_4"
			{spawn "tank_die"	        "fX_body_4_break01"}
			{spawn "marine_die"     	"fX_body_4_break02"}
			{spawn "barrel_die"			"fX_body_4_break03"}
		else component "body_5"
			{spawn "marine_die"	        "fX_body_5_break01"}
			{spawn "tank_die"        	"fX_body_5_break02"}
			{with_linked_entity "rear3"		{delete}}
			{with_linked_entity "sand11"	{call "stage2"}}
			{with_linked_entity "sand12"	{call "stage2"}}
		else component "body_7"                  
			{spawn "train_die"	        "fX_body_7_break01"}
			{spawn "platform_par1"	    "fX_body_7_break02"}
			{spawn "marine_die"      	"fX_body_7_break03"}
			{spawn "car_die_particle"   "fX_body_7_break04"}
			{with_linked_entity "back"		{call "explosion_delete"}}
			{with_linked_entity "sand9"		{call "stage2"}}
			{with_linked_entity "sand10"	{call "stage2"}}
			{with_linked_entity "lamp19"	{delete}}
		else component "body_8"
			{spawn "car_die_particle"	"fX_body_8_break01"}
			{spawn "marine_die"     	"fX_body_8_break02"}
			{spawn "tank_die"	        "fX_body_8_break03"}
			{spawn "barrel_die"	        "fX_body_8_break04"}
			{spawn "platform_par1"	    "fX_body_8_break05"}
			{with_linked_entity "front"		{call "explosion_delete"}}
			{with_linked_entity "rear2"		{delete}}
			{with_linked_entity "side2"		{call "explosion_delete"}}
			{with_linked_entity "sand4"		{call "stage2"}}
			{with_linked_entity "sand5"		{call "stage2"}}
			{with_linked_entity "sand6"		{call "stage2"}}
			{with_linked_entity "sand15"	{call "stage2"}}
			{with_linked_entity "sand16"	{call "stage2"}}
			{with_linked_entity "sand18"	{call "stage2"}}
			{with_linked_entity "lamp20"	{delete}}
			{with_linked_entity "lamp21"	{delete}}
			{with_linked_entity "lamp22"	{delete}}
		else component "cabin"
			{spawn "marine_die"	        "fX_cabin_break01"}
			{spawn "train_die"	        "fX_cabin_break02"}
			{with_linked_entity "lamp25"	{delete}}
		}
	}
}

{"armor_barge eng"
	{on break
		{if component "body_1"
			{spawn "marine_die"     	"fX_body_1_break01"}
			{spawn "barrel_die"			"fX_body_1_break02"}
			{with_linked_entity "sand1"		{call "stage2"}}
			{with_linked_entity "sand3"		{call "stage2"}}
			{with_linked_entity "sand14"	{call "stage2"}}
			{with_linked_entity "lamp26"	{delete}}
			{with_linked_entity "rear1"		{delete}}
		else component "body_2"
			{spawn "marine_die"     	"fX_body_2_break01"}
			{spawn "train_die"      	"fX_body_2_break02"}
			{with_linked_entity "side1"		{call "explosion_delete"}}
			{with_linked_entity "sand2"		{call "stage2"}}
			{with_linked_entity "sand17"	{call "stage2"}}
			{with_linked_entity "lamp24"	{delete}}
			{with_linked_entity "lamp27"	{delete}}
			{with_linked_entity "front"		{call "explosion_delete"}}
		else component "body_3"
			{spawn "marine_die"      	"fX_body_3_break01"}
			{spawn "car_die_particle"	"fX_body_3_break02"}
			{spawn "barrel_die"			"fX_body_3_break03"}
			{with_linked_entity "back"		{call "explosion_delete"}}
			{with_linked_entity "sand7"		{call "stage2"}}
			{with_linked_entity "sand8"		{call "stage2"}}
			{with_linked_entity "lamp23"	{delete}}
		else component "body_4"
			{spawn "tank_die"	        "fX_body_4_break01"}
			{spawn "marine_die"     	"fX_body_4_break02"}
			{spawn "barrel_die"			"fX_body_4_break03"}
		else component "body_5"
			{spawn "marine_die"	        "fX_body_5_break01"}
			{spawn "tank_die"        	"fX_body_5_break02"}
			{with_linked_entity "rear3"		{delete}}
			{with_linked_entity "sand11"	{call "stage2"}}
			{with_linked_entity "sand12"	{call "stage2"}}
		else component "body_7"                  
			{spawn "train_die"	        "fX_body_7_break01"}
			{spawn "platform_par1"	    "fX_body_7_break02"}
			{spawn "marine_die"      	"fX_body_7_break03"}
			{spawn "car_die_particle"   "fX_body_7_break04"}
			{with_linked_entity "back"		{call "explosion_delete"}}
			{with_linked_entity "sand9"		{call "stage2"}}
			{with_linked_entity "sand10"	{call "stage2"}}
			{with_linked_entity "lamp19"	{delete}}
		else component "body_8"
			{spawn "car_die_particle"	"fX_body_8_break01"}
			{spawn "marine_die"     	"fX_body_8_break02"}
			{spawn "tank_die"	        "fX_body_8_break03"}
			{spawn "barrel_die"	        "fX_body_8_break04"}
			{spawn "platform_par1"	    "fX_body_8_break05"}
			{with_linked_entity "front"		{call "explosion_delete"}}
			{with_linked_entity "rear2"		{delete}}
			{with_linked_entity "side2"		{call "explosion_delete"}}
			{with_linked_entity "sand4"		{call "stage2"}}
			{with_linked_entity "sand5"		{call "stage2"}}
			{with_linked_entity "sand6"		{call "stage2"}}
			{with_linked_entity "sand15"	{call "stage2"}}
			{with_linked_entity "sand16"	{call "stage2"}}
			{with_linked_entity "sand18"	{call "stage2"}}
			{with_linked_entity "lamp20"	{delete}}
			{with_linked_entity "lamp21"	{delete}}
			{with_linked_entity "lamp22"	{delete}}
		else component "cabin"
			{spawn "marine_die"	        "fX_cabin_break01"}
			{spawn "train_die"	        "fX_cabin_break02"}
			{with_linked_entity "lamp25"	{delete}}
		}
	}
}

{"barge_industrial"
	{on break
		{if component "body_9"
			{spawn "marine_die"     	"fX_body_9_break01"}
			{spawn "tank_die"	        "fX_body_9_break02"}
		else component "body_10"
			{spawn "marine_die"     	"fX_body_10_break01"}
			{spawn "tank_die"	        "fX_body_10_break02"}
		}
		{call "check_explosion1"}
	}
	{on "check_explosion1"
		{if broken "body_4"
			{delay 1 0.3
				{call "explosion"}
			}
		else broken "body_10"
			{delay 1 0.3
				{call "explosion"}
			}
		}
	}
}

{"adn_destroyer"
	{on "contact_airborne" overload}
	{on "explosion_sequence" overload}
	{on "break_front"
		{if broken "body10"
			{if broken "body9"
				{if broken "body8"
					{tags add "broken_front"}
					("body_break_fx" args front)
				}
			}
		}
	}
	{on "break_center"
		{if broken "body6"
			{if broken "body5"
				{if broken "body4"
					{if broken "body3"
						{tags add "broken_center"}
						("body_break_fx" args center)
					}
				}
			}
		}
	}
	{on "break_rear"
		{if broken "body7"
			{if broken "body11"
				{tags add "broken_rear"}
				("body_break_fx" args rear)
			}
		}
	}
	{on break
		{if component "body8" {call "break_front"}}
		{if component "body9" {call "break_front"}}
		{if component "body10" {call "break_front"}}
		{if component "body3" {call "break_center"}}
		{if component "body4" {call "break_center"}}
		{if component "body5" {call "break_center"}}
		{if component "body6" {call "break_center"}}
		{if component "body7" {call "break_rear"}}
		{if component "body11" {call "break_rear"}}
	}
	{on "sink"
		{components "body" break}
		{chassis_work 0}
		{ani_stop "drift"}
		{ani_play "sink" 0.1}
	}
}

{"coaster_ship"
	{on break
		{if component "body"
			{for_each_link
				{delay_effect 1 0.5 "break"}
			}
		}
	}
}

{"pantoon_bridge wood"
	{on "effects"
		{spawn "wood_hit_fg" "body" z}
	}
}