{"car"
	{on spawn
		{link_sound "flame" "fire/big"}

		{if not rain
			{add_view	"dustrun_small"			"on_grass"			"FXtraceR1"}
			{add_view	"dustrun_small"			"on_grass"			"FXtraceL1"}
			{add_view	"dustrun_sand_small"	"on_sand"			"FXtraceR1"}
			{add_view	"dustrun_sand_small"	"on_sand"			"FXtraceL1"}
			{add_view	"dustrun_snow_small"	"on_snow"			"FXtraceR1"}
			{add_view	"dustrun_snow_small"	"on_snow"			"FXtraceL1"}
			{add_view	"dustrun_small"			"on_country_road"	"FXtraceR1"}
			{add_view	"dustrun_small"			"on_country_road"	"FXtraceL1"}
			{add_view	"dustrun_small"			"on_ground"			"FXtraceR1"}
			{add_view	"dustrun_small"			"on_ground"			"FXtraceL1"}
		else
			{add_view	"engine_steam"			"engine_steam"		"FXfire1"}
		}
		{add_view	"wash_moto_dipper"			"on_water"			"FXtraceR1"}
		{add_view	"wash_moto_dipper"			"on_water"			"FXtraceL1"}
;		{add_view	"wash_moto_dipper"			"on_mud"			"FXtraceR1"}
;		{add_view	"wash_moto_dipper"			"on_mud"			"FXtraceL1"}
		{add_view	"wash_moto"		"on_puddle"			"FXtraceR1"}
		{add_view	"wash_moto"		"on_puddle"			"FXtraceL1"}

		{add_view	"smoke_black"			"smoke1"			"FXfire1"}
		{add_view	"smoke_black"			"smoke2"			"engine"}
		{add_view	"steam"					"steam"				"FXsteam"}
		{add_view	"exhaust_dark_small"	"exhaust"			"FXsmoke1"}
		{call "init_burnout"}
		{call "update_syst_on_spawn"}
	}

	{on "add_movement_sound"
		{link_sound "move"			"vehicle/wheels/car"}
		{link_sound "move_end"		"vehicle/wheels/car_end"}
		{link_sound "engine"		"vehicle/engine_cw/car"}
		{link_sound "engine_end"	"vehicle/engine_cw/car_end"}
		{link_sound "exhaust"		"vehicle/engine_cw/car_up"}
	}
;	{on "add_hatch_sound"
;		{link_sound "hatch_in"			"vehicle/other/door_in"}
;		{link_sound "hatch_out"			"vehicle/other/door_out"}
;	}
	{on "bullet_reflect"
;		{if not armor_health 1 and not flag "broken"
		{if not flag "broken"
			{if not stuff "bullet" and not stuff "fg" and not stuff "fr"
				{talk "tank_bullet_reflect"}
				{call "talk_target_bullet_reflected"}
			}
		}
	}
	{on "talk_target_destroyed"
		{call "destroyed_by_spy"}
		{talk "tank_leave"}
		{call "talk_target_destroyed_car"}
	}
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

		{call "check_burn_emit"}
											
		{reset_manual_control}
		{able select 0}
		{able repaired 0}
		{unlink_trailer}
	}
	{on bullet_hit
;=============part of projectile system by Timosh=============
		{if stuff "radar_ammo"
		else stuff "laser_ammo"
		else stuff "proj_pointer"
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
		else stuff "IR_ff_ammo"
;==========================
		else volume "glass"
		 	{call "break_glass"}
		 else volume "cabin"
		 	{call "break_glass"}
		else volume "glass1"
		 	{call "break_glass1"}
		 else volume "glass2"
			{call "break_glass2"}
		 else volume "glass3"
			{call "break_glass3"}
		else volume "glass4"
			{call "break_glass4"}
		else volume "glass5"
			{call "break_glass5"}
		else volume "glass6"
			{call "break_glass6"}
		else volume "glass7"
			{call "break_glass7"}
		else volume "glass8"
			{call "break_glass8"}
		else volume "glass9"
			{call "break_glass9"}
		else volume "glass10"
			{call "break_glass10"}
		}
		{if stuff "proj_pointer"
		else stuff "shell autocannon_small fg"
			{blastwave c4 0.5 r0 1.4 r1 1.7 position}
			{if rand 0.05 {components "engine" break} {call "_burn"}
			 {delay 1 {crew_emit}}
			 {delay 2 {crew_emit}}
			 {delay 3 {crew_emit}}
			}
		else stuff "shell autocannon_small cm"
			{blastwave c4 0.5 r0 1.4 r1 1.7 position}
			{if rand 0.05 {components "engine" break} {call "_burn"}
			 {delay 1 {crew_emit}}
			 {delay 2 {crew_emit}}
			 {delay 3 {crew_emit}}
			}
		}
	}

	{on pierce
	  {if stuff "radar_ammo"
	  else stuff "laser_ammo"
	  else stuff "proj_pointer"
	  else
		{if volume "body"
			{if not work "body"
				{if rand 0.05 {call "_burn"}
				 {delay 1 {crew_emit}}
			 {delay 2 {crew_emit}}
			 {delay 3 {crew_emit}}
				}
			}
		else volume "engine"
			{if rand 0.7
				{components "engine" break}
				{if rand 0.2
					{call "_burn"}
					{delay 1 {crew_emit}}
			 {delay 2 {crew_emit}}
			 {delay 3 {crew_emit}}
				}
			else stuff "shell"
				{components "engine" break}
				{if rand 0.6
					{call "_burn"}
					{delay 1 {crew_emit}}
			 {delay 2 {crew_emit}}
			 {delay 3 {crew_emit}}
				}
			}
		else volume "gun"
			{components "gun" break}
		else volume "gun1"
			{components "gun1" break}
		else volume "gun2"
			{components "gun2" break}
		else volume "gun3"
			{components "gun3" break}
		else volume "mgun"
			{components "mgun" break}
		else volume "mgun1"
			{components "mgun1" break}
		else volume "mgun2"
			{components "mgun2" break}
		else volume "mgun3"
			{components "mgun3" break}
		else volume "mgun4"
			{components "mgun4" break}
		else volume "mgun5"
			{components "mgun5" break}
		else volume "mgun6"
			{components "mgun6" break}
		}
		{if stuff  "hmgun"
			;{blastwave c4 0.5 r0 0.1 r1 0.2 position}
		else stuff "rok"
			{if rand 0.33 {blastwave c4 0.5 r0 1.0 r1 1.1 position}
			else rand 0.66 {blastwave c4 0.7 r0 1.0 r1 1.1 position}
			else {blastwave c4 0.9 r0 1.0 r1 1.1 position}
			}
		else stuff "ptrk"
			{if rand 0.33 {blastwave c4 0.5 r0 1.4 r1 1.7 position}
			else rand 0.66 {blastwave c4 0.7 r0 1.4 r1 1.7 position}
			else {blastwave c4 3 r0 0.9 r1 1.7 position}
			}
			{if component "body" 
				 {if rand 0.3 
				{components "body" break}
				{call "mp_destroy"}
				{tags add "destroyed"}
				 }
			}
		else stuff "cm"
		{components "body" break}
		{call "mp_destroy"}
		{tags add "destroyed"}
			{if rand 0.33 {blastwave c4 0.5 r0 1.4 r1 1.7 position}
			else rand 0.66 {blastwave c4 0.7 r0 1.4 r1 1.7 position}
			else {blastwave c4 0.9 r0 1.4 r1 1.7 position}
			}
			{bullet_detonate}
		else stuff "fg" 
		{components "body" break}
		{call "mp_destroy"}
		{tags add "destroyed"}
			{if rand 0.33 {blastwave c4 0.5 r0 1.0 r1 1.1 position}
			else rand 0.66 {blastwave c4 0.7 r0 1.0 r1 1.1 position}
			else {blastwave c4 0.9 r0 1.0 r1 1.1 position}
			}
			{bullet_detonate}
		else stuff "bullet"
		else stuff "ap"
		else stuff "apcr"
		else stuff "apcr_h"
		else
		{components "body" break}
		{call "mp_destroy"}
		{tags add "destroyed"}
			{if rand 0.33 {blastwave c4 0.5 r0 1.4 r1 1.7 position}
			else rand 0.66 {blastwave c4 0.7 r0 1.4 r1 1.7 position}
			else {blastwave c4 3 r0 0.9 r1 1.7 position}
			}
		}
		{if stuff "ic hmgun"
		  {if rand 0.3
			{fire radius 0.5 time 0.3 heating 10}
		  }
		else stuff "ic autocannon_small"
		  {if rand 0.6
			{fire radius 0.5 time 0.3 heating 10}
		  }
		else stuff "ic"
		  {if rand 0.5
			{fire radius 0.5 time 0.3 heating 10}
		  }
		}
	  }
       {if not stuff "proj_pointer"
	{if component "driver_panel"
		{components "driver_panel" break}
		{burn fx "smoke_dead_tank2" fake}
	else component "transmission"
		{components "transmission" break}
		{burn fx "smoke_dead_tank2" fake}
	else component "driver_place"	
	{if crew_in_place "driver"
     {damage_report "body" "driver_dead"}
    }
	{kill_crew "driver"}{icon_event "crew_dead" 10}
	{crew_enable place "driver" 0} {set "crew_tempdisabled" 1}
	{delay 10 {crew_enable place "driver" 1} {set "crew_tempdisabled" 0}}
	else component "driver1_place" 
	{if crew_in_place "driver1"
     {damage_report "body" "driver_dead"}
    }
	{kill_crew "driver1"}{icon_event "crew_dead" 10}
	{crew_enable place "driver1" 0} {set "crew_tempdisabled" 1}
	{delay 10 {crew_enable place "driver1" 1} {set "crew_tempdisabled" 0}}
	else component "gunner_place"	
	{if crew_in_place "gunner"
     {damage_report "body" "gunner_dead"}
    }
	{kill_crew "gunner"}{icon_event "crew_dead" 10}
	{crew_enable place "gunner" 0} {set "crew_tempdisabled" 1}
	{delay 10 {crew_enable place "gunner" 1} {set "crew_tempdisabled" 0}}
	else component "gunner1_place" 
	{if crew_in_place "gunner1"
     {damage_report "body" "shooter_dead"}
    }
	{kill_crew "gunner1"}{icon_event "crew_dead" 10}
	{crew_enable place "gunner1" 0} {set "crew_tempdisabled" 1}
	{delay 10 {crew_enable place "gunner1" 1} {set "crew_tempdisabled" 0}}
	else component "gunner2_place" 
	{if crew_in_place "gunner2"
     {damage_report "body" "shooter_dead"}
    }
	{kill_crew "gunner2"}{icon_event "crew_dead" 10}
	{crew_enable place "gunner2" 0} {set "crew_tempdisabled" 1}
	{delay 10 {crew_enable place "gunner2" 1} {set "crew_tempdisabled" 0}}
	else component "charger_place" 
	{if crew_in_place "charger"
     {damage_report "body" "charger_dead"}
    }
	{kill_crew "charger"}{icon_event "crew_dead" 10}
	{crew_enable place "charger" 0} {set "crew_tempdisabled" 1}
	{delay 10 {crew_enable place "charger" 1} {set "crew_tempdisabled" 0}}
	else component "commander_place" 
	{if crew_in_place "commander"
     {damage_report "body" "commander_dead"}
    }
	{kill_crew "commander"}{icon_event "crew_dead" 10}
	{crew_enable place "commander" 0} {set "crew_tempdisabled" 1}
	{delay 10 {crew_enable place "commander" 1} {set "crew_tempdisabled" 0}}
	else component "commander1_place" 
	{if crew_in_place "commander1"
     {damage_report "body" "commander_dead"}
    }
	{kill_crew "commander1"}{icon_event "crew_dead" 10}
	{crew_enable place "commander1" 0} {set "crew_tempdisabled" 1}
	{delay 10 {crew_enable place "commander1" 1} {set "crew_tempdisabled" 0}}
	else component "seat1_place"	{kill_crew "seat1"}
	else component "seat2_place"	{kill_crew "seat2"}
	else component "seat3_place"	{kill_crew "seat3"}
	else component "seat4_place"	{kill_crew "seat4"}
	else component "seat5_place"	{kill_crew "seat5"}
	else component "seat6_place"	{kill_crew "seat6"}
	else component "seat7_place"	{kill_crew "seat7"}
	else component "seat8_place"	{kill_crew "seat8"}
	else component "seat9_place"	{kill_crew "seat9"}
	else component "seat10_place" {kill_crew "seat10"}
	else component "seat11_place" {kill_crew "seat11"}
	else component "seat12_place" {kill_crew "seat12"}
	else component "seat13_place"	{kill_crew "seat13"}
	else component "seat14_place"	{kill_crew "seat14"}
	else component "seat15_place"	{kill_crew "seat15"}
	else component "seat16_place"	{kill_crew "seat16"}
	else component "seat17_place"	{kill_crew "seat17"}
	else component "seat18_place"	{kill_crew "seat18"}
	else component "seat19_place"	{kill_crew "seat19"}
	else component "seat20_place"	{kill_crew "seat20"}
	else component "seat21_place"	{kill_crew "seat21"}
	else component "seat22_place"	{kill_crew "seat22"}
	else component "seat23_place"	{kill_crew "seat23"}
	else component "seat24_place"	{kill_crew "seat24"}
	else component "seat25_place"	{kill_crew "seat25"}


	else component "driver_triplex"
		{components "driver_triplex" break}
		{spawn "glass_hit" }
	else component "commander_triplex"
		{components "commander_triplex" break}
		{spawn "glass_hit" }
	else component "additional_triplex"
		{components "additional_triplex" break}
		{spawn "glass_hit"}
	else component "additional_triplex1"
		{components "additional_triplex1" break}
		{spawn "glass_hit"}
	else component "additional_triplex2"
		{components "additional_triplex2" break}
		{spawn "glass_hit"}
	else component "additional_triplex3"
		{components "additional_triplex3" break}
		{spawn "glass_hit"}
	else component "additional_triplex4"
		{components "additional_triplex4" break}
		{spawn "glass_hit"}
	else component "additional_triplex5"
		{components "additional_triplex5" break}
		{spawn "glass_hit"}
	else component "ammo_storage_main"
		{damage_report "ammo_storage_main" "ammo_storage_damaged"}
		{spawn "metal_hit_bul"}
		{if  explosive_amount 750
			{if rand 0.95 {components "ammo_storage_main" break}}
		else  explosive_amount 500
			{if rand 0.8 {components "ammo_storage_main" break}}
		else  explosive_amount 250
			{if rand 0.65 {components "ammo_storage_main" break}}
		else  explosive_amount 100
			{if rand 0.5 {components "ammo_storage_main" break}}
		}
	else  component "ammo_storage_autocannon"
		{damage_report "ammo_storage_autocannon" "ammo_storage_damaged"}
		{spawn "metal_hit_bul"}
		{if rand 0.55 {components "ammo_storage_autocannon" break}}
	else  component "ammo_storage_mgun"
		{damage_report "ammo_storage_mgun" "ammo_storage_damaged"}
		{spawn "metal_hit_bul"}
		{if rand 0.45 {components "ammo_storage_mgun" break}}
	else component "autoloader"
		{components "autoloader" break}
		{burn fx "smoke_dead_tank2" fake}
	else component "fuel_tank_internal_a"
		{burn fx "smoke_dead_tank2" fake}
		{if stuff "cm" 
			{if rand 0.85 {components "fuel_tank_internal_a" break}}
		else stuff "rok"
			{if rand 0.85 {components "fuel_tank_internal_a" break}}
		else stuff "fg"
			{if rand 0.8 {components "fuel_tank_internal_a" break}}
		else stuff "ap"
			{if rand 0.25 {components "fuel_tank_internal_a" break}}
		else stuff "apcr"
			{if rand 0.2 {components "fuel_tank_internal_a" break}}
		else stuff "apcr_h"
			{if rand 0.2 {components "fuel_tank_internal_a" break}}
		else 
			{if rand 0.5 {components "fuel_tank_internal_a" break}}
		}
		
	else component "fuel_tank_internal_b"
		{burn fx "smoke_dead_tank2" fake}
		{if stuff "cm" 
			{if rand 0.85 {components "fuel_tank_internal_b" break}}
		else stuff "rok"
			{if rand 0.85 {components "fuel_tank_internal_b" break}}
		else stuff "fg"
			{if rand 0.8 {components "fuel_tank_internal_b" break}}
		else stuff "ap"
			{if rand 0.25 {components "fuel_tank_internal_b" break}}
		else stuff "apcr"
			{if rand 0.2 {components "fuel_tank_internal_b" break}}
		else stuff "apcr_h"
			{if rand 0.2 {components "fuel_tank_internal_b" break}}
		else 
			{if rand 0.5 {components "fuel_tank_internal_b" break}}
		}
		
	else component "fuel_tank_internal_c"
		{burn fx "smoke_dead_tank2" fake}
		{if stuff "cm" 
			{if rand 0.85 {components "fuel_tank_internal_c" break}}
		else stuff "rok"
			{if rand 0.85 {components "fuel_tank_internal_c" break}}
		else stuff "fg"
			{if rand 0.8 {components "fuel_tank_internal_c" break}}
		else stuff "ap"
			{if rand 0.25 {components "fuel_tank_internal_c" break}}
		else stuff "apcr"
			{if rand 0.2 {components "fuel_tank_internal_c" break}}
		else stuff "apcr_h"
			{if rand 0.2 {components "fuel_tank_internal_c" break}}
		else 
			{if rand 0.5 {components "fuel_tank_internal_c" break}}
		}
		
	else component "fuel_tank_internal_d"
		{burn fx "smoke_dead_tank2" fake}
		{if stuff "cm" 
			{if rand 0.85 {components "fuel_tank_internal_d" break}}
		else stuff "rok"
			{if rand 0.85 {components "fuel_tank_internal_d" break}}
		else stuff "fg"
			{if rand 0.8 {components "fuel_tank_internal_d" break}}
		else stuff "ap"
			{if rand 0.25 {components "fuel_tank_internal_d" break}}
		else stuff "apcr"
			{if rand 0.2 {components "fuel_tank_internal_d" break}}
		else stuff "apcr_h"
			{if rand 0.2 {components "fuel_tank_internal_d" break}}
		else 
			{if rand 0.5 {components "fuel_tank_internal_d" break}}
		}
		
	else component "fuel_tank_external_a"
		{burn fx "smoke_dead_tank2" fake}
		{if stuff "cm" 
			{if rand 0.85 {components "fuel_tank_external_a" break}}
		else stuff "rok"
			{if rand 0.85 {components "fuel_tank_external_a" break}}
		else stuff "fg"
			{if rand 0.8 {components "fuel_tank_external_a" break}}
		else stuff "ap"
			{if rand 0.25 {components "fuel_tank_external_a" break}}
		else stuff "apcr"
			{if rand 0.2 {components "fuel_tank_external_a" break}}
		else stuff "apcr_h"
			{if rand 0.2 {components "fuel_tank_external_a" break}}
		else 
			{if rand 0.5 {components "fuel_tank_external_a" break}}
		}
	else component "fuel_tank_external_b"
		{burn fx "smoke_dead_tank2" fake}
		{if stuff "cm" 
			{if rand 0.85 {components "fuel_tank_external_b" break}}
		else stuff "rok"
			{if rand 0.85 {components "fuel_tank_external_b" break}}
		else stuff "fg"
			{if rand 0.8 {components "fuel_tank_external_b" break}}
		else stuff "ap"
			{if rand 0.25 {components "fuel_tank_external_b" break}}
		else stuff "apcr"
			{if rand 0.2 {components "fuel_tank_external_b" break}}
		else stuff "apcr_h"
			{if rand 0.2 {components "fuel_tank_external_b" break}}
		else 
			{if rand 0.5 {components "fuel_tank_external_b" break}}
		}
	else component "fuel_tank_external_c"
		{burn fx "smoke_dead_tank2" fake}
		{if stuff "cm" 
			{if rand 0.85 {components "fuel_tank_external_c" break}}
		else stuff "rok"
			{if rand 0.85 {components "fuel_tank_external_c" break}}
		else stuff "fg"
			{if rand 0.8 {components "fuel_tank_external_c" break}}
		else stuff "ap"
			{if rand 0.25 {components "fuel_tank_external_c" break}}
		else stuff "apcr"
			{if rand 0.2 {components "fuel_tank_external_c" break}}
		else stuff "apcr_h"
			{if rand 0.2 {components "fuel_tank_external_c" break}}
		else 
			{if rand 0.5 {components "fuel_tank_external_c" break}}
		}
	else component "fuel_tank_external_d"
		{burn fx "smoke_dead_tank2" fake}
		{if stuff "cm" 
			{if rand 0.85 {components "fuel_tank_external_d" break}}
		else stuff "rok"
			{if rand 0.85 {components "fuel_tank_external_d" break}}
		else stuff "fg"
			{if rand 0.8 {components "fuel_tank_external_d" break}}
		else stuff "ap"
			{if rand 0.25 {components "fuel_tank_external_d" break}}
		else stuff "apcr"
			{if rand 0.2 {components "fuel_tank_external_d" break}}
		else stuff "apcr_h"
			{if rand 0.2 {components "fuel_tank_external_d" break}}
		else 
			{if rand 0.5 {components "fuel_tank_external_d" break}}
		}
	else component "gun2"
		{components "gun2" break}
	else component "gun3"
		{components "gun3" break}
	else component "mgun"
		{components "mgun" break}
	else component "mgun1"
		{components "mgun1" break}
	else component "mgun2"
		{components "mgun2" break}
	else component "mgun3"
		{components "mgun3" break}
	else component "mgun4"
		{components "mgun4" break}
	else component "mgun5"
		{components "mgun5" break}
	else component "mgun6"
		{components "mgun6" break}
	else component "mgun20"
		{components "mgun20" break}
	else component "mgun21"
		{components "mgun21" break}
	else component "turret_ring"
		{burn fx "smoke_dead_tank2" fake}
		{components "turret_ring" break}
	else component "panel_engine_connectors"
		{burn fx "smoke_dead_tank2" fake}
		{components "panel_engine_connectors" break}
	else component "turret_move_engine"
		{burn fx "smoke_dead_tank2" fake}
		{components "turret_move_engine" break}
	else component "front_wheels"
		{burn fx "smoke_dead_tank2" fake}
		{components "front_wheels" break}
	else component "stabilizer"
		{components "stabilizer" break}
		{burn fx "smoke_dead_tank2" fake}
	else component "gunner_panel"
		{components "gunner_panel" break}
		{burn fx "smoke_dead_tank2" fake}
	else component "ppu"
		{components "ppu" break}
		{burn fx "smoke_dead_tank2" fake}
	else component "apu"
		{components "apu" break}
		{burn fx "smoke_dead_tank2" fake}
	else component "body" 
	       {if not tagged "destroyed"
				{damage_report "body" "body_pierced"}
	       }
	       {if work "hull_integrity"
		{if stuff "cm" 
			{components "hull_integrity" break}
		else stuff "rok"
			{components "hull_integrity" break}
		else stuff "fg"
			{if rand 0.85 {components "hull_integrity" break}}
		else stuff "ap"
			{if rand 0.5 {components "hull_integrity" break}}
		else stuff "apcr"
			{if rand 0.75 {components "hull_integrity" break}}		
		else stuff "apcr_h"
			{if rand 0.75 {components "hull_integrity" break}}	
		else 
			{if rand 0.7 {components "hull_integrity" break}}
		}
	      }
	else component "turret" 
	       {if not tagged "destroyed"
		{damage_report "turret" "turret_pierced"}
	       }
	  }
    }
	}
	
	{on break_armor
		{if name "pierce"
			{if volume "fuel"
				{call "pierce_fuel"}
			}
		else name "blast"                   
			{if component "body"
			else volume "inventory"
				{call "blast_body"}
			else component "engine"
				{if min_energy 10
					{call "_burn"}
					{delay 1 {crew_emit}}
			 {delay 2 {crew_emit}}
			 {delay 3 {crew_emit}}
				else min_energy 6
					{if rand 0.5 
						{call "_burn"}
						{delay 1 {crew_emit}}
			 {delay 2 {crew_emit}}
			 {delay 3 {crew_emit}}
					}
				else min_energy 3
					{if rand 0.2 
						{call "_burn"}
						{delay 1 {crew_emit}}
			 {delay 2 {crew_emit}}
			 {delay 3 {crew_emit}}
					}
			}
			else component "cabin"
				{call "break_glass"}
			else component "bodyback"
			else min_energy 10
				{call "blast_body"}
			}
		{call "check_talk_target_broke_component"}
		}
	}
	{on break_armor_again
		{if name "blast"
			{if component "body"
				{call "blast_body"}
			else volume "inventory"
				{call "blast_body"}
			else component "engine"
				{call "_burn"}
				{delay 1 {crew_emit}}
			 {delay 2 {crew_emit}}
			 {delay 3 {crew_emit}}
			else component "cabin"
				{call "blast_body"}
			else component "bodyback"
				{call "blast_body"}
;			else
;				{call "blast_body"}
			}
		}
	}

	{on "blast_body"
		{if min_energy 40
			{impulse up 1.5 0.5 dir 1.5 0.5}
			{call "explosion"}
		 else min_energy 25
			{impulse up 0.8 0.3 dir 0.8 0.3}
			{call "explosion"}
		 else min_energy 5
            {call "explosion"}			
		}
		;{call "explosion"}
	}
	{on "pierce_fuel"
		{if rand 0.5
			{volumes "fuel" disable bullet contact blast}
			{spawn "tank_die_particle"}
			{call "burn"}
			{delay 1 {crew_emit}}
			 {delay 2 {crew_emit}}
			 {delay 3 {crew_emit}}
		}
	}
	{on "break_glass"
		{volumes "glass" disable bullet contact}
	 	{spawn "glass_hit2" "glass" x}
	 	{delay 0.1
		 	{bone cut "glass"}
	 	}
	}
	(define "break_glass_event"
		{on "break_glass%0"
			{volumes "glass%0" disable bullet contact}
		 	{spawn "glass_hit2" "glass%0" x}
		 	{delay 0.1
			 	{bone cut "glass%0"}
		 	}
		}
	)
	("break_glass_event" args 1)
	("break_glass_event" args 2)
	("break_glass_event" args 3)
	("break_glass_event" args 4)
	("break_glass_event" args 5)
	("break_glass_event" args 6)
	("break_glass_event" args 7)
	("break_glass_event" args 8)
	("break_glass_event" args 9)
	("break_glass_event" args 10)

	{on contact
		{if not impregnable
			{if effector_velocity 15
				{if effector "tank"
					{call "crush"}
				else effector "railway"
					{call "crush"}
				}
			else effector_velocity 10
				{if effector "tank"
					{component break}
				else effector "railway"
					{component break}
				}
			else effector_velocity 3
				{if effector "big part"
					{component break}
				}
			}
		}
	}
	{on fire "gun"
			{call "check_autoloader"}
	}

	{on "update_gun" overload
		{if work "gun"
			 {if work "stabilizer"
			   {if work "gunner_panel"
				  {if not tagged "contusion"
						{if not tagged "cw_autoloader_stuck"
							{weapon_work "gun" 1}
						else {weapon_work "gun" 0}}
				  else {weapon_work "gun" 0}}
			   else {weapon_work "gun" 0}}
			 else {weapon_work "gun" 0}}
		else {weapon_work "gun" 0}}
	}

	{on break
		{if component "cabin"
			{spawn "car_die_particle"}
			{volumes "cabin" disable bullet}
			{volumes "glass" disable bullet contact}
			{crew_enable group "crew" 0}
			{view start "smoke3"}
    		{delay 10 {view stop "smoke3"}}
    	else component "body"
			{if not tagged "crit_system_destroyed"
				{tags add "crit_system_destroyed"}
			else
				{components "body" break}
				{call "mp_destroy"}
				{tags add "destroyed"}
			}
			{spawn "car_die_particle"}
			{delay 1 {crew_emit}}
			{delay 2 {crew_emit}}
			{delay 3 {crew_emit}}
			{chassis_work 0} {components "move_indicator" break}
			{call "update_turret"}
			{tags add "body_brake"}
		else component "engine"
			{if flag "engine_started" {play_sound "engine_broken"}}
            {spawn "car_die_particle"}
			{view start "smoke2"}
			{delay 40 {view stop "smoke2"}}
			{view start "steam"}
			{delay 2  {view stop "steam"}}
			{tags add "no_power"}
			{components "power_indicator" break}
			{chassis_work 0} {components "move_indicator" break}
			{tags add "engine_brake"}
			{call "update_power"}
		else component "turret"
			{tags add "turret_brake"}
			{call "update_turret"}

		else component "gun"
			{if not tagged "destroyed"
				{damage_report "turret" "gun2:ptur_damaged"}
				{spawn "metal_hit_bul"}
				{tags add "gun_damaged"}
				{weapon_work "gun" 0}
				{if ammo_tag_for_weapon "gun" "ammo"
					{spawn "ex_air_big"}
					{fragments c4 2 r0 3 r1 4 position}
				}
			}
		}
		{call "update_lights"}
		{call "update_power"}
		{call "update_moveability"}
	}
	{on repair overload
		{inherited}
		{if component "cabin"
			{crew_enable group "crew" 1}
			{view stop "smoke2"}
		else component "engine"
            {tags remove "engine_brake"}
			{if tagged "crit_system_destroyed2"
				{tags remove "crit_system_destroyed2"}
			else
				  {if tagged "crit_system_destroyed"
				   {tags remove "crit_system_destroyed"}
				  }
			}
			{call "update_power"}
			{call "update_moveability"}

			{components "ammo_storage_mgun" repair}
			{components "ammo_storage_autocannon" repair}
			{components "ammo_storage_main" repair}
			{components "fuel_tank_internal_a" repair}
			{components "fuel_tank_internal_b" repair}
			{components "fuel_tank_internal_c" repair}
			{components "fuel_tank_internal_d" repair}
		else component "turret"
            {call "update_turret"}
			{if tagged "crit_system_destroyed2"
		{tags remove "crit_system_destroyed2"}
		 else
		  {if tagged "crit_system_destroyed"
		   {tags remove "crit_system_destroyed"}
		  }
            ; else
		 ; {if tagged "crit_system_destroyed3"
		  ; {tags remove "crit_system_destroyed3"}
		  ;} 		  
		}
            {tags remove "turret_brake"}
			{components "turret_ring" repair}
            {tags remove "turret_ring_broken"}
		else component "gun"
			{damage_report "gun" "gun_repaired"}
			{tags remove "gun_damaged"}
			{weapon_work "gun" 1}
		else component "body"
			{call "update_turret"}
			{tags remove "body_brake"}
		}
		{call "update_lights"}
		{call "update_power"}
		{call "update_moveability"}
	}

	{on "burn"
		{if not burned
			{call "_burn"}
			{delay 1 {crew_emit}}
			 {delay 2 {crew_emit}}
			 {delay 3 {crew_emit}}
		}
	}
	{on "check_burn_emit"
		{call "burn_emit"}
	}
	{on "_explosion"
		{add_view "smoke_dead_norm" "deathfx" "fxfire1"}
		{if not flag "crush"
			{spawn "tank_die" "Basis"}
			{spawn "tank_die_particle"}
			{impulse up 2.5 1.5 dir 2 1}
		}
	}
	{on "spawn_shellhole"
		{spawn "shellhole_dead_car2" "Basis"}
	}
	{on "tear"
		{if game_param 	"biom" "snow"
			{spawn	"spheredust_small_w"}
		else
			{spawn	"spheredust_small"}
		}
		{component destroy}
		{if volume "bodyback"
			{volume disable visible bullet contact}
		}
		{tear "piece_medium_steel" bone from_volume
			{impulse up 2 1 dir 2 1}
			{add_view "smoke_black" "smoke" "basis"}
			{view start "smoke"}
			{delay_effect 10 5 "pause"}
		}
	}
	{on "slice_load"
		{if name "car_part"
			{with_effector
				{add_view "smoke_black" "smoke" "basis"}
			}
		}
	}
	{on "cut_parts"
		{add_view "smoke_dead_norm" "deathfx" "fxfire1"}
		{view start "deathfx"}
		(define "cut_part"
			{tear "piece_medium_steel" bone %0
				{impulse up 4 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 6 no_position}
				{delay_effect 20 5 "stop"}
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
		;cut teared bones after SetSkeleton
		{if flag "cabine_teared"
			{bone cut "cabin"}
		}
		{if flag "engine_teared"
			{bone cut "engine"}
		}
		{delay 14 5 {view stop "deathfx"}}
	}
	{on "crush"
    	{component destroy}
    	{if volume "body"
    		{set "crush" 1}
    		{call "explosion"}
    	}
	}
	{on blast
		{if min_energy 7
			{call "explosion"}
		else min_energy 4
			{components "body" break}
		}
	}
	{on "sp_convoy_attack"	;for sp only
		{spawn "sp_convoy_assistor" "basis" x no_normal no_position}
	}
}

{"armored_glass"
	(define "break_glass_event"
		{on "break_glass%0" overload
		 	{spawn "glass_hit2" inv_normal}
		}
	)
	("break_glass_event" args 1)
	("break_glass_event" args 2)
	("break_glass_event" args 3)
	("break_glass_event" args 4)
	("break_glass_event" args 5)
	("break_glass_event" args 6)
	("break_glass_event" args 7)
	("break_glass_event" args 8)
	("break_glass_event" args 9)
	("break_glass_event" args 10)
	{on "trailer_link"
		{play_sound "trailer_link"}
	}
	{on "detach"
		{play_sound "detach"}
	}
	("action_play_sound_and_check_stop" action(round_sandbag)			delay_next_sound(2))			;{on "round_sandbag...
	("action_play_sound_and_check_stop" action(camouflage)				delay_next_sound(2))			;{on "camouflage...
	("action_play_sound_and_check_stop" action(build_supp_point)		delay_next_sound(3))			;{on "build_supp_point...

}


{"wheeled vehicle"
	{on ground_hit
	  {if volume "wheel"
		{constrain_velocity 0.5}
	  }
	}
	{on blast overload
        {if volume "wheel" and can_be_damaged
			{if stuff "mine"
				{if min_energy 2.5
					{call "tear_wheel"}
				}
			else min_energy 4
				{call "tear_wheel"}
			else min_energy 2
				{component break}
			}
		else {inherited}
		}
	}
	{on break_armor
		{if component "wheel"
			{if name "pierce"
				{component break}
			}
		}
	}
	{on "dont_move"
		{tags add "dont_move"}
		{call "check_work_mover"}
		{crew_enable place "driver" 0}
	}
	{on "tear_wheel"
		{if volume "wheelleft1" {bone cut "fxtracel1"}
		else volume "wheelright1" {bone cut "fxtracer1"}}
		{spawn	"spheredust_small"}
		{component destroy}
		{tear "piece_medium_steel" bone from_volume id "wheel"
			{volumes disable bullet contact blast}	
			{impulse up 6 4 dir 7 3}
			{add_view "smoke_dead_wheel" "smoke" "basis"}
			{fire radius 0.5 time 12 follow}
			{view start "smoke"}
			{delay_effect 10 5 "pause"}
		}
		{impulse up 0.3}
		{if tagged "1_wheel_teared"
			{tags add "2_wheel_teared"}
			{tags remove "1_wheel_teared"}
		else tagged "2_wheel_teared"
			{tags add "3_wheel_teared"}
			{tags remove "2_wheel_teared"}
		else {if not tagged "3_wheel_teared" {tags add "1_wheel_teared"}}
		}
		{call"update_moveability"}
	}
	
	{on "update_wheel_mover"
		{tags remove "1_wheel_broken"}
		{tags remove "2_wheel_broken"}
		{tags remove "3_wheel_broken"}
		{tags remove "4_wheel_broken"}
		{if not work "wheelright1"
			 {if tagged "1_wheel_broken"
			{tags add "2_wheel_broken"}
			{tags remove "1_wheel_broken"}
			 else tagged "2_wheel_broken"
			{tags add "3_wheel_broken"}
			{tags remove "2_wheel_broken"}
			 else tagged "3_wheel_broken"
			{tags add "4_wheel_broken"}
			{tags remove "3_wheel_broken"}
			 else {if not tagged "4_wheel_broken" {tags add "1_wheel_broken"}}
			 }
		}
		{if not work "wheelright2"
			 {if tagged "1_wheel_broken"
			{tags add "2_wheel_broken"}
			{tags remove "1_wheel_broken"}
			 else tagged "2_wheel_broken"
			{tags add "3_wheel_broken"}
			{tags remove "2_wheel_broken"}
			 else tagged "3_wheel_broken"
			{tags add "4_wheel_broken"}
			{tags remove "3_wheel_broken"}
			 else {if not tagged "4_wheel_broken" {tags add "1_wheel_broken"}}
			 }
		}
		{if not work "wheelright3"
			 {if tagged "1_wheel_broken"
			{tags add "2_wheel_broken"}
			{tags remove "1_wheel_broken"}
			 else tagged "2_wheel_broken"
			{tags add "3_wheel_broken"}
			{tags remove "2_wheel_broken"}
			 else tagged "3_wheel_broken"
			{tags add "4_wheel_broken"}
			{tags remove "3_wheel_broken"}
			 else {if not tagged "4_wheel_broken" {tags add "1_wheel_broken"}}
			 }
		}
		{if not work "wheelright4"
			 {if tagged "1_wheel_broken"
			{tags add "2_wheel_broken"}
			{tags remove "1_wheel_broken"}
			 else tagged "2_wheel_broken"
			{tags add "3_wheel_broken"}
			{tags remove "2_wheel_broken"}
			 else tagged "3_wheel_broken"
			{tags add "4_wheel_broken"}
			{tags remove "3_wheel_broken"}
			 else {if not tagged "4_wheel_broken" {tags add "1_wheel_broken"}}
			 }
		}
		{if not work "wheelleft1"
			 {if tagged "1_wheel_broken"
			{tags add "2_wheel_broken"}
			{tags remove "1_wheel_broken"}
			 else tagged "2_wheel_broken"
			{tags add "3_wheel_broken"}
			{tags remove "2_wheel_broken"}
			 else tagged "3_wheel_broken"
			{tags add "4_wheel_broken"}
			{tags remove "3_wheel_broken"}
			 else {if not tagged "4_wheel_broken" {tags add "1_wheel_broken"}}
			 }
		}
		{if not work "wheelleft2"
			 {if tagged "1_wheel_broken"
			{tags add "2_wheel_broken"}
			{tags remove "1_wheel_broken"}
			 else tagged "2_wheel_broken"
			{tags add "3_wheel_broken"}
			{tags remove "2_wheel_broken"}
			 else tagged "3_wheel_broken"
			{tags add "4_wheel_broken"}
			{tags remove "3_wheel_broken"}
			 else {if not tagged "4_wheel_broken" {tags add "1_wheel_broken"}}
			 }
		}
		{if not work "wheelleft3"
			 {if tagged "1_wheel_broken"
			{tags add "2_wheel_broken"}
			{tags remove "1_wheel_broken"}
			 else tagged "2_wheel_broken"
			{tags add "3_wheel_broken"}
			{tags remove "2_wheel_broken"}
			 else tagged "3_wheel_broken"
			{tags add "4_wheel_broken"}
			{tags remove "3_wheel_broken"}
			 else {if not tagged "4_wheel_broken" {tags add "1_wheel_broken"}}
			 }
		}
		{if not work "wheelleft4"
			 {if tagged "1_wheel_broken"
			{tags add "2_wheel_broken"}
			{tags remove "1_wheel_broken"}
			 else tagged "2_wheel_broken"
			{tags add "3_wheel_broken"}
			{tags remove "2_wheel_broken"}
			 else tagged "3_wheel_broken"
			{tags add "4_wheel_broken"}
			{tags remove "3_wheel_broken"}
			 else {if not tagged "4_wheel_broken" {tags add "1_wheel_broken"}}
			 }
		}
		{call"update_moveability"}
	}
	{on break 
		{if component "wheelright1" {call "update_wheel_mover"}
		else component "wheelright2" {call "update_wheel_mover"}
		else component "wheelright3" {call "update_wheel_mover"}
		else component "wheelright4" {call "update_wheel_mover"}
		else component "wheelleft1" {call "update_wheel_mover"}
		else component "wheelleft2" {call "update_wheel_mover"}
		else component "wheelleft3" {call "update_wheel_mover"}
		else component "wheelleft4" {call "update_wheel_mover"}
		}
		{if component "wheel"
			{if not linked
		 		{if not velocity 0.5
		 			{impulse up 0.05}
		 		}
			}
		}
	}
	{on repair 
		{if component "wheelright1" {call "update_wheel_mover"}
		else component "wheelright2" {call "update_wheel_mover"}
		else component "wheelright3" {call "update_wheel_mover"}
		else component "wheelright4" {call "update_wheel_mover"}
		else component "wheelleft1" {call "update_wheel_mover"}
		else component "wheelleft2" {call "update_wheel_mover"}
		else component "wheelleft3" {call "update_wheel_mover"}
		else component "wheelleft4" {call "update_wheel_mover"}
		}
	}

	{on "check_work_mover" overload
		{if tagged "dont_move"
			{chassis_work 0} {components "move_indicator" break}
		else
			{if not work "mover"
				{chassis_work 0} {components "move_indicator" break}
			else not work "track"
				{chassis_work 0} {components "move_indicator" break}
			else not work "engine"
				{chassis_work 0} {components "move_indicator" break}
			else not work "body"
				{chassis_work 0} {components "move_indicator" break}
			else work "wheel" 1
				{chassis_work 1} {delay 0.2 {components "move_indicator" repair}}	;causes crush if no delay
				{if broken "wheel" 2
					{movement_limit slow}
				else broken "wheel" 1
					{if tagged "cwts_normal" {movement_limit slow}		
					else tagged "cwts_heavy" {movement_limit slow}
					else {movement_limit normal}
					}
				else
					{if tagged "cwts_normal" {movement_limit normal}		
					else tagged "cwts_heavy" {movement_limit slow}
					else {movement_limit fast}
					}
				}
			else
				{movement_limit slow}
			}
		}
	}
	{on "_explosion"
		(define "rand_tear_wheel"
			{if rand 0.5
				{components %0 destroy}
				{tear "piece_medium_steel" bone %0 id "wheel"
					{volumes disable bullet contact blast}
					{impulse up 7 4 dir 7 4}
					{add_view "smoke_dead_wheel" "smoke" "basis"}
					{view start "smoke"}
					{delay_effect 10 5 "pause"}
				}
			}
		)
		("rand_tear_wheel" args "wheelleft1")
		("rand_tear_wheel" args "wheelleft2")
		("rand_tear_wheel" args "wheelright1")
		("rand_tear_wheel" args "wheelright2")
		("rand_tear_wheel" args "wheelleft3")
		("rand_tear_wheel" args "wheelleft4")
		("rand_tear_wheel" args "wheelright3")
		("rand_tear_wheel" args "wheelright4")
	}
}

{"truck"
	{on blast
        {if volume "wheel"
			{if min_energy 7
				{call "tear_wheel"}
			else min_energy 3
				{component break}
			}
		else {inherited}
		}
	}
}

{"fuel_tank"
	{on blast_hit
		{if min_energy 2
			{call "explosion"}
		}
	}
	{on break_armor
		{call "pierce_bodyback"}
	}
	{on break_armor_again
		{call "pierce_bodyback"}
	}
	{on pierce
		{call "pierce_bodyback"}
	}
	{on "pierce_bodyback"
		{if stuff "radar_ammo"
		else stuff "laser_ammo"
		else stuff "proj_pointer"
		else name "pierce"
			{if not able "exploded"
				{if volume "bodyback"
					{if stuff "bullet"
						{burn fx "drops_oil_small_long" fake}
					}
				}
			}
		}
	}
	{on "_explosion"
		{spawn "fuel_die"}
		{blastwave c4 5 r0 4 r1 15}
		{fire radius 8 time 15 heating 10}
	}
}

{"dead_vehicle"
	{on blast
		{if volume "body"
			{if min_energy 0.7
				{call "explosion"}
			}
		}
	}
	{on "explosion"
		{if not flag "exploded"
			{set "exploded" 1}
			{call "_explosion"}
		}
	}
	{on "_explosion"
		{start_sound "detonation/hit_huge/hit_huge"}
		{delay_ex 0
			{set_skeleton "_x" sync}
			{ani_play "death"}
			{call "cut_parts"}
		}
	}
	{on "cut_parts"
		{add_view "smoke_dead_wheel" "smoke" "basis"}
		{view start "smoke"}
		{delay 20 10
			{view stop "smoke"}
		}
		(define "cut_part"
			{tear "piece_medium_steel" bone %0
				{impulse up 4 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 6 no_position}
				{delay_effect 20 5 "stop"}
			}
		)
		("cut_part" args "part1")
		("cut_part" args "part2")
		("cut_part" args "part3")
		("cut_part" args "part4")
		("cut_part" args "part5")
		("cut_part" args "part6")
	}
}

{"buldozer"
	{on move on
		{ani_play "liftup" +1}
	}
	{on move off
		{ani_play "liftup" -1 resume}
	}
}



{"car_with_dust"
	{on spawn
		{add_view	"dustrun_small"			"on_ground"			"FXtraceR1"}
		{add_view	"dustrun_small"			"on_ground"			"FXtraceL1"}
	}
	{on "start_fx_ground"
		{view start "on_ground"}
	}
	{on "stop_fx_ground"
		{view pause "on_ground"}
	}
}


(define "ural375_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels_cw/truck_loop_3"	}
		{link_sound "engine"			"vehicle/engine_cw/ural375_work"		}
		{link_sound "engine_end"		"vehicle/engine_cw/ural375_stop"		}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"	}
		{link_sound "exhaust"			"vehicle/engine_cw/ural375_start"}
	}
)
(define "ural4320_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels_cw/truck_loop_3"	}
		{link_sound "engine"			"vehicle/engine_cw/ural4320_work"		}
		{link_sound "engine_end"		"vehicle/engine_cw/ural4320_stop"		}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"	}
		{link_sound "exhaust"			"vehicle/engine_cw/ural4320_start"}
	}
)
(define "kamaz_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels_cw/truck_loop_3"	}
		{link_sound "engine"			"vehicle/engine_cw/kamaz_loop"		}
		{link_sound "engine_end"		"vehicle/engine_cw/kamaz_shut_off"	}
		{link_sound "exhaust"			"vehicle/engine_cw/kamaz_start"}
	}
)
(define "maz_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels_cw/truck_loop_3"	}
		{link_sound "engine"			"vehicle/engine_cw/maz_work"		}
		{link_sound "engine_end"		"vehicle/engine_cw/maz_stop"	}
		{link_sound "exhaust"			"vehicle/engine_cw/maz_start"}
	}
)
(define "m939_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels_cw/truck_loop_3"	}
		{link_sound "engine"			"vehicle/engine_cw/m939_engine"		}
		{link_sound "engine_end"		"vehicle/engine_cw/m939_off"	}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"	}
		{link_sound "exhaust"			"vehicle/engine_cw/m939_start"}
	}
	
)
(define "man_kat_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels_cw/truck_loop_3"	}
		{link_sound "engine"			"vehicle/engine_cw/man_work"		}
		{link_sound "engine_end"		"vehicle/engine_cw/man_stop"	}
		{link_sound "rotate_turret" 	"vehicle/turret_cw/light_m2"	}
		{link_sound "exhaust"			"vehicle/engine_cw/man_start"}
	}
)
(define "mercedes_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels_cw/truck_loop_3"	}
		{link_sound "engine"			"vehicle/engine_cw/mercedes_work"		}
		{link_sound "engine_end"		"vehicle/engine_cw/mercedes_stop"	}
		{link_sound "rotate_turret" 	"vehicle/turret_cw/light_m2"	}
		{link_sound "exhaust"			"vehicle/engine_cw/mercedes_start"}
	}
)
(define "husky_tsv_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels_cw/truck_loop_3"	}
		{link_sound "engine"			"vehicle/engine_cw/husky_work"		}
		{link_sound "engine_end"		"vehicle/engine_cw/husky_stop"	}
		{link_sound "rotate_turret" 	"vehicle/turret_cw/light_m2"	}
		{link_sound "exhaust"			"vehicle/engine_cw/husky_start"}
	}
)
(define "renaultgbc_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels_cw/truck_loop_3"	}
		{link_sound "engine"			"vehicle/engine_cw/renaultgbc_work"		}
		{link_sound "engine_end"		"vehicle/engine_cw/renaultgbc_stop"	}
		{link_sound "rotate_turret" 	"vehicle/turret_cw/light_m2"	}
		{link_sound "exhaust"			"vehicle/engine_cw/renaultgbc_start"}
	}
)
(define "hemtt_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels_cw/truck_loop_3"	}
		{link_sound "engine"			"vehicle/engine_cw/hemtt_work"		}
		{link_sound "engine_end"		"vehicle/engine_cw/hemtt_stop"	}
		{link_sound "rotate_turret" 	"vehicle/turret_cw/m270_turret"	}
		{link_sound "exhaust"			"vehicle/engine_cw/hemtt_start"}
	}
)
(define "peugeot_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels_cw/truck_loop_3"	}
		{link_sound "engine"			"vehicle/engine_cw/peugeot_work"		}
		{link_sound "engine_end"		"vehicle/engine_cw/peugeot_stop"	}
		{link_sound "exhaust"			"vehicle/engine_cw/peugeot_start"}
	}
)
(define "sampt_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels_cw/truck_loop_3"	}
		{link_sound "engine"			"vehicle/engine_cw/renault_kerax_work"		}
		{link_sound "engine_end"		"vehicle/engine_cw/renault_kerax_stop"	}
		{link_sound "rotate_turret" 	"vehicle/turret/none"	}
		{link_sound "exhaust"			"vehicle/engine_cw/renault_kerax_start"}
	}
)
(define "wolf_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels_cw/hmmwv"	}
		{link_sound "engine"			"vehicle/engine_cw/wolf_work"		}
		{link_sound "engine_end"		"vehicle/engine_cw/wolf_stop"	}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"	}
		{link_sound "exhaust"			"vehicle/engine_cw/wolf_start"	}
	}
)
(define "dingo_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels_cw/hmmwv"	}
		{link_sound "engine"			"vehicle/engine_cw/dingo_work"		}
		{link_sound "engine_end"		"vehicle/engine_cw/dingo_stop"	}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"	}
		{link_sound "exhaust"			"vehicle/engine_cw/dingo_start"	}
	}
)
(define "ampv_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels_cw/hmmwv"	}
		{link_sound "engine"			"vehicle/engine_cw/ampv_work"		}
		{link_sound "engine_end"		"vehicle/engine_cw/ampv_stop"	}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"	}
		{link_sound "exhaust"			"vehicle/engine_cw/ampv_start"	}
	}
)
(define "gaz66_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels_cw/paz_loop"}
		{link_sound "engine"			"vehicle/engine_cw/gaz66_work"		}
		{link_sound "engine_end"		"vehicle/engine_cw/gaz66_stop"		}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"}
		{link_sound "exhaust"			"vehicle/engine_cw/gaz66_start"}
	}
)
(define "gaz_tigr_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels_cw/paz_loop"}
		{link_sound "engine"			"vehicle/engine_cw/gaz_tigr_work"		}
		{link_sound "engine_end"		"vehicle/engine_cw/gaz_tigr_stop"		}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"}
		{link_sound "exhaust"			"vehicle/engine_cw/gaz_tigr_start"}
	}
)
(define "hmmwv_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels_cw/hmmwv"	}
		{link_sound "engine"			"vehicle/engine_cw/humvee"		}
		{link_sound "engine_end"		"vehicle/engine_cw/humvee_stop"	}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"	}
		{link_sound "exhaust"			"vehicle/engine_cw/humvee_start"}
	}
)
(define "toyota_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels_cw/hmmwv"	}
		{link_sound "engine"			"vehicle/engine_cw/toyota_work"		}
		{link_sound "engine_end"		"vehicle/engine_cw/toyota_stop"	}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"	}
		{link_sound "exhaust"			"vehicle/engine_cw/toyota_start"}
	}
)
(define "landrover_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels_cw/hmmwv"	}
		{link_sound "engine"			"vehicle/engine_cw/landrover_work"		}
		{link_sound "engine_end"		"vehicle/engine_cw/landrover_stop"	}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"	}
		{link_sound "exhaust"			"vehicle/engine_cw/landrover_start"	}
	}
)
(define "jackal2_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels_cw/hmmwv"	}
		{link_sound "engine"			"vehicle/engine_cw/jackal2_work"		}
		{link_sound "engine_end"		"vehicle/engine_cw/jackal2_stop"	}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"	}
		{link_sound "exhaust"			"vehicle/engine_cw/jackal2_start"	}
	}
)
(define "chevrolet_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels_cw/4wd_loop"	}
		{link_sound "engine"			"vehicle/engine_cw/chevrolet_work"		}
		{link_sound "engine_end"		"vehicle/engine_cw/chevrolet_stop"	}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"	}
		{link_sound "exhaust"			"vehicle/engine_cw/vas_on"	}
	}
)
(define "pinzgauer_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels_cw/hmmwv"	}
		{link_sound "engine"			"vehicle/engine_cw/pinzgauer_work"		}
		{link_sound "engine_end"		"vehicle/engine_cw/pinzgauer_stop"	}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"	}
		{link_sound "exhaust"			"vehicle/engine_cw/wolf_start"	}
	}
)
(define "volkswagen_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels_cw/4wd_loop"	}
		{link_sound "engine"			"vehicle/engine_cw/beetle_work"		}
		{link_sound "engine_end"		"vehicle/engine_cw/beetle_stop"	}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"	}
		{link_sound "exhaust"			"vehicle/engine_cw/zaz_on"	}
	}
)
(define "bj2022_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels_cw/4wd_loop"	}
		{link_sound "engine"			"vehicle/engine_cw/bj2020_work"		}
		{link_sound "engine_end"		"vehicle/engine_cw/bj2020_stop"	}
		{link_sound "exhaust"			"vehicle/engine_cw/bj2020_start"	}
	}
)
(define "dodge_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels_cw/4wd_loop"	}
		{link_sound "engine"			"vehicle/engine_cw/dodge_work"		}
		{link_sound "engine_end"		"vehicle/engine_cw/dodge_stop"	}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"	}
		{link_sound "exhaust"			"vehicle/engine_cw/dodge_start"	}
	}
)
(define "ford_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels_cw/4wd_loop"	}
		{link_sound "engine"			"vehicle/engine_cw/fordf150_work"		}
		{link_sound "engine_end"		"vehicle/engine_cw/fordf150_stop"	}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"	}
		{link_sound "exhaust"			"vehicle/engine_cw/fordf150_start"	}
	}
)
{"beijing_bj2022"
	("bj2022_sound")
}
{"pcp001_cs_sm1"
	("bj2022_sound")
	{on fire "gun" 
		{ani_play "fire"}
		{spawn "tank_canon_fire_small" "Foresight1" x}
		{spawn "startsmoke" inv_normal}
	}
}
{"lyt2021"
	("bj2022_sound")
}
{"wolf"
	("wolf_sound")
}
{"lrover"
	("wolf_sound")
}
{"kwm_ampv"
	("ampv_sound")
	{on spawn
		{add_view	"flash_gun_big"			"flashbarrel1"			"Foresight1"}
		{add_view 	"smoke_zenit" 	"zenite_smoke" 		"foresight1"}
		{add_view "zenit_gilz"		"shell"	"fxshell"}	
	}
	{on fire "mgun" 
		{view start "flashbarrel1"}
		{view start "shell"}
		{kill_delay "flashbarrel1"}
		{delay 0.08 "flashbarrel1"
			{view pause "flashbarrel1"}
			{view pause "shell"}
		}
	}
}
{"atf_dingo"
	("dingo_sound")
	{on spawn
		{add_view	"flash_gun_big"			"flashbarrel1"			"Foresight1"}
		{add_view 	"smoke_zenit" 	"zenite_smoke" 		"foresight1"}
		{add_view "zenit_gilz"		"shell"	"fxshell"}	
	}
	{on fire "mgun" 
		{view start "flashbarrel1"}
		{view start "shell"}
		{kill_delay "flashbarrel1"}
		{delay 0.08 "flashbarrel1"
			{view pause "flashbarrel1"}
			{view pause "shell"}
		}
	}
}
{"Gaz66"
	("gaz66_sound")
}
{"Gaz66_zu"
	("gaz66_sound")
	{on ik begin "turret"
		{play_sound "rotate_turret" 1}
	}
	{on ik end "turret"
		{stop_sound "rotate_turret"}
	}
	{on "init_gun"
		{add_view "light_flash_zenit"	"flashbarrel"	"foresight1"}
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
		{ani_play "fire"}
		{ani_play "fire1"}
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
{"Gaz66_inf"
	("gaz66_sound")
}
{"URAL375"
	("ural375_sound")
}
{"ural4320"
	("ural4320_sound")
	(define "break_glass"
	  volume "glass%0"
		{volumes "glass%0" disable bullet contact blast}
	 	{spawn "glass_hit2" "glass%0" x}
	 	{delay 0.1
		 	{bone cut "glass%0"}
	 	}
	)
  {on bullet_hit
	  {if ("break_glass" args _f1)
	   else ("break_glass" args _f2)
	   else ("break_glass" args _f3)
	   else ("break_glass" args _l1)
	   else ("break_glass" args _r1)
	  }
	 }
}
{"kraz255"
	("ural375_sound")
}
{"ural5323_pmp"
	("ural375_sound")
}
{"pmp_carrier"
	{on spawn
		{if tagged "cw_pmp_empty"
			{bone cut "right_pmp"} {bone cut "left_pmp"} {bone cut "centreright"} {bone cut "centreleft"} {bone cut "pmp_basis"}  {bone cut "pmp_basis1"} 
			{bone hide "right_pmp"} {bone hide "left_pmp"} {bone hide "centreright"} {bone hide "centreleft"} {bone hide "pmp_basis"}  {bone hide "pmp_basis1"} 
		}
		;это надо затем, что при наличии tear понтон не пропадает без задержки перед командой.
	  {delay 0.1
		{if tagged "cw_pmp_empty"
			{bone cut "right_pmp"} {bone cut "left_pmp"} {bone cut "centreright"} {bone cut "centreleft"} {bone cut "pmp_basis"}  {bone cut "pmp_basis1"} 
			{bone hide "right_pmp"} {bone hide "left_pmp"} {bone hide "centreright"} {bone hide "centreleft"} {bone hide "pmp_basis"}  {bone hide "pmp_basis1"} 
		}
	   }
	}
	{on fire "gun" overload
		{ani_play "fire" callback}
		("cw_check_shooting" weap_id(gun))
		{volumes "bodyback" disable all}
	}
	{on "deploy_pmp"
		{ani_play "fire" callback}
		{volumes "bodyback" disable all}
	}
	{on animation_end "fire"
		{bone hide "right_pmp"} {bone hide "left_pmp"} {bone hide "centreright"} {bone hide "centreleft"} 
		{bone cut "right_pmp"} {bone cut "left_pmp"} {bone cut "centreright"} {bone cut "centreleft"} 
		{tags add "cw_pmp_empty"}
		{tear "ponton_pmp_land" bone "pmp_basis1"
				{impulse forward -3 com}
			{ani_play "start" callback}
			{if not altitude 2
				{if terrain_fx "water"
					{spawn "spherewater_big" "FX_bulb_medium_center2"}
					{delay 1 {spawn "spherewater_big" "FX_bulb_medium_center1"}}
				else  terrain_fx "deep_water"
					{spawn "spherewater_big" "FX_bulb_medium_center2"}
					{delay 1 {spawn "spherewater_big" "FX_bulb_medium_center1"}}
				}
			}
		}
	}
}
{"kamaz"
	("kamaz_sound")
	{on spawn		
		{add_view 	"headlight"	"light"			"Turret_light"}
		{view hide "light"}	
    }
}
{"kamaz_taifun"
	("kamaz_sound")
	{on "cut_parts"
		{if rand 0.5 ("cut_part" args "apparel")}
		{if rand 0.5 ("cut_part" args "doorl")}
		{if rand 0.5 ("cut_part" args "doorr")}
		{if rand 0.5 ("cut_part" args "cabin")}
	}
}
{"m939"
	("m939_sound")
}
{"m939_inf"
	("m939_sound")
}
{"patriot_truck"
	("m939_sound")
}
{"hemtt"
	("hemtt_sound")
}
{"man_kat"
	("man_kat_sound")
}
{"shaanxi"
	("mercedes_sound")
}
{"renault_gbc_180"
	("renaultgbc_sound")
}
{"husky_tsv"
	("husky_tsv_sound")
}
{"lars2"
	{on spawn
	  {delay 0.1
		{if operatable 
			{ani_wind "open" begin}
		else
			{ani_wind "open" end}
		}
	   }
	}
	{on ik begin "turret"
		{play_sound "rotate_turret" 1}
	}
	{on ik end "turret"
		{stop_sound "rotate_turret"}
	}
	{on fire "gun2" 
		{spawn "startsmoke_big" inv_normal}
		 {if rand 0.5
      			{spawn "dust_shot_big_2" "basis"}
		}
		{ani_play "fire"}
		{view start "flashbarrel_gun"}
		{view start "smoke_add"}
		{delay 0.16 "shell_off"
		{view pause "smoke_add"}
		{view pause "flashbarrel_gun"}
		}
	}
	{on "explosion"
		{set "big_explosion" 0}
		{if not flag "big_explosion"
			{if explosive_amount 400
				{blastwave c4 25 r0 15 r1 35}
				{spawn "train_die" "basis"}
				{set "big_explosion" 1}
			}
		}
	}
	{on "spawn_shellhole" overload
		{if flag "big_explosion"                                        
			{spawn "crater_extra_big" "basis" terrain_texmod}
                        			{spawn "shellhole_big_dead" "basis"}
		}
	}
	{on operatable on
		{ani_play "open" -1}
	}
	{on operatable off
		{ani_play "open"}
	}
	
	
	
	
	
}
{"mtvr_m2"
	{on spawn
		{add_view	 "flash_gun_big"	"flashbarrel3"	"Foresight2"}
	}
	("m939_sound")
	("commonzpu_params" gunner(gunner2) zpu_mgun(mgun) anim(into_hatch_car) pose(hmmwv_mgun) hatch_anim(none))
}
{"oshkosh_mtvr_mk25"
	("m939_sound")
}
{"ural_grad"
	{on ik begin "turret"
		{play_sound "rotate_turret" 1}
	}
	{on ik end "turret"
		{stop_sound "rotate_turret"}
	}
	{on fire "gun" 
		{spawn "startsmoke_big" inv_normal}
		 {if rand 0.5
      			{spawn "dust_shot_big_2" "basis"}
		}
		{ani_play "fire"}
		{view start "flashbarrel_gun"}
		{view start "smoke_add"}
		{delay 0.16 "shell_off"
		{view pause "smoke_add"}
		{view pause "flashbarrel_gun"}
		}
	}
	{on "explosion"
		{set "big_explosion" 0}
		{if not flag "big_explosion"
			{if explosive_amount 400
				{blastwave c4 25 r0 15 r1 35}
				{spawn "train_die" "basis"}
				{set "big_explosion" 1}
			}
		}
	}
	{on "spawn_shellhole" overload
		{if flag "big_explosion"                                        
			{spawn "crater_extra_big" "basis" terrain_texmod}
                        			{spawn "shellhole_big_dead" "basis"}
		}
	}
}
{"ural_umz"
	(define "turret"
	     {on ik begin "%0"	{play_sound "rotate_turret" 1}    }
	     {on ik end "%0"	{stop_sound "rotate_turret"}  }
	)
	("turret" args turret_umz) ("turret" args turret_umz2) ("turret" args turret_umz3) 
	("turret" args turret_umz4) ("turret" args turret_umz5) ("turret" args turret_umz6)
	{on fire "gun01"  {spawn "startsmoke" inv_normal} {spawn "umz_probe" inv_normal}}
	{on fire "gun02"  {spawn "startsmoke" inv_normal} {spawn "umz_probe" inv_normal}}
	{on fire "gun03"  {spawn "startsmoke" inv_normal} {spawn "umz_probe" inv_normal}}
	{on fire "gun04"  {spawn "startsmoke" inv_normal} {spawn "umz_probe" inv_normal}}
	{on fire "gun05"  {spawn "startsmoke" inv_normal} {spawn "umz_probe" inv_normal}}
	{on fire "gun06"  {spawn "startsmoke" inv_normal} {spawn "umz_probe" inv_normal}}
}
{"umz_probe"
	{on spawn      {delay 0.2 {delete}}}
	{on bullet_hit overload
	       {impulse up 0.01 com}
	       {gravity 0.01}
	       {volumes "body" disable all}
	       {if stuff "ksf_cassette kptm ammo"
		{spawn "ptm-1" inv_normal	{impulse forward 30 rnd_dir 4}}
		{spawn "ptm-1" inv_normal	{impulse forward 30 rnd_dir 4}}
		{spawn "ptm-1" inv_normal	{impulse forward 30 rnd_dir 4}}
	        else stuff "ksf_cassette ksf ammo"
		{spawn "pfm-1" inv_normal	{impulse forward 30 rnd_dir 4}}
		{spawn "pfm-1" inv_normal	{impulse forward 30 rnd_dir 4}}
		{spawn "pfm-1" inv_normal	{impulse forward 30 rnd_dir 4}}
		{spawn "pfm-1" inv_normal	{impulse forward 30 rnd_dir 4}}
		{spawn "pfm-1" inv_normal	{impulse forward 30 rnd_dir 4}}
		{spawn "pfm-1" inv_normal	{impulse forward 30 rnd_dir 4}}
		{spawn "pfm-1" inv_normal	{impulse forward 30 rnd_dir 4}}
		{spawn "pfm-1" inv_normal	{impulse forward 30 rnd_dir 4}}
		{spawn "pfm-1" inv_normal	{impulse forward 30 rnd_dir 4}}
		{spawn "pfm-1" inv_normal	{impulse forward 30 rnd_dir 4}}
		{spawn "pfm-1" inv_normal	{impulse forward 30 rnd_dir 4}}
		{spawn "pfm-1" inv_normal	{impulse forward 30 rnd_dir 4}}
		{spawn "pfm-1" inv_normal	{impulse forward 30 rnd_dir 4}}
		{spawn "pfm-1" inv_normal	{impulse forward 30 rnd_dir 4}}
		{spawn "pfm-1" inv_normal	{impulse forward 30 rnd_dir 4}}
		{spawn "pfm-1" inv_normal	{impulse forward 30 rnd_dir 4}}
		{spawn "pfm-1" inv_normal	{impulse forward 30 rnd_dir 4}}
	        else stuff "ksf_cassette kpom2 ammo"
		{spawn "pom_2" inv_normal	
			{volumes "body" disable all}
			{volumes "body" enable contact_ground}
			{delay 1 {volumes "body" enable all}}
			{impulse forward 30 rnd_dir 4}
		}
		{spawn "pom_2" inv_normal	
			{volumes "body" disable all}
			{volumes "body" enable contact_ground}
			{delay 1 {volumes "body" enable all}}
			{impulse forward 30 rnd_dir 4}
		}
		{spawn "pom_2" inv_normal	
			{volumes "body" disable all}
			{volumes "body" enable contact_ground}
			{delay 1 {volumes "body" enable all}}
			{impulse forward 30 rnd_dir 4}
		}
		{spawn "pom_2" inv_normal	
			{volumes "body" disable all}
			{volumes "body" enable contact_ground}
			{delay 1 {volumes "body" enable all}}
			{impulse forward 30 rnd_dir 4}
		}
	       }
	}
}
{"ural375_zu"
	{on ik begin "turret"
		{play_sound "rotate_turret" 1}
	}
	{on ik end "turret"
		{stop_sound "rotate_turret"}
	}
	{on "init_gun"
		{add_view "light_flash_zenit"	"flashbarrel"	"foresight1"}
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
(define "uaz_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels_cw/4wd_loop"	}
		{link_sound "engine"			"vehicle/engine_cw/uaz"		}
		{link_sound "engine_end"		"vehicle/engine_cw/uaz_shut_off"	}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"	}
		{link_sound "exhaust"			"vehicle/engine_cw/uaz_start"	}
	}
	
)
{"uaz_car"
	("uaz_sound")
}
{"uaz2"
	("uaz_sound")
	("commonzpu_params" gunner(gunner) zpu_mgun(mgun) anim(into_hatch_car) pose(seat_gunner_stand) hatch_anim(none))
}
{"uaz_van"
	{on spawn
		{delay 0.1 {call "update_lights"}}
	}
	("uaz_sound")
}
{"hmmwv car"
	("hmmwv_sound")
	("commonzpu_params" gunner(gunner) zpu_mgun(mgun) anim(into_hatch_common) pose(seat_m7_mgunner))
}
{"hmmwv_turret"
	("commonzpu_params" gunner(gunner) zpu_mgun(mgun) anim(into_hatch_car) pose(seat_gunner_stand))
}
(define "hmmwv_for_single_bul_counter"
	{on bullet_hit
	        {if tagged "for_single_count_damage"
		{if stuff "hmgun"
			{spawn "tagged_piece" {tags add "hmmwv_for_single_hit"} {delay 60 {delete}}}
			{spawn "tagged_piece" {tags add "hmmwv_for_single_hit"} {delay 60 {delete}}}
			{spawn "tagged_piece" {tags add "hmmwv_for_single_hit"} {delay 60 {delete}}}
		else stuff "bullet"
			{spawn "tagged_piece" {tags add "hmmwv_for_single_hit"} {delay 60 {delete}}}
		}
	        }
	}
)
{"hmmwv_for_single"
	{on "single_overheat" {view start "steam"}}
	("hmmwv_for_single_bul_counter")
}
{"hmmwv_for_single_turret"
	("hmmwv_for_single_bul_counter")
	(define "check_all_angles"
		(define "check_angle"
			{if tagged "rumb_%0" {if tagged "turn_to_%0" {call "remove_tags"}}}
		)
		("check_angle" args 0)("check_angle" args 1)("check_angle" args 2)("check_angle" args 3)
		("check_angle" args 4)("check_angle" args 5)("check_angle" args 6)("check_angle" args 7)
		("check_angle" args 8)("check_angle" args 9)("check_angle" args 10)("check_angle" args 11)
		("check_angle" args 12)("check_angle" args 13)("check_angle" args 14)("check_angle" args 15)
	)
	{on "remove_tags" 
		{tags remove "turn_to_0"} {tags remove "turn_to_1"} {tags remove "turn_to_2"} {tags remove "turn_to_3"}
		{tags remove "turn_to_4"} {tags remove "turn_to_5"} {tags remove "turn_to_6"} {tags remove "turn_to_7"}
		{tags remove "turn_to_8"} {tags remove "turn_to_9"} {tags remove "turn_to_10"} {tags remove "turn_to_11"}
		{tags remove "turn_to_12"} {tags remove "turn_to_13"} {tags remove "turn_to_14"} {tags remove "turn_to_15"}
		{tags remove "turning_left"} {tags remove "turning_right"}
	}
	{on "remove_rumb" 
		{tags remove "rumb_0"} {tags remove "rumb_1"} {tags remove "rumb_2"} {tags remove "rumb_3"}
		{tags remove "rumb_4"} {tags remove "rumb_5"} {tags remove "rumb_6"} {tags remove "rumb_7"}
		{tags remove "rumb_8"} {tags remove "rumb_9"} {tags remove "rumb_10"} {tags remove "rumb_11"}
		{tags remove "rumb_12"} {tags remove "rumb_13"} {tags remove "rumb_14"} {tags remove "rumb_15"}
	}
	(define "ani_turn"
		{on animation_end "turn_to_%curr"
			{if tagged "turning_right" {call "remove_rumb"} {tags add "rumb_%curr"}
			else tagged "turning_left" {call "remove_rumb"} {tags add "rumb_%left"}}
			("check_all_angles")
			{if tagged "turning_left" {call "turn_left"} else tagged "turning_right" {call "turn_right"}}
		}
	)
	("ani_turn" left(15) curr(0) right(1)) ("ani_turn" left(0) curr(1) right(2)) ("ani_turn" left(1) curr(2) right(3)) ("ani_turn" left(2) curr(3) right(4))
	("ani_turn" left(3) curr(4) right(5)) ("ani_turn" left(4) curr(5) right(6)) ("ani_turn" left(5) curr(6) right(7)) ("ani_turn" left(6) curr(7) right(8))
	("ani_turn" left(7) curr(8) right(9)) ("ani_turn" left(8) curr(9) right(10)) ("ani_turn" left(9) curr(10) right(11)) ("ani_turn" left(10) curr(11) right(12))
	("ani_turn" left(11) curr(12) right(13)) ("ani_turn" left(12) curr(13) right(14)) ("ani_turn" left(13) curr(14) right(15)) ("ani_turn" left(14) curr(15) right(0))
	{on "turn_left"
		(define "turn_cam_left"
			{if tagged "rumb_%0"	{ani_play "turn_to_%0" -1 callback}}
		)	
		("turn_cam_left" args 0)("turn_cam_left" args 1)("turn_cam_left" args 2)("turn_cam_left" args 3)
		("turn_cam_left" args 4)("turn_cam_left" args 5)("turn_cam_left" args 6)("turn_cam_left" args 7)
		("turn_cam_left" args 8)("turn_cam_left" args 9)("turn_cam_left" args 10)("turn_cam_left" args 11)
		("turn_cam_left" args 12)("turn_cam_left" args 13)("turn_cam_left" args 14)("turn_cam_left" args 15)
	}
	{on "turn_right"
		(define "turn_cam_right"
			{if tagged "rumb_%0"	{ani_play "turn_to_%1" 1 callback}}
		)	
		("turn_cam_right" args 0 1)("turn_cam_right" args 1 2)("turn_cam_right" args 2 3)("turn_cam_right" args 3 4)
		("turn_cam_right" args 4 5)("turn_cam_right" args 5 6)("turn_cam_right" args 6 7)("turn_cam_right" args 7 8)
		("turn_cam_right" args 8 9)("turn_cam_right" args 9 10)("turn_cam_right" args 10 11)("turn_cam_right" args 11 12)
		("turn_cam_right" args 12 13)("turn_cam_right" args 13 14)("turn_cam_right" args 14 15)("turn_cam_right" args 15 0)
	}
	{on "cam_left"
	       {delay 0.1
		{tags add "turning_left"}
		("check_all_angles")
		{if tagged "turning_left" {call "turn_left"}}
	       }
	}
	{on "cam_right"
	        {delay 0.1
		{tags add "turning_right"}
		("check_all_angles")
		{if tagged "turning_right" {call "turn_right"}}
	        }
	}
	{on "cam_up"
	        {ani_play "camera_up" 1}
	}
	{on "start_arrows"
	        {ani_play "arrows" 2 loop}
	}
	{on "stop_arrows"
	        {ani_stop "arrows"}
			{bone hide "arrows1"}
			{bone hide "arrows2"}
			{bone hide "arrows3"}
	}
}
{"hmmwv_tow"
	("hmmwv_sound")
	{on fire "gun"
;		{spawn "proj_probe" "Foresight1" x {tags add "Foresight1"}}
		{set "gun"}{call "proj_probe"}
	}
	("commonzpu_params" gunner(gunner) zpu_mgun(gun) anim(into_hatch_btr90) pose(seat_m7_mgunner))
}
{"m-atv"
	{on spawn
		{add_view	 "flash_gun_big"	"flashbarrel3"	"Foresight2"}
	}

	("hmmwv_sound")
	("commonzpu_params" gunner(gunner2) zpu_mgun(mgun) anim(into_hatch_common) pose(seat_m7_mgunner))
}
{"oshkosh_m-atv_mk19"
	{on fire "mgun" 
;      	{spawn "startsmoke" inv_normal}
	}
	("hmmwv_sound")
	("commonzpu_params" gunner(gunner2) zpu_mgun(mgun) anim(into_hatch_common) pose(seat_m7_mgunner))
}
{"gaz_24 car"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/engine_cw/gas"	}
		{link_sound "engine"			"vehicle/engine_cw/gas"		}
		{link_sound "engine_end"		"vehicle/engine_cw/vas_off"	}
		{link_sound "exhaust"			"vehicle/engine_cw/gas_start"	}
	}
	
}
{"vaz_2106 car"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/engine_cw/vas"	}
		{link_sound "engine"			"vehicle/engine_cw/vas"		}
		{link_sound "engine_end"		"vehicle/engine_cw/vas_off"	}
		{link_sound "exhaust"			"vehicle/engine_cw/vas_on"	}
	}
	
}	

{"m1097_avenger"
	("hmmwv_sound")
	{on ik begin "turret"
		{play_sound "rotate_turret" 1}
	}
	{on ik end "turret"
		{stop_sound "rotate_turret"}
	}
	{on fire "mgun" 
		{spawn "startsm_grl"}
	}
	{on fire "gun" 
		{spawn "startsmoke"}
		 {if rand 0.5
      			{spawn "dust_shot_big" "basis"}
		}
		{ani_play "fire"}
		{view start "flashbarrel_gun"}
		{view start "smoke_add"}
		{delay 0.16 "shell_off"
		{view pause "smoke_add"}
		{view pause "flashbarrel_gun"}
		}
		{if name "00"
			{delay 0.1 {spawn "fim-92a_carrier" "shooter00"   x}}
		else name "01"
			{delay 0.1 {spawn "fim-92a_carrier" "shooter01"   x}}
		else name "02"
			{delay 0.1 {spawn "fim-92a_carrier" "shooter02"   x}}
		else name "03"
			{delay 0.1 {spawn "fim-92a_carrier" "shooter03"   x}}
		else name "04"
			{delay 0.1 {spawn "fim-92a_carrier" "shooter04"   x}}
		else name "05"
			{delay 0.1 {spawn "fim-92a_carrier" "shooter05"   x}}
		else name "06"
			{delay 0.1 {spawn "fim-92a_carrier" "shooter06"   x}}
		else name "07"
			{delay 0.1 {spawn "fim-92a_carrier" "shooter07"   x}}
		}
	}
	{on bullet_hit 
		{if volume "glass" 
			{call "break_glass"} 
		else volume "body" 
			{call "break_glass"} 
		 }
		{if volume "glass1" 
			{volumes "glass1" disable bullet contact} 
			{spawn "glass_hit2"} 
			{delay 0.1 
			{bone cut "glass1"} 
			} 
		} 
		{if volume "glass2" 
			{volumes "glass2" disable bullet contact} 
			{spawn "glass_hit2"} 
			{delay 0.1 
				{bone cut "glass2"} 
			} 
		} 
		{if volume "glass3" 
			{volumes "glass3" disable bullet contact} 
			{spawn "glass_hit2"} 
			{delay 0.1 
				{bone cut "glass3"} 
			} 
		} 
		{if volume "glass4" 
			{volumes "glass4" disable bullet contact} 
			{spawn "glass_hit2"} 
			{delay 0.1 
				{bone cut "glass4"} 
			} 
		} 
	} 
} 

	
{"ural-4320_fuel" 

}
{"maz7410"
	{on spawn
		{add_view	"exhaust_dark_small"	"exhaust"			"FXsmoke"}	
    }
	("maz_sound")
}
(define "Tigr"
	("gaz_tigr_sound")
)

{"gaz_tigr"
	("Tigr")
    	{on fire "mgun2" 
      		{spawn "startsmoke" inv_normal}
	}
	("commonzpu_params" gunner(gunner) zpu_mgun(mgun) anim(into_hatch_car) pose(seat_gunner_stand) hatch_anim(none))
	{on "update_mgun2" overload
	     {if work "mgun2" 
	          {if not tagged "cwsh_zpu_off"
		{weapon_work "mgun2" 1}
	           }
	     }
	}
}
{"kornet-d"
	("Tigr")
	{on spawn			
		{add_view 	"rok_tail" 		"shootL00" 		"TailL00"}
		{add_view 	"rok_tail" 		"shootL01" 		"TailL01"}
		{add_view 	"rok_tail" 		"shootL02" 		"TailL02"}
		{add_view 	"rok_tail" 		"shootL03" 		"TailL03"}
		{add_view 	"startsmoke" 		"shootL00" 		"ShooterL00"}
		{add_view 	"startsmoke" 		"shootL01" 		"ShooterL01"}
		{add_view 	"startsmoke" 		"shootL02" 		"ShooterL02"}
		{add_view 	"startsmoke" 		"shootL03" 		"ShooterL03"}
		{add_view 	"rok_tail" 		"shootR00" 		"TailR00"}
		{add_view 	"rok_tail" 		"shootR01" 		"TailR01"}
		{add_view 	"rok_tail" 		"shootR02" 		"TailR02"}
		{add_view 	"rok_tail" 		"shootR03" 		"TailR03"}
		{add_view 	"startsmoke" 		"shootR00" 		"ShooterR00"}
		{add_view 	"startsmoke" 		"shootR01" 		"ShooterR01"}
		{add_view 	"startsmoke" 		"shootR02" 		"ShooterR02"}
		{add_view 	"startsmoke" 		"shootR03" 		"ShooterR03"}
    	}
	{on fire "gun2"
;		{spawn "proj_probe" "Foresight1" x   {tags add "Foresight1"}}
		{set "gun2"}{call "proj_probe"}
		(define "fire_barrel"
			name "%0"
				{ani_play "fire"}
				{view start "shootL%0"}
				{delay 0.42
					{view pause "shootL%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		else ("fire_barrel" args 01)
		else ("fire_barrel" args 02)
		else ("fire_barrel" args 03)
		}
	}
	{on fire "gun3"
;		{spawn "proj_probe" "Foresight2" x  {tags add "Foresight2"}}
		{set "gun3"}{call "proj_probe"}
		(define "fire_barrel"
			name "%0"
				{ani_play "fire"}
				{view start "shootR%0"}
				{delay 0.42
					{view pause "shootR%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		else ("fire_barrel" args 01)
		else ("fire_barrel" args 02)
		else ("fire_barrel" args 03)
		}
	}
}

{"kamaz-r142nm"
	("radar_params" triplex(commander_triplex) visor(visor1) anim_rotate(none) marker(none))
}


{"toyota"
	("toyota_sound")
}
{"toyota_hilux_dshkm"
	{on spawn
		{add_view	"flash_gun_big"			"flashbarrel1"			"Foresight1"}
		{add_view 	"smoke_zenit" 	"zenite_smoke" 		"foresight1"}
		{add_view "zenit_gilz"		"shell"	"fxshell"}	
	}
	{on fire "gun" 
		{view start "flashbarrel1"}
		{view start "shell"}
		{kill_delay "flashbarrel1"}
		{delay 0.08 "flashbarrel1"
			{view pause "flashbarrel1"}
			{view pause "shell"}
		}
	}
}
{"toyota_hilux_spg9"
	{on fire "gun" 
;		{spawn "proj_probe" "Foresight1" x}
		{set "gun"}{call "proj_probe"}
		{spawn "startsmoke" "tail" x}
		{spawn "startsmoke" inv_normal}
	}
}
{"toyota_hilux_nurs"
	{on fire "gun" 
		{spawn "startsmoke_big" inv_normal}
		{spawn "startsmoke_big" "tail" x}
		 {if rand 0.5
      			{spawn "dust_shot_norm" "basis"}
		}
		{ani_play "fire"}
		{view start "flashbarrel_gun"}
		{view start "smoke_add"}
		{delay 0.16 "shell_off"
			{view pause "smoke_add"}
			{view pause "flashbarrel_gun"}
		}
	}
}
{"toyota_hilux_kornet"
	{on fire "gun" 
;		{spawn "proj_probe" "Foresight1" x {tags add "Foresight1"}}
		{set "gun"}{call "proj_probe"}
		{spawn "startsmoke" "tail" x}
		{spawn "startsmoke" inv_normal}
	}
	{on "cut_parts"
		(define "cut_part"
			{tear "piece_medium_steel" bone %0
				{impulse up 4 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 6 no_position}
				{delay_effect 20 5 "stop"}
			}
		)
		("cut_part" args "gun")
	}
}
{"landrover"
	("landrover_sound")
}
{"land_rover_atgm"
	{on fire "gun2"
;		{spawn "proj_probe" "Foresight1" x {tags add "Foresight1"}}
		{set "gun2"}{call "proj_probe"}
	}
	("commonzpu_params" gunner(gunner) zpu_mgun(gun2) anim(into_hatch_btr90) pose(seat_m7_mgunner))
}
{"land_rover_mgun"
	("commonzpu_params" gunner(gunner) zpu_mgun(mgun) anim(into_hatch_common) pose(seat_m7_mgunner))
}
{"jackal2"
	("jackal2_sound")
	("commonzpu_params" gunner(gunner) zpu_mgun(mgun) anim(into_hatch_common) pose(seat_m7_mgunner))
}
{"shahed136_truck"
	("man_kat_sound")
	{on fire "gun2"
		(define "fire_barrel"
			name "%0"
;				{spawn "proj_probe" "foresight1"   x {tags add "shooter%0"}}
				{set "gun2"}{call "proj_probe"}
		)
			
			{if    ("fire_barrel" args 00)
			  else ("fire_barrel" args 01)
			  else ("fire_barrel" args 02)
			  else ("fire_barrel" args 03)
			  else ("fire_barrel" args 04)
			}
	}
}
{"peugeot_p4"("peugeot_sound")}
{"chevrolet_bel_air"("chevrolet_sound")}
{"chevy_s10"("chevrolet_sound")}
{"tatra_t810" 	("man_kat_sound")}
{"pinzgauer_710m"("pinzgauer_sound")}
{"volkswagen_beetle"("volkswagen_sound")}
{"dodje"("dodge_sound")}
{"dodje_police"("dodge_sound")}
{"fire_department"("man_kat_sound")}
{"ford_f150"("ford_sound")}
{"furgon"("pinzgauer_sound")}
{"furgon_swat"("pinzgauer_sound")}
