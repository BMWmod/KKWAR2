;COLD WAR MOD
;Scripted by Timosh


	{on spawn
		{link_sound "flame"			"fire/big"}
		{link_sound "move"			"vehicle/tracks/trackclank"}
		{link_sound "heavy_move"	"vehicle/tracks/heavy"}
		{link_sound "spo"	"vehicle/other/shtora"}
		{stop_sound "spo"}
		{if not rain
			{add_view	"dustrun_big"			"on_ground"				"FXtraceR1"}
			{add_view	"dustrun_big"			"on_ground"				"FXtraceL1"}
			{add_view	"dustrun_small"			"on_grass"				"FXtraceR1"}
			{add_view	"dustrun_small"			"on_grass"				"FXtraceL1"}
			{add_view	"dustrun_sand_big" 		"on_sand"				"FXtraceR1"}
			{add_view	"dustrun_sand_big" 		"on_sand"				"FXtraceL1"}
			{add_view	"dustrun_snow_big" 		"on_snow"				"FXtraceR1"}
			{add_view	"dustrun_snow_big" 		"on_snow"				"FXtraceL1"}
			{add_view	"dustrun_small"			"on_country_road"		"FXtraceR1"}
			{add_view	"dustrun_small"			"on_country_road"		"FXtraceL1"}
		else
			{add_view	"engine_steam"			"engine_steam"			"FXfire1"}
                }

		{add_view	"tank_grit_small"		"on_ground"				"FXtraceR2"}
		{add_view	"tank_grit_small"		"on_ground"				"FXtraceL2"}
		{add_view	"tank_grit_big"			"on_ground_time_short"	"FXtraceR2"}
		{add_view	"tank_grit_big"			"on_ground_time_short"	"FXtraceL2"}

		{add_view	"tank_grit_small"		"on_grass"				"FXtraceR2"}
		{add_view	"tank_grit_small"		"on_grass"				"FXtraceL2"}
		{add_view	"tank_grit_big"			"on_grass_time_short"	"FXtraceR2"}
		{add_view	"tank_grit_big"			"on_grass_time_short"	"FXtraceL2"}

		{add_view	"wash_moto_dipper"			"on_water"				"FXtraceR1"}
		{add_view	"wash_moto_dipper"			"on_water"				"FXtraceL1"}
		{add_view	"tank_grit_big_mud"		"on_mud"				"FXtraceR2"}
		{add_view	"tank_grit_big_mud"		"on_mud"				"FXtraceL2"}
		{add_view	"tank_grit_big_snow"	"on_snow"				"FXtraceR2"}
		{add_view	"tank_grit_big_snow"	"on_snow"				"FXtraceL2"}
		{add_view	"wash_moto"		"on_puddle"				"FXtraceR1"}
		{add_view	"wash_moto"		"on_puddle"				"FXtraceL1"}
		{add_view	"tank_grit_small_w"		"on_puddle"				"FXtraceR2"}
		{add_view	"tank_grit_small_w"		"on_puddle"				"FXtraceL2"}

;		{add_view	"flash_cannon_big"		"flashbarrel1"			"Foresight1"}
		{add_view	"powdersmoke_big"		"flashbarrel1s"			"Foresight1"}
		{add_view 	"flash_zenit"			"flashbarrel2s"			"foresight2"}
;		{add_view	"powdersmoke_small2" 	"flashbarrel1s" 		"Foresight1"}
;		{add_view	"flash_gun_big"			"flashbarrel2"			"Foresight3"}

		{add_view	"smoke_white_steam"		"smoke1"				"FXfire1"}
		{add_view	"smoke_black"			"smoke2"				"FXfire2"}
		{add_view	"smoke_black"			"smoke3"				"FXfire2"}
		{add_view	"smoke_black"			"smoke4"				"FXfire1"}
		{add_view	"smoke_dead_small2"		"smoke4_1"				"FXfire3"}
		{add_view	"smoke_dead_small2a"	"smoke4_2"				"FXfire3"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmoke"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmoke1"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmoke2"}
		{set "smoke3" 0}
		{set "smoke4" 0}

		{if user_control {able "emit_passangers_on_enemy" 0}}
		{call "init_burnout"}
		{call "talk_scanner"}
	}
	{on "talk_scanner"			
		{if attacking_weapon or attacked	
			{talk "tank_in_action" {audience all}}			
		}				
		{delay 1 "talk_scanner"
			{call "talk_scanner"}
		}
	}

	{on "add_movement_sound"
		{link_sound "engine"		"vehicle/engine_cw/tank"}
		{link_sound "engine_end"	"vehicle/engine_cw/tank_end"}
		{link_sound "exhaust"		"vehicle/engine_cw/tank_up"}
	}
;	{on "add_hatch_sound"
;		{link_sound "hatch_in"			"vehicle/other/hatch_in"}
;		{link_sound "hatch_out"			"vehicle/other/hatch_out"}
;	}
	
	("update_hatch_event" event(operatable on) place(gunner2))
	("update_hatch_event" event(operatable off) place(gunner2))
	("update_hatch_event" event(crew in) place(gunner2))
	("update_hatch_event" event(crew out) place(gunner2))
	

	{on "emit_on_hit"
		{call "burn_emit"}
		{able select 0}
		
		{view start "smoke4_1"}
		{set "smoke4_1" 1}
		
		{delay 8
			{view stop "smoke4_1"}
			{set "smoke4_1" 0} 	
			{if not flag "burn_fire"
				{able "burning" 0}
				{able repaired 1}			
			}
		}
		{delay 11
			{able select 1}
			{if not flag "burn_fire"
				{able "burning" 0}
				{able repaired 1}			
			}
		}
		{delay 20
			{if not flag "burn_fire"
				{able "burning" 0}			
			}		
		}
	}
        
        {on "emit_on_rocketlauncher"
		{if rand 0.5
			{call "burn_emit"}
		else
			{crew_emit}
		}
		{able select 0}	
		{delay 4
			{if not flag "burn_fire"
				{able select 1}
				{able "burning" 0}
				{able repaired 1}			
			}
		}
		{burn fx "smoke_dead_tank2" fake}
	}
	
	{on "stat_body_break"
		{if not broken
			{stat_notify break}
			{tags add "body_break"}	
		}	
	}
	{on "break_all" overload
		{call "kill_crew"}
		{drop_orders}
		{components "body" destroy}
		{components "cabin" destroy}
		{components "turret" destroy}
		{components "gun" destroy}
		{components "trackleft" destroy}
		{components "trackright" destroy}
		{components "engine" destroy}
		{reset_manual_control}
		{able select 0}
		{able repaired 0}
		{unlink_trailer}
		{clear_inventory}
	}
        
	(define "cut_shield_part"
		{if component %0
			{volume disable blast}
			{delay_ex 0.11
				{tear "piece_medium_steel" bone %0
					{volumes "kaz_hitzone" disable all}
					{impulse up 2 1 dir 2 1}
				}
			}
		}
	)
	(define "gun_hit"
		{if volume "gun"
			{if rand %rand
                {if work "gun"
				{components "gun" break}
				{damage_report "gun" "gun_damaged"}
                            }
			}
		}
	)
;//==================================================
;//=======================================================================
 	(define "track_hit"
		{if hit_side front
 			{if rand %max_rand
				{if volume "trackleft"
                    {if work "trackleft"
                        ;{burn fx "smoke_dead_tank2" fake}	
                        {components "trackleft" break}	
                        ;{damage_report "trackleft" "track_broken"}
                    }				
				else volume "trackright"
                    {if work "trackright"
                        ;{burn fx "smoke_dead_tank2" fake}
                        {components "trackright" break}	
                        ;{damage_report "trackright" "track_broken"}
                    }			
				}
			}
		else hit_side back
				{if rand %max_rand
					{if volume "trackleft"
                        {if work "trackleft"
                            ;{burn fx "smoke_dead_tank2" fake}
                            {components "trackleft" break}	
                            ;{damage_report "trackleft" "track_broken"}
                        }
					else volume "trackright"
                        {if work "trackright"
                            ;{burn fx "smoke_dead_tank2" fake}
                            {components "trackright" break}	
                            ;{damage_report "trackright" "track_broken"}
                        }			
					}				
				}
		else rand %min_rand
			{if volume "trackleft"
                {if work "trackleft"
                    {components "trackleft" break}
                    ;{burn fx "smoke_dead_tank2" fake}	
                    ;{damage_report "trackleft" "track_broken"}
                }
			else volume "trackright"
                {if work "trackright"
                	{components "trackright" break}	
                	;{burn fx "smoke_dead_tank2" fake}
                	;{damage_report "trackright" "track_broken"}
                }
			}				
		}
	)
	{on "mp_destroy"
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

		{if rand 0.5	
			("cut_shield_part" args "shieldl4")
			("cut_shield_part" args "shieldl5")
		}
		{if rand 0.5
			("cut_shield_part" args "shieldr4")
			("cut_shield_part" args "shieldr3")
		}
		{if rand 0.5	
			("cut_shield_part" args "shieldl2")
			("cut_shield_part" args "shieldl3")
		}
		{if rand 0.5
			("cut_shield_part" args "shieldr2")
			("cut_shield_part" args "shieldr1")
		}
		{if rand 0.5
			("cut_shield_part" args "shieldl3")
			("cut_shield_part" args "shieldl1")
		}
		{if rand 0.5
			("cut_shield_part" args "shieldl5")
			("cut_shield_part" args "shieldl6")
		}
		{if rand 0.5
			("cut_shield_part" args "shieldl7")
			("cut_shield_part" args "shieldl8")
		}
		{if rand 0.5
			("cut_shield_part" args "shieldl9")
			("cut_shield_part" args "shieldl10")
		}
		{if rand 0.5
			("cut_shield_part" args "shieldl11")
			("cut_shield_part" args "shieldl12")
		}
		{if rand 0.5
			("cut_shield_part" args "shieldl13")
			("cut_shield_part" args "shieldl14")
		}
		{if rand 0.5
			("cut_shield_part" args "shieldl15")
			("cut_shield_part" args "shieldl16")
		}
		{if rand 0.5
			("cut_shield_part" args "shieldr5")
			("cut_shield_part" args "shieldr6")
		}
		{if rand 0.5
			("cut_shield_part" args "shieldr7")
			("cut_shield_part" args "shieldr8")
		}
		{if rand 0.5
			("cut_shield_part" args "shieldr9")
			("cut_shield_part" args "shieldr10")
		}
		{if rand 0.5
			("cut_shield_part" args "shieldr11")
			("cut_shield_part" args "shieldr12")
		}
		{if rand 0.5
			("cut_shield_part" args "shieldr13")
			("cut_shield_part" args "shieldr14")
		}
		{if rand 0.5
			("cut_shield_part" args "shieldr15")
			("cut_shield_part" args "shieldr16")
		}
		{call "check_burn_emit"}
											
		{reset_manual_control}
		{able select 0}
		{able repaired 0}
		{unlink_trailer}
	}
		{on "upside_down"
;			{if not burned
;				{call "_burn"}
;			}
			{unlink_trailer}
			{delay 1	{crew_emit}}
			{delay 2	{crew_emit}}
			{delay 3	{crew_emit}}
		}

	{on "_explosion"
		{call "stat_break"}
		{blastwave c4 2 r0 6 r1 12}
;		{remove_grass 4}
		{add_view "engine_fire" "deathfx" "FXfire1"}
		{spawn "tank_die" "Basis"}
	}

;declared in tank types - IFV shouldn't have it
;	{on "init_gun"
;	      {if rand 0.3
;		{add_view "fire_ammo_burnout_barr1" "ammo_burnout1" "Foresight1"}
;		{add_view "fire_ammo_burnout_barr2" "ammo_burnout2" "Foresight1"}
;		{add_view "fire_ammo_burnout_barr3" "ammo_burnout3" "Foresight1"}
;		{add_view "fire_ammo_burnout_barr4" "ammo_burnout4" "Foresight1"}
;	       }
;	}

				
				
	{on "spawn_shellhole"
		{spawn "shellhole_dead_tank2" "Basis"}
	}
	{on "cut_parts"
		{spawn "tank_die" "Basis"}
		{add_view "smoke_black_big2" "deathfx" "basis"}
		{view start "deathfx"}
		(define "cut_part"
			{if rand 0.5
				{tear "piece_medium_steel" bone %0
					{impulse up 8 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 10 no_position}
;					{add_view "smoke_dead_wheel" "smoke" "basis"}
;					{view start "smoke"}
					{delay_effect 20 5 "stop"}
				}
			}
		)
		(define "cut_wheel"
				{tear "piece_tank_wheel" bone %0
					{impulse up 3 1 dir 3 1 cx 3 1 cy 3 1 rnd_dir 4 no_position}
;					{delay 0
;						{volumes "body" disable all}
;						{volumes "body1" enable contact contact_ground visible bullet blast obstacle}
;					}
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
		{if rand 0.3 {if rand 0.5 ("cut_wheel" args "wheell2") else ("cut_wheel" args "wheelr2")}}
		{if rand 0.3 ("cut_wheel" args "wheell3")} {if rand 0.3 ("cut_wheel" args "wheelr3")}
		{if rand 0.3 ("cut_wheel" args "wheell4")} {if rand 0.3 ("cut_wheel" args "wheelr4")}
		{if rand 0.3 ("cut_wheel" args "wheell5")} {if rand 0.3 ("cut_wheel" args "wheelr5")}
		{if rand 0.3 ("cut_wheel" args "wheell6")} {if rand 0.3 ("cut_wheel" args "wheelr6")}
		{delay 25 5	{view stop "deathfx"}}
	}

	{on "check_burn_emit"
		{if not flag "burn_fire"
			{if not flag "smoke3"
				{if not flag "smoke4"
					{able "burning" 0}
				else
                    {delay 5
						{call "burn_emit"}
                    }
				}
			else
                {delay 5
					{call "burn_emit"}
                }
			}
		else
            {delay
				{call "burn_emit"}
            }
		}
	}

	{on fire "gun"
        		{view start "flashbarrel1"}
		{view start "flashbarrel1s"}
		{ani_play "fire"}
		{delay 0.8
			{view pause "flashbarrel1"}
		}
		{delay 0.2
			{view pause "flashbarrel1s"}
		}
;====================================
;afterarmor system by Timosh
;decreasing fire rate when autoloader broken
		{call "check_autoloader"}
;end of decreasing fire rate when autoloader broken
;====================================
	}
	{on fire "gun1"                     
		{view start "flashbarrel2s"}
		{delay 0.2
			{view pause "flashbarrel2s"}
		}
	}
        {on "criticalhit" overload
        	{if component "body"
        		{if not hit_side front
        			{components "engine" break}
        		}
        	else component "turret"
			{components "gun" break}
        	}
        }
	{on "explosive_broken"
		{if not work "body"
			{delay 0.1 0.1
				{call "explosion"}
				{call "stat_break"}
				{damage_report "body" "empty"}
				{damage_report "engine" "empty"}
				{damage_report "trackright" "empty"}
				{damage_report "trackleft" "empty"}
				{damage_report "turret" "empty"}
				{damage_report "gun" "empty"}
			}
                }
        }
    {on "burn_hatch"
		{add_view	"smoke_dead_norm2"	"smoke_hatch"	"FXfire3"}
		{add_view	"smoke_dead_norm2"	"smoke_hatch"	"FXfire_bk1"}
		{add_view	"smoke_dead_norm2"	"smoke_hatch"	"FXfire_bk2"}
		{add_view	"smoke_dead_norm2"	"smoke_hatch"	"FXfire_bk3"}
		{view start "smoke_hatch"}
    }
    {on "burn_engine"
		{add_view	"fire_napalm"	"fire_napalm"	"engine"}
		{view start "fire_napalm"}
    }
    
    	{on "rand_burn"
		{if rand 0.2
			{if not burned
				{burn time 17}
				{delay 1
					{call "_burn"}
				}
			}
		}
	}
	{on "burn_crew_mp"
		{if rand 0.3 {kill_crew "gunner"}}
		{if rand 0.3 {kill_crew "charger"}}
		{if rand 0.3 {kill_crew "commander"}}
		{if rand 0.3 {kill_crew "driver"}}
	}
        (define "burn_by_engine"
        	{on "burn_by_engine"
        		{if not tagged "burned"
        			{if rand %0
        				{call "_burn"}
        			}
        		}
            	}
        )

;============================================================================
 (define "cut_d_a_part"
    {if component %0
		{delay_ex 0.11
                		{tear "piece_medium_steel" bone %0
                			{impulse up 2 1 dir 2 1}
			}
		}
    }
)
(define "blast_d_a"
	{if component "%0"
		{spawn "ex_air_norm"}
		{fragments c4 0.5 r0 0.3 r1 0.4}
		{components "%0" break}
		{delay_ex 0.01 
			{bone hide "%0"}
			{volumes "%0" disable contact bullet blast}
			{volumes "comp_%0" disable bullet}
		}
	}
)
(define "fix_d_a"
		{components "%0" repair}
		{bone show "%0"}
		{volumes "%0" enable bullet blast}
)
 (define "blast_nera"
            {if component "nera%0"
		{delay_ex 0.11
                		{tear "piece_medium_steel" bone "nera%0"
                			{impulse up 2 1 dir 2 1}
			}
		}
            }
)
	{on "repair_d_a"
		("fix_d_a" args d_a1)("fix_d_a" args d_a2)("fix_d_a" args d_a3)("fix_d_a" args d_a4)("fix_d_a" args d_a5)
		("fix_d_a" args d_a6)("fix_d_a" args d_a7)("fix_d_a" args d_a8)("fix_d_a" args d_a9)("fix_d_a" args d_a10)
		("fix_d_a" args d_a11)("fix_d_a" args d_a12)("fix_d_a" args d_a13)("fix_d_a" args d_a14)("fix_d_a" args d_a15)
		("fix_d_a" args d_a16)("fix_d_a" args d_a17)("fix_d_a" args d_a18)("fix_d_a" args d_a19)("fix_d_a" args d_a20)
		("fix_d_a" args d_a21)("fix_d_a" args d_a22)("fix_d_a" args d_a23)("fix_d_a" args d_a24)("fix_d_a" args d_a25)
		("fix_d_a" args d_a26)("fix_d_a" args d_a27)("fix_d_a" args d_a28)("fix_d_a" args d_a29)("fix_d_a" args d_a30)
		("fix_d_a" args d_a31)("fix_d_a" args d_a32)("fix_d_a" args d_a33)("fix_d_a" args d_a34)("fix_d_a" args d_a35)
		("fix_d_a" args d_a36)("fix_d_a" args d_a37)("fix_d_a" args d_a38)("fix_d_a" args d_a39)("fix_d_a" args d_a40)
		("fix_d_a" args d_a41)("fix_d_a" args d_a42)("fix_d_a" args d_a43)("fix_d_a" args d_a44)("fix_d_a" args d_a45)
		("fix_d_a" args d_a46)("fix_d_a" args d_a47)("fix_d_a" args d_a48)("fix_d_a" args d_a49)("fix_d_a" args d_a50)
		("fix_d_a" args d_a51)("fix_d_a" args d_a52)("fix_d_a" args d_a53)("fix_d_a" args d_a54)("fix_d_a" args d_a55)
		("fix_d_a" args d_a56)("fix_d_a" args d_a57)("fix_d_a" args d_a58)("fix_d_a" args d_a59)("fix_d_a" args d_a60)
		("fix_d_a" args d_a61)("fix_d_a" args d_a62)("fix_d_a" args d_a63)("fix_d_a" args d_a64)("fix_d_a" args d_a65)
		("fix_d_a" args d_a66)("fix_d_a" args d_a67)("fix_d_a" args d_a68)("fix_d_a" args d_a69)("fix_d_a" args d_a70)
		("fix_d_a" args d_a71)("fix_d_a" args d_a72)("fix_d_a" args d_a73)("fix_d_a" args d_a74)("fix_d_a" args d_a75)
		("fix_d_a" args d_a76)("fix_d_a" args d_a77)("fix_d_a" args d_a78)("fix_d_a" args d_a79)("fix_d_a" args d_a80)
		("fix_d_a" args d_a81)("fix_d_a" args d_a82)("fix_d_a" args d_a83)("fix_d_a" args d_a84)("fix_d_a" args d_a85)
		("fix_d_a" args d_a86)("fix_d_a" args d_a87)("fix_d_a" args d_a88)("fix_d_a" args d_a89)("fix_d_a" args d_a90)
		("fix_d_a" args d_a91)("fix_d_a" args d_a92)("fix_d_a" args d_a93)("fix_d_a" args d_a94)("fix_d_a" args d_a95)
		("fix_d_a" args d_a96)("fix_d_a" args d_a97)("fix_d_a" args d_a98)("fix_d_a" args d_a99)("fix_d_a" args d_a100)
		("fix_d_a" args d_a101)("fix_d_a" args d_a102)("fix_d_a" args d_a103)("fix_d_a" args d_a104)("fix_d_a" args d_a105)
		("fix_d_a" args d_a106)("fix_d_a" args d_a107)("fix_d_a" args d_a108)("fix_d_a" args d_a109)("fix_d_a" args d_a110)
		("fix_d_a" args d_a111)("fix_d_a" args d_a112)("fix_d_a" args d_a113)("fix_d_a" args d_a114)("fix_d_a" args d_a115)
		("fix_d_a" args d_a116)("fix_d_a" args d_a117)("fix_d_a" args d_a118)("fix_d_a" args d_a119)("fix_d_a" args d_a120)
		("fix_d_a" args d_a121)("fix_d_a" args d_a122)("fix_d_a" args d_a123)("fix_d_a" args d_a124)("fix_d_a" args d_a125)
		("fix_d_a" args d_a126)("fix_d_a" args d_a127)("fix_d_a" args d_a128)("fix_d_a" args d_a129)("fix_d_a" args d_a130)
	}



    {on break_armor
	{if component "d_a"
("blast_d_a" args d_a1)("blast_d_a" args d_a2)("blast_d_a" args d_a3)("blast_d_a" args d_a4)("blast_d_a" args d_a5)
("blast_d_a" args d_a6)("blast_d_a" args d_a7)("blast_d_a" args d_a8)("blast_d_a" args d_a9)("blast_d_a" args d_a10)
("blast_d_a" args d_a11)("blast_d_a" args d_a12)("blast_d_a" args d_a13)("blast_d_a" args d_a14)("blast_d_a" args d_a15)
("blast_d_a" args d_a16)("blast_d_a" args d_a17)("blast_d_a" args d_a18)("blast_d_a" args d_a19)("blast_d_a" args d_a20)
("blast_d_a" args d_a21)("blast_d_a" args d_a22)("blast_d_a" args d_a23)("blast_d_a" args d_a24)("blast_d_a" args d_a25)
("blast_d_a" args d_a26)("blast_d_a" args d_a27)("blast_d_a" args d_a28)("blast_d_a" args d_a29)("blast_d_a" args d_a30)
("blast_d_a" args d_a31)("blast_d_a" args d_a32)("blast_d_a" args d_a33)("blast_d_a" args d_a34)("blast_d_a" args d_a35)
("blast_d_a" args d_a36)("blast_d_a" args d_a37)("blast_d_a" args d_a38)("blast_d_a" args d_a39)("blast_d_a" args d_a40)
("blast_d_a" args d_a41)("blast_d_a" args d_a42)("blast_d_a" args d_a43)("blast_d_a" args d_a44)("blast_d_a" args d_a45)
("blast_d_a" args d_a46)("blast_d_a" args d_a47)("blast_d_a" args d_a48)("blast_d_a" args d_a49)("blast_d_a" args d_a50)
("blast_d_a" args d_a51)("blast_d_a" args d_a52)("blast_d_a" args d_a53)("blast_d_a" args d_a54)("blast_d_a" args d_a55)
("blast_d_a" args d_a56)("blast_d_a" args d_a57)("blast_d_a" args d_a58)("blast_d_a" args d_a59)("blast_d_a" args d_a60)
("blast_d_a" args d_a61)("blast_d_a" args d_a62)("blast_d_a" args d_a63)("blast_d_a" args d_a64)("blast_d_a" args d_a65)
("blast_d_a" args d_a66)("blast_d_a" args d_a67)("blast_d_a" args d_a68)("blast_d_a" args d_a69)("blast_d_a" args d_a70)
("blast_d_a" args d_a71)("blast_d_a" args d_a72)("blast_d_a" args d_a73)("blast_d_a" args d_a74)("blast_d_a" args d_a75)
("blast_d_a" args d_a76)("blast_d_a" args d_a77)("blast_d_a" args d_a78)("blast_d_a" args d_a79)("blast_d_a" args d_a80)
("blast_d_a" args d_a81)("blast_d_a" args d_a82)("blast_d_a" args d_a83)("blast_d_a" args d_a84)("blast_d_a" args d_a85)
("blast_d_a" args d_a86)("blast_d_a" args d_a87)("blast_d_a" args d_a88)("blast_d_a" args d_a89)("blast_d_a" args d_a90)
("blast_d_a" args d_a91)("blast_d_a" args d_a92)("blast_d_a" args d_a93)("blast_d_a" args d_a94)("blast_d_a" args d_a95)
("blast_d_a" args d_a96)("blast_d_a" args d_a97)("blast_d_a" args d_a98)("blast_d_a" args d_a99)("blast_d_a" args d_a100)
("blast_d_a" args d_a101)("blast_d_a" args d_a102)("blast_d_a" args d_a103)("blast_d_a" args d_a104)("blast_d_a" args d_a105)
("blast_d_a" args d_a106)("blast_d_a" args d_a107)("blast_d_a" args d_a108)("blast_d_a" args d_a109)("blast_d_a" args d_a110)
("blast_d_a" args d_a111)("blast_d_a" args d_a112)("blast_d_a" args d_a113)("blast_d_a" args d_a114)("blast_d_a" args d_a115)
("blast_d_a" args d_a116)("blast_d_a" args d_a117)("blast_d_a" args d_a118)("blast_d_a" args d_a119)("blast_d_a" args d_a120)
("blast_d_a" args d_a121)("blast_d_a" args d_a122)("blast_d_a" args d_a123)("blast_d_a" args d_a124)("blast_d_a" args d_a125)
("blast_d_a" args d_a126)("blast_d_a" args d_a127)("blast_d_a" args d_a128)("blast_d_a" args d_a129)("blast_d_a" args d_a130)

		   {damage_report "body" "era_pierced"}	        	
else component "nera"
		("blast_nera" args 1)("blast_nera" args 2)("blast_nera" args 3)("blast_nera" args 4)("blast_nera" args 7)
		("blast_nera" args 6)("blast_nera" args 10)("blast_nera" args 11)("blast_nera" args 12)("blast_nera" args 13)
		("blast_nera" args 14)("blast_nera" args 15)("blast_nera" args 16)("blast_nera" args 8)("blast_nera" args 9)
		("blast_nera" args 5)("blast_nera" args 17)("blast_nera" args 18)("blast_nera" args 19)("blast_nera" args 20)
		("blast_nera" args 21)("blast_nera" args 22)("blast_nera" args 23)("blast_nera" args 24)("blast_nera" args 25)
		("blast_nera" args 26)("blast_nera" args 27)("blast_nera" args 28)("blast_nera" args 29)("blast_nera" args 30)
		("blast_nera" args 31)("blast_nera" args 32)("blast_nera" args 33)("blast_nera" args 34)("blast_nera" args 35)
		("blast_nera" args 36)("blast_nera" args 37)("blast_nera" args 38)("blast_nera" args 39)("blast_nera" args 40)
		("blast_nera" args 41)("blast_nera" args 42)("blast_nera" args 43)("blast_nera" args 44)("blast_nera" args 45)
		("blast_nera" args 46)("blast_nera" args 47)("blast_nera" args 48)("blast_nera" args 49)("blast_nera" args 50)
		("blast_nera" args 51)("blast_nera" args 52)("blast_nera" args 53)("blast_nera" args 54)("blast_nera" args 55)
		("blast_nera" args 56)("blast_nera" args 57)("blast_nera" args 58)("blast_nera" args 59)("blast_nera" args 60)
		("blast_nera" args 61)("blast_nera" args 62)("blast_nera" args 63)("blast_nera" args 64)("blast_nera" args 65)
		("blast_nera" args 66)("blast_nera" args 67)("blast_nera" args 68)("blast_nera" args 69)("blast_nera" args 70)
		("blast_nera" args 71)("blast_nera" args 72)("blast_nera" args 73)("blast_nera" args 74)("blast_nera" args 75)
		("blast_nera" args 76)("blast_nera" args 77)("blast_nera" args 78)("blast_nera" args 79)("blast_nera" args 80)
		("blast_nera" args 81)("blast_nera" args 82)("blast_nera" args 83)("blast_nera" args 84)("blast_nera" args 85)
		("blast_nera" args 86)("blast_nera" args 87)("blast_nera" args 88)("blast_nera" args 89)("blast_nera" args 90)
}

                {if name "blast"
                    {if volume "body"
                        {if rand 0.1 {kill_crew "gunner"}}
                        {if rand 0.1 {kill_crew "charger"}}
                        {if rand 0.1 {kill_crew "commander"}}
                        {if rand 0.1 {kill_crew "driver"}}
                        {if rand 0.1 {kill_crew "gunner2"}}
                        
                        {if not tagged "destroyed"
                            {call "mp_destroy"}
                        }
                    else volume "track"
                    }
                    {if volume "explosive"
                        {if rand 0.5 {call "explosive_broken"}}
                    }
                }
                    {if not user_control
                        {if volume "body"
                            {if rand 0.1 {kill_crew "gunner"}}
                            {if rand 0.1 {kill_crew "charger"}}
                            {if rand 0.1 {kill_crew "commander"}}
                            {if rand 0.1 {kill_crew "driver"}}
                        }
                    }
                
                    {if not flag "no_burn_volumes"
                        {if name "pierce"
                            {if volume "body"
                                {burn fx "smoke_dead_tank1" fake}
                                ;(mod not "mp"
                                ;    {call "rand_burn"}
                                ;)
                            else volume "track"
                                {burn fx "smoke_dead_tank1" fake}
                            }
                        }
                    }
    }
 
    {on break_armor_again
                {if component "engine"
                    ;{call "burn_by_engine"}
                }
                {if name "blast"
                    {if volume "body"
                        {if not tagged "destroyed"
                            {call "mp_destroy"}
                        }
                    }
                    {if volume "explosive"
                        {if rand 0.8 {call "explosive_broken"}}
                    }
                }
    }
;=====================================
    {on break
		{if component "body"
			{spawn "circledust_norm" "Turret"}
			{call "update_turret"}
	;		{tags add "body_brake"}
			{call "stat_break"}		
	;		{call "mp_destroy"}
	        {able select 0}
			{chassis_work 0} {components "move_indicator" break}
			{spawn "tank_die_particle" "Body"}
			{delay 1	{crew_emit}}
			{delay 2	{crew_emit}}
			{delay 3	{crew_emit}
			{tags add "body_brake"}
			}
			(mod "mp" 
			{tags add "break_manager"}
			{call "check_body_break"}
			)
			{if rand 0.25
			{add_view "smoke_dead_tree" "burn_fire_1a""FXfire3"}
			{view start "burn_fire_1a"}
			{delay 7.5 1.5{view stop "burn_fire_1a"}}
			else rand 0.5
			{add_view "smoke_tank_small" "burn_fire_2a""FXfire3"}
			{view start "burn_fire_2a"}
			{delay 7.5 1.5{view stop "burn_fire_2a"}}
			else rand 0.75
			{add_view "smoke_dead_tree1" "burn_fire_3a""FXfire3"}
			{view start "burn_fire_3a"}
			{delay 7.5 1.5{view stop "burn_fire_3a"}}
			else
			{add_view "smoke_dead_small1" "burn_fire_3a""FXfire3"}
			{view start "burn_fire_3a"}
			{delay 9.5 1.5{view stop "burn_fire_3a"}}
			}
			;--------------------End-----------------
			{if name "blast"
				{view start "smoke4"}
				{set "smoke4" 1}
				 {delay 2.3 {view start "smoke4_1"}}
				 {delay 25
					{view start "smoke4_2"}
					{delay 30
						{view stop "smoke4_2"}
					}
				 }
				{delay 30
					{view stop "smoke4"}
					{view stop "smoke4_1"}
					{set "smoke4" 0}
				}
			}
		else component "engine"
			{chassis_work 0} {components "move_indicator" break}
			{if flag "engine_started" {play_sound "engine_broken"}}
			{tags add "engine_brake"}
			{call "update_power"}
			{if not tagged "crit_system_destroyed"
				{tags add "crit_system_destroyed"}
				 else
				  {if not tagged "crit_system_destroyed2"
				   {tags add "crit_system_destroyed2"}
					    else
					    {components "body" break}
				}	  
			}
			{spawn "tank_die_particle" "engine"}
			{view start "smoke1"}
			{set "smoke1" 1}
			;(mod not "mp"
			;	{call "check_burn_emit"}
			;)
			{delay 90
				{view stop "smoke1"}
				{set "smoke1" 0}	
				;(mod not "mp"
				;	{call "check_burn_emit"}
				;)
			}
			;{call "burn_by_engine"}
		else component "trackleft" or component "trackright"
			{play_sound "track_broken"}
		else component "shield"
				("cut_shield_part" args "shieldr1")
				("cut_shield_part" args "shieldr2")
				("cut_shield_part" args "shieldr3")
				("cut_shield_part" args "shieldr4")
				("cut_shield_part" args "shieldr5")
				("cut_shield_part" args "shieldr6")
			  ("cut_shield_part" args "shieldr7")
			  ("cut_shield_part" args "shieldr8")
			  ("cut_shield_part" args "shieldr9")
			  ("cut_shield_part" args "shieldr10")
			  ("cut_shield_part" args "shieldr11")
			  ("cut_shield_part" args "shieldr12")
			  ("cut_shield_part" args "shieldr13")
			  ("cut_shield_part" args "shieldr14")
			  ("cut_shield_part" args "shieldr15")
			  ("cut_shield_part" args "shieldr16")
				("cut_shield_part" args "shieldl1")
				("cut_shield_part" args "shieldl2")
				("cut_shield_part" args "shieldl3")
				("cut_shield_part" args "shieldl4")
				("cut_shield_part" args "shieldl5")
				("cut_shield_part" args "shieldl6")
				("cut_shield_part" args "shieldl7")
				("cut_shield_part" args "shieldl8")
				("cut_shield_part" args "shieldl9")
				("cut_shield_part" args "shieldl10")
				("cut_shield_part" args "shieldl11")
				("cut_shield_part" args "shieldl12")
				("cut_shield_part" args "shieldl13")
				("cut_shield_part" args "shieldl14")
				("cut_shield_part" args "shieldl15")
				("cut_shield_part" args "shieldl16")
		else component "turret"
	;=================================
			{add_view "smoke_black" "burn_fire_1a""FXfire3"}
			{view start "burn_fire_1a"}
			{delay 7.5 1.5{view stop "burn_fire_1a"}}
	;=================================
			{tags add "turret_brake"}
			{call "emit_by_turret"}
			{if not tagged "crit_system_destroyed"
				{tags add "crit_system_destroyed"}
				 else
				  {if not tagged "crit_system_destroyed2"
				   {tags add "crit_system_destroyed2"}
					    else
					    {components "body" break}
				}	  
			}
	;--------------------End-----------------
		else component "trackright"
			{tags add "chassis_brake"}
			{chassis_work 0} {components "move_indicator" break}
		else component "trackleft"
			{tags add "chassis_brake"}
			{chassis_work 0} {components "move_indicator" break}
		else component "gun"
			{tags add "gun_brake"}
			  {spawn "metal_hit_bul"}
			  {weapon_work "gun" 0}
				{call "update_gun"}
			  }
		{call "update_lights"}
		{call "update_power"}
		{call "update_moveability"}
}