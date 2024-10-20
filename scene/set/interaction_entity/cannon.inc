(define "handle_ik"
	{on ik begin "basis"}
	{on ik end "basis"}
	{on ik begin "turret"
		{play_sound "rotate_turret" 1}
	}
	{on ik end "turret"
		{stop_sound "rotate_turret"}
	}
	{on ik begin "gun_rot"}
	{on ik end "gun_rot"}
	{on ik begin "turret_rotator"}
	{on ik end "turret_rotator"}
)

(define "damage_cannon_process_pierce" ;by Svoyak
{if stuff "%staff"
    {if volume "standl"
        ;do nothing
    else volume "standr"
        ;do nothing
    else volume "wheell"
        ;do nothing
    else volume "wheelr"
        ;do nothing
    else volume "gun"
        {components "gun" break}
    else
        {burn fx "smoke_dead_tank3" fake}
        {if rand %pierce_turret__crew_die
            {kill_crew "commander"}
            {kill_crew "driver1"}
        else rand %pierce_turret__crew_die
            {kill_crew "driver2"}
            {kill_crew "gunner"}
        else rand %pierce_turret__crew_die
            {kill_crew "commander1"}
        ;{damage_report "body" "crew_down"}
        }

        {if rand %pierce_turret__crew_contusion
            {crew_throw_off up 2 1 dir 2 1 turn 0 180 forward 2 force}

            {if operatable
                {weapon_work "gun" 0}
                {tags add "contused"}
                {delay 2
                    {if not tagged "gun_brake"
                        {weapon_work "gun" 1}
                    }
                    {tags remove "contused"}
                }
            }
        }
        {if rand %pierce_turret__gun_brake
            {components "gun" break}
        }
    }
}
)
(define "detach_and_explosion"
	{detach}
	{call "explosion"}
)
{"mgun"
	{on spawn
		{ani_play "off"}
	}
}
{"cannon"
{on spawn 
	{tags add "cannon_proj"}
	{link_sound "round_dot" "fortification/install/reinforcement_sandbags_install"}
	{link_sound "camouflage_cannon" "fortification/install/scrim_install"}
	{call "talk_scanner"}		

}
	{on "executing_order_weapon_fire" overload
		{if not effector ; target - ground
			{if weapon_fire_mode "non_stop" ; once short_burst long_burst smart_burst
				{if aim_mode "attack_ground_forced"  ; default anti_airborne attack_ground_forced
					{talk "cannon_executing_order_weapon_fire_barrage"}
				else
					{talk "cannon_executing_order_weapon_fire_non_stop_ground"}
				}
			}
		}
	}
	{on "bullet_reflect"
;		{if not armor_health 1 and not flag "broken"
		{if not flag "broken"
			{if not stuff "bullet" and not stuff "fg" and not stuff "fr"
				{talk "cannon_bullet_reflect"}
				{call "talk_target_bullet_reflected"}
			}
		}
	}
	{on "talk_target_destroyed"
		{call "destroyed_by_spy"}
		{talk "cannon_leave"}
		{call "talk_target_destroyed_cannon"}
	}
	{on "talk_target_broke_engine" overload}
	{on "talk_target_broke_turret" overload}
	{on "talk_target_broke_track" overload}
	{on "smokescreen" overload
		{if operatable
			{call "cwsh_switch_hatch"}
		 }	
	}
	{on pierce
		("damage_cannon_process_pierce"
			staff(ptr)
			pierce_turret__crew_die(0)
			pierce_turret__gun_brake(0)
			pierce_turret__crew_contusion(0)
		)
		("damage_cannon_process_pierce"
			staff(shell ap)
			pierce_turret__crew_die(0.5)
			pierce_turret__gun_brake(0.3)
			pierce_turret__crew_contusion(1)
		)
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
		(define "check_damage_crew"
		  else volume "%crew_place" work and min_energy 1 and rand %p
				{if crew_in_place "%crew"
				 {damage_report "body" "%msg"}
				}
				{kill_crew "%crew"}{icon_event "crew_dead" 10}
				{crew_enable place "%crew" 0} {set "crew_tempdisabled" 1}
				{delay 10 {crew_enable place "%crew" 1} {set "crew_tempdisabled" 0}}
		)
		(define "check_damage_desant"
		  else volume "%crew_place" work and min_energy 1 and rand %p
				{kill_crew "%crew"}
		)
		min_energy %e 
		 {if component "d_a" or component "nera" {if rand 0.1   {blastwave c4 (+ %e 0.2) r0 0.01 r1 0.02 position}{spawn "metal_hit_bul"}}
		("check_damage_frag" component(autoloader)  p(1) splitter(%splitter))
		("check_damage_frag" component(mgun)  p(0.1) splitter(%splitter))
		("check_damage_frag" component(mgun1)  p(0.1) splitter(%splitter))
		("check_damage_frag" component(mgun2)  p(0.1) splitter(%splitter))
		("check_damage_frag" component(mgun3)  p(0.1) splitter(%splitter))
		("check_damage_frag" component(mgun4)  p(0.1) splitter(%splitter))
		("check_damage_frag" component(mgun5)  p(0.1) splitter(%splitter))
		("check_damage_frag" component(mgun6)  p(0.1) splitter(%splitter))
		("check_damage_frag" component(turret_ring)  p(0.5) splitter(%splitter))
		("check_damage_frag" component(turret_move_engine)  p(0.1) splitter(%splitter))
		("check_damage_frag" component(stabilizer)  p(0.35) splitter(%splitter))
		("check_damage_frag" component(gunner_panel)  p(0.25) splitter(%splitter))
		("check_damage_frag" component(PPU)  p(0.15) splitter(%splitter))
		("check_damage_frag" component(APU)  p(0.75) splitter(%splitter))
		("check_damage_frag" component(driver_triplex)  p(0.15) splitter(%splitter))
		("check_damage_frag" component(commander_triplex)  p(0.25) splitter(%splitter))
		("check_damage_frag" component(additional_triplex)  p(0.15) splitter(%splitter))
		("check_damage_frag" component(additional_triplex1)  p(0.15) splitter(%splitter))
		("check_damage_frag" component(additional_triplex2)  p(0.1) splitter(%splitter))
		("check_damage_frag" component(additional_triplex3)  p(0.1) splitter(%splitter))
		("check_damage_frag" component(additional_triplex4)  p(0.1) splitter(%splitter))
		("check_damage_frag" component(additional_triplex5)  p(0.1) splitter(%splitter))
		("check_damage_frag" component(ammo_storage_main)  p(1) splitter(%splitter))	;они большие, по 3м2
		("check_damage_frag" component(ammo_storage_autocannon)  p(0.5) splitter(%splitter))
		("check_damage_frag" component(ammo_storage_mgun)  p(0.1) splitter(%splitter))
		("check_damage_frag" component(gun)  p(0.2) splitter(%splitter))
		("check_damage_frag" component(gun1)  p(0.2) splitter(%splitter))
		("check_damage_frag" component(gun2)  p(0.3) splitter(%splitter))
		("check_damage_frag" component(gun3)  p(0.3) splitter(%splitter))
		 else {blastwave c4 (+ %e 0.2) r0 0.04 r1 0.05 position}{if rand 0.1{spawn "metal_hit_bul"}}
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
	{on break_armor
		{call "do_armor_break"}
	}
	{on break_armor_again
		{call "do_armor_break"}
	}
	{on "do_armor_break"
		{if name "blast"
			{if volume "body"
				{components "body" destroy}
				{call "stat_break"}
                {kick_entity_manager}
                {reset_manual_control}
                {able select 0}
        		{able repaired 0}
                {unlink_trailer}
				{tags add "destroyed"}
			else volume "turret"
				{components "turret" destroy}
				{call "stat_break"}
                {kick_entity_manager}
                {reset_manual_control}
                {able select 0}
        		{able repaired 0}
                {unlink_trailer}
				{tags add "destroyed"}
			}
		}
	}
	{on blast_hit
		{if min_energy 5 
			{if not linked
				{impulse up 0.5 0.2 dir 1 0.2}
			}
			{if simulating
				{attack_save}
				{delay_ex 0.3
					{attack_load}
					{crew_throw_off up 4 1 dir 5 1 turn 0 180 forward 2 force}
				}
			}
			{call "explosion"}
		else min_energy 1.2
			{if not linked
				{impulse up 0.3 0.2 dir 0.7 0.2}
			}
			{if simulating
				{attack_save}
				{delay_ex 0.3
					{attack_load}
					{crew_throw_off up 4 1 dir 5 1 turn 0 180 forward 2 force}
				}
			}
		else min_energy 0.6
 		 	{ani_play "hit"}
		}
	}
	{on "explosion"
	   {components "body" destroy}
	   {components "turret" destroy}
	   {call "stat_break"}
                {kick_entity_manager}
                {reset_manual_control}
                {able select 0}
        	   {able repaired 0}
                {unlink_trailer}
	}
	{on "cut_parts"
		{add_view "smoke_dead_norm" "deathfx" "FXfire1"}
		{view start "deathfx"}
		(define "cut_part"
			{tear "piece_medium_steel" bone %0
				{impulse up 8 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 10 no_position}
				{call "check_delete_part"}
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
		("cut_part" args "part9")
		("cut_part" args "part10")
		("cut_part" args "part11")
		("cut_part" args "part12")
		{delay 14 {view stop "deathfx"}}
	}
	{on fire "gun"
		{ani_play "recoil"}
        {view start "flashbarrel1"}
		{view start "flashbarrel1s"}
		{delay 0.15
			{view pause "flashbarrel1"}
		}
		{delay 0.3
			{view pause "flashbarrel1s"}
		}
		{call "spawn_shell"}
	}
	{on "spawn_shell"
		{start_sound "weapon/shot/shell"}
		{add_view "smoke_zenit" "smoke_shell" "fx_invers"}
		{view start "smoke_shell"}
		{delay 2.5 0.5
			{view stop "smoke_shell"}
		}
		{spawn "shell_cannon" "fx_invers" x ;scale 0.014
			{impulse up 1.5 0.5 dir -4.5 0.7 cz 0.2 0.1 com}
			{add_view "smoke_zenit" "smoke_shell" "fx_shellsmoke"}
			{view start "smoke_shell"}
			{delay_effect 3 1 "stop"}
			{delay 3 0.5
				{hide 3}
			}
		}
	}
	{on contact
		{if not impregnable
			{if not effector "armored_car"
				{if effector "tank"
				  {if effector_velocity 10	;to avoid destruction while putting inside vehicle
					{component destroy}
;					{if volume "body"
						{set "crush" 1}
						{call "explosion"}
;					}
				  }
				else effector "big part"
					{if effector_velocity 5
						{component break}
					}
				}
			}
		}
	}
	("handle_ik")

	{on "check_water_level" overload
		{if not linked
			{if water_level 1.2
				{able "sinking" 1}
			}
		}
	}
	{on "tear_wheel" overload}
	{on "fortification_crush"
		{if effector "trench"
			{kill_crew}
			{component destroy}
			{set "crush" 1}
			("detach_and_explosion")
		}
	}
	{on "diagnostics"
		{if not work "mgun"
			{damage_report "mgun" "mgun_damaged"}
		else not work "mgun1"
			{damage_report "mgun1" "mgun:mgun_damaged"}
		else not work "mgun2"
			{damage_report "mgun2" "mgun:mgun_damaged"}
		else not work "mgun3"
			{damage_report "mgun3" "mgun:mgun_damaged"}
		else not work "mgun4"
			{damage_report "mgun4" "mgun:mgun_damaged"}
		else not work "mgun5"
			{damage_report "mgun5" "mgun:mgun_damaged"}
		else not work "mgun6"
			{damage_report "mgun6" "mgun:mgun_damaged"}
		}
		{if not work "gun"
			{damage_report "gun" "gun_damaged"}
		}
		{if not work "gun1"
			{damage_report "gun1" "gun1_damaged"}
		}
		{if not work "gun2"
			{damage_report "gun2" "ptur_damaged"}
		else not work "gun3"
			{damage_report "gun3" "ptur_damaged"}
		}
		{if not work "driver_triplex"		
				{damage_report "driver_triplex" "driver_triplex_damaged"}
		}
		{if not work "commander_triplex"
				{damage_report "commander_triplex" "commander_triplex_damaged"}
		}
		{if not work "additional_triplex"
				{damage_report "additional_triplex" "additional_triplex_damaged"}
		else not work "additional_triplex1"
				{damage_report "additional_triplex1" "additional_triplex:additional_triplex_damaged"}
		else not work "additional_triplex2"
				{damage_report "additional_triplex2" "additional_triplex:additional_triplex_damaged"}
		else not work "additional_triplex3"
				{damage_report "additional_triplex3" "additional_triplex:additional_triplex_damaged"}
		else not work "additional_triplex4"
				{damage_report "additional_triplex4" "additional_triplex:additional_triplex_damaged"}
		else not work "additional_triplex5"
				{damage_report "additional_triplex5" "additional_triplex:additional_triplex_damaged"}
		}
		{if not work "body"
				{damage_report "body" "body_broken"}
		}
		{if not work "turret"
				{damage_report "turret" "turret_broken"}
		}
		{if not work "engine"
				{damage_report "engine" "engine_broken"}
		}
		{if not work "wheelleft1"
			{damage_report "wheelleft1" "wheels_damaged"}
		else not work "wheelright1"
			{damage_report "wheelright1" "wheels_damaged"}
		else not work "wheelleft2"
			{damage_report "wheelright2" "wheels_damaged"}
		else not work "wheelright2"
			{damage_report "wheelright2" "wheels_damaged"}
		else not work "wheelleft3"
			{damage_report "wheelright3" "wheels_damaged"}
		else not work "wheelright3"
			{damage_report "wheelright3" "wheels_damaged"}
		else not work "wheelleft4"
			{damage_report "wheelright4" "wheels_damaged"}
		else not work "wheelright4"
			{damage_report "wheelright4" "wheels_damaged"}
		}
	}
}
{"atgm" 
	{on spawn overload
		{add_view 	"rok_tail"	                            "rok_tail"			"tail"}
		{add_view 	"startsmoke"	                            "startsmoke"			"foresight1"}
		{add_view 	"smoke_zenit" 	"zenite_smoke2" 		"tail"}

        {tags add "cannon_proj"}
		{add_view	"dust_shot_norm_link"		"startsmoke_norm"			"basis"}
		{add_view	"dust_shot_big_link"		"startsmoke_big"			"basis"}
	}
	{on fire "gun" overload
		("low_speed_bullet")
		{view start "rok_tail"}
		{view start "startsmoke"}
		{volumes "gun" disable bullet blast}
		
		{if terrain_fx "ground"	or terrain_fx "country_road"	
;			{spawn "dust_shot_norm" "basis"}
			{view start "startsmoke_norm"}
		else terrain_fx "sand"	
;			{spawn "dust_shot_big" "basis"}
			{view start "startsmoke_big"}
		}
		
		{delay 0.4
			{view pause "rok_tail"}
			{view pause "startsmoke_big"}
			{view pause "startsmoke_norm"}
		}
		{delay 0.12 
			{view start "zenite_smoke2"}
			{delay 25 15
				{view pause "zenite_smoke2"}
			}
		}
		{delay 30
			{volumes "gun" enable bullet blast}
		}
		("cw_check_shooting" weap_id(gun))
	}
	{on fire "gun2" overload
		("low_speed_bullet")
		{view start "rok_tail"}
		{view start "startsmoke"}
		{volumes "gun" disable bullet blast}
		
		{if terrain_fx "ground"	{spawn "circledust_norm" "basis"}
		else terrain_fx "country_road"	{spawn "circledust_norm" "basis"}
		else terrain_fx "sand"	{spawn "circledust_norm" "basis"}
		}
		
		{delay 0.4
			{view pause "rok_tail"}
		}
		{delay 0.12 
			{view start "zenite_smoke2"}
			{delay 25 15
				{view pause "zenite_smoke2"}
			}
		}
		{delay 30
			{volumes "gun" enable bullet blast}
		}
		("cw_check_shooting" weap_id(gun2))
	}
	{on pierce
		{if volume "gun"
			{components "gun" break}
		else volume "gun2"
			{components "gun2" break}
		}
	}
    {on break 
		{if component "gun"
			{if not tagged "destroyed"
				{damage_report "turret" "ptur:ptur_damaged"}
				{spawn "metal_hit_bul"}
				{tags add "gun_damaged"}
				{weapon_work "gun" 0}
				{weapon_work "gun2" 0}
				{if ammo_tag_for_weapon "gun" "ammo"
					{spawn "ex_air_big"}
					{fragments c4 6 r0 0.3 r1 0.5 position}
					{fragments c4 2 r0 3 r1 4 position}
				}
			}
		else component "gun2"
			{if not tagged "destroyed"
				{damage_report "turret" "ptur:ptur_damaged"}
				{spawn "metal_hit_bul"}
				{tags add "gun_damaged"}
				{weapon_work "gun" 0}
				{weapon_work "gun2" 0}
				{if ammo_tag_for_weapon "gun2" "ammo"
					{spawn "ex_air_big"}
					{fragments c4 6 r0 0.3 r1 0.5 position}
					{fragments c4 2 r0 3 r1 4 position}
				}
			}
		}
     }

    {on repair
	{if component "gun"
		{damage_report "gun" "ptur:ptur_repaired"}
		{tags remove "gun_damaged"}
		{weapon_work "gun" 1}
		{weapon_work "gun2" 1}
	else component "gun2"
		{damage_report "gun2" "ptur:ptur_repaired"}
		{tags remove "gun2_damaged"}
		{tags remove "gun_damaged"}
		{weapon_work "gun2" 1}
		{weapon_work "gun" 1}
	}
	{if component "body"
	}
   }
	{on blast_hit
		{if min_energy 3	{call "explosion"}}
	}
	{on "ammo_reload_begin"
;		{if stuff "fliter by weapon"}
;		{if ammo "fliter by ammo"}
		{talk "ammo_reload_begin"}
	}
	{on "ammo_reload_end"
;		{if stuff "fliter by weapon"}
;		{if ammo "fliter by ammo"}
		{talk "ammo_reload_end"}
	}
	{on "selection" overload
		{talk "selection_support"}
	}
	{on "executing_order_move" overload
		{talk "executing_order"}
	}
	{on "bullet_hit_obstacle" overload
		{talk "human_bullet_hit_obstacle"}
	}
	{on "report_unable_move_reason" overload
		{talk "cannon_need_more_crew"}
	}
	{on "report_repairer_fail" overload
		{talk "cannon_repairer_fail"}
	}
	{on "enemy_observed" overload
		{talk "human_enemy_observed" {audience ally}}
	}
	{on "talk_scanner"			
		{if attacking_weapon or attacked	
			{talk "cannon_in_action" {audience all}}			
		}				
		{delay 1 "talk_scanner"
			{call "talk_scanner"}
		}
	}
	{on "play_sound_camouflage" overload
		{play_sound_in_channel "camouflage_cannon" "camouflage_ch"}
		{delay_effect 0 "camouflage_next_sound"}
	}
	{on "camouflage_next_sound" overload
		{if flag "camouflage_play_sound"
			{delay 1.1 0.1 "camouflage_next_sound"
				{call "play_sound_camouflage"}
			}
		}
	}
	("action_play_sound_and_check_stop" action(round_dot) delay_next_sound(2))
	{on move on
		{tags add "no_missile_control"}
	}
	{on move off
		{tags remove "no_missile_control"}
	}
	{on "update_power"
		{tags remove "no_missile_control"}
	}
}
{"laser_designator" 
	{on spawn overload
			(mod not "mp" {add_view "laser_designator" "laser_designator" "foresight1"})
			{view hide "laser_designator"}
			{tags add "cannon_proj"}
	}
	{on fire "gun" overload
			{view show "laser_designator"}
			{delay 0.6
				{view hide "laser_designator"}
			}
			("cw_check_shooting" weap_id(gun))
	}
}
{"eleron_catapult" 
	{on spawn 
	{tags add "cannon_proj"}
	}
	{on fire "gun" overload
		{ani_play "fire" callback}
		("cw_check_shooting" weap_id(gun))
	}
	{on animation_end "fire"
		{spawn "eleron3sv" "foresight1" x}
	}
}
{"eleron_control"
	{on "cut_parts"
		("cut_part" args "part1")
		("cut_part" args "part2")
		("cut_part" args "part3")
		("cut_part" args "part4")
		("cut_part" args "part5")
	}	

}
{"lancet3m_catapult" 
	{on spawn 
		{tags add "cannon_proj"}
		{tags remove "lancet3m_fg"}
		{tags remove "lancet3m_cm"}
	}
	{on fire "gun" overload
		{ani_play "fire" callback}
		("cw_check_shooting" weap_id(gun))
	}
	{on animation_end "fire"
	   {if tagged "lancet3m_fg"
		{spawn "lancet3m_fg" "foresight1" x}
	   else
		{spawn "lancet3m_cm" "foresight1" x}
	   }
		{tags remove "lancet3m_fg"}
		{tags remove "lancet3m_cm"}
	}
}
{"switchblade300_catapult" 
	{on spawn 
	{tags add "cannon_proj"}
	}
	{on fire "gun" overload
		{ani_play "fire" callback}
		("cw_check_shooting" weap_id(gun))
	}
	{on animation_end "fire"
		{spawn "switchblade300" "foresight1" x}
	}
}
{"switchblade600_catapult" 
	{on spawn 
	{tags add "cannon_proj"}
	}
	{on fire "gun" overload
		{ani_play "fire" callback}
		("cw_check_shooting" weap_id(gun))
	}
	{on animation_end "fire"
		{spawn "switchblade600" "foresight1" x}
	}
}
{"ch901_catapult" 
	{on spawn 
	{tags add "cannon_proj"}
	}
	{on fire "gun" overload
		{ani_play "fire" callback}
		("cw_check_shooting" weap_id(gun))
	}
	{on animation_end "fire"
		{spawn "ch901" "foresight1" x}
	}
}
{"ptur_konkurs"
	{on fire "gun" 
		{set "gun"}{call "proj_probe"}
	}
	{on "cut_parts" overload
		{add_view "smoke_dead_norm" "deathfx" "FXfire1"}
		{view start "deathfx"}
		(define "cut_part"
			{tear "piece_medium_steel" bone %0
				{impulse up 1 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 5 no_position}
				{call "check_delete_part"}
			}
		)
		("cut_part" args "ptur_rot")
		("cut_part" args "turret")
		("cut_part" args "ptur")
		{delay 14 {view stop "deathfx"}}
	}
}
{"metis_m"
	{on fire "gun2" 
;		{spawn "proj_probe" "Foresight1" x {tags add "Foresight1"}}
		{set "gun2"}{call "proj_probe"}
	}
	{on "cut_parts" overload
		{add_view "smoke_dead_norm" "deathfx" "FXfire1"}
		{view start "deathfx"}
		(define "cut_part"
			{tear "piece_medium_steel" bone %0
				{impulse up 1 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 5 no_position}
				{call "check_delete_part"}
			}
		)
		("cut_part" args "part1")
		("cut_part" args "part2")
		("cut_part" args "part3")
		{delay 14 {view stop "deathfx"}}
	}
}
{"kornet_stan"
	{on fire "gun" 
		{set "gun"}{call "proj_probe"}
	}
	{on "cut_parts" overload
		{add_view "smoke_dead_norm" "deathfx" "FXfire1"}
		{view start "deathfx"}
		(define "cut_part"
			{tear "piece_medium_steel" bone %0
				{impulse up 1 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 5 no_position}
				{call "check_delete_part"}
			}
		)
		("cut_part" args "part1")
		("cut_part" args "part2")
		("cut_part" args "part3")
		("cut_part" args "part5")
		("cut_part" args "gun")
		("cut_part" args "turret")
		{delay 14 {view stop "deathfx"}}
	}
}
{"malytka_stan"
	{on fire "gun" 
		{delay 0.1 {spawn "9k14m_carrier" "Foresight1_spawn" x}}
	}
	{on "cut_parts" overload
		{add_view "smoke_dead_norm" "deathfx" "FXfire1"}
		{view start "deathfx"}
		(define "cut_part"
			{tear "piece_medium_steel" bone %0
				{impulse up 1 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 5 no_position}
				{call "check_delete_part"}
			}
		)
		("cut_part" args "part2")
		("cut_part" args "part3")
		("cut_part" args "gun")
		{delay 14 {view stop "deathfx"}}
	}
}
{"hj73_stan"
	{on fire "gun" 
		{set "gun"}{call "proj_probe"}
	}
	{on "cut_parts" overload
		{add_view "smoke_dead_norm" "deathfx" "FXfire1"}
		{view start "deathfx"}
		(define "cut_part"
			{tear "piece_medium_steel" bone %0
				{impulse up 1 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 5 no_position}
				{call "check_delete_part"}
			}
		)
		("cut_part" args "part2")
		("cut_part" args "part3")
		("cut_part" args "gun")
		{delay 14 {view stop "deathfx"}}
	}
}
{"ptur_tow"
	{on fire "gun" 
;		{spawn "proj_probe" "Foresight1" x {tags add "Foresight1"}}
		{set "gun"}{call "proj_probe"}
	}
	{on "cut_parts" overload
		{add_view "smoke_dead_norm" "deathfx" "FXfire1"}
		{view start "deathfx"}
		(define "cut_part"
			{tear "piece_medium_steel" bone %0
				{impulse up 8 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 10 no_position}
				{call "check_delete_part"}
			}
		)
		("cut_part" args "gun")
		{delay 14 {view stop "deathfx"}}
	}
}
{"hj8_stan"
	{on fire "gun" 
		{set "gun"}{call "proj_probe"}
	}
	{on "cut_parts" overload
		{add_view "smoke_dead_norm" "deathfx" "FXfire1"}
		{view start "deathfx"}
		(define "cut_part"
			{tear "piece_medium_steel" bone %0
				{impulse up 8 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 10 no_position}
				{call "check_delete_part"}
			}
		)
		("cut_part" args "part1")
		("cut_part" args "part2")
		("cut_part" args "part3")
		("cut_part" args "part4")
		("cut_part" args "turret")
		{delay 14 {view stop "deathfx"}}
	}
}
{"milan_stan"
	{on fire "gun" 
		{set "gun"}{call "proj_probe"}
	}
	{on "cut_parts" overload
		{add_view "smoke_dead_norm" "deathfx" "FXfire1"}
		{view start "deathfx"}
		(define "cut_part"
			{tear "piece_medium_steel" bone %0
				{impulse up 8 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 10 no_position}
				{call "check_delete_part"}
			}
		)
		("cut_part" args "part1")
		("cut_part" args "part2")
		("cut_part" args "part3")
		{delay 14 {view stop "deathfx"}}
	}
}
{"spike_lr_stan"
	{on fire "gun" 
		{delay 0.1 {spawn "spike-lr_carrier" "foresight1" x}}
	}
	{on "cut_parts" overload
		{add_view "smoke_dead_norm" "deathfx" "FXfire1"}
		{view start "deathfx"}
		(define "cut_part"
			{tear "piece_medium_steel" bone %0
				{impulse up 8 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 10 no_position}
				{call "check_delete_part"}
			}
		)
		("cut_part" args "part1")
		("cut_part" args "part2")
		("cut_part" args "part3")
		{delay 14 {view stop "deathfx"}}
	}
}
{"spike_stan"
	{on fire "gun" 
		{delay 0.1 {spawn "spike-er_carrier" "foresight1" x}}
	}
	{on "cut_parts" overload
		{add_view "smoke_dead_norm" "deathfx" "FXfire1"}
		{view start "deathfx"}
		(define "cut_part"
			{tear "piece_medium_steel" bone %0
				{impulse up 8 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 10 no_position}
				{call "check_delete_part"}
			}
		)
		("cut_part" args "part1")
		("cut_part" args "part2")
		("cut_part" args "part3")
		("cut_part" args "part4")
		{delay 14 {view stop "deathfx"}}
	}
}
{"mmp_stan"
	{on fire "gun" 
		{delay 0.1 {spawn "mmp_missile_carrier" "foresight1" x}}
	}
	{on "cut_parts" overload
		{add_view "smoke_dead_norm" "deathfx" "FXfire1"}
		{view start "deathfx"}
		(define "cut_part"
			{tear "piece_medium_steel" bone %0
				{impulse up 8 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 10 no_position}
				{call "check_delete_part"}
			}
		)
		("cut_part" args "part1")
		("cut_part" args "part2")
		("cut_part" args "part3")
		("cut_part" args "turret")
		{delay 14 {view stop "deathfx"}}
	}
}
{"mistral_stan"
	{on fire "gun" 
		{delay 0.1 {spawn "mistral_missile_carrier" "foresight1" x}}
	}
	{on "cut_parts" overload
		{add_view "smoke_dead_norm" "deathfx" "FXfire1"}
		{view start "deathfx"}
		(define "cut_part"
			{tear "piece_medium_steel" bone %0
				{impulse up 8 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 10 no_position}
				{call "check_delete_part"}
			}
		)
		("cut_part" args "part1")
		("cut_part" args "part2")
		("cut_part" args "part3")
		("cut_part" args "part5")
		("cut_part" args "turret")
		{delay 14 {view stop "deathfx"}}
	}
}
{"starstreak_stan"
	("custom_multi_launcher"	weapon(gun) tail(taill_) shooter(shooter) missile(starstreak_ammo))
	{on "cut_parts" overload
		{add_view "smoke_dead_norm" "deathfx" "FXfire1"}
		{view start "deathfx"}
		(define "cut_part"
			{tear "piece_medium_steel" bone %0
				{impulse up 8 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 10 no_position}
				{call "check_delete_part"}
			}
		)
		("cut_part" args "part1")
		("cut_part" args "part2")
		("cut_part" args "part3")
		("cut_part" args "part4")
		("cut_part" args "part5")
		("cut_part" args "part6")
		("cut_part" args "turret")
		{delay 14 {view stop "deathfx"}}
	}
}
{"shershen_d_stan"
	("atgm_multi_launcher" weapon(gun) foresight(foresight1) tail(tail))

	{on "cut_parts" overload
		{add_view "smoke_dead_norm" "deathfx" "FXfire1"}
		{view start "deathfx"}
		(define "cut_part"
			{tear "piece_medium_steel" bone %0
				{impulse up 1 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 5 no_position}
				{call "check_delete_part"}
			}
		)
		("cut_part" args "part1")
		("cut_part" args "part2")
		("cut_part" args "part3")
		("cut_part" args "gun")
		("cut_part" args "turret")
		{delay 14 {view stop "deathfx"}}
	}
}
{"tl-4_stan"
	{on fire "gun" 
		{delay 0.1 {spawn "tl4_cm_carrier" "foresight1" x}}
	}
	{on "cut_parts" overload
		{add_view "smoke_dead_norm" "deathfx" "FXfire1"}
		{view start "deathfx"}
		(define "cut_part"
			{tear "piece_medium_steel" bone %0
				{impulse up 8 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 10 no_position}
				{call "check_delete_part"}
			}
		)
		("cut_part" args "part1")
		("cut_part" args "part2")
		("cut_part" args "part3")
		("cut_part" args "part4")
		{delay 14 {view stop "deathfx"}}
	}
}
{"spg_9"
	{on fire "gun" 
		{set "gun"}{call "proj_probe"}
		{spawn "startsmoke" "tail" x}
	}
}
{"cannon_small"
{on spawn 
{tags add "cannon_proj"}
}
	{on contact overload
		{if not impregnable
			{if effector "tank"
			  {if effector_velocity 7
				{component destroy}
;				{if volume "body"
					{set "crush" 1}
					{call "explosion"}
;				}
			  }
			else effector "armored_car"
			  {if effector_velocity 10
				{component destroy}
;				{if volume "body"
					{set "crush" 1}
					{call "explosion"}
;				}
			  }
			}
		}
	}
}

{"mg_stan"
	{on spawn
		{add_view	"flash_gun_big"	"flashbarrel2"	"Foresight3"}
	}
	{on fire "mgun"
		{view start "flashbarrel2"}
	}
	{on "explosion_blastwave" overload
		{impulse up 0.2 dir 0.3}
	}
;	{on contact overload}
	{on break
		{if component "shield"
			{call "explosion"}
		}
	}
}

{"no_exp_blast"
	{on "explosion_blastwave" overload
;		{impulse up 0.2 dir 0.3}
	}
	{on "explosion_sound" overload}
}

{"heavy cannon"
	{on spawn
		{add_view	"flash_cannon_medium"	"flashbarrel1"	"Foresight1"}
	}
	{on fire "gun"
       	{spawn "dust_shot_norm" "basis"}
        {spawn "tank_canon_fire" "Foresight1" x}
	}
}

{"medium cannon"
	{on spawn
		{add_view	"flash_cannon_small"	"flashbarrel1"	"Foresight1"}
		{add_view	"tank_canon_fire_link"		"flashbarrel1s"			"Foresight1"}
		{add_view	"dust_shot_small_link"		"flashbarrel1s"			"Foresight1"}
	}
	{on fire "gun"
		{view start "flashbarrel1s"}
		{delay 0.42
			{view pause "flashbarrel1s"}
		}
;       	{spawn "dust_shot_small" "basis"}
;        {spawn "tank_canon_fire_small" "Foresight1" x}
	}
}

{"truck_mortar"
	{on spawn
		{add_view	"startsmoke_link"		"flashbarrel1s"			"Foresight1"}
		{add_view	"dust_shot_small_link"		"flashbarrel1s"			"Foresight1"}
	}
	{on fire "gun"
		{view start "flashbarrel1s"}
		{delay 0.42
			{view pause "flashbarrel1s"}
		}
;		{spawn "startsmoke" inv_normal}
;		{spawn "circledust_norm2" "basis"}
		{ani_play "recoil"}
		{call "spawn_shell"}
		("cw_check_shooting" weap_id(gun))
	}
}

{"mortar"
	{on spawn overload
		{link_sound "rotate_turret" "vehicle/turret/mortar"}
		{link_sound "rotate_gun" "vehicle/turret/medium"}

		{add_view	"flash_cannon_big"		"flashbarrel1"	"Foresight1"}
		{add_view	"spheredust_big"	"dust"			"turret"}
		{add_view	"canon_gaub_fire_link"		"flashbarrel1s"			"Foresight1"}
	}
	{on fire "gun" overload
		{view start "flashbarrel1s"}
		{delay 0.42
			{view pause "flashbarrel1s"}
		}
		{ani_play "recoil"}
        {spawn "canon_gaub_fire" "Foresight1" x}
        {view start "flashbarrel1"}
		{view start "flashbarrel1s"}
       	{view start "dust"}
		{delay 1
			{view pause "dust"}
		}
		{delay 2
			{view pause "flashbarrel1"}
		}
		{call "spawn_shell"}
		("cw_check_shooting" weap_id(gun))
	}
	{on "cut_parts" overload
		{spawn "tank_die" "Basis"}
		{add_view "smoke_aero_big" "deathfx1" "fx_smoke1"}
		{add_view "smoke_black" "deathfx2" "fx_smoke2"}
		{view start "deathfx1"}
		{view start "deathfx2"}
		(define "cut_part"
			{tear "piece_big_steel" bone %0
				{impulse up 8 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 10 no_position}
				{call "check_delete_part"}
			}
		)
		("cut_part" args "part1")
		("cut_part" args "part2")
		("cut_part" args "part3")
		("cut_part" args "part4")
		("cut_part" args "part5")
		("cut_part" args "part6")
		{delay 10 2 {view stop "deathfx1"}}
		{delay 6 2 {view stop "deathfx2"}}
	}
	{on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
	{on contact overload}
}
{"l16_mortar"
	{on "cut_parts"
		("cut_part" args "gun")
		{bone cut "stan"}
	}
}
{"mortarfr"
	{on "cut_parts"
		("cut_part" args "Body1")
		("cut_part" args "WheelR")
		("cut_part" args "WheelL")
		("cut_part" args "gun")
	}
}
{"mo_81_llr_f1"
	{on "cut_parts"
		("cut_part" args "part1")
		("cut_part" args "part2")
	}
}
{"l118"
	{on "cut_parts"
		("cut_part" args "standl")
		("cut_part" args "standr")
		("cut_part" args "turret")
		("cut_part" args "wheelr")
		("cut_part" args "wheelr")
		("cut_part" args "wheell1")
		("cut_part" args "gun")
	}
}
{"m119"
	{on "cut_parts"
		("cut_part" args "standl")
		("cut_part" args "standr")
		("cut_part" args "turret")
		("cut_part" args "wheelr")
		("cut_part" args "wheelr")
		("cut_part" args "wheell1")
		("cut_part" args "gun")
	}
}
{"cannon flak"
	{on spawn overload
		{call "init_gun"}
		{call "add_movement_sound"}
	}
}

{"flak"
	("handle_ik")
	{on "init_gun"
		{add_view "ofzt_fire" 		"ofzt_fire" 				"foresight1"}
		{add_view "light_flash_zenit"	"flashbarrel"	"foresight1"}
		{add_view "flash_zenit"			"flashbarrel00"	"shooter00"}
		{add_view "flash_zenit"			"flashbarrel01"	"shooter01"}
		{add_view "flash_zenit"			"flashbarrel02"	"shooter02"}
		{add_view "flash_zenit"			"flashbarrel03"	"shooter03"}
		{add_view "smoke_zenit"			"smoke00"		"shooter00"}
		{add_view "smoke_zenit"			"smoke01"		"shooter01"}
		{add_view "smoke_zenit"			"smoke02"		"shooter02"}
		{add_view "smoke_zenit"			"smoke03"		"shooter03"}
		{add_view "zenit_gilz"			"shell"			"FXshell1"}
		{add_view "zenit_gilz"			"shell"			"FXshell2"}
		{add_view "zenit_gilz"			"shell"			"FXshell3"}
		{add_view "zenit_gilz"			"shell"			"FXshell4"}
		{add_view "circledust_norm2"	"dust"			"basis"}
		{call "update_gun"}
	}
	{on "add_movement_sound"
		{link_sound "rotate_turret" "vehicle/turret/light"}
	}
	{on fire "gun" overload
		(define "fire_barrel"
			name "%0"
				{call "fire_barrel%0"}
				{view start "flashbarrel%0"}
				;{view start "ofzt_fire"}
				 {delay 0.05
          					{view stop "ofzt_fire"}
       				 }
				{delay 0.42
					{view pause "flashbarrel%0"}
				}
				{ani_play "fire%0"}
				{delay 0.12 
					{view start "smoke%0"}
					{delay 5
						{view pause "smoke%0"}
					}
				}
		)
		
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		  else ("fire_barrel" args 02)
		  else ("fire_barrel" args 03)
		}

		{if name "00"
			{call "fire_gun_common"}
		}
	}
	{on "fire_gun_common"
		{view start "flashbarrel"}
		{ani_play "recoil"}
		{kill_delay "shell_off"}
		{view start "shell"}
		{view start "dust"}
		{delay 0.12 "shell_off"
			{view pause "shell"}
			{view pause "dust"}
		}
	}
}


{"small cannon"
	{on spawn overload
		{link_sound "rotate_turret" "turret.flak"}

		{add_view "light_flash_zenit"	"flashbarrel"	"foresight1"}
		{add_view "flash_zenit"			"flashbarrel1"	"foresight1"}
		{add_view "smoke_zenit"			"smoke"			"foresight1"}
		{add_view "zenit_gilz"			"shell"			"FXshell1"}
		{call "update_gun"}
		
		{add_view	"human_linked_selection" "linked_selection" "visor"}
		{view hide "linked_selection"}
	}
	{on fire "gun" overload
		{view start "flashbarrel"}
		{view start "flashbarrel1"}
		{ani_play "fire"}
		{ani_play "recoil"}
		{kill_delay "shell_off"}
		{view start "shell"}
		{delay 0.12 "shell_off"
			{view pause "shell"}
			{view start "smoke"}
			{delay 0.3
				{view pause "flashbarrel1"}
			}
			{delay 5
				{view pause "smoke"}
			}
		}
	}
}


{"lg_40"
	{on fire "gun"
		{spawn "bazooka_shot" "fxshot" x}
	}
}

{"zenite" ;gun mounted on car or tank
	("handle_ik")
	{on spawn
		{add_view "light_flash_zenit"	"zenite_flash"	"foresight1"}
		{add_view "flash_zenit"			"zenite_flash"	"foresight1"}
		{add_view "smoke_zenit"			"zenite_smoke"	"foresight1"}
		{add_view "zenit_gilz"			"zenite_shell"	"FXshell1"}
		{add_view "circledust_norm2"	"zenite_dust"	"turret"}
	}
	{on fire "gun" overload
        {view start "zenite_flash"}
		{ani_play "fire"}
		{kill_delay "shell_off"}
		{view start "zenite_shell"}
		{view start "zenite_dust"}
		{delay 0.12 "shell_off"
			{view pause "zenite_shell"}
			{view pause "zenite_dust"}
			{view pause "zenite_dust"}
			{view start "zenite_smoke"}
			{delay 0.3
				{view pause "zenite_flash"}
			}
			{delay 5
				{view pause "zenite_smoke"}
			}
		}
	}
}

{"searchlight"
	{on blast_hit
		{if min_energy 0.4
			{call "light_break"}
		}
	}
	{on "light_break" ; handled in extender
		{call "lamp_broken"}
	}
	{on bullet_hit
		{if volume "lamp1"
			{call "lamp_broken"}
		}
	}
	{on "lamp_broken"
		{tags add "lamp_broken"}
	}
	{on ground_hit
		{call "explosion"}
	}
	{on "_explosion"
		{drop_orders}
		{call "light_break"}
	}
	{on operatable on}	; handled in extender
	{on operatable off}	; handled in extender
}

;=================Main=================
{"cannon zu23-2"
	{on "add_movement_sound"  overload
		{link_sound "rotate_turret" "vehicle/turret_cw/light_m1"}
	}
	("handle_ik")
	{on "init_gun"
		;{add_view "ofzt_fire"                              "zen_ef00"  			"shooter00"}
		;{add_view "ofzt_fire"                              "zen_ef01"  			"shooter01"}
		{add_view "light_flash_zenit"	"flashbarrel"		"foresight1"}
		{add_view "flash_zenit"			"flashbarrel00"	"shooter00"}
		{add_view "flash_zenit"			"flashbarrel01"	"shooter01"}
		{add_view "smoke_zenit"			"smoke00"		"shooter00"}
		{add_view "smoke_zenit"			"smoke01"		"shooter01"}
		{add_view "zenit_gilz"			"shell"			"FXshell"}
		{add_view "zenit_gilz"			"shell"			"FXshell1"}
		{add_view "circledust_norm2"	"dust"			"basis"}
		{call "update_gun"}
	}
	{on "fire_gun_common"
		{view start "flashbarrel"}
		{ani_play "recoil"}
		{kill_delay "shell_off"}
		{view start "shell"}
		{view start "dust"}
		{delay 0.12 "shell_off"
			{view pause "shell"}
			{view pause "dust"}
		}	
	}
	
	
}	
(define "automatic_grenade_launcher"
    	{on fire "mgun" overload
      		;{spawn "startsm_grl" inv_normal}
	}	
)

{"cannon Ags30_stan"
	("automatic_grenade_launcher")
}
{"cannon ags17"
	("automatic_grenade_launcher")
}
{"cannon qlz04"
	("automatic_grenade_launcher")
}
{"cannon mk19"
	("automatic_grenade_launcher")
	{on "cut_parts"
		{tear "piece_medium_steel" bone "gun_rot"
			{impulse up 1 0.5}
			{call "check_delete_part"}
		}
	}
}	
(define "towed_cannon_gun"
	{on spawn		
		{add_view 	"smoke_zenit" 	"zenite_smoke" 		"foresight1"}	
		{add_view	"tank_canon_fire_small_link"		"flashbarrel1"			"smoke_gun1"}
		{add_view	"tank_canon_fire_small_link"		"flashbarrel1"			"smoke_gun2"}
		{add_view	"canon_gaub_fire_link"		"flashbarrel1"			"Foresight1"}
		{add_view	"dust_shot_big_2_link"		"flashbarrel1"			"basis"}
    }
    {on fire "gun"
;			{spawn "tank_canon_fire_small" "smoke_gun1"   x}
;			{spawn "tank_canon_fire_small" "smoke_gun2"   x}
 ;   	 	{spawn "canon_gaub_fire" "Foresight1" x}
 ;     		{spawn "dust_shot_big_2" "basis"}
		{view start "flashbarrel1"}
		{delay 0.42
			{view pause "flashbarrel1"}
		}
		{view start "smoke_add"}
		{delay 0.16 "shell_off"
			{view start "zenite_smoke"}
			{view pause "smoke_add"}
			{view pause "flashbarrel_gun"}
				{delay 5
					{view pause "zenite_smoke"}
				}
		}
	}
)
{"cannon D30"
	{on spawn		
		{add_view 	"smoke_zenit" 	"zenite_smoke" 		"foresight1"}	
		{add_view	"dust_shot_big_2_link"		"smoke_add"			"basis"}
    }
    {on fire "gun" 
		{set "gun"}{call "proj_probe"}
;      		{spawn "dust_shot_big_2" "basis"}
		{view start "smoke_add"}
		{delay 0.16 "shell_off"
			{view start "zenite_smoke"}
			{view pause "smoke_add"}
			{view pause "flashbarrel_gun"}
			{delay 5
				{view pause "zenite_smoke"}
			}
		}
	}	
	{on "cut_parts"
		("cut_part" args "wheell1")
		("cut_part" args "wheelr")
		("cut_part" args "turret")
		("cut_part" args "standr")
		("cut_part" args "standl")
	}		
}
{"cannon mt12_rapira"
	{on spawn		
		{add_view 	"smoke_zenit" 	"zenite_smoke" 		"foresight1"}	
		{add_view	"dust_shot_big_2_link"		"smoke_add"			"basis"}
    }
    {on fire "gun" 
		{set "gun"}{call "proj_probe"}
;      		{spawn "dust_shot_big_2" "basis"}
		{view start "smoke_add"}
		{delay 0.16 "shell_off"
			{start_sound "weapon/shot/shell"}
			{view start "zenite_smoke"}
			{view pause "smoke_add"}
			{view pause "flashbarrel_gun"}
			{delay 5
				{view pause "zenite_smoke"}
			}
		}
	}	
	{on "cut_parts"
		("cut_part" args "wheelleft")
		("cut_part" args "wheelright")
		("cut_part" args "turret")
		("cut_part" args "standr")
		("cut_part" args "standl")
	}	
}
{"cannon 2a65_msta_b"
	("towed_cannon_gun")
	{on "cut_parts"
		("cut_part" args "wheelleft")
		("cut_part" args "wheelright")
		("cut_part" args "turret")
		("cut_part" args "standr")
		("cut_part" args "standl")
	}	
}
{"cannon pl-66"
	("towed_cannon_gun")
	{on "cut_parts"
		("cut_part" args "wheelleft")
		("cut_part" args "wheelright")
		("cut_part" args "turret")
		("cut_part" args "standr")
		("cut_part" args "standl")
	}	
}
{"fh-70"
	("towed_cannon_gun")
	{on "cut_parts"
		("cut_part" args "wheelleft")
		("cut_part" args "wheelright")
		("cut_part" args "turret")
		("cut_part" args "standr")
		("cut_part" args "standl")
		("cut_part" args "standl1")
	}	
}
{"cannon m777"
	("towed_cannon_gun")
	{on "spawn_shell" overload
		{start_sound "weapon/shot/shell"}
		{add_view "smoke_zenit" "smoke_shell" "fx_invers"}
		{view start "smoke_shell"}
		{delay 2.5 0.5
			{view stop "smoke_shell"}
		}
		{spawn "shell_cannon_big" "fx_invers" x
			{impulse up 1.5 0.5 dir -4.5 0.7 cz 0.2 0.1 com}
			{add_view "smoke_zenit" "smoke_shell" "fx_shellsmoke"}
			{view start "smoke_shell"}
			{delay_effect 3 1 "stop"}
			{delay 3 0.5
				{hide 3}
			}
		}
	}
	{on "cut_parts"
		{bone cut "hydraulics_1"}
		{bone cut "hydraulics_2"}
		{bone cut "hydraulics_3"}
		{bone cut "hydraulics_4"}
		{bone cut "hydraulics_5"}
		{bone cut "rail_1"}
		("cut_part" args "wheelleft")
		("cut_part" args "wheelright")
		("cut_part" args "turret")
		("cut_part" args "part1")
		("cut_part" args "part2")
		("cut_part" args "part3")
		("cut_part" args "part4")
		("cut_part" args "part5")
		("cut_part" args "part6")
	}	
}
{"vasilek"
	{on "cut_parts"
		("cut_part" args "wheelleft")
		("cut_part" args "wheelright")
		("cut_part" args "part1")		
		("cut_part" args "part2")
		("cut_part" args "part3")
		("cut_part" args "part4")
		("cut_part" args "part5")
		("cut_part" args "turret")
	}
}
{"p-37"
	{on "check_rotation"
		{if crew_in_place "gunner"
			{if crew_in_place "gunner2"
				 {if work "turret"
				   {if not tagged "radar_off"
					{ani_play "turret" callback}
					{delay 0.1 {ani_play "visor1" -1} {ani_play "visor2" -1}}
					{with_linked_entity "vehicle9"
						{call "start"}
					}
				   else
				    {ani_stop "turret"}
					{delay 0.1 {ani_play "visor1" 1} {ani_play "visor2" 1}}
					{with_linked_entity "vehicle9"
						{call "stop"}
					}
				   }
				 else
					{ani_stop "turret"}
					{delay 0.1 {ani_play "visor1" 1} {ani_play "visor2" 1}}
					{with_linked_entity "vehicle9"
						{call "stop"}
					}
				}
			else
				{ani_stop "turret"}
				{delay 0.1 {ani_play "visor1" 1} {ani_play "visor2" 1}}
				{with_linked_entity "vehicle9"
					{call "stop"}
				}
			}
		else
			{ani_stop "turret"}
			{delay 0.1 {ani_play "visor1" 1} {ani_play "visor2" 1}}
			{with_linked_entity "vehicle9"
				{call "stop"}
			}
		}
	}
	{on animation_end "turret"
		{if linked {call "check_unlink"}
		else 
		   {if not tagged "radar_off"
			{ani_play "turret" callback}
		   }
		}
	}
	{on "check_unlink"
		{delay 3	
		       {if not linked {call "check_rotation"}
		       else {call "check_unlink"}}
		}
	}
	{on crew in
		{kill_delay "check_rotation"}
		{delay 3 "check_rotation"	{call "check_rotation"}}
	}
	{on crew out
		{kill_delay "check_rotation"}
		{delay 3 "check_rotation"	{call "check_rotation"}}
	}
	{on "cwsh_radar_on"
		{delay 0.1 {call "check_rotation"}}
	}
	{on "cwsh_radar_off"
		{delay 0.1 {call "check_rotation"}}
	}
	{on pierce overload
		{if volume "radar_bottom"
			{components "radar_bottom" break}
		else volume "radar_top"
			{components "radar_top" break}
		else volume "visor1"
			{components "visor1" break}
		else volume "visor2"
			{components "visor2" break}
		else volume "turret"
			{components "turret" break}
		}
	}
    {on "check_destroy"
    }
    {on break 
		{if component "visor1"
			{if not tagged "visor1_break"
				{tags add "visor1_break"}
				{damage_report "visor1" "radar_damaged"}
				{tear "piece_medium_steel" bone "visor1"
								{impulse up 2 1 dir 2 1}
				}
			else {call "explosion"}
			}
			{spawn "glass_hit" }
		}
		{if component "visor2"
			{if not tagged "visor2_break"
				{tags add "visor2_break"}
				{damage_report "visor2" "radar_damaged"}
				{tear "piece_medium_steel" bone "visor2"
								{impulse up 2 1 dir 2 1}
				}
			else {call "explosion"}
			}
			{spawn "glass_hit" }
		}
		{if component "radar_bottom"
			{if tagged "radar_break" {call "explosion"}
			else tagged "turret_break" {call "explosion"}}
			{tags add "radar_break"}
			{spawn "tank_die_particle" "radar_bottom"}
		   {damage_report "visor1" "radar_array:radar_array_damaged"}
		}
		{if component "radar_top"
			{if tagged "radar_break" {call "explosion"}
			else tagged "turret_break" {call "explosion"}}
			{tags add "radar_break"}
			{spawn "tank_die_particle" "radar_top"}
		   {damage_report "visor2" "radar_array:radar_array_damaged"}
		}
		{if component "turret"
			{if tagged "radar_break" {call "explosion"}
			else tagged "turret_break" {call "explosion"}}
			{tags add "turret_break"}
			{call "check_rotation"}
			{spawn "tank_die_particle" "turret"}
		}
    }

    {on repair
		{if component "radar_bottom"
			{tags remove "radar_break"}
		}
		{if component "radar_top"
			{tags remove "radar_break"}
		}
		{if component "turret"
			{tags remove "turret_break"}
			{call "check_rotation"}
		}
	}
}

{"radar_stan"
    {on break 
		{if component "visor1"
			{tags add "visor1_break"}
			{damage_report "visor1" "radar_damaged"}
			{call "check_rotation"}
		}
    }
    {on repair
		{if component "visor1"
			{tags remove "visor1_break"}
			{call "check_rotation"}
		}
	}
	{on "check_rotation"
		{if crew_in_place "gunner"
			{if crew_in_place "commander"
				 {if work "visor1"
				   {if not tagged "radar_off"
					{delay 0.1 {ani_play "visor1" -1}}
					{with_linked_entity "vehicle9"
						{call "start"}
					}
				   else
					{delay 0.1 {ani_play "visor1" 1}}
					{with_linked_entity "vehicle9"
						{call "stop"}
					}
				   }
				 else
					{delay 0.1 {ani_play "visor1" 1}}
					{with_linked_entity "vehicle9"
						{call "stop"}
					}
				}
			else
				{delay 0.1 {ani_play "visor1" 1}}
				{with_linked_entity "vehicle9"
					{call "stop"}
				}
			}
		else
			{delay 0.1 {ani_play "visor1" 1}}
			{with_linked_entity "vehicle9"
				{call "stop"}
			}
		}
	}
	{on crew in
		{delay 0.1 {call "check_rotation"}}
	}
	{on crew out
		{delay 0.1 {call "check_rotation"}}
	}
	{on "cwsh_radar_on"
		{delay 0.1 {call "check_rotation"}}
	}
	{on "cwsh_radar_off"
		{delay 0.1 {call "check_rotation"}}
	}
}


{"tank_add_container"
	{on spawn {physics_work 0}}
	{on blast_hit overload}
	{on blast overload}
	{on break_armor overload}
	{on break_armor_again overload}	
	{on break overload
		{if component "nisha"
			{burn fx "smoke_dead_tank2" fake}
		}
	}
	{on pierce
		{if component "nisha"
			{if explosive_amount 4000	;bit more than fully loaded Msta-S
				{spawn "ex_air_big2"} {blastwave c4 16 r0 7 r1 14 position}
				{delay 0.2 0.3 {spawn "ex_air_big2"} {blastwave c4 14 r0 6 r1 12 position}}
				{delay 0.3 0.4 {spawn "ex_air_big2"} {blastwave c4 12 r0 5 r1 10 position}}
				{delay 0.4 0.5 {spawn "ex_air_big2"} {blastwave c4 10 r0 5 r1 10 position}}
				{clear_inventory}
				{call "cut_parts"}
			else explosive_amount 3000
				{spawn "ex_air_big2"} {blastwave c4 12 r0 7 r1 14 position}
				{delay 0.2 0.5 {spawn "ex_air_big2"} {blastwave c4 10 r0 6 r1 12 position}}
				{delay 0.6 1 {spawn "ex_air_big2"} {blastwave c4 8 r0 5 r1 10 position}}
				{delay 1 1.2 {spawn "ex_air_big2"} {blastwave c4 7 r0 4 r1 8 position}}
				{delay 1.3 1.5 {spawn "ex_air_big2"} {blastwave c4 7 r0 4 r1 8 position}}
				{clear_inventory}
				{call "cut_parts"}
				else explosive_amount 2000		
				{spawn "ex_air_big2"} {blastwave c4 9 r0 5 r1 10 position}
				{delay 0.2 0.5 {spawn "ex_air_big2"} {blastwave c4 8 r0 5 r1 10 position}}
				{delay 0.6 1 {spawn "ex_air_big2"} {blastwave c4 8 r0 5 r1 10 position}}
				{delay 1 1.2 {spawn "ex_air_big2"} {blastwave c4 7 r0 4 r1 8 position}}
				{delay 1.3 1.5 {spawn "ex_air_big2"} {blastwave c4 7 r0 4 r1 8 position}}
				{delay 1.6 1.7 {spawn "ex_air_big2"} {blastwave c4 6 r0 4 r1 8 position}}
				{clear_inventory}
				{call "cut_parts"}
			else explosive_amount 1000		;fully loaded M1A1HA or T-72
				{spawn "ex_air_big2"} {blastwave c4 8 r0 5 r1 10 position}
				{delay 0.2 0.5 {spawn "ex_air_big2"} {blastwave c4 7 r0 5 r1 10 position}}
				{delay 0.6 1 {spawn "ex_air_big2"} {blastwave c4 7 r0 5 r1 10 position}}
				{delay 1 1.2 {spawn "ex_air_big2"} {blastwave c4 6 r0 4 r1 8 position}}
				{delay 1.3 1.5 {spawn "ex_air_big2"} {blastwave c4 6 r0 4 r1 8 position}}
				{delay 1.6 1.7 {spawn "ex_air_big2"} {blastwave c4 6 r0 4 r1 8 position}}
				{clear_inventory}
				{call "cut_parts"}
			else explosive_amount 750		;M1A1HA or T-72 after several shots - 1/4 ammo depleted
				{spawn "ex_air_big2"} {blastwave c4 6 r0 4 r1 8 position}
				{delay 0.2 0.5 {spawn "ex_air_big2"} {blastwave c4 6 r0 4 r1 8 position}}
				{delay 0.6 1 {spawn "ex_air_big2"} {blastwave c4 6 r0 4 r1 8 position}}
				{delay 1 1.2 {spawn "ex_air_big2"} {blastwave c4 6 r0 4 r1 8 position}}
				{delay 1.3 1.5 {spawn "ex_air_big2"} {blastwave c4 6 r0 4 r1 8 position}}
				{clear_inventory}
				{call "cut_parts"}
			else explosive_amount 500
				{spawn "ex_air_big2"} {blastwave c4 6 r0 4 r1 8 position}
				{delay 0.2 0.5 {spawn "ex_air_big2"} {blastwave c4 6 r0 4 r1 8 position}}
				{delay 0.6 1 {spawn "ex_air_big2"} {blastwave c4 5 r0 3 r1 6 position}}
				{delay 1 1.2 {spawn "ex_air_big2"} {blastwave c4 5 r0 3 r1 6 position}}
				{clear_inventory}
				{call "cut_parts"}
			else explosive_amount 250
				{spawn "ex_air_big2"} {blastwave c4 4 r0 3 r1 6 position}
				{delay 0.2 0.5 {spawn "ex_air_big2"} {blastwave c4 4 r0 3 r1 6 position}}
				{clear_inventory}
				{call "cut_parts"}
			else explosive_amount 100
				{if rand 0.5 {clear_inventory}{call "cut_parts"}}
			}
		}
	}
	{on "cut_parts"
		{components "nisha" break}
	}
}
{"ur_83p"
    {on fire "gun" 
      	{spawn "dust_shot_big_2" "basis"}
      	{spawn "startsmoke_big" "basis"}
      	{spawn "ur83p_charge" "basis" x}
	}	
	{on "cut_parts"
		("cut_part" args "gun")
	}
}
{"ur83p_charge"
    {on spawn
		{ani_play "wire_fly" callback}
		{add_view	"rocket_smoke"		"ur_engine"				"engine1"}
		{add_view	"rocket_smoke"		"ur_engine"				"engine2"}
		{add_view	"rocket_smoke"		"ur_engine"				"engine3"}
		{add_view	"rocket_smoke"		"ur_engine"				"engine4"}
		{add_view	"rocket_smoke"		"ur_engine"				"engine5"}
		{add_view	"rocket_smoke"		"ur_engine"				"engine6"}
		{add_view	"rocket_smoke"		"ur_engine"				"engine7"}
		{add_view	"rocket_smoke"		"ur_engine"				"engine8"}
		{view start "ur_engine"}
		{view show "ur_engine"}
		{delay 2 {bone cut "engine1"} {bone cut "engine2"} {bone cut "engine3"} {bone cut "engine4"} 
		{bone cut "engine5"} {bone cut "engine6"} {bone cut "engine7"} {bone cut "engine8"}}
	}
	{on animation_end "wire_fly"
		{physics_work 0}
		{delay 0.1 
			{set_skeleton "_x"}
			{delay 2
				{spawn "ur_83p_detector" "expl1"}
				{spawn "ur_83p_detector" "expl2"}
				{spawn "ur_83p_detector" "expl3"}
				{spawn "ur_83p_detector" "expl4"}
				{spawn "ur_83p_detector" "expl5"}
				{spawn "ur_83p_detector" "expl6"}
				{spawn "ur_83p_detector" "expl7"}
				{spawn "ur_83p_detector" "expl8"}
				{spawn "ur_83p_detector" "expl9"}
			}
			{delay 12 {delete}}
		}
	}
}
{"ur_83p_detector"
	{on spawn
		{impulse up 0.1 com}
		{gravity 0.5}
		{constrain_velocity 4.5}
		{delay 0.1 {call "loop_detect"}}
		{delay 10
			{stuff_detonate}
		
		}
	}
	{on "loop_detect"
		{impulse up -0.1 com}
		{if not altitude 1 
			{constrain_velocity 7.5}
			{delay 0.2 {call "loop_detect"}} 
		else altitude 0 
			{physics_work 0}
		else
			{constrain_velocity 1.5}
		}
	}
}
{"vant_vm_shield"
	{on spawn
		{add_view "smg_gilz" "shell" "FXshell"}
		{add_view "flash_gun_small" "flashbarrel" "foresight3"}
		{add_view "we_smoke" "smoke_or" "foresight3"}
		{if operatable {ani_wind "down" end}
		else {ani_wind "down" begin}}
	}
	{on operatable on
		{ani_play "down" 1}
	}
	{on operatable off
		{ani_play "down" -1}
	}
	{on fire "pistol"
		{view show	"flashbarrel"}
		{view start	"flashbarrel"}
		{view show	"smoke_or"}
		{view start	"smoke_or"}
		{view show	"shell"}
		{view start	"shell"}
		{kill_delay "fire"}
		{kill_delay "shells_we"}
		{delay 0.2 "shells_we"
			{view pause	"shells_we"}
			{view pause	"shell"}
		}
		{delay 0.45 "fire"
			{view hide	"flashbarrel"}
			{view pause	"flashbarrel"}
			{view pause	"smoke_or"}
			{view hide	"smoke_or"}
			{view pause	"flashbarrell"}
		}

	
	}

}
{"2start"
	{on spawn {tags remove "already_fired"}{tags remove "2start_off"}{call "update_weaponry"}}
	{on fire "gun2"
	 {if not tagged "already_fired"
	  {tags add "already_fired"}
	  {if tagged "2start_off"
		  {weapon_work "gun2" 0}
		  {delay 1 {weapon_work "gun2" 0}}
		  {delay 10 {call "update_weaponry"}}
	  }
	  {delay 3 
		  {tags remove "already_fired"}
	  }
	  else
	  {tags remove "already_fired"}
	  {weapon_work "gun2" 0}
	  {delay 6 {call "update_weaponry"}}
	 }
	}
	{on "single_launch"
	  {tags remove "already_fired"}
	  {weapon_work "gun2" 0}
	  {delay 6 {call "update_weaponry"}}

	}
	{on "smokescreen" overload
		{call "cwsh_switch_hatch"}
	}
	{on "cwsh_switch_hatch" overload
			{if tagged "2start_off"
				{components "zpu_indicator" repair}
				{tags remove "2start_off"}
				{damage_report "body" "salvo_launch"}
			else
				{tags add "2start_off"}
				{components "zpu_indicator" break}
				{damage_report "body" "single_launch"}
				{if tagged "already_fired"
				  {tags remove "already_fired"}
				  {weapon_work "gun2" 0}
				  {delay 1 {weapon_work "gun2" 0}}
				  {delay 6 {call "update_weaponry"}}
				}
			}
	}
}