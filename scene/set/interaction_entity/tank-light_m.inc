;==============================================
;afteratmor system by Timosh
;replacement of damage_process_pierce
(define "spawn_spall"
	{if props "spall_liner"
		{spawn "cw_secdamage_dir" {impulse dir 2 0.1} {tags add "%power"} {tags add "spall_liner"}}
	else
		{spawn "cw_secdamage_dir" {impulse dir 2 0.1} {tags add "%power"}}
	}
)
(define "secondary_damage"
	{if stuff  "hmgun"
		("spawn_spall" power(hmg))
		{spawn "metal_pierce_small"}
	else stuff "autocannon_small"
		("spawn_spall" power(autocannon))
		{spawn "metal_pierce_small"}
	else stuff "rok"
		("spawn_spall" power(power3))
		{spawn "metal_pierce"}
		("pierce_damage_contusion" blast_rand_contusion(1)	blast_crew_shock_time(20))
	else stuff "ptrk"
		("spawn_spall" power(power3))
		{if component "body" 
		     {if rand 0.6 
				{components "body" break}
				{call "mp_destroy"}
		     }
		}
		{spawn "metal_pierce"}
		("pierce_damage_contusion" blast_rand_contusion(1)	blast_crew_shock_time(20))
	else stuff "cm"
		("spawn_spall" power(power2))
		{spawn "metal_pierce_small"}
		("pierce_damage_contusion" blast_rand_contusion(1)	blast_crew_shock_time(20))
	else stuff "fg" 
		("spawn_spall" power(power4))
	else stuff "ap"
		("spawn_spall" power(power2))
		{spawn "metal_pierce_small"}
	else stuff "hesh"
		{bullet_detonate}
		("spawn_spall" power(hesh))
		{spawn "metal_pierce_small"}				
	else stuff "apcr" or stuff "apcr_h"
		("spawn_spall" power(power2))
		{spawn "metal_pierce"}
	else stuff "bullet"
		("spawn_spall" power(bullet))
	else
		{if flag "efp_core"
			("spawn_spall" power(power2))
			{spawn "metal_pierce_small"}
			("pierce_damage_contusion" blast_rand_contusion(1)	blast_crew_shock_time(20))
			{set "efp_core" 0}
	    else
			("spawn_spall" power(power2))
			{spawn "metal_pierce_small"}
			("pierce_damage_contusion" blast_rand_contusion(1)	blast_crew_shock_time(6))
		}
	}
	{if stuff "ic hmgun"
		{fire radius 0.5 time 0.3 heating 30}
	else stuff "ic autocannon_small"
		{fire radius 0.5 time 0.3 heating 60}
	}
)
{on pierce
		{if component "body" or component "turret"
			{burn fx "hit_tank_armor_pierce_wind" fake}
		else
			{burn fx "smoke_tank_damaged_armor_wind" fake}
		}
;		{if not armor_health 1
			{if component "body" or component "turret" or component "turret1" or component "turret2" or component "turret3" or component "turret4"
				{talk "tank_pierce"}
				{call "talk_target_pierced"}
			}
;		}
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
		else  explosive_amount 600
			{if rand 0.8 {components "ammo_storage_main" break}}
		else  explosive_amount 400
			{if rand 0.65 {components "ammo_storage_main" break}}
		else  explosive_amount 200
			{if rand 0.5 {components "ammo_storage_main" break}}
		}
	else component "ammo_storage_autocannon"
		{damage_report "ammo_storage_autocannon" "ammo_storage_damaged"}
		{spawn "metal_hit_bul"}
		{if rand 0.55 {components "ammo_storage_autocannon" break}}
	else component "ammo_storage_mgun"
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
	else component "engine"
		{components "engine" break}
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
			{if rand 0.75 {components "hull_integrity" break}}		;apcr всегда крупнокалиберный, а ap - бывают 25мм.
		else stuff "apcr_h"
			{if rand 0.75 {components "hull_integrity" break}}		;apcr всегда крупнокалиберный, а ap - бывают 25мм.
		else 
			{if rand 0.7 {components "hull_integrity" break}}
		}
	      }
	("secondary_damage")
	else component "turret" 
	       {if not tagged "destroyed"
		{damage_report "turret" "turret_pierced"}
	       }
	("secondary_damage")

	else component "trackleft"
		{if stuff "cm" 
			("track_hit" max_rand(0.8) min_rand(0.4))
		else stuff "rok"
			("track_hit" max_rand(0.9) min_rand(0.5))
		else stuff "fg"
			("track_hit" max_rand(0.9) min_rand(0.9))
		else stuff "ap"
			("track_hit" max_rand(0.8) min_rand(0.3))
		else stuff "apcr"
			("track_hit" max_rand(0.6) min_rand(0.2))
		else stuff "apcr_h"
			("track_hit" max_rand(0.6) min_rand(0.2))
		else 
			("track_hit" max_rand(0.8) min_rand(0.4))
		}
	else component "trackright"
		{if stuff "cm" 
			("track_hit" max_rand(0.8) min_rand(0.4))
		else stuff "rok"
			("track_hit" max_rand(0.9) min_rand(0.5))
		else stuff "fg"
			("track_hit" max_rand(0.9) min_rand(0.9))
		else stuff "ap"
			("track_hit" max_rand(0.8) min_rand(0.3))
		else stuff "apcr"
			("track_hit" max_rand(0.6) min_rand(0.2))
		else stuff "apcr_h"
			("track_hit" max_rand(0.6) min_rand(0.2))
		else 
			("track_hit" max_rand(0.8) min_rand(0.4))
		}
	;///////////////////////////DPS system 2 by Pheonix///////////////
	else component "d_a" 
	      {if not stuff "proj_pointer"
		("DPS_Effect" dps_apcr(0) dps_cm(1) dps_ap(0))
;		{if stuff "cm"
;			("DPS_Effect" dps_apcr(0) dps_cm(1) dps_ap(0))
;		else stuff "rok"
;			("DPS_Effect" dps_apcr(0) dps_cm(1) dps_ap(0))
;		else stuff "fg"
;			("DPS_Effect" dps_apcr(0) dps_cm(1) dps_ap(0))
;		else stuff "apcr"
;			("DPS_Effect" dps_apcr(0) dps_cm(1) dps_ap(0))
;		else stuff "apcr_h"
;			("DPS_Effect" dps_apcr(0) dps_cm(1) dps_ap(0))
;		}
	     }
	}
       }
;////////////////////////////END of DPS//////////////////////////
		("blast")
}; end of pierce
;=================================================================================================================================================


{on bullet_hit
;=============part of projectile system by Timosh=============
		{if  stuff "rus_IR_ff_beam ammo"
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
;==========================
;===============================
;Addition DPS effects by Pheonix
	{if component "d_a" 
	      {if not stuff "proj_pointer"
		{if stuff "cm" 
			("DPS_Effect" dps_apcr(0) dps_cm(1) dps_ap(0))
		else stuff "radar_ammo"
		else stuff "laser_ammo"
		else stuff "IR_ff_ammo"
		else stuff "rok"
			("DPS_Effect" dps_apcr(0) dps_cm(1) dps_ap(0))
		else stuff "fg"
			("DPS_Effect" dps_apcr(0) dps_cm(0.2) dps_ap(0))
		else stuff "ap"
			("DPS_Effect" dps_apcr(0) dps_cm(0) dps_ap(1))
		else stuff "apcr"
			("DPS_Effect" dps_apcr(0) dps_cm(0) dps_ap(1))
		else stuff "apcr_h"
			("DPS_Effect" dps_apcr(0) dps_cm(0) dps_ap(1))
		else stuff "big fg"
			("DPS_Effect" dps_apcr(0) dps_cm(1) dps_ap(0))
		else 
			("DPS_Effect" dps_apcr(0) dps_cm(0) dps_ap(1))
		}
	     }
	}
		("blast")
;=============================


               
    ;///////////////////////////////////////////////////////// 150to152
    ("damage_process_bullet_hit"
       staff(150to152fg)

        hit_body__explosive(0)
        hit_body__engine_burn(0.2)
        hit_body__body_destroy(0)
        hit_body__body_brake(0)
        ;--------------------------
        hit_engine__engine_brake(0)
        ;--------------------------
        hit_turret__explosive(0)
        hit_turret_front__gun_brake(0)
        hit_turret__turret_destroy(0)
        hit_turret__turret_brake(0.8)
        imp(0)
    )
};end on bullet_hit


;=============================================

{on blast ;higher energy must be first
    ("blast_damage_contusion"
	blast_rand_contusion(1)
	blast_energy(18)
	blast_crew_shock_time(15)
    )
    ("blast_damage_contusion"
	blast_rand_contusion(0.7)
	blast_energy(13)
	blast_crew_shock_time(12)
    )
    ("blast_damage_contusion"
	blast_rand_contusion(0.4)
	blast_energy(10)
	blast_crew_shock_time(20)
    )
    ("blast_damage_contusion"
	blast_rand_contusion(0.3)
	blast_energy(9)
	blast_crew_shock_time(5)
    )
    ("blast_damage_contusion"
	blast_rand_contusion(0.2)
	blast_energy(8)
	blast_crew_shock_time(4)
    )
    ("blast_damage_contusion"
	blast_rand_contusion(0.15)
	blast_energy(7)
	blast_crew_shock_time(3)
    )
	{if stuff "antitrack"
		{if volume "track"
		        {if min_energy 3
			{component break}
		        }
		}
	}
}
{on "update_gun" overload
	{if work "gun"
	     {if work "stabilizer"
		    {if work "gunner_panel"
			  {if not tagged "contusion"
				{weapon_work "gun" 1}
			  else {weapon_work "gun" 0}}
			else {weapon_work "gun" 0}}
	     else {weapon_work "gun" 0}}
	else {weapon_work "gun" 0}}
}
