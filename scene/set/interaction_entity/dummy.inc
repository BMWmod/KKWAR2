{"dummy"
	{on "stop"	{view stop ""}}
	{on "pause"	{view pause ""}}
	{on "delete"{delete}}
}

{"ps_dummy"
	{on "delete"{hide 3}}
}

{"gilza" 
	{on spawn
		{delay 20 2.5
			{hide 3}
		}
	}
}
{"gilza big" 
	{on spawn
		{add_view "smoke_zenit" "smoke_shell" "fx_shellsmoke"}
		{view start "smoke_shell"}
		{delay_effect 3 1 "stop"}
	}
}

{"physics_damping"
;	{friction 1000}
;	{restitution 0.001}
}

(define "throwing_weapon"
	{on contact
		{if effector "human"
			{delay 0
				{constrain_velocity 1}
			}
		}
	}
	{on "onThrow"
	    {tags add "throwed"}
	}
)

{"knife" ("throwing_weapon")}
{"axe" ("throwing_weapon")}
{"soldiers_flashlight"
	{on "light_on"
		{if not sunlight
			{view start "light"}
			{view show "light"}
		else
			{view stop "light"}
			{view hide "light"}
		}
	}
	{on "light_off"
		{if not sunlight
			{view hide "light"}
			{bone cut "fx_light"}
		}
	}
	{on spawn
		{add_view 	"soldier_headlight"	"light"		"fx_light"}
		{add_view 	"light_vehicle"		"light"		"fx_light"}
		{delay 0.1
			{call "light_on"}
		}
	}
	{on bullet_hit
		{call "light_off"}
	}
}
{"detect_throwing"
	;{on "onThrow"
	;}
}

{"warehouse"
	{on spawn
		{volumes disable all}
		{volumes enable contact obstacle}
	}
	{on contact
		{if effector "vehicle"
		else effector "human"
		else
		}
	}
}

{"mwp_weather"
	{on spawn
		{add_view "winter_test_slow" "weather1" "basis"}
		{add_view "winter_test" "weather2" "basis"}
	}
	{on "on_snow"
		{if not flag "snow1" and not flag "snow2" 
			{view start "weather1"}
			{set "snow1" 1}
			{tags add "snow1"}
		else flag "snow1" and not flag "snow2"
			{view stop "weather1"}
			{view start "weather2"}
			{set "snow2" 1}
			{tags add "snow2"}
		else flag "snow2" and flag "snow1"
			{view stop "weather2"}
			{view start "weather1"}
			{set "snow1" 0}
			{tags add "snow3"}
		else flag "snow2" and not flag "snow1"	
			{view stop "weather1"}	
			{set "snow2" 0}	
			{tags remove "snow3"}
			{tags remove "snow2"}
			{tags remove "snow1"}
		}
	}
}

{"stone"
	{on bullet_hit
		{bullet_detonate}
	(include "/lists/glide_bomb.inc")
		(define "proj_point_spawn_distributor"
			{with_effector
				;{with_effector 
					{if tagged "launch_00" 
						{spawn "proj_point_%bomb_gps_ground_00" ("proj_point_settings")}
					else tagged "launch_01" 
						{spawn "proj_point_%bomb_gps_ground_01" ("proj_point_settings")}
					else tagged "launch_02" 
						{spawn "proj_point_%bomb_gps_ground_02" ("proj_point_settings")}
					else tagged "launch_03" 
						{spawn "proj_point_%bomb_gps_ground_03" ("proj_point_settings")}
					else tagged "launch_04" 
						{spawn "proj_point_%bomb_gps_ground_04" ("proj_point_settings")}
					else tagged "launch_05" 
						{spawn "proj_point_%bomb_gps_ground_05" ("proj_point_settings")}
					else tagged "launch_06" 
						{spawn "proj_point_%bomb_gps_ground_06" ("proj_point_settings")}
					else tagged "launch_07" 
						{spawn "proj_point_%bomb_gps_ground_07" ("proj_point_settings")}
					else tagged "launch_08" 
						{spawn "proj_point_%bomb_gps_ground_08"("proj_point_settings")}
					else tagged "launch_09" 
						{spawn "proj_point_%bomb_gps_ground_09" ("proj_point_settings")}
					else tagged "launch_10" 
						{spawn "proj_point_%bomb_gps_ground_10" ("proj_point_settings")}
					else tagged "launch_11" 
						{spawn "proj_point_%bomb_gps_ground_11" ("proj_point_settings")}
					else tagged "launch_12" 
						{spawn "proj_point_%bomb_gps_ground_12" ("proj_point_settings")}
					else tagged "launch_13" 
						{spawn "proj_point_%bomb_gps_ground_13" ("proj_point_settings")}
					else tagged "launch_14" 
						{spawn "proj_point_%bomb_gps_ground_14" ("proj_point_settings")}
					else tagged "launch_15" 
						{spawn "proj_point_%bomb_gps_ground_15" ("proj_point_settings")}	
					}
				;}
			} 
		)
		(define "proj_point_settings"
			offset 0 0 0 
			{tags add "gps_target"} 
			{tags add "cwps_ground_attack"} 
			(mod "mp"{player 1}) 
			(mod not "mp"{player 7}) 
			{delay 25 {delete}}
		)
		{if stuff "light"	;to avoid fx from binoculars
			("list_glide_bomb_inc")
		}
	}
}

{"part"
	{on "check_delete_part" ; called only inside tear, so with_effector swaps entity&effector for flag check
		{with_effector
			{if flag "delete_parts"
				{with_effector
					{delay 20
						{hide 3}
					}
				}
			}
		}
	}
}

{"flesh part"
	{on blast  {spawn "bloodsparks_small"}}
	{on bullet_hit {spawn "bloodsparks_small"}}
	{on contact
		{spawn "bloodsparks_small"}
	}
	{on ground_hit
		{if min_speed 10
			{spawn "bloodsparks_small"}
		}
	}
}
{"piece_small_detonation"
	{on spawn 
		{if rand 0.5
			{start_sound "weapon/shot/traces"}
		else rand 0.15
			{start_sound "hit/big/metal_recochet"}
		else rand 0.4
			{start_sound "detonation/hit_big/hit_big_medium"}
		else
			{start_sound "detonation/hit_small/hit_small"}
		}
	}
}
{"small part"
	{on spawn
;		{con "spawn small part"}
		{delay 0.1
			{volumes disable bullet contact blast touch}	;prevent destroing at spawn moment
		}
		{delay 2 {volumes enable bullet contact blast}}
		{call "stop_view"}
		{delay 25 15 {hide 10}}
	}
	{on blast_hit
;		{con "blast small part"}
		{if min_energy 0.5
			{hide 1}
		else
			{impulse up 3 1 dir 2 1}
		}
	}
	{on bullet_hit
;		{con "bullet small part"}
		{if stuff "bullet"
			{impulse up 2 1 dir 1 0.5}
		else stuff "shell"
			{hide 1}
		}
	}
	{on contact
;		{con "contact small part"}
		{if effector "vehicle"
			{volumes disable bullet contact blast}	;prevent destroing at spawn moment
			{delay 4 1 {hide 2}}
		}
	}
}

{"small part fx"
	{on "stop_view"
		{delay 0.5 0.3 {view stop ""}}
	}
}

{"medium part"
;	{friction 2}
;	{restitution 0.2}
	{on spawn
		{delay 0.1
			{volumes disable bullet contact blast touch}	;prevent destroing at spawn moment
		}
		{delay 2 {volumes enable bullet contact blast}}
	}
	{on blast_hit
		{if min_energy 1.0
			{hide 1}
		else
			{impulse up 1 1 dir 2 1}
		}
	}
	{on bullet_hit
		{if stuff "bullet"
			{impulse up 0.5 0.5 dir 0.5 0.5}
		else stuff "shell"
			{hide 1}		
		}
	}
	{on contact
		{impulse up 0.1 0.1 dir 0.1 0.1}
	}
}
{"wheel_part"
	{on spawn
		{delay 0.1
			{volumes "body" disable all}
			{volumes disable bullet contact blast touch}	;prevent destroing at spawn moment
		}
		{delay 2 {volumes "body1" enable bullet contact blast}}
	}
	{on blast_hit
		{if min_energy 8 
			{impulse up 5 1 dir 5 1}
		  else min_energy 1.5
			{impulse up 1 0.3 dir 1 0.5}
		}
	}
	{on bullet_hit
		{if stuff "big shell extra"
			{impulse up 5 1 dir 5 1}
		 else stuff "shell"
			{impulse up 1 0.3 dir 1 0.5}
		 else stuff "zenite"
			{impulse up 0.2 0.1 dir 0.1 0.05}
		}
	}
	{on contact
		{impulse up 0.1 0.1 dir 0.1 0.1}
	}
}
{"big part"
	{on spawn
		{delay 0.1
			{volumes disable touch}
		}
	}
	{on blast_hit
		{if min_energy 8 
			{impulse up 5 1 dir 5 1}
		  else min_energy 0.5
			{impulse up 1 0.3 dir 1 0.5}
		}
	}
	{on bullet_hit
		{if stuff "big shell extra"
			{impulse up 5 1 dir 5 1}
		 else stuff "shell"
			{impulse up 1 0.3 dir 1 0.5}
		 else stuff "zenite"
			{impulse up 0.2 0.1 dir 0.1 0.05}
		}
	}
}

{"big part delete"
	{on spawn
		{delay 20
			{delete}
		}
	}
}

{"wood part"
	{on spawn
		{delay 2
			{volumes enable float}
		}
	}
;	{on ground_hit
;		{if terrain "water"
;			{call "kick"}
;		else terrain "deep_water"
;			{call "kick"}
;		}
;	}
;	{on "kick"
;		{delay 15
;			{kill_delay "kick_process"}
;		}
;		{call "kick_process"}
;	}
;	{on "kick_process"
;		{delay 0.3 0.1 "kick_process"
;			{impulse up 1}
;			{call "kick_process"}
;		}
;	}
}
{"fog_open_point_tailed"
	{on spawn
		{tags add "zonehit"}
		{delay 2 {delete}}
	}
}
{"fx_piece_flame"
	{on spawn
		{setup_stuff_activator}
		{call "start"}
		{delay 0.6 0.4 {delete}}
;		{delay 0.5 {impulse rnd_dir 0.5}}
	}
	{on "start"
		{volumes "body" disable contact}
		;{gravity 30}
		{gravity 10}
		{delay 0
			{add_view "fire_flame_thrower_fly" "fire1" "root"}
			{view start "fire1"}
		}
		{delay 0.2
			{add_view "fire_flame_thrower_fly4" "fire2" "root"}
			{view start "fire2"}
		}
		{delay 0.3
			{add_view "fire_flame_thrower_fly5" "fire" "root"}
			{view start "fire"}
		}
		{delay 0.05
			{volumes "body" enable contact}
			{fire radius 0.5 time 2 heating 1 follow}
		}
;		{delay 0.2
;			{fire radius 0.5 time 0.5 heating 0.5 follow}
;		}
;		{delay 0.5
;			{call "end"}
;		}
	}
	{on contact
		{volumes disable contact}
		{call "end_object"}
	}
	{on ground_hit
		{view stop "fire1"}
		{view stop "fire2"}
		{delay 0.1
			{call "end"}
		}
	}
	{on "end_object"
		{if rand 0.2
			{spawn "fire_die"}
		}
		{call "end"}
	}
	{on "ineffective_range"
		{view stop "fire1"}{view stop "fire0"}
		{view stop "fire2"}
		{view stop "fire"}
		{delete}
	}
	{on "end"
			{fire radius 1 time 1 heating 0.3}
			{fire radius 3 time 0.3 heating 0.2}
			
			{if not air
				{if not under_water
					{spawn "fire_flame_thrower" dir_velocity}
					{if rand 0.05
						{spawn "fx_piece_flame_end"}
					}
				}
			}
		{delete}
	}
}
{"fx_piece_phosphor"
	{on spawn
		{setup_stuff_activator}
		{volumes "body" disable contact}
		{gravity 7}
		{delay 0.05
			{volumes "body" enable contact}
		}
		{delay 0.4 {gravity 10}}
	}
	{on contact
		{volumes disable contact}
		{call "end"}
	}
	{on ground_hit
		{call "end"}
	}
	{on "ineffective_range"
	}
	{on "end"
		{setup_stuff_activator}
		{fire radius 2 time 2 heating 0.5}
		{if not under_water
			{spawn "smoke_ph" dir_velocity}
		}
		{delete}
	}
}

{"fx_sphere_ph"
	{on spawn overload
		{setup_stuff_activator}
		{physics_work 0}
		{delay 0.1 {delete}}
	}
}

{"aoe_heal_med"
	{on spawn overload
		{physics_work 0}
		{delay 0.15 {delete}}
	}
}
{"fx_sphere_ph_cas"
	{on spawn overload
		{setup_stuff_activator}
		{physics_work 0}
		{delay 0.1 {delete}}
	}
}
{"fx_detonation_flame"
	{on spawn overload
		{setup_stuff_activator}
		{physics_work 0}
		{delay 0.1 {delete}}
	}
}
{"smoke_gen"
	{on spawn overload
		{physics_work 0}
;		{delay 0.25 {tags add "stage_1"}}
		{delay 0.1 {delete}}
;		{delay 16 4 {delete}}
	}
	{on contact overload
;		{if effector "smoke_gen"
;			{if tagged "block"
;			else not tagged "stage_1"
;				{tags add "stage_1"}{spawn "smoke_on_map_from_exp"}{tags add "block"}{delay 1 {tags remove "block"}}
;			else not tagged "stage_2"
;				{tags add "stage_2"}{delay 0.1 {delete}}
;			else
;			}
;		else 
;		}
	}	
}

{"storm_botter"
	{on spawn overload
		{physics_work 0}
		{delay 0.1 {delete}{spawn "storm_botter_stack" "basis"}}
	}
	{on contact overload
		{if effector "storm_botter"
		else effector "storm_botter_stack"
			{delete}
		else 
		}
	}	
}

{"storm_botter_inter"
	{on spawn overload
		{physics_work 0}
		{delay 5 {delete}}
	}
	{on contact overload
		{if effector "storm_botter"
			{spawn "ex_molot_storm" "basis"}{fire radius 6 time 3 heating 6}{delete}
		else effector "storm_botter_stack"
			{spawn "ex_molot_storm" "basis"}{fire radius 6 time 3 heating 6}{delete}
		else 
		}
	}	
}

{"storm_botter_stack"
	{on spawn overload
		{setup_stuff_activator}
		{physics_work 0}
		{delay 7.5 {delete}}
	}
	{on contact overload
		{if effector "storm_botter"
			{if not tagged "stage_1"
				{tags add "stage_1"}
			else
				{call "detonate"}
			}
		else effector "storm_botter_stack"
			{delete}{spawn "storm_botter_inter" "basis"}
		else
		}
	}
	{on "detonate" overload
		{setup_stuff_activator}
		{spawn "ex_molot_storm" "basis"}{fire radius 6 time 3 heating 6}{delete}
	}	
}
{"flora_shak_min"
	{on spawn overload
		{physics_work 0}
		{blastwave c4 0.01 r0 10 r1 15}
		{delete}
	}	
}


{"fx_mine_ap"
	{on spawn
		{volumes "body" enable contact}
		{delay 5{delete}}	
		{gravity 25}
	}
	{on ground_hit
		{call "end"}
	}
	{on "end"
		{spawn "mine_antipersonnel"}{delete}
	}
}
{"fx_piece_flame_end"
	{on spawn
		{add_view "fire_flame_thrower_light" "light" "root"}
		{view start "light"}
		{delay 7
			{delete}
		}
	}
}
{"fire_molot_piece"
	{on spawn
		{fire radius 0.5 time 1 heating 1}
		{delay 1
			{delete}
		}
	}
}
{"napalm"
	{on "start"
		{setup_stuff_activator}
		{add_view "fire_napalm" "flame" "root"}
		{view start "flame"}
		{fire radius 2 time 1000000 heating 70 follow}
	}
	{on "end"
		{delete}
	}
}

{"fx_piece_phosphorus"
	{on "start" overload
		{setup_stuff_activator}
		{volumes "body" disable contact}
		{gravity 10}
		{delay 10 3 {delete}}
	}
	{on "end" overload
			{fire radius 2 time 5 heating 0.2}
			{fire radius 0.5 time 3 heating 0.3}
			
			{if not air
				{if not under_water
					{spawn "fire_phosphorus" dir_velocity}
				}
			}
		{delete}
	}
}

{## "tagged_piece"
	{on spawn
		{tags add "isu_fire"}
		{delay 25
			{delete}
		}
	}
}
{"sp_convoy_assistor"
	(define "spawn_tp"
		{spawn "tagged_piece" "r%n"
		{tags add "sp_ambush_marker"}{tags add "sp_ambush_right"} {delay 60 {delete}}}
		{spawn "tagged_piece" "ra%n"
		{tags add "sp_ambush_marker"}{tags add "sp_ambush_righta"} {delay 60 {delete}}}
		{spawn "tagged_piece" "l%n"
		{tags add "sp_ambush_marker"}{tags add "sp_ambush_left"} {delay 60 {delete}}}
		{spawn "tagged_piece" "la%n"
		{tags add "sp_ambush_marker"}{tags add "sp_ambush_lefta"} {delay 60 {delete}}}
	)
	{on spawn
		{delay 3
			{delete}
		}
		("spawn_tp" n(000))
		("spawn_tp" n(001))
		("spawn_tp" n(002))
		("spawn_tp" n(003))
		("spawn_tp" n(004))
		("spawn_tp" n(005))
		("spawn_tp" n(006))
		("spawn_tp" n(007))
		("spawn_tp" n(008))
	}
}
{"inventory_box"
	{on "break"
;		{explode_inventory
;			{5			"ex_arm_sm"		3	}
;			{30			"ex_anti_big"	8	}
;			{100		"ex_bomb_big"	11	}
;			{1000		"train_die"		15	}
;			{10000		"train_die"		20	}
;			{100000		"train_die"		25	}
;			{1000000	"train_die"		30	}
;		}
;explosive_amount counts like shell mass, but we need HE mass
		{if explosive_amount 50000
			{spawn "cw_explosion_5000kg"}
		else explosive_amount 10000
			{spawn "cw_explosion_1000kg"}
		else explosive_amount 2000
			{spawn "cw_explosion_200kg"}
		else explosive_amount 500
			{spawn "cw_explosion_50kg"}
		else explosive_amount 100
			{spawn "cw_explosion_10kg"}
		else explosive_amount 40	;shells - HE ratio about 0.1 (ap) - 0.2 (HE)
			{spawn "cw_explosion_4kg"}
		else explosive_amount 12	;mines - HE ratio about 0.2
			{spawn "cw_explosion_2kg"}
		else explosive_amount 5		;grenades - HE ratio about 0.2
			{spawn "cw_explosion_1kg"}
		else explosive_amount 2.5		;grenades - HE ratio about 0.2
			{spawn "cw_explosion_0_5kg"}
		}
	}
}
{"box_weapon_mp"
	{on spawn
		{delay 1 {call "check_explosive_amount"}}
	}
	{on "check_explosive_amount"
	    {delay 3 {call "check_explosive_amount"}}
	    {if not explosive_amount 0 
	    	{delete}  	
	    }
	}
}

{"inventory_box_actor"
	{on blast_hit
		{if min_energy 2 
			{call "explosion"}
		}
	}
	{on "explosion"
		{if explosive_amount 50000
			{spawn "cw_explosion_5000kg"}
		else explosive_amount 10000
			{spawn "cw_explosion_1000kg"}
		else explosive_amount 2000
			{spawn "cw_explosion_200kg"}
		else explosive_amount 500
			{spawn "cw_explosion_50kg"}
		else explosive_amount 100
			{spawn "cw_explosion_10kg"}
		else explosive_amount 40	;shells - HE ratio about 0.1 (ap) - 0.2 (HE)
			{spawn "cw_explosion_4kg"}
		else explosive_amount 12	;mines - HE ratio about 0.2
			{spawn "cw_explosion_2kg"}
		else explosive_amount 5		;grenades - HE ratio about 0.2
			{spawn "cw_explosion_1kg"}
		else explosive_amount 2.5		;grenades - HE ratio about 0.2
			{spawn "cw_explosion_0_5kg"}
		}
		{spawn "wood_hit_big"}
		{delete}
	}
}
{"flag"
	{on spawn
		{call "start"}
		{if tagged "disputed_zone_hide"
			{call "call_spawn_pointer"}
			{volumes disable all}
			{bone hide "flag_point"}
		}
	}
	{on "call_spawn_pointer"
		{if tagged "actual_a"
			{spawn "scout_02"}
		}
	}
	{on "stop"
		{ani_stop "flattern"}
		{ani_play "stop"}
	}
	{on "start"
		{ani_play "flattern" loop}
	}
}

{"flag captureable"
	{on "capture"
		{if tex_mod "1"
			{ani_play "up" resume callback}
		else
			{ani_play "down" resume callback}
		}
	}
	{on "cancel"
		{set "stop" 1}
		{ani_stop "up"}
		{ani_stop "down"}
		{set "stop" 0}
	}
	{on "enable"
		{volumes "activate" enable contact}
	}
	{on "disable"
		{volumes "activate" disable contact}
	}
	{on animation_end "down"
		{if not flag "stop"
			{tex_mod "1"}
			{call "capture"}
		}
	}
	{on animation_end "up"
		{if not flag "stop"
			{tags add "captured"}
		}
	}
}
{"flag flag_point"
	(define "set_tex_mod"
		{on "tex_mod_%0"
			{tex_mod "%0"}
		}
	)
	("set_tex_mod" args ger)
	("set_tex_mod" args rus)
	("set_tex_mod" args usa)
	("set_tex_mod" args jap)
	("set_tex_mod" args eng)
	("set_tex_mod" args cn)
	("set_tex_mod" args nato)
	
	("set_tex_mod" args aus)
	("set_tex_mod" args fra)
	("set_tex_mod" args gbr)
}
{"map_point"
	{on "start"
		{ani_play "rotate" loop}
	}
}


{"starshell"
	{on spawn
		{add_view "starshell_light"	"light" "root"}
		{delay 0.4
			{view start "light"}
		}
		{impulse up 40 fx 10 20 fy 10 20}
		{delay 4 1
			{delete}
		}
	}
}
{"water"
	{on spawn
		{ani_play "wave" loop}
		{add_view "wash_big_flow" "wash" "FX_wash"}
		{add_view "wash_big_flow" "wash" "FX_wash1"}
		{add_view "wash_big_flow" "wash" "FX_wash2"}
		{add_view "wash_big_flow" "wash" "FX_wash3"}
		{add_view "wash_big_flow" "wash" "FX_wash4"}
		{add_view "wash_big_flow" "wash" "FX_wash5"}
		{add_view "wash_big_flow" "wash" "FX_wash6"}
		{add_view "wash_big_flow" "wash" "FX_wash7"}
		{add_view "wash_big_flow" "wash" "FX_wash8"}
		{add_view "wash_big_flow" "wash" "FX_wash9"}
		{view start "wash"}
	}
}

{"water_animation_pingpong"
	{on spawn
		{set "backward" 0}
		{call "animate"}
	}
	{on animation_end "wave"
		{call "animate"}
	}
	{on "animate"
		{if flag "backward"
			{ani_play "wave" -1 callback}
			{set "backward" 0}
		else
			{ani_play "wave" 1 callback}
			{set "backward" 1}
		}
	}
}

{"cord_wood"
	{inflammation_time 3}
	(define "burn_start"
		{add_view "smoke_camp_norm" "fire" "fx_light"}
		{set "burning" 1}
		{view start "fire"}
		{burn time %0}
		{fire radius 0.7 time %0 heating 0.3 follow}
		{delay %0
			{view stop "fire"}
			{set "burning" 0}
			{tags remove "burned"}
		}
	)
	{on spawn
		{if flag "burning"
			{add_view "smoke_camp_norm" "fire" "fx_light"}
			{view start "fire"}
		}
	}
	{on "_burn"
		{if flag "poured"
			{tags add "burned"}
			("burn_start" args 300)
		}
	}
	{on "burn"
		{if not burned
			{call "_burn"}
		}
	}
	{on contact
		{if effector "vehicle"
			{call "break"}
		}
	}
	{on blast
		{if volume "body"
			{if min_energy 0.5
				{call "break"}
			}
		}
	}
	{on "break"
		{if flag "burning"
			{spawn "camp_die" no_position offset 0 0 5}
		else
			{spawn "wood_hit_small" no_position}
		}
		{delete}
	}
	{on "pour_over"
		{if name "fuel"
			{tags add "poured"}
			{set "poured" 1}
		}
	}
}

{"camp_fire"
	{on spawn
		{link_sound "camp_fire" "fire/fireplace"}
		{call "burn"}
	}
	{on "_burn" overload
		("burn_start" args 7200)
		{play_sound_in_channel "camp_fire" "camp_fire_ch" 1}
	}
}

{"camp_fire_o"
	{on "_burn" overload}
}

{"camp_fire2"
	{on contact overload}
}

{"post_way"
	{on "hide"
		{bone hide "root"}
	}
	{on "show"
		{bone show "root"}
	}
}

{"stuff"
	{on spawn	;без этого автосборщик соберет все вещи на карте, которые там лежат изначально.
	  {delay 0.1
		{tags remove "try_em_notouch"}
		{if not linked
			{tags add "try_em_notouch"}
			{delay 3 {tags remove "try_em_notouch"}}
		}
	  }
	}
	{on "crush_container"
;		{impulse up 2 1 cx 0 1 cy 0 1}
		{impulse dir 2 1 up 2 1 dir 7 2 cx 0 0.5 cy 0 0.5}
	}
	{on "drop_item"
		{impulse dir 2 1 cx 0 1 cy 0 1}
	}
	{on blast_hit
		{if not linked
			{call "blast_physics"}
		}
	}
	{on bullet_hit
		{if not linked
			{impulse up 0.4 0.2 dir 1 0.5}
		}
	}
	{on "blast_physics"
		{if min_energy 5
			{impulse up 3 1 dir 5 1.5}
		else min_energy 3
			{impulse up 2 0.85 dir 4 1.2}
		else min_energy 2
			{impulse up 1 0.7 dir 3 0.8}
		else min_energy 1
			{impulse up 0.5 0.5 dir 2 0.5}
		}
	}
}
{"stuff_weapon"
	{on "blast_physics"
		{if min_energy 6
			{if not flag "sliced"
				{set "sliced" 1}
				{call "break"}
			}
		}
	}
	{on "break"
		{spawn "#smg_part1" "root" x {impulse up 0.5 0.5 dir 1 0.5}}
		{spawn "#smg_part2" "root" x {impulse up 0.5 0.5 dir 1 0.5}}
		{spawn "#smg_part3" "root" x {impulse up 0.5 0.5 dir 1 0.5}}
		{spawn "#smg_part4" "root" x {impulse up 0.5 0.5 dir 1 0.5}}
		{delete}
	}
}
{"stuff no_blast_physics"
	{on "blast_physics" overload}
}

{"paratrooper"
	{on spawn
		{tags add "paratrooper_air"}
		{view hide "parachute_x"}
	}
	{on "start"
		{ani_play "flight" callback}
	}
	{on animation_end "flight"
		{tags add "paratrooper"}
		{ani_play "landing" callback}
	}
	{on animation_end "landing"
		{view show "parachute_x"}
	}
}

{"paratrooper_attach"
	{on "start"
		{animate_place "attach" "paratruper_flight"}
		{tags add "paratrooper_in_flight"}
	}
	{on animation_end "flight"
		{with_linked_entity "attach"
			{weapon_prepare}
			{get_off}
			{tags add "paratrooper"}
			{tags remove "paratrooper_in_flight"}
		}
	}
}
{"paradrop"
	{on spawn
		{start_sound "world/ambient/bomber_flyby.wav"}
		{ani_play "flight"}
		{delay 4.0
			{ani_play "landing"}
		}
	}
}
{"paradrop_base"
	{on spawn
		{tags add "can_spawn"}
		{delay 1
			{if tagged "can_spawn"
				{spawn "paradrop_ammo"}
			}
		}
	}
}
{"auto_landing"
	{on spawn
		{call "start"}
;		{link_sound "flyby" "world/ambient/bomber_flyby"}
;		{start_sound "world/ambient/bomber_flyby"}		
	}
	{on animation_end "flight"
		{with_linked_entity "attach"
			{weapon_prepare}
		}
	}
	{on animation_end "landing"
		{delete}
	}
}
{"parachute_new"
	{on spawn
		{bone hide "para"}
		{link_sound "ParachuteOpen" "vehicle/shot/airborne/ParachuteOpen"}
	}
	(define "para_tags_remove"
		{tags remove "heli_parashute0"}
		{tags remove "heli_parashute1"}
		{tags remove "heli_parashute2"}
		{tags remove "heli_parashute3"}
		{tags remove "heli_parashute4"}
		{tags remove "heli_parashute5"}
		{tags remove "heli_parashute6"}
		{tags remove "heli_parashute7"}
		{tags remove "heli_parashute8"}
	)
	(define "crew_tags_remove"
	)
	(define "altitude_step"
		{on "start_alt_%0"
			{play_sound "ParachuteOpen" 1}
			{ani_play "altitude%0" callback}
			{ani_play "open"}
			{delay 0.2 {animate_place "attach" "paratruper_flight"}}
		}
		{on animation_end "altitude%0" 
			("para_tags_remove")
			{ani_stop "open"}
			{ani_play "landing" callback}
			{with_linked_entity "attach"
				{get_off}
			}
			{delay 3 {bone cut "attach"}}
		}
	)
	("altitude_step" args 1)
	("altitude_step" args 2)
	("altitude_step" args 3)
	("altitude_step" args 4)
	("altitude_step" args 5)
	("altitude_step" args 6)
	("altitude_step" args 7)
	{on crew in
		("spawn")
		("para_tags_remove") 
		{bone show "para"}
		{with_linked_entity "attach" 
			{tags remove "heli_paradrop0"}
			{tags remove "heli_paradrop1"}
			{tags remove "heli_paradrop2"}
			{tags remove "heli_paradrop3"}
			{tags remove "heli_paradrop4"}
			{tags remove "heli_paradrop5"}
			{tags remove "heli_paradrop6"}
			{tags remove "heli_paradrop7"}
		 }
	}
	{on animation_end "landing"
;		{spawn "parachute_new_ground" "attach" x}
		(mod not "mp"{spawn "parachute_new_ground" "root" x})
		{hide 5}
	}
}

{"parachute_veh"
	{on spawn
		{link_sound "ParachuteOpen" "vehicle/shot/airborne/ParachuteOpen"}
		{volumes "body" disable contact bullet blast}
		{volumes "body1" disable contact bullet blast}
	}
	(define "para_tags_remove"
		{tags remove "heli_parashute0"}
		{tags remove "heli_parashute1"}
		{tags remove "heli_parashute2"}
		{tags remove "heli_parashute3"}
		{tags remove "heli_parashute4"}
		{tags remove "heli_parashute5"}
		{tags remove "heli_parashute6"}
		{tags remove "heli_parashute7"}
		{tags remove "heli_parashute8"}
		{with_linked_entity "attach" 
			{tags remove "heli_paradrop0"}
			{tags remove "heli_paradrop1"}
			{tags remove "heli_paradrop2"}
			{tags remove "heli_paradrop3"}
			{tags remove "heli_paradrop4"}
			{tags remove "heli_paradrop5"}
			{tags remove "heli_paradrop6"}
			{tags remove "heli_paradrop7"}
		 }
	)
	{on "start"
		{play_sound "ParachuteOpen" 1}
		{ani_play "start" callback}
		{ani_play "open"}
		{ani_play "bags_open"}
		{impulse forward 50 com}
		{delay 0.01
			{gravity 1}
			{constrain_velocity 50}
		}
		{delay 2 {call "loop_detect"} {gravity 2} {constrain_velocity 50}}
		;{delay 7 {constrain_velocity 30}}
	}
	{on "loop_detect"
		{if not altitude 2 {call "collide"} else {delay 0.2 {call "loop_detect"}}}
	}
	{on animation_end "start" 
		("para_tags_remove")
		{ani_play "swing"}
	}
	{on "collide"
		{impulse up -0.01 com}
		{ani_stop "open"}
		{ani_stop "start"}
		{ani_stop "bags_open"}
		{ani_stop "swing"}
		{ani_play "land" callback}
		{ani_play "bags_close"}
		{volumes "bags" disable contact_ground}
		{spawn "dust_shot_big_2"}
		{with_linked_entity "attach" {delay 0.85 {constrain_velocity 1} {delay 0.05 {impulse up -0.01 com}} {delay 0.1 {constrain_velocity 1}} }}
		{delay 0.9 {bone cut "attach"}}
	}
	{on contact {call "collide"}}
	{on animation_end "land"
		{spawn "parachute_veh_ground" "basis" x {hide 15}}
			{tear "piece_medium_steel" bone "Para_platform"
              	  			{impulse up 0.2 0.1 dir 2 1}
					{volumes "body1" enable  contact bullet blast}
			}
		{hide 5}
	}

}
{"ponton_pmp_land"
	{on spawn
		{bone cut "right_pmp"} {bone cut "left_pmp"} {bone cut "centreright"} {bone cut "centreleft"} 
		{if tagged "installed"
			{ani_wind "start" end}
		}
		{if tagged "pmp_disable_side1" {call "pmp_disable_side1"}}
		{if tagged "pmp_disable_side2" {call "pmp_disable_side2"}}
		{area enable	"rectangle1"}
		{area enable	"rectangle2"}
		{call "check_in_water"}
	}
	{on animation_end "start" 
		{if terrain_fx "water"
			{volumes disable contact_ground}
			{spawn "spherewater_big" "FX_bulb_medium_center3"}
			{spawn "spherewater_big" "FX_bulb_medium_center4"}
		else  terrain_fx "deep_water"
			{volumes disable contact_ground}
			{spawn "spherewater_big" "FX_bulb_medium_center3"}
			{spawn "spherewater_big" "FX_bulb_medium_center4"}
		}
		{impulse up 1 com}
		{delay 0.5	{call "loop_detect"}}
	}	
	{on "install"
		{player -1}
		{tags add "installed"}
;		{set "stop" 0}
		{physics_work 0}
		{land on}
		{update_visibility_patch}
		{volumes "body" disable contact obstacle}
		{volumes "blast" disable obstacle}
		{volumes "examine1" enable contact}
		{volumes "examine2" enable contact}
		{if tagged "in_water"
			{spawn "cwship_informer" "link1" {impulse up 5 com} {tags add "pmp_side1"}}
			{spawn "cwship_informer" "link2" {impulse up 5 com} {tags add "pmp_side2"}}
		}
		{area enable	"rectangle1"}
		{area enable	"rectangle2"}
		{if terrain_fx "water"
			{call "fell_in_water"}
		else  terrain_fx "deep_water"
			{call "fell_in_water"}
		}
	}
	{on "loop_detect"
	   {delay 0.5
		{if velocity 0.01
			{delay 0.5 {call "loop_detect"}}
		else velocity 0.1
			{delay 1 {call "loop_detect"}}
		else 
			{delay 0.1
				{call "install"}
			}
		}
	   }
	}
	{on "check_in_water"
		{bone cut "right_pmp"} {bone cut "left_pmp"} {bone cut "centreright"} {bone cut "centreleft"} 
		{if terrain_fx "water"
			{call "fell_in_water"}
		else  terrain_fx "deep_water"
			{call "fell_in_water"}
		}
	}
	{on "fell_in_water"
		{tags add "in_water"}
		{ani_play "drift" loop}
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_medium_center1"}
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_medium_center2"}
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_medium_center3"}
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_medium_center4"}
		{view start "on_stead"}
	}
	{on contact	;linking pontons is impossible, but we can spawn them
		(define "place_ponton"
					{tear "ponton_pmp_land" bone "link%side"
						{ani_play "start" callback}
						{if terrain_fx "water"
							{volumes "body" disable contact contact_ground}
						else  terrain_fx "deep_water"
							{volumes "body" disable contact contact_ground}
						}
						{if not altitude 2
							{if terrain_fx "water"
								{spawn "spherewater_big" "FX_bulb_medium_center2"}
								{delay 1 {spawn "spherewater_big" "FX_bulb_medium_center1"}}
							else  terrain_fx "deep_water"
								{spawn "spherewater_big" "FX_bulb_medium_center2"}
								{delay 1 {spawn "spherewater_big" "FX_bulb_medium_center1"}}
							}
						}
						{volumes "examine%counter" disable all}
						{impulse up -1 com}
;						{delay 0.1 {call "loop_detect"}}
					}
					{with_effector {delete}	{with_effector}}
		)
		{if volume "examine1" 
			{if not effector "cwship_informer"
				{call "pmp_disable_side1"}
				{volumes "body" disable contact}
				{if effector "ponton_pmp_land"
					("place_ponton" side(1) counter(2))
				}
			}
		else volume "examine2" 
			{if not effector "cwship_informer"
				{call "pmp_disable_side2"}
				{volumes "body" disable contact}
				{if effector "ponton_pmp_land"
					("place_ponton" side(2) counter(1))
				}
			}
		}
	}
	{on "pmp_disable_side1" {tags add "pmp_disable_side1"}{volumes "examine1" disable all}}
	{on "pmp_disable_side2" {tags add "pmp_disable_side2"}{volumes "examine2" disable all}}
	{on "pmp_ground_side1" {call "pmp_disable_side1"}{tear "ponton_pmp_shore" bone "link1"}}
	{on "pmp_ground_side2" {call "pmp_disable_side2"}{tear "ponton_pmp_shore" bone "link2"}}
	{on blast
		{if min_energy 4
			{land off}
;			{volumes "blast" disable all}
;			{bone cut "holder"}
			(define "cut_piece"
				{tear "piece_float_steel" bone "piece%0"
					{volumes disable all}
					{volumes "piece%0" enable contact contact_ground bullet blast float}
					{volumes "blast" disable all}
					{volumes "Float%0" enable float}
					{volumes "Floata%0" enable float}
					{volumes "Floatb%0" enable float}
					{volumes "Floatc%0" enable float}
					{impulse up -2.5 0.7 dir 1.5 0.6 no_position}
				}
			)
			("cut_piece" args 4)	("cut_piece" args 3)	("cut_piece" args 2)	("cut_piece" args 1)
			{delay 0.5 {delete}}
		}
	}
}
{"ponton_pmp_shore"
	{on blast
		{if min_energy 4
			{land off}
			(define "cut_piece"
				{tear "piece_medium_steel" bone "piece%0"
					{volumes disable all}
					{volumes "piece%0" enable contact contact_ground bullet blast}
					{volumes "blast" disable all}
					{impulse up 0.5 0.3 dir 1.5 1.3 no_position}
				}
			)
			("cut_piece" args 5)	("cut_piece" args 6)	("cut_piece" args 7)	("cut_piece" args 8)
			("cut_piece" args 9)	("cut_piece" args 10)	("cut_piece" args 11)	("cut_piece" args 12)
			{delay 0.5 {delete}}
		}
	}
}
{"random_animation"
	{on spawn
		{call "random_animation"}
	}

	(define "random_animation"
		rand 0.1
		{ani_play "animation%0" callback}
	)
	{on "random_animation"
		{if  ("random_animation" args 0)
		else ("random_animation" args 1)
		else ("random_animation" args 2)
		else ("random_animation" args 3)
		else ("random_animation" args 4)
		else ("random_animation" args 5)
		else ("random_animation" args 6)
		else ("random_animation" args 7)
		else ("random_animation" args 8)
		else rand 0.1
			{call "delay"}
		else
			{call "random_animation"}
		}
	}

	(define "random_animation_end"
		{on animation_end "animation%0"
			{call "random_animation"}
		}
	)
	("random_animation_end" args 0)
	("random_animation_end" args 1)
	("random_animation_end" args 2)
	("random_animation_end" args 3)
	("random_animation_end" args 4)
	("random_animation_end" args 5)
	("random_animation_end" args 6)
	("random_animation_end" args 7)
	("random_animation_end" args 8)

	{on "delay"
		{call "random_animation"}
	}
}

{"random_animation with_delay"
	{on "delay" overload
		{delay 12 4
			{call "random_animation"}
		}
	}
}

{"blast_flattern"
	{on blast
		{if volume "flattern"
			{if min_energy 0.3
				{ani_play "flattern"}
			}
		}
	}
}

{"pointer"
	{on spawn
		{tags add "pointer"}
	}
	{on "show"
		{inactive 0}
		{delay 5
			{inactive 1}
		}
	}
}
{"user_guide"
	{on spawn
		{tags add "user_guide"}
		{inactive 0}
		{delay 10
			{hide 5}
		}
	}
}
{"pointer_attack"
	{on spawn
		{tags add "pointer_attack"}
	}
	{on "show"
		{inactive 0}
		{delay 5
			{inactive 1}
		}
	}
}

{"pointer_defend"
	{on spawn
		{tags add "pointer_defend"}
	}
	{on "show"
		{inactive 0}
		{delay 5
			{inactive 1}
		}
	}
}

{"pointer_enemy"
	{on spawn
		{tags add "pointer_enemy"}
	}
	{on "show"
		{inactive 0}
		{delay 5
			{inactive 1}
		}
	}
}

{"pointer_going"
	{on spawn
		{tags add "pointer_going"}
	}
	{on "show"
		{inactive 0}
		{delay 5
			{inactive 1}
		}
	}
}

{"pointer_watchout"
	{on spawn
		{tags add "pointer_watchout"}
	}
	{on "show"
		{inactive 0}
		{delay 5
			{inactive 1}
		}
	}
}

{"pointer_help"
	{on spawn
		{tags add "pointer_help"}
	}
	{on "show"
		{inactive 0}
		{delay 5
			{inactive 1}
		}
	}
}

{"invisible_wall_mp_nz"
	{on spawn {tags add "invisible_wall_mp_nz"}}
}
{"antena"
	{on spawn
		{add_view "stop_signal" "lamp" "fx_lamp"}
	}
	{on "beacon_start"
		{view start "lamp"}
	}
	{on "beacon_stop"
		{view stop "lamp"}
	}
}
{"radio_beacon"
	{on spawn
		{add_view "stop_signal" "lamp" "fx_lamp"}
		{view start "lamp"}
	}
}

{"sandstorm"
	{on spawn
		{add_view "desert2_fx" "lamp" "fx_lamp"}
		{view start "super"}
	}
}
{"big_flying_rocket"
	{on spawn
		{link_sound "fly" "weapon/shot/reactive/rocket"}
		{play_sound "fly" 1}
	}
}

{"welding"
	{on spawn
		{add_view "spark_electro02a" "welding" "root"}
		{view start "welding"}
	}
}
{"air_cloud"
	{on spawn
		{add_view "dustrun_snow_big" "air_cloud" "root"}
		{view start "air_cloud"}
	}
}
{"exp_det_dust"
	{on "explode"
		{if game_param 	"biom" "snow"
			{add_view "ex_det_w" "detonation" "basis"}
		else
			{add_view "ex_det" "detonation" "basis"}
		}
		{view start "detonation"}
	}
}
{"flash_gun_big_entity"
	{on "explode"
		{add_view "flash_gun_big01" "detonation1" "basis"}
		{view start "detonation1"}
	}
}
{"light_plafond_dim_entity"
	{on spawn
		{add_view "light_plafond_dim" "welding" "root"}
		{view start "welding"}
	}
}
{"light_plafond_dim_w_entity"
	{on spawn
		{add_view "light_plafond_dim_w" "welding" "root"}
		{view start "welding"}
	}
}

{"art_piece_one" ;Снаряд вызываемого арт удара
	{on spawn
		{gravity 9}
		{volumes enable contact contact_ground}
	}
	{on contact
		{call "detonate"}
	}
	{on ground_hit
		{call "detonate"}
	}
	{on "detonate"
		{spawn "test_fg_v1"}
		{spawn "crater_norm"}
		;{spawn "smoke_gen_big"} ;Генератор дыма, вызрывы стакаются и генерируют дым.
		{blastwave c4 18 r0 7 r1 18}
		{blastwave c4 25 r0 5 r1 16}
		{delete}
	}	
}


{"xmas"
	{on spawn
		{add_view "xmas_smoke"	"smoke" "root"}
		{view start "smoke"}
		{start_sound "weapon/shot/gift/gift_spawn"}
		{tags add "gift_pointer"}
		{impulse up 8 0 rnd_dir 8 0 no_position}
	}
	{on contact
		{if can_crush
			;{call "break"}
		}
	}
	{on "smoke"
		{spawn "grenade_smoke"
			{call "activate"}
			{delay 0.05 0.025
				{impulse up 0.3 0.1 dir 0.5 0.2 cx 0.5 0.2 cy 0.5 0.2 rnd_dir 0.5 0.2 com}
			}
		}
		{call "break"}
	}
	{on "signal"
		{spawn "grenade_signal"
			{call "activate"}
			{delay 0.05 0.025
				{impulse up 0.3 0.1 dir 0.5 0.2 cx 0.5 0.2 cy 0.5 0.2 rnd_dir 0.5 0.2 com}
			}
		}
		{call "break"}
	}
	{on "f_explosion"
		{spawn "explosion_203mm"}
		{delay 1
			{delete}
		}
		{call "break"}
	}
	{on "break"
		{start_sound "weapon/shot/gift/gift_explosion"}
		{spawn "xmas_present_destroy" "root"}
		{delay 1
			{delete}
		}
	}
}
{"xmas_a"
	{on spawn overload
	}
}
(define "shellhole_show_with_delay"
	{on spawn
		{remove_grass %1}
		{view hide "shellhole"}
		{delay %0
			{view show "shellhole"}
		}
	}
)

{"shellhole_dead_moto"
	("shellhole_show_with_delay" args 0.1 2)
}
{"shellhole_dead_car"
	("shellhole_show_with_delay" args 0.2 4)
}
{"shellhole_dead_tank"
	("shellhole_show_with_delay" args 0.35 6)
}
{"shellhole_size2"
	("shellhole_show_with_delay" args 0.1 1.5)
}
{"shellhole_size3"
	("shellhole_show_with_delay" args 0.1 2)
}
{"shellhole_size4"
	("shellhole_show_with_delay" args 0.2 4)
}
{"shellhole_size5"
	("shellhole_show_with_delay" args 0.3 6)
}

{"crater big"
	{on spawn
		{remove_grass 4}
	}
}
{"crater normal"
	{on spawn
		{remove_grass 3.5}
	}
}
{"crater small"
	{on spawn
		{remove_grass 3}
	}
}

{"flare"
	{on spawn
		{gravity 1.3}
		{tags add "flare"}
		{add_view "signal_rocket" "flare" "root"}
		{view start "flare"}
		{delay 15.5
			{delete}
		}
	}
}
{"#flare_patron"
	{on spawn overload
		{gravity 7}
		{constrain_velocity 5}
		{add_view "flare_patron_fx" "flare" "root"}
		{view start "flare"}
		{delay 1 0.5
			{hide 1}
		}
	}
}
{"#smoke_piece"
	{on ground_hit
		{delete}
	}
}
{"mp_flag"
	{on spawn
		{if not props "flag_delete" 
		and not props "usa_aa_mp_flag" and not props "cnsam_mp_flag" and not props "nato_aa_mp_flag" and not props "pvo_mp_flag"
			{if rand 0.5
				{if rand 0.5 {tags add "texmod_flag1"}
				else {tags add "texmod_flag2"}}
			else
				{if rand 0.5 {tags add "texmod_flag3"}
				else {tags add "texmod_flag4"}}
			}
		}
	}
}

{"flag_delete"
	{on spawn
		{delay 2.0 {delete}}
	}
}

{"cw_cumulative_assistor"
	{on spawn {delay 0.7 {delete}}}
	{on ground_hit	{delete}}
	{on contact	{delete}}
}
{"cw_fg_assistor"
	{on spawn {delay 0.7 {delete}}}
	{on ground_hit	{delete}}
	{on contact	{delete}}
	{on overlap begin
		{with_effector {call "kaz_work_on_shell"}}
	}
}
{"cw_apcr_assistor"
	{on spawn {delay 0.7 {delete}}}
	{on ground_hit	{delete}}
	{on contact	{delete}}
	{on overlap begin
		{with_effector {call "kaz_work_on_shell"}}
	}
}
{"cw_cumshell_assistor_1gen"
	{on overlap begin
		{with_effector {call "comp_armor_on_1gen"}{call "kaz_work_on_shell"}}
	}
}
{"cw_cumshell_assistor_2gen"
	{on overlap begin
		{with_effector {call "comp_armor_on_2gen"}{call "kaz_work_on_shell"}}
	}
}
{"cw_cumshell_assistor_3gen"
	{on overlap begin
		{with_effector {call "comp_armor_on_3gen"}{call "kaz_work_on_shell"}}
	}
}
{"cw_cumulative_assistor_1gen"
	{on overlap begin
		{with_effector {call "comp_armor_on_1gen"}{call "kaz_work"}}
	}
}
{"cw_cumulative_assistor_2gen"
	{on overlap begin
		{with_effector {call "comp_armor_on_2gen"}{call "kaz_work"}}
	}
}
{"cw_cumulative_assistor_3gen"
	{on overlap begin
		{with_effector {call "comp_armor_on_3gen"}{call "kaz_work"}}
	}
}
(define "cw_assist_spawner"
	{on spawn 
		{spawn "%0" "sp_point1" x}
		{spawn "%0" "sp_point2" x}
		{spawn "%0" "sp_point3" x}
		{spawn "%0" "sp_point4" x}
		{spawn "%0" "sp_point5" x}
		{spawn "%0" "sp_point6" x}
		{spawn "%0" "sp_point7" x}
		{spawn "%0" "sp_point8" x}
		{spawn "%0" "sp_point9" x}
		{spawn "%0" "sp_point10" x}
		{spawn "%0" "sp_point11" x}
		{spawn "%0" "sp_point12" x}
		{spawn "%0" "sp_point13" x}
		{spawn "%0" "sp_point14" x}
		{spawn "%0" "sp_point15" x}
		{spawn "%0" "sp_point16" x}
		{spawn "%0" "sp_point17" x}
		{spawn "%0" "sp_point18" x}
		{spawn "%0" "sp_point19" x}
		{spawn "%0" "sp_point20" x}
		{spawn "%0" "sp_point21" x}
		{spawn "%0" "sp_point22" x}
		{spawn "%0" "sp_point23" x}
		{spawn "%0" "sp_point24" x}
		{spawn "%0" "sp_point25" x}
		{spawn "%0" "sp_point26" x}
		{spawn "%0" "sp_point27" x}
		{spawn "%0" "sp_point28" x}
		{spawn "%0" "sp_point29" x}
		{delay 0.1 {delete}}
	}
)
{"cw_cumshassist_spawner_1gen" ("cw_assist_spawner" args cw_cumshell_assistor_1gen)}
{"cw_cumshassist_spawner_2gen" ("cw_assist_spawner" args cw_cumshell_assistor_2gen)}
{"cw_cumshassist_spawner_3gen" ("cw_assist_spawner" args cw_cumshell_assistor_3gen)}
{"cw_apcrshassist_spawner" ("cw_assist_spawner" args cw_apcrshell_assistor)}
{"cw_fgshassist_spawner" ("cw_assist_spawner" args cw_fgshell_assistor)}
{"cw_shell_l_detector"
	{on spawn {delay 0.7 {delete}}}
	{on bullet_hit
		{if stuff "light_shell" {spawn "paratorch" no_normal no_position}
		else stuff "light_grenade" {spawn "paratorch_small" no_normal no_position}}
	}
}

{"parachute_signal_fire"
	{on spawn
		{add_view "signal_rocket2" "signal" "fx_signal"}
		{view start "signal"}
		{ani_play "flight" 0.5}
		{delay 3
			{ani_stop "flight"}
			{delay 35
				{ani_play "flight" resume callback}
			}
		}
	}
	{on animation_end "flight"
		{delay 0
			{delete}
		}
	}
}

{"desk_2a"
	{on bullet_hit
		{if not stuff "bullet"
			{impulse up 2 0.1 dir 0.1 0.05}
		}
	}
}
{"fx_spawner"
	{on "blizzard"
		{if tagged "start_blizzard"
				{view stop "winter_wind"}
				{tags remove "start_blizzard"}
				{add_view "winter_test_slow" "winter_wind_slow" "root"}
				{view start "winter_wind_slow"}
		
		else
			{tags add "start_blizzard"}
			{view stop "winter_wind_slow"}
			{add_view "winter_test" "winter_wind" "root"}
			{view start "winter_wind"}
		}
	}
}
{"zone_borders"
	{on spawn
		{if tagged "_1a"
		{add_view "border_neutral" "border0" "decal001"}
		{add_view "border_neutral" "border0" "decal002"}
		{add_view "border_neutral" "border0" "decal003"}
		{add_view "border_neutral" "border0" "decal004"}
		{add_view "border_neutral" "border0" "decal005"}
		{add_view "border_neutral" "border0" "decal006"}
		{add_view "border_neutral" "border0" "decal007"}
		{add_view "border_neutral" "border0" "decal008"}
		{add_view "border_neutral" "border0" "decal009"}
		{add_view "border_neutral" "border0" "decal010"}
		{add_view "border_neutral" "border0" "decal011"}
		{add_view "border_neutral" "border0" "decal012"}
		{add_view "border_neutral" "border0" "decal013"}
		{add_view "border_neutral" "border0" "decal014"}
		{add_view "border_neutral" "border0" "decal015"}
		{add_view "border_neutral" "border0" "decal016"}
		{add_view "border_neutral" "border0" "decal017"}
		{add_view "border_neutral" "border0" "decal018"}
		{add_view "border_neutral" "border0" "decal019"}


		{add_view "border_ally" "border1" "decal001"}
		{add_view "border_ally" "border1" "decal002"}
		{add_view "border_ally" "border1" "decal003"}
		{add_view "border_ally" "border1" "decal004"}
		{add_view "border_ally" "border1" "decal005"}
		{add_view "border_ally" "border1" "decal006"}
		{add_view "border_ally" "border1" "decal007"}
		{add_view "border_ally" "border1" "decal008"}
		{add_view "border_ally" "border1" "decal009"}
		{add_view "border_ally" "border1" "decal010"}
		{add_view "border_ally" "border1" "decal011"}
		{add_view "border_ally" "border1" "decal012"}
		{add_view "border_ally" "border1" "decal013"}
		{add_view "border_ally" "border1" "decal014"}
		{add_view "border_ally" "border1" "decal015"}
		{add_view "border_ally" "border1" "decal016"}
		{add_view "border_ally" "border1" "decal017"}
		{add_view "border_ally" "border1" "decal018"}
		{add_view "border_ally" "border1" "decal019"}

		{add_view "border_ally_between" "border-1" "decal001"}
		{add_view "border_ally_between" "border-1" "decal002"}
		{add_view "border_ally_between" "border-1" "decal003"}
		{add_view "border_ally_between" "border-1" "decal004"}
		{add_view "border_ally_between" "border-1" "decal005"}
		{add_view "border_ally_between" "border-1" "decal006"}
		{add_view "border_ally_between" "border-1" "decal007"}
		{add_view "border_ally_between" "border-1" "decal008"}
		{add_view "border_ally_between" "border-1" "decal009"}
		{add_view "border_ally_between" "border-1" "decal010"}
		{add_view "border_ally_between" "border-1" "decal011"}
		{add_view "border_ally_between" "border-1" "decal012"}
		{add_view "border_ally_between" "border-1" "decal013"}
		{add_view "border_ally_between" "border-1" "decal014"}
		{add_view "border_ally_between" "border-1" "decal015"}
		{add_view "border_ally_between" "border-1" "decal016"}
		{add_view "border_ally_between" "border-1" "decal017"}
		{add_view "border_ally_between" "border-1" "decal018"}
		{add_view "border_ally_between" "border-1" "decal019"}

		{add_view "border_enemy" "border2" "decal001"}
		{add_view "border_enemy" "border2" "decal002"}
		{add_view "border_enemy" "border2" "decal003"}
		{add_view "border_enemy" "border2" "decal004"}
		{add_view "border_enemy" "border2" "decal005"}
		{add_view "border_enemy" "border2" "decal006"}
		{add_view "border_enemy" "border2" "decal007"}
		{add_view "border_enemy" "border2" "decal008"}
		{add_view "border_enemy" "border2" "decal009"}
		{add_view "border_enemy" "border2" "decal010"}
		{add_view "border_enemy" "border2" "decal011"}
		{add_view "border_enemy" "border2" "decal012"}
		{add_view "border_enemy" "border2" "decal013"}
		{add_view "border_enemy" "border2" "decal014"}
		{add_view "border_enemy" "border2" "decal015"}
		{add_view "border_enemy" "border2" "decal016"}
		{add_view "border_enemy" "border2" "decal017"}
		{add_view "border_enemy" "border2" "decal018"}
		{add_view "border_enemy" "border2" "decal019"}

			{if tagged "_2a"
				{add_view "border_neutral" "border0" "decal020"}
				{add_view "border_neutral" "border0" "decal021"}
				{add_view "border_neutral" "border0" "decal022"}
				{add_view "border_neutral" "border0" "decal023"}
				{add_view "border_neutral" "border0" "decal024"}
				{add_view "border_neutral" "border0" "decal025"}
				{add_view "border_neutral" "border0" "decal026"}
				{add_view "border_neutral" "border0" "decal027"}
				{add_view "border_neutral" "border0" "decal028"}
				{add_view "border_neutral" "border0" "decal029"}
				{add_view "border_neutral" "border0" "decal030"}
				{add_view "border_neutral" "border0" "decal031"}
				{add_view "border_neutral" "border0" "decal032"}
				{add_view "border_neutral" "border0" "decal033"}
				{add_view "border_neutral" "border0" "decal034"}
				{add_view "border_neutral" "border0" "decal035"}
				{add_view "border_neutral" "border0" "decal036"}
				{add_view "border_neutral" "border0" "decal037"}
				{add_view "border_neutral" "border0" "decal038"}
	
				{add_view "border_ally" "border1" "decal020"}
				{add_view "border_ally" "border1" "decal021"}
				{add_view "border_ally" "border1" "decal022"}
				{add_view "border_ally" "border1" "decal023"}
				{add_view "border_ally" "border1" "decal024"}
				{add_view "border_ally" "border1" "decal025"}
				{add_view "border_ally" "border1" "decal026"}
				{add_view "border_ally" "border1" "decal027"}
				{add_view "border_ally" "border1" "decal028"}
				{add_view "border_ally" "border1" "decal029"}
				{add_view "border_ally" "border1" "decal030"}
				{add_view "border_ally" "border1" "decal031"}
				{add_view "border_ally" "border1" "decal032"}
				{add_view "border_ally" "border1" "decal033"}
				{add_view "border_ally" "border1" "decal034"}
				{add_view "border_ally" "border1" "decal035"}
				{add_view "border_ally" "border1" "decal036"}
				{add_view "border_ally" "border1" "decal037"}
				{add_view "border_ally" "border1" "decal038"}
	
				{add_view "border_ally_between" "border-1" "decal020"}
				{add_view "border_ally_between" "border-1" "decal021"}
				{add_view "border_ally_between" "border-1" "decal022"}
				{add_view "border_ally_between" "border-1" "decal023"}
				{add_view "border_ally_between" "border-1" "decal024"}
				{add_view "border_ally_between" "border-1" "decal025"}
				{add_view "border_ally_between" "border-1" "decal026"}
				{add_view "border_ally_between" "border-1" "decal027"}
				{add_view "border_ally_between" "border-1" "decal028"}
				{add_view "border_ally_between" "border-1" "decal029"}
				{add_view "border_ally_between" "border-1" "decal030"}
				{add_view "border_ally_between" "border-1" "decal031"}
				{add_view "border_ally_between" "border-1" "decal032"}
				{add_view "border_ally_between" "border-1" "decal033"}
				{add_view "border_ally_between" "border-1" "decal034"}
				{add_view "border_ally_between" "border-1" "decal035"}
				{add_view "border_ally_between" "border-1" "decal036"}
				{add_view "border_ally_between" "border-1" "decal037"}
				{add_view "border_ally_between" "border-1" "decal038"}

				{add_view "border_enemy" "border2" "decal020"}
				{add_view "border_enemy" "border2" "decal021"}
				{add_view "border_enemy" "border2" "decal022"}
				{add_view "border_enemy" "border2" "decal023"}
				{add_view "border_enemy" "border2" "decal024"}
				{add_view "border_enemy" "border2" "decal025"}
				{add_view "border_enemy" "border2" "decal026"}
				{add_view "border_enemy" "border2" "decal027"}
				{add_view "border_enemy" "border2" "decal028"}
				{add_view "border_enemy" "border2" "decal029"}
				{add_view "border_enemy" "border2" "decal030"}
				{add_view "border_enemy" "border2" "decal031"}
				{add_view "border_enemy" "border2" "decal032"}
				{add_view "border_enemy" "border2" "decal033"}
				{add_view "border_enemy" "border2" "decal034"}
				{add_view "border_enemy" "border2" "decal035"}
				{add_view "border_enemy" "border2" "decal036"}
				{add_view "border_enemy" "border2" "decal037"}
				{add_view "border_enemy" "border2" "decal038"}
				
				{if tagged "_3a"
					{add_view "border_neutral" "border0" "decal039"}
					{add_view "border_neutral" "border0" "decal040"}
					{add_view "border_neutral" "border0" "decal041"}
					{add_view "border_neutral" "border0" "decal042"}
					{add_view "border_neutral" "border0" "decal043"}
					{add_view "border_neutral" "border0" "decal044"}
					{add_view "border_neutral" "border0" "decal045"}
					{add_view "border_neutral" "border0" "decal046"}
					{add_view "border_neutral" "border0" "decal047"}

					{add_view "border_ally" "border1" "decal039"}
					{add_view "border_ally" "border1" "decal040"}
					{add_view "border_ally" "border1" "decal041"}
					{add_view "border_ally" "border1" "decal042"}
					{add_view "border_ally" "border1" "decal043"}
					{add_view "border_ally" "border1" "decal044"}
					{add_view "border_ally" "border1" "decal045"}
					{add_view "border_ally" "border1" "decal046"}
					{add_view "border_ally" "border1" "decal047"}

					{add_view "border_ally_between" "border-1" "decal039"}
					{add_view "border_ally_between" "border-1" "decal040"}
					{add_view "border_ally_between" "border-1" "decal041"}
					{add_view "border_ally_between" "border-1" "decal042"}
					{add_view "border_ally_between" "border-1" "decal043"}
					{add_view "border_ally_between" "border-1" "decal044"}
					{add_view "border_ally_between" "border-1" "decal045"}
					{add_view "border_ally_between" "border-1" "decal046"}
					{add_view "border_ally_between" "border-1" "decal047"}

					{add_view "border_enemy" "border2" "decal039"}
					{add_view "border_enemy" "border2" "decal040"}
					{add_view "border_enemy" "border2" "decal041"}
					{add_view "border_enemy" "border2" "decal042"}
					{add_view "border_enemy" "border2" "decal043"}
					{add_view "border_enemy" "border2" "decal044"}
					{add_view "border_enemy" "border2" "decal045"}
					{add_view "border_enemy" "border2" "decal046"}
					{add_view "border_enemy" "border2" "decal047"}
				}
			}
		}
		{view hide "border1"}
		{view hide "border-1"}
		{view hide "border2"}
	}
	{on "show0"
		{view hide "border0"}
		{view hide "border1"}
		{view hide "border-1"}
		{view hide "border2"}
		{view show "border0"}
	}
	{on "show1"
		{view hide "border0"}
		{view hide "border1"}
		{view hide "border-1"}
		{view hide "border2"}
		{view show "border1"}
	}
	{on "show-1"
		{view hide "border0"}
		{view hide "border1"}
		{view hide "border-1"}
		{view hide "border2"}
		{view show "border-1"}
	}
	{on "show2"
		{view hide "border0"}
		{view hide "border1"}
		{view hide "border-1"}
		{view hide "border2"}
		{view show "border2"}
	}
}
{"vehnet"
     {on spawn
	{if terrain_fx "snow"	{tex_morph "win" 0.1}
	else terrain_fx "sand"	{tex_morph "1" 0.1}
	}
     }
	{on animation_end "crush"
		{update_shadow}
		{update_visibility_patch}
		{volumes disable visible}
		{volumes "select" enable touch}
	}
	{on "demine"
		{spawn "vehnet_inventory"}
		{delete}
	}
}

{"wind"
	{on spawn {delay 5 {delete}}}
	{on ground_hit overload
		{delete}
	}
}

{"delete_after_spawn"
	{on spawn
		{delay 10
			{hide 2}
		}
	}	
}
{"obstacle_avoid_mine"
	{on spawn
		{delay 100
			{delete}
		}
	}	
}
{"targ_ndf"
    {on spawn
	    {bone hide "basis"}
		{delay 0.5 {player -1}}
	}
	{on "ndf_start"
	    {with_linked_entity "targ_ndf"
			{volumes "select" enable touch visible select}
		}
	}
	{on "ndf_stop"
	    {with_linked_entity "targ_ndf"
			{volumes "select" disable touch visible select}
		}
	}
}
{"targ_ndf_1"
    {on spawn
		{delay 0.5 {player -1}}
	}
}
{"radar_minimap"
    {on spawn
		 {tags add "radar_minimap"}
			 {call "move_radar_minimap"}
		{delay 600 {delete}}	;удаление зависших
	}
	{on contact {delete}}
	{on "move_radar_minimap"
		{if altitude 2 {impulse up -0.01 com}
		else {impulse up 0.01 com}}
         {gravity 0.0}
	    {delay 0.1 
			{physics_work 1} 
			{call "move_radar_minimap"}
	    }
    }
	{on blast
	    {delete}
	}
}
{"guided_shell_spawner"
	{on spawn overload {impulse up 0.1 com} {delay 1.1 {delete}}}
	{on contact overload {if effector "proj_impulse" {delete}}}
}
{"stuff_shell"
	{on spawn
	   {if not bone "cw_bullet_dummy"
		{volumes "body" enable bullet}
	   }
	}
}
;=================cwbs - Cold War Bullet System===================
{"bullet"
	{on spawn
	   {delay 0.1
		{if bone "cw_advanced_bullet"	;marker bone for any type of advanced bullet behavior - simple bullets check only one condition.
			{if bone "cw_self_destroy_0_7sec"
				{delay 0.7 0.07 {call "detonate"}}
			else bone "cw_self_destroy_1sec"
				{delay 1 0.1 {call "detonate"}}
			else bone "cw_self_destroy_2sec"
				{delay 2 0.2 {call "detonate"}}
			}
			{if bone "cw_altitude_fuse"
				{delay 0.5 {call "check_alt_cycle"}}
;				{delay 30 {tags add "no_alt_check"}}
			}

			
			{if bone "cw_proximity_fuse"	;event readings are performed only when volumes switch state, not constantly
				{delay 0.1 {volumes "rangefinder" enable contact contact_ground}}
				{delay 0.3 {volumes "rangefinder" disable contact contact_ground}}
				{delay 0.5 {volumes "rangefinder" enable contact contact_ground}}
				{delay 0.7 {volumes "rangefinder" disable contact contact_ground}}
				{delay 0.9 {volumes "rangefinder" enable contact contact_ground}}
				{delay 1.1 {volumes "rangefinder" disable contact contact_ground}}
				{delay 1.3 {volumes "rangefinder" enable contact contact_ground}}
				{delay 1.5 {volumes "rangefinder" disable contact contact_ground}}
				{delay 1.7 {volumes "rangefinder" enable contact contact_ground}}
				{delay 1.9 {volumes "rangefinder" disable contact contact_ground}}
				{delay 2.1 {volumes "rangefinder" enable contact contact_ground}}
			}
			{if bone "cwbs_152mm_shell_sound" 
				{delay 1.3 {link_sound "shell_fly" "weapon/special/shell_fly/"} {play_sound "shell_fly" 1}}
			else bone "cwbs_122mm_shell_sound" 
				{delay 0.7 {link_sound "shell_fly" "weapon/special/shell_fly/"} {play_sound "shell_fly" 1}}
			else bone "cwbs_mortar_sound" 
				{delay 1.0 {link_sound "shell_fly" "weapon/special/mortar_fly/"}{call "check_shell_sound_cycle"}}
			}
		}
	   }
	
	}
	{on "check_alt_cycle"
		(define "alt_level"
			{if bone "cw_altitude_fuse_%altm" 
				{if altitude (+ 5 %alt) {tags add "activated"}
				else not altitude (+ 1 %alt) 
				  {if tagged "activated"
					{spawn "cw_rocket_cl_detector"}
				  }
				}
			}
		
		)

		{if not altitude 4 {if tagged "alt05" {tags add "activated"}}
		else not altitude 6 {if tagged "alt07" {tags add "activated"}}
		else not altitude 8 {if tagged "alt10" {tags add "activated"}}
		else not altitude 12 {if tagged "alt15" {tags add "activated"}}
		else not altitude 15 {if tagged "alt20" {tags add "activated"}}
		else not altitude 18 {if tagged "alt25" {tags add "activated"}}
		else not altitude 20 {if tagged "alt30" {tags add "activated"}}
		else not altitude 25 {if tagged "alt40" {tags add "activated"}}
		else not altitude 30 {if tagged "alt50" {tags add "activated"}}
		}
		{if not tagged "no_alt_check"
			("alt_level" alt(5))
			("alt_level" alt(7))
			("alt_level" alt(10))
			("alt_level" alt(15))
			("alt_level" alt(20))
			("alt_level" alt(25))
			("alt_level" alt(30))
			("alt_level" alt(40))
			("alt_level" alt(50))

			{if altitude 50 {delay 0.2 {call "check_alt_cycle"}} {tags add "alt50"}
			else altitude 40 {delay 0.2 {call "check_alt_cycle"}} {tags add "alt40"}
			else altitude 30 {delay 0.2 {call "check_alt_cycle"}} {tags add "alt30"}
			else altitude 25 {delay 0.2 {call "check_alt_cycle"}} {tags add "alt25"}
			else altitude 20 {delay 0.15 {call "check_alt_cycle"}} {tags add "alt20"}
			else altitude 15 {delay 0.12 {call "check_alt_cycle"}} {tags add "alt15"}
			else altitude 10 {delay 0.1 {call "check_alt_cycle"}} {tags add "alt10"}
			else altitude 7 {delay 0.07 {call "check_alt_cycle"}} {tags add "alt07"}
			else altitude 5 {delay 0.05 {call "check_alt_cycle"}} {tags add "alt05"}
			else tagged "activated" {call "detonate"}
			}
		
		}
	}
	{on "check_shell_sound_cycle"
			{if altitude 37 {tags add "sound"}}
			{if not tagged "sound" {delay 0.5 {call "check_shell_sound_cycle"}}
			else altitude 36 {delay 0.2 {call "check_shell_sound_cycle"}}
			else {play_sound "shell_fly" 1}}
	}
	{on "detonate" {volumes "body" enable bullet}}
;	{on contact  }	
}




; register engine-used props
{"steel"}
{"wood"}
{"flesh"}
{"concrete"}
{"sand"}
{"ice"}

{"collectable"}
{"nocover"}
{"shoulderbag"}
{"capacity"}
{"obstacle_ignore_height"}
{"trailer"}
{"tractor"}
{"spread_items"}
{"slow_on_crush"}
{"turn_over"}
{"no_plant"}
{"flag_slave"}
{"crater"}

{"round_sandbag"}
{"round_sandbag2"}
{"round_sandbag3"}
{"sandbag_round"}
{"no_minimap_view"}
{"delete_after_burn"}

{"vision_lev01_can"}
{"vision_lev02_can"}
{"vision_lev03_can"}
{"vision_lev04_can"}
{"vision_lev05_can"}

{"vision_lev00"}
{"vision_lev01"}
{"vision_lev02"}
{"vision_lev03"}
{"vision_lev04"}
{"vision_lev04_spa"}
{"vision_lev05"}
{"vision_lev06"}
{"vision_lev07"}
{"sturmtiger"}
{"howitzer"}
{"seismic"}
{"place_mg_stan"}
{"paratroopers_carrier"}
{"climb"}
{"climb_trench"}
{"remote"}
{"detonate"}

{"tnk_heavy"}		;unit_info.set

{"stat_gun_hotbar"}	;для хотбара
{"art_point"}		;для селекта юнитов в триггерах (должно соответствовать типу юнита в metagame (кроме art_sup))
{"art_spec"}
{"art_sup"}
{"sup"}
{"art"}
{"apc"}
{"tank_light"}
{"tank_medium"}
{"tank_heavy"}
{"tank_hunt"}
{"spg"}

{"level01"}			;для селекта юнитов в триггерах (должно соответствовать уровню юнита в metagame)
{"level02"}
{"level03"}
{"level04"}
{"level05"}
{"level06"}

{"unarmed"} 		;для техники без оружия (чтобы в панели хот-групп было ниже других вихеклов)

{"glider"}				;для планеров (чтобы настроить им отдельные правила видимости)

{"inventory_crate_icon"} ;для иконки ящика с раздачей боеприпасов

{"stationary"} ;для юнит инфо не перемещаемых орудий

{"mg_stan_small"} ;для небольших станковых пулемётов, чтобы дать бонус незаметности

{"icon_for_linked"} ;для того, чтобы рисовать иконку состояния у некоторых линкуемых сущностей

{"anm_empty"} ;для моделей орудий без анимаций стрелка и заряжающего

{"anm_stereoscope"} ;для анимаций екипажа нового стереоскопа

{"anm_heavy_2"} ;для тяжелых орудий без анимаций стрелка и заряжающего

{"anm_empty_aa"} ;для анимаций зенитных установок без командира

{"anm_52k"} ;для анимаций экипажа 52к

{"m1_aa_anm"} ;для анимаций экипажа m1_aa

{"anm_61k"} ;для анимаций экипажа 61k

{"anm_flak18"} ;для анимаций экипажа flak18

{"anm_flak"} ;для анимаций экипажа flak

{"anm_aa_heavy"} ;для анимаций тяжелых пушек

{"anm_searchlight"} ;для анимаций прожектора

{"anm_mortar_empty"} ;для минометов без анимаций экипажа

{"anm_mortar"} ;для анимаций экипажа минометов

{"anm_aa"} ;для анимаций зенитных установок

{"anm_empty_commander_small"} ;для малых пушек без анимации стрелка

{"anm_empty_commander_big"} ;для тяжелых пушек без анимации стрелка

{"anm_heavy"} ;для экипажей тяжелых пушек

{"anm_mgun_stan"} ;для экипажа пулеметов со станиной

{"anm_mgun_lie"} ;для анимации пулеметов в лежачей позе

{"anm_multigun"} ;для анимаций авто с несколькими пулеметами

{"one_hand_mgun_anm"} ;анимации для стрелков автомобилей с хватом пулемета одной рукой

{"anm_bazooka"} ;анимации для стрелков автомобилей с базукой

{"29k_anm"} ;для анимаций экипажа 29к

{"aaa_anm"} ;для анимаций экипажа зениток на базе авто

{"anm_moto"} ;анимации для экипажа мотоциклов

{"moto_2h"} ;для анимации экипажа мотоциклов с анимацией хвата пулемета двумя руками

{"anm_m8grayhound"} ;для анимаций экипажа m8grayhound

{"anm_ac_2hand_mgun"} ;для анимаций экипажа бранетранспортера с хватом пулемета двумя руками

{"anm_251_17"} ;для анимаций экипажа 251_17

{"anm_251_9"} ;для анимаций экипажа 251_9

{"anm_ac_zenit"} ;для анимаций бронепранспортеров з зенитным орудием

{"anm_ac_2hand_mgun_com"} ;для анимаций бронепранспортеров з зенитным орудием но хватом двумя руками

{"m2"} ;для анимаций экипажа m2

{"m3"} ;для анимаций экипажа m3

{"m2_m"} ;для анимаций экипажа m2м

{"anm_ac_mortair"} ;для анимаций экипажа бтр с минометом 

{"anm_cannon"} ;для анимаций экипажа бтр с пушкой

{"anm_cannon_big"} ;для анимаций экипажа бтр с тяжелым орудием

{"airborne"} ;для анимаций экипажа самолетов

{"anm_tank"} ;для анимаций экипажа танков

{"anm_tank_aa"} ;для анимаций экипажа танков с зенитным пулеметом

{"anm_tank_2h"} ;для анимаций экипажа танков с зенитным пулеметом хватом двумя руками

{"anm_tank_2h_ext"} ;для анимаций экипажа танков с зенитным пулеметом хватом двумя руками с дополнительными членами экипажа

{"anm_tank_ext"} ;для анимаций экипажа танков с зенитным пулеметом с дополнительными членами экипажа

{"anm_m19"} ;для анимаций экипажа танка м19

{"anm_marder3"} ;для анимаций экипажа marder3

{"anm_tank_cannon"} ;для анимаций экипажа танков с видимыми стрелком и заряжающим

{"anm_tank_m7"} ;для анимаций экипажа танка м7

{"anm_tank_cannon_ext"} ;для анимаций экипажа танков с видимыми стрелком и заряжающим и дополнительными членами экипажа

{"anm_tank_cannon_2h_ext"} ;для анимации

{"anm_hummel"} ;для анимаций экипажа танка hummel

{"anm_welberwind"} ;для анимаций экипажа welberwind