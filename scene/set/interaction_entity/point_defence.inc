{"point_defence"
	{on spawn
		{call "update_turret"}
		{call "update_weaponry"}
		{call "add_gun_effects"}
		{add_view "smoke_black" "smoke3"	"FXfire1"}
		{tags remove "autorepairing"}
		{tags remove "autorepair80"}
		{tags remove "autorepair60"}
		{tags remove "autorepair40"}
		{tags remove "autorepair20"}
	}
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret_cw/light_m2"}
	}
	{on ik begin "turret" {play_sound "rotate_turret" 1}}
	{on ik end "turret" {stop_sound "rotate_turret"}}
	{on ik begin "gun_rot" {play_sound "rotate_turret" 1}}
	{on ik end "gun_rot" {stop_sound "rotate_turret"}}
	{on ik begin "turret_rotator" {play_sound "rotate_turret" 1}}
	{on ik end "turret_rotator" {stop_sound "rotate_turret"}}
	{on bullet_hit overload
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
	{on pierce
	      {if not stuff "proj_pointer"
		{if component "driver_triplex"
			{if not tagged "driver_triplex_break" and work "driver_triplex"
				{tags add "driver_triplex_break"}
				{damage_report "driver_triplex" "driver_triplex_damaged"}
				{tear "piece_medium_steel" bone "visor2"
             	 	  			{impulse up 2 1 dir 2 1}
				}
			}
			{spawn "glass_hit" }
		else component "commander_triplex"
			{if not tagged "commander_triplex_break" and work "commander_triplex"
				{tags add "commander_triplex_break"}
				{damage_report "commander_triplex" "commander_triplex_damaged"}
				{tear "piece_medium_steel" bone "visor1"
             	   			{impulse up 2 1 dir 2 1}
				}
			}
			{spawn "glass_hit" }
		else component "additional_triplex"
			{if not tagged "additional_triplex_break" and work "additional_triplex"
				{tags add "additional_triplex_break"}
				{damage_report "additional_triplex" "additional_triplex_damaged"}
				{tear "piece_medium_steel" bone "visor3"
             	   			{impulse up 2 1 dir 2 1}
				}
			}
			{spawn "glass_hit"}
		else component "additional_triplex1"
			{if not tagged "additional_triplex_break" and work "additional_triplex1"
				{tags add "additional_triplex1_break"}
				{damage_report "additional_triplex1" "additional_triplex:additional_triplex_damaged"}
				{tear "piece_medium_steel" bone "visor4"
             	   			{impulse up 2 1 dir 2 1}
				}
			}
			{spawn "glass_hit"}
		else component "ammo_storage_main"
			{damage_report "ammo_storage_main" "ammo_storage_damaged"}
			{spawn "metal_hit_bul"}
			{if  explosive_amount 1000
				{if rand 0.95 {components "ammo_storage_main" break}}
			else  explosive_amount 750
				{if rand 0.8 {components "ammo_storage_main" break}}
			else  explosive_amount 500
				{if rand 0.65 {components "ammo_storage_main" break}}
			else  explosive_amount 250
				{if rand 0.50 {components "ammo_storage_main" break}}
			}		
		else component "ammo_storage_autocannon"
			{damage_report "ammo_storage_autocannon" "ammo_storage_damaged"}
			{spawn "metal_hit_bul"}
			{if  explosive_amount 1000
				{if rand 0.65 {components "ammo_storage_main" break}}
			else  explosive_amount 750
				{if rand 0.5 {components "ammo_storage_main" break}}
			else  explosive_amount 500
				{if rand 0.35 {components "ammo_storage_main" break}}
			else  explosive_amount 250
				{if rand 0.20 {components "ammo_storage_main" break}}
			}		
		else component "ammo_storage_mgun"
			{damage_report "ammo_storage_mgun" "ammo_storage_damaged"}
			{spawn "metal_hit_bul"}
			{if rand 0.45 {components "ammo_storage_mgun" break}}
			else component "gun"
				{components "gun" break}
			else component "gun2"
				{components "gun2" break}
		else component "gun3"
			{components "gun3" break}
		else component "body"
			{components "body"break}
		else component "turret"
			{components "turret" break}
		else component "gun_rot"
			{components "gun_rot" break}
		else component "autoloader"
			{components "autoloader" break}
		}
	        }
	}
;	{on break_armor
;		{call "do_armor_break"}
;	}
;	{on break_armor_again
;		{call "do_armor_break"}
;	}
	{on "mp_destroy"
		{drop_orders}
		{reset_manual_control}
		{able select 0}
		{able repaired 0}
		{unlink_trailer}
		{if not tagged "destroyed"
			{damage_report "body" "body_broken"}
			{if not tagged "body_break"
				{components "body" break}
				{call "stat_break"}
			}
		}
		{delay 2
			{tags add "destroyed"}
			{kick_entity_manager}
		}
		{weapon_work "gun" 0}
		{weapon_work "gun1" 0}
		{weapon_work "gun2" 0}
		{weapon_work "gun3" 0}
		{tear "piece_medium_steel" bone "Visor1"
              	 	{impulse up 2 1 dir 2 1}
		}
		{tear "piece_medium_steel" bone "visor2"
              	 	{impulse up 2 1 dir 2 1}
		}
		{tear "piece_medium_steel" bone "visor3"
              	 	{impulse up 2 1 dir 2 1}
		}
		{tear "piece_medium_steel" bone "visor4"
              	 	{impulse up 2 1 dir 2 1}
		}
	}
;	{on "do_armor_break"
;		{if name "blast"
;			{if volume "body"
;				{components "body" destroy}
;				{call "mp_destroy"}
;			else volume "turret"
;				{components "turret" destroy}
;				{call "mp_destroy"}
;			}
;		}
;	}
	{on blast_hit
		{if min_energy 10 
			{impulse up 0.5 0.2 dir 1 0.2}
			{call "explosion"}
		}
	}
	{on "explosion"
	   {components "body" destroy}
	   {components "turret" destroy}
	   {call "mp_destroy"}
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
		{call "tear_turret"}
		("cut_part" args "part1")
		("cut_part" args "part2")
		("cut_part" args "part3")
		("cut_part" args "part4")
		("cut_part" args "part5")
		("cut_part" args "part6")
		{delay 14 {view stop "deathfx"}}
	}
	{on "tear_turret"
		{if not flag "turret_teared"
			{set "turret_teared" 1}
			{components "turret" destroy}
			{call "mp_destroy"}
			{add_view "smoke_black_big5" "smoke_turret" "basis"}
			{view start "smoke_turret"}
			{delay 60 15
				{view stop "smoke_turret"}
			}
			{delay_ex 0.1
				{tear "piece_large_steel" bone "turret" id "turret"
					{impulse up 3 2 dir 0.5 1}
					{delay 15 {impulse up 1}}
					{delay 30 {impulse up 1}}
					{if rand 0.2
						{add_view "smoke_dead_norm" "smoke" "basis"}
					else
						{add_view "smoke_black" "smoke" "basis"}
					}
					{view start "smoke"}
					{delay_effect 30 5 "pause"}
					{delay 0.1
						{volumes "gun" disable obstacle}
					}
				}
				{call "break_all"}
				{delay 0.1 {volumes disable all}}	;not attacking destroyed parts
			}
		}
	}
	{on "slice_load"
		{if name "turret"
			{with_effector
				{add_view "smoke_black" "smoke" "basis"}
			}
		}
	}
	{on contact
		{if not impregnable
			{if not effector "armored_car"
				{if effector "tank"
					{component destroy}
					{if volume "body"
						{set "crush" 1}
						{call "explosion"}
					}
				else effector "big part"
					{if effector_velocity 3
						{component break}
					}
				}
			}
		}
	}
	{on "update_weaponry"
	      {delay 0.1
		{if work "body"
			{call "update_gun"}
			{call "update_gun1"}
			{call "update_gun23"}
			{call "update_radar"}
		}
	     }
	}
	
	{on "update_gun"
		{if work "gun"
				{weapon_work "gun" 1}
		else {weapon_work "gun" 0}}
	}
	{on "update_gun1"
		{if work "gun1"
				{weapon_work "gun1" 1}
		else {weapon_work "gun1" 0}}
	}
	{on "update_gun23"
		{if work "gun2"
			{if not flag "specability"
				{weapon_work "gun2" 1}
			else {weapon_work "gun2" 0}}
		else {weapon_work "gun2" 0}}
		{if work "gun3"
			{if not flag "specability"
				{weapon_work "gun3" 1}
			else {weapon_work "gun3" 0}}
		else {weapon_work "gun3" 0}}
	}
	{on "update_turret"
		{if not work "turret"
			{ik_enable "turret" 0}
		else not work "body"
			{ik_enable "turret" 0}
		else
			{ik_enable "turret" 1}
		}
		{if not work "gun_rot"
			{ik_enable "gun_rot" 0}
		else not work "body"
			{ik_enable "gun_rot" 0}
		else
			{ik_enable "gun_rot" 1}
		}
	}
	{on fire "gun1"
		{view start "flashbarrel1"}
		{ani_play "fire1"}
		{view start "gilz1"}
		{kill_delay "gilz1"}
		{delay 0.2 "gilz1"
			{view pause "gilz1"}
		}
	}
	{on "sink" overload}
  {on break overload
	{if component "body"
		{call "mp_destroy"}
		{spawn "metal_hit_bul"}
	else component "turret"
		{ik_enable "turret" 0}
		{spawn "metal_hit_bul"}
		{if rand 0.2
			{add_view "smoke_dead_tree" "burn_fire_1""FXfire1"}
			{view start "burn_fire_1"}
			{delay 7.5 1.5{view stop "burn_fire_1"}}
		else rand 0.45
			{add_view "smoke_tank_small" "burn_fire_1""FXfire1"}
			{view start "burn_fire_1"}
			{delay 7.5 1.5{view stop "burn_fire_1"}}
		else rand 0.7
			{add_view "smoke_dead_tree1" "burn_fire_1""FXfire1"}
			{view start "burn_fire_1"}
			{delay 3.5 1.5{view stop "burn_fire_1"}}
		else
			{add_view "smoke_dead_small1" "burn_fire_1""FXfire1"}
			{view start "burn_fire_1"}
			{delay 9.5 1.5{view stop "burn_fire_1"}}
		}
		{call "update_turret"}
		{spawn "tank_die_particle" "body"}
		{spawn "circledust_norm" "body"}
		{view start "smoke3"}
		{delay 10
			{view stop "smoke3"}
		}
		{tags add "turret_brake"}
	else component "gun_rot"
		{ik_enable "gun_rot" 0}
		{spawn "metal_hit_bul"}
		{call "update_turret"}
		{spawn "tank_die_particle" "gun_rot"}
		{spawn "circledust_norm" "gun_rot"}
		{view start "smoke3"}
		{delay 10
			{view stop "smoke3"}
		}
		{tags add "gun_rot_brake"}
	else component "gun"
		{if not tagged "destroyed"
			{damage_report "gun" "gun_damaged"}
			{spawn "metal_hit_bul"}
			{weapon_work "gun" 0}
		}
		{tags add "gun_damaged"}
		{call "update_gun"}
	else component "autoloader"
		{if not tagged "destroyed"
			{damage_report "autoloader" "autoloader_damaged"}
			{spawn "metal_hit_bul"}
		}
		{tags add "autoloader_damaged"}
	else component "gun1"
		{if not tagged "destroyed"
			{damage_report "gun1" "gun1_damaged"}
			{spawn "metal_hit_bul"}
			{weapon_work "gun1" 0}
		}
		{tags add "gun1_damaged"}
		{call "update_gun1"}
	else component "gun2"
		{if not tagged "destroyed"
			{damage_report "turret" "ptur_damaged"}
			{spawn "metal_hit_bul"}
			{weapon_work "gun2" 0}
			{spawn "ex_air_big"}
			{fragments c4 2 r0 3 r1 4 position}
		}
		{tags add "gun2_damaged"}
		{call "update_gun23"}
	else component "gun3"
		{if not tagged "destroyed"
			{damage_report "turret" "ptur_damaged"}
			{spawn "metal_hit_bul"}
			{weapon_work "gun3" 0}
			{spawn "ex_air_big"}
			{fragments c4 2 r0 3 r1 4 position}
		}
		{tags add "gun3_damaged"}
		{call "update_gun23"}
	else component "ammo_storage_main"
		{if not tagged "destroyed"
		{if explosive_amount 4000	
			{spawn "ex_air_big2"} {blastwave c4 16 r0 7 r1 14 position}
			{delay 0.2 0.3 {spawn "ex_air_big2"} {blastwave c4 14 r0 6 r1 12 position}}
			{delay 0.3 0.4 {spawn "ex_air_big2"} {blastwave c4 12 r0 5 r1 10 position}}
			{delay 0.4 0.5 {spawn "ex_air_big2"} {blastwave c4 10 r0 5 r1 10 position}}
			{if rand 0.8 {call "_explosion"}}
			{clear_inventory}
		else explosive_amount 3000
			{spawn "ex_air_big2"} {blastwave c4 12 r0 7 r1 14 position}
			{delay 0.2 0.5 {spawn "ex_air_big2"} {blastwave c4 10 r0 6 r1 12 position}}
			{delay 0.6 1 {spawn "ex_air_big2"} {blastwave c4 8 r0 5 r1 10 position}}
			{delay 1 1.2 {spawn "ex_air_big2"} {blastwave c4 7 r0 4 r1 8 position}}
			{delay 1.3 1.5 {spawn "ex_air_big2"} {blastwave c4 7 r0 4 r1 8 position}}
			{if rand 0.6 {call "_explosion"}}
			{clear_inventory}
		else explosive_amount 2000		
			{spawn "ex_air_big2"} {blastwave c4 9 r0 5 r1 10 position}
			{delay 0.2 0.5 {spawn "ex_air_big2"} {blastwave c4 8 r0 5 r1 10 position}}
			{delay 0.6 1 {spawn "ex_air_big2"} {blastwave c4 8 r0 5 r1 10 position}}
			{delay 1 1.2 {spawn "ex_air_big2"} {blastwave c4 7 r0 4 r1 8 position}}
			{delay 1.3 1.5 {spawn "ex_air_big2"} {blastwave c4 7 r0 4 r1 8 position}}
			{delay 1.6 1.7 {spawn "ex_air_big2"} {blastwave c4 6 r0 4 r1 8 position}}
			{if rand 0.5 {call "_explosion"}}
			{clear_inventory}
		else explosive_amount 1000		
			{spawn "ex_air_big2"} {blastwave c4 8 r0 5 r1 10 position}
			{delay 0.2 0.5 {spawn "ex_air_big2"} {blastwave c4 7 r0 5 r1 10 position}}
			{delay 0.6 1 {spawn "ex_air_big2"} {blastwave c4 7 r0 5 r1 10 position}}
			{delay 1 1.2 {spawn "ex_air_big2"} {blastwave c4 6 r0 4 r1 8 position}}
			{delay 1.3 1.5 {spawn "ex_air_big2"} {blastwave c4 6 r0 4 r1 8 position}}
			{delay 1.6 1.7 {spawn "ex_air_big2"} {blastwave c4 6 r0 4 r1 8 position}}
			{if rand 0.5 {call "_explosion"}}
			{clear_inventory}
		else explosive_amount 750		
			{spawn "ex_air_big2"} {blastwave c4 6 r0 4 r1 8 position}
			{delay 0.2 0.5 {spawn "ex_air_big2"} {blastwave c4 6 r0 4 r1 8 position}}
			{delay 0.6 1 {spawn "ex_air_big2"} {blastwave c4 6 r0 4 r1 8 position}}
			{delay 1 1.2 {spawn "ex_air_big2"} {blastwave c4 6 r0 4 r1 8 position}}
			{delay 1.3 1.5 {spawn "ex_air_big2"} {blastwave c4 6 r0 4 r1 8 position}}
			{if rand 0.4 {call "_explosion"}}
			{clear_inventory}
		else explosive_amount 500
			{spawn "ex_air_big2"} {blastwave c4 6 r0 4 r1 8 position}
			{delay 0.2 0.5 {spawn "ex_air_big2"} {blastwave c4 6 r0 4 r1 8 position}}
			{delay 0.6 1 {spawn "ex_air_big2"} {blastwave c4 5 r0 3 r1 6 position}}
			{delay 1 1.2 {spawn "ex_air_big2"} {blastwave c4 5 r0 3 r1 6 position}}
			{if rand 0.2 {call "_explosion"}}
			{clear_inventory}
		else explosive_amount 250
			{spawn "ex_air_big2"} {blastwave c4 4 r0 3 r1 6 position}
			{delay 0.2 0.5 {spawn "ex_air_big2"} {blastwave c4 4 r0 3 r1 6 position}}
			{clear_inventory}
		else explosive_amount 100
			{if rand 0.5 {clear_inventory}}
		}
		}
	else component "ammo_storage_autocannon"
		{if not tagged "destroyed"
		{if explosive_amount 4000	
			{spawn "ex_air_big2"} {fragments c4 16 r0 7 r1 14 position}
			{delay 0.2 0.3 {spawn "ex_air_big2"} {fragments c4 14 r0 6 r1 12 position}}
			{delay 0.3 0.4 {spawn "ex_air_big2"} {fragments c4 12 r0 5 r1 10 position}}
			{delay 0.4 0.5 {spawn "ex_air_big"} {fragments c4 10 r0 5 r1 10 position}}
			{if rand 0.8 {call "_explosion"}}
			{clear_inventory}
		else explosive_amount 3000
			{spawn "ex_air_big2"} {fragments c4 12 r0 7 r1 14 position}
			{delay 0.2 0.5 {spawn "ex_air_big2"} {fragments c4 10 r0 6 r1 12 position}}
			{delay 0.6 1 {spawn "ex_air_big2"} {fragments c4 8 r0 5 r1 10 position}}
			{delay 1 1.2 {spawn "ex_air_big"} {fragments c4 7 r0 4 r1 8 position}}
			{delay 1.3 1.5 {spawn "ex_air_big"} {fragments c4 7 r0 4 r1 8 position}}
			{if rand 0.6 {call "_explosion"}}
			{clear_inventory}
		else explosive_amount 2000		
			{spawn "ex_air_big2"} {fragments c4 9 r0 5 r1 10 position}
			{delay 0.2 0.5 {spawn "ex_air_big2"} {fragments c4 8 r0 5 r1 10 position}}
			{delay 0.6 1 {spawn "ex_air_big2"} {fragments c4 8 r0 5 r1 10 position}}
			{delay 1 1.2 {spawn "ex_air_big"} {fragments c4 7 r0 4 r1 8 position}}
			{delay 1.3 1.5 {spawn "ex_air_big"} {fragments c4 7 r0 4 r1 8 position}}
			{delay 1.6 1.7 {spawn "ex_air_big"} {fragments c4 6 r0 4 r1 8 position}}
			{if rand 0.5 {call "_explosion"}}
			{if rand 0.85 {clear_inventory}}
		else explosive_amount 1000		
			{spawn "ex_air_big2"} {fragments c4 8 r0 5 r1 10 position}
			{delay 0.2 0.5 {spawn "ex_air_big2"} {fragments c4 7 r0 5 r1 10 position}}
			{delay 0.6 1 {spawn "ex_air_big"} {fragments c4 7 r0 5 r1 10 position}}
			{delay 1 1.2 {spawn "ex_air_big"} {fragments c4 6 r0 4 r1 8 position}}
			{delay 1.3 1.5 {spawn "ex_air_big"} {fragments c4 6 r0 4 r1 8 position}}
			{delay 1.6 1.7 {spawn "ex_air_big"} {fragments c4 6 r0 4 r1 8 position}}
			{if rand 0.5 {call "_explosion"}}
			{if rand 0.7 {clear_inventory}}
		else explosive_amount 750		
			{spawn "ex_air_big2"} {fragments c4 6 r0 4 r1 8 position}
			{delay 0.2 0.5 {spawn "ex_air_big"} {fragments c4 6 r0 4 r1 8 position}}
			{delay 0.6 1 {spawn "ex_air_big"} {fragments c4 6 r0 4 r1 8 position}}
			{delay 1 1.2 {spawn "ex_air_big"} {fragments c4 6 r0 4 r1 8 position}}
			{delay 1.3 1.5 {spawn "ex_air_big"} {fragments c4 6 r0 4 r1 8 position}}
			{if rand 0.4 {call "_explosion"}}
			{if rand 0.5 {clear_inventory}}
		else explosive_amount 500
			{spawn "ex_air_big2"} {fragments c4 6 r0 4 r1 8 position}
			{delay 0.2 0.5 {spawn "ex_air_big"} {fragments c4 6 r0 4 r1 8 position}}
			{delay 0.6 1 {spawn "ex_air_big"} {fragments c4 5 r0 3 r1 6 position}}
			{delay 1 1.2 {spawn "ex_air_big"} {fragments c4 5 r0 3 r1 6 position}}
			{if rand 0.2 {call "_explosion"}}
			{if rand 0.4 {clear_inventory}}
		else explosive_amount 250
			{spawn "ex_air_big2"} {fragments c4 4 r0 3 r1 6 position}
			{delay 0.2 0.5 {spawn "ex_air_big"} {fragments c4 4 r0 3 r1 6 position}}
			{if rand 0.3 {clear_inventory}}
		else explosive_amount 100
			{if rand 0.1 {clear_inventory}}
		}
		}
	else component "ammo_storage_mgun" 
		{if not tagged "destroyed"
		{spawn "ex_air_norm"}
		{fragments c4 2 r0 1 r1 3 position}
		{delay 0.2 0.5
			{spawn "ex_air_norm"}
			{fragments c4 2 r0 1 r1 3 position}
		}
		{delay  0.6 1
			{spawn "ex_air_norm"}
			{fragments c4 2 r0 1 r1 3 position}
		}
		{delay 1 1.2
			{spawn "ex_air_norm"}
			{fragments c4 2 r0 1 r1 3 position}
		}
		{delay 1.3 1.5
			{spawn "ex_air_norm"}
			{fragments c4 2 r0 1 r1 3 position}
		}
		}

	}
	{call "update_weaponry"}
	{call "break_light"}
  }
  {on repair overload
	{if component "turret"
		{ik_enable "turret" 1}
		{view stop "burn_fire_1"}
    		{view stop "smoke3"}
		{call "update_turret"}
		{tags remove "turret_brake"}
	else  component "gun_rot"
		{ik_enable "gun_rot" 1}
		{call "update_turret"}
		{tags remove "gun_rot_brake"}
	else component "autoloader"
		{damage_report "gun1" "autoloader_repaired"}
		{tags remove "autoloader_damaged"}
	else component "gun"
		{damage_report "gun" "gun_repaired"}
		{tags remove "gun_damaged"}
		{weapon_work "gun" 1}
	else component "gun1"
		{damage_report "gun1" "gun1_repaired"}
		{tags remove "gun1_damaged"}
		{weapon_work "gun1" 1}
	else  component "gun2"
		{damage_report "gun2" "ptur_repaired"}
		{tags remove "gun2_damaged"}
		{weapon_work "gun2" 1}
	else  component "gun3"
		{damage_report "gun3" "ptur_repaired"}
		{tags remove "gun3_damaged"}
		{weapon_work "gun3" 1}
	}
	{call "update_weaponry"}
	{call "repair_light"}
     }
     {on fire "gun"
             	{view start "flashbarrel1"}
	{ani_play "fire"}
	{delay 0.8
		{view pause "flashbarrel1"}
	}
	{if not work "autoloader"
		{weapon_work "gun" 0}
		{damage_report "autoloader" "autoloader_malfunction"}
		{delay 12 {call "update_weaponry"}}
	}
  }
  {on "start_autorepair"
	{if not tagged "autorepairing"
		{call "try_to_repair"}
	}
  }
  
    {on "try_to_repair"
		{if tagged "destroyed" 	{tags remove "autorepairing"}{tags remove "autorepair80"}{tags remove "autorepair60"}
			{tags remove "autorepair40"}{tags remove "autorepair20"}
		else not work "turret"
			{tags add "autorepairing"}
			{if tagged "autorepair80" {delay 20 3 {components "turret" repair} {tags remove "autorepair80"}{tags remove "autorepairing"}}
			else tagged "autorepair60"{delay 20 3 {tags add "autorepair80"} {tags remove "autorepair60"} {call "try_to_repair"}}
			else tagged "autorepair40"{delay 20 3 {tags add "autorepair60"} {tags remove "autorepair40"} {call "try_to_repair"}}
			else tagged "autorepair20"{delay 20 3 {tags add "autorepair40"} {tags remove "autorepair20"} {call "try_to_repair"}}
			else {delay 20 3 {tags add "autorepair20"} {call "try_to_repair"}}}
		else not work "gun_rot"
			{tags add "autorepairing"}
			{if tagged "autorepair60" {delay 20 3 {components "gun_rot" repair} {tags remove "autorepair60"}{tags remove "autorepairing"}}
			else tagged "autorepair40"{delay 20 3 {tags add "autorepair60"} {tags remove "autorepair40"} {call "try_to_repair"}}
			else tagged "autorepair20"{delay 20 3 {tags add "autorepair40"} {tags remove "autorepair20"} {call "try_to_repair"}}
			else {delay 20 3 {tags add "autorepair20"} {call "try_to_repair"}}}
		else not work "autoloader"
			{tags add "autorepairing"}
			{if tagged "autorepair60" {delay 20 3 {components "autoloader" repair} {tags remove "autorepair60"}{tags remove "autorepairing"}}
			else tagged "autorepair40"{delay 20 3 {tags add "autorepair60"} {tags remove "autorepair40"} {call "try_to_repair"}}
			else tagged "autorepair20"{delay 20 3 {tags add "autorepair40"} {tags remove "autorepair20"} {call "try_to_repair"}}
			else {delay 20 3 {tags add "autorepair20"} {call "try_to_repair"}}}
		else not work "gun2"
			{tags add "autorepairing"}
			{if tagged "autorepair60" {delay 20 3 {components "gun2" repair} {tags remove "autorepair60"}{tags remove "autorepairing"}}
			else tagged "autorepair40"{delay 20 3 {tags add "autorepair60"} {tags remove "autorepair40"} {call "try_to_repair"}}
			else tagged "autorepair20"{delay 20 3 {tags add "autorepair40"} {tags remove "autorepair20"} {call "try_to_repair"}}
			else {delay 20 3 {tags add "autorepair20"} {call "try_to_repair"}}}
		else not work "gun3"
			{tags add "autorepairing"}
			{if tagged "autorepair60" {delay 20 3 {components "gun3" repair} {tags remove "autorepair60"}{tags remove "autorepairing"}}
			else tagged "autorepair40"{delay 20 3 {tags add "autorepair60"} {tags remove "autorepair40"} {call "try_to_repair"}}
			else tagged "autorepair20"{delay 20 3 {tags add "autorepair40"} {tags remove "autorepair20"} {call "try_to_repair"}}
			else {delay 20 3 {tags add "autorepair20"} {call "try_to_repair"}}}
		else not work "gun"
			{tags add "autorepairing"}
			{if tagged "autorepair40" {delay 20 3 {components "gun" repair} {tags remove "autorepair40"}{tags remove "autorepairing"}}
			else tagged "autorepair20"{delay 20 3 {tags add "autorepair40"} {tags remove "autorepair20"} {call "try_to_repair"}}
			else {delay 20 3 {tags add "autorepair20"} {call "try_to_repair"}}}
		}
	}

}
(include "point_defence_units.inc")