(include "/lists/missile_settings3.inc")
(define "cwps3_stop"
	{with_linked_entity "cwps_proj_point"	{call "stop_%country_%type"}}
	{with_linked_entity "cwps_emitter1" {call "stop_%country_%type"}}
	{with_linked_entity "cwps_emitter2" {call "stop_%country_%type"}}
	{with_linked_entity "cwps_emitter3" {call "stop_%country_%type"}}
	{with_linked_entity "cwps_emitter4" {call "stop_%country_%type"}}
	{with_linked_entity "cwps_emitter5" {call "stop_%country_%type"}}
	{with_linked_entity "cwps_emitter6" {call "stop_%country_%type"}}
)
(define "cwps3_start"
	{if not chassis "water"
		{with_linked_entity "cwps_proj_point"	{call "start_%country_%type"}}
		{with_linked_entity "cwps_emitter1" {call "start_%country_%type"}}
		{with_linked_entity "cwps_emitter2" {call "start_%country_%type"}}
		{with_linked_entity "cwps_emitter3" {call "start_%country_%type"}}
		{with_linked_entity "cwps_emitter4" {call "start_%country_%type"}}
		{with_linked_entity "cwps_emitter5" {call "start_%country_%type"}}
		{with_linked_entity "cwps_emitter6" {call "start_%country_%type"}}
	else	;for ships
		
		{if work "body" {with_linked_entity "cwps_proj_point"	{call "start_%country_%type"}}}
		{if work "body1" {with_linked_entity "cwps_emitter1" {call "start_%country_%type"}}}
		{if work "body2" {with_linked_entity "cwps_emitter2" {call "start_%country_%type"}}}
		{if work "bridge_support" {with_linked_entity "cwps_emitter3" {call "start_%country_%type"}}}
		{if work "bridge" {with_linked_entity "cwps_emitter4" {call "start_%country_%type"}}}
		{if work "body5" {with_linked_entity "cwps_emitter5" {call "start_%country_%type"}}}
		{if work "body6" {with_linked_entity "cwps_emitter6" {call "start_%country_%type"}}}
	}
)
(define "jam_remover"		
		{delay %t "jam_remover"
			{tags remove "super_rad_jam"} {kill_delay "jam_remover"}
			{tags remove "high_rad_jam"} {kill_delay "jam_remover"}
			{tags remove "med_rad_jam"} {kill_delay "jam_remover"}
			{tags remove "low_rad_jam"} {kill_delay "jam_remover"}
			
			{tags remove "super_ir_jam"} {kill_delay "jam_remover"}
			{tags remove "high_ir_jam"} {kill_delay "jam_remover"}
			{tags remove "med_ir_jam"} {kill_delay "jam_remover"}
			{tags remove "low_ir_jam"} {kill_delay "jam_remover"}
			
			{tags remove "super_other_jam"} {kill_delay "jam_remover"}
			{tags remove "high_other_jam"} {kill_delay "jam_remover"}
			{tags remove "med_other_jam"} {kill_delay "jam_remover"}
			{tags remove "low_other_jam"} {kill_delay "jam_remover"}
		}
)
{on "drop_flares"
		{if work "flares1"
			{view start "flare_left"}
			{play_sound "flare"}
			{delay 0.1 {view pause "flare_left"}}
			{components "flare_fly_l" repair}
			{delay 3	{components "flare_fly_l" break}}
			{spawn "#flare_patron" "flare1_shooter" x {impulse up 0 1 forward 5 rnd_dir 1 com}} 
		}
		{if work "flares2"
			{view start "flare_right"}
			{play_sound "flare"}
			{delay 0.1 {view pause "flare_right"}}
			{components "flare_fly_r" repair}
			{delay 3	{components "flare_fly_r" break}}
			{spawn "#flare_patron" "flare2_shooter" x {impulse up 0 1 forward 5 rnd_dir 1 com}} 
		}
		{if work "chaff1"
			{view start "chaff_left"}
			{play_sound "flare"}
			{delay 0.1 {view pause "chaff_left"}}
			{components "chaff_fly_l" repair}
			{delay 3	{components "chaff_fly_l" break}}
		}
		{if work "chaff2"
			{view start "chaff_right"}
			{play_sound "flare"}
			{delay 0.1 {view pause "chaff_right"}}
			{components "chaff_fly_r" repair}
			{delay 3	{components "chaff_fly_r" break}}
		}
}
(define "drop_flare" 
		{if work "flares1"
			{view start "flare_left"}
			{play_sound "flare"}
			{delay 0.1 {view pause "flare_left"}}
			{spawn "#flare_patron" "flare1_shooter" x {impulse up 0 1 forward 5 rnd_dir 1 com}}
			{delay 0.03 {spawn "#flare_patron" "flare1_shooter" x {impulse up 0 1 forward 5 rnd_dir 1 com}}}
			{delay 0.06 {spawn "#flare_patron" "flare1_shooter" x {impulse up 0 1 forward 5 rnd_dir 1 com}}}
;			{components "flare_fly_l" repair}
;			{delay 3	{components "flare_fly_l" break}}
			{if rand 1
				{if bone "flare1_shooter"
					{tags add "low_ir_jam"} {kill_delay "jam_remover"}
				}
			}
		}
		{if work "flares2"
			{view start "flare_right"}
			{play_sound "flare"}
			{delay 0.1 {view pause "flare_right"}}
;			{components "flare_fly_r" repair}
;			{delay 3	{components "flare_fly_r" break}}
			{spawn "#flare_patron" "flare2_shooter" x {impulse up 0 1 forward 5 rnd_dir 1 com}} 
			{delay 0.03 {spawn "#flare_patron" "flare2_shooter" x {impulse up 0 1 forward 5 rnd_dir 1 com}}}
			{delay 0.06 {spawn "#flare_patron" "flare2_shooter" x {impulse up 0 1 forward 5 rnd_dir 1 com}}}
			{if rand 1
				{if bone "flare2_shooter"
					{tags add "low_ir_jam"} {kill_delay "jam_remover"}
				}
			}
		}
		("jam_remover" t(10))
)
(define "drop_chaff" 
		{if work "chaff1"
			{view start "chaff_left"}
			{play_sound "flare"}
			{delay 0.1 {view pause "chaff_left"}}
;				{components "chaff_fly_l" repair}
;				{delay 3	{components "chaff_fly_l" break}}
			{spawn "#flare_patron" "flare1_shooter" x {impulse up 0 1 forward 5 rnd_dir 1 com}} 
			{if rand 1
				{if bone "chaff1_shooter"
					{tags add "low_rad_jam"} {kill_delay "jam_remover"}
				}
			}
		}
		{if work "chaff2"
			{view start "chaff_right"}
			{play_sound "flare"}
			{delay 0.1 {view pause "chaff_right"}}
;				{components "chaff_fly_r" repair}
;				{delay 3	{components "chaff_fly_r" break}}
			{spawn "#flare_patron" "flare2_shooter" x {impulse up 0 1 forward 5 rnd_dir 1 com}} 
			{if rand 1
				{if bone "chaff2_shooter"
					{tags add "low_rad_jam"} {kill_delay "jam_remover"}
				}
			}
		}
		("jam_remover" t(10))
)
(define "ir_active_def_work"
	{if work "ir_active_def"
;		{components "ir_defence_sys_1gen" break} 
;		{delay 5 {components "ir_defence_sys_1gen" repair}}
		{if rand 0.5
		    {if bone "ir_1gen_emitter"
				{tags add "med_ir_jam"} {kill_delay "jam_remover"}
			}
		}
	}
)
(define "ir_active_def_2gen_work"
	{if work "ir_active_def"
		{if rand 0.5
		    {if bone "ir_2gen_emitter"
				{tags add "high_ir_jam"} {kill_delay "jam_remover"}
			}
		}
		{if not tagged "stop_soep"
			{if rand 0.85
				{delay 0.5
					{if bone "vitebsk1" {tags add "super_ir_jam"} {kill_delay "jam_remover"}}
					{view show "vitebsk1"}
					{view show "vitebsk2"}
					{view start "vitebsk1"}
					{view start "vitebsk2"}
					{delay 0.3
						{view hide "vitebsk1"}
						{view hide "vitebsk2"}
					}
					{tags add "stop_soep"}
					{weapon_work "soep1" 0}	{weapon_work "soep2" 0}
					{delay 5 {tags remove "stop_soep"} {weapon_work "soep1" 1}	{weapon_work "soep2" 1}}	
				}
			}
		}
	}
	("jam_remover" t(10))
)
(define "ecm_work"
	{if work "ecm"
;		{components "ecm_defence_sys" break} 
;		{delay 5 {components "ecm_defence_sys" repair}}
		{if rand 0.3
		    {if bone "ecm_emitter"
				{tags add "med_rad_jam"} {kill_delay "jam_remover"}
			}
		}
		{if rand 0.3
		    {if bone "ecm_emitter1"
				{tags add "med_rad_jam"} {kill_delay "jam_remover"}
			}
		}
		{if rand 0.3
		    {if bone "ecm_emitter2"
				{tags add "med_rad_jam"} {kill_delay "jam_remover"}
			}
		}
	}
	("jam_remover" t(30))
)
(define "ecm_pod_work"
	{if work "ecm_pod"
;		{components "ecm_pod_defence_sys" break} 
;		{delay 5 {components "ecm_pod_defence_sys" repair}}
		{if rand 0.5
		    {if bone "ecm_pod_emitter"
				{tags add "high_rad_jam"} {kill_delay "jam_remover"}
			}
		}
		{if rand 0.5
		    {if bone "ecm_pod_emitter1"
				{tags add "high_rad_jam"} {kill_delay "jam_remover"}
			}
		}
		{if rand 0.5
		    {if bone "ecm_pod_emitter2"
				{tags add "high_rad_jam"} {kill_delay "jam_remover"}
			}
		}
	}
	("jam_remover" t(30))
)
(define "drop_optic"
	{if rand 1.0
		{if rand 0.5
		    {if bone "shtora1"
				{tags add "med_other_jam"} {kill_delay "jam_remover"}
			}
		else
		    {if bone "shtora2"
				{tags add "high_other_jam"} {kill_delay "jam_remover"}
			}
		}
	}
	("jam_remover" t(10))
)
(define "optic_decoy_spawn"
	{if stuff  "laser_using_missile"	;мешает работе Шторы и СПО
;	     {call "shtora_warn"}
	     {if work "shtora"
		  {if not tagged "no_power"
			{kill_delay "launching_decoy"}
			{view show "shtora"}
			{view start "shtora"}
			{call "shtora_warn"}
			{delay 7 "launching_decoy"
				{view hide "shtora"}
			}
			{delay 0.5 "launching_decoy" ("drop_optic" country(%country) type(%type) decoyprob(%decoyprob))}
			{delay 1 "launching_decoy" ("drop_optic" country(%country) type(%type) decoyprob(%decoyprob))}
			{delay 1.5 "launching_decoy" ("drop_optic" country(%country) type(%type) decoyprob(%decoyprob))}
			{delay 2 "launching_decoy" ("drop_optic" country(%country) type(%type) decoyprob(%decoyprob))}
			{delay 2.5 "launching_decoy" ("drop_optic" country(%country) type(%type) decoyprob(%decoyprob))}
			{delay 3 "launching_decoy" ("drop_optic" country(%country) type(%type) decoyprob(%decoyprob))}
	      }
		 }
	}
)
(define "flare_decoy_spawn"
		{call "IR_warn"}
		{kill_delay "launching_decoy"}
		{delay 0.5 "launching_decoy" ("drop_flare" country(%country) type(%type) decoyprob(%decoyprob))}
		{delay 1 "launching_decoy" ("drop_flare" country(%country) type(%type) decoyprob(%decoyprob))}
		{delay 1.5 "launching_decoy" ("drop_flare" country(%country) type(%type) decoyprob(%decoyprob))}
		{delay 2 "launching_decoy" ("drop_flare" country(%country) type(%type) decoyprob(%decoyprob))}
		{delay 0.5 "launching_decoy"
			("ir_active_def_work" country(%country) type(%type) decoyprob(%decoyprob))
			("ir_active_def_2gen_work" country(%country) type(%type) decoyprob(%decoyprob))
		}
		{delay 1.5 "launching_decoy"
			("ir_active_def_2gen_work" country(%country) type(%type) decoyprob(%decoyprob))
		}
		{delay 2.5 "launching_decoy"
			("ir_active_def_work" country(%country) type(%type) decoyprob(%decoyprob))
			("ir_active_def_2gen_work" country(%country) type(%type) decoyprob(%decoyprob))
		}
)
(define "chaff_decoy_spawn"
		{call "radar_warn"}
		{kill_delay "launching_decoy"}
		{delay 0.5 "launching_decoy" ("drop_chaff" country(%country) type(%type) decoyprob(%decoyprob))}
		{delay 1 "launching_decoy" ("drop_chaff" country(%country) type(%type) decoyprob(%decoyprob))}
		{delay 1.5 "launching_decoy" ("drop_chaff" country(%country) type(%type) decoyprob(%decoyprob))}
		{delay 2 "launching_decoy" ("drop_chaff" country(%country) type(%type) decoyprob(%decoyprob))}
		{delay 1.5 "launching_decoy"
			("ecm_work" country(%country) type(%type) decoyprob(%decoyprob))
			("ecm_pod_work" country(%country) type(%type) decoyprob(%decoyprob))
		}
		{delay 3 "launching_decoy"
			("ecm_pod_work" country(%country) type(%type) decoyprob(%decoyprob))
		}
		{delay 5 "launching_decoy"
			("ecm_work" country(%country) type(%type) decoyprob(%decoyprob))
			("ecm_pod_work" country(%country) type(%type) decoyprob(%decoyprob))
		}
)


		(define "spawn_proj_point_vel"
			{with_linked_entity "cwps_proj_point"
				{ani_wind "forward%advance" end}
			}
			{with_linked_entity "cwps_emitter1"
				{ani_wind "forward%advance" end}
			}
			{with_linked_entity "cwps_emitter2"
				{ani_wind "forward%advance" end}
			}
			{with_linked_entity "cwps_emitter3"
				{ani_wind "forward%advance" end}
			}
			{with_linked_entity "cwps_emitter4"
				{ani_wind "forward%advance" end}
			}
			{with_linked_entity "cwps_emitter5"
				{ani_wind "forward%advance" end}
			}
			{with_linked_entity "cwps_emitter6"
				{ani_wind "forward%advance" end}
			}
		)
		  {on "forward_proj_point"
			{if not tagged "destroyed"
				{if velocity 110
					("spawn_proj_point_vel" advance(6))
				else velocity 90
					("spawn_proj_point_vel" advance(5))
				else velocity 80
					("spawn_proj_point_vel" advance(5))
				else velocity 70
					("spawn_proj_point_vel" advance(4))
				else velocity 60
					("spawn_proj_point_vel" advance(3))
				else velocity 50
					("spawn_proj_point_vel" advance(2))
				else velocity 40
					("spawn_proj_point_vel" advance(1))
				else velocity 20
					("spawn_proj_point_vel" advance(1))
				}
			}
		  }
		
		
;managing of loosing control of missile because of targeting station malfunction
;note that lack of crew or contusion does not lead to increasing missile deviation
;when you have no power or control unit is destroyed, you cannot compensate deviations
;when crew is uncapable, you simply do not track target movement, and missile flies straight

(define "cwps_abort"
	{tags remove "cwps_target_%country_%type"}
	{tags add "cwps_abort_%country_%type"}
	{delay_ex 7 {tags remove "cwps_abort_%country_%type"}}
	{call "stop_%country_%type"}
	{spawn "proj_point_%country_%type"  "basis" x
		{impulse up 10 3 rnd_dir 10 com}
		{gravity 0.5}
		 {kill_delay "normal_hide" }
	}
	("cwps3_stop" country(%country) type(%type))
)
(define "cwps_noadjust"
	{tags remove "cwps_target_%country_%type"}
	{tags add "cwps_abort_%country_%type"}
	{delay_ex 7 {tags remove "cwps_abort_%country_%type"}}
	{spawn "proj_point_spawner"  "basis" x
	 {spawn "proj_point_%country_%type"  "basis" x
		{impulse up 0.01 0.3 forward 0 5 rnd_dir 0 5 com}
		{gravity 0.01}
		{kill_delay "normal_hide" }
	 }
	{delete}
	}
	("cwps3_stop" country(%country) type(%type))
)
		
(define "cwps_mis_cntrl_time"
	{delay_ex %time "cwps_mis_cntrl_time"
	  {if tagged "cwps_target_%country_%type"
		{with_effector 
			{if tagged "no_missile_control"
				{tags remove "cwps_control_%country_%type"}
				{with_effector ("cwps_abort" country(%country) type(%type))}
			else tagged "destroyed"
				{tags remove "cwps_control_%country_%type"}
				{with_effector ("cwps_abort" country(%country) type(%type))}
			else tagged "no_power"
				{tags remove "cwps_control_%country_%type"}
				{with_effector ("cwps_abort" country(%country) type(%type))}
			else not tagged "cwps_control_%country_%type"
				{tags remove "cwps_control_%country_%type"}
				{with_effector ("cwps_abort" country(%country) type(%type))}
			else not operatable
				{tags remove "cwps_control_%country_%type"}
				{with_effector ("cwps_noadjust" country(%country) type(%type))}
			else tagged "contusion"
				{tags remove "cwps_control_%country_%type"}
				{with_effector ("cwps_noadjust" country(%country) type(%type))}

			}
			{with_effector}
		}
	  }
	}
)



	(define "cwps_mis_cntrl"
;this is checks if control station can control its missile
		{on "cwps_mis_cntrl_%country_%type"
		  {if stuff "semiactive"
			{if not tagged "cwps_target_%country_%type"
					{tags add "cwps_target_%country_%type"}	{with_effector {tags add "cwps_control_%country_%type"}	 {with_effector}}
					("cwps_mis_cntrl_time" country(%country) type(%type) time(0.5))
					("cwps_mis_cntrl_time" country(%country) type(%type) time(1.0))
					("cwps_mis_cntrl_time" country(%country) type(%type) time(1.5))
					("cwps_mis_cntrl_time" country(%country) type(%type) time(2.0))
					("cwps_mis_cntrl_time" country(%country) type(%type) time(2.5))
					("cwps_mis_cntrl_time" country(%country) type(%type) time(3.0))
					("cwps_mis_cntrl_time" country(%country) type(%type) time(3.5))
					("cwps_mis_cntrl_time" country(%country) type(%type) time(4.0))
					("cwps_mis_cntrl_time" country(%country) type(%type) time(4.5))
					("cwps_mis_cntrl_time" country(%country) type(%type) time(5.0))
				{if not tagged "cwps_mis_cntrl_7"	
					{delay_ex 5.5 "cwps_mis_cntrl_time"
					  {if tagged "cwps_target_%country_%type"
						{tags remove "cwps_target_%country_%type"} 
						{with_effector {tags remove "cwps_control_%country_%type"}	 {with_effector}}
					  }
					}	
				else
					("cwps_mis_cntrl_time" country(%country) type(%type) time(5.5))
					("cwps_mis_cntrl_time" country(%country) type(%type) time(6.0))
					("cwps_mis_cntrl_time" country(%country) type(%type) time(6.5))
					("cwps_mis_cntrl_time" country(%country) type(%type) time(7.0))
				}
				{if not tagged "cwps_mis_cntrl_9"	
					{delay_ex 5.5 "cwps_mis_cntrl_time"
					  {tags remove "cwps_mis_cntrl_7"}
					  {if tagged "cwps_target_%country_%type"
						{tags remove "cwps_target_%country_%type"}
						{with_effector {tags remove "cwps_control_%country_%type"}	 {with_effector}}
					  }
					}	
				else
					("cwps_mis_cntrl_time" country(%country) type(%type) time(7.5))
					("cwps_mis_cntrl_time" country(%country) type(%type) time(8.0))
					("cwps_mis_cntrl_time" country(%country) type(%type) time(8.5))
					("cwps_mis_cntrl_time" country(%country) type(%type) time(9.0))
				}
				{if not tagged "cwps_mis_cntrl_15"	
					{delay_ex 9.5 "cwps_mis_cntrl_time"
					  {tags remove "cwps_mis_cntrl_7"}
					  {tags remove "cwps_mis_cntrl_9"}
					  {if tagged "cwps_target_%country_%type"
						{tags remove "cwps_target_%country_%type"}
						{with_effector {tags remove "cwps_control_%country_%type"}	 {with_effector}}
					  }
					}	
				else				
					("cwps_mis_cntrl_time" country(%country) type(%type) time(9.5))
					("cwps_mis_cntrl_time" country(%country) type(%type) time(10.0))
					("cwps_mis_cntrl_time" country(%country) type(%type) time(10.5))
					("cwps_mis_cntrl_time" country(%country) type(%type) time(11.0))
					("cwps_mis_cntrl_time" country(%country) type(%type) time(11.5))
					("cwps_mis_cntrl_time" country(%country) type(%type) time(12.0))
					("cwps_mis_cntrl_time" country(%country) type(%type) time(12.5))
					("cwps_mis_cntrl_time" country(%country) type(%type) time(13.0))
					("cwps_mis_cntrl_time" country(%country) type(%type) time(13.5))
					("cwps_mis_cntrl_time" country(%country) type(%type) time(14.0))
					("cwps_mis_cntrl_time" country(%country) type(%type) time(14.5))
					("cwps_mis_cntrl_time" country(%country) type(%type) time(15.0))				
					{delay_ex 15.5 "cwps_mis_cntrl_time"
					  {tags remove "cwps_mis_cntrl_7"}
					  {tags remove "cwps_mis_cntrl_9"}
					  {tags remove "cwps_mis_cntrl_15"}
					  {if tagged "cwps_target_%country_%type"
						{tags remove "cwps_target_%country_%type"}
						{with_effector {tags remove "cwps_control_%country_%type"}	 {with_effector}}
					  }
					}
				}

			else
			  {tags remove "cwps_mis_cntrl_7"}
			  {tags remove "cwps_mis_cntrl_9"}
			  {tags remove "cwps_mis_cntrl_15"}	
			  {if tagged "cwps_target_%country_%type"
				{tags remove "cwps_target_%country_%type"}	
				{with_effector {tags remove "cwps_control_%country_%type"}	 {with_effector}}
			  }
			}
		  }
		}

	)
	
	("cwps_mis_cntrl" country(rus) type(laser))
	("cwps_mis_cntrl" country(usa) type(laser))
	("cwps_mis_cntrl" country(rus) type(other))
	("cwps_mis_cntrl" country(usa) type(other))
	("cwps_mis_cntrl" country(rus) type(active))
	("cwps_mis_cntrl" country(usa) type(active))
		
	{on "cwps_semi_rem_tags"
		(define "remove_ct_tag"
			{tags remove "cwps_abort_%country_%type"}
			{tags remove "cwps_target_%country_%type"}
			{tags remove "cwps_control_%country_%type"}
		)
		{kill_delay "cwps_mis_cntrl_time"}
		("remove_ct_tag" country(rus) type(laser))
		("remove_ct_tag" country(usa) type(laser))
		("remove_ct_tag" country(rus) type(other))
		("remove_ct_tag" country(usa) type(other))
		("remove_ct_tag" country(rus) type(active))
		("remove_ct_tag" country(usa) type(active))
		{tags remove "cwps_mis_cntrl_7"}
		{tags remove "cwps_mis_cntrl_9"}
		{tags remove "cwps_mis_cntrl_15"}
	}

	{on "check_proj_type"
		(define "point_move"
		  {if not velocity 15
			{if rand 0.33
				{if rand 0.5 {ani_play "rand1" 0.1 loop}
				else {ani_play "rand1" -0.1 loop}
				}
			else rand 0.5
				{if rand 0.5 {ani_play "rand1" 0.07 loop}
				else {ani_play "rand1" -0.07 loop}
				}
			else
				{if rand 0.5 {ani_play "rand1" 0.13 loop}
				else {ani_play "rand1" -0.13 loop}
				}
			}
		  }
		)
		(define "spawn_proj_point" 
		   ;{delay 0.5 0.1 {ani_stop "rand1"}}
		  {if altitude %min_alt		;два корня из реальной высоты
		    {if not tagged "cwps_abort_%country_%type"

			{call "forward_proj_point"}

			else 
				{ani_stop "rand1"} ("cwps3_stop" country(%country) type(%type))
			}
		  else
		    {ani_stop "rand1"} ("cwps3_stop" country(%country) type(%type))
		  }
		)
		(define "spawn_proj_passive"	
			{if operatable {if not tagged "destroyed" {if not tagged "proj_passive_decoy"
				{tags add "proj_passive_decoy"}
				("%decoytype_decoy_spawn" country(%country) type(%type) decoytype(%decoytype) decoyprob(%decoyprob))
				{delay 2 {tags remove "proj_passive_decoy"}}
			}}}	
			
			{kill_delay "CWPS3_passive"}
			{if not altitude 15
			{delay 2.0
			("point_move")
			}
			}
			("cwps3_start" country(%country) type(%type))
			

			{delay 0.1("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 0.5 "CWPS_guidance1" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 1.0 "CWPS_guidance2" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}

			{delay 2.3 "CWPS3_passive"  {ani_stop "rand1"} ("cwps3_stop" country(%country) type(%type))}	

;			{delay 1.5 "CWPS_guidance3" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
;			{delay 2.0 "CWPS_guidance4" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
;			{delay 2.5 "CWPS_guidance5" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
;			{delay 3.0 "CWPS_guidance6" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
;			{delay 3.5 "CWPS_guidance7" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
		)
		(define "spawn_proj_1"
			{tags remove "cwps_abort_%country_%type"}
			{if operatable {if not tagged "destroyed"
				("%decoytype_decoy_spawn" country(%country) type(%type) min_alt(%min_alt) decoytype(%decoytype) decoyprob(%decoyprob))
				{call "cwps_mis_cntrl_%country_%type"}
			}}
			
			{kill_delay "CWPS3_delay"}
			{if not altitude 15
			{delay 2.0
			("point_move")
			}
			}
			("cwps3_start" country(%country) type(%type))
			{with_linked_entity "cwps_proj_point"	{detect 2}}

			("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))

			{delay 1 "CWPS3_delay"  {ani_stop "rand1"} ("cwps3_stop" country(%country) type(%type))}	
		)
		(define "spawn_proj_5"
;====================decoy_processing======

;			("spawn_proj_1" country(%country) type(%type) min_alt(%min_alt) decoytype(%decoytype) decoyprob(%decoyprob))
			{tags remove "cwps_abort_%country_%type"}
			{if operatable {if not tagged "destroyed"
				("%decoytype_decoy_spawn" country(%country) type(%type) min_alt(%min_alt) decoytype(%decoytype) decoyprob(%decoyprob))
				{call "cwps_mis_cntrl_%country_%type"}
			}}
			
			{kill_delay "CWPS3_delay"}
			{if not altitude 15
			{delay 2.0
			("point_move")
			}
			}
			("cwps3_start" country(%country) type(%type))
			{with_linked_entity "cwps_proj_point"	{detect 5}}

			("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))

			{delay 0.5 "CWPS_guidance1" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 1.0 "CWPS_guidance2" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}		
			{delay 1.5 "CWPS_guidance3" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 2.0 "CWPS_guidance4" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 2.5 "CWPS_guidance5" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 3.0 "CWPS_guidance6" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 3.5 "CWPS_guidance7" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 4.0 "CWPS_guidance8" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 4.5 "CWPS_guidance9" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 5.0 "CWPS_guidance10" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			

			{delay 5.5 "CWPS3_delay"  {ani_stop "rand1"} ("cwps3_stop" country(%country) type(%type))}	
		)
		(define "spawn_proj_7"
			{tags add "cwps_mis_cntrl_7"}
;			("spawn_proj_5" country(%country) type(%type) min_alt(%min_alt) decoytype(%decoytype) decoyprob(%decoyprob))
			{tags remove "cwps_abort_%country_%type"}
			{if operatable {if not tagged "destroyed"
				("%decoytype_decoy_spawn" country(%country) type(%type) min_alt(%min_alt) decoytype(%decoytype) decoyprob(%decoyprob))
				{call "cwps_mis_cntrl_%country_%type"}
			}}
			
			{kill_delay "CWPS3_delay"}
			{if not altitude 15
			{delay 2.0
			("point_move")
			}
			}
			("cwps3_start" country(%country) type(%type))
			{with_linked_entity "cwps_proj_point"	{detect 7}}

			("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))

			{delay 0.5 "CWPS_guidance1" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 1.0 "CWPS_guidance2" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}		
			{delay 1.5 "CWPS_guidance3" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 2.0 "CWPS_guidance4" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 2.5 "CWPS_guidance5" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 3.0 "CWPS_guidance6" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 3.5 "CWPS_guidance7" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 4.0 "CWPS_guidance8" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 4.5 "CWPS_guidance9" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 5.0 "CWPS_guidance10" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}

			{delay 5.5 "CWPS_guidance11" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 6.0 "CWPS_guidance12" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 6.5 "CWPS_guidance13" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 7.0 "CWPS_guidance14" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}

			{delay 7.5 "CWPS3_delay"  {ani_stop "rand1"} ("cwps3_stop" country(%country) type(%type))}	
		)
		(define "spawn_proj_9"
			{tags add "cwps_mis_cntrl_9"}
;			("spawn_proj_7" country(%country) type(%type) min_alt(%min_alt) decoytype(%decoytype) decoyprob(%decoyprob))

			{tags remove "cwps_abort_%country_%type"}
			{if operatable {if not tagged "destroyed"
				("%decoytype_decoy_spawn" country(%country) type(%type) min_alt(%min_alt) decoytype(%decoytype) decoyprob(%decoyprob))
				{call "cwps_mis_cntrl_%country_%type"}
			}}
			
			{kill_delay "CWPS3_delay"}
			{if not altitude 15
			{delay 2.0
			("point_move")
			}
			}
			("cwps3_start" country(%country) type(%type))
			{with_linked_entity "cwps_proj_point"	{detect 9}}

			("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))

			{delay 0.5 "CWPS_guidance1" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 1.0 "CWPS_guidance2" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}		
			{delay 1.5 "CWPS_guidance3" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 2.0 "CWPS_guidance4" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 2.5 "CWPS_guidance5" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 3.0 "CWPS_guidance6" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 3.5 "CWPS_guidance7" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 4.0 "CWPS_guidance8" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 4.5 "CWPS_guidance9" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 5.0 "CWPS_guidance10" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}

			{delay 5.5 "CWPS_guidance11" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 6.0 "CWPS_guidance12" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 6.5 "CWPS_guidance13" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 7.0 "CWPS_guidance14" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}

			{delay 7.5 "CWPS_guidance15" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 8.0 "CWPS_guidance16" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 8.5 "CWPS_guidance17" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 9.0 "CWPS_guidance18" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}

			{delay 9.5 "CWPS3_delay"  {ani_stop "rand1"} ("cwps3_stop" country(%country) type(%type))}	
		)
		(define "spawn_proj_15"
			{tags add "cwps_mis_cntrl_15"}
;			("spawn_proj_9" country(%country) type(%type) min_alt(%min_alt) decoytype(%decoytype) decoyprob(%decoyprob))
			{tags remove "cwps_abort_%country_%type"}
			{if operatable {if not tagged "destroyed"
				("%decoytype_decoy_spawn" country(%country) type(%type) min_alt(%min_alt) decoytype(%decoytype) decoyprob(%decoyprob))
				{call "cwps_mis_cntrl_%country_%type"}
			}}
			
			{kill_delay "CWPS3_%country_%type"}
			{if not altitude 15
			{delay 2.0
			("point_move")
			}
			}
			("cwps3_start" country(%country) type(%type))
			{with_linked_entity "cwps_proj_point"	{detect 15}}

			("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))

			{delay 0.5 "CWPS_guidance1" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 1.0 "CWPS_guidance2" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}		
			{delay 1.5 "CWPS_guidance3" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 2.0 "CWPS_guidance4" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 2.5 "CWPS_guidance5" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 3.0 "CWPS_guidance6" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 3.5 "CWPS_guidance7" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 4.0 "CWPS_guidance8" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 4.5 "CWPS_guidance9" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 5.0 "CWPS_guidance10" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}

			{delay 5.5 "CWPS_guidance11" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 6.0 "CWPS_guidance12" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 6.5 "CWPS_guidance13" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 7.0 "CWPS_guidance14" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}

			{delay 7.5 "CWPS_guidance15" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 8.0 "CWPS_guidance16" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 8.5 "CWPS_guidance17" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 9.0 "CWPS_guidance18" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}

			{delay 9.5 "CWPS_guidance15" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 10.0 "CWPS_guidance16" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 10.5 "CWPS_guidance17" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 11.0 "CWPS_guidance18" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 11.5 "CWPS_guidance19" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 12.0 "CWPS_guidance20" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 12.5 "CWPS_guidance21" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 13.0 "CWPS_guidance22" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 13.5 "CWPS_guidance23" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 14.0 "CWPS_guidance24" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 14.5 "CWPS_guidance25" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}
			{delay 15.0 "CWPS_guidance26" ("spawn_proj_point" country(%country) type(%type) min_alt(%min_alt))}

			{delay 15.5 "CWPS3_delay"  {ani_stop "rand1"} ("cwps3_stop" country(%country) type(%type))}
			
		)
(include "/lists/missile_settings1.inc")
	}
