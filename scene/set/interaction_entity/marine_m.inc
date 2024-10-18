{"naval_part"
	{on "cut_pieces"
		{with_linked_entity "kranets1" {call "break"}}
		{with_linked_entity "kranets2" {call "break"}}
		{with_linked_entity "kranets3" {call "break"}}
		{with_linked_entity "kranets4" {call "break"}}
		{with_linked_entity "kranets5" {call "break"}}
		{with_linked_entity "kranets6" {call "break"}}
		{with_linked_entity "kranets7" {call "break"}}
		{with_linked_entity "kranets8" {call "break"}}
		{with_linked_entity "kranets9" {call "break"}}
		{with_linked_entity "kranets10" {call "break"}}
		{with_linked_entity "kranets11" {call "break"}}
		{with_linked_entity "kranets12" {call "break"}}
		{with_linked_entity "kranets13" {call "break"}}
		{with_linked_entity "kranets14" {call "break"}}
	}
}
{"kranets"
	{on "change_model"
		{delay 0.1 
;			{gravity 1.3}
			{impulse up 1 0.7 dir 2.5 0.3 rnd_dir 2 no_position}
		}
		{delay 1 {volumes enable contact float} {impulse up 1 0.7 dir 2.5 0.3 rnd_dir 2 no_position}}
	}
}
(define "cut_part_big"
	{if rand 0.5
		{tear "piece_big_steel" bone "%0"
			{impulse up 3 0.5 dir 2 2 cx 5 2 cy 5 2 rnd_dir 5 no_position}
			{add_view "fire_m_hole_norm" "smoke" "basis"}
			{add_view "fx_bubbles" "smoke" "basis"}
			{view start "smoke"}
;			{tex_morph "xx" 0.1}
			{delay 10 {impulse up 0.5}}
			{delay 20 {impulse up 0.5} {view stop "smoke"}}
		}
		{spawn "marine_die" "FXfire_norm_%0"}
	}
)
(define "cut_part"
	{if rand 0.5
		{tear "piece_medium_steel" bone "%0"
			{impulse up 1 0.5 dir 2 2 cx 5 2 cy 5 2 rnd_dir 5 no_position}
;			{tex_morph "xx" 0.1}
		}
	}
)
(define "sink_effect"
	{delay %delay
		{add_view "fire_m_hole_%effsize" "FXfire_%effsize_%bone" "FXfire_%effsize_%bone"}
		{add_view "fx_bubbles_%effsize" "FXfire_%effsize_%bone" "FXfire_%effsize_%bone"}
		{view start "FXfire_%effsize_%bone"}
		{spawn "marine_die" "FXfire_%effsize_%bone" x}
		{spawn "large_steel_debris" "FXfire_%effsize_%bone" x}
		{delay 30 15
			{spawn "marine_die" "FXfire_%effsize_%bone" x}
			{spawn "large_steel_debris" "FXfire_%effsize_%bone" x}
		}
	}
)
(define "break_effect"
	{delay %delay
		{add_view "fire_m_hole_%effsize" "FXbreak_%effsize_%bone" "FXfire_%effsize_%bone"}
		{view start "FXbreak_%effsize_%bone"}
		{spawn "marine_die" "FXfire_%effsize_%bone" x}
		{spawn "large_steel_debris" "FXfire_%effsize_%bone" x}
	}
)
(define "break_linked"
	{delay %delay
		{with_linked_entity "%name" {call "explosion"}{call "break"}}
	}
)
(define "break_delete_linked"
	{delay %delay
		{spawn "marine_die" "%name" x}
		{with_linked_entity "%name" {delete}}
	}
)
(define "tear_linked"
	{delay %delay
		{with_linked_entity "%name" {impulse up 0.1}}
		{bone cut "%name"}
	}
)
{"marine_M"	;это записи для всего корабля или всех его частей
	{on spawn
		{add_view	"smoke_black"		"on_move"	"FX_smoke"}
		{add_view	"smoke_black"		"on_move"	"FX_smoke1"}
		{add_view	"smoke_black"		"on_move"	"FX_smoke2"}
		{add_view	"smoke_black"		"on_move"	"FX_smoke3"}
		{add_view	"smoke_black"		"on_move"	"FX_smoke4"}
	
		{add_view	"smoke_ship_move"	"on_move"	"FX_smoke_big"}
		{add_view	"smoke_ship_move"	"on_move"	"FX_smoke_big1"}
		{add_view	"smoke_ship_move"	"on_move"	"FX_smoke_big2"}
		{add_view	"smoke_ship_move"	"on_move"	"FX_smoke_big3"}
		{add_view	"smoke_ship_move_side"	"on_move"	"FX_smoke_big_side"}
		{add_view	"smoke_ship_move_side"	"on_move"	"FX_smoke_big_side1"}

		{add_view	"wash_ship_stop_big"	"on_stead"	"FX_bulb_big_center1"}
		{add_view	"wash_ship_stop_big"	"on_stead"	"FX_bulb_big_center2"}
		{add_view	"wash_ship_stop_big"	"on_stead"	"FX_bulb_big_center3"}
		{add_view	"wash_ship_stop_big"	"on_stead"	"FX_bulb_big_center4"}
		{add_view	"wash_ship_stop_big"	"on_stead"	"FX_bulb_big_center5"}
		{add_view	"wash_ship_stop_big"	"on_stead"	"FX_bulb_big_center6"}
		{add_view	"wash_ship_stop_big"	"on_stead"	"FX_bulb_big_center7"}
		{add_view	"wash_ship_stop_big"	"on_stead"	"FX_bulb_big_center8"}
		{add_view	"wash_ship_stop_big"	"on_stead"	"FX_bulb_big_center9"}
		{add_view	"wash_ship_stop_big"	"on_stead"	"FX_bulb_big_center10"}
		{add_view	"wash_ship_stop_big"	"on_stead"	"FX_bulb_big_center11"}
		{add_view	"wash_ship_stop_big"	"on_stead"	"FX_bulb_big_center12"}
		{add_view	"wash_ship_stop_big"	"on_stead"	"FX_bulb_big_center13"}
		{add_view	"wash_ship_stop_big"	"on_stead"	"FX_bulb_big_center14"}
		{add_view	"wash_ship_stop_big"	"on_stead"	"FX_bulb_big_center15"}
		{add_view	"wash_ship_stop_big"	"on_stead"	"FX_bulb_big_center16"}
		{add_view	"wash_ship_stop_big"	"on_stead"	"FX_bulb_big_center17"}
		{add_view	"wash_ship_stop_medium"	"on_stead"	"FX_bulb_medium_center1"}
		{add_view	"wash_ship_stop_medium"	"on_stead"	"FX_bulb_medium_center2"}
		{add_view	"wash_ship_stop_medium"	"on_stead"	"FX_bulb_medium_center3"}
		{add_view	"wash_ship_stop_medium"	"on_stead"	"FX_bulb_medium_center4"}
		{add_view	"wash_ship_stop_medium"	"on_stead"	"FX_bulb_medium_center5"}
		{add_view	"wash_ship_stop_medium"	"on_stead"	"FX_bulb_medium_center6"}
		{add_view	"wash_ship_stop_medium"	"on_stead"	"FX_bulb_medium_center7"}
		{add_view	"wash_ship_stop_medium"	"on_stead"	"FX_bulb_medium_center8"}
		{add_view	"wash_ship_stop_medium"	"on_stead"	"FX_bulb_medium_center9"}
		{add_view	"wash_ship_stop_medium"	"on_stead"	"FX_bulb_medium_center10"}
		{add_view	"wash_ship_stop_medium"	"on_stead"	"FX_bulb_medium_center11"}
		{add_view	"wash_ship_stop_medium"	"on_stead"	"FX_bulb_medium_center12"}
		{add_view	"wash_ship_stop_medium"	"on_stead"	"FX_bulb_medium_center13"}
		{add_view	"wash_ship_stop_medium"	"on_stead"	"FX_bulb_medium_center14"}
		{add_view	"wash_ship_stop_medium"	"on_stead"	"FX_bulb_medium_center15"}
		{add_view	"wash_ship_stop_medium"	"on_stead"	"FX_bulb_medium_center16"}
		{add_view	"wash_ship_stop_medium"	"on_stead"	"FX_bulb_medium_center17"}
		{add_view	"wash_ship_stop_medium"	"on_stead"	"FX_bulb_medium_back1"}
		{add_view	"wash_ship_stop_medium"	"on_stead"	"FX_bulb_medium_back2"}
		

		{add_view	"wash_ship_motion_big"	"on_move"	"FX_bulb_big_center1"}
		{add_view	"wash_ship_motion_big"	"on_move"	"FX_bulb_big_center2"}
		{add_view	"wash_ship_motion_big"	"on_move"	"FX_bulb_big_center3"}
		{add_view	"wash_ship_motion_big"	"on_move"	"FX_bulb_big_center4"}
		{add_view	"wash_ship_motion_big"	"on_move"	"FX_bulb_big_center5"}
		{add_view	"wash_ship_motion_big"	"on_move"	"FX_bulb_big_center6"}
		{add_view	"wash_ship_motion_big"	"on_move"	"FX_bulb_big_center7"}
		{add_view	"wash_ship_motion_big"	"on_move"	"FX_bulb_big_center8"}
		{add_view	"wash_ship_motion_big"	"on_move"	"FX_bulb_big_center9"}
		{add_view	"wash_ship_motion_big"	"on_move"	"FX_bulb_big_center10"}
		{add_view	"wash_ship_motion_big"	"on_move"	"FX_bulb_big_center11"}
		{add_view	"wash_ship_motion_big"	"on_move"	"FX_bulb_big_center12"}
		{add_view	"wash_ship_motion_big"	"on_move"	"FX_bulb_big_center13"}
		{add_view	"wash_ship_motion_big"	"on_move"	"FX_bulb_big_center14"}
		{add_view	"wash_ship_motion_big"	"on_move"	"FX_bulb_big_center15"}
		{add_view	"wash_ship_motion_big"	"on_move"	"FX_bulb_big_center16"}
		{add_view	"wash_ship_motion_medium"	"on_move"	"FX_bulb_medium_center1"}
		{add_view	"wash_ship_motion_medium"	"on_move"	"FX_bulb_medium_center2"}
		{add_view	"wash_ship_motion_medium"	"on_move"	"FX_bulb_medium_center3"}
		{add_view	"wash_ship_motion_medium"	"on_move"	"FX_bulb_medium_center4"}
		{add_view	"wash_ship_motion_medium"	"on_move"	"FX_bulb_medium_center5"}
		{add_view	"wash_ship_motion_medium"	"on_move"	"FX_bulb_medium_center6"}
		{add_view	"wash_ship_motion_medium"	"on_move"	"FX_bulb_medium_center7"}
		{add_view	"wash_ship_motion_medium"	"on_move"	"FX_bulb_medium_center8"}
		{add_view	"wash_ship_motion_medium"	"on_move"	"FX_bulb_medium_center9"}
		{add_view	"wash_ship_motion_medium"	"on_move"	"FX_bulb_medium_center10"}
		{add_view	"wash_ship_motion_medium"	"on_move"	"FX_bulb_medium_center11"}
		{add_view	"wash_ship_motion_medium"	"on_move"	"FX_bulb_medium_center12"}
		{add_view	"wash_ship_motion_medium"	"on_move"	"FX_bulb_medium_center13"}
		{add_view	"wash_ship_motion_medium"	"on_move"	"FX_bulb_medium_center14"}
		{add_view	"wash_ship_motion_medium"	"on_move"	"FX_bulb_medium_center15"}
		{add_view	"wash_ship_motion_medium"	"on_move"	"FX_bulb_medium_center16"}
		{add_view	"wash_ship_motion_medium"	"on_move"	"FX_bulb_medium_center17"}
		{add_view	"wash_ship_motion_medium"	"on_move"	"FX_bulb_medium_back1"}
		{add_view	"wash_ship_motion_medium"	"on_move"	"FX_bulb_medium_back2"}

		{add_view	"wash_ship_wave_big"	"on_move_normal"	"FX_bulb_big_noseside1"}
		{add_view	"wash_ship_wave_big"	"on_move_normal"	"FX_bulb_big_noseside2"}
		{add_view	"wash_ship_wave_medium"	"on_move_normal"	"FX_bulb_medium_noseside1"}
		{add_view	"wash_ship_wave_medium"	"on_move_normal"	"FX_bulb_medium_noseside2"}
		{add_view	"wash_ship_wave_medium"	"on_move_normal"	"FX_bulb_medium_noseside3"}
		{add_view	"wash_ship_wave_medium"	"on_move_normal"	"FX_bulb_medium_noseside4"}
		{add_view	"wash_ship_burun_medium"	"on_move_normal"	"FX_bulb_big_nose1"}
		{add_view	"wash_ship_burun_medium"	"on_move_normal"	"FX_bulb_medium_nose1"}
		{add_view	"wash_ship_motion_big"	"on_move_normal"	"FX_bulb_big_noseside1"}
		{add_view	"wash_ship_motion_big"	"on_move_normal"	"FX_bulb_big_noseside2"}
		{add_view	"wash_ship_back_medium"	"on_move_normal"	"FX_bulb_medium_ship_back"}
		{add_view	"wash_ship_back_medium"	"on_move_normal"	"FX_bulb_medium_ship_back1"}
		{add_view	"wash_ship_back_big"	"on_move_normal"	"FX_bulb_big_ship_back"}
		{add_view	"wash_ship_back_big"	"on_move_normal"	"FX_bulb_big_ship_back1"}
		{add_view	"wash_engine_big"		"on_move_normal"	"FX_bulb_big_engine1"}
		{add_view	"wash_engine_big"		"on_move_normal"	"FX_bulb_big_engine2"}
		{add_view	"wash_engine_big"		"on_move_normal"	"FX_bulb_big_engine3"}
		{add_view	"wash_engine_norm"		"on_move_normal"	"FX_bulb_medium_engine1"}
		{add_view	"wash_engine_norm"		"on_move_normal"	"FX_bulb_medium_engine2"}
		{add_view	"wash_engine_norm"		"on_move_normal"	"FX_bulb_medium_engine3"}
		{add_view	"wash_ship_burun_big"	"on_move_fast"	"FX_bulb_big_nose1"}
		{add_view	"wash_ship_burun_medium1"	"on_move_fast"	"FX_bulb_medium_nose1"}
		
		{add_view	"steam"		"launching1"	"launching_point1_steam"}
		{add_view	"proj_smoke"	"launching1"	"launching_point1_steam"}
		{add_view	"steam"		"launching2"	"launching_point2_steam"}
		{add_view	"proj_smoke"	"launching2"	"launching_point2_steam"}
		{ani_play "radar_rotate" loop}
		{call "check_sinking"}
		{if able "sinking" {ani_wind "sink" end}}
		{tags add "cwps_precise"}
		{set "started" 0}
		
		{volumes disable visible}
		{volumes "hull_vis" enable visible}
		{delay 0.1
			{call "init_effects"}
			{with_linked_entity "boat_right_place"
				{view pause "on_stead"}
				{ani_stop "drift"}
			}
			{with_linked_entity "boat_left_place"
				{view pause "on_stead"}
				{ani_stop "drift"}
			}
			{with_linked_entity "boat_right_place1"
				{view pause "on_stead"}
				{ani_stop "drift"}
			}
			{with_linked_entity "boat_left_place1"
				{view pause "on_stead"}
				{ani_stop "drift"}
			}
		}
	}
	{on "add_movement_sound" overload
		{link_sound "engine_operatable"	"naval/move/ship_engine"}
		{link_sound "waves"	"naval/move/ship_waves"}
		{link_sound "alarm"	"naval/alarm/navysiren"}
		{play_sound "waves" 1}
	}
	{on operatable on
		{delay 0.1
			{play_sound "engine_operatable" 1}
		}
	}
	{on operatable off
		{stop_sound "engine_operatable"}
	}
	{on "play_sink_sound"
		{link_sound "sink1"	"naval/bulb/05"}
		{link_sound "sink2"	"naval/sink/bigshipcrush"}
		{link_sound "sink3"	"naval/sink/ship_sink"}
		{if chassis "water" 
			{play_sound "sink1" 1}
			{play_sound "sink3" 1}
		}
		{play_sound "sink2" 1}
		{stop_sound "waves"}
	}
	{on "stop_sink_sound"
		{stop_sound "sink1"}
		{stop_sound "sink2"}
		{stop_sound "sink3"}
	}
	{on move on
		{if chassis "water"
			{if not tagged "submerged" {view start "on_move"} }
			{view pause "on_stead"}
			{if not tagged "destroyed"
				{with_linked_entity "body" {if not tagged "submerged" {view start "on_move"} }{view pause "on_stead"}}{ani_play "move" loop}
				{with_linked_entity "body1" {if not tagged "submerged" {view start "on_move"} }{view pause "on_stead"}}{ani_play "move" loop}
				{with_linked_entity "body2" {if not tagged "submerged" {view start "on_move"} }{view pause "on_stead"}}{ani_play "move" loop}
				{with_linked_entity "body3" {if not tagged "submerged" {view start "on_move"} }{view pause "on_stead"}}{ani_play "move" loop}
				{with_linked_entity "body4" {if not tagged "submerged" {view start "on_move"} }{view pause "on_stead"}}{ani_play "move" loop}
			}
			{ani_stop "drift"}
			{ani_play "move" loop}
			{if not tagged "destroyed" {ani_play "move_drift" loop}}
		else
			{view pause "on_move"}
			{view pause "on_stead"}
		}
	}
	{on move off
		{if chassis "water"
			{if not tagged "submerged" {view start "on_stead"}}
			{view pause "on_move"}
			{if not tagged "destroyed"
				{with_linked_entity "body" {if not tagged "submerged" {view start "on_stead"}}{view pause "on_move"}}{ani_stop "move"}
				{with_linked_entity "body1" {if not tagged "submerged" {view start "on_stead"}}{view pause "on_move"}}{ani_stop "move"}
				{with_linked_entity "body2" {if not tagged "submerged" {view start "on_stead"}}{view pause "on_move"}}{ani_stop "move"}
				{with_linked_entity "body3" {if not tagged "submerged" {view start "on_stead"}}{view pause "on_move"}}{ani_stop "move"}
				{with_linked_entity "body4" {if not tagged "submerged" {view start "on_stead"}}{view pause "on_move"}}{ani_stop "move"}
			}
			{if not tagged "destroyed"{ani_play "drift" loop}}
			{ani_stop "move"}
			{ani_stop "move_drift"}
		else
			{view pause "on_move"}
			{view pause "on_stead"}
		}
	}
	{on "init_effects"
		{if chassis "water"
			{if not tagged "submerged" {view start "on_stead"}}
			{view pause "on_move"}
			{with_linked_entity "body" {if not tagged "submerged" {view start "on_stead"}}{view pause "on_move"}}
			{with_linked_entity "body1" {if not tagged "submerged" {view start "on_stead"}}{view pause "on_move"}}
			{with_linked_entity "body2" {if not tagged "submerged" {view start "on_stead"}}{view pause "on_move"}}
			{with_linked_entity "body3" {if not tagged "submerged" {view start "on_stead"}}{view pause "on_move"}}
			{with_linked_entity "body4" {if not tagged "submerged" {view start "on_stead"}}{view pause "on_move"}}
			{ani_play "drift" loop}
			{ani_stop "move"}
			{ani_stop "move_drift"}
		else
			{view pause "on_move"}
			{view pause "on_stead"}
		}	
	}
	{on "check_sinking" overload
		{call "check_water_level"}
		{if able "sinking"
			{reset_manual_control}
		}
		{delay 2 "check_sinking"
			{call "check_sinking"}
		}
	}
	{on "sink"
		{call "sinking"}
		{call "check_water_level"}
		{delay 1 
			{set "broken" 1}
			{able select 0}
			{able repaired 0}
			{player -1}
			{tags add "destroyed"}
			{ani_stop "drift"}
			{ani_stop "move"}
			{ani_stop "move_drift"}
			{ani_stop "radar_rotate"}
			{view pause "on_stead"}
			{view pause "on_move"}
			{view pause "on_move_normal"}
			{view pause "on_move_fast"}
			{delay 1 	
				{call "check_water_level"}
				{ani_stop "drift"}
				{ani_stop "move"}
				{ani_stop "move_drift"}
				{ani_stop "radar_rotate"}
				{view pause "on_stead"}
				{view pause "on_move"}
				{view pause "on_move_normal"}
				{view pause "on_move_fast"}
			}
		}
	}
	{on "check_water_level" overload	;used for speed checking
	   {if not tagged "destroyed"
		{if chassis "water"
			{if velocity 45
				{if not tagged "submerged" {view start "on_move_fast"}{view start "on_move_normal"} }
				{with_linked_entity "body" {if not tagged "submerged" {view start "on_move_fast"}{view start "on_move_normal"} }}
				{with_linked_entity "body1" {if not tagged "submerged" {view start "on_move_fast"}{view start "on_move_normal"} }}
				{with_linked_entity "body2" {if not tagged "submerged" {view start "on_move_fast"}{view start "on_move_normal"} }}
				{with_linked_entity "body3" {if not tagged "submerged" {view start "on_move_fast"}{view start "on_move_normal"} }}
				{with_linked_entity "body4" {if not tagged "submerged" {view start "on_move_fast"}{view start "on_move_normal"} }}

			else velocity 15
				{if not tagged "submerged" {view start "on_move_normal"} }
				{view pause "on_move_fast"}
				{with_linked_entity "body" {if not tagged "submerged" {view start "on_move_normal"} }{view pause "on_move_fast"}}
				{with_linked_entity "body1" {if not tagged "submerged" {view start "on_move_normal"} }{view pause "on_move_fast"}}
				{with_linked_entity "body2" {if not tagged "submerged" {view start "on_move_normal"} }{view pause "on_move_fast"}}
				{with_linked_entity "body3" {if not tagged "submerged" {view start "on_move_normal"} }{view pause "on_move_fast"}}
				{with_linked_entity "body4" {if not tagged "submerged" {view start "on_move_normal"} }{view pause "on_move_fast"}}
			else
				{view pause "on_move_fast"}
				{view pause "on_move_normal"}
				{with_linked_entity "body" {view pause "on_move_normal"}{view pause "on_move_fast"}}
				{with_linked_entity "body1" {view pause "on_move_normal"}{view pause "on_move_fast"}}
				{with_linked_entity "body2" {view pause "on_move_normal"}{view pause "on_move_fast"}}
				{with_linked_entity "body3" {view pause "on_move_normal"}{view pause "on_move_fast"}}
				{with_linked_entity "body4" {view pause "on_move_normal"}{view pause "on_move_fast"}}
			}
		}
	   }
	}
	{on "sinking"
		{delay 3
			{able "sinking" 1}
			{for_each_link
				{able "sinking" 1}
			}
		}
		{delay 10 {view stop "on_stead"} {view stop "on_move"}}
	}
	{on grounded on
		{ani_stop "drift"}
		{ani_stop "move"}
		{ani_stop "move_drift"}
	}
	{on grounded off
;		{ani_play "drift" loop}
	}
	{on bullet_hit
		{if stuff "rastrub" {with_effector {tags add "launch_antiship"}{with_effector}}}
	}
;=================разрушаемость
	{on break_armor
		{component break}
		{if volume "float"
			{call "break_float"}
		}
		{if component "part1"
			("cut_part" args part1)
		else component "part2"
			("cut_part" args part2)
		else component "part6"
			("cut_part" args part3)
		else component "part4"
			("cut_part" args part4)
		else component "part5"
			("cut_part" args part5)
		else component "part6"
			("cut_part" args part6)
		else component "part7"
			("cut_part" args part7)
		else component "part8"
			("cut_part" args part8)
		else component "part9"
			("cut_part" args part9)
		else component "part10"
			("cut_part" args part10)
		else component "part11"
			("cut_part" args part11)
		else component "part12"
			("cut_part" args part12)
		else component "part13"
			("cut_part" args part13)
		else component "part14"
			("cut_part" args part14)
		else component "part15"
			("cut_part" args part15)
		else component "part16"
			("cut_part" args part16)
		else component "part17"
			("cut_part" args part17)
		else component "part18"
			("cut_part" args part18)
		else component "part19"
			("cut_part" args part19)
		else component "part20"
			("cut_part" args part20)
		}
	}
	{on break overload
		{if component "body"
			{tags add "cwship_body_break"}
			{play_sound "alarm"}
			{spawn "cwship_informer" "break_inform_body" {tags add "cwship_body_break"}}
		else component "body1"
			{tags add "cwship_body1_break"}
			{play_sound "alarm"}
			{spawn "cwship_informer" "break_inform_body1" {tags add "cwship_body1_break"}}
		else component "body2"
			{tags add "cwship_body2_break"}
			{play_sound "alarm"}
			{spawn "cwship_informer" "break_inform_body2" {tags add "cwship_body2_break"}}
		else component "body3"
			{tags add "cwship_body3_break"}
			{play_sound "alarm"}
			{spawn "cwship_informer" "break_inform_body3" {tags add "cwship_body3_break"}}
		else component "body4"
			{tags add "cwship_body4_break"}
			{play_sound "alarm"}
			{spawn "cwship_informer" "break_inform_body4" {tags add "cwship_body4_break"}}
		else component "bridge"
			{tags add "cwship_bridge_break"}
			{play_sound "alarm"}
		}
		{delay 0.5 {call "check_hull_destroy"}}
		{delay 3 {call "check_hull_destroy"}}
	}
	{on "break_float"
		{call "sinking"}
		{volumes "float" disable all}
		{impulse up 0.2}
		{ani_stop "drift"}
		{chassis_work 0}
		{volumes disable obstacle}
	}
	{on "break_all" overload
		{kill_crew "driver"}
		{kill_crew "driver1"}
		{kill_crew "commander"}
		{kill_crew "commander1"}
		{kill_crew "gunner"}
		{drop_orders}
		{components destroy}
		{reset_manual_control}
		{able select 0}
		{able repaired 0}
		{unlink_trailer}
		{clear_inventory}
	}
	{on "cut_parts"
		("cut_part" args part1)
		("cut_part" args part2)
		("cut_part" args part3)
		("cut_part" args part4)
		("cut_part" args part5)
		("cut_part" args part6)
		("cut_part" args part7)
		("cut_part" args part8)
		("cut_part" args part9)
		("cut_part" args part10)
		("cut_part" args part11)
		("cut_part" args part12)
		("cut_part" args part13)
		("cut_part" args part14)
		("cut_part" args part15)
		("cut_part" args part16)
		("cut_part" args part17)
		("cut_part" args part18)
		("cut_part" args part19)
		("cut_part" args part20)
	}
	{on blast_hit
	       {if min_energy 10
		   		{spawn "marine_die"}
				{spawn "large_steel_debris" inv_normal}
;				{if volume "hull"
;					{spawn "marine_die"}
;					{spawn "large_steel_debris" inv_normal}
;				}
				{if component "part1"
					("cut_part" args part1)
				else component "part2"
					("cut_part" args part2)
				else component "part6"
					("cut_part" args part3)
				else component "part4"
					("cut_part" args part4)
				else component "part5"
					("cut_part" args part5)
				else component "part6"
					("cut_part" args part6)
				else component "part7"
					("cut_part" args part7)
				else component "part8"
					("cut_part" args part8)
				else component "part9"
					("cut_part" args part9)
				else component "part10"
					("cut_part" args part10)
				else component "part11"
					("cut_part" args part11)
				else component "part12"
					("cut_part" args part12)
				else component "part13"
					("cut_part" args part13)
				else component "part14"
					("cut_part" args part14)
				else component "part15"
					("cut_part" args part15)
				else component "part16"
					("cut_part" args part16)
				else component "part17"
					("cut_part" args part17)
				else component "part18"
					("cut_part" args part18)
				else component "part19"
					("cut_part" args part19)
				else component "part20"
					("cut_part" args part20)
				}
	       }
	}
	{on "update_lights"
		{for_each_link
			{call "start_autorepair"}
		}
	}
	
}


{"marine_M_section"
;==========CW projectile system part by Timosh
	(include "flares_and_chaff.inc")
	{on bullet_hit
		{if stuff "proj_pointer" {call "check_proj_type"}
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
}







;===============Разрушаемость линкованносоставных юнитов
{"cwship_main"	;это записи для любого корабля (для составных - только для главной части), отвечают за утопление
	{on "sink"
		{call "sinking"}
		{delay 1 
			{set "broken" 1}
			{able select 0}
			{able repaired 0}
			{player -1}
			{tags add "destroyed"}
			{ani_stop "drift"}
			{ani_stop "move"}
			{ani_stop "move_drift"}
			{ani_stop "radar_rotate"}
			{view pause "on_stead"}
			{view pause "on_move"}
			{view pause "on_move_normal"}
			{view pause "on_move_fast"}
		}
		{ani_stop "drift"}
		{ani_stop "move"}
		{ani_stop "move_drift"}
		{ani_stop "radar_rotate"}
		{call "play_sink_sound"}
		{view pause "submarine"}
		{view hide "submarine"}
		{view stop "submarine"}

	}
	{on "break_and_sink"
;		{delay 0.1 {tex_morph "xx" 10}}
;		{with_linked_entity "body" {tex_morph "xx" 10}{for_each_link {tex_morph "xx" 10}}}
;		{with_linked_entity "body1" {tex_morph "xx" 10}{for_each_link {tex_morph "xx" 10}}}
;		{with_linked_entity "body2" {tex_morph "xx" 10}{for_each_link {tex_morph "xx" 10}}}
;		{with_linked_entity "body3" {tex_morph "xx" 10}{for_each_link {tex_morph "xx" 10}}}
;		{with_linked_entity "body4" {tex_morph "xx" 10}{for_each_link {tex_morph "xx" 10}}}
;		{for_each_link {tex_morph "xx" 10}}
		{kill_crew "driver"}
		{kill_crew "commander"}
		{delay 0.1 {call "sink"}}
		{call "sink_sequence"}
	}
;	{on break	;это понадобится, если будут кастомные эффекты
;		{if component "body3"
;			{call "break_body3"}
;		else component "body1"
;			{call "break_body1"}
;		else component "body"
;			{call "break_body"}
;		else component "body2"
;			{call "break_body2"}
;		else component "body4"
;			{call "break_body4"}
;		else component "bridge"
;			{call "break_bridge"}
;		else component "bridge_support"
;			{call "break_bridge_support"}
;		}
;	}	
	{on animation_end "break_nose"
		{view stop "on_stead"} {view stop "on_move"}
	}
	{on animation_end "break_rear"
		{view stop "on_stead"} {view stop "on_move"}
	}
	{on "explode_and_sink"
		{call "break_and_sink"}
		{components "body" break} {with_linked_entity "body"  {components "body" break} {delay 0.1 {call "sink"}}}
		{components "body1" break} {with_linked_entity "body1"  {components "body1" break} {delay 0.1 {call "sink"}}}
		{components "body2" break} {with_linked_entity "body2"  {components "body2" break} {delay 0.1 {call "sink"}}}
		{components "body3" break} {with_linked_entity "body3"  {components "body3" break} {delay 0.1 {call "sink"}}}
		{components "body4" break} {with_linked_entity "body4"  {components "body4" break} {delay 0.1 {call "sink"}}}
		{components "bridge" break}
		{components "bridge_support" break}
	}
}
{"cwship_informer"
	{on spawn 
		{impulse up 0.1 com}
		{delay 1 {delete}}
	}
	{on contact	
	    {if effector "cwship_main"
			{if tagged "cwship_body3_break" {with_effector {components "body3" break} {with_effector}}
			else  tagged "cwship_body1_break" {with_effector {components "body1" break} {with_effector}}
			else  tagged "cwship_body_break" {with_effector {components "body" break} {with_effector}}
			else  tagged "cwship_body2_break" {with_effector {components "body2" break} {with_effector}}
			else  tagged "cwship_body4_break" {with_effector {components "body4" break} {with_effector}}
			}
		else effector "sam_radar"
			{if tagged "antirad_linked"	{with_effector {call "antirad_linked"} {with_effector}}}
		else effector "ponton_pmp_land"
			{if terrain_fx "water"
			else terrain_fx "deep_water"
			else terrain_fx "shallow_water"
			else terrain_fx "road"
				{if tagged "pmp_side1"	{with_effector {call "pmp_disable_side1"} {with_effector}}}
				{if tagged "pmp_side2"	{with_effector {call "pmp_disable_side2"} {with_effector}}}
			else  terrain_fx "bridge"
				{if tagged "pmp_side1"	{with_effector {call "pmp_disable_side1"} {with_effector}}}
				{if tagged "pmp_side2"	{with_effector {call "pmp_disable_side2"} {with_effector}}}
			else
				{if tagged "pmp_side1"	{with_effector {call "pmp_ground_side1"} {with_effector}}}
				{if tagged "pmp_side2"	{with_effector {call "pmp_ground_side2"} {with_effector}}}
			}	
	    }
	    {delete}
	}
}

;===============Additional damage from heavy blasts and sets of damaged hull sections to sink
;min_energy 15 - 155mm shell (6 kg HE), 25 - Kh-25ml (30 kg HE) or JSM (40 kg HE), 
;30 - Exoset (50 kg HE)
;50 - iskander (400 kg HE) or Malahit (380 kg HE) direct hit 
{"ship_heavy_M"	;heavy cruiser or air carrier with 5 hull sеctions and 2 bridge sections. More than 12000
	{on "check_hull_destroy"
	  {if not flag "broken"
	     {if tagged "cwship_body3_break"
	          {if tagged "cwship_body1_break"
				{if tagged "cwship_body_break"
					{call "break_and_sink"}
				}
	          }
	     }
	     {if tagged "cwship_body2_break"
	          {if tagged "cwship_body1_break"
				{if tagged "cwship_body_break"
					{call "break_and_sink"}
				}
	          }
	     }
	     {if tagged "cwship_body_break"
	          {if tagged "cwship_body2_break"
				{if tagged "cwship_body4_break"
					{call "break_and_sink"}
				}
	          }
	     }
	     {if tagged "cwship_body3_break"
	          {if tagged "cwship_body1_break"
				{if tagged "cwship_body2_break"
					 {if tagged "cwship_body4_break"
					{call "break_and_sink"}
					 }
				}
	          }
	     }
	   }
	}
}
{"ship_heavy_M_section"
	{on "contact_airborne" overload}
	{on blast_hit
		{if component "body3"
			{if min_energy 60
				{if rand 0.5 {components "body1" break}{spawn "cwship_informer" "break_inform_body3" {tags add "cwship_body1_break"}}}
			else min_energy 40
				{if rand 0.3 {components "body1" break}{spawn "cwship_informer" "break_inform_body3" {tags add "cwship_body1_break"}}}
			else min_energy 26
				{if rand 0.1 {components "body1" break}{spawn "cwship_informer" "break_inform_body3" {tags add "cwship_body1_break"}}}
;			else min_energy 21
;				{if rand 0.2 {components "body1" break}{spawn "cwship_informer" "break_inform_body3" {tags add "cwship_body1_break"}}}
			}
		else component "body1"
			{if min_energy 60
				{if rand 0.5 {components "body" break}{spawn "cwship_informer" "break_inform_body1" {tags add "cwship_body_break"}}}
				{if rand 0.5 {components "body3" break}{spawn "cwship_informer" "break_inform_body1" {tags add "cwship_body3_break"}}}
				{if rand 0.5 {components "bridge_support" break}{components "bridge" break}}
			else min_energy 40
				{if rand 0.3 {components "body" break}{spawn "cwship_informer" "break_inform_body1" {tags add "cwship_body_break"}}}
				{if rand 0.3 {components "body3" break}{spawn "cwship_informer" "break_inform_body1" {tags add "cwship_body3_break"}}}
				{if rand 0.3 {components "bridge_support" break}{components "bridge" break}}
			else min_energy 26
				{if rand 0.1 {components "body" break}{spawn "cwship_informer" "break_inform_body1" {tags add "cwship_body_break"}}}
				{if rand 0.1 {components "body3" break}{spawn "cwship_informer" "break_inform_body1" {tags add "cwship_body3_break"}}}
				{if rand 0.1 {components "bridge_support" break}{components "bridge" break}}
;			else min_energy 21
;				{if rand 0.2 {components "body" break}{spawn "cwship_informer" "break_inform_body1" {tags add "cwship_body_break"}}}
;				{if rand 0.2 {components "body3" break}{spawn "cwship_informer" "break_inform_body1" {tags add "cwship_body3_break"}}}
;				{if rand 0.2 {components "bridge_support" break}{components "bridge" break}}
			}
		else component "body"
			{if min_energy 60
				{if rand 0.5 {components "body1" break}{with_linked_entity "body1"  {components "body1" break}}}
				{if rand 0.5 {components "body2" break}{with_linked_entity "body2"  {components "body2" break}}}
				{if rand 0.5 {components "bridge_support" break}{components "bridge" break}}
			else min_energy 40
				{if rand 0.3 {components "body1" break}{with_linked_entity "body1"  {components "body1" break}}}
				{if rand 0.3 {components "body2" break}{with_linked_entity "body2"  {components "body2" break}}}
				{if rand 0.3 {components "bridge_support" break}{components "bridge" break}}
			else min_energy 26
				{if rand 0.1 {components "body1" break}{with_linked_entity "body1"  {components "body1" break}}}
				{if rand 0.1 {components "body2" break}{with_linked_entity "body2"  {components "body2" break}}}
				{if rand 0.1 {components "bridge_support" break}{components "bridge" break}}
;			else min_energy 21
;				{if rand 0.2 {components "body1" break}{with_linked_entity "body1"  {components "body1" break}}}
;				{if rand 0.2 {components "body2" break}{with_linked_entity "body2"  {components "body2" break}}}
;				{if rand 0.2 {components "bridge_support" break}{components "bridge" break}}
			}
		else component "body2"
			{if min_energy 60
				{if rand 0.5 {components "body4" break}{spawn "cwship_informer" "break_inform_body2" {tags add "cwship_body4_break"}}}
				{if rand 0.5 {components "body" break}{spawn "cwship_informer" "break_inform_body2" {tags add "cwship_body_break"}}}
			else min_energy 40
				{if rand 0.3 {components "body4" break}{spawn "cwship_informer" "break_inform_body2" {tags add "cwship_body4_break"}}}
				{if rand 0.3 {components "body" break}{spawn "cwship_informer" "break_inform_body2" {tags add "cwship_body_break"}}}
			else min_energy 26
				{if rand 0.1 {components "body4" break}{spawn "cwship_informer" "break_inform_body2" {tags add "cwship_body4_break"}}}
				{if rand 0.1 {components "body" break}{spawn "cwship_informer" "break_inform_body2" {tags add "cwship_body_break"}}}
;			else min_energy 21
;				{if rand 0.2 {components "body4" break}{spawn "cwship_informer" "break_inform_body2" {tags add "cwship_body4_break"}}}
;				{if rand 0.2 {components "body" break}{spawn "cwship_informer" "break_inform_body2" {tags add "cwship_body_break"}}}
			}
		else component "body4"
			{if min_energy 60
				{if rand 0.5 {components "body2" break}{spawn "cwship_informer" "break_inform_body4" {tags add "cwship_body2_break"}}}
			else min_energy 40
				{if rand 0.3 {components "body2" break}{spawn "cwship_informer" "break_inform_body4" {tags add "cwship_body2_break"}}}
			else min_energy 26
				{if rand 0.1 {components "body2" break}{spawn "cwship_informer" "break_inform_body4" {tags add "cwship_body2_break"}}}
;			else min_energy 21
;				{if rand 0.2 {components "body2" break}{spawn "cwship_informer" "break_inform_body4" {tags add "cwship_body2_break"}}}
			}
		else component "bridge_support"
			{if min_energy 60
				{if rand 0.5 {components "body1" break}}
				{if rand 0.5 {components "body" break}}
				{if rand 1 {components "bridge" break}}
			else min_energy 40
				{if rand 0.3 {components "body1" break}}
				{if rand 0.3 {components "body" break}}
				{if rand 1 {components "bridge" break}}
			else min_energy 26
				{if rand 0.15 {components "body1" break}}
				{if rand 0.15 {components "body" break}}
				{if rand 0.25 {components "bridge" break}}
;			else min_energy 21
;				{if rand 0.1 {components "body1" break}}
;				{if rand 0.1 {components "body" break}}
;				{if rand 0.4 {components "bridge" break}}
			}
		else component "bridge"
			{if min_energy 60
				{if rand 0.5 {components "bridge_support" break}}
			else min_energy 40
				{if rand 0.3 {components "bridge_support" break}}
			else min_energy 26
				{if rand 0.1 {components "bridge_support" break}}
;			else min_energy 21
;				{if rand 0.3 {components "bridge_support" break}}
			}
		}
	}
}

{"ship_medium_M"	;destroyer-class with 5 hull sеctions and 2 bridge sections. 1600-12000t
	{on "check_hull_destroy"
	  {if not flag "broken"
	     {if tagged "cwship_body3_break"
	          {if tagged "cwship_body1_break"
				{if tagged "cwship_body_break"
					{call "break_and_sink"}
				}
	          }
	     }
	     {if tagged "cwship_body2_break"
	          {if tagged "cwship_body1_break"
				{if tagged "cwship_body_break"
					{call "break_and_sink"}
				}
	          }
	     }
	     {if tagged "cwship_body_break"
	          {if tagged "cwship_body2_break"
				{if tagged "cwship_body4_break"
					{call "break_and_sink"}
				}
	          }
	     }
	     {if tagged "cwship_body3_break"
	          {if tagged "cwship_body1_break"
				{if tagged "cwship_body2_break"
					 {if tagged "cwship_body4_break"
					{call "break_and_sink"}
					 }
				}
	          }
	     }
	   }
	}
	{on blast_hit
		{if component "body3"
			{if min_energy 45
				{if rand 0.5 {components "body1" break}}
			else min_energy 30
				{if rand 0.3 {components "body1" break}}
			else min_energy 21
				{if rand 0.2 {components "body1" break}}
			else min_energy 16
				{if rand 0.1 {components "body1" break}}
			}
		else component "body1"
			{if min_energy 45
				{if rand 0.5 {components "body" break}}
				{if rand 0.5 {components "body3" break}}
				{if rand 0.5 {components "bridge_support" break}{components "bridge" break}}
			else min_energy 30
				{if rand 0.3 {components "body" break}}
				{if rand 0.3 {components "body3" break}}
				{if rand 0.3 {components "bridge_support" break}{components "bridge" break}}
			else min_energy 21
				{if rand 0.2 {components "body" break}}
				{if rand 0.2 {components "body3" break}}
				{if rand 0.2 {components "bridge_support" break}{components "bridge" break}}
			else min_energy 16
				{if rand 0.1 {components "body" break}}
				{if rand 0.1 {components "body3" break}}
				{if rand 0.1 {components "bridge_support" break}{components "bridge" break}}
			}
		else component "body"
			{if min_energy 45
				{if rand 0.5 {components "body1" break}}
				{if rand 0.5 {components "body2" break}}
				{if rand 0.5 {components "bridge_support" break}{components "bridge" break}}
			else min_energy 30
				{if rand 0.3 {components "body1" break}}
				{if rand 0.3 {components "body2" break}}
				{if rand 0.3 {components "bridge_support" break}{components "bridge" break}}
			else min_energy 21
				{if rand 0.2 {components "body1" break}}
				{if rand 0.2 {components "body2" break}}
				{if rand 0.2 {components "bridge_support" break}{components "bridge" break}}
			else min_energy 16
				{if rand 0.1 {components "body1" break}}
				{if rand 0.1 {components "body2" break}}
				{if rand 0.1 {components "bridge_support" break}{components "bridge" break}}
			}
		else component "body2"
			{if min_energy 45
				{if rand 0.5 {components "body4" break}}
				{if rand 0.5 {components "body" break}}
			else min_energy 30
				{if rand 0.3 {components "body4" break}}
				{if rand 0.3 {components "body" break}}
			else min_energy 21
				{if rand 0.2 {components "body4" break}}
				{if rand 0.2 {components "body" break}}
			else min_energy 16
				{if rand 0.1 {components "body4" break}}
				{if rand 0.1 {components "body" break}}
			}
		else component "body4"
			{if min_energy 45
				{if rand 0.5 {components "body2" break}}
			else min_energy 30
				{if rand 0.3 {components "body2" break}}
			else min_energy 21
				{if rand 0.2 {components "body2" break}}
			else min_energy 16
				{if rand 0.1 {components "body2" break}}
			}
		else component "bridge_support"
			{if min_energy 45
				{if rand 0.3 {components "body1" break}}
				{if rand 0.3 {components "body" break}}
				{if rand 1 {components "bridge" break}}
			else min_energy 30
				{if rand 0.2 {components "body1" break}}
				{if rand 0.2 {components "body" break}}
				{if rand 0.5 {components "bridge" break}}
			else min_energy 21
				{if rand 0.15 {components "body1" break}}
				{if rand 0.15 {components "body" break}}
				{if rand 0.25 {components "bridge" break}}
			else min_energy 16
				{if rand 0.1 {components "body1" break}}
				{if rand 0.1 {components "body" break}}
				{if rand 0.4 {components "bridge" break}}
			}
		else component "bridge"
			{if min_energy 45
				{if rand 0.75 {components "bridge_support" break}}
			else min_energy 30
				{if rand 0.5 {components "bridge_support" break}}
			else min_energy 21
				{if rand 0.3 {components "bridge_support" break}}
			else min_energy 16
				{if rand 0.1 {components "bridge_support" break}}
			}
		}
	  }
}

{"ship_light_M"	;corvette-class with 3 hull sеctions and 2 bridge sections. About 500-1500 t
				;It sinks without animation, but due to physics of ballast volumes
	{on "check_hull_destroy"
	  {if not flag "broken"
	    {if tagged "cwship_body1_break"
			{if tagged "cwship_body_break"
				{call "break_and_sink"}
			}
	    }
	    {if tagged "cwship_body2_break"
	        {if tagged "cwship_body_break"
				{call "break_and_sink"}
	        }
	    }
        {if tagged "cwship_body1_break"
			{if tagged "cwship_body2_break"
				{call "break_and_sink"}
			}
	     }
	   }
	}
	{on blast_hit
		{if component "body1"
			{if min_energy 30
				{if rand 1 {components "body" break}}
			else min_energy 21
				{if rand 0.8 {components "body" break}}
			else min_energy 16
				{if rand 0.5 {components "body" break}}
			else min_energy 13
				{if rand 0.2 {components "body" break}}
			}
		else component "body"
			{if min_energy 30
				{if rand 1 {components "body1" break}}
				{if rand 1 {components "body2" break}}
				{if rand 1 {components "bridge_support" break}{components "bridge" break}}
			else min_energy 21
				{if rand 0.8 {components "body1" break}}
				{if rand 0.8 {components "body2" break}}
				{if rand 0.8 {components "bridge_support" break}{components "bridge" break}}
			else min_energy 16
				{if rand 0.5 {components "body1" break}}
				{if rand 0.5 {components "body2" break}}
				{if rand 0.5 {components "bridge_support" break}{components "bridge" break}}
			else min_energy 13
				{if rand 0.2 {components "body1" break}}
				{if rand 0.2 {components "body2" break}}
				{if rand 0.2 {components "bridge_support" break}{components "bridge" break}}
			}
		else component "body2"
			{if min_energy 30
				{if rand 1 {components "body" break}}
			else min_energy 21
				{if rand 0.8 {components "body" break}}
			else min_energy 16
				{if rand 0.5 {components "body" break}}
			else min_energy 13
				{if rand 0.2 {components "body" break}}
			}
		else component "bridge_support"
			{if min_energy 30
				{if rand 0.8 {components "body" break}}
				{if rand 1 {components "bridge" break}}
			else min_energy 21
				{if rand 0.4 {components "body" break}}
				{if rand 1 {components "bridge" break}}
			else min_energy 16
				{if rand 0.15 {components "body" break}}
				{if rand 0.25 {components "bridge" break}}
			else min_energy 13
				{if rand 0.1 {components "body" break}}
				{if rand 0.4 {components "bridge" break}}
			}
		else component "bridge"
			{if min_energy 30
				{if rand 1 {components "bridge_support" break}}
			else min_energy 21
				{if rand 1 {components "bridge_support" break}}
			else min_energy 16
				{if rand 0.4 {components "bridge_support" break}}
			else min_energy 13
				{if rand 0.3 {components "bridge_support" break}}
			}
		}
	  }
	{on "sink_ballast"
		{delay 12 5 {volumes "ballast1" disable float} {impulse up 0.1}}
		{delay 12 5 {volumes "ballast2" disable float} {impulse up 0.1}}
		{delay 12 5 {volumes "ballast3" disable float} {impulse up 0.1}}
		{delay 12 5 {volumes "ballast4" disable float} {impulse up 0.1}}
		{delay 12 5 {volumes "ballast5" disable float} {impulse up 0.1}}
		{delay 12 5 {volumes "ballast6" disable float} {impulse up 0.1}}
	}
	{on "sink_sequence"
		{add_view "fx_bubbles_big" "FXfire_basis" "body"}
		{add_view "fx_bubbles_big" "FXfire_basis" "body1"}
		{add_view "fx_bubbles_big" "FXfire_basis" "body2"}
		{view start "FXfire_basis"}
		{delay 20 
			{view pause "on_stead"}
			{view pause "on_move"}
		}
		("sink_effect" effsize(small) bone(01) delay(10 10))
		("sink_effect" effsize(small) bone(02) delay(10 10))
		("sink_effect" effsize(small) bone(03) delay(10 10))
		("sink_effect" effsize(small) bone(04) delay(20 12))
		("sink_effect" effsize(small) bone(05) delay(20 12))
		("sink_effect" effsize(small) bone(06) delay(20 12))
		("sink_effect" effsize(small) bone(07) delay(30 15))
		("sink_effect" effsize(small) bone(08) delay(30 15))
		("sink_effect" effsize(small) bone(09) delay(30 15))
		("sink_effect" effsize(small) bone(10) delay(30 15))
		("sink_effect" effsize(small) bone(11) delay(30 15))
		("sink_effect" effsize(small) bone(12) delay(30 15))
		("sink_effect" effsize(small) bone(13) delay(30 15))
		("sink_effect" effsize(small) bone(14) delay(30 15))
		("sink_effect" effsize(small) bone(15) delay(30 15))
		("sink_effect" effsize(small) bone(16) delay(30 15))
		("sink_effect" effsize(small) bone(17) delay(30 15))
		("sink_effect" effsize(small) bone(18) delay(30 15))
		("sink_effect" effsize(small) bone(19) delay(30 15))
		("sink_effect" effsize(small) bone(20) delay(30 15))
		("sink_effect" effsize(norm) bone(01) delay(20 12))
		("sink_effect" effsize(norm) bone(02) delay(10 10))
		("sink_effect" effsize(norm) bone(03) delay(22 11))
		("sink_effect" effsize(norm) bone(04) delay(20 12))
		("sink_effect" effsize(norm) bone(05) delay(10 10))
		("sink_effect" effsize(norm) bone(06) delay(22 11))
		("sink_effect" effsize(norm) bone(07) delay(20 12))
		("sink_effect" effsize(norm) bone(08) delay(10 10))
		("sink_effect" effsize(norm) bone(09) delay(22 11))
		("sink_effect" effsize(norm) bone(10) delay(20 12))
		("sink_effect" effsize(norm) bone(11) delay(10 10))
		("sink_effect" effsize(norm) bone(12) delay(22 11))
		("sink_effect" effsize(big) bone(01) delay(20 10))
		;big bones can be involved in tearing hull parts, so they can not
		;to activate its FX at some circumstances
	}
}
;===============
{"nimitz_main air_carrier"
	{on spawn
		{delay 0.5 {with_linked_entity "landhelper0_place" {tags add "cwss_landhelper0"}}}
		{delay 0.5 {with_linked_entity "landhelper1_place" {tags add "cwss_landhelper1"}}}
		{delay 0.5 {with_linked_entity "landhelper2_place" {tags add "cwss_landhelper2"}}}
		(define "manage_place"
			{delay 0.5 
			   {if tagged "cwship_pl%0_busy"
			      {with_linked_entity "standing%0" 
				{chassis_work 0}{physics_work 0} {call "landing_load"}{ani_wind "fly" end}{ani_wind "damage_fly" end}{ani_wind "close_wings" end}
			      }
			   }
			}
		)
		("manage_place" args 1) ("manage_place" args 2) ("manage_place" args 3) ("manage_place" args 4) ("manage_place" args 5)
		("manage_place" args 6) ("manage_place" args 7) ("manage_place" args 8) ("manage_place" args 9) ("manage_place" args 10)
	}
;===============================Посадка
	{on overlap begin
		{if effector "carrier_based"
		    {if not tagged "cwship_deck_busy"
		        {if not tagged "cwship_hangar_full"
			{call "glissada_check"}
		        else {with_linked_entity "landing_sys" {call "stop_landing"}}
		        }
		    else {with_linked_entity "landing_sys" {call "stop_landing"}}
		    }
		}
	}
	{on "glissada_check"
	         {if tagged "cwship_glissada"
		{call "select_place"}
		{volumes "glissada" disable overlap}
		{tags remove "cwship_glissada"}
		{call "reload_landing"}
	         else tagged "cwship_glissada1"
		{with_linked_entity "landing_sys" {call "indicate_readiness"}}
		{volumes "glissada2" disable overlap}
		{volumes "glissada1" disable overlap}
		{volumes "glissada" enable overlap}
		{tags remove "cwship_glissada1"}
		{tags add "cwship_glissada"}
	         else
		{with_linked_entity "landing_sys" 
			{call "enable"}
			{call "indicate_readiness"}	;под вопросом - хорошо ли будет смотреться
		}
		{volumes "glissada2" disable overlap}
		{volumes "glissada1" enable overlap}
		{tags add "cwship_glissada1"}
	         }
	         {delay 7 "cwship_reload_landing" 
		{call "reload_landing"}
		{with_linked_entity "landing_sys" {call "stop_landing"}}
	         }
	}
	{on "select_place"
		(define "cwship_place_lift"
		    not tagged "cwship_pl%id_busy"
		    {if not tagged "cwship_%lift_busy"
		        {if not tagged "cwship_%parkzone_busy"
			{call "permit_landing"}
			{tags add "cwship_deck_busy"}
			{tags add "cwship_pl%id_busy"}
			{tags add "cwship_%lift_busy"}
			{tags add "cwship_%parkzone_busy"}
			{tags add "cwship_to_pl%id"}
			{with_effector 
				{tags add "cwship_landing_plane"}
				{delay 5 	{tags remove "cwship_landing_plane"}}
				{with_effector}
			}
			{with_linked_entity "landing_sys" {call "final"}}
		        }
		    }
		)
		(define "cwship_place"
		    not tagged "cwship_pl%id_busy"
		        {if not tagged "cwship_%parkzone_busy"
			{call "permit_landing"}
			{tags add "cwship_deck_busy"}
			{tags add "cwship_pl%id_busy"}
			{tags add "cwship_%parkzone_busy"}
			{tags add "cwship_to_pl%id"}
			{with_effector 
				{tags add "cwship_landing_plane"}
				{delay 5 	{tags remove "cwship_landing_plane"}}
				{with_effector}
			}
			{with_linked_entity "landing_sys" {call "final"}}
		        }
		)
		{if ("cwship_place_lift" id(1) parkzone(street) lift(lift1))
		else ("cwship_place" id(6) parkzone(street))
		else ("cwship_place" id(7) parkzone(street))
		else ("cwship_place" id(8) parkzone(street))
		else ("cwship_place_lift" id(9) parkzone(street) lift(lift1)) 
		else ("cwship_place_lift" id(2) parkzone(deck) lift(lift4))
		else ("cwship_place_lift" id(3) parkzone(deck) lift(lift3))
		else ("cwship_place_lift" id(4) parkzone(deck) lift(lift4))
		else ("cwship_place_lift" id(5) parkzone(deck) lift(lift3))
		else ("cwship_place_lift" id(10) parkzone(street) lift(lift1))
		}
		{if tagged "cwship_to_pl10" {tags add "cwship_hangar_full"}}
	}
	{on "reload_landing"
		{kill_delay "cwship_reload_landing"}
		{volumes "glissada" disable overlap}
		{volumes "glissada1" disable overlap}
		{volumes "glissada2" enable overlap}
		{tags remove "cwship_glissada1"}
		{tags remove "cwship_glissada"}
	}
	{on "landing_plane"
		{ani_play "landing" callback}
		{with_linked_entity "landing" 
			{tags remove "cwship_landing_plane"} {chassis_work 0}{physics_work 0} {call "landing_load"}{ani_wind "fly" end}{ani_play "gak_out"}
		}
	}
	{on animation_end "landing"
		{with_linked_entity "landing" 
			{ani_play "gak_out" -1}{ani_play "close_wings"}
		}
		{if tagged "cwship_to_pl1"
			{call "cwship_tr_land_to_pl1"}
		else tagged "cwship_to_pl2"
			{call "cwship_tr_land_to_pl2"}
		else tagged "cwship_to_pl3"
			{call "cwship_tr_land_to_pl3"}
		else tagged "cwship_to_pl4"
			{call "cwship_tr_land_to_pl4"}
		else tagged "cwship_to_pl5"
			{call "cwship_tr_land_to_pl5"}
		else tagged "cwship_to_pl6"
			{call "cwship_tr_land_to_pl6"}
		else tagged "cwship_to_pl7"
			{call "cwship_tr_land_to_pl7"}
		else tagged "cwship_to_pl8"
			{call "cwship_tr_land_to_pl8"}
		else tagged "cwship_to_pl9"
			{call "cwship_tr_land_to_pl9"}
		else tagged "cwship_to_pl10"
			{call "cwship_tr_land_to_pl10"}
		}
	}
;===============================Трансфер по палубе
(define "deck_place"
	{on "cwship_tr_land_to_pl%id"
		{tags remove "cwship_to_pl%id"}
		{with_linked_entity "landing" {tags add "cwship_tr_land_to_pl%id"} {delay 1 {tags remove "cwship_tr_land_to_pl%id"}}}
		{ani_play "stand_in_place%id" callback}
		{tags remove "cwship_deck_busy"}
		{tags remove "cwship_%parkzone_busy"}
		{with_linked_entity "%hull_part" {ani_play "lift%lift_id"}}
	}
	{on animation_end "stand_in_place%id"
;		{delay 3 {call "cwship_tr_pl%id_to_launch%catapult_id"}}
		{tags remove "cwship_lift%lift_id_busy"}
	}
	{on "cwship_tr_pl%id_to_launch%catapult_id"
		{tags remove "cwship_hangar_full"}
		{ani_play "stand_out_place%id" callback}
		{with_linked_entity "%hull_part" {ani_play "lift%lift_id"}}
	}
	{on animation_end "stand_out_place%id"
		{with_linked_entity "standing%id" {tags add "cwship_launching%catapult_id"}}
		{call "launching%catapult_id"}
		{tags remove "cwship_%launchzone_busy"}
		{tags remove "cwship_lift%lift_id_busy"}
	}
)
("deck_place" id(1) catapult_id(1) hull_part(none) lift_id(1) parkzone(street) launchzone(deck))
("deck_place" id(2) catapult_id(1) hull_part(body4) lift_id(4) parkzone(deck) launchzone(deck))
("deck_place" id(3) catapult_id(1) hull_part(body4) lift_id(3) parkzone(deck) launchzone(deck))
("deck_place" id(4) catapult_id(1) hull_part(body4) lift_id(4) parkzone(deck) launchzone(deck))
("deck_place" id(5) catapult_id(1) hull_part(body4) lift_id(3) parkzone(deck) launchzone(deck))
("deck_place" id(6) catapult_id(2) hull_part(none) lift_id(none) parkzone(street) launchzone(street))
("deck_place" id(7) catapult_id(2) hull_part(none) lift_id(none) parkzone(street) launchzone(street))
("deck_place" id(8) catapult_id(2) hull_part(none) lift_id(none) parkzone(street) launchzone(street))
("deck_place" id(9) catapult_id(2) hull_part(body) lift_id(1) parkzone(street) launchzone(street))
("deck_place" id(10) catapult_id(2) hull_part(body) lift_id(1) parkzone(street) launchzone(street))
;===============================Взлет
{on "specability" overload
;		{damage_report "body" "Запуск самолета"}
		{call "launch_next_plane"}
}
	{on "launch_next_plane"
		(define "cwship_place_lift"
		    tagged "cwship_pl%id_busy"
		    {if not tagged "cwship_%lift_busy"
		        {if not tagged "cwship_%launchzone_busy"
			{call "cwship_tr_pl%id_to_launch%catapult_id"}
			{tags remove "cwship_pl%id_busy"}
			{tags add "cwship_%lift_busy"}
			{tags add "cwship_%launchzone_busy"}
		        }
		    }
		)
		(define "cwship_place"
		    tagged "cwship_pl%id_busy"
		        {if not tagged "cwship_%launchzone_busy"
			{call "cwship_tr_pl%id_to_launch%catapult_id"}
			{tags remove "cwship_pl%id_busy"}
			{tags add "cwship_%launchzone_busy"}
		        }
		)
		{if ("cwship_place_lift" id(1) launchzone(deck) catapult_id(1) lift(lift1))
		else ("cwship_place" id(6) launchzone(street) catapult_id(2))
		else ("cwship_place" id(7) launchzone(street) catapult_id(2))
		else ("cwship_place" id(8) launchzone(street) catapult_id(2))
		else ("cwship_place_lift" id(9) launchzone(street) catapult_id(2) lift(lift1)) 
		else ("cwship_place_lift" id(2) launchzone(deck) catapult_id(1) lift(lift4))
		else ("cwship_place_lift" id(3) launchzone(deck) catapult_id(1) lift(lift3))
		else ("cwship_place_lift" id(4) launchzone(deck) catapult_id(1) lift(lift4))
		else ("cwship_place_lift" id(5) launchzone(deck) catapult_id(1) lift(lift3))
		else ("cwship_place_lift" id(10) launchzone(street) catapult_id(2) lift(lift1))
		}
	}
(define "deck_launch"
	{on "launching%id"
	  {if not tagged "destroyed"
		{ani_play "launching%id" callback}
		{view start "launching%id"}
		{delay 0.5 {with_linked_entity "launching%id" {call "script_overburn_on"}{ani_play "close_wings" -1}}}
		{delay 0.1 {with_linked_entity "%hull_part" {ani_play "p%id_blastshield"}}}
	  }
	}
	{on animation_end "launching%id"
	  {if not tagged "destroyed"
		{with_linked_entity "launching%id" 
			{call "script_overburn_off" }
			{tags add "cwship_launched_plane"}{chassis_work 1}{physics_work 1} 
			{delay 3 {tags remove "cwship_launched_plane"}}
			{call "takeoff_load"}
		}
	   else
		{with_linked_entity "launching%id" 
			{chassis_work 1}{physics_work 1} 
			{call "fall" }
		}
	   }
	   {view pause "launching%id"}
	}
)
("deck_launch" id(1) hull_part(none))
("deck_launch" id(2) hull_part(body))
}

{"air_carrier heli_carrier"
	{on spawn
		{delay 0.5 {with_linked_entity "landhelper0_place" {tags add "cwss_landhelper0"}}}
		{delay 0.5 {with_linked_entity "landhelper1_place" {tags add "cwss_landhelper1"}}}
		{delay 0.5 {with_linked_entity "landhelper2_place" {tags add "cwss_landhelper2"}}}
		{delay 0.5 
		   {if tagged "cwship_pl1_busy"
			  {with_linked_entity "standing1" 
			{chassis_work 0}{physics_work 0} {call "landing_load"}{ani_wind "fly" end}{ani_wind "damage_fly" end}{ani_wind "close_wings" end}{ani_wind "engine_stop" end}
			  }
		   }
		}
	}
;===============================Посадка
	{on overlap begin
		{if effector "Helicopter_M"
		    {if not tagged "cwship_deck_busy"
		        {if not tagged "cwship_hangar_full"
					{call "glissada_check"}
		        else {with_linked_entity "landing_sys" {call "stop_landing"}}
		        }
		    else {with_linked_entity "landing_sys" {call "stop_landing"}}
		    }
		}
	}
	{on "glissada_check"
	    {if tagged "cwship_glissada"
			{if not tagged "cwship_pl1_busy"
				{call "permit_landing"}
				{tags add "cwship_pl1_busy"}
				{tags add "cwship_hangar_full"}
				{with_effector 
					{tags add "cwship_landing_plane"}
					{delay 5 	{tags remove "cwship_landing_plane"}}
					{with_effector}
				}
				{with_linked_entity "landing_sys" {call "final"}}
			}
			{volumes "glissada" disable overlap}
			{tags remove "cwship_glissada"}
			{call "reload_landing"}
	    else tagged "cwship_glissada1"
			{with_linked_entity "landing_sys" {call "indicate_readiness"}}
			{volumes "glissada2" disable overlap}
			{volumes "glissada1" disable overlap}
			{volumes "glissada" enable overlap}
			{tags remove "cwship_glissada1"}
			{tags add "cwship_glissada"}
	    else
			{with_linked_entity "landing_sys" 
				{call "enable"}
				{call "indicate_readiness"}	;под вопросом - хорошо ли будет смотреться
			}
			{volumes "glissada2" disable overlap}
			{volumes "glissada1" enable overlap}
			{tags add "cwship_glissada1"}
	    }
	    {delay 7 "cwship_reload_landing" 
			{call "reload_landing"}
			{with_linked_entity "landing_sys" {call "stop_landing"}}
	     }
	}

	{on "reload_landing"
		{kill_delay "cwship_reload_landing"}
		{volumes "glissada" disable overlap}
		{volumes "glissada1" disable overlap}
		{volumes "glissada2" enable overlap}
		{tags remove "cwship_glissada1"}
		{tags remove "cwship_glissada"}
	}
	{on "landing_plane"
		{ani_play "landing" callback}
		{with_linked_entity "landing" 
			{tags remove "cwship_landing_plane"} 
			{chassis_work 0}{physics_work 0} {call "landing_load"}{ani_wind "fly" end}
			{delay 0.1
				{set "engine_started" 1}
				{ani_play "engine_work" loop}
				{play_sound "engine_work" 1}
				{view start "engine_steam1"}
				{view start "engine_steam2"}
			
			}

		}
	}
	{on animation_end "landing"
		{with_linked_entity "landing" 
			{call "engine_stop"}
			{delay 1 {ani_play "close_wings"}}
		}
	}
	

;===============================Взлет


	
	{on "specability" overload
		{if tagged "cwship_pl1_busy"
			{tags remove "cwship_hangar_full"}
			{tags remove "cwship_pl1_busy"}
			{delay 3 {ani_play "launching1" callback}}
			{with_linked_entity "landing" 
				{ani_play "close_wings" -1}
				{delay 2
					{call "engine_on"}
				}
			}
		}
	}

	{on animation_end "launching1"
		{with_linked_entity "landing" 
			{call "script_overburn_off" }
			{tags add "cwship_launched_plane"}{chassis_work 1}{physics_work 1} 
			{delay 1 {tags remove "cwship_launched_plane"}}
			{call "takeoff_load"}
		}
	}
}

{"submarine"
	{on spawn
		{if not tagged "destroyed"	{add_view	"submarine"	"submarine"	"basis"}}
		{tags remove "submerge_busy"}
		{if  tagged "submerged" 
			{ani_wind "submerge" end}
			{volumes "hull" disable contact_ground}
			{volumes "hull_vis" disable bullet visible}
			{components "bodysub" break}
			{if not tagged "destroyed" {view start "submarine"}	{view show "submarine"}}
		else  
			{ani_wind "submerge" begin}
			{volumes "hull_vis" enable bullet visible}
			{volumes "hull" enable contact_ground}
			{if work "body"	{components "bodymsub" repair}}
			{if work "body1"	{components "body1sub" repair}}
			{if work "body2"	{components "body2sub" repair}}
			{if work "body3"	{components "body3sub" repair}}
			{if work "body4"	{components "body4sub" repair}}
			{view pause "submarine"}
			{view hide "submarine"}
		}
	}
	{on "cwsh_switch_hatch"
		{if not tagged "anten_up"
			{ani_play "anten_up"}
			{ani_play "cover_open"}
			{tags add "anten_up"}
			
		else
			{ani_play "anten_up" -1}
			{ani_play "cover_open" -1}
			{tags remove "anten_up"}
		}
	}
	{on "update_wash"
		{if  tagged "submerged"
			{view pause "on_stead"}
			{view pause "on_move"}
			{view pause "on_move_normal"}
			{view pause "on_move_fast"}
		else velocity 1 {view start "on_move"}{view pause "on_stead"} {call "check_water_level"}
		else {view pause "on_move"}{view start "on_stead"} {call "check_water_level"}
		}
	}
	{on "specability" overload
	  {if not tagged "submerge_busy"
		{if not tagged "submerged"
			{tags add "submerge_busy"}
			{ani_play "submerge"}
			{volumes "hull" disable contact_ground}
			{tags add "submerged"}
			{volumes "hull_vis" disable bullet visible}
			{delay 5 {tags remove "submerge_busy"} {call "check_hull_destroy"}}
			{delay 1 {call "update_wash"}}
			{components "bodysub" break}
			{view start "submarine"}
			{view show "submarine"}
		else
			{tags add "submerge_busy"}
			{ani_play "submerge_up"}
			{tags remove "submerged"}
			{volumes "hull_vis" enable bullet visible}
			{delay 5 {tags remove "submerge_busy"}{volumes "hull" enable contact_ground}}
			{delay 2 {call "update_wash"}}
			{if work "body"	{components "bodymsub" repair}}
			{if work "body1"	{components "body1sub" repair}}
			{if work "body2"	{components "body2sub" repair}}
			{if work "body3"	{components "body3sub" repair}}
			{if work "body4"	{components "body4sub" repair}}
			{view pause "submarine"}
			{view hide "submarine"}
		}
	  }
	}
	{on "check_hull_destroy"
	  {if not flag "broken"
	    {if not tagged "submerged"
		  {if tagged "cwship_body_break"
	        {if tagged "cwship_body1_break" {call "break_and_sink"}
			else tagged "cwship_body2_break" {call "break_and_sink"}
			else tagged "cwship_body3_break" {call "break_and_sink"}
			else tagged "cwship_body4_break" {call "break_and_sink"}
	        }
		  else tagged "cwship_body1_break"
	        {if tagged "cwship_body2_break" {call "break_and_sink"}
			else tagged "cwship_body3_break" {call "break_and_sink"}
			else tagged "cwship_body4_break" {call "break_and_sink"}
	        }
		  else tagged "cwship_body2_break"
	        {if tagged "cwship_body3_break" {call "break_and_sink"}
			else tagged "cwship_body4_break" {call "break_and_sink"}
	        }
		  else tagged "cwship_body3_break"
	        {if tagged "cwship_body4_break" {call "break_and_sink"}
	        }
	      }
		else
			{if tagged "cwship_body_break" {call "break_and_sink"}
			else tagged "cwship_body1_break" {call "break_and_sink"}
			else tagged "cwship_body2_break" {call "break_and_sink"}
			else tagged "cwship_body3_break" {call "break_and_sink"}
			else tagged "cwship_body4_break" {call "break_and_sink"}
	        }
		}
	   }
	}
}
{"linked_lamp"
	{on "lights_on"
		{view start "light"}
		{view show "light"}
	}
	{on "lights_off"
		{view stop "light"}
		{view hide "light"}
	}
	{on "update_lights"
		{if not sunlight
			{if not tagged "crushed"
				{call "lights_on"}
			else
				{call "lights_off"}
			}
		}
	}
	{on "break"
		{view stop "light"}
		{view hide "light"}
		{spawn "glass_hit" "lamp_light_point" x}
		{spawn "glass_hit" "lamp_light_point1" x}
		{spawn "glass_hit" "lamp_light_point2" x}
		{spawn "glass_hit" "lamp_light_point3" x}
		{spawn "glass_hit" "lamp_light_point4" x}
		{spawn "glass_hit" "lamp_light_point5" x}
		{set_skeleton "_x" sync}
	}
}
{"lamp_directional"
	{on spawn
		{add_view 	"light_boat_dir"		"light"			"lamp_light_point1"}
		{add_view 	"light_boat_dir"		"light"			"lamp_light_point2"}
		{add_view 	"light_marine_plafond"	"light"			"light_point"}
		{call "lights_off"}
		{call "update_lights"}
	}
}
{"lamp_omni"
	{on spawn
		{add_view 	"light_post_plafond"		"light"			"lamp_light_point1"}
		{add_view 	"light_post_point"			"light"			"light_point"}
		{call "lights_off"}
		{call "update_lights"}
	}
}
{"depth_charge"
	{on spawn 
		{ani_play "start" 10} 
		{delay 0.1 {call "cycle"}}
		{volumes "proximity" enable contact contact_ground}
		{delay 20 2  {call "detonate"}}
	}
;	{on animation_end "start" {call "detonate"}}
	{on ground_hit {call "detonate"}}
	{on contact {call "detonate"}}
	{on "detonate"
		{if not flag "broken"
			{set "broken" 1}
			{volumes disable blast}
			{stuff_detonate}

		}
	}
	{on "cycle" {impulse up -20 com} {delay 0.5 {call "cycle"}}}
}
(include "marine_modern.inc")


