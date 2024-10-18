{"human"
	(include "flamer.inc")
	{inflammation_time 0.25}
	{on spawn
		{add_view	"cigarettesmoke"		"smoke"		"head"}
		{add_view	"drops_water_small2"	"on_water"	"foot3r"}
		{add_view	"drops_water_small2"	"on_water"	"foot3l"}
		{add_view	"drops_water_small3"	"swim"		"foot3r"}
		{add_view	"drops_water_small3"	"swim"		"foot3l"}
		{add_view	"drops_water_small3"	"swim"		"hand2r"}
		{add_view	"drops_water_small3"	"swim"		"hand2l"}
		{add_view	"wash_human_small"		"swim_move"	"head"}
		{add_view	"drops_puddle_small"	"on_puddle"	"foot3r"}
		{add_view	"drops_puddle_small"	"on_puddle"	"foot3l"}
		{add_view	"drops_puddle_small"	"die_in_swamp"	"foot3r"}
		{add_view	"drops_puddle_small"	"die_in_swamp"	"foot3l"}
		
		;deleted in AS 2_05 
		{add_view	"healing" 				"healing" "head"}
		{add_view	"attention" 				"attention" "head"}

		;added in AS 2_05 
		{add_view	"marker_healing" 		"marker_healing" "head"}
		{add_view	"marker_repair" 		"marker_repair" "head"}
		{add_view	"marker_ammo_out" 		"marker_ammo_out" "head"}
		{add_view	"marker_ammo_refill" 	"marker_ammo_refill" "head"}
		{add_view	"marker_personage" 		"marker_personage" "head"}
;		{add_view	"marker_personage_acute""marker_personage_acute" "head"}
		{add_view	"marker_veterancy" 		"marker_veterancy" "head"}
		
		{add_view	"shield" 		"shield" "head"}
		{add_view	"broken_shield" 		"broken_shield" "head"}
		
		{link_sound "move_ground" "human/move/ground"}
		{link_sound "move_road"   "human/move/road"}
		{link_sound "move_sand"   "human/move/sand"}
		{link_sound "move_snow"   "human/move/snow"}
		{link_sound "move_grass"  "human/move/grass"}
		{link_sound "door_in"			"vehicle/other/door_in"}
		{link_sound "door_out"			"vehicle/other/door_out"}
		{link_sound "hatch_in"			"vehicle/other/hatch_in"}
		{link_sound "hatch_out"			"vehicle/other/hatch_out"}

		{link_sound "swim" "human/move/swim"}
		{link_sound "repair" "vehicle/repair"}
		{link_sound "barricade" "fortification/install/human_sandbags_install"}
		{link_sound "barbwire" "fortification/install/barber_wire_install"}
		{link_sound "camouflage" "fortification/install/camouflage_bushes_install"}
		{link_sound "mine" "weapon/mining"}
		{link_sound "hedgehog" "fortification/antitank_hedgehog_disassemble"}
		{link_sound "put_dynamite" "weapon/mine_activation"}
		{link_sound "detonation" "weapon/detonation_click"}
		{link_sound "knife_stub" "weapon/melee/knife_stub"}
		{link_sound "shovel_stub" "weapon/melee/shovel_stub"}
		{link_sound "mine_detected" "weapon/demining"}
;		{link_sound "pose_changed" "human/pose_change"}
;		{link_sound "heal" "human/healing"}
		{link_sound "cut_wire" "human/barber_wire_cut"}
		{link_sound "burn" "detonation/matches_install"}
;		{link_sound "trench" "fortification/build/trench_digging"}
		
		{link_sound "pour" "vehicle/refueling"}
		
		{if able "burning"
			{call "add_burn_fx"}
			{view start "burn_fire"}
		}
		{call "start_update_lights"}
		{if tagged "cw_face1"	;face loading
			{bone show "head1"} {bone hide "head2"} {bone hide "head3"} {bone hide "head4"}
			{bone hide "head5"} {bone hide "head6"} {bone hide "head7"} {bone hide "head8"} 
		else  tagged "cw_face2"
			{bone hide "head1"} {bone show "head2"} {bone hide "head3"} {bone hide "head4"}
			{bone hide "head5"} {bone hide "head6"} {bone hide "head7"} {bone hide "head8"} 
		else  tagged "cw_face3"
			{bone hide "head1"} {bone hide "head2"} {bone show "head3"} {bone hide "head4"}
			{bone hide "head5"} {bone hide "head6"} {bone hide "head7"} {bone hide "head8"} 
		else  tagged "cw_face4"
			{bone hide "head1"} {bone hide "head2"} {bone hide "head3"} {bone show "head4"}
			{bone hide "head5"} {bone hide "head6"} {bone hide "head7"} {bone hide "head8"} 
		else  tagged "cw_face5"
			{bone hide "head1"} {bone hide "head2"} {bone hide "head3"} {bone hide "head4"}
			{bone show "head5"} {bone hide "head6"} {bone hide "head7"} {bone hide "head8"} 
		else  tagged "cw_face6"
			{bone hide "head1"} {bone hide "head2"} {bone hide "head3"} {bone hide "head4"}
			{bone hide "head5"} {bone show "head6"} {bone hide "head7"} {bone hide "head8"} 
		else  tagged "cw_face7"
			{bone hide "head1"} {bone hide "head2"} {bone hide "head3"} {bone hide "head4"}
			{bone hide "head5"} {bone hide "head6"} {bone show "head7"} {bone hide "head8"} 
		else  tagged "cw_face8"
			{bone hide "head1"} {bone hide "head2"} {bone hide "head3"} {bone hide "head4"}
			{bone hide "head5"} {bone hide "head6"} {bone hide "head7"} {bone show "head8"} 
		else	;random face select
			{if rand 0.125
				{bone show "head1"} {bone hide "head2"} {bone hide "head3"} {bone hide "head4"}
				{bone hide "head5"} {bone hide "head6"} {bone hide "head7"} {bone hide "head8"} 
				{tags add "cw_face1"}
			else  rand 0.143
				{bone hide "head1"} {bone show "head2"} {bone hide "head3"} {bone hide "head4"}
				{bone hide "head5"} {bone hide "head6"} {bone hide "head7"} {bone hide "head8"} 
				{tags add "cw_face2"}
			else  rand 0.167
				{bone hide "head1"} {bone hide "head2"} {bone show "head3"} {bone hide "head4"}
				{bone hide "head5"} {bone hide "head6"} {bone hide "head7"} {bone hide "head8"} 
				{tags add "cw_face3"}
			else  rand 0.2
				{bone hide "head1"} {bone hide "head2"} {bone hide "head3"} {bone show "head4"}
				{bone hide "head5"} {bone hide "head6"} {bone hide "head7"} {bone hide "head8"} 
				{tags add "cw_face4"}
			else  rand 0.25
				{bone hide "head1"} {bone hide "head2"} {bone hide "head3"} {bone hide "head4"}
				{bone show "head5"} {bone hide "head6"} {bone hide "head7"} {bone hide "head8"} 
				{tags add "cw_face5"}
			else  rand 0.33
				{bone hide "head1"} {bone hide "head2"} {bone hide "head3"} {bone hide "head4"}
				{bone hide "head5"} {bone show "head6"} {bone hide "head7"} {bone hide "head8"} 
				{tags add "cw_face6"}
			else  rand 0.5
				{bone hide "head1"} {bone hide "head2"} {bone hide "head3"} {bone hide "head4"}
				{bone hide "head5"} {bone hide "head6"} {bone show "head7"} {bone hide "head8"} 
				{tags add "cw_face7"}
			else
				{bone hide "head1"} {bone hide "head2"} {bone hide "head3"} {bone hide "head4"}
				{bone hide "head5"} {bone hide "head6"} {bone hide "head7"} {bone show "head8"} 
				{tags add "cw_face8"}
			}
		}
	    {tags remove "bleeding"}
		{volumes "body_c" enable bullet}
		{call "talk_scanner"}
	}
	(define "health_damage"
		{health_damage_count %c
			{effects "" "hit" "damage" "die" "die"}
		}
	)
	(define "bleed_damage"
	  {if not dead
	   {if tagged "bleeding" and not withdrawn_recovering
		{health_damage_count %c
			{effects "" "hit" "damage" "die" "die"}
		}	  
	   }
	   else {tags remove "bleeding"} 
	  }

	)
	(define "bleed"
	  {if not stuff "nobleed"
	   {if not impregnable
		{if rand (* 0.5 %bleed_big)
			{call "bleed_big"}
		else rand %bleed_med
			{call "bleed_med"}
		else rand %bleed_small
			{call "bleed_small"}
		}
	   }
	  }
	)
	{on "bleed_big"
		{tags add "bleeding"}
		{delay 5 {if tagged "bleeding" {if not dead  ("bleed_damage" c(16))
			{delay 10 {if tagged "bleeding" ("bleed_damage" c(16))
				{if not linked {delay 5 {if tagged "bleeding" ("bleed_damage" c(16))
					{delay 5 {if tagged "bleeding" ("bleed_damage" c(16))
						{delay 5 {if tagged "bleeding" ("bleed_damage" c(16))
							{delay 5 {if tagged "bleeding" ("bleed_damage" c(0))
								{delay 1 {if tagged "bleeding"
									{tags remove "bleeding"} 
								}}
							}}
						}}
					}}
				}}}
			}}
		}}}
	}
	{on "bleed_med"
		{tags add "bleeding"}
		{delay 5 {if tagged "bleeding" {if not dead  ("bleed_damage" c(8))
			{delay 5 {if tagged "bleeding" ("bleed_damage" c(8))
				{delay 5 {if tagged "bleeding" ("bleed_damage" c(8))
					{delay 5 {if tagged "bleeding" ("bleed_damage" c(8))
						{delay 5 {if tagged "bleeding" ("bleed_damage" c(8))
							{delay 5 {if tagged "bleeding" ("bleed_damage" c(0))
								{delay 1 {if tagged "bleeding"
									{tags remove "bleeding"} 
								}}
							}}
						}}
					}}
				}}
			}}
		}}}
	}
	{on "bleed_small"
		{tags add "bleeding"}
		{delay 5 {if tagged "bleeding" {if not dead  ("bleed_damage" c(4))
			{delay 5 {if tagged "bleeding" ("bleed_damage" c(4))
				{delay 5 {if tagged "bleeding" ("bleed_damage" c(4))
					{delay 5 {if tagged "bleeding" ("bleed_damage" c(4))
						{delay 5 {if tagged "bleeding" ("bleed_damage" c(4))
							{delay 5 {if tagged "bleeding" ("bleed_damage" c(0))
								{delay 1 {if tagged "bleeding"
									{tags remove "bleeding"} 
								}}
							}}
						}}
					}}
				}}
			}}
		}}}
	}
	
	
	
	{on "cannot_move_low_morale"
		{talk "drop_morale"}
	}
	{on "talk_scanner"
		{##if ai_squad
			{if morale 0 30
				{delay 4 3 "drop_morale"
					{talk "drop_morale" {audience all}}
					;{con "--==============DROP MORALE--"}
				}
			}
		}
		{if attacking_weapon "rocketlauncher"
			{talk "shot_from_a_bazooka" {audience all}}			
		}		
		{if attacking_weapon "sniper"
			{talk "shot_from_a_sniper_rifle" {audience all}}
			{con "--==============Sniper shot--"}			
		}
;		{if fsm_tags "throw" and item_in_hand "grenade"
;			{talk "throwing_a_grenade" {audience all}}			
;		}		
		{if health_percent 0.2 and attacked
			{talk "drop_morale" {audience all}}				
		}		
		{if suppressed 2 and attacked
			{talk "things_look_blue" {audience all}}			
		}		
		{if attacking_weapon or attacked
			{talk "in_action" {audience all}}		
		}				
		{delay 5 "talk_scanner"
			{call "talk_scanner"}
		}
	}
	{on "talk_scanner_off"
		{kill_delay "drop_morale"}
		{kill_delay "talk_scanner"}
	}
	{on "throw_off_by_collision_with_vehicle_die"
		{if terrain_fx "water" or terrain_fx "shallow_water"
			{spawn "bloodsparks_drops_water" "body"}
		else
			{spawn "bloodsparks_drops" "body"}
		}
		{throw_off up 1.3 0.5 dir 5.5 2 force die}
	}
	{on contact
		{if not impregnable
			{kill_flags reset}
			{volumes disable contact}
			{delay 2
				{volumes enable contact}
			}
			{if effector "tank"
				{if not user_control
					{health_damage_crush "die" "crush"}
				else
						{health_damage_crush "die" "crush"}
				else
					{call "knock_down"}
				}
			else effector "vehicle"
				{if not dead
					{if not user_control
						{call "die"}
					(mod "mp"
					 else
					        {call "die"}
					)
					}
				else
					{spawn "bloodsparks_small"}
				}
			else effector "aoe_heal_med"
				{if health_percent 0.5
					{health_damage_count -25
						{effects "" "" "" "" ""}
					}
					{spawn "test_fx" "basis"}
				else health_percent 0.8
					{health_damage_count -10
						{effects "" "" "" "" ""}
					}
				else
				}
			else effector "knife"

				{if volume "body"
				  {if not volume_armored
					{if contact_velocity 5
						{health_damage_count 500
							{effects "" "hit" "damage" "die_from_knife" "die_from_knife"}
						}
					}
				   }
				 else volume "head"
				  {if not volume_armored
					{if contact_velocity 5
						{health_damage_count 500
							{effects "" "hit" "damage" "die_from_knife" "die_from_knife"}
						}
					}
				   else
				     {if rand 0.5
						{if contact_velocity 5
							{health_damage_count 500
								{effects "" "hit" "damage" "die_from_knife" "die_from_knife"}
							}
						}
					 }
				   }
				 else
				 	{if contact_velocity 5
						{health_damage_count 100
							{effects "" "hit" "damage" "die_from_knife" "die_from_knife"}
						}
					}
				}
			(define "contact_part"
			else effector %e
				{if contact_velocity %v
						("health_damage" c(%d))
				}

  	        )
			("contact_part" e("building_part")	v(3)	ud(20)	d(120))
			("contact_part" e("big part")		v(3)	ud(20)	d(120))
			("contact_part" e("medium part")	v(6)	ud(10)	d(100))
			("contact_part" e("small part")		v(10)	ud(3)	d(40))
			("contact_part" e("part")			v(10)	ud(3)	d(100))
			else effector "chicken"
				{health_damage_count 0
					{effects "" "hit" "hit" "hit" "hit"}
				}
			else effector "wire"
				{health_damage_count 20
					{effects "" "hit" "damage" "die" "die"}
				}
			else effector "flame_piece"
				{health_damage_count 15
					{effects "" "hit" "hit" "die" "die"}
				}
			else effector "fx_piece_flame"
				{health_damage_count 201
					{effects "" "hit" "hit" "die" "die"}
				}
				{able "burning" 1}
            	{able select 0}	
            	{call "add_burn_fx"}
                {view start "burn_fire"}
            	{delay 3
            	    {able "burning" 0}
            	    {able select 1}	
                    {view stop "burn_fire"}
            	}	
			}
		}
	}
	(define "spawn_bloodsparks"
		{if linked_root "house"
			{if rand 0.08 {spawn %n}}
		else
			{spawn %n}
		}
	)
(define "bullet_damage"
					{health_damage_pierce
						{effects	"hit-scream"
								"hit-light" "hit-heavy"
								"die" "hit-explosion"
								"throw-off" "throw-off-and-die"
						}
						{explosive_treshold 70}
						{table {30 1} {200 2.5} {500 3} {5000 5}}
					}
)
(define "kill_flags"
		{if hit_side front	{kill_flags front}
		else hit_side back	{kill_flags back}
		else				{kill_flags front back}
		}
		{if velocity 7		{kill_flags run}
		else velocity 0.1	{kill_flags go}
		}
		{kill_flags piercing}
;		{if	stuff "rifle"	{kill_flags rifle}}		;Эти флаги отключены в MOW2, но другие нет
;		{if	stuff "mgun"	{kill_flags mgun}}	;Эти флаги отключены в MOW2, но другие нет
;		{if	stuff "smg"	{kill_flags smg}}	;Эти флаги отключены в MOW2, но другие нет
;		{if	stuff "pistol"	{kill_flags pistol}}	;Эти флаги отключены в MOW2, но другие нет
)
	
	{on bullet_hit
		{if stuff "laser_ammo"
		else stuff "radar_ammo"
		else stuff "IR_ff_ammo"
		else stuff "proj_pointer"
		else
			{kill_flags reset}
			{spawn "bloodsparks_small"}		; to generate hit signal
		}
		{if stuff "hesh_type_dmg" {spawn "cw_cumulative_frestrict" inv_normal}
		else stuff "cm_type_dmg cm" {spawn "rpg_restrictor" inv_normal}}
		{if stuff "laser_ammo"
		else stuff "radar_ammo"
		else stuff "proj_pointer"
		else stuff "shell"
			{if stuff "shell fg" or stuff "shell fr"
				{bullet_detonate}
				{kill_flags reset}
				{call "process_bullet_hit"}
				{spawn "bloodsparks_big"}
			else stuff "autocannon_small"
				{kill_flags reset}
				{call "process_bullet_hit"}
				{call "die_with_blood"}
				{spawn "bloodsparks_big"}
			else stuff "shell apcr"
				{kill_flags reset}
				{call "process_bullet_hit"}
				{call "die_with_blood"}
				{spawn "bloodsparks_big"}
			else stuff "shell apcr_h"
				{kill_flags reset}
				{call "process_bullet_hit"}
				{call "die_with_blood"}
				{spawn "bloodsparks_big"}
			else stuff "shell ap"
				{kill_flags reset}
				{call "process_bullet_hit"}
				{call "hit-explosion"}
				{spawn "bloodsparks_big"}
			}
		else stuff "mgun" and relation "enemy"
			{kill_flags reset}
			{call "process_bullet_hit"}
		else stuff "mgun" and relation "ally"
			{kill_flags reset}
			{call "process_bullet_hit"}
			{with_effector
				{if manual_control
					{with_effector {kill_flags reset} {call "process_bullet_hit"}}
				}
			}		
		else stuff "20mm"
			{kill_flags reset}
			{call "process_bullet_hit"}
			{spawn "bloodsparks_big"}
		else stuff "bazooka"
			{bullet_detonate}
			{call "process_bullet_hit"}
		else stuff "full_shock"
			{if stuff "tazzer" {die}}
			{if dead
				{tags add "melee_hit"}
			else
				{tags add "melee_hit_temp"}
				{delay 5 {tags remove "melee_hit_temp"}}
			}
			{bullet_detonate}
			("kill_flags")
			("bullet_damage")
;			{call "process_bullet_hit"}
		else stuff "bullet" and relation "enemy"
			{if volume_armored
				{bullet_detonate}
			}
;			{spawn "hit_blood"}
			{call "process_bullet_hit"}
		else stuff "bullet" and relation "ally"
			{if volume_armored
				{bullet_detonate}
			}
			{with_effector
				{if manual_control
					{with_effector {call "process_bullet_hit"}}
				}
			}	
		else stuff "flaergun strike"
			("health_damage" c(5))
	        ("grenade_signal")			
		else stuff "smoke_gr"
			("health_damage" c(5))
			("grenade_smoke")				
		else
			{call "process_bullet_hit"}
		}
	}
	{on blow
		{if not name "knife"
			{start_sound "human/blow"}
		}
	}
	{on blow opponent
		{if name "knife"
			{health_damage_blow
				{effects "" "hit" "hit" "die_from_knife" "die_from_knife"}
			}
		else
			{if name "head"
				{spawn "bloodsparks_small" "head"}
			}
			{health_damage_blow
				{effects "" "hit" "hit" "die" "die"}
			}
			{if dead
				{tags add "melee_hit"}
			else
				{tags add "melee_hit_temp"}
				{delay 5 {tags remove "melee_hit_temp"}}
			}
		}
	}

	{on "hit_in_leg"
		{if stuff "shell" {die} 
		else stuff "mgun" 
			("health_damage" c(0)) 
			("bullet_damage")
		else stuff "hmgun" {die}{spawn "bloodsparks_big"}
		else stuff "zenite" {die} 
		else stuff "bullet" 
			("health_damage" c(0))
			("bullet_damage")
		}
	}
	{on pierce
		;double damage when critical organs hit
		{if volume "crit"
			;("bullet_damage")
			("bleed" bleed_big(0.33) bleed_med(0.2) bleed_small(0.2))
		}
	}
	{on "blow_in_house"
		{start_sound "human/blow"}
	}
	{on "blow_in_house_opponent"
		{if name "head"
			{spawn "bloodsparks_small" "head"}
		}
	}
	{on "auto_withdraw_reason"
		{if breed_mask "*/*miner*" "*/*antipersonel_miner*" "*/*antitank_miner*" "*/engineer" "*/corpsman"
			{if auto_withdraw_reason "damage_any" or auto_withdraw_reason "damage_percent" and health_percent 0.7
				{withdraw}
			}
		}
	}
	{on "process_bullet_hit"
		{if hit_side front	{kill_flags front}
		else hit_side back	{kill_flags back}
		else				{kill_flags front back}
		}
		{if velocity 7		{kill_flags run}
		else velocity 0.1	{kill_flags go}
		}
		{tags remove "melee_hit"}
		("kill_flags")
;====================Part of damage system by Svoyak, edit by Pheonix===========================
		{if volume "foot1r" {call "hit_in_leg"} ("bleed" bleed_big(0.66) bleed_med(0.10) bleed_small(0.13))
		else volume "foot2r" {call "hit_in_leg"} ("bleed" bleed_big(0.05) bleed_med(0.66) bleed_small(0.2))
		else volume "foot1l" {call "hit_in_leg"} ("bleed" bleed_big(0.66) bleed_med(0.10) bleed_small(0.13))
		else volume "foot2l" {call "hit_in_leg"} ("bleed" bleed_big(0.05) bleed_med(0.66) bleed_small(0.2))
		else volume "body"
			{if stuff "hmgun" {die}{spawn "bloodsparks_big"}
			else
				("bullet_damage")
				("bullet_damage")
				("bleed" bleed_big(0.10) bleed_med(0.13) bleed_small(0.2))
			}
		else  volume "head"
		    {if not impregnable			
				{if stuff "hmgun" {die}{spawn "bloodsparks_big" "head"}
				else stuff "sniper" 
					{die}{spawn "bloodsparks_big" "head"}
				else stuff "mgun" {if not volume_armored {die}{spawn "bloodsparks_big" "head"}}
				else stuff "smg" {if not volume_armored {die}{spawn "bloodsparks_big" "head"}}
				}
			}
			;("bleed" bleed_big(0.15) bleed_med(0.15) bleed_small(0.15))
			("bullet_damage")
			("bullet_damage")
			("bullet_damage")
				
		}
		{icon_event "human_damage" 2.0}
		{if selected
			{with_effector
				{icon_event "damage_current_user" 2.0}
			}
		}
		{call "auto_withdraw_reason"}

	}
	{on "health_damage_blast"
       	 {if min_energy 2.5
            		{health_damage_crush "die" "crush"}
      	  }
		  {if not volume_armored
		  {if min_energy 0.5
            		("bleed" bleed_big(0.0) bleed_med(0.0) bleed_small(0.66))
      	  }
		  {if min_energy 1.0
            		("bleed" bleed_big(0.0) bleed_med(0.66) bleed_small(0.0))
      	  }
		  }
		{kill_flags reset}
		{if hit_side front	{kill_flags front}
			else hit_side back	{kill_flags back}
			else				{kill_flags front back}
	    }
		{kill_flags blast}
		{icon_event "human_damage" 2.0}
		{if can_be_damaged and not linked
			{if stuff "mine antipersonnel" or stuff "mine antitank"
				{talk "human_mines" {audience ally}}
			else stuff "dynamite"
				{talk "explosives" {audience ally}}
				;{self_damage}
			}
		}
		{call "auto_withdraw_reason"}
		{if volume "head"
			{if volume_armored
				{if min_energy 0.1
					{health_damage_blast
						{effects	"hit-scream"
									"hit-light" "hit-heavy"
									"die" "hit-explosion"
									"throw-off" "throw-off-and-die"
						}
;						{table {0.5 0.5} {2 2.6} {10 4} {50 6}}
						{table {0.5 0.25} {2 0.4} {10 1} {50 2}}
					}
				else
					{health_damage_blast
						{effects	"hit-scream"
									"hit-light" "hit-heavy"
									"die" "hit-explosion"
									"throw-off" "throw-off-and-die"
						}
;						{table {0.5 0.5} {2 2.6} {10 4} {50 6}}
						{table {0.5 0.25} {2 0.4} {10 1} {50 2}}
					}
					("bleed" bleed_big(0.10) bleed_med(0.10) bleed_small(0.10))
					else
					("health_damage" c(50)) 
					("bleed" bleed_big(0.10) bleed_med(0.10) bleed_small(0.10))						
				}
			else
				{health_damage_blast
					{effects	"hit-scream"
								"hit-light" "hit-heavy"
								"die" "hit-explosion"
								"throw-off" "throw-off-and-die"
					}
;						{table {0.5 0.5} {2 2.6} {10 4} {50 6}}
						{table {0.5 0.25} {2 0.4} {10 1} {50 2}}
				}
				("bleed" bleed_big(0.10) bleed_med(0.10) bleed_small(0.10))
			}
		
		else volume_armored
			{if min_energy 0.1
				{health_damage_blast
					{effects	"hit-scream"
								"hit-light" "hit-heavy"
								"die" "hit-explosion"
								"throw-off" "throw-off-and-die"
					}
;						{table {0.5 0.5} {2 2.6} {10 4} {50 6}}
						{table {0.5 0.25} {2 0.4} {10 1} {50 2}}
				}
				("bleed" bleed_big(0.10) bleed_med(0.10) bleed_small(0.10))
			}
		else
			{health_damage_blast
				{effects	"hit-scream"
							"hit-light" "hit-heavy"
							"die" "hit-explosion"
							"throw-off" "throw-off-and-die"
				}
;						{table {0.5 0.5} {2 2.6} {10 4} {50 6}}
						{table {0.5 0.25} {2 0.4} {10 1} {50 2}}
			}
			("bleed" bleed_big(0.10) bleed_med(0.10) bleed_small(0.10))
		}
;		{throw_off dir 1} ;disabling this prevents from throwing off crew from armoured cars
	}
	{on blast_hit
		{call "health_damage_blast"}
	}
	{on fragments_hit overload
		{call "health_damage_blast"}
	}
	
	{on "die_throw_high"
		{set "die_after_throw" 1}
		{spawn "bloodsparks_small"}
		{call "die_scream"}
		{call "throw_high"}
	}
	
	{on "hit-scream"
		{if not flag "talk"
			{set "talk" 1}
			{talk "injuring" {audience all} {ambient_for_selection 0}}
			{delay 10 2
				{set "talk" 0}
			}
		}
	}
	
	{on "talk_in_action"
		{if not flag "talk"
			{set "talk" 1}
			{talk "in_action" {audience all} {ambient_for_selection 0}}
			{delay 10 2
				{set "talk" 0}
			}
		}
	}	

	{on "hit-light"
		("spawn_bloodsparks" n("bloodsparks_small"))
	}
	
	{on "hit-heavy"
		{spawn "bloodsparks_big"}
	}
	{on "hit-explosion"
		{if tagged "no_explosion"
			{call "die"}
		else
			{call "die_scream"}
			{if stuff "bullet"
				;ничего трупу от пуль
			else 
				{call "explosion"}

			}
		}
	}
	{on "throw-off"
		{set "die_after_throw" 0}
		{if not in_fortification "trench" and not ammo "not_throw"
			{call "throw_high"}
		}
	}
	{on "throw-off-and-die"
		{set "die_after_throw" 1}
		{call "die_scream"}
		{call "throw_high"}
		{if weapon "sniper"
			{icon_event "killed_by_sniper" 2.0}
			{talk_nearest_ally "killed_by_sniper" 40}
		}
	}
	
	{on "hit"
		{call "hit-scream"}
	}
	{on "damage"
		{spawn "bloodsparks_small"}
		{call "hit"}
	}

	{on "throw_high"
		{if senseless
			{if not dead
				{if not user_control
					{call "die"}
				else flag "die_after_throw"
					{call "die"}
				}
			}
		else
			{if not dead
				{if linked "vehicle"
					{if flag "die_after_throw"
						{throw_off up 1.3 0.5 dir 5.5 2 forward 4 turn 0 360 die force}
					else
						{throw_off up 1.3 0.5 dir 5.5 2 forward 4 turn 0 360 force}
					}
				else
					{if flag "die_after_throw"
						{throw_off up 4 0.8 dir 3.5 0.5 forward 0 0 die}
					else
						{throw_off up 4 0.8 dir 3.5 0.5 forward 0 0}
					}
				}
			else
				{if stuff "bullet"
					;ничего трупу от пуль
				else 
					{call "explosion"}
				}
			}
		}
	}
	{on "throw_off_end"
		{if not user_control
			{health_damage_count 50 
				{effects "" "hit" "damage" "die" "die"}
			}
		}
		{call "knock_down"}
	}
	{on "throw_off_end_stumble"
		{call "stumble"}
	}
	{on "throw_off_end_die"
		{call "die"}
	}
	{on "throw_off_from_tower"
		{throw_off up 1 forward 2 die force}
	}
	{on "throw_off_from_ladder"
		{throw_off up 1 forward -2 die force}
	}
	{on "throw_off_from_ship"
		{throw_off up 4 dir 3 1 die force}
	}
	{on "throw_off_from_vehicle"
		{if user_control
			{throw_off up 1.3 0.5 dir 5.5 2 forward 4 turn 0 360 force}
		else
			{throw_off up 1.3 0.5 dir 5 1 forward 4 turn 0 360 rnd_die 0.7 force}
		}
	}
	{on "throw_off_from_vehicle_die"
		{if user_control
			{throw_off up 1.3 0.5 dir 5.5 2 forward 4 turn 0 360 die force}
		else
			{throw_off up 1.3 0.5 dir 5 1 forward 4 turn 0 360 die force}
		}
	}
	{on "throw_off_from_house_die"
		{throw_off up 1.3 0.5 dir 5 1 forward 1 turn 0 60 die force}
	}
	{on "linker_simulation"
		{if effector "airborne"
		 else effector "cannon"
;			{throw_off up 2.25 0.75 forward 2.25 0.75 turn 0 360 force}
		 else altitude 3
			{throw_off up 1 forward 2 die force}
		}
	}

	{on "knock_down"
		{if not water_level -0.1
			{knockdown 8 3}
		}
	}
	{on "stumble"
		{if not water_level -0.1
			{knockdown 0.5 0}
		}
	}
	{on "die"
		{if linked_root "house"
			{reserve_structure_place 5}
		}
		{if weapon "sniper"
			{icon_event "killed_by_sniper" 2.0}
		}
		{hide_gunners 1.5}
		{if not dead
			{spawn "bloodsparks_small"}
			{delay 1.2 0.2	
				{if terrain_fx "water" or terrain_fx "shallow_water"
					{spawn "bloodsparks_drops_water" "body"}
				else
					{spawn "bloodsparks_drops" "body"}
				}
			}
			{if linked
				{if linked "shipflak"
					{call "throw_off_from_ship"}
				else linked "doublecolt"
					{call "throw_off_from_ship"}
				else linked "car"
					{if place "driver"
						{throw_off up 1.6 forward 2 turn -90 die force rotate_to_dir}
					else place "commander"
						{throw_off up 1.6 forward 2 turn +90 die force rotate_to_dir}
					else
						{call "die_with_blood"}
					}
				else altitude 2
					{if boarding
						{call "throw_off_from_ladder"}
					else
						{call "throw_off_from_tower"}
					}
				else linked "cannon"
					{call "die_with_blood"}
				else linked "airborne"
					{call "throw_off_from_ship"}
				else linked "vehicle"
					{call "throw_off_from_vehicle"}
				else linked "trench"
					{if cover_type "snipe_cover"
						; we have special die animations
						{call "die_with_blood"} 
					else
						{call "throw_off_from_vehicle_die"}
					}
				else linked_root "house"
					{call "throw_off_from_house_die"}
				else
					{call "die_with_blood"}
				}
			else
				{call "die_with_blood"}
			}
		}
		{drop_item "mine_fuze"}
	}
	{on "die_with_blood"
		{if not senseless
			{spawn "blood"}
		}
;		{if tex_mod "1" {tex_morph "dead_1" 3}
;		else tex_mod "2" {tex_morph "dead_2" 3}
;		else tex_mod "3" {tex_morph "dead_2" 3}
;		else tex_mod "gorka" {tex_morph "dead_gorka" 3}
;		else tex_mod "cifra" {tex_morph "dead_cifra" 3}
;		else tex_mod "marpat" {tex_morph "dead_marpat" 3}
;		else tex_mod "multicam" {tex_morph "dead_multicam" 3}
;		else {tex_morph "dead" 3}
;		}
		{tex_morph "dead" 3}
		{call "die_without_blood"}
	}
	{on "die_without_blood"
;		{con "die"}
		{view pause "swim"}
		{view stop "light"}
		{view hide "light"}
		{view pause "light"}
		{call "die_scream"}
		{if not kill_flags blast
			{kill_flags piercing}
		}
		{die}
;		{able collect 1}
		{delay 3
			{volumes enable contact}
		}
;		{delay 30 {delete}}
	}
	{on "die_scream"
		{if not flag "die_sound"
			{set "die_sound" 1}
			{call "talk_scanner_off"}
			{talk "death_cry" {audience all} {ambient_for_selection 0}}
			{signal mandie 5}
;			{if flag "die_from_knife"
;				{start_sound "human/die/from_knife"}
;			else
;				{start_sound "human/die"}
;			}
		}
	}
	{on "die_from_knife"
		{set "die_from_knife" 1}
		{call "die"}
	}

;	{on "die_contused"
;		{able select 0}
;		{delay 2 0.5 "die_contused"
;			{if inactive
;				{call "die_contused"}
;			else
;				{call "die"}
;			}
;		}
;	}

	{on "sensible"
		{volumes enable bullet}
		{set "die_sound" 0}
	}

	{on ground_hit
		{spawn "blood"}
	}

	(define "piece_explosion"
		{spawn %0 %1
			{impulse	up 1 0.5 dir 8 4
						cx 0 12 cy 0 12
						fx 0 60 fy 0 60 fz 80 40
			}
		}
	)
	(define "piece_crush"
		{spawn %0 %1
			{impulse	up 0.1 0.1
						fx 0 7 fy 0 7 fz 0 7
			}
			{add_view "blood_tail01" "tail" "root"}
			{view start "tail"}
		}
	)
	(define "spawn_pieces"
		;head
		{if rand 0.75	(%0 args "#tete01" "head")}
		
		;torse
		{if rand 0.9	(%0 args "#torse01" "body")}
		
		;left hand
		{if rand 0.33	(%0 args "#bras01" "hand2l")
		else rand 0.5	(%0 args "#main01" "hand2l")}
		
		;right hand
		{if rand 0.33	(%0 args "#bras01" "hand2r")
		else rand 0.5	(%0 args "#main01" "hand2r")}
		
		;left foot
		{if rand 0.33	(%0 args "#membre01" "foot1l")
		else rand 0.5	(%0 args "#membre02" "foot2l")}
		
		;right foot
		{if rand 0.33	(%0 args "#membre01" "foot1r")
		else rand 0.5	(%0 args "#membre02" "foot2r")}
		
		;tripe
						(%0 args "#tripe01" "body")
						(%0 args "#tripe02" "body")
						(%0 args "#tripe03" "body")
						(%0 args "#tripe04" "body")
	)

	{on "explosion"
		{if personage
			{call "die"}
		else
			{spawn "bloodsparks_big"}
;			("spawn_pieces" args "piece_explosion")
			{call "delete"}
		}
	}
	{on "crush"
		{if personage
			{call "die"}
		else
			{spawn "bloodsparks_big"}
;			("spawn_pieces" args "piece_crush")
			("spawn_pieces" args "piece_crush")
			{call "delete"}
		}
	}
	{on "delete"
		{if not dead
			{stat_notify die}
		}
		{delete}
	}
	{on "burn_volume"
		{if volume "body"
			{call "_burn"}
		}
	}
	{on "get_off"
		{get_off}
	}
	{on "_burn"
		{if not burned
			{able "burning" 1}
			{able select 0}			
			(define "try_get_off"
				{delay %0 0.5
					{get_off}
				}
			)
			("try_get_off" args 1.0)
			("try_get_off" args 2.0)
			("try_get_off" args 3.0)
			("try_get_off" args 4.0)
			("try_get_off" args 5.0)
			{tex_morph "burned" 10}
			{call "add_burn_fx"}
			{view start "burn_fire"}
			{delay_effect 0.5 0.2 "burn_scream"}
			{delay 6 2 "burn_die"
				{able "burning" 0}
				{kill_flags reset}
				{kill_flags piercing}
				("health_damage" c(150))
				{if not dead
					{call "die"}
				}
				{view stop "burn_fire"}
				{if terrain_fx "puddle"
					{call "stop_burn"}
				else
					{add_view "smoke_dead_small1" "burn_fire_b" 	"body"}
					{add_view "smoke_dead_small1" "burn_fire_hl"	"hand1l"}
					{add_view "smoke_dead_small1" "burn_fire_hr"	"hand1r"}
					{add_view "smoke_dead_small1" "burn_fire_fl"	"foot2l"}
					{add_view "smoke_dead_small1" "burn_fire_fr"	"foot2r"}
					{view start "burn_fire_b"}
					{view start "burn_fire_hl"}
					{view start "burn_fire_hr"}
					{view start "burn_fire_fl"}
					{view start "burn_fire_fr"}
					{delay 7.5 1.5	{view stop "burn_fire_b"}}
					{delay 3.5 2.0	{view stop "burn_fire_hl"}}
					{delay 3.8 1.5	{view stop "burn_fire_hr"}}
					{delay 4.3 1.5	{view stop "burn_fire_fl"}}
					{delay 4.5 1.5	{view stop "burn_fire_fr"}}
				}
			}
			{burn time 17} ; total burn time
		}
	}
	{on "add_burn_fx"
		{add_view "smoke_dead_small" "burn_fire"	"body"}
		{add_view "smoke_dead_small" "burn_fire"	"hand1l"}
		{add_view "smoke_dead_small" "burn_fire"	"hand1r"}
;		{add_view "smoke_dead_small" "burn_fire"	"hand2l"}
;		{add_view "smoke_dead_small" "burn_fire"	"hand2r"}
		{add_view "smoke_dead_small" "burn_fire"	"foot2l"}
		{add_view "smoke_dead_small" "burn_fire"	"foot2r"}
	}
	{on "burn_scream"
		{if not dead
			{if not senseless
				{if not flag "quench"
					{talk "death_cry" {audience all} {ambient_for_selection 0}}
;					{start_sound "human/die" }
					{delay_effect 1.2 0.5 "burn_scream"}
				else
					{kill_delay "burn_die"}
					{view stop "burn_fire"}
					{set "quench" 0}
					{able "burning" 0}
				}
			}
		}
	}
	{on "smoke"
		{smoke}
	}
	{on "smoking"
;		{con "smoke start"}
		{view start "smoke"}
		{delay 0.3 0.1
			{view pause "smoke"}
;			{con "smoke end"}
		}
	}
	{on "reset_manual_control"
		{reset_manual_control}
	}
;-=-----------------
;WE_System by Pheonix
(include "we_system.inc")
;-------------------

	(define "terrain_fx_human"
		{on terrain_fx %0 enter
			{if not swimming
				{view start "on_%1"}
				{view start "on_%1_time_short"}
				{delay 0.1
					{view pause "on_%1_time_short"}
				}
			}
		}
		{on terrain_fx %0 leave
			{view pause "on_%1"}
		}
	)
	("terrain_fx_human" args "water" 			water)
	("terrain_fx_human" args "puddle"			puddle)
	("terrain_fx_human" args "shallow_water"	puddle)
	("terrain_fx_human" args "mud" 				mud)

	{on terrain_pp "swamp" enter
		{delay 0							; without delay will crash in Die()
			{call "die_without_blood"}
			{view start "die_in_swamp"}
			{delay 10
				{view stop "die_in_swamp"}
				{delete}
			}
		}
	}

	{on "diving"
		{delay 0.3
			{spawn "spherewater_big"}
		}
	}
	{on swim on
		{view pause "on_water"}
		{view start "swim"}
		{call "stop_burn"}
		{kill_delay "after_swim"}
	}
	{on swim off
		{delay 1.5 "after_swim"
			{view pause "swim"}
		}
	}
	{on "selection"
		{if breed_mask "*/artilleryman*" "*/tankman" "*/*miner*" "*/engineer" "*/corpsman" "*/sapper"
			{talk "selection_support"}
		else
			{talk "selection"}
		}
	}
	{on "executing_order_move"
		{if charge 
			{talk "attack"}
		else
			{talk "executing_order"}
		}
	}
	{on move on
		{if swimming
			{view start "swim_move"}
		}
		;{call "update_move_sounds"}
		{if flag "barricade_play_sound"		{call "barricade_stop_sound"}}
		{if flag "barbwire_play_sound"		{call "barbwire_stop_sound"}}
		{if flag "hedgehog_play_sound"		{call "hedgehog_stop_sound"}}
		{if flag "cut_wire_play_sound"		{call "cut_wire_stop_sound"}}
		{if flag "trench_play_sound"		{call "trench_stop_sound"}}
	}
;	(define "play_move_sound"
;		{if terrain_fx "road"
;			{start_sound "human/move/%0/road_%1"}
;		else terrain_fx "country_road"
;			{start_sound "human/move/%0/road_%1"}
;		else terrain_fx "ice"
;			{start_sound "human/move/%0/snow_%1"}
;		else terrain_fx "snow"
;			{start_sound "human/move/%0/snow_%1"}
;		else terrain_fx "sand"
;			{start_sound "human/move/%0/sand_%1"}
;		else terrain_fx "grass"
;			{start_sound "human/move/%0/grass_%1"}
;		else
;			{start_sound "human/move/%0/ground_%1"}
;		}
;	)
	
	
	
	{on "stop_move_sounds"
;		{stop_sound "move_road_start"}
;		{stop_sound "move_ground_start"}
;		{stop_sound "move_snow_start"}
;		{stop_sound "move_sand_start"}
;		{stop_sound "move_grass_start"}
		{stop_sound "move_road"}
		{stop_sound "move_ground"}
		{stop_sound "move_snow"}
		{stop_sound "move_sand"}
		{stop_sound "move_grass"}

		{stop_sound "swim"}
;		{set "radar_up" 0}	;instead of fast_move_mode
	}
	{on movement_mode_changed
		{call "stop_move_sounds"}
		{if name "fast"
			{if swimming
				{play_sound "swim" 1}
			else not lying
;				("play_move_sound" args fast start)
;				{set "radar_up" 1}

				{if terrain_fx "road"
;					{play_sound "move_road_start"}
					{play_sound "move_road" 1}
				else terrain_fx "country_road"
;					{play_sound "move_road_start"}
					{play_sound "move_road" 1}
				else terrain_fx "ice"
;					{play_sound "move_snow_start"}
					{play_sound "move_snow" 1}
				else terrain_fx "snow"
;					{play_sound "move_snow_start"}
					{play_sound "move_snow" 1}
				else terrain_fx "sand"
;					{play_sound "move_sand_start"}
					{play_sound "move_sand" 1}
				else terrain_fx "grass"
;					{play_sound "move_grass_start"}
					{play_sound "move_grass" 1}
				else
;					{play_sound "move_ground_start"}
					{play_sound "move_ground" 1}
				}
			}
		}
	}
;	(define "play_leg_sound"
;		{if flag "fast_move_mode"
;			("play_move_sound" args fast %0)
;		else lying
;			("play_move_sound" args lying %0)
;		else
;			("play_move_sound" args normal %0)
;		}
;	)
;
;	{on animation_event "leg_left"
;		("play_leg_sound" args left)
;	}
;	{on animation_event "leg_right"
;		("play_leg_sound" args right)
;	}

	{on move off
		{view pause "swim_move"}
		{call "stop_move_sounds"}
	}
	{on "stop_burn"
		{if burned
			{burn stop_retry}
			{set "quench" 1}
		}
	}
	{on "falldown" overload
		{if installing
			{throw_on_ground}
		else altitude 3
			{throw_off up 1 forward 0.01 die force}
		else altitude 1
			{throw_off up 1 forward 0.01 force}
		else       
			{throw_on_ground}
		}
	}
	{on "fortification_crush"
		{if effector "trench"
			{throw_off up 1 forward 0.01 die force}
		}
	}
	(define "sink_on_emit"
		{if effector "sink_on_%0"
			{if name "%0"
				{with_effector
					{if chassis "water"
						{components "hull_integrity" break}
					}
					{with_effector}
				}
			}
		}	
	)

	(define "check_crew_level"
		{on "check_level_%skill"
			{if ability {"%skill" master} {with_effector  
				{tags add "cwcs_master"} {tags remove "cwcs_expert"} {tags remove "cwcs_advanced"} {tags remove "cwcs_basic"} {tags remove "cwcs_none"}

			{with_effector}}
			else ability {"%skill" expert} {with_effector  
				{if not tagged "cwcs_master" {tags add "cwcs_expert"} {tags remove "cwcs_advanced"} {tags remove "cwcs_basic"} {tags remove "cwcs_none"}}
			{with_effector}}
			else ability {"%skill" advanced} {with_effector  
				{if not tagged "cwcs_master" and not tagged "cwcs_expert" {tags add "cwcs_advanced"} {tags remove "cwcs_basic"} {tags remove "cwcs_none"}}
			{with_effector}}
			else ability {"%skill" basic} {with_effector  
				{if not tagged "cwcs_master" and not tagged "cwcs_expert" and not tagged "cwcs_advanced" {tags add "cwcs_basic"} {tags remove "cwcs_none"}}
			{with_effector}}
			else ability {"%skill" none} {with_effector  
				{if not tagged "cwcs_master" and not tagged "cwcs_expert" and not tagged "cwcs_advanced" and not tagged "cwcs_basic" {tags add "cwcs_none"}}
			{with_effector}}
			}	
		}
	)
	("check_crew_level" skill(skill_tank))
	("check_crew_level" skill(skill_apc))
	("check_crew_level" skill(skill_car))
	("check_crew_level" skill(skill_stan))
	("check_crew_level" skill(skill_plane))
	{on board in
		{view pause "swim"}
		{if effector "no_hatch_sound"
		else effector "car"
			{play_sound "door_in"}
		else effector "tank"
			{play_sound "hatch_in"}
		}
		("sink_on_emit" args emit0)
		 ("sink_on_emit" args emit1)
		 ("sink_on_emit" args emit2)
		 ("sink_on_emit" args emit3)
		 ("sink_on_emit" args emit4)
		 ("sink_on_emit" args emit5)
		 ("sink_on_emit" args emit6)
		 ("sink_on_emit" args emit7)
		 ("sink_on_emit" args emit8)
		{if effector "sink_on_allemit"
			{with_effector
				{if chassis "water"
					{components "hull_integrity" break}
				}
				{with_effector}
			}
		}
		{with_effector
			{call "update_crew"} 
			{if tagged "no_minimap" {tags remove "no_minimap"}}
			{with_effector}
			
		}
;		{with_effector
;			{play_sound "hatch_in"} {with_effector}
;		}
	}
	{on board out
		{if effector "mtb_d3"
			{if name "emit1" "emit2" "emit3" "emit4"
				{delay 0.7
					{spawn "spherewater_big"}
				}
			}
		}
		{delay_effect 2 "repair_start_sound"}
		{if effector "no_hatch_sound"
		else effector  "car truck"
			{if name "emit1" "emit2" {play_sound "door_out"}}	;анализ эмита работает только при покидании машины, не при залезании
		else effector "car"
			{play_sound "door_out"}
		else effector "tank"
			{play_sound "hatch_out"}
		}
		("sink_on_emit" args emit0)
		 ("sink_on_emit" args emit1)
		 ("sink_on_emit" args emit2)
		 ("sink_on_emit" args emit3)
		 ("sink_on_emit" args emit4)
		 ("sink_on_emit" args emit5)
		 ("sink_on_emit" args emit6)
		 ("sink_on_emit" args emit7)
		 ("sink_on_emit" args emit8)
		{if effector "sink_on_allemit"
			{with_effector
				{if chassis "water"
					{components "hull_integrity" break}
				}
				{with_effector}
			}
		}
		{with_effector
			{call "update_crew"} {with_effector}
		}
;		{with_effector
;			{play_sound "hatch_out"} {with_effector}
;		}
		
		
;====================================
;Paradrop system by Timosh
	(include "/lists/aircraft.inc")

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
			{if not altitude 2
				{tags add "heli_paradrop%1"} {delay 5 {tags remove "heli_paradrop%1"}}
				{spawn "parachute_new"  "basis" x no_position
					{tags add "heli_parashute%1"} 
					{call "start_alt_%0"}
				}
			}
		)
		{if linked "able_paradrop"
			     {if altitude 40	("paradrop_crew_member_with_alt_" args 7)
			      else altitude 35	("paradrop_crew_member_with_alt_" args 6)
			      else altitude 30	("paradrop_crew_member_with_alt_" args 5)
			      else altitude 25	("paradrop_crew_member_with_alt_" args 4)
			      else altitude 20	("paradrop_crew_member_with_alt_" args 3)
			      else altitude 12	("paradrop_crew_member_with_alt_" args 2)
			      else altitude 8	("paradrop_crew_member_with_alt_" args 1)
			      else altitude 3
				   ("list_throw_off")
			      else
			      }
		}
;================================
	}

;deleted in AS 2_05
	{on "start_heal"
		{view start "healing"}
	}
	{on "stop_heal"
		{view pause "healing"}
	}

;added in AS 2_05. Should be useful, I think - if it will work without mission scripts.
	{on "start_healing"
		{tags remove "bleeding"}
		{view start  "marker_healing"}
		
	}
	{on "stop_healing"
		{view pause "marker_healing"}
	}
	{on "start_repair"
		{view start  "marker_repair"}
	}
	{on "capture"
		{tags add "capturer"}
	}
	{on "start_target"
		{view start "attention"}
	}
	{on "stop_target"
		{view pause "attention"}
	}
	{on "stop_repair"
		{view pause "marker_repair"}
	}
	{on "start_ammo_out"
		{view start  "marker_ammo_out"}
	}
	{on "stop_ammo_out"
		{view pause "marker_ammo_out"}
	}
	{on "fx_link"
		(define "spwn_link"
			{if rand 0.125
				{spawn "%name" local_offset -%range 0 0}
			else
				{if rand 0.1428
					{spawn "%name" local_offset %range 0 0}
				else
					{if rand 0.1666
						{spawn "%name" local_offset 0 -%range 0}
					else
						{if rand 0.2
							{spawn "%name" local_offset 0 %range 0}				
						else
							{if rand 0.25
								{spawn "%name" local_offset -%range -%range 0}
							else
								{if rand 0.33
									{spawn "%name" local_offset %range %range 0}
								else
									{if rand 0.5
										{spawn "%name" local_offset -%range %range 0}
									else
										{spawn "%name" local_offset %range -%range 0}
									}
								}
							}
						}
					}
				}
			}
		)
		(define "rnd_spwn_link"
				{if rand 0.33
					("spwn_link" name(%name) range(100))
				else
					{if rand 0.5
						("spwn_link" name(%name) range(200))
					else
						("spwn_link" name(%name) range(300))
					}
				}
		)
		("rnd_spwn_link" name(fx_link))
	}
	;{on "observed_by_enemy"
	;	{if spy and not breed_mask "*/scout*" "*/scout2*"
	;		{talk "observed_by_enemy"}
	;		{if territory_type "enemy" ; ????? ???????? ?? ????? ??????????
	;			{marker "enemy_in_the_rear" 5 enemy {chat_message "mp/game/user_guide/enemy_in_rear/desc"}} ; ???????? ?????? ?? ??????, ??????? ??? ?????? 3 ??????? ? ??????? ?? ?? ? ???
	;			{with_effector
	;				{call "enemy_observed"} ; ? ??????? ?????????
	;			}
	;		}
	;	}
	;}
	;{on "enemy_observed"
	;	{talk "human_enemy_observed" {audience ally}}
	;}
	{on "bullet_hit_obstacle"
		{talk "human_bullet_hit_obstacle"}
	}
	{on "add_tags_on_saboteurs" 	;for missions
		{if breed_mask "*/scout_mso_com"
			{tags add "saboteur"}
		else breed_mask "*/scout_mso_mgun"
			{tags add "saboteur_smg"}
		else breed_mask "*/scout_mso_sniper"
			{tags add "saboteur_sniper"}
		}
	}
	{on "start_ammo_refill"
		{view start  "marker_ammo_refill"}
		{delay 2.5
			{view pause "marker_ammo_refill"}
		}
	}
	{on "start_personage"
		{view pause "marker_personage_acute"}
		{view start  "marker_personage"}
	}
	{on "stop_personage"
		{view pause "marker_personage"}
		{view pause "marker_personage_acute"}
	}
	{on "start_personage_acute"
		{view pause "marker_personage"}
		
	}
	{on "start_veterancy"
		{view start  "marker_veterancy"}
		{delay 3.5
			{view pause "marker_veterancy"}
		}
	}
	{on "stop_veterancy"
		{view pause "marker_veterancy"}
	}
	{on "hide_veterancy"
		{view hide "marker_veterancy"}
	}
	{on "start_blinded"

;		{knockdown 8 3}

		{view start  "marker_blinded"}
	}
	{on "stop_blinded"
		{view pause "marker_blinded"}
	}
	{on "charge"
		{tags add "charge"}
	}
	{on "repair_next_sound"
		{if tagged "repairing"
			{delay 4 "repair_next_sound"
				{play_sound_in_channel "repair" "repair_ch"}
				{delay_effect 0 "repair_next_sound"}
			}
		else
			{kill_delay "repair_next_sound"}
		}
	}
	{on "repair_start_sound"
		{if tagged "repairing"
			{play_sound_in_channel "repair" "repair_ch"}
			{call "repair_next_sound"}
			{delay_effect 2 "repair_stop_sound"}
		}
	}
	{on "repair_stop_sound"
		{if not tagged "repairing"
			{kill_delay "repair_next_sound"}
			{stop_sound "repair" 0 0.1}
		else
			{delay_effect 0.5 "repair_stop_sound"}
		}
	}
	{on "put_dynamite_start_sound"
		{play_sound "put_dynamite"}
	}
	{on "detonation_start_sound"
		{play_sound "detonation"}
	}
	{on "mine_start_sound"
		{play_sound "mine"}
	}
	{on "mine_detected"
		{play_sound "mine_detected"}
	}
	{on "burn_start_sound"
		{play_sound "burn"}
	}
;	("action_play_sound" 				action(barricade)				delay_next_sound(1))			;{on "barricade...
;	("action_play_sound" 				action(barbwire) 				delay_next_sound(2.5 0.5))		;{on "barbwire...
;	("action_play_sound" 				action(hedgehog) 				delay_next_sound(2))			;{on "hedgehog...
;	("action_play_sound_and_check_stop" action(camouflage)				delay_next_sound(2))			;{on "camouflage...
;	;("action_play_sound" 				action(heal) 					delay_next_sound(2))			;{on "heal...(start_heal & stop_heal)
;	("action_play_sound" 				action(cut_wire) 				delay_next_sound(2))			;{on "cut_wire...
;	;("action_play_sound" 				action(trench) 					delay_next_sound(2))			;{on "trench...
	
;	("action_play_sound" 				action(pour)					delay_next_sound(5))			;{on "pour(_in|_out)...

}
{"armor_plate"
{inflammation_time 0.25}
	{on bullet_hit overload
		{if not under_water
			{if stuff "bullet"
;				{spawn "sand_hit_bul"}
			else {inherited}
			}
		}

		{if volume "armor_plate"
			{if stuff "hmgun"
				{volumes "soft_plate" disable blast}
				{blastwave c4 0.4 r0 0.4 r1 0.41}
				{delay 0.1 {volumes "soft_plate" enable blast}}
			else stuff "autocannon_small"
				{volumes "soft_plate" disable blast}
				{blastwave c4 0.6 r0 0.4 r1 0.41}
				{delay 0.1 {volumes "soft_plate" enable blast}}
			}
		}
	}
	{on pierce
		{call "armor_plate_pierce"}
		{if stuff "bullet"
		  {if not volume "soft_plate"
			{call "armor_plate_pierce"}
		  }
		}
	}
	{on "armor_plate_pierce"
		{if hit_side front
			{blastwave c4 0.1 r0 0.4 r1 0.41}	;minus 25 HP
;			{spawn "cw_human_secdamage2" "root"}
;		else
;			{blastwave c4 0.2 r0 0.4 r1 0.41}	;minus 50 HP
;			{spawn "cw_human_secdamage3" "root"}
		}
	}
	{on break_armor
		(define "break_plate"
			volume "%plate"
			{volumes "%plate" disable bullet}
		)
		{if ("break_plate" plate(front_plate))
		else ("break_plate" plate(rear_plate))
		else ("break_plate" plate(sider_plate))
		else ("break_plate" plate(sidel_plate))
		else ("break_plate" plate(front_ceramic))
		else ("break_plate" plate(rear_ceramic))
		else ("break_plate" plate(sider_ceramic))
		else ("break_plate" plate(sidel_ceramic))
		else ("break_plate" plate(soft_plate))
		}
	}
	{on "burn_volume"
		{if not burned
			{able "burning" 1}
			{tex_morph "burned" 10}
			{add_view "smoke_dead_small" "burn_fire"	"root"}
			{view start "burn_fire"}
			{delay 6 2 "burn_die"
				{able "burning" 0}
				{view stop "burn_fire"}
				{if terrain_fx "puddle"
					{call "stop_burn"}
				else
					{add_view "smoke_dead_small1" "burn_fire_b" 	"root"}
					{view start "burn_fire_b"}
					{delay 7.5 1.5	{view stop "burn_fire_b"}}
				}
			}
			{burn time 17} ; total burn time
		}
	}
}
;USA standarts are lower then Russian-Euro. Rus standars for afterarmor trauma allow only minor tissue damage (penetration approx 20mm)
;USA ones allow up to 44mm and 10% lethality even if armor class match bullet
{"armor_plate armor_plate_usa"
	{on "armor_plate_pierce" overload
		{if hit_side front
			{blastwave c4 0.16 r0 0.4 r1 0.41}	;minus 40 HP
;			{spawn "cw_human_secdamage2" "root"}
;		else
;			{blastwave c4 0.32 r0 0.4 r1 0.41}	;minus 80 HP
;			{spawn "cw_human_secdamage3" "root"}
			;{if rand 0.1 {call "die"}}		;http://bodyguardsonline.com/weapons/specsredstva/2332-klassnost-bronezhiletov.html
		}
	}
}
;Контузия отключена, т.к. вызывает откидывание при пробитии задней бронеплиты сквозь тело
{"cw_human_secdamage" {on spawn {stuff_detonate}}}