;======================CWPS 1 - Cold War Projectile System by Timosh
;first missile system, do not use. Is used in SP only
;Contains no inherited events, you can not look here at all

(include "missile_cwps1.inc")

;======================CWPS 3 - Cold War Projectile System by Timosh
;used on MOWAS2. On MOW2 tends to fly through targets - should be used mostly for torpedoes
;Contains a lot of records that are inherited by impulse missiles
;Not obsolete
(include "missile_cwps3.inc")

;===================================Helpers
;Additional entities used both for CWPS3 and for CWPS Impulse
{"proj_probe"
	{on spawn
		{delay 0.2 
			{impulse up -555 com} 
			{delay 5.0 {delete}}
		}
	}
}
{"proj_point"
	{on spawn
		{delay 2.1 "normal_hide" {delete}}
		{delay 2 "emergency_hide" {delete}}
		{delay 0.2
		     {if tagged "cwps_ground_attack"
				{kill_delay "normal_hide"}
				{kill_delay "emergency_hide"}
				{delay 50 {delete}}
		     }
		}
		{delay 5
		 {if tagged "inertial_gs"
	     {delay 1 
		    {volumes "target" disable bullet visible}
			 {volumes "body" disable bullet visible}
		 }
	     }
		}
	}
	{on overlap begin
		{if tagged "cwps_ground_attack" {delay 0.1 {delete}}}
		{if effector "cwps_rangefinder"
			{with_effector
				{call "top_attack"}
		    }
		}
		{if tagged "proj_vitebsk"
		{volumes disable bullet visible}
		}
	}
}

{"proj_point_gps_ground"
	{on spawn
		{volumes disable contact contact_ground blast}
		{physics_work 0}
	}
	{on bullet_hit
		{volumes "target_gorka" disable all}
		{components "body" break}
	}
}

{"proj_point_acc"
    {on spawn
		{impulse up 0.01 com} {gravity 0.0}
		{delay_ex 1.0 {physics_work 1}  {impulse rnd_dir 0.11 com}}
		{delay_ex 2.0   {impulse rnd_dir 0.11 com}}
		{delay_ex 3.0  {impulse rnd_dir 0.21 com}}
		{delay_ex 4.0  {impulse rnd_dir 0.35 com}}
		{delay_ex 5.0  {impulse rnd_dir  0.45 com}}
		{delay 6.0 {delete}}
		 
    }
	{on contact overload
		{if effector "vehicle"
			{delete}             ; udaleniye pri nayezde tekhniki na marker
		}
	}
}
{"proj_point_dummy"
     {on spawn 
	  {delay 0.1 {delete}}
	 }
}
{"proj_point_ground"
     {on spawn
	 {impulse up -0.01 com}
	 {gravity 0.0}
	  {delay_ex 1  {impulse forward 0.31 com}  

	  }
	 {delay_ex 2.0  {impulse forward 1.01 com}  ; vertikal'nyy razbros. Randomnoye napravleniye mozhet zagnat' marker pod zemlyu, ili v vozdukh

	  }
	   {delay_ex 3.0  {impulse forward -2.11 com} ; + postoyannoye dvizheniye dlya udaleniya markera v sluchaye, yesli ne srabotayet 1357 stroka

	   }
	   {delay_ex 4.0  {impulse forward 1.11 com}

	   }
	   {delay_ex 5.0  {impulse forward -1.11 com}

	   }
	 }
	{on contact overload
	{if effector "vehicle" ; udaleniye pri nayezde tekhniki na marker
	 {if not effector "cannon"  ; stankovka mozhet svobodno khodit' po markeru, i on ne budet udalayat'sya
	  {if not tagged "ground_far" ; for NLOS
	   {delete}
	  }
	 }
	}
	 {if effector "proj_point_acc" {with_effector {physics_work 0}{with_effector}} ; v sluchaye, yesli odnovremenno zaspavnyatsya oba markera (chasto voznikalo pri popadanii v traki ili nld
	   {delete}
	 }
	}
}


{"cwps3_proj_point"
	{on spawn overload
		{components "rus_active" break}
		{components "rus_antiship" break}
		{components "rus_ir" break}
		{components "rus_laser" break}
		{components "rus_laser_spot" break}
		{components "rus_other" break}
		{components "rus_radpassive" break}
		
		{components "usa_active" break}
		{components "usa_antiship" break}
		{components "usa_ir" break}
		{components "usa_laser" break}
		{components "usa_other" break}
		{components "usa_radpassive" break}
		{ani_play "hide"}
		{delay 0.1 {player -1}}
	}
	{on "sp_convoy_attack"	;for sp only
		{spawn "sp_convoy_assistor" "basis" x no_normal no_position}
	}
	{on overlap begin overload
		{if tagged "forward"
		   {volumes enable bullet}
		   {ani_wind "forward1" begin}
		   {ani_wind "forward2" begin}
		   {ani_wind "forward3" begin}
		   {ani_wind "forward4" begin}
		   {ani_wind "forward5" begin}
		   {ani_wind "forward6" begin}

		{tags add "stop_forward"}
		{delay_ex 1 {if tagged "stop_forward" {tags remove "stop_forward"}} {volumes disable bullet}}
		}
		{if effector "cwps_rangefinder"
		  {if effector "ignore_linked_pointer" and linked
		  else
			{with_effector
				{call "top_attack"}
		    }
		  }
		}
	}
	{on bullet_hit
		{if stuff "cwps2"
			{kill_delay "incoming"}
			{set "stop" 1}
			{ani_wind "forward1" begin}
			{delay 2 "incoming" {set "stop" 0}}
		}
	}
(define "actions"
	{on "start_%country_%type"
		{components "%country_%type" repair}
		(mod "mp" {player 1})
;		(mod not "mp" {player 15})
		(mod not "mp" {player 7})
		(mod "coop" {player 7})
		{ani_wind "hide" begin}
		{tags add "cwps3_locked"}
	}
	{on "stop_%country_%type"
		{components "%country_%type" break}

		{if not work "rus_active"
		{if not work "rus_antiship"
		{if not work "rus_ir"
		{if not work "rus_laser"
		{if not work "rus_laser_spot"
		{if not work "rus_other"
		{if not work "usa_radpassive"

		{if not work "usa_active"
		{if not work "usa_antiship"
		{if not work "usa_ir"
		{if not work "usa_laser"
		{if not work "usa_other"
		{if not work "usa_radpassive"
			{player -1}
			{ani_play "hide"}
			{tags remove "cwps3_locked"}

		}}}}}}}}}}}}}
	}
)
("actions" country(rus) type(active))
("actions" country(rus) type(antiship))
("actions" country(rus) type(ir))
("actions" country(rus) type(laser))
("actions" country(rus) type(laser_spot))
("actions" country(rus) type(other))
("actions" country(rus) type(radpassive))
	
("actions" country(usa) type(active))
("actions" country(usa) type(antiship))
("actions" country(usa) type(ir))
("actions" country(usa) type(laser))
("actions" country(usa) type(other))
("actions" country(usa) type(radpassive))
	
	
	
}
{"cw_bullet_target"
    {on spawn
	    {impulse up -5}
        (mod "mp"{player 1}) (mod not "mp"{player 7})
		{delay 3 {delete}}
    }
}
{"balmis_detector"
    {on spawn
		{delay 1 {delete}}
    }
    {on contact
	    {if effector "radioproximity"
	    {volumes disable contact}
		{if altitude 5
		    {physics_work 0}
		    {volumes enable bullet}
			{with_effector
				{call "detonate"}
			}
		}
		}		
	}
}
{"proj_point_guide"
    {on spawn
	    {tags add "1111t"}
	  (mod "mp"{player 1}) (mod not "mp"{player 7})
		{if not altitude 15
		  {volumes disable bullet visible}
		}
		{delay 1 {delete}}
    }
}
{"antirad_spawner"
	{on spawn	overload
			{delay 0.1 {spawn "cwship_informer" "basis" local_offset 0 0 40 {tags add "antirad_linked"} {impulse up 3 com}}}
		{delay 1 
			{if not linked  {delete}
			else 
			{spawn "cwship_informer" "body_holder" local_offset 0 0 300 {tags add "antirad_linked"} {impulse up 3 com}}
			}
		}
	}
	{on "start"
		{ani_play "rand_move" loop}
		{with_linked_entity "point"
			{tags remove "no_minimap"}
			{volumes "body" enable visible}
			{volumes "target" enable visible}
			{components "body" repair}
		}
	}
	{on "stop"
		{ani_stop "rand_move"}
		{with_linked_entity "point"
			{tags add "no_minimap"}
			{volumes "body" disable visible}
			{volumes "target" disable visible}
			{components "body" break}
		}
	}
}
{"minimap_antirad"
	{on spawn	overload
		{delay 1 {if not linked {delete}}}
	}
}
{"proj_point_rus_large_antirad"
	{on overlap begin overload
		{if effector "cwps_antirad_usa"
			{with_effector {call "top_attack"}}
		}
	}
}
{"proj_point_rus_antirad"
	{on overlap begin overload
		{if effector "cwps_antirad_usa"
			{with_effector {call "top_attack"}}
		}
	}
}
{"proj_point_usa_large_antirad"
	{on overlap begin overload
		{if effector "cwps_antirad_rus"
			{with_effector {call "top_attack"}}
		}
	}
}
{"proj_point_usa_antirad"
	{on overlap begin overload
		{if effector "cwps_antirad_rus"
			{with_effector {call "top_attack"}}
		}
	}
}
{"minimap_antirad"
	{on spawn	overload
		{delay 1 {if not linked {delete}}}
	}
}
{"proj_point_rus_large_antirad"
	{on overlap begin overload
		{if effector "cwps_antirad_usa"
			{with_effector {call "top_attack"}}
		}
	}
}
{"proj_point_rus_antirad"
	{on overlap begin overload
		{if effector "cwps_antirad_usa"
			{with_effector {call "top_attack"}}
		}
	}
}
{"proj_point_usa_large_antirad"
	{on overlap begin overload
		{if effector "cwps_antirad_rus"
			{with_effector {call "top_attack"}}
		}
	}
}
{"proj_point_usa_antirad"
	{on overlap begin overload
		{if effector "cwps_antirad_rus"
			{with_effector {call "top_attack"}}
		}
	}
}
)
{"smoke_volume"
	{on spawn
		{delay 0.1 {gravity 0.01} {constrain_velocity 0.5}}
		{tags add "smoke"}
		{volumes "smoke1" enable visible contact}
		{update_visibility_patch}
		{spawn "smoke_volume_helper" local_offset 0 0 -300}
		{delay 0.5
			{volumes "smoke2" enable visible contact} {update_visibility_patch}
		}
		{delay 1
			{volumes "smoke3" enable visible contact} {update_visibility_patch}
		}
		{delay 10{hide 1}}
	}
}
{"smoke_volume_helper"
	{on spawn
		{add_smoke_obstacle radius 220 fill_time 1 rise_time 1 dissolve_period 9 11}
		{delay 10 {remove_smoke_obstacle}{hide 1}}
	}
}
{"smoke_volume_ground"
	{on spawn
		{delay 0.1 {gravity 0.01} {constrain_velocity 0.5}}
		{tags add "smoke"}
		{volumes "smoke1" enable visible contact}
		{update_visibility_patch}
		{add_smoke_obstacle radius 160 fill_time 5 rise_time 5 dissolve_period 56 62}
		{delay 2
			{volumes "smoke2" enable visible contact}	{update_visibility_patch}
		}
		{delay 5
			{volumes "smoke3" enable visible contact}	{update_visibility_patch}
		}
		{delay 60 	{remove_smoke_obstacle}{hide 1}}
	}
}
{"piece_missile_booster"
	{on spawn 
		{delay 10 {hide 3}}
		{delay 0.1 
			{volumes "part" enable contact_ground}
			{volumes "part1" enable contact_ground}
			{volumes "part2" enable contact_ground}
			{volumes "part3" enable contact_ground}
			{volumes "part4" enable contact_ground}
			{volumes "starter" enable contact_ground}
		    {if not flag "fall" {impulse up -0.1 forward 30 rnd_dir 2}}
			{set "fall" 1}
		}
		{delay 1 
			{volumes "part" enable contact contact_ground}
			{volumes "part1" enable contact contact_ground}
			{volumes "part2" enable contact contact_ground}
			{volumes "part3" enable contact contact_ground}
			{volumes "part4" enable contact contact_ground}
			{volumes "starter" enable contact contact_ground}
		}
		{add_view "steam" "steam" "root"}
		{view start "steam"}
		{view show "steam"}
	}
	{on ground_hit
		{view stop "steam"}
		{view pause "steam"}
	}
}
{"sub_helper"
	{on spawn 
		{volumes "body" disable contact}
		{if altitude -1 {tags add "surface_launch"}
		else {tags add "underwater_launch"}}
		{delay 1 {volumes "body" enable contact}}
		{if tagged "surface_launch" 
			{volumes "ballast1" disable float}
			{volumes "body" disable contact}
			{delay 2 {volumes "body" enable contact}}
		}
		{volumes "ballast2" disable float}
		{impulse forward 50 com}
		{ani_play "on_start"}
		{delay 0.5 {call "check_altitiude"}}
		{delay 10 {hide}}
	}
	{on "check_altitiude"
		{kill_delay "check_altitiude"}
		{if not tagged "destroyed"
			{if tagged "surface_launch"
				{if not altitude -5
					{tags add "underwater_launch"}
					{tags remove "surface_launch"}
					{volumes "ballast1" enable float}
				}
			}
			{if altitude -4
			  {if tagged "underwater_launch"
				{call "spawn_missile"}
			  }
			}
			{delay 0.5 "check_altitiude" {call "check_altitiude"}}
		}
	}
	{on "detonate" overload
		{if not tagged "destroyed" {inherited}}
	}
	(define "spawn_spherewaters"
		  {if not tagged "spawn_underwater"
		    {tags add "spawn_underwater"}
			{spawn "spherewater_big"}
			{spawn "spherewater_big2" local_offset -50 0 0}
			{spawn "spherewater_big2" local_offset -100 0 0}
			{spawn "spherewater_big2" local_offset -150 0 0}
		  }
	)
	{on ground_hit overload
	  {if terrain_fx "water"
		("spawn_spherewaters")
	  else terrain_fx "shallow_water"
	  	("spawn_spherewaters")
	  else terrain_fx "deep_water"
	  	("spawn_spherewaters")
	  else {inherited}
	  }
	}
}
{"caliber_sub_helper"
	{on "spawn_missile" 
		{spawn "ex_water_big"}
		{spawn "3m14_carrier" "foresight2" x}
		{bone cut "part1"}
		{tags add "destroyed"}
		{volumes "body" disable contact bullet blast}
	}
}
{"caliber54_sub_helper"
	{on "spawn_missile" 
		{spawn "ex_water_big"}
		{spawn "3m54_carrier" "foresight2" x}
		{bone cut "part1"}
		{tags add "destroyed"}
		{volumes "body" disable contact bullet blast}
	}
}
{"vodopad_sub_helper"
	{on "spawn_missile" 
		{spawn "ex_water_big"}
		{spawn "vodopad_carrier" "foresight2" x}
		{delete}
	}
}
{"veter_sub_helper"
	{on "spawn_missile" 
		{spawn "ex_water_big"}
		{spawn "veter_carrier" "foresight2" x}
		{delete}
	}
}
{"harpoon_sub_helper"
	{on spawn
		{delay 0.1 {constrain_velocity 10}}
	}
	{on "spawn_missile" 
		{spawn "ex_water_big"}
		{spawn "ugm-84a_carrier" "foresight2" x}
		{tags add "destroyed"}
		{volumes "body" disable contact bullet blast}
	}
}

;==================torpedo chassis modification. Not expected to work with impulse engine
{"cwps_torpedo"
	{on spawn {volumes "rangefinder" disable all} {volumes "rangefinder" enable overlap}
		{add_view "wash_torpedo_small" "tail" "missile_point"}	{view start "tail"}

	}
	{on overlap begin
		{if effector "submarine" 
		;{bone cut "rangefinder_holder"} 
		{volumes "rangefinder" disable all}
		{ani_play "down" 1.3}}
	}

}
{"allow_manual_control"
(define "cwps_abort"
	{volumes "missile" disable select touch}
	{able select 0}
)

(define "cwps_mis_cntrl_time"
	{delay_ex %time "cwps_mis_cntrl_time"
		{with_effector 
			{if tagged "no_missile_control"
				{with_effector ("cwps_abort")}
			else tagged "destroyed"
				{with_effector ("cwps_abort")}
			else tagged "no_power"
				{with_effector ("cwps_abort")}
			else not operatable
				{with_effector ("cwps_abort")}
			else tagged "contusion"
				{with_effector ("cwps_abort")}
			}
			{with_effector}
		}
	}
)

	(define "cwps_mis_cntrl"
;this is checks if control station can control its missile
					("cwps_mis_cntrl_time" time(0.5))
					("cwps_mis_cntrl_time" time(1.0))
					("cwps_mis_cntrl_time" time(1.5))
					("cwps_mis_cntrl_time" time(2.0))
					("cwps_mis_cntrl_time" time(2.5))
					("cwps_mis_cntrl_time" time(3.0))
					("cwps_mis_cntrl_time" time(3.5))
					("cwps_mis_cntrl_time" time(4.0))
					("cwps_mis_cntrl_time" time(4.5))
					("cwps_mis_cntrl_time" time(5.0))
					("cwps_mis_cntrl_time" time(5.5))
					("cwps_mis_cntrl_time" time(6.0))
					("cwps_mis_cntrl_time" time(6.5))
					("cwps_mis_cntrl_time" time(7.0))
					("cwps_mis_cntrl_time" time(7.5))
					("cwps_mis_cntrl_time" time(8.0))
					("cwps_mis_cntrl_time" time(8.5))
					("cwps_mis_cntrl_time" time(9.0))
					("cwps_mis_cntrl_time" time(9.5))
					("cwps_mis_cntrl_time" time(10.0))
					("cwps_mis_cntrl_time" time(10.5))
					("cwps_mis_cntrl_time" time(11.0))
					("cwps_mis_cntrl_time" time(11.5))
					("cwps_mis_cntrl_time" time(12.0))
					("cwps_mis_cntrl_time" time(12.5))
					("cwps_mis_cntrl_time" time(13.0))
					("cwps_mis_cntrl_time" time(13.5))
					("cwps_mis_cntrl_time" time(14.0))
					("cwps_mis_cntrl_time" time(14.5))
					("cwps_mis_cntrl_time" time(15.0))
	)
	{on spawn
		{if altitude 3
	    {volumes "control_probe" disable contact}
		{delay 3 {volumes "control_probe" enable contact}}
		}
	}
	{on contact overload
		{if volume "control_probe" 
		  {if effector "vehicle_common"
			{volumes "control_probe" disable all} ("cwps_mis_cntrl")
		  else {volumes "control_probe" disable all}
		  }
		else {inherited}
		}
	}
}
;для импульсных ракет координата считается по координатам БЧ, для обычных - где базис карриера.
(define "jammed_manual_control_missile"
{"allow_manual_control ecm_vulnerable_%side"
	{on "ecm_jammed"
		{if tagged "ecm_effect_3"
			{reset_manual_control}
			{volumes "missile" disable select touch}
			{able select 0}
		}
	}
}
{"allow_manual_control proj_impulse ecm_vulnerable_%side"
	{on "ecm_jammed" overload
		{if tagged "ecm_effect_4"
			{reset_manual_control}
			{volumes "missile" disable select touch}
			{able select 0}
		}
	}
}
)
("jammed_manual_control_missile" side(rus))("jammed_manual_control_missile" side(usa))
{"heavy_antiship"
     {on blast_hit overload
	  {if min_energy 1
	    {if rand 0.8
			{call "detonate"}
		else  
			{spawn "aero_die_particle" "missile_point" x}
			{if rand 0.5
				{burn fx "aero_die_fire" fake}
			}		
			{if rand 0.5
				{tags remove "guided"}  {weapon_work "targeting_sys" 0} {weapon_work "targeting_sys_anti_jamming" 0}
			}
		}
		
	  }
     }
     {on blast overload
     }
	  {on break_armor
		{if component "missile" {call "detonate"}}
     }
	{on contact overload
		{if effector "proj_deleter"
			{call "destroyed_by_ground"}
		else effector "proj_dummy" 
			{with_effector 
				{volumes disable contact}
			{with_effector}}
		else {inherited}}
	}
}

{"medium_antiship"
     {on blast_hit overload
	  {if min_energy 1
	    {if rand 0.5
			{call "detonate"}
		else  
			{spawn "aero_die_particle" "missile_point" x}
			{if rand 0.5
				{burn fx "aero_die_fire" fake}
			}		
			{if rand 0.5
				{tags remove "guided"}  {weapon_work "targeting_sys" 0} {weapon_work "targeting_sys_anti_jamming" 0}
			}
		}
		
	  }
     }
     {on blast overload
     }
	  {on break_armor
		{if component "missile" {call "detonate"}}
     }
	{on contact overload
		{if effector "proj_deleter"
			{call "destroyed_by_ground"}
		else not effector "proj_dummy" {inherited}}
	}
}

{"heavy_antiship_impactor_link"
     {on pierce overload
     }
	 {on bullet_hit overload
     }
     {on blast_hit overload
     }
     {on blast overload
     }
	{on contact overload
	}
}
;Дальность ЗУР и ВВ	slow	normal	fast
;			7м/шаг	10м/шаг	10м/шаг
;всего		300м	400м	400м
;плюс 20 проц. на маневр (это около 30м), плюс 4 шага для вертикалок.
;Дальность ATGM и AGM	slow	normal	fast
;			5м/шаг	7м/шаг	7м/шаг
;всего		200м	300м	300м
;плюс 10 проц. на маневр (это около 14м)
(define "tracer"
	{on "manage_effects1"
		{delay 0.1 {with_linked_entity "missile" 
			{add_view	"%tracer"			"proj_tracer"			"%bone"}
			{view start "proj_tracer"}
			{view show "proj_tracer"}
		}}
	}
)
(define "jam_tag_selector"
	tagged "%tag"
		{with_effector  
		  {if not tagged "checked"
		    {tags add "checked"}
			{if not tagged "100m_fly"
				{if rand ( * %tag1 %decoyprob) {call "missile_missed"} {with_effector}}
			else tagged "100m_fly"
				{if rand ( * %tag1 (* 1.25 %decoyprob)) {call "missile_missed"} {with_effector}}
			}
		  }
		}	
	
)
(define "missile_jam"
	{if ("jam_tag_selector" tag(super_rad_jam) tag1(%super_rad_jam) decoyprob(%decoyprob))
	else ("jam_tag_selector" tag(high_rad_jam) tag1(%high_rad_jam) decoyprob(%decoyprob))
	else ("jam_tag_selector" tag(med_rad_jam) tag1(%med_rad_jam) decoyprob(%decoyprob))
	else ("jam_tag_selector" tag(low_rad_jam) tag1(%low_rad_jam) decoyprob(%decoyprob))
	}
	
	{if ("jam_tag_selector" tag(super_ir_jam) tag1(%super_ir_jam) decoyprob(%decoyprob))
	else ("jam_tag_selector" tag(high_ir_jam) tag1(%high_ir_jam) decoyprob(%decoyprob))
	else ("jam_tag_selector" tag(med_ir_jam) tag1(%med_ir_jam) decoyprob(%decoyprob))
	else ("jam_tag_selector" tag(low_ir_jam) tag1(%low_ir_jam) decoyprob(%decoyprob))
	}
	
	{if ("jam_tag_selector" tag(super_other_jam) tag1(%super_other_jam) decoyprob(%decoyprob))
	else ("jam_tag_selector" tag(high_other_jam) tag1(%high_other_jam) decoyprob(%decoyprob))
	else ("jam_tag_selector" tag(med_other_jam) tag1(%med_other_jam) decoyprob(%decoyprob))
	else ("jam_tag_selector" tag(low_other_jam) tag1(%low_other_jam) decoyprob(%decoyprob))
	}
)
(define "missile_missed"
	{on "missile_missed"
		{volumes "proximity" disable contact}
		{tags remove "guided"}  {weapon_work "targeting_sys" 0} {weapon_work "targeting_sys_anti_jamming" 0}
		{call "change_direction"}
		{damage_report "root" "component/jamming_work"}
	}
	{on overlap begin
		{delay 0.1 {volumes "overlap_volume" enable overlap}}
		{if effector "helicopter_M"
			{with_effector
				{if not altitude 30
					("missile_jam" decoyprob(%decoyprob) 
						super_rad_jam(3.5) high_rad_jam(3.0) med_rad_jam(2.5) low_rad_jam(2.0)
						super_ir_jam(2.0) high_ir_jam(1.5) med_ir_jam(1.0) low_ir_jam(0.5)
						super_other_jam(2.0) high_other_jam(1.5) med_other_jam(1.0) low_other_jam(0.5)
					)
				else not altitude 65
					("missile_jam" decoyprob(%decoyprob) 
						super_rad_jam(1.75) high_rad_jam(1.25) med_rad_jam(1.0) low_rad_jam(0.75)
						super_ir_jam(2.0) high_ir_jam(1.5) med_ir_jam(1.0) low_ir_jam(0.5)
						super_other_jam(2.0) high_other_jam(1.5) med_other_jam(1.0) low_other_jam(0.5)
					)
				else
					("missile_jam" decoyprob(%decoyprob) 
						super_rad_jam(1.5) high_rad_jam(1.0) med_rad_jam(0.75) low_rad_jam(0.5)
						super_ir_jam(2.0) high_ir_jam(1.5) med_ir_jam(1.0) low_ir_jam(0.5)
						super_other_jam(2.0) high_other_jam(1.5) med_other_jam(1.0) low_other_jam(0.5)
					)
				}
			}
		else effector "airborne"
			{with_effector
				{if not altitude 30
					("missile_jam" decoyprob(%decoyprob) 
						super_rad_jam(2.0) high_rad_jam(1.5) med_rad_jam(1.5) low_rad_jam(1.0)
						super_ir_jam(2.0) high_ir_jam(1.5) med_ir_jam(1.0) low_ir_jam(0.5)
						super_other_jam(2.0) high_other_jam(1.5) med_other_jam(1.0) low_other_jam(0.5)
					)
				else not altitude 65
					("missile_jam" decoyprob(%decoyprob) 
						super_rad_jam(1.75) high_rad_jam(1.25) med_rad_jam(1.0) low_rad_jam(0.75)
						super_ir_jam(2.0) high_ir_jam(1.5) med_ir_jam(1.0) low_ir_jam(0.5)
						super_other_jam(2.0) high_other_jam(1.5) med_other_jam(1.0) low_other_jam(0.5)
					)
				else
					("missile_jam" decoyprob(%decoyprob) 
						super_rad_jam(1.5) high_rad_jam(1.0) med_rad_jam(0.75) low_rad_jam(0.5)
						super_ir_jam(2.0) high_ir_jam(1.5) med_ir_jam(1.0) low_ir_jam(0.5)
						super_other_jam(2.0) high_other_jam(1.5) med_other_jam(1.0) low_other_jam(0.5)
					)	
				}
			}	
		else not effector "cannon"
			{if effector "vehicle"
				{with_effector
					("missile_jam" decoyprob(%decoyprob) 
						super_rad_jam(2.0) high_rad_jam(1.5) med_rad_jam(1.0) low_rad_jam(0.5)
						super_ir_jam(2.0) high_ir_jam(1.5) med_ir_jam(1.0) low_ir_jam(0.5)
						super_other_jam(2.0) high_other_jam(1.5) med_other_jam(1.0) low_other_jam(0.5)
					)
				}
			}	
		}
	}
)
{"proj_dummy active"
	{on spawn {tags add "rad_guidance"}}
}
{"proj_dummy active_asm"
	{on spawn {tags add "rad_guidance"}}
}
{"proj_dummy radpassive"
	{on spawn {tags add "rad_guidance"}}
}
{"proj_dummy ir"
	{on spawn {tags add "ir_guidance"}}
}
{"proj_dummy other"
	{on spawn {tags add "other_guidance"}}
}
{"proj_dummy laser"
	{on spawn {tags add "other_guidance"}}
}
(define "CWPS_proj"
"%missilename_carrier"
	{on spawn
	    {weapon_work "targeting_sys" 0}
		{weapon_work "targeting_sys_anti_jamming" 1}
		{if rand %rotation {ani_play "rotation" 0.5 loop}}
		{if rand %rand_move {delay 0.3 {ani_play "rand_move" 0.75 loop}}}
		{if rand %smoke_vulnerable {tags add "smoke_vulnerable"}}
;		{if rand ( * 1 %decoyprob) {weapon_work "targeting_sys_anti_jamming" 0} {weapon_work "targeting_sys" 1} 
;		{damage_report "root" "jamming_work"}
;		}
		{call "spawn2"}
		
	}
	("missile_missed" decoyprob(%decoyprob))
	{on "spawn_missile"
		{spawn "%missilename_impactor" "missile_point" x
			{impulse up 4 forward 50 com}
			{delay 0.01 {call "detonate"}}
		}
	}
	{on "spawn_missile_ground"
		{spawn "%missilename_impactor" "missile_point" x
			{bone hide "root"}
			;{impulse up 4 forward -30 com}
			{delay 0.01 {impulse up 0.1 com}{call "detonate"}}
		}
	}

	{on "change_stage"
			{if tagged "stage_%range" {if not tagged "cwps_extended_range" {call "detonate"}}}
	}
	{on "manage_effects"
		{delay 0.02 {with_linked_entity "missile" 
			{add_view	"%tail"			"proj_jet"			"tail"}
			{view start "proj_jet"}
			{view show "proj_jet"}
		}}
		{delay %eng_time {with_linked_entity "missile" 
			{view pause "proj_jet"}
			{view stop "proj_jet"}
			{view hide "proj_jet"}
		}}
	}
)
(define "CWPS_torpedo"
"%missilename_carrier"
	{on spawn
		{if rand %rotation {ani_play "rotation" 0.5 loop}}
		{if rand %rand_move {delay 0.3 {ani_play "rand_move" 0.75 loop}}}
		{if rand %smoke_vulnerable {tags add "smoke_vulnerable"}}
		{call "spawn2"}
	}
	{on "spawn_missile"
	  {with_linked_entity "missile"
		{spawn "%missilename_impactor" "root" x
			{tags add "instant_detonate"}
			{impulse up 4 forward 50 com}
			{delay 0.1 {call "detonate"}}
		}
	  }
	}
	{on "spawn_missile_ground"
		{spawn "%missilename_impactor" "missile_point" x
			{tags add "instant_detonate"}
			{bone hide "root"}
			;{impulse up 4 forward -30 com}
			{delay 0.1 {impulse up 0.1 com}{call "detonate"}}
		}
	}

	{on "change_stage"
			{if tagged "stage_%range" {if not tagged "cwps_extended_range" {call "detonate"}}}
	}
	{on "manage_effects"
		{delay 0.02 {with_linked_entity "missile" 
			{add_view	"%tail"			"proj_jet"			"tail"}
			{view start "proj_jet"}
			{view show "proj_jet"}
		}}
		{delay %eng_time {with_linked_entity "missile" 
			{view pause "proj_jet"}
			{view stop "proj_jet"}
			{view hide "proj_jet"}
		}}
	}
)
(define "CWPS_proj_2stage"
"%missilename_carrier"
	{on spawn
	    {weapon_work "targeting_sys" 0}
		{weapon_work "targeting_sys_anti_jamming" 1}
		{if rand %rotation {ani_play "rotation" 0.5 loop}}
		{if rand %rand_move {ani_play "rand_move" 0.75 loop}}
		{if rand %smoke_vulnerable {tags add "smoke_vulnerable"}}
		{call "spawn2"}
;            {if rand (* 0.8 %decoyprob)  {weapon_work "targeting_sys_anti_jamming" 0} {weapon_work "targeting_sys" 1}
;			{damage_report "root" "jamming_work"}
;			}
		
	}
	("missile_missed" decoyprob(%decoyprob))
	{on "spawn_missile"
		{spawn "%missilename_impactor" "missile_point" x
			{impulse up 4 forward 50 com}
			{delay 0.01 {call "detonate"}}
		}
	}
	{on "spawn_missile_ground"
		{spawn "%missilename_impactor" "missile_point" x
			{bone hide "root"}
			;{impulse up 4 forward -30 com}
			{delay 0.01 {impulse up 0.1 com}{call "detonate"}}
		}
	}
	{on "change_stage" overload
	     {if  tagged "cwps_extended_range"
		{if tagged "stage_%range40plus"  {call "spawn_second_stage"}
		else tagged  "stage_0%range40plus"  {call "spawn_second_stage"}
		}
	     }
		{inherited}
	}
	{on "link_effects"
	}
	{on "manage_effects" overload
		{if  not tagged "cwps_not_first_stage" 
			{delay 0.02 {with_linked_entity "missile" 
				{add_view	"%tail"			"proj_jet"			"tail"}
				{view start "proj_jet"}
				{view show "proj_jet"}
			}}
		}
		{delay %eng_time {with_linked_entity "missile" 
			{view pause "proj_jet"}
			{view stop "proj_jet"}
			{view hide "proj_jet"}
		}}
		{tags add "cwps_extended_range"}
		{call "launch_procedures"}
	}
	{on "spawn_second_stage"
		{spawn "%missilename_carrier" "missile_point" x 
			{tags add "cwps_not_first_stage"}
			{delay 0.1 {tags remove "cwps_extended_range"}}
			{delay 0.2 {tags remove "cwps_extended_range"}}
			{delay 0.3 {tags remove "cwps_extended_range"}}
			{delay 0.1 {with_linked_entity "missile" {ani_wind "on_start"  end}}}
			{with_linked_entity "missile" 
				{bone cut "part1"}{bone cut "part2"}{bone cut "part3"}{bone cut "part4"}
				{bone cut "part"}{bone cut "starter"}{bone cut "starter1"}{bone cut "starter2"}
			}
		} 
		{delete}
	}
)
(define "CWPS_proj_3stage"
"%missilename_carrier"
	{on spawn
	    {weapon_work "targeting_sys" 0}
		{weapon_work "targeting_sys_anti_jamming" 1}
		{if rand %rotation {ani_play "rotation" 0.5 loop}}
		{if rand %rand_move {ani_play "rand_move" 0.75 loop}}
		{if rand %smoke_vulnerable {tags add "smoke_vulnerable"}}
		{call "spawn2"}
;              {if rand (* 0.6 %decoyprob)  {weapon_work "targeting_sys_anti_jamming" 0} {weapon_work "targeting_sys" 1}
;			  {damage_report "root" "jamming_work"}
;			  }
		
	}
	("missile_missed" decoyprob(%decoyprob))
	{on "spawn_missile"
		{spawn "%missilename_impactor" "missile_point" x
			{impulse up 4 forward 50 com}
			{delay 0.01 {call "detonate"}}
		}
	}
	{on "spawn_missile_ground"
		{spawn "%missilename_impactor" "missile_point" x
			{bone hide "root"}
			;{impulse up 4 forward -30 com}
			{delay 0.01 {impulse up 0.1 com}{call "detonate"}}
		}
	}
	{on "change_stage" overload
	     {if not tagged "cwps_extended_range2"
	          {if tagged "cwps_extended_range"
					{if tagged "stage_%range80plus"  {call "spawn_second_stage"}
					else tagged "stage_0%range80plus"  {call "spawn_second_stage"}}
	           }
	     }
		{inherited}
	}
	{on "link_effects"
		{delay 0 {with_linked_entity "missile" 
			{add_view	"%tail"			"proj_jet"			"tail"}
		}}
	}
	{on "manage_effects" overload
		{if  not tagged "cwps_not_first_stage" 
			{delay 0.02 {with_linked_entity "missile" 
				{add_view	"%tail"			"proj_jet"			"tail"}
				{view start "proj_jet"}
				{view show "proj_jet"}
			}}
		}
		{delay %eng_time {with_linked_entity "missile" 
			{view pause "proj_jet"}
			{view stop "proj_jet"}
			{view hide "proj_jet"}
		}}
		{tags add "cwps_extended_range2"}
		{call "launch_procedures"}
	}
	{on "spawn_presecond_stage"
		{spawn "%missilename_carrier" "missile_point" x 
			{tags add "cwps_not_first_stage"}
			{delay 0.5 {tags remove "cwps_extended_range2"}{tags add "cwps_extended_range"}}
			{delay 0.1 {with_linked_entity "missile" {ani_wind "on_start"  end}}}
			{with_linked_entity "missile" 
				{bone cut "part1"}{bone cut "part2"}{bone cut "part3"}{bone cut "part4"}
				{bone cut "part"}{bone cut "starter"}{bone cut "starter1"}{bone cut "starter2"}
			}
		} 
		{delete}
	}
	{on "spawn_second_stage"
		{spawn "%missilename_carrier" "missile_point" x 
			{tags add "cwps_not_first_stage"}
			{delay 0.1 {tags remove "cwps_extended_range2"}{tags remove "cwps_extended_range"}}
			{delay 0.2 {tags remove "cwps_extended_range2"}{tags remove "cwps_extended_range"}}
			{delay 0.5 {tags remove "cwps_extended_range2"}{tags remove "cwps_extended_range"}}
			{delay 0.1 {with_linked_entity "missile" {ani_wind "on_start"  end}}}
			{with_linked_entity "missile" 
				{bone cut "part1"}{bone cut "part2"}{bone cut "part3"}{bone cut "part4"}
				{bone cut "part"}{bone cut "starter"}{bone cut "starter1"}{bone cut "starter2"}
			}
		} 
		{delete}
	}	
)

;{"switchblade300_carrier"
;    {on spawn
;	    {delay 6.5
;       		{with_linked_entity "missile"
;		    	{spawn "proj_deleter" "root"
;		    	    {delay 0.2 {delete}}
;		    	}
;		    }
;		}	
;	}
;    {on "check_altitude"
;		{with_linked_entity "missile"
;			{if not altitude 1.0
;				{if not tagged "underwater_launch"
;					;{spawn "proj_point_dummy" "root"}
;					{spawn "proj_deleter" "root"
;					 {delete}
;					;{delay 0.2 {delete}}
;					}	;вызывает вылет изредка
;				}
;			}	
;		}
;	}
;	{on fire "targeting_sys_anti_jamming"
;	    {with_linked_entity "missile"
;		    {spawn "proj_deleter" "root"
;			 {delete}
;			;{delay 0.2 {delete}}
;			}
;	    }
;	}
;	{on "spawn_missile" overload
;		{spawn "switchblade300_impactor" "missile_point" x
;			{call "detonate"}
;		}
;	}
;}


;{"igla_s_carrier"
;	{on spawn
;	{weapon_work "targeting_sys" 0}
;	{weapon_work "targeting_sys_anti_jamming" 1}
;	{ani_play "rotation" 0.5 loop}
;	{if rand ( * 1 0.2) {weapon_work "targeting_sys_anti_jamming" 0} {weapon_work "targeting_sys" 1}
;	{damage_report "root" "jamming_work"}
;	}
;	}
;	{on "spawn_missile"
;	  {if tagged "100m_fly"
;		{spawn "igla_s_impactor" "missile_point" x
;			{impulse up 0.1 forward 50 com}	{delay 0.1 {call "detonate"}}
;		}
;	     else tagged "50m_fly"
;		{spawn "igla_s1_impactor" "missile_point" x
;			{impulse up 0.1 forward 50 com}	{delay 0.1 {call "detonate"}}
;		}
;	     else 
;		{spawn "igla_s2_impactor" "missile_point" x
;			{impulse up 0.1 forward 50 com}	{delay 0.1 {call "detonate"}}
;		}
;	  }
;	}
;	{on "spawn_missile_ground"
;		{spawn "igla_s_impactor" "missile_point" x
;			{bone hide "root"}
;			;{impulse up 4 forward -30 com}
;			{delay 0.01 {impulse up 0.1 com}{call "detonate"}}
;		}
;	}
;	{on "change_stage" {if tagged "stage_17" {call "detonate"}}}
;	{on "manage_effects"
;		{delay 0 {with_linked_entity "missile" 
;			{add_view	"proj_jet_sam"			"proj_jet"			"tail"}
;			{view show "proj_jet"}
;			{view start "proj_jet"}
;		}}
;		{delay 1.5 {with_linked_entity "missile" 
;			{view pause "proj_jet"}
;			{view stop "proj_jet"}
;			{view hide "proj_jet"}
;		}}
;	}
;	("speed_normal" coeff(1.07))
;}

;{"tow2b_carrier"
;	{on spawn	
;	{weapon_work "targeting_sys" 0}
;	{weapon_work "targeting_sys_anti_jamming" 1}
;	{tags add "smoke_vulnerable"}
;	{if rand ( * 1 0.25) {weapon_work "targeting_sys_anti_jamming" 0} {weapon_work "targeting_sys" 1}
;	{damage_report "root" "jamming_work"}
;	}
;	}
;	{on "spawn_missile"
;		{spawn "tow2b_impactor" "missile_point" x
;			{impulse up 0.1 forward 25 com}
;			{delay 0.01 {spawn "tow2b_core" {impulse up -10 forward 0.1 com}}}
;			{delay 0.05 {spawn "tow2b_core" {impulse up -10 forward -1.1 com}}} 
;			{delay 0.5 {call "detonate"}}
;		}
;	}
;	{on "spawn_missile_ground"
;		{spawn "tow2b_impactor" "missile_point" x
;			{bone hide "root"}
;			;{impulse up 4 forward -30 com}
;			{delay 0.01 {impulse up 0.1 com}{call "detonate"}}
;		}
;	}
;	{on "change_stage"	{if tagged "stage_35" {call "detonate"}}}
;	{on "manage_effects"
;		{delay 0 {with_linked_entity "missile" 
;			{add_view	"proj_jet_atgm"			"proj_jet"			"tail"}
;			{view show "proj_jet"}
;			{view start "proj_jet"}
;		}}
;		{delay 0.5 {with_linked_entity "missile" 
;			{view pause "proj_jet"}
;			{view stop "proj_jet"}
;			{view hide "proj_jet"}
;		}}
;	}
;	("speed_normal" coeff(0.84))
;	("tracer" tracer(tracer_tow) bone(tail))
;}

;{"sraw_rock_carrier"
;	{on "spawn_missile"
;		{spawn "sraw_rock_impactor" "missile_point" x
;			{impulse up 0.1 forward 15 com}
;			{call "detonate"}
;		}
;	}
;	{on "spawn_missile_ground"
;		{spawn "sraw_rock_impactor" "missile_point" x
;			{bone hide "root"}
;			;{impulse up 4 forward -30 com}
;			{delay 0.01 {impulse up 0.1 com}{call "detonate"}}
;		}
;	}
;	{on "change_stage"
;			{if tagged "stage_19" {if not tagged "cwps_extended_range" {call "detonate"}}}
;	}
;	{on "manage_effects"
;		{delay 0 {with_linked_entity "missile" 
;			{add_view	"proj_jet_atgm"			"proj_jet"			"tail"}
;			{view show "proj_jet"}
;			{view start "proj_jet"}
;		}}
;		{delay 0.5 {with_linked_entity "missile" 
;			{view pause "proj_jet"}
;			{view stop "proj_jet"}
;			{view hide "proj_jet"}
;		}}
;	}
;	("speed_slow" coeff(1.50))
;}
;{"sraw_rock_impactor" {on "detonate" overload {spawn "sraw_core" "body" {impulse up -10 forward 1.1 com}} {delay 0.01 {stuff_detonate}}}}

;{"nlaw_rocket_carrier"
;	{on "spawn_missile"
;		{spawn "nlaw_rocket_impactor" "missile_point" x
;			{impulse up 0.1 forward 15 com}
;			{call "detonate"}
;		}
;	}
;	{on "spawn_missile_ground"
;		{spawn "nlaw_rocket_impactor" "missile_point" x
;			{bone hide "root"}
;			;{impulse up 4 forward -30 com}
;			{delay 0.01 {impulse up 0.1 com}{call "detonate"}}
;		}
;	}
;	{on "change_stage"
;			{if tagged "stage_19" {if not tagged "cwps_extended_range" {call "detonate"}}}
;	}
;	{on "manage_effects"
;		{delay 0 {with_linked_entity "missile" 
;			{add_view	"proj_jet_atgm"			"proj_jet"			"tail"}
;			{view show "proj_jet"}
;			{view start "proj_jet"}
;		}}
;		{delay 0.5 {with_linked_entity "missile" 
;			{view pause "proj_jet"}
;			{view stop "proj_jet"}
;			{view hide "proj_jet"}
;		}}
;	}
;	("speed_slow" coeff(1.50))
;}
;{"nlaw_rocket_impactor" {on "detonate" overload {spawn "nlaw_core" "body" {impulse up -10 forward 1.1 com}} {delay 0.01 {stuff_detonate}}}}

{"r17_script"
	{on spawn overload
		{volumes disable contact}
		{physics_work 0}
		{add_view	"proj_smoke"		"proj_tail"		"tail"}
	}
	{on "fall"
		{ani_play "fall" callback}
		{view start "proj_tail"}
	}
	{on animation_end "fall"
		{delete}
	}
	{on "spawn_missile" overload
	}
	{on "detonate" overload}
}
{"iskander_script"
	{on spawn overload
		{volumes disable contact}
		{physics_work 0}
	}
	{on "fall"
		{ani_play "fall" callback}
		{view start "proj_tail"}
	}
	{on "detonate" overload
		{stuff_detonate}
	}
	{on animation_end "fall"
		{call "detonate"}
	}
	{on "spawn_missile" overload
	}
}

{"missile_script"
	{on spawn overload
;		{volumes disable contact}
		{physics_work 0}
		{add_view	"proj_smoke"		"proj_tail"		"tail"}
		{if tagged "fall" {call "fall"}}
	}
	("speed_normal" coeff(0.33))
	{on "fall"
		{tags add "fall"}
		{ani_play "fall" callback}
		{view start "proj_tail"}
		{delay 10 {call "chdir_repeater"}}
	}
	{on "detonate" overload
		{stuff_detonate}
	}
	{on animation_end "fall"
		{call "detonate"}
	}
	{on "spawn_missile" overload
	}
}
{"antirad_missile"	;simplified lock-on for enemy missiles
	{on spawn 
		{delay 1.0 
			{volumes "targ_for_missile" enable bullet}
			{volumes "target_front" enable bullet}
		}
	}
	{on bullet_hit
		{if stuff "proj_pointer"
			{if not stuff "rad_aa_passive"
				{volumes "targ_for_missile" disable bullet}
				{components "targ_for_missile" break}
				{with_effector {tags remove "already_fired"} {with_effector}}
				{delay 4.0 
					{volumes "targ_for_missile" enable bullet}
					{components "targ_for_missile" repair}
				}
			}
		}
		{if stuff "rad_aa_passive"
			{spawn "proj_point_rus_radpassive" (mod "mp"{player 1}) (mod not "mp"{player 7})}
			{spawn "proj_point_usa_radpassive" (mod "mp"{player 1}) (mod not "mp"{player 7})}
		}
	}
}
;========================================================================================
;Impulse missiles by Dimka and Timosh
;Primary for MOW2.
(include "missile_impulse.inc")

;========================================================================================
;Missile local settings
(include "/lists/missile_settings2.inc")
