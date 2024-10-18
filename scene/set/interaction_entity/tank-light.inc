{on pierce

;///////////////////////////DPS system 2 by Pheonix///////////////
	{if component "d_a" 
		{if stuff "cm" 
			("DPS_Effect" dps_apcr(0) dps_cm(1) dps_ap(0))
		else stuff "rok"
			("DPS_Effect" dps_apcr(0) dps_cm(1) dps_ap(0))
		else stuff "fg"
			("DPS_Effect" dps_apcr(0) dps_cm(1) dps_ap(0))
		else stuff "apcr"
			("DPS_Effect" dps_apcr(1) dps_cm(0) dps_ap(0))
		else 
			("DPS_Effect" dps_apcr(1) dps_cm(0) dps_ap(0))
		}
	}
;////////////////////////////END of DPS//////////////////////////

;/////////////////////////////////////////////////////////RPG7
 ("damage_process_pierce"
        staff(rpg18)

     ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(0)
        pierce_front_back_track(1)
        pierce_left_right_track(1)
        pierce_inventory__explosive(1)
    ;--------------------------
        pierce_body__burn(0.6)
        pierce_body__body_brake(0.7)
        pierce_body__body_destroy(0.5)
       pierce_body__body_brake_apcr(0) 
	dps_effect_explosion_cumulative(1) 
    ;--------------------------
		crew_shock_time(0)
    ;--------------------------
        pierce_turret__burn(0.6)
        pierce_turret__explosive(0.5)

        pierce_turret_front__turret_brake(0.4)
        pierce_turret_back__turret_brake(0.4)
        pierce_turret_left_right__turret_brake(0.4)

        pierce_turret_front__gun_brake(1) pierce_mantlet__gun_brake(1)
        pierce_turret_back__gun_brake(0.6)
        pierce_turret_left_right__gun_brake(0.6)

    ;---------------------------
        pierce_engine__engine_brake(1)
        pierce_engine__engine_burn(0.9)

    ;Probability crew die
    ;--------------------------
        pierce_body__kill_charger(0.6)
        pierce_body__kill_gunner(0.3)
        pierce_body__kill_driver(0.6)
        pierce_body__kill_commander(0.3)
        pierce_body__kill_gunner2(0.3)
    ;--------------------------
        pierce_turret__kill_charger(0.4)
        pierce_turret__kill_gunner(0.6)
        pierce_turret__kill_driver(0.3)
        pierce_turret__kill_commander(0.6)
        pierce_turret__kill_gunner2(0.6)
    )
   
;\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\rpg18
	 ("damage_process_pierce"
        staff(rpg7)

     ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(0)
        pierce_front_back_track(1)
        pierce_left_right_track(1)
        pierce_inventory__explosive(1)
    ;--------------------------
        pierce_body__burn(0.6)
        pierce_body__body_brake(0.8)
        pierce_body__body_destroy(0.6)
       pierce_body__body_brake_apcr(0) dps_effect_explosion_cumulative(1) 
    ;--------------------------
		crew_shock_time(0)
    ;--------------------------
        pierce_turret__burn(0.6)
        pierce_turret__explosive(0.5)

        pierce_turret_front__turret_brake(0.4)
        pierce_turret_back__turret_brake(0.4)
        pierce_turret_left_right__turret_brake(0.4)

        pierce_turret_front__gun_brake(1) pierce_mantlet__gun_brake(1)
        pierce_turret_back__gun_brake(0.6)
        pierce_turret_left_right__gun_brake(0.6)

    ;---------------------------
        pierce_engine__engine_brake(1)
        pierce_engine__engine_burn(0.9)

    ;Probability crew die
    ;--------------------------
        pierce_body__kill_charger(0.6)
        pierce_body__kill_gunner(0.3)
        pierce_body__kill_driver(0.6)
        pierce_body__kill_commander(0.3)
        pierce_body__kill_gunner2(0.3)
    ;--------------------------
        pierce_turret__kill_charger(0.4)
        pierce_turret__kill_gunner(0.6)
        pierce_turret__kill_driver(0.3)
        pierce_turret__kill_commander(0.6)
        pierce_turret__kill_gunner2(0.6)
    )
   
;////////////////////////////////////////////////////////////////////////
   ;///////////////////////////////////////////////////////// hmgun
    ("damage_process_pierce"
        staff(hmgun)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(0)
        pierce_front_back_track(0)
        pierce_left_right_track(0)
        pierce_inventory__explosive(0)
    ;--------------------------
        pierce_body__burn(0)
        pierce_body__body_brake(0.2)
        pierce_body__body_destroy(0)
       pierce_body__body_brake_apcr(0) dps_effect_explosion_cumulative(0)
    ;--------------------------
		  crew_shock_time(0)
    ;--------------------------
        pierce_turret__burn(0)
        pierce_turret__explosive(0)

        pierce_turret_front__turret_brake(0)
        pierce_turret_back__turret_brake(0)
        pierce_turret_left_right__turret_brake(0)

        pierce_turret_front__gun_brake(0.3) pierce_mantlet__gun_brake(0.3)
        pierce_turret_back__gun_brake(0.1)
        pierce_turret_left_right__gun_brake(0.1)

    ;---------------------------
        pierce_engine__engine_brake(1)
        pierce_engine__engine_burn(0.1)

    ;Probability crew die
    ;--------------------------
        pierce_body__kill_charger(0)
        pierce_body__kill_gunner(0)
        pierce_body__kill_driver(0.2)
        pierce_body__kill_commander(0)
        pierce_body__kill_gunner2(0)
    ;--------------------------
        pierce_turret__kill_charger(0)
        pierce_turret__kill_gunner(0.1)
        pierce_turret__kill_driver(0)
        pierce_turret__kill_commander(0.2)
        pierce_turret__kill_gunner2(0.2)
    )
    ;///////////////////////////////////////////////////////// ptr
   ("damage_process_pierce"
        staff(ptr)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(1)
        pierce_front_back_track(1)
        pierce_left_right_track(0.7)
        pierce_inventory__explosive(0)
    ;--------------------------
        pierce_body__burn(0)
        pierce_body__body_brake(0.3)
        pierce_body__body_destroy(0)
        pierce_body__body_brake_apcr(0) dps_effect_explosion_cumulative(0)
    ;--------------------------
		  crew_shock_time(3)
    ;--------------------------
        pierce_turret__burn(0)
        pierce_turret__explosive(0)

        pierce_turret_front__turret_brake(0)
        pierce_turret_back__turret_brake(0)
        pierce_turret_left_right__turret_brake(0)

        pierce_turret_front__gun_brake(0.3) pierce_mantlet__gun_brake(0.3)
        pierce_turret_back__gun_brake(0.1)
        pierce_turret_left_right__gun_brake(0.1)

    ;---------------------------
        pierce_engine__engine_brake(1)
        pierce_engine__engine_burn(0.7)

    ;Probability crew die
    ;--------------------------
        pierce_body__kill_charger(0)
        pierce_body__kill_gunner(0)
        pierce_body__kill_driver(0.2)
        pierce_body__kill_commander(0)
        pierce_body__kill_gunner2(0)
    ;--------------------------
        pierce_turret__kill_charger(0)
        pierce_turret__kill_gunner(0.1)
        pierce_turret__kill_driver(0)
        pierce_turret__kill_commander(0.2)
        pierce_turret__kill_gunner2(0.2)
    )
    ;///////////////////////////////////////////////////////// 20mm
   ("damage_process_pierce"
        staff(20mm)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(0.5)
        pierce_front_back_track(0.8)
        pierce_left_right_track(0.2)
        pierce_inventory__explosive(0)
    ;--------------------------
        pierce_body__burn(0)
        pierce_body__body_brake(0.2)
        pierce_body__body_destroy(0)
       pierce_body__body_brake_apcr(0) dps_effect_explosion_cumulative(0) 
    ;--------------------------
		  crew_shock_time(2)
    ;--------------------------
        pierce_turret__burn(0)
        pierce_turret__explosive(0)

        pierce_turret_front__turret_brake(0)
        pierce_turret_back__turret_brake(0)
        pierce_turret_left_right__turret_brake(0)

        pierce_turret_front__gun_brake(0.3) pierce_mantlet__gun_brake(0.3)
        pierce_turret_back__gun_brake(0.1)
        pierce_turret_left_right__gun_brake(0.1)

    ;---------------------------
        pierce_engine__engine_brake(1)
        pierce_engine__engine_burn(0.1)

    ;Probability crew die
    ;--------------------------
        pierce_body__kill_charger(0)
        pierce_body__kill_gunner(0)
        pierce_body__kill_driver(0.2)
        pierce_body__kill_commander(0)
        pierce_body__kill_gunner2(0)
    ;--------------------------
        pierce_turret__kill_charger(0)
        pierce_turret__kill_gunner(0.1)
        pierce_turret__kill_driver(0)
        pierce_turret__kill_commander(0.2)
        pierce_turret__kill_gunner2(0.2)
    )

    ;///////////////////////////////////////////////////////// 37to47
   ("damage_process_pierce"
        staff(37to47)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(1)
        pierce_front_back_track(1)
        pierce_left_right_track(0.5)
        pierce_inventory__explosive(0.2)
    ;--------------------------
        pierce_body__burn(0)
        pierce_body__body_brake(0.4)
        pierce_body__body_destroy(0)
       pierce_body__body_brake_apcr(0) dps_effect_explosion_cumulative(0)
    ;--------------------------
		  crew_shock_time(2)
    ;--------------------------
        pierce_turret__burn(0)
        pierce_turret__explosive(0)

        pierce_turret_front__turret_brake(0.5)
        pierce_turret_back__turret_brake(0.5)
        pierce_turret_left_right__turret_brake(0.5)

        pierce_turret_front__gun_brake(0.5) pierce_mantlet__gun_brake(0.5)
        pierce_turret_back__gun_brake(0.4)
        pierce_turret_left_right__gun_brake(0.3)

    ;---------------------------
        pierce_engine__engine_brake(1)
        pierce_engine__engine_burn(0.1)

    ;Probability crew die
    ;--------------------------
        pierce_body__kill_charger(0.2)
        pierce_body__kill_gunner(0)
        pierce_body__kill_driver(0.4)
        pierce_body__kill_commander(0)
        pierce_body__kill_gunner2(0)
    ;--------------------------
        pierce_turret__kill_charger(0)
        pierce_turret__kill_gunner(0.4)
        pierce_turret__kill_driver(0)
        pierce_turret__kill_commander(0.4)
        pierce_turret__kill_gunner2(0.4)
    )
    ;///////////////////////////////////////////////////////// 50to57
   ("damage_process_pierce"
        staff(50to57)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(1)
        pierce_front_back_track(1)
        pierce_left_right_track(0.5)
        pierce_inventory__explosive(0.5)
    ;--------------------------
        pierce_body__burn(0)
        pierce_body__body_brake(0.4)
        pierce_body__body_destroy(0.1)
       pierce_body__body_brake_apcr(0) dps_effect_explosion_cumulative(0)
    ;--------------------------
		  crew_shock_time(4)
    ;--------------------------
        pierce_turret__burn(0)
        pierce_turret__explosive(0)

        pierce_turret_front__turret_brake(0.7)
        pierce_turret_back__turret_brake(0.7)
        pierce_turret_left_right__turret_brake(0.7)

        pierce_turret_front__gun_brake(0.8) pierce_mantlet__gun_brake(0.8)
        pierce_turret_back__gun_brake(0.7)
        pierce_turret_left_right__gun_brake(0.5)

    ;---------------------------
        pierce_engine__engine_brake(1)
        pierce_engine__engine_burn(0.2)

    ;Probability crew die
    ;--------------------------
        pierce_body__kill_charger(0.2)
        pierce_body__kill_gunner(0)
        pierce_body__kill_driver(0.4)
        pierce_body__kill_commander(0)
        pierce_body__kill_gunner2(0)
    ;--------------------------
        pierce_turret__kill_charger(0)
        pierce_turret__kill_gunner(0.4)
        pierce_turret__kill_driver(0)
        pierce_turret__kill_commander(0.4)
        pierce_turret__kill_gunner2(0.4)
    )
    ;///////////////////////////////////////////////////////// 75to76
   ("damage_process_pierce"
        staff(75to76)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(1)
        pierce_front_back_track(1)
        pierce_left_right_track(0.5)
        pierce_inventory__explosive(1)
    ;--------------------------
        pierce_body__burn(0)
        pierce_body__body_brake(0.6)
        pierce_body__body_destroy(0.5)
       pierce_body__body_brake_apcr(0) dps_effect_explosion_cumulative(0)
    ;--------------------------
		  crew_shock_time(5)
    ;--------------------------
        pierce_turret__burn(0)
        pierce_turret__explosive(0)

        pierce_turret_front__turret_brake(0.6)
        pierce_turret_back__turret_brake(0.6)
        pierce_turret_left_right__turret_brake(0.6)

        pierce_turret_front__gun_brake(0.8) pierce_mantlet__gun_brake(0.8)
        pierce_turret_back__gun_brake(0.7)
        pierce_turret_left_right__gun_brake(0.5)

    ;---------------------------
        pierce_engine__engine_brake(1)
        pierce_engine__engine_burn(0.3)

    ;Probability crew die
    ;--------------------------
        pierce_body__kill_charger(0.3)
        pierce_body__kill_gunner(0.1)
        pierce_body__kill_driver(0.5)
        pierce_body__kill_commander(0.1)
        pierce_body__kill_gunner2(0.1)
    ;--------------------------
        pierce_turret__kill_charger(0.1)
        pierce_turret__kill_gunner(0.5)
        pierce_turret__kill_driver(0.1)
        pierce_turret__kill_commander(0.5)
        pierce_turret__kill_gunner2(0.5)
    )
    ;///////////////////////////////////////////////////////// 85mm
   ("damage_process_pierce"
        staff(85mm)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(1)
        pierce_front_back_track(1)
        pierce_left_right_track(0.5)
        pierce_inventory__explosive(1)
    ;--------------------------
        pierce_body__burn(0)
        pierce_body__body_brake(1)
        pierce_body__body_destroy(1)
       pierce_body__body_brake_apcr(0) dps_effect_explosion_cumulative(0)
    ;--------------------------
		  crew_shock_time(6)
    ;--------------------------
        pierce_turret__burn(0)
        pierce_turret__explosive(0.1)

        pierce_turret_front__turret_brake(0.9)
        pierce_turret_back__turret_brake(0.9)
        pierce_turret_left_right__turret_brake(0.9)

        pierce_turret_front__gun_brake(1) pierce_mantlet__gun_brake(1)
        pierce_turret_back__gun_brake(0.9)
        pierce_turret_left_right__gun_brake(0.8)

    ;---------------------------
        pierce_engine__engine_brake(1)
        pierce_engine__engine_burn(0.5)

    ;Probability crew die
    ;--------------------------
        pierce_body__kill_charger(0.4)
        pierce_body__kill_gunner(0.2)
        pierce_body__kill_driver(0.6)
        pierce_body__kill_commander(0.2)
        pierce_body__kill_gunner2(0.2)
    ;--------------------------
        pierce_turret__kill_charger(0.4)
        pierce_turret__kill_gunner(0.6)
        pierce_turret__kill_driver(0.1)
        pierce_turret__kill_commander(0.6)
        pierce_turret__kill_gunner2(0.6)
    )
    ;///////////////////////////////////////////////////////// 88to105
   ("damage_process_pierce"
        staff(88to105)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(1)
        pierce_front_back_track(1)
        pierce_left_right_track(0.5)
        pierce_inventory__explosive(1)
    ;--------------------------
        pierce_body__burn(0)
        pierce_body__body_brake(1)
        pierce_body__body_destroy(1)
       pierce_body__body_brake_apcr(0) dps_effect_explosion_cumulative(0)
    ;--------------------------
		  crew_shock_time(6)
    ;--------------------------
        pierce_turret__burn(0)
        pierce_turret__explosive(0.1)

        pierce_turret_front__turret_brake(1)
        pierce_turret_back__turret_brake(1)
        pierce_turret_left_right__turret_brake(1)

        pierce_turret_front__gun_brake(1) pierce_mantlet__gun_brake(1)
        pierce_turret_back__gun_brake(0.9)
        pierce_turret_left_right__gun_brake(0.8)

    ;---------------------------
        pierce_engine__engine_brake(1)
        pierce_engine__engine_burn(0.5)

    ;Probability crew die
    ;--------------------------
        pierce_body__kill_charger(0.4)
        pierce_body__kill_gunner(0.2)
        pierce_body__kill_driver(0.6)
        pierce_body__kill_commander(0.2)
        pierce_body__kill_gunner2(0.2)
    ;--------------------------
        pierce_turret__kill_charger(0.4)
        pierce_turret__kill_gunner(0.6)
        pierce_turret__kill_driver(0.1)
        pierce_turret__kill_commander(0.6)
        pierce_turret__kill_gunner2(0.6)
    )
    ;///////////////////////////////////////////////////////// 122to128
   ("damage_process_pierce"
        staff(122to128)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(1)
        pierce_front_back_track(1)
        pierce_left_right_track(0.5)
        pierce_inventory__explosive(1)
    ;--------------------------
        pierce_body__burn(0)
        pierce_body__body_brake(1)
        pierce_body__body_destroy(1)
       pierce_body__body_brake_apcr(0) dps_effect_explosion_cumulative(0) 
    ;--------------------------
		  crew_shock_time(6)
    ;--------------------------
        pierce_turret__burn(0)
        pierce_turret__explosive(0.5)

        pierce_turret_front__turret_brake(1)
        pierce_turret_back__turret_brake(1)
        pierce_turret_left_right__turret_brake(1)

        pierce_turret_front__gun_brake(1) pierce_mantlet__gun_brake(1)
        pierce_turret_back__gun_brake(0.9)
        pierce_turret_left_right__gun_brake(0.8)

    ;---------------------------
        pierce_engine__engine_brake(1)
        pierce_engine__engine_burn(0.7)

    ;Probability crew die
    ;--------------------------
        pierce_body__kill_charger(0.5)
        pierce_body__kill_gunner(0.2)
        pierce_body__kill_driver(0.7)
        pierce_body__kill_commander(0.2)
        pierce_body__kill_gunner2(0.2)
    ;--------------------------
        pierce_turret__kill_charger(0.5)
        pierce_turret__kill_gunner(0.7)
        pierce_turret__kill_driver(0.1)
        pierce_turret__kill_commander(0.7)
        pierce_turret__kill_gunner2(0.7)
    )
    ;///////////////////////////////////////////////////////// 150to152
   ("damage_process_pierce"
        staff(150to152)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(1)
        pierce_front_back_track(1)
        pierce_left_right_track(1)
        pierce_inventory__explosive(1)
    ;--------------------------
        pierce_body__burn(0)
        pierce_body__body_brake(0)
        pierce_body__body_destroy(1)
       pierce_body__body_brake_apcr(0) dps_effect_explosion_cumulative(0) 
    ;--------------------------
		  crew_shock_time(0)
    ;--------------------------
        pierce_turret__burn(0)
        pierce_turret__explosive(0.7)

        pierce_turret_front__turret_brake(1)
        pierce_turret_back__turret_brake(1)
        pierce_turret_left_right__turret_brake(1)

        pierce_turret_front__gun_brake(1) pierce_mantlet__gun_brake(1)
        pierce_turret_back__gun_brake(1)
        pierce_turret_left_right__gun_brake(1)

    ;---------------------------
        pierce_engine__engine_brake(1)
        pierce_engine__engine_burn(0.9)

    ;Probability crew die
    ;--------------------------
        pierce_body__kill_charger(0.5)
        pierce_body__kill_gunner(0.2)
        pierce_body__kill_driver(0.7)
        pierce_body__kill_commander(0.2)
        pierce_body__kill_gunner2(0.2)
    ;--------------------------
        pierce_turret__kill_charger(0.5)
        pierce_turret__kill_gunner(0.7)
        pierce_turret__kill_driver(0.1)
        pierce_turret__kill_commander(0.7)
        pierce_turret__kill_gunner2(0.7)
    )
    ;///////////////////////////////////////////////////////// cumulative
   ("damage_process_pierce"
        staff(cumulative_charge)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(0)
        pierce_front_back_track(1)
        pierce_left_right_track(1)
        pierce_inventory__explosive(1)
    ;--------------------------
        pierce_body__burn(0.6)
        pierce_body__body_brake(0.7)
        pierce_body__body_destroy(0.5)
       pierce_body__body_brake_apcr(0) dps_effect_explosion_cumulative(1)
    ;--------------------------
		crew_shock_time(6)
    ;--------------------------
        pierce_turret__burn(0)
        pierce_turret__explosive(0.3)

        pierce_turret_front__turret_brake(0.4)
        pierce_turret_back__turret_brake(0.4)
        pierce_turret_left_right__turret_brake(0.4)

        pierce_turret_front__gun_brake(1) pierce_mantlet__gun_brake(1)
        pierce_turret_back__gun_brake(0.6)
        pierce_turret_left_right__gun_brake(0.6)

    ;---------------------------
        pierce_engine__engine_brake(1)
        pierce_engine__engine_burn(0.9)

    ;Probability crew die
    ;--------------------------
        pierce_body__kill_charger(0.6)
        pierce_body__kill_gunner(0.3)
        pierce_body__kill_driver(0.6)
        pierce_body__kill_commander(0.3)
        pierce_body__kill_gunner2(0.3)
    ;--------------------------
        pierce_turret__kill_charger(0.4)
        pierce_turret__kill_gunner(0.6)
        pierce_turret__kill_driver(0.3)
        pierce_turret__kill_commander(0.6)
        pierce_turret__kill_gunner2(0.6)
    )


    ;///////////////////////////////////////////////////////// cumulative
   ("damage_process_pierce"
        staff(cumulative)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(0)
        pierce_front_back_track(1)
        pierce_left_right_track(1)
        pierce_inventory__explosive(1)
    ;--------------------------
        pierce_body__burn(0.6)
        pierce_body__body_brake(0.7)
        pierce_body__body_destroy(0.5)
       pierce_body__body_brake_apcr(0) dps_effect_explosion_cumulative(1) 
    ;--------------------------
		crew_shock_time(6)
    ;--------------------------
        pierce_turret__burn(0.6)
        pierce_turret__explosive(0.5)

        pierce_turret_front__turret_brake(0.4)
        pierce_turret_back__turret_brake(0.4)
        pierce_turret_left_right__turret_brake(0.4)

        pierce_turret_front__gun_brake(1) pierce_mantlet__gun_brake(1)
        pierce_turret_back__gun_brake(0.6)
        pierce_turret_left_right__gun_brake(0.6)

    ;---------------------------
        pierce_engine__engine_brake(1)
        pierce_engine__engine_burn(0.9)

    ;Probability crew die
    ;--------------------------
        pierce_body__kill_charger(0.6)
        pierce_body__kill_gunner(0.3)
        pierce_body__kill_driver(0.6)
        pierce_body__kill_commander(0.3)
        pierce_body__kill_gunner2(0.3)
    ;--------------------------
        pierce_turret__kill_charger(0.4)
        pierce_turret__kill_gunner(0.6)
        pierce_turret__kill_driver(0.3)
        pierce_turret__kill_commander(0.6)
        pierce_turret__kill_gunner2(0.6)
    )
   
    ;///////////////////////////////////////////////////////// APCR small
   ("damage_process_pierce"
        staff(small_apcr )

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(0)
        pierce_front_back_track(1)
        pierce_left_right_track(0.5)
        pierce_inventory__explosive(0.2)
    ;--------------------------
        pierce_body__burn(0)
        pierce_body__body_brake(0.4)
        pierce_body__body_destroy(0)
       pierce_body__body_brake_apcr(0) dps_effect_explosion_cumulative(0)
    ;--------------------------
		  crew_shock_time(0)
    ;--------------------------
        pierce_turret__burn(0)
        pierce_turret__explosive(0)

        pierce_turret_front__turret_brake(0.5)
        pierce_turret_back__turret_brake(0.5)
        pierce_turret_left_right__turret_brake(0.5)

        pierce_turret_front__gun_brake(0.6) pierce_mantlet__gun_brake(0.6)
        pierce_turret_back__gun_brake(0.5)
        pierce_turret_left_right__gun_brake(0.3)

    ;---------------------------
        pierce_engine__engine_brake(1)
        pierce_engine__engine_burn(0)

    ;Probability crew die
    ;--------------------------
        pierce_body__kill_charger(0.1)
        pierce_body__kill_gunner(0)
        pierce_body__kill_driver(0.3)
        pierce_body__kill_commander(0)
        pierce_body__kill_gunner2(0)
    ;--------------------------
        pierce_turret__kill_charger(0)
        pierce_turret__kill_gunner(0.3)
        pierce_turret__kill_driver(0)
        pierce_turret__kill_commander(0.3)
        pierce_turret__kill_gunner2(0.3)
    )
    ;///////////////////////////////////////////////////////// APCR medium
   ("damage_process_pierce"
        staff(med_apcr)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(1)
        pierce_front_back_track(1)
        pierce_left_right_track(0.5)
        pierce_inventory__explosive(1)
    ;--------------------------
        pierce_body__burn(0)
        pierce_body__body_brake(0.6)
        pierce_body__body_destroy(0.5)
       pierce_body__body_brake_apcr(0) dps_effect_explosion_cumulative(0)
    ;--------------------------
		  crew_shock_time(0)
    ;--------------------------
        pierce_turret__burn(0)
        pierce_turret__explosive(0)

        pierce_turret_front__turret_brake(0.6)
        pierce_turret_back__turret_brake(0.6)
        pierce_turret_left_right__turret_brake(0.6)

        pierce_turret_front__gun_brake(0.8) pierce_mantlet__gun_brake(0.8)
        pierce_turret_back__gun_brake(0.7)
        pierce_turret_left_right__gun_brake(0.5)

    ;---------------------------
        pierce_engine__engine_brake(1)
        pierce_engine__engine_burn(0.3)

    ;Probability crew die
    ;--------------------------
        pierce_body__kill_charger(0.3)
        pierce_body__kill_gunner(0.1)
        pierce_body__kill_driver(0.5)
        pierce_body__kill_commander(0.1)
        pierce_body__kill_gunner2(0.1)
    ;--------------------------
        pierce_turret__kill_charger(0.1)
        pierce_turret__kill_gunner(0.5)
        pierce_turret__kill_driver(0.1)
        pierce_turret__kill_commander(0.5)
        pierce_turret__kill_gunner2(0.5)
    )
    ;///////////////////////////////////////////////////////// APCR big
   ("damage_process_pierce"
        staff(big_apcr)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(1)
        pierce_front_back_track(1)
        pierce_left_right_track(0.5)
        pierce_inventory__explosive(0.4)
    ;--------------------------
        pierce_body__burn(0)
        pierce_body__body_brake(0.8)
        pierce_body__body_destroy(0.3)
       pierce_body__body_brake_apcr(0) dps_effect_explosion_cumulative(0)
    ;--------------------------
		  crew_shock_time(0)
    ;--------------------------
        pierce_turret__burn(0)
        pierce_turret__explosive(0)

        pierce_turret_front__turret_brake(0.9)
        pierce_turret_back__turret_brake(0.9)
        pierce_turret_left_right__turret_brake(0.9)

        pierce_turret_front__gun_brake(1) pierce_mantlet__gun_brake(1)
        pierce_turret_back__gun_brake(0.8)
        pierce_turret_left_right__gun_brake(0.7)

    ;---------------------------
        pierce_engine__engine_brake(1)
        pierce_engine__engine_burn(0.2)

    ;Probability crew die
    ;--------------------------
        pierce_body__kill_charger(0.2)
        pierce_body__kill_gunner(0)
        pierce_body__kill_driver(0.4)
        pierce_body__kill_commander(0)
        pierce_body__kill_gunner2(0)
    ;--------------------------
        pierce_turret__kill_charger(0)
        pierce_turret__kill_gunner(0.4)
        pierce_turret__kill_driver(0.4)
        pierce_turret__kill_commander(0.4)
        pierce_turret__kill_gunner2(0.4)
    )
}; end of pierce
;=================================================================================================================================================
;-----------------------PTRK---------------------------

{on bullet_hit
;=========
 {if stuff "ptrk"
		{call "stat_break"}
		{call "explosion"}
 	else stuff "rok"
		{call "stat_break"}
		{call "explosion"}
	else stuff "cm_b"
		{call "stat_break"}
		{call "explosion"}
	}
	{if volume "engine"
		{if stuff "rpg7"
			{if rand 0.6
				{call "stat_break"}
				{call "explosion"}
			}
		else stuff "rpg18"
				{call "stat_break"}
				{call "explosion"}
		}
	}
;=========
 {if stuff "size2"
        ("pierce_damage_contusion" blast_rand_contusion(1)	blast_crew_shock_time(1))
    else stuff "size3"
        ("pierce_damage_contusion" blast_rand_contusion(1)	blast_crew_shock_time(2))
    else stuff "size4"
        ("pierce_damage_contusion" blast_rand_contusion(1)	blast_crew_shock_time(3))
 }
                
    ;///////////////////////////////////////////////////////// 150to152
    ("damage_process_bullet_hit"
       staff(150to152fg)

        angle_hit(44) ;degrees

        hit_body__explosive(0)
        hit_body__engine_burn(0.5)
        hit_body__body_destroy(0)
        hit_body__body_brake(0)
        ;--------------------------
        hit_engine__engine_brake(0)
        ;--------------------------
        hit_turret__explosive(0)
        hit_turret_front__gun_brake(0)
        hit_turret__turret_destroy(0)
        hit_turret__turret_brake(1)
        imp(0)
    )
}; end of bullet_hit

{on blast ;higher energy must be first
    ("blast_damage_contusion"
	blast_rand_contusion(0.8)
	blast_energy(5)
	blast_crew_shock_time(6)
    )
    ("blast_damage_contusion"
	blast_rand_contusion(0.5)
	blast_energy(4)
	blast_crew_shock_time(5)
    )
    ("blast_damage_contusion"
	blast_rand_contusion(0.3)
	blast_energy(3)
	blast_crew_shock_time(4)
    )
}
