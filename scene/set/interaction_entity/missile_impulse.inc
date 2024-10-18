{"proj_impulse"
	{on spawn overload
		{if props "horizon_align"
			{pillar_up}		;эти 2 команды - дл€ начального выравнивани€ ракеты по горизонту.
			{physics_work 1}
		}
		{tags add "guided"}
		{call "on_spawn_custom"}
		{call "check_no_signal"}
		{volumes disable contact}
		{tags add "moving"}
		{ani_play "on_start"}
		{delay 0.01 
			{with_linked_entity "missile"
				{physics_work 0}
				{volumes disable all}
				{ani_play "on_start"}
			}
			{update_visibility_patch}
		}
		{delay 0.3 {weapon_work "targeting_sys_anti_jamming" 1} {weapon_work "targeting_sys" 0}

		}
		{delay 0 {call "link_effects"}}
		{call "check_no_signal"}
	    {delay 0.15 
			{volumes "body" enable contact bullet blast}
		    {volumes "proximity" enable contact}
	    }
		;»меютс€ проблемы с полетом ракет с отключенным contact body сквозь другие волумы, пусть даже с отключенным всем.
		{if altitude 5
			{delay 1
				{set "launch_delay" 1}
				{volumes "body" enable contact bullet blast}
				{volumes "proximity" enable contact}
			}
		else
			{delay 0.2
				{set "launch_delay" 1}
				{volumes "body" enable contact bullet blast}
				{volumes "proximity" enable contact}
			}		
		}

	}
	{on grounded on {call "stuff_detonate"} }
	{on blast overload }
	{on blast_hit overload 
		{if min_energy 10 {call "stuff_detonate"}
		;else min_energy 7 {call "random_malfunction"}
		;else min_energy 3 {if rand 0.5 {call "random_malfunction"}}
		else min_energy 1 {call "random_malfunction"}
		}
	}
	{on pierce {if not stuff "proj_pointer" {if rand 0.05 {call "stuff_detonate"}}}}	;попадание во взрыватель
	{on break {if component "body" {call "stuff_detonate"}}}

	{on "random_malfunction"
		{if rand 0.3 
			{with_linked_entity "missile" 
				{tear "piece_small_steel" bone "wingl" {impulse forward 5} {delay 10 {hide 3}}}
				{tear "piece_small_steel" bone "wingr" {impulse forward 5} {delay 10 {hide 3}}}
				{tear "piece_small_steel" bone "wing_l" {impulse forward 5} {delay 10 {hide 3}}}
				{tear "piece_small_steel" bone "wing_r" {impulse forward 5} {delay 10 {hide 3}}}
			}
			{call "fall"}
			{delay 0.01 {impulse forward 3}{gravity 20}}
		else rand 0.5
			{call "stuff_detonate"}
		}
	}
	
	{on "detonate" overload
		{call "stuff_detonate"}
	}
	{on "stuff_detonate" overload
		{if not tagged "stuff_detonate"
			{tags add "stuff_detonate"}
			{volumes disable bullet blast}
			{with_linked_entity "missile" {call "delete"}}
			{manual_shot}
			{delay 0 {stuff_detonate}}
		}	
	}
	{on "check_altitude"
			{if not altitude 0.1
			else not altitude 10
				{view pause "proj_tail10"}
				{view pause "proj_tail20"}
				{view pause "proj_tail30"}
				{view pause "proj_tail"}
			else not altitude 20
				{view start "proj_tail10"}
				{view pause "proj_tail20"}
				{view pause "proj_tail30"}
				{view pause "proj_tail"}
			else not altitude 30
				{view pause "proj_tail10"}
				{view start "proj_tail20"}
				{view pause "proj_tail30"}
				{view pause "proj_tail"}
			else not altitude 40
				{view pause "proj_tail10"}
				{view pause "proj_tail20"}
				{view start "proj_tail30"}
				{view pause "proj_tail"}
			else
				{view pause "proj_tail10"}
				{view pause "proj_tail20"}
				{view pause "proj_tail30"}
				{view start "proj_tail"}
			}
			{delay 0.5 {call "check_altitude"} }
	}
;фишка с подрывом импактора сразу после выстрела не работает - стру€ гаситс€ объектом proj_detonator, хот€ у него толщина 0,1
;	{on fire "cm_weapon_jet"
;		{spawn "proj_detonator" "gun"
;		{delay 0.1 {delete}}
;		}
;	}

}
;{"proj_detonator"
;	{on bullet_hit
;		{bullet_detonate}
;		{delete}
;	}
;}
(define "proj_impulse_movement"
	{on "move" overload
	    {if tagged "moving"
	        {spawn "proj_cont" "cont_vol" x {impulse up 0 dir 0.0 forward %cont_impulse com}}
		    {delay 0.133 {call "move"}}
	    }
	}
	{on contact overload
		{if effector "proj_cont"
			{if volume "cont_vol"
			{impulse up 0 dir %main_impulse forward 0 com} {constrain_velocity %const_vel}
			}
			else		
			{inherited}
		}
	}
)
(define "proj_impulse_missile_movement"
	{on "move" overload
	    {if tagged "forced_launch"
			{impulse forward %cont_impulse com}
			{delay 0.133 {call "move"}}
		else tagged "moving"
	        {spawn "proj_cont" "cont_vol" x {impulse up 0 dir 0.0 forward %cont_impulse com}} {constrain_velocity %const_vel}
		    {delay 0.133 {call "move"}}
			;{if distance_to_last_target_less_than 1 {tags remove "move"} {volumes "cont_vol" disable all}}
	    }
	}
	{on contact overload
		(define "altitude_compensator"	;up  предотвращает снижение ракеты в полете
			{if altitude 1
				{impulse up (*0.00 %main_impulse) dir %impulse forward 0 com}
			else
				{impulse up (*0.05 %main_impulse) dir %impulse forward 0 com}
			}
		)
	
		{if effector "proj_cont" and volume "cont_vol"
			  {if tagged "guided"
				{if tagged "starting"
					("altitude_compensator" main_impulse(%main_impulse) impulse(%starting_impulse))
				else tagged "moving_slow"	
					("altitude_compensator" main_impulse(%main_impulse) impulse(%slow_impulse))
				else tagged "moving"
					("altitude_compensator" main_impulse(%main_impulse) impulse(%main_impulse))
				}
			  else
			    {impulse up (*0.02 %main_impulse) dir %main_impulse cy 0 0.2 cz 0 0.2 forward 0 com}
			  }
		else volume "cont_vol"
		     {volumes "cont_vol" disable contact} {delay 0.1 {volumes "cont_vol" enable contact}}
		else not flag "launch_delay"
			{volumes "body" disable contact overlap}
		    {volumes "proximity" disable  contact overlap}
		else 
			{inherited}
		}
	}
	
	
)
(define "all_ik_off"
		{ik_enable "rot_hor1" 0} {ik_enable "rot_ver1" 0}
		{ik_enable "rot_hor2" 0} {ik_enable "rot_ver2" 0}
		{ik_enable "rot_hor3" 0} {ik_enable "rot_ver3" 0}
		{ik_enable "rot_hor4" 0} {ik_enable "rot_ver4" 0}
		{ik_enable "rot_hor5" 0} {ik_enable "rot_ver5" 0}
		{ik_enable "rot_hor6" 0} {ik_enable "rot_ver6" 0}
		{ik_enable "rot_hor7" 0} {ik_enable "rot_ver7" 0}
		{ik_enable "rot_hor8" 0} {ik_enable "rot_ver8" 0}
)
{"proj_impulse_bomb"	;simplified lock-on for enemy missiles
	{on "on_spawn_custom"
		("all_ik_off")
		{weapon_work "targeting_sys_anti_jamming" 0}
		{delay 1.0 
		    {if altitude 10
		        else 
		        {gravity 50}
		    }
		}
		{tags add "cwps_missile_minimap"}
		{delay 1.5
			{volumes "body" enable contact}
			{volumes "cont_vol" enable contact}
			{call "move"}
			{ik_enable "rot_hor1" 1}
			{ik_enable "rot_ver1" 1}
			{delay 0.5 {impulse up 1.5 1 com}}
		}
	}
	{on "fall"
			{set "rotate_turret" 1}
			{volumes "check_for_sam" disable bullet}
			{components "check_for_sam" break}
		    {tags remove "moving"}
			("all_ik_off")
			{gravity 50}
	}
	{on fire "targeting_sys_anti_jamming"
;если бомба уже пикирует, то поздно пускать новые ракеты, только сопровождаем запущенные
	  {if not flag "rotate_turret"
		{set "rotate_turret" 1}
		{volumes "check_for_sam" disable bullet}
		{components "check_for_sam" break}
	  }
	}
	{on bullet_hit
		{if stuff "proj_pointer"
			{volumes "check_for_sam" disable bullet}
			{components "check_for_sam" break}
			{with_effector {tags remove "already_fired"} {with_effector}}
			;{delay 4.0 
			;	{volumes "check_for_sam" enable bullet}
			;	{components "check_for_sam" repair}
			;}
		}		
	}
}
{"proj_impulse_atgm"	;no lock-on support for enemy missiles
	{on "engine_start_effects"
		{with_linked_entity "missile"
		    {add_view	"proj_smoke"		"proj_tail"		"root"}
			{add_view	"proj_smoke30"		"proj_tail30"		"root"}
			{add_view	"proj_smoke20"		"proj_tail20"		"root"}
			{add_view	"proj_smoke10"		"proj_tail10"		"root"}
		    {link_sound "fly"	"vehicle/engine/missile/missileengine"}
			{play_sound "fly" 1}
			{tags add "cwps_missile_minimap"}
			{call "check_altitude"}
				{add_view	"proj_jet_small"			"proj_jet_main"			"tail1"}
				{add_view	"proj_jet_sam"			"proj_jet"			"tail"}
				{view start "proj_tail"}
				{view start "proj_jet"}
		}
	}
	{on "engine_stop_booster_effects"
		{with_linked_entity "missile"
			{view stop "proj_jet"}
			{view hide "proj_jet"}
			{view start "proj_jet_main"}
			{volumes "part" enable contact contact_ground bullet blast}
			{volumes "part1" enable contact contact_ground bullet blast}
			{volumes "part2" enable contact contact_ground bullet blast}
			{volumes "part3" enable contact contact_ground bullet blast}
			{volumes "part4" enable contact contact_ground bullet blast}
			{tear "piece_missile_booster" bone "starter" {impulse forward 5}}
			{tear "piece_missile_booster" bone "part" {impulse forward 5}}
			{tear "piece_missile_booster" bone "part1" {impulse forward 5}}
			{tear "piece_small_steel" bone "part2" {impulse forward 5}}
			{tear "piece_small_steel" bone "part3" {impulse forward 5}}
			{tear "piece_small_steel" bone "part4" {impulse forward 5}}
		}
	}
	{on "engine_stop_effects"
		{with_linked_entity "missile"
			{view pause "proj_jet_main"}
			{view stop "proj_jet_main"}
			{view hide "proj_jet_main"}
		}
	}
	{on fire "gun"
		{impulse up 0 dir 0.1 forward 0 com}
		{call "move"}
	}
}
{"proj_impulse_cruise_missile"	;full lock-on support for enemy missiles
	{on "engine_start_effects"
		    {add_view	"proj_smoke"		"proj_tail"		"root"}
			{add_view	"proj_smoke30"		"proj_tail30"		"root"}
			{add_view	"proj_smoke20"		"proj_tail20"		"root"}
			{add_view	"proj_smoke10"		"proj_tail10"		"root"}
		    {link_sound "fly"	"vehicle/engine/missile/missileengine"}
			{play_sound "fly" 1}
			{tags add "cwps_missile_minimap"}
			{call "check_altitude"}
			{with_linked_entity "missile"
				{add_view	"proj_jet_small"			"proj_jet_main"			"tail1"}
				{add_view	"proj_jet_sam"			"proj_jet"			"tail"}
				{view start "proj_tail"}
				{view start "proj_jet"}
			}
	}
	{on "engine_stop_booster_effects"
		{with_linked_entity "missile"
			{view stop "proj_jet"}
			{view hide "proj_jet"}
			{view start "proj_jet_main"}
			{volumes "part" enable contact contact_ground bullet blast}
			{volumes "part1" enable contact contact_ground bullet blast}
			{volumes "part2" enable contact contact_ground bullet blast}
			{volumes "part3" enable contact contact_ground bullet blast}
			{volumes "part4" enable contact contact_ground bullet blast}
			{tear "piece_missile_booster" bone "starter" {impulse forward 5}}
			{tear "piece_missile_booster" bone "part" {impulse forward 5}}
			{tear "piece_missile_booster" bone "part1" {impulse forward 5}}
			{tear "piece_small_steel" bone "part2" {impulse forward 5}}
			{tear "piece_small_steel" bone "part3" {impulse forward 5}}
			{tear "piece_small_steel" bone "part4" {impulse forward 5}}
		}
	}
	{on "engine_stop_effects"
		{with_linked_entity "missile"
			{view pause "proj_jet_main"}
			{view stop "proj_jet_main"}
			{view hide "proj_jet_main"}
		}
	}
	{on fire "gun"
		{impulse up 0 dir 0.1 forward 0 com}
		{call "move"}
	}
	(include "flares_and_chaff.inc")
	{on bullet_hit
		{if stuff "proj_pointer" {call "check_proj_type"}}
	}
}

(define "impulse_missile_seq"
	("all_ik_off")
	{impulse %launch_imp com}
	{gravity %eject_gravity}
	{delay %start_delay
		{call "engine_start_effects"}
		{impulse dir 0.0 %start_imp com}
		{call "move"}
		{volumes "cont_vol" enable contact}
		{tags add "starting"}
	}
	{delay %booster_delay 
		{call "engine_stop_booster_effects"}
		{tags remove "starting"}
		{ik_enable "rot_hor1" 1}
	    {ik_enable "rot_ver1" 1}
		{delay (* (- %slowing_delay %booster_delay) 0.125) {ik_enable "rot_hor2" 1} {ik_enable "rot_ver2" 1} {ik_enable "rot_hor1" 0} {ik_enable "rot_ver1" 0}{components "missile_fuel1" break}}
		{delay (* (- %slowing_delay %booster_delay) 0.250) {ik_enable "rot_hor3" 1} {ik_enable "rot_ver3" 1} {ik_enable "rot_hor2" 0} {ik_enable "rot_ver2" 0}{components "missile_fuel2" break}}
		{delay (* (- %slowing_delay %booster_delay) 0.375) {ik_enable "rot_hor4" 1} {ik_enable "rot_ver4" 1} {ik_enable "rot_hor3" 0} {ik_enable "rot_ver3" 0}{components "missile_fuel3" break}}
		{delay (* (- %slowing_delay %booster_delay) 0.500) {ik_enable "rot_hor5" 1} {ik_enable "rot_ver5" 1} {ik_enable "rot_hor4" 0} {ik_enable "rot_ver4" 0}{components "missile_fuel4" break}}
		{delay (* (- %slowing_delay %booster_delay) 0.625) {ik_enable "rot_hor6" 1} {ik_enable "rot_ver6" 1} {ik_enable "rot_hor5" 0} {ik_enable "rot_ver5" 0}{components "missile_fuel5" break}}
		{delay (* (- %slowing_delay %booster_delay) 0.750) {ik_enable "rot_hor7" 1} {ik_enable "rot_ver7" 1} {ik_enable "rot_hor6" 0} {ik_enable "rot_ver6" 0}{components "missile_fuel6" break}}
		{delay (* (- %slowing_delay %booster_delay) 0.875) {ik_enable "rot_hor8" 1} {ik_enable "rot_ver8" 1} {ik_enable "rot_hor7" 0} {ik_enable "rot_ver7" 0}{components "missile_fuel7" break}}
	}			 
	{delay %engine_stop_delay  {call "engine_stop_effects"} }
	{delay %slowing_delay 
		{tags add "moving_slow"}
		{impulse up 0 dir 0.0 forward 1 com}
		{gravity 150.0}
		("all_ik_off")
		{call "move"}
	}
	{delay %fall_delay 
		{gravity 700.0}
		{impulse up 0.15}
		{call "stuff_detonate"}
	}
)


;=====================================================================================================

;("CWPS_proj"  rotation(1) rand_move(0) smoke_vulnerable(1))



	;const_vel(15) starting_impulse(750) - 20 /slow atgm 0.9
	;const_vel(30) impulse(800) - 29.4 /normal atgm 0.84
	;const_vel(60) impulse(825) - 38.5 /normal atgm 1.09
	;const_vel(90) impulse(850) - 45.5 /fast atgm 0.97
	;const_vel(110) impulse(875) - 53.7 /fast agm 1.14
	;const_vel(150) impulse(900) - 62.5 /fast sam 1
	
(define "CWPS_impulse_proj_generic"
 "%missilename_carrier"
   {on "on_spawn_custom"
		{if rand %rotation {ani_play "rotation" 0.5 loop}}
		{if rand %rand_move {delay 0.3 {ani_play "rand_move" 0.75 loop}}}
		{if rand %smoke_vulnerable {tags add "smoke_vulnerable"}}
		{if rand ( * 1 %decoyprob) {weapon_work "targeting_sys_anti_jamming" 0} {weapon_work "targeting_sys" 1} 
		{damage_report "root" "jamming_work"}
		}
			("impulse_missile_seq"
				eject_gravity(%eject_gravity)
				launch_imp(%launch_imp)	;impulse during missile ejection
				start_delay(%start_delay) start_imp(%start_imp)	;booster ignition
				booster_delay(%booster_delay)				;booster off, cruise engine on
				engine_stop_delay(%eng_time)			;engine off
				slowing_delay(%flight_time)				;low energy, slowing down
				fall_delay((+ %flight_time 0.1))					;stall and fall
			)
	}
	("proj_impulse_missile_movement" cont_impulse(10) const_vel(%vel) starting_impulse(%imp) slow_impulse(%imp) main_impulse(%imp))
	{on "manage_effects"
		{delay %start_delay {with_linked_entity "missile" 
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
(define "cm_jet"
	{on "stuff_detonate"
		{spawn "cw_cumulative_jetthrower%dmg" dir_velocity}
	}
)
(define "CWPS_impulse_proj"	;tag force_airdrop turns on airdrop mode for 1.5sec. Use only here.
	("CWPS_impulse_proj_generic" missilename(%missilename) 
	rotation(%rotation) rand_move(%rand_move) 
	smoke_vulnerable(%smoke_vulnerable) decoyprob(%decoyprob) 
	vel(%vel) imp(%imp) flight_time((* %flight_time 1.07)) 
	tail(%tail) eng_time(%eng_time)
	launch_imp(forward 30) eject_gravity(0.01)
	start_delay(0.2) start_imp(up 0 forward 10)	;booster ignition
	booster_delay(0.3)				;booster off, cruise engine on
	)
)
(define "CWPS_impulse_proj_eject"	;for missiles that should be ejected forward
	("CWPS_impulse_proj_generic" missilename(%missilename) 
	rotation(%rotation) rand_move(%rand_move) 
	smoke_vulnerable(%smoke_vulnerable) decoyprob(%decoyprob) 
	vel(%vel) imp(%imp) flight_time( (+ (* %flight_time 1.07) 0.6)) 
	tail(%tail) eng_time((+ 0.6 %eng_time))
	launch_imp(forward 40) eject_gravity(0.01)
	start_delay(0.5) start_imp(up 1 forward 10)	;booster ignition
	booster_delay(0.6)				;booster off, cruise engine on
	)
)	
(define "CWPS_impulse_proj_eject_slow"	;for missiles that should be ejected forward slowly
	("CWPS_impulse_proj_generic" missilename(%missilename) 
	rotation(%rotation) rand_move(%rand_move) 
	smoke_vulnerable(%smoke_vulnerable) decoyprob(%decoyprob) 
	vel(%vel) imp(%imp) flight_time( (+ (* %flight_time 1.07) 0.6)) 
	tail(%tail) eng_time((+ 0.6 %eng_time))
	launch_imp(forward 20) eject_gravity(0.01)
	start_delay(0.5) start_imp(up 1 forward 7)	;booster ignition
	booster_delay(0.6)				;booster off, cruise engine on
	)
)	
(define "CWPS_impulse_proj_airdropped"	;for air-launched missiles that should be always dropped down from aircraft
	("CWPS_impulse_proj_generic" missilename(%missilename) 
	rotation(%rotation) rand_move(%rand_move) 
	smoke_vulnerable(%smoke_vulnerable) decoyprob(%decoyprob) 
	vel(%vel) imp(%imp) flight_time( (+ (* %flight_time 1.07) 1)) 
	tail(%tail) eng_time((+ 1 %eng_time))
	launch_imp(up -5 forward 30) eject_gravity(2)
	start_delay(1) start_imp(up 0 forward 10)	;booster ignition
	booster_delay(1.1)				;booster off, cruise engine on
	)
)	
;===================================особенности носителей
;это кумул€тивный дамаг.
{"cw_cumulative_jetthrower" {on spawn {manual_shot} {delay 0.01 {delete}}}}

{"smoke_cloud"	;дымовые облака
	{on contact
		{if effector "proj_impulse"
			{volumes disable contact} {delay 0.3 {volumes enable contact}}
			;почему-то импульсные ракеты не могут летать внутри дыма, приходитс€ дым отключать на 0,3с.
			{with_effector 
			  {if tagged "guided"
				{tags remove "guided"}
				{weapon_work "targeting_sys" 0} {weapon_work "targeting_sys_anti_jamming" 0}
			  }
			{with_effector}}
		}
	}
}

{"maneuvrability_inertial"
	{on spawn 
		{delay 1.5
			{weapon_work "targeting_sys" 0} {weapon_work "targeting_sys_anti_jamming" 0}
		}
	}
}

{"cwps_rangefinder"
	{on spawn
		{volumes "rangefinder" enable overlap}
	}
	{on "top_attack"
		{volumes "rangefinder" disable overlap}
	}
}
{"cwps_top_attack"
	{on spawn
		{ani_play "top_attack_on" 1}
		{delay 2.5 {ani_play "top_attack_off" 1}}
	}
	{on "top_attack"
		{ani_play "top_attack_off" 1}
	}
}
{"cwps_gorka"
	{on spawn
		{ani_play "gorka" 0.4}
	}
}
{"cwps_antiroof"
	{on spawn
		{delay 0.1 {ani_play "antiroof" 0.3}}
	}
}
{"surfaceproximity"
	{on contact overload
		{if volume "proximity"
			{if not effector_velocity 1
				{volumes "proximity" disable contact}
				{delay 0.1 {volumes "proximity" enable contact}}
			else {inherited}
			}
		else {inherited}
		}
	}
}
{"radioproximity"
	{on contact overload
		{if volume "proximity"
			{if not effector "steel"
				{volumes "proximity" disable contact}
				 {volumes "proximity" enable contact}
			else {inherited}
			}
		else {inherited}
		}
	}
}
{"ir_seeker"
     {on bullet_hit overload
		{if stuff "ir_soep_ammo" {if tagged "guided" {tags remove "guided"}  {weapon_work "targeting_sys" 0} {weapon_work "targeting_sys_anti_jamming" 0} }
		else {inherited}
		}
     }
}
{"krasnopol_test"
	{on spawn overload
		{tags add "moving"}
		{impulse up 0 dir 0.1 forward 1000 rnd_dir 20 com} {constrain_velocity 100}
		{call "move"}
		{delay 1
		    {if not altitude 35
		        {gravity 50}
		        {impulse fz -1.5}
		    }
			{impulse fz 0 0.1}
			{impulse fy 0 0.1}
		}
		{delay 6 
		    {tags remove "moving"}
			("all_ik_off")
		}
	}
	{on "move" overload
	    {if tagged "moving"
	        {spawn "proj_cont" "cont_vol" x {impulse up 0 dir 0.0 forward 100 com}} {constrain_velocity 100}
			{impulse fz -0.11}
		    {delay 0.133 {call "move"}}
	    }
	}
	{on contact overload
	{if effector "proj_cont"
		{if volume "cont_vol"
		{impulse up 0 dir 50.0 forward 0 com}	
		}
        else		
		{call "stuff_detonate"}
	}
	}
    {on fire "gun"
		{impulse up 0 dir 0.1 forward 0 com} {call "move"}
	}
}
{"vulcano_sal"
	{on spawn overload
		{tags add "moving"}
		{impulse up 0 dir 0.1 forward 1000 rnd_dir 20 com} {constrain_velocity 100}
		{call "move"}
		{delay 1
		    {if not altitude 35
		        {gravity 50}
		        {impulse fz -1.5}
		    }
			{impulse fz 0 0.1}
			{impulse fy 0 0.1}
		}
		{delay 6 
		    {tags remove "moving"}
			("all_ik_off")
		}
	}
	{on "move" overload
	    {if tagged "moving"
	        {spawn "proj_cont" "cont_vol" x {impulse up 0 dir 0.0 forward 100 com}} {constrain_velocity 100}
			{impulse fz -0.05}
		    {delay 0.133 {call "move"}}
	    }
	}
	{on contact overload
	{if effector "proj_cont"
		{if volume "cont_vol"
		{impulse up 0 dir 50.0 forward 0 com}	
		}
        else		
		{call "stuff_detonate"}
	}
	}
    {on fire "gun"
		{impulse up 0 dir 0.1 forward 0 com} {call "move"}
	}
}
{"gbu39_guided"
    {on "on_spawn_custom"
		{impulse up -1 forward 35 2 com} {constrain_velocity 50}
		{delay 0.1
			{with_linked_entity "missile"  
				{ani_play "flip_bomb" 0.25 callback}
			}
		}
		{delay 1.5
			{with_linked_entity "missile"  
			 {ani_play "open_wing" 1.0}
			}
		}
		{delay 25  {call "fall"}}
	}
	("proj_impulse_movement" cont_impulse(10) main_impulse(20) const_vel(20))
}
{"gbu53b_guided"
    {on "on_spawn_custom"
		{impulse up -1 forward 35 2 com} {constrain_velocity 50}
		{delay 0.1
			{with_linked_entity "missile"  
				{ani_play "flip_bomb" 0.25 callback}
			}
		}
		{delay 1.5
			{with_linked_entity "missile"  
			 {ani_play "open_wing" 1.0}
			}
		}
		{delay 25  {call "fall"}}
	}
	("proj_impulse_movement" cont_impulse(10) main_impulse(20) const_vel(20))
}
{"jdam_er_guided"
    {on "on_spawn_custom"
		{impulse up -1 forward 35 2 com} {constrain_velocity 50}
		{delay 0.1
			{with_linked_entity "missile"  
				{ani_play "flip_bomb" 0.25 callback}
			}
		}
		{delay 1.5
			{with_linked_entity "missile"  
			 {ani_play "open_wing" 1.0}
			}
		}
		{delay 25  {call "fall"}}
	}
	("proj_impulse_movement" cont_impulse(10) main_impulse(20) const_vel(20))
}

{"umpk_500_guided"
    {on "on_spawn_custom"
		{impulse up -1.5 0.5 forward 35 4 com} {constrain_velocity 50}
		{delay 0.1
			{with_linked_entity "missile"  
				{ani_play "flip_bomb" 0.25 callback}
			}
		}
		{delay 1.5
			{with_linked_entity "missile"  
			 {add_view	"flash_cannon_small"	 "flash_cannon_small"	 "tail"} 
			 {view start "flash_cannon_small"}
			 {ani_play "open_wing" 1.0}
			}
		}
		{delay 22  {call "fall"}}

	}
	("proj_impulse_movement" cont_impulse(10) main_impulse(20) const_vel(20))
}
{"ls6_guided"
    {on "on_spawn_custom"
		{impulse up -1.5 0.5 forward 35 4 com} {constrain_velocity 50}
		{delay 0.5
			{with_linked_entity "missile"  
			 {ani_play "open_wing" 1.0}
			}
		}
		{delay 21  {call "fall"}}
	}
	("proj_impulse_movement" cont_impulse(10) main_impulse(20) const_vel(20))
}
{"cs-bbm2_guided"
    {on "on_spawn_custom"
		{impulse up -1.5 0.5 forward 18 4 com} {constrain_velocity 30}
		{delay 0.5
			{with_linked_entity "missile"  
			 {ani_play "open_wing" 1.0}
			}
		}
		{delay 23  {call "fall"}}
	}
	("proj_impulse_movement" cont_impulse(10) main_impulse(14) const_vel(20))
}
{"proj_cont"
{on spawn {delay 0.3 {delete}}}
{on contact overload {delete}}
}