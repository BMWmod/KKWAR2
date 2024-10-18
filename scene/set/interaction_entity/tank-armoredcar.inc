{on pierce
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
        pierce_body__body_brake(0.20)
        pierce_body__body_destroy(0.10)
    ;--------------------------
		  crew_shock_time(0)
    ;--------------------------
        pierce_turret__burn(0)
        pierce_turret__explosive(0)

        pierce_turret_front__turret_brake(0.30)
        pierce_turret_back__turret_brake(0.30)
        pierce_turret_left_right__turret_brake(0.30)

        pierce_turret_front__gun_brake(0.30) pierce_mantlet__gun_brake(0.30)
        pierce_turret_back__gun_brake(0.10)
        pierce_turret_left_right__gun_brake(0.10)

    ;---------------------------
        pierce_engine__engine_brake(1.00)
        pierce_engine__engine_burn(0.10)

    ;Probability crew die
    ;--------------------------
        pierce_body__kill_charger(0.20)
        pierce_body__kill_gunner(0)
        pierce_body__kill_driver(0.20)
        pierce_body__kill_commander(0)
        pierce_body__kill_gunner2(0)
    ;--------------------------
        pierce_turret__kill_charger(0)
        pierce_turret__kill_gunner(0.20)
        pierce_turret__kill_driver(0)
        pierce_turret__kill_commander(0.20)
        pierce_turret__kill_gunner2(0.20)
    )
    ;///////////////////////////////////////////////////////// ptr
   ("damage_process_pierce"
        staff(ptr)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(1.00)
        pierce_front_back_track(1.00)
        pierce_left_right_track(0.70)
        pierce_inventory__explosive(0)
    ;--------------------------
        pierce_body__burn(0)
        pierce_body__body_brake(0.30)
        pierce_body__body_destroy(0.40)
    ;--------------------------
		  crew_shock_time(3.00)
    ;--------------------------
        pierce_turret__burn(0)
        pierce_turret__explosive(0)

        pierce_turret_front__turret_brake(0.30)
        pierce_turret_back__turret_brake(0.30)
        pierce_turret_left_right__turret_brake(0.30)

        pierce_turret_front__gun_brake(0.30) pierce_mantlet__gun_brake(0.30)
        pierce_turret_back__gun_brake(0.10)
        pierce_turret_left_right__gun_brake(0.10)

    ;---------------------------
        pierce_engine__engine_brake(1.00)
        pierce_engine__engine_burn(0.10)

    ;Probability crew die
    ;--------------------------
        pierce_body__kill_charger(0.20)
        pierce_body__kill_gunner(0)
        pierce_body__kill_driver(0.20)
        pierce_body__kill_commander(0)
        pierce_body__kill_gunner2(0)
    ;--------------------------
        pierce_turret__kill_charger(0)
        pierce_turret__kill_gunner(0.20)
        pierce_turret__kill_driver(0)
        pierce_turret__kill_commander(0.20)
        pierce_turret__kill_gunner2(0.20)
    )
    ;///////////////////////////////////////////////////////// 20mm
   ("damage_process_pierce"
        staff(20mm)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(0.5)
        pierce_front_back_track(1.00)
        pierce_left_right_track(0.80)
        pierce_inventory__explosive(0)
    ;--------------------------
        pierce_body__burn(0)
        pierce_body__body_brake(0.30)
        pierce_body__body_destroy(0.50)
    ;--------------------------
		  crew_shock_time(4.00)
    ;--------------------------
        pierce_turret__burn(0)
        pierce_turret__explosive(0)

        pierce_turret_front__turret_brake(0.30)
        pierce_turret_back__turret_brake(0.30)
        pierce_turret_left_right__turret_brake(0.30)

        pierce_turret_front__gun_brake(0.30) pierce_mantlet__gun_brake(0.30)
        pierce_turret_back__gun_brake(0.10)
        pierce_turret_left_right__gun_brake(0.10)

    ;---------------------------
        pierce_engine__engine_brake(1.00)
        pierce_engine__engine_burn(0.10)

    ;Probability crew die
    ;--------------------------
        pierce_body__kill_charger(0.20)
        pierce_body__kill_gunner(0)
        pierce_body__kill_driver(0.20)
        pierce_body__kill_commander(0)
        pierce_body__kill_gunner2(0)
    ;--------------------------
        pierce_turret__kill_charger(0)
        pierce_turret__kill_gunner(0.20)
        pierce_turret__kill_driver(0)
        pierce_turret__kill_commander(0.20)
        pierce_turret__kill_gunner2(0.20)
    )

    ;///////////////////////////////////////////////////////// 37to47
   ("damage_process_pierce"
        staff(shell_verysmall)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(1.00)
        pierce_front_back_track(1.00)
        pierce_left_right_track(0.90)
        pierce_inventory__explosive(0.70)
    ;--------------------------
        pierce_body__burn(0)
        pierce_body__body_brake(0.20)
        pierce_body__body_destroy(0.55)
    ;--------------------------
		  crew_shock_time(5.00)
    ;--------------------------
        pierce_turret__burn(0)
        pierce_turret__explosive(0)

        pierce_turret_front__turret_brake(0.60)
        pierce_turret_back__turret_brake(0.60)
        pierce_turret_left_right__turret_brake(0.60)

        pierce_turret_front__gun_brake(0.60) pierce_mantlet__gun_brake(0.60)
        pierce_turret_back__gun_brake(0.50)
        pierce_turret_left_right__gun_brake(0.40)

    ;---------------------------
        pierce_engine__engine_brake(1.00)
        pierce_engine__engine_burn(0.25)

    ;Probability crew die
    ;--------------------------
        pierce_body__kill_charger(0.25)
        pierce_body__kill_gunner(0.05)
        pierce_body__kill_driver(1.00)
        pierce_body__kill_commander(0.05)
        pierce_body__kill_gunner2(0.05)
    ;--------------------------
        pierce_turret__kill_charger(0.05)
        pierce_turret__kill_gunner(1.00)
        pierce_turret__kill_driver(0.05)
        pierce_turret__kill_commander(0.25)
        pierce_turret__kill_gunner2(0.25)
    )
    ;///////////////////////////////////////////////////////// 50to57
   ("damage_process_pierce"
        staff(shell_small)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(1.00)
        pierce_front_back_track(1.00)
        pierce_left_right_track(1.00)
        pierce_inventory__explosive(0.80)
    ;--------------------------
        pierce_body__burn(0)
        pierce_body__body_brake(0.20)
        pierce_body__body_destroy(0.60)
    ;--------------------------
		  crew_shock_time(6.00)
    ;--------------------------
        pierce_turret__burn(0)
        pierce_turret__explosive(0)

        pierce_turret_front__turret_brake(0.70)
        pierce_turret_back__turret_brake(0.70)
        pierce_turret_left_right__turret_brake(0.70)

        pierce_turret_front__gun_brake(0.70) pierce_mantlet__gun_brake(0.70)
        pierce_turret_back__gun_brake(0.60)
        pierce_turret_left_right__gun_brake(0.50)

    ;---------------------------
        pierce_engine__engine_brake(1.00)
        pierce_engine__engine_burn(0.30)

    ;Probability crew die
    ;--------------------------
        pierce_body__kill_charger(0.30)
        pierce_body__kill_gunner(0.10)
        pierce_body__kill_driver(1.00)
        pierce_body__kill_commander(0.10)
        pierce_body__kill_gunner2(0.10)
    ;--------------------------
        pierce_turret__kill_charger(0.10)
        pierce_turret__kill_gunner(1.00)
        pierce_turret__kill_driver(0.10)
        pierce_turret__kill_commander(0.30)
        pierce_turret__kill_gunner2(0.30)
    )
    ;///////////////////////////////////////////////////////// 75to76
   ("damage_process_pierce"
        staff(shell_medium)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(1.00)
        pierce_front_back_track(1.00)
        pierce_left_right_track(1.00)
        pierce_inventory__explosive(0.90)
    ;--------------------------
        pierce_body__burn(0)
        pierce_body__body_brake(1.00)
        pierce_body__body_destroy(1.00)
    ;--------------------------
		  crew_shock_time(7.00)
    ;--------------------------
        pierce_turret__burn(0)
        pierce_turret__explosive(0)

        pierce_turret_front__turret_brake(0.80)
        pierce_turret_back__turret_brake(0.80)
        pierce_turret_left_right__turret_brake(0.80)

        pierce_turret_front__gun_brake(0.80) pierce_mantlet__gun_brake(0.80)
        pierce_turret_back__gun_brake(0.70)
        pierce_turret_left_right__gun_brake(0.60)

    ;---------------------------
        pierce_engine__engine_brake(1.00)
        pierce_engine__engine_burn(0.35)

    ;Probability crew die
    ;--------------------------
        pierce_body__kill_charger(0.35)
        pierce_body__kill_gunner(0.15)
        pierce_body__kill_driver(1.00)
        pierce_body__kill_commander(0.15)
        pierce_body__kill_gunner2(0.15)
    ;--------------------------
        pierce_turret__kill_charger(0.15)
        pierce_turret__kill_gunner(1.00)
        pierce_turret__kill_driver(0.15)
        pierce_turret__kill_commander(0.35)
        pierce_turret__kill_gunner2(0.35)
    )
    ;///////////////////////////////////////////////////////// 80to85
   ("damage_process_pierce"
        staff(shell_mediumbig)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(1.00)
        pierce_front_back_track(1.00)
        pierce_left_right_track(1.00)
        pierce_inventory__explosive(1.00)
    ;--------------------------
        pierce_body__burn(0)
        pierce_body__body_brake(1.00)
        pierce_body__body_destroy(1.00)
    ;--------------------------
		  crew_shock_time(8.00)
    ;--------------------------
        pierce_turret__burn(0)
        pierce_turret__explosive(0.1)

        pierce_turret_front__turret_brake(0.90)
        pierce_turret_back__turret_brake(0.90)
        pierce_turret_left_right__turret_brake(0.90)

        pierce_turret_front__gun_brake(0.90) pierce_mantlet__gun_brake(0.90)
        pierce_turret_back__gun_brake(0.80)
        pierce_turret_left_right__gun_brake(0.70)

    ;---------------------------
        pierce_engine__engine_brake(1.00)
        pierce_engine__engine_burn(0.40)

    ;Probability crew die
    ;--------------------------
        pierce_body__kill_charger(0.40)
        pierce_body__kill_gunner(0.20)
        pierce_body__kill_driver(1.00)
        pierce_body__kill_commander(0.20)
        pierce_body__kill_gunner2(0.20)
    ;--------------------------
        pierce_turret__kill_charger(0.20)
        pierce_turret__kill_gunner(1.00)
        pierce_turret__kill_driver(0.20)
        pierce_turret__kill_commander(0.40)
        pierce_turret__kill_gunner2(0.40)
    )
    ;///////////////////////////////////////////////////////// 88to105
   ("damage_process_pierce"
        staff(shell_big)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(1.00)
        pierce_front_back_track(1.00)
        pierce_left_right_track(1.00)
        pierce_inventory__explosive(1.00)
    ;--------------------------
        pierce_body__burn(0)
        pierce_body__body_brake(1.00)
        pierce_body__body_destroy(1.00)
    ;--------------------------
		  crew_shock_time(9.00)
    ;--------------------------
        pierce_turret__burn(0)
        pierce_turret__explosive(0.1)

        pierce_turret_front__turret_brake(1.00)
        pierce_turret_back__turret_brake(1.00)
        pierce_turret_left_right__turret_brake(1.00)

        pierce_turret_front__gun_brake(1.00) pierce_mantlet__gun_brake(1.00)
        pierce_turret_back__gun_brake(0.90)
        pierce_turret_left_right__gun_brake(0.80)

    ;---------------------------
        pierce_engine__engine_brake(1.00)
        pierce_engine__engine_burn(0.45)

    ;Probability crew die
    ;--------------------------
        pierce_body__kill_charger(0.45)
        pierce_body__kill_gunner(0.25)
        pierce_body__kill_driver(1.00)
        pierce_body__kill_commander(0.25)
        pierce_body__kill_gunner2(0.25)
    ;--------------------------
        pierce_turret__kill_charger(0.25)
        pierce_turret__kill_gunner(1.00)
        pierce_turret__kill_driver(0.25)
        pierce_turret__kill_commander(0.45)
        pierce_turret__kill_gunner2(0.45)
    )
    ;///////////////////////////////////////////////////////// 122to128
   ("damage_process_pierce"
        staff(shell_verybig)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(1.00)
        pierce_front_back_track(1.00)
        pierce_left_right_track(1.00)
        pierce_inventory__explosive(1.00)
    ;--------------------------
        pierce_body__burn(0)
        pierce_body__body_brake(1.00)
        pierce_body__body_destroy(1.00)
    ;--------------------------
		  crew_shock_time(10.00)
    ;--------------------------
        pierce_turret__burn(0)
        pierce_turret__explosive(0.5)

        pierce_turret_front__turret_brake(1.00)
        pierce_turret_back__turret_brake(1.00)
        pierce_turret_left_right__turret_brake(1.00)

        pierce_turret_front__gun_brake(1.00) pierce_mantlet__gun_brake(1.00)
        pierce_turret_back__gun_brake(0.90)
        pierce_turret_left_right__gun_brake(0.80)

    ;---------------------------
        pierce_engine__engine_brake(1.00)
        pierce_engine__engine_burn(0.50)

    ;Probability crew die
    ;--------------------------
        pierce_body__kill_charger(0.50)
        pierce_body__kill_gunner(0.30)
        pierce_body__kill_driver(1.00)
        pierce_body__kill_commander(0.30)
        pierce_body__kill_gunner2(0.30)
    ;--------------------------
        pierce_turret__kill_charger(0.30)
        pierce_turret__kill_gunner(1.00)
        pierce_turret__kill_driver(0.30)
        pierce_turret__kill_commander(0.50)
        pierce_turret__kill_gunner2(0.50)
    )
    ;///////////////////////////////////////////////////////// 150to152
   ("damage_process_pierce"
        staff(shell_maximum)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(1.00)
        pierce_front_back_track(1.00)
        pierce_left_right_track(1.00)
        pierce_inventory__explosive(1.00)
    ;--------------------------
        pierce_body__burn(0)
        pierce_body__body_brake(0)
        pierce_body__body_destroy(1.00)
    ;--------------------------
		  crew_shock_time(0)
    ;--------------------------
        pierce_turret__burn(0)
        pierce_turret__explosive(0.7)

        pierce_turret_front__turret_brake(1.00)
        pierce_turret_back__turret_brake(1.00)
        pierce_turret_left_right__turret_brake(1.00)

        pierce_turret_front__gun_brake(1.00) pierce_mantlet__gun_brake(1.00)
        pierce_turret_back__gun_brake(1.00)
        pierce_turret_left_right__gun_brake(1.00)

    ;---------------------------
        pierce_engine__engine_brake(1.00)
        pierce_engine__engine_burn(0.55)

    ;Probability crew die
    ;--------------------------
        pierce_body__kill_charger(0.55)
        pierce_body__kill_gunner(0.35)
        pierce_body__kill_driver(1.00)
        pierce_body__kill_commander(0.35)
        pierce_body__kill_gunner2(0.35)
    ;--------------------------
        pierce_turret__kill_charger(0.35)
        pierce_turret__kill_gunner(1.00)
        pierce_turret__kill_driver(0.35)
        pierce_turret__kill_commander(0.55)
        pierce_turret__kill_gunner2(0.55)
    )
    ;///////////////////////////////////////////////////////// cumulative
   ("damage_process_pierce"
        staff(cumulative_charge)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(0)
        pierce_front_back_track(1.00)
        pierce_left_right_track(1.00)
        pierce_inventory__explosive(1.00)
    ;--------------------------
        pierce_body__burn(1.00)
        pierce_body__body_brake(0)
        pierce_body__body_destroy(1.00)
    ;--------------------------
		crew_shock_time(6.00)
    ;--------------------------
        pierce_turret__burn(0)
        pierce_turret__explosive(1.00)

        pierce_turret_front__turret_brake(0.40)
        pierce_turret_back__turret_brake(0.40)
        pierce_turret_left_right__turret_brake(0.40)

        pierce_turret_front__gun_brake(1.00) pierce_mantlet__gun_brake(1.00)
        pierce_turret_back__gun_brake(0.60)
        pierce_turret_left_right__gun_brake(0.60)

    ;---------------------------
        pierce_engine__engine_brake(1.00)
        pierce_engine__engine_burn(0.90)

    ;Probability crew die
    ;--------------------------
        pierce_body__kill_charger(0.60)
        pierce_body__kill_gunner(0.30)
        pierce_body__kill_driver(0.60)
        pierce_body__kill_commander(0.30)
        pierce_body__kill_gunner2(0.30)
    ;--------------------------
        pierce_turret__kill_charger(0.30)
        pierce_turret__kill_gunner(0.60)
        pierce_turret__kill_driver(0.30)
        pierce_turret__kill_commander(0.60)
        pierce_turret__kill_gunner2(0.60)
    )


    ;///////////////////////////////////////////////////////// cumulative
   ("damage_process_pierce"
        staff(cumulative)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(0)
        pierce_front_back_track(1.00)
        pierce_left_right_track(1.00)
        pierce_inventory__explosive(1.00)
    ;--------------------------
        pierce_body__burn(1.00)
        pierce_body__body_brake(0)
        pierce_body__body_destroy(1.00)
    ;--------------------------
		crew_shock_time(6.00)
    ;--------------------------
        pierce_turret__burn(0)
        pierce_turret__explosive(1.00)

        pierce_turret_front__turret_brake(0.40)
        pierce_turret_back__turret_brake(0.40)
        pierce_turret_left_right__turret_brake(0.40)

        pierce_turret_front__gun_brake(1.00) pierce_mantlet__gun_brake(1.00)
        pierce_turret_back__gun_brake(0.60)
        pierce_turret_left_right__gun_brake(0.60)

    ;---------------------------
        pierce_engine__engine_brake(1.00)
        pierce_engine__engine_burn(0.90)

    ;Probability crew die
    ;--------------------------
        pierce_body__kill_charger(0.60)
        pierce_body__kill_gunner(0.30)
        pierce_body__kill_driver(0.60)
        pierce_body__kill_commander(0.30)
        pierce_body__kill_gunner2(0.30)
    ;--------------------------
        pierce_turret__kill_charger(0.30)
        pierce_turret__kill_gunner(0.60)
        pierce_turret__kill_driver(0.30)
        pierce_turret__kill_commander(0.60)
        pierce_turret__kill_gunner2(0.60)
    )

}; end of pierce
;================================================================================================================================================
{on bullet_hit
  {if not stuff "proj_pointer"
                    ;{if stuff "big shell extra"
                    ;    ;{ani_play "hit"}
                    ;else stuff "big shell"
                    ;    ;{ani_play "hit"}
                    ;}

    ;///////////////////////////////////////////////////////// 150to152
    ("damage_process_bullet_hit"
       staff(shell_maximum)

        hit_body__explosive(0)
        hit_body__engine_burn(0)
        hit_body__body_destroy(0)
        hit_body__body_brake(0)
        ;--------------------------
        hit_body__engine_brake(0)
        ;--------------------------
        hit_turret__explosive(0)
        hit_turret_front__gun_brake(0)
        hit_turret__turret_destroy(0)
        hit_turret__turret_brake(0)
        imp(0)
        hit_tank__tank_destroy(1.00)
        hit_engine__engine_brake(0)
    )
    ("damage_process_bullet_hit"
       staff(shell_verybigfg)

        hit_body__explosive(0)
        hit_body__engine_burn(0)
        hit_body__body_destroy(0)
        hit_body__body_brake(0)
        ;--------------------------
        hit_body__engine_brake(0)
        ;--------------------------
        hit_turret__explosive(0)
        hit_turret_front__gun_brake(0)
        hit_turret__turret_destroy(0)
        hit_turret__turret_brake(0)
        imp(0)
        hit_tank__tank_destroy(1.00)
        hit_engine__engine_brake(0)
    )
    ("damage_process_bullet_hit"
       staff(85to93fg)

        hit_body__explosive(0)
        hit_body__engine_burn(0)
        hit_body__body_destroy(1.00)
        hit_body__body_brake(0)
        ;--------------------------
        hit_body__engine_brake(0)
        ;--------------------------
        hit_turret__explosive(0)
        hit_turret_front__gun_brake(0)
        hit_turret__turret_destroy(0)
        hit_turret__turret_brake(0)
        imp(0)
        hit_tank__tank_destroy(0.5)
        hit_engine__engine_brake(0)
    )
  }
}; end of bullet_hit=


{on blast ;higher energy must be first
    ("blast_damage_contusion"
	blast_rand_contusion(1.00)
	blast_energy(8)
	blast_crew_shock_time(6.00)
    )
    ("blast_damage_contusion"
	blast_rand_contusion(1.00)
	blast_energy(6)
	blast_crew_shock_time(5.00)
    )
    ("blast_damage_contusion"
	blast_rand_contusion(1.00)
	blast_energy(4)
	blast_crew_shock_time(1.00)
    )
    ("blast_damage_contusion"
	blast_rand_contusion(0.5)
	blast_energy(3)
	blast_crew_shock_time(0.70)
    )
    ("blast_damage_contusion"
	blast_rand_contusion(0.3)
	blast_energy(2)
	blast_crew_shock_time(0.50)
    )
}