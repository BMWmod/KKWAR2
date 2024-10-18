
{"nimitz_flols"
	{on spawn
		{add_view	"gabarit_blue"	"ready_to_land"	"flols_ready1"}
		{add_view	"gabarit_blue"	"ready_to_land"	"flols_ready2"}
		{add_view	"gabarit_blue"	"ready_to_land"	"flols_ready3"}
		{add_view	"gabarit_blue"	"ready_to_land"	"flols_ready4"}
		{add_view	"gabarit_yellow_big"	"flols_center"	"flols_center"}
		{add_view	"gabarit_blue_big"	"ready_to_land"	"flols_readyh1"}
		{add_view	"gabarit_blue_big"	"ready_to_land"	"flols_readyh2"}
		{add_view	"gabarit_blue_big"	"ready_to_land"	"flols_readyh3"}
		{add_view	"gabarit_blue_big"	"ready_to_land"	"flols_readyh4"}
		{add_view	"gabarit_yellow_verybig"	"flols_center"	"flols_centerh"}
		{view hide "ready_to_land"}
		{view hide "flols_center"}
		{bone hide "flols_helper"}
	}
	{on "enable"
		{tags add "cwship_flols_work"}
		{bone show "flols_helper"}
		{call "loop_detect"}
	}
	{on "indicate_readiness"
		{view show "ready_to_land"} {view start "ready_to_land"}
	}
	{on "final"
		{tags remove "cwship_flols_work"}
		{view show "flols_center"} {view start "flols_center"}
		{delay 5 {view hide "flols_center"}}
	}
	{on "stop_landing"
		{view hide "ready_to_land"}
		{view hide "flols_center"}
		{tags remove "cwship_flols_work"}
		{with_linked_entity "nimitz_flols_low" 
			{view show "abort"} {view start "abort"}
			{delay 10 {view hide "abort"}}
		}
		{delay 10 {bone hide "flols_helper"}}
		{for_each_link {call "turn_off"}}
	}
	{on "loop_detect"
		{if tagged "cwship_flols_work" {delay 0.2 {call "loop_detect"}}
			{for_each_link {call "check"}}
		else
			{for_each_link {call "turn_off"}}
		}
	}
}
{"flols_detector"
	{on overlap begin
		{if effector "Airborne_M"
			{set "radar_up" 1}
		else effector "Helicopter_M"
			{set "radar_up" 1}
		}
	}
	{on overlap end
		{set "radar_up" 0}
		{view hide "detection"}
	}
	{on "check"
		{if flag "radar_up" 
			{view show "detection"} 
			{view start "detection"} 
		}
	}
	{on "turn_off"
		{view hide "detection"}
	}
}
{"nimitz_flols_high"
     {on spawn
	{add_view	"gabarit_yellow_big"	"detection"	"flols_up1"}
	{add_view	"gabarit_red"	"detection"	"flols_up2"}
	{add_view	"gabarit_red"	"detection"	"flols_up3"}
	{add_view	"gabarit_red"	"detection"	"flols_up4"}
	{add_view	"gabarit_red"	"detection"	"flols_up5"}
	{add_view	"gabarit_yellow_verybig"	"detection"	"flols_uph1"}
	{add_view	"gabarit_red_big"	"detection"	"flols_uph2"}
	{add_view	"gabarit_red_big"	"detection"	"flols_uph3"}
	{add_view	"gabarit_red_big"	"detection"	"flols_uph4"}
	{add_view	"gabarit_red_big"	"detection"	"flols_uph5"}
	{view hide "detection"}

     }
}
{"nimitz_flols_low"
     {on spawn
	{add_view	"gabarit_red"	"detection"	"flols_down1"}
	{add_view	"gabarit_red"	"abort"		"flols_down2"}
	{add_view	"gabarit_red"	"abort"		"flols_down3"}
	{add_view	"gabarit_red"	"abort"		"flols_down4"}
	{add_view	"gabarit_red"	"abort"		"flols_down5"}
	{add_view	"gabarit_red"	"abort"		"flols_down6"}
	{add_view	"gabarit_red"	"abort"		"flols_down7"}
	{add_view	"gabarit_red"	"abort"		"flols_down8"}
	{add_view	"gabarit_red"	"abort"		"flols_down9"}
	{add_view	"gabarit_red_verybig"	"detection"	"flols_downh1"}
	{add_view	"gabarit_red_big"	"abort"		"flols_downh2"}
	{add_view	"gabarit_red_big"	"abort"		"flols_downh3"}
	{add_view	"gabarit_red_big"	"abort"		"flols_downh4"}
	{add_view	"gabarit_red_big"	"abort"		"flols_downh5"}
	{add_view	"gabarit_red_big"	"abort"		"flols_downh6"}
	{add_view	"gabarit_red_big"	"abort"		"flols_downh7"}
	{add_view	"gabarit_red_big"	"abort"		"flols_downh8"}
	{add_view	"gabarit_red_big"	"abort"		"flols_downh9"}
	{view hide "detection"}
	{view hide "abort"}

     }
}
{"nimitz_flols_left"
     {on spawn
	{add_view	"gabarit_blue"	"detection"	"flols_left1"}
	{add_view	"gabarit_blue"	"detection"	"flols_left2"}
	{add_view	"gabarit_blue"	"detection"	"flols_left3"}
	{add_view	"gabarit_blue"	"detection"	"flols_left4"}
	{add_view	"gabarit_blue"	"detection"	"flols_left5"}
	{add_view	"gabarit_blue"	"detection"	"flols_left6"}
	{add_view	"gabarit_blue_big"	"detection"	"flols_lefth1"}
	{add_view	"gabarit_blue_big"	"detection"	"flols_lefth2"}
	{add_view	"gabarit_blue_big"	"detection"	"flols_lefth3"}
	{add_view	"gabarit_blue_big"	"detection"	"flols_lefth4"}
	{add_view	"gabarit_blue_big"	"detection"	"flols_lefth5"}
	{add_view	"gabarit_blue_big"	"detection"	"flols_lefth6"}
	{view hide "detection"}
     }
}
{"nimitz_flols_right"
     {on spawn
	{add_view	"gabarit_blue"	"detection"	"flols_right1"}
	{add_view	"gabarit_blue"	"detection"	"flols_right2"}
	{add_view	"gabarit_blue"	"detection"	"flols_right3"}
	{add_view	"gabarit_blue"	"detection"	"flols_right4"}
	{add_view	"gabarit_blue"	"detection"	"flols_right5"}
	{add_view	"gabarit_blue"	"detection"	"flols_right6"}
	{add_view	"gabarit_blue_big"	"detection"	"flols_righth1"}
	{add_view	"gabarit_blue_big"	"detection"	"flols_righth2"}
	{add_view	"gabarit_blue_big"	"detection"	"flols_righth3"}
	{add_view	"gabarit_blue_big"	"detection"	"flols_righth4"}
	{add_view	"gabarit_blue_big"	"detection"	"flols_righth5"}
	{add_view	"gabarit_blue_big"	"detection"	"flols_righth6"}
	{view hide "detection"}
     }
}

{"nimitz_main"
	{on spawn
		{tags add "nimitz"}
	}

;===============================Разрушаемость

	{on "sink"
		{ani_play "sink" 0.02 callback}
		{delay 15 15 {with_linked_entity "body3" {call "play_sink_sound"}}}
		{delay 15 15 {with_linked_entity "body1" {call "play_sink_sound"}}}
		{delay 15 15 {with_linked_entity "body" {call "play_sink_sound"}}}
		{delay 15 15 {with_linked_entity "body4" {call "play_sink_sound"}}}
	}
	{on "break_and_sink"
		{delay 5 {ani_play "break_nose" 0.05 callback}}
	}
	{on "explode_and_sink"
		     {delay 15
			{ani_play "break_bridge" callback}
			("sink_effect" effsize(big) bone(01) delay(0))
			("sink_effect" effsize(big) bone(02) delay(0))
			("break_delete_linked" name(bridge_radar1) delay(0))
			("break_delete_linked" name(bridge_radar2) delay(0))
			("break_delete_linked" name(bridge_radar3) delay(0))
			("break_delete_linked" name(bridge_radar_indish1) delay(0))
			("break_delete_linked" name(bridge_radar_indish2) delay(0))
			("break_delete_linked" name(bridge_radar_indish3) delay(0))
			("break_delete_linked" name(bridge_radar_indish4) delay(0))
			("break_delete_linked" name(bridge_radar_indish5) delay(0))
			("break_delete_linked" name(bridge_radar_indish5) delay(0))
			("break_delete_linked" name(machta_radar1) delay(0))
			("break_delete_linked" name(machta_radar2) delay(0))
			("break_delete_linked" name(machta_radar3) delay(0))
			{delay 0.5 ("cut_part_big" args bridge_anten)}
			
			("break_delete_linked" name(radar_machta_rad1) delay(0))
			("break_delete_linked" name(radar_machta_rad2) delay(0))
			("break_delete_linked" name(radar_machta_rad3) delay(0))
			{delay 1.2 ("cut_part_big" args radar_machta)}
			
			("break_delete_linked" name(bridge_lamp1) delay(0))
			("break_delete_linked" name(bridge_lamp2) delay(0))
			("break_delete_linked" name(bridge_lamp3) delay(0))
			("break_delete_linked" name(bridge_lamp4) delay(0))
			("break_delete_linked" name(bridge_lamp5) delay(0))
			("break_delete_linked" name(bridge_lamp6) delay(0))
			("break_delete_linked" name(add_road_r2) delay(0))
			("break_delete_linked" name(stuff_point02) delay(0))
			("break_delete_linked" name(stuff_point03) delay(0))
			("break_delete_linked" name(stuff_point06) delay(0))
			("break_delete_linked" name(stuff_point09) delay(0))
			("break_delete_linked" name(stuff_point10) delay(0))
		     }
	}
	{on animation_end "break_nose"
			{with_linked_entity "body3"
				("break_delete_linked" name(add_road_r3) delay(0))
				("break_delete_linked" name(point_def1) delay(0))
				("break_delete_linked" name(point_def2) delay(0))
				("break_delete_linked" name(point_def3) delay(0))
				{if not tagged "no_hull_cut"
					{delay 0.5
						{tear "ship_part" bone "body3"
							{impulse up -1 dir 1 1 cx 1 1 cy 1 1 rnd_dir 2 no_position}
							{volumes disable float}
						}
					}
				}
			}
	}
	{on animation_end "break_bridge"
		{if not tagged "no_hull_cut"
			{tear "ship_part" bone "bridge_holder"
				{impulse up -1 dir 1 1 cx 1 1 cy 1 1 rnd_dir 2 no_position}
			}
		}
	}
	{on animation_end "sink"
		{view pause "on_stead"}
		{view pause "on_move"}
		{call "stop_sink_sound"}
		{with_linked_entity "body1"
			{view pause "on_stead"}
			{view pause "on_move"}
			{call "stop_sink_sound"}
		}
		{with_linked_entity "body3"
			{view pause "on_stead"}
			{view pause "on_move"}
			{call "stop_sink_sound"}
		}
		{with_linked_entity "body4"
			{view pause "on_stead"}
			{view pause "on_move"}
			{call "stop_sink_sound"}
		}
		{with_linked_entity "body"
			{view pause "on_stead"}
			{view pause "on_move"}
			{call "stop_sink_sound"}
		}
		
	}
	{on "sink_sequence"
		{add_view "fx_bubbles_big" "FXfire_basis" "body2"}
		{view start "FXfire_basis"}
		{delay 20 
			{view pause "on_stead"}
			{view pause "on_move"}
		}
		{delay 1.5 {with_linked_entity "standing1" {tags add "no_messages"} {physics_work 1} {call "explosion"}}}
		{delay 1.5 {with_linked_entity "standing2" {tags add "no_messages"} {physics_work 1} {call "explosion"}}}
		{delay 1.5 {with_linked_entity "standing3" {tags add "no_messages"} {physics_work 1} {call "explosion"}}}
		{delay 1.5 {with_linked_entity "standing4" {tags add "no_messages"} {physics_work 1} {call "explosion"}}}

		{delay 1.5 {with_linked_entity "standing5" {tags add "no_messages"} {physics_work 1} {call "explosion"}}}
		{delay 1.5 {with_linked_entity "standing6" {tags add "no_messages"} {physics_work 1} {call "explosion"}}}
		{delay 1.5 {with_linked_entity "standing7" {tags add "no_messages"} {physics_work 1} {call "explosion"}}}
		{delay 1.5 {with_linked_entity "standing8" {tags add "no_messages"} {physics_work 1} {call "explosion"}}}

		{delay 1.5 {with_linked_entity "standing9" {tags add "no_messages"} {physics_work 1} {call "explosion"}}}
		{delay 1.5 {with_linked_entity "standing10" {tags add "no_messages"} {physics_work 1} {call "explosion"}}}
		{delay 1.5 {with_linked_entity "launching1" {tags add "no_messages"} {physics_work 1} {call "explosion"}}}
		{delay 1.5 {with_linked_entity "launching2" {tags add "no_messages"} {physics_work 1} {call "explosion"}}}
		{delay 1.5 {with_linked_entity "landing" {tags add "no_messages"} {physics_work 1} {call "explosion"}}}
		
;		{delay 2.5 {with_linked_entity "standing1" {tags add "no_messages"} {physics_work 1} {call "explosion"}}}
;		{delay 2.5 {with_linked_entity "standing2" {tags add "no_messages"} {physics_work 1} {call "explosion"}}}
;		{delay 2.5 {with_linked_entity "standing3" {tags add "no_messages"} {physics_work 1} {call "explosion"}}}
;		{delay 2.5 {with_linked_entity "standing4" {tags add "no_messages"} {physics_work 1} {call "explosion"}}}
;
;		{delay 2.5 {with_linked_entity "standing5" {tags add "no_messages"} {physics_work 1} {call "explosion"}}}
;		{delay 2.5 {with_linked_entity "standing6" {tags add "no_messages"} {physics_work 1} {call "explosion"}}}
;		{delay 2.5 {with_linked_entity "standing7" {tags add "no_messages"} {physics_work 1} {call "explosion"}}}
;		{delay 2.5 {with_linked_entity "standing8" {tags add "no_messages"} {physics_work 1} {call "explosion"}}}
;
;		{delay 2.5 {with_linked_entity "standing9" {tags add "no_messages"} {physics_work 1} {call "explosion"}}}
;		{delay 2.5 {with_linked_entity "standing10" {tags add "no_messages"} {physics_work 1} {call "explosion"}}}
;		{delay 2.5 {with_linked_entity "launching1" {tags add "no_messages"} {physics_work 1} {call "explosion"}}}
;		{delay 2.5 {with_linked_entity "launching2" {tags add "no_messages"} {physics_work 1} {call "explosion"}}}
;		{delay 2.5 {with_linked_entity "landing" {tags add "no_messages"} {physics_work 1} {call "explosion"}}}
		
		("sink_effect" effsize(small) bone(01) delay(15 15))
		("sink_effect" effsize(small) bone(02) delay(15 15))
		("sink_effect" effsize(small) bone(03) delay(15 15))
		("sink_effect" effsize(small) bone(04) delay(30 15))
		("sink_effect" effsize(small) bone(05) delay(30 15))
		("sink_effect" effsize(small) bone(06) delay(30 15))
		("sink_effect" effsize(small) bone(07) delay(45 15))
		("sink_effect" effsize(small) bone(08) delay(45 15))
		("sink_effect" effsize(small) bone(09) delay(45 15))
		("sink_effect" effsize(small) bone(10) delay(45 15))
		("sink_effect" effsize(norm) bone(01) delay(30 15))
		("sink_effect" effsize(norm) bone(02) delay(15 15))
		("sink_effect" effsize(norm) bone(03) delay(45 15))
		("sink_effect" effsize(norm) bone(04) delay(15 15))
		("sink_effect" effsize(norm) bone(05) delay(45 15))
		("sink_effect" effsize(norm) bone(06) delay(30 15))
		("sink_effect" effsize(norm) bone(07) delay(15 15))
		("sink_effect" effsize(norm) bone(08) delay(45 15))
		("sink_effect" effsize(norm) bone(09) delay(30 15))
		{delay 25 10 ("sink_effect" effsize(norm) bone(10) delay(0))
			("cut_part" args blastshield3)
		}
		{delay 40 10 ("sink_effect" effsize(norm) bone(11) delay(0))
			("cut_part" args blastshield4)
		}
		
		("break_delete_linked" name(machta_radar1) delay(15 5))
		("break_delete_linked" name(machta_radar2) delay(15 5))
		("break_delete_linked" name(machta_radar3) delay(15 5))
		{delay 20 ("cut_part_big" args bridge_anten)}
		
		("break_delete_linked" name(radar_machta_rad1) delay(25 5))
		("break_delete_linked" name(radar_machta_rad2) delay(25 5))
		("break_delete_linked" name(radar_machta_rad3) delay(25 5))
		{delay 30 ("cut_part_big" args radar_machta)}
		
		("break_linked" name(bridge_radar1) delay(45 30))
		("break_linked" name(bridge_radar2) delay(45 30))
		("break_linked" name(bridge_radar3) delay(45 30))
		("break_linked" name(bridge_radar_indish1) delay(45 30))
		("break_linked" name(bridge_radar_indish2) delay(45 30))
		("break_linked" name(bridge_radar_indish3) delay(45 30))
		("break_linked" name(bridge_radar_indish4) delay(45 30))
		("break_linked" name(bridge_radar_indish5) delay(45 30))
		("break_linked" name(bridge_radar_indish5) delay(45 30))
		("break_linked" name(add_road_r2) delay(45 30))
		("break_linked" name(landing_sys) delay(45 30))
		("tear_linked" name(stuff_point01) delay(45 30))
		("break_linked" name(stuff_point02) delay(45 30))
		("break_linked" name(stuff_point03) delay(45 30))
		("tear_linked" name(stuff_point04) delay(45 30))
		("tear_linked" name(stuff_point05) delay(45 30))
		("break_linked" name(stuff_point06) delay(45 30))
		("tear_linked" name(stuff_point07) delay(45 30))
		("tear_linked" name(stuff_point08) delay(45 30))
		("break_linked" name(stuff_point09) delay(45 30))
		("break_linked" name(stuff_point10) delay(45 30))
		
		("tear_linked" name(standing1) delay(45 30))
		("tear_linked" name(standing6) delay(45 30))
		("tear_linked" name(standing7) delay(45 30))
		("tear_linked" name(standing8) delay(45 30))
		{delay 30 30 {with_linked_entity "bridge_lamp1" {call "lights_off"}}}
		{delay 30 30 {with_linked_entity "bridge_lamp2" {call "lights_off"}}}
		{delay 30 30 {with_linked_entity "bridge_lamp3" {call "lights_off"}}}
		{delay 30 30 {with_linked_entity "bridge_lamp4" {call "lights_off"}}}
		{delay 30 30 {with_linked_entity "bridge_lamp5" {call "lights_off"}}}
		{delay 30 30 {with_linked_entity "bridge_lamp6" {call "lights_off"}}}

		{with_linked_entity "body1"
			{add_view "fx_bubbles_big" "FXfire_basis" "body1"}
			{view start "FXfire_basis"}
			("sink_effect" effsize(small) bone(01) delay(15 15))
			("sink_effect" effsize(small) bone(02) delay(15 15))
			("sink_effect" effsize(small) bone(03) delay(30 15))
			("sink_effect" effsize(small) bone(04) delay(30 15))
			("sink_effect" effsize(small) bone(05) delay(45 15))
			{delay 30 5 ("sink_effect" effsize(norm) bone(01) delay(0))
				("cut_part" args blastshield1)
			}
			("sink_effect" effsize(big) bone(01) delay(0))
			("sink_effect" effsize(big) bone(02) delay(0))
			("tear_linked" name(stuff_point15) delay(30 30))
		}
		{with_linked_entity "body"
			{add_view "fx_bubbles_big" "FXfire_basis" "body"}
			{view start "FXfire_basis"}
			("sink_effect" effsize(small) bone(01) delay(15 15))
			("sink_effect" effsize(small) bone(02) delay(15 15))
			("sink_effect" effsize(small) bone(03) delay(15 15))
			("sink_effect" effsize(small) bone(04) delay(15 15))
			("sink_effect" effsize(small) bone(05) delay(15 15))
			("sink_effect" effsize(small) bone(06) delay(30 15))
			("sink_effect" effsize(small) bone(07) delay(30 15))
			("sink_effect" effsize(small) bone(08) delay(30 15))
			("sink_effect" effsize(small) bone(09) delay(30 15))
			("sink_effect" effsize(small) bone(10) delay(30 15))
			("sink_effect" effsize(norm) bone(01) delay(15 15))
			("sink_effect" effsize(norm) bone(02) delay(15 15))
			("sink_effect" effsize(norm) bone(03) delay(15 15))
			("sink_effect" effsize(norm) bone(04) delay(15 15))
			{delay 40 10 ("sink_effect" effsize(norm) bone(05) delay(0))
				("cut_part" args blastshield2)
			}
			{delay 15 15 
				("sink_effect" effsize(big) bone(01) delay(0))
				("sink_effect" effsize(big) bone(02) delay(0))
				("cut_part_big" args lift1)
				("cut_part" args lift1_doorR)
				("cut_part" args lift1_doorL)
			}
			{delay 30 15 
				("sink_effect" effsize(big) bone(03) delay(0))
				("sink_effect" effsize(big) bone(04) delay(0))
				("cut_part_big" args lift2)
				("cut_part" args lift2_doorR)
				("cut_part" args lift2_doorL)
			}
			("break_linked" name(targ_radar_l1) delay(30 30))
			("break_linked" name(targ_radar_l2) delay(30 30))
			("break_linked" name(add_road_r) delay(30 30))
			("break_linked" name(add_road_l) delay(30 30))
			("tear_linked" name(stuff_point14) delay(30 30))
		}
		{with_linked_entity "body4"
			{add_view "fx_bubbles_big" "FXfire_basis" "body4"}
			{view start "FXfire_basis"}
			("sink_effect" effsize(small) bone(01) delay(15 15))
			("sink_effect" effsize(small) bone(02) delay(15 15))
			("sink_effect" effsize(small) bone(03) delay(15 15))
			("sink_effect" effsize(small) bone(04) delay(15 15))
			("sink_effect" effsize(small) bone(05) delay(15 15))
			("sink_effect" effsize(small) bone(06) delay(30 15))
			("sink_effect" effsize(small) bone(07) delay(30 15))
			("sink_effect" effsize(small) bone(08) delay(30 15))
			("sink_effect" effsize(norm) bone(01) delay(15 15))
			("sink_effect" effsize(norm) bone(02) delay(15 15))
			("sink_effect" effsize(norm) bone(03) delay(15 15))
			{delay 15 15 
				("sink_effect" effsize(big) bone(01) delay(0))
				("sink_effect" effsize(big) bone(02) delay(0))
				("cut_part_big" args lift3)
				("cut_part" args lift3_doorR)
				("cut_part" args lift3_doorL)
			}
			{delay 30 15 
				("sink_effect" effsize(big) bone(03) delay(0))
				("sink_effect" effsize(big) bone(04) delay(0))
				("cut_part_big" args lift4)
				("cut_part" args lift4_doorR)
				("cut_part" args lift4_doorL)
			}
			{delay 30 15
				("sink_effect" effsize(big) bone(05) delay(0))
				("sink_effect" effsize(big) bone(06) delay(0))
			}
			("break_linked" name(point_def4) delay(30 30))
			("break_linked" name(point_def5) delay(30 30))
			("break_linked" name(point_def6) delay(30 30))
			("break_linked" name(point_def7) delay(30 30))
			("break_linked" name(point_def8) delay(30 30))
			("break_linked" name(targ_radar_l3) delay(30 30))
			("break_linked" name(landingpost) delay(30 30))
			("break_linked" name(add_road_r1) delay(30 30))
			("break_linked" name(stuff_point11) delay(30 30))
			("tear_linked" name(stuff_point12) delay(30 30))
			("tear_linked" name(stuff_point13) delay(30 30))
		}
		{with_linked_entity "body3"
			("break_linked" name(add_road_r3) delay(5 5))
			{delay 3 2
				("break_linked" name(point_def1) delay(0))
				{delay 0.5 
					("break_delete_linked" name(point_def1) delay(0))
					{delay 0.5 ("cut_part_big" args part1_big)}
				}
			}
			{delay 3 2
				("break_linked" name(point_def2) delay(0))
				("break_linked" name(point_def3) delay(0))
				{delay 0.5 
					("break_delete_linked" name(point_def2) delay(0))
					("break_delete_linked" name(point_def3) delay(0))
					{delay 0.5 ("cut_part_big" args part2_big)}
				}
			}
		}
	}
	{on break
		{if component "body3"
			{with_linked_entity "body3"
				{delay 3 2
					("break_linked" name(point_def1) delay(0))
					{delay 0.5 
						("break_delete_linked" name(point_def1) delay(0))
						("cut_part_big" args part1_big)
					}
				}
				{delay 3 2
					("break_linked" name(point_def2) delay(0))
					("break_linked" name(point_def3) delay(0))
					{delay 0.5 
						("break_delete_linked" name(point_def2) delay(0))
						("break_delete_linked" name(point_def3) delay(0))
						("cut_part_big" args part2_big)
					}
				}
			}
		else component "body1"
			{with_linked_entity "body3"
				("break_linked" name(add_road_r3) delay(0))
			}
			{with_linked_entity "body1"
				("break_effect" effsize(small) bone(01) delay(0))
				("break_effect" effsize(small) bone(04) delay(0))
				("break_effect" effsize(small) bone(05) delay(0))
			}
		else component "body"
			{with_linked_entity "body3"
				("break_effect" effsize(big) bone(05) delay(0))
				("break_effect" effsize(norm) bone(01) delay(0))
				("break_effect" effsize(norm) bone(04) delay(0))
				("break_linked" name(targ_radar_l1) delay(15 7))
				("break_linked" name(targ_radar_l2) delay(15 7))
			}
		else component "body2"
			("break_effect" effsize(big) bone(03) delay(0))
			("break_effect" effsize(norm) bone(06) delay(0))
			("break_effect" effsize(norm) bone(07) delay(0))
		else component "body4"
			{with_linked_entity "body4"
				("break_effect" effsize(big) bone(07) delay(0))
				("break_linked" name(point_def4) delay(15 7))
				("break_linked" name(point_def5) delay(15 7))
				("break_linked" name(point_def6) delay(15 7))
				("break_linked" name(point_def7) delay(15 7))
				("break_linked" name(point_def8) delay(15 7))
				("sink_effect" effsize(small) bone(02) delay(0))
				("sink_effect" effsize(small) bone(04) delay(0))
			}
		else component "bridge"
			("break_linked" name(bridge_lamp1) delay(0))
			("break_linked" name(bridge_lamp2) delay(0))
			("break_linked" name(bridge_lamp3) delay(0))
			("break_linked" name(bridge_lamp4) delay(0))
			("break_linked" name(bridge_lamp5) delay(0))
			("break_linked" name(bridge_lamp6) delay(0))
		else component "bridge_support"
			("break_effect" effsize(norm) bone(03) delay(0))
		}
	}
	{on "cut_parts" overload
		("break_delete_linked" name(point_def1) delay(0))
		("break_delete_linked" name(point_def2) delay(0))
		("break_delete_linked" name(point_def3) delay(0))
		{delay 0.5
			("cut_part_big" args part1_big)
			("cut_part_big" args part2_big)
			("cut_part_big" args part3_big)
			("cut_part_big" args part4_big)
			("cut_part_big" args part5_big)
			("cut_part_big" args part6_big)
		}
	}
	{on break_armor overload
		{component break}
		{if volume "float"
			{call "break_float"}
		}
		{if component "part1_big"
			("break_delete_linked" name(point_def1) delay(0))
			{delay 0.5 ("cut_part_big" args part1_big)}
		else component "part2_big"
			("break_delete_linked" name(point_def2) delay(0))
			("break_delete_linked" name(point_def3) delay(0))
			{delay 0.5 ("cut_part_big" args part2_big)}
		else component "part3_big"
			("cut_part_big" args part3_big)
		else component "part4_big"
			("cut_part_big" args part4_big)
		else component "part5_big"
			("cut_part_big" args part5_big)
		else component "part6_big"
			("cut_part_big" args part6_big)
		}
	}
}
{"nimitz_main_cvn75"
	{on spawn
	       {delay 0.5
		{with_linked_entity "body4"
			{bone cut "point_def_support4"}
		}
	       }
	}
}
{"Arley_Burke"
;===============================Разрушаемость
	{on "sink"
		{ani_play "sink" 0.02 callback}
	}
	{on "break_and_sink"
		{if tagged "cwship_body3_break" {ani_play "break_nose" 0.05 callback}}
		{if tagged "cwship_body4_break" {ani_play "break_rear" 0.05 callback}}
	}
	{on animation_end "break_nose"
		("break_delete_linked" name(missile1) delay(0))
		("break_delete_linked" name(maingun) delay(0))
		{if not tagged "no_hull_cut"
			{delay 0.5
				{tear "ship_part" bone "body3"
					{impulse up -1 dir 1 1 cx 1 1 cy 1 1 rnd_dir 2 no_position}
					{volumes disable float}
				}
			}
		}
	}
	{on animation_end "break_rear"
		{delay 0.5
			{if not tagged "no_hull_cut"
				{tear "ship_part" bone "body4"
					{impulse up -1 dir 1 1 cx 1 1 cy 1 1 rnd_dir 2 no_position}
					{volumes disable float}
				}
			}
		}
	}
	{on animation_end "sink"
		{view pause "on_stead"}
		{view pause "on_move"}
		{call "stop_sink_sound"}
	}
	{on "sink_sequence"
		{add_view "fx_bubbles_big" "FXfire_basis" "body"}
		{add_view "fx_bubbles_big" "FXfire_basis" "body1"}
		{add_view "fx_bubbles_big" "FXfire_basis" "body2"}
		{add_view "fx_bubbles_big" "FXfire_basis" "body3"}
		{add_view "fx_bubbles_big" "FXfire_basis" "body4"}
		{view start "FXfire_basis"}
		{delay 20 
			{view pause "on_stead"}
			{view pause "on_move"}
		}
		{with_linked_entity "vehicle9" {delete}}

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
		("sink_effect" effsize(norm) bone(01) delay(20 12))
		("sink_effect" effsize(norm) bone(02) delay(10 10))
		("sink_effect" effsize(norm) bone(03) delay(30 15))
		("sink_effect" effsize(norm) bone(04) delay(10 10))
		("sink_effect" effsize(norm) bone(05) delay(30 15))
		("sink_effect" effsize(norm) bone(06) delay(20 12))
		("sink_effect" effsize(norm) bone(07) delay(10 10))
		("sink_effect" effsize(norm) bone(08) delay(30 15))
		("sink_effect" effsize(norm) bone(09) delay(20 12))
		("sink_effect" effsize(norm) bone(10) delay(30 15))
		("sink_effect" effsize(norm) bone(11) delay(10 10))
		("sink_effect" effsize(norm) bone(12) delay(20 12))
		("sink_effect" effsize(norm) bone(13) delay(30 15))
		("sink_effect" effsize(big) bone(01) delay(30 15))
		("sink_effect" effsize(big) bone(02) delay(20 12))
		("break_linked" name(lamp_place1) delay(15 10))
		
		("break_delete_linked" name(lamp_place4) delay(10 5))
		("break_delete_linked" name(lamp_place5) delay(10 5))
		("break_delete_linked" name(lamp_place6) delay(10 5))
		{delay 15 ("cut_part_big" args bridge_anten)}
		{delay 10 5 ("cut_part" args part2_big)}
		{delay 10 5 ("cut_part" args part1_big)}
		
		
		("break_linked" name(bridge_radar1) delay(30 20))
		("break_linked" name(bridge_radar2) delay(30 20))
		("break_linked" name(bridge_radar3) delay(30 20))
		("break_linked" name(kranets_place1) delay(30 20))
		("break_linked" name(kranets_place2) delay(30 20))
		("break_linked" name(kranets_place3) delay(30 20))
		("break_linked" name(kranets_place4) delay(30 20))
		("break_linked" name(kranets_place5) delay(30 20))
		("break_linked" name(kranets_place6) delay(30 20))
		("break_linked" name(kranets_place7) delay(30 20))
		("break_linked" name(kranets_place8) delay(30 20))
		("break_linked" name(kranets_place9) delay(30 20))
		("break_linked" name(kranets_place10) delay(30 20))
		("break_linked" name(kranets_place11) delay(30 20))
		("break_linked" name(kranets_place12) delay(30 20))

		{delay 20 20 {with_linked_entity "lamp_place1" {call "lights_off"}}}
		{delay 20 20 {with_linked_entity "lamp_place2" {call "lights_off"}}}
		{delay 20 20 {with_linked_entity "lamp_place3" {call "lights_off"}}}
		{delay 20 20 {with_linked_entity "lamp_place7" {call "lights_off"}}}
		{delay 20 20 {with_linked_entity "lamp_place8" {call "lights_off"}}}
		{delay 20 20 {with_linked_entity "lamp_place9" {call "lights_off"}}}
		{delay 20 20 {with_linked_entity "lamp_place10" {call "lights_off"}}}
		{delay 20 20 {with_linked_entity "lamp_place11" {call "lights_off"}}}
		{delay 20 20 {with_linked_entity "lamp_place12" {call "lights_off"}}}
		
		("break_linked" name(maingun) delay(30 20))
		("break_linked" name(missile1) delay(30 20))
		("break_linked" name(missile2) delay(30 20))
		("break_linked" name(autocannon1_place) delay(30 20))
		("break_linked" name(autocannon2_place) delay(30 20))
		("break_linked" name(point_def1_place) delay(30 20))
		("break_linked" name(point_def2_place) delay(30 20))
		("break_linked" name(torpedo1_place) delay(30 20))
		("break_linked" name(torpedo2_place) delay(30 20))
		("break_linked" name(torpedo3_place) delay(30 20))
		("break_linked" name(torpedo4_place) delay(30 20))
		("break_linked" name(mgun1_place) delay(30 20))
		("break_linked" name(mgun2_place) delay(30 20))
	}
	{on break
		{if component "body3"
			("break_effect" effsize(big) bone(03) delay(0))
			("break_linked" name(maingun) delay(15 7))
			("break_linked" name(missile1) delay(15 7))
		else component "body1"
			("break_effect" effsize(norm) bone(02) delay(0))
		else component "body"
			("break_effect" effsize(big) bone(04) delay(0))
			("break_linked" name(point_def1_place) delay(15 7))
			("break_linked" name(torpedo3_place) delay(15 7))
			("break_linked" name(torpedo4_place) delay(15 7))
		else component "body2"
			("break_effect" effsize(big) bone(01) delay(0))
			("break_linked" name(torpedo1_place) delay(15 7))
			("break_linked" name(torpedo2_place) delay(15 7))
		else component "body4"
		else component "bridge"
			("break_effect" effsize(small) bone(02) delay(0))
			("break_effect" effsize(small) bone(03) delay(0))
			("break_linked" name(lamp_place1) delay(0))
		else component "bridge_support"
			("break_effect" effsize(norm) bone(07) delay(0))
			("break_effect" effsize(small) bone(01) delay(0))
			("break_linked" name(autocannon1_place) delay(15 7))
			("break_linked" name(autocannon2_place) delay(15 7))
			("break_linked" name(point_def2_place) delay(15 7))
		}
	}
	{on blast
	       {if min_energy 4
		{spawn "metal_hit_bul"}	;волей шайтана без этой записи передние двери не отрываются. Не удалять.
		{if volume "part1"
			("cut_part" args part1)
			{area disable "part1"}
		else volume "part2"
			("cut_part" args part2)
			{area disable "part2"}
		}
	       }
	}
}
{"arley_burke_with_land"
	{on spawn
	       {delay 0.1
		{if tagged "opened"
;			{tags add "opened"}
			{delay 0.1 {call "trap_open"}}
		}
	        }
	        {volumes  "hull" disable touch}
	}
	{on "init_effects" overload}
	{on "sink"
		{land off}
	}
	{on "trap_open"
		{ani_wind "dooropen" end}
		{delay 0.1
;			{with_linked_entity "maingun" {call "close"}}
;			{spawn "arley_burke_doorlb" "door_placelb" x}
;			{spawn "arley_burke_ doorrb" "door_placerb" x}
			{area disable "close"}
			{area disable "right"}
			{area enable "open1"}
			{area enable "open2"}
			{land off}
			{land on}
			{chassis_work 0}
			{physics_work 0}
		}
	}
	{on "check_hull_destroy" overload}
	{on break overload
		{if component "body3"
			("break_effect" effsize(big) bone(03) delay(0))
		else component "body1"
		else component "body"
			("break_effect" effsize(big) bone(04) delay(0))
		else component "body2"
			("break_effect" effsize(big) bone(01) delay(0))
		else component "body4"
		else component "bridge"
			("break_effect" effsize(small) bone(02) delay(0))
			("break_effect" effsize(small) bone(03) delay(0))
			("break_linked" name(lamp_place1) delay(0))
		else component "bridge_support"
			("break_effect" effsize(norm) bone(07) delay(0))
			("break_effect" effsize(small) bone(01) delay(0))
		}
	}
	{on "trap_close"
		{ani_play "dooropen" -1 callback}
	}
	{on animation_end "dooropen"
		{delay 0.1
			{area enable "close"}
			{area enable "right"}
			{area disable "open1"}
			{area disable "open2"}
			{land off}
			{land on}
			{chassis_work 0}
			{physics_work 0}
		}
	}
	{on "show_passages" {bone show "exterior"}}
	{on "hide_passages" {bone hide "exterior"}}
}

{"pr1234_ovod"
;===============================Разрушаемость
	{on "break_and_sink"
		{if not work "body1"
		   {if rand 0.5
			{ani_play "break_nose" 0.03 callback}
			{delay 2 {call "break_nose"}}
		   }
		}
		{if not work "body2"
		   {if rand 0.5
			{ani_play "break_rear" 0.03 callback}
			{delay 2 {call "break_rear"}}
		   }
		}
		{if work "body1"
			{delay 10 2 {call "sink_ballast"}}
		else work "body2"
			{delay 10 2 {call "sink_ballast"}}
		else
			{call "sink_ballast"}
		}
		{components break}
	}
	{on "break_nose"
		("break_delete_linked" name(point_def1_place) delay(0))
		("sink_effect" effsize(big) bone(02) delay(0))
		{delay 4 2 {volumes "ballast1" disable float} {impulse up 0.1}}
		{delay 4 2 {volumes "ballast2" disable float} {impulse up 0.1}}
		{delay 0.5
			{if not tagged "no_hull_cut"
				{tear "ship_part" bone "body1"
					{impulse up -1 dir 1 1 cx 1 1 cy 1 1 rnd_dir 2 no_position}
					{volumes disable float}
				}
			}
		}
	}
	{on "break_rear"
		("break_delete_linked" name(autocannon1_place) delay(0))
		("break_delete_linked" name(ak630radar) delay(0))
		("break_delete_linked" name(maingun) delay(0))
		("sink_effect" effsize(big) bone(03) delay(0))
		{delay 4 2 {volumes "ballast5" disable float} {impulse up 0.1}}
		{delay 4 2 {volumes "ballast6" disable float} {impulse up 0.1}}
		{delay 0.5
			{if not tagged "no_hull_cut"
				{tear "ship_part" bone "body2"
					{impulse up -1 dir 1 1 cx 1 1 cy 1 1 rnd_dir 2 no_position}
					{volumes disable float}
				}
			}
		}
	}
	{on animation_end "sink"
		{view pause "on_stead"}
		{view pause "on_move"}
		{call "stop_sink_sound"}
	}
	{on "sink_sequence"
		{delay 15 ("cut_part_big" args machta)}
		
		("break_linked" name(ak630radar) delay(20 15))
		("break_linked" name(osa_ma_rls_place) delay(20 15))
		("break_linked" name(maingun) delay(20 15))
		("break_linked" name(autocannon1_place) delay(20 15))
		("break_linked" name(missile1) delay(20 15))
		("break_linked" name(point_def1_place) delay(20 15))
	}
	{on break
		{if component "body1"
			("break_linked" name(point_def1_place) delay(15 7))
			("break_effect" effsize(big) bone(01) delay(0))
		else component "body"
			("break_effect" effsize(norm) bone(01) delay(0))
			("break_effect" effsize(norm) bone(02) delay(0))
			("break_linked" name(missile1) delay(15 7))
		else component "body2"
			("break_effect" effsize(norm) bone(03) delay(0))
			("break_effect" effsize(small) bone(01) delay(0))
			("break_linked" name(ak630radar) delay(15 7))
			("break_linked" name(autocannon1_place) delay(15 7))
			("break_linked" name(maingun) delay(15 7))
		else component "bridge"
			("break_effect" effsize(small) bone(07) delay(0))
			("break_effect" effsize(small) bone(09) delay(0))
		else component "bridge_support"
			("break_effect" effsize(small) bone(04) delay(0))
			("break_effect" effsize(small) bone(03) delay(0))
			("break_linked" name(osa_ma_rls_place) delay(15 7))
		}
	}
}
{"zubr"
	(define "zubr_fx"
		{add_view	"zubr_bigcloud_%fxtype"			"on_%terraintype"				"FX_cloud_big1"}
		{add_view	"zubr_bigcloud_%fxtype"			"on_%terraintype"				"FX_cloud_big2"}
		{add_view	"zubr_cloud_%fxtype"			"on_%terraintype"				"FX_cloud_medium1"}
		{add_view	"zubr_cloud_%fxtype"			"on_%terraintype"				"FX_cloud_medium2"}
		{add_view	"zubr_cloud_%fxtype"			"on_%terraintype"				"FX_cloud_medium3"}
		{add_view	"zubr_cloud_%fxtype"			"on_%terraintype"				"FX_cloud_medium4"}		
		{add_view	"zubr_cloud_%fxtype"			"on_%terraintype"				"FX_cloud_medium5"}	
		{add_view	"zubr_cloud_%fxtype"			"on_%terraintype"				"FX_cloud_medium6"}	
	)
	{on spawn
		{if not rain
			("zubr_fx" terraintype(ground) fxtype(ground))
			("zubr_fx" terraintype(grass) fxtype(ground))
			("zubr_fx" terraintype(sand) fxtype(sand))
			("zubr_fx" terraintype(country_road) fxtype(ground))
			("zubr_fx" terraintype(road) fxtype(road))
		}
		("zubr_fx" terraintype(water) fxtype(water))
		("zubr_fx" terraintype(mud) fxtype(water))
		("zubr_fx" terraintype(puddle) fxtype(water))
		("zubr_fx" terraintype(snow) fxtype(snow))
		{if not flag "engine_started"
			{ani_wind "zubr_start" end}
		}
		{tags add "dont_drop"}
	}
	{on "add_movement_sound" overload
		{add_view	"exhaust_dark_big"		"enginea_exhaust"		"enginea_exhaust"	}
		{add_view	"exhaust_dark_big"		"engineb_exhaust" 		"engineb_exhaust"	}
		{add_view	"exhaust_dark_big"		"enginec_exhaust"		"enginec_exhaust"	}
		{add_view	"exhaust_dark_big"		"engined_exhaust"		"FX_smoke_turbo4"	}
		{add_view	"exhaust_dark_big"		"engined_exhaust"		"FX_smoke_turbo5"	}
		
		{link_sound "waves"	"naval/move/ship_waves"}
		{link_sound "alarm"	"naval/alarm/Navysiren"}
		
		{link_sound "engine_start"		"vehicle/airborne/fw_start"			}
		{link_sound "engine_work"		"vehicle/airborne/fw_work"			}
		{link_sound "engine_stop"		"vehicle/airborne/fw_stop"			}
	}
	{on move on
		{call "engine_on"}
		{if tagged "cargo_open" {call "close_cargo"}}
	}
	{on move off
		{call "engine_stop"}
		{delay 0.1
			{if terrain_pp "ground"
				{view start "on_ground"}
			else terrain_pp "sand"
				{view start "on_sand"}		
			else terrain_pp "grass"
				{view start "on_grass"}	
			else terrain_pp "deep_water"
				{view start "on_water"}	
			else terrain_pp "water"
				{view start "on_water"}	
			else terrain_pp "shallow_water"
				{view start "on_puddle"}	
			else terrain_pp "puddle"
				{view start "on_puddle"}	
			else terrain_pp "mud"
				{view start "on_mud"}	
			else terrain_pp "country_road"
				{view start "on_country_road"}	
			else terrain_pp "snow"
				{view start "on_snow"}	
			}
		}
	}
	{on turn on
		{call "engine_on"}
		{if tagged "cargo_open" {call "close_cargo"}}
		{delay 0.1
			{if terrain_pp "ground"
				{view start "on_ground"}
			else terrain_pp "sand"
				{view start "on_sand"}		
			else terrain_pp "grass"
				{view start "on_grass"}	
			else terrain_pp "deep_water"
				{view start "on_water"}	
			else terrain_pp "water"
				{view start "on_water"}	
			else terrain_pp "shallow_water"
				{view start "on_puddle"}	
			else terrain_pp "puddle"
				{view start "on_puddle"}	
			else terrain_pp "mud"
				{view start "on_mud"}	
			else terrain_pp "country_road"
				{view start "on_country_road"}	
			else terrain_pp "snow"
				{view start "on_snow"}	
			}
		}
	}
	{on turn off
		{call "engine_stop"}
	}
	{on engine on overload
	}
	{on engine off overload
	}
	{on "engine_on" overload
		{kill_delay "engine_stopped"}
		{if not velocity 5 {call "close_rampa"} {set "specability" 0}}
		{if not flag "engine_started"
			{play_sound "waves" 0}
			{play_sound "waves" 0}
			{ani_play "zubr_start" -1}
			{kill_delay "engine_stopped"}
			{stop_sound "engine_stop"}
			{play_sound "engine_start"}
			{set "engine_started" 1}
			{view start "engine_steam"}
;			{if work "enginea"
				{ani_play "enginea_start" callback}
				{view start "enginea_exhaust"}
;			}
;			{if work "engineb"
				{ani_play "engineb_start" callback}
				{view start "engineb_exhaust"}
;			}
;			{if work "enginec"
				{ani_play "enginec_start" callback}
				{view start "enginec_exhaust"}
;			}
			{view start "engined_exhaust"}
		}
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
	{on "engine_stop" overload
		{kill_delay "engine_stopped"}
		{delay 12 "engine_stopped"
			{call "engine_stop_load"}
		}
	}
	{on "engine_stop_load" overload
		{kill_delay "engine_stopped"}
		{view pause "enginea_exhaust"}
		{view pause "engineb_exhaust"}
		{view pause "enginec_exhaust"}
		{view pause "engined_exhaust"}
		{play_sound "waves" 1}
		{stop_sound "engine_work"}
		{stop_sound "engine_start"}
		{play_sound "engine_stop"}
		{set "engine_started" 0}
		{view pause "engine_steam"}
		{ani_play "zubr_start"}
		{ani_stop "enginea_start"}
		{ani_stop "enginea_work"}
		{ani_play "enginea_stop"}
		{ani_stop "engineb_start"}
		{ani_stop "engineb_work"}
		{ani_play "engineb_stop"}
		{ani_stop "enginec_start"}
		{ani_stop "enginec_work"}
		{ani_play "enginec_stop"}
		{view pause "on_ground"}
		{view pause "on_sand"}		
		{view pause "on_grass"}	
		{view pause "on_water"}	
		{view pause "on_water"}	
		{view pause "on_puddle"}	
		{view pause "on_puddle"}	
		{view pause "on_mud"}	
		{view pause "on_country_road"}	
		{view pause "on_snow"}
	}
	{on terrain_fx "shallow_water" enter
		{delay 0.1 {kill_delay "engine_stopped"}}
	}
	{on terrain_fx "shallow_water" leave
		{delay 0.1 {kill_delay "engine_stopped"}}
	}
	{on "_burn" overload}
	;1-6 - places for IFV-APC 7-9 - for tanks. Place 7 blocks 1,2 and vice versa, place 8 blocks 1-4 and so on. 
;	(define "load_light_vehicle"
	{on "load_light_vehicle"
		        {tags add "cargo_inside"}
		        {if not tagged "place1_busy"
			{delay 0.1 {ani_play "vehicle1_in" callback}}
			{tags add "vdv_link_place1"} {delay 3 {tags remove "vdv_link_place1"}}
			{tags add "place1_busy"} {tags add "place7_busy"}
			{with_effector {tags add "vdv_link_to_place1"} {call "emit_desant"} {delay 3 {tags remove "vdv_link_to_place1"}}}
		        else not tagged "place2_busy"
			{delay 0.1 {ani_play "vehicle2_in" callback}}
			{tags add "vdv_link_place2"} {delay 3 {tags remove "vdv_link_place2"}}
			{tags add "place2_busy"} {tags add "place7_busy"}
			{with_effector {tags add "vdv_link_to_place2"} {call "emit_desant"} {delay 3 {tags remove "vdv_link_to_place2"}}}
		        else not tagged "place3_busy"
			{delay 0.1 {ani_play "vehicle3_in" callback}}
			{tags add "vdv_link_place3"} {delay 3 {tags remove "vdv_link_place3"}}
			{tags add "place3_busy"} {tags add "place8_busy"}
			{with_effector {tags add "vdv_link_to_place3"} {call "emit_desant"} {delay 3 {tags remove "vdv_link_to_place3"}}}
		        else not tagged "place4_busy"
			{delay 0.1 {ani_play "vehicle4_in" callback}}
			{tags add "vdv_link_place4"} {delay 3 {tags remove "vdv_link_place4"}}
			{tags add "place4_busy"} {tags add "place8_busy"}
			{with_effector {tags add "vdv_link_to_place4"} {call "emit_desant"} {delay 3 {tags remove "vdv_link_to_place4"}}}
		        else not tagged "place5_busy"
			{delay 0.1 {ani_play "vehicle5_in" callback}}
			{tags add "vdv_link_place5"} {delay 3 {tags remove "vdv_link_place5"}}
			{tags add "place5_busy"} {tags add "place9_busy"}
			{with_effector {tags add "vdv_link_to_place5"} {call "emit_desant"} {delay 3 {tags remove "vdv_link_to_place5"}}}
		        else not tagged "place6_busy"
			{delay 0.1 {ani_play "vehicle6_in" callback}}
			{tags add "vdv_link_place6"} {delay 3 {tags remove "vdv_link_place6"}}
			{tags add "place6_busy"} {tags add "place9_busy"}
			{with_effector {tags add "vdv_link_to_place6"} {call "emit_desant"} {delay 3 {tags remove "vdv_link_to_place6"}}}
			}
	}
;	)
;	(define "load_heavy_vehicle"
	{on "load_heavy_vehicle"
		        {tags add "cargo_inside"}
		        {if not tagged "place7_busy"
			{delay 0.1 {ani_play "vehicle7_in" callback}}
			{tags add "vdv_link_place7"} {delay 3 {tags remove "vdv_link_place7"}}
			{tags add "place7_busy"} {tags add "place1_busy"} {tags add "place2_busy"}
			{with_effector {tags add "vdv_link_to_place7"} {call "emit_desant"} {delay 3 {tags remove "vdv_link_to_place7"}}}
		        else not tagged "place8_busy"
			{delay 0.1 {ani_play "vehicle8_in" callback}}
			{tags add "vdv_link_place8"} {delay 3 {tags remove "vdv_link_place8"}}
			{tags add "place8_busy"} {tags add "place1_busy"} {tags add "place2_busy"} {tags add "place3_busy"} {tags add "place4_busy"}
			{with_effector {tags add "vdv_link_to_place8"} {call "emit_desant"} {delay 3 {tags remove "vdv_link_to_place8"}}}
		        else not tagged "place9_busy"
			{delay 0.1 {ani_play "vehicle9_in" callback}}
			{tags add "vdv_link_place9"} {delay 3 {tags remove "vdv_link_place9"}}
			{tags add "place9_busy"} {tags add "place1_busy"} {tags add "place2_busy"} {tags add "place3_busy"} {tags add "place4_busy"} {tags add "place5_busy"} {tags add "place6_busy"}
			{with_effector {tags add "vdv_link_to_place9"} {call "emit_desant"} {delay 3 {tags remove "vdv_link_to_place9"}}}
		        }
	}
;	)
	{on overlap begin
	      {if tagged "rampa_open"
			{if effector "heavy_M"
				{call "load_heavy_vehicle"}
			else  effector "medium_M"
				{call "load_heavy_vehicle"}
			else  effector "armored_car_M"
				{call "load_light_vehicle"}
			else  effector "light_M"
				{call "load_light_vehicle"}
			else  effector "car"
				{call "load_light_vehicle"}
			}
	       }
	}
	{on "script_update_cargo_anim"
		{if tagged "place1_busy" {ani_wind "vehicle1_in" end} else {ani_wind "vehicle1_in" begin}}
		{if tagged "place2_busy" {ani_wind "vehicle2_in" end} else {ani_wind "vehicle2_in" begin}}
		{if tagged "place3_busy" {ani_wind "vehicle3_in" end} else {ani_wind "vehicle3_in" begin}}
		{if tagged "place4_busy" {ani_wind "vehicle4_in" end} else {ani_wind "vehicle4_in" begin}}
		{if tagged "place5_busy" {ani_wind "vehicle5_in" end} else {ani_wind "vehicle5_in" begin}}
		{if tagged "place6_busy" {ani_wind "vehicle6_in" end} else {ani_wind "vehicle6_in" begin}}
		{if tagged "place7_busy" {ani_wind "vehicle7_in" end} else {ani_wind "vehicle7_in" begin}}
		{if tagged "place8_busy" {ani_wind "vehicle8_in" end} else {ani_wind "vehicle8_in" begin}}
		{if tagged "place9_busy" {ani_wind "vehicle9_in" end} else {ani_wind "vehicle9_in" begin}}
	}
	{on "open_cargo"
		{if not tagged "cargo_open"
			{volumes "vehicle" enable overlap}
		}
		{if flag "engine_started" {call "engine_stop_load"}}
	}
	(define "scripted_unload"
		{on animation_end "vehicle%0_unload" overload
			{with_linked_entity "vehicle%0"
				{tags add "unlink_me"}
				{able "sinking" 0}
			}
		}
     )
	("scripted_unload" args 1)
	("scripted_unload" args 2)
	("scripted_unload" args 3)
	("scripted_unload" args 4)
	("scripted_unload" args 5)
	("scripted_unload" args 6)
	("scripted_unload" args 7)
	("scripted_unload" args 8)
	("scripted_unload" args 9)
	(define "zubr_unload"
		{if tagged "place%place_busy"
			{delay %delay {volumes disable overlap} {ani_play "cargo_unload"} {ani_play "vehicle%place_unload" callback}}
		}
	)
	{on animation_end "cargo_open"	overload
	          {if tagged "cargo_inside"
				{tags remove "cargo_inside"}
				{chassis_work 0}
				{if tagged "place5_busy"
					{delay 10 {call "zubr_unload_step2"}}
				else tagged "place6_busy"
					{delay 10 {call "zubr_unload_step2"}}
				else tagged "place9_busy"
					{delay 5 {call "zubr_unload_step2"}}
				else {call "zubr_unload_step2"}
				}
				("zubr_unload" place(6) delay(0))
				("zubr_unload" place(5) delay(5))
				("zubr_unload" place(9) delay(0))
				{tags remove "place6_busy"}{tags remove "place5_busy"}{tags remove "place9_busy"}
			  else {volumes "vehicle" enable overlap}
	          }
	}
	{on "zubr_unload_step2"
		{if tagged "place3_busy"
			{delay 10 {call "zubr_unload_step3"}}
		else tagged "place4_busy"
			{delay 10 {call "zubr_unload_step3"}}
		else tagged "place8_busy"
			{delay 5 {call "zubr_unload_step3"}}
		else {call "zubr_unload_step3"}
		}
		("zubr_unload" place(4) delay(0))
		("zubr_unload" place(3) delay(5))
		("zubr_unload" place(8) delay(0))
		{tags remove "place4_busy"}{tags remove "place3_busy"}{tags remove "place8_busy"}
	}
	{on "zubr_unload_step3"
		("zubr_unload" place(2) delay(0))
		("zubr_unload" place(1) delay(5))
		("zubr_unload" place(7) delay(0))
		{tags remove "place2_busy"}{tags remove "place1_busy"}{tags remove "place7_busy"}
		{delay 5 {call "drop_desant"}{chassis_work 1}}
	}
	{on "drop_desant"
		{delay 0.1 {with_linked_entity "seat00"	{get_off}	}}
		{delay 0.3 {with_linked_entity "seat01"	{get_off}	}}
		{delay 0.5 {with_linked_entity "seat02"	{get_off}	}}
		{delay 0.7 {with_linked_entity "seat03"	{get_off}	}}
		{delay 0.9 {with_linked_entity "seat04"	{get_off}	}}
		{delay 1.1 {with_linked_entity "seat05"	{get_off}	}}
		{delay 1.3 {with_linked_entity "seat06"	{get_off}	}}
		{delay 1.5 {with_linked_entity "seat07"	{get_off}	}}
		{delay 1.7 {with_linked_entity "seat08"	{get_off}	}}
		{delay 1.9 {with_linked_entity "seat09"	{get_off}	}}
		{delay 2.1 {with_linked_entity "seat10"	{get_off}	}}
		{delay 2.3 {with_linked_entity "seat11"	{get_off}	}}
		{delay 2.5 {with_linked_entity "seat12"	{get_off}	}}
		{delay 2.7 {with_linked_entity "seat13"	{get_off}	}}
		{delay 2.9 {with_linked_entity "seat14"	{get_off}	}}
		{delay 3.1 {with_linked_entity "seat15"	{get_off}	}}
		{delay 3.3 {with_linked_entity "seat16"	{get_off}	}}
		{delay 3.2 {with_linked_entity "seat17"	{get_off}	}}
		{delay 3.7 {with_linked_entity "seat18"	{get_off}	}}
		{delay 3.9 {with_linked_entity "seat19"	{get_off}	}}
		{delay 4.1 {with_linked_entity "seat20"	{get_off}	}}
		{delay 4.3 {with_linked_entity "seat21"	{get_off}	}}
		{delay 4.5 {with_linked_entity "seat22"	{get_off}	}}
		{delay 4.7 {with_linked_entity "seat23"	{get_off}	}}
		{delay 4.9 {with_linked_entity "seat24"	{get_off}	}}
		{delay 5.1 {with_linked_entity "seat25"	{get_off}	}}
		{delay 5.3 {with_linked_entity "seat26"	{get_off}	}}
		{delay 5.5 {with_linked_entity "seat27"	{get_off}	}}
		{delay 5.7 {with_linked_entity "seat28"	{get_off}	}}
		{delay 5.9 {with_linked_entity "seat29"	{get_off}	}}
		{delay 6.1 {with_linked_entity "seat30"	{get_off}	}}
		{delay 6.3 {with_linked_entity "seat31"	{get_off}	}}
		{delay 6.5 {with_linked_entity "seat32"	{get_off}	}}
		{delay 6.7 {with_linked_entity "seat33"	{get_off}	}}
		{delay 6.9 {with_linked_entity "seat34"	{get_off}	}}
		{delay 7.1 {with_linked_entity "seat35"	{get_off}	}}
		{delay 7.3 {with_linked_entity "seat36"	{get_off}	}}
		{delay 7.5 {with_linked_entity "seat37"	{get_off}	}}
		{delay 7.7 {with_linked_entity "seat38"	{get_off}	}}
		{delay 7.9 {with_linked_entity "seat39"	{get_off}	}}
		{delay 8.1 {with_linked_entity "seat40"	{get_off}	}}
		{delay 8.3 {with_linked_entity "seat41"	{get_off}	}}
		{delay 8.5 {with_linked_entity "seat42"	{get_off}	}}
		{delay 8.7 {with_linked_entity "seat43"	{get_off}	}}
		{delay 8.9 {with_linked_entity "seat44"	{get_off}	}}
		{delay 9.1 {with_linked_entity "seat45"	{get_off}	}}
		{delay 9.3 {with_linked_entity "seat46"	{get_off}	}}
		{delay 9.5 {with_linked_entity "seat47"	{get_off}	}}
	}
;============================================================================sinking
	{on "break_and_sink"
		{if not work "body1"
		   {if rand 0.5
			{delay 2 {call "break_nose"}}
		   }
		}
		{if not work "body2"
		   {if rand 0.5
			{delay 2 {call "break_rear"}}
		   }
		}
		{if work "body1"
			{delay 10 2 {call "sink_ballast"}}
		else work "body2"
			{delay 10 2 {call "sink_ballast"}}
		else
			{call "sink_ballast"}
		}
		{components break}
	}
	{on "break_nose"
		("break_delete_linked" name(point_def1_place) delay(0))
		{delay 4 2 {volumes "ballast1" disable float} {impulse up 0.1}}
		{delay 4 2 {volumes "ballast2" disable float} {impulse up 0.1}}
	}
	{on "break_rear"
		("break_delete_linked" name(autocannon1_place) delay(0))
		("break_delete_linked" name(ak630radar) delay(0))
		("break_delete_linked" name(maingun) delay(0))
		{delay 4 2 {volumes "ballast5" disable float} {impulse up 0.1}}
		{delay 4 2 {volumes "ballast6" disable float} {impulse up 0.1}}
	}
	{on animation_end "sink"
		{view pause "on_stead"}
		{view pause "on_move"}
		{call "stop_sink_sound"}
	}
	{on "sink_sequence"
		{delay 15 ("cut_part_big" args machta)}
		
		("break_linked" name(ak630radar) delay(20 15))
		("break_linked" name(autocannon1_place) delay(20 15))
		("break_linked" name(autocannon2_place) delay(20 15))
		("break_linked" name(missile1) delay(20 15))
		("break_linked" name(missile2) delay(20 15))
	}
	{on break
		{if component "body1"
			("break_linked" name(autocannon1_place) delay(15 7))
			("break_linked" name(autocannon2_place) delay(15 7))
			("break_linked" name(missile1) delay(15 7))
			("break_linked" name(missile2) delay(15 7))
			("break_effect" effsize(norm) bone(01) delay(0))
		else component "body"
			("break_effect" effsize(norm) bone(03) delay(0))
			("break_effect" effsize(small) bone(05) delay(0))
		else component "body2"
			("break_effect" effsize(norm) bone(08) delay(0))
		else component "bridge_support"
			("break_effect" effsize(small) bone(03) delay(0))
			("break_effect" effsize(small) bone(04) delay(0))
			("break_linked" name(ak630radar) delay(15 7))
		}
	}
}

{"lcac"
	(define "zubr_fx"
		{add_view	"zubr_cloud_%fxtype"			"on_%terraintype"				"FX_cloud_big1"}
		{add_view	"zubr_cloud_%fxtype"			"on_%terraintype"				"FX_cloud_big2"}
		{add_view	"zubr_cloud_%fxtype"			"on_%terraintype"				"FX_cloud_medium1"}
		{add_view	"zubr_cloud_%fxtype"			"on_%terraintype"				"FX_cloud_medium2"}
		{add_view	"zubr_cloud_%fxtype"			"on_%terraintype"				"FX_cloud_medium3"}
		{add_view	"zubr_cloud_%fxtype"			"on_%terraintype"				"FX_cloud_medium4"}		
		{add_view	"zubr_cloud_%fxtype"			"on_%terraintype"				"FX_cloud_medium5"}	
		{add_view	"zubr_cloud_%fxtype"			"on_%terraintype"				"FX_cloud_medium6"}	
	)
	{on spawn
		{if not rain
			("zubr_fx" terraintype(ground) fxtype(ground))
			("zubr_fx" terraintype(grass) fxtype(ground))
			("zubr_fx" terraintype(sand) fxtype(sand))
			("zubr_fx" terraintype(country_road) fxtype(ground))
			("zubr_fx" terraintype(road) fxtype(road))
		}
		("zubr_fx" terraintype(water) fxtype(water))
		("zubr_fx" terraintype(mud) fxtype(water))
		("zubr_fx" terraintype(puddle) fxtype(water))
		("zubr_fx" terraintype(snow) fxtype(snow))
		{if not flag "engine_started"
			{ani_wind "zubr_start" end}
		}
		{tags add "dont_drop"}
	}
	{on "add_movement_sound" overload
		{add_view	"exhaust_dark_big"		"enginea_exhaust"		"enginea_exhaust"	}
		{add_view	"exhaust_dark_big"		"engineb_exhaust" 		"engineb_exhaust"	}
		{add_view	"exhaust_dark_big"		"enginec_exhaust"		"enginec_exhaust"	}
		{add_view	"exhaust_dark_big"		"engined_exhaust"		"FX_smoke_turbo4"	}
		{add_view	"exhaust_dark_big"		"engined_exhaust"		"FX_smoke_turbo5"	}
		
		{link_sound "waves"	"naval/move/ship_waves"}
		{link_sound "alarm"	"naval/alarm/Navysiren"}
		
		{link_sound "engine_start"		"vehicle/airborne/fw_start"			}
		{link_sound "engine_work"		"vehicle/airborne/fw_work"			}
		{link_sound "engine_stop"		"vehicle/airborne/fw_stop"			}
	}
	{on move on
		{call "engine_on"}
		{if tagged "cargo_open" {call "close_cargo"}}
	}
	{on move off
		{call "engine_stop"}
		{delay 0.1
			{if terrain_pp "ground"
				{view start "on_ground"}
			else terrain_pp "sand"
				{view start "on_sand"}		
			else terrain_pp "grass"
				{view start "on_grass"}	
			else terrain_pp "deep_water"
				{view start "on_water"}	
			else terrain_pp "water"
				{view start "on_water"}	
			else terrain_pp "shallow_water"
				{view start "on_puddle"}	
			else terrain_pp "puddle"
				{view start "on_puddle"}	
			else terrain_pp "mud"
				{view start "on_mud"}	
			else terrain_pp "country_road"
				{view start "on_country_road"}	
			else terrain_pp "snow"
				{view start "on_snow"}	
			}
		}
	}
	{on turn on
		{call "engine_on"}
		{if tagged "cargo_open" {call "close_cargo"}}
		{delay 0.1
			{if terrain_pp "ground"
				{view start "on_ground"}
			else terrain_pp "sand"
				{view start "on_sand"}		
			else terrain_pp "grass"
				{view start "on_grass"}	
			else terrain_pp "deep_water"
				{view start "on_water"}	
			else terrain_pp "water"
				{view start "on_water"}	
			else terrain_pp "shallow_water"
				{view start "on_puddle"}	
			else terrain_pp "puddle"
				{view start "on_puddle"}	
			else terrain_pp "mud"
				{view start "on_mud"}	
			else terrain_pp "country_road"
				{view start "on_country_road"}	
			else terrain_pp "snow"
				{view start "on_snow"}	
			}
		}
	}
	{on turn off
		{call "engine_stop"}
	}
	{on engine on overload
	}
	{on engine off overload
	}
	{on "engine_on" overload
		{kill_delay "engine_stopped"}
		{if not velocity 5 {call "close_rampa"} {set "specability" 0}}
		{if not flag "engine_started"
			{play_sound "waves" 0}
			{play_sound "waves" 0}
			{ani_play "zubr_start" -1}
			{kill_delay "engine_stopped"}
			{stop_sound "engine_stop"}
			{play_sound "engine_start"}
			{set "engine_started" 1}
			{view start "engine_steam"}
;			{if work "enginea"
				{ani_play "enginea_start" callback}
				{view start "enginea_exhaust"}
;			}
;			{if work "engineb"
				{ani_play "engineb_start" callback}
				{view start "engineb_exhaust"}
;			}
;			{if work "enginec"
				{ani_play "enginec_start" callback}
				{view start "enginec_exhaust"}
;			}
			{view start "engined_exhaust"}
		}
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
	{on "engine_stop" overload
		{kill_delay "engine_stopped"}
		{delay 12 "engine_stopped"
			{call "engine_stop_load"}
		}
	}
	{on "engine_stop_load" overload
		{kill_delay "engine_stopped"}
		{view pause "enginea_exhaust"}
		{view pause "engineb_exhaust"}
		{view pause "enginec_exhaust"}
		{view pause "engined_exhaust"}
		{play_sound "waves" 1}
		{stop_sound "engine_work"}
		{stop_sound "engine_start"}
		{play_sound "engine_stop"}
		{set "engine_started" 0}
		{view pause "engine_steam"}
		{ani_play "zubr_start"}
		{ani_stop "enginea_start"}
		{ani_stop "enginea_work"}
		{ani_play "enginea_stop"}
		{ani_stop "engineb_start"}
		{ani_stop "engineb_work"}
		{ani_play "engineb_stop"}
		{ani_stop "enginec_start"}
		{ani_stop "enginec_work"}
		{ani_play "enginec_stop"}
		{view pause "on_ground"}
		{view pause "on_sand"}		
		{view pause "on_grass"}	
		{view pause "on_water"}	
		{view pause "on_water"}	
		{view pause "on_puddle"}	
		{view pause "on_puddle"}	
		{view pause "on_mud"}	
		{view pause "on_country_road"}	
		{view pause "on_snow"}
	}
	{on terrain_fx "shallow_water" enter
		{delay 0.1 {kill_delay "engine_stopped"}}
	}
	{on terrain_fx "shallow_water" leave
		{delay 0.1 {kill_delay "engine_stopped"}}
	}
	{on "_burn" overload}
	;1-4 - places for APC 7 - for IFV-tanks. Place 7 blocks 1-4 and vice versa. 
	{on "load_light_vehicle"
		    {tags add "cargo_inside"}
		        {if not tagged "place1_busy"
			{delay 0.1 {ani_play "vehicle1_in" callback}}
			{tags add "vdv_link_place1"} {delay 3 {tags remove "vdv_link_place1"}}
			{tags add "place1_busy"} {tags add "place7_busy"}
			{with_effector {tags add "vdv_link_to_place1"} {call "emit_desant"} {delay 3 {tags remove "vdv_link_to_place1"}}}
		        else not tagged "place2_busy"
			{delay 0.1 {ani_play "vehicle2_in" callback}}
			{tags add "vdv_link_place2"} {delay 3 {tags remove "vdv_link_place2"}}
			{tags add "place2_busy"} {tags add "place7_busy"}
			{with_effector {tags add "vdv_link_to_place2"} {call "emit_desant"} {delay 3 {tags remove "vdv_link_to_place2"}}}
		        else not tagged "place3_busy"
			{delay 0.1 {ani_play "vehicle3_in" callback}}
			{tags add "vdv_link_place3"} {delay 3 {tags remove "vdv_link_place3"}}
			{tags add "place3_busy"} {tags add "place7_busy"}
			{with_effector {tags add "vdv_link_to_place3"} {call "emit_desant"} {delay 3 {tags remove "vdv_link_to_place3"}}}
		        else not tagged "place4_busy"
			{delay 0.1 {ani_play "vehicle4_in" callback}}
			{tags add "vdv_link_place4"} {delay 3 {tags remove "vdv_link_place4"}}
			{tags add "place4_busy"} {tags add "place7_busy"}
			{with_effector {tags add "vdv_link_to_place4"} {call "emit_desant"} {delay 3 {tags remove "vdv_link_to_place4"}}}
			}
	}
	{on "load_heavy_vehicle"
		        {tags add "cargo_inside"}
		        {if not tagged "place7_busy"
			{delay 0.1 {ani_play "vehicle7_in" callback}}
			{tags add "vdv_link_place7"} {delay 3 {tags remove "vdv_link_place7"}}
			{tags add "place7_busy"} {tags add "place1_busy"} {tags add "place2_busy"}{tags add "place3_busy"} {tags add "place4_busy"}
			{with_effector {tags add "vdv_link_to_place7"} {call "emit_desant"} {delay 3 {tags remove "vdv_link_to_place7"}}}
		        }
	}
	{on overlap begin
	      {if tagged "rampa_open"
			{if effector "heavy_M"
				{call "load_heavy_vehicle"}
			else  effector "medium_M"
				{call "load_heavy_vehicle"}
			else  effector "armored_car_M"
				{call "load_light_vehicle"}
			else  effector "light_M"
				{call "load_heavy_vehicle"}
			else  effector "car"
				{call "load_light_vehicle"}
			}
	       }
	}
	{on "script_update_cargo_anim"
		{if tagged "place1_busy" {ani_wind "vehicle1_in" end} else {ani_wind "vehicle1_in" begin}}
		{if tagged "place2_busy" {ani_wind "vehicle2_in" end} else {ani_wind "vehicle2_in" begin}}
		{if tagged "place3_busy" {ani_wind "vehicle3_in" end} else {ani_wind "vehicle3_in" begin}}
		{if tagged "place4_busy" {ani_wind "vehicle4_in" end} else {ani_wind "vehicle4_in" begin}}
		{if tagged "place7_busy" {ani_wind "vehicle7_in" end} else {ani_wind "vehicle7_in" begin}}
	}
	{on "open_cargo"
		{if not tagged "cargo_open"
			{volumes "vehicle" enable overlap}
		}
		{if flag "engine_started" {call "engine_stop_load"}}
	}
	(define "scripted_unload"
		{on animation_end "vehicle%0_unload" overload
			{with_linked_entity "vehicle%0"
				{tags add "unlink_me"}
				{able "sinking" 0}
			}
		}
     )
	("scripted_unload" args 1)
	("scripted_unload" args 2)
	("scripted_unload" args 3)
	("scripted_unload" args 4)
	("scripted_unload" args 7)
	(define "zubr_unload"
		{if tagged "place%place_busy"
			{delay %delay {volumes disable overlap} {ani_play "cargo_unload"} {ani_play "vehicle%place_unload" callback}}
		}
	)
	{on animation_end "cargo_open"	overload
	          {if tagged "cargo_inside"
				{tags remove "cargo_inside"}
				{chassis_work 0}
				{if tagged "place3_busy"
					{delay 10 {call "zubr_unload_step2"}}
				else tagged "place4_busy"
					{delay 10 {call "zubr_unload_step2"}}
				else {call "zubr_unload_step2"}
				}
				("zubr_unload" place(3) delay(0))
				("zubr_unload" place(4) delay(5))
				("zubr_unload" place(7) delay(0))
				{tags remove "place3_busy"}{tags remove "place4_busy"}{tags remove "place7_busy"}
			  else {volumes "vehicle" enable overlap}
	          }
	}
	{on "zubr_unload_step2"
		("zubr_unload" place(1) delay(0))
		("zubr_unload" place(2) delay(5))
		{tags remove "place1_busy"}{tags remove "place2_busy"}
		{delay 5 {chassis_work 1}}
	}
;============================================================================sinking
	{on "break_and_sink"
		{if not work "body1"
		   {if rand 0.5
			{delay 2 {call "break_nose"}}
		   }
		}
		{if not work "body2"
		   {if rand 0.5
			{delay 2 {call "break_rear"}}
		   }
		}
		{if work "body1"
			{delay 10 2 {call "sink_ballast"}}
		else work "body2"
			{delay 10 2 {call "sink_ballast"}}
		else
			{call "sink_ballast"}
		}
		{components break}
	}
	{on "break_nose"
		("break_delete_linked" name(point_def1_place) delay(0))
		{delay 4 2 {volumes "ballast1" disable float} {impulse up 0.1}}
		{delay 4 2 {volumes "ballast2" disable float} {impulse up 0.1}}
	}
	{on "break_rear"
		("break_delete_linked" name(autocannon1_place) delay(0))
		("break_delete_linked" name(ak630radar) delay(0))
		("break_delete_linked" name(maingun) delay(0))
		{delay 4 2 {volumes "ballast5" disable float} {impulse up 0.1}}
		{delay 4 2 {volumes "ballast6" disable float} {impulse up 0.1}}
	}
	{on animation_end "sink"
		{view pause "on_stead"}
		{view pause "on_move"}
		{call "stop_sink_sound"}
	}
;	{on "sink_sequence"
;		{delay 15 ("cut_part_big" args machta)}
;	}
	{on break
		{if component "body1"
			("break_effect" effsize(small) bone(04) delay(0))
			("break_effect" effsize(small) bone(03) delay(0))
			("break_effect" effsize(small) bone(05) delay(0))
			("break_effect" effsize(small) bone(07) delay(0))
		else component "body"
		else component "body2"
			("break_effect" effsize(small) bone(08) delay(0))
			("break_effect" effsize(small) bone(01) delay(0))
			("break_effect" effsize(small) bone(06) delay(0))
		else component "bridge_support"
			("break_effect" effsize(small) bone(00) delay(0))
			("break_effect" effsize(small) bone(02) delay(0))
		}
	}
}
{"pr949a"
	{on spawn
		{if tagged "single_launch_salvo" {call "single_launch"}}
	}
	{on fire "gun2" 
		{if not tagged "anten_up"
			{ani_play "cover_open"}
			{tags add "anten_up"}
			{ani_play "anten_up"}
		}
		(define "fire_barrel"
			{delay 0.5 
				{spawn "granit_carrier" "missile0%0"   x}
			}
			{ani_play "fire%0"}
			{if not tagged "submerged" {spawn "sturmtiger_fire" "missile0%0"   x}}
		)
			{if name "00" ("fire_barrel" args 00) else name "01" ("fire_barrel" args 01)
			else name "02" ("fire_barrel" args 02) else name "03" ("fire_barrel" args 03)
			else name "04" ("fire_barrel" args 04) else name "05" ("fire_barrel" args 05)
			else name "06" ("fire_barrel" args 06) else name "07" ("fire_barrel" args 07)
			else name "08" ("fire_barrel" args 08) else name "09" ("fire_barrel" args 09)
			else name "10" ("fire_barrel" args 10) else name "11" ("fire_barrel" args 11)
			else name "12" ("fire_barrel" args 12) else name "13" ("fire_barrel" args 13)
			else name "14" ("fire_barrel" args 14) else name "15" ("fire_barrel" args 15)
			else name "16" ("fire_barrel" args 16) else name "17" ("fire_barrel" args 17)
			else name "18" ("fire_barrel" args 18) else name "19" ("fire_barrel" args 19)
			else name "20" ("fire_barrel" args 20) else name "21" ("fire_barrel" args 21)
			else name "22" ("fire_barrel" args 22) else name "23" ("fire_barrel" args 23)
			}
	}
	(define "single_fire_barrel"
		{delay 0.5 
			{spawn "granit_carrier" "missile0%0"   x}
			{tags remove "%0"}{tags add "%1"}
		}
		{ani_play "fire%0"}
		{if not tagged "submerged" {spawn "sturmtiger_fire" "missile0%0"   x}}
		{delay 4  {call "single_launch"}}
	)
	{on "single_launch_salvo"
		{tags add "single_launch_salvo"} {tags add "00"} {call "single_launch"}
	}
	{on "single_launch"
		{if tagged "single_launch_salvo"
			{if tagged "00" ("single_fire_barrel" args 00 01)
			else tagged "01" ("single_fire_barrel" args 01 02)
			else tagged "02" ("single_fire_barrel" args 02 03)
			else tagged "03" ("single_fire_barrel" args 03 04)
			else tagged "04" ("single_fire_barrel" args 04 05)
			else tagged "05" ("single_fire_barrel" args 05 06)
			else tagged "06" ("single_fire_barrel" args 06 07)
			else tagged "07" ("single_fire_barrel" args 07 08)
			else tagged "08" ("single_fire_barrel" args 08 09)
			else tagged "09" ("single_fire_barrel" args 09 10)
			else tagged "10" ("single_fire_barrel" args 10 11)
			else tagged "11" ("single_fire_barrel" args 11 12)
			else tagged "12" ("single_fire_barrel" args 12 13)
			else tagged "13" ("single_fire_barrel" args 13 14)
			else tagged "14" ("single_fire_barrel" args 14 15)
			else tagged "15" ("single_fire_barrel" args 15 16)
			else tagged "16" ("single_fire_barrel" args 16 17)
			else tagged "17" ("single_fire_barrel" args 17 18)
			else tagged "18" ("single_fire_barrel" args 18 19)
			else tagged "19" ("single_fire_barrel" args 19 20)
			else tagged "20" ("single_fire_barrel" args 20 21)
			else tagged "21" ("single_fire_barrel" args 21 22)
			else tagged "22" ("single_fire_barrel" args 22 23)
			else tagged "23" ("single_fire_barrel" args 23 24) {tags remove "single_launch_salvo"}
			}
		}
	
	}
;===============================Разрушаемость
	{on "sink"
	  {ani_play "sink" 0.04 callback}
	}
	{on animation_end "sink"
		{view pause "on_stead"}
		{view pause "on_move"}
		{call "stop_sink_sound"}
	}
	{on "sink_sequence"
		{add_view "fx_bubbles_big" "FXfire_basis" "body"}
		{add_view "fx_bubbles_big" "FXfire_basis" "body1"}
		{add_view "fx_bubbles_big" "FXfire_basis" "body2"}
		{add_view "fx_bubbles_big" "FXfire_basis" "body3"}
		{add_view "fx_bubbles_big" "FXfire_basis" "body4"}
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
		("sink_effect" effsize(norm) bone(01) delay(20 12))
		("sink_effect" effsize(norm) bone(02) delay(10 10))
		("sink_effect" effsize(big) bone(01) delay(30 15))
		("sink_effect" effsize(big) bone(02) delay(20 12))
		("sink_effect" effsize(big) bone(03) delay(20 12))
	}
	{on fire "torpedo1" 
		(define "fire_barrel"
			name "%0"
;				{spawn "proj_probe" "foresight2"   x {tags add "shooter%0"}}
				{set "torpedo1"}{call "proj_probe"}
				{ani_play "fireB%0"}
		)
			{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			  else ("fire_barrel" args 02)
			  else ("fire_barrel" args 03)
			}
	}
	{on fire "torpedo2" 
		(define "fire_barrel"
			name "%0"
				{delay 0.1 {spawn "veter_sub_helper" "shooterb_0%0"   x}}
				{ani_play "fireA%0"}
		)
			{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			}
	}

	{on break
		{if component "body3"
			("break_effect" effsize(big) bone(02) delay(0))
		else component "body1"
			("break_effect" effsize(big) bone(01) delay(0))
		else component "body"
			("break_effect" effsize(big) bone(02) delay(0))
			("break_effect" effsize(small) bone(01) delay(0))
			("break_effect" effsize(small) bone(02) delay(0))
		else component "body2"
			("break_effect" effsize(small) bone(03) delay(0))
			("break_effect" effsize(small) bone(04) delay(0))
			("break_effect" effsize(small) bone(07) delay(0))
		else component "body4"
			("break_effect" effsize(big) bone(03) delay(0))
		}
	}
}
{"los_angeles"
	{on spawn
		{volumes "gun_recoil" disable blast}
		{call "init_gun2"}
	}
	{on "init_gun2"
		{add_view	 "proj_jet_sam"	"exh_000"	"tail_000"}
		{add_view	 "proj_jet_sam"	"exh_001"	"tail_001"}
		{add_view	 "proj_jet_sam"	"exh_002"	"tail_002"}
		{add_view	 "proj_jet_sam"	"exh_003"	"tail_003"}
		{add_view	 "proj_jet_sam"	"exh_004"	"tail_004"}
		{add_view	 "proj_jet_sam"	"exh_005"	"tail_005"}
		{add_view	 "proj_jet_sam"	"exh_006"	"tail_006"}
		{add_view	 "proj_jet_sam"	"exh_007"	"tail_007"}
		{add_view	 "proj_jet_sam"	"exh_008"	"tail_008"}
		{add_view	 "proj_jet_sam"	"exh_009"	"tail_009"}
		{add_view	 "proj_jet_sam"	"exh_010"	"tail_010"}
		{add_view	 "proj_jet_sam"	"exh_011"	"tail_011"}

		{view hide	"exh_000"}
		{view hide	"exh_001"}
		{view hide	"exh_002"}
		{view hide	"exh_003"}
		{view hide	"exh_004"}
		{view hide	"exh_005"}
		{view hide	"exh_006"}
		{view hide	"exh_007"}
		{view hide	"exh_008"}
		{view hide	"exh_009"}
		{view hide	"exh_010"}
		{view hide	"exh_011"}
	}

	{on fire "gun2" 
		(define "fire_barrel"
			{delay 0.2 
				{volumes "gun_recoil" enable blast}
				{spawn "turret_dir_detector" "gun_recoil" {stuff_detonate}}
				{delay 0.5 {volumes "gun_recoil" disable blast}}
				{if not tagged "submerged" {spawn "startsmoke_vert" "shooter_0%0" x}}
				{bone show "tomahawk_0%0"}
				{delay 0.15 {view start "exh_0%0"}{view show "exh_0%0"}}
				{delay 0.45 {if tagged "submerged" {spawn "ex_water_big" "shooter_0%0"   x}}}
				{delay 1.3
					{bone hide "tomahawk_0%0"}
					{spawn "tomahawk_carrier" "tomahawk_0%0"   x}
					{view pause "exh_0%0"}
					{view hide "exh_0%0"}
				}
				{delay 1.49
					{ani_play "fire_restore"}
				}
			}
			{ani_play "fire%0" 1}
		)
			{if name "00" ("fire_barrel" args 00) else name "01" ("fire_barrel" args 01)
			else name "02" ("fire_barrel" args 02) else name "03" ("fire_barrel" args 03)
			else name "04" ("fire_barrel" args 04) else name "05" ("fire_barrel" args 05)
			else name "06" ("fire_barrel" args 06) else name "07" ("fire_barrel" args 07)
			else name "08" ("fire_barrel" args 08) else name "09" ("fire_barrel" args 09)
			else name "10" ("fire_barrel" args 10) else name "11" ("fire_barrel" args 11)
			}
	}
	{on blast_hit
		{if stuff "turret_dir_detector"
			{if volume "recoil_gun_front"  {ani_play "fire_front" 1.5} {ani_play "fire_front_common"}
			else volume "recoil_gun_left"  {ani_play "fire_left" 1.5} {ani_play "fire_left_common"}
			else volume "recoil_gun_right"  {ani_play "fire_right" 1.5} {ani_play "fire_right_common"}
			else volume "recoil_gun_back"  {ani_play "fire_back" 1.5} {ani_play "fire_back_common"}
			else volume "recoil_gun_central"
			}
		}
	}
;===============================Разрушаемость
	{on "sink"
	  {ani_play "sink" 0.04 callback}
	}
	{on animation_end "sink"
		{view pause "on_stead"}
		{view pause "on_move"}
		{call "stop_sink_sound"}
	}
	{on "sink_sequence"
		{add_view "fx_bubbles_big" "FXfire_basis" "body"}
		{add_view "fx_bubbles_big" "FXfire_basis" "body1"}
		{add_view "fx_bubbles_big" "FXfire_basis" "body2"}
		{add_view "fx_bubbles_big" "FXfire_basis" "body3"}
		{add_view "fx_bubbles_big" "FXfire_basis" "body4"}
		{view start "FXfire_basis"}
		{delay 20 
			{view pause "on_stead"}
			{view pause "on_move"}
		}
		("sink_effect" effsize(small) bone(01) delay(10 10))
		("sink_effect" effsize(small) bone(02) delay(10 10))
		("sink_effect" effsize(small) bone(03) delay(10 10))
		("sink_effect" effsize(norm) bone(01) delay(20 12))
		("sink_effect" effsize(norm) bone(02) delay(10 10))
		("sink_effect" effsize(norm) bone(03) delay(30 15))
		("sink_effect" effsize(big) bone(01) delay(30 15))
		("sink_effect" effsize(big) bone(02) delay(20 12))
	}
	{on fire "torpedo1" 
		(define "fire_barrel"
			name "%0"
;				{spawn "proj_probe" "foresight3"   x {tags add "shootera%0"}}
				{set "torpedo1"}{call "proj_probe"}
				{ani_play "firea%0"}
		)
			{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			}
	}
	{on fire "torpedo2" 
		(define "fire_barrel"
			name "%0"
;				{spawn "proj_probe" "foresight2"   x {tags add "shooterb%0"}}
				{set "torpedo2"}{call "proj_probe"}
				{ani_play "fireb%0"}
		)
			{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			}
	}

	{on break
		{if component "body3"
			("break_effect" effsize(norm) bone(01) delay(0))
		else component "body1"
			("break_effect" effsize(big) bone(01) delay(0))
			("break_effect" effsize(small) bone(01) delay(0))
		else component "body"
			("break_effect" effsize(norm) bone(03) delay(0))
			("break_effect" effsize(small) bone(02) delay(0))
		else component "body2"
			("break_effect" effsize(big) bone(02) delay(0))
			("break_effect" effsize(norm) bone(02) delay(0))
		else component "body4"
		}
	}
}

{"636_3varshavyanka"
;===============================Разрушаемость
	{on "sink"
	  {ani_play "sink" 0.04 callback}
	}
	{on animation_end "sink"
		{view pause "on_stead"}
		{view pause "on_move"}
		{call "stop_sink_sound"}
	}
	{on "sink_sequence"
		{add_view "fx_bubbles_big" "FXfire_basis" "body"}
		{add_view "fx_bubbles_big" "FXfire_basis" "body1"}
		{add_view "fx_bubbles_big" "FXfire_basis" "body2"}
		{add_view "fx_bubbles_big" "FXfire_basis" "body3"}
		{add_view "fx_bubbles_big" "FXfire_basis" "body4"}
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
		("sink_effect" effsize(norm) bone(01) delay(20 12))
		("sink_effect" effsize(norm) bone(02) delay(10 10))
		("sink_effect" effsize(norm) bone(03) delay(30 15))
		("sink_effect" effsize(big) bone(01) delay(30 15))
	}
	{on fire "torpedo1" 
		(define "fire_barrel"
			name "%0"
;				{spawn "proj_probe" "foresight3"   x {tags add "shooter%0"}}
				{set "torpedo1"}{call "proj_probe"}
				{ani_play "firea%0"}
		)
			{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			  else ("fire_barrel" args 02)
			}
	}
	{on fire "torpedo2" 
		(define "fire_barrel"
			name "%0"
;				{spawn "proj_probe" "foresight2"   x {tags add "shooterb%0"}}
				{set "torpedo2"}{call "proj_probe"}
				{ani_play "fireb%0"}
		)
			{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			  else ("fire_barrel" args 02)
			}
	}

	{on break
		{if component "body1"
			("break_effect" effsize(big) bone(01) delay(0))
			("break_effect" effsize(small) bone(01) delay(0))
		else component "body"
			("break_effect" effsize(norm) bone(01) delay(0))
			("break_effect" effsize(norm) bone(02) delay(0))
			("break_effect" effsize(small) bone(02) delay(0))
			("break_effect" effsize(small) bone(03) delay(0))
			("break_effect" effsize(small) bone(04) delay(0))
			("break_effect" effsize(small) bone(05) delay(0))
		else component "body2"
			("break_effect" effsize(norm) bone(03) delay(0))
			("break_effect" effsize(small) bone(06) delay(0))
		}
	}
}
{"bpk1155"
;===============================Разрушаемость
	{on "sink"
		{ani_play "sink" 0.02 callback}
	}
	{on "break_and_sink"
		{if tagged "cwship_body3_break" {ani_play "break_nose" 0.05 callback}}
		{if tagged "cwship_body4_break" {ani_play "break_rear" 0.05 callback}}
	}
	{on animation_end "break_nose"
		("break_delete_linked" name(kinjal_front_place) delay(0))
		("break_delete_linked" name(ak100_1_place) delay(0))
		{if not tagged "no_hull_cut"
			{delay 0.5
				{tear "ship_part" bone "body3"
					{impulse up -1 dir 1 1 cx 1 1 cy 1 1 rnd_dir 2 no_position}
					{volumes disable float}
				}
			}
		}
	}
	{on animation_end "break_rear"
		{delay 0.5
			{if not tagged "no_hull_cut"
				{tear "ship_part" bone "body4"
					{impulse up -1 dir 1 1 cx 1 1 cy 1 1 rnd_dir 2 no_position}
					{volumes disable float}
				}
			}
		}
	}
	{on animation_end "sink"
		{view pause "on_stead"}
		{view pause "on_move"}
		{call "stop_sink_sound"}
	}
	{on "sink_sequence"
		{add_view "fx_bubbles_big" "FXfire_basis" "body"}
		{add_view "fx_bubbles_big" "FXfire_basis" "body1"}
		{add_view "fx_bubbles_big" "FXfire_basis" "body2"}
		{add_view "fx_bubbles_big" "FXfire_basis" "body3"}
		{add_view "fx_bubbles_big" "FXfire_basis" "body4"}
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
		("sink_effect" effsize(norm) bone(01) delay(20 12))
		("sink_effect" effsize(norm) bone(02) delay(10 10))
		("sink_effect" effsize(norm) bone(03) delay(30 15))
		("sink_effect" effsize(norm) bone(04) delay(10 10))
		("sink_effect" effsize(norm) bone(05) delay(30 15))
		("sink_effect" effsize(norm) bone(06) delay(20 12))
		("sink_effect" effsize(norm) bone(07) delay(10 10))
		("sink_effect" effsize(norm) bone(08) delay(30 15))
		("sink_effect" effsize(norm) bone(09) delay(20 12))
		("sink_effect" effsize(big) bone(01) delay(30 15))
		("sink_effect" effsize(big) bone(02) delay(20 12))
		("sink_effect" effsize(big) bone(03) delay(20 12))
		("sink_effect" effsize(big) bone(04) delay(20 12))
		("sink_effect" effsize(big) bone(05) delay(20 12))
		("break_linked" name(lamp_place1) delay(15 10))
		("break_linked" name(lamp_place2) delay(15 10))
		("break_linked" name(lamp_place3) delay(15 10))
		("break_linked" name(lamp_place4) delay(15 10))
		{delay 15 
			("break_delete_linked" name(podkat_place) delay(0))
			{bone cut "leer1"}{bone cut "leer2"}
			{delay 1 ("cut_part_big" args bridge_anten)}
		}
		{delay 19 
			("break_delete_linked" name(fregat_place) delay(0))
			{bone cut "leer3"}
			{delay 1 ("cut_part_big" args bridge_anten1)}
		}
		
		("break_linked" name(kranets_place000) delay(30 20))
		("break_linked" name(kranets_place001) delay(30 20))
		("break_linked" name(kranets_place002) delay(30 20))
		("break_linked" name(kranets_place003) delay(30 20))
		("break_linked" name(kranets_place004) delay(30 20))
		("break_linked" name(kranets_place005) delay(30 20))
		("break_linked" name(kranets_place006) delay(30 20))
		("break_linked" name(kranets_place007) delay(30 20))
		("break_linked" name(kranets_place008) delay(30 20))
		("break_linked" name(kranets_place009) delay(30 20))
		("break_linked" name(kranets_place010) delay(30 20))
		("break_linked" name(kranets_place011) delay(30 20))
		("break_linked" name(kranets_place012) delay(30 20))
		("break_linked" name(kranets_place013) delay(30 20))
		("break_linked" name(kranets_place014) delay(30 20))
		("break_linked" name(kranets_place015) delay(30 20))
		("break_linked" name(kranets_place016) delay(30 20))
		("break_linked" name(kranets_place017) delay(30 20))
		("break_linked" name(kranets_place018) delay(30 20))
		("break_linked" name(kranets_place019) delay(30 20))
		("break_linked" name(kranets_place020) delay(30 20))
		("break_linked" name(kranets_place021) delay(30 20))
		("break_linked" name(kranets_place022) delay(30 20))
		("break_linked" name(kranets_place023) delay(30 20))
		("break_linked" name(kranets_place024) delay(30 20))
		("break_linked" name(kranets_place025) delay(30 20))
		("break_linked" name(kranets_place026) delay(30 20))

		{delay 20 20 {with_linked_entity "lamp_place1" {call "lights_off"}}}
		{delay 20 20 {with_linked_entity "lamp_place2" {call "lights_off"}}}
		{delay 20 20 {with_linked_entity "lamp_place3" {call "lights_off"}}}
		{delay 20 20 {with_linked_entity "lamp_place4" {call "lights_off"}}}
		
		("break_linked" name(kinjal_1155front) delay(30 20))
		("break_linked" name(ak100_1_place) delay(30 20))
		("break_linked" name(ak100_2_place) delay(30 20))
		("break_linked" name(rastrub_place) delay(30 20))
		("break_linked" name(kinjal_rls_place) delay(30 20))
		("break_linked" name(lev_radar_place) delay(30 20))
		("break_linked" name(podkat_place) delay(30 20))
		("break_linked" name(fregat_place) delay(30 20))
		("break_linked" name(boat_left_place) delay(30 20))
		("break_linked" name(boat_right_place) delay(30 20))
		("break_linked" name(torpedotube_1155_l_place) delay(30 20))
		("break_linked" name(torpedotube_1155_r_place) delay(30 20))
		("break_linked" name(ak630rls_place1) delay(30 20))
		("break_linked" name(ak630rls_place2) delay(30 20))
		("break_linked" name(ak630_place1) delay(30 20))
		("break_linked" name(ak630_place2) delay(30 20))
		("break_linked" name(ak630_place3) delay(30 20))
		("break_linked" name(ak630_place4) delay(30 20))
		("break_linked" name(rbu_place) delay(30 20))
		("break_linked" name(rbu1_place) delay(30 20))
		("break_linked" name(kinjal_1155back) delay(30 20))
		("break_linked" name(kinjal_rls_place1) delay(30 20))
	}
	{on break
		{if component "body3"
			("break_effect" effsize(big) bone(01) delay(0))
			("break_linked" name(kinjal_front_place) delay(15 7))
			("break_linked" name(ak100_1_place) delay(15 7))
		else component "body1"
			("break_linked" name(ak100_2_place) delay(15 7))
			("break_linked" name(rastrub_place) delay(15 7))
			("break_linked" name(boat_left_place) delay(15 7))
			("break_linked" name(boat_right_place) delay(15 7))
			("break_effect" effsize(norm) bone(04) delay(0))
			("break_effect" effsize(small) bone(01) delay(0))
		else component "body"
			("break_linked" name(torpedotube_1155_l_place) delay(15 7))
			("break_linked" name(torpedotube_1155_r_place) delay(15 7))
			("break_linked" name(ak630rls_place1) delay(15 7))
			("break_linked" name(ak630rls_place2) delay(15 7))
			("break_linked" name(ak630_place1) delay(15 7))
			("break_linked" name(ak630_place2) delay(15 7))
			("break_linked" name(ak630_place3) delay(15 7))
			("break_linked" name(ak630_place4) delay(15 7))
			("break_linked" name(fregat_place) delay(15 7))
			("break_effect" effsize(big) bone(02) delay(0))
			("break_effect" effsize(big) bone(03) delay(0))
			("break_effect" effsize(norm) bone(06) delay(0))
		else component "body2"
			("break_linked" name(torpedo1_place) delay(15 7))
			("break_linked" name(torpedo2_place) delay(15 7))
			("break_effect" effsize(big) bone(04) delay(0))
			("break_effect" effsize(small) bone(06) delay(0))
		else component "body4"
			("break_linked" name(rbu_place) delay(15 7))
			("break_linked" name(rbu1_place) delay(15 7))
			("break_linked" name(kinjal_back_place) delay(15 7))
			("break_linked" name(kinjal_rls_place1) delay(15 7))
			("break_effect" effsize(small) bone(08) delay(0))
			("break_effect" effsize(small) bone(09) delay(0))
		else component "bridge"
			("break_linked" name(kinjal_rls_place) delay(15 7))
			("break_linked" name(lev_radar_place) delay(15 7))
			("break_linked" name(podkat_place) delay(15 7))
			("break_effect" effsize(small) bone(10) delay(0))
			("break_effect" effsize(small) bone(11) delay(0))
		else component "bridge_support"
			("break_effect" effsize(norm) bone(01) delay(0))
			("break_effect" effsize(norm) bone(02) delay(0))
			("break_effect" effsize(small) bone(13) delay(0))
		}
	}
}

{"pr1164"
;===============================Разрушаемость
	{on "sink"
		{ani_play "sink" 0.02 callback}
	}
	{on "break_and_sink"
		{if tagged "cwship_body3_break" {ani_play "break_nose" 0.05 callback}}
		{if tagged "cwship_body4_break" {ani_play "break_rear" 0.05 callback}}
	}
	{on animation_end "break_nose"
		("break_delete_linked" name(ak130_place) delay(0))
		{if not tagged "no_hull_cut"
			{delay 0.5
				{tear "ship_part" bone "body3"
					{impulse up -1 dir 1 1 cx 1 1 cy 1 1 rnd_dir 2 no_position}
					{volumes disable float}
				}
			}
		}
	}
	{on animation_end "break_rear"
		("break_delete_linked" name(osa_pu_place1) delay(0))
		("break_delete_linked" name(osa_pu_place2) delay(0))
		("break_delete_linked" name(osa_rls_place1) delay(0))
		("break_delete_linked" name(osa_rls_place2) delay(0))
		("break_delete_linked" name(Fort_rls2_place) delay(0))
		("break_delete_linked" name(torpedo_place_right) delay(0))
		("break_delete_linked" name(torpedo_place_left) delay(0))
		("break_linked" name(kranets_b_place000) delay(0))
		("break_linked" name(kranets_b_place001) delay(0))
		("break_linked" name(kranets_b_place002) delay(0))
		("break_linked" name(kranets_b_place003) delay(0))
		("break_linked" name(kranets_b_place004) delay(0))
		("break_linked" name(kranets_b_place005) delay(0))
		("break_linked" name(kranets_b_place006) delay(0))
		("break_linked" name(kranets_b_place007) delay(0))
		("break_linked" name(kranets_b_place008) delay(0))
		("break_linked" name(kranets_place027) delay(0))
		("break_linked" name(kranets_place013) delay(0))
		("break_linked" name(kranets_place014) delay(0))
		{delay 0.5
			{if not tagged "no_hull_cut"
				{tear "ship_part" bone "body4"
					{impulse up -1 dir 1 1 cx 1 1 cy 1 1 rnd_dir 2 no_position}
					{volumes disable float}
				}
			}
		}
	}
	{on animation_end "sink"
		{view pause "on_stead"}
		{view pause "on_move"}
		{call "stop_sink_sound"}
	}
	{on "sink_sequence"
		{add_view "fx_bubbles_big" "FXfire_basis" "body"}
		{add_view "fx_bubbles_big" "FXfire_basis" "body1"}
		{add_view "fx_bubbles_big" "FXfire_basis" "body2"}
		{add_view "fx_bubbles_big" "FXfire_basis" "body3"}
		{add_view "fx_bubbles_big" "FXfire_basis" "body4"}
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
		("sink_effect" effsize(small) bone(21) delay(30 15))
		("sink_effect" effsize(small) bone(22) delay(30 15))
		("sink_effect" effsize(small) bone(23) delay(30 15))
		("sink_effect" effsize(small) bone(24) delay(30 15))
		("sink_effect" effsize(small) bone(25) delay(30 15))
		("sink_effect" effsize(small) bone(26) delay(30 15))
		("sink_effect" effsize(small) bone(27) delay(30 15))
		("sink_effect" effsize(norm) bone(01) delay(20 12))
		("sink_effect" effsize(norm) bone(02) delay(10 10))
		("sink_effect" effsize(norm) bone(03) delay(30 15))
		("sink_effect" effsize(norm) bone(04) delay(10 10))
		("sink_effect" effsize(norm) bone(05) delay(30 15))
		("sink_effect" effsize(norm) bone(06) delay(20 12))
		("sink_effect" effsize(norm) bone(07) delay(10 10))
		("sink_effect" effsize(norm) bone(08) delay(30 15))
		("sink_effect" effsize(norm) bone(09) delay(20 12))
		("sink_effect" effsize(norm) bone(10) delay(30 15))
		("sink_effect" effsize(norm) bone(11) delay(10 10))
		("sink_effect" effsize(big) bone(01) delay(30 15))
		("sink_effect" effsize(big) bone(02) delay(20 12))
		("sink_effect" effsize(big) bone(03) delay(20 12))
		("sink_effect" effsize(big) bone(04) delay(20 12))
		("break_linked" name(lamp_place1) delay(15 10))
		("break_linked" name(lamp_place2) delay(15 10))
;		{delay 15 
;			{bone cut "leer1"}{bone cut "leer2"}
;			("cut_part_big" args bridge_anten)	;no masts for 1164
;		}
		
		("break_linked" name(kranets_place000) delay(30 20))
		("break_linked" name(kranets_place001) delay(30 20))
		("break_linked" name(kranets_place002) delay(30 20))
		("break_linked" name(kranets_place003) delay(30 20))
		("break_linked" name(kranets_place004) delay(30 20))
		("break_linked" name(kranets_place005) delay(30 20))
		("break_linked" name(kranets_place006) delay(30 20))
		("break_linked" name(kranets_place007) delay(30 20))
		("break_linked" name(kranets_place008) delay(30 20))
		("break_linked" name(kranets_place009) delay(30 20))
		("break_linked" name(kranets_place010) delay(30 20))
		("break_linked" name(kranets_place011) delay(30 20))
		("break_linked" name(kranets_place012) delay(30 20))
		("break_linked" name(kranets_place013) delay(30 20))
		("break_linked" name(kranets_place014) delay(30 20))
		("break_linked" name(kranets_place015) delay(30 20))
		("break_linked" name(kranets_place016) delay(30 20))
		("break_linked" name(kranets_place017) delay(30 20))
		("break_linked" name(kranets_place018) delay(30 20))
		("break_linked" name(kranets_place019) delay(30 20))
		("break_linked" name(kranets_place020) delay(30 20))
		("break_linked" name(kranets_place021) delay(30 20))
		("break_linked" name(kranets_place022) delay(30 20))
		("break_linked" name(kranets_place023) delay(30 20))
		("break_linked" name(kranets_place024) delay(30 20))
		("break_linked" name(kranets_place025) delay(30 20))
		("break_linked" name(kranets_place026) delay(30 20))
		("break_linked" name(kranets_place027) delay(30 20))
		("break_linked" name(kranets_place028) delay(30 20))
		("break_linked" name(kranets_place029) delay(30 20))
		("break_linked" name(kranets_b_place000) delay(30 20))
		("break_linked" name(kranets_b_place001) delay(30 20))
		("break_linked" name(kranets_b_place002) delay(30 20))
		("break_linked" name(kranets_b_place003) delay(30 20))
		("break_linked" name(kranets_b_place004) delay(30 20))
		("break_linked" name(kranets_b_place005) delay(30 20))
		("break_linked" name(kranets_b_place006) delay(30 20))
		("break_linked" name(kranets_b_place007) delay(30 20))
		("break_linked" name(kranets_b_place008) delay(30 20))

		{delay 20 20 {with_linked_entity "lamp_place1" {call "lights_off"}}}
		{delay 20 20 {with_linked_entity "lamp_place2" {call "lights_off"}}}
		
		("break_linked" name(boat_right_place) delay(30 20))
		("break_linked" name(boat_left_place) delay(30 20))
		("break_linked" name(ak130_place) delay(30 20))
		("break_linked" name(Basalt_place) delay(30 20))
		("break_linked" name(ak630_place1) delay(30 20))
		("break_linked" name(ak630_place2) delay(30 20))
		("break_linked" name(ak630_place3) delay(30 20))
		("break_linked" name(ak630_place4) delay(30 20))
		("break_linked" name(ak630_place5) delay(30 20))
		("break_linked" name(ak630_place6) delay(30 20))
		("break_linked" name(RBU6000_place1) delay(30 20))
		("break_linked" name(RBU6000_place2) delay(30 20))
		("break_linked" name(osa_pu_place1) delay(30 20))
		("break_linked" name(osa_pu_place2) delay(30 20))
		("break_linked" name(fort_place) delay(30 20))
		("break_linked" name(torpedo_place_left) delay(30 20))
		("break_linked" name(torpedo_place_right) delay(30 20))
		("break_linked" name(ak630rls_place1) delay(30 20))
		("break_linked" name(ak630rls_place2) delay(30 20))
		("break_linked" name(ak630rls_place3) delay(30 20))
		("break_linked" name(fregat_place) delay(30 20))
		("break_linked" name(main_rls_place) delay(30 20))
		("break_linked" name(lev_place) delay(30 20))
		("break_linked" name(osa_rls_place1) delay(30 20))
		("break_linked" name(osa_rls_place2) delay(30 20))
		("break_linked" name(Fort_rls2_place) delay(30 20))
	}
	{on break
		{if component "body3"
			("break_effect" effsize(norm) bone(01) delay(0))
			("break_effect" effsize(small) bone(01) delay(0))
			("break_effect" effsize(small) bone(02) delay(0))
			("break_linked" name(ak130_place) delay(15 7))
		else component "body1"
			("break_effect" effsize(big) bone(01) delay(0))
			("break_effect" effsize(norm) bone(02) delay(0))
			("break_effect" effsize(small) bone(05) delay(0))
			("break_effect" effsize(small) bone(07) delay(0))
			("break_linked" name(ak630_place1) delay(15 7))
			("break_linked" name(ak630_place2) delay(15 7))
			("break_linked" name(rbu6000_place1) delay(15 7))
			("break_linked" name(rbu6000_place2) delay(15 7))
			("break_linked" name(ak630rls_place1) delay(15 7))
		else component "body"
			("break_effect" effsize(big) bone(02) delay(0))
			("break_effect" effsize(norm) bone(03) delay(0))
			("break_effect" effsize(small) bone(09) delay(0))
			("break_effect" effsize(small) bone(10) delay(0))
			("break_linked" name(basalt_place) delay(15 7))
		else component "body2"
			("break_effect" effsize(big) bone(03) delay(0))
			("break_effect" effsize(norm) bone(04) delay(0))
			("break_effect" effsize(norm) bone(06) delay(0))
			("break_effect" effsize(small) bone(13) delay(0))
			("break_effect" effsize(small) bone(14) delay(0))
			("break_linked" name(boat_left_place) delay(15 7))
			("break_linked" name(boat_right_place) delay(15 7))
			("break_linked" name(fort_place) delay(15 7))
		else component "body4"
			("break_effect" effsize(big) bone(04) delay(0))
			("break_effect" effsize(norm) bone(10) delay(0))
			("break_effect" effsize(small) bone(17) delay(0))
			("break_effect" effsize(small) bone(20) delay(0))
			("break_linked" name(osa_pu_place1) delay(15 7))
			("break_linked" name(osa_pu_place2) delay(15 7))
			("break_linked" name(osa_rls_place1) delay(15 7))
			("break_linked" name(osa_rls_place2) delay(15 7))
			("break_linked" name(Fort_rls2_place) delay(15 7))
			("break_linked" name(torpedo_place_right) delay(15 7))
			("break_linked" name(torpedo_place_left) delay(15 7))
		else component "bridge"
			("break_effect" effsize(norm) bone(11) delay(0))
			("break_effect" effsize(small) bone(22) delay(0))
			("break_linked" name(ak630rls_place2) delay(15 7))
			("break_linked" name(ak630rls_place3) delay(15 7))
			("break_linked" name(ak630_place5) delay(15 7))
			("break_linked" name(ak630_place6) delay(15 7))
			("break_linked" name(ak630_place3) delay(15 7))
			("break_linked" name(ak630_place4) delay(15 7))
			("break_linked" name(main_rls_place) delay(15 7))
			("break_linked" name(lev_radar_place) delay(15 7))
		else component "bridge_support"
			("break_effect" effsize(small) bone(23) delay(0))
			("break_effect" effsize(small) bone(25) delay(0))
			("break_linked" name(fregat_place) delay(15 7))
			("break_linked" name(lev_place) delay(15 7))
		}
	}
}
{"pr956"
;===============================Разрушаемость
	{on "sink"
		{ani_play "sink" 0.02 callback}
	}
	{on "break_and_sink"
		{if tagged "cwship_body3_break" {ani_play "break_nose" 0.05 callback}}
		{if tagged "cwship_body4_break" {ani_play "break_rear" 0.05 callback}}
	}
	{on animation_end "break_nose"
		("break_delete_linked" name(ak130_place1) delay(0))
		("break_delete_linked" name(uragan_place1) delay(0))
		{if not tagged "no_hull_cut"
			{delay 0.5
				{tear "ship_part" bone "body3"
					{impulse up -1 dir 1 1 cx 1 1 cy 1 1 rnd_dir 2 no_position}
					{volumes disable float}
				}
			}
		}
	}
	{on animation_end "break_rear"
		("break_delete_linked" name(ak130_place2) delay(0))
		{delay 0.5
			{if not tagged "no_hull_cut"
				{tear "ship_part" bone "body4"
					{impulse up -1 dir 1 1 cx 1 1 cy 1 1 rnd_dir 2 no_position}
					{volumes disable float}
				}
			}
		}
	}
	{on animation_end "sink"
		{view pause "on_stead"}
		{view pause "on_move"}
		{call "stop_sink_sound"}
	}
	{on "sink_sequence"
		{add_view "fx_bubbles_big" "FXfire_basis" "body"}
		{add_view "fx_bubbles_big" "FXfire_basis" "body1"}
		{add_view "fx_bubbles_big" "FXfire_basis" "body2"}
		{add_view "fx_bubbles_big" "FXfire_basis" "body3"}
		{add_view "fx_bubbles_big" "FXfire_basis" "body4"}
		{view start "FXfire_basis"}
		{delay 20 
			{view pause "on_stead"}
			{view pause "on_move"}
		}
		{delay 3 2
			("break_linked" name(fregat_rls_place) delay(0))
			{delay 0.5 
				("break_delete_linked" name(fregat_rls_place) delay(0))
				{delay 0.5 ("cut_part_big" args part1_big)}
			}
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
		("sink_effect" effsize(norm) bone(01) delay(20 12))
		("sink_effect" effsize(norm) bone(02) delay(10 10))
		("sink_effect" effsize(norm) bone(03) delay(30 15))
		("sink_effect" effsize(norm) bone(04) delay(10 10))
		("sink_effect" effsize(norm) bone(05) delay(30 15))
		("sink_effect" effsize(norm) bone(06) delay(20 12))
		("sink_effect" effsize(norm) bone(07) delay(10 10))
		("sink_effect" effsize(norm) bone(08) delay(30 15))
		("sink_effect" effsize(norm) bone(09) delay(20 12))
		("sink_effect" effsize(big) bone(01) delay(30 15))
		("sink_effect" effsize(big) bone(02) delay(20 12))
		("sink_effect" effsize(big) bone(03) delay(20 12))
		("sink_effect" effsize(big) bone(04) delay(20 12))
		("break_linked" name(lamp_place1) delay(15 10))
		("break_linked" name(lamp_place2) delay(15 10))
		("break_linked" name(lamp_place3) delay(15 10))
		("break_linked" name(lamp_place4) delay(15 10))
		("break_linked" name(lamp_place5) delay(15 10))
		("break_linked" name(lamp_place6) delay(15 10))
		{delay 15 
			{bone cut "leer"}
			("cut_part_big" args bridge_anten)
		}
		
		("break_linked" name(kranets_place000) delay(30 20))
		("break_linked" name(kranets_place001) delay(30 20))
		("break_linked" name(kranets_place002) delay(30 20))
		("break_linked" name(kranets_place003) delay(30 20))
		("break_linked" name(kranets_place004) delay(30 20))
		("break_linked" name(kranets_place005) delay(30 20))
		("break_linked" name(kranets_place006) delay(30 20))
		("break_linked" name(kranets_place007) delay(30 20))
		("break_linked" name(kranets_place008) delay(30 20))
		("break_linked" name(kranets_place009) delay(30 20))
		("break_linked" name(kranets_place010) delay(30 20))
		("break_linked" name(kranets_place011) delay(30 20))
		("break_linked" name(kranets_a_place000) delay(30 20))
		("break_linked" name(kranets_a_place001) delay(30 20))
		("break_linked" name(kranets_a_place002) delay(30 20))
		("break_linked" name(kranets_a_place003) delay(30 20))
		("break_linked" name(kranets_b_place004) delay(30 20))
		("break_linked" name(kranets_b_place001) delay(30 20))
		("break_linked" name(kranets_b_place002) delay(30 20))
		("break_linked" name(kranets_b_place003) delay(30 20))
		("break_linked" name(kranets_b_place004) delay(30 20))
		("break_linked" name(kranets_b_place005) delay(30 20))
		("break_linked" name(kranets_b_place006) delay(30 20))
		("break_linked" name(kranets_b_place007) delay(30 20))

		{delay 20 20 {with_linked_entity "lamp_place1" {call "lights_off"}}}
		{delay 20 20 {with_linked_entity "lamp_place2" {call "lights_off"}}}
		{delay 20 20 {with_linked_entity "lamp_place3" {call "lights_off"}}}
		{delay 20 20 {with_linked_entity "lamp_place4" {call "lights_off"}}}
		{delay 20 20 {with_linked_entity "lamp_place5" {call "lights_off"}}}
		{delay 20 20 {with_linked_entity "lamp_place6" {call "lights_off"}}}
		
		("break_linked" name(boat_right_place) delay(30 20))
		("break_linked" name(boat_left_place) delay(30 20))
		("break_linked" name(ak130_place1) delay(30 20))
		("break_linked" name(ak130_place2) delay(30 20))
		("break_linked" name(uragan_place1) delay(30 20))
		("break_linked" name(uragan_place2) delay(30 20))
		("break_linked" name(moskit_place) delay(30 20))
		("break_linked" name(ak630_place1) delay(30 20))
		("break_linked" name(ak630_place2) delay(30 20))
		("break_linked" name(ak630_place3) delay(30 20))
		("break_linked" name(ak630_place4) delay(30 20))
		("break_linked" name(RBU1000_place1) delay(30 20))
		("break_linked" name(RBU1000_place2) delay(30 20))
		("break_linked" name(torpedo_place_left) delay(30 20))
		("break_linked" name(torpedo_place_right) delay(30 20))
		("break_linked" name(ak630rls_place1) delay(30 20))
		("break_linked" name(ak630rls_place2) delay(30 20))
		("break_linked" name(Lev_radar_place) delay(30 20))
		("break_linked" name(rls_uragan_place1) delay(30 20))
		("break_linked" name(rls_uragan_place2) delay(30 20))
		("break_linked" name(rls_uragan_place3) delay(30 20))
		("break_linked" name(rls_uragan_place4) delay(30 20))
		("break_linked" name(rls_uragan_place5) delay(30 20))
		("break_linked" name(rls_uragan_place6) delay(30 20))
		("break_linked" name(fregat_place) delay(30 20))
	}
	{on "cut_parts"
		("break_delete_linked" name(fregat_rls_place) delay(0))
		{delay 0.5
			("cut_part_big" args part1_big)
		}
	}
	{on break_armor
		{if component "part1_big"
			("break_delete_linked" name(fregat_rls_place) delay(0))
			{delay 0.5 ("cut_part_big" args part1_big)}
		}
	}
	{on break
		{if component "body3"
			("break_linked" name(ak130_place1) delay(15 7))
			("break_effect" effsize(norm) bone(01) delay(0))
			("break_effect" effsize(small) bone(02) delay(0))
		else component "body1"
			("break_effect" effsize(big) bone(01) delay(0))
		else component "body"
			("break_linked" name(rls_uragan_place3) delay(15 7))
			("break_linked" name(rls_uragan_place4) delay(15 7))
			("break_linked" name(boat_left_place) delay(15 7))
			("break_linked" name(boat_right_place) delay(15 7))
			("break_linked" name(torpedo_place_right) delay(15 7))
			("break_linked" name(torpedo_place_left) delay(15 7))
			("break_effect" effsize(big) bone(02) delay(0))
		else component "body2"
			("break_linked" name(moskit_place) delay(15 7))
			("break_effect" effsize(norm) bone(07) delay(0))
		else component "body4"
			("break_linked" name(ak130_place2) delay(15 7))
			("break_effect" effsize(big) bone(03) delay(0))
		else component "bridge"
			("break_linked" name(Lev_radar_place) delay(15 7))
			("break_linked" name(rls_uragan_place1) delay(15 7))
			("break_linked" name(rls_uragan_place2) delay(15 7))
			("break_effect" effsize(small) bone(05) delay(0))
			("break_effect" effsize(small) bone(06) delay(0))
		else component "bridge_support"
			("break_linked" name(uragan_place2) delay(15 7))
			("break_linked" name(ak630_rls_place1) delay(15 7))
			("break_linked" name(ak630_rls_place2) delay(15 7))
			("break_linked" name(ak630_place1) delay(15 7))
			("break_linked" name(ak630_place2) delay(15 7))
			("break_linked" name(ak630_place3) delay(15 7))
			("break_linked" name(ak630_place4) delay(15 7))
			("break_linked" name(rls_uragan_place5) delay(15 7))
			("break_linked" name(rls_uragan_place6) delay(15 7))
			("break_linked" name(RBU1000_place1) delay(15 7))
			("break_linked" name(RBU1000_place2) delay(15 7))
			("break_effect" effsize(big) bone(04) delay(0))
			("break_effect" effsize(norm) bone(04) delay(0))
		}
	}
}


{"orlan_main"
;===============================Разрушаемость

	{on "sink"
		{ani_play "sink" 0.02 callback}
		{delay 15 15 {with_linked_entity "body3" {call "play_sink_sound"}}}
		{delay 15 15 {with_linked_entity "body1" {call "play_sink_sound"}}}
		{delay 15 15 {with_linked_entity "body" {call "play_sink_sound"}}}
		{delay 15 15 {with_linked_entity "body4" {call "play_sink_sound"}}}
	}
	
	{on "break_and_sink"
		{delay 5 {if tagged "cwship_body3_break" {ani_play "break_nose" 0.05 callback}}}
		{delay 5 {if tagged "cwship_body4_break" {ani_play "break_rear" 0.05 callback}}}
	}
	{on animation_end "break_nose"
			{with_linked_entity "body3"
				("break_delete_linked" name(rbu12000_place1) delay(0))
				{if not tagged "no_hull_cut"
					{delay 0.5
						{tear "ship_part" bone "body3"
							{impulse up -1 dir 1 1 cx 1 1 cy 1 1 rnd_dir 2 no_position}
							{volumes disable float}
						}
					}
				}
			}
	}
	{on animation_end "break_rear"
			{with_linked_entity "body4"
				("break_delete_linked" name(kinjal_1144_place) delay(0))
				{if not tagged "no_hull_cut"
					{delay 0.5
						{tear "ship_part" bone "body4"
							{impulse up -1 dir 1 1 cx 1 1 cy 1 1 rnd_dir 2 no_position}
							{volumes disable float}
						}
					}
				}
			}
	}
	{on animation_end "sink"
		{view pause "on_stead"}
		{view pause "on_move"}
		{call "stop_sink_sound"}
		{with_linked_entity "body1"
			{view pause "on_stead"}
			{view pause "on_move"}
			{call "stop_sink_sound"}
		}
		{with_linked_entity "body3"
			{view pause "on_stead"}
			{view pause "on_move"}
			{call "stop_sink_sound"}
		}
		{with_linked_entity "body4"
			{view pause "on_stead"}
			{view pause "on_move"}
			{call "stop_sink_sound"}
		}
		{with_linked_entity "body"
			{view pause "on_stead"}
			{view pause "on_move"}
			{call "stop_sink_sound"}
		}
		
	}
	{on "sink_sequence"
		{add_view "fx_bubbles_big" "FXfire_basis" "body"}
		{view start "FXfire_basis"}
		{delay 20 
			{view pause "on_stead"}
			{view pause "on_move"}
		}

		("sink_effect" effsize(small) bone(01) delay(15 15))
		
		{delay 30 30 {with_linked_entity "lamp1155_front_place1" {call "lights_off"}}}
		{delay 30 30 {with_linked_entity "lamp1155_front_place2" {call "lights_off"}}}
		{delay 30 30 {with_linked_entity "lamp1155_side_place1" {call "lights_off"}}}
		{delay 30 30 {with_linked_entity "lamp1155_side_place2" {call "lights_off"}}}
		{delay 30 30 {with_linked_entity "lamp1155_side_place3" {call "lights_off"}}}
		{delay 30 30 {with_linked_entity "lamp1155_side_place4" {call "lights_off"}}}
		
		("break_linked" name(kranets_place000) delay(30 20))
		("break_linked" name(kranets_place001) delay(30 20))
		("break_linked" name(kranets_place002) delay(30 20))
		("break_linked" name(kranets_place003) delay(30 20))
		("break_linked" name(kranets_place004) delay(30 20))
		("break_linked" name(kranets_place005) delay(30 20))
		("break_linked" name(kranets_place006) delay(30 20))
		("break_linked" name(kranets_place007) delay(30 20))
		("break_linked" name(kranets_place008) delay(30 20))
		("break_linked" name(kranets_place009) delay(30 20))
		("break_linked" name(kranets_place010) delay(30 20))
		("break_linked" name(kranets_place011) delay(30 20))
		("break_linked" name(kranets_place012) delay(30 20))
		("break_linked" name(kranets_place013) delay(30 20))
		("break_linked" name(kranets_place014) delay(30 20))
		("break_linked" name(kranets_place015) delay(30 20))
		("break_linked" name(kranets_place016) delay(30 20))
		("break_linked" name(kranets_place017) delay(30 20))
		("break_linked" name(kranets_place018) delay(30 20))
		("break_linked" name(kranets_place019) delay(30 20))
		("break_linked" name(kranets_place020) delay(30 20))
		("break_linked" name(kranets_place021) delay(30 20))
		("break_linked" name(kranets_place022) delay(30 20))
		("break_linked" name(kranets_place023) delay(30 20))
		("break_linked" name(kranets_place024) delay(30 20))
		("break_linked" name(kranets_place025) delay(30 20))
		("break_linked" name(kranets_place026) delay(30 20))
		("break_linked" name(kranets_place027) delay(30 20))
		("break_linked" name(kranets_place028) delay(30 20))
		("break_linked" name(kranets_place029) delay(30 20))
		("break_linked" name(kranets_place030) delay(30 20))
		("break_linked" name(kranets_place031) delay(30 20))
		("break_linked" name(kranets_place032) delay(30 20))
		("break_linked" name(kranets_place033) delay(30 20))
		("break_linked" name(kranets_place034) delay(30 20))
		("break_linked" name(kranets_place035) delay(30 20))
		("break_linked" name(kranets_place036) delay(30 20))
		("break_linked" name(kranets_place037) delay(30 20))
		("break_linked" name(kranets_place038) delay(30 20))
		("break_linked" name(kranets_place039) delay(30 20))
		("break_linked" name(kranets_place050) delay(30 20))
		("break_linked" name(kranets_place051) delay(30 20))
		("break_linked" name(kranets_place052) delay(30 20))
		("break_linked" name(kranets_place053) delay(30 20))
		("break_linked" name(kranets_a_place000) delay(30 20))
		("break_linked" name(kranets_a_place001) delay(30 20))
		("break_linked" name(kranets_a_place002) delay(30 20))
		("break_linked" name(kranets_a_place003) delay(30 20))
		("break_linked" name(kranets_a_place004) delay(30 20))
		("break_linked" name(kranets_a_place005) delay(30 20))
		("break_linked" name(kranets_a_place008) delay(30 20))
		("break_linked" name(kranets_a_place009) delay(30 20))
		("break_linked" name(kranets_a_place010) delay(30 20))
		("break_linked" name(kranets_a_place011) delay(30 20))
		("break_linked" name(kranets_a_place012) delay(30 20))
		("break_linked" name(kranets_a_place013) delay(30 20))
		("break_linked" name(boat_right_place) delay(30 30))
		("break_linked" name(boat_left_place) delay(30 30))
		("break_linked" name(boat_right_place1) delay(30 30))
		("break_linked" name(boat_left_place1) delay(30 30))
		("break_linked" name(kortik3_place) delay(30 30))
		("break_linked" name(kortik4_place) delay(30 30))
		("break_linked" name(kortik5_place) delay(30 30))
		("break_linked" name(kortik6_place) delay(30 30))
		("break_linked" name(lev_radar_place) delay(30 30))
		("break_linked" name(podkat1_place) delay(30 30))
		("break_linked" name(podkat_place) delay(30 30))
		("break_linked" name(kinjal_rls_place) delay(30 30))
		("break_linked" name(Fort_rls2_place) delay(30 30))
		("break_linked" name(Fort_rls1_place) delay(30 30))
		("break_linked" name(fregat_place) delay(30 30))
		("break_linked" name(main_rls_place) delay(30 30))
		
		("sink_effect" effsize(big) bone(03) delay(15 15))
		("sink_effect" effsize(norm) bone(08) delay(15 15))
		("sink_effect" effsize(norm) bone(09) delay(15 15))
		("sink_effect" effsize(small) bone(07) delay(15 15))
		("sink_effect" effsize(small) bone(08) delay(15 15))
		("sink_effect" effsize(small) bone(09) delay(15 15))
		("sink_effect" effsize(small) bone(10) delay(15 15))
		("sink_effect" effsize(small) bone(14) delay(15 15))
		("sink_effect" effsize(small) bone(15) delay(15 15))
		("sink_effect" effsize(small) bone(16) delay(15 15))
		("sink_effect" effsize(small) bone(17) delay(15 15))
		("sink_effect" effsize(small) bone(18) delay(15 15))
		("sink_effect" effsize(small) bone(19) delay(15 15))
		("sink_effect" effsize(small) bone(20) delay(15 15))
		("sink_effect" effsize(small) bone(21) delay(15 15))

		{with_linked_entity "body1"
			{add_view "fx_bubbles_big" "FXfire_basis" "body1"}
			{view start "FXfire_basis"}
			("break_linked" name(fort1144_place) delay(30 30))
			("break_linked" name(granit_place) delay(30 30))
			("break_linked" name(kortik1_place) delay(30 30))
			("break_linked" name(kortik2_place) delay(30 30))
			("break_linked" name(kranets_a_place006) delay(30 20))
			("break_linked" name(kranets_a_place007) delay(30 20))
			("break_linked" name(kranets_a_place014) delay(30 20))
			("break_linked" name(kranets_a_place015) delay(30 20))
			("break_linked" name(kranets_place040) delay(30 20))
			("break_linked" name(kranets_place041) delay(30 20))
			("break_linked" name(kranets_place042) delay(30 20))
			("break_linked" name(kranets_place043) delay(30 20))
			("break_linked" name(kranets_place044) delay(30 20))
			("break_linked" name(kranets_place045) delay(30 20))
			("break_linked" name(kranets_place046) delay(30 20))
			("break_linked" name(kranets_place047) delay(30 20))
			("break_linked" name(kranets_place048) delay(30 20))
			("break_linked" name(kranets_place049) delay(30 20))

			("sink_effect" effsize(big) bone(02) delay(15 15))
			("sink_effect" effsize(norm) bone(03) delay(15 15))
			("sink_effect" effsize(small) bone(03) delay(15 15))
			("sink_effect" effsize(small) bone(04) delay(15 15))
			("sink_effect" effsize(small) bone(05) delay(15 15))
			("sink_effect" effsize(small) bone(06) delay(15 15))
		}
		{with_linked_entity "body2"
			{add_view "fx_bubbles_big" "FXfire_basis" "body2"}
			{view start "FXfire_basis"}
			("sink_effect" effsize(big) bone(04) delay(15 15))
			("break_linked" name(ak130_place) delay(30 30))
			("break_linked" name(rbu1000_place1) delay(30 30))
			("break_linked" name(rbu1000_place2) delay(30 30))
			("break_linked" name(torpedo_place_left) delay(30 30))
			("break_linked" name(torpedo_place_right) delay(30 30))
			("sink_effect" effsize(norm) bone(04) delay(15 15))
			("sink_effect" effsize(norm) bone(05) delay(15 15))
			("sink_effect" effsize(small) bone(11) delay(15 15))
			("sink_effect" effsize(small) bone(12) delay(15 15))
			("sink_effect" effsize(small) bone(13) delay(15 15))
		}
		{with_linked_entity "body3"
			("break_linked" name(rbu12000_place1) delay(30 30))
			("sink_effect" effsize(big) bone(01) delay(15 15))
			("sink_effect" effsize(norm) bone(01) delay(15 15))
			("sink_effect" effsize(norm) bone(02) delay(15 15))
			("sink_effect" effsize(small) bone(01) delay(15 15))
			("sink_effect" effsize(small) bone(02) delay(15 15))
		}
		{with_linked_entity "body4"
			{add_view "fx_bubbles_big" "FXfire_basis" "body4"}
			{view start "FXfire_basis"}
			("break_linked" name(kinjal_1144_place) delay(30 30))
			("sink_effect" effsize(norm) bone(06) delay(15 15))
		}
	}
	{on break
		{if component "body3"
			{with_linked_entity "body3"
				("break_linked" name(rbu12000_place1) delay(30 30))
				("break_effect" effsize(big) bone(01) delay(0))
				("break_effect" effsize(norm) bone(01) delay(0))
				("break_effect" effsize(norm) bone(02) delay(0))
				("break_effect" effsize(small) bone(01) delay(0))
			}
		else component "body1"
			{with_linked_entity "body1"
				("break_linked" name(fort1144_place) delay(30 30))
				("break_linked" name(granit_place) delay(30 30))
				("break_linked" name(kortik1_place) delay(30 30))
				("break_linked" name(kortik2_place) delay(30 30))
				("break_effect" effsize(big) bone(02) delay(0))
				("break_effect" effsize(norm) bone(03) delay(0))
				("break_effect" effsize(small) bone(03) delay(0))
				("break_effect" effsize(small) bone(04) delay(0))
				("break_effect" effsize(small) bone(06) delay(0))
			}
		else component "body"
				("break_effect" effsize(big) bone(03) delay(0))
				("break_effect" effsize(small) bone(08) delay(0))
				("break_effect" effsize(small) bone(09) delay(0))
		else component "body2"
			{with_linked_entity "body1"
				("break_linked" name(ak130_place) delay(30 30))
				("break_linked" name(rbu1000_place1) delay(30 30))
				("break_linked" name(rbu1000_place2) delay(30 30))
				("break_linked" name(torpedo_place_left) delay(30 30))
				("break_linked" name(torpedo_place_right) delay(30 30))
				("break_effect" effsize(norm) bone(05) delay(0))
				("break_effect" effsize(small) bone(12) delay(0))
				("break_effect" effsize(small) bone(13) delay(0))
			}
		else component "body4"
			{with_linked_entity "body4"
				("break_linked" name(kinjal_1144_place) delay(30 30))
				("break_effect" effsize(norm) bone(06) delay(0))
			}
		else component "bridge"
			("break_linked" name(Fort_rls1_place) delay(15 7))
			("break_linked" name(lamp1155_front_place1) delay(0))
			("break_linked" name(lamp1155_front_place2) delay(0))
			("break_linked" name(lamp1155_side_place1) delay(0))
			("break_linked" name(lamp1155_side_place2) delay(0))
			("break_linked" name(podkat1_place) delay(15 7))
			("break_linked" name(podkat_place) delay(15 7))
			("break_linked" name(main_rls_place) delay(15 7))
			("break_effect" effsize(norm) bone(08) delay(0))
			("break_effect" effsize(small) bone(17) delay(0))
			("break_effect" effsize(small) bone(19) delay(0))
			("break_effect" effsize(small) bone(21) delay(0))
		else component "bridge_support"
			("break_linked" name(lamp1155_side_place3) delay(0))
			("break_linked" name(lamp1155_side_place4) delay(0))
			("break_linked" name(kortik3_place) delay(15 7))
			("break_linked" name(kortik4_place) delay(15 7))
			("break_linked" name(kortik5_place) delay(15 7))
			("break_linked" name(kortik6_place) delay(15 7))
			("break_linked" name(lev_radar_place) delay(15 7))
			("break_linked" name(kinjal_rls_place) delay(15 7))
			("break_linked" name(Fort_rls2_place) delay(15 7))
			("break_linked" name(fregat_place) delay(15 7))
			("break_effect" effsize(norm) bone(07) delay(0))
			("break_effect" effsize(small) bone(14) delay(0))
			("break_effect" effsize(small) bone(16) delay(0))
		}
	}
	
	
	{on "cut_parts"
		{delay 0.5
		   {with_linked_entity "body2"
			("cut_part_big" args part1_big)
			("cut_part_big" args part2_big)
		   }
			("cut_part_big" args part3_big)
			("cut_part_big" args part4_big)
		}
	}
	{on break_armor
		{if component "part1_big"
			("cut_part_big" args part1_big)
		else component "part2_big"
			("cut_part_big" args part2_big)
		else component "part3_big"
			("cut_part_big" args part3_big)
		else component "part4_big"
			("cut_part_big" args part4_big)
		}
	}
}
{"lcvp_mk5"
	{on "specability" overload
		{if not flag "specability"
			{set "specability" 1}
			{damage_report "body" "cargobay_opened"}
			{call "open_rampa"}
		else 
			{set "specability" 0}
			{damage_report "body" "cargobay_closed"}
			{call "close_rampa"}
		}
	}
	{on "engine_on"
		{if not velocity 5 {call "close_rampa"} {set "specability" 0}}
	}
	{on move on
		{if tagged "cargo_open" {call "close_cargo"}}
	}
	{on "open_rampa"
		{if not tagged "rampa_open"
			{ani_play "cargo_open"}
			{tags add "rampa_open"}
		}
	}
	{on "close_rampa"
		{if tagged "rampa_open"
			{ani_play "cargo_open" -1}
			{tags remove "rampa_open"}
		}
	}
}